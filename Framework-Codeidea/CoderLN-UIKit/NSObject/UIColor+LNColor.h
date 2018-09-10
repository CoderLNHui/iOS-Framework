/*
 * UIColor+LNColor.h
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

@interface UIColor (LNColor)

#pragma mark - 十六进制字符串获取颜色
+ (UIColor *)ln_colorWithHex:(NSInteger)hex alpha:(CGFloat)alpha;
// 通过代码将”0xff6a50“ 或者 ”#ff6a50“ 这样的字符串形式值，实现为自定义的颜色
+ (UIColor *)ln_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;


#pragma mark - 生成随机颜色
+ (UIColor *)ln_randomColorWithAlpha:(CGFloat)alpha;

@end





















