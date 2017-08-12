/*
 * NSRunLoop.h
 * 🔍白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 1994-2016
 *
 * Created by 【🔍Plainboiledwaterln】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * @白开水LN_LICENSE_HEADER_如人饮水,冷暖自知_END@
 */


#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>
#import <CoreFoundation/CFRunLoop.h>

@class NSTimer, NSPort, NSArray<ObjectType>, NSString;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSRunLoopMode const NSDefaultRunLoopMode;// (默认):同一时间只能执行一个任务
FOUNDATION_EXPORT NSRunLoopMode const NSRunLoopCommonModes NS_AVAILABLE(10_5, 2_0); // (公用):可以分配一定的时间处理定时器

@interface NSRunLoop : NSObject {
@private
    id          _rl;
    id          _dperf;
    id          _perft;
    id          _info;
    id		_ports;
    void	*_reserved[6];
}

#if FOUNDATION_SWIFT_SDK_EPOCH_AT_LEAST(8)
/**
 获取当前线程的RunLoop:有的话就直接获取，没有的话就自动创建
 */
@property (class, readonly, strong) NSRunLoop *currentRunLoop;
/**
 获取主线程的NSRunLoop
 */
@property (class, readonly, strong) NSRunLoop *mainRunLoop NS_AVAILABLE(10_5, 2_0);

#endif



/**
 获取当前runloop的执行模式,readonly
 */
@property (nullable, readonly, copy) NSRunLoopMode currentMode;

/**
 获取RunLoop的CFRunLoopRef对象
 */
- (CFRunLoopRef)getCFRunLoop CF_RETURNS_NOT_RETAINED;

/**
 将定时器添加到runloop中
 */
- (void)addTimer:(NSTimer *)timer forMode:(NSRunLoopMode)mode;

/**
 添加输入源端口到runloop中，NSPort对象可以理解为详细的载体，会传递消息与其代理。
 */
- (void)addPort:(NSPort *)aPort forMode:(NSRunLoopMode)mode;
/**
 将某个输入源端口移除
 */
- (void)removePort:(NSPort *)aPort forMode:(NSRunLoopMode)mode;

/**
 获取下个响应时间
【注解】：定时器的执行，其实并不是按照时间段额间隔进行调用方法，而是在定时器注册到RunLoop中后，RunLoop会设置一个一个的时间点进行调用，例如，5,10,15,20等等。如果错过了某个时间点，定时器并不会延迟调用，而是直接等待下一个时间点调用，所以定时器并不是准确的。
 */
- (nullable NSDate *)limitDateForMode:(NSRunLoopMode)mode;
/**
 在某个时间期限前接收相应
 */
- (void)acceptInputForMode:(NSRunLoopMode)mode beforeDate:(NSDate *)limitDate;

@end



#pragma mark ------------------
#pragma mark - 【NSRunLoopConveniences】
@interface NSRunLoop (NSRunLoopConveniences)

/**
 开始运行
 */
- (void)run;
/**
 到某个时间点运行
 */
- (void)runUntilDate:(NSDate *)limitDate;
/**
 在某个期限前运行
 */
- (BOOL)runMode:(NSRunLoopMode)mode beforeDate:(NSDate *)limitDate;

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))
- (void)configureAsServer NS_DEPRECATED(10_0, 10_5, 2_0, 2_0);
#endif

/// Schedules the execution of a block on the target run loop in given modes.
/// - parameter: modes   An array of input modes for which the block may be executed.
/// - parameter: block   The block to execute
- (void)performInModes:(NSArray<NSRunLoopMode> *)modes block:(void (^)(void))block API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));

/// Schedules the execution of a block on the target run loop.
/// - parameter: block   The block to execute
- (void)performBlock:(void (^)(void))block API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));

@end



/**************** 	Delayed perform	延迟执行 ******************/

@interface NSObject (NSDelayedPerforming)

/**
 针对当前线程
 */
- (void)performSelector:(SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay inModes:(NSArray<NSRunLoopMode> *)modes;
- (void)performSelector:(SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay;


/**
 取消，在当前线程，和上面两个方法对应
 */
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(nullable id)anArgument;
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget;

@end

@interface NSRunLoop (NSOrderedPerform)

/**
 
 */
- (void)performSelector:(SEL)aSelector target:(id)target argument:(nullable id)arg order:(NSUInteger)order modes:(NSArray<NSRunLoopMode> *)modes;
- (void)cancelPerformSelector:(SEL)aSelector target:(id)target argument:(nullable id)arg;
- (void)cancelPerformSelectorsWithTarget:(id)target;

@end

NS_ASSUME_NONNULL_JIANSHU-LIUNAN_END
