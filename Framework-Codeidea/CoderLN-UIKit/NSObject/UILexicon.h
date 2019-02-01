/*
 * UILexicon.h
 *
 * UIKit (c) 2014-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

CoderLN_NOTE NS_ASSUME_NONNULL_END
