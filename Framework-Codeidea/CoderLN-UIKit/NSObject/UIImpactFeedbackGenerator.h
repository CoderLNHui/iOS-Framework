/*
 * UIImpactFeedbackGenerator.h
 *
 * UIKit (c) 2016-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

 
#import <UIKit/UIFeedbackGenerator.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIImpactFeedbackStyle) {
    UIImpactFeedbackStyleLight,
    UIImpactFeedbackStyleMedium,
    UIImpactFeedbackStyleHeavy
};

// UIImpactFeedbackGenerator is used to give user feedback when an impact between UI elements occurs
UIKIT_CLASS_AVAILABLE_IOS_ONLY(10_0) @interface UIImpactFeedbackGenerator : UIFeedbackGenerator

- (instancetype)initWithStyle:(UIImpactFeedbackStyle)style;

/// call when your UI element impacts something else
- (void)impactOccurred;

@end
NS_ASSUME_NONNULL_END

