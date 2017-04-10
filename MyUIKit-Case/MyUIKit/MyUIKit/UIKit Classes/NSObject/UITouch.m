//
//  UITouch.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UITouch.h"
#import "UIGestureRecognizer.h"
#import "UIView.h"
#import "UIWindow.h"
#import "UIView+UIPrivate.h"

@implementation UITouch
{
    CGPoint _locationOnScreen;
    CGPoint _previousLocationOnScreen;
    NSMutableArray *_gestureRecognizers;
    BOOL _wasDeliveredToView;
    BOOL _wasCancelledInView;
    NSTimeInterval _beganPhaseTimestamp;
    CGPoint _beganPhaseLocationOnScreen;
}

- (id)init
{
    if ((self=[super init])) {
        _phase = UITouchPhaseBegan;
        _timestamp = [NSDate timeIntervalSinceReferenceDate];
        _gestureRecognizers = [NSMutableArray new];
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(_viewDidMoveToSuperviewNotification:) name:UIViewDidMoveToSuperviewNotification object:nil];
    }
    return self;
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIViewDidMoveToSuperviewNotification object:nil];
}

- (void)_viewDidMoveToSuperviewNotification:(NSNotification *)notification
{
    if ([_view isDescendantOfView:[notification object]]) {
        _view = nil;
    }
}

- (void)setTimestamp:(NSTimeInterval)timestamp
{
    _timestamp = timestamp;
    
    if (_phase == UITouchPhaseBegan) {
        _beganPhaseTimestamp = timestamp;
    }
}

- (void)setTapCount:(NSUInteger)tapCount
{
    _tapCount = tapCount;
}

- (void)setPhase:(UITouchPhase)phase
{
    _phase = phase;
    
    if (phase == UITouchPhaseStationary || phase == UITouchPhaseBegan) {
        _previousLocationOnScreen = _locationOnScreen;
    }
}

- (void)setView:(UIView *)view
{
    _view = view;
    _window = view.window;
}

- (CGPoint)locationOnScreen
{
    return _locationOnScreen;
}

- (void)setLocationOnScreen:(CGPoint)locationOnScreen
{
    _previousLocationOnScreen = _locationOnScreen;
    _locationOnScreen = locationOnScreen;
    
    if (_phase == UITouchPhaseStationary || _phase == UITouchPhaseBegan) {
        _previousLocationOnScreen = locationOnScreen;
    }
    
    if (_phase == UITouchPhaseBegan) {
        _beganPhaseLocationOnScreen = locationOnScreen;
    }
}

- (BOOL)wasDeliveredToView
{
    return _wasDeliveredToView;
}

- (void)setWasDeliveredToView:(BOOL)wasDeliveredToView
{
    _wasDeliveredToView = wasDeliveredToView;
}

- (BOOL)wasCancelledInView
{
    return _wasCancelledInView;
}

- (void)setWasCancelledInView:(BOOL)wasCancelledInView
{
    _wasCancelledInView = wasCancelledInView;
}

- (NSTimeInterval)beganPhaseTimestamp
{
    return _beganPhaseTimestamp;
}

- (CGPoint)beganPhaseLocationOnScreen
{
    return _beganPhaseLocationOnScreen;
}

- (NSArray *)gestureRecognizers
{
    return [_gestureRecognizers copy];
}

- (void)_addGestureRecognizer:(UIGestureRecognizer *)gesture
{
    [_gestureRecognizers addObject:gesture];
}

- (void)_removeGestureRecognizer:(UIGestureRecognizer *)gesture
{
    [_gestureRecognizers removeObject:gesture];
}

- (CGPoint)locationInView:(UIView *)inView
{
    return [self.window convertPoint:[self.window convertPoint:_locationOnScreen fromWindow:nil] toView:inView];
}

- (CGPoint)previousLocationInView:(UIView *)inView
{
    return [self.window convertPoint:[self.window convertPoint:_previousLocationOnScreen fromWindow:nil] toView:inView];
}

- (NSString *)description
{
    NSString *phase = @"";
    
    switch (self.phase) {
        case UITouchPhaseBegan:
            phase = @"Began";
            break;
        case UITouchPhaseMoved:
            phase = @"Moved";
            break;
        case UITouchPhaseStationary:
            phase = @"Stationary";
            break;
        case UITouchPhaseEnded:
            phase = @"Ended";
            break;
        case UITouchPhaseCancelled:
            phase = @"Cancelled";
            break;
    }
    
    return [NSString stringWithFormat:@"<%@: %p; timestamp = %e; tapCount = %lu; phase = %@; view = %@; window = %@>", [self className], self, self.timestamp, (unsigned long)self.tapCount, phase, self.view, self.window];
}



@end
