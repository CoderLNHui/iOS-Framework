/*
 * UIScreenEdgePanGestureRecognizer.h 
 *
 * UIKit (c) 2012-2017
 */

 
#import <UIKit/UIGeometry.h>
#import <UIKit/UIPanGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

/*! This subclass of UIPanGestureRecognizer only recognizes if the user slides their finger
 in from the bezel on the specified edge. */
NS_CLASS_AVAILABLE_IOS(7_0) __TVOS_PROHIBITED @interface UIScreenEdgePanGestureRecognizer : UIPanGestureRecognizer
@property (readwrite, nonatomic, assign) UIRectEdge edges; //< The edges on which this gesture recognizes, relative to the current interface orientation
@end

CoderLN_NOTE NS_ASSUME_NONNULL_END
