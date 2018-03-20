/*
 * UILocalNotification.h 
 *
 * (c) 2007-2016
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class CLRegion;

// In iOS 8.0 and later, your application must register for user notifications using -[UIApplication registerUserNotificationSettings:] before being able to schedule and present UILocalNotifications
NS_CLASS_DEPRECATED_IOS(4_0, 10_0, "Use UserNotifications Framework's UNNotificationRequest") __TVOS_PROHIBITED
@interface UILocalNotification : NSObject<NSCopying, NSCoding>

//--------------------------- 【初始化】 ------------------------------//
//

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;



//--------------------------- 【设置通知显示的内容】 ------------------------------//
//

// timer-based scheduling
//【设置通知发出的时间】
@property(nullable, nonatomic,copy) NSDate *fireDate;
// the time zone to interpret fireDate in. pass nil if fireDate is an absolute GMT time (e.g. for an egg timer).
// pass a time zone to interpret fireDate as a wall time to be adjusted automatically upon time zone changes (e.g. for an alarm clock).
//【时区，一般不需要设置】
@property(nullable, nonatomic,copy) NSTimeZone *timeZone;

//【通知的重复间隔】，枚举
@property(nonatomic) NSCalendarUnit repeatInterval;      // 0 means don't repeat

//【重复日期】
@property(nullable, nonatomic,copy) NSCalendar *repeatCalendar;

// location-based scheduling

// set a CLRegion object to trigger the notification when the user enters or leaves a geographic region, depending upon the properties set on the CLRegion object itself. registering multiple UILocalNotifications with different regions containing the same identifier will result in undefined behavior. the number of region-triggered UILocalNotifications that may be registered at any one time is internally limited. in order to use region-triggered notifications, applications must have "when-in-use" authorization through CoreLocation. see the CoreLocation documentation for more information.
//【区域:当进入该区域时,就会发出一个通知】
@property(nullable, nonatomic,copy) CLRegion *region NS_AVAILABLE_IOS(8_0);

// when YES, the notification will only fire one time. when NO, the notification will fire every time the region is entered or exited (depending upon the CLRegion object's configuration). default is YES.
//【YES:进入某一个区域只会发出一次通知.NO:每次进入该区域都会发出通知】
@property(nonatomic,assign) BOOL regionTriggersOnce NS_AVAILABLE_IOS(8_0);

// alerts
//【设置通知的内容】
@property(nullable, nonatomic,copy) NSString *alertBody;      // defaults to nil. pass a string or localized string key to show an alert
//【用于决定alertAction是否生效】
@property(nonatomic) BOOL hasAction;                // defaults to YES. pass NO to hide launching button/slider
//【锁屏界面滑块下显示的文字】
@property(nullable, nonatomic,copy) NSString *alertAction;    // used in UIAlert button or 'slide to unlock...' slider in place of unlock
//【不需要设置】
@property(nullable, nonatomic,copy) NSString *alertLaunchImage;   // used as the launch image (UILaunchImageFile) when launch button is tapped
//【通知中心的标题】
@property(nullable, nonatomic,copy) NSString *alertTitle NS_AVAILABLE_IOS(8_2);  // defaults to nil. pass a string or localized string key

// sound
//【设置通知发出时音效】，系统默认声音
@property(nullable, nonatomic,copy) NSString *soundName;      // name of resource in app's bundle to play or UILocalNotificationDefaultSoundName

// badge
//【应用程序右上角的数字】
@property(nonatomic) NSInteger applicationIconBadgeNumber;  // 0 means no change. defaults to 0

// user info
//【额外的信息】
@property(nullable, nonatomic,copy) NSDictionary *userInfo;   // throws if contains non-property list types

// category identifer of the local notification, as set on a UIUserNotificationCategory and passed to +[UIUserNotificationSettings settingsForTypes:categories:]
//【 】
@property (nullable, nonatomic, copy) NSString *category NS_AVAILABLE_IOS(8_0);

@end


UIKIT_EXTERN NSString *const UILocalNotificationDefaultSoundName NS_DEPRECATED_IOS(4_0, 10_0, "Use UserNotifications Framework's +[UNNotificationSound defaultSound]") __TVOS_PROHIBITED;
START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

NS_ASSUME_NONNULL_END
