/**
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


/* CoreAnimation - CADisplayLink.h
 
 Copyright (c) 2009-2017, Apple Inc.
 All rights reserved. */

#import <QuartzCore/CABase.h>
#import <Foundation/NSObject.h>

@class NSString, NSRunLoop;

NS_ASSUME_NONNULL_BEGIN

/** Class representing a timer bound to the display vsync. **/

CA_CLASS_AVAILABLE_IOS(3.1, 9.0, 2.0)
@interface CADisplayLink : NSObject
{
@private
    void *_impl;
}

/* Create a new display link object for the main display. It will
 * invoke the method called 'sel' on 'target', the method has the
 * signature '(void)selector:(CADisplayLink *)sender'. */

// 初始化定时器
+ (CADisplayLink *)displayLinkWithTarget:(id)target selector:(SEL)sel;

/* Adds the receiver to the given run-loop and mode. Unless paused, it
 * will fire every vsync until removed. Each object may only be added
 * to a single run-loop, but it may be added in multiple modes at once.
 * While added to a run-loop it will implicitly be retained. */

// 添加到runloop
- (void)addToRunLoop:(NSRunLoop *)runloop forMode:(NSRunLoopMode)mode;

/* Removes the receiver from the given mode of the runloop. This will
 * implicitly release it when removed from the last mode it has been
 * registered for. */

// 从runloop中移除
- (void)removeFromRunLoop:(NSRunLoop *)runloop forMode:(NSRunLoopMode)mode;

/* Removes the object from all runloop modes (releasing the receiver if
 * it has been implicitly retained) and releases the 'target' object. */
// 销毁
- (void)invalidate;

/* The current time, and duration of the display frame associated with
 * the most recent target invocation. Time is represented using the
 * normal Core Animation conventions, i.e. Mach host time converted to
 * seconds. */

@property(readonly, nonatomic) CFTimeInterval timestamp;//时间戳
@property(readonly, nonatomic) CFTimeInterval duration;//持续时间

/* The next timestamp that the client should target their render for. */
// 客户端应为其渲染目标设置的下一个时间戳
@property(readonly, nonatomic) CFTimeInterval targetTimestamp CA_AVAILABLE_IOS_STARTING(10.0, 10.0, 3.0);

/* When true the object is prevented from firing. Initial state is
 * false. */

@property(getter=isPaused, nonatomic) BOOL paused;//暂停

/* Defines how many display frames must pass between each time the
 * display link fires. Default value is one, which means the display
 * link will fire for every display frame. Setting the interval to two
 * will cause the display link to fire every other display frame, and
 * so on. The behavior when using values less than one is undefined.
 * DEPRECATED - use preferredFramesPerSecond. */

@property(nonatomic) NSInteger frameInterval //帧间隔
CA_AVAILABLE_BUT_DEPRECATED_IOS (3.1, 10.0, 9.0, 10.0, 2.0, 3.0, "use preferredFramesPerSecond");

/* Defines the desired callback rate in frames-per-second for this
 * display link. The default value is 60. If set to zero, the
 * display link will fire at the native cadence of the display hardware.
 * The display link will make a best-effort attempt at issuing callbacks
 * at the requested rate. */
//每秒优先帧数
@property(nonatomic) NSInteger preferredFramesPerSecond CA_AVAILABLE_IOS_STARTING(10.0, 10.0, 3.0);

@end

NS_ASSUME_NONNULL_END

