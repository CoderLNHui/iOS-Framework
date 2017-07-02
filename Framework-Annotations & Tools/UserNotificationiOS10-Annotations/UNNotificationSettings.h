/*
 * UNNotificationSettings.h
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

typedef NS_ENUM(NSInteger, UNAuthorizationStatus) {
    // The user has not yet made a choice regarding whether the application may post user notifications.
    UNAuthorizationStatusNotDetermined = 0,
    
    // The application is not authorized to post user notifications.
    UNAuthorizationStatusDenied,
    
    // The application is authorized to post user notifications.
    UNAuthorizationStatusAuthorized
} __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

typedef NS_ENUM(NSInteger, UNNotificationSetting) {
    // The application does not support this notification type
    UNNotificationSettingNotSupported  = 0,
    
    // The notification setting is turned off.
    UNNotificationSettingDisabled,
    
    // The notification setting is turned on.
    UNNotificationSettingEnabled,
} __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

typedef NS_ENUM(NSInteger, UNAlertStyle) {
    UNAlertStyleNone = 0,
    UNAlertStyleBanner,
    UNAlertStyleAlert,
} __IOS_AVAILABLE(10.0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNNotificationSettings : NSObject <NSCopying, NSSecureCoding>

@property (NS_NONATOMIC_IOSONLY, readonly) UNAuthorizationStatus authorizationStatus;

@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationSetting soundSetting __TVOS_PROHIBITED;
@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationSetting badgeSetting __WATCHOS_PROHIBITED;
@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationSetting alertSetting __TVOS_PROHIBITED;

@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationSetting notificationCenterSetting __TVOS_PROHIBITED;
@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationSetting lockScreenSetting __TVOS_PROHIBITED __WATCHOS_PROHIBITED;
@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationSetting carPlaySetting __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

@property (NS_NONATOMIC_IOSONLY, readonly) UNAlertStyle alertStyle __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
