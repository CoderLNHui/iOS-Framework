//  私有分类    完全实现
#import "UIWindow.h"

@interface UIWindow (UIPrivate)
- (UIResponder *)_firstResponder;
- (void)_setFirstResponder:(UIResponder *)newFirstResponder;
- (void)_makeHidden;
- (void)_makeVisible;
@end
