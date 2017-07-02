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
 

#include <Foundation/Foundation.h>

@class UNNotificationRequest;
@class UNNotificationContent;

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED
@interface UNNotificationServiceExtension : NSObject

// Call contentHandler with the modified notification content to deliver. If the handler is not called before the service's time expires then the unmodified notification will be delivered.
// You are expected to override this method to implement push notification modification.
- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent *contentToDeliver))contentHandler;

// Will be called just before this extension is terminated by the system. You may choose whether to override this method.
- (void)serviceExtensionTimeWillExpire;

@end

NS_ASSUME_NONNULL_END
