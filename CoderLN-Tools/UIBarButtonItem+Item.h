/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>

#pragma mark - 快速创建导航栏UIBarButtonItem
@interface UIBarButtonItem (LNItem)

#pragma mark -高亮
+ (UIBarButtonItem *)ln_itemWithImage:(UIImage *)image hightImage:(UIImage *)hightImage target:(id)target action:(SEL)action;

#pragma mark -选中
+ (UIBarButtonItem *)ln_itemWithImage:(UIImage *)image seleImage:(UIImage *)seleImage target:(id)target action:(SEL)action;

#pragma mark -返回按钮（图片+文字）
+ (UIBarButtonItem *)ln_backWithImage:(UIImage *)image hightImage:(UIImage *)hightImage target:(id)target action:(SEL)action title:(NSString *)title;



#pragma mark - UIBarButtonItem (LNBadge)徽章小红点
@interface UIBarButtonItem (LNBadge)

#pragma mark -徽章小红点
@property (strong, atomic) UILabel *badge;

#pragma mark -badge的文字
@property (nonatomic) NSString *badgeValue;

#pragma mark -背景颜色
@property (nonatomic) UIColor *badgeBGColor;

#pragma mark -文字颜色
@property (nonatomic) UIColor *badgeTextColor;

#pragma mark -文字的字体
@property (nonatomic) UIFont *badgeFont;

#pragma mark -badge的padding
@property (nonatomic) CGFloat badgePadding;

#pragma mark -最小的size
@property (nonatomic) CGFloat badgeMinSize;

#pragma mark -x坐标
@property (nonatomic) CGFloat badgeOriginX;

#pragma mark -y坐标
@property (nonatomic) CGFloat badgeOriginY;

#pragma mark -如果是数字0的话就隐藏不显示
@property BOOL shouldHideBadgeAtZero;

#pragma mark -是否要缩放动画
@property BOOL shouldAnimateBadge;

@end


