/*
 * UNNotificationCategory.h 
 *
 * UserNotifications (c) 2015
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
/**
 UNNotificationCategory,用以定义一组样式类型，该分类包含了某一个通知包含的交互动作的组合，比如说UNNotificationRequest内包含了一个Category标示，那该通知就会以预定义好的交互按钮或者文本框添加到通知实体上。
 
 category：设置标识（identifier）、actions、intentIdentifiers（需要填写你想要添加到哪个推送消息的 id）、策略选项（options）
 
 
 
 */

#import <Foundation/Foundation.h>

@class UNNotificationAction;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UNNotificationCategoryOptions) {
    UNNotificationCategoryOptionNone = (0),
    
    // Whether dismiss action should be sent to the UNUserNotificationCenter delegate
    UNNotificationCategoryOptionCustomDismissAction = (1 << 0), //【当清除当前通知时，会走center的delegate】
    
    // Whether notifications of this category should be allowed in CarPlay
    UNNotificationCategoryOptionAllowInCarPlay = (2 << 0), //【适用于行车模式】
    
} __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED;

__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
@interface UNNotificationCategory : NSObject <NSCopying, NSSecureCoding>

// The unique identifier for this category. The UNNotificationCategory's actions will be displayed on notifications when the UNNotificationCategory's identifier matches the UNNotificationRequest's categoryIdentifier.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *identifier;

// The UNNotificationActions in the order they will be displayed.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray<UNNotificationAction *> *actions;

// The intents supported support for notifications of this category. See <Intents/INIntentIdentifiers.h> for possible values.
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSArray<NSString *> *intentIdentifiers;

@property (NS_NONATOMIC_IOSONLY, readonly) UNNotificationCategoryOptions options;

+ (instancetype)categoryWithIdentifier:(NSString *)identifier actions:(NSArray<UNNotificationAction *> *)actions intentIdentifiers:(NSArray<NSString *> *)intentIdentifiers options:(UNNotificationCategoryOptions)options;

- (instancetype)init NS_UNAVAILABLE;

@end

CoderLN_NOTE NS_ASSUME_NONNULL_END
