/*
 * UISpringLoadedInteractionSupporting.h
 *
 * UIKit (c) 2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UISpringLoadedInteractionSupporting <NSObject>

@property (nonatomic, assign, getter=isSpringLoaded) BOOL springLoaded UIKIT_AVAILABLE_IOS_ONLY(11_0);

@end
NS_ASSUME_NONNULL_END

