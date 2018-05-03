/*
 * UISearchController.h 
 *
 * Framework: UIKit  (c) 2014-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIPresentationController.h>
#import <UIKit/UIViewControllerTransitioning.h>
#import <UIKit/UISearchBar.h>

NS_ASSUME_NONNULL_BEGIN

@class UISearchController;

@protocol UISearchControllerDelegate <NSObject>
@optional
// These methods are called when automatic presentation or dismissal occurs. They will not be called if you present or dismiss the search controller yourself.
- (void)willPresentSearchController:(UISearchController *)searchController;
- (void)didPresentSearchController:(UISearchController *)searchController;
- (void)willDismissSearchController:(UISearchController *)searchController;
- (void)didDismissSearchController:(UISearchController *)searchController;

// Called after the search controller's search bar has agreed to begin editing or when 'active' is set to YES. If you choose not to present the controller yourself or do not implement this method, a default presentation is performed on your behalf.
- (void)presentSearchController:(UISearchController *)searchController;
@end

@protocol UISearchResultsUpdating <NSObject>
@required


// Called when the search bar's text or scope has changed or when the search bar becomes first responder.
// 搜索框获得第一响应或内容变化时触发
- (void)updateSearchResultsForSearchController:(UISearchController *)searchController;
@end

NS_CLASS_AVAILABLE_IOS(8_0) @interface UISearchController : UIViewController <UIViewControllerTransitioningDelegate, UIViewControllerAnimatedTransitioning>



#pragma mark - 初始化

// Pass nil if you wish to display search results in the same view that you are searching. This is not supported on tvOS; please provide a results controller on tvOS.
// 初始化方法, 参数是展示搜索结果的控制器, 如果是在当前控制器展示搜索结果, 就传nil
- (instancetype)initWithSearchResultsController:(nullable UIViewController *)searchResultsController;


// The object responsible for updating the content of the searchResultsController.
// 负责更新搜索结果的代理, 需要遵循 UISearchResultsUpdating 协议
@property (nullable, nonatomic, weak) id <UISearchResultsUpdating> searchResultsUpdater;


// Setting this property to YES is a convenience method that performs a default presentation of the search controller appropriate for how the controller is configured. Implement -presentSearchController: if the default presentation is not adequate.
// 搜索控制器是否是活跃状态, 当在一个控制器展示搜索结果的时候, 可以此来判断返回的数据源
@property (nonatomic, assign, getter = isActive) BOOL active;

// 控制器代理  遵循 UISearchControllerDelegate协议
@property (nullable, nonatomic, weak) id <UISearchControllerDelegate> delegate;

// 当搜索框激活时, 是否添加一个背景透明蒙版
@property (nonatomic, assign) BOOL dimsBackgroundDuringPresentation __TVOS_PROHIBITED; // default is YES, and has the same behavior as obscuresBackgroundDuringPresentation.
@property (nonatomic, assign) BOOL obscuresBackgroundDuringPresentation NS_AVAILABLE_IOS(9_1); // default is YES. On tvOS, defaults to NO when contained in UISearchContainerViewController.

// 当搜索框激活时, 是否隐藏导航条
@property (nonatomic, assign) BOOL hidesNavigationBarDuringPresentation;     // default is YES

// 展示搜索结果的控制器
@property (nullable, nonatomic, strong, readonly) UIViewController *searchResultsController;

// You are free to become the search bar's delegate to monitor for text changes and button presses.
@property (nonatomic, strong, readonly) UISearchBar *searchBar;// 搜索栏控件
@end

NS_ASSUME_NONNULL_END


/**
 @property (nonatomic,retain)UISearchController *searchC;
 
 //初始化UISearchController，把搜索框添加在tableView的headerView上
 //添加搜索栏
 _searchC = [[UISearchController alloc]initWithSearchResultsController:nil];
 //设置frame
 _searchC.searchBar.frame = CGRectMake(0, 0, 414, 50);
 
 //更新代理
 _searchC.searchResultsUpdater = self;
 
 //搜索结果不变灰
 _searchC.dimsBackgroundDuringPresentation = NO;
 
 //添加到header
 self.tableView.tableHeaderView = _searchC.searchBar;
 
 */







