/*
 * UISearchContainerViewController.h 
 *
 * UIKit (c) 2015-2016
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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
