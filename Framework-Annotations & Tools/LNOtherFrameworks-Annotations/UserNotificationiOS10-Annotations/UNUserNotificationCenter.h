/*
 * UNUserNotificationCenter.h 
 *
 * (c) 2015
 * Framework: UserNotifications
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

/**
 UNUserNotificationCenter通知中心，用以管理通知的注册、权限获取和管理、通知的删除与更新，通过代理分发事件等。
 */

#import <Foundation/Foundation.h>

@class UNNotification;
@class UNNotificationAttachment;
@class UNNotificationCategory;
@class UNNotificationContent;
@class UNNotificationRequest;
@class UNNotificationResponse;
@class UNNotificationSettings;

@protocol UNUserNotificationCenterDelegate;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UNAuthorizationOptions) {
    UNAuthorizationOptionBadge   = (1 << 0),
    UNAuthorizationOptionSound   = (1 << 1),
    UNAuthorizationOptionAlert   = (1 << 2),
    UNAuthorizationOptionCarPlay = (1 << 3),
} __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

static const UNAuthorizationOptions UNAuthorizationOptionNone NS_SWIFT_UNAVAILABLE("Use [] instead.") __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED = 0;

// UNNotificationRequests can be scheduled using UNUserNotificationCenter. They can also be sent to the device from a server using Apple Push Notification Service. If the application is authorized then the UNNotificationRequest will be used to create a UNNotification and it will be used to notify the user. If the user acts on the UNNotification then a UNNotificationResponse will be sent to the application.

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNUserNotificationCenter : NSObject

// The delegate can only be set from an application
@property (NS_NONATOMIC_IOSONLY, nullable, weak) id <UNUserNotificationCenterDelegate> delegate;

// Returns YES if the current device supports content extensions
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL supportsContentExtensions;

// The UNUserNotificationCenter for the current application
+ (UNUserNotificationCenter *)currentNotificationCenter;

- (instancetype)init NS_UNAVAILABLE;

// User authorization is required for applications to notify the user using UNUserNotificationCenter via both local and remote notifications.
- (void)requestAuthorizationWithOptions:(UNAuthorizationOptions)options completionHandler:(void (^)(BOOL granted, NSError *__nullable error))completionHandler;

// Notification categories can be used to choose which actions will be displayed on which notifications.
- (void)setNotificationCategories:(NSSet<UNNotificationCategory *> *)categories __TVOS_PROHIBITED;
- (void)getNotificationCategoriesWithCompletionHandler:(void(^)(NSSet<UNNotificationCategory *> *categories))completionHandler __TVOS_PROHIBITED;

// The application's user notification settings
- (void)getNotificationSettingsWithCompletionHandler:(void(^)(UNNotificationSettings *settings))completionHandler;

// Notification requests can be scheduled to notify the user via time and location. See UNNotificationTrigger for more information. Calling -addNotificationRequest: will replace an existing notification request with the same identifier. A notification request with the identifier as an existing delivered notifications will alert for the new notification request and replace the existing delivered notification when it is triggered. The number of pending notification requests that may be scheduled by an application at any one time is limited by the system.
#pragma mark ------------------
#pragma mark - 【添加通知】✔️
/**
 【添加通知】
  需要先创建request，给request设置content和trigger，再添加到center
 */
- (void)addNotificationRequest:(UNNotificationRequest *)request withCompletionHandler:(nullable void(^)(NSError *__nullable error))completionHandler;



#pragma mark ------------------
#pragma mark - 【管理通知】✔️
// iOS10的推送都是通过center进行管理的。
// 通过request的identifier，进行通知的查找、更新、删除。这个标识是用来区分这个通知和其他通知的
// Notification requests that are waiting for their trigger to fire
/**
 【获取所有等待递送的通知】
 */
- (void)getPendingNotificationRequestsWithCompletionHandler:(void(^)(NSArray<UNNotificationRequest *> *requests))completionHandler;
/**
 【移除特定等待递送的通知】
 */
- (void)removePendingNotificationRequestsWithIdentifiers:(NSArray<NSString *> *)identifiers;
/**
 【移除所有等待递送的通知】
 */
- (void)removeAllPendingNotificationRequests;

// Notifications that have been delivered and remain in Notification Center. Notifiations triggered by location cannot be retrieved, but can be removed.
/**
 【获取所有已经递送的通知】
 */
- (void)getDeliveredNotificationsWithCompletionHandler:(void(^)(NSArray<UNNotification *> *notifications))completionHandler __TVOS_PROHIBITED;
/**
 【移除特定已经递送的通知】
 */
- (void)removeDeliveredNotificationsWithIdentifiers:(NSArray<NSString *> *)identifiers __TVOS_PROHIBITED;
/**
 【移除已经递送的通知】
 */
- (void)removeAllDeliveredNotifications __TVOS_PROHIBITED;

@end

typedef NS_OPTIONS(NSUInteger, UNNotificationPresentationOptions) {
    UNNotificationPresentationOptionBadge   = (1 << 0),
    UNNotificationPresentationOptionSound   = (1 << 1),
    UNNotificationPresentationOptionAlert   = (1 << 2),
} __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

static const UNNotificationPresentationOptions UNNotificationPresentationOptionNone NS_SWIFT_UNAVAILABLE("Use [] instead.") __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) = 0;

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@protocol UNUserNotificationCenterDelegate <NSObject>

@optional



// The method will be called on the delegate only if the application is in the foreground. If the method is not implemented or the handler is not called in a timely manner then the notification will not be presented. The application can choose to have the notification presented as a sound, badge, alert and/or in the notification list. This decision should be based on whether the information in the notification is otherwise visible to the user.
#pragma mark ------------------
#pragma mark - 【CenterDelegate代理回调】✔️
/**
 【通知将要显示的回调方法】：应用在前台，收到通知时触发。
 
 // 如果需要在应用在前台也展示通知
 completionHandler(UNNotificationPresentationOptionSound | UNNotificationPresentationOptionAlert);
 */
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);




// The method will be called on the delegate when the user responded to the notification by opening the application, dismissing the notification or choosing a UNNotificationAction. The delegate must be set before the application returns from applicationDidFinishLaunching:.
/**
 【操作的回调方法】：不管应用在前台、后台还是被手动划掉，下面三种情况将触发该方法。
 1.点击通知进入应用
 2.点击action
 3.清除了category是UNNotificationCategoryOptionCustomDismissAction的通知。
 */
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)())completionHandler __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
