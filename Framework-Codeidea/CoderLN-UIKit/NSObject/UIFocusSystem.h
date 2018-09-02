/*
 * UIFocusSystem.h
 *
 * Framework: UIKit (c) 2016-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
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

