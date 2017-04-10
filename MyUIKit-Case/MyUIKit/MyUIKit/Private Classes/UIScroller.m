//
//  UIScroller.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//  UIScroller是个非常有意思的类，下面说说它的实现原理
/*
   UIScroller的实现原理：
   其实很简单，UIScroller就是一个比较细的UIView，有意思的地方是它会变长或变短，它会根据当前页面跟UIScrollView的contentSize.height的比例来变化长度，
   看懂knobSize和knobRect就懂了
 
 */


#import "UIScroller.h"
#import "UIColor.h"
#import "UIBezierPath.h"
#import "UITouch.h"

static const CGFloat _UIScrollerMinimumAlpha = 0;

CGFloat UIScrollerWidthForBoundsSize(CGSize boundsSize)
{
    const CGFloat minViewSize = 50;
    
    if (boundsSize.width <= minViewSize || boundsSize.height <= minViewSize) {
        return 6;
    } else {
        return 10;
    }
}

@implementation UIScroller
{
    CGFloat _dragOffset;
    BOOL _draggingKnob;
    BOOL _isVertical;
    CGPoint _lastTouchLocation;
    NSTimer *_holdTimer;
    NSTimer *_fadeTimer;
}

- (id)initWithFrame:(CGRect)frame
{
    if ((self = [super initWithFrame:frame])) {
        self.opaque = NO;
        self.alpha = _UIScrollerMinimumAlpha;
        self.indicatorStyle = UIScrollViewIndicatorStyleDefault;
    }
    return self;
}

- (void)setFrame:(CGRect)frame
{
    _isVertical = (frame.size.height > frame.size.width);
    [super setFrame:frame];
}


#pragma mark - 淡出其实就是个UIView动画，改变透明度为0
- (void)_fadeOut
{
    [_fadeTimer invalidate];
    _fadeTimer = nil;
    
    [UIView animateWithDuration:0.33
                          delay:0
                        options:UIViewAnimationOptionCurveEaseOut | UIViewAnimationOptionTransitionNone | UIViewAnimationOptionAllowUserInteraction | UIViewAnimationOptionBeginFromCurrentState
                     animations:^(void) {
                         self.alpha = _UIScrollerMinimumAlpha;
                     }
                     completion:NULL];
}

- (void)_fadeOutAfterDelay:(NSTimeInterval)time
{
    [_fadeTimer invalidate];
    _fadeTimer = [NSTimer scheduledTimerWithTimeInterval:time target:self selector:@selector(_fadeOut) userInfo:nil repeats:NO];
}

#pragma mark - 淡入其实就是个UIView动画，改变透明度为1
- (void)_fadeIn
{
    [_fadeTimer invalidate];
    _fadeTimer = nil;
    
    [UIView animateWithDuration:0.33
                          delay:0
                        options:UIViewAnimationOptionCurveEaseOut | UIViewAnimationOptionTransitionNone | UIViewAnimationOptionAllowUserInteraction | UIViewAnimationOptionBeginFromCurrentState
                     animations:^(void) {
                         self.alpha = 1;
                     }
                     completion:NULL];
}

- (void)flash
{
    [self _fadeIn];
    
    if (!_alwaysVisible) {
        [self _fadeOutAfterDelay:1.5];
    }
}

- (void)quickFlash
{
    self.alpha = 1;
    
    if (!_alwaysVisible) {
        [self _fadeOutAfterDelay:0.5];
    }
}

- (void)setAlwaysVisible:(BOOL)v
{
    _alwaysVisible = v;
    
    if (_alwaysVisible) {
        [self _fadeIn];
    } else if (self.alpha > _UIScrollerMinimumAlpha && !_fadeTimer) {
        [self _fadeOut];
    }
}

- (void)setIndicatorStyle:(UIScrollViewIndicatorStyle)style
{
    _indicatorStyle = style;
    [self setNeedsDisplay];
}

- (CGFloat)knobSize
{
    /*
    //    _verticalScroller.contentSize = _contentSize.height;
    //    _verticalScroller.contentOffset = _contentOffset.y;
    //    _horizontalScroller.contentSize = _contentSize.width;
    //    _horizontalScroller.contentOffset = _contentOffset.x;
     */
    const CGRect bounds = self.bounds;
    const CGFloat dimension = MAX(bounds.size.width, bounds.size.height);
    // 这里是求出自己跟_contentSize的比例，_contentSize是什么这个方法的133到139我写了，是UIScrollView里面拷贝过来的代码
    const CGFloat knobScale = MIN(1, (dimension / _contentSize));
    return MAX((dimension * knobScale), 50);
}

- (CGRect)knobRect
{
    const CGRect bounds = self.bounds;
    const CGFloat dimension = MAX(bounds.size.width, bounds.size.height);
    const CGFloat maxContentSize = MAX(1,(_contentSize-dimension));
    const CGFloat knobSize = [self knobSize];
    const CGFloat positionScale = MIN(1, (MIN(_contentOffset,maxContentSize) / maxContentSize));
    const CGFloat knobPosition = (dimension - knobSize) * positionScale;
    
    if (_isVertical) {
        return CGRectMake(bounds.origin.x, knobPosition, bounds.size.width, knobSize);
    } else {
        return CGRectMake(knobPosition, bounds.origin.y, knobSize, bounds.size.height);
    }
}

- (void)setContentOffset:(CGFloat)newOffset
{
    _contentOffset = MIN(MAX(0,newOffset),_contentSize);
    [self setNeedsDisplay];
}

- (void)setContentSize:(CGFloat)newContentSize
{
    _contentSize = newContentSize;
    [self setNeedsDisplay];
}
- (void)drawRect:(CGRect)rect
{
    CGRect knobRect = [self knobRect];
    
    if (_isVertical) {
        knobRect.origin.y += 2;
        knobRect.size.height -= 4;
        knobRect.origin.x += 1;
        knobRect.size.width -= 3;
    } else {
        knobRect.origin.y += 1;
        knobRect.size.height -= 3;
        knobRect.origin.x += 2;
        knobRect.size.width -= 4;
    }
    
    UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:knobRect cornerRadius:4];
    
    if (_indicatorStyle == UIScrollViewIndicatorStyleBlack) {
        [[[UIColor blackColor] colorWithAlphaComponent:0.5] setFill];
    } else if (_indicatorStyle == UIScrollViewIndicatorStyleWhite) {
        [[[UIColor whiteColor] colorWithAlphaComponent:0.5] setFill];
    } else {
        [[[UIColor blackColor] colorWithAlphaComponent:0.5] setFill];
        [[[UIColor whiteColor] colorWithAlphaComponent:0.3] setStroke];
        [path setLineWidth:1.8];
        [path stroke];
    }
    
    [path fill];
}

@end
