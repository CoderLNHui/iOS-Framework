/*
 * UNNotificationSound.h 
 *
 * UserNotifications (c) 2015
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

__IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0) __TVOS_PROHIBITED
@interface UNNotificationSound : NSObject <NSCopying, NSSecureCoding>

// The default sound used for notifications.
+ (instancetype)defaultSound;

// The name of a sound file to be played for the notification. The sound file must be contained in the app’s bundle or in the Library/Sounds folder of the app's data container. If files exist in both locations then the file in ~/Library/Sounds will be preferred.
+ (instancetype)soundNamed:(NSString *)name __WATCHOS_PROHIBITED;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
