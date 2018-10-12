/*
 * UIImageView+LNImageView.m
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import "UIImageView+LNImageView.h"

@implementation UIImageView (LNImageView)

/*
 *【根据头像的URL,返回圆形头像】
 */
- (void)ln_dealHeadViewURL:(NSString *)urlStr placeholderImageName:(NSString *)placeholderImageStr
{
    [self sd_setImageWithURL:[NSURL URLWithString:urlStr] placeholderImage:[UIImage ln_circleImageNamed:placeholderImageStr] options:0 completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL) {
        
        // 如果图片下载失败，直接返回（按SD默认做法返回显示占位图片）
        if (!image) return ;
        // 返回圆形图片赋值
        self.image = [image circleImage];
    }];
    
    // 正常返回方形头像图片
    //[self sd_setImageWithURL:[NSURL URLWithString:urlStr] placeholderImage:[UIImage imageNamed:placeholderImageStr]];
}





#pragma mark - 根据网络状态来加载图片(原图/中图/缩略图)
/*
 1.在AppDelegate didFinishLaunchingWithOptions:中开始监控网络状态
    [[AFNetworkReachabilityManager sharedManager] startMonitoring];

 2.absoluteString 提供安全（1、可将url传递服务器MD5加密，同样服务器返回本地需要MD5解密；2、）
    [[SDWebImageManager sharedManager]setCacheKeyFilter:^(NSURL *url) {
        // 所有缓存图片的key后面都有个-CoderLN后缀
        return [NSString stringWithFormat:@"%@-CoderLN", url.absoluteString];
    }];
 3.SDWebImage的图片缓存是用图片的url字符串作为key <--> UIImage
 4.可能存在BUG，导致内容错乱，这里不是直接赋值self.image = originImage;，而是SD下载 返回值
 */
- (void)ln_setOriginImage:(NSString *)originImageURL thumbnailImage:(NSString *)thumbnailImageURL placeholderImage:(UIImage *)placeholderImage completed:(LNWebImageCompletionBlock)completedBlock
{
    // 根据网络状态来加载图片
    AFNetworkReachabilityManager *mgr = [AFNetworkReachabilityManager sharedManager];
    
    // 获得原图imageFromDiskCacheForKey:从沙盒加载(SD内部会先查看内存中，如果有就直接返回（这里只获取不发请求）；如果没有然后再去沙盒中查找);
    UIImage *originImage = [[SDImageCache sharedImageCache] imageFromDiskCacheForKey:originImageURL];
    if (originImage) { // 原图已经被下载过
        // sd_setImageWithURL内部，会先查看沙盒(1.内存2.沙盒)中，查看前会取消之前下载，如果没有然后再发送请求URL下载；
        [self sd_setImageWithURL:[NSURL URLWithString:originImageURL] placeholderImage:placeholderImage completed:completedBlock];
    } else { // 原图并未下载过
        if (mgr.isReachableViaWiFi) {
            [self sd_setImageWithURL:[NSURL URLWithString:originImageURL] placeholderImage:placeholderImage completed:completedBlock];
        } else if (mgr.isReachableViaWWAN) {
            
#warning downloadOriginImageWhen3GOr4G配置项的值需要从沙盒里面获取
            // 3G\4G网络下时候要下载原图
            BOOL downloadOriginImageWhen3GOr4G = YES;
            if (downloadOriginImageWhen3GOr4G) {
                [self sd_setImageWithURL:[NSURL URLWithString:originImageURL] placeholderImage:placeholderImage completed:completedBlock];
            } else {
                [self sd_setImageWithURL:[NSURL URLWithString:thumbnailImageURL] placeholderImage:placeholderImage completed:completedBlock];
            }
        } else { // 没有可用网络
            UIImage *thumbnailImage = [[SDImageCache sharedImageCache] imageFromDiskCacheForKey:thumbnailImageURL];
            if (thumbnailImage) { // 缩略图已经被下载过
                [self sd_setImageWithURL:[NSURL URLWithString:thumbnailImageURL] placeholderImage:placeholderImage completed:completedBlock];
            } else { // 没有下载过任何图片
                // 占位图片
                [self sd_setImageWithURL:nil placeholderImage:placeholderImage completed:completedBlock];
            }
        }
    }
}



@end

