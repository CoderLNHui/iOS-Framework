/*
 * NSCache.h 缓存
 *
 * Foundation (c) 2008-2017
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
#pragma mark -名称
@property (copy) NSString *name;
#pragma mark -设置代理
@property (nullable, assign) id<NSCacheDelegate> delegate;

#pragma mark -根据key获取value值
- (nullable ObjectType)objectForKey:(KeyType)key;
#pragma mark -保存在缓存中设置指定键名对应的值，0成本
- (void)setObject:(ObjectType)obj forKey:(KeyType)key; // 0 cost
#pragma mark -保存在缓存中设置指定键名对应的值，并且指定该键值对的成本
//用于计算记录在缓存中的所有对象的总成本，出现内存警告或者超出缓存总成本上限的时候，缓存会开启一个回收过程，删除部分元素
- (void)setObject:(ObjectType)obj forKey:(KeyType)key cost:(NSUInteger)g;

#pragma mark -移除缓存中指定键名的对象
- (void)removeObjectForKey:(KeyType)key;
#pragma mark -移除缓存中所有的对象
- (void)removeAllObjects;

#pragma mark -设置缓存空间的最大总成本，超出上限会自动回收之前对象。默认值为0，表示没有限制
@property NSUInteger totalCostLimit;    // limits are imprecise/not strict
#pragma mark -设置能够缓存的对象的最大数量。默认值为0，表示没有限制
@property NSUInteger countLimit;    // limits are imprecise/not strict
#pragma mark -标识缓存是否回收废弃的内容
@property BOOL evictsObjectsWithDiscardedContent;

@end

@protocol NSCacheDelegate <NSObject>
@optional
#pragma mark -即将回收对象的时候调用该方法
- (void)cache:(NSCache *)cache willEvictObject:(id)obj;
@end
NS_ASSUME_NONNULL_END
