//  完全实现
#import "UIView.h"

extern NSString *const UIViewFrameDidChangeNotification;
extern NSString *const UIViewBoundsDidChangeNotification;
extern NSString *const UIViewDidMoveToSuperviewNotification;
extern NSString *const UIViewHiddenDidChangeNotification;

@interface UIView (UIPrivate)
- (void)_removeFromSuperview:(BOOL)notifyViewController;
- (void)_setViewController:(UIViewController *)theViewController;
- (UIViewController *)_viewController;
- (void)_superviewSizeDidChangeFrom:(CGSize)oldSize to:(CGSize)newSize;
- (void)_layoutSubviews;
- (void)_didMoveToScreen;
@end
