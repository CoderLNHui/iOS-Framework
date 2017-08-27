//
//  NSMutableAttributedString+AttributedString.h
//  白开水ln（https://github.com/CustomPBWaters）
//
//  Created by 【WechatPublic-Codeidea】 on Elegant programming16.
//  Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
//
//  http://www.jianshu.com/u/fd745d76c816
//
//  @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
//

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
