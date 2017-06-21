//
//  NSMutableDictionary+Dictionary.m
//  ☕️（https://github.com/CustomPBWaters）
//
//  Created by 【Plain Boiled Water ln】 on 15/-/-.
//  Copyright © 2015年（https://custompbwaters.github.io）All rights reserved.
//

#import "NSMutableDictionary+Dictionary.h"


@implementation NSMutableDictionary (Dictionary)

/*
 *【利用链式编程去实现富文本属性的赋值】
 * @param headerUrl    字体 & 颜色
 */
-(NSMutableDictionary *(^)(CGFloat))Font
{
    return ^id(CGFloat font)
    {
        [self setValue:[UIFont systemFontOfSize:font] forKey:NSFontAttributeName];
        return self;
    };
}

-(NSMutableDictionary *(^)(UIColor *))Color
{
    return ^id(UIColor * color)
    {
        [self setValue:color forKey:NSForegroundColorAttributeName];
        return self;
    };
}



@end








