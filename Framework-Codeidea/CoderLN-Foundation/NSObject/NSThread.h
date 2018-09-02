/*
 * File:  NSThread.h
 *
 * Framework: Foundation (c) 1994-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 作用：线程
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSNotification.h>

@class NSArray<ObjectType>, NSMutableDictionary, NSDate, NSNumber, NSString;

NS_ASSUME_NONNULL_BEGIN

@interface NSThread : NSObject  {
@private
    id _private;
    uint8_t _bytes[44];
}

@property (class, readonly, strong) NSThread *currentThread;// 当前线程

/**
 创建方式二：分离子线程,自动启动线程
 */
+ (void)detachNewThreadWithBlock:(void (^)(void))block API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));
+ (void)detachNewThreadSelector:(SEL)selector toTarget:(id)target withObject:(nullable id)argument;

+ (BOOL)isMultiThreaded;


@property (readonly, retain) NSMutableDictionary *threadDictionary;


/**
 阻塞线程（延迟执行）-> 进入阻塞状态
 */
+ (void)sleepUntilDate:(NSDate *)date;
+ (void)sleepForTimeInterval:(NSTimeInterval)ti;


/**
 强制停止线程-> 进入死亡状态
 */
+ (void)exit;



/**
 设置优先级（取值范围 0.0 ~ 1.0 之间 最高是1.0 默认优先级是0.5
 
 验证：threadPriority 线程优先级，优先级高的CPU就会调度的次数多❓
 结果：最后打印顺序是 线程C 线程B 线程A
 场景：同时开多条子线程执行任务时，可设置那个任务优先执行。
 */
+ (double)threadPriority;
+ (BOOL)setThreadPriority:(double)p;

@property double threadPriority API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)); // To be deprecated; use qualityOfService below

@property NSQualityOfService qualityOfService API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)); // read-only after the thread is started

@property (class, readonly, copy) NSArray<NSNumber *> *callStackReturnAddresses API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
@property (class, readonly, copy) NSArray<NSString *> *callStackSymbols API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@property NSUInteger stackSize API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@property (readonly) BOOL isMainThread API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
@property (class, readonly) BOOL isMainThread API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)); // reports whether current thread is main
@property (class, readonly, strong) NSThread *mainThread API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

- (instancetype)init API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithTarget:(id)target selector:(SEL)selector object:(nullable id)argument API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
- (instancetype)initWithBlock:(void (^)(void))block API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));

@property (readonly, getter=isExecuting) BOOL executing API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
@property (readonly, getter=isFinished) BOOL finished API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
@property (readonly, getter=isCancelled) BOOL cancelled API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

- (void)cancel API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

- (void)start API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

- (void)main API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));    // thread body method

@end

FOUNDATION_EXPORT NSNotificationName const NSWillBecomeMultiThreadedNotification;
FOUNDATION_EXPORT NSNotificationName const NSDidBecomeSingleThreadedNotification;
FOUNDATION_EXPORT NSNotificationName const NSThreadWillExitNotification;

@interface NSObject (NSThreadPerformAdditions)


/**
 回到主线程
 */
- (void)performSelectorOnMainThread:(SEL)aSelector withObject:(nullable id)arg waitUntilDone:(BOOL)wait modes:(nullable NSArray<NSString *> *)array;
- (void)performSelectorOnMainThread:(SEL)aSelector withObject:(nullable id)arg waitUntilDone:(BOOL)wait;
// equivalent to the first method with kCFRunLoopCommonModes

- (void)performSelector:(SEL)aSelector onThread:(NSThread *)thr withObject:(nullable id)arg waitUntilDone:(BOOL)wait modes:(nullable NSArray<NSString *> *)array API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
- (void)performSelector:(SEL)aSelector onThread:(NSThread *)thr withObject:(nullable id)arg waitUntilDone:(BOOL)wait API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
// equivalent to the first method with kCFRunLoopCommonModes
- (void)performSelectorInBackground:(SEL)aSelector withObject:(nullable id)arg API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

@end

NS_ASSUME_NONNULL_END
