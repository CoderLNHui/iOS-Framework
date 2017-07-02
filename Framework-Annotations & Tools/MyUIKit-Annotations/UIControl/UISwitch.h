/*
 * UISwitch.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2008-2015
 * Created by 【Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */



#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UISwitch : UIControl <NSCoding>

@property(nullable, nonatomic, strong) UIColor *onTintColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property(null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(6_0);
@property(nullable, nonatomic, strong) UIColor *thumbTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

@property(nullable, nonatomic, strong) UIImage *onImage NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;
@property(nullable, nonatomic, strong) UIImage *offImage NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

@property(nonatomic,getter=isOn) BOOL on;

- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;      // This class enforces a size appropriate for the control, and so the frame size is ignored.
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (void)setOn:(BOOL)on animated:(BOOL)animated; // does not send action

@end

NS_ASSUME_NONNULL_END
