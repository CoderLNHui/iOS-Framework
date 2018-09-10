/*
 * UIFeedbackGenerator.h
 *
 * UIKit (c) 2016-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

// UIFeedbackGenerator is an abstract class that should not be used directly
UIKIT_CLASS_AVAILABLE_IOS_ONLY(10_0) @interface UIFeedbackGenerator : NSObject

/// informs self that it will likely receive events soon, so that it can ensure minimal latency for any feedback generated
/// safe to call more than once before the generator receives an event, if events are still imminently possible
- (void)prepare;

@end

NS_ASSUME_NONNULL_END

