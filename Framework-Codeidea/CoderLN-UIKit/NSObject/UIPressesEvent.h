/*
 * UIPressesEvent.h
 *
 * UIKit (c) 2005-2016
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

CoderLN_NOTE NS_ASSUME_NONNULL_END
