/*
 * UIControl+LNControl.h
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 作用：
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>

@interface UIControl (LNControl)

@end


@interface UIControl (LNDelay)

#pragma mark -每次响应的间隔
@property (assign, nonatomic) NSTimeInterval acceptEventInterval;

@end
