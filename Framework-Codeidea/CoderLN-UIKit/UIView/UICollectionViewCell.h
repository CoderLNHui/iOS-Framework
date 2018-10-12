/*
 * UICollectionViewCell.h 
 *
 * UIKit (c) 2011-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */


#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UICollectionView.h>

NS_ASSUME_NONNULL_BEGIN

@class UICollectionViewLayout;
@class UICollectionView;
@class UICollectionViewLayoutAttributes;
@class UILongPressGestureRecognizer;

typedef NS_ENUM(NSInteger, UICollectionViewCellDragState) {
    UICollectionViewCellDragStateNone,
    /* The cell is in the "lifting" state.
     */
    UICollectionViewCellDragStateLifting,
    
    /* A cell in the "dragging" state is left behind with a
     * "ghosted" appearance to denote where the drag
     * started from.
     */
    UICollectionViewCellDragStateDragging
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

#pragma mark - 复用视图
NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionReusableView : UIView

#pragma mark -标识
@property (nonatomic, readonly, copy, nullable) NSString *reuseIdentifier;//

// Override point.
// Called by the collection view before the instance is returned from the reuse queue.
// Subclassers must call super.
#pragma mark -准备复用（当cell被复用会调用）
/**
 注解:
     重写cell的prepareForReuse官方头文件中有说明.当前已经被分配的cell如果被重用了(通常是滚动出屏幕外了),会调用cell的prepareForReuse通知cell.
     注意这里重写方法的时候,注意一定要调用父类方法[super prepareForReuse] .
     这个在使用cell作为网络访问的代理容器时尤其要注意,需要在这里通知取消掉前一次网络请求.不要再给这个cell发数据了.
 */
- (void)prepareForReuse;



// Classes that want to support custom layout attributes specific to a given UICollectionViewLayout subclass can apply them here.
// This allows the view to work in conjunction with a layout class that returns a custom subclass of UICollectionViewLayoutAttributes from -layoutAttributesForItem: or the corresponding layoutAttributesForHeader/Footer methods.
// -applyLayoutAttributes: is then called after the view is added to the collection view and just before the view is returned from the reuse queue.
// Note that -applyLayoutAttributes: is only called when attributes change, as defined by -isEqual:.
- (void)applyLayoutAttributes:(UICollectionViewLayoutAttributes *)layoutAttributes;

// Override these methods to provide custom UI for specific layouts.
- (void)willTransitionFromLayout:(UICollectionViewLayout *)oldLayout toLayout:(UICollectionViewLayout *)newLayout;
- (void)didTransitionFromLayout:(UICollectionViewLayout *)oldLayout toLayout:(UICollectionViewLayout *)newLayout;

- (UICollectionViewLayoutAttributes *)preferredLayoutAttributesFittingAttributes:(UICollectionViewLayoutAttributes *)layoutAttributes NS_AVAILABLE_IOS(8_0);

@end




#pragma mark - cell视图内容（继承复用视图ReusableView）
NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionViewCell : UICollectionReusableView

#pragma mark -内容视图
/**
 注解:
     Cell需要自定义 且 必须通过注册,原因: 系统cell没有任何子控件;
     子控件imageView,label 添加到contentView上
 */
@property (nonatomic, readonly) UIView *contentView; // add custom subviews to the cell's contentView

// Cells become highlighted when the user touches them.
// The selected state is toggled when the user lifts up from a highlighted cell.
// Override these methods to provide custom UI for a selected or highlighted state.
// The collection view may call the setters inside an animation block.
#pragma mark -选择
@property (nonatomic, getter=isSelected) BOOL selected;//
#pragma mark -高亮
@property (nonatomic, getter=isHighlighted) BOOL highlighted;//

// Override this method to modify the visual appearance for a particular
// dragState.
//
// Call super if you want to add to the existing default implementation.
//
- (void)dragStateDidChange:(UICollectionViewCellDragState)dragState API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos);

// The background view is a subview behind all other views.
// If selectedBackgroundView is different than backgroundView, it will be placed above the background view and animated in on selection.
#pragma mark -背景视图
@property (nonatomic, strong, nullable) UIView *backgroundView;//
#pragma mark -选中背景视图
@property (nonatomic, strong, nullable) UIView *selectedBackgroundView;//

@end











