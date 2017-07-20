/*
 * ImageUtil.h
 * 🔍白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <Foundation/Foundation.h>

@interface ImageUtil : NSObject

//添加文字
+(UIImage *)ln_addText:(UIImage *)image text:(NSString *)text;

//添加图片
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage;

//添加图片和文字
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage text:(NSString *)text;

//截屏
+ (UIImage *)ln_screenShot:(UIView *)view;

@end
