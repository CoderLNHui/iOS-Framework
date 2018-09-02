/*
 * LNConst.m
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 作用：常用常量 - 阶段总结
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>

/** UITabBar的高度 */
CGFloat const LNTabBarH = 49;

/** 导航栏的最大Y值 */
CGFloat const LNNavMaxY = 64;

/** 标题栏的高度 */
CGFloat const LNTitlesViewH = 35;

/** 全局统一的间距10 */
CGFloat const LNMarin = 10;

/** TabBarBtn被重复点击的通知 */
NSString * const LNTabBarButtonDidRepeatClickNotification = @"tabBarButtonDidRepeatClickNotification";

/** TitleBtn被重复点击的通知 */
NSString * const LNTitleButtonDidRepeatClickNotification = @"titleButtonDidRepeatClickNotification";

/** 发布按钮被重复点击的通知 */
NSString * const LNPublishBtnClickNotification = @"publishBtnClickNotification";

/** 统一的请求基本URL */
NSString * const LNbasicURL = @"http://api.budejie.com/api/api_open.php";
