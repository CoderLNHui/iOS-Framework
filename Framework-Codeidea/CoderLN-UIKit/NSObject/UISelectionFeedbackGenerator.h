/*
 * UISelectionFeedbackGenerator.h
 *
 * Framework: UIKit (c) 2016-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <UIKit/UIFeedbackGenerator.h>

NS_ASSUME_NONNULL_BEGIN

// UISelectionFeedbackGenerator is used to give user feedback when a selection changes
UIKIT_CLASS_AVAILABLE_IOS_ONLY(10_0) @interface UISelectionFeedbackGenerator : UIFeedbackGenerator

/// call when the selection changes (not on initial selection)
- (void)selectionChanged;

@end

NS_ASSUME_NONNULL_END

