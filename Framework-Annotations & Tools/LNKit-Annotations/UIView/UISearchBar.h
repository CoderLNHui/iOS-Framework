/*
 * UISearchBar.h 
 *
 * (c) 2008-2017
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UITextField.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIBarButtonItem.h>
#import <UIKit/UIBarCommon.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UISearchBarIcon) {
    UISearchBarIconSearch, // The magnifying glass
    UISearchBarIconClear __TVOS_PROHIBITED, // The circle with an x in it
    UISearchBarIconBookmark __TVOS_PROHIBITED, // The open book icon
    UISearchBarIconResultsList __TVOS_PROHIBITED, // The list lozenge icon
};

typedef NS_ENUM(NSUInteger, UISearchBarStyle) {
    UISearchBarStyleDefault,    // currently UISearchBarStyleProminent
    UISearchBarStyleProminent,  // used my Mail, Messages and Contacts
    UISearchBarStyleMinimal     // used by Calendar, Notes and Music
} NS_ENUM_AVAILABLE_IOS(7_0);


@protocol UISearchBarDelegate;
@class UITextField, UILabel, UIButton, UIColor;

/*
 UISearchBar officially conformed to UITextInputTraits in iOS 8.0 and privately conformed in iOS 7.0. Prior to 7.0, UISearchBar only implemented these four traits: autocapitalizationType, autocorrectionType, spellCheckingType and keyboardType. If your deployment target is <7.0 and you are using any trait other than one of the four mentioned, you must check its availability with respondsToSelector:
 */


NS_CLASS_AVAILABLE_IOS(2_0) @interface UISearchBar : UIView <UIBarPositioning, UITextInputTraits>
#pragma mark - ↑
#pragma mark - 初始化

- (instancetype)init __TVOS_PROHIBITED;
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER __TVOS_PROHIBITED;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER __TVOS_PROHIBITED;


#pragma mark - ↑
#pragma mark - 属性

#pragma mark - 搜索框风格
@property(nonatomic)        UIBarStyle              barStyle __TVOS_PROHIBITED;// 搜索框样式              // default is UIBarStyleDefault (blue)
typedef NS_ENUM(NSInteger, UIBarStyle) {
    UIBarStyleDefault         //白色搜索框，灰色背景
    UIBarStyleBlack           //黑色搜索框,
    
    UIBarStyleBlackOpaque      = 1, // 禁用. Use UIBarStyleBlack
    UIBarStyleBlackTranslucent = 2, // 禁用. Use UIBarStyleBlack and set the translucent property to YES
}



#pragma mark - 搜索的文本、搜索框顶部的提示信息、占位符
@property(nullable,nonatomic,weak) id<UISearchBarDelegate> delegate;// 代理             // weak reference. default is nil
@property(nullable,nonatomic,copy)   NSString               *text;// 搜索的文本                  // current/starting search text
@property(nullable,nonatomic,copy)   NSString               *prompt;// 搜索框顶部的提示信息                // default is nil
@property(nullable,nonatomic,copy)   NSString               *placeholder;// 占位符，默认nil, 若有值则在输入文本后消失          // default is nil



#pragma mark - 搜索框右侧的按钮
@property(nonatomic)        BOOL                    showsBookmarkButton __TVOS_PROHIBITED;// 搜索框右侧是否显示图书按钮    // default is NO
@property(nonatomic)        BOOL                    showsCancelButton __TVOS_PROHIBITED;//搜索框右侧是否显示取消按钮     // default is NO
@property(nonatomic)        BOOL                    showsSearchResultsButton NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED;// 搜索框右侧是否显示搜索结果按钮 // default is NO
@property(nonatomic, getter=isSearchResultsButtonSelected) BOOL searchResultsButtonSelected NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED;// 搜索结果按钮为选中状态 // default is NO
// 设置是否动画效果的显示或隐藏取消按钮
- (void)setShowsCancelButton:(BOOL)showsCancelButton animated:(BOOL)animated NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;


/// Use this method to modify the contents of the Unified Content Bar, shown on top of the keyboard when search is engaged.
/// You may modify the returned inputAssistantItem to add to or replace the existing items on the bar.
/// Modifications made to the returned UITextInputAssistantItem are reflected automatically.
@property (nonatomic, readonly, strong) UITextInputAssistantItem *inputAssistantItem NS_AVAILABLE_IOS(9_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;



/*
 The behavior of tintColor for bars has changed on iOS 7.0. It no longer affects the bar's background
 and behaves as described for the tintColor property added to UIView.
 To tint the bar's background, please use -barTintColor.
 */
#pragma mark - 光标颜色、背景颜色、搜索框样式
// 风格颜色，可用于修改输入框的光标颜色，取消按钮和选择栏被选中时候都会变成设置的颜色
@property(null_resettable, nonatomic,strong) UIColor *tintColor;
// 搜索框背景颜色
@property(nullable, nonatomic,strong) UIColor *barTintColor NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;  // default is nil

@property (nonatomic) UISearchBarStyle searchBarStyle NS_AVAILABLE_IOS(7_0);// 搜索框样式
typedef NS_ENUM(NSUInteger, UISearchBarStyle) {
    UISearchBarStyleDefault,    // 默认样式，和UISearchBarStyleProminent 一样
    UISearchBarStyleProminent,  // 类似于通讯录搜索栏，搜索栏具有半透明背景，搜索区域不透明。
    UISearchBarStyleMinimal     // 类似于音乐搜索栏，搜索栏没有背景，搜索字段是半透明的。
}


/*
 New behavior on iOS 7.
 Default is YES.
 You may force an opaque background by setting the property to NO.
 If the search bar has a custom background image, the default is inferred
 from the alpha values of the image—YES if it has any pixel with alpha < 1.0
 If you send setTranslucent:YES to a bar with an opaque custom background image
 it will apply a system opacity less than 1.0 to the image.
 If you send setTranslucent:NO to a bar with a translucent custom background image
 it will provide an opaque background for the image using the bar's barTintColor if defined, or black
 for UIBarStyleBlack or white for UIBarStyleDefault if barTintColor is nil.
 */
@property(nonatomic,assign,getter=isTranslucent) BOOL translucent NS_AVAILABLE_IOS(3_0);// 半透明 // Default is NO on iOS 6 and earlier. Always YES if barStyle is set to UIBarStyleBlackTranslucent


#pragma mark - 搜索栏的附件选择按钮视图
@property(nullable, nonatomic,copy) NSArray<NSString *>   *scopeButtonTitles        NS_AVAILABLE_IOS(3_0);// 选择按钮视图的按钮标题 // array of NSStrings. no scope bar shown unless 2 or more items
@property(nonatomic)      NSInteger  selectedScopeButtonIndex NS_AVAILABLE_IOS(3_0);// 选中的按钮下标值 ，默认 0. 如果超出范围则忽略 // index into array of scope button titles. default is 0. ignored if out of range
@property(nonatomic)      BOOL       showsScopeBar            NS_AVAILABLE_IOS(3_0);// 是否显示搜索栏的附件选择按钮视图 // default is NO. if YES, shows the scope bar. call sizeToFit: to update frame

/* Allow placement of an input accessory view to the keyboard for the search bar
 */
@property (nullable, nonatomic, readwrite, strong) UIView *inputAccessoryView;


#pragma mark - 搜索框背景图片、搜索框附属分栏条的背景颜色
// 1pt wide images and resizable images will be scaled or tiled according to the resizable area, otherwise the image will be tiled
@property(nullable, nonatomic,strong) UIImage *backgroundImage NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;// 搜索框背景图片
@property(nullable, nonatomic,strong) UIImage *scopeBarBackgroundImage NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;// 搜索框附属分栏条的背景颜色



#pragma mark - 设置 (获取) 搜索框背景图片、选择按钮视图的背景图片、文本框的背景图片、搜索框的图标
// 1.设置搜索框背景图片
- (void)setBackgroundImage:(nullable UIImage *)backgroundImage forBarPosition:(UIBarPosition)barPosition barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;  // Use UIBarMetricsDefaultPrompt to set a separate backgroundImage for a search bar with a prompt
//  获取置搜索框背景图片
- (nullable UIImage *)backgroundImageForBarPosition:(UIBarPosition)barPosition barMetrics:(UIBarMetrics)barMetrics NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;

/* In general, you should specify a value for the normal state to be used by other states which don't have a custom value set
 */

/* The rounded-rect search text field image. Valid states are UIControlStateNormal and UIControlStateDisabled
 */
// 2.设置搜索框文本框的背景图片
- (void)setSearchFieldBackgroundImage:(nullable UIImage *)backgroundImage forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
// 获取搜索框文本框的背景图片
- (nullable UIImage *)searchFieldBackgroundImageForState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;


// 3.设置搜索框的图标
- (void)setImage:(nullable UIImage *)iconImage forSearchBarIcon:(UISearchBarIcon)icon state:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
typedef NS_ENUM(NSInteger, UISearchBarIcon) {
    UISearchBarIconSearch, // 搜索框放大镜图标
    UISearchBarIconClear , // 搜索框右侧可用于清除输入的文字的图标x
    UISearchBarIconBookmark , // 搜索框右侧的图书图标
    UISearchBarIconResultsList , // 搜索框右侧的搜索结果列表图标
};

// 获取搜索框的图标
- (nullable UIImage *)imageForSearchBarIcon:(UISearchBarIcon)icon state:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

//
// Customizing the appearance of the scope bar buttons.
//

/* If backgroundImage is an image returned from -[UIImage resizableImageWithCapInsets:] the cap widths will be calculated from the edge insets, otherwise, the cap width will be calculated by subtracting one from the image's width then dividing by 2. The cap widths will also be used as the margins for text placement. To adjust the margin use the margin adjustment methods.
 */
// 4.设置选择按钮视图的背景图片
- (void)setScopeBarButtonBackgroundImage:(nullable UIImage *)backgroundImage forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
// 获取选择按钮视图的背景图片
- (nullable UIImage *)scopeBarButtonBackgroundImageForState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;



#pragma mark - 设置（获取）选择按钮视图的分割线图片、按钮上显示的标题样式
/* To customize the segmented control appearance you will need to provide divider images to go between two unselected segments (leftSegmentState:UIControlStateNormal rightSegmentState:UIControlStateNormal), selected on the left and unselected on the right (leftSegmentState:UIControlStateSelected rightSegmentState:UIControlStateNormal), and unselected on the left and selected on the right (leftSegmentState:UIControlStateNormal rightSegmentState:UIControlStateSelected).
 */
// 设置选择按钮视图的分割线图片
- (void)setScopeBarButtonDividerImage:(nullable UIImage *)dividerImage forLeftSegmentState:(UIControlState)leftState rightSegmentState:(UIControlState)rightState NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
// 获取选择按钮视图的分割线图片
- (nullable UIImage *)scopeBarButtonDividerImageForLeftSegmentState:(UIControlState)leftState rightSegmentState:(UIControlState)rightState NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

/* You may specify the font, text color, and shadow properties for the title in the text attributes dictionary, using the keys found in NSAttributedString.h.
 */
// 设置选择按钮视图的标题样式
- (void)setScopeBarButtonTitleTextAttributes:(nullable NSDictionary<NSString *, id> *)attributes forState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
// 获取选择按钮视图的标题样式
- (nullable NSDictionary<NSString *, id> *)scopeBarButtonTitleTextAttributesForState:(UIControlState)state NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;


/* To nudge the position of the search text field background in the search bar
 */
@property(nonatomic) UIOffset searchFieldBackgroundPositionAdjustment NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;// 搜索框中文本框的背景偏移量

/* To nudge the position of the text within the search text field background
 */
@property(nonatomic) UIOffset searchTextPositionAdjustment NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;// 搜索框中文本框的文本偏移量



#pragma mark - 设置（获取）搜索框四种图标的偏移量
/* To nudge the position of the icon within the search text field
 */
//  设置搜索框图标的偏移量
- (void)setPositionAdjustment:(UIOffset)adjustment forSearchBarIcon:(UISearchBarIcon)icon NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
//  获取搜索框图标的偏移量
- (UIOffset)positionAdjustmentForSearchBarIcon:(UISearchBarIcon)icon NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@end


#pragma mark - ↑
#pragma mark - 代理方法
@protocol UISearchBarDelegate <UIBarPositioningDelegate>

@optional (可选)

// 1. 将要开始编辑文本时会调用该方法，返回 NO 将不会变成第一响应者
- (BOOL)searchBarShouldBeginEditing:(UISearchBar *)searchBar;                      // return NO to not become first responder

// 2. 开始输入文本会调用该方法
- (void)searchBarTextDidBeginEditing:(UISearchBar *)searchBar;                     // called when text starts editing

// 3. 文字改变前会调用该方法，返回NO则不能加入新的编辑文字
- (BOOL)searchBar:(UISearchBar *)searchBar shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text NS_AVAILABLE_IOS(3_0); // called before text changes


// 4. 文本改变会调用该方法（包含clear文本）
- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText;   // called when text changes (including clear)

// 5. 键盘上的搜索按钮点击的会调用该方法
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar;                     // called when keyboard search button pressed


// 6. 搜索框右侧图书按钮点击会调用该方法
- (void)searchBarBookmarkButtonClicked:(UISearchBar *)searchBar __TVOS_PROHIBITED; // called when bookmark button pressed
// 6.点击取消按钮会调用该方法
- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar __TVOS_PROHIBITED;   // called when cancel button pressed
// 6.搜索结果列表按钮被按下会调用该方法
- (void)searchBarResultsListButtonClicked:(UISearchBar *)searchBar NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED; // called when search results button pressed


// 6. 将要结束编辑文本时会调用该方法，返回 NO 将不会释放第一响应者
- (BOOL)searchBarShouldEndEditing:(UISearchBar *)searchBar;                        // return NO to not resign first responder

// 7. 结束编辑文本时调用该方法
- (void)searchBarTextDidEndEditing:(UISearchBar *)searchBar;                       // called when text ends editing


// 8. 搜索框的附属按钮视图中切换按钮会调用该方法
- (void)searchBar:(UISearchBar *)searchBar selectedScopeButtonIndexDidChange:(NSInteger)selectedScope NS_AVAILABLE_IOS(3_0);

@end

NS_ASSUME_NONNULL_END

