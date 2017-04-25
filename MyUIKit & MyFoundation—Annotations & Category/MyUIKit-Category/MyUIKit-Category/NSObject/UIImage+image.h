//
//  UIImage+image.h
//
//  Created by 白开水ln on 16/-/-.
//  Copyright (c) 2016 Apple Inc. All rights reserved.
//  https://custompbwaters.github.io    http://www.jianshu.com/p/e5b995ecf44d

/**
 在分类中 @property 只会生成set,get方法.并不会生成下划线的成员属性
 
 写分类:避免跟其他开发者产生冲突,最好加上前缀
 
 
 */

#import <UIKit/UIKit.h>

@interface UIImage (image)


/**
 *  返回一张没有经过渲染的图片
 *
 *  @param imageName 图片名称
 */
+ (UIImage *)imageWithOriginalImageName:(NSString *)imageName;


/**
 *  返回一张受保护的图片(被拉伸的)
 *
 *  @param prImageName 图片名称
 */
+ (instancetype)imageTensileAndProtectImageName: (NSString *)prImageName;


/**
 *  根据颜色生成一张尺寸为1*1的相同颜色图片
 *
 *  @param color 颜色
 */
+ (UIImage *)imageWithColor:(UIColor *)color;


/**
 *  根据传入的图片,生成一终带有边框的圆形图片
 *
 *  @param image        原始图片
 *  @param borderW      边框宽度
 *  @param borderColor  边框颜色
 */
+ (UIImage *)imageWithImage:(UIImage *)image Border:(CGFloat)borderW color:(UIColor *)borderColor;


/**
 *  返回一张绘制字符串的图片
 *
 *  @param string       字符串
 *  @param textFont     字体大小
 *  @param textColor    字体颜色
 *  @param clip         是否裁剪
 *  @param image        原始图片
 *  @param atPoint      文字位置
 */
+ (UIImage *)imageWithNSString:(NSString *)string font:(CGFloat)textFont color:(UIColor *)textColor clip:(BOOL)clip drawAtImage:(UIImage *)image drawAtPoint:(CGPoint)atPoint;









@end
