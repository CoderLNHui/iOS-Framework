/*
 * UNNotificationServiceExtension.h
 * UserNotifications
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2015
 * Created by 【Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */
 

/**
 UNNotificationServiceExtension，是一个在接收到APNs服务器推送过来的数据进行处理的服务扩展，如果App提供了服务扩展，那么APNs下发推送后在通知显示触发之前，会在UNNotificationServiceExtension内接收到，此处有大约30秒的处理时间，开发者可以进行一些数据下载、数据解密、更新等操作，然后交由而后的内容扩展(UNNotificationContentExtension)或者是App进行触发显示，这里需要注意：如果数据处理失败，超时，extension会报一个崩溃信息，但是通知会用默认的形式展示出来，app不会崩溃。
 */

#include <Foundation/Foundation.h>

@class UNNotificationRequest;
@class UNNotificationContent;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED
@interface UNNotificationServiceExtension : NSObject

// Call contentHandler with the modified notification content to deliver. If the handler is not called before the service's time expires then the unmodified notification will be delivered.
// You are expected to override this method to implement push notification modification.
//【你需要通过重写这个方法，来重写你的通知内容，也可以在这里下载附件内容】
- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent *contentToDeliver))contentHandler;

// Will be called just before this extension is terminated by the system. You may choose whether to override this method.
//【如果处理时间太长，等不及处理了，就会把收到的apns直接展示出来】
- (void)serviceExtensionTimeWillExpire;

@end

NS_ASSUME_NONNULL_END
