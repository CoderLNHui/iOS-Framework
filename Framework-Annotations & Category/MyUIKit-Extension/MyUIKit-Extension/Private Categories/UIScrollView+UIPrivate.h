//  完全实现ok
#import "UIScrollView.h"

@interface UIScrollView (UIPrivate)
- (void)_quickFlashScrollIndicators;
- (CGPoint)_confinedContentOffset:(CGPoint)p;
- (void)_setRestrainedContentOffset:(CGPoint)offset;
@end
