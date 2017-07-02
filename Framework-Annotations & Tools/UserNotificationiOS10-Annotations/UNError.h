/*
 * UNError.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 * Created by 【Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */
 
#import <Foundation/Foundation.h>

extern NSString * const UNErrorDomain __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

typedef NS_ENUM(NSInteger, UNErrorCode) {
    UNErrorCodeNotificationsNotAllowed = 1,
    
    UNErrorCodeAttachmentInvalidURL = 100,
    UNErrorCodeAttachmentUnrecognizedType,
    UNErrorCodeAttachmentInvalidFileSize,
    UNErrorCodeAttachmentNotInDataStore,
    UNErrorCodeAttachmentMoveIntoDataStoreFailed,
    UNErrorCodeAttachmentCorrupt,
    
    UNErrorCodeNotificationInvalidNoDate = 1400,
    UNErrorCodeNotificationInvalidNoContent,
} __IOS_AVAILABLE(10.0) __TVOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);
