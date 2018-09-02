/*
 * NSSortDescriptor.h
 *
 * Framework: Foundation (c) 2002-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕ 该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/NSArray.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSOrderedSet.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSSortDescriptor : NSObject <NSSecureCoding, NSCopying> {
@private
    NSUInteger _sortDescriptorFlags;
    NSString *_key;
    SEL _selector;
    id _selectorOrBlock;
}

+ (instancetype)sortDescriptorWithKey:(nullable NSString *)key ascending:(BOOL)ascending API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));
+ (instancetype)sortDescriptorWithKey:(nullable NSString *)key ascending:(BOOL)ascending selector:(nullable SEL)selector API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

// keys may be key paths
- (instancetype)initWithKey:(nullable NSString *)key ascending:(BOOL)ascending;
- (instancetype)initWithKey:(nullable NSString *)key ascending:(BOOL)ascending selector:(nullable SEL)selector;
- (nullable instancetype)initWithCoder:(NSCoder *)coder;

@property (nullable, readonly, copy) NSString *key;
@property (readonly) BOOL ascending;
@property (nullable, readonly) SEL selector;

- (void)allowEvaluation API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); // Force a sort descriptor which was securely decoded to allow evaluation

+ (instancetype)sortDescriptorWithKey:(nullable NSString *)key ascending:(BOOL)ascending comparator:(NSComparator)cmptr API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

- (instancetype)initWithKey:(nullable NSString *)key ascending:(BOOL)ascending comparator:(NSComparator)cmptr API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@property (readonly) NSComparator comparator API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

- (NSComparisonResult)compareObject:(id)object1 toObject:(id)object2;    // primitive - override this method if you want to perform comparisons differently (not key based for example)
@property (readonly, retain) id reversedSortDescriptor;    // primitive - override this method to return a sort descriptor instance with reversed sort order

@end

@interface NSSet<ObjectType> (NSSortDescriptorSorting)

- (NSArray<ObjectType> *)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));    // returns a new array by sorting the objects of the receiver

@end

@interface NSArray<ObjectType> (NSSortDescriptorSorting)

- (NSArray<ObjectType> *)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors;    // returns a new array by sorting the objects of the receiver

@end

@interface NSMutableArray<ObjectType> (NSSortDescriptorSorting)

- (void)sortUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors;    // sorts the array itself

@end

@interface NSOrderedSet<ObjectType> (NSKeyValueSorting)

// returns a new array by sorting the objects of the receiver
- (NSArray<ObjectType> *)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0));

@end

@interface NSMutableOrderedSet<ObjectType> (NSKeyValueSorting)

// sorts the ordered set itself
- (void)sortUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0));

@end

NS_ASSUME_NONNULL_END
