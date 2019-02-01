/*
 * UIStoryboard.h
 *
 * UIKit (c) 2011-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

@class UIViewController;

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(5_0) @interface UIStoryboard : NSObject {
}

+ (UIStoryboard *)storyboardWithName:(NSString *)name bundle:(nullable NSBundle *)storyboardBundleOrNil;

- (nullable __kindof UIViewController *)instantiateInitialViewController;
- (__kindof UIViewController *)instantiateViewControllerWithIdentifier:(NSString *)identifier;

@end
NS_ASSUME_NONNULL_END
