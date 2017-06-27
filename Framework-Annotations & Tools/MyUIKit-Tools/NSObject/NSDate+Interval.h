//
//  NSDate+Interval.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

//---------------------------【日期处理(计算两个时间的间隔值)】------------------------------//
//

#import <Foundation/Foundation.h>


@interface NSCalendar (Init)

+ (instancetype)ln_calendar;

@end
//--------------------------- 【日期处理(计算两个时间的间隔值)】 ------------------------------//



@interface LNDateInterval : NSObject
/** 相隔多少天 */
@property (nonatomic, assign) NSInteger day;
/** 相隔多少小时 */
@property (nonatomic, assign) NSInteger hour;
/** 相隔多少分钟 */
@property (nonatomic, assign) NSInteger minute;
/** 相隔多少秒 */
@property (nonatomic, assign) NSInteger second;

@end

@interface NSDate (Interval)

/**
 *  判断是否为今天
 */
- (BOOL)ln_isInToday;
/**
 *  判断是否为昨天
 */
- (BOOL)ln_isInYesterday;
/**
 *  判断是否为明天
 */
- (BOOL)ln_isInTomorrow;
/**
 *  判断是否为今年
 */
- (BOOL)ln_isInThisYear;

/**
 *  计算self和anotherDate之间的时间间隔,返回值为LNDateInterval模型
 */
- (LNDateInterval *)ln_intervalSinceDate:(NSDate *)anotherDate;

- (void)ln_intervalSinceDate:(NSDate *)anotherDate day:(NSInteger *)dayP hour:(NSInteger *)hourP minute:(NSInteger *)minuteP second:(NSInteger *)secondP;
@end

