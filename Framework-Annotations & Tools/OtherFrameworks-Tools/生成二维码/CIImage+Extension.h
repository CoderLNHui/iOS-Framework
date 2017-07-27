/*
 * CIImage+Extension.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
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
