/*
 * UITextField+LNTextField.h
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
#import <objc/message.h>
 
@interface UITextField (LNTextField)

#pragma mark -设置占位文字的颜色
//使用runtime交换方法、添加属性placeholderColor，快速设置TextField占位文字、占位文字颜色
@property UIColor *placeholderColor;

#pragma mark -设置占位文字（设置文字和文字颜色是没有先后顺序的）
- (void)setLN_Placeholder:(NSString *)placeholder;

@end
