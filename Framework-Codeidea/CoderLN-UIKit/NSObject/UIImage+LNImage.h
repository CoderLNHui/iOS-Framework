/*
 * UIImage+LNImage.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import <UIKit/UIKit.h>

@interface UIImage (LNImage)

#pragma mark - 返回没有被渲染的原始图片
+ (UIImage *)ln_imageWithOriginalImageName:(NSString *)imageName;
- (UIImage *)ln_imageWithOriginalImage;

#pragma mark - 返回不被拉伸的原始图片
+ (instancetype)ln_resizeImage:(NSString *)imageName;
- (UIImage *)ln_resizeImage;


#pragma mark - 根据颜色生成一张尺寸为1*1的相同颜色图片
+ (UIImage *)ln_imageWithColor:(UIColor *)color;


#pragma mark - 绘制图片(是否为圆形且有边框)
+ (UIImage *)ln_imageWithClipAndBorder:(BOOL)clip Border:(CGFloat)borderW color:(nullable UIColor *)borderColor image:(UIImage *)image;

#pragma mark - 绘制返回一张绘制字符串的图片
+ (UIImage *)ln_imageWithNSString:(NSString *)string font:(CGFloat)textFont color:(UIColor *)textColor clip:(BOOL)clip drawAtImage:(UIImage *)image drawAtPoint:(CGPoint)atPoint;

#pragma mark - 绘制返回圆形图片
+ (instancetype)ln_circleImageNamed:(NSString *)name;
- (instancetype)ln_circleImage;




#pragma mark - 返回一张抗锯齿图片
// 本质：在图片生成一个透明为1的像素边框
- (UIImage *)ln_imageAntialias;


#pragma mark - 图片的压缩
// 要被压缩的图片 、 要被压缩的尺寸(宽)
+ (UIImage *)ln_IMGCompressed:(UIImage *)sourceImg targetWidth:(CGFloat)defineWidth;





#pragma mark - 加载GIF图片资源
typedef void (^GIFimageBlock)(UIImage *GIFImage);
@interface UIImage (GIFImage)

#pragma mark -根据本地GIF图片名 获得GIF image对象
+ (UIImage *)imageWithGIFNamed:(NSString *)name;

#pragma mark -根据一个GIF图片的data数据 获得GIF image对象
+ (UIImage *)imageWithGIFData:(NSData *)data;

#pragma mark -根据一个GIF图片的URL 获得GIF image对象
+ (void)imageWithGIFUrl:(NSString *)url and:(GIFimageBlock)gifImageBlock;

#pragma mark -使用：加载GIF图片资源
/**
    方式一：本地GIF图片名
    _imgView1.image = [UIImage imageWithGIFNamed:@"xuanxuan"];

    方式二：GIF图片的data数据
    NSString *path = [[NSBundle mainBundle] pathForResource:@"xuanxuan" ofType:@"gif"];
    NSData *imgData = [NSData dataWithContentsOfFile:path];
    _imgView2.image = [UIImage imageWithGIFData:imgData];

    方式三：GIF图片的URL
    [UIImage imageWithGIFUrl:@"https://upload-images.jianshu.io/upload_images/2230763-3da3eb6ceb1f06f6.gif?imageMogr2/auto-orient/strip" and:^(UIImage *GIFImage) {
     _imgView3.image = GIFImage;
    }];
 */


#pragma mark - 将imagae按指定角度旋转后绘制图片
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;


#pragma mark - 裁剪图像
- (UIImage *)cutImage:(UIImage *)image;

#pragma mark - 截屏
- (UIImage *)screenshots:(UIView *)view;
@end





















