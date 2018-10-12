/*
 * NSDate+Date.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

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

@interface NSDate (Date)

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






//--------------------------- <#我是分割线#> ------------------------------//
//

/**
 * 获取日、月、年、小时、分钟、秒
 */
- (NSUInteger)day;
- (NSUInteger)month;
- (NSUInteger)year;
- (NSUInteger)hour;
- (NSUInteger)minute;
- (NSUInteger)second;
+ (NSUInteger)day:(NSDate *)date;
+ (NSUInteger)month:(NSDate *)date;
+ (NSUInteger)year:(NSDate *)date;
+ (NSUInteger)hour:(NSDate *)date;
+ (NSUInteger)minute:(NSDate *)date;
+ (NSUInteger)second:(NSDate *)date;

/**
 * 获取一年中的总天数
 */
- (NSUInteger)daysInYear;
+ (NSUInteger)daysInYear:(NSDate *)date;

/**
 * 判断是否是润年
 * @return YES表示润年，NO表示平年
 */
- (BOOL)isLeapYear;
+ (BOOL)isLeapYear:(NSDate *)date;

/**
 * 获取该日期是该年的第几周
 */
- (NSUInteger)weekOfYear;
+ (NSUInteger)weekOfYear:(NSDate *)date;

/**
 * 获取格式化为YYYY-MM-dd格式的日期字符串
 */
- (NSString *)formatYMD;
+ (NSString *)formatYMD:(NSDate *)date;

/**
 * 返回当前月一共有几周(可能为4,5,6)
 */
- (NSUInteger)weeksOfMonth;
+ (NSUInteger)weeksOfMonth:(NSDate *)date;

/**
 * 获取该月的第一天的日期
 */
- (NSDate *)begindayOfMonth;
+ (NSDate *)begindayOfMonth:(NSDate *)date;

/**
 * 获取该月的最后一天的日期
 */
- (NSDate *)lastdayOfMonth;
+ (NSDate *)lastdayOfMonth:(NSDate *)date;

/**
 * 返回day天后的日期(若day为负数,则为|day|天前的日期)
 */
- (NSDate *)dateAfterDay:(NSUInteger)day;
+ (NSDate *)dateAfterDate:(NSDate *)date day:(NSInteger)day;

/**
 * 返回day天后的日期(若day为负数,则为|day|天前的日期)
 */
- (NSDate *)dateAfterMonth:(NSUInteger)month;
+ (NSDate *)dateAfterDate:(NSDate *)date month:(NSInteger)month;

/**
 * 返回numYears年后的日期
 */
- (NSDate *)offsetYears:(int)numYears;
+ (NSDate *)offsetYears:(int)numYears fromDate:(NSDate *)fromDate;

/**
 * 返回numMonths月后的日期
 */
- (NSDate *)offsetMonths:(int)numMonths;
+ (NSDate *)offsetMonths:(int)numMonths fromDate:(NSDate *)fromDate;

/**
 * 返回numDays天后的日期
 */
- (NSDate *)offsetDays:(int)numDays;
+ (NSDate *)offsetDays:(int)numDays fromDate:(NSDate *)fromDate;

/**
 * 返回numHours小时后的日期
 */
- (NSDate *)offsetHours:(int)hours;
+ (NSDate *)offsetHours:(int)numHours fromDate:(NSDate *)fromDate;

/**
 * 距离该日期前几天
 */
- (NSUInteger)daysAgo;
+ (NSUInteger)daysAgo:(NSDate *)date;

/**
 *  获取星期几
 *
 *  @return Return weekday number
 *  [1 - Sunday]
 *  [2 - Monday]
 *  [3 - Tuerday]
 *  [4 - Wednesday]
 *  [5 - Thursday]
 *  [6 - Friday]
 *  [7 - Saturday]
 */
- (NSInteger)weekday;
+ (NSInteger)weekday:(NSDate *)date;

/**
 *  获取星期几(名称)
 *
 *  @return Return weekday as a localized string
 *  [1 - Sunday]
 *  [2 - Monday]
 *  [3 - Tuerday]
 *  [4 - Wednesday]
 *  [5 - Thursday]
 *  [6 - Friday]
 *  [7 - Saturday]
 */
- (NSString *)dayFromWeekday;
+ (NSString *)dayFromWeekday:(NSDate *)date;

/**
 *  日期是否相等
 *
 *  @param anotherDate The another date to compare as NSDate
 *  @return Return YES if is same day, NO if not
 */
- (BOOL)isSameDay:(NSDate *)anotherDate;

/**
 *  是否是今天
 *
 *  @return Return if self is today
 */
- (BOOL)isToday;

/**
 *  Add days to self
 *
 *  @param days The number of days to add
 *  @return Return self by adding the gived days number
 */
- (NSDate *)dateByAddingDays:(NSUInteger)days;

/**
 *  Get the month as a localized string from the given month number
 *
 *  @param month The month to be converted in string
 *  [1 - January]
 *  [2 - February]
 *  [3 - March]
 *  [4 - April]
 *  [5 - May]
 *  [6 - June]
 *  [7 - July]
 *  [8 - August]
 *  [9 - September]
 *  [10 - October]
 *  [11 - November]
 *  [12 - December]
 *
 *  @return Return the given month as a localized string
 */
+ (NSString *)monthWithMonthNumber:(NSInteger)month;

/**
 * 根据日期返回字符串
 */
+ (NSString *)stringWithDate:(NSDate *)date format:(NSString *)format;
- (NSString *)stringWithFormat:(NSString *)format;
+ (NSDate *)dateWithString:(NSString *)string format:(NSString *)format;

/**
 * 获取指定月份的天数
 */
- (NSUInteger)daysInMonth:(NSUInteger)month;
+ (NSUInteger)daysInMonth:(NSDate *)date month:(NSUInteger)month;

/**
 * 获取当前月份的天数
 */
- (NSUInteger)daysInMonth;
+ (NSUInteger)daysInMonth:(NSDate *)date;

/**
 * 返回x分钟前/x小时前/昨天/x天前/x个月前/x年前
 */
- (NSString *)timeInfo;
+ (NSString *)timeInfoWithDate:(NSDate *)date;
+ (NSString *)timeInfoWithDateString:(NSString *)dateString;

/**
 * 分别获取yyyy-MM-dd/HH:mm:ss/yyyy-MM-dd HH:mm:ss格式的字符串
 */
- (NSString *)ymdFormat;
- (NSString *)hmsFormat;
- (NSString *)ymdHmsFormat;
+ (NSString *)ymdFormat;
+ (NSString *)hmsFormat;
+ (NSString *)ymdHmsFormat;

@end



//  http://schwiiz.org/
@interface NSDate (Formatter)

+(NSDateFormatter *)formatter;
+(NSDateFormatter *)formatterWithoutTime;
+(NSDateFormatter *)formatterWithoutDate;

-(NSString *)formatWithUTCTimeZone;
-(NSString *)formatWithLocalTimeZone;
-(NSString *)formatWithTimeZoneOffset:(NSTimeInterval)offset;
-(NSString *)formatWithTimeZone:(NSTimeZone *)timezone;

-(NSString *)formatWithUTCTimeZoneWithoutTime;
-(NSString *)formatWithLocalTimeZoneWithoutTime;
-(NSString *)formatWithTimeZoneOffsetWithoutTime:(NSTimeInterval)offset;
-(NSString *)formatWithTimeZoneWithoutTime:(NSTimeZone *)timezone;

-(NSString *)formatWithUTCWithoutDate;
-(NSString *)formatWithLocalTimeWithoutDate;
-(NSString *)formatWithTimeZoneOffsetWithoutDate:(NSTimeInterval)offset;
-(NSString *)formatTimeWithTimeZone:(NSTimeZone *)timezone;


+ (NSString *)currentDateStringWithFormat:(NSString *)format;
+ (NSDate *)dateWithSecondsFromNow:(NSInteger)seconds;
+ (NSDate *)dateWithYear:(NSInteger)year month:(NSUInteger)month day:(NSUInteger)day;
- (NSString *)dateStringWithFormat:(NSString *)format;
@end


@interface NSDate (Helper)

/** 获取日期的指定格式字符串  */
- (NSString *)getStringWithFormatter:(NSString *)format;

- (NSDate *)yesterday;

- (BOOL)sameYearWithNow;
- (BOOL)sameDayWithNow;

/** 获取今天之前几天的日期字符串 */
- (NSString *)dateAgoWithDays:(NSInteger)days;

/** 精选日期 */
- (NSString *)featuredDateAgoWithDays:(NSInteger)days;

/** 获取今天之前几天的日期字符串 */
- (NSString *)dateParamWithDays:(NSInteger)days;

/** 计算日期距离今天又几天，按零点分割天 */
- (NSInteger)daysAgoFromNow;

/** 倒计时几天几小时几分  */
-(NSString*)countDown;

//- (NSString *)intervalSinceNow: (NSString *) theDate;

@end




// A category to parse internet date & time strings
@interface NSDate (InternetDateTime)

// Formatting hints
typedef enum {
    DateFormatHintNone,
    DateFormatHintRFC822,
    DateFormatHintRFC3339
} DateFormatHint;


// Get date from RFC3339 or RFC822 string
// - A format/specification hint can be used to speed up,
//   otherwise both will be attempted in order to get a date
+ (NSDate *)dateFromInternetDateTimeString:(NSString *)dateString
                                formatHint:(DateFormatHint)hint;

// Get date from a string using a specific date specification
+ (NSDate *)dateFromRFC3339String:(NSString *)dateString;
+ (NSDate *)dateFromRFC822String:(NSString *)dateString;

@end




@interface NSDate (Reporting)

// Return a date with a specified year, month and day.
+ (NSDate *)dateWithYear:(int)year month:(int)month day:(int)day;

// Return midnight on the specified date.
+ (NSDate *)midnightOfDate:(NSDate *)date;

// Return midnight today.
+ (NSDate *)midnightToday;

// Return midnight tomorrow.
+ (NSDate *)midnightTomorrow;

// Returns a date that is exactly 1 day after the specified date. Does *not*
// zero out the time components. For example, if the specified date is
// April 15 2012 10:00 AM, the return value will be April 16 2012 10:00 AM.
+ (NSDate *)oneDayAfter:(NSDate *)date;

// Returns midnight of the first day of the current, previous or next Month.
// Note: firstDayOfNextMonth returns midnight of the first day of next month,
// which is effectively the same as the "last moment" of the current month.
+ (NSDate *)firstDayOfCurrentMonth;
+ (NSDate *)firstDayOfPreviousMonth;
+ (NSDate *)firstDayOfNextMonth;

// Returns midnight of the first day of the current, previous or next Quarter.
// Note: firstDayOfNextQuarter returns midnight of the first day of next quarter,
// which is effectively the same as the "last moment" of the current quarter.
+ (NSDate *)firstDayOfCurrentQuarter;
+ (NSDate *)firstDayOfPreviousQuarter;
+ (NSDate *)firstDayOfNextQuarter;

// Returns midnight of the first day of the current, previous or next Year.
// Note: firstDayOfNextYear returns midnight of the first day of next year,
// which is effectively the same as the "last moment" of the current year.
+ (NSDate *)firstDayOfCurrentYear;
+ (NSDate *)firstDayOfPreviousYear;
+ (NSDate *)firstDayOfNextYear;


- (NSDate*)dateFloor;
- (NSDate*)dateCeil;

- (NSDate*)startOfWeek;
- (NSDate*)endOfWeek;

- (NSDate*) startOfMonth;
- (NSDate*) endOfMonth;

- (NSDate*) startOfYear;
- (NSDate*) endOfYear;

- (NSDate*) previousDay;
- (NSDate*) nextDay;

- (NSDate*) previousWeek;
- (NSDate*) nextWeek;

- (NSDate*) previousMonth;
- (NSDate*) previousMonth:(NSUInteger) monthsToMove;
- (NSDate*) nextMonth;
- (NSDate*) nextMonth:(NSUInteger) monthsToMove;

#ifdef DEBUG
// For testing only. A helper function to format and display a date
// with an optional comment. For example:
//     NSDate *test = [NSDate firstDayOfCurrentMonth];
//     [test logWithComment:@"First day of current month: "];
- (void)logWithComment:(NSString *)comment;
#endif



@end
#


















