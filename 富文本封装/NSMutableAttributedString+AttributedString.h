//
//  NSMutableAttributedString+AttributedString.h
//  ☕️（https://github.com/CustomPBWaters）
//
//  Created by 【Plain Boiled Water ln】 on 15/-/-.
//  Copyright © 2015年（https://custompbwaters.github.io）All rights reserved.
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
