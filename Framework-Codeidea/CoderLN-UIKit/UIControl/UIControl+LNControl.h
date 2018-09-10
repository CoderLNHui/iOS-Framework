/*
 * UIControl+LNControl.h
 *
 * UIKit
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>

@interface UIControl (LNControl)

@end


@interface UIControl (LNDelay)

#pragma mark -每次响应的间隔
@property (assign, nonatomic) NSTimeInterval acceptEventInterval;

@end
