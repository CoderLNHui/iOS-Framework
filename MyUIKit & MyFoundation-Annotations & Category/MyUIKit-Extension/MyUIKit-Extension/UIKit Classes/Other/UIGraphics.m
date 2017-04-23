//
//  UIGraphics.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIGraphics.h"
#import <AppKit/AppKit.h>
#import "UIImage.h"
#import "UIScreen.h"

static NSMutableArray *contextStack = nil;
static NSMutableArray *imageContextStack = nil;

void UIGraphicsPushContext(CGContextRef ctx)
{
    if (!contextStack) {
        contextStack = [[NSMutableArray alloc] initWithCapacity:1];
    }
    
    if ([NSGraphicsContext currentContext]) {
        [contextStack addObject:[NSGraphicsContext currentContext]];
    }
    
    [NSGraphicsContext setCurrentContext:[NSGraphicsContext graphicsContextWithGraphicsPort:(void *)ctx flipped:YES]];
}

void UIGraphicsPopContext()
{
    if ([contextStack lastObject]) {
        [NSGraphicsContext setCurrentContext:[contextStack lastObject]];
        [contextStack removeLastObject];
    }
}

CGContextRef UIGraphicsGetCurrentContext()
{
    return [[NSGraphicsContext currentContext] graphicsPort];
}

CGFloat _UIGraphicsGetContextScaleFactor(CGContextRef ctx)
{
    const CGRect rect = CGContextGetClipBoundingBox(ctx);
    const CGRect deviceRect = CGContextConvertRectToDeviceSpace(ctx, rect);
    const CGFloat scale = deviceRect.size.height / rect.size.height;
    return scale;
}

void UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, CGFloat scale)
{
    if (scale == 0.f) {
        scale = [UIScreen mainScreen].scale ?: 1;
    }
    
    const size_t width = size.width * scale;
    const size_t height = size.height * scale;
    
    if (width > 0 && height > 0) {
        if (!imageContextStack) {
            imageContextStack = [[NSMutableArray alloc] initWithCapacity:1];
        }
        
        [imageContextStack addObject:[NSNumber numberWithFloat:scale]];
        
        CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
        CGContextRef ctx = CGBitmapContextCreate(NULL, width, height, 8, 4*width, colorSpace, (opaque? kCGImageAlphaNoneSkipFirst : kCGImageAlphaPremultipliedFirst));
        CGContextConcatCTM(ctx, CGAffineTransformMake(1, 0, 0, -1, 0, height));
        CGContextScaleCTM(ctx, scale, scale);
        CGColorSpaceRelease(colorSpace);
        UIGraphicsPushContext(ctx);
        CGContextRelease(ctx);
    }
}

void UIGraphicsBeginImageContext(CGSize size)
{
    UIGraphicsBeginImageContextWithOptions(size, NO, 1.f);
}

UIImage *UIGraphicsGetImageFromCurrentImageContext()
{
    if ([imageContextStack lastObject]) {
        const CGFloat scale = [[imageContextStack lastObject] floatValue];
        CGImageRef theCGImage = CGBitmapContextCreateImage(UIGraphicsGetCurrentContext());
        UIImage *image = [UIImage imageWithCGImage:theCGImage scale:scale orientation:UIImageOrientationUp];
        CGImageRelease(theCGImage);
        return image;
    } else {
        return nil;
    }
}

void UIGraphicsEndImageContext()
{
    if ([imageContextStack lastObject]) {
        [imageContextStack removeLastObject];
        UIGraphicsPopContext();
    }
}

void UIRectClip(CGRect rect)
{
    CGContextClipToRect(UIGraphicsGetCurrentContext(), rect);
}

void UIRectFill(CGRect rect)
{
    UIRectFillUsingBlendMode(rect, kCGBlendModeCopy);
}

void UIRectFillUsingBlendMode(CGRect rect, CGBlendMode blendMode)
{
    CGContextRef c = UIGraphicsGetCurrentContext();
    CGContextSaveGState(c);
    CGContextSetBlendMode(c, blendMode);
    CGContextFillRect(c, rect);
    CGContextRestoreGState(c);
}

void UIRectFrame(CGRect rect)
{
    CGContextStrokeRect(UIGraphicsGetCurrentContext(), rect);
}

void UIRectFrameUsingBlendMode(CGRect rect, CGBlendMode blendMode)
{
    CGContextRef c = UIGraphicsGetCurrentContext();
    CGContextSaveGState(c);
    CGContextSetBlendMode(c, blendMode);
    UIRectFrame(rect);
    CGContextRestoreGState(c);
}

