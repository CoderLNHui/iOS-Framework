/*
 * NSMutableAttributedString+AttributedString.h
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>

@interface NSMutableAttributedString (AttributedString)


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
