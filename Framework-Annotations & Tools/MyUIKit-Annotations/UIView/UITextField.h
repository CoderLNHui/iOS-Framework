/*
 * File:  UITextField.h
 * Framework:  UIKit
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2005-2017
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook: http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextDragging.h>
#import <UIKit/UITextDropping.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UIContentSizeCategoryAdjusting.h>
#import <UIKit/UITextPasteConfigurationSupporting.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage, UIImageView, UILabel, UIColor, UIButton;
@class UITextFieldAtomBackgroundView;
@class UITextFieldBackgroundView;
@class UITextFieldBorderView;
@class UITextFieldLabel;
@class UITextInputTraits;
@class UITextSelectionView;
@class UITextInteractionAssistant;
@class UIPopoverController;
@protocol UITextFieldDelegate;
@protocol UITextSelecting;

typedef NS_ENUM(NSInteger, UITextBorderStyle) {
    UITextBorderStyleNone,//没有任何边框
    UITextBorderStyleLine,//线性边框
    UITextBorderStyleBezel,//阴影效果边框
    UITextBorderStyleRoundedRect//原型效果边框
}; // 输入框类型


typedef NS_ENUM(NSInteger, UITextFieldViewMode) {
    UITextFieldViewModeNever, //从不显示
    UITextFieldViewModeWhileEditing, //编辑的时候显示
    UITextFieldViewModeUnlessEditing, //非编辑的时候显示
    UITextFieldViewModeAlways //任何时候都显示
}; // 设置清除按钮的显示模式

typedef NS_ENUM(NSInteger, UITextFieldDidEndEditingReason) {
    UITextFieldDidEndEditingReasonCommitted,
    UITextFieldDidEndEditingReasonCancelled UIKIT_AVAILABLE_TVOS_ONLY(10_0)
} NS_ENUM_AVAILABLE_IOS(10_0);

NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextField : UIControl <UITextInput, NSCoding, UIContentSizeCategoryAdjusting>

/**
 【文本框文字】
 */
@property(nullable, nonatomic,copy)   NSString               *text;                 // default is nil

/**
【通过AttributedString创建文字】
 */
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedText NS_AVAILABLE_IOS(6_0); // default is nil

/**
 【文字颜色】
 */
@property(nullable, nonatomic,strong) UIColor                *textColor;            // default is nil. use opaque black

/**
 【文字大小，默认12】
 */
@property(nullable, nonatomic,strong) UIFont                 *font;                 // default is nil. use system font 12 pt

/**
 【文字对齐格式，默认NSLeftTextAlignment居左】
 */
@property(nonatomic)        NSTextAlignment         textAlignment;        // default is NSLeftTextAlignment

/**
 【输入框类型，默认UITextBorderStyleNone】
 */
@property(nonatomic)        UITextBorderStyle       borderStyle;          // default is UITextBorderStyleNone. If set to UITextBorderStyleRoundedRect, custom background images are ignored.

/**
【设置默认字体属性】
 */
@property(nonatomic,copy)   NSDictionary<NSString *, id>           *defaultTextAttributes NS_AVAILABLE_IOS(7_0); // applies attributes to the full range of text. Unset attributes act like default values.

/**
 【设置占位符：灰色】
 */
@property(nullable, nonatomic,copy)   NSString               *placeholder;          // default is nil. string is drawn 70% gray

/**
 【设置占位符：灰色】
 */
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedPlaceholder NS_AVAILABLE_IOS(6_0); // default is nil

/**
 【是否在开始编辑时清空输入框内容】
 */
@property(nonatomic)        BOOL                    clearsOnBeginEditing; // default is NO which moves cursor to location clicked. if YES, all text cleared

/**
 【设置字体大小是否随宽度自适应（默认为NO）】
 */
@property(nonatomic)        BOOL                    adjustsFontSizeToFitWidth; // default is NO. if YES, text will shrink to minFontSize along baseline

/**
 【设置最小收缩字号，adjustsFontSizeToFitWidth is YES】
 */
@property(nonatomic)        CGFloat                 minimumFontSize;      // default is 0.0. actual min may be pinned to something readable. used if adjustsFontSizeToFitWidth is YES


@property(nullable, nonatomic,weak)   id<UITextFieldDelegate> delegate;             // default is nil. weak reference



/**
 【设置背景图片（会被拉伸）】
 */
@property(nullable, nonatomic,strong) UIImage                *background;           // default is nil. draw in border rect. image should be stretchable

/**
 【设置禁用时的背景图片】
 */
@property(nullable, nonatomic,strong) UIImage                *disabledBackground;   // default is nil. ignored if background not set. image should be stretchable


/**
 【是否正在编辑（只读属性）】
 */
@property(nonatomic,readonly,getter=isEditing) BOOL editing;


/**
 【是否允许更改字符属性字典】
 */
@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // default is NO. allows editing text attributes with style operations and pasting rich text

/**
【设置属性字典】
 */
@property(nullable, nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes


// You can supply custom views which are displayed at the left or right
// sides of the text field. Uses for such views could be to show an icon or
// a button to operate on the text in the field in an application-defined
// manner.
//
// A very common use is to display a clear button on the right side of the
// text field, and a standard clear button is provided.

/**
 【设置清除按钮的显示模式】
 */
@property(nonatomic)        UITextFieldViewMode  clearButtonMode; // sets when the clear button shows up. default is UITextFieldViewModeNever

/**
 【设置输入框左边的view】
 */
@property(nullable, nonatomic,strong) UIView              *leftView;        // e.g. magnifying glass


/**
 【设置输入框左视图的显示模式】
 */
@property(nonatomic)        UITextFieldViewMode  leftViewMode;    // sets when the left view shows up. default is UITextFieldViewModeNever


/**
 【设置输入框右边的view】
 */
@property(nullable, nonatomic,strong) UIView              *rightView;       // e.g. bookmarks button

/**
 【设置输入框右视图的显示模式】
 */
@property(nonatomic)        UITextFieldViewMode  rightViewMode;   // sets when the right view shows up. default is UITextFieldViewModeNever

// drawing and positioning overrides

- (CGRect)borderRectForBounds:(CGRect)bounds;
- (CGRect)textRectForBounds:(CGRect)bounds;
- (CGRect)placeholderRectForBounds:(CGRect)bounds;
- (CGRect)editingRectForBounds:(CGRect)bounds;
- (CGRect)clearButtonRectForBounds:(CGRect)bounds;
- (CGRect)leftViewRectForBounds:(CGRect)bounds;
- (CGRect)rightViewRectForBounds:(CGRect)bounds;

- (void)drawTextInRect:(CGRect)rect;
- (void)drawPlaceholderInRect:(CGRect)rect;





// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
/**
 【设置输入框成为第一响应时弹出的视图和辅助视图（类似键盘）】
 */
@property (nullable, readwrite, strong) UIView *inputView;
@property (nullable, readwrite, strong) UIView *inputAccessoryView;

/**
 【这个属性设置是否允许再次编辑时在内容中间插入内容】
 */
@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.

@end

#if TARGET_OS_IOS

@interface UITextField () <UITextDraggable, UITextDroppable, UITextPasteConfigurationSupporting>
@end

#endif

@interface UIView (UITextField)
/**
 【注销第一响应（収键盘）】
 */
- (BOOL)endEditing:(BOOL)force;    // use to make the view or any subview that is the first responder resign (optionally force)
@end

@protocol UITextFieldDelegate <NSObject>

@optional【可选】
#pragma mark ------------------
#pragma mark -【UITextFieldDelegate】

/**
 【点击输入框时触发的方法，返回YES则可以进入编辑状态，NO则不能。】
 */
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        // return NO to disallow editing.
/**
 【开始编辑时调用的方法】
 */
- (void)textFieldDidBeginEditing:(UITextField *)textField;           // became first responder


/**
 【将要结束编辑时调用的方法，返回YES则可以结束编辑状态，NO则不能】
 */
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          // return YES to allow editing to stop and to resign first responder status. NO to disallow the editing session to end
/**
 【结束编辑调用的方法】
 */
- (void)textFieldDidEndEditing:(UITextField *)textField;             // may be called if forced even if shouldEndEditing returns NO (e.g. view removed from window) or endEditing:YES called

/**
 【输入字符时调用的方法】
 */
- (void)textFieldDidEndEditing:(UITextField *)textField reason:(UITextFieldDidEndEditingReason)reason NS_AVAILABLE_IOS(10_0); // if implemented, called in place of textFieldDidEndEditing:

/**
 【输入字符时调用的方法】
 */
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   // return NO to not change text

/**
 【点击清除按钮时调用的函数，返回YES则可以清除，点击NO则不能清除】
 */
- (BOOL)textFieldShouldClear:(UITextField *)textField;               // called when clear button pressed. return NO to ignore (no notifications)

/**
 【点击return键触发的函数】
 */
- (BOOL)textFieldShouldReturn:(UITextField *)textField;              // called when 'return' key pressed. return NO to ignore.

@end

UIKIT_EXTERN NSNotificationName const UITextFieldTextDidBeginEditingNotification;
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidEndEditingNotification;
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidChangeNotification;

UIKIT_EXTERN NSString *const UITextFieldDidEndEditingReasonKey NS_AVAILABLE_IOS(10_0);

#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END


