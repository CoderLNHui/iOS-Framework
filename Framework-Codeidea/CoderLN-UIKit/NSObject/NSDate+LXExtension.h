/*
 * NSDate+LXExtension.h
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 作用：
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
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
 
