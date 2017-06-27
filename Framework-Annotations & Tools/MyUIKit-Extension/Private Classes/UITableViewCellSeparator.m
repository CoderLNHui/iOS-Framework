//
//  UITableViewCellSeparator.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UITableViewCellSeparator.h"
#import "UIColor.h"

@implementation UITableViewCellSeparator
{
    UITableViewCellSeparatorStyle _style;
    UIColor *_color;
}

- (id)initWithFrame:(CGRect)frame
{
    if ((self=[super initWithFrame:frame])) {
        _style = UITableViewCellSeparatorStyleNone;
        self.hidden = YES;
    }
    return self;
}

- (void)setSeparatorStyle:(UITableViewCellSeparatorStyle)theStyle color:(UIColor *)theColor
{
    if (_style != theStyle) {
        _style = theStyle;
        [self setNeedsDisplay];
    }
    
    if (_color != theColor) {
        _color = theColor;
        [self setNeedsDisplay];
    }
    
    self.hidden = (_style == UITableViewCellSeparatorStyleNone);
}

- (void)drawRect:(CGRect)rect
{
    if (_color) {
        if (_style == UITableViewCellSeparatorStyleSingleLine) {
            [_color setFill];
            CGContextFillRect(UIGraphicsGetCurrentContext(),CGRectMake(0,0,self.bounds.size.width,1));
        }
    }
}


@end
