/*
 * UITextDragPreviewRenderer.h
 *
 * UIKit (c) 2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

