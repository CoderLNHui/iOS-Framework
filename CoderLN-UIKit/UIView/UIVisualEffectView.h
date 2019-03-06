/*
 * UIVisualEffectView.h
 *
 * UIKit (c) 2014-2017
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


/**
 使用 UIVisualEffectView 实现毛玻璃效果
 
 通常要想创建一个特殊效果(如blur效果)，可以创建一个UIVisualEffectView视图对象，这个对象提供了一种简单的方式来实现复杂的视觉效果。这个可以把这个对象看作是效果的一个容器；
 
 其大小和需要模糊的imageView大小一样，最后将其盖在了imageView上面，实现了模糊效果；如果我们要实现局部模糊，那么只需调整UIVisualEffectView的Frame即可；
 
 需要注意是的，不应该直接添加子视图到UIVisualEffectView视图中，而是应该添加到UIVisualEffectView对象的contentView中。
 */

#import <UIKit/UIView.h>
#import <UIKit/UIBlurEffect.h>
#import <UIKit/UIVibrancyEffect.h>

NS_ASSUME_NONNULL_BEGIN

/* UIVisualEffectView is a class that provides a simple abstraction over complex visual effects. Depending on the desired effect, the results may affect content layered behind the view or content added to the view's contentView. Please see the notes for each UIVisualEffect for more details.
 
 Proper use of this class requires some assistance on your part. Namely:
 
 • Avoid alpha values < 1 - By default, when a view is partially transparent, the system composites that view and all of its subviews in an offscreen render pass to get the correct translucency. However, UIVisualEffects require being composited as part of the content they are logically layered on top of to look correct. If alpha is less than 1 on the UIVisualEffectView or any of its superviews, many effects will look incorrect or won't show up at all. Setting the alpha on views placed inside the contentView is supported.
 
 • Judicious masking - Masks have similar semantics to non-opaque views with regards to offscreen rendering. Masks applied to the UIVisualEffectView itself are forwarded to all internal views, including the contentView. You are free to apply a mask to just the contentView. The mask you provide to UIVisualEffectView will not be the view that actually performs the mask. UIKit will make copies of the view to apply to each subview. To reflect a size change to the mask, you must apply the change to the original mask view and reset it on the effect view. Applying a mask to a superview of a UIVisualEffectView (via setMaskView: or the layer's mask property) will cause the effect to fail.
 
 • Correctly capturing snapshots - Many effects require support from the window that hosts the view. As such, attempting to take a snapshot of just the UIVisualEffectView will result in the snapshot not containing the effect at all or it appearing incorrectly. To properly snapshot a view hierarchy that contains a UIVisualEffectView, you must snapshot the entire UIWindow or UIScreen that contains it.
 */

NS_CLASS_AVAILABLE_IOS(8_0) @interface UIVisualEffectView : UIView <NSSecureCoding>

@property (nonatomic, strong, readonly) UIView *contentView; // Do not add subviews directly to UIVisualEffectView, use this view instead.

@property (nonatomic, copy, nullable) UIVisualEffect *effect;

- (instancetype)initWithEffect:(nullable UIVisualEffect *)effect NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end
NS_ASSUME_NONNULL_END






//----------------------- <#我是分割线#> ------------------------//
//


/**

- (void)viewDidLoad {
    [super viewDidLoad];
    
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    
    //添加待模糊的图片视图
    UIImageView * imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"image"]];
    [imageView setFrame:screenRect];
    [self.view addSubview:imageView];
    
    // 生成特定样式的模糊效果
    UIBlurEffect * blurEffect = [UIBlurEffect effectWithStyle:UIBlurEffectStyleDark];
    
    // 根据模糊效果生成模糊视图
    UIVisualEffectView * effectView = [[UIVisualEffectView alloc] initWithEffect:blurEffect];
    
    // 设定模糊区域大小 (如果我们要实现局部模糊，只需更改这里的frame)
    [effectView setFrame:screenRect];
    
    [self.imageView addSubview:effectView];
}
 
 */


























