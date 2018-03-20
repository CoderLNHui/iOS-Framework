/*
 * UICollectionViewController.h 
 *
 * (c) 2011-2015
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

#import <UIKit/UIViewController.h>
#import <UIKit/UICollectionView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UICollectionViewLayout;
@class UICollectionViewController;

NS_CLASS_AVAILABLE_IOS(6_0) @interface UICollectionViewController : UIViewController <UICollectionViewDelegate, UICollectionViewDataSource>

- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout *)layout NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@property (nullable, nonatomic, strong) __kindof UICollectionView *collectionView;

// Defaults to YES, and if YES, any selection is cleared in viewWillAppear:
// This property has no effect if the useLayoutToLayoutNavigationTransitions property is set to YES
@property (nonatomic) BOOL clearsSelectionOnViewWillAppear;

// Set to YES before pushing a a UICollectionViewController onto a
// UINavigationController. The top view controller of the navigation controller
// must be a UICollectionViewController that was pushed with this property set
// to NO. This property should NOT be changed on a UICollectionViewController that
// has already been pushed onto a UINavigationController.
@property (nonatomic, assign) BOOL useLayoutToLayoutNavigationTransitions NS_AVAILABLE_IOS(7_0);

// The layout object is needed when defining interactive layout to layout transitions.
@property (nonatomic, readonly) UICollectionViewLayout *collectionViewLayout NS_AVAILABLE_IOS(7_0);

// Defaults to YES, and if YES, a system standard reordering gesture is used to drive collection view reordering
@property (nonatomic) BOOL installsStandardGestureForInteractiveMovement NS_AVAILABLE_IOS(9_0);

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

