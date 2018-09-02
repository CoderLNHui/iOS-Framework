/*
 * NSNull.h
 *
 * Framework: Foundation (c) 1994-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕ 该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSNull : NSObject <NSCopying, NSSecureCoding>

+ (NSNull *)null;

@end

NS_ASSUME_NONNULL_END

