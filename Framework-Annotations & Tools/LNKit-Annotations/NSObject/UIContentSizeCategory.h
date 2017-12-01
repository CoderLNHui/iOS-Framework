/*
 * UIContentSizeCategory.h
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2016-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
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

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
