//
//  NSDate+Interval.m
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import "NSDate+Interval.h"

@implementation NSCalendar (Init)
+ (instancetype)ln_calendar
{
    if ([NSCalendar respondsToSelector:@selector(calendarWithIdentifier:)]) {
        return [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
    } else {
        return [NSCalendar currentCalendar];
    }
}
@end
//--------------------------- <#我是分割线#> ------------------------------//




@implementation LNDateInterval
@end


@implementation NSDate (Interval)

/**
 *  判断是否为今年
 */
- (BOOL)ln_isInThisYear
{
    NSCalendar *calendar = [NSCalendar ln_calendar];
    
    NSDateComponents *nowCmps = [calendar components:NSCalendarUnitYear fromDate:[NSDate date]];
    NSDateComponents *selfCmps = [calendar components:NSCalendarUnitYear fromDate:self];
    
    // NSDateComponents重写了isEqual:方法, 只要各种元素一样, 那么isEqual:就返回YES
    return [nowCmps isEqual:selfCmps];
}

/**
 *  判断是否为今天
 */
- (BOOL)ln_isInToday
{
    NSCalendar *calendar = [NSCalendar ln_calendar];
    
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay;
    NSDateComponents *nowCmps = [calendar components:unit fromDate:[NSDate date]];
    NSDateComponents *selfCmps = [calendar components:unit fromDate:self];
    
    // NSDateComponents重写了isEqual:方法, 只要各种元素一样, 那么isEqual:就返回YES
    return [nowCmps isEqual:selfCmps];
    //    return nowCmps.year == selfCmps.year
    //    && nowCmps.month == selfCmps.month
    //    && nowCmps.day == selfCmps.day;
}

/**
 *  判断是否为昨天
 */
- (BOOL)ln_isInYesterday
{
    // 判断self是否为昨天
    
    // self == 2015-01-31 23:10:10 -> 2015-01-31 00:00:00
    // now  == 2015-02-01 01:10:10 -> 2015-02-01 00:00:00
    
    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    fmt.dateFormat = @"yyyyMMdd";
    
    // 生成只有年月日的字符串(没有时分秒, 时分秒已经被抛弃了)
    NSString *selfString = [fmt stringFromDate:self]; // 20150131
    NSString *nowString = [fmt stringFromDate:[NSDate date]]; // 20150201
    
    // 生成只有年月日的日期(没有时分秒, 时分秒已经被抛弃了)
    NSDate *selfDate = [fmt dateFromString:selfString];
    NSDate *nowDate = [fmt dateFromString:nowString];
    
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay;
    NSDateComponents *cmps = [[NSCalendar ln_calendar] components:unit fromDate:selfDate toDate:nowDate options:0];
    
    return cmps.year == 0
    && cmps.month == 0
    && cmps.day == 1;
}

/**
 *  判断是否为明天
 */
- (BOOL)ln_isInTomorrow
{    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    fmt.dateFormat = @"yyyyMMdd";
    
    // 生成只有年月日的字符串(没有时分秒, 时分秒已经被抛弃了)
    NSString *selfString = [fmt stringFromDate:self]; // 20150131
    NSString *nowString = [fmt stringFromDate:[NSDate date]]; // 20150201
    
    // 生成只有年月日的日期(没有时分秒, 时分秒已经被抛弃了)
    NSDate *selfDate = [fmt dateFromString:selfString];
    NSDate *nowDate = [fmt dateFromString:nowString];
    
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay;
    NSDateComponents *cmps = [[NSCalendar ln_calendar] components:unit fromDate:selfDate toDate:nowDate options:0];
    
    return cmps.year == 0
    && cmps.month == 0
    && cmps.day == -1;
}
//通过模型作为返回值,传值
- (LNDateInterval *)ln_intervalSinceDate:(NSDate *)anotherDate
{
    // 时间间隔(单位:s)
    NSInteger interval = [self timeIntervalSinceDate:anotherDate];
    
    NSInteger secsPerMinute = 60;
    NSInteger secsPerHour = 60 * secsPerMinute;
    NSInteger secsPerDay = 24 * secsPerHour;
    
    LNDateInterval *dateInterval = [[LNDateInterval alloc] init];
    dateInterval.day = interval / secsPerDay;
    dateInterval.hour = (interval % secsPerDay) / secsPerHour;
    dateInterval.minute = ((interval % secsPerDay) % secsPerHour) / secsPerMinute;
    dateInterval.second = interval % secsPerMinute;
    return dateInterval;
}

//通过地址传值
- (void)ln_intervalSinceDate:(NSDate *)anotherDate day:(NSInteger *)dayP hour:(NSInteger *)hourP minute:(NSInteger *)minuteP second:(NSInteger *)secondP
{
    // 时间间隔(单位:s)
    NSInteger interval = [self timeIntervalSinceDate:anotherDate];
    
    NSInteger secsPerMinute = 60;
    NSInteger secsPerHour = 60 * secsPerMinute;
    NSInteger secsPerDay = 24 * secsPerHour;
    
    *dayP = interval / secsPerDay;
    *hourP = (interval % secsPerDay) / secsPerHour;
    *minuteP = ((interval % secsPerDay) % secsPerHour) / secsPerMinute;
    *secondP = interval % secsPerMinute;
}

@end
