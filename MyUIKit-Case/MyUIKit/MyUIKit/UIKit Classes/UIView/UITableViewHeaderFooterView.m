//
//  UITableViewHeaderFooterView.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/12.
//  Copyright © 2017年 Jack. All rights reserved.
//
/*
 UITableViewHeaderFooterView这个控件的实现原理很简单，跟UITableViewCell非常相似，只不过比UITableViewCell简单很多，只是在contentView上加了个textLabel和
 detailTextLabel过于简单，我就不写了。。相信大家都懂
 */
#import "UITableViewHeaderFooterView.h"

extern CGFloat _UITableViewDefaultHeaderFooterView;

@implementation UITableViewHeaderFooterView

- (instancetype)initWithReuseIdentifier:(NSString *)reuseIdentifier
{
   // 320应该改为手机宽度，大家懂就好了，为了简单，后面的文件默认都会使用320，而不是[UIScreen mainScreen]的宽度
    if ([self = self initWithFrame:CGRectMake(0, 0, 320, _UITableViewDefaultHeaderFooterView)]) {
        _reuseIdentifier = [reuseIdentifier copy];
    }
    
    return self;
}


@end
