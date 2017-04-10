//
//  UIWindow.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"

typedef CGFloat UIWindowLevel;
extern const UIWindowLevel UIWindowLevelNormal;
extern const UIWindowLevel UIWindowLevelStatusBar;
extern const UIWindowLevel UIWindowLevelAlert;

extern NSString *const UIWindowDidBecomeVisibleNotification;
extern NSString *const UIWindowDidBecomeHiddenNotification;
extern NSString *const UIWindowDidBecomeKeyNotification;
extern NSString *const UIWindowDidResignKeyNotification;

extern NSString *const UIKeyboardWillShowNotification;
extern NSString *const UIKeyboardDidShowNotification;
extern NSString *const UIKeyboardWillHideNotification;
extern NSString *const UIKeyboardDidHideNotification;
extern NSString *const UIKeyboardWillChangeFrameNotification;

extern NSString *const UIKeyboardFrameBeginUserInfoKey;
extern NSString *const UIKeyboardFrameEndUserInfoKey;
extern NSString *const UIKeyboardAnimationDurationUserInfoKey;
extern NSString *const UIKeyboardAnimationCurveUserInfoKey;

// deprecated
extern NSString *const UIKeyboardCenterBeginUserInfoKey;
extern NSString *const UIKeyboardCenterEndUserInfoKey;
extern NSString *const UIKeyboardBoundsUserInfoKey;

@class UIScreen, UIViewController;

@interface UIWindow : UIView

- (CGPoint)convertPoint:(CGPoint)toConvert toWindow:(UIWindow *)toWindow;
- (CGPoint)convertPoint:(CGPoint)toConvert fromWindow:(UIWindow *)fromWindow;
- (CGRect)convertRect:(CGRect)toConvert fromWindow:(UIWindow *)fromWindow;
- (CGRect)convertRect:(CGRect)toConvert toWindow:(UIWindow *)toWindow;

- (void)makeKeyWindow;
- (void)makeKeyAndVisible;

- (void)resignKeyWindow;
- (void)becomeKeyWindow;

- (void)sendEvent:(UIEvent *)event;

// this property returns YES only if the underlying screen's UIKitView is on the AppKit's key window
// and this UIWindow was made key at some point in the past (and is still key from the point of view
// of the underlying screen) which is of course rather different from the real UIKit.
// this is done because unlike iOS, on OSX the user can change the key window at will at any time and
// we need a way to reconnect key windows when they change. :/
@property (nonatomic, readonly, getter=isKeyWindow) BOOL keyWindow;

@property (nonatomic, strong) UIScreen *screen;
@property (nonatomic, assign) UIWindowLevel windowLevel;
@property (nonatomic, strong) UIViewController *rootViewController;
@end
