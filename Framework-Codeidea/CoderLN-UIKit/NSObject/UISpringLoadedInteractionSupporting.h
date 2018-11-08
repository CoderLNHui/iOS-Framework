/*
 * UISpringLoadedInteractionSupporting.h
 *
 * UIKit (c) 2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UISpringLoadedInteractionSupporting <NSObject>

@property (nonatomic, assign, getter=isSpringLoaded) BOOL springLoaded UIKIT_AVAILABLE_IOS_ONLY(11_0);

@end
NS_ASSUME_NONNULL_END

