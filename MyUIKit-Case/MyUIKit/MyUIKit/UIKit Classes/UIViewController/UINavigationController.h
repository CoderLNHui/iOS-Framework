//
//  UINavigationController.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/7.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIViewController.h"

@class UINavigationBar, UIToolbar, UIViewController;

@protocol UINavigationControllerDelegate <NSObject>
@optional
- (void)navigationController:(UINavigationController *)navigationController didShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (void)navigationController:(UINavigationController *)navigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated;
@end

@interface UINavigationController : UIViewController
- (id)initWithRootViewController:(UIViewController *)rootViewController;
- (void)setViewControllers:(NSArray *)newViewControllers animated:(BOOL)animated;
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (UIViewController *)popViewControllerAnimated:(BOOL)animated;
- (NSArray *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated;
- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated;
- (void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated;                    // toolbar support is not really implemented yet
- (void)setNavigationBarHidden:(BOOL)navigationBarHidden animated:(BOOL)animated; // doesn't animate yet

@property (nonatomic, copy) NSArray *viewControllers;
@property (nonatomic, readonly, strong) UIViewController *visibleViewController;
@property (nonatomic, readonly) UINavigationBar *navigationBar;
@property (nonatomic, readonly) UIToolbar *toolbar;                               // toolbar support is not really implemented yet
@property (nonatomic, assign) id<UINavigationControllerDelegate> delegate;
@property (nonatomic, readonly, strong) UIViewController *topViewController;
@property (nonatomic, getter=isNavigationBarHidden) BOOL navigationBarHidden;
@property (nonatomic, getter=isToolbarHidden) BOOL toolbarHidden;                  // toolbar support is not really implemented yet
@end
