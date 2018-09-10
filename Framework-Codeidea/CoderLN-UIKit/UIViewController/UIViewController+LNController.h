/*
 * UIViewController+LNController.h
 *
 * UIKit
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
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


