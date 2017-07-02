//  UIKit.h
 
/*
 该 **MyUIKit-Extension** ,
 原作者 http://www.jianshu.com/subscriptions#/subscriptions/5281730/user
 
 阅读总会能有点收获 ！向优秀的开源者致敬 ！向优秀的分享者致敬 ！
 */


// 阅读此项目时，私有类及私有分类不必太关注，这些类只是.m里面为了实现某些功能定义的私有方法

#ifndef UIKit_h
#define UIKit_h

#ifndef IBAction
#define IBAction void
#endif

#ifndef IBOutlet
#define IBOutlet
#endif
//  UIView,UIViewController,UIView动画实现，UIAppearance文章待写

#import "UIResponder.h"   //  完全实现ok
#import "UIEvent.h"  //  完全实现ok
#import "UITouch.h"  //  完全实现

#import "UIView.h"  //  完全实现
#import "UIScrollView.h" // 完全实现ok（重点）
#import "UITableView"  //  完全实现ok（重点）

#import "UITableViewCell.h"  //  完全实现ok
#import "UITableViewHeaderFooterView.h"  //  完全实现ok
#import "UIViewController.h"  // 完全实现

#import "UIBezierPath.h"  // 完全实现ok
#import "UIGeometry.h"  // 完全实现ok
#import "UIGraphics.h"  // 完全实现ok
#import "UIColor.h"  // 完全实现ok
#import "UIFont.h"  // 完全实现ok

#import "UIAcceleration.h"  // 完全实现ok
#import "UIAccelerometer.h"  // 完全实现ok
#import "UIAccessibilityElement.h"  // 完全实现ok
#import "UIAccessibility.h" // 完全实现ok

#import "UIBarItem.h"  // 完全实现ok
#import "UITabBarItem.h"  // 完全实现ok
#import "UIBarButtonItem.h" // 完全实现ok
#import "UIInterface.h"  // 完全实现ok

#import "UIDevice.h"  // 完全实现ok


#endif /* UIKit_h */
