// 完全实现ok
#import "UIColor.h"
#import "UIFont.h"


typedef NS_ENUM(NSInteger, UIBarStyle) {
    UIBarStyleDefault = 0,
    UIBarStyleBlack = 1,
    UIBarStyleBlackOpaque = 1, // Deprecated
    UIBarStyleBlackTranslucent = 2 // Deprecated
};

typedef NS_ENUM(NSInteger, UIBarMetrics) {
    UIBarMetricsDefault,
    UIBarMetricsLandscapePhone,
};

@interface UIColor (UIColorSystemColors)
+ (UIColor *)groupTableViewBackgroundColor;
@end


@interface UIFont (UIFontSystemFonts)
+ (CGFloat)systemFontSize;
+ (CGFloat)smallSystemFontSize;
+ (CGFloat)labelFontSize;
+ (CGFloat)buttonFontSize;
@end
