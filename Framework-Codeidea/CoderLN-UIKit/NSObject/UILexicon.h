/*
 * UILexicon.h
 *
 * UIKit (c) 2014-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UILexiconEntry : NSObject <NSCopying>
// -documentText returns the intended text to be inserted into the document for a given -userInput.
// -userInput represents the expected typed string, which need not match the actual typed string.
// for example, if the -documentText were "iPhone", the corresponsing -userInput could be "iphone"
// -the documentText may also be in a different text script from the -userInput
@property (nonatomic, readonly) NSString *documentText;
@property (nonatomic, readonly) NSString *userInput;
@end

NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UILexicon : NSObject <NSCopying>
@property (nonatomic, readonly) NSArray<UILexiconEntry *> *entries;
@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
