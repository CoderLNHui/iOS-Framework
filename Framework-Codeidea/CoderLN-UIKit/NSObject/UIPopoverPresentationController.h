/*
 * UIPopoverPresentationController.h
 *
 * UIKit (c) 2014-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#pragma mark - 释义
/**
 From the time a popover is presented until the time it is dismissed, UIKit uses an instance of this class to manage the presentation behavior. You use instances of this class as-is to configure aspects of the popover appearance and behavior for view controllers whose presentation style is set to popover

 从一个popover（也就是弹出的窗口）被presented（呈现）到被dismissed（退出）的期间，UIkit使用UIPopoverPresentationController的实例来管理呈现的行为。我们可以使用这个实例来为那些呈现的样式为popover的控制器设置popover的各个方面的外观和行为

 以气泡方式弹出显示的控制器
 */



#import <UIKit/UIPresentationController.h>
#import <UIKit/UIPopoverSupport.h>
#import <UIKit/UIPopoverBackgroundView.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPopoverPresentationController;

__TVOS_PROHIBITED
#pragma mark - 代理方法（定制Popover的行为）
@protocol UIPopoverPresentationControllerDelegate <UIAdaptivePresentationControllerDelegate>
@optional

- (void)prepareForPopoverPresentation:(UIPopoverPresentationController *)popoverPresentationController;

// Called on the delegate when the popover controller will dismiss the popover. Return NO to prevent the
// dismissal of the view.
#pragma mark -点击蒙版popover消失，默认YES，所以该方法可以不用实现。
- (BOOL)popoverPresentationControllerShouldDismissPopover:(UIPopoverPresentationController *)popoverPresentationController;

// Called on the delegate when the user has taken action to dismiss the popover. This is not called when the popover is dimissed programatically.
- (void)popoverPresentationControllerDidDismissPopover:(UIPopoverPresentationController *)popoverPresentationController;

// -popoverPresentationController:willRepositionPopoverToRect:inView: is called on your delegate when the
// popover may require a different view or rectangle.
- (void)popoverPresentationController:(UIPopoverPresentationController *)popoverPresentationController willRepositionPopoverToRect:(inout CGRect *)rect inView:(inout UIView  * __nonnull * __nonnull)view;

@end



#pragma mark - 气泡展示控制器
NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UIPopoverPresentationController : UIPresentationController

#pragma mark - 常用属性
#pragma mark -代理
@property (nullable, nonatomic, weak) id <UIPopoverPresentationControllerDelegate> delegate;

#pragma mark -设置popover的箭头（表示允许的方向）
@property (nonatomic, assign) UIPopoverArrowDirection permittedArrowDirections;

#pragma mark -弹出的位置（指定popover指向的View）
@property (nullable, nonatomic, strong) UIView *sourceView;

#pragma mark -箭头的位置（指定popover指向的矩形）
@property (nonatomic, assign) CGRect sourceRect;

// By default, a popover is not allowed to overlap its source view rect.
// When this is set to YES, popovers with more content than available space are allowed to overlap the source view rect in order to accommodate the content.
#pragma mark -popover是否可以和它的源视图矩形重叠，默认是false。
//如果为true的话，表示popover的内容比可用空间更大时被允许重叠源视图以容纳内容
@property (nonatomic, assign) BOOL canOverlapSourceViewRect NS_AVAILABLE_IOS(9_0);

#pragma mark -pop点击按钮（指定popover指向UIBarButtonItem）
@property (nullable, nonatomic, strong) UIBarButtonItem *barButtonItem;

// Returns the direction the arrow is pointing on a presented popover. Before presentation, this returns UIPopoverArrowDirectionUnknown.
#pragma mark -设置popover的箭头（获取箭头的指向）
@property (nonatomic, readonly) UIPopoverArrowDirection arrowDirection;

// By default, a popover disallows interaction with any view outside of the popover while the popover is presented.
// This property allows the specification of an array of UIView instances which the user is allowed to interact with
// while the popover is up.
#pragma mark - 存放当popover显示的时候，可以和用户交互的视图
@property (nullable, nonatomic, copy) NSArray<UIView *> *passthroughViews;

// Set popover background color. Set to nil to use default background color. Default is nil.
#pragma mark - popover的背景视图颜色
@property (nullable, nonatomic, copy) UIColor *backgroundColor;

// Clients may wish to change the available area for popover display. The default implementation of this method always
// returns insets which define 10 points from the edges of the display, and presentation of popovers always accounts
// for the status bar. The rectangle being inset is always expressed in terms of the current device orientation; (0, 0)
// is always in the upper-left of the device. This may require insets to change on device rotation.
#pragma mark - 设置popover的外观
@property (nonatomic, readwrite) UIEdgeInsets popoverLayoutMargins;

// Clients may customize the popover background chrome by providing a class which subclasses `UIPopoverBackgroundView`
// and which implements the required instance and class methods on that class.
#pragma mark - 这个属性可以是UIPopoverBackgroundView的子类，
// 也可以自定义一个UIView但是必须遵守UIPopoverBackgroundViewMethods协议并实现这个协议的响应方法。这个协议可以设置箭头的位置、高度以及它的contentView的inset
@property (nullable, nonatomic, readwrite, strong) Class <UIPopoverBackgroundViewMethods> popoverBackgroundViewClass;

@end

NS_ASSUME_NONNULL_END

