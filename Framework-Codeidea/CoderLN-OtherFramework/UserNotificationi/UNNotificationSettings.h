/*
 * UNNotificationSettings.h 
 *
 * UserNotifications (c) 2015
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
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

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
