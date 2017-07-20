/*
 * UIDevice+Device.h
 * 🔍白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */


#import <UIKit/UIKit.h>


@interface UIDevice (Device)
+ (NSString*)deviceVersion;
@end



/*
 Erica Sadun, http://ericasadun.com
 iPhone Developer's Cookbook, 6.x Edition
 BSD License, Use at your own risk
 
 Modified by Eric Horacek for Monospace Ltd. on 2/4/13
 */

typedef NS_ENUM(NSUInteger, UIDeviceFamily) {
    UIDeviceFamilyiPhone,
    UIDeviceFamilyiPod,
    UIDeviceFamilyiPad,
    UIDeviceFamilyAppleTV,
    UIDeviceFamilyUnknown,
};

@interface UIDevice (Hardware)

/**
 Returns a machine-readable model name in the format of "iPhone4,1"
 */
- (NSString *)modelIdentifier;

/**
 Returns a human-readable model name in the format of "iPhone 4S". Fallback of the the `modelIdentifier` value.
 机型
 */
- (NSString *)modelName;

/** iPhone7,2 */
+ (NSString *)platform;

/** iPhone 6 */
+ (NSString *)platformString;

/** mac地址 */
+ (NSString *)macAddress;

/** ram的size */
+ (NSUInteger)ramSize;

/** cpu个数 */
+ (NSUInteger)cpuNumber;

/** 系统的版本号 */
+ (NSString *)systemVersion;

/** 是否有摄像头 */
+ (BOOL)hasCamera;

/** 获取手机内存总量, 返回的是字节数 */
+ (NSUInteger)totalMemoryBytes;

/** 获取手机可用内存, 返回的是字节数 */
+ (NSUInteger)freeMemoryBytes;

/** 获取手机硬盘总空间, 返回的是字节数 */
+ (NSUInteger)totalDiskSpaceBytes;

/** 获取手机硬盘空闲空间, 返回的是字节数 */
+ (NSUInteger)freeDiskSpaceBytes;

@end
