//
//  UIPanGestureRecognizer.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/10.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIPanGestureRecognizer.h"
#import "UITouchEvent.h"
#import "UIGestureRecognizerSubclass.h"
#import "UITouch.h"

@implementation UIPanGestureRecognizer
{
    CGPoint _translation;
    CGPoint _velocity;
    NSTimeInterval _lastMovementTime;
}

- (id)initWithTarget:(id)target action:(SEL)action
{
    if ((self=[super initWithTarget:target action:action])) {
        _minimumNumberOfTouches = 1;
        _maximumNumberOfTouches = NSUIntegerMax;
        _translation = CGPointZero;
        _velocity = CGPointZero;
    }
    return self;
}

- (CGPoint)translationInView:(UIView *)view
{
    return _translation;
}

- (void)setTranslation:(CGPoint)translation inView:(UIView *)view
{
    _velocity = CGPointZero;
    _translation = translation;
}

- (BOOL)_translate:(CGPoint)delta withEvent:(UIEvent *)event
{
    const NSTimeInterval timeDiff = event.timestamp - _lastMovementTime;
    
    if (!CGPointEqualToPoint(delta, CGPointZero) && timeDiff > 0) {
        _translation.x += delta.x;
        _translation.y += delta.y;
        _velocity.x = delta.x / timeDiff;
        _velocity.y = delta.y / timeDiff;
        _lastMovementTime = event.timestamp;
        return YES;
    } else {
        return NO;
    }
}

- (void)reset
{
    [super reset];
    _translation = CGPointZero;
    _velocity = CGPointZero;
}

- (CGPoint)velocityInView:(UIView *)view
{
    return _velocity;
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (self.state == UIGestureRecognizerStatePossible) {
        if ([event isKindOfClass:[UITouchEvent class]]) {
            UITouchEvent *touchEvent = (UITouchEvent *)event;
            
            if (touchEvent.touchEventGesture != UITouchEventGestureBegin) {
                self.state = UIGestureRecognizerStateFailed;
            }
        }
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    if ([event isKindOfClass:[UITouchEvent class]]) {
        UITouchEvent *touchEvent = (UITouchEvent *)event;
        
        if (touchEvent.touchEventGesture == UITouchEventGesturePan) {
            if (self.state == UIGestureRecognizerStatePossible) {
                _lastMovementTime = touchEvent.timestamp;
                [self setTranslation:touchEvent.translation inView:touchEvent.touch.view];
                self.state = UIGestureRecognizerStateBegan;
            } else if ([self _translate:touchEvent.translation withEvent:event]) {
                self.state = UIGestureRecognizerStateChanged;
            }
        }
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (self.state == UIGestureRecognizerStateBegan || self.state == UIGestureRecognizerStateChanged) {
        if ([event isKindOfClass:[UITouchEvent class]]) {
            UITouchEvent *touchEvent = (UITouchEvent *)event;
            [self _translate:touchEvent.translation withEvent:touchEvent];
            self.state = UIGestureRecognizerStateEnded;
        } else {
            self.state = UIGestureRecognizerStateCancelled;
        }
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (self.state == UIGestureRecognizerStateBegan || self.state == UIGestureRecognizerStateChanged) {
        self.state = UIGestureRecognizerStateCancelled;
    }
}

@end
