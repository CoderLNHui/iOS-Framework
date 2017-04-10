//
//  UIScrollView.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIScrollView.h"
#import "UIScroller.h"
#import "UIScrollViewAnimation.h"
#import "UIPanGestureRecognizer.h"
#import "UIScrollViewAnimationScroll.h"
#import "UIScrollViewAnimationDeceleration.h"
#import <QuartzCore/QuartzCore.h>
#import "UITouch.h"

/*
 UIScrollView的实现原理(竖直和水平滚动条的实现主要由UIScroller类实现，暂时不讲，等专门讲UIScroller时候再说)
 
 一.首先在初始化方法中添加一个pan手势，然后监听手势方法，根据手势的开始，移到和介绍分别调用不同的方法
   1.开始手势的方法很简单，就不说了，主要说手势改变的方法
   2.手势改变的方法_dragBy，由originalOffset加上偏移量，得到真正的proposedOffset，后来这个方法根据bounces的值不同，分为2种情况。。先说说最常见的情况，调用setContentOffset，其实setContentOffset调用的真正方法是_setScrollAnimation，_setScrollAnimation其实就是开了个定时器，每秒调用60次的[_scrollAnimation animate]方法。
      这里特别要说明下大概470行左右的代码， _scrollAnimation = animation;
    // 赋值后的_scrollAnimation的真实类型肯定是UIScrollViewAnimationScroll或UIScrollViewAnimationDeceleration之一
        _scrollAnimation = animation;
       [UIScrollViewAnimationScroll animate]和[UIScrollViewAnimationDeceleration animate]方法去UIScrollViewAnimationScroll和UIScrollViewAnimationDeceleration的animate方法实现
 
    3.手势结束时候，调用_endDraggingWithDecelerationVelocity方法，这里pagingEnabled要注意下，2种动画方法的实现
    // pagingEnabled默认是NO，根据pagingEnabled的值选择不同的减速动画方式
    UIScrollViewAnimation *decelerationAnimation = _pagingEnabled? [self _pageSnapAnimation] : [self _decelerationAnimationWithVelocity:velocity];
 
 */
// 文字能说明的东西有限，细节的情况还请多看这个类的源码，就在下面
//  UIScrollView实现： http://www.jianshu.com/p/1e920aee7429

static const NSTimeInterval UIScrollViewAnimationDuration = 0.33;
static const NSTimeInterval UIScrollViewQuickAnimationDuration = 0.22;
static const NSUInteger UIScrollViewScrollAnimationFramesPerSecond = 60;

const float UIScrollViewDecelerationRateNormal = 0.998;
const float UIScrollViewDecelerationRateFast = 0.99;


@interface UIScrollView ()
@end
@implementation UIScrollView 
{
    UIScroller *_verticalScroller;
    UIScroller *_horizontalScroller;
    
    UIScrollViewAnimation *_scrollAnimation;
    NSTimer *_scrollTimer;
    
    struct {
        unsigned scrollViewDidScroll : 1;
        unsigned scrollViewWillBeginDragging : 1;
        unsigned scrollViewDidEndDragging : 1;
        unsigned viewForZoomingInScrollView : 1;
        unsigned scrollViewWillBeginZooming : 1;
        unsigned scrollViewDidEndZooming : 1;
        unsigned scrollViewDidZoom : 1;
        unsigned scrollViewDidEndScrollingAnimation : 1;
        unsigned scrollViewWillBeginDecelerating : 1;
        unsigned scrollViewDidEndDecelerating : 1;
    } _delegateCan;
}

- (id)initWithFrame:(CGRect)frame
{
    if ((self=[super initWithFrame:frame])) {
        // 为属性赋默认值
        _contentOffset = CGPointZero;
        _contentSize = CGSizeZero;
        _contentInset = UIEdgeInsetsZero;
        _scrollIndicatorInsets = UIEdgeInsetsZero;
        _showsVerticalScrollIndicator = YES;
        _showsHorizontalScrollIndicator = YES;
        _maximumZoomScale = 1;
        _minimumZoomScale = 1;
        _scrollsToTop = YES;
        _indicatorStyle = UIScrollViewIndicatorStyleDefault;
        _delaysContentTouches = YES;
        _canCancelContentTouches = YES;
        _pagingEnabled = NO;
        _bouncesZoom = NO;
        _zooming = NO;
        _alwaysBounceVertical = NO;
        _alwaysBounceHorizontal = NO;
        _bounces = YES;
        _decelerationRate = UIScrollViewDecelerationRateNormal;
        
        // 添加pan手势
        _panGestureRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(_gestureDidChange:)];
        [self addGestureRecognizer:_panGestureRecognizer];
        
        // 初始化竖直和水平滚动条
        _verticalScroller = [[UIScroller alloc] init];
        [self addSubview:_verticalScroller];
        
        _horizontalScroller = [[UIScroller alloc] init];
        [self addSubview:_horizontalScroller];
        
        self.clipsToBounds = YES;
    }
    return self;
}

#pragma mark - pagingEnabled为yes时的动画
- (UIScrollViewAnimation *)_pageSnapAnimation
{
    const CGSize pageSize = self.bounds.size;
    // floorf向下取整函数
    const CGSize numberOfWholePages = CGSizeMake(floorf(_contentSize.width/pageSize.width), floorf(_contentSize.height/pageSize.height));
    const CGSize currentRawPage = CGSizeMake(_contentOffset.x/pageSize.width, _contentOffset.y/pageSize.height);
    const CGSize currentPage = CGSizeMake(floorf(currentRawPage.width), floorf(currentRawPage.height));
    const CGSize currentPagePercentage = CGSizeMake(1-(currentRawPage.width-currentPage.width), 1-(currentRawPage.height-currentPage.height));
    
    CGPoint finalContentOffset = CGPointZero;
    
    // 翻页时能回去的代码
    // 翻页少于50%回去，翻页多余50%时去下一页
    if (currentPagePercentage.width < 0.5 && (currentPage.width+1) < numberOfWholePages.width) {
        finalContentOffset.x = pageSize.width * (currentPage.width + 1);
    } else {
        finalContentOffset.x = pageSize.width * currentPage.width;
    }
    
    if (currentPagePercentage.height < 0.5 && (currentPage.height+1) < numberOfWholePages.height) {
        finalContentOffset.y = pageSize.height * (currentPage.height + 1);
    } else {
        finalContentOffset.y = pageSize.height * currentPage.height;
    }
    
    if (!CGPointEqualToPoint(finalContentOffset, _contentOffset)) {
        return [[UIScrollViewAnimationScroll alloc] initWithScrollView:self
                                                     fromContentOffset:_contentOffset
                                                       toContentOffset:finalContentOffset
                                                              duration:UIScrollViewQuickAnimationDuration
                                                                 curve:UIScrollViewAnimationScrollCurveQuadraticEaseOut];
    } else {
        return nil;
    }
}

#pragma mark - 正常的带速度的减速动画
- (UIScrollViewAnimation *)_decelerationAnimationWithVelocity:(CGPoint)velocity
{
    const CGPoint confinedOffset = [self _confinedContentOffset:_contentOffset];
    
    // 如果我们拖拽超出了它的边界，就让它回到边界，并且带动画
    if (confinedOffset.x != _contentOffset.x) {
        velocity.x = 0;
    }
    if (confinedOffset.y != _contentOffset.y) {
        velocity.y = 0;
    }
    
    if (!CGPointEqualToPoint(velocity, CGPointZero) || !CGPointEqualToPoint(confinedOffset, _contentOffset)) {
        return [[UIScrollViewAnimationDeceleration alloc] initWithScrollView:self
                                                                    velocity:velocity];
    } else {
        return nil;
    }
}

#pragma mark - 开始拖拽的时候
- (void)_beginDragging
{
    if (!_dragging) {
        // dragging标志位置为yes，显示
        _dragging = YES;
        _horizontalScroller.alwaysVisible = YES;
        _verticalScroller.alwaysVisible = YES;
        
        [self _cancelScrollAnimation];
        
        if (_delegateCan.scrollViewWillBeginDragging) {
            [_delegate scrollViewWillBeginDragging:self];
        }
    }
}

#pragma mark - 带减速的结束拖拽方法
- (void)_endDraggingWithDecelerationVelocity:(CGPoint)velocity
{
    if (_dragging) {
        _dragging = NO;
        
        // pagingEnabled默认是NO，根据pagingEnabled的值选择不同的减速动画方式
        UIScrollViewAnimation *decelerationAnimation = _pagingEnabled? [self _pageSnapAnimation] : [self _decelerationAnimationWithVelocity:velocity];
        
        if (_delegateCan.scrollViewDidEndDragging) {
            [_delegate scrollViewDidEndDragging:self willDecelerate:(decelerationAnimation != nil)];
        }
    
        if (decelerationAnimation) {
            [self _setScrollAnimation:decelerationAnimation];
            
            _horizontalScroller.alwaysVisible = YES;
            _verticalScroller.alwaysVisible = YES;
            _decelerating = YES;
            
            if (_delegateCan.scrollViewWillBeginDecelerating) {
                [_delegate scrollViewWillBeginDecelerating:self];
            }
        } else {
            _horizontalScroller.alwaysVisible = NO;
            _verticalScroller.alwaysVisible = NO;
            [self _confineContent];
        }
    }
}


// 正在拖拽的方法
- (void)_dragBy:(CGPoint)delta
{
    if (_dragging) {
        _horizontalScroller.alwaysVisible = YES;
        _verticalScroller.alwaysVisible = YES;
        
        const CGPoint originalOffset = self.contentOffset;
        
        CGPoint proposedOffset = originalOffset;
        proposedOffset.x += delta.x;
        proposedOffset.y += delta.y;
        
        const CGPoint confinedOffset = [self _confinedContentOffset:proposedOffset];
        
        if (self.bounces) {
            BOOL shouldHorizontalBounce = (fabs(proposedOffset.x - confinedOffset.x) > 0);
            BOOL shouldVerticalBounce = (fabs(proposedOffset.y - confinedOffset.y) > 0);
            
            if (shouldHorizontalBounce) {
                proposedOffset.x = originalOffset.x + (0.055 * delta.x);
            }
            
            if (shouldVerticalBounce) {
                proposedOffset.y = originalOffset.y + (0.055 * delta.y);
            }
            
            [self _setRestrainedContentOffset:proposedOffset];
        } else {
            [self setContentOffset:confinedOffset];
        }
    }
}

// pan手势的方法
- (void)_gestureDidChange:(UIGestureRecognizer *)gesture
{
    if (gesture == _panGestureRecognizer) {
        if (_panGestureRecognizer.state == UIGestureRecognizerStateBegan) {
            [self _beginDragging];
        } else if (_panGestureRecognizer.state == UIGestureRecognizerStateChanged) {
            [self _dragBy:[_panGestureRecognizer translationInView:self]];
            [_panGestureRecognizer setTranslation:CGPointZero inView:self];
        } else if (_panGestureRecognizer.state == UIGestureRecognizerStateEnded) {
            [self _endDraggingWithDecelerationVelocity:[_panGestureRecognizer velocityInView:self]];
        }
    }
}
/*
 scrollRectToVisible:animated:与setContentOffset:animated:类似，只不过是将scrollView坐标系内的一块指定区域移到scrollView的窗口中，如果这部分已经存在于窗口中，则什么也不做。
 */
- (void)scrollRectToVisible:(CGRect)rect animated:(BOOL)animated
{
    const CGRect contentRect = CGRectMake(0,0,_contentSize.width, _contentSize.height);
    const CGRect visibleRect = self.bounds;
    // 取交集的函数CGRectIntersection
    CGRect goalRect = CGRectIntersection(rect, contentRect);
    
    if (!CGRectIsNull(goalRect) && !CGRectContainsRect(visibleRect, goalRect)) {
        
        goalRect.size.width = MIN(goalRect.size.width, visibleRect.size.width);
        goalRect.size.height = MIN(goalRect.size.height, visibleRect.size.height);
        
        CGPoint offset = self.contentOffset;
        
        if (CGRectGetMaxY(goalRect) > CGRectGetMaxY(visibleRect)) {
            offset.y += CGRectGetMaxY(goalRect) - CGRectGetMaxY(visibleRect);
        } else if (CGRectGetMinY(goalRect) < CGRectGetMinY(visibleRect)) {
            offset.y += CGRectGetMinY(goalRect) - CGRectGetMinY(visibleRect);
        }
        
        if (CGRectGetMaxX(goalRect) > CGRectGetMaxX(visibleRect)) {
            offset.x += CGRectGetMaxX(goalRect) - CGRectGetMaxX(visibleRect);
        } else if (CGRectGetMinX(goalRect) < CGRectGetMinX(visibleRect)) {
            offset.x += CGRectGetMinX(goalRect) - CGRectGetMinX(visibleRect);
        }
        
        [self setContentOffset:offset animated:animated];
    }
}

// zoom缩放的方法
- (BOOL)isZoomBouncing
{
    return NO;
}

- (float)zoomScale
{
    UIView *zoomingView = [self _zoomingView];
    
    return zoomingView? zoomingView.transform.a : 1.f;
}

- (void)setZoomScale:(float)scale animated:(BOOL)animated
{
    UIView *zoomingView = [self _zoomingView];
    scale = MIN(MAX(scale, _minimumZoomScale), _maximumZoomScale);
    
    if (zoomingView && self.zoomScale != scale) {
        [UIView animateWithDuration:animated? UIScrollViewAnimationDuration : 0
                              delay:0
                            options:UIViewAnimationOptionCurveEaseOut | UIViewAnimationOptionBeginFromCurrentState
                         animations:^(void) {
                             zoomingView.transform = CGAffineTransformMakeScale(scale, scale);
                             const CGSize size = zoomingView.frame.size;
                             zoomingView.layer.position = CGPointMake(size.width/2.f, size.height/2.f);
                             self.contentSize = size;
                         }
                         completion:NULL];
    }
}

- (void)setZoomScale:(float)scale
{
    [self setZoomScale:scale animated:NO];
}

- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated
{
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@: %p; frame = (%.0f %.0f; %.0f %.0f); clipsToBounds = %@; layer = %@; contentOffset = {%.0f, %.0f}>", [self className], self, self.frame.origin.x, self.frame.origin.y, self.frame.size.width, self.frame.size.height, (self.clipsToBounds ? @"YES" : @"NO"), self.layer, self.contentOffset.x, self.contentOffset.y];
}

#pragma mark - 取消滚动动画
- (void)_cancelScrollAnimation
{
    [_scrollTimer invalidate];
    _scrollTimer = nil;
    
    _scrollAnimation = nil;
    
    if (_delegateCan.scrollViewDidEndScrollingAnimation) {
        [_delegate scrollViewDidEndScrollingAnimation:self];
    }
    
    if (_decelerating) {
        _horizontalScroller.alwaysVisible = NO;
        _verticalScroller.alwaysVisible = NO;
        _decelerating = NO;
        
        if (_delegateCan.scrollViewDidEndDecelerating) {
            [_delegate scrollViewDidEndDecelerating:self];
        }
    }
}


#pragma mark - 设置代理
- (void)setDelegate:(id)newDelegate
{
    _delegate = newDelegate;
    _delegateCan.scrollViewDidScroll = [_delegate respondsToSelector:@selector(scrollViewDidScroll:)];
    _delegateCan.scrollViewWillBeginDragging = [_delegate respondsToSelector:@selector(scrollViewWillBeginDragging:)];
    _delegateCan.scrollViewDidEndDragging = [_delegate respondsToSelector:@selector(scrollViewDidEndDragging:willDecelerate:)];
    _delegateCan.viewForZoomingInScrollView = [_delegate respondsToSelector:@selector(viewForZoomingInScrollView:)];
    _delegateCan.scrollViewWillBeginZooming = [_delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)];
    _delegateCan.scrollViewDidEndZooming = [_delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)];
    _delegateCan.scrollViewDidZoom = [_delegate respondsToSelector:@selector(scrollViewDidZoom:)];
    _delegateCan.scrollViewDidEndScrollingAnimation = [_delegate respondsToSelector:@selector(scrollViewDidEndScrollingAnimation:)];
    _delegateCan.scrollViewWillBeginDecelerating = [_delegate respondsToSelector:@selector(scrollViewWillBeginDecelerating:)];
    _delegateCan.scrollViewDidEndDecelerating = [_delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)];
}

- (UIView *)_zoomingView
{
    return (_delegateCan.viewForZoomingInScrollView)? [_delegate viewForZoomingInScrollView:self] : nil;
}

- (void)setIndicatorStyle:(UIScrollViewIndicatorStyle)style
{
    _indicatorStyle = style;
    _horizontalScroller.indicatorStyle = style;
    _verticalScroller.indicatorStyle = style;
}

- (void)setShowsHorizontalScrollIndicator:(BOOL)show
{
    _showsHorizontalScrollIndicator = show;
    [self setNeedsLayout];
}

- (void)setShowsVerticalScrollIndicator:(BOOL)show
{
    _showsVerticalScrollIndicator = show;
    [self setNeedsLayout];
}

- (BOOL)_canScrollHorizontal
{
    // scrollEnabled且_contentSize.width大于本事的宽度
    return self.scrollEnabled && (_contentSize.width > self.bounds.size.width);
}

- (BOOL)_canScrollVertical
{
    return self.scrollEnabled && (_contentSize.height > self.bounds.size.height);
}

- (void)_updateScrollers
{
    _verticalScroller.contentSize = _contentSize.height;
    _verticalScroller.contentOffset = _contentOffset.y;
    _horizontalScroller.contentSize = _contentSize.width;
    _horizontalScroller.contentOffset = _contentOffset.x;
    
    _verticalScroller.hidden = !self._canScrollVertical;
    _horizontalScroller.hidden = !self._canScrollHorizontal;
}

- (void)setScrollEnabled:(BOOL)enabled
{
    self.panGestureRecognizer.enabled = enabled;
    
    [self _updateScrollers];
    [self setNeedsLayout];
}

- (BOOL)isScrollEnabled
{
    return self.panGestureRecognizer.enabled ;
}
#pragma mark - 真正的减速或滑动动画执行的地方
- (void)_updateScrollAnimation
{
    // _scrollAnimation animate是滑动动画或减速动画之一
    if ([_scrollAnimation animate]) {
        [self _cancelScrollAnimation];
    }
}

// setContentOffset调用的真正方法是_setScrollAnimation
- (void)_setScrollAnimation:(UIScrollViewAnimation *)animation
{
    [self _cancelScrollAnimation];
    // 赋值后的_scrollAnimation的真实类型肯定是UIScrollViewAnimationScroll或UIScrollViewAnimationDeceleration之一
    _scrollAnimation = animation;
    
    if (!_scrollTimer) {
        // UIScrollViewScrollAnimationFramesPerSecond = 60, 也就是一秒钟调60次
        _scrollTimer = [NSTimer scheduledTimerWithTimeInterval:1/(NSTimeInterval)UIScrollViewScrollAnimationFramesPerSecond target:self selector:@selector(_updateScrollAnimation) userInfo:nil repeats:YES];
    }
}

// 这个方法的目的是返回设置了_contentInset的真正修正后的contentOffset
- (CGPoint)_confinedContentOffset:(CGPoint)contentOffset
{
    const CGRect scrollerBounds = UIEdgeInsetsInsetRect(self.bounds, _contentInset);
    
    if ((_contentSize.width-contentOffset.x) < scrollerBounds.size.width) {
        contentOffset.x = (_contentSize.width - scrollerBounds.size.width);
    }
    
    if ((_contentSize.height-contentOffset.y) < scrollerBounds.size.height) {
        contentOffset.y = (_contentSize.height - scrollerBounds.size.height);
    }
    
    contentOffset.x = MAX(contentOffset.x,0);
    contentOffset.y = MAX(contentOffset.y,0);
    
    if (_contentSize.width <= scrollerBounds.size.width) {
        contentOffset.x = 0;
    }
    
    if (_contentSize.height <= scrollerBounds.size.height) {
        contentOffset.y = 0;
    }
    
    return contentOffset;
}

// 给self.contentOffset赋值
- (void)_setRestrainedContentOffset:(CGPoint)offset
{
    const CGPoint confinedOffset = [self _confinedContentOffset:offset];
    const CGRect scrollerBounds = UIEdgeInsetsInsetRect(self.bounds, _contentInset);
    
    if (!self.alwaysBounceHorizontal && _contentSize.width <= scrollerBounds.size.width) {
        offset.x = confinedOffset.x;
    }
    
    if (!self.alwaysBounceVertical && _contentSize.height <= scrollerBounds.size.height) {
        offset.y = confinedOffset.y;
    }
    
    self.contentOffset = offset;
}
- (void)_confineContent
{
    self.contentOffset = [self _confinedContentOffset:_contentOffset];
}
- (void)layoutSubviews
{
    [super layoutSubviews];
    
    const CGRect bounds = self.bounds;
    const CGFloat scrollerSize = UIScrollerWidthForBoundsSize(bounds.size);
    
    // 设置水平和竖直滚动条的frame
    _verticalScroller.frame = CGRectMake(bounds.origin.x+bounds.size.width-scrollerSize-_scrollIndicatorInsets.right,bounds.origin.y+_scrollIndicatorInsets.top,scrollerSize,bounds.size.height-_scrollIndicatorInsets.top-_scrollIndicatorInsets.bottom);
    _horizontalScroller.frame = CGRectMake(bounds.origin.x+_scrollIndicatorInsets.left,bounds.origin.y+bounds.size.height-scrollerSize-_scrollIndicatorInsets.bottom,bounds.size.width-_scrollIndicatorInsets.left-_scrollIndicatorInsets.right,scrollerSize);
}

- (void)setFrame:(CGRect)frame
{
    [super setFrame:frame];
    [self _confineContent];
}

- (void)_bringScrollersToFront
{
    // 把水平和竖直滚动条置于最上面
    [super bringSubviewToFront:_horizontalScroller];
    [super bringSubviewToFront:_verticalScroller];
}

// 重写这3个方法，确保水平和竖直滚动条置在最上面
- (void)addSubview:(UIView *)subview
{
    [super addSubview:subview];
    [self _bringScrollersToFront];
}

- (void)bringSubviewToFront:(UIView *)subview
{
    [super bringSubviewToFront:subview];
    [self _bringScrollersToFront];
}

- (void)insertSubview:(UIView *)subview atIndex:(NSInteger)index
{
    [super insertSubview:subview atIndex:index];
    [self _bringScrollersToFront];
}

- (void)_updateBounds
{
    CGRect bounds = self.bounds;
    bounds.origin.x = _contentOffset.x - _contentInset.left;
    bounds.origin.y = _contentOffset.y - _contentInset.top;
    self.bounds = bounds;
    
    [self _updateScrollers];
    [self setNeedsLayout];
}

#pragma mark - 核心方法
- (void)setContentOffset:(CGPoint)theOffset animated:(BOOL)animated
{
    if (animated) {
        UIScrollViewAnimationScroll *animation = nil;
        
        if ([_scrollAnimation isKindOfClass:[UIScrollViewAnimationScroll class]]) {
            animation = (UIScrollViewAnimationScroll *)_scrollAnimation;
        }
        
        if (!animation || !CGPointEqualToPoint(theOffset, animation.endContentOffset)) {
            [self _setScrollAnimation:[[UIScrollViewAnimationScroll alloc] initWithScrollView:self
                                                                            fromContentOffset:self.contentOffset
                                                                              toContentOffset:theOffset
                                                                                     duration:UIScrollViewAnimationDuration
                                                                                        curve:UIScrollViewAnimationScrollCurveLinear]];
        }
    } else {
        // 四舍五入的函数roundf
        _contentOffset.x = roundf(theOffset.x);
        _contentOffset.y = roundf(theOffset.y);
        
        [self _updateBounds];
        
        if (_delegateCan.scrollViewDidScroll) {
            [_delegate scrollViewDidScroll:self];
        }
    }
}

- (void)setContentOffset:(CGPoint)theOffset
{
    [self setContentOffset:theOffset animated:NO];
}

- (void)setContentInset:(UIEdgeInsets)contentInset
{
    if (!UIEdgeInsetsEqualToEdgeInsets(contentInset, _contentInset)) {
        const CGFloat x = contentInset.left - _contentInset.left;
        const CGFloat y = contentInset.top - _contentInset.top;
        
        _contentInset = contentInset;
        _contentOffset.x -= x;
        _contentOffset.y -= y;
        
        [self _updateBounds];
    }
}

- (void)setContentSize:(CGSize)newSize
{
    if (!CGSizeEqualToSize(newSize, _contentSize)) {
        _contentSize = newSize;
        [self _confineContent];
    }
}

- (void)flashScrollIndicators
{
    [_horizontalScroller flash];
    [_verticalScroller flash];
}

- (void)_quickFlashScrollIndicators
{
    [_horizontalScroller quickFlash];
    [_verticalScroller quickFlash];
}

- (BOOL)isTracking
{
    return NO;
}

@end
