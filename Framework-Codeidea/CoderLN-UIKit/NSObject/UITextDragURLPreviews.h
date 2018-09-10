/*
 * UITextDragURLPreviews.h
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
#import <UIKit/UIDragPreview.h>
#import <UIKit/UITargetedDragPreview.h>

NS_ASSUME_NONNULL_BEGIN

/* Methods to create previews for dragging a URL.
 * The previews show a textual representation of the URL, and may not
 * contain the full URL string.
 * Should be used only for Internet protocol based URLs, not file URLs.
 */

@interface UIDragPreview (URLPreviews)

+ (instancetype)previewForURL:(NSURL *)url API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

/* If the title is nil or empty, this is the same as `previewForURL:`.
 */
+ (instancetype)previewForURL:(NSURL *)url title:(NSString * _Nullable)title API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@end


@interface UITargetedDragPreview (URLPreviews)

+ (instancetype)previewForURL:(NSURL *)url target:(UIDragPreviewTarget*)target API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

/* If the title is nil or empty, this is the same as `previewForURL:target:`.
 */
+ (instancetype)previewForURL:(NSURL *)url title:(NSString * _Nullable)title target:(UIDragPreviewTarget*)target API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@end

NS_ASSUME_NONNULL_END

