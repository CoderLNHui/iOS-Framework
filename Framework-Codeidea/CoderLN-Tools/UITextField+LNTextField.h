/*
 * UITextField+LNTextField.h
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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
