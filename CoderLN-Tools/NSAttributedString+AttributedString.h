/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>

@interface NSMutableAttributedString (LNAttributedString)

//结合 NSDictionary+Dictionary.h【利用链式编程去实现富文本属性的赋值】使用
#pragma mark - 快速创建属性字符串
/*
 * @param string  字符串
 * @param block   返回attributes
 */
+(NSMutableAttributedString *)ln_makeAttributeString:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block;

#pragma mark - 拼接属性字符串
/*
 * @param string  字符串
 * @param block   返回attributes
 */
-(NSMutableAttributedString *)ln_makeAttributeStringAdd:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block;

@end

