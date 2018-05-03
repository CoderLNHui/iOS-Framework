/*
 * File:  UICollectionViewCell.h 
 *
 * Framework: UIKit  (c) 2011-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UICollectionView.h>

NS_ASSUME_NONNULL_BEGIN

@class UICollectionViewLayout;
@class UICollectionView;
@class UICollectionViewLayoutAttributes;
@class UILongPressGestureRecognizer;


#pragma mark - ↑
#pragma mark - UICollectionReusableView 补充视图
NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionReusableView : UIView

@property (nonatomic, readonly, copy, nullable) NSString *reuseIdentifier;// 标识

// Override point.
// Called by the collection view before the instance is returned from the reuse queue.
// Subclassers must call super.
/**
 作用:重用 ❓
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






#pragma mark - ↑
#pragma mark - UICollectionViewCell 视图内容

NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionViewCell : UICollectionReusableView

/**
 作用:内容视图
 注解:
     Cell需要自定义 且 必须通过注册,原因: 系统cell没有任何子控件;
     子控件imageView,label 添加到contentView上
 */
@property (nonatomic, readonly) UIView *contentView; // add custom subviews to the cell's contentView

// Cells become highlighted when the user touches them.
// The selected state is toggled when the user lifts up from a highlighted cell.
// Override these methods to provide custom UI for a selected or highlighted state.
// The collection view may call the setters inside an animation block.
@property (nonatomic, getter=isSelected) BOOL selected;// 选择
@property (nonatomic, getter=isHighlighted) BOOL highlighted;// 高亮

// The background view is a subview behind all other views.
// If selectedBackgroundView is different than backgroundView, it will be placed above the background view and animated in on selection.
@property (nonatomic, strong, nullable) UIView *backgroundView;// 背景视图
@property (nonatomic, strong, nullable) UIView *selectedBackgroundView;// 选中背景视图

@end











