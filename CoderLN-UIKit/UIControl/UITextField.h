/*
 * UITextField.h 
 *
 * UIKit (c) 2005-2017
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

#pragma mark - NS_ENUM枚举
#pragma mark -输入框类型
typedef NS_ENUM(NSInteger, UITextBorderStyle) {
    UITextBorderStyleNone,//没有任何边框
    UITextBorderStyleLine,//线性边框
    UITextBorderStyleBezel,//阴影效果边框
    UITextBorderStyleRoundedRect//原型效果边框
}; //

#pragma mark -设置清除按钮的显示模式
typedef NS_ENUM(NSInteger, UITextFieldViewMode) {
    UITextFieldViewModeNever, //从不显示
    UITextFieldViewModeWhileEditing, //编辑的时候显示
    UITextFieldViewModeUnlessEditing, //非编辑的时候显示
    UITextFieldViewModeAlways //任何时候都显示
}; //

#pragma mark -结束编辑的原因
typedef NS_ENUM(NSInteger, UITextFieldDidEndEditingReason) {
    UITextFieldDidEndEditingReasonCommitted,
    UITextFieldDidEndEditingReasonCancelled UIKIT_AVAILABLE_TVOS_ONLY(10_0)
} NS_ENUM_AVAILABLE_IOS(10_0);



NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextField : UIControl <UITextInput, NSCoding, UIContentSizeCategoryAdjusting>

#pragma mark - 常用属性
#pragma mark -文本框文字
@property(nullable, nonatomic,copy)   NSString               *text;                 // default is nil
#pragma mark -通过AttributedString创建文字
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedText NS_AVAILABLE_IOS(6_0); // default is nil
#pragma mark -文字颜色
@property(nullable, nonatomic,strong) UIColor                *textColor;            // default is nil. use opaque black
#pragma mark -文字大小，默认12
@property(nullable, nonatomic,strong) UIFont                 *font;                 // default is nil. use system font 12 pt
#pragma mark -文字对齐格式，默认NSLeftTextAlignment居左
@property(nonatomic)        NSTextAlignment         textAlignment;        // default is NSLeftTextAlignment
#pragma mark -输入框类型，默认UITextBorderStyleNone
@property(nonatomic)        UITextBorderStyle       borderStyle;          // default is UITextBorderStyleNone. If set to UITextBorderStyleRoundedRect, custom background images are ignored.
#pragma mark -设置默认字体属性
@property(nonatomic,copy)   NSDictionary<NSString *, id>           *defaultTextAttributes NS_AVAILABLE_IOS(7_0); // applies attributes to the full range of text. Unset attributes act like default values.
#pragma mark -设置占位符：灰色
@property(nullable, nonatomic,copy)   NSString               *placeholder;          // default is nil. string is drawn 70% gray
#pragma mark -设置占位符：灰色
@property(nullable, nonatomic,copy)   NSAttributedString     *attributedPlaceholder NS_AVAILABLE_IOS(6_0); // default is nil
#pragma mark -是否在重新开始编辑时清空输入框内容
@property(nonatomic)        BOOL                    clearsOnBeginEditing; // default is NO which moves cursor to location clicked. if YES, all text cleared

#pragma mark -设置字体大小是否随宽度自适应（默认为NO）
@property(nonatomic)        BOOL                    adjustsFontSizeToFitWidth; // default is NO. if YES, text will shrink to minFontSize along baseline
#pragma mark -设置最小收缩字号，adjustsFontSizeToFitWidth is YES
@property(nonatomic)        CGFloat                 minimumFontSize;      // default is 0.0. actual min may be pinned to something readable. used if adjustsFontSizeToFitWidth is YES
#pragma mark -代理
@property(nullable, nonatomic,weak)   id<UITextFieldDelegate> delegate;             // default is nil. weak reference
#pragma mark -设置背景图片（会被拉伸）
@property(nullable, nonatomic,strong) UIImage                *background;           // default is nil. draw in border rect. image should be stretchable
#pragma mark -设置禁用时的背景图片
@property(nullable, nonatomic,strong) UIImage                *disabledBackground;   // default is nil. ignored if background not set. image should be stretchable
#pragma mark -是否正在编辑（只读属性）
@property(nonatomic,readonly,getter=isEditing) BOOL editing;
#pragma mark -是否允许更改字符属性字典
@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // default is NO. allows editing text attributes with style operations and pasting rich text
#pragma mark -设置属性字典
@property(nullable, nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes

// You can supply custom views which are displayed at the left or right
// sides of the text field. Uses for such views could be to show an icon or
// a button to operate on the text in the field in an application-defined
// manner.
//
// A very common use is to display a clear button on the right side of the
// text field, and a standard clear button is provided.
#pragma mark -设置清除按钮的显示模式
@property(nonatomic)        UITextFieldViewMode  clearButtonMode; // sets when the clear button shows up. default is UITextFieldViewModeNever
#pragma mark -设置输入框左边的view
@property(nullable, nonatomic,strong) UIView              *leftView;        // e.g. magnifying glass
#pragma mark -设置输入框左视图的显示模式
@property(nonatomic)        UITextFieldViewMode  leftViewMode;    // sets when the left view shows up. default is UITextFieldViewModeNever
#pragma mark -设置输入框右边的view
@property(nullable, nonatomic,strong) UIView              *rightView;       // e.g. bookmarks button
#pragma mark -设置输入框右视图的显示模式
@property(nonatomic)        UITextFieldViewMode  rightViewMode;   // sets when the right view shows up. default is UITextFieldViewModeNever

// drawing and positioning overrides
#pragma mark - 绘图和定位覆盖（改变Bounds）
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

#pragma mark - 设置输入框成为第一响应时弹出的视图和辅助视图（类似键盘）
@property (nullable, readwrite, strong) UIView *inputView;
@property (nullable, readwrite, strong) UIView *inputAccessoryView;

#pragma mark -设置textView获得焦点，在用户使用虚拟键盘进行输入时，清除之前的文本
@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.

@end

#if TARGET_OS_IOS

@interface UITextField () <UITextDraggable, UITextDroppable, UITextPasteConfigurationSupporting>
@end

#endif

@interface UIView (UITextField)

#pragma mark -注销第一响应（収键盘）
- (BOOL)endEditing:(BOOL)force;    // use to make the view or any subview that is the first responder resign (optionally force)
@end

#pragma mark - UITextFieldDelegate
@protocol UITextFieldDelegate <NSObject>
@optional 可选
#pragma mark -点击输入框时触发的方法，返回YES则可以进入编辑状态，NO则不能。
- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField;        // return NO to disallow editing.

#pragma mark -开始编辑时调用的方法，文本框成为第一响应者。
- (void)textFieldDidBeginEditing:(UITextField *)textField;           // became first responder

#pragma mark -将要结束编辑时调用的方法，返回YES则可以结束编辑状态，NO则不能
- (BOOL)textFieldShouldEndEditing:(UITextField *)textField;          // return YES to allow editing to stop and to resign first responder status. NO to disallow the editing session to end

#pragma mark -结束编辑调用的方法
- (void)textFieldDidEndEditing:(UITextField *)textField;             // may be called if forced even if shouldEndEditing returns NO (e.g. view removed from window) or endEditing:YES called

#pragma mark -结束编辑调用的方法
- (void)textFieldDidEndEditing:(UITextField *)textField reason:(UITextFieldDidEndEditingReason)reason NS_AVAILABLE_IOS(10_0); // if implemented, called in place of textFieldDidEndEditing:

#pragma mark -输入字符时调用的方法 (拦截用户输入)
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;   // return NO to not change text

#pragma mark -点击清除按钮时调用的函数，返回YES则可以清除，NO则不能清除
- (BOOL)textFieldShouldClear:(UITextField *)textField;               // called when clear button pressed. return NO to ignore (no notifications)

#pragma mark -点击return键触发的函数
- (BOOL)textFieldShouldReturn:(UITextField *)textField;              // called when 'return' key pressed. return NO to ignore.

@end

#pragma mark - 监听文本框编辑改变的通知（用于监听键盘的弹出和隐藏）
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidBeginEditingNotification;// 开始编辑
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidEndEditingNotification;// 结束编辑
UIKIT_EXTERN NSNotificationName const UITextFieldTextDidChangeNotification;// 文本改变
UIKIT_EXTERN NSString *const UITextFieldDidEndEditingReasonKey NS_AVAILABLE_IOS(10_0);// 结束编辑的原因（是点击取消结束的，还是失去第一响应者结束的）



