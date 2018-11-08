/*
 * NSAttributedString.h 
 *
 * Foundation (c) 2011-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#import <Foundation/NSAttributedString.h>
#import <UIKit/UIKitDefines.h>
@class NSFileWrapper;
@class NSURL;

NS_ASSUME_NONNULL_BEGIN
/************************ Attributes ************************/

// Predefined character attributes for text. If the key is not in the dictionary, then use the default values as described below.

// (字体) 该属性所对应的值是一个 UIFont 对象。
// 该属性用于改变一段文本的字体。如果不指定该属性，则默认为12-point Helvetica(Neue)。
UIKIT_EXTERN NSString * const NSFontAttributeName NS_AVAILABLE(10_0, 6_0);                // UIFont, default Helvetica(Neue) 12


// (段落) 该属性所对应的值是一个 NSParagraphStyle 对象。
// 该属性在一段文本上应用多个属性。如果不指定该属性，则默认为 NSParagraphStyle 的defaultParagraphStyle 方法返回的默认段落属性。
UIKIT_EXTERN NSString * const NSParagraphStyleAttributeName NS_AVAILABLE(10_0, 6_0);      // NSParagraphStyle, default defaultParagraphStyle


// (字体颜色) 该属性所对应的值是一个 UIColor 对象。
// 该属性用于指定一段文本的字体颜色。如果不指定该属性，则默认为黑色。
UIKIT_EXTERN NSString * const NSForegroundColorAttributeName NS_AVAILABLE(10_0, 6_0);     // UIColor, default blackColor


// (字体背景色) 该属性所对应的值是一个 UIColor 对象。
// 该属性用于指定一段文本的背景颜色。如果不指定该属性，则默认无背景色。
UIKIT_EXTERN NSString * const NSBackgroundColorAttributeName NS_AVAILABLE(10_0, 6_0);     // UIColor, default nil: no background


// (连字符) 该属性所对应的值是一个 NSNumber 对象(整数)。
// 连体字符是指某些连在一起的字符，它们采用单个的图元符号。0 表示没有连体字符。1 表示使用默认的连体字符。2表示使用所有连体符号。默认值为 1（注意，iOS 不支持值为 2）。
UIKIT_EXTERN NSString * const NSLigatureAttributeName NS_AVAILABLE(10_0, 6_0);            // NSNumber containing integer, default 1: default ligatures, 0: no ligatures


// (字间距) 该属性所对应的值是一个 NSNumber 对象(整数)。
// 字母紧排指定了用于调整字距的像素点数。字母紧排的效果依赖于字体。值为 0 表示不使用字母紧排。默认值为0。
UIKIT_EXTERN NSString * const NSKernAttributeName NS_AVAILABLE(10_0, 6_0);                // NSNumber containing floating point value, in points; amount to modify default kerning. 0 means kerning is disabled.


// (删除线) 该属性所对应的值是一个 NSNumber 对象(整数)。
// 该值指定是否在文字上加上删除线，该值参考“Underline Style Attributes”。默认值是NSUnderlineStyleNone。
UIKIT_EXTERN NSString * const NSStrikethroughStyleAttributeName NS_AVAILABLE(10_0, 6_0);  // NSNumber containing integer, default 0: no strikethrough


// (下划线) 该属性所对应的值是一个 NSNumber 对象(整数)。
// 该值指定是否在文字上加上下划线，该值参考“Underline Style Attributes”。默认值是NSUnderlineStyleNone。
UIKIT_EXTERN NSString * const NSUnderlineStyleAttributeName NS_AVAILABLE(10_0, 6_0);      // NSNumber containing integer, default 0: no underline


// (边线颜色) 该属性所对应的值是一个 UIColor 对象。
// 如果该属性不指定（默认），则等同于 NSForegroundColorAttributeName。否则，指定为删除线或下划线颜色。
UIKIT_EXTERN NSString * const NSStrokeColorAttributeName NS_AVAILABLE(10_0, 6_0);         // UIColor, default nil: same as foreground color



// (边线宽度) 该属性所对应的值是一个 NSNumber 对象(小数)。
// 该值改变描边宽度（相对于字体size 的百分比）。默认为 0，即不改变。正数只改变描边宽度。负数同时改变文字的描边和填充宽度。例如，对于常见的空心字，这个值通常为3.0。
UIKIT_EXTERN NSString * const NSStrokeWidthAttributeName NS_AVAILABLE(10_0, 6_0);         // NSNumber containing floating point value, in percent of font point size, default 0: no stroke; positive for stroke alone, negative for stroke and fill (a typical value for outlined text would be 3.0)


// (阴影) 该属性所对应的值是一个 NSShadow 对象。默认为 nil。
UIKIT_EXTERN NSString * const NSShadowAttributeName NS_AVAILABLE(10_0, 6_0);              // NSShadow, default nil: no shadow

// 设置（文本特殊效果），取值为 NSString 对象，目前只有图版印刷效果可用
UIKIT_EXTERN NSString *const NSTextEffectAttributeName NS_AVAILABLE(10_10, 7_0);          // NSString, default nil: no text effect

UIKIT_EXTERN NSString * const NSAttachmentAttributeName NS_AVAILABLE(10_0, 7_0);          // NSTextAttachment, default nil
UIKIT_EXTERN NSString * const NSLinkAttributeName NS_AVAILABLE(10_0, 7_0);                // NSURL (preferred) or NSString

// 设置（基线偏移值），取值为 NSNumber （float）,正值上偏，负值下偏
UIKIT_EXTERN NSString * const NSBaselineOffsetAttributeName NS_AVAILABLE(10_0, 7_0);      // NSNumber containing floating point value, in points; offset from baseline, default 0
UIKIT_EXTERN NSString * const NSUnderlineColorAttributeName NS_AVAILABLE(10_0, 7_0);      // UIColor, default nil: same as foreground color
UIKIT_EXTERN NSString * const NSStrikethroughColorAttributeName NS_AVAILABLE(10_0, 7_0);  // UIColor, default nil: same as foreground color

// 设置（字形倾斜度），取值为 NSNumber （float）,正值右倾，负值左倾
UIKIT_EXTERN NSString * const NSObliquenessAttributeName NS_AVAILABLE(10_0, 7_0);         // NSNumber containing floating point value; skew to be applied to glyphs, default 0: no skew
UIKIT_EXTERN NSString * const NSExpansionAttributeName NS_AVAILABLE(10_0, 7_0);           // NSNumber containing floating point value; log of expansion factor to be applied to glyphs, default 0: no expansion

UIKIT_EXTERN NSString * const NSWritingDirectionAttributeName NS_AVAILABLE(10_6, 7_0);    // NSArray of NSNumbers representing the nested levels of writing direction overrides as defined by Unicode LRE, RLE, LRO, and RLO characters.  The control characters can be obtained by masking NSWritingDirection and NSWritingDirectionFormatType values.  LRE: NSWritingDirectionLeftToRight|NSWritingDirectionEmbedding, RLE: NSWritingDirectionRightToLeft|NSWritingDirectionEmbedding, LRO: NSWritingDirectionLeftToRight|NSWritingDirectionOverride, RLO: NSWritingDirectionRightToLeft|NSWritingDirectionOverride,



// (横竖排版) 该属性所对应的值是一个 NSNumber 对象(整数)。
// 0 表示横排文本。1 表示竖排文本。在 iOS 中，总是使用横排文本，0 以外的值都未定义
UIKIT_EXTERN NSString * const NSVerticalGlyphFormAttributeName NS_AVAILABLE(10_7, 6_0);   // An NSNumber containing an integer value.  0 means horizontal text.  1 indicates vertical text.  If not specified, it could follow higher-level vertical orientation settings.  Currently on iOS, it's always horizontal.  The behavior for any other value is undefined.



/************************ Attribute values ************************/
// This defines currently supported values for NSUnderlineStyleAttributeName and NSStrikethroughStyleAttributeName. NSUnderlineStyle*, NSUnderlinePattern*, and NSUnderlineByWord are or'ed together to produce an underline style.
typedef NS_ENUM(NSInteger, NSUnderlineStyle) {
    NSUnderlineStyleNone                                    = 0x00,
    NSUnderlineStyleSingle                                  = 0x01,
    NSUnderlineStyleThick NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x02,
    NSUnderlineStyleDouble NS_ENUM_AVAILABLE(10_0, 7_0)     = 0x09,
    
    NSUnderlinePatternSolid NS_ENUM_AVAILABLE(10_0, 7_0)      = 0x0000,
    NSUnderlinePatternDot NS_ENUM_AVAILABLE(10_0, 7_0)        = 0x0100,
    NSUnderlinePatternDash NS_ENUM_AVAILABLE(10_0, 7_0)       = 0x0200,
    NSUnderlinePatternDashDot NS_ENUM_AVAILABLE(10_0, 7_0)    = 0x0300,
    NSUnderlinePatternDashDotDot NS_ENUM_AVAILABLE(10_0, 7_0) = 0x0400,
    
    NSUnderlineByWord NS_ENUM_AVAILABLE(10_0, 7_0)            = 0x8000
} NS_ENUM_AVAILABLE(10_0, 6_0);

// NSWritingDirectionFormatType values used by NSWritingDirectionAttributeName. It is or'ed with either NSWritingDirectionLeftToRight or NSWritingDirectionRightToLeft. Can specify the formatting controls defined by Unicode Bidirectional Algorithm.
typedef NS_ENUM(NSInteger, NSWritingDirectionFormatType) {
    NSWritingDirectionEmbedding     = (0 << 1),
    NSWritingDirectionOverride      = (1 << 1)
} NS_ENUM_AVAILABLE(10_11, 9_0);

// NSTextEffectAttributeName values
UIKIT_EXTERN NSString *const NSTextEffectLetterpressStyle NS_AVAILABLE(10_10, 7_0);









/**************************************************************************
 *                                                                        *
 *                       WechatPublic - CoderLN                          *
 *                                                                        *
 *  WeChat-CoderLN    用文字记录自己的思想与经验,关于编程、职场、阅读以及摄影.     *
 *  WeChat-CoderLN    希望在这个浮躁的社会中通过自己的一丝经历与感知 ~            *
 *  WeChat-CoderLN    些许能带给你新思想或是习惯.                             *
 *  JaneBook-白开水ln   Reprinted Please indicate the source.Mustbe.       *
 *                 WELCOME YOU TO JOIN_GitHub & CoderLN                  *
 *                                                                        *
 **************************************************************************/










/************************ Attribute fixing ************************/

@interface NSMutableAttributedString (NSAttributedStringAttributeFixing)
// This method fixes attribute inconsistencies inside range.  It ensures NSFontAttributeName covers the characters, NSParagraphStyleAttributeName is only changing at paragraph boundaries, and NSTextAttachmentAttributeName is assigned to NSAttachmentCharacter.  NSTextStorage automatically invokes this method via -ensureAttributesAreFixedInRange:.
- (void)fixAttributesInRange:(NSRange)range NS_AVAILABLE(10_0, 7_0);

@end


/************************ Document formats ************************/

// Supported document types for the NSDocumentTypeDocumentAttribute key in the document attributes dictionary.
UIKIT_EXTERN NSString * const NSPlainTextDocumentType NS_AVAILABLE(10_0, 7_0);
UIKIT_EXTERN NSString * const NSRTFTextDocumentType NS_AVAILABLE(10_0, 7_0);
UIKIT_EXTERN NSString * const NSRTFDTextDocumentType NS_AVAILABLE(10_0, 7_0);
UIKIT_EXTERN NSString * const NSHTMLTextDocumentType NS_AVAILABLE(10_0, 7_0);

// Keys for NSLayoutOrientationSectionsAttribute.
UIKIT_EXTERN NSString * const NSTextLayoutSectionOrientation NS_AVAILABLE(10_7, 7_0); // NSNumber containing NSTextLayoutOrientation value. default: NSTextLayoutOrientationHorizontal
UIKIT_EXTERN NSString * const NSTextLayoutSectionRange NS_AVAILABLE(10_7, 7_0); // NSValue containing NSRange representing a character range. default: a range covering the whole document


// Keys for options and document attributes dictionaries.  They are in and out document properties used by both read/write methods.

UIKIT_EXTERN NSString * const NSDocumentTypeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"DocumentType", one of the document types declared above.  For reader methods, this key in options can specify the document type for interpreting the contents.  Upon return, the document attributes can contain this key for indicating the actual format used to read the contents.  For write methods, this key specifies the format for generating the data.


// NSPlainTextDocumentType document attributes
UIKIT_EXTERN NSString * const NSCharacterEncodingDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"CharacterEncoding", NSNumber containing integer specifying NSStringEncoding for the file; default for plain text is the default encoding.  This key in options can specify the string encoding for reading the data.  Upon return, the document attributes can contain the actual encoding used.  For writing methods, this value is used for generating the plain text data.
UIKIT_EXTERN NSString * const NSDefaultAttributesDocumentAttribute NS_AVAILABLE(10_11, 7_0);  // @"DefaultAttributes", NSDictionary containing attributes to be applied to plain files.  Used by reader methods.  This key in options can specify the default attributes applied to the entire document contents.  The document attributes can contain this key indicating the actual attributes used.


// NSRTFTextDocumentType and NSRTFDTextDocumentType document attributes
// Document dimension
// They are document attributes used by read/write methods.
UIKIT_EXTERN NSString * const NSPaperSizeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"PaperSize", NSValue containing CGSize (in points)
UIKIT_EXTERN NSString * const NSPaperMarginDocumentAttribute NS_AVAILABLE_IOS(7_0);  // @"PaperMargin", NSValue containing UIEdgeInsets

UIKIT_EXTERN NSString * const NSViewSizeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ViewSize", NSValue containing CGSize (in points)
UIKIT_EXTERN NSString * const NSViewZoomDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ViewZoom", NSNumber containing floating point value (100 == 100% zoom)
UIKIT_EXTERN NSString * const NSViewModeDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ViewMode", NSNumber containing integer; 0 = normal; 1 = page layout

// Document settings
// They are document attributes used by read/write methods.
UIKIT_EXTERN NSString * const NSReadOnlyDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"ReadOnly", NSNumber containing integer; if missing, or 0 or negative, not readonly; 1 or more, readonly. Note that this has nothing to do with the file system protection on the file, but instead, on how the file should be displayed to the user
UIKIT_EXTERN NSString * const NSBackgroundColorDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"BackgroundColor", UIColor, representing the document-wide page background color
UIKIT_EXTERN NSString * const NSHyphenationFactorDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"HyphenationFactor", NSNumber containing floating point value (0=off, 1=full hyphenation)
UIKIT_EXTERN NSString * const NSDefaultTabIntervalDocumentAttribute NS_AVAILABLE(10_0, 7_0);  // @"DefaultTabInterval", NSNumber containing floating point value, representing the document-wide default tab stop interval, in points
UIKIT_EXTERN NSString * const NSTextLayoutSectionsAttribute NS_AVAILABLE(10_7, 7_0);  // NSArray of dictionaries.  Each dictionary describing a layout orientation section.  The dictionary can have two attributes: NSTextLayoutSectionOrientation and NSTextLayoutSectionRange.  When there is a gap between sections, it's assumed to have NSTextLayoutOrientationHorizontal.



@interface NSAttributedString (NSAttributedStringDocumentFormats)
// Methods initializing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (nullable instancetype)initWithURL:(NSURL *)url options:(NSDictionary<NSString *, id> *)options documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict error:(NSError **)error NS_AVAILABLE(10_4, 9_0);
- (nullable instancetype)initWithData:(NSData *)data options:(NSDictionary<NSString *, id> *)options documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict error:(NSError **)error NS_AVAILABLE(10_0, 7_0);

// Generates an NSData object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.
- (nullable NSData *)dataFromRange:(NSRange)range documentAttributes:(NSDictionary<NSString *, id> *)dict error:(NSError **)error NS_AVAILABLE(10_0, 7_0);

// Returns an NSFileWrapper object for the receiver contents in range.  It requires a document attributes dict specifying at least the NSDocumentTypeDocumentAttribute to determine the format to be written.  The method returns a directory file wrapper for those document types represented by a file package such as NSRTFDTextDocumentType; otherwise, it returns a regular-file file wrapper.
- (nullable NSFileWrapper *)fileWrapperFromRange:(NSRange)range documentAttributes:(NSDictionary<NSString *, id> *)dict error:(NSError **)error NS_AVAILABLE(10_0, 7_0);

@end

@interface NSMutableAttributedString (NSMutableAttributedStringDocumentFormats)
// Methods replacing the receiver contents with an external document data.  options specify document attributes for interpreting the document contents.  NSDocumentTypeDocumentAttribute, NSCharacterEncodingDocumentAttribute, and NSDefaultAttributesDocumentAttribute are supported options key.  When they are not specified, these methods will examine the data and do their best to detect the appropriate attributes.  If dict is non-NULL, it will return a dictionary with various document-wide attributes accessible via NS...DocumentAttribute keys.
- (BOOL)readFromURL:(NSURL *)url options:(NSDictionary<NSString *, id> *)opts documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict error:(NSError **)error  NS_AVAILABLE(10_11, 9_0);
- (BOOL)readFromData:(NSData *)data options:(NSDictionary<NSString *, id> *)opts documentAttributes:(NSDictionary<NSString *, id> * __nullable * __nullable)dict error:(NSError **)error NS_AVAILABLE(10_0, 7_0);
@end


/************************ Misc methods ************************/
@interface NSAttributedString (NSAttributedStringKitAdditions)
// Returns YES if the receiver contains a property configured (NSAttachmentAttributeName with NSAttachmentCharacter) in range
- (BOOL)containsAttachmentsInRange:(NSRange)range NS_AVAILABLE(10_11, 9_0);
@end

/************************ Deprecated ************************/

typedef NS_ENUM(NSInteger, NSTextWritingDirection) {
    NSTextWritingDirectionEmbedding     = (0 << 1),
    NSTextWritingDirectionOverride      = (1 << 1)
} NS_ENUM_DEPRECATED_IOS(7_0, 9_0, "Use NSWritingDirectionFormatType instead") __TVOS_PROHIBITED;

@interface NSAttributedString(NSDeprecatedKitAdditions)
- (nullable instancetype)initWithFileURL:(NSURL *)url options:(NSDictionary *)options documentAttributes:(NSDictionary* __nullable * __nullable)dict error:(NSError **)error NS_DEPRECATED_IOS(7_0, 9_0, "Use -initWithURL:options:documentAttributes:error: instead") __TVOS_PROHIBITED;
@end

@interface NSMutableAttributedString (NSDeprecatedKitAdditions)
- (BOOL)readFromFileURL:(NSURL *)url options:(NSDictionary *)opts documentAttributes:(NSDictionary* __nullable * __nullable)dict error:(NSError **)error NS_DEPRECATED_IOS(7_0, 9_0, "Use -readFromURL:options:documentAttributes:error: instead") __TVOS_PROHIBITED;
@end

NS_ASSUME_NONNULL_END





















