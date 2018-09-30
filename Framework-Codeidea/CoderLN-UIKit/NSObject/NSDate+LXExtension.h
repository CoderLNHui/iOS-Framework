/*
 * NSDate+LXExtension.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#import <Foundation/Foundation.h>

@interface LXDateItem : NSObject
@property (nonatomic, assign) NSInteger day;
@property (nonatomic, assign) NSInteger hour;
@property (nonatomic, assign) NSInteger minute;
@property (nonatomic, assign) NSInteger second;
@end

@interface NSDate (LXExtension)

- (LXDateItem *)lx_timeIntervalSinceDate:(NSDate *)anotherDate;

- (BOOL)lx_isToday;
- (BOOL)lx_isYesterday;
- (BOOL)lx_isTomorrow;
- (BOOL)lx_isThisYear;
// 获取今天周几
- (NSInteger)getNowWeekday;


@end
 
