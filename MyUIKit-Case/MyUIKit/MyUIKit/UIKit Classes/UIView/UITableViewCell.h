//  UITableViewCell  完全实现ok
//  UITableViewCell.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
typedef NS_ENUM(NSInteger, UITableViewCellAccessoryType) {
    UITableViewCellAccessoryNone,
    UITableViewCellAccessoryDisclosureIndicator,
    UITableViewCellAccessoryDetailDisclosureButton,
    UITableViewCellAccessoryCheckmark
};

typedef NS_ENUM(NSInteger, UITableViewCellSeparatorStyle) {
    UITableViewCellSeparatorStyleNone,
    UITableViewCellSeparatorStyleSingleLine,
    UITableViewCellSeparatorStyleSingleLineEtched
};

typedef NS_ENUM(NSInteger, UITableViewCellStyle) {
    UITableViewCellStyleDefault,
    UITableViewCellStyleValue1,
    UITableViewCellStyleValue2,
    UITableViewCellStyleSubtitle
};

typedef NS_ENUM(NSInteger, UITableViewCellSelectionStyle) {
    UITableViewCellSelectionStyleNone,
    UITableViewCellSelectionStyleBlue,
    UITableViewCellSelectionStyleGray
};

typedef NS_ENUM(NSInteger, UITableViewCellEditingStyle) {
    UITableViewCellEditingStyleNone,
    UITableViewCellEditingStyleDelete,
    UITableViewCellEditingStyleInsert
};

@class UILabel, UIImageView;
@interface UITableViewCell : UIView

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier;
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;
- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
- (void)prepareForReuse;

@property (nonatomic, readonly, strong) UIView *contentView;
@property (nonatomic, readonly, strong) UILabel *textLabel;
@property (nonatomic, readonly, strong) UILabel *detailTextLabel;
@property (nonatomic, readonly, strong) UIImageView *imageView;
@property (nonatomic, strong) UIView *backgroundView;
@property (nonatomic, strong) UIView *selectedBackgroundView;
@property (nonatomic) UITableViewCellSelectionStyle selectionStyle;
@property (nonatomic) NSInteger indentationLevel;
@property (nonatomic) UITableViewCellAccessoryType accessoryType;
@property (nonatomic, strong) UIView *accessoryView;
@property (nonatomic) UITableViewCellAccessoryType editingAccessoryType;
@property (nonatomic, getter=isSelected) BOOL selected;
@property (nonatomic, getter=isHighlighted) BOOL highlighted;
@property (nonatomic, getter=isEditing) BOOL editing; // 未实现
@property (nonatomic, readonly) BOOL showingDeleteConfirmation;  // 未实现
@property (nonatomic, readonly, copy) NSString *reuseIdentifier;
@property (nonatomic, assign) CGFloat indentationWidth; // 10 per default
@property (nonatomic, readonly) UITableViewCellEditingStyle editingStyle;

@end
