/*
 * UITableViewCell.h 
 *
 * UIKit (c) 2005-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage, UIColor, UILabel, UIImageView, UIButton, UITextField, UITableView, UILongPressGestureRecognizer;

#pragma mark - NS_ENUM
#pragma mark -设置Cell显示样式
typedef NS_ENUM(NSInteger, UITableViewCellStyle) {
    UITableViewCellStyleDefault,// 默认风格，自带标题和一个图片视图，图片在左    // Simple cell with text label and optional image view (behavior of UITableViewCell in iPhoneOS 2.x)
    UITableViewCellStyleValue1,// 只有标题和副标题 副标题在右边        // Left aligned label on left and right aligned label on right with blue text (Used in Settings)
    UITableViewCellStyleValue2,// 只有标题和副标题，副标题在左边标题的下边        // Right aligned label on left with blue text and left aligned label on right (Used in Phone/Contacts)
    UITableViewCellStyleSubtitle// 自带图片视图和主副标题，主副标题都在左边，副标题在下    // Left aligned label on top and left aligned label on bottom with gray text (Used in iPod).
}; // available in iPhone OS 3.0

#pragma mark -设置分割线样式
typedef NS_ENUM(NSInteger, UITableViewCellSeparatorStyle) {
    UITableViewCellSeparatorStyleNone,
    UITableViewCellSeparatorStyleSingleLine,
    UITableViewCellSeparatorStyleSingleLineEtched   // This separator style is only supported for grouped style table views currently
} __TVOS_PROHIBITED;

#pragma mark -设置Cell选中时样式
typedef NS_ENUM(NSInteger, UITableViewCellSelectionStyle) {
    UITableViewCellSelectionStyleNone, // 不能选中
    UITableViewCellSelectionStyleBlue, // 变蓝
    UITableViewCellSelectionStyleGray, // 变灰色
    UITableViewCellSelectionStyleDefault NS_ENUM_AVAILABLE_IOS(7_0)// 默认 为蓝色
};

#pragma mark -Cell集中样式
typedef NS_ENUM(NSInteger, UITableViewCellFocusStyle) {
    UITableViewCellFocusStyleDefault,
    UITableViewCellFocusStyleCustom
} NS_ENUM_AVAILABLE_IOS(9_0);

#pragma mark -cell编辑样式
typedef NS_ENUM(NSInteger, UITableViewCellEditingStyle) {
    UITableViewCellEditingStyleNone,// 无编辑
    UITableViewCellEditingStyleDelete,// 删除编辑(-号)
    UITableViewCellEditingStyleInsert// 插入编辑(+号)
};

#pragma mark -cell右侧附件类型
typedef NS_ENUM(NSInteger, UITableViewCellAccessoryType) {
    UITableViewCellAccessoryNone, // 没有视图                                                    // don't show any accessory view
    UITableViewCellAccessoryDisclosureIndicator, // cell右侧显示一个灰色箭头                                      // regular chevron. doesn't track
    UITableViewCellAccessoryDetailDisclosureButton __TVOS_PROHIBITED, // 显示详情符号和灰色箭头               // info button w/ chevron. tracks
    UITableViewCellAccessoryCheckmark,// cell右侧显示蓝色对号                                                 // checkmark. doesn't track
    UITableViewCellAccessoryDetailButton NS_ENUM_AVAILABLE_IOS(7_0)  __TVOS_PROHIBITED // info button. tracks // cell右侧显示一个详情符号
};

#pragma mark -
typedef NS_OPTIONS(NSUInteger, UITableViewCellStateMask) {
    UITableViewCellStateDefaultMask                     = 0,//默认状态
    UITableViewCellStateShowingEditControlMask          = 1 << 0,//编辑状态
    UITableViewCellStateShowingDeleteConfirmationMask   = 1 << 1//确认删除状态
};//

#pragma mark -cell拖拽情形
typedef NS_ENUM(NSInteger, UITableViewCellDragState) {
    UITableViewCellDragStateNone,
    UITableViewCellDragStateLifting, // The cell is lifting from the table view before it joins the drag session.
    UITableViewCellDragStateDragging // The cell is involved in a drag session.
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


#define UITableViewCellStateEditingMask UITableViewCellStateShowingEditControlMask
#pragma mark - UITableViewCell
NS_CLASS_AVAILABLE_IOS(2_0) @interface UITableViewCell : UIView <NSCoding, UIGestureRecognizerDelegate>

// Designated initializer.  If the cell can be reused, you must pass in a reuse identifier.  You should use the same reuse identifier for all cells of the same form.
#pragma mark -cell初始化
- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(nullable NSString *)reuseIdentifier NS_AVAILABLE_IOS(3_0) NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
/**
 注解：将单元格的边框设置为圆角
    cell.layer.cornerRadius = 12;
    cell.layer.masksToBounds = YES;
 */

#pragma mark - cell常用属性
// Content.  These properties provide direct access to the internal label and image views used by the table view cell.  These should be used instead of the content properties below.
#pragma mark -图片
@property (nonatomic, readonly, strong, nullable) UIImageView *imageView NS_AVAILABLE_IOS(3_0);   // default is nil.  image view will be created if necessary.

#pragma mark -标题Lable
@property (nonatomic, readonly, strong, nullable) UILabel *textLabel NS_AVAILABLE_IOS(3_0);   // default is nil.  label will be created if necessary.

#pragma mark -详情Lable
@property (nonatomic, readonly, strong, nullable) UILabel *detailTextLabel NS_AVAILABLE_IOS(3_0); // default is nil.  label will be created if necessary (and the current style supports a detail label).

// If you want to customize cells by simply adding additional views, you should add them to the content view so they will be positioned appropriately as the cell transitions into and out of editing mode.
#pragma mark -内容视图
// 自定义cell，子控件要添加到ContentView
@property (nonatomic, readonly, strong) UIView *contentView;

// Default is nil for cells in UITableViewStylePlain, and non-nil for UITableViewStyleGrouped. The 'backgroundView' will be added as a subview behind all other views.
#pragma mark -设置cell的背景View(优先级: backgroundView > backgroundColor)
@property (nonatomic, strong, nullable) UIView *backgroundView;


// Default is nil for cells in UITableViewStylePlain, and non-nil for UITableViewStyleGrouped. The 'selectedBackgroundView' will be added as a subview directly above the backgroundView if not nil, or behind all other views. It is added as a subview only when the cell is selected. Calling -setSelected:animated: will cause the 'selectedBackgroundView' to animate in and out with an alpha fade.
#pragma mark -设置cell选中时背景View
@property (nonatomic, strong, nullable) UIView *selectedBackgroundView;

// If not nil, takes the place of the selectedBackgroundView when using multiple selection.
@property (nonatomic, strong, nullable) UIView *multipleSelectionBackgroundView NS_AVAILABLE_IOS(5_0);
#pragma mark -复用标识
@property (nonatomic, readonly, copy, nullable) NSString *reuseIdentifier;


#pragma mark -当被重用的cell将要显示时调用
/**
 注解：
    这个方法最大的用武之地是当你自定义的cell上面有图片时，如果产生了重用，图片可能会错乱（当图片来自异步下载时及其明显），这时我们可以重写这个方法把内容抹掉。
    可以在该函数中做一些初始化的操作 比如停掉原来cell中播放的视频音乐等
 */
- (void)prepareForReuse;                                                        // if the cell is reusable (has a reuse identifier), this is called just before the cell is returned from the table view method dequeueReusableCellWithIdentifier:.  If you override, you MUST call super.

#pragma mark -设置选中样式(StyleNone选中不变灰色)
@property (nonatomic) UITableViewCellSelectionStyle   selectionStyle;             // default is UITableViewCellSelectionStyleBlue.
#pragma mark -选中
@property (nonatomic, getter=isSelected) BOOL         selected;                   // set selected state (title, image, background). default is NO. animated is NO
#pragma mark -高亮
@property (nonatomic, getter=isHighlighted) BOOL      highlighted;                // set highlighted state (title, image, background). default is NO. animated is NO


#pragma mark -重写layoutsubviews方法，为了查看当cell改变编辑状态时，有什么subviews
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;                     // animate between regular and selected state
#pragma mark -当cell处于高亮状态时调用
//UItableview内部会自动调用该方法，重写该方法可以在cell处于高亮时做一些额外操作
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;               // animate between regular and highlighted state


#pragma mark -cell当前的编辑模式
@property (nonatomic, readonly) UITableViewCellEditingStyle editingStyle;         // default is UITableViewCellEditingStyleNone. This is set by UITableView using the delegate's value for cells who customize their appearance accordingly.


@property (nonatomic) BOOL                            showsReorderControl;        // default is NO
@property (nonatomic) BOOL                            shouldIndentWhileEditing;   // default is YES.  This is unrelated to the indentation level below.


#pragma mark -附加类型（比如右侧的箭头）
@property (nonatomic) UITableViewCellAccessoryType    accessoryType;              // default is UITableViewCellAccessoryNone. use to set standard type
#pragma mark -设置右侧显示的视图
@property (nonatomic, strong, nullable) UIView       *accessoryView;              // if set, use custom view. ignore accessoryType. tracks if enabled can calls accessory action
#pragma mark -设置当cell进入编辑模式时的辅助按钮类型
@property (nonatomic) UITableViewCellAccessoryType    editingAccessoryType;       // default is UITableViewCellAccessoryNone. use to set standard type
#pragma mark -自定义cell进入编辑模式后辅助视图
@property (nonatomic, strong, nullable) UIView       *editingAccessoryView;       // if set, use custom view. ignore editingAccessoryType. tracks if enabled can calls accessory action


#pragma mark -获取cell的缩进级别
@property (nonatomic) NSInteger                       indentationLevel;           // adjust content indent. default is 0
#pragma mark -获取cell的缩进宽度
@property (nonatomic) CGFloat                         indentationWidth;           // width for each level. default is 10.0
#pragma mark -设置分割线的偏移量
@property (nonatomic) UIEdgeInsets                    separatorInset NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED; // allows customization of the separator frame

#pragma mark -设置是否编辑状态
@property (nonatomic, getter=isEditing) BOOL          editing;                    // show appropriate edit controls (+/- & reorder). By default -setEditing: calls setEditing:animated: with NO for animated.
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;

#pragma mark -返回是否目前正在显示删除按钮
@property(nonatomic, readonly) BOOL                   showingDeleteConfirmation;  // currently showing "Delete" button

@property (nonatomic) UITableViewCellFocusStyle       focusStyle NS_AVAILABLE_IOS(9_0) UI_APPEARANCE_SELECTOR;




// These methods can be used by subclasses to animate additional changes to the cell when the cell is changing state
// Note that when the cell is swiped, the cell will be transitioned into the UITableViewCellStateShowingDeleteConfirmationMask state,
// but the UITableViewCellStateShowingEditControlMask will not be set.
#pragma mark -当cell的状态变为编辑时自动调用以下方法，重写该方法可以改变cell的布局
- (void)willTransitionToState:(UITableViewCellStateMask)state NS_AVAILABLE_IOS(3_0);
- (void)didTransitionToState:(UITableViewCellStateMask)state NS_AVAILABLE_IOS(3_0);

/* Override this method to receive notifications that the cell's drag state has changed.
 * Call super if you want to apply the default appearance.
 */
- (void)dragStateDidChange:(UITableViewCellDragState)dragState API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

/* Controls whether the cell in the table view allows user interaction once it is part of a drag (UITableViewCellDragStateDragging).
 * Default is NO.
 */
@property (nonatomic) BOOL userInteractionEnabledWhileDragging API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

@end
# WechatPublic-CoderLN



#pragma mark - 弃用 UIDeprecated
@interface UITableViewCell (UIDeprecated)

// Frame is ignored.  The size will be specified by the table view width and row height.
- (id)initWithFrame:(CGRect)frame reuseIdentifier:(nullable NSString *)reuseIdentifier NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;



// Content properties.  These properties were deprecated in iPhone OS 3.0.  The textLabel and imageView properties above should be used instead.
// For selected attributes, set the highlighted attributes on the textLabel and imageView.
@property (nonatomic, copy, nullable)   NSString *text NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;                        // default is nil
@property (nonatomic, strong, nullable) UIFont   *font NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;                        // default is nil (Use default font)
@property (nonatomic) NSTextAlignment   textAlignment NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;               // default is UITextAlignmentLeft
@property (nonatomic) NSLineBreakMode   lineBreakMode NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;               // default is UILineBreakModeTailTruncation
@property (nonatomic, strong, nullable) UIColor  *textColor NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;                   // default is nil (text draws black)
@property (nonatomic, strong, nullable) UIColor  *selectedTextColor NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;           // default is nil (text draws white)

@property (nonatomic, strong, nullable) UIImage  *image NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;                       // default is nil. appears on left next to title.
@property (nonatomic, strong, nullable) UIImage  *selectedImage NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;               // default is nil

// Use the new editingAccessoryType and editingAccessoryView instead
@property (nonatomic) BOOL              hidesAccessoryWhenEditing NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;   // default is YES

// Use the table view data source method -tableView:commitEditingStyle:forRowAtIndexPath: or the table view delegate method -tableView:accessoryButtonTappedForRowWithIndexPath: instead
@property (nonatomic, assign, nullable) id        target NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;                      // target for insert/delete/accessory clicks. default is nil (i.e. go up responder chain). weak reference
@property (nonatomic, nullable) SEL               editAction NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;                  // action to call on insert/delete call. set by UITableView
@property (nonatomic, nullable) SEL               accessoryAction NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;             // action to call on accessory view clicked. set by UITableView

@end


