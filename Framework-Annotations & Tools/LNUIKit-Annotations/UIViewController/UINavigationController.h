/*
 * UINavigationController.h
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2007-2017
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIPanGestureRecognizer.h>
#import <UIKit/UITapGestureRecognizer.h>

/*!
 UINavigationController manages a stack of view controllers and a navigation bar.
 It performs horizontal view transitions for pushed and popped views while keeping the navigation bar in sync.
 
 Most clients will not need to subclass UINavigationController.
 
 If a navigation controller is nested in a tabbar controller, it uses the title and toolbar attributes of the bottom view controller on the stack.
 
 UINavigationController is rotatable if its top view controller is rotatable.
 Navigation between controllers with non-uniform rotatability is currently not supported.
 */


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UINavigationControllerOperation) {
    UINavigationControllerOperationNone,
    UINavigationControllerOperationPush,
    UINavigationControllerOperationPop,
};

UIKIT_EXTERN const CGFloat UINavigationControllerHideShowBarDuration;

@class UIView, UINavigationBar, UINavigationItem, UIToolbar;
@protocol UINavigationControllerDelegate;


NS_CLASS_AVAILABLE_IOS(2_0) @interface UINavigationController : UIViewController


/* Use this initializer to make the navigation controller use your custom bar class.
 Passing nil for navigationBarClass will get you UINavigationBar, nil for toolbarClass gets UIToolbar.
 The arguments must otherwise be subclasses of the respective UIKit classes.
 */
//UINavigationController初始化,自定义NavigationBar,自定义toolbar
- (instancetype)initWithNavigationBarClass:(nullable Class)navigationBarClass toolbarClass:(nullable Class)toolbarClass NS_AVAILABLE_IOS(5_0);

//UINavigationController初始化,导航控制器的根控制器
- (instancetype)initWithRootViewController:(UIViewController *)rootViewController; // Convenience method pushes the root view controller without animation.


//压栈：将目标控制器压入栈中
- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated; // Uses a horizontal slide transition. Has no effect if the view controller is already in the stack.

//弹栈：将栈顶控制器从栈中弹出
- (nullable UIViewController *)popViewControllerAnimated:(BOOL)animated; // Returns the popped controller.

//弹栈：弹到指定的目标控制器
- (nullable NSArray<__kindof UIViewController *> *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated; // Pops view controllers until the one specified is on top. Returns the popped controllers.

//弹栈：弹到根控制器
- (nullable NSArray<__kindof UIViewController *> *)popToRootViewControllerAnimated:(BOOL)animated; // Pops until there's only a single view controller left on the stack. Returns the popped controllers.


//导航栈的栈顶视图 只读 就是某个导航栈的栈顶视图，和导航息息相关
@property(nullable, nonatomic,readonly,strong) UIViewController *topViewController; // The top view controller on the stack.

//当前显示的控制器 只读 visibleViewController和哪个导航栈没有关系，只是当前显示的控制器，也就是说任意一个导航的visibleViewController所返回的值应该是一样的
@property(nullable, nonatomic,readonly,strong) UIViewController *visibleViewController; // Return modal view controller if it exists. Otherwise the top view controller.


//栈里的视图控制器数组
@property(nonatomic,copy) NSArray<__kindof UIViewController *> *viewControllers; // The current view controller stack.


//替换栈中的视图控制器数组
- (void)setViewControllers:(NSArray<UIViewController *> *)viewControllers animated:(BOOL)animated NS_AVAILABLE_IOS(3_0); // If animated is YES, then simulate a push or pop depending on whether the new top view controller was previously in the stack.


//是否隐藏导航栏
@property(nonatomic,getter=isNavigationBarHidden) BOOL navigationBarHidden;
//设置导航栏隐藏 是否有动画
- (void)setNavigationBarHidden:(BOOL)hidden animated:(BOOL)animated; // Hide or show the navigation bar. If animated, it will transition vertically using UINavigationControllerHideShowBarDuration.


//导航栏
@property(nonatomic,readonly) UINavigationBar *navigationBar; // The navigation bar managed by the controller. Pushing, popping or setting navigation items on a managed navigation bar is not supported.


//toolbar是否隐藏
@property(nonatomic,getter=isToolbarHidden) BOOL toolbarHidden NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // Defaults to YES, i.e. hidden.
//toolbar是否隐藏 是否有动画
- (void)setToolbarHidden:(BOOL)hidden animated:(BOOL)animated NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // Hide or show the toolbar at the bottom of the screen. If animated, it will transition vertically using UINavigationControllerHideShowBarDuration.

//toolbar对象
@property(null_resettable,nonatomic,readonly) UIToolbar *toolbar NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // For use when presenting an action sheet.






//委托
@property(nullable, nonatomic, weak) id<UINavigationControllerDelegate> delegate;

// 侧滑返回手势识别器
@property(nullable, nonatomic, readonly) UIGestureRecognizer *interactivePopGestureRecognizer NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;



//----------------------- 【IOS8特性】 ------------------------//
//

//展示视图控制器
- (void)showViewController:(UIViewController *)vc sender:(nullable id)sender NS_AVAILABLE_IOS(8_0); // Interpreted as pushViewController:animated:

/// When the keyboard appears, the navigation controller's navigationBar toolbar will be hidden. The bars will remain hidden when the keyboard dismisses, but a tap in the content area will show them.
// 键盘出现隐藏、键盘消失保持隐藏(此时轻拍显示)
@property (nonatomic, readwrite, assign) BOOL hidesBarsWhenKeyboardAppears NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;
/// When the user swipes, the navigation controller's navigationBar & toolbar will be hidden (on a swipe up) or shown (on a swipe down). The toolbar only participates if it has items.


// 向上轻扫隐藏、向下轻扫显示
@property (nonatomic, readwrite, assign) BOOL hidesBarsOnSwipe NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

/// The gesture recognizer that triggers if the bars will hide or show due to a swipe. Do not change the delegate or attempt to replace this gesture by overriding this method.
// 用于轻扫隐藏UINavigationBar与UIToolbar的手势识别器
@property (nonatomic, readonly, strong) UIPanGestureRecognizer *barHideOnSwipeGestureRecognizer NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

/// When the UINavigationController's vertical size class is compact, hide the UINavigationBar and UIToolbar. Unhandled taps in the regions that would normally be occupied by these bars will reveal the bars.
// 横屏隐藏(此时轻拍显示)、竖屏显示
@property (nonatomic, readwrite, assign) BOOL hidesBarsWhenVerticallyCompact NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;


/// When the user taps, the navigation controller's navigationBar & toolbar will be hidden or shown, depending on the hidden state of the navigationBar. The toolbar will only be shown if it has items to display.
// 轻拍隐藏、再次轻拍显示
@property (nonatomic, readwrite, assign) BOOL hidesBarsOnTap NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

/// The gesture recognizer used to recognize if the bars will hide or show due to a tap in content. Do not change the delegate or attempt to replace this gesture by overriding this method.
// 用于轻拍隐藏UINavigationBar与UIToolbar的手势识别器
@property (nonatomic, readonly, assign) UITapGestureRecognizer *barHideOnTapGestureRecognizer NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

//
//----------------------- 【IOS8特性】 ------------------------//

@end

@protocol UIViewControllerInteractiveTransitioning;
@protocol UIViewControllerAnimatedTransitioning;

@protocol UINavigationControllerDelegate <NSObject>

@optional

// Called when the navigation controller shows a new top view controller via a push, pop or setting of the view controller stack.
/*
 * 将要展示一个UIViewController
 * 参数一: UINavigationController
 * 参数二: UIViewController
 * 参数三: 是否执行动画
 */
- (void)navigationController:(UINavigationController *)navigationController willShowViewController:(UIViewController *)viewController animated:(BOOL)animated;

/*
 * 已经展示一个UIViewController
 * 参数一: UINavigationController
 * 参数二: UIViewController
 * 参数三: 是否执行动画
 */
- (void)navigationController:(UINavigationController *)navigationController didShowViewController:(UIViewController *)viewController animated:(BOOL)animated;


/*
 * 提供支持展示方向
 * 参数一: UINavigationController
 * 返回值: UIInterfaceOrientationMask
 */
- (UIInterfaceOrientationMask)navigationControllerSupportedInterfaceOrientations:(UINavigationController *)navigationController NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;


/*
 * 提供优先展示方向
 * 参数一: UINavigationController
 * 返回值: UIInterfaceOrientation
 */
- (UIInterfaceOrientation)navigationControllerPreferredInterfaceOrientationForPresentation:(UINavigationController *)navigationController NS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED;




/*
 * 提供自定义交互式过渡动画
 * 参数一: UINavigationController
 * 参数二: 由navigationController:animationControllerForOperation:fromViewController:toViewController:代理方法提供的实现了UIViewControllerAnimatedTransitioning协议的NSObject对象
 * 返回值: 实现了UIViewControllerInteractiveTransitioning协议的NSObject对象
 */
- (nullable id <UIViewControllerInteractiveTransitioning>)navigationController:(UINavigationController *)navigationController
                                   interactionControllerForAnimationController:(id <UIViewControllerAnimatedTransitioning>) animationController NS_AVAILABLE_IOS(7_0);


/*
 * 提供自定义非交互式过渡动画
 * 参数一: UINavigationController
 * 参数二: UINavigationControllerOperation, 可选项为UINavigationControllerOperationNone(无操作), UINavigationControllerOperationPush(Push操作), UINavigationControllerOperationPop(Pop操作)
 * 参数三: UIViewController, 当前可见视图控制器
 * 参数四: UIViewController, 动画结束后可见视图控制器
 * 返回值: 实现了UIViewControllerAnimatedTransitioning协议的NSObject对象
 */
- (nullable id <UIViewControllerAnimatedTransitioning>)navigationController:(UINavigationController *)navigationController
                                            animationControllerForOperation:(UINavigationControllerOperation)operation
                                                         fromViewController:(UIViewController *)fromVC
                                                           toViewController:(UIViewController *)toVC  NS_AVAILABLE_IOS(7_0);

@end



//----------------------- <#我是分割线#> ------------------------//
//


@interface UIViewController (UINavigationControllerItem)

//导航栏上面用户自定义视图
@property(nonatomic,readonly,strong) UINavigationItem *navigationItem; // Created on-demand so that a view controller may customize its navigation appearance.

//推送时隐藏bottom底部栏
@property(nonatomic) BOOL hidesBottomBarWhenPushed __TVOS_PROHIBITED; // If YES, then when this view controller is pushed into a controller hierarchy with a bottom bar (like a tab bar), the bottom bar will slide out. Default is NO.

//下级视图的导航控制器
@property(nullable, nonatomic,readonly,strong) UINavigationController *navigationController; // If this view controller has been pushed onto a navigation controller, return it.

@end




@interface UIViewController (UINavigationControllerContextualToolbarItems)

//属性设置工具条中包含的按钮
@property (nullable, nonatomic, strong) NSArray<__kindof UIBarButtonItem *> *toolbarItems NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;
- (void)setToolbarItems:(nullable NSArray<UIBarButtonItem *> *)toolbarItems animated:(BOOL)animated NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END

