/*
 * UIFocusAnimationCoordinator.h
 *
 * Framework: UIKit (c) 2015
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// UIFocusAnimationCoordinator is used to coordinate disparate animations that are related to a focus update.
NS_CLASS_AVAILABLE_IOS(9_0) @interface UIFocusAnimationCoordinator : NSObject

/**
 Specifies focus-related animations that should be coordinated with the animations of the focusing or un-focusing view.
 
 Any animations specified will be run in the same animation context as the main animation. The completion block is invoked after the main animation completes.
 (Note that this may not be after all the coordinated animations specified by the call complete if the duration is not inherited.)
 
 It is perfectly legitimate to only specify a completion block.
 */
- (void)addCoordinatedAnimations:(nullable void (^)(void))animations completion:(nullable void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
