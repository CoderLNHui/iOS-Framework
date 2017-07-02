/*
 * UIViewController+Controller.m
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */
#import "UIViewController+Controller.h"

@implementation UIViewController (Controller)

@end




@implementation UIViewController (Current)

+ (UIViewController *)findBestViewController:(UIViewController *)vc
{
    if (vc.presentedViewController)
    {
        return [self findBestViewController:vc.presentedViewController];
    }
    else if ([vc isKindOfClass:[UISplitViewController class]])
    {
        UISplitViewController* svc = (UISplitViewController*) vc;
        if (svc.viewControllers.count > 0)
        {
            return [self findBestViewController:svc.viewControllers.lastObject];
        }
        else
        {
            return vc;
        }
        
    }
    else if ([vc isKindOfClass:[UINavigationController class]])
    {
        UINavigationController* svc = (UINavigationController*) vc;
        if (svc.viewControllers.count > 0)
        {
            return [self findBestViewController:svc.topViewController];
        }
        else
        {
            return vc;
        }
        
    }
    else if ([vc isKindOfClass:[UITabBarController class]])
    {
        UITabBarController* svc = (UITabBarController *)vc;
        if (svc.viewControllers.count > 0)
        {
            return [self findBestViewController:svc.selectedViewController];
        }
        else
        {
            return vc;
        }
        
    }
    else
    {
        return vc;
    }
}

+ (UIViewController *)currentViewController
{
    UIViewController *viewController = [[UIApplication sharedApplication].delegate window].rootViewController;
    
    return [UIViewController findBestViewController:viewController];
}

+ (UINavigationController *)currentNavigatonController {
    
    UIViewController * currentViewController =  [UIViewController currentViewController];
    
    return currentViewController.navigationController;
}

@end



/************************************************************
 *  * EaseMob CONFIDENTIAL
 * __________________
 * Copyright (C) 2013-2014 EaseMob Technologies. All rights reserved.
 *
 * NOTICE: All information contained herein is, and remains
 * the property of EaseMob Technologies.
 * Dissemination of this information or reproduction of this material
 * is strictly forbidden unless prior written permission is obtained
 * from EaseMob Technologies.
 */

@implementation UIViewController (DismissKeyboard)

- (void)dismissKeyboard {
    NSNotificationCenter *nc = [NSNotificationCenter defaultCenter];
    UITapGestureRecognizer *singleTapGR =
    [[UITapGestureRecognizer alloc] initWithTarget:self
                                            action:@selector(tapAnywhereToDismissKeyboard:)];
    
    __weak UIViewController *weakSelf = self;
    
    NSOperationQueue *mainQuene =[NSOperationQueue mainQueue];
    [nc addObserverForName:UIKeyboardWillShowNotification
                    object:nil
                     queue:mainQuene
                usingBlock:^(NSNotification *note){
                    [weakSelf.view addGestureRecognizer:singleTapGR];
                }];
    [nc addObserverForName:UIKeyboardWillHideNotification
                    object:nil
                     queue:mainQuene
                usingBlock:^(NSNotification *note){
                    [weakSelf.view removeGestureRecognizer:singleTapGR];
                }];
}

- (void)tapAnywhereToDismissKeyboard:(UIGestureRecognizer *)gestureRecognizer {
    //此method会将self.view里所有的subview的first responder都resign掉
    [self.view endEditing:YES];
}


@end

