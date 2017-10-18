/*
 * File:  UIImageView.h
 * Framework:  UIKit
 * Author:  白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2006-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook:  http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIImageView : UIView

- (instancetype)initWithImage:(nullable UIImage *)image;
- (instancetype)initWithImage:(nullable UIImage *)image highlightedImage:(nullable UIImage *)highlightedImage NS_AVAILABLE_IOS(3_0);

@property (nullable, nonatomic, strong) UIImage *image; // default is nil
@property (nullable, nonatomic, strong) UIImage *highlightedImage NS_AVAILABLE_IOS(3_0); // default is nil


/**
【是否允许交互】
 */
@property (nonatomic, getter=isUserInteractionEnabled) BOOL userInteractionEnabled; // default is NO

@property (nonatomic, getter=isHighlighted) BOOL highlighted NS_AVAILABLE_IOS(3_0); // default is NO

// these allow a set of images to be animated. the array may contain multiple copies of the same

/**
【动画图片数组】
 */
@property (nullable, nonatomic, copy) NSArray<UIImage *> *animationImages; // The array must contain UIImages. Setting hides the single image. default is nil

/**
 【动画高亮图片数组】
 */
@property (nullable, nonatomic, copy) NSArray<UIImage *> *highlightedAnimationImages NS_AVAILABLE_IOS(3_0); // The array must contain UIImages. Setting hides the single image. default is nil

/**
 【动画持续时间】
 */
@property (nonatomic) NSTimeInterval animationDuration;         // for one cycle of images. default is number of images * 1/30th of a second (i.e. 30 fps)

/**
 【动画持续次数，0表示一直重复】
 */
@property (nonatomic) NSInteger      animationRepeatCount;      // 0 means infinite (default is 0)

// When tintColor is non-nil, any template images set on the image view will be colorized with that color.
// The tintColor is inherited through the superview hierarchy. See UIView for more information.
@property (null_resettable, nonatomic, strong) UIColor *tintColor NS_AVAILABLE_IOS(7_0);

/**
 【开始动画】
 */
- (void)startAnimating;
/**
 【停止动画】
 */
- (void)stopAnimating;




#if UIKIT_DEFINE_AS_PROPERTIES
/**
 【是否动画】
 */
@property(nonatomic, readonly, getter=isAnimating) BOOL animating;
#else
- (BOOL)isAnimating;
#endif

// if YES, the UIImageView will display a focused appearance when any of its immediate or distant superviews become focused
@property (nonatomic) BOOL adjustsImageWhenAncestorFocused UIKIT_AVAILABLE_TVOS_ONLY(9_0);

// if adjustsImageWhenAncestorFocused is set, the image view may display its image in a larger frame when focused.
// this layout guide can be used to align other elements with the image view's focused frame.
@property(readonly,strong) UILayoutGuide *focusedFrameGuide UIKIT_AVAILABLE_TVOS_ONLY(9_0);

@end

#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

