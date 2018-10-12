/*
 * UIPasteConfiguration.h
 *
 * UIKit (c) 2007-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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

