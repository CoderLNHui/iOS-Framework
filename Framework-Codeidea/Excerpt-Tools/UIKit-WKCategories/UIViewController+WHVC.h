//
//  UIViewController+WHVC.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <UIKit/UIKit.h>

@interface UIViewController (WHVC)

//找到当前视图控制器
+ (UIViewController *)wh_currentViewController;

//找到当前导航控制器
+ (UINavigationController *)wh_currentNavigatonController;

/**
 * 在当前视图控制器中添加子控制器，将子控制器的视图添加到 view 中
 *
 * @param childController 要添加的子控制器
 * @param view            要添加到的视图
 */
- (void)wh_addChildController:(UIViewController *)childController intoView:(UIView *)view;

@end
