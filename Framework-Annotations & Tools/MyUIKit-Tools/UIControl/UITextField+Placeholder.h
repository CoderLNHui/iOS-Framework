/*
 * UITextField+Placeholder.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <UIKit/UIKit.h>

@interface UITextField (Placeholder)


/*
 *【设置占位文字的颜色】
 * @param placeholderColor  占位文字的颜色 属性
 * 通过这个属性名，就可以修改textField内部的占位文字颜色
 */
@property UIColor *placeholderColor;


/*
 *【方式四：runtime交换方法(修改UITextField的占位文字，且设置文字和文字颜色是无序的)】
 * @param placeholder       占位文字
 */
- (void)ln_setPlaceholder:(NSString *)placeholder;


@end
