/*
 * UIGraphicsPDFRenderer.h
 *
 * Framework: UIKit (c) 2016-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIGraphicsRenderer.h>

NS_ASSUME_NONNULL_BEGIN

@class UIGraphicsPDFRendererContext;

typedef void (^UIGraphicsPDFDrawingActions)(UIGraphicsPDFRendererContext *rendererContext) NS_AVAILABLE_IOS(10_0);

NS_CLASS_AVAILABLE_IOS(10_0) @interface UIGraphicsPDFRendererFormat : UIGraphicsRendererFormat
@property (nonatomic, copy) NSDictionary<NSString *, id> *documentInfo;
@end

NS_CLASS_AVAILABLE_IOS(10_0) @interface UIGraphicsPDFRendererContext : UIGraphicsRendererContext
@property (nonatomic, readonly) CGRect pdfContextBounds;

- (void)beginPage;
- (void)beginPageWithBounds:(CGRect)bounds pageInfo:(NSDictionary<NSString *, id> *)pageInfo;

- (void)setURL:(NSURL *)url forRect:(CGRect)rect;
- (void)addDestinationWithName:(NSString *)name atPoint:(CGPoint)point;
- (void)setDestinationWithName:(NSString *)name forRect:(CGRect)rect;
@end

NS_CLASS_AVAILABLE_IOS(10_0) @interface UIGraphicsPDFRenderer : UIGraphicsRenderer
- (instancetype)initWithBounds:(CGRect)bounds format:(UIGraphicsPDFRendererFormat *)format NS_DESIGNATED_INITIALIZER;

- (BOOL)writePDFToURL:(NSURL *)url withActions:(NS_NOESCAPE UIGraphicsPDFDrawingActions)actions error:(NSError **)error;
- (NSData *)PDFDataWithActions:(NS_NOESCAPE UIGraphicsPDFDrawingActions)actions;
@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
