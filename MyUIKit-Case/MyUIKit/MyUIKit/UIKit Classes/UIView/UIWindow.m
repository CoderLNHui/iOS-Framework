//
//  UIWindow.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIWindow.h"

const UIWindowLevel UIWindowLevelNormal = 0;
const UIWindowLevel UIWindowLevelStatusBar = 1000;
const UIWindowLevel UIWindowLevelAlert = 2000;

NSString *const UIWindowDidBecomeVisibleNotification = @"UIWindowDidBecomeVisibleNotification";
NSString *const UIWindowDidBecomeHiddenNotification = @"UIWindowDidBecomeHiddenNotification";
NSString *const UIWindowDidBecomeKeyNotification = @"UIWindowDidBecomeKeyNotification";
NSString *const UIWindowDidResignKeyNotification = @"UIWindowDidResignKeyNotification";

NSString *const UIKeyboardWillShowNotification = @"UIKeyboardWillShowNotification";
NSString *const UIKeyboardDidShowNotification = @"UIKeyboardDidShowNotification";
NSString *const UIKeyboardWillHideNotification = @"UIKeyboardWillHideNotification";
NSString *const UIKeyboardDidHideNotification = @"UIKeyboardDidHideNotification";
NSString *const UIKeyboardWillChangeFrameNotification = @"UIKeyboardWillChangeFrameNotification";

NSString *const UIKeyboardFrameBeginUserInfoKey = @"UIKeyboardFrameBeginUserInfoKey";
NSString *const UIKeyboardFrameEndUserInfoKey = @"UIKeyboardFrameEndUserInfoKey";
NSString *const UIKeyboardAnimationDurationUserInfoKey = @"UIKeyboardAnimationDurationUserInfoKey";
NSString *const UIKeyboardAnimationCurveUserInfoKey = @"UIKeyboardAnimationCurveUserInfoKey";

// deprecated
NSString *const UIKeyboardCenterBeginUserInfoKey = @"UIKeyboardCenterBeginUserInfoKey";
NSString *const UIKeyboardCenterEndUserInfoKey = @"UIKeyboardCenterEndUserInfoKey";
NSString *const UIKeyboardBoundsUserInfoKey = @"UIKeyboardBoundsUserInfoKey";

@implementation UIWindow

@end
