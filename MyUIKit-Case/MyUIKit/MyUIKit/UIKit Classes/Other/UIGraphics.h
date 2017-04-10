//  完全实现ok
//  UIGraphics.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIImage;

#ifdef __cplusplus
extern "C" {
#endif
    
    void UIGraphicsPushContext(CGContextRef ctx);
    void UIGraphicsPopContext(void);
    CGContextRef UIGraphicsGetCurrentContext(void);
    
    CGFloat _UIGraphicsGetContextScaleFactor(CGContextRef ctx);
    
    void UIGraphicsBeginImageContextWithOptions(CGSize size, BOOL opaque, CGFloat scale);
    void UIGraphicsBeginImageContext(CGSize size);
    UIImage *UIGraphicsGetImageFromCurrentImageContext(void);
    void UIGraphicsEndImageContext(void);
    
    void UIRectClip(CGRect rect);
    
    void UIRectFill(CGRect rect);
    void UIRectFillUsingBlendMode(CGRect rect, CGBlendMode blendMode);
    
    void UIRectFrame(CGRect rect);
    void UIRectFrameUsingBlendMode(CGRect rect, CGBlendMode blendMode);
    
#ifdef __cplusplus
}
#endif
