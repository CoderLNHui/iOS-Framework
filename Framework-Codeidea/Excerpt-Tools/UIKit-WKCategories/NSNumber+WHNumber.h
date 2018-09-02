//
//  NSNumber+WHNumber.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <Foundation/Foundation.h>

@interface NSNumber (WHNumber)

/** 返回自己对应的罗马数字 */
- (NSString *)romanNumeral;

/* 展示 */
- (NSString*)toDisplayNumberWithDigit:(NSInteger)digit;
- (NSString*)toDisplayPercentageWithDigit:(NSInteger)digit;

/*　四舍五入 */
/**
 *  @brief  四舍五入
 *
 *  @param digit  限制最大位数
 *
 *  @return 结果
 */
- (NSNumber*)doRoundWithDigit:(NSUInteger)digit;

/**
 *  @brief  取上整
 *
 *  @param digit  限制最大位数
 *
 *  @return 结果
 */
- (NSNumber*)doCeilWithDigit:(NSUInteger)digit;

/**
 *  @brief  取下整
 *
 *  @param digit  限制最大位数
 *
 *  @return 结果
 */
- (NSNumber*)doFloorWithDigit:(NSUInteger)digit;


@end
