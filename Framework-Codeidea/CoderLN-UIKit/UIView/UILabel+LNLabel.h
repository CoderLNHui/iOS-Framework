/*
 * UILabel+LNLabel.h
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <UIKit/UIKit.h>

@interface UILabel (LNLabel)
 
#pragma mark - 设置字间距
- (void)ln_setColumnSpace:(CGFloat)columnSpace;

#pragma mark - 设置行距
- (void)ln_setRowSpace:(CGFloat)rowSpace;

@end
 
