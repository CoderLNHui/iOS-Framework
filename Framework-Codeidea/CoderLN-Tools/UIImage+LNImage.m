/*
 * UIImage+Image.m
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import "UIImage+Image.h"

@implementation UIImage (Image)


#pragma mark - 返回没有被渲染的原始图片
+ (UIImage *)ln_imageWithOriginalImageName:(NSString *)imageName
{
    return [[UIImage imageNamed:imageName] ln_imageWithOriginalImage];
}

- (UIImage *)ln_imageWithOriginalImage
{
    return  [self imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
}


#pragma mark - 返回不被拉伸的原始图片
+ (instancetype)ln_resizeImage:(NSString *)imageName
{
    return [[UIImage imageNamed:imageName] ln_resizeImage];
}

- (UIImage *)ln_resizeImage
{
    // 获取图片的尺寸
    CGFloat width = self.size.width * 0.5;
    CGFloat height = self.size.height * 0.5;
    
    // 返回一张拉伸且受保护的图片
    return [self stretchableImageWithLeftCapWidth:width topCapHeight:height];
}


#pragma mark - 根据颜色生成一张指定宽高相同颜色图片
// 同等大小1:1 rect = CGRectMake(0.0f, 0.0f, 1.0f, 1.0f);
+ (UIImage *)ln_imageWithColor:(UIColor *)color width:(CGFloat)width height:(CGFloat)height
{
    // 描述矩形
    CGRect rect = CGRectMake(0.0f, 0.0f, width, height);
    // 开启同等大小图片上下文
    UIGraphicsBeginImageContext(rect.size);
    // 获取当前上下文
    CGContextRef context = UIGraphicsGetCurrentContext();
    // 使用color填充上下文
    CGContextSetFillColorWithColor(context, [color CGColor]);
    // 渲染上下文
    CGContextFillRect(context, rect);
    // 从当前上下文中获取图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    // 结束上下文
    UIGraphicsEndImageContext();
    
    return newImage;
}


#pragma mark - 绘制图片(是否为圆形且有边框)
+ (UIImage *)ln_imageWithClipAndBorder:(BOOL)clip Border:(CGFloat)borderW color:(nullable UIColor *)borderColor image:(UIImage *)image
{
    CGSize size = CGSizeMake(image.size.width + 2*borderW, image.size.height + 2*borderW);
    
    // 1.开启同等大小的图片上下文
    UIGraphicsBeginImageContextWithOptions(size, NO, 0);
    
    // 2.绘制路径
    if (clip) {
        // 绘制个大圆，作为覆盖后的边框
        UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, size.width, size.height)];
        // 边框颜色
        borderColor ? [borderColor set]:[UIColor blackColor];
        [path fill];
        
        // 绘制个小圆，设置圆形裁剪区域
        UIBezierPath *clipPath = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(borderW, borderW, image.size.width, image.size.height)];
        [clipPath addClip]; //UIRectClip(CGRectMake(0, 0, 20, 20)); // 裁剪区域
    }
    
    // 3.把图片、文字 绘制到上下文中
    [image drawAtPoint:CGPointMake(borderW, borderW)];
    //[@"我是绘制上\n的文字" drawAtPoint:CGPointMake(20, _imageView.frame.size.height/2) withAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:30],NSForegroundColorAttributeName:[UIColor blackColor]}];
    
    // 4.从上下文当中获取一张图片（把上下文当中绘制的所有内容截屏生成一张图片）
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    // 4.关闭上下文
    UIGraphicsEndImageContext();
    // 5.赋值
    image = newImage;
    
    return image;
}


#pragma mark - 返回圆形图片
+ (instancetype)ln_circleImageNamed:(NSString *)name
{
    return [[self imageNamed:name] ln_circleImage];
}

- (instancetype)ln_circleImage
{
    // 1.开启同等大小的图片上下文（大小、透明度、缩放比例：当前点与像素比例）
    UIGraphicsBeginImageContextWithOptions(self.size, NO, 0);
    // 2.设置裁剪区域、添加裁剪
    UIBezierPath *path = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, self.size.width, self.size.height)];
    [path addClip];
    // 3.绘制图片
    [self drawAtPoint:CGPointZero];
    // 4.从当前上下文获取一张图片
    UIImage * newImage = UIGraphicsGetImageFromCurrentImageContext();
    // 5.关闭图片上下文
    UIGraphicsEndImageContext();
    
    return newImage;
}




#pragma mark - 返回一张抗锯齿图片

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
    UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return newImage;
}




#pragma mark - 图片的压缩

+ (UIImage *)IMGCompressed:(UIImage *)sourceImage targetWidth:(CGFloat)defineWidth
{
    
    UIImage *newImage = nil;
    CGSize imageSize = sourceImage.size;
    CGFloat width = imageSize.width;
    CGFloat height = imageSize.height;
    CGFloat targetWidth = defineWidth;
    CGFloat targetHeight = height / (width / targetWidth);
    CGSize size = CGSizeMake(targetWidth, targetHeight);
    CGFloat scaleFactor = 0.0;
    CGFloat scaledWidth = targetWidth;
    CGFloat scaledHeight = targetHeight;
    CGPoint thumbnailPoint = CGPointMake(0.0, 0.0);
    if(CGSizeEqualToSize(imageSize, size) == NO){
        CGFloat widthFactor = targetWidth / width;
        CGFloat heightFactor = targetHeight / height;
        if(widthFactor > heightFactor){
            scaleFactor = widthFactor;
        }
        else{
            scaleFactor = heightFactor;
        }
        scaledWidth = width * scaleFactor;
        scaledHeight = height * scaleFactor;
        if(widthFactor > heightFactor){
            thumbnailPoint.y = (targetHeight - scaledHeight) * 0.5;
        }else if(widthFactor < heightFactor){
            thumbnailPoint.x = (targetWidth - scaledWidth) * 0.5;
        }
    }
    UIGraphicsBeginImageContext(size);
    CGRect thumbnailRect = CGRectZero;
    thumbnailRect.origin = thumbnailPoint;
    thumbnailRect.size.width = scaledWidth;
    thumbnailRect.size.height = scaledHeight;
    
    [sourceImage drawInRect:thumbnailRect];
    
    newImage = UIGraphicsGetImageFromCurrentImageContext();
    if(newImage == nil){
        
        NSAssert(!newImage,@"图片压缩失败");
    }
    
    UIGraphicsEndImageContext();
    return newImage;
}




#pragma mark - 加载GIF图片资源

#import <ImageIO/ImageIO.h>
@implementation UIImage (GIFImage)

#pragma mark -根据本地GIF图片名 获得GIF image对象
+ (UIImage *)imageWithGIFNamed:(NSString *)name
{
    NSUInteger scale = (NSUInteger)[UIScreen mainScreen].scale;
    return [self GIFName:name scale:scale];
}

+ (UIImage *)GIFName:(NSString *)name scale:(NSUInteger)scale
{
    NSString *imagePath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@@%zdx", name, scale] ofType:@"gif"];
    if (!imagePath) {
        (scale + 1 > 3) ? (scale -= 1) : (scale += 1);
        imagePath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"%@@%zdx", name, scale] ofType:@"gif"];
    }
    if (imagePath) {
        // 传入图片名(不包含@Nx)
        NSData *imageData = [NSData dataWithContentsOfFile:imagePath];
        return [UIImage imageWithGIFData:imageData];
    } else {
        imagePath = [[NSBundle mainBundle] pathForResource:name ofType:@"gif"];
        if (imagePath) {
            // 传入的图片名已包含@Nx or 传入图片只有一张 不分@Nx
            NSData *imageData = [NSData dataWithContentsOfFile:imagePath];
            return [UIImage imageWithGIFData:imageData];
        } else {
            // 不是一张GIF图片(后缀不是gif)
            return [UIImage imageNamed:name];
        }
    }
}


#pragma mark -根据一个GIF图片的data数据 获得GIF image对象
+ (UIImage *)imageWithGIFData:(NSData *)data
{
    if (!data) return nil;
    CGImageSourceRef source = CGImageSourceCreateWithData((__bridge CFDataRef)data, NULL);
    size_t count = CGImageSourceGetCount(source);
    UIImage *animatedImage;
    if (count <= 1) {
        animatedImage = [[UIImage alloc] initWithData:data];
    } else {
        NSMutableArray *images = [NSMutableArray array];
        NSTimeInterval duration = 0.0f;
        for (size_t i = 0; i < count; i++) {
            // 拿出了Gif的每一帧图片
            CGImageRef image = CGImageSourceCreateImageAtIndex(source, i, NULL);
            //Learning... 设置动画时长 算出每一帧显示的时长(帧时长)
            NSTimeInterval frameDuration = [UIImage sd_frameDurationAtIndex:i source:source];
            duration += frameDuration;
            // 将每帧图片添加到数组中
            [images addObject:[UIImage imageWithCGImage:image scale:[UIScreen mainScreen].scale orientation:UIImageOrientationUp]];
            // 释放真图片对象
            CFRelease(image);
        }
        // 设置动画时长
        if (!duration) {
            duration = (1.0f / 10.0f) * count;
        }
        animatedImage = [UIImage animatedImageWithImages:images duration:duration];
    }
    
    // 释放源Gif图片
    CFRelease(source);
    return animatedImage;
}

//关于GIF图片帧时长
+ (float)sd_frameDurationAtIndex:(NSUInteger)index source:(CGImageSourceRef)source
{
    float frameDuration = 0.1f;
    CFDictionaryRef cfFrameProperties = CGImageSourceCopyPropertiesAtIndex(source, index, nil);
    NSDictionary *frameProperties = (__bridge NSDictionary *)cfFrameProperties;
    NSDictionary *gifProperties = frameProperties[(NSString *)kCGImagePropertyGIFDictionary];
    NSNumber *delayTimeUnclampedProp = gifProperties[(NSString *)kCGImagePropertyGIFUnclampedDelayTime];
    if (delayTimeUnclampedProp) {
        frameDuration = [delayTimeUnclampedProp floatValue];
    }
    else {
        NSNumber *delayTimeProp = gifProperties[(NSString *)kCGImagePropertyGIFDelayTime];
        if (delayTimeProp) {
            frameDuration = [delayTimeProp floatValue];
        }
    }
    // Many annoying ads specify a 0 duration to make an image flash as quickly as possible.
    // We follow Firefox's behavior and use a duration of 100 ms for any frames that specify
    // a duration of <= 10 ms. See and
    // for more information.
    if (frameDuration < 0.011f) {
        frameDuration = 0.100f;
    }
    CFRelease(cfFrameProperties);
    return frameDuration;
}



#pragma mark -根据一个GIF图片的URL 获得GIF image对象
+ (void)imageWithGIFUrl:(NSString *)url and:(GIFimageBlock)gifImageBlock
{
    NSURL *GIFUrl = [NSURL URLWithString:url];
    if (!GIFUrl) return;
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        NSData *CIFData = [NSData dataWithContentsOfURL:GIFUrl];
        // 刷新UI在主线程
        dispatch_async(dispatch_get_main_queue(), ^{
            gifImageBlock([UIImage imageWithGIFData:CIFData]);
        });
    });
}





#pragma mark - 将Imagae按指定角度旋转后绘制图片
#define DegreesToRadians(x) (M_PI*(x)/180.0)
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees
{
    UIView *rotatedViewBox = [[UIView alloc] initWithFrame:CGRectMake(0,0,self.size.height, self.size.width)];
    rotatedViewBox.transform = CGAffineTransformMakeRotation(DegreesToRadians(degrees));
    CGSize rotatedSize = rotatedViewBox.frame.size;
    UIGraphicsBeginImageContext(rotatedSize);
    CGContextRef bitmap = UIGraphicsGetCurrentContext();
    CGContextTranslateCTM(bitmap, rotatedSize.width/2, rotatedSize.height/2);
    CGContextRotateCTM(bitmap, DegreesToRadians(degrees));
    CGContextScaleCTM(bitmap, 1.0, -1.0);
    CGContextDrawImage(bitmap, CGRectMake(-self.size.height / 2, -self.size.width / 2, self.size.height, self.size.width), [self CGImage]);
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}


#pragma mark - 裁剪图像
- (UIImage *)cutImage:(UIImage *)image
{
    //1.开启一个基于位图的图形上下文
    UIGraphicsBeginImageContextWithOptions(image.size, NO, 0.0);
    //2.创建裁剪路径
    UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:CGRectMake(0, 0, image.size.width, image.size.height) cornerRadius:10];
    //3.裁剪
    [path addClip];
    //4.画图
    [image drawInRect:CGRectMake(0, 0, image.size.width, image.size.height)];
    //5.取图
    UIImage *endImage = UIGraphicsGetImageFromCurrentImageContext();
    //6.结束上下文
    UIGraphicsEndImageContext();
    
    return endImage;
}


#pragma mark - 截屏
- (UIImage *)screenshots:(UIView *)view
{
    if (view == nil) return nil;
    
    // 1.开启同等大小的位图上下文
    UIGraphicsBeginImageContextWithOptions(view.bounds.size, NO, 0);
    // 2.获取当前上下文
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    // 3.渲染上下文的内容到view上
    [view.layer renderInContext:ctx];
    // 4.从当前上下文中获取一张图片
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    // 5.结束上下文
    UIGraphicsEndImageContext();
    
    return image;
}

@end















