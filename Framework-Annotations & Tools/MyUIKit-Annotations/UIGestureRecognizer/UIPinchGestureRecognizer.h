/*
 * UIPinchGestureRecognizer.h
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2008-2015
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
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

START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
NS_ASSUME_NONNULL_END
