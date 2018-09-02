/*
 * UIViewController+LNController.h
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
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


