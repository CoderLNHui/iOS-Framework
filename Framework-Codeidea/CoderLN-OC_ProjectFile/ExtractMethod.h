/*
 * ExtractMethod.h
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 作用：常用方法抽取封装 - 阶段总结
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
@interface ExtractMethod : NSObject

#pragma mark - 文件路径相关
#pragma mark -获得文件全路径
-(NSString *)fullPath;
#pragma mark -获得指定文件路径对应文件的数据大小
-(NSInteger)getFileSize;


#pragma mark - 弹框提示用户登录请求结果
#pragma mark -截取服务器返回Data:响应体信息字符串 (延迟执行,弹框提示用户登录请求结果,登录成功或登录失败)
- (void)showWithResult:(NSString *)result;


#pragma mark - 时间处理
#pragma mark -把一个数字时间串转化为date格式的字符串
+(NSString *)dateStringFormNumberString:(NSString *)str;

#pragma mark -获得当前时间
+ (void)getCurrentTime;

#pragma mark -
+(NSString*)calculateDateInterval:(NSString*)expireDateStr;


#pragma mark - 根据字符串内容 获取Label的高度
+(CGFloat)textHeightFromString:(NSString *)textStr width:(CGFloat)width fontSize:(CGFloat)size;


#pragma mark - 快速加载View
+ (instancetype)loadView;





















































@end




































