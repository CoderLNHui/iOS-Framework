//
//  UITextField+JKInputLimit.h
//  JKCategories (https://github.com/shaojiankui/JKCategories)
//
//  Created by Jakey on 2016/11/29.
//  Copyright (c) 2016年 www.skyfox.org. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (JKInputLimit)
@property (assign, nonatomic)  NSInteger jk_maxLength;//if <=0, no limit
@end
