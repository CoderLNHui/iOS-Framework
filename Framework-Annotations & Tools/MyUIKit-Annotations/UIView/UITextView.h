/*
 * File:  UITextView.h
 * Framework:  UIKit
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2007-2017
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
#import <UIKit/UIScrollView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UITextDragging.h>
#import <UIKit/UITextDropping.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDataDetectors.h>
#import <UIKit/UITextInteraction.h>
#import <UIKit/UIContentSizeCategoryAdjusting.h>
#import <UIKit/UITextPasteConfigurationSupporting.h>

NS_ASSUME_NONNULL_BEGIN

@class UIFont, UIColor, UITextView, NSTextContainer, NSLayoutManager, NSTextStorage, NSTextAttachment;


#pragma mark ------------------
#pragma mark -【UITextViewDelegate】
@protocol UITextViewDelegate <NSObject, UIScrollViewDelegate>

@optional

/**
【是否允许 开始、结束 编辑】
 */
- (BOOL)textViewShouldBeginEditing:(UITextView *)textView;
- (BOOL)textViewShouldEndEditing:(UITextView *)textView;




//【点击文本框开始编辑时调用】
- (void)textViewDidBeginEditing:(UITextView *)textView;

//【输入字符时调用】
- (void)textViewDidChange:(UITextView *)textView;

//【文本框结束编辑时调用】
- (void)textViewDidEndEditing:(UITextView *)textView;



/**
 【是否允许改变文本框内容(拦截用户输入)】
 */
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

/**
 【选中内容改变】
 */
- (void)textViewDidChangeSelection:(UITextView *)textView;



/**
 <#注解#>
 */
- (BOOL)textView:(UITextView *)textView shouldInteractWithURL:(NSURL *)URL inRange:(NSRange)characterRange interaction:(UITextItemInteraction)interaction NS_AVAILABLE_IOS(10_0);
- (BOOL)textView:(UITextView *)textView shouldInteractWithTextAttachment:(NSTextAttachment *)textAttachment inRange:(NSRange)characterRange interaction:(UITextItemInteraction)interaction NS_AVAILABLE_IOS(10_0);

- (BOOL)textView:(UITextView *)textView shouldInteractWithURL:(NSURL *)URL inRange:(NSRange)characterRange NS_DEPRECATED_IOS(7_0, 10_0, "Use textView:shouldInteractWithURL:inRange:forInteractionType: instead");
- (BOOL)textView:(UITextView *)textView shouldInteractWithTextAttachment:(NSTextAttachment *)textAttachment inRange:(NSRange)characterRange NS_DEPRECATED_IOS(7_0, 10_0, "Use textView:shouldInteractWithTextAttachment:inRange:forInteractionType: instead");

@end




#pragma mark ------------------
#pragma mark -【UITextView】
NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextView : UIScrollView <UITextInput, UIContentSizeCategoryAdjusting>

@property(nullable,nonatomic,weak) id<UITextViewDelegate> delegate;

@property(null_resettable,nonatomic,copy) NSString *text;// 文字
@property(nullable,nonatomic,strong) UIFont *font;// 字体大小
@property(nullable,nonatomic,strong) UIColor *textColor;// 字体颜色
@property(nonatomic) NSTextAlignment textAlignment; // 对齐样式   // default is NSLeftTextAlignment
@property(nonatomic) NSRange selectedRange;// 选中内容范围
/**
【是否允许编辑内容，输入】
 */
@property(nonatomic,getter=isEditable) BOOL editable __TVOS_PROHIBITED;
/**
 【是否允许选中内容，复制】
 */
@property(nonatomic,getter=isSelectable) BOOL selectable NS_AVAILABLE_IOS(7_0); // toggle selectability, which controls the ability of the user to select content and interact with URLs & attachments. On tvOS this also makes the text view focusable.

/**
 显示数据类型的连接模式（如电话号码、网址、地址等）
 UIDataDetectorTypeAll
 */
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;

@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // defaults to NO

/**
 通过AttributedString设置文字
 
 NSMutableAttributedString *attStr = [[NSMutableAttributedString alloc] initWithString:@"我是白开水ln开发工程师"];
 [attStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:18.f] range:NSMakeRange(0, attStr.length)];
 [attStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(0, attStr.length)];
 textView.attributedText = attStr;
 */
@property(null_resettable,copy) NSAttributedString *attributedText NS_AVAILABLE_IOS(6_0);

/**
【待：验证❓】
 */
@property(nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes
- (void)scrollRangeToVisible:(NSRange)range;


// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
/**
 【设置输入框成为第一响应时弹出的inputView视图(自定义键盘) 和 inputAccessoryView辅助视图(系统弹出键盘上的配件视图)】
 */
@property (nullable, readwrite, strong) UIView *inputView;
@property (nullable, readwrite, strong) UIView *inputAccessoryView;


@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.


// Create a new text view with the specified text container (can be nil) - this is the new designated initializer for this class
/**
 【创建textView】
 */
- (instancetype)initWithFrame:(CGRect)frame textContainer:(nullable NSTextContainer *)textContainer NS_AVAILABLE_IOS(7_0) NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


/**
 【textView的 页边距(文本居边框上左下右的间隙)：UIEdgeInsetsZero 和 两边空白间隙】
  textView.textContainerInset (CGFloat top 8, left 0, bottom 8, right 0;)
  textView.textContainer.lineFragmentPadding (5)
 
 【需求】：1.可以设置文本框输入时，前面空几格。
 
 textView.textContainerInset = UIEdgeInsetsZero;
 textView.textContainer.lineFragmentPadding = 0;
 */
// Get the text container for the text view
@property(nonatomic,readonly) NSTextContainer *textContainer NS_AVAILABLE_IOS(7_0);
// Inset the text container's layout area within the text view's content area
@property(nonatomic, assign) UIEdgeInsets textContainerInset NS_AVAILABLE_IOS(7_0);




// Convenience accessors (access through the text container)
@property(nonatomic,readonly) NSLayoutManager *layoutManager NS_AVAILABLE_IOS(7_0);
@property(nonatomic,readonly,strong) NSTextStorage *textStorage NS_AVAILABLE_IOS(7_0);

// Style for links

@property(null_resettable, nonatomic, copy) NSDictionary<NSString *, id> *linkTextAttributes NS_AVAILABLE_IOS(7_0);

@end

#if TARGET_OS_IOS

@interface UITextView () <UITextDraggable, UITextDroppable, UITextPasteConfigurationSupporting>
@end

#endif

UIKIT_EXTERN NSNotificationName const UITextViewTextDidBeginEditingNotification;// 开始编辑
UIKIT_EXTERN NSNotificationName const UITextViewTextDidChangeNotification;// 改变编辑
UIKIT_EXTERN NSNotificationName const UITextViewTextDidEndEditingNotification;// 结束编辑

#NS_ASSUME_NONNULL_END


