/*
 * File: ImageUtil.m
 *
 * Framework: UIKit
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import "ImageUtil.h"

@implementation ImageUtil

//添加文字水印
+ (UIImage *)ln_addText:(UIImage *)useImage text:(NSString *)text
{
    float width = useImage.size.width;
    float height = useImage.size.height;
    UIGraphicsBeginImageContext(useImage.size);
    [useImage drawInRect:CGRectMake(0, 0, useImage.size.width, useImage.size.height)];
    
    [text drawAtPoint:CGPointMake(width/2, height-20) withAttributes:@{NSFontAttributeName:[UIFont fontWithName:@"Georgia" size:15],NSForegroundColorAttributeName:[UIColor whiteColor]}];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return resultingImage;
}

//图片
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage
{
    float width = useImage.size.width;
    float height = useImage.size.height;
    UIGraphicsBeginImageContext(useImage.size);
    [useImage drawInRect:CGRectMake(0, 0, useImage.size.width, useImage.size.height)];
    
    [newImage drawInRect:CGRectMake(width/2, height-20, 18, 18)];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return resultingImage;
}

//图片和文字
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage text:(NSString *)text
{
    float width = useImage.size.width;
    float height = useImage.size.height;
    UIGraphicsBeginImageContext(useImage.size);
    [useImage drawInRect:CGRectMake(0, 0, useImage.size.width, useImage.size.height)];
    
    [newImage drawInRect:CGRectMake(width/2, height-20, 18, 18)];
    [text drawAtPoint:CGPointMake(width/2 + 25, height-20) withAttributes:@{NSFontAttributeName:[UIFont fontWithName:@"Georgia" size:15],NSForegroundColorAttributeName:[UIColor whiteColor]}];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return resultingImage;
}

//截屏
+ (UIImage *)ln_screenShot:(UIView *)view
{
    CGRect mainRect = [[UIScreen mainScreen] bounds];
    
    UIGraphicsBeginImageContext(mainRect.size);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextFillRect(context, mainRect);
    [view.layer renderInContext:context];
    
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return newImage;
}

@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
