/*
 * File:  UICollectionView.h 
 *
 * Framework: UIKit (c) 2011-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <UIKit/UIScrollView.h>
#import <UIKit/UIKitDefines.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#pragma mark - NS_ENUM
#pragma mark -滚动位置
typedef NS_OPTIONS(NSUInteger, UICollectionViewScrollPosition) {
    UICollectionViewScrollPositionNone                 = 0,
    
    // The vertical positions are mutually exclusive to each other, but are bitwise or-able with the horizontal scroll positions.
    // Combining positions from the same grouping (horizontal or vertical) will result in an NSInvalidArgumentException.
    UICollectionViewScrollPositionTop                  = 1 << 0,
    UICollectionViewScrollPositionCenteredVertically   = 1 << 1,
    UICollectionViewScrollPositionBottom               = 1 << 2,
    
    // Likewise, the horizontal positions are mutually exclusive to each other.
    UICollectionViewScrollPositionLeft                 = 1 << 3,
    UICollectionViewScrollPositionCenteredHorizontally = 1 << 4,
    UICollectionViewScrollPositionRight                = 1 << 5
};

#pragma mark -重新排列节奏
typedef NS_ENUM(NSInteger, UICollectionViewReorderingCadence) {
    UICollectionViewReorderingCadenceImmediate,
    UICollectionViewReorderingCadenceFast,
    UICollectionViewReorderingCadenceSlow
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);




@class UICollectionView, UICollectionReusableView, UICollectionViewCell, UICollectionViewLayout, UICollectionViewTransitionLayout, UICollectionViewLayoutAttributes, UITouch, UINib;
@class UIDragItem, UIDragPreviewParameters, UIDragPreviewTarget;
@class UICollectionViewDropProposal, UICollectionViewPlaceholder, UICollectionViewDropPlaceholder;
@protocol UIDataSourceTranslating, UISpringLoadedInteractionContext;
@protocol UIDragSession, UIDropSession;
@protocol UICollectionViewDragDelegate, UICollectionViewDropDelegate, UICollectionViewDropCoordinator, UICollectionViewDropItem, UICollectionViewDropPlaceholderContext;




#pragma mark -布局转换Block
// layout transition block signature
typedef void (^UICollectionViewLayoutInteractiveTransitionCompletion)(BOOL completed, BOOL finished);



#pragma mark - UICollectionView FocusUpdateContext
NS_CLASS_AVAILABLE_IOS(9_0) @interface UICollectionViewFocusUpdateContext : UIFocusUpdateContext

@property (nonatomic, strong, readonly, nullable) NSIndexPath *previouslyFocusedIndexPath;
@property (nonatomic, strong, readonly, nullable) NSIndexPath *nextFocusedIndexPath;

@end




#pragma mark - DataSource
@protocol UICollectionViewDataSource <NSObject>

#pragma mark -@required（必须）

#pragma mark -设置每个组Section中有多少个item
- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section;

#pragma mark -设置每个组中 item的内容，类似于UITableViewCell的设置
// The cell that is returned must be retrieved from a call to -dequeueReusableCellWithReuseIdentifier:forIndexPath:
- (__kindof UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;


#pragma mark -@optional（可选）

#pragma mark -设置容器视图有多少组Section，系统默认返回值为1
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView;

#pragma mark -返回顶部视图和底部视图，通过kind参数分辨是设置顶部还是底部（补充视图）
// The view that is returned must be retrieved from a call to -dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:
/**
 注解：补充视图，这里可以充当区的头和尾，我们自己不实现的话，系统默认返回值为nil
 */
- (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

#pragma mark -指定的单元格项目是否可以移动到集合视图中的另一个位置，默认返回值为NO
- (BOOL)collectionView:(UICollectionView *)collectionView canMoveItemAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);

#pragma mark -将指定的单元格项目从一个位置移动到集合视图中的另一个位置
- (void)collectionView:(UICollectionView *)collectionView moveItemAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath*)destinationIndexPath NS_AVAILABLE_IOS(9_0);

@end



#pragma mark - DataSourcePrefetching
@protocol UICollectionViewDataSourcePrefetching <NSObject>
@required
// indexPaths are ordered ascending by geometric distance from the collection view
- (void)collectionView:(UICollectionView *)collectionView prefetchItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths NS_AVAILABLE_IOS(10_0);

@optional
// indexPaths that previously were considered as candidates for pre-fetching, but were not actually used; may be a subset of the previous call to -collectionView:prefetchItemsAtIndexPaths:
- (void)collectionView:(UICollectionView *)collectionView cancelPrefetchingForItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths  NS_AVAILABLE_IOS(10_0);

@end



#pragma mark - Delegate
@protocol UICollectionViewDelegate <UIScrollViewDelegate>
@optional
/**
 事件的处理顺序如下：
    1、手指按下：shouldHighlightItemAtIndexPath (如果返回YES则向下执行，否则执行到这里为止)。
    2、didHighlightItemAtIndexPath (高亮)。
    3、手指松开：didUnhighlightItemAtIndexPath (取消高亮)。
    4、shouldSelectItemAtIndexPath (如果返回YES则向下执行，否则执行到这里为止)。
    5、didSelectItemAtIndexPath (执行选择事件)。
 */
// Methods for notification of selection/deselection and highlight/unhighlight events.
// The sequence of calls leading to selection from a user touch is:
//
// (when the touch begins)
// 1. -collectionView:shouldHighlightItemAtIndexPath:
// 2. -collectionView:didHighlightItemAtIndexPath:
//
// (when the touch lifts)
// 3. -collectionView:shouldSelectItemAtIndexPath: or -collectionView:shouldDeselectItemAtIndexPath:
// 4. -collectionView:didSelectItemAtIndexPath: or -collectionView:didDeselectItemAtIndexPath:
// 5. -collectionView:didUnhighlightItemAtIndexPath:

#pragma mark -cell点击时是否高亮
- (BOOL)collectionView:(UICollectionView *)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -手指长按下高亮
- (void)collectionView:(UICollectionView *)collectionView didHighlightItemAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -手指松开取消高亮
- (void)collectionView:(UICollectionView *)collectionView didUnhighlightItemAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -当前item是否可以点击
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSelectItemAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -当前item是否取消点击
- (BOOL)collectionView:(UICollectionView *)collectionView shouldDeselectItemAtIndexPath:(NSIndexPath *)indexPath; // called when the user taps on an already-selected item in multi-select mode


#pragma mark - 选中item 和 取消选中item
- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didDeselectItemAtIndexPath:(NSIndexPath *)indexPath;



#pragma mark - 指定indexPath的cell的显示或移除调用方法
/**
 这两个方法分别是 指定indexPath的cell将要显示出的时候调用, 指定indexPath的头部或尾部视图view将要显示出来的时候调用
 */
- (void)collectionView:(UICollectionView *)collectionView willDisplayCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(8_0);
- (void)collectionView:(UICollectionView *)collectionView willDisplaySupplementaryView:(UICollectionReusableView *)view forElementKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(8_0);

- (void)collectionView:(UICollectionView *)collectionView didEndDisplayingCell:(UICollectionViewCell *)cell forItemAtIndexPath:(NSIndexPath *)indexPath;
- (void)collectionView:(UICollectionView *)collectionView didEndDisplayingSupplementaryView:(UICollectionReusableView *)view forElementOfKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath;



// These methods provide support for copy/paste actions on cells.
// All three should be implemented if any are.
#pragma mark - 支持长按后的菜单 复制/粘贴操作相关方法

#pragma mark -是否弹出菜单，需要返回YES
- (BOOL)collectionView:(UICollectionView *)collectionView shouldShowMenuForItemAtIndexPath:(NSIndexPath *)indexPath;

#pragma mark -是否可以弹出事件，使copy和paste有效
- (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender;

#pragma mark -对事件进行相应操作
- (void)collectionView:(UICollectionView *)collectionView performAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender;
/**
 示例：假如我们只想使用拷贝和粘贴，可以这样写：
 - (BOOL)collectionView:(UICollectionView *)collectionView canPerformAction:(SEL)action forItemAtIndexPath:(NSIndexPath *)indexPath withSender:(nullable id)sender {
    if ([NSStringFromSelector(action) isEqualToString:@"copy:"] || [NSStringFromSelector(action) isEqualToString:@"paste:"]){
    return YES;
    }
    return NO;
 }
 */


#pragma mark - support for custom transition layout
- (nonnull UICollectionViewTransitionLayout *)collectionView:(UICollectionView *)collectionView transitionLayoutForOldLayout:(UICollectionViewLayout *)fromLayout newLayout:(UICollectionViewLayout *)toLayout;

#pragma mark - Focus
- (BOOL)collectionView:(UICollectionView *)collectionView canFocusItemAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);
- (BOOL)collectionView:(UICollectionView *)collectionView shouldUpdateFocusInContext:(UICollectionViewFocusUpdateContext *)context NS_AVAILABLE_IOS(9_0);
- (void)collectionView:(UICollectionView *)collectionView didUpdateFocusInContext:(UICollectionViewFocusUpdateContext *)context withAnimationCoordinator:(UIFocusAnimationCoordinator *)coordinator NS_AVAILABLE_IOS(9_0);
- (nullable NSIndexPath *)indexPathForPreferredFocusedViewInCollectionView:(UICollectionView *)collectionView NS_AVAILABLE_IOS(9_0);

- (NSIndexPath *)collectionView:(UICollectionView *)collectionView targetIndexPathForMoveFromItemAtIndexPath:(NSIndexPath *)originalIndexPath toProposedIndexPath:(NSIndexPath *)proposedIndexPath NS_AVAILABLE_IOS(9_0);

- (CGPoint)collectionView:(UICollectionView *)collectionView targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset NS_AVAILABLE_IOS(9_0); // customize the content offset to be applied during transition or update animations


#pragma mark - Spring Loading

/* Allows opting-out of spring loading for an particular item.
 *
 * If you want the interaction effect on a different subview of the spring loaded cell, modify the context.targetView property.
 * The default is the cell.
 *
 * If this method is not implemented, the default is YES.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView shouldSpringLoadItemAtIndexPath:(NSIndexPath *)indexPath withContext:(id<UISpringLoadedInteractionContext>)context API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


@end







#pragma mark - 综合视图
NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionView : UIScrollView <UIDataSourceTranslating>

#pragma mark - 初始化
- (instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout *)layout NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

#pragma mark - 常用属性
#pragma mark -布局对象
@property (nonatomic, strong) UICollectionViewLayout *collectionViewLayout;
#pragma mark -代理
@property (nonatomic, weak, nullable) id <UICollectionViewDelegate> delegate;
#pragma mark -数据源
@property (nonatomic, weak, nullable) id <UICollectionViewDataSource> dataSource;
@property (nonatomic, weak, nullable) id<UICollectionViewDataSourcePrefetching> prefetchDataSource NS_AVAILABLE_IOS(10_0);

/**
 预加载
 */
@property (nonatomic, getter=isPrefetchingEnabled) BOOL prefetchingEnabled NS_AVAILABLE_IOS(10_0);

@property (nonatomic, weak, nullable) id <UICollectionViewDragDelegate> dragDelegate API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);
@property (nonatomic, weak, nullable) id <UICollectionViewDropDelegate> dropDelegate API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

/* To enable intra-app drags on iPhone, set this to YES.
 * You can also force drags to be disabled for this collection view by setting this to NO.
 * By default, For iPad this will return YES and iPhone will return NO.
 */
@property (nonatomic) BOOL dragInteractionEnabled API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

/* Reordering cadence affects how easily reordering occurs while dragging around a reorder-capable drop destination.
 * Default is UICollectionViewReorderingCadenceImmediate.
 */
@property (nonatomic) UICollectionViewReorderingCadence reorderingCadence API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


#pragma mark -背景视图
@property (nonatomic, strong, nullable) UIView *backgroundView; // will be automatically resized to track the size of the collection view and placed behind all cells and supplementary views.



#pragma mark - 常用方法
#pragma mark -cell注册（Class、Xib）
// For each reuse identifier that the collection view will use, register either a class or a nib from which to instantiate a cell.
// If a nib is registered, it must contain exactly 1 top level object which is a UICollectionViewCell.
// If a class is registered, it will be instantiated via alloc/initWithFrame:
/**
 使用：
     [self.collectionView registerClass:[LNCollectionViewCell class] forCellWithReuseIdentifier:cellID];
     [self.collectionView registerNib:[UINib nibWithNibName:NSStringFromClass([LNCollectionViewCell class]) bundle:nil] forCellWithReuseIdentifier:cellID];
 */
- (void)registerClass:(nullable Class)cellClass forCellWithReuseIdentifier:(NSString *)identifier;
- (void)registerNib:(nullable UINib *)nib forCellWithReuseIdentifier:(NSString *)identifier;




#pragma mark -补充视图(HeaderView 和 FooterView)注册（Class、Xib）
/**
 使用：
     [self.collectionView registerClass:[UICollectionReusableView class] forSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:HeadViewID];
 
     [self.collectionView registerNib:[UINib nibWithNibName:NSStringFromClass([LNHeaderCollectionReusableView class]) bundle:nil] forSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:HeadViewID];
 */
- (void)registerClass:(nullable Class)viewClass forSupplementaryViewOfKind:(NSString *)elementKind withReuseIdentifier:(NSString *)identifier;
- (void)registerNib:(nullable UINib *)nib forSupplementaryViewOfKind:(NSString *)kind withReuseIdentifier:(NSString *)identifier;


#pragma mark -cell复用队列（访问缓存池）
/**
 使用：
     LNCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:cellID forIndexPath:indexPath];
 
     LNHeaderCollectionReusableView *headView = [collectionView dequeueReusableSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:HeadViewID forIndexPath:indexPath];
 */
- (__kindof UICollectionViewCell *)dequeueReusableCellWithReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;
- (__kindof UICollectionReusableView *)dequeueReusableSupplementaryViewOfKind:(NSString *)elementKind withReuseIdentifier:(NSString *)identifier forIndexPath:(NSIndexPath *)indexPath;

#pragma mark - 允许选择 或 多个选择
// These properties control whether items can be selected, and if so, whether multiple items can be simultaneously selected.
@property (nonatomic) BOOL allowsSelection; // default is YES
@property (nonatomic) BOOL allowsMultipleSelection; // default is NO



#pragma mark - 返回所有选中Items 下标的数组
#if UIKIT_DEFINE_AS_PROPERTIES
@property (nonatomic, readonly, nullable) NSArray<NSIndexPath *> *indexPathsForSelectedItems; // returns nil or an array of selected index paths
#else
- (nullable NSArray<NSIndexPath *> *)indexPathsForSelectedItems; // returns nil or an array of selected index paths
#endif
- (void)selectItemAtIndexPath:(nullable NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UICollectionViewScrollPosition)scrollPosition;
- (void)deselectItemAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated;

// Returns YES if the collection view is reordering or has drop placeholders.
@property (nonatomic, readonly) BOOL hasUncommittedUpdates API_AVAILABLE(ios(11.0));


#pragma mark - 全局刷新
- (void)reloadData; // discard the dataSource and delegate data and requery as necessary



#pragma mark - 这两个方法是布局动画
- (void)setCollectionViewLayout:(UICollectionViewLayout *)layout animated:(BOOL)animated; // transition from one layout to another
- (void)setCollectionViewLayout:(UICollectionViewLayout *)layout animated:(BOOL)animated completion:(void (^ __nullable)(BOOL finished))completion NS_AVAILABLE_IOS(7_0);

#pragma mark - Transition
- (UICollectionViewTransitionLayout *)startInteractiveTransitionToCollectionViewLayout:(UICollectionViewLayout *)layout completion:(nullable UICollectionViewLayoutInteractiveTransitionCompletion)completion NS_AVAILABLE_IOS(7_0);
- (void)finishInteractiveTransition NS_AVAILABLE_IOS(7_0);
- (void)cancelInteractiveTransition NS_AVAILABLE_IOS(7_0);


#pragma mark - 获取对应信息
// Information about the current state of the collection view.
#if UIKIT_DEFINE_AS_PROPERTIES
@property (nonatomic, readonly) NSInteger numberOfSections;
#else
- (NSInteger)numberOfSections;
#endif
- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (nullable UICollectionViewLayoutAttributes *)layoutAttributesForItemAtIndexPath:(NSIndexPath *)indexPath;
- (nullable UICollectionViewLayoutAttributes *)layoutAttributesForSupplementaryElementOfKind:(NSString *)kind atIndexPath:(NSIndexPath *)indexPath;

- (nullable NSIndexPath *)indexPathForItemAtPoint:(CGPoint)point;
- (nullable NSIndexPath *)indexPathForCell:(UICollectionViewCell *)cell;

- (nullable UICollectionViewCell *)cellForItemAtIndexPath:(NSIndexPath *)indexPath;




#if UIKIT_DEFINE_AS_PROPERTIES
@property (nonatomic, readonly) NSArray<__kindof UICollectionViewCell *> *visibleCells;
@property (nonatomic, readonly) NSArray<NSIndexPath *> *indexPathsForVisibleItems;
#else
- (NSArray<__kindof UICollectionViewCell *> *)visibleCells;
- (NSArray<NSIndexPath *> *)indexPathsForVisibleItems;
#endif

- (nullable UICollectionReusableView *)supplementaryViewForElementKind:(NSString *)elementKind atIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0);
- (NSArray<UICollectionReusableView *> *)visibleSupplementaryViewsOfKind:(NSString *)elementKind NS_AVAILABLE_IOS(9_0);
- (NSArray<NSIndexPath *> *)indexPathsForVisibleSupplementaryElementsOfKind:(NSString *)elementKind NS_AVAILABLE_IOS(9_0);

// Interacting with the collection view.
/**
 与综合视图交互
 */
- (void)scrollToItemAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UICollectionViewScrollPosition)scrollPosition animated:(BOOL)animated;



#pragma mark - 允许动态修改当前的Item 和 Section方法
// These methods allow dynamic modification of the current set of items in the collection view

#pragma mark -插入Section
- (void)insertSections:(NSIndexSet *)sections;
#pragma mark -删除Section
- (void)deleteSections:(NSIndexSet *)sections;
#pragma mark -刷新Section
- (void)reloadSections:(NSIndexSet *)sections;
#pragma mark -移动Section
- (void)moveSection:(NSInteger)section toSection:(NSInteger)newSection;

#pragma mark -插入Item
- (void)insertItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
#pragma mark -删除Item
- (void)deleteItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
#pragma mark -刷新Item
- (void)reloadItemsAtIndexPaths:(NSArray<NSIndexPath *> *)indexPaths;
#pragma mark -移动Item
- (void)moveItemAtIndexPath:(NSIndexPath *)indexPath toIndexPath:(NSIndexPath *)newIndexPath;

#pragma mark -也可以批量操作
- (void)performBatchUpdates:(void (^ __nullable)(void))updates completion:(void (^ __nullable)(BOOL finished))completion; // allows multiple insert/delete/reload/move calls to be animated simultaneously. Nestable.

// Support for reordering
- (BOOL)beginInteractiveMovementForItemAtIndexPath:(NSIndexPath *)indexPath NS_AVAILABLE_IOS(9_0); // returns NO if reordering was prevented from beginning - otherwise YES
- (void)updateInteractiveMovementTargetPosition:(CGPoint)targetPosition NS_AVAILABLE_IOS(9_0);
- (void)endInteractiveMovement NS_AVAILABLE_IOS(9_0);
- (void)cancelInteractiveMovement NS_AVAILABLE_IOS(9_0);

// Support for Focus
@property (nonatomic) BOOL remembersLastFocusedIndexPath NS_AVAILABLE_IOS(9_0); // defaults to NO. If YES, when focusing on a collection view the last focused index path is focused automatically. If the collection view has never been focused, then the preferred focused index path is used.

// Drag & Drop

/* YES if a drag session is currently active. A drag session begins after items are "lifted" from the collection view.
 */
@property (nonatomic, readonly) BOOL hasActiveDrag API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

/* YES if collection view is currently tracking a drop session.
 */
@property (nonatomic, readonly) BOOL hasActiveDrop API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


@end
# WechatPublic-Codeidea

// _______________________________________________________________________________________________________________
// Drag & Drop
#pragma mark - Drag & Drop (ios(11.0))

#if TARGET_OS_IOS
@interface UICollectionView (UIDragAndDrop) <UISpringLoadedInteractionSupporting>
@end
#endif

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UICollectionViewDragDelegate <NSObject>

@required

/* Provide items to begin a drag associated with a given indexPath.
 * If an empty array is returned a drag session will not begin.
 */
- (NSArray<UIDragItem *> *)collectionView:(UICollectionView *)collectionView itemsForBeginningDragSession:(id<UIDragSession>)session atIndexPath:(NSIndexPath *)indexPath;

@optional

/* Called to request items to add to an existing drag session in response to the add item gesture.
 * You can use the provided point (in the collection view's coordinate space) to do additional hit testing if desired.
 * If not implemented, or if an empty array is returned, no items will be added to the drag and the gesture
 * will be handled normally.
 */
- (NSArray<UIDragItem *> *)collectionView:(UICollectionView *)collectionView itemsForAddingToDragSession:(id<UIDragSession>)session atIndexPath:(NSIndexPath *)indexPath point:(CGPoint)point;

/* Allows customization of the preview used for the item being lifted from or cancelling back to the collection view.
 * If not implemented or if nil is returned, the entire cell will be used for the preview.
 */
- (nullable UIDragPreviewParameters *)collectionView:(UICollectionView *)collectionView dragPreviewParametersForItemAtIndexPath:(NSIndexPath *)indexPath;

/* Called after the lift animation has completed to signal the start of a drag session.
 * This call will always be balanced with a corresponding call to -collectionView:dragSessionDidEnd:
 */
- (void)collectionView:(UICollectionView *)collectionView dragSessionWillBegin:(id<UIDragSession>)session;

/* Called to signal the end of the drag session.
 */
- (void)collectionView:(UICollectionView *)collectionView dragSessionDidEnd:(id<UIDragSession>)session;


/* Controls whether move operations (see UICollectionViewDropProposal.operation) are allowed for the drag session.
 * If not implemented this will default to YES.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView dragSessionAllowsMoveOperation:(id<UIDragSession>)session;

/* Controls whether the drag session is restricted to the source application.
 * If YES the current drag session will not be permitted to drop into another application.
 * If not implemented this will default to NO.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView dragSessionIsRestrictedToDraggingApplication:(id<UIDragSession>)session;

@end

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UICollectionViewDropDelegate <NSObject>

@required

/* Called when the user initiates the drop.
 * Use the dropCoordinator to specify how you wish to animate the dropSession's items into their final position as
 * well as update the collection view's data source with data retrieved from the dropped items.
 * If the supplied method does nothing, default drop animations will be supplied and the collection view will
 * revert back to its initial pre-drop session state.
 */
- (void)collectionView:(UICollectionView *)collectionView performDropWithCoordinator:(id<UICollectionViewDropCoordinator>)coordinator;

@optional

/* If NO is returned no further delegate methods will be called for this drop session.
 * If not implemented, a default value of YES is assumed.
 */
- (BOOL)collectionView:(UICollectionView *)collectionView canHandleDropSession:(id<UIDropSession>)session;

/* Called when the drop session begins tracking in the collection view's coordinate space.
 */
- (void)collectionView:(UICollectionView *)collectionView dropSessionDidEnter:(id<UIDropSession>)session;

/* Called frequently while the drop session being tracked inside the collection view's coordinate space.
 * When the drop is at the end of a section, the destination index path passed will be for a item that does not yet exist (equal
 * to the number of items in that section), where an inserted item would append to the end of the section.
 * The destination index path may be nil in some circumstances (e.g. when dragging over empty space where there are no cells).
 * Note that in some cases your proposal may not be allowed and the system will enforce a different proposal.
 * You may perform your own hit testing via -[UIDropSession locationInView]
 */
- (UICollectionViewDropProposal *)collectionView:(UICollectionView *)collectionView dropSessionDidUpdate:(id<UIDropSession>)session withDestinationIndexPath:(nullable NSIndexPath *)destinationIndexPath;

/* Called when the drop session is no longer being tracked inside the collection view's coordinate space.
 */
- (void)collectionView:(UICollectionView *)collectionView dropSessionDidExit:(id<UIDropSession>)session;

/* Called when the drop session completed, regardless of outcome. Useful for performing any cleanup.
 */
- (void)collectionView:(UICollectionView *)collectionView dropSessionDidEnd:(id<UIDropSession>)session;

/* Allows customization of the preview used for the item being dropped.
 * If not implemented or if nil is returned, the entire cell will be used for the preview.
 *
 * This will be called as needed when animating drops via -[UICollectionViewDropCoordinator dropItem:toItemAtIndexPath:]
 * (to customize placeholder drops, please see UICollectionViewDropPlaceholder.previewParametersProvider)
 */
- (nullable UIDragPreviewParameters *)collectionView:(UICollectionView *)collectionView dropPreviewParametersForItemAtIndexPath:(NSIndexPath *)indexPath;

@end

typedef NS_ENUM(NSInteger, UICollectionViewDropIntent) {
    /* Collection view will accept the drop, but the location is not yet known and will be determined later.
     * Will not open a gap. You may wish to provide some visual treatment to communicate this to the user.
     */
    UICollectionViewDropIntentUnspecified,
    
    /* The drop will be placed in item(s) inserted at the destination index path.
     * Opens a gap at the specified location simulating the final dropped layout.
     */
    UICollectionViewDropIntentInsertAtDestinationIndexPath,
    
    /* The drop will be placed inside the item at the destination index path (e.g. the item is a container of other items).
     * Will not open a gap. Collection view will highlight the item at the destination index path.
     */
    UICollectionViewDropIntentInsertIntoDestinationIndexPath,
    
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);


UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@interface UICollectionViewDropProposal : UIDropProposal

- (instancetype)initWithDropOperation:(UIDropOperation)operation intent:(UICollectionViewDropIntent)intent;

/* The default is UICollectionViewDropIntentUnspecified.
 */
@property (nonatomic, readonly) UICollectionViewDropIntent intent;

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UICollectionViewDropCoordinator <NSObject>

/* Ordered list of items available for this drop.
 */
@property (nonatomic, readonly) NSArray<id<UICollectionViewDropItem>> *items;

/* The last hit-tested index path known during the drop session.
 * If this is nil, the proposal's intent will be .unspecified
 */
@property (nonatomic, readonly, nullable) NSIndexPath *destinationIndexPath;

/* The current drop proposal at the time of the drop.
 */
@property (nonatomic, readonly) UICollectionViewDropProposal *proposal;


@property (nonatomic, readonly) id<UIDropSession> session;

/* Animate the dragItem to an automatically inserted placeholder item.
 *
 * A placeholder cell will be created for the reuse identifier and inserted at the specified indexPath without requiring a dataSource update.
 *
 * The cellUpdateHandler will be called whenever the placeholder cell becomes visible; -collectionView:cellForItemAtIndexPath: will not be called
 * for the placeholder.
 *
 * Once the dragItem data is available, you can exchange the temporary placeholder cell with the final cell using
 * the placeholder context method -commitInsertionWithDataSourceUpdates:
 *
 * UICollectionViewDropPlaceholderContext also conforms to UIDragAnimating to allow adding alongside animations and completion handlers.
 */
- (id<UICollectionViewDropPlaceholderContext>)dropItem:(UIDragItem *)dragItem toPlaceholder:(UICollectionViewDropPlaceholder*)placeholder;

/* Animate the dragItem to a newly inserted item at the specified index path.
 * You must call -performBatchUpdates:completion: to update your data source and insert a new item into the collection view prior to calling this method.
 *
 * To tweak the appearance of the preview being dropping (e.g. supply a clipping path), see -collectionView:dropPreviewParametersForItemAtIndexPath:
 */
- (id<UIDragAnimating>)dropItem:(UIDragItem *)dragItem toItemAtIndexPath:(NSIndexPath *)indexPath;

/* Animate the dragItem to a rect inside an existing item.
 * The rect is in the coordinate space of the cell at this index path.
 * The item will be animated with an aspect fit scale transform to fit inside the rect. Use a rect with zero size to shrink the item to a single point.
 */
- (id<UIDragAnimating>)dropItem:(UIDragItem *)dragItem intoItemAtIndexPath:(NSIndexPath *)indexPath rect:(CGRect)rect;

/* Animate the dragItem to a location specified by the UIDragPreviewTarget.
 */
- (id<UIDragAnimating>)dropItem:(UIDragItem *)dragItem toTarget:(UIDragPreviewTarget *)target;

@end

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos,watchos)
@interface UICollectionViewPlaceholder : NSObject

- (instancetype)initWithInsertionIndexPath:(NSIndexPath*)insertionIndexPath reuseIdentifier:(NSString *)reuseIdentifier NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/* Called whenever the placeholder cell is visible to update the contents of the cell.
 */
@property (nonatomic, nullable, copy) void(^cellUpdateHandler)(__kindof UICollectionViewCell *);

@end

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos,watchos)
@interface UICollectionViewDropPlaceholder : UICollectionViewPlaceholder

/* If specified, will be used to modify the appearance (e.g. visiblePath to supply a "cut out" region of the placeholder cell) of the animating dropped item.
 * Handler will be called as-needed.
 */
@property (nonatomic, nullable, copy) UIDragPreviewParameters * _Nullable (^previewParametersProvider)(__kindof UICollectionViewCell *);
@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UICollectionViewDropItem <NSObject>

@property (nonatomic, readonly) UIDragItem *dragItem;

/* If this drop item is also from this collection view this indexPath will specify the location of the item.
 * If the dragItem comes from some other source (e.g. another source inside or outside of the app), it will be nil.
 * This is useful for directly accessing the model objects in the data source instead of using the item provider
 * to retrieve the data.
 */
@property (nonatomic, readonly, nullable) NSIndexPath *sourceIndexPath;

/* May be useful for computing the UIDragPreviewTarget transform for UICollectionViewDropCoordinator dropItem:toTarget:
 * Returns CGSizeZero if the dragItem does not have a visible drop preview.
 */
@property (nonatomic, readonly) CGSize previewSize;

@end


API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UICollectionViewDropPlaceholderContext <UIDragAnimating>

/* Retrieve drop data from the dragItem's itemProvider.
 */
@property (nonatomic, readonly) UIDragItem *dragItem;


/* Exchange the placeholder for the final cell.
 * You are only responsible for updating your data source inside the block using the provided insertionIndexPath.
 * If the placeholder is no longer available (e.g. -reloadData has been called) the dataSourceUpdates block
 * will not be executed and this will return NO.
 */
- (BOOL)commitInsertionWithDataSourceUpdates:(void(NS_NOESCAPE ^)(NSIndexPath *insertionIndexPath))dataSourceUpdates;

/* If the placeholder is no longer needed or you wish to manually insert a cell for the drop data, you can
 * remove the placeholder via this method.
 * If the placeholder is no longer available (e.g. -reloadData has been called) this will return NO.
 */
- (BOOL)deletePlaceholder;

/* Call this method to request an update of the placeholder cell's content via the updateCellHandler.
 * This will only be called if the placeholder is visible. If the placeholder becomes visible via scrolling,
 * the updateCellHandler will automatically be called.
 */
- (void)setNeedsCellUpdate;

@end



NS_ASSUME_NONNULL_END

