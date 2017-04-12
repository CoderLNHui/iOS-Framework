
## 导语
>我们追求技术的提升，关注技术的发展历程；作为从事技术工作的伐码猿，有个想法（`仅是个人想法`），这个想法工程量之大（`遇到，用到，最新技术点，点点积累，及时补充吧`），从事技术多年也算是对所花费时间的一个总结（算是对技术这块的一个目标吧）。

>这篇文章的内容仅是【UIKit框架 各文件分类的一个简明介绍】，**重点 -> 重点 -> 重点**（`重要的事情说 2+1 遍`），  
**我的「想法和行动」都在文章末尾**



## UIKit-Framework-OpenSource
UIKit 框架，归类整理，各分类文件注解，并对每一类中常用的功能进行案例渐进式解析；以简化初学者入门和老司机回顾的繁索过程，尽快切入主题，快速使用起来。这里只等你的到来 ！


UIKit Framework Annotation  Practical Case
![「UIKit Framework Annotation  Practical Case」](http://upload-images.jianshu.io/upload_images/2230763-0fd6bbb32d5a58aa.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



## 我 GitHub 工程已创建好，只等你的到来

**在「时间 & 知识 」有限内，总结的文章难免有「未全、不足 」的地方，还望各位好友指出，以提高文章质量**。




UIKit 分类结构

![ UIKit 框架](http://upload-images.jianshu.io/upload_images/2230763-0a6913fa199b11c5.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




## Content progress
//--------------------------- 「MyUIKit-Annotations」 ------------------------------//  
//

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


#import <UIKit/UIBezierPath.h>

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




# UIBezierPath.h // 注解完全✔️

//--------------------------- <#我是分割线#> ------------------------------//
//
#import <Foundation/NSObject.h>
#import "NSURLSession.h" // 注解未全➕



```










***


//--------------------------- 「MyUIKit-Case」 ------------------------------//  
//

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




**总之，学习一门新的框架类库的时侯，需要追根溯源，才好提纲切领，即能掌握全局，又能深入细节。  
从系统根类出发，结合事件响应处理的机制原理，再深入到各个界面组件或自定义，就会胸有成竹而不乱阵脚了**。



## UIKit框架注解演示




## 期待

- 如果在阅读过程中遇到 error，希望你能 Issues 我，谢谢。

- 如果你想为【本文相关】分享点什么，也希望你能 Issues 我，我非常想为这篇文章增加更多实用的内容，谢谢。

- [「博客原文」]()，对本文我会【不定时、持续更新、一些 学习心得与文章、实用才是硬道理】^_^.

-  [附上工程地址，如果「你喜欢 或 有帮助」，可否点个 Star](https://github.com/CustomPBWaters/UIKit-Framework-OpenSource)


## 后续 & About me

【我也是对所花费时间的一个总结】

**About me**：[@「伐码猿」](http://www.jianshu.com/u/fd745d76c816)

我只是个【有思想的伐码猿🐒】加上【自己的学习总结☕️】写出来的文章。






















