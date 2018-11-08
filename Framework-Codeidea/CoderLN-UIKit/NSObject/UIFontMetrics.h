/*
 * UIFontMetrics.h
 *
 * UIKit (c) 2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

