//
//  UIBarButtonItem.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIBarButtonItem.h"

@implementation UIBarButtonItem

- (id)init
{
    if ((self=[super init])) {
        _isSystemItem = NO;
        self.style = UIBarButtonItemStylePlain;
    }
    return self;
}

- (id)initWithBarButtonSystemItem:(UIBarButtonSystemItem)systemItem target:(id)target action:(SEL)action
{
    if ((self=[self init])) {
        _isSystemItem = YES;
        _systemItem = systemItem;
        
        self.target = target;
        self.action = action;
    }
    return self;
}

- (id)initWithCustomView:(UIView *)customView
{
    if ((self=[self init])) {
        self.customView = customView;
    }
    return self;
}

- (id)initWithTitle:(NSString *)title style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action
{
    if ((self=[self init])) {
        self.title = title;
        self.style = style;
        self.target = target;
        self.action = action;
    }
    return self;
}

- (id)initWithImage:(UIImage *)image style:(UIBarButtonItemStyle)style target:(id)target action:(SEL)action
{
    if ((self=[self init])) {
        self.image = image;
        self.style = style;
        self.target = target;
        self.action = action;
    }
    return self;
}


- (UIView *)customView
{
    return _isSystemItem? nil : _customView;
}

- (UIImage *)backButtonBackgroundImageForState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics
{
    return nil;
}

- (void)setBackButtonBackgroundImage:(UIImage *)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics
{
}

- (UIOffset)backButtonTitlePositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics
{
    return UIOffsetZero;
}

- (void)setBackButtonTitlePositionAdjustment:(UIOffset)adjustment forBarMetrics:(UIBarMetrics)barMetrics
{
}

- (CGFloat)backButtonBackgroundVerticalPositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics
{
    return 0;
}

- (void)setBackButtonBackgroundVerticalPositionAdjustment:(CGFloat)adjustment forBarMetrics:(UIBarMetrics)barMetrics
{
}

- (CGFloat)backgroundVerticalPositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics
{
    return 0;
}

- (void)setBackgroundVerticalPositionAdjustment:(CGFloat)adjustment forBarMetrics:(UIBarMetrics)barMetrics
{
}

- (UIImage *)backgroundImageForState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics
{
    return nil;
}

- (void)setBackgroundImage:(UIImage *)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics
{
}

- (UIImage *)backgroundImageForState:(UIControlState)state style:(UIBarButtonItemStyle)style barMetrics:(UIBarMetrics)barMetrics
{
    return nil;
}

- (void)setBackgroundImage:(UIImage *)backgroundImage forState:(UIControlState)state style:(UIBarButtonItemStyle)style barMetrics:(UIBarMetrics)barMetrics
{
}

- (UIOffset)titlePositionAdjustmentForBarMetrics:(UIBarMetrics)barMetrics
{
    return UIOffsetZero;
}

- (void)setTitlePositionAdjustment:(UIOffset)adjustment forBarMetrics:(UIBarMetrics)barMetrics
{
}

@end
