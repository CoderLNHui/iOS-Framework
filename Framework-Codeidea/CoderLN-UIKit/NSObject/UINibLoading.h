/*
 * UINibLoading.h
 *
 * UIKit (c) 2005-2016
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString * const UINibExternalObjects NS_AVAILABLE_IOS(3_0);

@interface NSBundle(UINibLoadingAdditions)
- (nullable NSArray *)loadNibNamed:(NSString *)name owner:(nullable id)owner options:(nullable NSDictionary *)options;
@end

@interface NSObject(UINibLoadingAdditions)
- (void)awakeFromNib NS_REQUIRES_SUPER;
- (void)prepareForInterfaceBuilder NS_AVAILABLE_IOS(8_0);
@end

UIKIT_EXTERN NSString * const UINibProxiedObjectsKey NS_DEPRECATED_IOS(2_0, 3_0) __TVOS_PROHIBITED;

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
