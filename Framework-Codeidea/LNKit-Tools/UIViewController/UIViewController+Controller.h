/*
 * UIViewController+Controller.h
 *
 * Framework: UIKit
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>

@interface UIViewController (Controller)

@end



@interface UIViewController (Current)

//找到当前视图控制器
+ (UIViewController *)currentViewController;

//找到当前导航控制器
+ (UINavigationController *)currentNavigatonController;

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

@interface UIViewController (DismissKeyboard)


/**
 退下键盘：此method会将self.view里所有的subview的first responder都resign掉
 */
- (void)dismissKeyboard;
@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

