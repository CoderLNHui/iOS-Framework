/*
 * UIStoryboardPopoverSegue.h
 *
 * UIKit (c) 2011-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <UIKit/UIStoryboardSegue.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPopoverController;

NS_CLASS_DEPRECATED_IOS(5_0, 9_0, "Access destinationViewController.popoverPresentationController from your segue's performHandler or override of -perform") @interface UIStoryboardPopoverSegue : UIStoryboardSegue {
}

@property (nonatomic, strong, readonly) UIPopoverController *popoverController;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
