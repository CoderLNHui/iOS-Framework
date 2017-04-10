//
//  UITouchEvent.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/10.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIEvent.h"

@class UITouch;

typedef NS_ENUM(NSInteger, UITouchEventGesture) {
    UITouchEventGestureNone,
    UITouchEventGestureBegin,
    UITouchEventGesturePinch,
    UITouchEventGestureRotate,
    UITouchEventGesturePan,

};
@interface UITouchEvent : UIEvent

- (id)initWithTouch:(UITouch *)touch;
- (void)endTouchEvent;

@property (nonatomic, readonly, strong) UITouch *touch;
@property (nonatomic, readwrite, assign) UITouchEventGesture touchEventGesture;     // default UITouchEventGestureNone
@property (nonatomic, readonly) BOOL isDiscreteGesture;
@property (nonatomic, readwrite, assign) CGPoint translation;
@property (nonatomic, readwrite, assign) CGFloat rotation;
@property (nonatomic, readwrite, assign) CGFloat magnification;

@end
