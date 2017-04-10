//  完全实现
//  UIViewController+UIPrivate.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/7.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIViewController.h"

@interface UIViewController (UIPrivate)
- (void)_setParentViewController:(UIViewController *)theViewController;
@end
