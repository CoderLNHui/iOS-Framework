/*
 * LNConst.h 常用常量（在.h声明 / 在.m实现）
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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
