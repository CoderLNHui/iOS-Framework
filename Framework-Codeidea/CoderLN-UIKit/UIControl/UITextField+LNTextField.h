/*
 * UITextField+LNTextField.h
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>
#import <objc/message.h>
 
@interface UITextField (LNTextField)

#pragma mark -设置占位文字的颜色
//使用runtime交换方法、添加属性placeholderColor，快速设置TextField占位文字、占位文字颜色
@property UIColor *placeholderColor;

#pragma mark -设置占位文字（设置文字和文字颜色是没有先后顺序的）
- (void)setLN_Placeholder:(NSString *)placeholder;

@end
