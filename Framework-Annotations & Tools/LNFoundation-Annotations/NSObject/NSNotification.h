/*
 * NSNotification.h 
 *
 * (c) 1994-2016
 * Framework: Foundation
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */


#import <Foundation/NSObject.h>

typedef NSString *NSNotificationName NS_EXTENSIBLE_STRING_ENUM;

@class NSString, NSDictionary, NSOperationQueue;

NS_ASSUME_NONNULL_BEGIN

/****************	Notifications	****************/

#pragma mark ------------------
#pragma mark - 属性
@interface NSNotification : NSObject <NSCopying, NSCoding>

/** 通知的标识名称(一般为常量字符串) */
@property (readonly, copy) NSNotificationName name;

/** 任意想要携带的对象(通常为发送者自己,可为nil) */
@property (nullable, readonly, retain) id object;

/** 关于通知的附加信息(可为nil) */
@property (nullable, readonly, copy) NSDictionary *userInfo;

/**
 
 */
- (instancetype)initWithName:(NSNotificationName)name object:(nullable id)object userInfo:(nullable NSDictionary *)userInfo NS_AVAILABLE(10_6, 4_0) NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end



@interface NSNotification (NSNotificationCreation)

#pragma mark ------------------
#pragma mark - 初始化方法

+ (instancetype)notificationWithName:(NSNotificationName)aName object:(nullable id)anObject;
+ (instancetype)notificationWithName:(NSNotificationName)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo; // 有附加信息

- (instancetype)init /*NS_UNAVAILABLE*/;	/* do not invoke; not a valid initializer for this class */

@end

/****************	Notification Center	****************/

@interface NSNotificationCenter : NSObject {
    @package
    void *_impl;
    void *_callback;
    void *_pad[11];
}

#if FOUNDATION_SWIFT_SDK_EPOCH_AT_LEAST(8)

/** 获取通知中心 */
@property (class, readonly, strong) NSNotificationCenter *defaultCenter;


#pragma mark ------------------
#pragma mark - 注册观察者（添加监听）

// 注册观察者（添加监听）
/*
 * @param Observer: 观察者
 * @param selector: 只要一监听到通知,就会调用观察者这个方法
 * @param Name: 通知名称也是通知的唯一标示，编译器就是通过这个找到通知的。
 * @param object: 谁发出的通知,表示会对哪个发送者对象发出的事件作出响应，nil 时表示接受所有发送者的事件
 * 注意: 有注册就一定有移除。
 */
- (void)addObserver:(id)observer selector:(SEL)aSelector name:(nullable NSNotificationName)aName object:(nullable id)anObject;


// 注册观察者（block方式）
/*
 * @param Name: 通知名称
 * @param object: 谁发出的通知
 * @param queue: 决定block在哪个线程执行,nil:在发布通知的线程中执行
 *               [NSOperationQueue mainQueue]: 一般都是使用主队列
 * @param usingBlock: 只要监听到通知,就会执行这个block
 * 注意: 有注册就一定有移除。
 */
- (id <NSObject>)addObserverForName:(nullable NSNotificationName)name object:(nullable id)obj queue:(nullable NSOperationQueue *)queue usingBlock:(void (^)(NSNotification *note))block NS_AVAILABLE(10_6, 4_0);
#endif



#pragma mark ------------------
#pragma mark - 发送通知

- (void)postNotification:(NSNotification *)notification;
- (void)postNotificationName:(NSNotificationName)aName object:(nullable id)anObject;
- (void)postNotificationName:(NSNotificationName)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;
/*
 注：三种方式都是发送NSNotification对象给通知中心注册的所有观察者。
 发送通知通过name和object来确定来标识观察者，name和object两个参数的规则相同即当通知设置name为kChangeNotifition时，那么只会发送给符合name为kChangeNotifition的观察者，同理object指发送给某个特定对象通知，如果只设置了name，那么只有对应名称的通知会触发。如果同时设置name和object参数时就必须同时符合这两个条件的观察者才能接收到通知。

*/



#pragma mark ------------------
#pragma mark - 移除观察者（移除监听）
// 注：传入相应的需要移除的observer 或者使用第二种方式三个参数来移除指定某个观察者。

- (void)removeObserver:(id)observer;
- (void)removeObserver:(id)observer name:(nullable NSNotificationName)aName object:(nullable id)anObject;


// The return value is retained by the system, and should be held onto by the caller in
// order to remove the observer with removeObserver: later, to stop observation.

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
