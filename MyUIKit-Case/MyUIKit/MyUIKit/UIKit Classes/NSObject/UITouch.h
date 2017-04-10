//  完全实现
//  UITouch.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UITouchPhase) {
    UITouchPhaseBegan,
    UITouchPhaseMoved,
    UITouchPhaseStationary,
    UITouchPhaseEnded,
    UITouchPhaseCancelled,
};

@class UIView, UIWindow;

@interface UITouch : NSObject
- (CGPoint)locationInView:(UIView *)inView;
- (CGPoint)previousLocationInView:(UIView *)inView;

@property (nonatomic, readonly) NSTimeInterval timestamp;
@property (nonatomic, readonly) NSUInteger tapCount;
@property (nonatomic, readonly) UITouchPhase phase;
@property (nonatomic, readonly, strong) UIView *view;
@property (nonatomic, readonly, strong) UIWindow *window;
@property (nonatomic, readonly, copy) NSArray *gestureRecognizers;

@end
