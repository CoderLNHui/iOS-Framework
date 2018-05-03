/*
 * File:  UILabel.h 
 *
 * Framework: UIKit (c) 2006-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIContentSizeCategoryAdjusting.h>

NS_ASSUME_NONNULL_BEGIN

@class UIColor, UIFont;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UILabel : UIView <NSCoding, UIContentSizeCategoryAdjusting>

/**
 文字
 */
@property(nullable, nonatomic,copy)   NSString           *text;            // default is nil
/**
 字体大小
 */
@property(null_resettable, nonatomic,strong) UIFont      *font;            // default is nil (system font 17 plain)
/**
 字体颜色
 */
@property(null_resettable, nonatomic,strong) UIColor     *textColor;       // default is nil (text draws black)
/**
 字体阴影颜色
 */
@property(nullable, nonatomic,strong) UIColor            *shadowColor;     // default is nil (no shadow)
/**
 字体阴影偏移量
 */
@property(nonatomic)        CGSize             shadowOffset;    // default is CGSizeMake(0, -1) -- a top shadow
/**
【文字居中】
 */
@property(nonatomic)        NSTextAlignment    textAlignment;   // default is NSTextAlignmentNatural (before iOS 9, the default was NSTextAlignmentLeft)
/**
 设置文字过长时的显示格式，结尾部分的内容以……方式省略，显示头的文字内容。

 换行+显示模式
 NSLineBreakByWordWrapping = 0,  // 单词包裹,换行的时候会以一个单词换行
 NSLineBreakByCharWrapping,     // 字符包裹换行,换行的时候会以一个字符换行
 NSLineBreakByClipping,     // 裁剪超出的内容
 NSLineBreakByTruncatingHead,    // 一行中头部省略(注意:numberOfLines要为1): "...wxyz"
 NSLineBreakByTruncatingTail,    // 一行中尾部省略: "abcd..."
 NSLineBreakByTruncatingMiddle    // 一行中中间部省略:  "ab...yz"
 */
@property(nonatomic)        NSLineBreakMode    lineBreakMode;   // default is NSLineBreakByTruncatingTail. used for single and multiple lines of text

// the underlying attributed string drawn by the label, if set, the label ignores the properties above.
/**
【设置label的富文本】NSMutableAttributedString
 */
@property(nullable, nonatomic,copy)   NSAttributedString *attributedText NS_AVAILABLE_IOS(6_0);  // default is nil

// the 'highlight' property is used by subclasses for such things as pressed states. it's useful to make it part of the base class as a user property
/**
 高亮显示时的文本颜色
 */
@property(nullable, nonatomic,strong)               UIColor *highlightedTextColor; // default is nil
/**
 是否高亮显示
 */
@property(nonatomic,getter=isHighlighted) BOOL     highlighted;          // default is NO
/**
 是否可以交互，默认NO
 */
@property(nonatomic,getter=isUserInteractionEnabled) BOOL userInteractionEnabled;  // default is NO
/**
 只是决定了Label的绘制方式，将它设置为NO将会使文本变暗，表示它没有激活，这时向它设置颜色值是无效的。
 */
@property(nonatomic,getter=isEnabled)                BOOL enabled;                 // default is YES. changes how the label is drawn

// this determines the number of lines to draw and what to do when sizeToFit is called. default value is 1 (single line). A value of 0 means no limit
// if the height of the text reaches the # of lines or the height of the view is less than the # of lines allowed, the text will be
// truncated using the line break mode.
/**
 标签最多显示行数,如果为0则表示多行。
 */
@property(nonatomic) NSInteger numberOfLines;

// these next 3 properties allow the label to be autosized to fit a certain width by scaling the font size(s) by a scaling factor >= the minimum scaling factor
// and to specify how the text baseline moves when it needs to shrink the font.
/**
 【设置字体大小是否随宽度自适应（默认为NO）】
 */
@property(nonatomic) BOOL adjustsFontSizeToFitWidth;         // default is NO



/**
 当adjustsFontSizeToFitWidth=YES时候，如果文本font要缩小时
 baselineAdjustment这个值控制文本的基线位置，只有文本行数为1是有效
 ![Snip20160817_5.png](http://upload-images.jianshu.io/upload_images/2230763-0c52f7bd1dd91ec5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
 
 
 typedef NS_ENUM(NSInteger, UIBaselineAdjustment) {
 UIBaselineAdjustmentAlignBaselines = 0, 默认，文本最上端与中线对齐。
 UIBaselineAdjustmentAlignCenters, 文本中线与label中线对齐。
 UIBaselineAdjustmentNone, 文本最低端与label中线对齐。
 };
 */
@property(nonatomic) UIBaselineAdjustment baselineAdjustment; // default is UIBaselineAdjustmentAlignBaselines



/**
 设置最小收缩比例，如果Label宽度小于文字长度时，文字进行收缩，收缩超过比例后，停止收缩。
 */
@property(nonatomic) CGFloat minimumScaleFactor NS_AVAILABLE_IOS(6_0); // default is 0.0


// Tightens inter-character spacing in attempt to fit lines wider than the available space if the line break mode is one of the truncation modes before starting to truncate.
// The maximum amount of tightening performed is determined by the system based on contexts such as font, line width, etc.
@property(nonatomic) BOOL allowsDefaultTighteningForTruncation NS_AVAILABLE_IOS(9_0); // default is NO

// override points. can adjust rect before calling super.
// label has default content mode of UIViewContentModeRedraw

- (CGRect)textRectForBounds:(CGRect)bounds limitedToNumberOfLines:(NSInteger)numberOfLines;
/**
 文字绘制
 */
- (void)drawTextInRect:(CGRect)rect;


// Support for constraint-based layout (auto layout)
// If nonzero, this is used when determining -intrinsicContentSize for multiline labels
// 手动设置label文字的最大宽度 (目地是为了能过计算label真实的高度)
@property(nonatomic) CGFloat preferredMaxLayoutWidth NS_AVAILABLE_IOS(6_0);
















#warning deprecated: 弃用

/**
 设置最小收缩字号，如果Label宽度小于文字长度时，文字字号减小，低于设定字号后，不再减小。//6.0以后不再使用了。
 */
@property(nonatomic) CGFloat minimumFontSize NS_DEPRECATED_IOS(2_0, 6_0) __TVOS_PROHIBITED; // deprecated - use minimumScaleFactor. default is 0.0

// Non-functional.  Hand tune by using NSKernAttributeName to affect tracking, or consider using the allowsDefaultTighteningForTruncation property.
/**
 改变字母之间的间距来适应Label大小
 */
@property(nonatomic) BOOL adjustsLetterSpacingToFitWidth NS_DEPRECATED_IOS(6_0,7_0) __TVOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END


#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
