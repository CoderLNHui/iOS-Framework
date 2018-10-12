/*
 * UIReferenceLibraryViewController.h 
 *
 * UIKit (c) 2011-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <UIKit/UIViewController.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED
@interface UIReferenceLibraryViewController : UIViewController {}

/*! Returns YES if any installed dictionary has a definition for the provided term.
 */
+ (BOOL)dictionaryHasDefinitionForTerm:(NSString *)term;

/*! Initializes an instance of a UIReferenceLibraryViewController with the term provided.
 */
- (instancetype)initWithTerm:(NSString *)term NS_DESIGNATED_INITIALIZER;
- (instancetype) initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER; // Declared solely for the sake of potential subclassers.

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
