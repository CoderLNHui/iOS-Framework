/*
 * UIPrintPaper.h
 *
 * UIKit (c) 2010-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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
