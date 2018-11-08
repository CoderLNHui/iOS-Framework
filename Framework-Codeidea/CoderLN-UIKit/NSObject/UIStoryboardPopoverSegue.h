/*
 * UIStoryboardPopoverSegue.h
 *
 * UIKit (c) 2011-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <UIKit/UIStoryboardSegue.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPopoverController;

NS_CLASS_DEPRECATED_IOS(5_0, 9_0, "Access destinationViewController.popoverPresentationController from your segue's performHandler or override of -perform") @interface UIStoryboardPopoverSegue : UIStoryboardSegue {
}

@property (nonatomic, strong, readonly) UIPopoverController *popoverController;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
