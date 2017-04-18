// 完全实现
#import "UITouch.h"

@class UIGestureRecognizer;

@interface UITouch (UIPrivate)
@property (nonatomic, readwrite, assign) NSTimeInterval timestamp;
@property (nonatomic, readwrite, assign) NSUInteger tapCount;
@property (nonatomic, readwrite, assign) UITouchPhase phase;
@property (nonatomic, readwrite, assign) UIView *view;
@property (nonatomic, readwrite, assign) CGPoint locationOnScreen;
@property (nonatomic, readwrite, assign) BOOL wasDeliveredToView;
@property (nonatomic, readwrite, assign) BOOL wasCancelledInView;
@property (nonatomic, readonly) NSTimeInterval beganPhaseTimestamp;
@property (nonatomic, readonly) CGPoint beganPhaseLocationOnScreen;
- (void)_addGestureRecognizer:(UIGestureRecognizer *)recognizer;
- (void)_removeGestureRecognizer:(UIGestureRecognizer *)recognizer;
@end
