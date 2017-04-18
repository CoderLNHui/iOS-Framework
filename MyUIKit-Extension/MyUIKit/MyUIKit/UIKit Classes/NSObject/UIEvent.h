//  UIEvent  完全实现ok
//  UIEvent.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UIEventType) {
    UIEventTypeTouches,
    UIEventTypeMotion,
    
    // nonstandard
    UIEventTypeKeyboard,
    UIEventTypeAction
};

typedef NS_ENUM(NSInteger, UIEventSubtype) {
    UIEventSubtypeNone        = 0,
    UIEventSubtypeMotionShake = 1,
};

@class UIWindow, UIView, UIGestureRecognizer;

@interface UIEvent : NSObject

- (NSSet *)allTouches;
- (NSSet *)touchesForView:(UIView *)view;
- (NSSet *)touchesForWindow:(UIWindow *)window;
- (NSSet *)touchesForGestureRecognizer:(UIGestureRecognizer *)gesture;

@property (nonatomic, readonly) NSTimeInterval timestamp;
@property (nonatomic, readonly) UIEventType type;
@property (nonatomic, readonly) UIEventSubtype subtype;
@end
