//  UIScrollView 完全实现ok （重点）
//  UIScrollView.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
#import "UIGeometry.h"

typedef NS_ENUM(NSInteger, UIScrollViewIndicatorStyle) {
    UIScrollViewIndicatorStyleDefault,
    UIScrollViewIndicatorStyleBlack,
    UIScrollViewIndicatorStyleWhite
};

extern const float UIScrollViewDecelerationRateNormal;
extern const float UIScrollViewDecelerationRateFast;

@class UIScrollView, UIPanGestureRecognizer;

@protocol UIScrollViewDelegate <NSObject>
@optional
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;
- (void)scrollViewDidScroll:(UIScrollView *)scrollView;
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
- (void)scrollViewWillBeginDecelerating:(UIScrollView *)scrollView;
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView;
- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView;
- (void)scrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(UIView *)view;
- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(UIView *)view atScale:(float)scale;
- (void)scrollViewDidZoom:(UIScrollView *)scrollView;
- (BOOL)scrollViewShouldScrollToTop:(UIScrollView *)scrollView;
@end


@interface UIScrollView : UIView

- (void)scrollRectToVisible:(CGRect)rect animated:(BOOL)animated;
- (void)setZoomScale:(float)scale animated:(BOOL)animated;
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated;
- (void)setContentOffset:(CGPoint)theOffset animated:(BOOL)animated;
- (void)flashScrollIndicators;

@property (nonatomic) CGSize contentSize;
@property (nonatomic) CGPoint contentOffset;
@property (nonatomic) UIEdgeInsets contentInset;
@property (nonatomic) UIEdgeInsets scrollIndicatorInsets;
@property (nonatomic) UIScrollViewIndicatorStyle indicatorStyle;
@property (nonatomic) BOOL showsHorizontalScrollIndicator;
@property (nonatomic) BOOL showsVerticalScrollIndicator;
@property (nonatomic) BOOL bounces;
@property (nonatomic) BOOL alwaysBounceVertical;
@property (nonatomic) BOOL alwaysBounceHorizontal;
@property (nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;
@property (nonatomic, assign) id<UIScrollViewDelegate> delegate;
@property (nonatomic) BOOL scrollsToTop;
@property (nonatomic) BOOL delaysContentTouches;
@property (nonatomic) BOOL canCancelContentTouches;
@property (nonatomic, getter=isDirectionalLockEnabled) BOOL directionalLockEnabled;
@property (nonatomic, readonly, getter=isDragging) BOOL dragging;
@property (nonatomic, readonly, getter=isTracking) BOOL tracking;
@property (nonatomic, readonly, getter=isDecelerating) BOOL decelerating;
@property (nonatomic, assign) BOOL pagingEnabled;
@property (nonatomic) float decelerationRate;
@property (nonatomic) float maximumZoomScale;
@property (nonatomic) float minimumZoomScale;
@property (nonatomic) float zoomScale;
@property (nonatomic, readonly, getter=isZooming) BOOL zooming;
@property (nonatomic, readonly, getter=isZoomBouncing) BOOL zoomBouncing;
@property (nonatomic) BOOL bouncesZoom;
@property (nonatomic, readonly) UIPanGestureRecognizer *panGestureRecognizer;

@end
