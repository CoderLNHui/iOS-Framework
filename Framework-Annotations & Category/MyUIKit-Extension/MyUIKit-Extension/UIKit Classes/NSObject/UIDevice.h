//  完全实现ok
//  UIDevice.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/7.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const UIDeviceOrientationDidChangeNotification;

typedef NS_ENUM(NSInteger, UIDeviceOrientation) {
    UIDeviceOrientationUnknown,
    UIDeviceOrientationPortrait,
    UIDeviceOrientationPortraitUpsideDown,
    UIDeviceOrientationLandscapeLeft,
    UIDeviceOrientationLandscapeRight,
    UIDeviceOrientationFaceUp,
    UIDeviceOrientationFaceDown
};

typedef NS_ENUM(NSInteger, UIUserInterfaceIdiom) {
    UIUserInterfaceIdiomPhone,
    UIUserInterfaceIdiomPad,
    UIUserInterfaceIdiomDesktop,
};

#define UI_USER_INTERFACE_IDIOM() \
([[UIDevice currentDevice] respondsToSelector:@selector(userInterfaceIdiom)] ? \
[[UIDevice currentDevice] userInterfaceIdiom] : \
UIUserInterfaceIdiomPhone)

#define UIDeviceOrientationIsPortrait(orientation)  \
((orientation) == UIDeviceOrientationPortrait || \
(orientation) == UIDeviceOrientationPortraitUpsideDown)

#define UIDeviceOrientationIsLandscape(orientation) \
((orientation) == UIDeviceOrientationLandscapeLeft || \
(orientation) == UIDeviceOrientationLandscapeRight)

@interface UIDevice : NSObject
+ (UIDevice *)currentDevice;

- (void)beginGeneratingDeviceOrientationNotifications;  // no effect
- (void)endGeneratingDeviceOrientationNotifications;    // no effect

@property (nonatomic, readonly, strong) NSString *name;
@property (nonatomic, assign) UIUserInterfaceIdiom userInterfaceIdiom;
@property (nonatomic, readonly) UIDeviceOrientation orientation;
@property (nonatomic, readonly,getter=isMultitaskingSupported) BOOL multitaskingSupported;	
@property (nonatomic, readonly, strong) NSString *systemName;
@property (nonatomic, readonly, strong) NSString *systemVersion;
@property (nonatomic, readonly, strong) NSString *model;
@property (nonatomic, readonly, getter=isGeneratingDeviceOrientationNotifications) BOOL generatesDeviceOrientationNotifications; // aways
@end
