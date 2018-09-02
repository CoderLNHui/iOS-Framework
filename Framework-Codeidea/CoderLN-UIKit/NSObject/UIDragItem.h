/*
 * UIDragItem.h
 *
 * Framework: UIKit  (c) 2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIDragPreview;

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos) @interface UIDragItem : NSObject

- (instancetype)initWithItemProvider:(NSItemProvider *)itemProvider NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property (nonatomic, readonly) __kindof NSItemProvider *itemProvider;

/* Use `localObject` to attach additional information to
 * this drag item, visible only inside the app that started the drag.
 */
@property (nonatomic, strong, nullable) id localObject;

/* Use `previewProvider` to change the preview for an item.
 *
 * Each item is usually given a preview when the drag begins,
 * either by the UIDragInteractionDelegate's `-dragInteraction:previewForLiftingItem:session:`
 * method, or by creating a preview from the dragging view.
 *
 * During the drag, applications may attempt to change the item's preview,
 * by setting `previewProvider` to a block that returns a preview.
 * It will be called when and if the system requests it.
 *
 * To use the default preview, set `previewProvider` to nil.
 * To hide the preview, set `previewProvider` to a block that returns nil.
 */
@property (nonatomic, copy, nullable) UIDragPreview * _Nullable (^previewProvider)(void);

@end

NS_ASSUME_NONNULL_END
