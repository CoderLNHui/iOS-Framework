/*
 * UINotificationFeedbackGenerator.h
 *
 * UIKit (c) 2016-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#import <UIKit/UIFeedbackGenerator.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UINotificationFeedbackType) {
    UINotificationFeedbackTypeSuccess,
    UINotificationFeedbackTypeWarning,
    UINotificationFeedbackTypeError
};

// UINotificationFeedbackGenerator is used to give user feedback when an notification is displayed
UIKIT_CLASS_AVAILABLE_IOS_ONLY(10_0) @interface UINotificationFeedbackGenerator : UIFeedbackGenerator

/// call when a notification is displayed, passing the corresponding type
- (void)notificationOccurred:(UINotificationFeedbackType)notificationType;

@end
NS_ASSUME_NONNULL_END
