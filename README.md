>阅读源码，不仅能使我们了解作者的功能实现方式，方便我们运用其功能，快速的fix使用中遇到的bug，更重要的是在阅读优秀源码时体会作者的设计思想和架构设计，具体的技术很快就会过时，优秀的设计思想却会历久弥新，给我们今后编码以很大的借鉴和启迪。向优秀的开源者致敬！向优秀的分享者致敬！
>
>为什么要建这个仓库❓
>我非常想为这个工程增加更多实用的内容，以简化初学者入门和老司机回顾的繁索过程，尽快切入主题，快速使用起来。
>—— Agree Agree Agree
 


##### repository list

```objc
{
    UIKit .h文件 🔞
    Foundation .h文件 🔞
    OtherFramework 常用 🔞
    ProjectFile 🔞
    思维脑图 🔞
    ...

}
```

 
##### .h progress

```objc
//  UIKit.h - Copyright (c) 2005-2017 Apple Inc. All rights reserved.

#import <UIKit/UIKitDefines.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIAccelerometer.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIAccelerometer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIAccessibility.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/UIAccessibilityConstants.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIAccessibilityContentSizeCategoryImageAdjusting.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIAccessibilityContentSizeCategoryImageAdjusting.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<UIKit/UIActivityIndicatorView.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIActivityIndicatorView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIActivity.h>    <# ⦁ 注解完成#>
#import <UIKit/UIActivityItemProvider.h>    <# ⦁ 注解完成#>
#import <UIKit/UIActivityViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIActionSheet.h>    <# ⦁ 注解完成#>
#import <UIKit/UIAlertController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIAlertView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIAppearance.h>    <# ⦁ 注解完成#>
#import <UIKit/UIApplication.h>    <# ⦁ 注解完成#>
#import <UIKit/UIBarButtonItem.h>    <# ⦁ 注解完成#>
#import <UIKit/UIBarButtonItemGroup.h>    <# ⦁ 注解完成#>
#import <UIKit/UIBarItem.h>    <# ⦁ 注解完成#>
#endif


#import <UIKit/UIBezierPath.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIButton.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIButton.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollectionView.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollectionViewCell.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollectionViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollectionViewFlowLayout.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollectionViewLayout.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollectionViewTransitionLayout.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/UIColor.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIContentSizeCategoryAdjusting.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIContentSizeCategoryAdjusting.h>    <# ⦁ 注解完成#>
#import <UIKit/UIContentSizeCategory.h>    <# ⦁ 注解完成#>
#import <UIKit/UIControl.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDataDetectors.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDatePicker.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDevice.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDocument.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDocumentInteractionController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDocumentPickerViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDocumentMenuViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDocumentPickerExtensionViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UICloudSharingController.h>    <# ⦁ 注解完成#>
#import <UIKit/NSFileProviderExtension.h>    <# ⦁ 注解完成#>
#import <UIKit/UIVisualEffect.h>    <# ⦁ 注解完成#>
#import <UIKit/UIBlurEffect.h>    <# ⦁ 注解完成#>
#import <UIKit/UIVibrancyEffect.h>    <# ⦁ 注解完成#>
#import <UIKit/UIVisualEffectView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIEvent.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/UIFont.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFontDescriptor.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFontMetrics.h>    <# ⦁ 注解完成#>
#import <UIKit/UIGeometry.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIGestureRecognizer.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIGestureRecognizer.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/UIGraphics.h>    <# ⦁ 注解完成#>
#import <UIKit/UIImage.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIGraphicsRenderer.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIGraphicsRenderer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIGraphicsImageRenderer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIGraphicsPDFRenderer.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<UIKit/UIImageAsset.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIImageAsset.h>    <# ⦁ 注解完成#>
#import <UIKit/NSDataAsset.h>    <# ⦁ 注解完成#>
#import <UIKit/UIImagePickerController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIImageView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIInputView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIInputViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIInterface.h>    <# ⦁ 注解完成#>
#import <UIKit/UILabel.h>    <# ⦁ 注解完成#>
#import <UIKit/UILexicon.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/UILocalNotification.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/UIUserNotificationSettings.h>    <# ⦁ 注解完成#>)

#import <UIKit/UIApplicationShortcutItem.h>    <# ⦁ 注解完成#>
#import <UIKit/UIUserNotificationSettings.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFocus.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFocusSystem.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFocusGuide.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFocusAnimationCoordinator.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFocusDebugger.h>    <# ⦁ 注解完成#>
#import <UIKit/UILocalizedIndexedCollation.h>    <# ⦁ 注解完成#>
#import <UIKit/UILongPressGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIManagedDocument.h>    <# ⦁ 注解完成#>
#import <UIKit/UIMenuController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIMotionEffect.h>    <# ⦁ 注解完成#>
#import <UIKit/UINavigationBar.h>    <# ⦁ 注解完成#>
#import <UIKit/UINavigationController.h>    <# ⦁ 注解完成#>
#import <UIKit/UINib.h>    <# ⦁ 注解完成#>
#import <UIKit/UINibDeclarations.h>    <# ⦁ 注解完成#>
#import <UIKit/UINibLoading.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPageControl.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPageViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPanGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPasteboard.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPasteConfiguration.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPasteConfigurationSupporting.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPickerView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPinchGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPopoverController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPopoverBackgroundView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPress.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPressesEvent.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrinter.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrinterPickerController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrintError.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrintFormatter.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrintInfo.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrintInteractionController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrintPageRenderer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPrintPaper.h>    <# ⦁ 注解完成#>
#import <UIKit/UIProgressView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIReferenceLibraryViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIRefreshControl.h>    <# ⦁ 注解完成#>
#import <UIKit/UIResponder.h>    <# ⦁ 注解完成#>
#import <UIKit/UIRotationGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIScreen.h>    <# ⦁ 注解完成#>
#import <UIKit/UIScreenEdgePanGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UIScreenMode.h>    <# ⦁ 注解完成#>
#import <UIKit/UIScrollView.h>    <# ⦁ 注解完成#>
#import <UIKit/UISearchBar.h>    <# ⦁ 注解完成#>
#import <UIKit/UISearchContainerViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UISearchController.h>    <# ⦁ 注解完成#>
#import <UIKit/UISearchDisplayController.h>    <# ⦁ 注解完成#>
#import <UIKit/UISegmentedControl.h>    <# ⦁ 注解完成#>
#import <UIKit/UISlider.h>    <# ⦁ 注解完成#>
#import <UIKit/UISplitViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStepper.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStoryboard.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStoryboardPopoverSegue.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStoryboardSegue.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStringDrawing.h>    <# ⦁ 注解完成#>
#import <UIKit/UISwipeGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UISwitch.h>    <# ⦁ 注解完成#>
#import <UIKit/UITabBar.h>    <# ⦁ 注解完成#>
#import <UIKit/UITabBarController.h>    <# ⦁ 注解完成#>
#import <UIKit/UITabBarItem.h>    <# ⦁ 注解完成#>
#import <UIKit/UITableView.h>    <# ⦁ 注解完成#>
#import <UIKit/UITableViewHeaderFooterView.h>    <# ⦁ 注解完成#>
#import <UIKit/UITableViewCell.h>    <# ⦁ 注解完成#>
#import <UIKit/UITableViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UITapGestureRecognizer.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextChecker.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextField.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextInput.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextInputTraits.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIToolbar.h>    <# ⦁ 注解完成#>
#import <UIKit/UITouch.h>    <# ⦁ 注解完成#>
#import <UIKit/UITraitCollection.h>    <# ⦁ 注解完成#>
#import <UIKit/UIVideoEditorController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIViewController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIWebView.h>    <# ⦁ 注解完成#>
#import <UIKit/UIWindow.h>    <# ⦁ 注解完成#>

#import <UIKit/UIDragInteraction.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDragItem.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDragPreview.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDragPreviewParameters.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDragSession.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDropInteraction.h>    <# ⦁ 注解完成#>
#import <UIKit/UIInteraction.h>    <# ⦁ 注解完成#>
#import <UIKit/UITargetedDragPreview.h>    <# ⦁ 注解完成#>
#import <UIKit/UISpringLoadedInteraction.h>    <# ⦁ 注解完成#>
#import <UIKit/UISpringLoadedInteractionSupporting.h>    <# ⦁ 注解完成#>

#endif

#import <UIKit/NSAttributedString.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/NSItemProvider+UIKitAdditions.h>    <# ⦁ 注解完成#>)
#import <UIKit/NSItemProvider+UIKitAdditions.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<UIKit/NSLayoutConstraint.h>    <# ⦁ 注解完成#>)
#import <UIKit/NSLayoutConstraint.h>    <# ⦁ 注解完成#>
#import <UIKit/NSLayoutAnchor.h>    <# ⦁ 注解完成#>
#import <UIKit/UILayoutGuide.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStackView.h>    <# ⦁ 注解完成#>
#import <UIKit/NSLayoutManager.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/NSParagraphStyle.h>    <# ⦁ 注解完成#>


#if __has_include(<UIKit/NSShadow.h>    <# ⦁ 注解完成#>)
#import <UIKit/NSShadow.h>    <# ⦁ 注解完成#>
#endif

#import <UIKit/NSStringDrawing.h>    <# ⦁ 注解完成#>
#import <UIKit/NSText.h>    <# ⦁ 注解完成#>

#if __has_include(<UIKit/NSTextAttachment.h>    <# ⦁ 注解完成#>)
#import <UIKit/NSTextAttachment.h>    <# ⦁ 注解完成#>
#import <UIKit/NSTextContainer.h>    <# ⦁ 注解完成#>
#import <UIKit/NSTextStorage.h>    <# ⦁ 注解完成#>
#import <UIKit/UIStateRestoration.h>    <# ⦁ 注解完成#>
#import <UIKit/UIViewControllerTransitioning.h>    <# ⦁ 注解完成#>
#import <UIKit/UIViewControllerTransitionCoordinator.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPresentationController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPreviewInteraction.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPopoverPresentationController.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDynamicAnimator.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDynamicBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UIPushBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UISnapBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UIDynamicItemBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UIFieldBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UIGravityBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UIAttachmentBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UICollisionBehavior.h>    <# ⦁ 注解完成#>
#import <UIKit/UIRegion.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<UIKit/UITextDragging.h>    <# ⦁ 注解完成#>)
#import <UIKit/UITextDragging.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextDropping.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextDropProposal.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextDragPreviewRenderer.h>    <# ⦁ 注解完成#>
#import <UIKit/UITextDragURLPreviews.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<UIKit/UIViewPropertyAnimator.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIViewPropertyAnimator.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<UIKit/UIFeedbackGenerator.h>    <# ⦁ 注解完成#>)
#import <UIKit/UIFeedbackGenerator.h>    <# ⦁ 注解完成#>
#import <UIKit/UISelectionFeedbackGenerator.h>    <# ⦁ 注解完成#>
#import <UIKit/UIImpactFeedbackGenerator.h>    <# ⦁ 注解完成#>
#import <UIKit/UINotificationFeedbackGenerator.h>    <# ⦁ 注解完成#>
#endif

#if __has_include(<DocumentManager/DocumentManager.h>    <# ⦁ 注解完成#>)
#import <DocumentManager/DocumentManager.h>    <# ⦁ 注解完成#>
#endif
```
 
 
***
 
 
```objc
// Foundation.h - Copyright (c) 1994-2017, Apple Inc. All rights reserved.

#include <CoreFoundation/CoreFoundation.h>   <# ⦁ 注解完成#>

#import <Foundation/NSObjCRuntime.h>   <# ⦁ 注解完成#>

#import <Foundation/NSArray.h>   <# ⦁ 注解完成#>
#import <Foundation/NSAutoreleasePool.h>   <# ⦁ 注解完成#>
#import <Foundation/NSBundle.h>   <# ⦁ 注解完成#>
#import <Foundation/NSByteOrder.h>   <# ⦁ 注解完成#>
#import <Foundation/NSCalendar.h>   <# ⦁ 注解完成#>
#import <Foundation/NSCharacterSet.h>   <# ⦁ 注解完成#>
#import <Foundation/NSCoder.h>   <# ⦁ 注解完成#>
#import <Foundation/NSData.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDate.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDateInterval.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDateFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDateIntervalFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSISO8601DateFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMassFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSLengthFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSEnergyFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMeasurement.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMeasurementFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPersonNameComponents.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPersonNameComponentsFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDecimal.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDecimalNumber.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDictionary.h>   <# ⦁ 注解完成#>
#import <Foundation/NSEnumerator.h>   <# ⦁ 注解完成#>
#import <Foundation/NSError.h>   <# ⦁ 注解完成#>
#import <Foundation/NSException.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFileHandle.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFileManager.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSHashTable.h>   <# ⦁ 注解完成#>
#import <Foundation/NSHTTPCookie.h>   <# ⦁ 注解完成#>
#import <Foundation/NSHTTPCookieStorage.h>   <# ⦁ 注解完成#>
#import <Foundation/NSIndexPath.h>   <# ⦁ 注解完成#>
#import <Foundation/NSIndexSet.h>   <# ⦁ 注解完成#>
#import <Foundation/NSInvocation.h>   <# ⦁ 注解完成#>
#import <Foundation/NSJSONSerialization.h>   <# ⦁ 注解完成#>
#import <Foundation/NSKeyValueCoding.h>   <# ⦁ 注解完成#>
#import <Foundation/NSKeyValueObserving.h>   <# ⦁ 注解完成#>
#import <Foundation/NSKeyedArchiver.h>   <# ⦁ 注解完成#>
#import <Foundation/NSLocale.h>   <# ⦁ 注解完成#>
#import <Foundation/NSLock.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMapTable.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMethodSignature.h>   <# ⦁ 注解完成#>
#import <Foundation/NSNotification.h>   <# ⦁ 注解完成#>
#import <Foundation/NSNotificationQueue.h>   <# ⦁ 注解完成#>
#import <Foundation/NSNull.h>   <# ⦁ 注解完成#>
#import <Foundation/NSNumberFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSObject.h>   <# ⦁ 注解完成#>
#import <Foundation/NSOperation.h>   <# ⦁ 注解完成#>
#import <Foundation/NSOrderedSet.h>   <# ⦁ 注解完成#>
#import <Foundation/NSOrthography.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPathUtilities.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPointerArray.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPointerFunctions.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPort.h>   <# ⦁ 注解完成#>
#import <Foundation/NSProcessInfo.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPropertyList.h>   <# ⦁ 注解完成#>
#import <Foundation/NSProxy.h>   <# ⦁ 注解完成#>
#import <Foundation/NSRange.h>   <# ⦁ 注解完成#>
#import <Foundation/NSRegularExpression.h>   <# ⦁ 注解完成#>
#import <Foundation/NSRunLoop.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScanner.h>   <# ⦁ 注解完成#>
#import <Foundation/NSSet.h>   <# ⦁ 注解完成#>
#import <Foundation/NSSortDescriptor.h>   <# ⦁ 注解完成#>
#import <Foundation/NSStream.h>   <# ⦁ 注解完成#>
#import <Foundation/NSString.h>   <# ⦁ 注解完成#>
#import <Foundation/NSTextCheckingResult.h>   <# ⦁ 注解完成#>
#import <Foundation/NSThread.h>   <# ⦁ 注解完成#>
#import <Foundation/NSTimeZone.h>   <# ⦁ 注解完成#>
#import <Foundation/NSTimer.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUnit.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURL.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLAuthenticationChallenge.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLCache.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLConnection.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLCredential.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLCredentialStorage.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLError.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLProtectionSpace.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLProtocol.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLRequest.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLResponse.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUserDefaults.h>   <# ⦁ 注解完成#>
#import <Foundation/NSValue.h>   <# ⦁ 注解完成#>
#import <Foundation/NSValueTransformer.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLParser.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXPCConnection.h>   <# ⦁ 注解完成#>
#import <Foundation/NSZone.h>   <# ⦁ 注解完成#>

#import <Foundation/FoundationErrors.h>   <# ⦁ 注解完成#>

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)

#import <Foundation/NSAttributedString.h>   <# ⦁ 注解完成#>
#import <Foundation/NSByteCountFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSCache.h>   <# ⦁ 注解完成#>
#import <Foundation/NSComparisonPredicate.h>   <# ⦁ 注解完成#>
#import <Foundation/NSCompoundPredicate.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDateComponentsFormatter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSExpression.h>   <# ⦁ 注解完成#>
#import <Foundation/NSExtensionContext.h>   <# ⦁ 注解完成#>
#import <Foundation/NSExtensionItem.h>   <# ⦁ 注解完成#>
#import <Foundation/NSExtensionRequestHandling.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFileCoordinator.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFilePresenter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFileVersion.h>   <# ⦁ 注解完成#>
#import <Foundation/NSFileWrapper.h>   <# ⦁ 注解完成#>
#import <Foundation/NSItemProvider.h>   <# ⦁ 注解完成#>
#import <Foundation/NSLinguisticTagger.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMetadata.h>   <# ⦁ 注解完成#>
#import <Foundation/NSMetadataAttributes.h>   <# ⦁ 注解完成#>
#import <Foundation/NSNetServices.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPredicate.h>   <# ⦁ 注解完成#>
#import <Foundation/NSProgress.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUbiquitousKeyValueStore.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUndoManager.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLSession.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUserActivity.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUUID.h>   <# ⦁ 注解完成#>
#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || TARGET_OS_WIN32

#import <Foundation/NSArchiver.h>   <# ⦁ 注解完成#>
#import <Foundation/NSBackgroundActivityScheduler.h>   <# ⦁ 注解完成#>
#import <Foundation/NSCalendarDate.h>   <# ⦁ 注解完成#>
#import <Foundation/NSConnection.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDistantObject.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDistributedNotificationCenter.h>   <# ⦁ 注解完成#>
#import <Foundation/NSGeometry.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPortCoder.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPortMessage.h>   <# ⦁ 注解完成#>
#import <Foundation/NSPortNameServer.h>   <# ⦁ 注解完成#>
#import <Foundation/NSProtocolChecker.h>   <# ⦁ 注解完成#>
#import <Foundation/NSTask.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLDTD.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLDTDNode.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLDocument.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLElement.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLNode.h>   <# ⦁ 注解完成#>
#import <Foundation/NSXMLNodeOptions.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLDownload.h>   <# ⦁ 注解完成#>
#import <Foundation/NSURLHandle.h>   <# ⦁ 注解完成#>

#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))

#import <Foundation/NSAffineTransform.h>   <# ⦁ 注解完成#>
#import <Foundation/NSAppleEventDescriptor.h>   <# ⦁ 注解完成#>
#import <Foundation/NSAppleEventManager.h>   <# ⦁ 注解完成#>
#import <Foundation/NSAppleScript.h>   <# ⦁ 注解完成#>
#import <Foundation/NSClassDescription.h>   <# ⦁ 注解完成#>
#import <Foundation/NSDistributedLock.h>   <# ⦁ 注解完成#>
#import <Foundation/NSGarbageCollector.h>   <# ⦁ 注解完成#>
#import <Foundation/NSHFSFileTypes.h>   <# ⦁ 注解完成#>
#import <Foundation/NSHost.h>   <# ⦁ 注解完成#>
#import <Foundation/NSObjectScripting.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptClassDescription.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptCoercionHandler.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptCommand.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptCommandDescription.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptExecutionContext.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptKeyValueCoding.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptObjectSpecifiers.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptStandardSuiteCommands.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptSuiteRegistry.h>   <# ⦁ 注解完成#>
#import <Foundation/NSScriptWhoseTests.h>   <# ⦁ 注解完成#>
#import <Foundation/NSSpellServer.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUserNotification.h>   <# ⦁ 注解完成#>
#import <Foundation/NSUserScriptTask.h>   <# ⦁ 注解完成#>

#endif

#import <Foundation/FoundationLegacySwiftCompatibility.h>   <# ⦁ 注解完成#>
```

 
##### [不知名开发者](https://upload-images.jianshu.io/upload_images/2230763-a98b15f328e7cf69.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
###### - 各位厂友，由于「时间 & 知识」有限，难免有「未全、不足」，后续「坚持新增，替换、补充文章内容」.

