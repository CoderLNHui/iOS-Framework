/*
 * NSStringDrawing.h
 *
 * UIKit (c) 2011-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 

#import <Foundation/NSString.h>
#import <CoreGraphics/CGGeometry.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/NSAttributedString.h>

@class NSStringDrawingContext;

NS_ASSUME_NONNULL_BEGIN

// When attributes=nil, the methods declared here uses the default behavior for each attribute described in <UIKit/NSAttributedString.h>. When stringDrawingContext=nil, it's equivalent of passing the default instance initialized with [[NSStringDrawingContext alloc] init].

NS_CLASS_AVAILABLE(10_11, 6_0) @interface NSStringDrawingContext : NSObject

// Minimum scale factor for drawWithRect:options:context: and boundingRectWithSize:options:context: methods. If this property is set, the extended string drawing methods will attempt to draw the attributed string in the given bounds by proportionally scaling the font(s) in the attributed string
@property(NS_NONATOMIC_IOSONLY) CGFloat minimumScaleFactor;

// actual scale factor used by the last drawing call where minimum scale factor was specified
@property(readonly, NS_NONATOMIC_IOSONLY) CGFloat actualScaleFactor;

// bounds of the string drawn by the previous invocation of drawWithRect:options:context:
@property(readonly, NS_NONATOMIC_IOSONLY) CGRect totalBounds;

@end

@interface NSString(NSStringDrawing)
- (CGSize)sizeWithAttributes:(nullable NSDictionary<NSString *, id> *)attrs NS_AVAILABLE(10_0, 7_0);
- (void)drawAtPoint:(CGPoint)point withAttributes:(nullable NSDictionary<NSString *, id> *)attrs NS_AVAILABLE(10_0, 7_0);
- (void)drawInRect:(CGRect)rect withAttributes:(nullable NSDictionary<NSString *, id> *)attrs NS_AVAILABLE(10_0, 7_0);
@end

@interface NSAttributedString(NSStringDrawing)
- (CGSize)size NS_AVAILABLE(10_0, 6_0);
- (void)drawAtPoint:(CGPoint)point NS_AVAILABLE(10_0, 6_0);
- (void)drawInRect:(CGRect)rect NS_AVAILABLE(10_0, 6_0);
@end

typedef NS_OPTIONS(NSInteger, NSStringDrawingOptions) {
    NSStringDrawingUsesLineFragmentOrigin = 1 << 0, // The specified origin is the line fragment origin, not the base line origin
    NSStringDrawingUsesFontLeading = 1 << 1, // Uses the font leading for calculating line heights
    NSStringDrawingUsesDeviceMetrics = 1 << 3, // Uses image glyph bounds instead of typographic bounds
    NSStringDrawingTruncatesLastVisibleLine NS_ENUM_AVAILABLE(10_5, 6_0) = 1 << 5, // Truncates and adds the ellipsis character to the last visible line if the text doesn't fit into the bounds specified. Ignored if NSStringDrawingUsesLineFragmentOrigin is not also set.
    
} NS_ENUM_AVAILABLE(10_0, 6_0);


// NOTE: All of the following methods will default to drawing on a baseline, limiting drawing to a single line.
// To correctly draw and size multi-line text, pass NSStringDrawingUsesLineFragmentOrigin in the options parameter.
@interface NSString (NSExtendedStringDrawing)
- (void)drawWithRect:(CGRect)rect options:(NSStringDrawingOptions)options attributes:(nullable NSDictionary<NSString *, id> *)attributes context:(nullable NSStringDrawingContext *)context NS_AVAILABLE(10_11, 7_0);
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options attributes:(nullable NSDictionary<NSString *, id> *)attributes context:(nullable NSStringDrawingContext *)context NS_AVAILABLE(10_11, 7_0);
@end

@interface NSAttributedString (NSExtendedStringDrawing)
- (void)drawWithRect:(CGRect)rect options:(NSStringDrawingOptions)options context:(nullable NSStringDrawingContext *)context NS_AVAILABLE(10_11, 6_0);
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options context:(nullable NSStringDrawingContext *)context NS_AVAILABLE(10_11, 6_0);
@end

/************************ Deprecated ************************/
@interface NSStringDrawingContext (NSStringDrawingContextDeprecated)
@property(nonatomic) CGFloat minimumTrackingAdjustment NS_DEPRECATED_IOS(6_0,7_0) __TVOS_PROHIBITED;
@property(nonatomic, readonly) CGFloat actualTrackingAdjustment NS_DEPRECATED_IOS(6_0,7_0) __TVOS_PROHIBITED;
@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
