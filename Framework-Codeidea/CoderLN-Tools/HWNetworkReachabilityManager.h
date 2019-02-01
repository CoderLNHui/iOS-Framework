/*
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import "AFNetworkReachabilityManager.h"

@interface HWNetworkReachabilityManager : NSObject

// 当前网络状态
@property (nonatomic, assign, readonly) AFNetworkReachabilityStatus networkReachabilityStatus;

// 获取单例
+ (instancetype)shareManager;

// 监听网络状态
- (void)monitorNetworkStatus;

@end
