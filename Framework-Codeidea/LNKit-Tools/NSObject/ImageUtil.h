/*
 * File: ImageUtil.h
 *
 * Framework: UIKit
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
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
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
