/*
 * File: ImageUtil.h
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
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
