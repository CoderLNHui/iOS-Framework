//  2017.3.5   完全实现ok
//  UIResponder.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIEvent.h"

@interface UIResponder : NSObject

- (UIResponder *)nextResponder;
- (BOOL)isFirstResponder;
- (BOOL)canBecomeFirstResponder;
- (BOOL)becomeFirstResponder;
- (BOOL)canResignFirstResponder;
- (BOOL)resignFirstResponder;

- (BOOL)canPerformAction:(SEL)action withSender:(id)sender;

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;

- (void)motionBegan:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionEnded:(UIEventSubtype)motion withEvent:(UIEvent *)event;
- (void)motionCancelled:(UIEventSubtype)motion withEvent:(UIEvent *)event;

@property (nonatomic, readonly) NSArray *keyCommands;

@property (readonly, strong) UIView *inputAccessoryView;
@property (readonly, strong) UIView *inputView;
@property (readonly) NSUndoManager *undoManager;

@end

typedef NS_OPTIONS(NSInteger, UIKeyModifierFlags) {
    UIKeyModifierAlphaShift     = 1 << 16,  // capslock
    UIKeyModifierShift          = 1 << 17,
    UIKeyModifierControl        = 1 << 18,
    UIKeyModifierAlternate      = 1 << 19,
    UIKeyModifierCommand        = 1 << 20,
    UIKeyModifierNumericPad     = 1 << 21,
};

extern NSString *const UIKeyInputUpArrow;
extern NSString *const UIKeyInputDownArrow;
extern NSString *const UIKeyInputLeftArrow;
extern NSString *const UIKeyInputRightArrow;
extern NSString *const UIKeyInputEscape;

@interface UIKeyCommand : NSObject <NSCopying, NSSecureCoding>
+ (UIKeyCommand *)keyCommandWithInput:(NSString *)input modifierFlags:(UIKeyModifierFlags)modifierFlags action:(SEL)action;
@property (nonatomic,readonly) NSString *input;
@property (nonatomic,readonly) UIKeyModifierFlags modifierFlags;
@end

@interface NSObject (UIResponderStandardEditActions)
- (void)copy:(id)sender;
- (void)cut:(id)sender;
- (void)delete:(id)sender;
- (void)paste:(id)sender;
- (void)select:(id)sender;
- (void)selectAll:(id)sender;

- (void)makeTextWritingDirectionLeftToRight:(id)sender;
- (void)makeTextWritingDirectionRightToLeft:(id)sender;
- (void)toggleBoldface:(id)sender;
- (void)toggleItalics:(id)sender;
- (void)toggleUnderline:(id)sender;

- (void)increaseSize:(id)sender;
- (void)decreaseSize:(id)sender;
@end
