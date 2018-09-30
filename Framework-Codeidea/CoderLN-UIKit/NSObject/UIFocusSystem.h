/*
 * UIFocusSystem.h
 *
 * UIKit (c) 2016-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */
 

#import <UIKit/UIFocus.h>

NS_ASSUME_NONNULL_BEGIN

/// UIFocusSystem instances manage focus state within a part of the user interface. They are in charge of tracking the current focused item, as well as processing focus updates.
NS_CLASS_AVAILABLE_IOS(11_0) @interface UIFocusSystem : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// Returns true if `environment` is an ancestor of `otherEnvironment`, or false if otherwise.
+ (BOOL)environment:(id<UIFocusEnvironment>)environment containsEnvironment:(id<UIFocusEnvironment>)otherEnvironment;

/// Registers a sound file for a given identifier.
+ (void)registerURL:(NSURL *)soundFileURL forSoundIdentifier:(UIFocusSoundIdentifier)identifier API_AVAILABLE(tvos(11.0)) API_UNAVAILABLE(ios, watchos);

@end

NS_ASSUME_NONNULL_END

