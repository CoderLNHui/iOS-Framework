/*
 * LNConst.m
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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
