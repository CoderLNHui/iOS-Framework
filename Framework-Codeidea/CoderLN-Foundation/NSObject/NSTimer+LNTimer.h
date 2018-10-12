/*
 * NSTimer+LNTimer.h
 *
 * Foundation
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import <Foundation/Foundation.h>

@interface NSTimer (LNTimer)

#pragma mark - 创建Timer
+ (id)scheduledTimerWithTimeInterval:(NSTimeInterval)inTimeInterval block:(void (^)())inBlock repeats:(BOOL)inRepeats;

+ (id)timerWithTimeInterval:(NSTimeInterval)inTimeInterval block:(void (^)())inBlock repeats:(BOOL)inRepeats;

#pragma mark - 暂停NSTimer
- (void)pauseTimer;

#pragma mark - 开始NSTimer
- (void)resumeTimer;

#pragma mark - 延迟开始NSTimer
- (void)resumeTimerAfterTimeInterval:(NSTimeInterval)interval;


@end

