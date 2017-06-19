//  UIStringDrawing   NSString的分类，主要实现NSString的绘制功能    完全实现ok
//  UIStringDrawing.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger, UILineBreakMode) {
    UILineBreakModeWordWrap = 0,
    UILineBreakModeCharacterWrap,
    UILineBreakModeClip,
    UILineBreakModeHeadTruncation,
    UILineBreakModeTailTruncation,
    UILineBreakModeMiddleTruncation,
};

typedef NS_ENUM(NSInteger, UITextAlignment) {
    UITextAlignmentLeft,
    UITextAlignmentCenter,
    UITextAlignmentRight,
};

typedef NS_ENUM(NSInteger, UIBaselineAdjustment) {
    UIBaselineAdjustmentAlignBaselines,
    UIBaselineAdjustmentAlignCenters,
    UIBaselineAdjustmentNone,
};

extern NSString *const UITextAttributeFont;
extern NSString *const UITextAttributeTextColor;
extern NSString *const UITextAttributeTextShadowColor;
extern NSString *const UITextAttributeTextShadowOffset;

@class UIFont;

@interface NSString (UIStringDrawing)

- (CGSize)sizeWithFont:(UIFont *)font;
- (CGSize)sizeWithFont:(UIFont *)font forWidth:(CGFloat)width lineBreakMode:(UILineBreakMode)lineBreakMode;
- (CGSize)sizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size;
- (CGSize)sizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size lineBreakMode:(UILineBreakMode)lineBreakMode;
- (CGSize)drawAtPoint:(CGPoint)point withFont:(UIFont *)font;
- (CGSize)drawAtPoint:(CGPoint)point forWidth:(CGFloat)width withFont:(UIFont *)font lineBreakMode:(UILineBreakMode)lineBreakMode;
- (CGSize)drawAtPoint:(CGPoint)point forWidth:(CGFloat)width withFont:(UIFont *)font fontSize:(CGFloat)fontSize lineBreakMode:(UILineBreakMode)lineBreakMode baselineAdjustment:(UIBaselineAdjustment)baselineAdjustment;
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont *)font;
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont *)font lineBreakMode:(UILineBreakMode)lineBreakMode;
- (CGSize)drawInRect:(CGRect)rect withFont:(UIFont *)font lineBreakMode:(UILineBreakMode)lineBreakMode alignment:(UITextAlignment)alignment;

// not yet implemented
- (CGSize)sizeWithFont:(UIFont *)font minFontSize:(CGFloat)minFontSize actualFontSize:(CGFloat *)actualFontSize forWidth:(CGFloat)width lineBreakMode:(UILineBreakMode)lineBreakMode;
- (CGSize)drawAtPoint:(CGPoint)point forWidth:(CGFloat)width withFont:(UIFont *)font minFontSize:(CGFloat)minFontSize actualFontSize:(CGFloat *)actualFontSize lineBreakMode:(UILineBreakMode)lineBreakMode baselineAdjustment:(UIBaselineAdjustment)baselineAdjustment;

@end
