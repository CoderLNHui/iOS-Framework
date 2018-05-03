/*
 * File:  UITextField+TextField.h
 * Framework: UIKit
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>
#import <objc/message.h>

@interface UITextField (TextField)

/*
 *【设置占位文字的颜色】
 * @param placeholderColor  占位文字的颜色
 */
@property UIColor *placeholderColor;


/*
 *【runtime交换方法(修改UITextField的占位文字，且设置文字和文字颜色是无序的)】
 * @param placeholder       占位文字
 */
- (void)setLN_Placeholder:(NSString *)placeholder;

@end
