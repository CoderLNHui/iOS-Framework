/*
 * NSString+UserNotifications.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 * Created by 【Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */
 
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (UNUserNotificationCenterSupport)

// Use -[NSString localizedUserNotificationStringForKey:arguments:] to provide a string that will be localized at the time that the notification is presented.
+ (NSString *)localizedUserNotificationStringForKey:(NSString *)key arguments:(nullable NSArray *)arguments __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END
