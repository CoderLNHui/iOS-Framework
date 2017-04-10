//
//  UITableViewSectionLabel.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/10.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UITableViewSectionLabel.h"
#import "UIFont.h"
#import "UIColor.h"

@implementation UITableViewSectionLabel
+ (UITableViewSectionLabel *)sectionLabelWithTitle:(NSString *)title
{
    UITableViewSectionLabel *label = [[self alloc] init];
    label.text = [NSString stringWithFormat:@"  %@", title];
    label.font = [UIFont boldSystemFontOfSize:17];
    label.textColor = [UIColor whiteColor];
    label.shadowColor = [UIColor colorWithRed:100/255.f green:105/255.f blue:110/255.f alpha:1];
    label.shadowOffset = CGSizeMake(0,1);
    return label;
}

- (void)drawRect:(CGRect)rect
{
    const CGSize size = self.bounds.size;
    
    [[UIColor colorWithRed:166/255.f green:177/255.f blue:187/255.f alpha:1] setFill];
    UIRectFill(CGRectMake(0.f, 0.f, size.width, 1.f));
    
    UIColor *startColor = [UIColor colorWithRed:145/255.f green:158/255.f blue:171/255.f alpha:1];
    UIColor *endColor = [UIColor colorWithRed:185/255.f green:193/255.f blue:201/255.f alpha:1];
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGFloat locations[2] = {0.f, 1.f};
    const void *colors[2] = {startColor.CGColor, endColor.CGColor};
    CFArrayRef gradientColors = CFArrayCreate(NULL, colors, 2, NULL);
    CGGradientRef gradient = CGGradientCreateWithColors(colorSpace, gradientColors, locations);
    CGColorSpaceRelease(colorSpace);
    CGContextDrawLinearGradient(UIGraphicsGetCurrentContext(), gradient, CGPointMake(0.f, 1.f), CGPointMake(0.f, size.height - 1.f), 0);
    CGGradientRelease(gradient);
    CFRelease(gradientColors);
    [[UIColor colorWithRed:153/255.f green:158/255.f blue:165/255.f alpha:1] setFill];
    UIRectFill(CGRectMake(0.f, size.height - 1.f, size.width, 1.f));
    [super drawRect:rect];
}

@end
