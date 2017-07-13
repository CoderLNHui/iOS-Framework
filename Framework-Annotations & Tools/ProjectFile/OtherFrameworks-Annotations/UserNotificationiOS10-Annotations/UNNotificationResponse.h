/*
 * UNNotificationResponse.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 * Created by 【Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */


/**
 UNNotificationResponse，用户在触发了按钮或者文本提交的UNNotificationAction的时候，会形成一个response，通过通知中心的代理方法回调给App进行处理或者是交给扩展处理。
 */

#import <Foundation/Foundation.h>

@class UNNotification;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const UNNotificationDefaultActionIdentifier __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED;
extern NSString *const UNNotificationDismissActionIdentifier __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED;

__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
@interface UNNotificationResponse : NSObject <NSCopying, NSSecureCoding>

// The notification to which the user responded.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) UNNotification *notification;

// The action identifier that the user chose:
// * UNNotificationDismissActionIdentifier if the user dismissed the notification
// * UNNotificationDefaultActionIdentifier if the user opened the application from the notification
// * the identifier for a registered UNNotificationAction for other actions
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *actionIdentifier;

- (instancetype)init NS_UNAVAILABLE;

@end

__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
@interface UNTextInputNotificationResponse : UNNotificationResponse

// The text entered or chosen by the user.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *userText;

@end

NS_ASSUME_NONNULL_END
