//
//  NSTimer+WHTimer.m
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//

#import "NSTimer+WHTimer.h"
#import <objc/runtime.h>

static const void *s_hyb_private_currentCountTime = "s_hyb_private_currentCountTime";

@implementation NSTimer (WHTimer)

- (NSNumber *)hyb_private_currentCountTime {
    NSNumber *obj = objc_getAssociatedObject(self, s_hyb_private_currentCountTime);
    
    if (obj == nil) {
        obj = @(0);
        
        [self setHyb_private_currentCountTime:obj];
    }
    
    return obj;
}

- (void)setHyb_private_currentCountTime:(NSNumber *)time {
    objc_setAssociatedObject(self,
                             s_hyb_private_currentCountTime,
                             time, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

+ (NSTimer *)wh_scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                         count:(NSInteger)count
                                      callback:(TimerCallback)callback {
    if (count <= 0) {
        return [self wh_scheduledTimerWithTimeInterval:interval
                                               repeats:YES
                                              callback:callback];
    }
    
    NSDictionary *userInfo = @{@"callback"     : callback,
                               @"count"        : @(count)};
    return [NSTimer scheduledTimerWithTimeInterval:interval
                                            target:self
                                          selector:@selector(hyb_onTimerUpdateCountBlock:)
                                          userInfo:userInfo
                                           repeats:YES];
}

+ (NSTimer *)wh_scheduledTimerWithTimeInterval:(NSTimeInterval)interval
                                       repeats:(BOOL)repeats
                                      callback:(TimerCallback)callback {
    return [NSTimer scheduledTimerWithTimeInterval:interval
                                            target:self
                                          selector:@selector(hyb_onTimerUpdateBlock:)
                                          userInfo:callback
                                           repeats:repeats];
}

- (void)hyb_fireTimer {
    [self setFireDate:[NSDate distantPast]];
}

- (void)hyb_unfireTimer {
    [self setFireDate:[NSDate distantFuture]];
}

- (void)hyb_invalidate {
    if (self.isValid) {
        [self invalidate];
    }
}

#pragma mark - Private
+ (void)hyb_onTimerUpdateBlock:(NSTimer *)timer {
    TimerCallback block = timer.userInfo;
    
    if (block) {
        block(timer);
    }
}

+ (void)hyb_onTimerUpdateCountBlock:(NSTimer *)timer {
    NSInteger currentCount = [[timer hyb_private_currentCountTime] integerValue];
    
    NSDictionary *userInfo = timer.userInfo;
    TimerCallback callback = userInfo[@"callback"];
    NSNumber *count = userInfo[@"count"];
    
    if (currentCount < count.integerValue) {
        currentCount++;
        [timer setHyb_private_currentCountTime:@(currentCount)];
        
        if (callback) {
            callback(timer);
        }
    } else {
        currentCount = 0;
        [timer setHyb_private_currentCountTime:@(currentCount)];
        
        [timer hyb_unfireTimer];
        [timer hyb_invalidate];
    }
}

-(void)pauseTimer
{
    if (![self isValid])
    {
        return ;
    }
    
    [self setFireDate:[NSDate distantFuture]];
}

-(void)resumeTimer
{
    if (![self isValid])
    {
        return ;
    }
    
    [self setFireDate:[NSDate date]];
}

- (void)resumeTimerAfterTimeInterval:(NSTimeInterval)interval
{
    if (![self isValid])
    {
        return ;
    }
    
    [self setFireDate:[NSDate dateWithTimeIntervalSinceNow:interval]];
}

@end
