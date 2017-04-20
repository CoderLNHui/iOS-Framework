
## 导语 📌 

>我们追求技术的提升，关注技术的发展历程；作为从事技术工作的伐码猿，有个想法（`仅是个人想法`），这个想法工程量之大（`遇到，用到，最新技术点，点点积累，及时补充吧`），从事技术多年也算是对所花费时间的一个总结（`算是对技术这块的一个目标吧`）。

>这篇文章的内容仅是【UIKit框架 各文件分类的一个简明介绍】，  
**重点 -> 重点 -> 重点**（`重要的事情说 2+1 遍`），    
**我的「想法和行动」都在文章末尾**



## UIKit&Foundation-Framework-OpenSource

`UIKit` 框架 & `Foundation` 框架，归类整理，各分类文件注解，并对每一类中常用的功能进行案例渐进式解析；`以简化初学者入门和老司机回顾的繁索过程`，尽快切入主题，快速使用起来。这里只等你的到来 ！


![「UIKit Framework Annotation  Practical Case」](http://upload-images.jianshu.io/upload_images/2230763-0fd6bbb32d5a58aa.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![「Foundation Framework Annotation  Practical Case」](http://upload-images.jianshu.io/upload_images/2230763-ce14862fab7de4fe.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



## 我 GitHub 工程已创建好，只等你的到来

**在「时间 & 知识 」有限内，总结的文章难免有「未全、不足 」的地方，还望各位好友指出，以提高文章质量**。




**UIKit 分类结构**

![ UIKit 框架](http://upload-images.jianshu.io/upload_images/2230763-0a6913fa199b11c5.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




**Foundation 分类结构**

[这里有篇详细的介绍，请你移步这里阅读](http://www.cnblogs.com/kenshincui/p/3885689.html#!comments)






## Content progress

//--------------------------- 「MyUIKit-Annotations」 ------------------------------//  
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
#import <UIKit/UIBarButtonItem.h>
#import <UIKit/UIBarButtonItemGroup.h>
#import <UIKit/UIBarItem.h>
#endif


#import <UIKit/UIBezierPath.h> // 注解完全✔️

#if __has_include(<UIKit/UIButton.h>)
#import <UIKit/UIButton.h>
#import <UIKit/UICollectionView.h> // 注解完全✔️
#import <UIKit/UICollectionViewCell.h> // 注解未全➕
#import <UIKit/UICollectionViewController.h> // 注解未全➕
#import <UIKit/UICollectionViewFlowLayout.h> // 注解完全✔️
#import <UIKit/UICollectionViewLayout.h> // 注解完全✔️
#import <UIKit/UICollectionViewTransitionLayout.h>
#endif

#import <UIKit/UIColor.h>

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
#import <UIKit/UIImage.h>

#if __has_include(<UIKit/UIGraphicsRenderer.h>)
#import <UIKit/UIGraphicsRenderer.h>
#import <UIKit/UIGraphicsImageRenderer.h>
#import <UIKit/UIGraphicsPDFRenderer.h>
#endif

#if __has_include(<UIKit/UIImageAsset.h>)
#import <UIKit/UIImageAsset.h>
#import <UIKit/NSDataAsset.h>
#import <UIKit/UIImagePickerController.h>
#import <UIKit/UIImageView.h>
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
#import <UIKit/UITextField.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UITextView.h>
#import <UIKit/UIToolbar.h>
#import <UIKit/UITouch.h>
#import <UIKit/UITraitCollection.h>
#import <UIKit/UIVideoEditorController.h>
#import <UIKit/UIView.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIWebView.h>
#import <UIKit/UIWindow.h>
#endif

#import <UIKit/NSAttributedString.h>

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
#import "UIColor.h"  // 完全实现✔️
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




//--------------------------- 「MyFoundation-Annotations」 ------------------------------//    
// `期待你的加入 ^_^.`


```objc
/*	Foundation.h
	Copyright (c) 1994-2016, Apple Inc. All rights reserved.
*/


#include <CoreFoundation/CoreFoundation.h>

#import <Foundation/NSObjCRuntime.h>

#import <Foundation/NSArray.h>
#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSBundle.h>
#import <Foundation/NSByteOrder.h>
#import <Foundation/NSCalendar.h>
#import <Foundation/NSCharacterSet.h>
#import <Foundation/NSCoder.h>
#import <Foundation/NSData.h>
#import <Foundation/NSDate.h>
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
#import <Foundation/NSDictionary.h>
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
#import <Foundation/NSNotification.h>
#import <Foundation/NSNotificationQueue.h>
#import <Foundation/NSNull.h>
#import <Foundation/NSNumberFormatter.h>
#import <Foundation/NSObject.h>
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
#import <Foundation/NSString.h>
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



//--------------------------- 「MyFoundation-Extension」 ------------------------------//  
// `期待你的加入 ^_^.`

```objc

期待你的加入 ^_^.

期待你的加入 ^_^.

期待你的加入 ^_^.

```


**总之，学习一门新的框架类库的时侯，需要追根溯源，才好提纲切领，即能掌握全局，又能深入细节。  
从系统根类出发，结合事件响应处理的机制原理，再深入到各个界面组件或自定义，就会胸有成竹而不乱阵脚了**。



**温馨提示：☕️    
所有文章将「迁移 & 后续」对应两个工程下，这两个想法是个长期而持续的目标吧，如果你感觉看我写的文章对你 利大于弊 . . .；`由于个人 「时间 & 知识」 有限，是心有余而力有限，欢迎你的 Star & Fork`**。





## UIKit框架注解演示
[ UIKit框架注解演示.gif http://www.jianshu.com/p/e5b995ecf44d](http://www.jianshu.com/p/e5b995ecf44d)


 
## GitHub工程地址 📌 

- [官方文档译文框架源码注解，当你「了解权威 & 进阶原理」的时候，网搜的众多中 ~ ~（自行脑补）。做只有思想的伐码猿，做到「实用概念，不文言」&「实现原理，简明详解」，从零开始，由浅入深。 以简化初学者入门和老司机回顾的繁索过程，尽快切入主题，快速使用起来。这里只等你的到来 ！Star & Fork](https://github.com/CustomPBWaters/OfficialTranslation-SourceAnnotation)



- [iOS·Objective-C 实用文章详解整理专题](https://github.com/CustomPBWaters/UIKit-Framework-OpenSource/blob/master/iOS·Objective-C%20实用文章详解整理.md)




## 期待

- 如果在阅读过程中遇到 error，希望你能 Issues 我，谢谢。

- 如果你想为【本文相关】分享点什么，也希望你能 Issues 我，我非常想为这篇文章增加更多实用的内容，谢谢。

- [「博客原文」](https://custompbwaters.github.io/2015/06/01/源码注解+活用/iOS%20UIKit框架/)，对本文我会【不定时、持续更新、一些 学习心得与文章、实用才是硬道理】^_^.



## About me

【我也是对所花费时间的一个总结】

我只是个【有思想的伐码猿🐒】加上【自己的学习总结☕️】写出来的文章。


![↑ 《伐码吧》 --> "兄弟"   ↑ ](http://upload-images.jianshu.io/upload_images/2230763-6746b831e7f456f6.gif?imageMogr2/auto-orient/strip)


















