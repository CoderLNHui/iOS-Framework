/*
 * UNNotificationContent.h 
 *
 * (c) 2015
 * Framework: UserNotifications
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <Foundation/Foundation.h>

@class UNNotificationAttachment;
@class UNNotificationSound;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNNotificationContent : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>


/**
 UNNotificationContent 通知内容，通知的title，sound，badge以及相关的图像、声音、视频附件UNNotificationAttachment，触发打开App时候指定的LacnchImage等
 */

#pragma mark ------------------
#pragma mark - 【设置推送内容】✔️

// Optional array of attachments.
//【附件】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray <UNNotificationAttachment *> *attachments __TVOS_PROHIBITED;

// The application badge number.
//【角标】
@property (NS_NONATOMIC_IOSONLY, readonly, copy, nullable) NSNumber *badge;

// The body of the notification.
//【推送内容】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *body __TVOS_PROHIBITED;

// The identifier for a registered UNNotificationCategory that will be used to determine the appropriate actions to display for the notification.
//【category标识，操作策略】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *categoryIdentifier __TVOS_PROHIBITED;

// The launch image that will be used when the app is opened from the notification.
//【点击通知进入应用的启动图】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *launchImageName __TVOS_PROHIBITED;

// The sound that will be played for the notification.
//【声音】
@property (NS_NONATOMIC_IOSONLY, readonly, copy, nullable) UNNotificationSound *sound __TVOS_PROHIBITED;

// The subtitle of the notification.
//【推送内容子标题】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *subtitle __TVOS_PROHIBITED;

// The unique identifier for the thread or conversation related to this notification request. It will be used to visually group notifications together.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *threadIdentifier __TVOS_PROHIBITED;

// The title of the notification.
//【推送内容标题】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *title __TVOS_PROHIBITED;

// Apps can set the userInfo for locally scheduled notification requests. The contents of the push payload will be set as the userInfo for remote notifications.
//【附加通知的内容】
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSDictionary *userInfo __TVOS_PROHIBITED;

@end

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNMutableNotificationContent : UNNotificationContent

// Optional array of attachments.
@property (NS_NONATOMIC_IOSONLY, copy) NSArray <UNNotificationAttachment *> *attachments __TVOS_PROHIBITED;

// The application badge number. nil means no change. 0 to hide.
@property (NS_NONATOMIC_IOSONLY, copy, nullable) NSNumber *badge;

// The body of the notification. Use -[NSString localizedUserNotificationStringForKey:arguments:] to provide a string that will be localized at the time that the notification is presented.
@property (NS_NONATOMIC_IOSONLY, copy) NSString *body __TVOS_PROHIBITED;

// The identifier for a registered UNNotificationCategory that will be used to determine the appropriate actions to display for the notification.
@property (NS_NONATOMIC_IOSONLY, copy) NSString *categoryIdentifier __TVOS_PROHIBITED;

// The launch image that will be used when the app is opened from the notification.
@property (NS_NONATOMIC_IOSONLY, copy) NSString *launchImageName __TVOS_PROHIBITED;

// The sound that will be played for the notification.
@property (NS_NONATOMIC_IOSONLY, copy, nullable) UNNotificationSound *sound __TVOS_PROHIBITED;

// The subtitle of the notification. Use -[NSString localizedUserNotificationStringForKey:arguments:] to provide a string that will be localized at the time that the notification is presented.
@property (NS_NONATOMIC_IOSONLY, copy) NSString *subtitle __TVOS_PROHIBITED;

// The unique identifier for the thread or conversation related to this notification request. It will be used to visually group notifications together.
@property (NS_NONATOMIC_IOSONLY, copy) NSString *threadIdentifier __TVOS_PROHIBITED;

// The title of the notification. Use -[NSString localizedUserNotificationStringForKey:arguments:] to provide a string that will be localized at the time that the notification is presented.
@property (NS_NONATOMIC_IOSONLY, copy) NSString *title __TVOS_PROHIBITED;

// Apps can set the userInfo for locally scheduled notification requests. The contents of the push payload will be set as the userInfo for remote notifications.
@property (NS_NONATOMIC_IOSONLY, copy) NSDictionary *userInfo;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
