/*
 * UIImageView+LNImageView.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#import <UIKit/UIKit.h>

// Block定义成变量
typedef void(^LNWebImageCompletionBlock)(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL);

@interface UIImageView (LNImageView)

#pragma mark - 传入头像URL圆角处理
- (void)ln_dealHeadViewURL:(NSString *)urlStr placeholderImageName:(NSString *)placeholderImageStr;



#pragma mark - 根据网络状态来加载图片(原图/中图/缩略图)
/**
 根据网络状态来加载图片(原图/中图/缩略图)
   原图的URL地址
   缩略图的URL地址
   占位图片
   返回下载完成的图片image, 原图的URL地址imageURL
 */
- (void)ln_setOriginImage:(NSString *)originImageURL thumbnailImage:(NSString *)thumbnailImageURL placeholderImage:(UIImage *)placeholderImage completed:(LNWebImageCompletionBlock)completedBlock;

@end

