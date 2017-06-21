//
//  NSMutableDictionary+Dictionary.h
//  ☕️（https://github.com/CustomPBWaters）
//
//  Created by 【Plain Boiled Water ln】 on 15/-/-.
//  Copyright © 2015年（https://custompbwaters.github.io）All rights reserved.
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
