//
//  UILabel.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
#import "UIStringDrawing.h"

@class UIFont, UIColor;
@interface UILabel : UIView
- (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines;
- (void)drawTextInRect:(CGRect)rect;

@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *highlightedTextColor;
@property (nonatomic, strong) UIColor *shadowColor;
@property (nonatomic) CGSize shadowOffset;
@property (nonatomic) UITextAlignment textAlignment;
@property (nonatomic) UILineBreakMode lineBreakMode;
@property (nonatomic, getter=isEnabled) BOOL enabled;
@property (nonatomic) NSInteger numberOfLines;					// currently only supports 0 or 1
@property (nonatomic) UIBaselineAdjustment baselineAdjustment;	// not implemented
@property (nonatomic) BOOL adjustsFontSizeToFitWidth;			// not implemented
@property (nonatomic) CGFloat minimumFontSize;					// not implemented
@property (nonatomic, getter=isHighlighted) BOOL highlighted;
@end
