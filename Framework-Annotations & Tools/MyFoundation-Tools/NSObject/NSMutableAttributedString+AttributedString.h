/*
 * NSMutableAttributedString+AttributedString.h
 * 🔍白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <Foundation/Foundation.h>

@interface NSMutableAttributedString (AttributedString)

//--------------------------- <#我是分割线#> ------------------------------//
// 结合 NSDictionary+Dictionary.h【利用链式编程去实现富文本属性的赋值】使用
/*
 *【快速创建属性字符串】
 * @param string  字符串
 * @param block   返回attributes
 */
+(NSMutableAttributedString *)makeAttributeString:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block;

/*
 *【拼接属性字符串】
 * @param string  字符串
 * @param block   返回attributes
 */
-(NSMutableAttributedString *)makeAttributeStringAdd:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block;

@end
