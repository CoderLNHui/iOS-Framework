//  UIInputController 私有类    完全实现ok
//  UIInputController.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIResponder.h"
#import "UITextInput.h"

@class UIView, UIWindow;

@interface UIInputController : NSObject

+ (UIInputController *)sharedInputController;

- (void)setInputVisible:(BOOL)visible animated:(BOOL)animated;

@property (nonatomic, strong) UIView *inputAccessoryView;
@property (nonatomic, strong) UIView *inputView;
@property (nonatomic, weak) UIResponder <UIKeyInput> *keyInputResponder;
@property (nonatomic, assign) BOOL inputVisible;

@end
