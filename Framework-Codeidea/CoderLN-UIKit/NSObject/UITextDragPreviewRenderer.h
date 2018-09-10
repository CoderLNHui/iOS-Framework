/*
 * UITextDragPreviewRenderer.h
 *
 * UIKit (c) 2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
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

