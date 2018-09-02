/*
 * UIDragPreview.h
 *
 * Framework: UIKit  (c) 2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIDragPreviewParameters, UIView;

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos) @interface UIDragPreview : NSObject <NSCopying>

/* UIDragPreview is a preview used after a drag has started,
 * when no lift, drop, or cancel animation is running.
 *
 * A UIDragItem's `previewProvider` may be set to a block that
 * creates and returns a UIDragPreview.
 *
 * The preview will show a static snapshot of the provided view. Subsequent changes
 * to the view will not appear. The UIDragPreview will not change or move the view.
 */

/* Create a preview based on a view and parameters.
 * Note: it doesn't matter whether this view is in a window or not.
 */
- (instancetype)initWithView:(UIView *)view parameters:(UIDragPreviewParameters *)parameters NS_DESIGNATED_INITIALIZER;

/* Use the default parameters.
 */
- (instancetype)initWithView:(UIView *)view;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly) UIView *view;

@property (nonatomic, readonly, copy) UIDragPreviewParameters *parameters;

@end

NS_ASSUME_NONNULL_END

