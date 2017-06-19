//
//  UIBarItem.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIBarItem.h"

@implementation UIBarItem

- (id)init
{
    if ((self = [super init])) {
        self.enabled = YES;
        self.imageInsets = UIEdgeInsetsZero;
    }
    return self;
}


- (void)setTitleTextAttributes:(NSDictionary *)attributes forState:(UIControlState)state
{
    
}

- (NSDictionary *)titleTextAttributesForState:(UIControlState)state
{
    return nil;
}

@end
