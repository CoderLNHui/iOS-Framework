//
//  UIButton.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIControl.h"
#import "UIGeometry.h"

typedef NS_ENUM(NSInteger, UIButtonType) {
    UIButtonTypeCustom = 0,
    UIButtonTypeRoundedRect,
    UIButtonTypeDetailDisclosure,
    UIButtonTypeInfoLight,
    UIButtonTypeInfoDark,
    UIButtonTypeContactAdd,
};

@class UILabel, UIImageView, UIImage;

@interface UIButton : UIControl

+ (id)buttonWithType:(UIButtonType)buttonType;

- (void)setTitle:(NSString *)title forState:(UIControlState)state;
- (void)setTitleColor:(UIColor *)color forState:(UIControlState)state;
- (void)setTitleShadowColor:(UIColor *)color forState:(UIControlState)state;
- (void)setBackgroundImage:(UIImage *)image forState:(UIControlState)state;
- (void)setImage:(UIImage *)image forState:(UIControlState)state;

- (NSString *)titleForState:(UIControlState)state;
- (UIColor *)titleColorForState:(UIControlState)state;
- (UIColor *)titleShadowColorForState:(UIControlState)state;
- (UIImage *)backgroundImageForState:(UIControlState)state;
- (UIImage *)imageForState:(UIControlState)state;

- (CGRect)backgroundRectForBounds:(CGRect)bounds;
- (CGRect)contentRectForBounds:(CGRect)bounds;
- (CGRect)titleRectForContentRect:(CGRect)contentRect;
- (CGRect)imageRectForContentRect:(CGRect)contentRect;

@property (nonatomic, readonly) UIButtonType buttonType;
@property (nonatomic,readonly,strong) UILabel *titleLabel;
@property (nonatomic,readonly,strong) UIImageView *imageView;
@property (nonatomic) BOOL reversesTitleShadowWhenHighlighted;
@property (nonatomic) BOOL adjustsImageWhenHighlighted;
@property (nonatomic) BOOL adjustsImageWhenDisabled;
@property (nonatomic) BOOL showsTouchWhenHighlighted;		// no effect
@property (nonatomic) UIEdgeInsets contentEdgeInsets;
@property (nonatomic) UIEdgeInsets titleEdgeInsets;
@property (nonatomic) UIEdgeInsets imageEdgeInsets;

@property (nonatomic, readonly, strong) NSString *currentTitle;
@property (nonatomic, readonly, strong) UIColor *currentTitleColor;
@property (nonatomic, readonly, strong) UIColor *currentTitleShadowColor;
@property (nonatomic, readonly, strong) UIImage *currentImage;
@property (nonatomic, readonly, strong) UIImage *currentBackgroundImage;
@end
