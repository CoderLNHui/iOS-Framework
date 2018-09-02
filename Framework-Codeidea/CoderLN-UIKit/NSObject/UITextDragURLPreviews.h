/*
 * UITextDragURLPreviews.h
 *
 * Framework: UIKit (c) 2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
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

