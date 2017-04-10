// 完全实现ok
#import "UIColor.h"

@class UIColorRep;

@interface UIColor (UIPrivate)
- (id)_initWithRepresentations:(NSArray *)reps;
- (UIColorRep *)_bestRepresentationForProposedScale:(CGFloat)scale;
- (BOOL)_isOpaque;
@end
