/*
 * File:  UITableView.h 
 *
 * Framework: UIKit (c) 2005-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UISwipeGestureRecognizer.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - NS_ENUM
#pragma mark -UITableViewStyle样式
typedef NS_ENUM(NSInteger, UITableViewStyle) {
    UITableViewStylePlain,  //普通类型(单组数据悬停)        // regular table view
    UITableViewStyleGrouped  //分组类型(多组数据不悬停)       // preferences style table view
};

#pragma mark -定位的相对位置
typedef NS_ENUM(NSInteger, UITableViewScrollPosition) {
    UITableViewScrollPositionNone, //同UITableViewScrollPositionTop
    UITableViewScrollPositionTop, //定位完成后，将定位的行显示在tableView的顶部
    UITableViewScrollPositionMiddle, //定位完成后，将定位的行显示在tableView的中间
    UITableViewScrollPositionBottom //定位完成后，将定位的行显示在tableView最下面
};// scroll so row of interest is completely visible at top/center/bottom of view

#pragma mark -行动画类型(插入、删除、移动)
typedef NS_ENUM(NSInteger, UITableViewRowAnimation) {
    UITableViewRowAnimationFade, //淡入淡出
    UITableViewRowAnimationRight, //从右滑入         // slide in from right (or out to right)
    UITableViewRowAnimationLeft, //从左滑入
    UITableViewRowAnimationTop, //从上滑入
    UITableViewRowAnimationBottom, //从下滑入
    UITableViewRowAnimationNone,    //没有动画         // available in iOS 3.0
    UITableViewRowAnimationMiddle,          // available in iOS 3.2.  attempts to keep cell centered in the space it will/did occupy
    UITableViewRowAnimationAutomatic = 100 // 自动选择合适的动画 // available in iOS 5.0.  chooses an appropriate animation style for you
};



// Including this constant string in the array of strings returned by sectionIndexTitlesForTableView: will cause a magnifying glass icon to be displayed at that location in the index.
// This should generally only be used as the first title in the index.
// 这通常只应用作索引中的第一个标题
UIKIT_EXTERN NSString *const UITableViewIndexSearch NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;

// Returning this value from tableView:heightForHeaderInSection: or tableView:heightForFooterInSection: results in a height that fits the value returned from
// tableView:titleForHeaderInSection: or tableView:titleForFooterInSection: if the title is not nil.
// 自动适配尺寸
UIKIT_EXTERN const CGFloat UITableViewAutomaticDimension NS_AVAILABLE_IOS(5_0);

@class UITableView, UINib, UITableViewHeaderFooterView, UIVisualEffect;
@protocol UITableViewDataSource, UITableViewDataSourcePrefetching;
@class UIDragItem, UIDragPreviewParameters, UIDragPreviewTarget, UITableViewDropProposal, UITableViewPlaceholder, UITableViewDropPlaceholder;
@protocol UISpringLoadedInteractionContext, UIDragSession, UIDropSession;
@protocol UITableViewDragDelegate, UITableViewDropDelegate, UITableViewDropCoordinator, UITableViewDropItem, UITableViewDropPlaceholderContext;


#pragma mark - 行附加功能
#pragma mark -cell侧滑功能类型
typedef NS_ENUM(NSInteger, UITableViewRowActionStyle) {
    UITableViewRowActionStyleDefault = 0,// 危险的，如 删除
    UITableViewRowActionStyleDestructive = UITableViewRowActionStyleDefault,// 危险的，如 删除
    UITableViewRowActionStyleNormal // 普通的
} NS_ENUM_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

// Use UIContextualAction instead of this class, which will be deprecated in a future release.
NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED
@interface UITableViewRowAction : NSObject <NSCopying>

#pragma mark -自定义左滑右侧显示按钮
+ (instancetype)rowActionWithStyle:(UITableViewRowActionStyle)style title:(nullable NSString *)title handler:(void (^)(UITableViewRowAction *action, NSIndexPath *indexPath))handler;

#pragma mark -右侧显示按钮样式
@property (nonatomic, readonly) UITableViewRowActionStyle style;//
#pragma mark -标题
@property (nonatomic, copy, nullable) NSString *title;//
#pragma mark -背景颜色
@property (nonatomic, copy, nullable) UIColor *backgroundColor;//  // default background color is dependent on style
#pragma mark -视觉效果
@property (nonatomic, copy, nullable) UIVisualEffect* backgroundEffect;//

@end



#pragma mark - 更新上下文
NS_CLASS_AVAILABLE_IOS(9_0) @interface UITableViewFocusUpdateContext : UIFocusUpdateContext

@property (nonatomic, strong, readonly, nullable) NSIndexPath *previouslyFocusedIndexPath;
@property (nonatomic, strong, readonly, nullable) NSIndexPath *nextFocusedIndexPath;
@end




//_______________________________________________________________________________________________________________
// this represents the display and behaviour of the cells.

#pragma mark - Delegate
@protocol UITableViewDelegate<NSObject, UIScrollViewDelegate>

#pragma mark - @optional（可选）

// Display customization -- 显示自定义

#pragma mark - 将要显示 \ 显示完成回调方法
/**
 作用：【cell将要显示时调用的方法】
 */
- (void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath;

/**
 作用：【头视图将要显示时调用的方法】
 */
- (void)tableView:(UITableView *)tableView willDisplayHeaderView:(UIView *)view forSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

/**
 作用：【尾视图将要显示时调用的方法】
 */
- (void)tableView:(UITableView *)tableView willDisplayFooterView:(UIView *)view forSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

/**
 作用：【和上面的方法对应，这三个方法分别是cell，头视图，尾视图已经显示时调用的方法】
 */
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
/**
 注解：对于高度可变的情况下，提高效率
 */
- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(7_0);
- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForHeaderInSection:(NSInteger)section NS_AVAILABLE_IOS(7_0);
- (CGFloat)tableView:(UITableView *)tableView estimatedHeightForFooterInSection:(NSInteger)section NS_AVAILABLE_IOS(7_0);


// Section header & footer information. Views are preferred over title should you decide to provide both
#pragma mark - 设置区头视图、区尾视图
- (nullable UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section;   // custom view for header. will be adjusted to default or specified header height
- (nullable UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section;   // custom view for footer. will be adjusted to default or specified footer height


// Accessories (disclosures).
#pragma mark - 设置Cell右侧显示附件，如：箭头、对号
- (UITableViewCellAccessoryType)tableView:(UITableView *)tableView accessoryTypeForRowWithIndexPath:(NSIndexPath *)indexPath NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;
- (void)tableView:(UITableView *)tableView accessoryButtonTappedForRowWithIndexPath:(NSIndexPath *)indexPath;


// Selection -- 选择
#pragma mark - 选择回调代理方法
// -tableView:shouldHighlightRowAtIndexPath: is called when a touch comes down on a row.
// Returning NO to that message halts the selection process and does not cause the currently selected row to lose its selected look while the touch is down.
/**
 作用：【设置cell是否可以高亮】
 */
- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0);

/**
 作用：【cell 高亮调用的方法】
 */
- (void)tableView:(UITableView *)tableView didHighlightRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0);

/**
 作用：【cell 取消高亮调用的方法】
 */
- (void)tableView:(UITableView *)tableView didUnhighlightRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0);


// Called before the user changes the selection. Return a new indexPath, or nil, to change the proposed selection.
#pragma mark -当即将选中某行和取消选中某行时调用，返回行所在分区
- (nullable NSIndexPath *)tableView:(UITableView *)tableView willSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (nullable NSIndexPath *)tableView:(UITableView *)tableView willDeselectRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(3_0);


// Called after the user changes the selection.
#pragma mark -选中和取消选中后调用
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;
- (void)tableView:(UITableView *)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(3_0);



// Editing -- 编辑
#pragma mark - 编辑回调代理方法
// Allows customization of the editingStyle for a particular cell located at 'indexPath'. If not implemented, all editable cells will have UITableViewCellEditingStyleDelete set for them when the table has editing property set to YES.
#pragma mark -设置tableView被编辑时的状态风格，如果不设置，默认都是删除风格
/**
 注解：
    UITableViewCellEditingStyleNone,       没有
    UITableViewCellEditingStyleDelete,     删除
    UITableViewCellEditingStyleInsert      添加
 */
- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -自定义左滑删除按钮的标题
/**
 注解：return @"删除"
 */
- (nullable NSString *)tableView:(UITableView *)tableView titleForDeleteConfirmationButtonForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;


// Use -tableView:trailingSwipeActionsConfigurationForRowAtIndexPath: instead of this method, which will be deprecated in a future release.
// This method supersedes -tableView:titleForDeleteConfirmationButtonForRowAtIndexPath: if return value is non-nil
#pragma mark -用于自定义创建tableView被编辑时右边的按钮
/**
 注解：return @[action1,action];// 排列从右到左
 */
- (nullable NSArray<UITableViewRowAction *> *)tableView:(UITableView *)tableView editActionsForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;


// Swipe actions
// These methods supersede -editActionsForRowAtIndexPath: if implemented
// return nil to get the default swipe actions
- (nullable UISwipeActionsConfiguration *)tableView:(UITableView *)tableView leadingSwipeActionsConfigurationForRowAtIndexPath:(NSIndexPath *)indexPath API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos);
- (nullable UISwipeActionsConfiguration *)tableView:(UITableView *)tableView trailingSwipeActionsConfigurationForRowAtIndexPath:(NSIndexPath *)indexPath API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos);


// Controls whether the background is indented while editing.  If not implemented, the default is YES.  This is unrelated to the indentation level below.  This method only applies to grouped style table views.
#pragma mark -设置编辑时背景是否缩进
- (BOOL)tableView:(UITableView *)tableView shouldIndentWhileEditingRowAtIndexPath:(NSIndexPath *)indexPath;


// The willBegin/didEnd methods are called whenever the 'editing' property is automatically changed by the table (allowing insert/delete/move). This is done by a swipe activating a single row
#pragma mark -将要编辑和结束编辑时调用的方法s
- (void)tableView:(UITableView *)tableView willBeginEditingRowAtIndexPath:(NSIndexPath *)indexPath __TVOS_PROHIBITED;
- (void)tableView:(UITableView *)tableView didEndEditingRowAtIndexPath:(nullable NSIndexPath *)indexPath __TVOS_PROHIBITED;


#pragma mark - 移动，重新排序
// Moving/reordering
// Allows customization of the target row for a particular row as it is being moved/reordered
#pragma mark -移动特定的某行
- (NSIndexPath *)tableView:(UITableView *)tableView targetIndexPathForMoveFromRowAtIndexPath:(NSIndexPath *)sourceIndexPath toProposedIndexPath:(NSIndexPath *)proposedDestinationIndexPath;


// Indentation
#pragma mark -tableView行缩进
- (NSInteger)tableView:(UITableView *)tableView indentationLevelForRowAtIndexPath:(NSIndexPath *)indexPath; // return 'depth' of row for hierarchies








// Copy/Paste.-- 复制/粘贴  All three methods must be implemented by the delegate.
#pragma mark - 复制/粘贴

#pragma mark -通知委托是否在指定行显示菜单，返回值为YES时，长按显示菜单
- (BOOL)tableView:(UITableView *)tableView shouldShowMenuForRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(5_0);

#pragma mark -弹出选择菜单时会调用此方法（复制、粘贴、全选、剪切)
- (BOOL)tableView:(UITableView *)tableView canPerformAction:(SEL)action forRowAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender NS_AVAILABLE_IOS(5_0);

#pragma mark -选择菜单项完成之后调用此方法
- (void)tableView:(UITableView *)tableView performAction:(SEL)action forRowAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender NS_AVAILABLE_IOS(5_0);




#pragma mark - Focus -- 焦点

- (BOOL)tableView:(UITableView *)tableView canFocusRowAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);
- (BOOL)tableView:(UITableView *)tableView shouldUpdateFocusInContext:(UITableViewFocusUpdateContext *)context NS_AVAILABLE_IOS(9_0);
- (void)tableView:(UITableView *)tableView didUpdateFocusInContext:(UITableViewFocusUpdateContext *)context withAnimationCoordinator:(UIFocusAnimationCoordinator *)coordinator NS_AVAILABLE_IOS(9_0);
- (nullable NSIndexPath *)indexPathForPreferredFocusedViewInTableView:(UITableView *)tableView NS_AVAILABLE_IOS(9_0);


// Spring Loading

// Allows opting-out of spring loading for an particular row.
// If you want the interaction effect on a different subview of the spring loaded cell, modify the context.targetView property. The default is the cell.
// If this method is not implemented, the default is YES except when the row is part of a drag session.
- (BOOL)tableView:(UITableView *)tableView shouldSpringLoadRowAtIndexPath:(NSIndexPath *)indexPath withContext:(id<UISpringLoadedInteractionContext>)context API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


@end



// cell选中改变完成通知常量
UIKIT_EXTERN NSNotificationName const UITableViewSelectionDidChangeNotification;

typedef NS_ENUM(NSInteger, UITableViewSeparatorInsetReference) {
    // The value set to the separatorInset property is interpreted as an offset from the edges of the cell.
    UITableViewSeparatorInsetFromCellEdges,
    
    // The value set to the separatorInset property is interpreted as an offset from the automatic separator insets.
    UITableViewSeparatorInsetFromAutomaticInsets
} API_AVAILABLE(ios(11.0), tvos(11.0));



//_______________________________________________________________________________________________________________


#pragma mark - UITableView
NS_CLASS_AVAILABLE_IOS(2_0) @interface UITableView : UIScrollView <NSCoding, UIDataSourceTranslating>

#pragma mark - 初始化时必须指定类型
//(有普通(UITableViewStylePlain)和分组两种类型(UITableViewStyleGrouped))
- (instancetype)initWithFrame:(CGRect)frame style:(UITableViewStyle)style NS_DESIGNATED_INITIALIZER; // must specify style at creation. -initWithFrame: calls this with UITableViewStylePlain
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


#pragma mark - 常用属性
#pragma mark -类型
@property (nonatomic, readonly) UITableViewStyle style;
#pragma mark -数据源
@property (nonatomic, weak, nullable) id <UITableViewDataSource> dataSource; //
#pragma mark -代理方法
@property (nonatomic, weak, nullable) id <UITableViewDelegate> delegate; //
#pragma mark -预估数据源
@property (nonatomic, weak) id<UITableViewDataSourcePrefetching> prefetchDataSource NS_AVAILABLE_IOS(10_0);

@property (nonatomic, weak, nullable) id <UITableViewDragDelegate> dragDelegate API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);
@property (nonatomic, weak, nullable) id <UITableViewDropDelegate> dropDelegate API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

#pragma mark -全局设置row行高(默认 44)、区头高、区尾高
@property (nonatomic) CGFloat rowHeight;             // will return the default value if unset
@property (nonatomic) CGFloat sectionHeaderHeight;   // will return the default value if unset
@property (nonatomic) CGFloat sectionFooterHeight;   // will return the default value if unset

#pragma mark -全局设置Row估算高度、区头的估算高度、区尾的估算高度
@property (nonatomic) CGFloat estimatedRowHeight NS_AVAILABLE_IOS(7_0); // default is 0, which means there is no estimate
@property (nonatomic) CGFloat estimatedSectionHeaderHeight NS_AVAILABLE_IOS(7_0); // default is 0, which means there is no estimate
@property (nonatomic) CGFloat estimatedSectionFooterHeight NS_AVAILABLE_IOS(7_0); // default is 0, which means there is no estimate

#pragma mark - 设置分割线的内边距dequeueReusableCellWithIdentifier
@property (nonatomic) UIEdgeInsets separatorInset NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR-separatorInset; // allows customization of the frame of cell separators

@property (nonatomic, weak, nullable) id <UITableViewDragDelegate> dragDelegate API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);
@property (nonatomic, weak, nullable) id <UITableViewDropDelegate> dropDelegate API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


#pragma mark - 背景视图(自动匹配tableView视图的大小)
/**
 注解：
     设置后作为列表视图(tableView)的子视图，且在所有cell和headers/footers的后面。默认nil
 */
@property (nonatomic, strong, nullable) UIView *backgroundView NS_AVAILABLE_IOS(3_2); // the background view will be automatically resized to track the size of the table view.  this will be placed as a subview of the table view behind all cells and headers/footers.  default may be non-nil for some devices.

#pragma mark - 设置tableView 表头视图 和 表尾部视图
/**
 使用：
     self.tableView.tableFooterView = [[UIView alloc] init]; // 隐藏多余分割线
 */
@property (nonatomic, strong, nullable) UIView *tableHeaderView;                           // accessory view for above row content. default is nil. not to be confused with section header
@property (nonatomic, strong, nullable) UIView *tableFooterView;                           // accessory view below content. default is nil. not to be confused with section footer

// Returns YES if the table view is in the middle of reordering, is displaying a drop target gap, or has drop placeholders. If possible, avoid calling -reloadData while there are uncommitted updates to avoid interfering with user-initiated interactions that have not yet completed.
@property (nonatomic, readonly) BOOL hasUncommittedUpdates API_AVAILABLE(ios(11.0), tvos(11.0));


#pragma mark - 数据刷新
#pragma mark -全局刷新
- (void)reloadData; // reloads everything from scratch. redisplays visible rows. because we only keep info about visible rows, this is cheap. will adjust offset if table shrinks

#pragma mark -局部刷新
//section这个方法常用于新加或者删除了索引类别而无需刷新整个表视图的情况下
- (void)reloadSectionIndexTitles NS_AVAILABLE_IOS(3_0);   // reloads the index bar.









#pragma mark - 常用方法
// Info -- 信息
#pragma mark - 获取cell对应信息

#pragma mark -列表的组数
@property (nonatomic, readonly) NSInteger numberOfSections;
#pragma mark -某一组有多少行
- (NSInteger)numberOfRowsInSection:(NSInteger)section;
#pragma mark -某一组所占的矩形区域(包括header,footer和所有的行)
- (CGRect)rectForSection:(NSInteger)section;                                    // includes header, footer and all rows
#pragma mark -某一组的header所占的矩形区域
- (CGRect)rectForHeaderInSection:(NSInteger)section;
#pragma mark -某一组的footer所占的矩形区域
- (CGRect)rectForFooterInSection:(NSInteger)section;
#pragma mark -某一分区的row所占的矩形区域
- (CGRect)rectForRowAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -某一点在tableview上所占的分区，如果该点不在tableView的任何row上返回nil
- (nullable NSIndexPath *)indexPathForRowAtPoint:(CGPoint)point;                         // returns nil if point is outside of any row in the table
#pragma mark -某一行所在的分区，如果改行是不可见的返回nil
- (nullable NSIndexPath *)indexPathForCell:(UITableViewCell *)cell;                      // returns nil if cell is not visible
#pragma mark -某一矩形区域内所有行所在的所有分区，返回元素为NSIndexPath类型的数组。当该矩形是一个无效值时，返回nil
- (nullable NSArray<NSIndexPath *> *)indexPathsForRowsInRect:(CGRect)rect;                              // returns nil if rect not valid

#pragma mark -某一分区的cell，如果改cell是不可见的或者indexPath超出了范围则返回nil
- (nullable __kindof UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath;   // returns nil if cell is not visible or index path is out of range

#pragma mark -所有可见的cell，只读数组型(数组类型为UITableViewCell)
@property (nonatomic, readonly) NSArray<__kindof UITableViewCell *> *visibleCells;
#pragma mark -所有可见行所在的分区，只读数组型(数组类型为NSIndexPath)
@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForVisibleRows;

#pragma mark -某一组的header视图(常用于自定义headerView的时候用)
- (nullable UITableViewHeaderFooterView *)headerViewForSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);
#pragma mark -某一组的footer视图(常用于自定义footerView的时候用)
- (nullable UITableViewHeaderFooterView *)footerViewForSection:(NSInteger)section NS_AVAILABLE_IOS(6_0);

#pragma mark -使表格定位到某一行
- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

#pragma mark -使表格定位到选中行
- (void)scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated;

// Reloading and Updating
// Allows multiple insert/delete/reload/move calls to be animated simultaneously. Nestable.
- (void)performBatchUpdates:(void (NS_NOESCAPE ^ _Nullable)(void))updates completion:(void (^ _Nullable)(BOOL finished))completion API_AVAILABLE(ios(11.0), tvos(11.0));


// Row insertion/deletion/reloading. -- 行的插入/删除/刷新

#pragma mark - 操作：行的插入/删除/刷新

#pragma mark -允许多个插入/行和段被同时删除动画。可排序
- (void)beginUpdates;   // allow multiple insert/delete of rows and sections to be animated simultaneously. Nestable
#pragma mark -只调用插入/删除/重载呼叫或改变一更新区块内的编辑状态。然而对于行数等属性可能是无效的
- (void)endUpdates;     // only call insert/delete/reload calls or change the editing state inside an update block.  otherwise things like row count, etc. may be invalid.

#pragma mark -插入某些组
- (void)insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
#pragma mark -删除某些组
- (void)deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation;
#pragma mark -刷新某些组
- (void)reloadSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation NS_AVAILABLE_IOS(3_0);
#pragma mark -移动组section到组newSection的位置
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection NS_AVAILABLE_IOS(5_0);

#pragma mark -插入某些行
- (void)insertRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
#pragma mark -删除某些行
- (void)deleteRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation;
#pragma mark -刷新某些分区的行
- (void)reloadRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation NS_AVAILABLE_IOS(3_0);
#pragma mark -移动分区indexPath的行到分区newIndexPath
- (void)moveRowAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath NS_AVAILABLE_IOS(5_0);



#pragma mark - 编辑模式
// Editing. When set, rows show insert/delete/reorder controls based on data source queries
// -- 编辑。设置之后，行的显示会基于数据源查询插入/删除/重排序的控制

#pragma mark -设置是否是编辑状态(编辑状态下的cell左边会出现一个减号，右边会滑出删除按钮)
@property (nonatomic, getter=isEditing) BOOL editing;                             // default is NO. setting is not animated.
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;

#pragma mark -当不在编辑模式时，是否可以选中。默认YES
@property (nonatomic) BOOL allowsSelection NS_AVAILABLE_IOS(3_0);  // default is YES. Controls whether rows can be selected when not in editing mode
#pragma mark -当处在编辑模式时，是否可以选中。默认NO
@property (nonatomic) BOOL allowsSelectionDuringEditing;                                 // default is NO. Controls whether rows can be selected when in editing mode

#pragma mark -是否可以同时选中。默认NO
@property (nonatomic) BOOL allowsMultipleSelection NS_AVAILABLE_IOS(5_0);                // default is NO. Controls whether multiple rows can be selected simultaneously
#pragma mark -当处在编辑模式时，是否可以同时选中。默认NO
@property (nonatomic) BOOL allowsMultipleSelectionDuringEditing NS_AVAILABLE_IOS(5_0);   // default is NO. Controls whether multiple rows can be selected simultaneously in editing mode



// Selection -- 选中
#pragma mark - 选中的行所在的所有分区(单选、多选)
@property (nonatomic, readonly, nullable) NSIndexPath *indexPathForSelectedRow; // returns nil or index path representing section and row of selection.
@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForSelectedRows NS_AVAILABLE_IOS(5_0); // returns nil or a set of index paths representing the sections and rows of the selection.

// Selects and deselects rows. These methods will not call the delegate methods (-tableView:willSelectRowAtIndexPath: or tableView:didSelectRowAtIndexPath:), nor will it send out a notification.
#pragma mark - 手动选中与取消选中某行
// 这两个方法将不会回调代理中的方法
- (void)selectRowAtIndexPath:(nullable NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition;
- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;




// Appearance -- 外观
#pragma mark - 设置右侧索引

#pragma mark -设置索引栏最小显示行数。显示在右侧专门章节索引列表当行数达到此值。默认值为0
@property (nonatomic) NSInteger sectionIndexMinimumDisplayRowCount;                                                      // show special section index list on right when row count reaches this value. default is 0
#pragma mark -设置索引栏字体颜色
@property (nonatomic, strong, nullable) UIColor *sectionIndexColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;                   // color used for text of the section index
#pragma mark -设置索引栏背景颜色
@property (nonatomic, strong, nullable) UIColor *sectionIndexBackgroundColor NS_AVAILABLE_IOS(7_0) UI_APPEARANCE_SELECTOR;         // the background color of the section index while not being touched
#pragma mark -设置索引栏被选中时的颜色
@property (nonatomic, strong, nullable) UIColor *sectionIndexTrackingBackgroundColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR; // the background color of the section index while it is being touched



#pragma mark - 设置分割线
#pragma mark -设置分割线的风格
@property (nonatomic) UITableViewCellSeparatorStyle separatorStyle __TVOS_PROHIBITED; // default is UITableViewCellSeparatorStyleSingleLine
#pragma mark -设置分割线颜色
@property (nonatomic, strong, nullable) UIColor *separatorColor UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED; // default is the standard separator gray
#pragma mark -设置分割线毛玻璃效果(IOS8之后可用)
@property (nonatomic, copy, nullable) UIVisualEffect *separatorEffect NS_AVAILABLE_IOS(8_0) UI_APPEARANCE_SELECTOR __TVOS_PROHIBITED; // effect to apply to table separators

@property (nonatomic) BOOL cellLayoutMarginsFollowReadableWidth NS_AVAILABLE_IOS(9_0); // if cell margins are derived from the width of the readableContentGuide.
@property (nonatomic) BOOL insetsContentViewsToSafeArea API_AVAILABLE(ios(11.0), tvos(11.0)); // default value is YES


#pragma mark - Cell复用队列
#pragma mark -获取复用池中cell
/**
 不注册方式，cell复用队列使用这个方法.
 是只要缓存池有待复用的cell，不管什么类型这个方法都会拿来复用吗❓
 委托用于获取已分配的单元格，而不是分配一个新的单元格
 */
- (nullable __kindof UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;  // Used by the delegate to acquire an already allocated cell, in lieu of allocating a new one.

#pragma mark -获取一个已注册的cell
/**
 采用注册方式，cell复用队列使用这个方法.
 根据注册的标识ID，在缓存池中获取对应的cell❓
 假设标识符已注册，则较新的dequeue方法可确保正确返回单元格并调整其大小
 */
- (__kindof UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(6_0); // newer dequeue method guarantees a cell is returned and resized properly, assuming identifier is registered
#pragma mark -从复用池获取头视图或尾视图
- (nullable __kindof UITableViewHeaderFooterView *)dequeueReusableHeaderFooterViewWithIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);  // like dequeueReusableCellWithIdentifier:, but for headers/footers


// Beginning in iOS 6, clients can register a nib or class for each cell.
// If all reuse identifiers are registered, use the newer -dequeueReusableCellWithIdentifier:forIndexPath: to guarantee that a cell instance is returned.
// Instances returned from the new dequeue method will also be properly sized when they are returned.
#pragma mark - Cell注册
#pragma mark -cell注册（Xib）
- (void)registerNib:(nullable UINib *)nib forCellReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(5_0);
#pragma mark -cell注册（代码）
- (void)registerClass:(nullable Class)cellClass forCellReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);
#pragma mark -附加视图注册（Xib）
- (void)registerNib:(nullable UINib *)nib forHeaderFooterViewReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);
#pragma mark -附加视图注册（代码）
- (void)registerClass:(nullable Class)aClass forHeaderFooterViewReuseIdentifier:(NSString *)identifier NS_AVAILABLE_IOS(6_0);


// Focus -- 焦点
@property (nonatomic) BOOL remembersLastFocusedIndexPath NS_AVAILABLE_IOS(9_0); // defaults to NO. If YES, when focusing on a table view the last focused index path is focused automatically. If the table view has never been focused, then the preferred focused index path is used.


// Drag & Drop

// To enable intra-app drags on iPhone, set this to YES.
// You can also force drags to be disabled for this table view by setting this to NO.
// By default, this will return YES on iPad and NO on iPhone.
@property (nonatomic) BOOL dragInteractionEnabled API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

// YES if a drag session is currently active. A drag session begins after rows are "lifted" from the table view.
@property (nonatomic, readonly) BOOL hasActiveDrag API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

// YES if table view is currently tracking a drop session.
@property (nonatomic, readonly) BOOL hasActiveDrop API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


@end

//_______________________________________________________________________________________________________________
// this protocol represents the data model object. as such, it supplies no information about appearance (including the cells)
// -- 数据源协议方法，这个协议描绘了数据源模型，它不提供关于外观的任何信息(包括cell)

#pragma mark - DataSource
@protocol UITableViewDataSource<NSObject>

#pragma mark - @required（必须）
#pragma mark -多少行
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;

// Row display. Implementers should *always* try to reuse cells by setting each cell's reuseIdentifier and querying for available reusable cells with dequeueReusableCellWithIdentifier:
// Cell gets various attributes set automatically based on table (separators) and data source (accessory views, editing controls)
#pragma mark -行内容
//可以通过每个cell的标识对多种多样的cell进行查找，进而进行cell的复用
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark - @optional（可选）

#pragma mark -多少区
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView;              // Default is 1 if not implemented

#pragma mark -组头标题和组尾标题
- (nullable NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section;    // fixed font style. use custom view (UILabel) if you want something different
- (nullable NSString *)tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section;



// Editing -- 编辑相关
// Individual rows can opt out of having the -editing property set for them. If not implemented, all rows are assumed to be editable.
#pragma mark -每一行可以设置自己的编辑属性，默认YES，即是否可以删除移动选中等
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath;





// Moving/reordering -- 移动/重新排序
// Allows the reorder accessory view to optionally be shown for a particular row. By default, the reorder control will be shown only if the datasource implements -tableView:moveRowAtIndexPath:toIndexPath:
#pragma mark -设置某行是否可以被移动
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath;




// Index -- 索引
#pragma mark -设置索引栏组头标题数组
//实现这个方法，会在tableView右边显示每个分区的索引，例如：ABCDEFG...Z
- (nullable NSArray<NSString *> *)sectionIndexTitlesForTableView:(UITableView *)tableView __TVOS_PROHIBITED;                                                    // return list of section titles to display in section index view (e.g. "ABCD...Z#")

#pragma mark -设置索引栏组头标题对应的分区
- (NSInteger)tableView:(UITableView *)tableView sectionForSectionIndexTitle:(NSString *)title atIndex:(NSInteger)index __TVOS_PROHIBITED;  // tell table which section corresponds to section title/index (e.g. "B",1))


// Data manipulation - insert and delete support
// After a row has the minus or plus button invoked (based on the UITableViewCellEditingStyle for the cell), the dataSource must commit the change
// Not called for edit actions using UITableViewRowAction - the action's handler will be invoked instead
#pragma mark - tableView编辑时调用（只要实现这个方法,就拥有系统左滑删除功能）
//点击左滑出删除按钮会调用这个方法
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath;


// Data manipulation - reorder / moving support
#pragma mark - tableView的cell被移动时调用
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath;



@end




// _______________________________________________________________________________________________________________
// this protocol can provide information about cells before they are displayed on screen.
// 此协议可以在屏幕上显示之前提供有关单元格的信息

@protocol UITableViewDataSourcePrefetching <NSObject>

@required

// indexPaths are ordered ascending by geometric distance from the table view
- (void)tableView:(UITableView *)tableView prefetchRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

@optional

// indexPaths that previously were considered as candidates for pre-fetching, but were not actually used; may be a subset of the previous call to -tableView:prefetchRowsAtIndexPaths:
- (void)tableView:(UITableView *)tableView cancelPrefetchingForRowsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;

@end



// _______________________________________________________________________________________________________________
// Drag & Drop

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UITableViewDragDelegate <NSObject>

@required

// Provide items to begin a drag associated with a given index path.
// You can use -[session locationInView:] to do additional hit testing if desired.
// If an empty array is returned a drag session will not begin.
- (NSArray<UIDragItem *> *)tableView:(UITableView *)tableView itemsForBeginningDragSession:(id<UIDragSession>)session atIndexPath:(NSIndexPath *)indexPath;

@optional

// Called to request items to add to an existing drag session in response to the add item gesture.
// You can use the provided point (in the table view's coordinate space) to do additional hit testing if desired.
// If not implemented, or if an empty array is returned, no items will be added to the drag and the gesture
// will be handled normally.
- (NSArray<UIDragItem *> *)tableView:(UITableView *)tableView itemsForAddingToDragSession:(id<UIDragSession>)session atIndexPath:(NSIndexPath *)indexPath point:(CGPoint)point;

// Allows customization of the preview used for the row when it is lifted or if the drag cancels.
// If not implemented or if nil is returned, the entire cell will be used for the preview.
- (nullable UIDragPreviewParameters *)tableView:(UITableView *)tableView dragPreviewParametersForRowAtIndexPath:(NSIndexPath *)indexPath;

// Called after the lift animation has completed to signal the start of a drag session.
// This call will always be balanced with a corresponding call to -tableView:dragSessionDidEnd:
- (void)tableView:(UITableView *)tableView dragSessionWillBegin:(id<UIDragSession>)session;

// Called to signal the end of the drag session.
- (void)tableView:(UITableView *)tableView dragSessionDidEnd:(id<UIDragSession>)session;

// Controls whether move operations are allowed for the drag session.
// If not implemented, defaults to YES.
- (BOOL)tableView:(UITableView *)tableView dragSessionAllowsMoveOperation:(id<UIDragSession>)session;

// Controls whether the drag session is restricted to the source application.
// If not implemented, defaults to NO.
- (BOOL)tableView:(UITableView *)tableView dragSessionIsRestrictedToDraggingApplication:(id<UIDragSession>)session;

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UITableViewDropDelegate <NSObject>

@required

// Called when the user initiates the drop.
// Use the drop coordinator to access the items in the drop and the final destination index path and proposal for the drop,
// as well as specify how you wish to animate each item to its final position.
// If your implementation of this method does nothing, default drop animations will be supplied and the table view will
// revert back to its initial state before the drop session entered.
- (void)tableView:(UITableView *)tableView performDropWithCoordinator:(id<UITableViewDropCoordinator>)coordinator;

@optional

// If NO is returned no further delegate methods will be called for this drop session.
// If not implemented, a default value of YES is assumed.
- (BOOL)tableView:(UITableView *)tableView canHandleDropSession:(id<UIDropSession>)session;

// Called when the drop session begins tracking in the table view's coordinate space.
- (void)tableView:(UITableView *)tableView dropSessionDidEnter:(id<UIDropSession>)session;

// Called frequently while the drop session being tracked inside the table view's coordinate space.
// When the drop is at the end of a section, the destination index path passed will be for a row that does not yet exist (equal
// to the number of rows in that section), where an inserted row would append to the end of the section.
// The destination index path may be nil in some circumstances (e.g. when dragging over empty space where there are no cells).
// Note that in some cases your proposal may not be allowed and the system will enforce a different proposal.
// You may perform your own hit testing via -[session locationInView:]
- (UITableViewDropProposal *)tableView:(UITableView *)tableView dropSessionDidUpdate:(id<UIDropSession>)session withDestinationIndexPath:(nullable NSIndexPath *)destinationIndexPath;

// Called when the drop session is no longer being tracked inside the table view's coordinate space.
- (void)tableView:(UITableView *)tableView dropSessionDidExit:(id<UIDropSession>)session;

// Called when the drop session completed, regardless of outcome. Useful for performing any cleanup.
- (void)tableView:(UITableView *)tableView dropSessionDidEnd:(id<UIDropSession>)session;

// Allows customization of the preview used when dropping to a newly inserted row.
// If not implemented or if nil is returned, the entire cell will be used for the preview.
- (nullable UIDragPreviewParameters *)tableView:(UITableView *)tableView dropPreviewParametersForRowAtIndexPath:(NSIndexPath *)indexPath;

@end



typedef NS_ENUM(NSInteger, UITableViewDropIntent) {
    // Table view will accept the drop, but the location is not yet known and will be determined later.
    // Will not open a gap. You may wish to provide some visual treatment to communicate this to the user.
    UITableViewDropIntentUnspecified,
    
    // The drop will be placed in row(s) inserted at the destination index path.
    // Opens a gap at the specified location simulating the final dropped layout.
    UITableViewDropIntentInsertAtDestinationIndexPath,
    
    // The drop will be placed inside the row at the destination index path (e.g. the row is a container of other items).
    // Will not open a gap. Table view will highlight the row at the destination index path.
    UITableViewDropIntentInsertIntoDestinationIndexPath,
    
    // The table view will automatically choose between .insertAtDestinationIndexPath and
    // .insertIntoDestinationIndexPath depending on the position of the drop. This should be used instead
    // of .insertIntoDestinationIndexPath when the item being dropped can either be placed inside the row
    // at the destination index path or inserted in a new row at the index path of the container row.
    UITableViewDropIntentAutomatic
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@interface UITableViewDropProposal : UIDropProposal

- (instancetype)initWithDropOperation:(UIDropOperation)operation intent:(UITableViewDropIntent)intent;

// The default is UITableViewDropIntentUnspecified.
@property (nonatomic, readonly) UITableViewDropIntent intent;

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UITableViewDropCoordinator <NSObject>

// Ordered list of items available for this drop.
@property (nonatomic, readonly) NSArray<id<UITableViewDropItem>> *items;

// The last hit-tested index path known during the drop session.
// When the drop is at the end of a section, this index path will be for a row that does not yet exist (equal
// to the number of rows in that section), where an inserted row would append to the end of the section.
// This index path may be nil in some circumstances (e.g. when dragging over empty space where there are no cells),
// and if it is nil, the proposal's intent will always be UITableViewDropIntentUnspecified.
@property (nonatomic, readonly, nullable) NSIndexPath *destinationIndexPath;

// The current drop proposal at the time of the drop.
@property (nonatomic, readonly) UITableViewDropProposal *proposal;

// The drop session.
@property (nonatomic, readonly) id<UIDropSession> session;

// Animate the dragItem to an automatically inserted placeholder row.
// Once the dragItem data is available, you can exchange the temporary placeholder cell with the final cell using the placeholder context
// method -commitInsertionWithDataSourceUpdates:
- (id<UITableViewDropPlaceholderContext>)dropItem:(UIDragItem *)dragItem toPlaceholder:(UITableViewDropPlaceholder *)placeholder;

// Animate the dragItem to a row that you inserted at this index path.
// You must call -performBatchUpdates:completion: to update your data source and insert a new row into the table view prior to calling this method.
// If desired, use the drop delegate method -tableView:dropPreviewParametersForRowAtIndexPath: to provide preview parameters.
- (id<UIDragAnimating>)dropItem:(UIDragItem *)dragItem toRowAtIndexPath:(NSIndexPath *)indexPath;

// Animate the dragItem to a rect inside an existing row.
// The rect is in the coordinate space of the cell at this index path.
// The item will be animated with an aspect fit scale transform to fit inside the rect. Use a rect with zero size to shrink the item to a single point.
- (id<UIDragAnimating>)dropItem:(UIDragItem *)dragItem intoRowAtIndexPath:(NSIndexPath *)indexPath rect:(CGRect)rect;

// Animate the dragItem to a location specified by the UIDragPreviewTarget.
// The -[UITableViewDropItem previewSize] may be helpful to compute an appropriate transform.
- (id<UIDragAnimating>)dropItem:(UIDragItem *)dragItem toTarget:(UIDragPreviewTarget *)target;

@end


UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@interface UITableViewPlaceholder : NSObject

// A placeholder cell will be dequeued for the reuse identifier and inserted at the specified index path without requiring a data source update.
// You may use UITableViewAutomaticDimension for the rowHeight to have the placeholder cell self-size if the table view is using estimated row heights.
- (instancetype)initWithInsertionIndexPath:(NSIndexPath *)insertionIndexPath reuseIdentifier:(NSString *)reuseIdentifier rowHeight:(CGFloat)rowHeight NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

// Called whenever the placeholder cell is visible to update the contents of the cell.
@property (nonatomic, nullable, copy) void(^cellUpdateHandler)(__kindof UITableViewCell *);

@end

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@interface UITableViewDropPlaceholder : UITableViewPlaceholder

// Allows customization of the preview used when dropping to a placeholder.
// If no block is set, or if nil is returned, the entire cell will be used for the preview.
@property (nonatomic, nullable, copy) UIDragPreviewParameters * _Nullable (^previewParametersProvider)(__kindof UITableViewCell *);

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UITableViewDropItem <NSObject>

// Retrieve drop data from the dragItem's itemProvider.
@property (nonatomic, readonly) UIDragItem *dragItem;

// If this drop item is also from this table view this index path will specify the location of the row it came from.
// If the dragItem comes from some other source (e.g. another source inside or outside of the app), or if the source
// table view is updated or reloaded after the drag begins, this index path will be nil.
// This is useful for directly accessing the model object in your data source instead of using the item provider
// to retrieve the data.
@property (nonatomic, readonly, nullable) NSIndexPath *sourceIndexPath;

// May be useful for computing the UIDragPreviewTarget transform for UITableViewDropCoordinator dropItem:toTarget:
// Returns CGSizeZero if the dragItem does not have a visible drop preview.
@property (nonatomic, readonly) CGSize previewSize;

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UITableViewDropPlaceholderContext <UIDragAnimating>

// The drag item this placeholder was created for.
@property (nonatomic, readonly) UIDragItem *dragItem;

// Exchange the placeholder for the final cell.
// You are only responsible for updating your data source inside the block using the provided insertionIndexPath.
// If the placeholder is no longer available (e.g. -reloadData has been called) the dataSourceUpdates block
// will not be executed and this will return NO.
- (BOOL)commitInsertionWithDataSourceUpdates:(void(NS_NOESCAPE ^)(NSIndexPath *insertionIndexPath))dataSourceUpdates;

// If the placeholder is no longer needed or you wish to manually insert a cell for the drop data, you can
// remove the placeholder via this method.
// If the placeholder is no longer available (e.g. -reloadData has been called) this will return NO.
- (BOOL)deletePlaceholder;

@end

NS_ASSUME_NONNULL_END










