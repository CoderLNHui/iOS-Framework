/*
 * NSDictionary+LNDictionary.h
 *
 * Foundation
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>

@interface NSDictionary (LNDictionary)


#pragma mark - 利用链式编程去实现富文本属性的赋值
//字体 & 颜色
-(NSMutableDictionary *(^)(CGFloat))Font;
-(NSMutableDictionary *(^)(UIColor *))Color;


#pragma mark - 字典转模型KVC实现(自动生成模型属性代码)
- (void)ln_createPropertyCode;





#pragma mark - 字典转模型示例:本地Plist文件
/**

 NSString *filePath = [[NSBundle mainBundle] pathForResource:@"status.plist" ofType:nil];
 NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:filePath];
 
 // 字典转模型,生成属性代码 => dict
 [dict createPropertyCode];
 
 
 打印输出:
 2015-03-04 15:27:23.767 字典转模型-自动生成属性代码 [5227:154068]
 @property (nonatomic, strong) NSString *source;
 
 @property (nonatomic, assign) NSInteger reposts_count;
 
 @property (nonatomic, strong) NSArray *pic_urls;
 
 @property (nonatomic, strong) NSString *created_at;
 
 @property (nonatomic, assign) BOOL isA;
 
 @property (nonatomic, assign) NSInteger attitudes_count;
 
 @property (nonatomic, strong) NSString *idstr;
 
 @property (nonatomic, strong) NSString *text;
 
 @property (nonatomic, assign) NSInteger comments_count;
 
 @property (nonatomic, strong) NSDictionary *user;
 */


@end
