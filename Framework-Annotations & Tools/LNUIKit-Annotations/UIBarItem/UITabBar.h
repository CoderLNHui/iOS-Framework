/*
 * File: UITabBar.h
 * Framework: UIKit
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2008-2017
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook:  http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO Join_GitHub & Wechat_Codeidea_END@
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIControl.h>
#import <UIKit/UISpringLoadedInteractionSupporting.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UITabBarItemPositioning) {
    UITabBarItemPositioningAutomatic,
    UITabBarItemPositioningFill,
    UITabBarItemPositioningCentered,
} NS_ENUM_AVAILABLE_IOS(7_0);

@class UITabBarItem;
@class UIImageView;
@protocol UITabBarDelegate;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UITabBar : UIView

@property(nullable, nonatomic, weak) id<UITabBarDelegate> delegate;     // weak reference. default is nil

// get/set UITabBarItems 默认是nil 改变时没有动画效果 按顺序展示
@property(nullable, nonatomic, copy) NSArray<UITabBarItem *> *items;        // get/set visible UITabBarItems. default is nil. changes not animated. shown in order

// 选中的item
@property(nullable, nonatomic, weak) UITabBarItem *selectedItem; // will show feedback based on mode. default is nil

// 设置Items
- (void)setItems:(nullable NSArray<UITabBarItem *> *)items animated:(BOOL)animated;   // will fade in or out or reorder and adjust spacing

// Reorder items. This will display a sheet with all the items listed, allow the user to change/reorder items and shows a 'Done' button at the top

- (void)beginCustomizingItems:(NSArray<UITabBarItem *> *)items __TVOS_PROHIBITED;   // list all items that can be reordered. always animates a sheet up. visible items not listed are fixed in place
- (BOOL)endCustomizingAnimated:(BOOL)animated __TVOS_PROHIBITED;    // hide customization sheet. normally you should let the user do it. check list of items to see new layout. returns YES if layout changed
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly, getter=isCustomizing) BOOL customizing __TVOS_PROHIBITED;
#else
- (BOOL)isCustomizing __TVOS_PROHIBITED;
#endif

/*
 The behavior of tintColor for bars has changed on iOS 7.0. It no longer affects the bar's background
 and behaves as described for the tintColor property added to UIView.
 To tint the bar's background, please use -barTintColor.
 */
// ios7之后
@property(null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(5_0);
@property(nullable, nonatomic, strong) UIColor *barTintColor NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;  // default is nil
/// Unselected items in this tab bar will be tinted with this color. Setting this value to nil indicates that UITabBar should use its default value instead.

// 未选中的Item的颜色 IOS10可用
@property (nonatomic, readwrite, copy, nullable) UIColor *unselectedItemTintColor NS_AVAILABLE_IOS(10_0) UI_APPEARANCE_SELECTOR;

/* selectedImageTintColor will be applied to the gradient image used when creating the
 selected image. Default is nil and will result in the system bright blue for selected
 tab item images. If you wish to also customize the unselected image appearance, you must
 use the image and selectedImage properties on UITabBarItem along with UIImageRenderingModeAlways
 
 Deprecated in iOS 8.0. On iOS 7.0 and later the selected image takes its color from the
 inherited tintColor of the UITabBar, which may be set separately if necessary.
 */
// ios8后废除 使用tintColor
@property(nullable, nonatomic, strong) UIColor *selectedImageTintColor NS_DEPRECATED_IOS(5_0,8_0,"Use tintColor") UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED;



/* The background image will be tiled to fit, even if it was not created via the UIImage resizableImage methods.
 */
//设置UITabBar的背景图片
@property(nullable, nonatomic, strong) UIImage *backgroundImage NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* The selection indicator image is drawn on top of the tab bar, behind the bar item icon.
 */
// 设置选中的按钮的图片
@property(nullable, nonatomic, strong) UIImage *selectionIndicatorImage NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* Default is nil. When non-nil, a custom shadow image to show instead of the default shadow image. For a custom shadow to be shown, a custom background image must also be set with -setBackgroundImage: (if the default background image is used, the default shadow image will be used).
 */
// 设置阴影图片，但必须设置backgroundImage属性
@property(nullable, nonatomic, strong) UIImage *shadowImage NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;






/*
 Default is UITabBarItemPositioningAutomatic. The tab bar items fill horizontally
 for the iPhone user interface idiom, and are centered with a default width and
 inter-item spacing (customizable with the itemWidth and itemSpacing
 properties) for the iPad idiom. When the tab bar is owned by a UITabBarController
 further heuristics may determine the positioning for UITabBarItemPositioningAutomatic.
 Use UITabBarItemPositioningFill to force the items to fill horizontally.
 Use UITabBarItemPositioningCenter to force the items to center with a default
 width (or the itemWidth, if set).
 */
// 设置定位属性 item位置
@property(nonatomic) UITabBarItemPositioning itemPositioning NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED;

/*
 Set the itemWidth to a positive value to be used as the width for tab bar items
 when they are positioned as a centered group (as opposed to filling the tab bar).
 Default of 0 or values less than 0 will be interpreted as a system-defined width.
 */
//item宽度
@property(nonatomic) CGFloat itemWidth NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;

/*
 Set the itemSpacing to a positive value to be used between tab bar items
 when they are positioned as a centered group.
 Default of 0 or values less than 0 will be interpreted as a system-defined spacing.
 */
//item间隙
@property(nonatomic) CGFloat itemSpacing NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;

/*
 Valid bar styles are UIBarStyleDefault (default) and UIBarStyleBlack.
 */
//样式
@property(nonatomic) UIBarStyle barStyle NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED;

/*
 Default is YES.
 You may force an opaque background by setting the property to NO.
 If the tab bar has a custom background image, the default is inferred from the alpha
 values of the image—YES if it has any pixel with alpha < 1.0
 If you send setTranslucent:YES to a tab bar with an opaque custom background image
 the tab bar will apply a system opacity less than 1.0 to the image.
 If you send setTranslucent:NO to a tab bar with a translucent custom background image
 the tab bar will provide an opaque background for the image using the bar's barTintColor if defined, or black
 for UIBarStyleBlack or white for UIBarStyleDefault if barTintColor is nil.
 */
//半透明
@property(nonatomic,getter=isTranslucent) BOOL translucent NS_AVAILABLE_IOS(7_0);
@end

//___________________________________________________________________________________________________


@protocol UITabBarDelegate<NSObject>
@optional

// 选中后调用
- (void)tabBar:(UITabBar *)tabBar didSelectItem:(UITabBarItem *)item; // called when a new view is selected by the user (but not programatically)




// 此四个代理方法是当Items>=6个时，当进入More页面时，开始或结束Item编辑状态的相关回调
/* called when user shows or dismisses customize sheet. you can use the 'willEnd' to set up what appears underneath.
 changed is YES if there was some change to which items are visible or which order they appear. If selectedItem is no longer visible,
 it will be set to nil.
 */

// 即将编辑时调用
- (void)tabBar:(UITabBar *)tabBar willBeginCustomizingItems:(NSArray<UITabBarItem *> *)items __TVOS_PROHIBITED;                     // called before customize sheet is shown. items is current item list

// 编辑时调用
- (void)tabBar:(UITabBar *)tabBar didBeginCustomizingItems:(NSArray<UITabBarItem *> *)items __TVOS_PROHIBITED;                      // called after customize sheet is shown. items is current item list

// 即将结束编辑时调用
- (void)tabBar:(UITabBar *)tabBar willEndCustomizingItems:(NSArray<UITabBarItem *> *)items changed:(BOOL)changed __TVOS_PROHIBITED; // called before customize sheet is hidden. items is new item list

// 结束编辑时调用
- (void)tabBar:(UITabBar *)tabBar didEndCustomizingItems:(NSArray<UITabBarItem *> *)items changed:(BOOL)changed __TVOS_PROHIBITED;  // called after customize sheet is hidden. items is new item list

@end

#if TARGET_OS_IOS
@interface UITabBar (SpringLoading) <UISpringLoadedInteractionSupporting>
@end
#endif

NS_WELCOME YOU TO Join_GitHub & Wechat_Codeidea_ASSUME_NONNULL_END










//----------------------- 【补充】 ------------------------//
//

1.UIBarMetrics和UIBarPosition

typedef NS_ENUM(NSInteger, UIBarMetrics) {
    UIBarMetricsDefault, //横屏
    UIBarMetricsCompact,//竖屏
    UIBarMetricsDefaultPrompt = 101, //横屏且设置了prompt属性  Applicable only in bars with the prompt property, such as UINavigationBar and UISearchBar
    UIBarMetricsCompactPrompt, //竖屏且设置了prompt属性
};

typedef NS_ENUM(NSInteger, UIBarPosition) {
    UIBarPositionAny = 0, //Bar在任何位置
    UIBarPositionBottom = 1, //Bar在底部
    UIBarPositionTop = 2, //Bar在顶部
    UIBarPositionTopAttached = 3, //Bar在顶部，且他的背景扩展到statusBar的区域
} NS_ENUM_AVAILABLE_IOS(7_0);















