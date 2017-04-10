//
//  UITextField.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/10.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIControl.h"
#import "UITextInput.h"
#import "UIStringDrawing.h"

extern NSString *const UITextFieldTextDidBeginEditingNotification;
extern NSString *const UITextFieldTextDidChangeNotification;
extern NSString *const UITextFieldTextDidEndEditingNotification;

typedef NS_ENUM(NSInteger, UITextBorderStyle) {
    UITextBorderStyleNone,
    UITextBorderStyleLine,
    UITextBorderStyleBezel,
    UITextBorderStyleRoundedRect
};

typedef NS_ENUM(NSInteger, UITextFieldViewMode) {
    UITextFieldViewModeNever,
    UITextFieldViewModeWhileEditing,
    UITextFieldViewModeUnlessEditing,
    UITextFieldViewModeAlways
};

@class UIFont, UIColor, UITextField, UIImage;

@protocol UITextFieldDelegate <NSObject>
@optional
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;
- (void)textFieldDidBeginEditing:(UITextField *)textField;
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;
- (void)textFieldDidEndEditing:(UITextField *)textField;

- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;
- (BOOL)textFieldShouldClear:(UITextField *)textField;
- (BOOL)textFieldShouldReturn:(UITextField *)textField;
@end


@interface UITextField : UIControl <UITextInput>
- (CGRect)borderRectForBounds:(CGRect)bounds;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (CGRect)leftViewRectForBounds:(CGRect)bounds;
- (CGRect)placeholderRectForBounds:(CGRect)bounds;
- (CGRect)rightViewRectForBounds:(CGRect)bounds;
- (CGRect)textRectForBounds:(CGRect)bounds;

- (void)drawPlaceholderInRect:(CGRect)rect;
- (void)drawTextInRect:(CGRect)rect;

@property (nonatomic, assign) id<UITextFieldDelegate> delegate;
@property (nonatomic, assign) UITextAlignment textAlignment;
@property (nonatomic, copy) NSString *placeholder;
@property (nonatomic, copy) NSString *text;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic) UITextBorderStyle borderStyle;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, readonly, getter=isEditing) BOOL editing;
@property (nonatomic) BOOL clearsOnBeginEditing;
@property (nonatomic) BOOL adjustsFontSizeToFitWidth;
@property (nonatomic) CGFloat minimumFontSize;

@property (nonatomic, strong) UIImage *background;
@property (nonatomic, strong) UIImage *disabledBackground;

@property (nonatomic) UITextFieldViewMode clearButtonMode;
@property (nonatomic, strong) UIView *leftView;
@property (nonatomic) UITextFieldViewMode leftViewMode;
@property (nonatomic, strong) UIView *rightView;
@property (nonatomic) UITextFieldViewMode rightViewMode;

@property (readwrite, strong) UIView *inputAccessoryView;
@property (readwrite, strong) UIView *inputView;

@end

@interface UIView (UITextField)
- (BOOL)endEditing:(BOOL)force;
@end
