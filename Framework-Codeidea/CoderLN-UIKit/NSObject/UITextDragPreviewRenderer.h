/*
 * UITextDragPreviewRenderer.h
 *
 * UIKit (c) 2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/NSLayoutManager.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@interface UITextDragPreviewRenderer : NSObject

- (instancetype)initWithLayoutManager:(NSLayoutManager*)layoutManager range:(NSRange)range;
- (instancetype)initWithLayoutManager:(NSLayoutManager*)layoutManager range:(NSRange)range unifyRects:(BOOL)unifyRects NS_DESIGNATED_INITIALIZER;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, readonly) NSLayoutManager *layoutManager;
@property (nonatomic, readonly) UIImage *image;
@property (nonatomic, readonly) CGRect firstLineRect;
@property (nonatomic, readonly) CGRect bodyRect;
@property (nonatomic, readonly) CGRect lastLineRect;

- (void)adjustFirstLineRect:(inout CGRect*)firstLineRect bodyRect:(inout CGRect*)bodyRect lastLineRect:(inout CGRect*)lastLineRect textOrigin:(CGPoint)origin;

@end
NS_ASSUME_NONNULL_END

