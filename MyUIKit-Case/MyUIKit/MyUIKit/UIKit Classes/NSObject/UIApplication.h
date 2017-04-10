//
//  UIApplication.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIResponder.h"
#import "UIDevice.h"

extern NSString *const UIApplicationWillChangeStatusBarOrientationNotification;
extern NSString *const UIApplicationDidChangeStatusBarOrientationNotification;
extern NSString *const UIApplicationWillEnterForegroundNotification;
extern NSString *const UIApplicationWillTerminateNotification;
extern NSString *const UIApplicationWillResignActiveNotification;
extern NSString *const UIApplicationDidEnterBackgroundNotification;
extern NSString *const UIApplicationDidBecomeActiveNotification;
extern NSString *const UIApplicationDidFinishLaunchingNotification;

extern NSString *const UIApplicationLaunchOptionsURLKey;
extern NSString *const UIApplicationLaunchOptionsSourceApplicationKey;
extern NSString *const UIApplicationLaunchOptionsRemoteNotificationKey;
extern NSString *const UIApplicationLaunchOptionsAnnotationKey;
extern NSString *const UIApplicationLaunchOptionsLocalNotificationKey;
extern NSString *const UIApplicationLaunchOptionsLocationKey;

extern NSString *const UIApplicationDidReceiveMemoryWarningNotification;

extern NSString *const UITrackingRunLoopMode;

typedef NS_ENUM(NSInteger, UIStatusBarStyle) {
    UIStatusBarStyleDefault,
    UIStatusBarStyleBlackTranslucent,
    UIStatusBarStyleBlackOpaque
};

typedef NS_ENUM(NSInteger, UIStatusBarAnimation) {
    UIStatusBarAnimationNone,
    UIStatusBarAnimationFade,
    UIStatusBarAnimationSlide,
};

typedef NS_ENUM(NSInteger, UIInterfaceOrientation) {
    UIInterfaceOrientationPortrait           = UIDeviceOrientationPortrait,
    UIInterfaceOrientationPortraitUpsideDown = UIDeviceOrientationPortraitUpsideDown,
    UIInterfaceOrientationLandscapeLeft      = UIDeviceOrientationLandscapeRight,
    UIInterfaceOrientationLandscapeRight     = UIDeviceOrientationLandscapeLeft
};

typedef NS_OPTIONS(NSUInteger, UIInterfaceOrientationMask) {
    UIInterfaceOrientationMaskPortrait = (1 << UIInterfaceOrientationPortrait),
    UIInterfaceOrientationMaskLandscapeLeft = (1 << UIInterfaceOrientationLandscapeLeft),
    UIInterfaceOrientationMaskLandscapeRight = (1 << UIInterfaceOrientationLandscapeRight),
    UIInterfaceOrientationMaskPortraitUpsideDown = (1 << UIInterfaceOrientationPortraitUpsideDown),
    UIInterfaceOrientationMaskLandscape = (UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight),
    UIInterfaceOrientationMaskAll = (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight | UIInterfaceOrientationMaskPortraitUpsideDown),
    UIInterfaceOrientationMaskAllButUpsideDown = (UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight),
};


@interface UIApplication : UIResponder
+ (UIApplication *)sharedApplication;
- (BOOL)sendAction:(SEL)action to:(id)target from:(id)sender forEvent:(UIEvent *)event;
@end
