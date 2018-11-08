/*
 * LNConst.h 常用常量（在.h声明 / 在.m实现）
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>


/** UITabBar的高度 */
UIKIT_EXTERN CGFloat const LNTabBarH;

/** 导航栏的最大Y值 */
UIKIT_EXTERN CGFloat const LNNavMaxY;

/** 标题栏的高度 */
UIKIT_EXTERN CGFloat const LNTitlesViewH;

/** TabBarBtn被重复点击的通知 */
UIKIT_EXTERN NSString * const LNTabBarButtonDidRepeatClickNotification;

/** TitleBtn被重复点击的通知 */
UIKIT_EXTERN NSString * const LNTitleButtonDidRepeatClickNotification;

/** 发布按钮被重复点击的通知 */
UIKIT_EXTERN NSString * const LNPublishBtnClickNotification;

/** 全局统一的间距10 */
UIKIT_EXTERN CGFloat const LNMarin;

/** 统一的请求基本URL */
UIKIT_EXTERN NSString * const LNbasicURL;
