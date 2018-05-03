/*
 * UIContentSizeCategoryAdjusting.h
 *
 * Framework: UIKit (c) 2016-2016
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(10_0) @protocol UIContentSizeCategoryAdjusting <NSObject>

/*
 Indicates whether the corresponding element should automatically update its font when the device’s UIContentSizeCategory is changed.
 For this property to take effect, the element’s font must be a font vended using +preferredFontForTextStyle: or +preferredFontForTextStyle:compatibleWithTraitCollection: with a valid UIFontTextStyle.
 */
@property (nonatomic) BOOL adjustsFontForContentSizeCategory;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
