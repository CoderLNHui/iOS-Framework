/*
 * UNError.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
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


#_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
