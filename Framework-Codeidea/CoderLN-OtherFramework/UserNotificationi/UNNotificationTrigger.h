/*
 * UNNotificationTrigger.h 
 *
 * UserNotifications (c) 2015
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>

@class CLRegion;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
@interface UNNotificationTrigger : NSObject <NSCopying, NSSecureCoding>

@property (NS_NONATOMIC_IOSONLY, readonly) BOOL repeats;

- (instancetype)init NS_UNAVAILABLE;

@end


#pragma mark ------------------
#pragma mark - 【设置通知触发器(4种)】✔️

// UNPushNotificationTrigger can be sent from a server using Apple Push Notification Service.
__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
/**
 UNPushNotificationTrigger 
【触发APNS服务，系统自动设置（这是区分本地通知和远程通知的标识）】
 */
@interface UNPushNotificationTrigger : UNNotificationTrigger

@end

// UNTimeIntervalNotificationTrigger can be scheduled on the device to notify after the time interval, and optionally repeat.
__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
/**
 UNTimeIntervalNotificationTrigger 
【一段时间后触发】
 */
@interface UNTimeIntervalNotificationTrigger : UNNotificationTrigger

@property (NS_NONATOMIC_IOSONLY, readonly) NSTimeInterval timeInterval;

+ (instancetype)triggerWithTimeInterval:(NSTimeInterval)timeInterval repeats:(BOOL)repeats;

- (nullable NSDate *)nextTriggerDate;

@end

// UNCalendarNotificationTrigger can be scheduled on the device to notify based on date and time values, and optionally repeat. For example, if a notification should be delivered at the next 8:00 AM then set the 'hour' property of dateComponents to 8. If the notification should be delivered every day at 8:00 AM then set repeats to YES.
__IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0)
/**
 UNCalendarNotificationTrigger 
【指定日期触发】
 */
@interface UNCalendarNotificationTrigger : UNNotificationTrigger

@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSDateComponents *dateComponents;

// The next date is calculated using matching date components.
+ (instancetype)triggerWithDateMatchingComponents:(NSDateComponents *)dateComponents repeats:(BOOL)repeats;

- (nullable NSDate *)nextTriggerDate;

@end

// UNLocationNotificationTrigger can be scheduled on the device to notify when the user enters or leaves a geographic region. The identifier on CLRegion must be unique. Scheduling multiple UNNotificationRequests with different regions containing the same identifier will result in undefined behavior. The number of UNLocationNotificationTriggers that may be scheduled by an application at any one time is limited by the system. Applications must have "when-in-use" authorization through CoreLocation. See the CoreLocation documentation for more information.
__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
/**
 UNLocationNotificationTrigger
【根据位置触发，支持进入某地或者离开某地或者都有】
 */
@interface UNLocationNotificationTrigger : UNNotificationTrigger

@property (NS_NONATOMIC_IOSONLY, readonly, copy) CLRegion *region;

+ (instancetype)triggerWithRegion:(CLRegion *)region repeats:(BOOL)repeats __WATCHOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
