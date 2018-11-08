/*
 * UIImageView+LNImageView.h
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

