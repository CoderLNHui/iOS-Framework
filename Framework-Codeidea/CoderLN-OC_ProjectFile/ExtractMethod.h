/*
 * ExtractMethod.h 常用方法抽取封装
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>
@interface ExtractMethod : NSObject

#pragma mark - 文件路径相关
#pragma mark -获得文件全路径
- (NSString *)fullPath;
#pragma mark -获得指定文件路径对应文件的数据大小
- (NSInteger)getFileSize;
#pragma mark -创建沙盒存储路径文件夹
- (NSString *)createFolderPath;


#pragma mark - 弹框提示用户登录请求结果
#pragma mark -截取服务器返回Data:响应体信息字符串 (延迟执行,弹框提示用户登录请求结果,登录成功或登录失败)
- (void)showWithResult:(NSString *)result;


#pragma mark - 时间处理
#pragma mark -把一个数字时间串转化为date格式的字符串
+ (NSString *)dateStringFormNumberString:(NSString *)str;
#pragma mark -获得当前时间
+ (void)getCurrentTime;
#pragma mark -计算日期间隔
+ (NSString*)calculateDateInterval:(NSString*)expireDateStr;


#pragma mark - 根据字符串内容 获取Label的高度
+ (CGFloat)textHeightFromString:(NSString *)textStr width:(CGFloat)width fontSize:(CGFloat)size;

#pragma mark - 快速加载View
+ (instancetype)loadView;

#pragma mark - 设置随机颜色
- (UIColor *)randomColor;


#pragma mark - Touch触摸
#pragma mark -Touch触摸获取当前手指点
- (CGPoint)getCurrentPoint:(NSSet *)touches;
#pragma mark -判断点在不在按钮身上 (如果在按钮身上,返回当前所在的按钮, 如果不在,返回nil)
- (UIButton *)btnRectContainsPoint:(CGPoint)point;


#pragma mark - 数据安全
#pragma mark -将文件名md5加密
- (NSString *)encryptFileNameWithMD5:(NSString *)str;










































@end




































