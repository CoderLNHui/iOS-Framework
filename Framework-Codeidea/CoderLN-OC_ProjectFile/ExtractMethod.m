/*
 * ExtractMethod.m  
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import "ExtractMethod.h"
@implementation ExtractMethod

#pragma mark - 文件路径相关
#pragma mark -获得文件全路径
-(NSString *)fullPath {
    if (_fullPath == nil) {
        // 拼接文件后的本地名称 FileName @"123.mp4" 或者 [url lastPathComponent] 获取URL最后一个字节命名
        _fullPath = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"123.mp4"];
    }
    return _fullPath;
}

#pragma mark -获得指定文件路径对应文件的数据大小
-(NSInteger)getFileSize {
    NSDictionary *fileInfoDict = [[NSFileManager defaultManager] attributesOfItemAtPath:self.fullPath error:nil];
    NSLog(@"%@",fileInfoDict);
    NSInteger currentSize = [fileInfoDict[@"NSFileSize"] integerValue];
    
    return currentSize;
}




#pragma mark - 截取服务器返回信息字符串(延迟执行,弹框提示用户登录请求结果)

// 截取服务器返回Data:响应体信息字符串 (延迟执行,弹框提示用户登录请求结果,登录成功或登录失败)
- (void)showWithResult:(NSString *)result {
    
    NSUInteger loc = [result rangeOfString:@":\""].location + 2;
    NSUInteger len =  [result rangeOfString:@"\"}"].location - loc;
    NSString *msg = [result substringWithRange:NSMakeRange(loc, len)];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if ([result containsString:@"error"]) {
            [SVProgressHUD showErrorWithStatus:msg];
        }else {
            [SVProgressHUD showSuccessWithStatus:msg];
        }
    });
    NSLog(@"\n%@",[NSThread currentThread]);
}



#pragma mark - 时间处理
//时间字符串转化为格式为@"yyyy-MM-dd HH:mm:ss"
+ (NSString *)dateStringFormNumberString:(NSString *)str{
    double t = [str doubleValue];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:t];
    NSDateFormatter *fm = [[NSDateFormatter alloc]init];
    fm.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    return [fm stringFromDate:date];
}



+ (NSString*)calculateDateInterval:(NSString*)expireDateStr{
    NSDateFormatter *fomatter=[[NSDateFormatter alloc]init];
    [fomatter setDateFormat:@"yyyy-MM-dd HH:mm:ss.0"];
    //把传进来的日期转换为日期
    NSDate *expireDate=[fomatter dateFromString:expireDateStr];
    
    NSTimeInterval interval=[expireDate timeIntervalSinceNow];
    //获取秒数
    NSInteger second=(NSInteger)interval%60;
    NSInteger minute=(NSInteger)interval/60%60;
    NSInteger hour=(NSInteger)interval/60/60;
    NSString *str=[NSString stringWithFormat:@"剩余：%.2d:%.2d:%.2d",hour,minute,second];
    return str;
}


//获得当前时间
+ (void)getCurrentTime{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    NSString *dateTime = [formatter stringFromDate:[NSDate date]];
    _startTime = dateTime;
}



#pragma mark - 根据字符串内容 获取（设置）Label的高度(图文混排时用的到)
+ (CGFloat)textHeightFromString:(NSString *)textStr width:(CGFloat)width fontSize:(CGFloat)size{
    //根据字符串的内容 和固定的宽度来求高度
    NSDictionary *dict = @{NSFontAttributeName:[UIFont systemFontOfSize:size]                                                                                                                                                                                        };
    CGRect frame = [textStr boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading|NSStringDrawingTruncatesLastVisibleLine attributes:dict context:nil];
    
    return frame.size.height;
}


#pragma mark - 快速加载View
/**
 快速加载View
 */
+ (instancetype)loadView
{
    return [[[NSBundle mainBundle] loadNibNamed:NSStringFromClass(self) owner:nil options:nil] firstObject];
}





@end
