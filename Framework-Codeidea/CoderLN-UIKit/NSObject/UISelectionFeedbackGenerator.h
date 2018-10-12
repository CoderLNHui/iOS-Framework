/*
 * UISelectionFeedbackGenerator.h
 *
 * UIKit (c) 2016-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <UIKit/UIFeedbackGenerator.h>

NS_ASSUME_NONNULL_BEGIN

// UISelectionFeedbackGenerator is used to give user feedback when a selection changes
UIKIT_CLASS_AVAILABLE_IOS_ONLY(10_0) @interface UISelectionFeedbackGenerator : UIFeedbackGenerator

/// call when the selection changes (not on initial selection)
- (void)selectionChanged;

@end
NS_ASSUME_NONNULL_END

