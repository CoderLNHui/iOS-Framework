/*
 * NSNotificationQueue.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 1994-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */

#import <Foundation/NSObject.h>
#import <Foundation/NSRunLoop.h>

@class NSNotification, NSNotificationCenter, NSArray<ObjectType>, NSString;

NS_ASSUME_NONNULL_BEGIN

#pragma mark ------------------
#pragma mark - 发送方式
// NSPostingStyle包括三种类型
typedef NS_ENUM(NSUInteger, NSPostingStyle) {
    NSPostWhenIdle = 1, // 空闲发送通知 当运行循环处于等待或空闲状态时，发送通知，对于不重要的通知可以使用。
    NSPostASAP = 2, // 尽快发送通知 当前运行循环迭代完成时，通知将会被发送，有点类似没有延迟的定时器。
    NSPostNow = 3 // 同步发送通知 如果不使用合并通知 和postNotification:一样是同步通知。
};


// NSNotificationCoalescing也包括三种类型
typedef NS_OPTIONS(NSUInteger, NSNotificationCoalescing) {
    NSNotificationNoCoalescing = 0, // 不合并通知。
    NSNotificationCoalescingOnName = 1, // 合并相同名称的通知
    NSNotificationCoalescingOnSender = 2 // 合并相同通知和同一对象的通知
};
/**
 注解：
 通过合并我们可以用来保证相同的通知只被发送一次。
 forModes:(nullable NSArray<NSRunLoopMode> *)modes可以使用不同的NSRunLoopMode配合来发送通知，可以看出实际上NSNotificationQueue与RunLoop的机制以及运行循环有关系，通过NSNotificationQueue队列来发送的通知和关联的RunLoop运行机制来进行的。
 */

@interface NSNotificationQueue : NSObject {
@private
    id		_notificationCenter;
    id		_asapQueue;
    id		_asapObs;
    id		_idleQueue;
    id		_idleObs;
}
#if FOUNDATION_SWIFT_SDK_EPOCH_AT_LEAST(8)
@property (class, readonly, strong) NSNotificationQueue *defaultQueue;
#endif

#pragma mark ------------------
#pragma mark - 创建通知队列方法
- (instancetype)initWithNotificationCenter:(NSNotificationCenter *)notificationCenter NS_DESIGNATED_INITIALIZER;


#pragma mark ------------------
#pragma mark - 往队列加入通知方法(异步)
- (void)enqueueNotification:(NSNotification *)notification postingStyle:(NSPostingStyle)postingStyle;
- (void)enqueueNotification:(NSNotification *)notification postingStyle:(NSPostingStyle)postingStyle coalesceMask:(NSNotificationCoalescing)coalesceMask forModes:(nullable NSArray<NSRunLoopMode> *)modes;


#pragma mark ------------------
#pragma mark - 移除队列中的通知方法
- (void)dequeueNotificationsMatching:(NSNotification *)notification coalesceMask:(NSUInteger)coalesceMask;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
