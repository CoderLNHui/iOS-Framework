/*
 * UIColor+LNColor.h
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

@interface UIColor (LNColor)

#pragma mark - 十六进制字符串获取颜色
+ (UIColor *)ln_colorWithHex:(NSInteger)hex alpha:(CGFloat)alpha;
// 通过代码将”0xff6a50“ 或者 ”#ff6a50“ 这样的字符串形式值，实现为自定义的颜色
+ (UIColor *)ln_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;


#pragma mark - 生成随机颜色
+ (UIColor *)ln_randomColorWithAlpha:(CGFloat)alpha;

@end





















