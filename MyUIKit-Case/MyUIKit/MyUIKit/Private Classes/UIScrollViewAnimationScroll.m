
#import "UIScrollViewAnimationScroll.h"

@implementation UIScrollViewAnimationScroll

- (id)initWithScrollView:(UIScrollView *)sv fromContentOffset:(CGPoint)from toContentOffset:(CGPoint)to duration:(NSTimeInterval)d curve:(UIScrollViewAnimationScrollCurve)c
{
    if ((self=[super initWithScrollView:sv])) {
        _beginContentOffset = from;
        _endContentOffset = to;
        _duration = d;
        _animationCurve = c;
    }
    return self;
}
    
- (BOOL)animate
{
    const NSTimeInterval currentTime = [NSDate timeIntervalSinceReferenceDate];
    const NSTimeInterval elapsedTime = currentTime - self.beginTime;
    const CGFloat animationPosition = MIN(1, (elapsedTime / _duration));

    CGFloat (*curveFunction)(CGFloat t, CGFloat start, CGFloat end) = (_animationCurve == UIScrollViewAnimationScrollCurveLinear)? &UILinearInterpolation : &UIQuadraticEaseOut;
    
    self.scrollView.contentOffset = CGPointMake(curveFunction(animationPosition, _beginContentOffset.x, _endContentOffset.x),
                                           curveFunction(animationPosition, _beginContentOffset.y, _endContentOffset.y));

    return (animationPosition == 1);
}

@end
