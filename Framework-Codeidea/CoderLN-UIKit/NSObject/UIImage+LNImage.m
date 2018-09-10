/*
 * UIImage+Image.m
 *
 * UIKit
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
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


#pragma mark - 根据传入的图片,生成一张带有边框的圆形图片
+ (UIImage *)ln_imageWithCircleImage:(NSString *)imageName Border:(CGFloat)borderW color:(UIColor *)borderColor {
    
    return [[self imageNamed:imageName] ln_circleImageWithBorder:borderW color:borderColor];
}

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




#pragma mark - 绘制返回一张绘制字符串的图片
+ (UIImage *)ln_imageWithNSString:(NSString *)string font:(CGFloat)textFont color:(UIColor *)textColor clip:(BOOL)clip drawAtImage:(UIImage *)image drawAtPoint:(CGPoint)atPoint {
    
    // 1.开启同等大小的图片上下文
    UIGraphicsBeginImageContextWithOptions(image.size, NO, 0);
    
    // 2.设置圆形裁剪区域
    if (clip) {
        UIBezierPath *clipPath = [UIBezierPath bezierPathWithOvalInRect:CGRectMake(0, 0, image.size.width, image.size.height)];
        [clipPath addClip];
    }
    // 3.绘制图片（把图片绘制到上下文当中）
    [image drawAtPoint:CGPointMake(0, 0)];
    
    // 绘制文字
    NSString *str = string;
    NSDictionary *dict = @{NSFontAttributeName:[UIFont systemFontOfSize:textFont],NSForegroundColorAttributeName:textColor};
    [str drawAtPoint:atPoint withAttributes:dict];
    
    // 4.从当前上下文中获取一张图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    // 5.关闭图片上下文
    UIGraphicsEndImageContext();
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



@end















