/*
 * UIImageView+ImageView.m
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import "UIImageView+ImageView.h"

@implementation UIImageView (ImageView)

/*
 *【根据头像的URL,返回圆形头像】
 */
- (void)ln_setHeader:(NSString *)headerUrl placeholderImage:(NSString *)plaImageName
{
    //【返回圆形头像图片】
    [self sd_setImageWithURL:[NSURL URLWithString:headerUrl] placeholderImage:[UIImage ln_circleImageNamed:plaImageName] options:0 completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL) {
        //【判断图片下载失败,直接返回（按SD默认做法返回显示占位图片）】
        if (!image) return ;
        
        // 根据传入的图片,返回一张圆形图片
        self.image = [image ln_circleImage];
    }];
    
    //【正常返回方形头像图片】
    //[self sd_setImageWithURL:[NSURL URLWithString:headerUrl] placeholderImage:[UIImage imageNamed:plaImageName]];
}



/*
 *【根据网络状态来加载图片(原图/中图/缩略图)】
 */
//【在AppDelegate didFinishLaunchingWithOptions:中】开始监控网络状态
// [[AFNetworkReachabilityManager sharedManager] startMonitoring];

- (void)ln_setOriginImage:(NSString *)originImageURL thumbnailImage:(NSString *)thumbnailImageURL placeholderImage:(UIImage *)placeholderImage completed:(LNWebImageCompletionBlock)completedBlock
{
    //    [[SDWebImageManager sharedManager]setCacheKeyFilter:^(NSURL *url) {
    //        // 所有缓存图片的key后面都有个-xmg后缀
    //        return [NSString stringWithFormat:@"%@-xmg", url.absoluteString];
    //    }];
    
    // 根据网络状态来加载图片
    AFNetworkReachabilityManager *mgr = [AFNetworkReachabilityManager sharedManager];
    // 获得原图【(SDWebImage的图片缓存是用图片的 url字符串作为key <--> UIImage)】
    //【imageFromDiskCacheForKey:】从沙盒加载(SD内部会先看内存中,有 直接返回;没有 然后再去沙盒中查找); 只获取,不发请求
    UIImage *originImage = [[SDImageCache sharedImageCache] imageFromDiskCacheForKey:originImageURL];
    
    if (originImage) { // 原图已经被下载过
        // 可能存在BUG，导致内容错乱，这里不是直接赋值，而是SD下载 返回值
        // sd_setImageWithURL内部，【会先查看沙盒(1.内存2.沙盒)中】，如果没有然后去URL下载；会取消之前下载
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
                self.image = thumbnailImage;
            } else { // 没有下载过任何图片
                // 占位图片（不是直接赋值self.image = thumbnailImage;，而是SD下载返回值）
                [self sd_setImageWithURL:nil placeholderImage:placeholderImage completed:completedBlock];
            }
        }
    }
}



@end
