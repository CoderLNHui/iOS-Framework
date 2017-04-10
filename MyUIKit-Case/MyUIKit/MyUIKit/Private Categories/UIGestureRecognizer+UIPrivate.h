//  完全实现
#import "UIGestureRecognizer.h"
#import "UITouch.h"

@class UITouchEvent;

@interface UIGestureRecognizer (UIPrivate)
- (void)_setView:(UIView *)v;
- (void)_abort;

- (void)_beginTrackingTouch:(UITouch *)touch withEvent:(UITouchEvent *)event;
- (void)_continueTrackingWithEvent:(UITouchEvent *)event;
- (void)_endTrackingTouch:(UITouch *)touch withEvent:(UITouchEvent *)event;
@end
