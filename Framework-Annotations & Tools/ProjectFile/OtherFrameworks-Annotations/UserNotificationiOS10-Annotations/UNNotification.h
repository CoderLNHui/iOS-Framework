/*
 * UNNotification.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
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

/*
 * @PBWLN_LICENSE_HEADER
 * Copyright © [@码员白开水ln http://www.jianshu.com/u/fd745d76c816] Reprint please indicate the source
 * @PBWLN_LICENSE_END@
 */
NS_ASSUME_NONNULL_END
