/*
 * UICollectionViewTransitionLayout.h
 *
 * UIKit (c) 2012-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

 
#import <UIKit/UICollectionViewLayout.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(7_0) @interface UICollectionViewTransitionLayout : UICollectionViewLayout

@property (assign, nonatomic) CGFloat transitionProgress;
@property (readonly, nonatomic) UICollectionViewLayout *currentLayout;
@property (readonly, nonatomic) UICollectionViewLayout *nextLayout;

- (instancetype)initWithCurrentLayout:(UICollectionViewLayout *)currentLayout nextLayout:(UICollectionViewLayout *)newLayout NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (void)updateValue:(CGFloat)value forAnimatedKey:(NSString *)key;
- (CGFloat)valueForAnimatedKey:(NSString *)key;

@end
NS_ASSUME_NONNULL_END




