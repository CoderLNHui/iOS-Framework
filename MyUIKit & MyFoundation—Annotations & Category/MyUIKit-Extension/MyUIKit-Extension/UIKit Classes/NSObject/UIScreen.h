//
//  UIScreen.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>
extern NSString *const UIScreenDidConnectNotification;
extern NSString *const UIScreenDidDisconnectNotification;
extern NSString *const UIScreenModeDidChangeNotification;

@class UIKitView, UIScreenMode, UIWindow;
@interface UIScreen : NSObject
+ (UIScreen *)mainScreen;
+ (NSArray *)screens;

@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic, readonly) CGRect applicationFrame;
@property (nonatomic, readonly, copy) NSArray *availableModes;      // only ever returns the currentMode
@property (nonatomic, strong) UIScreenMode *currentMode;            // ignores any attempt to set this
@property (nonatomic, readonly) CGFloat scale;
@property (nonatomic) CGFloat brightness;                           // not implemented, of course
@end
