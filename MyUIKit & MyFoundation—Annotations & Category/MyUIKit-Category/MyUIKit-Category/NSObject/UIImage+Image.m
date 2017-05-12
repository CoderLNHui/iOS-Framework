//
//  UIImage+image.m
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import "UIImage+image.h"

@implementation UIImage (Image)

/*
 *【返回一张没有经过渲染的图片】
 */
- (UIImage *)ln_imageWithOriginalImage
{
    return  [self imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
}

+ (UIImage *)ln_imageWithOriginalImageName:(NSString *)imageName
{
    return [[UIImage imageNamed:imageName] ln_imageWithOriginalImage];
}



/*
 *【返回一张受保护的图片(被拉伸的)】
 */
- (UIImage *)ln_resizeImage
{
    // 获取图片的尺寸
    CGFloat width = self.size.width * 0.5;
    CGFloat height = self.size.height * 0.5;
    
    // 返回一张拉伸且受保护的图片
    return [self stretchableImageWithLeftCapWidth:width topCapHeight:height];
}

+ (instancetype)ln_resizeImage:(NSString *)imageName
{
    return [[UIImage imageNamed:imageName] ln_resizeImage];
    
}


/*
 *【根据颜色生成一张尺寸为1*1的相同颜色图片】
 */
+ (UIImage *)ln_imageWithColor:(UIColor *)color
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


/*
 *【根据传入的图片,生成一张带有边框的圆形图片】
 */
- (instancetype)ln_circleImageWithBorder:(CGFloat)borderW color:(UIColor *)borderColor {
    
    // borderWidth 表示边框的宽度
    CGFloat imageW = self.size.width + 2 * borderW;
    CGFloat imageH = imageW;
    CGSize imageSize = CGSizeMake(imageW, imageH);
    UIGraphicsBeginImageContextWithOptions(imageSize, NO, 0.0);
    CGContextRef context = UIGraphicsGetCurrentContext();
    // borderColor表示边框的颜色
    [borderColor set];
    CGFloat bigRadius = imageW * 0.5;
    CGFloat centerX = bigRadius;
    CGFloat centerY = bigRadius;
    CGContextAddArc(context, centerX, centerY, bigRadius, 0, M_PI * 2, 0);
    CGContextFillPath(context);
    CGFloat smallRadius = bigRadius - borderW;
    CGContextAddArc(context, centerX, centerY, smallRadius, 0, M_PI * 2, 0);
    CGContextClip(context);
    [self drawInRect:CGRectMake(borderW, borderW, self.size.width, self.size.height)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return newImage;
}

+ (UIImage *)ln_imageWithCircleImage:(NSString *)imageName Border:(CGFloat)borderW color:(UIColor *)borderColor {
    
    return [[self imageNamed:imageName] ln_circleImageWithBorder:borderW color:borderColor];
}



/*
 *【返回一张绘制字符串的图片】
 */
+ (UIImage *)ln_imageWithNSString:(NSString *)string font:(CGFloat)textFont color:(UIColor *)textColor clip:(BOOL)clip drawAtImage:(UIImage *)image drawAtPoint:(CGPoint)atPoint {
    
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


/*
 *【根据传入的图片,返回一张圆形图片】
 */
- (instancetype)ln_circleImage
{
    // 1.开启图形上下文
    // 比例因素:当前点与像素比例
    UIGraphicsBeginImageContextWithOptions(self.size, NO, 0);
    // 2.描述裁剪区域
    UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, self.size.width, self.size.height)];
    // 3.设置裁剪区域;
    [path addClip];
    // 4.画图片
    [self drawAtPoint:CGPointZero];
    // 5.取出图片
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    // 6.关闭上下文
    UIGraphicsEndImageContext();
    
    return image;
}

+ (instancetype)ln_circleImageNamed:(NSString *)name
{
    return [[self imageNamed:name] ln_circleImage];
}


/*
 *【返回一张抗锯齿图片】
 */
- (UIImage *)ln_imageAntialias
{
    CGFloat border = 1.0f;
    CGRect rect = CGRectMake(border, border, self.size.width-2*border, self.size.height-2*border);
    
    UIImage *img = nil;
    
    UIGraphicsBeginImageContext(CGSizeMake(rect.size.width,rect.size.height));
    [self drawInRect:CGRectMake(-1, -1, self.size.width, self.size.height)];
    img = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    UIGraphicsBeginImageContext(self.size);
    [img drawInRect:rect];
    UIImage* antiImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return antiImage;
}




/*
 *【固定宽度与固定高度】
 */
- (UIImage *)scaleWithFixedWidth:(CGFloat)width
{
    float newHeight = self.size.height * (width / self.size.width);
    CGSize size = CGSizeMake(width, newHeight);
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextTranslateCTM(context, 0.0, size.height);
    CGContextScaleCTM(context, 1.0, -1.0);
    
    CGContextSetBlendMode(context, kCGBlendModeCopy);
    CGContextDrawImage(context, CGRectMake(0.0f, 0.0f, size.width, size.height), self.CGImage);
    
    UIImage *imageOut = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return imageOut;
}

- (UIImage *)scaleWithFixedHeight:(CGFloat)height
{
    float newWidth = self.size.width * (height / self.size.height);
    CGSize size = CGSizeMake(newWidth, height);
    
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    CGContextTranslateCTM(context, 0.0, size.height);
    CGContextScaleCTM(context, 1.0, -1.0);
    
    CGContextSetBlendMode(context, kCGBlendModeCopy);
    CGContextDrawImage(context, CGRectMake(0.0f, 0.0f, size.width, size.height), self.CGImage);
    
    UIImage *imageOut = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return imageOut;
}


/*
 *【裁剪图片的一部分】
 */
- (UIImage *)croppedImageAtFrame:(CGRect)frame
{
    frame = CGRectMake(frame.origin.x * self.scale, frame.origin.y * self.scale, frame.size.width * self.scale, frame.size.height * self.scale);
    CGImageRef sourceImageRef = [self CGImage];
    CGImageRef newImageRef = CGImageCreateWithImageInRect(sourceImageRef, frame);
    UIImage *newImage = [UIImage imageWithCGImage:newImageRef scale:[self scale] orientation:[self imageOrientation]];
    CGImageRelease(newImageRef);
    return newImage;
}


/*
 *【将自身填充到指定的size】
 */
- (UIImage *)fillClipSize:(CGSize)size
{
    UIGraphicsBeginImageContext(size);
    CGContextRef imageContext = UIGraphicsGetCurrentContext();
    CGContextDrawTiledImage(imageContext, (CGRect){CGPointZero, self.size}, [self CGImage]);
    UIImage *outputImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return outputImage;
}





@end
