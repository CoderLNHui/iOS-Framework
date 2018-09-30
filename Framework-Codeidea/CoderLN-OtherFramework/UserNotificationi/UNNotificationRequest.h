/*
 * UNNotificationRequest.h 
 *
 * UserNotifications (c) 2015
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

/**
 UNNotificationRequest包含通知内容UNNotificationContent和触发器UNNotificationTrigger
 */

#import <Foundation/Foundation.h>

@class UNNotificationContent;
@class UNNotificationTrigger;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNNotificationRequest : NSObject <NSCopying, NSSecureCoding>

// The unique identifier for this notification request. It can be used to replace or remove a pending notification request or a delivered notification.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *identifier;

// The content that will be shown on the notification.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) UNNotificationContent *content;

// The trigger that will or did cause the notification to be delivered. No trigger means deliver now.
@property (NS_NONATOMIC_IOSONLY, readonly, copy, nullable) UNNotificationTrigger *trigger;

+ (instancetype)requestWithIdentifier:(NSString *)identifier content:(UNNotificationContent *)content trigger:(nullable UNNotificationTrigger *)trigger;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
