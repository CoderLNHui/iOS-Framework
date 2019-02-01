/*
 * UIImpactFeedbackGenerator.h
 *
 * UIKit (c) 2016-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

