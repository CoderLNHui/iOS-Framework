// 滚动动画的实现   完全实现ok
#import "UIScrollViewAnimation.h"

typedef NS_ENUM(NSInteger, UIScrollViewAnimationScrollCurve) {
    UIScrollViewAnimationScrollCurveLinear,
    UIScrollViewAnimationScrollCurveQuadraticEaseOut
};

@interface UIScrollViewAnimationScroll : UIScrollViewAnimation
- (id)initWithScrollView:(UIScrollView *)sv fromContentOffset:(CGPoint)from toContentOffset:(CGPoint)to duration:(NSTimeInterval)d curve:(UIScrollViewAnimationScrollCurve)c;

@property (nonatomic, readonly) CGPoint beginContentOffset;
@property (nonatomic, readonly) CGPoint endContentOffset;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, readonly) UIScrollViewAnimationScrollCurve animationCurve;
@end
