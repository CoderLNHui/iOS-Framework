/*
 * UINavigationController+LNController.m
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#import "UINavigationController+Controller.h"

@implementation UINavigationController (LNController)

@end


@implementation UINavigationController (LNStackManager)

#pragma mark -寻找Navigation中的某个viewcontroler
- (id)findViewController:(Class)className;
{
    for (UIViewController *viewController in self.viewControllers)
    {
        if ([viewController isKindOfClass:className])
        {
            return viewController;
        }
    }
    
    return nil;
}

#pragma mark -判断是否只有一个RootViewController
- (BOOL)isOnlyContainRootViewController
{
    if (self.viewControllers && self.viewControllers.count == 1)
    {
        return YES;
    }
    return NO;
}

#pragma mark -获取RootViewController
- (UIViewController *)rootViewController
{
    if (self.viewControllers && [self.viewControllers count] >0)
    {
        return [self.viewControllers firstObject];
    }
    return nil;
}

#pragma mark -返回指定的viewcontroler
- (NSArray *)popToViewControllerWithClassName:(Class)className animated:(BOOL)animated;
{
    return [self popToViewController:[self findViewController:className] animated:YES];
}

#pragma mark -pop回第n层
- (NSArray *)popToViewControllerWithLevel:(NSInteger)level animated:(BOOL)animated
{
    NSInteger viewControllersCount = self.viewControllers.count;
    if (viewControllersCount > level) {
        NSInteger idx = viewControllersCount - level - 1;
        UIViewController *viewController = self.viewControllers[idx];
        return [self popToViewController:viewController animated:animated];
    } else {
        return [self popToRootViewControllerAnimated:animated];
    }
}

@end



@implementation UINavigationController (Transitions)

#pragma mark -pushVC
- (void)pushViewController:(UIViewController *)controller withTransition:(UIViewAnimationTransition)transition {
    [UIView beginAnimations:nil context:NULL];
    [self pushViewController:controller animated:NO];
    [UIView setAnimationDuration:0.5];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationTransition:transition forView:self.view cache:YES];
    [UIView commitAnimations];
}

#pragma mark -popVC
- (UIViewController *)popViewControllerWithTransition:(UIViewAnimationTransition)transition {
    [UIView beginAnimations:nil context:NULL];
    UIViewController *controller = [self popViewControllerAnimated:NO];
    [UIView setAnimationDuration:0.5];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationTransition:transition forView:self.view cache:YES];
    [UIView commitAnimations];
    return controller;
}

@end

