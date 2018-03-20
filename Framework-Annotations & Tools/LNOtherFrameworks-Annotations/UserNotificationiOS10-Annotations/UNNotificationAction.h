/*
 * UNNotificationAction.h 
 *
 * (c) 2015
 * Framework: UserNotifications
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

/**
 UNNotificationAction，是通知中添加的action，展示在通知栏的下方。默认以的button样式展示。有一个文本输入的子类UNTextInputNotificationAction。可以在点击button之后弹出一个键盘，输入信息。用户点击信息和输入的信息可以在UNNotificationResponse中获取
 
 通知策略（Category+Action）
 action：设置标识（identifier）、按钮标题（title）、按钮选项（options）
 
 action 有2种类型：
 UNNotificationAction 普通按钮样式
 UNTextInputNotificationAction 输入框样式
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UNNotificationActionOptions) {
    
    // Whether this action should require unlocking before being performed.
    // 指定该动作是否需要用户解锁验证身份
    UNNotificationActionOptionAuthenticationRequired = (1 << 0), //【执行前需要解锁确认-认证】
    
    // Whether this action should be indicated as destructive.
    // 指定用户执行该动作是否要将通知从iOS的通知中心移除，以防止处理过该通知以后重复处理
    UNNotificationActionOptionDestructive = (1 << 1), //【显示高亮（红色⚠️）】
    
    // Whether this action should cause the application to launch in the foreground.
    /**
    【思想】: 
     指定通知action点击后是否要进入app到前台，如果到前台，这个对Notification Content Extension的自定义的通知UI有意义，可以在Extension中处理用户的点击或者提交文字，那么就可以指定该action不需要进入app，
      UNNotificationActionOptionAuthenticationRequired这个就不要加入
     */
    UNNotificationActionOptionForeground = (1 << 2), //【启动应用-前台】
} __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED;

static const UNNotificationActionOptions UNNotificationActionOptionNone NS_SWIFT_UNAVAILABLE("Use [] instead.") __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED = 0;


__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
//【普通按钮样式】
@interface UNNotificationAction : NSObject <NSCopying, NSSecureCoding>

// The unique identifier for this action.
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSString *identifier;

// The title to display for this action.
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSString *title;

// The options configured for this action.
@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationActionOptions options;

// Use -[NSString localizedUserNotificationStringForKey:arguments:] to provide a string that will be localized at the time that the notification is presented.
+ (instancetype)actionWithIdentifier:(NSString *)identifier title:(NSString *)title options:(UNNotificationActionOptions)options;

- (instancetype)init NS_UNAVAILABLE;

@end

__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
//【输入框样式】
@interface UNTextInputNotificationAction : UNNotificationAction

// Use -[NSString localizedUserNotificationStringForKey:arguments:] to provide a string that will be localized at the time that the notification is presented.
+ (instancetype)actionWithIdentifier:(NSString *)identifier title:(NSString *)title options:(UNNotificationActionOptions)options textInputButtonTitle:(NSString *)textInputButtonTitle textInputPlaceholder:(NSString *)textInputPlaceholder;

// The text input button title displayed for this action.
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSString *textInputButtonTitle;

// The placeholder text displayed in the text input field for this action.
@property (NS_NONATOMIC_IOSONLY, copy, readonly) NSString *textInputPlaceholder;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
