/*
 * UISearchContainerViewController.h 
 *
 * (c) 2015-2016
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

NS_ASSUME_NONNULL_BEGIN

@class UISearchController;

// If intending to use a UISearchController in a non-presentation manner, use this container view controller.
UIKIT_CLASS_AVAILABLE_IOS_TVOS(9_1, 9_0) @interface UISearchContainerViewController : UIViewController
@property (nonatomic, strong, readonly) UISearchController *searchController;

- (instancetype)initWithSearchController:(UISearchController *)searchController;

@end
NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
