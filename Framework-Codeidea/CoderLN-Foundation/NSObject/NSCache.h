/*
 * NSCache.h
 *
 * Foundation (c) 2008-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <Foundation/NSObject.h>

@class NSString;
@protocol NSCacheDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_6, 4_0)
@interface NSCache <KeyType, ObjectType> : NSObject {
@private
    id _delegate;
    void *_private[5];
    void *_reserved;
}

@property (copy) NSString *name;

@property (nullable, assign) id<NSCacheDelegate> delegate;

- (nullable ObjectType)objectForKey:(KeyType)key;
- (void)setObject:(ObjectType)obj forKey:(KeyType)key; // 0 cost
- (void)setObject:(ObjectType)obj forKey:(KeyType)key cost:(NSUInteger)g;
- (void)removeObjectForKey:(KeyType)key;

- (void)removeAllObjects;

@property NSUInteger totalCostLimit;    // limits are imprecise/not strict
@property NSUInteger countLimit;    // limits are imprecise/not strict
@property BOOL evictsObjectsWithDiscardedContent;

@end

@protocol NSCacheDelegate <NSObject>
@optional
- (void)cache:(NSCache *)cache willEvictObject:(id)obj;
@end

NS_ASSUME_NONNULL_END
