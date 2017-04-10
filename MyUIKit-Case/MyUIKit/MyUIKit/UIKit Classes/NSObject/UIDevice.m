//
//  UIDevice.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/7.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIDevice.h"
#import <IOKit/IOKitLib.h>
#import <SystemConfiguration/SystemConfiguration.h>

NSString *const UIDeviceOrientationDidChangeNotification = @"UIDeviceOrientationDidChangeNotification";

static UIDevice *theDevice;

@implementation UIDevice

+ (void)initialize
{
    if (self == [UIDevice class]) {
        theDevice = [[UIDevice alloc] init];
    }
}

+ (UIDevice *)currentDevice
{
    return theDevice;
}

- (id)init
{
    if ((self=[super init])) {
        _userInterfaceIdiom = UIUserInterfaceIdiomPhone;
    }
    return self;
}

- (NSString *)name
{
    return (__bridge_transfer NSString *)SCDynamicStoreCopyComputerName(NULL,NULL);
}

- (UIDeviceOrientation)orientation
{
    return UIDeviceOrientationPortrait;
}

- (BOOL)isMultitaskingSupported
{
    return YES;
}

- (NSString *)systemName
{
    return [[NSProcessInfo processInfo] operatingSystemVersionString];
}

- (NSString *)systemVersion
{
    return [[NSProcessInfo processInfo] operatingSystemVersionString];
}

- (NSString *)model
{
    return @"iPhone";
}

- (BOOL)isGeneratingDeviceOrientationNotifications
{
    return NO;
}

- (void)beginGeneratingDeviceOrientationNotifications
{
}

- (void)endGeneratingDeviceOrientationNotifications
{
}

@end
