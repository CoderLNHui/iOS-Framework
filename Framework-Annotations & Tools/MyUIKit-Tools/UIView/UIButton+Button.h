/*
 * UIButton+Button.h
 * 🔍白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <UIKit/UIKit.h>

@interface UIButton (Button)

@end


@interface UIButton (BackgroundColor)

/** 设置state状态下的backgroundColor */
- (void)setBackgroundColor:(UIColor *)backgroundColor forState:(UIControlState)state;

@end


@interface UIButton (Badge)

@property (strong, nonatomic) UILabel *badge;

/** badge的文字 */
@property (nonatomic) NSString *badgeValue;

/** 背景颜色 */
@property (nonatomic) UIColor *badgeBGColor;

/** 文字颜色 */
@property (nonatomic) UIColor *badgeTextColor;

/** 文字的字体 */
@property (nonatomic) UIFont *badgeFont;

/** badge的padding */
@property (nonatomic) CGFloat badgePadding;

/** 最小的size */
@property (nonatomic) CGFloat badgeMinSize;

/** x坐标 */
@property (nonatomic) CGFloat badgeOriginX;

/** y坐标 */
@property (nonatomic) CGFloat badgeOriginY;

/** 如果是数字0的话就隐藏不显示 */
@property BOOL shouldHideBadgeAtZero;

/** 是否要缩放动画 */
@property BOOL shouldAnimateBadge;

@end


@interface UIButton (Block)

typedef void (^TouchedButtonBlock)(void);
- (void)addActionHandler:(TouchedButtonBlock)touchHandler;

@end



/** 改变按钮的响应区域 */
@interface UIButton (ClickEdgeInsets)

/** 上左下右分别增加或减小多少  正数为增加 负数为减小*/
@property (nonatomic, assign) UIEdgeInsets clickEdgeInsets;

@end



@interface UIButton (CountDown)

/**
 倒计时按钮
 
 @param timeout     总时间
 @param waitBlock   倒计时过程中可以再里面做一些操作
 @param finishBlock 完成时执行的block
 */
- (void)startTime:(NSInteger)timeout waitBlock:(void(^)(NSInteger remainTime))waitBlock finishBlock:(void(^)())finishBlock;

@end


/** 提交按钮: 提交时在中间显示一个菊花 */
@interface UIButton (Indicator)

/** 显示菊花 */
- (void)showIndicator;

/** 隐藏菊花 */
- (void)hideIndicator;

@end


@interface UIButton (Create)


+ (UIButton*) createButtonWithFrame: (CGRect) frame Target:(id)target Selector:(SEL)selector Image:(NSString *)image ImagePressed:(NSString *)imagePressed;

+ (UIButton *) createButtonWithFrame:(CGRect)frame Title:(NSString *)title Target:(id)target Selector:(SEL)selector;


@end


