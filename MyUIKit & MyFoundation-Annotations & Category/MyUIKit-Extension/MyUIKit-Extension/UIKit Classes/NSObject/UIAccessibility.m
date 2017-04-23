
#import "UIAccessibility.h"

UIAccessibilityTraits UIAccessibilityTraitNone = 0;
UIAccessibilityTraits UIAccessibilityTraitButton = 1;
UIAccessibilityTraits UIAccessibilityTraitLink = 2;
UIAccessibilityTraits UIAccessibilityTraitImage = 4;
UIAccessibilityTraits UIAccessibilityTraitSelected = 8;
UIAccessibilityTraits UIAccessibilityTraitPlaysSound = 16;
UIAccessibilityTraits UIAccessibilityTraitKeyboardKey = 32;
UIAccessibilityTraits UIAccessibilityTraitStaticText = 64;
UIAccessibilityTraits UIAccessibilityTraitSummaryElement = 128;
UIAccessibilityTraits UIAccessibilityTraitNotEnabled = 256;
UIAccessibilityTraits UIAccessibilityTraitUpdatesFrequently = 512;
UIAccessibilityTraits UIAccessibilityTraitSearchField = 1024;
UIAccessibilityTraits UIAccessibilityTraitHeader = 2048;

UIAccessibilityNotifications UIAccessibilityScreenChangedNotification = 1000;
UIAccessibilityNotifications UIAccessibilityLayoutChangedNotification = 1001;
UIAccessibilityNotifications UIAccessibilityAnnouncementNotification = 1002;
UIAccessibilityNotifications UIAccessibilityPageScrolledNotification = 1003;

NSString *const UIAccessibilityVoiceOverStatusChanged = @"UIAccessibilityVoiceOverStatusChanged";

@implementation NSObject (UIAccessibility)
- (BOOL)isAccessibilityElement
{
    return NO;
}

- (void)setIsAccessibilityElement:(BOOL)isElement
{
}

- (NSString *)accessibilityLabel
{
    return nil;
}

- (void)setAccessibilityLabel:(NSString *)label
{
}

- (NSString *)accessibilityHint
{
    return nil;
}

- (void)setAccessibilityHint:(NSString *)hint
{
}

- (NSString *)accessibilityValue
{
    return nil;
}

- (void)setAccessibilityValue:(NSString *)value
{
}

- (UIAccessibilityTraits)accessibilityTraits
{
    return UIAccessibilityTraitNone; // STUB
}

- (void)setAccessibilityTraits:(UIAccessibilityTraits)traits
{
}

- (CGRect)accessibilityFrame
{
    return CGRectNull;
}

- (void)setAccessibilityFrame:(CGRect)frame
{
}

- (BOOL)accessibilityViewIsModal
{
    return NO;
}

- (void)setAccessibilityViewIsModal:(BOOL)isModal
{
}

- (BOOL)accessibilityElementsHidden
{
    return NO;
}

- (void)setAccessibilityElementsHidden:(BOOL)accessibilityElementsHidden
{
}

@end


@implementation NSObject (UIAccessibilityContainer)
- (NSInteger)accessibilityElementCount
{
    return 0;
}

- (id)accessibilityElementAtIndex:(NSInteger)index
{
    return nil;
}

- (NSInteger)indexOfAccessibilityElement:(id)element
{
    return NSNotFound;
}
@end


@implementation NSObject (UIAccessibilityFocus)
- (void)accessibilityElementDidBecomeFocused
{
}

- (void)accessibilityElementDidLoseFocus
{
}

- (BOOL)accessibilityElementIsFocused
{
    return NO;
}
@end


void UIAccessibilityPostNotification(UIAccessibilityNotifications notification, id argument)
{
}

BOOL UIAccessibilityIsVoiceOverRunning()
{
    return NO;
}
