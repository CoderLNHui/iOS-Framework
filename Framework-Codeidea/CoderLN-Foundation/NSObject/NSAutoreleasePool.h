/*
 * NSAutoreleasePool.h
 *
 * Foundation (c) 1994-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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

