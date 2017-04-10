//
//  UINavigationItem.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/7.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UIBarButtonItem, UIView;

@interface UINavigationItem : NSObject
- (id)initWithTitle:(NSString *)title;
- (void)setLeftBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated;
- (void)setRightBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated;
- (void)setHidesBackButton:(BOOL)hidesBackButton animated:(BOOL)animated;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *prompt;
@property (nonatomic, strong) UIBarButtonItem *backBarButtonItem;
@property (nonatomic, strong) UIBarButtonItem *leftBarButtonItem;
@property (nonatomic, strong) UIBarButtonItem *rightBarButtonItem;
@property (nonatomic, strong) UIView *titleView;
@property (nonatomic, assign) BOOL hidesBackButton;
@end
