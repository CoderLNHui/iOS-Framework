//
//  UIImage+image.m
//
//  Created by 白开水ln on 16/-/-.
//  Copyright (c) 2016 Apple Inc. All rights reserved.
//  https://custompbwaters.github.io    http://www.jianshu.com/p/e5b995ecf44d


#import "UIImage+image.h"

@implementation UIImage (image)

/** 返回一张没有经过渲染的图片 */
+ (UIImage *)imageWithOriginalImageName:(NSString *)imageName
{
    UIImage *image = [UIImage imageNamed:imageName];
    return  [image imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
}




/** 返回一张受保护的图片(被拉伸的) */
+ (instancetype)imageTensileAndProtectImageName: (NSString *)prImageName
{
    // 创建图片对象
    UIImage *image     = [UIImage imageNamed:prImageName];
    // 获取图片的尺寸
    CGFloat imageWidth = image.size.width;
    CGFloat imageHeiht = image.size.height;
    
    // 返回一张拉伸且受保护的图片
    return [image stretchableImageWithLeftCapWidth:imageWidth * 0.5 topCapHeight:imageHeiht * 0.5 ];
}




/** 根据颜色生成一张尺寸为1*1的相同颜色图片 */
+ (UIImage *)imageWithColor:(UIColor *)color
{
    // 描述矩形
    CGRect rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
    
    // 开启位图上下文
    UIGraphicsBeginImageContext(rect.size);
    // 获取位图上下文
    CGContextRef context = UIGraphicsGetCurrentContext();
    // 使用color演示填充上下文
    CGContextSetFillColorWithColor(context, [color CGColor]);
    // 渲染上下文
    CGContextFillRect(context, rect);
    // 从上下文中获取图片
    UIImage *theImage = UIGraphicsGetImageFromCurrentImageContext();
    // 结束上下文
    UIGraphicsEndImageContext();
    
    return theImage;
}



/**
 根据传入的图片,生成一终带有边框的圆形图片
 参数:边框宽度,边框颜色,原始图片
 */
+ (UIImage *)imageWithImage:(UIImage *)image Border:(CGFloat)borderW color:(UIColor *)borderColor
{
    
    CGSize size = CGSizeMake(image.size.width + 2*borderW, image.size.height + 2*borderW);
    // 1.开启一个跟图片原始大小的上下文
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    
    // 2.绘制大圆
    UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, size.width, size.height)];
    [borderColor set];// 边框颜色
    [path fill];
    // 设置圆形裁剪区域
    UIBezierPath *clipPath = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(borderW, borderW, image.size.width, image.size.height)];
    [clipPath addClip];
    
    // 3.把图片绘制到上下文当中
    [image drawAtPoint:CGPointMake(borderW, borderW)];
    
    // 4.从上下文当中生成一张图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    // 5.关闭上下文
    UIGraphicsEndImageContext();
    image = newImage;
    
    return image;
}




/** 返回一张绘制字符串的图片 */
+ (UIImage *)imageWithNSString:(NSString *)string font:(CGFloat)textFont color:(UIColor *)textColor clip:(BOOL)clip drawAtImage:(UIImage *)image drawAtPoint:(CGPoint)atPoint
{
    
    // 1.开启一个跟图片原始大小的上下文
    UIGraphicsBeginImageContextWithOptions(image.size, NO, 0);
    
    // 设置圆形裁剪区域
    if (clip) {
        UIBezierPath *clipPath = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, image.size.width, image.size.height)];
        [clipPath addClip];
    }
    // 2.把图片绘制到上下文当中
    [image drawAtPoint:CGPointMake(0, 0)];
    
    // 3.把文字绘制到上下文当中
    NSString *str = string;
    NSDictionary *dict = @{NSFontAttributeName:[UIFont systemFontOfSize:textFont],NSForegroundColorAttributeName:textColor};
    [str drawAtPoint:atPoint withAttributes:dict];
    
    // 4.从上下文当中生成一张图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    // 5.关闭上下文
    UIGraphicsEndImageContext();
    image = newImage;
    
    return image;
}



@end







