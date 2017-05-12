//
//  UIColor+color.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Color)

/*
 *【默认alpha位1】
 */
+ (UIColor *)colorWithHexString:(NSString *)color;


/*
 *【从十六进制字符串获取颜色】
 *
 * color:支持@“#123456”、 @“0X123456”、 @“123456”三种格式
 */
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

@end







/*
 颜色:3种颜色通道 R G B
 颜色表达方式:24位,32位
 每一个颜色通道是8位,范围(0~256)
 R:213 G:213 B:213
 
 #ffffff   -> f=15
 R:FF => 10进制 15 * 16^0 + 15 * 16^1 = 255
 G:FF 255
 B:FF 255
 
 #:美工16进制表示形式
 0x:OC16进制表达式
 */
