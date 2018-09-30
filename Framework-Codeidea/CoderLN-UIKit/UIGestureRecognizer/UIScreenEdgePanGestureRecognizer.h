/*
 * UIScreenEdgePanGestureRecognizer.h 
 *
 * UIKit (c) 2012-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
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
