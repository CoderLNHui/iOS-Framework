/*
 * UIControl+Control.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <UIKit/UIKit.h>

@interface UIControl (Control)

@end


@interface UIControl (Delay)

/** 每次响应的间隔 */
@property (assign, nonatomic) NSTimeInterval acceptEventInterval;

@end
