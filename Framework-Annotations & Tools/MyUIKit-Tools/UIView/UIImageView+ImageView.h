/*
 * UIImageView+ImageView.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <UIKit/UIKit.h>
#import <UIImageView+WebCache.h>

//【Block基本使用】
typedef void(^LNWebImageCompletionBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL);

@interface UIImageView (ImageView)

/*
 *【根据头像的URL,返回圆形头像】
 * @param headerUrl    头像的URL地址
 */
- (void)ln_setHeader:(NSString *)headerUrl placeholderImage:(NSString *)plaImageName;


/*
 *【根据网络状态来加载图片(原图/中图/缩略图)】
 *
 * @param originImageURL    原图的URL地址
 * @param thumbnailImageURL 缩略图的URL地址
 * @param placeholder       占位图片
 * @param completedBlock    返回下载完成的图片image, 原图的URL地址imageURL
 */
- (void)ln_setOriginImage:(NSString *)originImageURL thumbnailImage:(NSString *)thumbnailImageURL placeholderImage:(UIImage *)placeholderImage completed:(LNWebImageCompletionBlock)completedBlock;


@end
