/*
 * UIButton.h 
 *
 * Framework: UIKit (c) 2005-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage, UIFont, UIColor, UIImageView, UILabel;
#pragma mark - NS_ENUM
#pragma mark -按钮类型
typedef NS_ENUM(NSInteger, UIButtonType) {
    UIButtonTypeCustom = 0, // 无样式                        // no button type
    UIButtonTypeSystem NS_ENUM_AVAILABLE_IOS(7_0),// 设置为系统样式  // standard system button
    
    UIButtonTypeDetailDisclosure,// 详细信息样式 (被动加上一个感叹号)
    UIButtonTypeInfoLight,//同上
    UIButtonTypeInfoDark,//同上
    UIButtonTypeContactAdd,//显示加号
    
    UIButtonTypeRoundedRect = UIButtonTypeSystem,  //（被弃用的）请使用UIButtonTypeSystem样式 // Deprecated, use UIButtonTypeSystem instead
};

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIButton : UIControl <NSCoding>

#pragma mark - 初始化
+ (instancetype)buttonWithType:(UIButtonType)buttonType;

#pragma mark - 常用属性
#pragma mark -整体内容内边距
@property(nonatomic)          UIEdgeInsets contentEdgeInsets UI_APPEARANCE_SELECTOR; // default is UIEdgeInsetsZero. On tvOS 10 or later, default is nonzero except for custom buttons.

#pragma mark -按钮内部label控件 内边距
@property(nonatomic)          UIEdgeInsets titleEdgeInsets;                // default is UIEdgeInsetsZero
#pragma mark -按钮设置高亮时是否改变阴影的BOOL值
@property(nonatomic)          BOOL         reversesTitleShadowWhenHighlighted; // default is NO. if YES, shadow reverses to shift between engrave and emboss appearance

#pragma mark -按钮内部image控件 内边距
@property(nonatomic)          UIEdgeInsets imageEdgeInsets;                // default is UIEdgeInsetsZero

#pragma mark -是否图片点击时高亮
@property(nonatomic)          BOOL         adjustsImageWhenHighlighted;    // default is YES. if YES, image is drawn darker when highlighted(pressed)

#pragma mark -是否图片点击时失效
@property(nonatomic)          BOOL         adjustsImageWhenDisabled;       // default is YES. if YES, image is drawn lighter when disabled

#pragma mark - 按钮点击处变亮
@property(nonatomic)          BOOL         showsTouchWhenHighlighted __TVOS_PROHIBITED;      // default is NO. if YES, show a simple feedback (currently a glow) while highlighted

#pragma mark -渲染颜色
@property(null_resettable, nonatomic,strong)   UIColor     *tintColor NS_AVAILABLE_IOS(5_0); // The tintColor is inherited through the superview hierarchy. See UIView for more information.

#pragma mark -按钮类型
@property(nonatomic,readonly) UIButtonType buttonType;

// you can set the image, title color, title shadow color, and background image to use for each state. you can specify data
// for a combined state by using the flags added together. in general, you should specify a value for the normal state to be used
// by other states which don't have a custom value set
#pragma mark - 设置Btn某种状态下的 文字、文字颜色、文字阴影颜色、图片、背景图片、属性字符串文字
- (void)setTitle:(nullable NSString *)title forState:(UIControlState)state;                     // default is nil. title is assumed to be single line
- (void)setTitleColor:(nullable UIColor *)color forState:(UIControlState)state UI_APPEARANCE_SELECTOR; // default if nil. use opaque white
- (void)setTitleShadowColor:(nullable UIColor *)color forState:(UIControlState)state UI_APPEARANCE_SELECTOR; // default is nil. use 50% black
- (void)setImage:(nullable UIImage *)image forState:(UIControlState)state;                      // default is nil. should be same size if different for different states
- (void)setBackgroundImage:(nullable UIImage *)image forState:(UIControlState)state UI_APPEARANCE_SELECTOR; // default is nil
- (void)setAttributedTitle:(nullable NSAttributedString *)title forState:(UIControlState)state NS_AVAILABLE_IOS(6_0); // default is nil. title is assumed to be single line

#pragma mark - 获取Btn某种状态下的 文字、文字颜色、文字阴影颜色、图片、背景图片、属性字符串文字
- (nullable NSString *)titleForState:(UIControlState)state;          // these getters only take a single state value
- (nullable UIColor *)titleColorForState:(UIControlState)state;
- (nullable UIColor *)titleShadowColorForState:(UIControlState)state;
- (nullable UIImage *)imageForState:(UIControlState)state;
- (nullable UIImage *)backgroundImageForState:(UIControlState)state;
- (nullable NSAttributedString *)attributedTitleForState:(UIControlState)state NS_AVAILABLE_IOS(6_0);

// these are the values that will be used for the current state. you can also use these for overrides. a heuristic will be used to
// determine what image to choose based on the explict states set. For example, the 'normal' state value will be used for all states
// that don't have their own image defined.
#pragma mark - 当前 文字、文字颜色、文字阴影颜色、图片、背景图片、属性字符串文字
@property(nullable, nonatomic,readonly,strong) NSString *currentTitle;             // normal/highlighted/selected/disabled. can return nil
@property(nonatomic,readonly,strong) UIColor  *currentTitleColor;        // normal/highlighted/selected/disabled. always returns non-nil. default is white(1,1)
@property(nullable, nonatomic,readonly,strong) UIColor  *currentTitleShadowColor;  // normal/highlighted/selected/disabled.
@property(nullable, nonatomic,readonly,strong) UIImage  *currentImage;             // normal/highlighted/selected/disabled. can return nil
@property(nullable, nonatomic,readonly,strong) UIImage  *currentBackgroundImage;   // normal/highlighted/selected/disabled. can return nil
@property(nullable, nonatomic,readonly,strong) NSAttributedString *currentAttributedTitle NS_AVAILABLE_IOS(6_0);  // normal/highlighted/selected/disabled. can return nil

// return title and image views. will always create them if necessary. always returns nil for system buttons
#pragma mark - 内部子控件
#pragma mark -label文字
@property(nullable, nonatomic,readonly,strong) UILabel     *titleLabel NS_AVAILABLE_IOS(3_0);
#pragma mark -imageView图片
@property(nullable, nonatomic,readonly,strong) UIImageView *imageView  NS_AVAILABLE_IOS(3_0);

// these return the rectangle for the background (assumes bounds), the content (image + title) and for the image and title separately. the content rect is calculated based
// on the title and image size and padding and then adjusted based on the control content alignment. there are no draw methods since the contents
// are rendered in separate subviews (UIImageView, UILabel)

/**
 backgroundRectForBounds: 自定义按钮时，可以更改【背景图片】在按钮当中的位置
 contentRectForBounds:    自定义按钮时，可以更改【整个内容】在按钮当中的位置
 titleRectForContentRect: 自定义按钮时，可以更改【Label】在按钮当中的位置
 imageRectForContentRect: 自定义按钮时，可以更改【图片】在按钮当中的位置
 */
- (CGRect)backgroundRectForBounds:(CGRect)bounds;
- (CGRect)contentRectForBounds:(CGRect)bounds;
- (CGRect)titleRectForContentRect:(CGRect)contentRect;
- (CGRect)imageRectForContentRect:(CGRect)contentRect;
@end

#pragma mark - 弃用
@interface UIButton(UIButtonDeprecated)

@property(nonatomic,strong) UIFont         *font              NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;
@property(nonatomic)        NSLineBreakMode lineBreakMode     NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;
@property(nonatomic)        CGSize          titleShadowOffset NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;

@end

START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
NS_ASSUME_NONNULL_END
