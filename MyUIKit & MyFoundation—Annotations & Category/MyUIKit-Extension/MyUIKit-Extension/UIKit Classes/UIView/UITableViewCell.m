//
//  UITableViewCell.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//  http://www.jianshu.com/p/6dea099c1c3d
/*
 这个UITableViewCell类算是简化版的UITableViewCell，跟系统的UITableViewCell的相比缺少的功能如下：
 1.editing的状态未实现，这里简单说下实现editing的实现思路，用editing标志位控制cell是否处于编辑状态，当实现tableView的编辑的相关代理方法后，将editing置为YES。给UITableViewCell再增加一个子控件view，为删除或增加的view，放在常用子控件的下方，然后给UITableViewCell增加一个手势，当editing为yes的时候，手势生效，左滑可以看到这个删除的view
 2.layoutSubviews方法中还有关于UITableViewCellAccessoryType的判断没有做，当accessoryView未赋值，而UITableViewCellAccessoryType不为UITableViewCellAccessoryNone的时候，显示UITableViewCell自带的accessoryView控件
 3.还有很多枚举的Style没有判断，这些都比较简单。。就不实现了。。无非是在layoutSubviews中加入一些判断和子控件的颜色，位置的设置
 */
#import "UITableViewCell.h"
#import "UITableViewCellSeparator.h"
#import "UIImageView.h"
#import "UILabel.h"
#import "UIColor.h"
#import "UIFont.h"

extern CGFloat _UITableViewDefaultRowHeight;

@implementation UITableViewCell
{
    UITableViewCellStyle _style;
    UITableViewCellSeparator *_seperatorView;
    UIView *_contentView;
    UIImageView *_imageView;
    UILabel *_textLabel;
    UILabel *_detailTextLabel;
}

- (id)initWithFrame:(CGRect)frame
{
    if ((self = [super initWithFrame:frame])) {
        _indentationWidth = 10;
        _style = UITableViewCellStyleDefault;
        _selectionStyle = UITableViewCellSelectionStyleBlue;
        
        _seperatorView = [[UITableViewCellSeparator alloc] init];
        [self addSubview:_seperatorView];
        
        self.accessoryType = UITableViewCellAccessoryNone;
        self.editingAccessoryType = UITableViewCellAccessoryNone;
    }
    return self;
}

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    // 320应该改为手机宽度，大家懂就好了，为了简单，后面的文件默认都会使用320，而不是[UIScreen mainScreen]的宽度
    if ((self = [self initWithFrame:CGRectMake(0,0,320,_UITableViewDefaultRowHeight)])) {
        _style = style;
        _reuseIdentifier = [reuseIdentifier copy];
    }
    return self;
}

#pragma mark - 懒加载子控件
- (UIView *)contentView
{
    if (!_contentView) {
        _contentView = [[UIView alloc] init];
        [self addSubview:_contentView];
        [self layoutIfNeeded];
    }
    
    return _contentView;
}

- (UIImageView *)imageView
{
    if (!_imageView) {
        _imageView = [[UIImageView alloc] init];
        _imageView.contentMode = UIViewContentModeCenter;
        [self.contentView addSubview:_imageView];
        [self layoutIfNeeded];
    }
    
    return _imageView;
}

- (UILabel *)textLabel
{
    if (!_textLabel) {
        _textLabel = [[UILabel alloc] init];
        _textLabel.backgroundColor = [UIColor clearColor];
        _textLabel.textColor = [UIColor blackColor];
        _textLabel.highlightedTextColor = [UIColor whiteColor];
        _textLabel.font = [UIFont boldSystemFontOfSize:17];
        [self.contentView addSubview:_textLabel];
        [self layoutIfNeeded];
    }
    
    return _textLabel;
}

- (UILabel *)detailTextLabel
{
    if (!_detailTextLabel) {
        _detailTextLabel = [[UILabel alloc] init];
        _detailTextLabel = [[UILabel alloc] init];
        _detailTextLabel.backgroundColor = [UIColor clearColor];
        _detailTextLabel.textColor = [UIColor blackColor];
        _detailTextLabel.highlightedTextColor = [UIColor whiteColor];
        _detailTextLabel.font = [UIFont boldSystemFontOfSize:12];
        [self.contentView addSubview:_detailTextLabel];
        [self layoutIfNeeded];
    }
    return _detailTextLabel;
}


- (void)layoutSubviews
{
    [super layoutSubviews];
    
    const CGRect bounds = self.bounds;
    BOOL showingSeperator = !_seperatorView.hidden;
    
    CGRect contentFrame = CGRectMake(0,0,bounds.size.width,bounds.size.height-(showingSeperator? 1 : 0));
    CGRect accessoryRect = CGRectMake(bounds.size.width,0,0,0);
    
    if(_accessoryView) {
        // 计算accessoryView的尺寸和位置
        accessoryRect.size = [_accessoryView sizeThatFits: bounds.size];
        accessoryRect.origin.x = bounds.size.width - accessoryRect.size.width;
        accessoryRect.origin.y = round(0.5*(bounds.size.height - accessoryRect.size.height));
        _accessoryView.frame = accessoryRect;
        [self addSubview: _accessoryView];
        contentFrame.size.width = accessoryRect.origin.x - 1;
    }
    
    _backgroundView.frame = contentFrame;
    _selectedBackgroundView.frame = contentFrame;
    _contentView.frame = contentFrame;
    
    [self sendSubviewToBack:_selectedBackgroundView];
    [self sendSubviewToBack:_backgroundView];
    [self bringSubviewToFront:_contentView];
    [self bringSubviewToFront:_accessoryView];
    
    if (showingSeperator) {
        _seperatorView.frame = CGRectMake(0,bounds.size.height-1,bounds.size.width,1);
        [self bringSubviewToFront:_seperatorView];
    }
    
    // UITableViewCellStyle根据类型调整子控件的位置
    if (_style == UITableViewCellStyleDefault) {
        const CGFloat padding = 5;
        
        const BOOL showImage = (_imageView.image != nil);
        const CGFloat imageWidth = (showImage? 30:0);
        
        _imageView.frame = CGRectMake(padding,0,imageWidth,contentFrame.size.height);
        
        CGRect textRect;
        textRect.origin = CGPointMake(padding+imageWidth+padding,0);
        textRect.size = CGSizeMake(MAX(0,contentFrame.size.width-textRect.origin.x-padding),contentFrame.size.height);
        _textLabel.frame = textRect;
    }
    // 还有其余3种情况就不写了。。跟UITableViewCellStyleDefault的情况差不多，无非是控件的位置和隐藏的情况不太一样
    else if (_style == UITableViewCellStyleValue1)
    {
        
    }
    else if (_style == UITableViewCellStyleValue2)
    {
        
    }
    else if (_style == UITableViewCellStyleSubtitle)
    {
        
    }
}

- (void)_setSeparatorStyle:(UITableViewCellSeparatorStyle)theStyle color:(UIColor *)theColor
{
    [_seperatorView setSeparatorStyle:theStyle color:theColor];
}

// 将子控件全部置为Highlighted状态
- (void)_setHighlighted:(BOOL)highlighted forViews:(id)subviews
{
    for (id view in subviews) {
        if ([view respondsToSelector:@selector(setHighlighted:)]) {
            [view setHighlighted:highlighted];
        }
        [self _setHighlighted:highlighted forViews:[view subviews]];
    }
}

- (void)_updateSelectionState
{
    BOOL shouldHighlight = (_highlighted || _selected);
    _selectedBackgroundView.hidden = !shouldHighlight;
    [self _setHighlighted:shouldHighlight forViews:[self subviews]];
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    if (selected != _selected && _selectionStyle != UITableViewCellSelectionStyleNone) {
        _selected = selected;
        [self _updateSelectionState];
    }
}

- (void)setSelected:(BOOL)selected
{
    [self setSelected:selected animated:NO];
}

- (void)setHighlighted:(BOOL)highlighted animated:(BOOL)animated
{
    if (_highlighted != highlighted && _selectionStyle != UITableViewCellSelectionStyleNone) {
        _highlighted = highlighted;
        [self _updateSelectionState];
    }
}
- (void)setEditing:(BOOL)editing animated:(BOOL)animated
{
    if (_editing != editing && _editingStyle != UITableViewCellEditingStyleNone) {
        _editing = editing;
        [self _updateSelectionState];
    }
}
- (void)setEditing:(BOOL)editing
{
    [self setEditing:editing animated:NO];
}

- (void)setHighlighted:(BOOL)highlighted
{
    [self setHighlighted:highlighted animated:NO];
}

- (void)setBackgroundView:(UIView *)theBackgroundView
{
    if (theBackgroundView != _backgroundView) {
        [_backgroundView removeFromSuperview];
        _backgroundView = theBackgroundView;
        [self addSubview:_backgroundView];
        // 同时设置backgroundView，backgroundColor。。backgroundColor被覆盖
        self.backgroundColor = [UIColor clearColor];
    }
}

- (void)setSelectedBackgroundView:(UIView *)theSelectedBackgroundView
{
    if (theSelectedBackgroundView != _selectedBackgroundView) {
        [_selectedBackgroundView removeFromSuperview];
        _selectedBackgroundView = theSelectedBackgroundView;
        _selectedBackgroundView.hidden = !_selected;
        [self addSubview:_selectedBackgroundView];
    }
}

- (void)prepareForReuse
{
}


@end
