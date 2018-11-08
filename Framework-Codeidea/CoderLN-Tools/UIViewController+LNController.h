/*
 * UIViewController+LNController.h
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>

@interface UIViewController (LNController)

@end

@interface UIViewController (LNCurrent)

#pragma mark -找到当前视图控制器
+ (UIViewController *)currentViewController;

#pragma mark -找到当前导航控制器
+ (UINavigationController *)currentNavigatonController;

@end


@interface UIViewController (LNDismissKeyboard)

#pragma mark -退下键盘：此method会将self.view里所有的subview的firstResponder都resign掉
- (void)dismissKeyboard;
@end


