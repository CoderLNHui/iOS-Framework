//  完全实现ok
#import "UIImage.h"

@class NSImage, UIImageRep;

@interface UIImage (UIPrivate)
+ (void)_cacheImage:(UIImage *)image forName:(NSString *)name;
+ (UIImage *)_cachedImageForName:(NSString *)name;
+ (UIImage *)_backButtonImage;
+ (UIImage *)_highlightedBackButtonImage;
+ (UIImage *)_toolbarButtonImage;
+ (UIImage *)_highlightedToolbarButtonImage;
+ (UIImage *)_leftPopoverArrowImage;
+ (UIImage *)_rightPopoverArrowImage;
+ (UIImage *)_topPopoverArrowImage;
+ (UIImage *)_bottomPopoverArrowImage;
+ (UIImage *)_popoverBackgroundImage;
+ (UIImage *)_roundedRectButtonImage;
+ (UIImage *)_highlightedRoundedRectButtonImage;
+ (UIImage *)_windowResizeGrabberImage;
+ (UIImage *)_buttonBarSystemItemAdd;
+ (UIImage *)_buttonBarSystemItemReply;
+ (UIImage *)_tabBarBackgroundImage;
+ (UIImage *)_tabBarItemImage;

- (id)_initWithRepresentations:(NSArray *)reps;
- (UIImageRep *)_bestRepresentationForProposedScale:(CGFloat)scale;
- (void)_drawRepresentation:(UIImageRep *)rep inRect:(CGRect)rect;
- (NSArray *)_representations;
- (BOOL)_isOpaque;

- (UIImage *)_toolbarImage;		// returns a new image which is modified as required for toolbar buttons (turned into a solid color)
@end
