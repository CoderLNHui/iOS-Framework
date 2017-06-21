//
//  NSMutableAttributedString+AttributedString.m
//  ☕️（https://github.com/CustomPBWaters）
//
//  Created by 【Plain Boiled Water ln】 on 15/-/-.
//  Copyright © 2015年（https://custompbwaters.github.io）All rights reserved.
//

#import "NSMutableAttributedString+AttributedString.h"

@implementation NSMutableAttributedString (AttributedString)

/*
 *【快速创建属性字符串】
 * @param string  字符串
 * @param block   返回attributes
 */
+(NSMutableAttributedString *)makeAttributeString:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block
{
    NSMutableDictionary * attributes = [NSMutableDictionary dictionary];
    block(attributes);
    NSMutableAttributedString * as = [[NSMutableAttributedString alloc] initWithString:string attributes:attributes];
    return as;
}


/*
 *【拼接属性字符串】
 * @param string  字符串
 * @param block   返回attributes
 */
-(NSMutableAttributedString *)makeAttributeStringAdd:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block
{
    NSMutableDictionary * attributes = [NSMutableDictionary dictionary];
    block(attributes);
    NSMutableAttributedString * as = [[NSMutableAttributedString alloc] initWithString:string attributes:attributes];
    [self appendAttributedString:as];
    return self;
}


//--------------------------- 【示例】 ------------------------------//
//

/*

- (void)attributedString
{
    //【常用方式】
    NSMutableAttributedString *AttributedStr = [[NSMutableAttributedString alloc]initWithString:@"我是帅锅的帅锅的人"];
    [AttributedStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:16.0] range:NSMakeRange(2, 2)];
    [AttributedStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(2, 2)];
    //    testLabel.attributedText = AttributedStr;
    
    //【封装工具类】
    NSMutableAttributedString * testAS = [NSMutableAttributedString makeAttributeString:@"直接创建" Attribute:^(NSMutableDictionary *attributes) {
        attributes.Font(24).Color([UIColor yellowColor]);
    }];
    [testAS makeAttributeStringAdd:@"拼接新的文字" Attribute:^(NSMutableDictionary *attributes) {
        attributes.Font(12).Color([UIColor redColor]);
    }];
    testLabel.attributedText = testAS;
}

 */



@end

















