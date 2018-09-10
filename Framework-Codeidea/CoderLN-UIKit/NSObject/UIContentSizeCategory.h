/*
 * UIContentSizeCategory.h
 *
 * UIKit (c) 2016-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * UIContentSizeCategory NS_STRING_ENUM NS_AVAILABLE_IOS(7_0);

// Content size category constants

UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryUnspecified NS_AVAILABLE_IOS(10_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryExtraSmall NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategorySmall NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryMedium NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryLarge NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryExtraLarge NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryExtraExtraLarge NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryExtraExtraExtraLarge NS_AVAILABLE_IOS(7_0);

// Accessibility sizes
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryAccessibilityMedium NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryAccessibilityLarge NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryAccessibilityExtraLarge NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryAccessibilityExtraExtraLarge NS_AVAILABLE_IOS(7_0);
UIKIT_EXTERN UIContentSizeCategory const UIContentSizeCategoryAccessibilityExtraExtraExtraLarge NS_AVAILABLE_IOS(7_0);

// Notification is emitted when the user has changed the preferredContentSizeCategory for the system
UIKIT_EXTERN NSNotificationName const UIContentSizeCategoryDidChangeNotification NS_AVAILABLE_IOS(7_0); // userInfo dictionary will contain new value for UIContentSizeCategoryNewValueKey
UIKIT_EXTERN NSString *const UIContentSizeCategoryNewValueKey NS_AVAILABLE_IOS(7_0); // NSString instance with new content size category in userInfo

UIKIT_EXTERN BOOL UIContentSizeCategoryIsAccessibilityCategory(UIContentSizeCategory category) API_AVAILABLE(ios(11.0),tvos(11.0),watchos(4.0)) NS_REFINED_FOR_SWIFT;
UIKIT_EXTERN NSComparisonResult UIContentSizeCategoryCompareToCategory(UIContentSizeCategory lhs, UIContentSizeCategory rhs) API_AVAILABLE(ios(11.0),tvos(11.0),watchos(4.0)) NS_REFINED_FOR_SWIFT;

NS_ASSUME_NONNULL_END

