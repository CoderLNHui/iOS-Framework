/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import "NSDate+Date.h"

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


@implementation NSDate (Date)

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













//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//

//  https://github.com/632840804/HYBNSDateExtension
@implementation NSDate (Extension)

- (NSUInteger)day {
    return [NSDate day:self];
}

- (NSUInteger)month {
    return [NSDate month:self];
}

- (NSUInteger)year {
    return [NSDate year:self];
}

- (NSUInteger)hour {
    return [NSDate hour:self];
}

- (NSUInteger)minute {
    return [NSDate minute:self];
}

- (NSUInteger)second {
    return [NSDate second:self];
}

+ (NSUInteger)day:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitDay) fromDate:date];
#else
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitDay) fromDate:date];
#endif
    
    return [dayComponents day];
}

+ (NSUInteger)month:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitMonth) fromDate:date];
#else
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitMonth) fromDate:date];
#endif
    
    return [dayComponents month];
}

+ (NSUInteger)year:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitYear) fromDate:date];
#else
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitYear) fromDate:date];
#endif
    
    return [dayComponents year];
}

+ (NSUInteger)hour:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitHour) fromDate:date];
#else
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitHour) fromDate:date];
#endif
    
    return [dayComponents hour];
}

+ (NSUInteger)minute:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitMinute) fromDate:date];
#else
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitMinute) fromDate:date];
#endif
    
    return [dayComponents minute];
}

+ (NSUInteger)second:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitSecond) fromDate:date];
#else
    NSDateComponents *dayComponents = [calendar components:(NSCalendarUnitSecond) fromDate:date];
#endif
    
    return [dayComponents second];
}

- (NSUInteger)daysInYear {
    return [NSDate daysInYear:self];
}

+ (NSUInteger)daysInYear:(NSDate *)date {
    return [self isLeapYear:date] ? 366 : 365;
}

- (BOOL)isLeapYear {
    return [NSDate isLeapYear:self];
}

+ (BOOL)isLeapYear:(NSDate *)date {
    NSUInteger year = [date year];
    if ((year % 4  == 0 && year % 100 != 0) || year % 400 == 0) {
        return YES;
    }
    return NO;
}

- (NSString *)formatYMD {
    return [NSDate formatYMD:self];
}

+ (NSString *)formatYMD:(NSDate *)date {
    return [NSString stringWithFormat:@"%lu-%02lu-%02lu",[date year],[date month], [date day]];
}

- (NSUInteger)weeksOfMonth {
    return [NSDate weeksOfMonth:self];
}

+ (NSUInteger)weeksOfMonth:(NSDate *)date {
    return [[date lastdayOfMonth] weekOfYear] - [[date begindayOfMonth] weekOfYear] + 1;
}

- (NSUInteger)weekOfYear {
    return [NSDate weekOfYear:self];
}

+ (NSUInteger)weekOfYear:(NSDate *)date {
    NSUInteger i;
    NSUInteger year = [date year];
    
    NSDate *lastdate = [date lastdayOfMonth];
    
    for (i = 1;[[lastdate dateAfterDay:-7 * i] year] == year; i++) {
        
    }
    
    return i;
}

- (NSDate *)dateAfterDay:(NSUInteger)day {
    return [NSDate dateAfterDate:self day:day];
}

+ (NSDate *)dateAfterDate:(NSDate *)date day:(NSInteger)day {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *componentsToAdd = [[NSDateComponents alloc] init];
    [componentsToAdd setDay:day];
    
    NSDate *dateAfterDay = [calendar dateByAddingComponents:componentsToAdd toDate:date options:0];
    
    return dateAfterDay;
}

- (NSDate *)dateAfterMonth:(NSUInteger)month {
    return [NSDate dateAfterDate:self month:month];
}

+ (NSDate *)dateAfterDate:(NSDate *)date month:(NSInteger)month {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *componentsToAdd = [[NSDateComponents alloc] init];
    [componentsToAdd setMonth:month];
    NSDate *dateAfterMonth = [calendar dateByAddingComponents:componentsToAdd toDate:date options:0];
    
    return dateAfterMonth;
}

- (NSDate *)begindayOfMonth {
    return [NSDate begindayOfMonth:self];
}

+ (NSDate *)begindayOfMonth:(NSDate *)date {
    return [self dateAfterDate:date day:-[date day] + 1];
}

- (NSDate *)lastdayOfMonth {
    return [NSDate lastdayOfMonth:self];
}

+ (NSDate *)lastdayOfMonth:(NSDate *)date {
    NSDate *lastDate = [self begindayOfMonth:date];
    return [[lastDate dateAfterMonth:1] dateAfterDay:-1];
}

- (NSUInteger)daysAgo {
    return [NSDate daysAgo:self];
}

+ (NSUInteger)daysAgo:(NSDate *)date {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    NSDateComponents *components = [calendar components:(NSCalendarUnitDay)
                                               fromDate:date
                                                 toDate:[NSDate date]
                                                options:0];
#else
    NSDateComponents *components = [calendar components:(NSCalendarUnitDay)
                                               fromDate:date
                                                 toDate:[NSDate date]
                                                options:0];
#endif
    
    return [components day];
}

- (NSInteger)weekday {
    return [NSDate weekday:self];
}

+ (NSInteger)weekday:(NSDate *)date {
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *comps = [gregorian components:(NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear | NSCalendarUnitWeekday) fromDate:date];
    NSInteger weekday = [comps weekday];
    
    return weekday;
}

- (NSString *)dayFromWeekday {
    return [NSDate dayFromWeekday:self];
}

+ (NSString *)dayFromWeekday:(NSDate *)date {
    switch([date weekday]) {
        case 1:
            return @"星期天";
            break;
        case 2:
            return @"星期一";
            break;
        case 3:
            return @"星期二";
            break;
        case 4:
            return @"星期三";
            break;
        case 5:
            return @"星期四";
            break;
        case 6:
            return @"星期五";
            break;
        case 7:
            return @"星期六";
            break;
        default:
            break;
    }
    return @"";
}

- (BOOL)isSameDay:(NSDate *)anotherDate {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components1 = [calendar components:(NSCalendarUnitYear
                                                          | NSCalendarUnitMonth
                                                          | NSCalendarUnitDay)
                                                fromDate:self];
    NSDateComponents *components2 = [calendar components:(NSCalendarUnitYear
                                                          | NSCalendarUnitMonth
                                                          | NSCalendarUnitDay)
                                                fromDate:anotherDate];
    return ([components1 year] == [components2 year]
            && [components1 month] == [components2 month]
            && [components1 day] == [components2 day]);
}

- (BOOL)isToday {
    return [self isSameDay:[NSDate date]];
}

- (NSDate *)dateByAddingDays:(NSUInteger)days {
    NSDateComponents *c = [[NSDateComponents alloc] init];
    c.day = days;
    return [[NSCalendar currentCalendar] dateByAddingComponents:c toDate:self options:0];
}

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
+ (NSString *)monthWithMonthNumber:(NSInteger)month {
    switch(month) {
        case 1:
            return @"January";
            break;
        case 2:
            return @"February";
            break;
        case 3:
            return @"March";
            break;
        case 4:
            return @"April";
            break;
        case 5:
            return @"May";
            break;
        case 6:
            return @"June";
            break;
        case 7:
            return @"July";
            break;
        case 8:
            return @"August";
            break;
        case 9:
            return @"September";
            break;
        case 10:
            return @"October";
            break;
        case 11:
            return @"November";
            break;
        case 12:
            return @"December";
            break;
        default:
            break;
    }
    return @"";
}

+ (NSString *)stringWithDate:(NSDate *)date format:(NSString *)format {
    return [date stringWithFormat:format];
}

- (NSString *)stringWithFormat:(NSString *)format {
    NSDateFormatter *outputFormatter = [[NSDateFormatter alloc] init];
    [outputFormatter setDateFormat:format];
    
    NSString *retStr = [outputFormatter stringFromDate:self];
    
    return retStr;
}

+ (NSDate *)dateWithString:(NSString *)string format:(NSString *)format {
    NSDateFormatter *inputFormatter = [[NSDateFormatter alloc] init];
    [inputFormatter setDateFormat:format];
    
    NSDate *date = [inputFormatter dateFromString:string];
    
    return date;
}

- (NSUInteger)daysInMonth:(NSUInteger)month {
    return [NSDate daysInMonth:self month:month];
}

+ (NSUInteger)daysInMonth:(NSDate *)date month:(NSUInteger)month {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2:
            return [date isLeapYear] ? 29 : 28;
    }
    return 30;
}

- (NSUInteger)daysInMonth {
    return [NSDate daysInMonth:self];
}

+ (NSUInteger)daysInMonth:(NSDate *)date {
    return [self daysInMonth:date month:[date month]];
}

- (NSString *)timeInfo {
    return [NSDate timeInfoWithDate:self];
}

+ (NSString *)timeInfoWithDate:(NSDate *)date {
    return [self timeInfoWithDateString:[self stringWithDate:date format:[self ymdHmsFormat]]];
}

+ (NSString *)timeInfoWithDateString:(NSString *)dateString {
    NSDate *date = [self dateWithString:dateString format:[self ymdHmsFormat]];
    
    NSDate *curDate = [NSDate date];
    NSTimeInterval time = -[date timeIntervalSinceDate:curDate];
    
    int month = (int)([curDate month] - [date month]);
    int year = (int)([curDate year] - [date year]);
    int day = (int)([curDate day] - [date day]);
    
    NSTimeInterval retTime = 1.0;
    if (time < 3600) { // 小于一小时
        retTime = time / 60;
        retTime = retTime <= 0.0 ? 1.0 : retTime;
        return [NSString stringWithFormat:@"%.0f分钟前", retTime];
    } else if (time < 3600 * 24) { // 小于一天，也就是今天
        retTime = time / 3600;
        retTime = retTime <= 0.0 ? 1.0 : retTime;
        return [NSString stringWithFormat:@"%.0f小时前", retTime];
    } else if (time < 3600 * 24 * 2) {
        return @"昨天";
    }
    // 第一个条件是同年，且相隔时间在一个月内
    // 第二个条件是隔年，对于隔年，只能是去年12月与今年1月这种情况
    else if ((abs(year) == 0 && abs(month) <= 1)
             || (abs(year) == 1 && [curDate month] == 1 && [date month] == 12)) {
        int retDay = 0;
        if (year == 0) { // 同年
            if (month == 0) { // 同月
                retDay = day;
            }
        }
        
        if (retDay <= 0) {
            // 获取发布日期中，该月有多少天
            int totalDays = (int)[self daysInMonth:date month:[date month]];
            
            // 当前天数 + （发布日期月中的总天数-发布日期月中发布日，即等于距离今天的天数）
            retDay = (int)[curDate day] + (totalDays - (int)[date day]);
        }
        
        return [NSString stringWithFormat:@"%d天前", (abs)(retDay)];
    } else  {
        if (abs(year) <= 1) {
            if (year == 0) { // 同年
                return [NSString stringWithFormat:@"%d个月前", abs(month)];
            }
            
            // 隔年
            int month = (int)[curDate month];
            int preMonth = (int)[date month];
            if (month == 12 && preMonth == 12) {// 隔年，但同月，就作为满一年来计算
                return @"1年前";
            }
            return [NSString stringWithFormat:@"%d个月前", (abs)(12 - preMonth + month)];
        }
        
        return [NSString stringWithFormat:@"%d年前", abs(year)];
    }
    
    return @"1小时前";
}

- (NSString *)ymdFormat {
    return [NSDate ymdFormat];
}

- (NSString *)hmsFormat {
    return [NSDate hmsFormat];
}

- (NSString *)ymdHmsFormat {
    return [NSDate ymdHmsFormat];
}

+ (NSString *)ymdFormat {
    return @"yyyy-MM-dd";
}

+ (NSString *)hmsFormat {
    return @"HH:mm:ss";
}

+ (NSString *)ymdHmsFormat {
    return [NSString stringWithFormat:@"%@ %@", [self ymdFormat], [self hmsFormat]];
}

- (NSDate *)offsetYears:(int)numYears {
    return [NSDate offsetYears:numYears fromDate:self];
}

+ (NSDate *)offsetYears:(int)numYears fromDate:(NSDate *)fromDate {
    if (fromDate == nil) {
        return nil;
    }
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#else
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#endif
    
    
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    [offsetComponents setYear:numYears];
    
    return [gregorian dateByAddingComponents:offsetComponents
                                      toDate:fromDate
                                     options:0];
}

- (NSDate *)offsetMonths:(int)numMonths {
    return [NSDate offsetMonths:numMonths fromDate:self];
}

+ (NSDate *)offsetMonths:(int)numMonths fromDate:(NSDate *)fromDate {
    if (fromDate == nil) {
        return nil;
    }
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#else
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#endif
    
    
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    [offsetComponents setMonth:numMonths];
    
    return [gregorian dateByAddingComponents:offsetComponents
                                      toDate:fromDate
                                     options:0];
}

- (NSDate *)offsetDays:(int)numDays {
    return [NSDate offsetDays:numDays fromDate:self];
}

+ (NSDate *)offsetDays:(int)numDays fromDate:(NSDate *)fromDate {
    if (fromDate == nil) {
        return nil;
    }
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#else
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#endif
    
    
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    [offsetComponents setDay:numDays];
    
    return [gregorian dateByAddingComponents:offsetComponents
                                      toDate:fromDate
                                     options:0];
}

- (NSDate *)offsetHours:(int)hours {
    return [NSDate offsetHours:hours fromDate:self];
}

+ (NSDate *)offsetHours:(int)numHours fromDate:(NSDate *)fromDate {
    if (fromDate == nil) {
        return nil;
    }
    
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_8_0
    // NSCalendarUnitDay
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#else
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
#endif
    
    
    NSDateComponents *offsetComponents = [[NSDateComponents alloc] init];
    [offsetComponents setHour:numHours];
    
    return [gregorian dateByAddingComponents:offsetComponents
                                      toDate:fromDate
                                     options:0];
}

@end




@implementation NSDate (Formatter)
+(NSDateFormatter *)formatter {
    
    static NSDateFormatter *formatter = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        formatter = [[NSDateFormatter alloc] init];
        [formatter setDateStyle:NSDateFormatterMediumStyle];
        [formatter setTimeStyle:NSDateFormatterShortStyle];
        [formatter setDoesRelativeDateFormatting:YES];
    });
    
    return formatter;
}

+(NSDateFormatter *)formatterWithoutTime {
    
    static NSDateFormatter *formatterWithoutTime = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        formatterWithoutTime = [[NSDate formatter] copy];
        [formatterWithoutTime setTimeStyle:NSDateFormatterNoStyle];
    });
    
    return formatterWithoutTime;
}

+(NSDateFormatter *)formatterWithoutDate {
    
    static NSDateFormatter *formatterWithoutDate = nil;
    static dispatch_once_t oncePredicate;
    
    dispatch_once(&oncePredicate, ^{
        formatterWithoutDate = [[NSDate formatter] copy];
        [formatterWithoutDate setDateStyle:NSDateFormatterNoStyle];
    });
    
    return formatterWithoutDate;
}

#pragma mark -
#pragma mark Formatter with date & time
-(NSString *)formatWithUTCTimeZone {
    return [self formatWithTimeZoneOffset:0];
}

-(NSString *)formatWithLocalTimeZone {
    return [self formatWithTimeZone:[NSTimeZone localTimeZone]];
}

-(NSString *)formatWithTimeZoneOffset:(NSTimeInterval)offset {
    return [self formatWithTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:offset]];
}

-(NSString *)formatWithTimeZone:(NSTimeZone *)timezone {
    NSDateFormatter *formatter = [NSDate formatter];
    [formatter setTimeZone:timezone];
    return [formatter stringFromDate:self];
}

#pragma mark -
#pragma mark Formatter without time
-(NSString *)formatWithUTCTimeZoneWithoutTime {
    return [self formatWithTimeZoneOffsetWithoutTime:0];
}

-(NSString *)formatWithLocalTimeZoneWithoutTime {
    return [self formatWithTimeZoneWithoutTime:[NSTimeZone localTimeZone]];
}

-(NSString *)formatWithTimeZoneOffsetWithoutTime:(NSTimeInterval)offset {
    return [self formatWithTimeZoneWithoutTime:[NSTimeZone timeZoneForSecondsFromGMT:offset]];
}

-(NSString *)formatWithTimeZoneWithoutTime:(NSTimeZone *)timezone {
    NSDateFormatter *formatter = [NSDate formatterWithoutTime];
    [formatter setTimeZone:timezone];
    return [formatter stringFromDate:self];
}

#pragma mark -
#pragma mark Formatter without date
-(NSString *)formatWithUTCWithoutDate {
    return [self formatTimeWithTimeZone:0];
}
-(NSString *)formatWithLocalTimeWithoutDate {
    return [self formatTimeWithTimeZone:[NSTimeZone localTimeZone]];
}

-(NSString *)formatWithTimeZoneOffsetWithoutDate:(NSTimeInterval)offset {
    return [self formatTimeWithTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:offset]];
}

-(NSString *)formatTimeWithTimeZone:(NSTimeZone *)timezone {
    NSDateFormatter *formatter = [NSDate formatterWithoutDate];
    [formatter setTimeZone:timezone];
    return [formatter stringFromDate:self];
}
#pragma mark -
#pragma mark Formatter  date
+ (NSString *)currentDateStringWithFormat:(NSString *)format
{
    NSDate *chosenDate = [NSDate date];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format];
    NSString *date = [formatter stringFromDate:chosenDate];
    return date;
}
+ (NSDate *)dateWithSecondsFromNow:(NSInteger)seconds {
    NSDate *date = [NSDate date];
    NSDateComponents *components = [NSDateComponents new];
    [components setSecond:seconds];
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDate *dateSecondsAgo = [calendar dateByAddingComponents:components toDate:date options:0];
    return dateSecondsAgo;
}

+ (NSDate *)dateWithYear:(NSInteger)year month:(NSUInteger)month day:(NSUInteger)day {
    NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *components = [[NSDateComponents alloc] init];
    [components setYear:year];
    [components setMonth:month];
    [components setDay:day];
    return [calendar dateFromComponents:components];
}
- (NSString *)dateStringWithFormat:(NSString *)format
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format];
    NSString *date = [formatter stringFromDate:self];
    return date;
}

@end


@implementation NSDate (Helper)

- (NSString *)getStringWithFormatter:(NSString *)format {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.dateFormat = format;
    return [formatter stringFromDate:self];
}

- (NSDate *)yesterday{
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit units = NSCalendarUnitSecond | NSCalendarUnitMinute | NSCalendarUnitHour | NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSDateComponents *components = [calendar components:units fromDate:self];
    components.day--;
    return [calendar dateFromComponents:components];
}

- (BOOL)sameYearWithNow {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit units = NSCalendarUnitSecond | NSCalendarUnitMinute | NSCalendarUnitHour | NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSDateComponents *components = [calendar components:units fromDate:self];
    NSDateComponents *components1 = [calendar components:units fromDate:[NSDate date]];
    return components.year == components1.year;
}

- (BOOL)sameDayWithNow {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit units = NSCalendarUnitSecond | NSCalendarUnitMinute | NSCalendarUnitHour | NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSDateComponents *components = [calendar components:units fromDate:self];
    NSDateComponents *components1 = [calendar components:units fromDate:[NSDate date]];
    return components.day == components1.day;
}

- (NSString *)dateAgoWithDays:(NSInteger)days {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit units = NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSDateComponents *components = [calendar components:units fromDate:self];
    components.day-= days;
    NSDate *date = [calendar dateFromComponents:components];
    
    NSDateComponents *components1 = [calendar components:units fromDate:[NSDate date]];
    if (components.year == components1.year) {
        return [date getStringWithFormatter:@"MM.dd"];
    }else {
        return [date getStringWithFormatter:@"yyyy.MM.dd"];
    }
}

- (NSString *)featuredDateAgoWithDays:(NSInteger)days {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit units = NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSDateComponents *components = [calendar components:units fromDate:self];
    components.day-= days;
    NSDate *date = [calendar dateFromComponents:components];
    
    return [date getStringWithFormatter:@"yyyy.MM.dd"];
}

- (NSString *)dateParamWithDays:(NSInteger)days {
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit units = NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear;
    NSDateComponents *components = [calendar components:units fromDate:self];
    components.day-= days;
    NSDate *date = [calendar dateFromComponents:components];
    return [date getStringWithFormatter:@"yyyy-MM-dd"];
}

- (NSInteger)daysAgoFromNow {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.dateFormat = @"yyyy-MM-dd";
    NSString *string1 = [formatter stringFromDate:self];
    NSString *string2 = [formatter stringFromDate:[NSDate date]];
    NSDate *date1 = [formatter dateFromString:string1];
    NSDate *date2 = [formatter dateFromString:string2];
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitDay)
                                               fromDate:date1
                                                 toDate:date2
                                                options:0];
    return [components day];
}


- (NSInteger)secondsAfter{
    NSCalendar *calendar =  [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitSecond)
                                               fromDate:[NSDate date]
                                                 toDate:self
                                                options:0];
    return [components second];
}
- (NSInteger)minutesAfter{
    NSCalendar *calendar =  [NSCalendar currentCalendar];
    
    NSDateComponents *components = [calendar components:(NSCalendarUnitMinute)
                                               fromDate: [NSDate date]
                                                 toDate:self
                                                options:0];
    return [components minute];
}
- (NSInteger)hoursAfter{
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitHour)
                                               fromDate:[NSDate date]
                                                 toDate: self                                              options:0];
    return [components hour];
}



- (NSInteger)daysAfter{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    formatter.dateFormat = @"yyyy-MM-dd";
    NSString *string1 = [formatter stringFromDate:self];
    NSString *string2 = [formatter stringFromDate:[NSDate date]];
    NSDate *date1 = [formatter dateFromString:string1];
    NSDate *date2 = [formatter dateFromString:string2];
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSDateComponents *components = [calendar components:(NSCalendarUnitDay)
                                               fromDate:date2
                                                 toDate:date1
                                                options:0];
    return [components day];
}



//倒计时
-(NSString*)countDown
{
    
    NSString * countDownStr = [NSMutableString string];
    if([self daysAfter]>0)
    {
        
        countDownStr = [countDownStr stringByAppendingString:[NSString stringWithFormat:@"%ld天",(long)[self daysAfter]]];
        
        NSLog(@"%@",countDownStr);
        
    }
    
    if([self hoursAfter]>0)
    {
        countDownStr = [countDownStr stringByAppendingString:[NSString stringWithFormat:@"%ld小时",(long)[self daysAfter]]];
        NSLog(@"%@",countDownStr);
        
        
    }
    if([self minutesAfter]>0)
    {
        countDownStr = [countDownStr stringByAppendingString:[NSString stringWithFormat:@"%ld分",(long)[self daysAfter]]];
        NSLog(@"%@",countDownStr);
        
    }
    
    
    
    return countDownStr;
    
}

@end




// Always keep the formatter around as they're expensive to instantiate
static NSDateFormatter *_internetDateTimeFormatter = nil;

// Good info on internet dates here:
// http://developer.apple.com/iphone/library/qa/qa2010/qa1480.html
@implementation NSDate (InternetDateTime)

// Instantiate single date formatter
+ (NSDateFormatter *)internetDateTimeFormatter {
    @synchronized(self) {
        if (!_internetDateTimeFormatter) {
            NSLocale *en_US_POSIX = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"];
            _internetDateTimeFormatter = [[NSDateFormatter alloc] init];
            [_internetDateTimeFormatter setLocale:en_US_POSIX];
            [_internetDateTimeFormatter setTimeZone:[NSTimeZone timeZoneForSecondsFromGMT:0]];
        }
    }
    return _internetDateTimeFormatter;
}

// Get a date from a string - hint can be used to speed up
+ (NSDate *)dateFromInternetDateTimeString:(NSString *)dateString formatHint:(DateFormatHint)hint {
    // Keep dateString around a while (for thread-safety)
    NSDate *date = nil;
    if (dateString) {
        if (hint != DateFormatHintRFC3339) {
            // Try RFC822 first
            date = [NSDate dateFromRFC822String:dateString];
            if (!date) date = [NSDate dateFromRFC3339String:dateString];
        } else {
            // Try RFC3339 first
            date = [NSDate dateFromRFC3339String:dateString];
            if (!date) date = [NSDate dateFromRFC822String:dateString];
        }
    }
    // Finished with date string
    return date;
}

// See http://www.faqs.org/rfcs/rfc822.html
+ (NSDate *)dateFromRFC822String:(NSString *)dateString {
    // Keep dateString around a while (for thread-safety)
    NSDate *date = nil;
    if (dateString) {
        NSDateFormatter *dateFormatter = [NSDate internetDateTimeFormatter];
        @synchronized(dateFormatter) {
            
            // Process
            NSString *RFC822String = [[NSString stringWithString:dateString] uppercaseString];
            if ([RFC822String rangeOfString:@","].location != NSNotFound) {
                if (!date) { // Sun, 19 May 2002 15:21:36 GMT
                    [dateFormatter setDateFormat:@"EEE, d MMM yyyy HH:mm:ss zzz"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
                if (!date) { // Sun, 19 May 2002 15:21 GMT
                    [dateFormatter setDateFormat:@"EEE, d MMM yyyy HH:mm zzz"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
                if (!date) { // Sun, 19 May 2002 15:21:36
                    [dateFormatter setDateFormat:@"EEE, d MMM yyyy HH:mm:ss"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
                if (!date) { // Sun, 19 May 2002 15:21
                    [dateFormatter setDateFormat:@"EEE, d MMM yyyy HH:mm"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
            } else {
                if (!date) { // 19 May 2002 15:21:36 GMT
                    [dateFormatter setDateFormat:@"d MMM yyyy HH:mm:ss zzz"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
                if (!date) { // 19 May 2002 15:21 GMT
                    [dateFormatter setDateFormat:@"d MMM yyyy HH:mm zzz"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
                if (!date) { // 19 May 2002 15:21:36
                    [dateFormatter setDateFormat:@"d MMM yyyy HH:mm:ss"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
                if (!date) { // 19 May 2002 15:21
                    [dateFormatter setDateFormat:@"d MMM yyyy HH:mm"];
                    date = [dateFormatter dateFromString:RFC822String];
                }
            }
            if (!date) NSLog(@"Could not parse RFC822 date: \"%@\" Possible invalid format.", dateString);
            
        }
    }
    // Finished with date string
    return date;
}

// See http://www.faqs.org/rfcs/rfc3339.html
+ (NSDate *)dateFromRFC3339String:(NSString *)dateString {
    // Keep dateString around a while (for thread-safety)
    NSDate *date = nil;
    if (dateString) {
        NSDateFormatter *dateFormatter = [NSDate internetDateTimeFormatter];
        @synchronized(dateFormatter) {
            
            // Process date
            NSString *RFC3339String = [[NSString stringWithString:dateString] uppercaseString];
            RFC3339String = [RFC3339String stringByReplacingOccurrencesOfString:@"Z" withString:@"-0000"];
            // Remove colon in timezone as it breaks NSDateFormatter in iOS 4+.
            // - see https://devforums.apple.com/thread/45837
            if (RFC3339String.length > 20) {
                RFC3339String = [RFC3339String stringByReplacingOccurrencesOfString:@":"
                                                                         withString:@""
                                                                            options:0
                                                                              range:NSMakeRange(20, RFC3339String.length-20)];
            }
            if (!date) { // 1996-12-19T16:39:57-0800
                [dateFormatter setDateFormat:@"yyyy'-'MM'-'dd'T'HH':'mm':'ssZZZ"];
                date = [dateFormatter dateFromString:RFC3339String];
            }
            if (!date) { // 1937-01-01T12:00:27.87+0020
                [dateFormatter setDateFormat:@"yyyy'-'MM'-'dd'T'HH':'mm':'ss.SSSZZZ"];
                date = [dateFormatter dateFromString:RFC3339String];
            }
            if (!date) { // 1937-01-01T12:00:27
                [dateFormatter setDateFormat:@"yyyy'-'MM'-'dd'T'HH':'mm':'ss"];
                date = [dateFormatter dateFromString:RFC3339String];
            }
            if(!date) //  2013-04-05 14:06:00
            {
                [dateFormatter setDateFormat:@"yyyy'-'MM'-'dd HH':'mm':'ss"];
                date = [dateFormatter dateFromString:RFC3339String];
            }
            if (!date) NSLog(@"Could not parse RFC3339 date: \"%@\" Possible invalid format.", dateString);
            
        }
    }
    // Finished with date string
    return date;
}

@end




// Private Helper functions
@interface NSDate (Private)
+ (void)zeroOutTimeComponents:(NSDateComponents **)components;
+ (NSDate *)firstDayOfQuarterFromDate:(NSDate *)date;
@end

@implementation NSDate (Reporting)

+ (NSDate *)dateWithYear:(int)year month:(int)month day:(int)day {
    NSDateComponents *components = [[NSDateComponents alloc] init];
    
    // Assign the year, month and day components.
    [components setYear:year];
    [components setMonth:month];
    [components setDay:day];
    
    // Zero out the hour, minute and second components.
    [self zeroOutTimeComponents:&components];
    
    // Generate a valid NSDate and return it.
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    return [gregorianCalendar dateFromComponents:components];
}

+ (NSDate *)midnightOfDate:(NSDate *)date {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    // Start out by getting just the year, month and day components of the specified date.
    NSDateComponents *components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay
                                                        fromDate:date];
    // Zero out the hour, minute and second components.
    [self zeroOutTimeComponents:&components];
    
    // Convert the components back into a date and return it.
    return [gregorianCalendar dateFromComponents:components];
}

+ (NSDate *)midnightToday {
    return [self midnightOfDate:[NSDate date]];
}

+ (NSDate *)midnightTomorrow {
    NSDate *midnightToday = [self midnightToday];
    return [self oneDayAfter:midnightToday];
}

+ (NSDate *)oneDayAfter:(NSDate *)date {
    NSDateComponents *oneDayComponent = [[NSDateComponents alloc] init];
    [oneDayComponent setDay:1];
    
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    return [gregorianCalendar dateByAddingComponents:oneDayComponent
                                              toDate:date
                                             options:0];
}

+ (NSDate *)firstDayOfCurrentMonth {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    // Start out by getting just the year, month and day components of the current date.
    NSDate *currentDate = [NSDate date];
    NSDateComponents *components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay
                                                        fromDate:currentDate];
    
    // Change the Day component to 1 (for the first day of the month), and zero out the time components.
    [components setDay:1];
    [self zeroOutTimeComponents:&components];
    
    return [gregorianCalendar dateFromComponents:components];
}

+ (NSDate *)firstDayOfPreviousMonth {
    // Set up a "minus one month" component.
    NSDateComponents *minusOneMonthComponent = [[NSDateComponents alloc] init];
    [minusOneMonthComponent setMonth:-1];
    
    // Subtract 1 month from today's date. This gives us "one month ago today".
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDate *currentDate = [NSDate date];
    NSDate *oneMonthAgoToday = [gregorianCalendar dateByAddingComponents:minusOneMonthComponent
                                                                  toDate:currentDate
                                                                 options:0];
    
    // Now extract the year, month and day components of oneMonthAgoToday.
    NSDateComponents *components = [gregorianCalendar components:NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear
                                                        fromDate:oneMonthAgoToday];
    
    // Change the day to 1 (since we want the first day of the previous month).
    [components setDay:1];
    
    // Zero out the time components so we get midnight.
    [self zeroOutTimeComponents:&components];
    
    // Finally, create a new NSDate from components and return it.
    return [gregorianCalendar dateFromComponents:components];
}

+ (NSDate *)firstDayOfNextMonth {
    NSDate *firstDayOfCurrentMonth = [self firstDayOfCurrentMonth];
    
    // Set up a "plus 1 month" component.
    NSDateComponents *plusOneMonthComponent = [[NSDateComponents alloc] init];
    [plusOneMonthComponent setMonth:1];
    
    // Add 1 month to firstDayOfCurrentMonth.
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    return [gregorianCalendar dateByAddingComponents:plusOneMonthComponent
                                              toDate:firstDayOfCurrentMonth
                                             options:0];
}

+ (NSDate *)firstDayOfCurrentQuarter {
    return [self firstDayOfQuarterFromDate:[NSDate date]];
}

+ (NSDate *)firstDayOfPreviousQuarter {
    NSDate *firstDayOfCurrentQuarter = [self firstDayOfCurrentQuarter];
    
    // Set up a "minus one day" component.
    NSDateComponents *minusOneDayComponent = [[NSDateComponents alloc] init];
    [minusOneDayComponent setDay:-1];
    
    // Subtract 1 day from firstDayOfCurrentQuarter.
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDate *lastDayOfPreviousQuarter = [gregorianCalendar dateByAddingComponents:minusOneDayComponent
                                                                          toDate:firstDayOfCurrentQuarter
                                                                         options:0];
    return [self firstDayOfQuarterFromDate:lastDayOfPreviousQuarter];
}

+ (NSDate *)firstDayOfNextQuarter {
    NSDate *firstDayOfCurrentQuarter = [self firstDayOfCurrentQuarter];
    
    // Set up a "plus 3 months" component.
    NSDateComponents *plusThreeMonthsComponent = [[NSDateComponents alloc] init];
    [plusThreeMonthsComponent setMonth:3];
    
    // Add 3 months to firstDayOfCurrentQuarter.
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    return [gregorianCalendar dateByAddingComponents:plusThreeMonthsComponent
                                              toDate:firstDayOfCurrentQuarter
                                             options:0];
}

+ (NSDate *)firstDayOfCurrentYear {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    // Start out by getting just the year, month and day components of the current date.
    NSDate *currentDate = [NSDate date];
    NSDateComponents *components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay
                                                        fromDate:currentDate];
    
    // Change the Day and Month components to 1 (for the first day of the year), and zero out the time components.
    [components setDay:1];
    [components setMonth:1];
    [self zeroOutTimeComponents:&components];
    
    return [gregorianCalendar dateFromComponents:components];
}

+ (NSDate *)firstDayOfPreviousYear {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDate *currentDate = [NSDate date];
    NSDateComponents *components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay
                                                        fromDate:currentDate];
    [components setDay:1];
    [components setMonth:1];
    [components setYear:components.year - 1];
    
    // Zero out the time components so we get midnight.
    [self zeroOutTimeComponents:&components];
    return [gregorianCalendar dateFromComponents:components];
}

+ (NSDate *)firstDayOfNextYear {
    NSDate *firstDayOfCurrentYear = [self firstDayOfCurrentYear];
    
    // Set up a "plus 1 year" component.
    NSDateComponents *plusOneYearComponent = [[NSDateComponents alloc] init];
    [plusOneYearComponent setYear:1];
    
    // Add 1 year to firstDayOfCurrentYear.
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    return [gregorianCalendar dateByAddingComponents:plusOneYearComponent
                                              toDate:firstDayOfCurrentYear
                                             options:0];
}

#ifdef DEBUG
- (void)logWithComment:(NSString *)comment {
    NSString *output = [NSDateFormatter localizedStringFromDate:self
                                                      dateStyle:NSDateFormatterMediumStyle
                                                      timeStyle:NSDateFormatterMediumStyle];
    NSLog(@"%@: %@", comment, output);
}
#endif

#pragma mark - Private Helper functions

+ (void)zeroOutTimeComponents:(NSDateComponents **)components {
    [*components setHour:0];
    [*components setMinute:0];
    [*components setSecond:0];
}

+ (NSDate *)firstDayOfQuarterFromDate:(NSDate *)date {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents *components = [gregorianCalendar components:NSCalendarUnitMonth | NSCalendarUnitYear
                                                        fromDate:date];
    
    NSInteger quarterNumber = floor((components.month - 1) / 3) + 1;
    // NSLog(@"Quarter number: %d", quarterNumber);
    
    NSInteger firstMonthOfQuarter = (quarterNumber - 1) * 3 + 1;
    [components setMonth:firstMonthOfQuarter];
    [components setDay:1];
    
    // Zero out the time components so we get midnight.
    [self zeroOutTimeComponents:&components];
    return [gregorianCalendar dateFromComponents:components];
}



- (NSDate*) dateFloor {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* dateComponents = [gregorianCalendar components:(NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear) fromDate:self];
    
    return [gregorianCalendar dateFromComponents:dateComponents];
}

- (NSDate*) dateCeil {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* dateComponents = [gregorianCalendar components:(NSCalendarUnitDay | NSCalendarUnitMonth | NSCalendarUnitYear) fromDate:self];
    
    [dateComponents setHour:23];
    [dateComponents setMinute:59];
    [dateComponents setSecond:59];
    
    return [gregorianCalendar dateFromComponents:dateComponents];
}

- (NSDate*) startOfWeek {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitWeekday | NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:self];
    
    [components setDay:([components day] - ([components weekday] - 1))];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) endOfWeek {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitWeekday | NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:self];
    
    [components setDay:([components day] + (7 - [components weekday]))];
    [components setHour:23];
    [components setMinute:59];
    [components setSecond:59];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) startOfMonth {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth fromDate:self];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) endOfMonth {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth fromDate:self];
    
    NSRange dayRange = [gregorianCalendar rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:self];
    
    [components setDay:dayRange.length];
    [components setHour:23];
    [components setMinute:59];
    [components setSecond:59];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) startOfYear {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitYear fromDate:self];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) endOfYear {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitYear fromDate:self];
    
    [components setDay:31];
    [components setMonth:12];
    [components setHour:23];
    [components setMinute:59];
    [components setSecond:59];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) previousDay {
    return [self dateByAddingTimeInterval:-86400];
}

- (NSDate*) nextDay {
    return [self dateByAddingTimeInterval:86400];
}

- (NSDate*) previousWeek {
    return [self dateByAddingTimeInterval:-(86400*7)];
}

- (NSDate*) nextWeek {
    return [self dateByAddingTimeInterval:+(86400*7)];
}

- (NSDate*) previousMonth {
    return [self previousMonth:1];
}

- (NSDate*) previousMonth:(NSUInteger) monthsToMove {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:self];
    
    NSInteger dayInMonth = [components day];
    
    // Update the components, initially setting the day in month to 0
    NSInteger newMonth = ([components month] - monthsToMove);
    [components setDay:1];
    [components setMonth:newMonth];
    
    // Determine the valid day range for that month
    NSDate* workingDate = [gregorianCalendar dateFromComponents:components];
    NSRange dayRange = [gregorianCalendar rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:workingDate];
    
    // Set the day clamping to the maximum number of days in that month
    [components setDay:MIN(dayInMonth, dayRange.length)];
    
    return [gregorianCalendar dateFromComponents:components];
}

- (NSDate*) nextMonth {
    return [self nextMonth:1];
}

- (NSDate*) nextMonth:(NSUInteger) monthsToMove {
    NSCalendar *gregorianCalendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    NSDateComponents* components = [gregorianCalendar components:NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay fromDate:self];
    
    NSInteger dayInMonth = [components day];
    
    // Update the components, initially setting the day in month to 0
    NSInteger newMonth = ([components month] + monthsToMove);
    [components setDay:1];
    [components setMonth:newMonth];
    
    // Determine the valid day range for that month
    NSDate* workingDate = [gregorianCalendar dateFromComponents:components];
    NSRange dayRange = [gregorianCalendar rangeOfUnit:NSCalendarUnitDay inUnit:NSCalendarUnitMonth forDate:workingDate];
    
    // Set the day clamping to the maximum number of days in that month
    [components setDay:MIN(dayInMonth, dayRange.length)];
    
    return [gregorianCalendar dateFromComponents:components];
}







@end
#
