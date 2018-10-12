/*
 * UNError.h 
 *
 * UserNotifications (c) 2015
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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
