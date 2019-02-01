/*
 * UNNotificationContent.h 
 *
 * UserNotifications (c) 2015
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#import <Foundation/Foundation.h>


/**
 UNNotificationContent
 通知内容，通知的title，sound，badge以及相关的图像、声音、视频附件UNNotificationAttachment，触发打开App时候指定的启动图LacnchImage等
 */


@class UNNotificationAttachment;
@class UNNotificationSound;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 不可变通知内容
__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNNotificationContent : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

#pragma mark - 设置推送的内容 ✔️
// Optional array of attachments.
#pragma mark -附件
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray <UNNotificationAttachment *> *attachments __TVOS_PROHIBITED;

// The application badge number.
#pragma mark -角标
@property (NS_NONATOMIC_IOSONLY, readonly, copy, nullable) NSNumber *badge;

// The body of the notification.
#pragma mark -推送内容
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *body __TVOS_PROHIBITED;

// The identifier for a registered UNNotificationCategory that will be used to determine the appropriate actions to display for the notification.
#pragma mark -种类标识 
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *categoryIdentifier __TVOS_PROHIBITED;

// The launch image that will be used when the app is opened from the notification.
#pragma mark -点击通知进入应用的启动图
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *launchImageName __TVOS_PROHIBITED;

// The sound that will be played for the notification.
#pragma mark -通知声音
@property (NS_NONATOMIC_IOSONLY, readonly, copy, nullable) UNNotificationSound *sound __TVOS_PROHIBITED;

// The subtitle of the notification.
#pragma mark -推送内容子标题
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *subtitle __TVOS_PROHIBITED;

// The unique identifier for the thread or conversation related to this notification request. It will be used to visually group notifications together.
#pragma mark -发送通知所在的线程
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *threadIdentifier __TVOS_PROHIBITED;

// The title of the notification.
#pragma mark -推送内容标题
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *title __TVOS_PROHIBITED;

// Apps can set the userInfo for locally scheduled notification requests. The contents of the push payload will be set as the userInfo for remote notifications.
#pragma mark -通知附加的内容
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSDictionary *userInfo __TVOS_PROHIBITED;

@end

#pragma mark - 可变通知内容
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

CoderLN_NOTE NS_ASSUME_NONNULL_END

