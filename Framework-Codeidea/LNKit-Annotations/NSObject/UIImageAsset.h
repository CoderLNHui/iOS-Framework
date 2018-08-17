/*
 * UIImageAsset.h
 *
 * Framework: UIKit  (c) 2014-2016
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <UIKit/UIImage.h>

NS_ASSUME_NONNULL_BEGIN

@class UITraitCollection;

NS_CLASS_AVAILABLE_IOS(8_0) @interface UIImageAsset : NSObject <NSSecureCoding>

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (UIImage *)imageWithTraitCollection:(UITraitCollection *)traitCollection; // Images returned hold a strong reference to the asset that created them
- (void)registerImage:(UIImage *)image withTraitCollection:(UITraitCollection *)traitCollection; // Adds a new variation to this image asset that is appropriate for the provided traits. Any traits not exposed by asset catalogs (such as forceTouchCapability) are ignored.
- (void)unregisterImageWithTraitCollection:(UITraitCollection *)traitCollection; // removes only those images added with registerImage:withTraitCollection:
@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

