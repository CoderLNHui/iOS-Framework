//  完全实现ok  UITableViewCellSeparator  这个类其实就是高度为1的分割线
//  UITableViewCellSeparator.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
#import "UITableViewCell.h"

@class UIColor;

@interface UITableViewCellSeparator : UIView

- (void)setSeparatorStyle:(UITableViewCellSeparatorStyle)theStyle color:(UIColor *)theColor;

@end
