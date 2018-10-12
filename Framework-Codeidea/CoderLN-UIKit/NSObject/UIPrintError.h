/*
 * UIPrintError.h
 *
 * UIKit (c) 2010-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSErrorDomain const UIPrintErrorDomain __TVOS_PROHIBITED;

enum {
    UIPrintingNotAvailableError = 1,  // cannot print at this time
    UIPrintNoContentError,            // empty list of files or images
    UIPrintUnknownImageFormatError,   // unrecognized image format
    UIPrintJobFailedError,            // internal error with print job
} __TVOS_PROHIBITED;
NS_ASSUME_NONNULL_END

