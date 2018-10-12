/*
 * UIControl+LNControl.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import <UIKit/UIKit.h>

@interface UIControl (LNControl)

@end


@interface UIControl (LNDelay)

#pragma mark -每次响应的间隔
@property (assign, nonatomic) NSTimeInterval acceptEventInterval;

@end
