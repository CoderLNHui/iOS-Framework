//  完全实现ok
//  UITableViewHeaderFooterView.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/12.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
#import "UILabel.h"

@interface UITableViewHeaderFooterView : UIView

- (instancetype)initWithReuseIdentifier:(nullable NSString *)reuseIdentifier NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, null_resettable) UIColor *tintColor;

@property (nonatomic, readonly, strong, nullable) UILabel *textLabel;
@property (nonatomic, readonly, strong, nullable) UILabel *detailTextLabel; // only supported for headers in grouped style

@property (nonatomic, readonly, strong) UIView *contentView;
@property (nonatomic, strong, nullable) UIView *backgroundView;

@property (nonatomic, readonly, copy, nullable) NSString *reuseIdentifier;

- (void)prepareForReuse;  // if the view is reusable (has a reuse identifier), this is called just before the view is returned from the table view method dequeueReusableHeaderFooterViewWithIdentifier:.  If you override, you MUST call super.



@end
