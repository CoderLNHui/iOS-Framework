/*
 * UITapGestureRecognizer.h 
 *
 * Framework: UIKit (c) 2008-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

// Recognizes: when numberOfTouchesRequired have tapped numberOfTapsRequired times

// Touch Location Behaviors:
//     locationInView:         location of the tap, from the first tap in the sequence if numberOfTapsRequired > 1. this is the centroid if numberOfTouchesRequired > 1
//     locationOfTouch:inView: location of a particular touch, from the first tap in the sequence if numberOfTapsRequired > 1

NS_CLASS_AVAILABLE_IOS(3_2) @interface UITapGestureRecognizer : UIGestureRecognizer

/**
 设置点击次数, 例如连续敲击2次
 */
@property (nonatomic) NSUInteger  numberOfTapsRequired;       // Default is 1. The number of taps required to match
/**
 需要几根手指一起敲击
 */
@property (nonatomic) NSUInteger  numberOfTouchesRequired __TVOS_PROHIBITED;    // Default is 1. The number of fingers required to match

@end

START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
NS_ASSUME_NONNULL_END
