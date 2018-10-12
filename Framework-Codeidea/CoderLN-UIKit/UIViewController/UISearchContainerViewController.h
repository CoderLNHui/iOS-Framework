/*
 * UISearchContainerViewController.h 
 *
 * UIKit (c) 2015-2016
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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
