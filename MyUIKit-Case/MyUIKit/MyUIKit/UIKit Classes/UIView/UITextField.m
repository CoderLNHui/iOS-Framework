//
//  UITextField.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/10.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UITextField.h"

NSString *const UITextFieldTextDidBeginEditingNotification = @"UITextFieldTextDidBeginEditingNotification";
NSString *const UITextFieldTextDidChangeNotification = @"UITextFieldTextDidChangeNotification";
NSString *const UITextFieldTextDidEndEditingNotification = @"UITextFieldTextDidEndEditingNotification";

@interface UIControl ()
@end

@interface UITextField ()
@end

@implementation UITextField 
   
    

@end


@implementation UIView (UITextField)

- (BOOL)endEditing:(BOOL)force
{
    if ([self isFirstResponder]) {
        if (force || [self canResignFirstResponder]) {
            return [self resignFirstResponder];
        }
    } else {
        for (UIView *view in self.subviews) {
            if ([view endEditing:force]) {
                return YES;
            }
        }
    }
    
    return NO;
}

@end
