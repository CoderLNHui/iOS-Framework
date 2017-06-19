//
//  UIView+Frame.m
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import "UIView+Frame.h"

@implementation UIView (Frame)


//--------------------------- 【UIView扩展属性】 ------------------------------//
//
- (void)setLn_width:(CGFloat)ln_width
{
    CGRect rect = self.frame;
    rect.size.width = ln_width;
    self.frame = rect;
}

- (void)setLn_height:(CGFloat)ln_height
{
    CGRect rect = self.frame;
    rect.size.height = ln_height;
    self.frame = rect;
}

-(CGFloat)ln_width
{
    return self.frame.size.width;
}

- (CGFloat)ln_height
{
    return self.frame.size.height;
}

- (void)setLn_x:(CGFloat)ln_x
{
    CGRect rect = self.frame;
    rect.origin.x = ln_x;
    self.frame = rect;
}

- (void)setLn_y:(CGFloat)ln_y
{
    CGRect rect = self.frame;
    rect.origin.y = ln_y;
    self.frame = rect;
}


- (CGFloat)ln_x
{
    return self.frame.origin.x;
}

- (CGFloat)ln_y
{
    return self.frame.origin.y;
}


-(void)setLn_centerX:(CGFloat)ln_centerX {
    CGPoint center = self.center;
    center.x = ln_centerX;
    self.center = center;
}

- (void)setLn_centerY:(CGFloat)ln_centerY {
    CGPoint center = self.center;
    center.y = ln_centerY;
    self.center = center;
}

- (CGFloat)ln_centerX {
    return self.center.x;
}

- (CGFloat)ln_centerY {
    return self.center.y;
}


/*
 *【快速加载View对应的Xib】
 */
+ (instancetype)ln_ViewFromNib
{
    return [[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:nil options:nil].firstObject;
}


/**
 * 【判断self和view是否重叠】
 */
- (BOOL)ln_intersectsWithView:(UIView *)view
{
    //都先转换为相对于窗口的坐标，然后进行判断是否重合
    CGRect selfRect = [self convertRect:self.bounds toView:nil];
    CGRect viewRect = [view convertRect:view.bounds toView:nil];
    return CGRectIntersectsRect(selfRect, viewRect);
}

@end
