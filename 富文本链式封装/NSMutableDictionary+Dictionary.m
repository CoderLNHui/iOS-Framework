//
//  NSMutableDictionary+Dictionary.m
//  🔍白开水ln（https://github.com/CustomPBWaters）
//
//  Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
//  Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
//
//  @PBWLN_LICENSE_HEADER_END@
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








