/*
 * UIDatePicker.h 
 *
 * UIKit (c) 2006-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIDatePickerMode) {
    UIDatePickerModeTime,// 时间           // Displays hour, minute, and optionally AM/PM designation depending on the locale setting (e.g. 6 | 53 | PM)
    UIDatePickerModeDate,// 日期           // Displays month, day, and year depending on the locale setting (e.g. November | 15 | 2007)
    UIDatePickerModeDateAndTime,// 日期和时间    // Displays date, hour, minute, and optionally AM/PM designation depending on the locale setting (e.g. Wed Nov 15 | 6 | 53 | PM)
    UIDatePickerModeCountDownTimer,// 时分 // Displays hour and minute (e.g. 1 | 53)
} __TVOS_PROHIBITED;

NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UIDatePicker : UIControl <NSCoding>

@property (nonatomic) UIDatePickerMode datePickerMode;// 设置日期模式 // default is UIDatePickerModeDateAndTime

@property (nullable, nonatomic, strong) NSLocale   *locale;// 设置地区: zh - 中国   // default is [NSLocale currentLocale]. setting nil returns to default

@property (null_resettable, nonatomic, copy)   NSCalendar *calendar; // default is [NSCalendar currentCalendar]. setting nil returns to default
@property (nullable, nonatomic, strong) NSTimeZone *timeZone; // default is nil. use current time zone or time zone from calendar

@property (nonatomic, strong) NSDate *date;        // default is current date when picker created. Ignored in countdown timer mode. for that mode, picker starts at 0:00

// 设置显示的最小日期
@property (nullable, nonatomic, strong) NSDate *minimumDate; // specify min/max date range. default is nil. When min > max, the values are ignored. Ignored in countdown timer mode
// 设置显示的最大日期
@property (nullable, nonatomic, strong) NSDate *maximumDate; // default is nil

// 设置时分
@property (nonatomic) NSTimeInterval countDownDuration; // for UIDatePickerModeCountDownTimer, ignored otherwise. default is 0.0. limit is 23:59 (86,399 seconds). value being set is div 60 (drops remaining seconds).
@property (nonatomic) NSInteger      minuteInterval;    // display minutes wheel with interval. interval must be evenly divided into 60. default is 1. min is 1, max is 30

// 设置日期
- (void)setDate:(NSDate *)date animated:(BOOL)animated; // if animated is YES, animate the wheels of time to display the new date




// 添加事件:监听日期改变
[datePicker addTarget:self action:@selector(dateChange:) forControlEvents:UIControlEventValueChanged];


- (void)dateChange:(UIDatePicker *)datePicker
{
    // 1.获取当前日期
    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    // 设置显示格式
    fmt.dateFormat = @"yyyy年 MM月 dd日 HH:mm:ss";
    // 2.将日期转字符串
    self.text = [fmt stringFromDate:datePicker.date];
}









@end
NS_ASSUME_NONNULL_END


