// 完全实现ok
#import <Foundation/Foundation.h>

typedef uint64_t UIAccessibilityTraits;

extern UIAccessibilityTraits UIAccessibilityTraitNone;
extern UIAccessibilityTraits UIAccessibilityTraitButton;
extern UIAccessibilityTraits UIAccessibilityTraitLink;
extern UIAccessibilityTraits UIAccessibilityTraitSearchField;
extern UIAccessibilityTraits UIAccessibilityTraitImage;
extern UIAccessibilityTraits UIAccessibilityTraitSelected;
extern UIAccessibilityTraits UIAccessibilityTraitPlaysSound;
extern UIAccessibilityTraits UIAccessibilityTraitKeyboardKey;
extern UIAccessibilityTraits UIAccessibilityTraitStaticText;
extern UIAccessibilityTraits UIAccessibilityTraitSummaryElement;
extern UIAccessibilityTraits UIAccessibilityTraitNotEnabled;
extern UIAccessibilityTraits UIAccessibilityTraitUpdatesFrequently;
extern UIAccessibilityTraits UIAccessibilityTraitHeader;


typedef uint32_t UIAccessibilityNotifications;
extern UIAccessibilityNotifications UIAccessibilityScreenChangedNotification;
extern UIAccessibilityNotifications UIAccessibilityLayoutChangedNotification;
extern UIAccessibilityNotifications UIAccessibilityAnnouncementNotification;
extern UIAccessibilityNotifications UIAccessibilityPageScrolledNotification;


@interface NSObject (UIAccessibility)
@property (nonatomic) BOOL isAccessibilityElement;
@property (nonatomic) NSString *accessibilityLabel;
@property (nonatomic) NSString *accessibilityHint;
@property (nonatomic) NSString *accessibilityValue;
@property (nonatomic) UIAccessibilityTraits accessibilityTraits;
@property (nonatomic) CGRect accessibilityFrame;
@property (nonatomic) BOOL accessibilityViewIsModal;
@property (nonatomic) BOOL accessibilityElementsHidden;
@end

@interface NSObject (UIAccessibilityContainer)
- (NSInteger)accessibilityElementCount;
- (id)accessibilityElementAtIndex:(NSInteger)index;
- (NSInteger)indexOfAccessibilityElement:(id)element;
@end

@interface NSObject (UIAccessibilityFocus)
- (void)accessibilityElementDidBecomeFocused;
- (void)accessibilityElementDidLoseFocus;
- (BOOL)accessibilityElementIsFocused;
@end

extern void UIAccessibilityPostNotification(UIAccessibilityNotifications notification, id argument);
extern BOOL UIAccessibilityIsVoiceOverRunning(void);

extern NSString *const UIAccessibilityVoiceOverStatusChanged;

typedef NS_ENUM(NSInteger, UIAccessibilityScrollDirection) {
    UIAccessibilityScrollDirectionRight = 1,
    UIAccessibilityScrollDirectionLeft,
    UIAccessibilityScrollDirectionUp,
    UIAccessibilityScrollDirectionDown,
    UIAccessibilityScrollDirectionNext,
    UIAccessibilityScrollDirectionPrevious
};
