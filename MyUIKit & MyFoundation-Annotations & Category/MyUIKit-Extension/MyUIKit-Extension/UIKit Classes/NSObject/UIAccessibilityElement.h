// 完全实现ok
#import "UIAccessibility.h"

@interface UIAccessibilityElement : NSObject
- (id)initWithAccessibilityContainer:(id)container;

@property (nonatomic, strong) NSString *accessibilityLabel;
@property (nonatomic, strong) NSString *accessibilityHint;
@property (nonatomic, strong) NSString *accessibilityValue;
@property (nonatomic, assign) CGRect accessibilityFrame;
@property (nonatomic, assign) UIAccessibilityTraits accessibilityTraits;
@end
