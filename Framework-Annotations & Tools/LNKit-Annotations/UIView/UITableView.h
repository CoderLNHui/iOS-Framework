/*
 * File:  UITableView.h
 * Framework:  UIKit
 * Author:  白水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2005-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 👣
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UISwipeGestureRecognizer.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN


#pragma mark - NS_ENUM、Class相关

typedef NS_ENUM(NSInteger, UITableViewStyle) {
    UITableViewStylePlain,  //普通类型(单组数据悬停)        // regular table view
    UITableViewStyleGrouped  //分组类型(多组数据不悬停)       // preferences style table view
};// UITableViewStyle样式


typedef NS_ENUM(NSInteger, UITableViewScrollPosition) {
    UITableViewScrollPositionNone, //同UITableViewScrollPositionTop
    UITableViewScrollPositionTop, //定位完成后，将定位的行显示在tableView的顶部
    UITableViewScrollPositionMiddle, //定位完成后，将定位的行显示在tableView的中间
    UITableViewScrollPositionBottom //定位完成后，将定位的行显示在tableView最下面
};// scrollPosition参数决定定位的相对位置     // scroll so row of interest is completely visible at top/center/bottom of view


typedef NS_ENUM(NSInteger, UITableViewRowAnimation) {
    UITableViewRowAnimationFade, //淡入淡出
    UITableViewRowAnimationRight, //从右滑入         // slide in from right (or out to right)
    UITableViewRowAnimationLeft, //从左滑入
    UITableViewRowAnimationTop, //从上滑入
    UITableViewRowAnimationBottom, //从下滑入
    UITableViewRowAnimationNone,    //没有动画         // available in iOS 3.0
    UITableViewRowAnimationMiddle,          // available in iOS 3.2.  attempts to keep cell centered in the space it will/did occupy
    UITableViewRowAnimationAutomatic = 100 // 自动选择合适的动画 // available in iOS 5.0.  chooses an appropriate animation style for you
};// RowAnimation行变化(插入、删除、移动)的动画类型


// Including this constant string in the array of strings returned by sectionIndexTitlesForTableView: will cause a magnifying glass icon to be displayed at that location in the index.
// This should generally only be used as the first title in the index.
UIKIT_EXTERN NSString *const UITableViewIndexSearch NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;

// Returning this value from tableView:heightForHeaderInSection: or tableView:heightForFooterInSection: results in a height that fits the value returned from
// tableView:titleForHeaderInSection: or tableView:titleForFooterInSection: if the title is not nil.
UIKIT_EXTERN const CGFloat UITableViewAutomaticDimension NS_AVAILABLE_IOS(5_0);

@class UITableView;
@class UINib;
@protocol UITableViewDataSource;
@protocol UITableViewDataSourcePrefetching;
@class UILongPressGestureRecognizer;
@class UITableViewHeaderFooterView;
@class UIRefreshControl;
@class UIVisualEffect;

typedef NS_ENUM(NSInteger, UITableViewRowActionStyle) {
    UITableViewRowActionStyleDefault = 0,
    UITableViewRowActionStyleDestructive = UITableViewRowActionStyleDefault,
    UITableViewRowActionStyleNormal
} NS_ENUM_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;







#pragma mark - ↑
#pragma mark - cell侧滑行为相关 UITableViewRowAction类

NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UITableViewRowAction : NSObject <NSCopying>


/**
 * 自定义左滑显示按钮
 */
+ (instancetype)rowActionWithStyle:(UITableViewRowActionStyle)style title:(nullable NSString *)title handler:(void (^)(UITableViewRowAction *action, NSIndexPath *indexPath))handler;

@property (nonatomic, readonly) UITableViewRowActionStyle style;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) UIColor *backgroundColor; // default background color is dependent on style
@property (nonatomic, copy, nullable) UIVisualEffect* backgroundEffect;

@end





#pragma mark - ↑
#pragma mark - UITableViewFocusUpdateContext类相关

NS_CLASS_AVAILABLE_IOS(9_0) @interface UITableViewFocusUpdateContext : UIFocusUpdateContext

@property (nonatomic, strong, readonly, nullable) NSIndexPath *previouslyFocusedIndexPath;
@property (nonatomic, strong, readonly, nullable) NSIndexPath *nextFocusedIndexPath;

@end




//_______________________________________________________________________________________________________________
// this represents the display and behaviour of the cells.


#pragma mark - ↑
#pragma mark - Delegate代理方法

@protocol UITableViewDelegate<NSObject, UIScrollViewDelegate>

@optional（可选）

// Display customization -- 显示自定义

#pragma mark - 显示 \ 完成回调方法

//【cell将要显示时调用的方法】
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;

//【头视图将要显示时调用的方法】
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

//【尾视图将要显示时调用的方法】
- (void)tableView:(UITableView *)tableView willDisplayFooterView:(UIView *)view forSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

//【和上面的方法对应，这三个方法分别是cell，头视图，尾视图已经显示时调用的方法】
- (void)tableView:(UITableView *)tableView didEndDisplayingCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath*)indexPath NS_AVAILABLE_IOS(6_0);
- (void)tableView:(UITableView *)tableView didEndDisplayingHeaderView:(UIView *)view forSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);
- (void)tableView:(UITableView *)tableView didEndDisplayingFooterView:(UIView *)view forSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);






#pragma mark - 设置行高、区头高度、区尾高度
// Variable height support
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section;
- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section;



// Use the estimatedHeight methods to quickly calcuate guessed values which will allow for fast load times of the table.
// If these methods are implemented, the above -tableView:heightForXXX calls will be deferred until views are ready to be displayed, so more expensive logic can be placed there.

#pragma mark - 设置估算行高、估算区头高度、估算区尾高度
// 对于高度可变的情况下，提高效率
- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(7_0);
- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForHeaderInSection:(NSInteger)section NS_AVAILABLE_IOS(7_0);
- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForFooterInSection:(NSInteger)section NS_AVAILABLE_IOS(7_0);




// Section header & footer information. Views are preferred over title should you decide to provide both
#pragma mark - 设置区头视图、区尾视图
- (nullable UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section;   // custom view for header. will be adjusted to default or specified header height
- (nullable UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section;   // custom view for footer. will be adjusted to default or specified footer height





// Accessories (disclosures).
#pragma mark - 设置附件
- (UITableViewCellAccessoryType)tableView:(UITableView *)tableView accessoryTypeForRowWithIndexPath:(NSIndexPath *)indexPath NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;
- (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath;





// Selection -- 选择
#pragma mark - 选择回调代理方法

// -tableView:shouldHighlightRowAtIndexPath: is called when a touch comes down on a row.
// Returning NO to that message halts the selection process and does not cause the currently selected row to lose its selected look while the touch is down.
//【设置cell是否可以高亮】
- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0);
//【cell 高亮调用的方法】
- (void)tableView:(UITableView *)tableView didHighlightRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0);
//【cell 取消高亮调用的方法】
- (void)tableView:(UITableView *)tableView didUnhighlightRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0);


// Called before the user changes the selection. Return a new indexPath, or nil, to change the proposed selection.
//【当即将选中某行和取消选中某行时调用的函数，返回行所在分区】
- (nullable NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (nullable NSIndexPath *)tableView:(UITableView *)tableView willDeselectRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(3_0);

// Called after the user changes the selection.
//【选中和取消选中后调用的函数】
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(3_0);






// Editing -- 编辑
#pragma mark - 编辑回调代理方法

// Allows customization of the editingStyle for a particular cell located at 'indexPath'. If not implemented, all editable cells will have UITableViewCellEditingStyleDelete set for them when the table has editing property set to YES.
//【设置tableView被编辑时的状态风格，如果不设置，默认都是删除风格】
- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath;
//【自定义左滑删除按钮的标题】
- (nullable NSString *)tableView:(UITableView *)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;
//【下面这个方法是IOS8中的新方法，用于自定义创建tableView被编辑时右边的按钮，按钮类型为UITableViewRowAction】
- (nullable NSArray<UITableViewRowAction *> *)tableView:(UITableView *)tableView editActionsForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED; // supercedes -tableView:titleForDeleteConfirmationButtonForRowAtIndexPath: if return value is non-nil

// Controls whether the background is indented while editing.  If not implemented, the default is YES.  This is unrelated to the indentation level below.  This method only applies to grouped style table views.
//【设置编辑时背景是否缩进】
- (BOOL)tableView:(UITableView *)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath;


// The willBegin/didEnd methods are called whenever the 'editing' property is automatically changed by the table (allowing insert/delete/move). This is done by a swipe activating a single row
//【将要编辑和结束编辑时调用的方法】
- (void)tableView:(UITableView *)tableView willBeginEditingRowAtIndexPath:(NSIndexPath *)indexPath __TVOS_PROHIBITED;
- (void)tableView:(UITableView *)tableView didEndEditingRowAtIndexPath:(nullable NSIndexPath *)indexPath __TVOS_PROHIBITED;

// Moving/reordering

// Allows customization of the target row for a particular row as it is being moved/reordered
//【移动特定的某行】
- (NSIndexPath *)tableView:(UITableView *)tableView targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)sourceIndexPath toProposedIndexPath:(NSIndexPath *)proposedDestinationIndexPath;

// Indentation
//【tableView行缩进】
- (NSInteger)tableView:(UITableView *)tableView indentationLevelForRowAtIndexPath:(NSIndexPath *)indexPath; // return 'depth' of row for hierarchies








// Copy/Paste.-- 复制/粘贴  All three methods must be implemented by the delegate.
#pragma mark - 复制/粘贴

//【通知委托是否在指定行显示菜单，返回值为YES时，长按显示菜单】
- (BOOL)tableView:(UITableView *)tableView shouldShowMenuForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(5_0);
//【弹出选择菜单时会调用此方法（复制、粘贴、全选、剪切)】
- (BOOL)tableView:(UITableView *)tableView canPerformAction:(SEL)action forRowAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender NS_AVAILABLE_IOS(5_0);
//【选择菜单项完成之后调用此方法】
- (void)tableView:(UITableView *)tableView performAction:(SEL)action forRowAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender NS_AVAILABLE_IOS(5_0);




// Focus -- 焦点

- (BOOL)tableView:(UITableView *)tableView canFocusRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);
- (BOOL)tableView:(UITableView *)tableView shouldUpdateFocusInContext:(UITableViewFocusUpdateContext *)context NS_AVAILABLE_IOS(9_0);
- (void)tableView:(UITableView *)tableView didUpdateFocusInContext:(UITableViewFocusUpdateContext *)context withAnimationCoordinator:(UIFocusAnimationCoordinator *)coordinator NS_AVAILABLE_IOS(9_0);
- (nullable NSIndexPath *)indexPathForPreferredFocusedViewInTableView:(UITableView *)tableView NS_AVAILABLE_IOS(9_0);

@end

UIKIT_EXTERN NSNotificationName const UITableViewSelectionDidChangeNotification;






//_______________________________________________________________________________________________________________

#pragma mark - ↑
#pragma mark - 初始化 & 属性

//【UITableView类继承自UIScrollView,遵守NSCoding协议】
NS_CLASS_AVAILABLE_IOS(2_0) @interface UITableView : UIScrollView <NSCoding>

//【创建时必须指定类型(有普通(UITableViewStylePlain)和分组两种类型(UITableViewStyleGrouped))】
- (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style NS_DESIGNATED_INITIALIZER; // must specify style at creation. -initWithFrame: calls this with UITableViewStylePlain
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

//【列表视图的类型，只读】
@property (nonatomic, readonly) UITableViewStyle style;
@property (nonatomic, weak, nullable) id <UITableViewDataSource> dataSource; // 数据源
@property (nonatomic, weak, nullable) id <UITableViewDelegate> delegate; // 代理方法
@property (nonatomic, weak) id<UITableViewDataSourcePrefetching> prefetchDataSource NS_AVAILABLE_IOS(10_0);

//【全局设置行row高(默认 44)】
@property (nonatomic) CGFloat rowHeight;             // will return the default value if unset
//【全局设置区头高】
@property (nonatomic) CGFloat sectionHeaderHeight;   // will return the default value if unset
//【全局设置区尾高】
@property (nonatomic) CGFloat sectionFooterHeight;   // will return the default value if unset
//【设置Row的预设高度,默认0】
@property (nonatomic) CGFloat estimatedRowHeight NS_AVAILABLE_IOS(7_0); // default is 0, which means there is no estimate
//【设置区头的预设高度,默认0】
@property (nonatomic) CGFloat estimatedSectionHeaderHeight NS_AVAILABLE_IOS(7_0); // default is 0, which means there is no estimate
//【设置区尾的预设高度,默认0】
@property (nonatomic) CGFloat estimatedSectionFooterHeight NS_AVAILABLE_IOS(7_0); // default is 0, which means there is no estimate

//【允许更改分割线的frame】
@property (nonatomic) UIEdgeInsets separatorInset NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR; // allows customization of the frame of cell separators

//【背景视图(自动匹配tableView视图的大小)，设置后作为列表视图(tableView)的子视图，且在所有cell和headers/footers的后面。默认nil】
@property (nonatomic, strong, nullable) UIView *backgroundView NS_AVAILABLE_IOS(3_2); // the background view will be automatically resized to track the size of the table view.  this will be placed as a subview of the table view behind all cells and headers/footers.  default may be non-nil for some devices.

//【设置tableView头视图】
@property (nonatomic, strong, nullable) UIView *tableHeaderView;                           // accessory view for above row content. default is nil. not to be confused with section header

@property (nonatomic, strong, nullable) UIView *tableFooterView;                           // accessory view below content. default is nil. not to be confused with section footer
/**
 设置tableView尾视图
 self.tableView.tableFooterView = [[UIView alloc] init]; // 隐藏多余分割线
 */




#pragma mark - ↑
#pragma mark - 数据刷新
//【全局刷新】
- (void)reloadData; // reloads everything from scratch. redisplays visible rows. because we only keep info about visible rows, this is cheap. will adjust offset if table shrinks
//【刷新section这个方法常用于新加或者删除了索引类别而无需刷新整个表视图的情况下】
- (void)reloadSectionIndexTitles NS_AVAILABLE_IOS(3_0);   // reloads the index bar.




// Info -- 信息
#pragma mark - ↑
#pragma mark - 获取信息

//【列表的组数】
@property (nonatomic, readonly) NSInteger numberOfSections;
//【某一组有多少行】
- (NSInteger)numberOfRowsInSection:(NSInteger)section;
//【某一组所占的矩形区域(包括header,footer和所有的行)】
- (CGRect)rectForSection:(NSInteger)section;                                    // includes header, footer and all rows
//【某一组的header所占的矩形区域】
- (CGRect)rectForHeaderInSection:(NSInteger)section;
//【某一组的footer所占的矩形区域】
- (CGRect)rectForFooterInSection:(NSInteger)section;
//【某一分区的row所占的矩形区域】
- (CGRect)rectForRowAtIndexPath:(NSIndexPath *)indexPath;

//【某一点在tableview上所占的分区，如果该点不在tableView的任何row上返回nil】
- (nullable NSIndexPath *)indexPathForRowAtPoint:(CGPoint)point;                         // returns nil if point is outside of any row in the table
//【某一行所在的分区，如果改行是不可见的返回nil】
- (nullable NSIndexPath *)indexPathForCell:(UITableViewCell *)cell;                      // returns nil if cell is not visible
//【某一矩形区域内所有行所在的所有分区，返回元素为NSIndexPath类型的数组。当该矩形是一个无效值时，返回ni】
- (nullable NSArray<NSIndexPath *> *)indexPathsForRowsInRect:(CGRect)rect;                              // returns nil if rect not valid

//【某一分区的cell，如果改cell是不可见的或者indexPath超出了范围则返回nil】
- (nullable __kindof UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath;   // returns nil if cell is not visible or index path is out of range

//【所有可见的cell，只读数组型(数组类型为UITableViewCell)】
@property (nonatomic, readonly) NSArray<__kindof UITableViewCell *> *visibleCells;
//【所有可见行所在的分区，只读数组型(数组类型为NSIndexPath)】
@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForVisibleRows;

//【某一组的header视图(常用于自定义headerView的时候用)】
- (nullable UITableViewHeaderFooterView *)headerViewForSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);
//【某一组的footer视图(常用于自定义footerView的时候用)】
- (nullable UITableViewHeaderFooterView *)footerViewForSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

//【使表格图定位到某一位置(行)】
- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;
//【使表格图定位到选中行】
- (void)scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;









// Row insertion/deletion/reloading. -- 行的插入/删除/刷新
#pragma mark - ↑
#pragma mark - tableView操作：行的插入/删除/刷新

//【允许多个插入/行和段被同时删除动画。可排序】
- (void)beginUpdates;   // allow multiple insert/delete of rows and sections to be animated simultaneously. Nestable
//【只调用插入/删除/重载呼叫或改变一更新区块内的编辑状态。然而对于行数等属性可能是无效的。】
- (void)endUpdates;     // only call insert/delete/reload calls or change the editing state inside an update block.  otherwise things like row count, etc. may be invalid.

//【插入某些组】
- (void)insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
//【删除某些组】
- (void)deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
//【刷新某些组】
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation NS_AVAILABLE_IOS(3_0);
//【移动组section到组newSection的位置】
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection NS_AVAILABLE_IOS(5_0);

//【插入某些行】
- (void)insertRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
//【删除某些行】
- (void)deleteRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
//【刷新某些分区的行】
- (void)reloadRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation NS_AVAILABLE_IOS(3_0);
//【移动分区indexPath的行到分区newIndexPath】
- (void)moveRowAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath NS_AVAILABLE_IOS(5_0);






// Editing. When set, rows show insert/delete/reorder controls based on data source queries
// -- 编辑。设置之后，行的显示会基于数据源查询插入/删除/重排序的控制
#pragma mark - ↑
#pragma mark - 编辑

//【设置是否是编辑状态(编辑状态下的cell左边会出现一个减号，点击右边会划出删除按钮)】
@property (nonatomic, getter=isEditing) BOOL editing;                             // default is NO. setting is not animated.
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;

//【当不在编辑模式时，是否可以选中。默认YES】
@property (nonatomic) BOOL allowsSelection NS_AVAILABLE_IOS(3_0);  // default is YES. Controls whether rows can be selected when not in editing mode
//【当处在编辑模式时，是否可以选中。默认NO】
@property (nonatomic) BOOL allowsSelectionDuringEditing;                                 // default is NO. Controls whether rows can be selected when in editing mode

//【是否可以同时选中。默认NO】
@property (nonatomic) BOOL allowsMultipleSelection NS_AVAILABLE_IOS(5_0);                // default is NO. Controls whether multiple rows can be selected simultaneously
//【当处在编辑模式时，是否可以同时选中。默认NO】
@property (nonatomic) BOOL allowsMultipleSelectionDuringEditing NS_AVAILABLE_IOS(5_0);   // default is NO. Controls whether multiple rows can be selected simultaneously in editing mode





// Selection -- 选中
#pragma mark - ↑
#pragma mark - 手动选中行

//【选中的行所在的分区(单选)】
@property (nonatomic, readonly, nullable) NSIndexPath *indexPathForSelectedRow; // returns nil or index path representing section and row of selection.
//【选中的行所在的所有分区(多选)】
@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForSelectedRows NS_AVAILABLE_IOS(5_0); // returns nil or a set of index paths representing the sections and rows of the selection.

// Selects and deselects rows. These methods will not call the delegate methods (-tableView:willSelectRowAtIndexPath: or tableView:didSelectRowAtIndexPath:), nor will it send out a notification.
//【代码手动选中与取消选中某行，注意：这两个方法将不会回调代理中的方法。】
- (void)selectRowAtIndexPath:(nullable NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;






// Appearance -- 外观
#pragma mark - ↑
#pragma mark - 设置索引

//【设置索引栏最小显示行数。显示在右侧专门章节索引列表当行数达到此值。默认值为0】
@property (nonatomic) NSInteger sectionIndexMinimumDisplayRowCount;                                                      // show special section index list on right when row count reaches this value. default is 0
//【设置索引栏字体颜色】
@property (nonatomic, strong, nullable) UIColor *sectionIndexColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;                   // color used for text of the section index
//【设置索引栏背景颜色】
@property (nonatomic, strong, nullable) UIColor *sectionIndexBackgroundColor NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;         // the background color of the section index while not being touched
//【设置索引栏被选中时的颜色】
@property (nonatomic, strong, nullable) UIColor *sectionIndexTrackingBackgroundColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR; // the background color of the section index while it is being touched




#pragma mark - 【设置分割线】
//【设置分割线的风格】
@property (nonatomic) UITableViewCellSeparatorStyle separatorStyle __TVOS_PROHIBITED; // default is UITableViewCellSeparatorStyleSingleLine
//【设置分割线颜色】
@property (nonatomic, strong, nullable) UIColor *separatorColor UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED; // default is the standard separator gray
//【设置分割线毛玻璃效果(IOS8之后可用)】
@property (nonatomic, copy, nullable) UIVisualEffect *separatorEffect NS_AVAILABLE_IOS(8_0) UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED; // effect to apply to table separators

@property (nonatomic) BOOL cellLayoutMarginsFollowReadableWidth NS_AVAILABLE_IOS(9_0); // if cell margins are derived from the width of the readableContentGuide.




#pragma mark - 【复用队列】
//【从复用池中取cell】
- (nullable __kindof UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;  // Used by the delegate to acquire an already allocated cell, in lieu of allocating a new one.
//【获取一个已注册的cell】
- (__kindof UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0); // newer dequeue method guarantees a cell is returned and resized properly, assuming identifier is registered
//【从复用池获取头视图或尾视图】
- (nullable __kindof UITableViewHeaderFooterView *)dequeueReusableHeaderFooterViewWithIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);  // like dequeueReusableCellWithIdentifier:, but for headers/footers


// Beginning in iOS 6, clients can register a nib or class for each cell.
// If all reuse identifiers are registered, use the newer -dequeueReusableCellWithIdentifier:forIndexPath: to guarantee that a cell instance is returned.
// Instances returned from the new dequeue method will also be properly sized when they are returned.
#pragma mark - 【注册】
//【通过xib文件注册cell】
- (void)registerNib:(nullable UINib *)nib forCellReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(5_0);
//【通过 OC 类注册cell】
- (void)registerClass:(nullable Class)cellClass forCellReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);

//【通过xib文件注册头视图和尾视图】
- (void)registerNib:(nullable UINib *)nib forHeaderFooterViewReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);
//【通过OC类注册头视图和尾视图】
- (void)registerClass:(nullable Class)aClass forHeaderFooterViewReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);


// Focus -- 焦点
@property (nonatomic) BOOL remembersLastFocusedIndexPath NS_AVAILABLE_IOS(9_0); // defaults to NO. If YES, when focusing on a table view the last focused index path is focused automatically. If the table view has never been focused, then the preferred focused index path is used.

@end

//_______________________________________________________________________________________________________________
// this protocol represents the data model object. as such, it supplies no information about appearance (including the cells)
// -- 数据源协议方法，这个协议描绘了数据源模型，它不提供关于外观的任何信息(包括cell)






#pragma mark - ↑
#pragma mark - DataSource数据源
@protocol UITableViewDataSource<NSObject>

@required（必须）

//【每一组有多少行】
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;

// Row display. Implementers should *always* try to reuse cells by setting each cell's reuseIdentifier and querying for available reusable cells with dequeueReusableCellWithIdentifier:
// Cell gets various attributes set automatically based on table (separators) and data source (accessory views, editing controls)

//【行显示内容，可以通过每个cell的reuseIdentifier对多种多样的cell进行查找，进而进行cell的复用】
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;


@optional（可选）

//【列表有多少组(默认1)】
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;              // Default is 1 if not implemented

//【组头标题，字体样式是固定的。如果想要不同的样式，可以自定义】
- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;    // fixed font style. use custom view (UILabel) if you want something different
//【组底标题，字体样式是固定的。如果想要不同的样式，可以自定义】
- (nullable NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section;


// Editing -- 编辑相关
// Individual rows can opt out of having the -editing property set for them. If not implemented, all rows are assumed to be editable.
//【每一行可以设置自己的编辑属性，默认YES，即使否可以删除移动选中等。】
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath;


// Moving/reordering -- 移动/重新排序
// Allows the reorder accessory view to optionally be shown for a particular row. By default, the reorder control will be shown only if the datasource implements -tableView:moveRowAtIndexPath:toIndexPath:
//【设置某行是否可以被移动】
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath;


// Index -- 索引
//【设置索引栏标题数组（实现这个方法，会在tableView右边显示每个分区的索引），例如：ABCDEFG...Z】
- (nullable NSArray<NSString *> *)sectionIndexTitlesForTableView:(UITableView *)tableView __TVOS_PROHIBITED;                                                    // return list of section titles to display in section index view (e.g. "ABCD...Z#")
//【设置索引栏标题对应的分区】
- (NSInteger)tableView:(UITableView *)tableView sectionForSectionIndexTitle:(NSString *)title atIndex:(NSInteger)index __TVOS_PROHIBITED;  // tell table which section corresponds to section title/index (e.g. "B",1))

// Data manipulation - insert and delete support

// After a row has the minus or plus button invoked (based on the UITableViewCellEditingStyle for the cell), the dataSource must commit the change
// Not called for edit actions using UITableViewRowAction - the action's handler will be invoked instead
/**
【tableView接受编辑时调用的方法】
 只要实现这个方法,就拥有系统左滑删除功能,点击左滑出删除按钮会调用这个方法.
 */
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath;


// Data manipulation - reorder / moving support
//【tableView的cell被移动时调用的方法】
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;


#pragma mark - ↑
@end


// _______________________________________________________________________________________________________________
// this protocol can provide information about cells before they are displayed on screen.

@protocol UITableViewDataSourcePrefetching <NSObject>

@required

// indexPaths are ordered ascending by geometric distance from the table view
- (void)tableView:(UITableView *)tableView prefetchRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

@optional

// indexPaths that previously were considered as candidates for pre-fetching, but were not actually used; may be a subset of the previous call to -tableView:prefetchRowsAtIndexPaths:
- (void)tableView:(UITableView *)tableView cancelPrefetchingForRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

@end


//_______________________________________________________________________________________________________________

// This category provides convenience methods to make it easier to use an NSIndexPath to represent a section and row
@interface NSIndexPath (UITableView)

//【类方法】
+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section;

//【indexPath的组】
@property (nonatomic, readonly) NSInteger section;
//【indexPath的行】
@property (nonatomic, readonly) NSInteger row;


@end


PS.
// 将单元格的边框设置为圆角
cell.layer.cornerRadius = 12;
cell.layer.masksToBounds = YES;






