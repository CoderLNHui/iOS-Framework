
#import "UIGestureRecognizer.h"

@interface UIGestureRecognizer ()
- (void)ignoreTouch:(UITouch *)touch forEvent:(UIEvent*)event;		// don't override

@property (nonatomic,readwrite) UIGestureRecognizerState state;

// override, but be sure to call super
- (void)reset;
- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer *)preventedGestureRecognizer;
- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer *)preventingGestureRecognizer;
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
@end
