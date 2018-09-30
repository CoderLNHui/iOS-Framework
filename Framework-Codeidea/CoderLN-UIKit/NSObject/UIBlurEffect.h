/*
 * UIBlurEffect.h
 *
 * UIKit (c) 2016-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */
 
#import <UIKit/UIVisualEffect.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIBlurEffectStyle) {
    UIBlurEffectStyleExtraLight,
    UIBlurEffectStyleLight,
    UIBlurEffectStyleDark,
    UIBlurEffectStyleExtraDark __TVOS_AVAILABLE(10_0) __IOS_PROHIBITED __WATCHOS_PROHIBITED,
    UIBlurEffectStyleRegular NS_ENUM_AVAILABLE_IOS(10_0), // Adapts to user interface style
    UIBlurEffectStyleProminent NS_ENUM_AVAILABLE_IOS(10_0), // Adapts to user interface style
} NS_ENUM_AVAILABLE_IOS(8_0);

/* UIBlurEffect will provide a blur that appears to have been applied to the content layered behind the UIVisualEffectView. Views added to the contentView of a blur visual effect are not blurred themselves. */
NS_CLASS_AVAILABLE_IOS(8.0) @interface UIBlurEffect : UIVisualEffect

+ (UIBlurEffect *)effectWithStyle:(UIBlurEffectStyle)style;

@end

NS_ASSUME_NONNULL_END
