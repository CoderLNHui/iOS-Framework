/*
 * UINavigationController+Tool.h
 * 🔍白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <UIKit/UIKit.h>

@interface UINavigationController (Controller)

@end


@interface UINavigationController (StackManager)

/** 寻找Navigation中的某个viewcontroler */
- (id)findViewController:(Class)className;

/** 判断是否只有一个RootViewController */
- (BOOL)isOnlyContainRootViewController;

/** RootViewController */
- (UIViewController *)rootViewController;

/** 返回指定的viewcontroler */
- (NSArray *)popToViewControllerWithClassName:(Class)className animated:(BOOL)animated;

/** pop回第n层 */
- (NSArray *)popToViewControllerWithLevel:(NSInteger)level animated:(BOOL)animated;

@end



@interface UINavigationController (Transitions)

- (void)pushViewController:(UIViewController *)controller withTransition:(UIViewAnimationTransition)transition;
- (UIViewController *)popViewControllerWithTransition:(UIViewAnimationTransition)transition;

@end
