/*
 * UNNotificationAttachment.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */


/**
 UNNotificationAttachment，通知内容UNNotificationContent包含的附件，一般为图片、视频和音频，虽然iOS10的通知数据容量为4k，但依旧很少，在添加了UNNotificationServiceExtension扩展的情况下，可以在服务里下载图片，生成图片、视频等的本地缓存，UNNotificationAttachment根据缓存数据生成并添加到UNNotificationContent中，交由UI显示
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
@interface UNNotificationAttachment : NSObject <NSCopying, NSSecureCoding>

// The identifier of this attachment
@property (NS_NONATOMIC_IOSONLY, readonly, copy) NSString *identifier;

// The URL to the attachment's data. If you have obtained this attachment from UNUserNotificationCenter then the URL will be security-scoped.
@property (nonatomic, readonly, copy) NSURL *URL;

// The UTI of the attachment.
@property (nonatomic, readonly, copy) NSString *type;

// Creates an attachment for the data at URL with an optional options dictionary. URL must be a file URL. Returns nil if the data at URL is not supported.
+ (nullable instancetype)attachmentWithIdentifier:(NSString *)identifier URL:(NSURL *)URL options:(nullable NSDictionary *)options error:(NSError *__nullable *__nullable)error;

- (instancetype)init NS_UNAVAILABLE;

@end

// Key to manually provide a type hint for the attachment. If not set the type hint will be guessed from the attachment's file extension. Value must be an NSString.
//【指定文件类型，查看文档可以发现支持哪些文件】
extern NSString * const UNNotificationAttachmentOptionsTypeHintKey __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

// Key to specify if the thumbnail for this attachment is hidden. Defaults to NO. Value must be a boolean NSNumber.
//【指定通知上是否显示文件的缩略图】
extern NSString * const UNNotificationAttachmentOptionsThumbnailHiddenKey __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

// Key to specify a normalized clipping rectangle to use for the attachment thumbnail. Value must be a CGRect encoded using CGRectCreateDictionaryRepresentation.
//【指定缩略图的切割比例】
extern NSString * const UNNotificationAttachmentOptionsThumbnailClippingRectKey __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

// Key to specify the animated image frame number or the movie time to use as the thumbnail.
// An animated image frame number must be an NSNumber. A movie time must either be an NSNumber with the time in seconds or a CMTime encoded using CMTimeCopyAsDictionary.
//【影片切割时间】
extern NSString * const UNNotificationAttachmentOptionsThumbnailTimeKey __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

NS_ASSUME_NONNULL_END

