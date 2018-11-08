/*
 * UIRegion.h
 *
 * UIKit (c) 2015-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(9_0) @interface UIRegion : NSObject <NSCopying, NSCoding>

/*! A shared infinite region
 */
#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) UIRegion *infiniteRegion;
#else
+ (UIRegion *)infiniteRegion;
#endif

/*! Create a circular region with radius
 */
- (instancetype)initWithRadius:(CGFloat)radius;

/*! Create a rectangular region of size.
 */
- (instancetype)initWithSize:(CGSize)size;

/*! Create a new region that is the inverse of the current region.
 The inverse of the infiniteRegion is an empty region.
 Subclasses of UIRegion need to provide an implementation of inverseRegion.
 */
- (instancetype)inverseRegion;

/*! Create a new region that is the original region plus the supplied region
 */
- (instancetype)regionByUnionWithRegion:(UIRegion *)region;

/*! Create a new region that is the original region minus the supplied region
 */
- (instancetype)regionByDifferenceFromRegion:(UIRegion *)region;

/*! Create a new region that is the region covered by the original region and the supplied region
 */
- (instancetype)regionByIntersectionWithRegion:(UIRegion *)region;

/*! Test for containment
 */
- (BOOL)containsPoint:(CGPoint)point;

@end


NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
