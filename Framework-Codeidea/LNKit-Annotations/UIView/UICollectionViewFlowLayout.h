/*
 * File:  UICollectionViewFlowLayout.h 
 *
 * Framework: UIKit (c) 2011-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <UIKit/UICollectionViewLayout.h>
#import <UIKit/UICollectionView.h>
#import <UIKit/UIKitDefines.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString *const UICollectionElementKindSectionHeader NS_AVAILABLE_IOS(6_0);
UIKIT_EXTERN NSString *const UICollectionElementKindSectionFooter NS_AVAILABLE_IOS(6_0);
UIKIT_EXTERN const CGSize UICollectionViewFlowLayoutAutomaticSize  NS_AVAILABLE_IOS(10_0);

typedef NS_ENUM(NSInteger, UICollectionViewScrollDirection) {
    UICollectionViewScrollDirectionVertical, // 默认是竖直滚动
    UICollectionViewScrollDirectionHorizontal // 水平滚动
};// 设置滚动方向，




NS_CLASS_AVAILABLE_IOS(7_0) @interface UICollectionViewFlowLayoutInvalidationContext : UICollectionViewLayoutInvalidationContext

@property (nonatomic) BOOL invalidateFlowLayoutDelegateMetrics; // if set to NO, flow layout will not requery the collection view delegate for size information etc.
@property (nonatomic) BOOL invalidateFlowLayoutAttributes; // if set to NO, flow layout will keep all layout information, effectively not invalidating - useful for a subclass which invalidates only a piece of itself

@end






#pragma mark - ↑
#pragma mark - UICollectionView DelegateFlowLayout(与属性对应的代理方法)

@protocol UICollectionViewDelegateFlowLayout <UICollectionViewDelegate>
@optional

/**
 作用:设置指定indexPath的单元格的大小(itemSize)
 */
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath;

/**
 作用:设置分组中的每一个单元格的上下左右的空白距离(内边距)
 */
- (UIEdgeInsets)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout insetForSectionAtIndex:(NSInteger)section;

/**
 作用:设置分组中的单元格的Line行间距(横向)
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section;

/**
 作用:设置每行中的item的(列)间距(竖向)
 */
- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section;

/**
 作用:分组的头部视图的size大小，含义也是有滚动方向决定的
 */
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout referenceSizeForHeaderInSection:(NSInteger)section;

/**
 作用:分组的尾部视图的size大小，含义也是有滚动方向决定的
 */
- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout referenceSizeForFooterInSection:(NSInteger)section;

@end




#pragma mark - ↑
#pragma mark - UICollectionViewFlowLayout 流水布局(与代理方法对应的属性)

NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionViewFlowLayout : UICollectionViewLayout

@property (nonatomic) CGFloat minimumLineSpacing; // 设置行之间的最小间距(竖直)
@property (nonatomic) CGFloat minimumInteritemSpacing; // 设置2个item之间(列)的最小间隙(水平)，
@property (nonatomic) CGSize itemSize; // 设置item的大小

/**
 作用:预设item大小
 */
@property (nonatomic) CGSize estimatedItemSize NS_AVAILABLE_IOS(8_0); // defaults to CGSizeZero - setting a non-zero size enables cells that self-size via -preferredLayoutAttributesFittingAttributes:

/**
 作用:设置滚动方向，默认是竖直滚动 V
 */
@property (nonatomic) UICollectionViewScrollDirection scrollDirection; // default is UICollectionViewScrollDirectionVertical



/**
 注解:1.如果是垂直滚动，高度起作用，宽度忽略 / 2.如果是水平滚动，宽度期作用，高度忽略
 */
@property (nonatomic) CGSize headerReferenceSize; // 分组的头部视图的size大小
@property (nonatomic) CGSize footerReferenceSize; // 分组的尾部视图的size大小
@property (nonatomic) UIEdgeInsets sectionInset; // 设置区的内边距



// Set these properties to YES to get headers that pin to the top of the screen and footers that pin to the bottom while scrolling (similar to UITableView).
/**
 作用:头部视图悬停设为YES
 */
@property (nonatomic) BOOL sectionHeadersPinToVisibleBounds NS_AVAILABLE_IOS(9_0);
/**
 作用:尾部视图悬停设为YES
 */
@property (nonatomic) BOOL sectionFootersPinToVisibleBounds NS_AVAILABLE_IOS(9_0);

@end


























