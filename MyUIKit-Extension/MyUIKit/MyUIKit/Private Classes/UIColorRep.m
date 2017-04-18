//
//  UIColorRep.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIColorRep.h"
#import "UIImageRep.h"

static void drawPatternImage(void *info, CGContextRef ctx)
{
    UIImageRep *rep = [(__bridge UIColorRep *)info patternImageRep];
    
    UIGraphicsPushContext(ctx);
    CGContextSaveGState(ctx);
    
    const CGRect patternRect = {CGPointZero, rep.imageSize};
    const CGRect deviceRect = CGContextConvertRectToDeviceSpace(ctx, patternRect);

    
    [rep drawInRect:patternRect fromRect:CGRectNull];
    
    CGContextRestoreGState(ctx);
    UIGraphicsPopContext();
}

@implementation UIColorRep {
    CGColorRef _CGColor;
}

- (id)initWithPatternImageRepresentation:(UIImageRep *)patternImageRep
{
    if (!patternImageRep) {
        self = nil;
    } else if ((self=[super init])) {
        _patternImageRep = patternImageRep;
    }
    return self;
}

- (id)initWithCGColor:(CGColorRef)color
{
    if (!color) {
        self = nil;
    } else if ((self=[super init])) {
        _CGColor = CGColorRetain(color);
    }
    return self;
}

- (void)dealloc
{
    CGColorRelease(_CGColor);
}

- (CGColorRef)CGColor
{
    if (!_CGColor && _patternImageRep) {
        const CGSize imageSize = _patternImageRep.imageSize;
        const CGFloat scaler = 1/_patternImageRep.scale;
       
        const CGAffineTransform t = CGAffineTransformMakeScale(scaler, scaler);
        static const CGPatternCallbacks callbacks = {0, &drawPatternImage, NULL};
        
        CGPatternRef pattern = CGPatternCreate ((__bridge void *)self,
                                                CGRectMake (0, 0, imageSize.width, imageSize.height),
                                                t,
                                                imageSize.width,
                                                imageSize.height,
                                                kCGPatternTilingConstantSpacing,
                                                true,
                                                &callbacks);
        
        CGColorSpaceRef space = CGColorSpaceCreatePattern(NULL);
        CGFloat components[1] = {1.0};
        
        _CGColor = CGColorCreateWithPattern(space, pattern, components);
        
        CGColorSpaceRelease(space);
        CGPatternRelease(pattern);
    }
    
    return _CGColor;
}

- (CGFloat)scale
{
    return _patternImageRep? _patternImageRep.scale : 1;
}

- (BOOL)isOpaque
{
    if (!_patternImageRep && _CGColor) {
        return CGColorGetAlpha(_CGColor) == 1;
    } else {
        return _patternImageRep.opaque;
    }
}


@end
