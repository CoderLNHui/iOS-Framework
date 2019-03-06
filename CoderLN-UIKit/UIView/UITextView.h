/*
 * UITextView.h 
 *
 * UIKit (c) 2007-2017
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

#pragma mark - UITextViewDelegate
@protocol UITextViewDelegate <NSObject, UIScrollViewDelegate>
@optional 可选

#pragma mark -是否允许 开始、结束 编辑
- (BOOL)textViewShouldBeginEditing:(UITextView *)textView;
- (BOOL)textViewShouldEndEditing:(UITextView *)textView;

#pragma mark -点击文本框开始编辑时调用
- (void)textViewDidBeginEditing:(UITextView *)textView;

#pragma mark -输入字符时调用
- (void)textViewDidChange:(UITextView *)textView;

#pragma mark -文本框结束编辑时调用
- (void)textViewDidEndEditing:(UITextView *)textView;

#pragma mark -是否允许改变文本框内容(拦截用户输入)
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

#pragma mark -选中内容改变
- (void)textViewDidChangeSelection:(UITextView *)textView;

- (BOOL)textView:(UITextView *)textView shouldInteractWithURL:(NSURL *)URL inRange:(NSRange)characterRange interaction:(UITextItemInteraction)interaction NS_AVAILABLE_IOS(10_0);
- (BOOL)textView:(UITextView *)textView shouldInteractWithTextAttachment:(NSTextAttachment *)textAttachment inRange:(NSRange)characterRange interaction:(UITextItemInteraction)interaction NS_AVAILABLE_IOS(10_0);

- (BOOL)textView:(UITextView *)textView shouldInteractWithURL:(NSURL *)URL inRange:(NSRange)characterRange NS_DEPRECATED_IOS(7_0, 10_0, "Use textView:shouldInteractWithURL:inRange:forInteractionType: instead");
- (BOOL)textView:(UITextView *)textView shouldInteractWithTextAttachment:(NSTextAttachment *)textAttachment inRange:(NSRange)characterRange NS_DEPRECATED_IOS(7_0, 10_0, "Use textView:shouldInteractWithTextAttachment:inRange:forInteractionType: instead");

@end


NS_CLASS_AVAILABLE_IOS(2_0) @interface UITextView : UIScrollView <UITextInput, UIContentSizeCategoryAdjusting>

#pragma mark - 常用属性
#pragma mark -代理
@property(nullable,nonatomic,weak) id<UITextViewDelegate> delegate;
#pragma mark -文字
@property(null_resettable,nonatomic,copy) NSString *text;//
#pragma mark -字体大小
@property(nullable,nonatomic,strong) UIFont *font;//
#pragma mark -字体颜色
@property(nullable,nonatomic,strong) UIColor *textColor;//
#pragma mark -对齐样式
@property(nonatomic) NSTextAlignment textAlignment;
#pragma mark -选中内容范围
@property(nonatomic) NSRange selectedRange;//

#pragma mark -是否允许编辑内容，输入
@property(nonatomic,getter=isEditable) BOOL editable __TVOS_PROHIBITED;
#pragma mark -是否允许选中内容，复制
@property(nonatomic,getter=isSelectable) BOOL selectable NS_AVAILABLE_IOS(7_0); // toggle selectability, which controls the ability of the user to select content and interact with URLs & attachments. On tvOS this also makes the text view focusable.

#pragma mark -显示数据类型的连接模式（如电话号码、网址、地址等）
//textView.allowsEditingTextAttributes = NO;
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED;

#pragma mark -是否允许改变文本属性字典
@property(nonatomic) BOOL allowsEditingTextAttributes NS_AVAILABLE_IOS(6_0); // defaults to NO

#pragma mark -设置属性字符串
/**
 NSMutableAttributedString *attStr = [[NSMutableAttributedString alloc] initWithString:@"我是CoderLN开发工程师"];
 [attStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:18.f] range:NSMakeRange(0, attStr.length)];
 [attStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(0, attStr.length)];
 textView.attributedText = attStr;
 */
@property(null_resettable,copy) NSAttributedString *attributedText NS_AVAILABLE_IOS(6_0);

#pragma mark -重新设置改变的文字的属性字典
@property(nonatomic,copy) NSDictionary<NSString *, id> *typingAttributes NS_AVAILABLE_IOS(6_0); // automatically resets when the selection changes
#pragma mark -滚动到可见范围
- (void)scrollRangeToVisible:(NSRange)range;


// Presented when object becomes first responder.  If set to nil, reverts to following responder chain.  If
// set while first responder, will not take effect until reloadInputViews is called.
#pragma mark -弹出视图(用于自定义键盘)
@property (nullable, readwrite, strong) UIView *inputView;
#pragma mark -辅助视图(系统弹出键盘上的配件视图)
@property (nullable, readwrite, strong) UIView *inputAccessoryView;
#pragma mark -设置textView获得焦点，在用户使用虚拟键盘进行输入时，清除之前的文本
@property(nonatomic) BOOL clearsOnInsertion NS_AVAILABLE_IOS(6_0); // defaults to NO. if YES, the selection UI is hidden, and inserting text will replace the contents of the field. changing the selection will automatically set this to NO.

// Create a new text view with the specified text container (can be nil) - this is the new designated initializer for this class

#pragma mark - 初始化文本视图
- (instancetype)initWithFrame:(CGRect)frame textContainer:(nullable NSTextContainer *)textContainer NS_AVAILABLE_IOS(7_0) NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;


/**
 【需求】：可以设置文本框输入时，前面空几格。
    textView的 页边距8(文本居边框上左下右的间隙)：UIEdgeInsetsZero 和 两边空白间隙5
    textView.textContainerInset (CGFloat top 8, left 0, bottom 8, right 0;)
    textView.textContainer.lineFragmentPadding (5)

    textView.textContainerInset = UIEdgeInsetsZero;
    textView.textContainer.lineFragmentPadding = 0;
 */
#pragma mark -页边距8(文本居边框上左下右的间隙) 和 两边空白间隙5（可以设置文本框输入时，前面空几格）
// Get the text container for the text view
@property(nonatomic,readonly) NSTextContainer *textContainer NS_AVAILABLE_IOS(7_0);
// Inset the text container's layout area within the text view's content area
@property(nonatomic, assign) UIEdgeInsets textContainerInset NS_AVAILABLE_IOS(7_0);

// Convenience accessors (access through the text container)
@property(nonatomic,readonly) NSLayoutManager *layoutManager NS_AVAILABLE_IOS(7_0);
@property(nonatomic,readonly,strong) NSTextStorage *textStorage NS_AVAILABLE_IOS(7_0);

// Style for links
#pragma mark -链接文本的样式设置
@property(null_resettable, nonatomic, copy) NSDictionary<NSString *, id> *linkTextAttributes NS_AVAILABLE_IOS(7_0);

@end

#if TARGET_OS_IOS

@interface UITextView () <UITextDraggable, UITextDroppable, UITextPasteConfigurationSupporting>
@end

#endif

#pragma mark - 监听文本视图编辑的通知（用于判断键盘的弹出和隐藏）
UIKIT_EXTERN NSNotificationName const UITextViewTextDidBeginEditingNotification;// 开始编辑
UIKIT_EXTERN NSNotificationName const UITextViewTextDidChangeNotification;// 改变编辑
UIKIT_EXTERN NSNotificationName const UITextViewTextDidEndEditingNotification;// 结束编辑

#
NS_ASSUME_NONNULL_END


