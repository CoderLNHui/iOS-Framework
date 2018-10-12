/*
 * UIPreviewInteraction.h
 *
 * UIKit (c) 2015-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIView.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UIPreviewInteractionDelegate;

UIKIT_CLASS_AVAILABLE_IOS_ONLY(10_0) @interface UIPreviewInteraction : NSObject

- (instancetype)initWithView:(UIView *)view NS_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, weak) UIView *view;

- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, nullable, weak) id <UIPreviewInteractionDelegate> delegate;

- (CGPoint)locationInCoordinateSpace:(nullable id <UICoordinateSpace>)coordinateSpace; // returns the current location of the touch that started the interaction
- (void)cancelInteraction;

@end

@protocol UIPreviewInteractionDelegate <NSObject>

- (void)previewInteraction:(UIPreviewInteraction *)previewInteraction didUpdatePreviewTransition:(CGFloat)transitionProgress ended:(BOOL)ended UIKIT_AVAILABLE_IOS_ONLY(10_0); // transitionProgress ranges from 0 to 1
- (void)previewInteractionDidCancel:(UIPreviewInteraction *)previewInteraction UIKIT_AVAILABLE_IOS_ONLY(10_0);

@optional

- (BOOL)previewInteractionShouldBegin:(UIPreviewInteraction *)previewInteraction UIKIT_AVAILABLE_IOS_ONLY(10_0);

// If implemented, a preview interaction will also trigger haptic feedback when detecting a commit (pop). The provided transitionProgress ranges from 0 to 1.
- (void)previewInteraction:(UIPreviewInteraction *)previewInteraction didUpdateCommitTransition:(CGFloat)transitionProgress ended:(BOOL)ended UIKIT_AVAILABLE_IOS_ONLY(10_0);

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
