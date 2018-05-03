/*
 * UIBarButtonItem+Item.h
 *
 * Framework: UIKit
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (Item)

/*
 *【创建UIBarButtonItem,高亮】
 *
 * @param image      普通状态下的图片
 * @param hightImage 高亮状态下的图片
 * @param target     一般为self
 * @param action     BarButton点击方法
 */
+ (UIBarButtonItem *)ln_itemWithImage:(UIImage *)image hightImage:(UIImage *)hightImage target:(id)target action:(SEL)action;


/*
 *【创建UIBarButtonItem,选中】
 *
 * @param image      普通状态下的图片
 * @param seleImage  选中状态下的图片
 * @param target     一般为self
 * @param action     BarButton点击方法
 */
+ (UIBarButtonItem *)ln_itemWithImage:(UIImage *)image seleImage:(UIImage *)seleImage target:(id)target action:(SEL)action;


/*
 *【创建UIBarButtonItem,高亮,标题文字】
 *
 * @param image      普通状态下的图片
 * @param hightImage 高亮状态下的图片
 * @param target     一般为self
 * @param action     BarButton点击方法
 * @param title      标题文字
 */
+ (UIBarButtonItem *)ln_backWithImage:(UIImage *)image hightImage:(UIImage *)hightImage target:(id)target action:(SEL)action title:(NSString *)title;







//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//

@interface UIBarButtonItem (Badge)

@property (strong, atomic) UILabel *badge;

/** badge的文字 */
@property (nonatomic) NSString *badgeValue;

/** 背景颜色 */
@property (nonatomic) UIColor *badgeBGColor;

/** 文字颜色 */
@property (nonatomic) UIColor *badgeTextColor;

/** 文字的字体 */
@property (nonatomic) UIFont *badgeFont;

/** badge的padding */
@property (nonatomic) CGFloat badgePadding;

/** 最小的size */
@property (nonatomic) CGFloat badgeMinSize;

/** x坐标 */
@property (nonatomic) CGFloat badgeOriginX;

/** y坐标 */
@property (nonatomic) CGFloat badgeOriginY;

/** 如果是数字0的话就隐藏不显示 */
@property BOOL shouldHideBadgeAtZero;

/** 是否要缩放动画 */
@property BOOL shouldAnimateBadge;

@end



@interface UIBarButtonItem (Extension)
+ (instancetype)itemWithImage:(NSString *)image highImage:(NSString *)highImage target:(id)target action:(SEL)action;


@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
