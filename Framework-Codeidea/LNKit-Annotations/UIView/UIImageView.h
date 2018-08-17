/*
 * File:  UIImageView.h 
 *
 * Framework: UIKit (c) 2006-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

#pragma mark - 图片视图
NS_CLASS_AVAILABLE_IOS(2_0) @interface UIImageView : UIView

- (instancetype)initWithImage:(nullable UIImage *)image;
- (instancetype)initWithImage:(nullable UIImage *)image highlightedImage:(nullable UIImage *)highlightedImage NS_AVAILABLE_IOS(3_0);

#pragma mark -图片
@property (nullable, nonatomic, strong) UIImage *image; // default is nil
#pragma mark -高亮图片
@property (nullable, nonatomic, strong) UIImage *highlightedImage NS_AVAILABLE_IOS(3_0); // default is nil

#pragma mark -是否允许交互
@property (nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled; // default is NO

@property (nonatomic, getter=isHighlighted) BOOL highlighted NS_AVAILABLE_IOS(3_0); // default is NO

// these allow a set of images to be animated. the array may contain multiple copies of the same
#pragma mark -动画图片数组
@property (nullable, nonatomic, copy) NSArray<UIImage *> *animationImages; // The array must contain UIImages. Setting hides the single image. default is nil

#pragma mark -动画高亮图片数组
@property (nullable, nonatomic, copy) NSArray<UIImage *> *highlightedAnimationImages NS_AVAILABLE_IOS(3_0); // The array must contain UIImages. Setting hides the single image. default is nil

#pragma mark -动画持续时间
@property (nonatomic) NSTimeInterval animationDuration;         // for one cycle of images. default is number of images * 1/30th of a second (i.e. 30 fps)

#pragma mark -动画持续次数，0表示一直重复
@property (nonatomic) NSInteger      animationRepeatCount;      // 0 means infinite (default is 0)

// When tintColor is non-nil, any template images set on the image view will be colorized with that color.
// The tintColor is inherited through the superview hierarchy. See UIView for more information.
@property (null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(7_0);

#pragma mark -开始动画
- (void)startAnimating;
#pragma mark -停止动画
- (void)stopAnimating;


#if UIKIT_DEFINE_AS_PROPERTIES
#pragma mark - 是否动画
@property(nonatomic, readonly, getter=isAnimating) BOOL animating;
#else
- (BOOL)isAnimating;
#endif

// if YES, the UIImageView will display a focused appearance when any of its immediate or distant superviews become focused
@property (nonatomic) BOOL adjustsImageWhenAncestorFocused UIKIT_AVAILABLE_TVOS_ONLY(9_0);

// if adjustsImageWhenAncestorFocused is set, the image view may display its image in a larger frame when focused.
// this layout guide can be used to align other elements with the image view's focused frame.
@property(readonly,strong) UILayoutGuide *focusedFrameGuide UIKIT_AVAILABLE_TVOS_ONLY(9_0);

// the overlayContentView will be placed above the image, automatically resized to fill the image view's frame, and created if necessary when this property is accessed.
// You may add your own subviews to this view.
// By default, the overlayContentView will clip its children to the image view's frame. Set the overlayContentView's clipsToBounds property to false to allow views to draw outside of the image.
// On tvOS, if adjustsImageWhenAncestorFocused is true, the overlayContentView will receive the same floating effects as the image when focused.
@property (nonatomic, strong, readonly) UIView *overlayContentView UIKIT_AVAILABLE_TVOS_ONLY(11_0);

// if YES, the UIImageView's focused appearance will support transparency in the image.
// For example, the shadow will be based on the alpha channel of the image; the highlight will be masked to the image's alpha channel, etc.
// This property is only supported for single-layer images, not images will multiple layers like LCRs.
// Additionally, the image view must have the same aspect ratio as its image for this property to be effective.
// Supporting transparency affects performance, so only set this when needed.
@property (nonatomic) BOOL masksFocusEffectToContents UIKIT_AVAILABLE_TVOS_ONLY(11_0);
@end
