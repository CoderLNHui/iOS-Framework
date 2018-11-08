/*
 * LNConst.m
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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
