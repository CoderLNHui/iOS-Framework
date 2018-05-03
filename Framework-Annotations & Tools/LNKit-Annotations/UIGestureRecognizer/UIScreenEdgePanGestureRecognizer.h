/*
 * UIScreenEdgePanGestureRecognizer.h 
 *
 * Framework: UIKit (c) 2012-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

 
#import <UIKit/UIGeometry.h>
#import <UIKit/UIPanGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

/*! This subclass of UIPanGestureRecognizer only recognizes if the user slides their finger
 in from the bezel on the specified edge. */
NS_CLASS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED @interface UIScreenEdgePanGestureRecognizer : UIPanGestureRecognizer
@property (readwrite, nonatomic, assign) UIRectEdge edges; //< The edges on which this gesture recognizes, relative to the current interface orientation
@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
