/*
 * UIInteraction.h
 *
 * UIKit (c) 2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <UIKit/UIView.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos) @protocol UIInteraction <NSObject>

@property (nonatomic, nullable, weak, readonly) __kindof UIView *view;

- (void)willMoveToView:(nullable UIView *)view;
- (void)didMoveToView:(nullable UIView *)view;

@end


@interface UIView (Interactions)

- (void)addInteraction:(id<UIInteraction>)interaction API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);
- (void)removeInteraction:(id<UIInteraction>)interaction API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@property (nonatomic, copy) NSArray<id<UIInteraction>> *interactions API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos);

@end
NS_ASSUME_NONNULL_END

