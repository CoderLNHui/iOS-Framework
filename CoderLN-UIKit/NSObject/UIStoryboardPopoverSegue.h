/*
 * UIStoryboardPopoverSegue.h
 *
 * UIKit (c) 2011-2017
 */
 
#import <UIKit/UIStoryboardSegue.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPopoverController;

NS_CLASS_DEPRECATED_IOS(5_0, 9_0, "Access destinationViewController.popoverPresentationController from your segue's performHandler or override of -perform") @interface UIStoryboardPopoverSegue : UIStoryboardSegue {
}

@property (nonatomic, strong, readonly) UIPopoverController *popoverController;

@end

CoderLN_NOTE NS_ASSUME_NONNULL_END
