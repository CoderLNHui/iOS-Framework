/*
 * UNNotification.h 
 *
 * UserNotifications (c) 2015
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */
 

/**
 UNNotification 通知实体，在UNUserNotificationCenter的代理回调事件中，告知App接收到一条通知，包含一个发起通知的请求UNNotificationRequest
 */

#import <Foundation/Foundation.h>

@class UNNotificationRequest;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNNotification : NSObject <NSCopying, NSSecureCoding>

// The date displayed on the notification.
@property (nonatomic, readonly, copy) NSDate *date;

// The notification request that caused the notification to be delivered.
@property (nonatomic, readonly, copy) UNNotificationRequest *request;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
