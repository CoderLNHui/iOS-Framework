/*
 * UIPanGestureRecognizer.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2008-2016
 * Created by 【🔍Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGestureRecognizer.h>

// Begins:  when at least minimumNumberOfTouches have moved enough to be considered a pan
// Changes: when a finger moves while at least minimumNumberOfTouches are down
// Ends:    when all fingers have lifted

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(3_2) @interface UIPanGestureRecognizer : UIGestureRecognizer

@property (nonatomic)          NSUInteger minimumNumberOfTouches __TVOS_PROHIBITED;   // default is 1. the minimum number of touches required to match
@property (nonatomic)          NSUInteger maximumNumberOfTouches __TVOS_PROHIBITED;   // default is UINT_MAX. the maximum number of touches that can be down

- (CGPoint)translationInView:(nullable UIView *)view;                        // translation in the coordinate system of the specified view
- (void)setTranslation:(CGPoint)translation inView:(nullable UIView *)view;

- (CGPoint)velocityInView:(nullable UIView *)view;                           // velocity of the pan in points/second in the coordinate system of the specified view

@end

NS_ASSUME_NONNULL_END
