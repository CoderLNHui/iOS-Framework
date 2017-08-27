//
//  NSMutableDictionary+Dictionary.h
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

@interface NSMutableDictionary (Dictionary)

/*
 *【利用链式编程去实现富文本属性的赋值】
 * @param headerUrl    字体 & 颜色
 */
-(NSMutableDictionary *(^)(CGFloat))Font;
-(NSMutableDictionary *(^)(UIColor *))Color;

@end
