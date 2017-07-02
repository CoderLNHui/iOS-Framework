/*
 * UIPinchGestureRecognizer.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2008-2015
 * Created by 【Plain Boiled Water ln】 on Elegant programming.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

// Begins:  when two touches have moved enough to be considered a pinch
// Changes: when a finger moves while two fingers remain down
// Ends:    when both fingers have lifted

NS_CLASS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED @interface UIPinchGestureRecognizer : UIGestureRecognizer

@property (nonatomic)          CGFloat scale;               // scale relative to the touch points in screen coordinates
@property (nonatomic,readonly) CGFloat velocity;            // velocity of the pinch in scale/second

@end

NS_ASSUME_NONNULL_END
