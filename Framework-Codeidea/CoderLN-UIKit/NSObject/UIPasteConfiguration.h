/*
 * UIPasteConfiguration.h
 *
 * UIKit (c) 2007-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN


UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(watchos, tvos)
@interface UIPasteConfiguration : NSObject <NSSecureCoding, NSCopying>

@property (nonatomic, copy) NSArray<NSString *> *acceptableTypeIdentifiers;

- (instancetype)init NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithAcceptableTypeIdentifiers:(NSArray<NSString *> *)acceptableTypeIdentifiers;
- (void)addAcceptableTypeIdentifiers:(NSArray<NSString *> *)acceptableTypeIdentifiers;

// Uses the readableTypeIdentifiersForItemProvider class property to get acceptable types.
- (instancetype)initWithTypeIdentifiersForAcceptingClass:(Class<NSItemProviderReading>)aClass;
- (void)addTypeIdentifiersForAcceptingClass:(Class<NSItemProviderReading>)aClass;

@end
NS_ASSUME_NONNULL_END

