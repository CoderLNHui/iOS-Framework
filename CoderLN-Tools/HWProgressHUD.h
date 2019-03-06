/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>

@interface HWProgressHUD : UIView

// 显示转圈加载，调用dismiss、showMessage等方法隐藏，常用于已有视图上提交加载数据
+ (void)show;

// 显示加载，在特定视图
+ (void)showInView:(UIView *)view;

// 空页面显示加载动画，常用于未创建视图时加载数据，创建控件
+ (void)showWhilePushing;

// 加载动画，传YES显示空页面显示加载动画，传NO显示转圈加载动画
+ (void)showWhilePushing:(BOOL)pushing;

// 显示文字，默认两秒后消失
+ (void)showMessage:(NSString *)message;

// 显示文字，默认两秒后消失，在特定视图
+ (void)showMessage:(NSString *)message inView:(UIView *)view;

// 显示文字，设置显示时长
+ (void)showMessage:(NSString *)message duration:(NSTimeInterval)duration;

// 显示文字，设置显示时长，在特定视图
+ (void)showMessage:(NSString *)message duration:(NSTimeInterval)duration inView:(UIView *)view;

// 隐藏
+ (void)dismiss;

@end
