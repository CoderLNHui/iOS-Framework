//
//  UIImage+image.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Image)

/*
 *【返回一张没有经过渲染的图片】
 * @param imageName  原始的图片
 */
+ (UIImage *)ln_imageWithOriginalImageName:(NSString *)imageName;

- (UIImage *)ln_imageWithOriginalImage;


/*
 *【返回一张受保护的图片(被拉伸的)】
 * @param prImageName   原始的图片
 */
+ (instancetype)ln_resizeImage:(NSString *)imageName;

- (UIImage *)ln_resizeImage;


/*
 *【根据颜色生成一张尺寸为1*1的相同颜色图片】
 * @param color  颜色
 */
+ (UIImage *)ln_imageWithColor:(UIColor *)color;


/*
 *【根据传入的图片,生成一张带有边框的圆形图片】
 *
 * @param image         原始图片
 * @param borderW       边框宽度
 * @param borderColor   边框颜色
 */
+ (UIImage *)ln_imageWithCircleImage:(NSString *)imageName Border:(CGFloat)borderW color:(UIColor *)borderColor;

- (instancetype)ln_circleImageWithBorder:(CGFloat)borderW color:(UIColor *)borderColor;

/*
 *【返回一张绘制字符串的图片】
 */
+ (UIImage *)ln_imageWithNSString:(NSString *)string font:(CGFloat)textFont color:(UIColor *)textColor clip:(BOOL)clip drawAtImage:(UIImage *)image drawAtPoint:(CGPoint)atPoint;


/*
 *【根据传入的图片,返回一张圆形图片】
 */
- (instancetype)ln_circleImage;

/*
 *【根据传入的图片,返回一张圆形图片】
 */
+ (instancetype)ln_circleImageNamed:(NSString *)name;


/*
 *【返回一张抗锯齿图片】
 * 本质：在图片生成一个透明为1的像素边框
 */
- (UIImage *)ln_imageAntialias;


/*
 *【固定宽度与固定高度】
 */
- (UIImage *)scaleWithFixedWidth:(CGFloat)width;
- (UIImage *)scaleWithFixedHeight:(CGFloat)height;


/*
 *【裁剪图片的一部分】
 */
- (UIImage *)croppedImageAtFrame:(CGRect)frame;


/*
 *【将自身填充到指定的size】
 */
- (UIImage *)fillClipSize:(CGSize)size;



@end





















