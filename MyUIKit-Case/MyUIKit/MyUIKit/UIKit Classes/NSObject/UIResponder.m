//  UIResponder是一个比较重要的类，很多常用的类都是它的子类或者子类的子类，与响应者链条关系密切
//  UIResponder.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIResponder.h"
#import "UIWindow+UIPrivate.h"
#import "UIInputController.h"

@implementation UIResponder

- (UIResponder *)nextResponder
{
    return nil;
}

- (UIWindow *)_responderWindow
{
    if ([self isKindOfClass:[UIView class]]) {
        return [(UIView *)self window];
    } else {
        return [[self nextResponder] _responderWindow];
    }
}

- (BOOL)isFirstResponder
{
    return ([[self _responderWindow] _firstResponder] == self);
}

- (BOOL)canBecomeFirstResponder
{
    return NO;
}

#pragma mark - 成为第一响应者
- (BOOL)becomeFirstResponder
{
    if ([self isFirstResponder]) {
        return YES;
    } else {
        UIWindow *window = [self _responderWindow];
        UIResponder *firstResponder = [window _firstResponder];
        
        if (window && [self canBecomeFirstResponder]) {
            BOOL didResign = NO;
            
            if (firstResponder && [firstResponder canResignFirstResponder]) {
                didResign = [firstResponder resignFirstResponder];
            } else {
                didResign = YES;
            }
            
            if (didResign) {
                [window _setFirstResponder:self];
                
                if ([self conformsToProtocol:@protocol(UIKeyInput)]) {
                    
                    UIInputController *controller = [UIInputController sharedInputController];
                    controller.inputAccessoryView = self.inputAccessoryView;
                    controller.inputView = self.inputView;
                    controller.keyInputResponder = (UIResponder<UIKeyInput> *)self;
                    [controller setInputVisible:YES animated:YES];
                    
                    [window makeKeyWindow];
                }
                
                return YES;
            }
        }
        
        return NO;
    }
}

- (BOOL)canResignFirstResponder
{
    return YES;
}

- (BOOL)resignFirstResponder
{
    if ([self isFirstResponder]) {
        [[self _responderWindow] _setFirstResponder:nil];
        [[UIInputController sharedInputController] setInputVisible:NO animated:YES];
    }
    
    return YES;
}
- (BOOL)canPerformAction:(SEL)action withSender:(id)sender
{
    if ([[self class] instancesRespondToSelector:action]) {
        return YES;
    } else {
        return [[self nextResponder] canPerformAction:action withSender:sender];
    }
}
- (NSArray *)keyCommands
{
    return nil;
}
- (UIView *)inputAccessoryView
{
    return nil;
}

- (UIView *)inputView
{
    return nil;
}
- (NSUndoManager *)undoManager
{
    return [[self nextResponder] undoManager];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    [[self nextResponder] touchesBegan:touches withEvent:event];
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    [[self nextResponder] touchesMoved:touches withEvent:event];
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    [[self nextResponder] touchesEnded:touches withEvent:event];
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    [[self nextResponder] touchesCancelled:touches withEvent:event];
}

- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
    [[self nextResponder] motionBegan:motion withEvent:event];
}

- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
    [[self nextResponder] motionEnded:motion withEvent:event];
}

- (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event
{
    [[self nextResponder] motionCancelled:motion withEvent:event];
}

@end


@implementation UIKeyCommand

+ (UIKeyCommand *)keyCommandWithInput:(NSString *)input modifierFlags:(UIKeyModifierFlags)modifierFlags action:(SEL)action
{
    // TODO
    return nil;
}

+ (BOOL)supportsSecureCoding
{
    return YES;
}

- (id)initWithCoder:(NSCoder *)decoder
{
    return [self init];
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
    // TODO
}

- (id)copyWithZone:(NSZone *)zone
{
    return self;
}

NSString *const UIKeyInputUpArrow = @"UIKeyInputUpArrow";
NSString *const UIKeyInputDownArrow = @"UIKeyInputDownArrow";
NSString *const UIKeyInputLeftArrow = @"UIKeyInputLeftArrow";
NSString *const UIKeyInputRightArrow = @"UIKeyInputRightArrow";
NSString *const UIKeyInputEscape = @"UIKeyInputEscape";

@end
