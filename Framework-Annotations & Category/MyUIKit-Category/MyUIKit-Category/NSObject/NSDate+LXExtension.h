
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LXDateItem : NSObject
@property (nonatomic, assign) NSInteger day;
@property (nonatomic, assign) NSInteger hour;
@property (nonatomic, assign) NSInteger minute;
@property (nonatomic, assign) NSInteger second;
@end

@interface NSDate (LXExtension)
- (LXDateItem *)lx_timeIntervalSinceDate:(NSDate *)anotherDate;

- (BOOL)lx_isToday;
- (BOOL)lx_isYesterday;
- (BOOL)lx_isTomorrow;
- (BOOL)lx_isThisYear;
//获取今天周几
- (NSInteger)getNowWeekday;
@end
