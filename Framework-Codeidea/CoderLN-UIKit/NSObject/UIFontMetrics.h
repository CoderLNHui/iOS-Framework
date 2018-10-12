/*
 * UIFontMetrics.h
 *
 * UIKit (c) 2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIFont.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(11.0),tvos(11.0),watchos(4.0))
@interface UIFontMetrics : NSObject

@property (class, readonly, strong) UIFontMetrics *defaultMetrics;

+ (instancetype)metricsForTextStyle:(UIFontTextStyle)textStyle;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initForTextStyle:(UIFontTextStyle)textStyle NS_DESIGNATED_INITIALIZER;

- (UIFont *)scaledFontForFont:(UIFont *)font;
- (UIFont *)scaledFontForFont:(UIFont *)font maximumPointSize:(CGFloat)maximumPointSize;
- (UIFont *)scaledFontForFont:(UIFont *)font compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection __WATCHOS_PROHIBITED;
- (UIFont *)scaledFontForFont:(UIFont *)font maximumPointSize:(CGFloat)maximumPointSize compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection __WATCHOS_PROHIBITED;

- (CGFloat)scaledValueForValue:(CGFloat)value;
- (CGFloat)scaledValueForValue:(CGFloat)value compatibleWithTraitCollection:(nullable UITraitCollection *)traitCollection __WATCHOS_PROHIBITED;

@end
NS_ASSUME_NONNULL_END

