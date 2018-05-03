/*
 * CIImage+Extension.h
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <CoreImage/CoreImage.h>
#import <UIKit/UIKit.h>

@interface CIImage (Extension)

/*
 * 根据CIImage生成指定大小的UIImage
 *
 * @param size 图片宽度
 */
- (UIImage *)createNonInterpolatedWithSize:(CGFloat)size;

@end
