//
//  HWToolBox.m
//  HWProject
//
//  Created by wangqibin on 2018/4/9.
//  Copyright © 2018年 wangqibin. All rights reserved.
//

#import "HWToolBox.h"
#include <sys/types.h>
#include <sys/sysctl.h>

@implementation HWToolBox

// 根据字节大小返回文件大小字符KB、MB
+ (NSString *)stringFromByteCount:(long long)byteCount
{
    return [NSByteCountFormatter stringFromByteCount:byteCount countStyle:NSByteCountFormatterCountStyleFile];
}

// 时间转换为时间戳，精确到微秒
+ (NSInteger)getTimeStampWithDate:(NSDate *)date
{
    return [[NSNumber numberWithDouble:[date timeIntervalSince1970] * 1000 * 1000] integerValue];
}

// 时间戳转换为时间
+ (NSDate *)getDateWithTimeStamp:(NSInteger)timeStamp
{
    return [NSDate dateWithTimeIntervalSince1970:timeStamp * 0.001 * 0.001];
}

// 一个时间戳与当前时间的间隔（s）
+ (NSInteger)getIntervalsWithTimeStamp:(NSInteger)timeStamp
{
    return [[NSDate date] timeIntervalSinceDate:[self getDateWithTimeStamp:timeStamp]];
}

//验证是否是纯数字
+ (BOOL)isAllNumber:(NSString *)number
{
    if (number.length == 0) {
        return NO;
    }
    
    NSString *regex = @"[0-9]*";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    if ([pred evaluateWithObject:number]) {
        return YES;
    }
    
    return NO;
}

//获得设备型号
+ (NSString *)getCurrentDeviceModel
{
    int mib[2];
    size_t len;
    char *machine;
    
    mib[0] = CTL_HW;
    mib[1] = HW_MACHINE;
    sysctl(mib, 2, NULL, &len, NULL, 0);
    machine = malloc(len);
    sysctl(mib, 2, machine, &len, NULL, 0);
    
    NSString *platform = [NSString stringWithCString:machine encoding:NSASCIIStringEncoding];
    free(machine);
    
    // iPhone
    if ([platform isEqualToString:@"iPhone1,1"]) return @"iPhone 2G";
    if ([platform isEqualToString:@"iPhone1,2"]) return @"iPhone 3G";
    if ([platform isEqualToString:@"iPhone2,1"]) return @"iPhone 3GS";
    if ([platform isEqualToString:@"iPhone3,1"]) return @"iPhone 4";
    if ([platform isEqualToString:@"iPhone3,2"]) return @"iPhone 4";
    if ([platform isEqualToString:@"iPhone3,3"]) return @"iPhone 4";
    if ([platform isEqualToString:@"iPhone4,1"]) return @"iPhone 4S";
    if ([platform isEqualToString:@"iPhone5,1"]) return @"iPhone 5";
    if ([platform isEqualToString:@"iPhone5,2"]) return @"iPhone 5";
    if ([platform isEqualToString:@"iPhone5,3"]) return @"iPhone 5c";
    if ([platform isEqualToString:@"iPhone5,4"]) return @"iPhone 5c";
    if ([platform isEqualToString:@"iPhone6,1"]) return @"iPhone 5s";
    if ([platform isEqualToString:@"iPhone6,2"]) return @"iPhone 5s";
    if ([platform isEqualToString:@"iPhone7,2"]) return @"iPhone 6";
    if ([platform isEqualToString:@"iPhone7,1"]) return @"iPhone 6 Plus";
    if ([platform isEqualToString:@"iPhone8,1"]) return @"iPhone 6s";
    if ([platform isEqualToString:@"iPhone8,2"]) return @"iPhone 6s Plus";
    if ([platform isEqualToString:@"iPhone8,3"]) return @"iPhone SE";
    if ([platform isEqualToString:@"iPhone8,4"]) return @"iPhone SE";
    if ([platform isEqualToString:@"iPhone9,1"]) return @"iPhone 7";
    if ([platform isEqualToString:@"iPhone9,2"]) return @"iPhone 7 Plus";
    if ([platform isEqualToString:@"iPhone10,1"]) return @"iPhone 8";
    if ([platform isEqualToString:@"iPhone10,4"]) return @"iPhone 8";
    if ([platform isEqualToString:@"iPhone10,2"]) return @"iPhone 8 Plus";
    if ([platform isEqualToString:@"iPhone10,5"]) return @"iPhone 8 Plus";
    if ([platform isEqualToString:@"iPhone10,3"]) return @"iPhone X";
    if ([platform isEqualToString:@"iPhone10,6"]) return @"iPhone X";
    
    //iPod Touch
    if ([platform isEqualToString:@"iPod1,1"])   return @"iPod Touch";
    if ([platform isEqualToString:@"iPod2,1"])   return @"iPod Touch 2G";
    if ([platform isEqualToString:@"iPod3,1"])   return @"iPod Touch 3G";
    if ([platform isEqualToString:@"iPod4,1"])   return @"iPod Touch 4G";
    if ([platform isEqualToString:@"iPod5,1"])   return @"iPod Touch 5G";
    if ([platform isEqualToString:@"iPod7,1"])   return @"iPod Touch 6G";
    
    //iPad
    if ([platform isEqualToString:@"iPad1,1"])   return @"iPad";
    if ([platform isEqualToString:@"iPad2,1"])   return @"iPad 2";
    if ([platform isEqualToString:@"iPad2,2"])   return @"iPad 2";
    if ([platform isEqualToString:@"iPad2,3"])   return @"iPad 2";
    if ([platform isEqualToString:@"iPad2,4"])   return @"iPad 2";
    if ([platform isEqualToString:@"iPad3,1"])   return @"iPad 3";
    if ([platform isEqualToString:@"iPad3,2"])   return @"iPad 3";
    if ([platform isEqualToString:@"iPad3,3"])   return @"iPad 3";
    if ([platform isEqualToString:@"iPad3,4"])   return @"iPad 4";
    if ([platform isEqualToString:@"iPad3,5"])   return @"iPad 4";
    if ([platform isEqualToString:@"iPad3,6"])   return @"iPad 4";
    
    //iPad Air
    if ([platform isEqualToString:@"iPad4,1"])   return @"iPad Air";
    if ([platform isEqualToString:@"iPad4,2"])   return @"iPad Air";
    if ([platform isEqualToString:@"iPad4,3"])   return @"iPad Air";
    if ([platform isEqualToString:@"iPad5,3"])   return @"iPad Air2";
    if ([platform isEqualToString:@"iPad5,4"])   return @"iPad Air2";
    
    //iPad mini
    if ([platform isEqualToString:@"iPad2,5"])   return @"iPad mini 1G";
    if ([platform isEqualToString:@"iPad2,6"])   return @"iPad mini 1G";
    if ([platform isEqualToString:@"iPad2,7"])   return @"iPad mini 1G";
    if ([platform isEqualToString:@"iPad4,4"])   return @"iPad mini 2";
    if ([platform isEqualToString:@"iPad4,5"])   return @"iPad mini 2";
    if ([platform isEqualToString:@"iPad4,6"])   return @"iPad mini 2";
    if ([platform isEqualToString:@"iPad4,7"])   return @"iPad mini 3";
    if ([platform isEqualToString:@"iPad4,8"])   return @"iPad mini 3";
    if ([platform isEqualToString:@"iPad4,9"])   return @"iPad mini 3";
    if ([platform isEqualToString:@"iPad5,1"])   return @"iPad mini 4";
    if ([platform isEqualToString:@"iPad5,2"])   return @"iPad mini 4";
    
    if ([platform isEqualToString:@"i386"])      return @"iPhone Simulator";
    if ([platform isEqualToString:@"x86_64"])    return @"iPhone Simulator";
    
    return platform;
}

//通过view获取控制器
+ (UIViewController *)findViewController:(UIView *)view
{
    id target = view;
    while (target) {
        target = ((UIResponder *)target).nextResponder;
        if ([target isKindOfClass:[UIViewController class]]) {
            break;
        }
    }
    
    return target;
}

//获取当前控制器
+ (UIViewController *)getCurrentVC
{
    UIWindow *window = [[UIApplication sharedApplication].windows firstObject];
    if (!window) {
        return nil;
    }
    UIView *tempView;
    for (UIView *subview in window.subviews) {
        if ([[subview.classForCoder description] isEqualToString:@"UILayoutContainerView"]) {
            tempView = subview;
            break;
        }
    }
    if (!tempView) {
        tempView = [window.subviews lastObject];
    }
    
    id nextResponder = [tempView nextResponder];
    while (![nextResponder isKindOfClass:[UIViewController class]] || [nextResponder isKindOfClass:[UINavigationController class]] || [nextResponder isKindOfClass:[UITabBarController class]]) {
        tempView =  [tempView.subviews firstObject];
        
        if (!tempView) {
            return nil;
        }
        nextResponder = [tempView nextResponder];
    }
    
    return (UIViewController *)nextResponder;
}

//删除path路径下的文件
+ (void)clearCachesWithFilePath:(NSString *)path
{
    NSFileManager *mgr = [NSFileManager defaultManager];
    [mgr removeItemAtPath:path error:nil];
}

//获取沙盒Library的文件目录
+ (NSString *)LibraryDirectory
{
    return [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];
}

//获取沙盒Document的文件目录
+ (NSString *)DocumentDirectory
{
    return [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
}

//获取沙盒Preference的文件目录
+ (NSString *)PreferencePanesDirectory
{
    return [NSSearchPathForDirectoriesInDomains(NSPreferencePanesDirectory, NSUserDomainMask, YES) lastObject];
}

//获取沙盒Caches的文件目录
+ (NSString *)CachesDirectory
{
    return [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject];
}

//验证手机号码
+ (BOOL)isMobileNumber:(NSString *)mobileNum
{
    NSString *mobile = @"^0?(13|14|15|16|17|18|19)[0-9]{9}$";
    
    NSPredicate *regextestMobile = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", mobile];
    
    if ([regextestMobile evaluateWithObject:mobileNum] == YES) {
        return YES;
    }else {
        return NO;
    }
}

//验证身份证号码
+ (BOOL)isIdentityCardNumber:(NSString *)number
{
    NSString *cardNum = @"^[1-9]\\d{5}[1-9]\\d{3}((0\\d)|(1[0-2]))(([0|1|2]\\d)|3[0-1])\\d{3}([0-9]|[X|x])";
    
    NSPredicate *identityCardPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", cardNum];
    
    if ([identityCardPredicate evaluateWithObject:number] == YES) {
        return YES;
    }else {
        return NO;
    }
}

//验证香港身份证号码
+ (BOOL)isIdentityHKCardNumber:(NSString *)number
{
    NSString *cardNum = @"^[A-Z]{1,2}[0-9]{6}\\(?[0-9A]\\)?$";
    
    NSPredicate *identityCardPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", cardNum];
    
    if ([identityCardPredicate evaluateWithObject:number] == YES) {
        return YES;
    }else {
        return NO;
    }
}

//验证是否护照
+ (BOOL)isPassportNumber:(NSString *)number
{
    NSString *portNum = @"^1[45][0-9]{7}|([P|p|S|s]\\d{7})|([S|s|G|g]\\d{8})|([Gg|Tt|Ss|Ll|Qq|Dd|Aa|Ff]\\d{8})|([H|h|M|m]\\d{8，10})$";
    NSPredicate *identityCardPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", portNum];
    if ([identityCardPredicate evaluateWithObject:number] == YES) {
        return YES;
    }else {
        return NO;
    }
}

//验证密码格式（包含大写、小写、数字）
+ (BOOL)isConformSXPassword:(NSString *)password
{
    NSString *conText = @"(?=.*[A-Z])(?=.*[a-z])(?=.*[0-9])[a-zA-Z0-9]{6,20}";
    
    NSPredicate *regextestMobile = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", conText];
    
    if ([regextestMobile evaluateWithObject:password] == YES) {
        return YES;
    }else {
        return NO;
    }
}

//计算文字的长度
+ (CGSize)sizeWithText:(NSString *)text font:(UIFont *)font maxSize:(CGSize)maxSize
{
    return [text boundingRectWithSize:maxSize options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:font} context:nil].size;
}

//去掉小数点后无效的0
+ (NSString *)deleteFailureZero:(NSString *)string
{
    if ([string rangeOfString:@"."].length == 0) {
        return string;
    }
    
    for (int i = 0; i < string.length; i++) {
        if (![string hasSuffix:@"0"]) {
            break;
        }else {
            string = [string substringToIndex:[string length] - 1];
        }
    }
    
    //避免像2.0000这样的被解析成2.
    if ([string hasSuffix:@"."]) {
        return [string substringToIndex:[string length] - 1];
    }else {
        return string;
    }
}

//得到中英文混合字符串长度
+ (int)lengthForText:(NSString *)text
{
    int strlength = 0;
    char *p = (char*)[text cStringUsingEncoding:NSUnicodeStringEncoding];
    for (int i=0 ; i < [text lengthOfBytesUsingEncoding:NSUnicodeStringEncoding]; i++) {
        if (*p) {
            p++;
            strlength++;
        }else {
            p++;
        }
    }
    
    return strlength;
}

//提示弹窗
+ (void)showAlertWithTitle:(NSString *)title sureMessage:(NSString *)sureMessage cancelMessage:(NSString *)cancelMessage warningMessage:(NSString *)warningMessage style:(UIAlertControllerStyle)UIAlertControllerStyle target:(id)target sureHandler:(void(^)(UIAlertAction *action))sureHandler cancelHandler:(void(^)(UIAlertAction *action))cancelHandler warningHandler:(void(^)(UIAlertAction *action))warningHandler
{
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title message:nil preferredStyle:UIAlertControllerStyle];
    
    if (sureMessage) {
        UIAlertAction *sureAction = [UIAlertAction actionWithTitle:sureMessage style:UIAlertActionStyleDefault handler:sureHandler];
        [alertController addAction:sureAction];
    }
    
    if (cancelMessage) {
        UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:cancelMessage style:UIAlertActionStyleCancel handler:cancelHandler];
        [alertController addAction:cancelAction];
    }
    
    if (warningMessage) {
        UIAlertAction *warningBtn = [UIAlertAction actionWithTitle:warningMessage style:UIAlertActionStyleDestructive handler:warningHandler];
        [alertController addAction:warningBtn];
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [target presentViewController:alertController animated:YES completion:nil];
    });
}

+ (NSString *)currentTime
{
    NSDate *date = [NSDate date];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateStyle:NSDateFormatterMediumStyle];
    [formatter setTimeStyle:NSDateFormatterShortStyle];
    [formatter setDateFormat:@"YYYY-MM-dd"];
    NSString *DateTime = [formatter stringFromDate:date];
    
    return DateTime;
}

@end
