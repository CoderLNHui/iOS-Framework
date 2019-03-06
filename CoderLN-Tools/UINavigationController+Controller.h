/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>

@interface UINavigationController (LNController)

@end


@interface UINavigationController (LNStackManager)

#pragma mark -寻找Navigation中的某个viewcontroler
- (id)findViewController:(Class)className;

#pragma mark -判断是否只有一个RootViewController
- (BOOL)isOnlyContainRootViewController;

#pragma mark -获取RootViewController
- (UIViewController *)rootViewController;

#pragma mark -返回指定的viewcontroler
- (NSArray *)popToViewControllerWithClassName:(Class)className animated:(BOOL)animated;

#pragma mark -pop回第n层
- (NSArray *)popToViewControllerWithLevel:(NSInteger)level animated:(BOOL)animated;

@end



@interface UINavigationController (LNTransitions)

#pragma mark -pushVC
- (void)pushViewController:(UIViewController *)controller withTransition:(UIViewAnimationTransition)transition;

#pragma mark -popVC
- (UIViewController *)popViewControllerWithTransition:(UIViewAnimationTransition)transition;

@end
 
