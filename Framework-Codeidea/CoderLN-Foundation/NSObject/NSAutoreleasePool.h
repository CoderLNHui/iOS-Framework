/*
 * NSAutoreleasePool.h
 *
 * Foundation (c) 1994-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import <Foundation/NSObject.h>

NS_ASSUME_NONNULL_BEGIN

NS_AUTOMATED_REFCOUNT_UNAVAILABLE
@interface NSAutoreleasePool : NSObject {
@private
    void    *_token;
    void    *_reserved3;
    void    *_reserved2;
    void    *_reserved;
}

+ (void)addObject:(id)anObject;

- (void)addObject:(id)anObject;

- (void)drain;

@end
NS_ASSUME_NONNULL_END

