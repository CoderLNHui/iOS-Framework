//
//  UITextField+Placeholder.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

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
- (void)setLN_Placeholder:(NSString *)placeholder;


@end
