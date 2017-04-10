//
//  UIGestureRecognizer.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIGestureRecognizer.h"
#import "UIAction.h"
#import "UITouch.h"
#import "UIEvent.h"
#import "UITouch+UIPrivate.h"
#import "UITouchEvent.h"


@implementation UIGestureRecognizer
{
    NSMutableArray *_registeredActions;
    NSMutableArray *_trackingTouches;
    __unsafe_unretained UIView *_view;
    
    struct {
        unsigned shouldBegin : 1;
        unsigned shouldReceiveTouch : 1;
        unsigned shouldRecognizeSimultaneouslyWithGestureRecognizer : 1;
    } _delegateHas;
}

- (id)initWithTarget:(id)target action:(SEL)action
{
    if ((self=[super init])) {
        _state = UIGestureRecognizerStatePossible;
        _cancelsTouchesInView = YES;
        _delaysTouchesBegan = NO;
        _delaysTouchesEnded = YES;
        _enabled = YES;
        
        _registeredActions = [[NSMutableArray alloc] initWithCapacity:1];
        _trackingTouches = [[NSMutableArray alloc] initWithCapacity:1];
        
        [self addTarget:target action:action];
    }
    return self;
}

- (void)_setView:(UIView *)v
{
    if (v != _view) {
        [self reset]; // not sure about this, but I think it makes sense
        _view = v;
    }
}

- (void)setDelegate:(id<UIGestureRecognizerDelegate>)aDelegate
{
    if (aDelegate != _delegate) {
        _delegate = aDelegate;
        _delegateHas.shouldBegin = [_delegate respondsToSelector:@selector(gestureRecognizerShouldBegin:)];
        _delegateHas.shouldReceiveTouch = [_delegate respondsToSelector:@selector(gestureRecognizer:shouldReceiveTouch:)];
        _delegateHas.shouldRecognizeSimultaneouslyWithGestureRecognizer = [_delegate respondsToSelector:@selector(gestureRecognizer:shouldRecognizeSimultaneouslyWithGestureRecognizer:)];
    }
}

- (void)addTarget:(id)target action:(SEL)action
{
    NSAssert(target != nil, @"target must not be nil");
    NSAssert(action != NULL, @"action must not be NULL");
    
    UIAction *actionRecord = [[UIAction alloc] init];
    actionRecord.target = target;
    actionRecord.action = action;
    [_registeredActions addObject:actionRecord];
}

- (void)removeTarget:(id)target action:(SEL)action
{
    UIAction *actionRecord = [[UIAction alloc] init];
    actionRecord.target = target;
    actionRecord.action = action;
    [_registeredActions removeObject:actionRecord];
}

- (void)requireGestureRecognizerToFail:(UIGestureRecognizer *)otherGestureRecognizer
{
}

- (NSUInteger)numberOfTouches
{
    return [_trackingTouches count];
}

- (CGPoint)locationInView:(UIView *)view
{
    CGFloat x = 0;
    CGFloat y = 0;
    CGFloat k = 0;
    
    for (UITouch *touch in _trackingTouches) {
        const CGPoint p = [touch locationInView:view];
        x += p.x;
        y += p.y;
        k++;
    }
    
    if (k > 0) {
        return CGPointMake(x/k, y/k);
    } else {
        return CGPointZero;
    }
}

- (CGPoint)locationOfTouch:(NSUInteger)touchIndex inView:(UIView *)view
{
    return [[_trackingTouches objectAtIndex:touchIndex] locationInView:view];
}

- (void)setState:(UIGestureRecognizerState)state
{
    if (_delegateHas.shouldBegin && _state == UIGestureRecognizerStatePossible && (state == UIGestureRecognizerStateRecognized || state == UIGestureRecognizerStateBegan)) {
        if (![_delegate gestureRecognizerShouldBegin:self]) {
            state = UIGestureRecognizerStateFailed;
        }
    }
    
    typedef struct { UIGestureRecognizerState fromState, toState; BOOL shouldNotify; } StateTransition;
    
#define NumberOfStateTransitions 9
    static const StateTransition allowedTransitions[NumberOfStateTransitions] = {
        // discrete gestures
        {UIGestureRecognizerStatePossible,		UIGestureRecognizerStateRecognized,     YES},
        {UIGestureRecognizerStatePossible,		UIGestureRecognizerStateFailed,          NO},
        
        // continuous gestures
        {UIGestureRecognizerStatePossible,		UIGestureRecognizerStateBegan,          YES},
        {UIGestureRecognizerStateBegan,			UIGestureRecognizerStateChanged,        YES},
        {UIGestureRecognizerStateBegan,			UIGestureRecognizerStateCancelled,      YES},
        {UIGestureRecognizerStateBegan,			UIGestureRecognizerStateEnded,          YES},
        {UIGestureRecognizerStateChanged,		UIGestureRecognizerStateChanged,        YES},
        {UIGestureRecognizerStateChanged,		UIGestureRecognizerStateCancelled,      YES},
        {UIGestureRecognizerStateChanged,		UIGestureRecognizerStateEnded,          YES}
    };
    
    const StateTransition *transition = NULL;
    
    for (NSUInteger t=0; t<NumberOfStateTransitions; t++) {
        if (allowedTransitions[t].fromState == _state && allowedTransitions[t].toState == state) {
            transition = &allowedTransitions[t];
            break;
        }
    }
    
    NSAssert2((transition != NULL), @"invalid state transition from %ld to %ld", _state, state);
    
    if (transition) {
        _state = transition->toState;
        
        if (transition->shouldNotify) {
            for (UIAction *actionRecord in _registeredActions) {
               
                [actionRecord.target performSelector:actionRecord.action withObject:self afterDelay:0];
            }
        }
    }
}

- (void)reset
{
    _state = UIGestureRecognizerStatePossible;
}

- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer *)preventedGestureRecognizer
{
    return YES;
}

- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer *)preventingGestureRecognizer
{
    return YES;
}

- (void)ignoreTouch:(UITouch *)touch forEvent:(UIEvent*)event
{
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)_beginTrackingTouch:(UITouch *)touch withEvent:(UITouchEvent *)event
{
    if (self.enabled) {
        if (!_delegateHas.shouldReceiveTouch || [_delegate gestureRecognizer:self shouldReceiveTouch:touch]) {
            [touch _addGestureRecognizer:self];
            [_trackingTouches addObject:touch];
        }
    }
}

- (void)_continueTrackingWithEvent:(UITouchEvent *)event
{
    NSMutableSet *began = [NSMutableSet new];
    NSMutableSet *moved = [NSMutableSet new];
    NSMutableSet *ended = [NSMutableSet new];
    NSMutableSet *cancelled = [NSMutableSet new];
    BOOL multitouchSequenceIsEnded = YES;
    
    for (UITouch *touch in _trackingTouches) {
        if (touch.phase == UITouchPhaseBegan) {
            multitouchSequenceIsEnded = NO;
            [began addObject:touch];
        } else if (touch.phase == UITouchPhaseMoved) {
            multitouchSequenceIsEnded = NO;
            [moved addObject:touch];
        } else if (touch.phase == UITouchPhaseStationary) {
            multitouchSequenceIsEnded = NO;
        } else if (touch.phase == UITouchPhaseEnded) {
            [ended addObject:touch];
        } else if (touch.phase == UITouchPhaseCancelled) {
            [cancelled addObject:touch];
        }
    }
    
    if (_state == UIGestureRecognizerStatePossible || _state == UIGestureRecognizerStateBegan || _state == UIGestureRecognizerStateChanged) {
        if ([began count]) {
            [self touchesBegan:began withEvent:event];
        }
        
        if ([moved count]) {
            [self touchesMoved:moved withEvent:event];
        }
        
        if ([ended count]) {
            [self touchesEnded:ended withEvent:event];
        }
        
        if ([cancelled count]) {
            [self touchesCancelled:cancelled withEvent:event];
        }
    }
    
    
    if (multitouchSequenceIsEnded || event.isDiscreteGesture) {
        
        [self performSelector:@selector(reset) withObject:nil afterDelay:0];
    }
}

- (void)_endTrackingTouch:(UITouch *)touch withEvent:(UITouchEvent *)event
{
    [touch _removeGestureRecognizer:self];
    [_trackingTouches removeObject:touch];
}

- (NSString *)description
{
    NSString *state = @"";
    switch (self.state) {
        case UIGestureRecognizerStatePossible:
            state = @"Possible";
            break;
        case UIGestureRecognizerStateBegan:
            state = @"Began";
            break;
        case UIGestureRecognizerStateChanged:
            state = @"Changed";
            break;
        case UIGestureRecognizerStateEnded:
            state = @"Ended";
            break;
        case UIGestureRecognizerStateCancelled:
            state = @"Cancelled";
            break;
        case UIGestureRecognizerStateFailed:
            state = @"Failed";
            break;
    }
    return [NSString stringWithFormat:@"<%@: %p; state = %@; view = %@>", [self className], self, state, self.view];
}

@end
