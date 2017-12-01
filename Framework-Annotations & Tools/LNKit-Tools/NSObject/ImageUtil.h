/*
 * ImageUtil.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
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
