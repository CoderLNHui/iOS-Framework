
#### Elegant programming
 
| 不管谁的博客上面写的(`也包括自己`)，阅读的你要敢于去验证，停止无意义的`⏹copy 👬 paste`。 |
|:-:|

 

## Content progress

//--------------------------- 「MyUIKit-Annotations & Category」 ------------------------------//  
// `期待你的加入 ^_^.`

```objc
#import <UIKit/UIKitDefines.h>

#if __has_include(<UIKit/UIAccelerometer.h>)
#import <UIKit/UIAccelerometer.h>
#import <UIKit/UIAccessibility.h>
#endif

#import <UIKit/UIAccessibilityConstants.h>

#if __has_include(<UIKit/UIActivityIndicatorView.h>)
#import <UIKit/UIActivityIndicatorView.h>
#import <UIKit/UIActivity.h>
#import <UIKit/UIActivityItemProvider.h>
#import <UIKit/UIActivityViewController.h>
#import <UIKit/UIActionSheet.h>
#import <UIKit/UIAlertController.h>
#import <UIKit/UIAlertView.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIBarButtonItem.h> 📌工具类持续➕
#import <UIKit/UIBarButtonItemGroup.h>
#import <UIKit/UIBarItem.h>
#endif


#import <UIKit/UIBezierPath.h> // 注解完全✔️

#if __has_include(<UIKit/UIButton.h>)
#import <UIKit/UIButton.h> // 注解未全➕
#import <UIKit/UICollectionView.h> // 注解完全✔️
#import <UIKit/UICollectionViewCell.h> // 注解未全➕
#import <UIKit/UICollectionViewController.h> // 注解未全➕
#import <UIKit/UICollectionViewFlowLayout.h> // 注解完全✔️
#import <UIKit/UICollectionViewLayout.h> // 注解完全✔️
#import <UIKit/UICollectionViewTransitionLayout.h>
#endif

#import <UIKit/UIColor.h> // 注解未全➕

#if __has_include(<UIKit/UIContentSizeCategoryAdjusting.h>)
#import <UIKit/UIContentSizeCategoryAdjusting.h>
#import <UIKit/UIContentSizeCategory.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIDataDetectors.h>
#import <UIKit/UIDatePicker.h>
#import <UIKit/UIDevice.h>
#import <UIKit/UIDocument.h>
#import <UIKit/UIDocumentInteractionController.h>
#import <UIKit/UIDocumentPickerViewController.h>
#import <UIKit/UIDocumentMenuViewController.h>
#import <UIKit/UIDocumentPickerExtensionViewController.h>
#import <UIKit/UICloudSharingController.h>
#import <UIKit/NSFileProviderExtension.h>
#import <UIKit/UIVisualEffectView.h>
#import <UIKit/UIEvent.h>
#endif

#import <UIKit/UIFont.h>
#import <UIKit/UIFontDescriptor.h>
#import <UIKit/UIGeometry.h>

#if __has_include(<UIKit/UIGestureRecognizer.h>)
#import <UIKit/UIGestureRecognizer.h>
#endif

#import <UIKit/UIGraphics.h>
#import <UIKit/UIImage.h> // 注解未全➕  📌工具类持续➕

#if __has_include(<UIKit/UIGraphicsRenderer.h>)
#import <UIKit/UIGraphicsRenderer.h>
#import <UIKit/UIGraphicsImageRenderer.h>
#import <UIKit/UIGraphicsPDFRenderer.h>
#endif

#if __has_include(<UIKit/UIImageAsset.h>)
#import <UIKit/UIImageAsset.h>
#import <UIKit/NSDataAsset.h>
#import <UIKit/UIImagePickerController.h>
#import <UIKit/UIImageView.h> // 注解未全➕ 📌工具类持续➕
#import <UIKit/UIInputView.h>
#import <UIKit/UIInputViewController.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UILabel.h>
#import <UIKit/UILexicon.h>
#endif

#import <UIKit/UILocalNotification.h>

#if __has_include(<UIKit/UIUserNotificationSettings.h>)

#import <UIKit/UIApplicationShortcutItem.h>
#import <UIKit/UIUserNotificationSettings.h>
#import <UIKit/UIFocus.h>
#import <UIKit/UIFocusGuide.h>
#import <UIKit/UIFocusAnimationCoordinator.h>
#import <UIKit/UILocalizedIndexedCollation.h>
#import <UIKit/UILongPressGestureRecognizer.h>
#import <UIKit/UIManagedDocument.h>
#import <UIKit/UIMenuController.h>
#import <UIKit/UIMotionEffect.h>
#import <UIKit/UINavigationBar.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UINib.h>
#import <UIKit/UINibDeclarations.h>
#import <UIKit/UINibLoading.h>
#import <UIKit/UIPageControl.h> // 注解完全✔️
#import <UIKit/UIPageViewController.h>
#import <UIKit/UIPanGestureRecognizer.h>
#import <UIKit/UIPasteboard.h>
#import <UIKit/UIPickerView.h>
#import <UIKit/UIPinchGestureRecognizer.h>
#import <UIKit/UIPopoverController.h>
#import <UIKit/UIPopoverBackgroundView.h>
#import <UIKit/UIPress.h>
#import <UIKit/UIPressesEvent.h>
#import <UIKit/UIPrinter.h>
#import <UIKit/UIPrinterPickerController.h>
#import <UIKit/UIPrintError.h>
#import <UIKit/UIPrintFormatter.h>
#import <UIKit/UIPrintInfo.h>
#import <UIKit/UIPrintInteractionController.h>
#import <UIKit/UIPrintPageRenderer.h>
#import <UIKit/UIPrintPaper.h>
#import <UIKit/UIProgressView.h>
#import <UIKit/UIReferenceLibraryViewController.h>
#import <UIKit/UIRefreshControl.h>
#import <UIKit/UIResponder.h>
#import <UIKit/UIRotationGestureRecognizer.h>
#import <UIKit/UIScreen.h>
#import <UIKit/UIScreenEdgePanGestureRecognizer.h>
#import <UIKit/UIScreenMode.h>
#import <UIKit/UIScrollView.h> // 注解完全✔️
#import <UIKit/UISearchBar.h>
#import <UIKit/UISearchContainerViewController.h>
#import <UIKit/UISearchController.h>
#import <UIKit/UISearchDisplayController.h>
#import <UIKit/UISegmentedControl.h>
#import <UIKit/UISlider.h>
#import <UIKit/UISplitViewController.h>
#import <UIKit/UIStepper.h>
#import <UIKit/UIStoryboard.h>
#import <UIKit/UIStoryboardPopoverSegue.h>
#import <UIKit/UIStoryboardSegue.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UISwipeGestureRecognizer.h>
#import <UIKit/UISwitch.h>
#import <UIKit/UITabBar.h>
#import <UIKit/UITabBarController.h>
#import <UIKit/UITabBarItem.h>
#import <UIKit/UITableView.h> // 注解完全✔️
#import <UIKit/UITableViewHeaderFooterView.h>
#import <UIKit/UITableViewCell.h> // 注解完全✔️
#import <UIKit/UITableViewController.h> // 注解完全✔️
#import <UIKit/UITapGestureRecognizer.h>
#import <UIKit/UITextChecker.h>
#import <UIKit/UITextField.h> // 注解未全➕ 📌工具类持续➕
#import <UIKit/UITextInput.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UITextView.h>
#import <UIKit/UIToolbar.h>
#import <UIKit/UITouch.h>
#import <UIKit/UITraitCollection.h>
#import <UIKit/UIVideoEditorController.h>
#import <UIKit/UIView.h> // 注解未全➕  📌工具类持续➕ 
#import <UIKit/UIViewController.h>
#import <UIKit/UIWebView.h>
#import <UIKit/UIWindow.h>
#endif

#import <UIKit/NSAttributedString.h> // 注解完全✔️

#if __has_include(<UIKit/NSLayoutConstraint.h>)
#import <UIKit/NSLayoutConstraint.h>
#import <UIKit/NSLayoutAnchor.h>
#import <UIKit/UILayoutGuide.h>
#import <UIKit/UIStackView.h>
#import <UIKit/NSLayoutManager.h>
#endif

#import <UIKit/NSParagraphStyle.h>

#if __has_include(<UIKit/NSShadow.h>)
#import <UIKit/NSShadow.h>
#endif

#import <UIKit/NSStringDrawing.h>
#import <UIKit/NSText.h>

#if __has_include(<UIKit/NSTextAttachment.h>)
#import <UIKit/NSTextAttachment.h>
#import <UIKit/NSTextContainer.h>
#import <UIKit/NSTextStorage.h>
#import <UIKit/UIStateRestoration.h>
#import <UIKit/UIViewControllerTransitioning.h>
#import <UIKit/UIViewControllerTransitionCoordinator.h>
#import <UIKit/UIPresentationController.h>
#import <UIKit/UIPreviewInteraction.h>
#import <UIKit/UIPopoverPresentationController.h>
#import <UIKit/UIDynamicAnimator.h>
#import <UIKit/UIDynamicBehavior.h>
#import <UIKit/UIPushBehavior.h>
#import <UIKit/UISnapBehavior.h>
#import <UIKit/UIDynamicItemBehavior.h>
#import <UIKit/UIFieldBehavior.h>
#import <UIKit/UIGravityBehavior.h>
#import <UIKit/UIAttachmentBehavior.h>
#import <UIKit/UICollisionBehavior.h>
#import <UIKit/UIRegion.h>
#endif

#if __has_include(<UIKit/UIViewPropertyAnimator.h>)
#import <UIKit/UIViewPropertyAnimator.h>
#endif

#if __has_include(<UIKit/UIFeedbackGenerator.h>)
#import <UIKit/UIFeedbackGenerator.h>
#import <UIKit/UISelectionFeedbackGenerator.h>
#import <UIKit/UIImpactFeedbackGenerator.h>
#import <UIKit/UINotificationFeedbackGenerator.h>
#endif

```



 
***


//--------------------------- 「MyFoundation-Annotations & Category」 ------------------------------//    
// `期待你的加入 ^_^.`


```objc
/*	Foundation.h
	Copyright (c) 1994-2016, Apple Inc. All rights reserved.
*/


#include <CoreFoundation/CoreFoundation.h>

#import <Foundation/NSObjCRuntime.h>

#import <Foundation/NSArray.h> // 注解未全➕
#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSBundle.h>
#import <Foundation/NSByteOrder.h>
#import <Foundation/NSCalendar.h>
#import <Foundation/NSCharacterSet.h>
#import <Foundation/NSCoder.h>
#import <Foundation/NSData.h>
#import <Foundation/NSDate.h> // 注解未全➕  📌工具类持续➕
#import <Foundation/NSDateInterval.h>
#import <Foundation/NSDateFormatter.h>
#import <Foundation/NSDateIntervalFormatter.h>
#import <Foundation/NSISO8601DateFormatter.h>
#import <Foundation/NSMassFormatter.h>
#import <Foundation/NSLengthFormatter.h>
#import <Foundation/NSEnergyFormatter.h>
#import <Foundation/NSMeasurement.h>
#import <Foundation/NSMeasurementFormatter.h>
#import <Foundation/NSPersonNameComponents.h>
#import <Foundation/NSPersonNameComponentsFormatter.h>
#import <Foundation/NSDecimal.h>
#import <Foundation/NSDecimalNumber.h>
#import <Foundation/NSDictionary.h> // 注解未全➕  📌工具类持续➕
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSError.h>
#import <Foundation/NSException.h>
#import <Foundation/NSFileHandle.h>
#import <Foundation/NSFileManager.h>
#import <Foundation/NSFormatter.h>
#import <Foundation/NSHashTable.h>
#import <Foundation/NSHTTPCookie.h>
#import <Foundation/NSHTTPCookieStorage.h>
#import <Foundation/NSIndexPath.h>
#import <Foundation/NSIndexSet.h>
#import <Foundation/NSInvocation.h>
#import <Foundation/NSJSONSerialization.h>
#import <Foundation/NSKeyValueCoding.h>
#import <Foundation/NSKeyValueObserving.h>
#import <Foundation/NSKeyedArchiver.h>
#import <Foundation/NSLocale.h>
#import <Foundation/NSLock.h>
#import <Foundation/NSMapTable.h>
#import <Foundation/NSMethodSignature.h>
#import <Foundation/NSNotification.h> // 注解完全✔️
#import <Foundation/NSNotificationQueue.h> // 注解完全✔️
#import <Foundation/NSNull.h>
#import <Foundation/NSNumberFormatter.h>
#import <Foundation/NSObject.h> // 注解未全➕  📌工具类持续➕
#import <Foundation/NSOperation.h>
#import <Foundation/NSOrderedSet.h>
#import <Foundation/NSOrthography.h>
#import <Foundation/NSPathUtilities.h>
#import <Foundation/NSPointerArray.h>
#import <Foundation/NSPointerFunctions.h>
#import <Foundation/NSPort.h>
#import <Foundation/NSProcessInfo.h>
#import <Foundation/NSPropertyList.h>
#import <Foundation/NSProxy.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSRegularExpression.h>
#import <Foundation/NSRunLoop.h>
#import <Foundation/NSScanner.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSSortDescriptor.h>
#import <Foundation/NSStream.h>
#import <Foundation/NSString.h> // 注解完全✔️  📌工具类持续➕
#import <Foundation/NSTextCheckingResult.h>
#import <Foundation/NSThread.h>
#import <Foundation/NSTimeZone.h>
#import <Foundation/NSTimer.h>
#import <Foundation/NSUnit.h>
#import <Foundation/NSURL.h>
#import <Foundation/NSURLAuthenticationChallenge.h>
#import <Foundation/NSURLCache.h>
#import <Foundation/NSURLConnection.h>
#import <Foundation/NSURLCredential.h>
#import <Foundation/NSURLCredentialStorage.h>
#import <Foundation/NSURLError.h>
#import <Foundation/NSURLProtectionSpace.h>
#import <Foundation/NSURLProtocol.h>
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSURLResponse.h>
#import <Foundation/NSUserDefaults.h>
#import <Foundation/NSValue.h>
#import <Foundation/NSValueTransformer.h>
#import <Foundation/NSXMLParser.h>
#import <Foundation/NSZone.h>

#import <Foundation/FoundationErrors.h>

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)

#import <Foundation/NSAttributedString.h>
#import <Foundation/NSByteCountFormatter.h>
#import <Foundation/NSCache.h>
#import <Foundation/NSComparisonPredicate.h>
#import <Foundation/NSCompoundPredicate.h>
#import <Foundation/NSDateComponentsFormatter.h>
#import <Foundation/NSExpression.h>
#import <Foundation/NSExtensionContext.h>
#import <Foundation/NSExtensionItem.h>
#import <Foundation/NSExtensionRequestHandling.h>
#import <Foundation/NSFileCoordinator.h>
#import <Foundation/NSFilePresenter.h>
#import <Foundation/NSFileVersion.h>
#import <Foundation/NSFileWrapper.h>
#import <Foundation/NSItemProvider.h>
#import <Foundation/NSLinguisticTagger.h>
#import <Foundation/NSMetadata.h>
#import <Foundation/NSMetadataAttributes.h>
#import <Foundation/NSNetServices.h>
#import <Foundation/NSPredicate.h>
#import <Foundation/NSProgress.h>
#import <Foundation/NSUbiquitousKeyValueStore.h>
#import <Foundation/NSUndoManager.h>
#import <Foundation/NSURLSession.h> // 注解未全➕
#import <Foundation/NSUserActivity.h>
#import <Foundation/NSUUID.h>
#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || TARGET_OS_WIN32

#import <Foundation/NSArchiver.h>
#import <Foundation/NSBackgroundActivityScheduler.h>
#import <Foundation/NSCalendarDate.h>
#import <Foundation/NSConnection.h>
#import <Foundation/NSDistantObject.h>
#import <Foundation/NSDistributedNotificationCenter.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSPortCoder.h>
#import <Foundation/NSPortMessage.h>
#import <Foundation/NSPortNameServer.h>
#import <Foundation/NSProtocolChecker.h>
#import <Foundation/NSTask.h>
#import <Foundation/NSXMLDTD.h>
#import <Foundation/NSXMLDTDNode.h>
#import <Foundation/NSXMLDocument.h>
#import <Foundation/NSXMLElement.h>
#import <Foundation/NSXMLNode.h>
#import <Foundation/NSXMLNodeOptions.h>
#import <Foundation/NSURLDownload.h>
#import <Foundation/NSURLHandle.h>

#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))

#import <Foundation/NSAffineTransform.h>
#import <Foundation/NSAppleEventDescriptor.h>
#import <Foundation/NSAppleEventManager.h>
#import <Foundation/NSAppleScript.h>
#import <Foundation/NSClassDescription.h>
#import <Foundation/NSDistributedLock.h>
#import <Foundation/NSGarbageCollector.h>
#import <Foundation/NSHFSFileTypes.h>
#import <Foundation/NSHost.h>
#import <Foundation/NSObjectScripting.h>
#import <Foundation/NSScriptClassDescription.h>
#import <Foundation/NSScriptCoercionHandler.h>
#import <Foundation/NSScriptCommand.h>
#import <Foundation/NSScriptCommandDescription.h>
#import <Foundation/NSScriptExecutionContext.h>
#import <Foundation/NSScriptKeyValueCoding.h>
#import <Foundation/NSScriptObjectSpecifiers.h>
#import <Foundation/NSScriptStandardSuiteCommands.h>
#import <Foundation/NSScriptSuiteRegistry.h>
#import <Foundation/NSScriptWhoseTests.h>
#import <Foundation/NSSpellServer.h>
#import <Foundation/NSUserNotification.h>
#import <Foundation/NSUserScriptTask.h>
#import <Foundation/NSXPCConnection.h>

#endif

#import <Foundation/FoundationLegacySwiftCompatibility.h>

```


***

//--------------------------- 「MyUIKit-Extension」 ------------------------------//  
// `期待你的加入 ^_^.`

```objc
#import "UIResponder.h"   //  完全实现✔️
#import "UIEvent.h"  //  完全实现✔️
#import "UITouch.h"  //  完全实现✔️

#import "UIView.h"  //  完全实现✔️ 
#import "UIScrollView.h" // 完全实现✔️（重点）
#import "UITableView"  //  完全实现✔️（重点）

#import "UITableViewCell.h"  //  完全实现✔️
#import "UITableViewHeaderFooterView.h"  //  完全实现✔️
#import "UIViewController.h"  // 完全实现✔️

#import "UIBezierPath.h"  // 完全实现✔️
#import "UIGeometry.h"  // 完全实现✔️
#import "UIGraphics.h"  // 完全实现✔️
#import "UIColor.h"  // 完全实现✔️ 📌工具类持续➕
#import "UIFont.h"  // 完全实现✔️

#import "UIAcceleration.h"  // 完全实现✔️
#import "UIAccelerometer.h"  // 完全实现✔️
#import "UIAccessibilityElement.h"  // 完全实现✔️
#import "UIAccessibility.h" // 完全实现✔️

#import "UIBarItem.h"  // 完全实现✔️
#import "UITabBarItem.h"  // 完全实现✔️
#import "UIBarButtonItem.h" // 完全实现✔️
#import "UIInterface.h"  // 完全实现✔️

#import "UIDevice.h"  // 完全实现✔️


#endif /* UIKit_h */
```

***


//--------------------------- 【Other】———————————————//  
// `期待你的加入 ^_^.`




```objc

#import "runtime.h" // 注解完全✔️

#import "WKWebView.h" // 注解未全➕



Foundation+Log.m // 【用于控制字典和数组打印输出格式为中文(直接拖入项目中就可以了,不要做任何处理) 】

Single.h // 【快速创建一个单例 MRC模式 & ARC模式】




Header.h // 常用持续➕

PrefixHeader.pch // 常用持续➕

```
 
 
***
| `  ☕️ 分享是你我熟悉的味道 ☕️ 未完待续 ！` |
| :-: |
| :💥❤️💥: |
| `To be continued ☕️ Plain boiled water ☕️ To be continued` |












