// 减速动画的类   完全实现ok
#import "UIScrollViewAnimation.h"

typedef struct {
    NSTimeInterval decelerateTime;
    CGFloat position;
    CGFloat velocity;
    NSTimeInterval returnTime;
    CGFloat returnFrom;
    BOOL bounced;
} UIScrollViewAnimationDecelerationComponent;

@interface UIScrollViewAnimationDeceleration : UIScrollViewAnimation
- (id)initWithScrollView:(UIScrollView *)sv velocity:(CGPoint)v;

@end







