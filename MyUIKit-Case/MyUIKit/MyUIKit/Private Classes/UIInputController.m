//
//  UIInputController.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIInputController.h"
#import "UIView+UIPrivate.h"
#import "UIWindow+UIPrivate.h"
#import "UIScreen.h"
#import "UIGeometry.h"


static UIView *ContainerForView(UIView *view)
{
    UIView *containerView = view;
    
    while (containerView && !([containerView isKindOfClass:[UIWindow class]] || [containerView _viewController])) {
        containerView = [containerView superview];
    }
    
    return containerView;
}


@implementation UIInputController {
    UIWindow *_inputWindow;
}

+ (UIInputController *)sharedInputController
{
    static UIInputController *controller = nil;
    
    if (!controller) {
        controller = [[self alloc] init];
    }
    
    return controller;
}

- (id)init
{
    if ((self=[super init])) {
        _inputWindow = [[UIWindow alloc] initWithFrame:CGRectZero];
        _inputWindow.windowLevel = UIWindowLevelStatusBar;
        
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(_viewChangedNotification:) name:UIViewFrameDidChangeNotification object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(_viewChangedNotification:) name:UIViewDidMoveToSuperviewNotification object:nil];
    }
    return self;
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
}

- (UIView *)_referenceView
{
    UIResponder *firstResponder = self.keyInputResponder;
    
    if (firstResponder) {
        UIResponder *currentResponder = firstResponder;
    
        while (currentResponder) {
            if ([currentResponder isKindOfClass:[UIView class]]) {
                return (UIView *)currentResponder;
            } else {
                currentResponder = [currentResponder nextResponder];
            }
        }
    }
    
    return nil;
}

- (void)_repositionInputWindow
{
    UIView *referenceView = [self _referenceView];
    UIView *containerView = ContainerForView(referenceView);
    UIScreen *screen = containerView.window.screen;
    
    if (screen && containerView) {
        _inputWindow.screen = screen;
        
        const CGRect viewFrameInWindow = [referenceView convertRect:referenceView.bounds toView:nil];
        const CGRect viewFrameInScreen = [referenceView.window convertRect:viewFrameInWindow toWindow:nil];
        
        const CGRect containerFrameInWindow = [containerView convertRect:containerView.bounds toView:nil];
        const CGRect containerFrameInScreen = [containerView.window convertRect:containerFrameInWindow toWindow:nil];
        
        const CGFloat inputWidth = CGRectGetWidth(containerFrameInScreen);
        CGFloat inputHeight = 0;
        
        if (_inputAccessoryView) {
            const CGFloat height = _inputAccessoryView.frame.size.height;
            _inputAccessoryView.autoresizingMask = UIViewAutoresizingNone;
            _inputAccessoryView.frame = CGRectMake(0, inputHeight, inputWidth, height);
            inputHeight += height;
        }
        
        if (_inputView) {
            const CGFloat height = _inputView.frame.size.height;
            _inputView.autoresizingMask = UIViewAutoresizingNone;
            _inputView.frame = CGRectMake(0, inputHeight, inputWidth, height);
            inputHeight += height;
        }
        
        _inputWindow.frame = CGRectMake(CGRectGetMinX(containerFrameInScreen), CGRectGetMaxY(viewFrameInScreen), inputWidth, inputHeight);
    }
}

- (void)_viewChangedNotification:(NSNotification *)note
{
    if (self.inputVisible) {
        UIView *view = [note object];
        UIView *referenceView = [self _referenceView];
        
        if (view == referenceView || [ContainerForView(referenceView) isDescendantOfView:view]) {
            [self _repositionInputWindow];
        }
    }
}

- (void)setInputVisible:(BOOL)visible animated:(BOOL)animated
{
    [self _repositionInputWindow];
    
    NSDictionary *fakeAnimationInfo = [NSDictionary dictionaryWithObjectsAndKeys:
                                       [NSValue valueWithCGRect:_inputWindow.frame], UIKeyboardFrameBeginUserInfoKey,
                                       [NSValue valueWithCGRect:_inputWindow.frame], UIKeyboardFrameEndUserInfoKey,
                                       [NSNumber numberWithDouble:0], UIKeyboardAnimationDurationUserInfoKey,
                                       [NSNumber numberWithInt:UIViewAnimationCurveLinear], UIKeyboardAnimationCurveUserInfoKey,
                                       nil];
    
    if (visible) {
        [[NSNotificationCenter defaultCenter] postNotificationName:UIKeyboardWillShowNotification object:nil userInfo:fakeAnimationInfo];
    } else {
        [[NSNotificationCenter defaultCenter] postNotificationName:UIKeyboardWillHideNotification object:nil userInfo:fakeAnimationInfo];
    }
    
    _inputWindow.hidden = !visible;
    
    if (visible) {
        [[NSNotificationCenter defaultCenter] postNotificationName:UIKeyboardDidShowNotification object:nil userInfo:fakeAnimationInfo];
    } else {
        [[NSNotificationCenter defaultCenter] postNotificationName:UIKeyboardDidHideNotification object:nil userInfo:fakeAnimationInfo];
    }
}

- (void)setInputVisible:(BOOL)inputVisible
{
    [self setInputVisible:inputVisible animated:NO];
}

- (BOOL)inputVisible
{
    return !_inputWindow.hidden;
}

- (void)setInputAccessoryView:(UIView *)view
{
    if (view != _inputAccessoryView) {
        [_inputAccessoryView removeFromSuperview];
        
        _inputAccessoryView = view;
        [_inputWindow addSubview:_inputAccessoryView];
    }
}

- (void)setInputView:(UIView *)view
{
    if (view != _inputView) {
        [_inputView removeFromSuperview];
        
        _inputView = view;
        [_inputWindow addSubview:_inputView];
    }
}



@end
