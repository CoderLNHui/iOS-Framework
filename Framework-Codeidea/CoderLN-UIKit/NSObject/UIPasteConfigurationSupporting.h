/*
 * UIPasteConfigurationSupporting.h
 *
 * Framework: UIKit (c) 2007-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPasteConfiguration;

UIKIT_EXTERN API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(tvos, watchos)
@protocol UIPasteConfigurationSupporting <NSObject>

@property (nonatomic, copy, nullable) UIPasteConfiguration *pasteConfiguration;

@optional
- (void)pasteItemProviders:(NSArray<NSItemProvider *> *)itemProviders;
- (BOOL)canPasteItemProviders:(NSArray<NSItemProvider *> *)itemProviders;

@end

NS_ASSUME_NONNULL_END

