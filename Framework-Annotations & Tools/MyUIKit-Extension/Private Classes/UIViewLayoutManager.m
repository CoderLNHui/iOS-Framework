//
//  UIViewLayoutManager.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIViewLayoutManager.h"
#import "UIView+UIPrivate.h"
#import <QuartzCore/CALayer.h>

static UIViewLayoutManager *theLayoutManager = nil;

@implementation UIViewLayoutManager

+ (void)initialize
{
    if (self == [UIViewLayoutManager class]) {
        theLayoutManager = [[self alloc] init];
    }
}

+ (UIViewLayoutManager *)layoutManager
{
    return theLayoutManager;
}

- (void)layoutSublayersOfLayer:(CALayer *)theLayer
{
    UIView *view = (UIView *)[theLayer delegate];
    [view _layoutSubviews];
}

@end
