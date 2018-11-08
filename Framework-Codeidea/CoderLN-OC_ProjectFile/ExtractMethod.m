/*
 * ExtractMethod.m  
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#import "ExtractMethod.h"
@implementation ExtractMethod

#pragma mark - 文件路径相关
#pragma mark -获得文件全路径
- (NSString *)fullPath
{
    if (_fullPath == nil) {
        // 拼接文件后的本地名称,url.lastPathComponent 获取URL最后一个字节命名
        _fullPath = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:response.suggestedFilename];
    }
    return _fullPath;
}

#pragma mark -获得指定文件路径对应文件的数据大小
- (NSInteger)getFileSize
{
    NSDictionary *fileInfoDict = [[NSFileManager defaultManager] attributesOfItemAtPath:self.fullPath error:nil];
    NSLog(@"%@",fileInfoDict);
    NSInteger currentSize = [fileInfoDict[@"NSFileSize"] integerValue];
    
    return currentSize;
}

#pragma mark -创建沙盒存储路径文件夹
- (NSString *)createFolderPath
{
    NSString * path = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject stringByAppendingPathComponent:[NSBundle mainBundle].infoDictionary[@"CFBundleName"]];
    
    BOOL isExistDrectory;
    [[NSFileManager defaultManager] fileExistsAtPath:path isDirectory:&isExistDrectory];//判断文件夹是否存在
    if (!isExistDrectory) {
        NSError * error;
        BOOL isExist = [[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:&error];
        if (isExist) {
            NSLog(@"创建沙盒存储路径文件夹成功");
        }
        _folderPath = path;
    } else {
        NSLog(@"该目录已存在");
    }
    return _folderPath;
}






#pragma mark - 截取服务器返回信息字符串(延迟执行,弹框提示用户登录请求结果)
//登录成功或登录失败
- (void)showWithResult:(NSString *)result
{
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
+ (NSString *)dateStringFormNumberString:(NSString *)str
{
    double t = [str doubleValue];
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:t];
    NSDateFormatter *fm = [[NSDateFormatter alloc]init];
    fm.dateFormat = @"yyyy-MM-dd HH:mm:ss";
    return [fm stringFromDate:date];
}

#pragma mark -计算日期间隔
+ (NSString*)calculateDateInterval:(NSString*)expireDateStr
{
    NSDateFormatter *fomatter=[[NSDateFormatter alloc]init];
    [fomatter setDateFormat:@"yyyy-MM-dd HH:mm:ss.0"];
    //把传进来的日期转换为日期
    NSDate *expireDate = [fomatter dateFromString:expireDateStr];
    
    NSTimeInterval interval = [expireDate timeIntervalSinceNow];
    //获取秒数
    NSInteger second = (NSInteger)interval%60;
    NSInteger minute = (NSInteger)interval/60%60;
    NSInteger hour = (NSInteger)interval/60/60;
    NSString *str = [NSString stringWithFormat:@"剩余：%.2d:%.2d:%.2d",hour,minute,second];
    return str;
}

#pragma mark -获得当前时间
+ (void)getCurrentTime
{
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    NSString *dateTime = [formatter stringFromDate:[NSDate date]];
    _startTime = dateTime;
}


#pragma mark - 根据字符串内容 获取（设置）Label的高度(图文混排时用的到)
+ (CGFloat)textHeightFromString:(NSString *)textStr width:(CGFloat)width fontSize:(CGFloat)size
{
    //根据字符串的内容 和固定的宽度来求高度
    NSDictionary *dict = @{NSFontAttributeName:[UIFont systemFontOfSize:size]                                                                                                                                                                                        };
    CGRect frame = [textStr boundingRectWithSize:CGSizeMake(width, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin|NSStringDrawingUsesFontLeading|NSStringDrawingTruncatesLastVisibleLine attributes:dict context:nil];
    
    return frame.size.height;
}


#pragma mark - 快速加载View
+ (instancetype)loadView
{
    return [[[NSBundle mainBundle] loadNibNamed:NSStringFromClass(self) owner:nil options:nil] firstObject];
}


#pragma mark - 设置随机颜色
- (UIColor *)randomColor
{
    CGFloat r = arc4random_uniform(256) / 255.0;
    CGFloat g = arc4random_uniform(256) / 255.0;
    CGFloat b = arc4random_uniform(256) / 255.0;
    return [UIColor colorWithRed:r green:g blue:b alpha:1.0];
}


#pragma mark - Touch触摸
#pragma mark -Touch触摸获取当前手指点
- (CGPoint)getCurrentPoint:(NSSet *)touches
{
    UITouch *touch = [touches anyObject];
    CGPoint curP = [touch locationInView:self];
    return curP;
}

#pragma mark -判断点在不在按钮身上 (如果在按钮身上,返回当前所在的按钮, 如果不在,返回nil)
- (UIButton *)btnRectContainsPoint:(CGPoint)point
{    
    for (UIButton *btn in self.subviews) {
        if (CGRectContainsPoint(btn.frame, point)) {// 判断点在不在Rect范围内(BooL)
            // 让当前按钮成为选中状态 (方法抽取封装不要在内部写死,方便后期复用方法,这里直接返回按钮本身)
            //btn.selected = YES;
            return btn;
        }
    }
    return nil;
}



#pragma mark - 数据安全
#pragma mark -将文件名md5加密
- (NSString *)encryptFileNameWithMD5:(NSString *)str
{
    //要进行UTF8的转码
    const char* input = [str UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(input, (CC_LONG)strlen(input), result);
    
    NSMutableString *digest = [NSMutableString stringWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for (NSInteger i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        [digest appendFormat:@"%02x", result[i]];
    }
    return digest;
}






















@end
