/*
 * UIPrintPaper.h
 *
 * UIKit (c) 2010-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(4_2)__TVOS_PROHIBITED @interface UIPrintPaper : NSObject

+ (UIPrintPaper *)bestPaperForPageSize:(CGSize)contentSize withPapersFromArray:(NSArray<UIPrintPaper *> *)paperList; // for use by delegate. pass in list

@property(readonly) CGSize paperSize;
@property(readonly) CGRect printableRect;

@end

//_____________________________________________

@interface UIPrintPaper(Deprecated_Nonfunctional)
- (CGRect)printRect __TVOS_PROHIBITED ;
@end
NS_ASSUME_NONNULL_END
