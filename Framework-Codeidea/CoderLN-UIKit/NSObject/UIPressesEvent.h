/*
 * UIPressesEvent.h
 *
 * UIKit (c) 2005-2016
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */
 
#import <UIKit/UIEvent.h>
#import <UIKit/UIPress.h>
#import <UIKit/UIGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(9_0) @interface UIPressesEvent : UIEvent

#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly) NSSet <UIPress *> *allPresses;
#else
- (NSSet <UIPress *> *)allPresses;
#endif
- (NSSet <UIPress *> *)pressesForGestureRecognizer:(UIGestureRecognizer *)gesture;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
