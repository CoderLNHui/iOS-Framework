/*
 * NSPredicate.h 谓词过滤器
 *
 * Foundation (c) 1994-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

/*    NSPredicate.h
 Copyright (c) 2004-2017, Apple Inc. All rights reserved.
 */

#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSOrderedSet.h>

@class NSDictionary <KeyType, ObjectType>, NSString;

NS_ASSUME_NONNULL_BEGIN

// Predicates wrap some combination of expressions and operators and when evaluated return a BOOL.
// 谓词包含表达式和运算符的某种组合，并在计算时返回BOOL

NS_CLASS_AVAILABLE(10_4, 3_0)
@interface NSPredicate : NSObject <NSSecureCoding, NSCopying> {
    struct _predicateFlags {
        unsigned int _evaluationBlocked:1;
        unsigned int _reservedPredicateFlags:31;
    } _predicateFlags;
#ifdef __LP64__
    uint32_t reserved;
#endif
}

#pragma mark - 创建谓词解析格式
// Parse predicateFormat and return an appropriate predicate
// 解析谓词格式并返回适当的谓词
+ (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat argumentArray:(nullable NSArray *)arguments;
+ (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat, ...;
+ (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat arguments:(va_list)argList;

+ (nullable NSPredicate *)predicateFromMetadataQueryString:(NSString *)queryString API_AVAILABLE(macos(10.9)) API_UNAVAILABLE(ios, watchos, tvos);

+ (NSPredicate *)predicateWithValue:(BOOL)value;    // return predicates that always evaluate to true/false

+ (NSPredicate*)predicateWithBlock:(BOOL (^)(id _Nullable evaluatedObject, NSDictionary<NSString *, id> * _Nullable bindings))block API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@property (readonly, copy) NSString *predicateFormat;    // returns the format string of the predicate

- (instancetype)predicateWithSubstitutionVariables:(NSDictionary<NSString *, id> *)variables;    // substitute constant values for variables

- (BOOL)evaluateWithObject:(nullable id)object;    // evaluate a predicate against a single object

- (BOOL)evaluateWithObject:(nullable id)object substitutionVariables:(nullable NSDictionary<NSString *, id> *)bindings API_AVAILABLE(macos(10.5), ios(3.0), watchos(2.0), tvos(9.0)); // single pass evaluation substituting variables from the bindings dictionary for any variable expressions encountered

- (void)allowEvaluation API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0)); // Force a predicate which was securely decoded to allow evaluation

@end

/**
 通过下面的描述可以看出
 使用谓词过滤不可变集合和可变集合的区别是：过滤不可变集合时，会返回符合条件的集合元素组成的新集合；过滤可变集合时，没有返回值，会直接剔除不符合条件的集合元素
 */

/**
 NSArray提供了如下方法使用谓词来过滤集合
 - (NSArray<ObjectType> *)filteredArrayUsingPredicate:(NSPredicate *)predicate:使用指定的谓词过滤NSArray集合，返回符合条件的元素组成的新集合
 */
@interface NSArray<ObjectType> (NSPredicateSupport)
- (NSArray<ObjectType> *)filteredArrayUsingPredicate:(NSPredicate *)predicate;    // evaluate a predicate against an array of objects and return a filtered array
@end


/**
 NSMutableArray提供了如下方法使用谓词来过滤集合
 - (void)filterUsingPredicate:(NSPredicate *)predicate：使用指定的谓词过滤NSMutableArray，剔除集合中不符合条件的元素
 */
@interface NSMutableArray<ObjectType> (NSPredicateSupport)
- (void)filterUsingPredicate:(NSPredicate *)predicate;    // evaluate a predicate against an array of objects and filter the mutable array directly
@end


/**
 NSSet提供了如下方法使用谓词来过滤集合
 - (NSSet<ObjectType> *)filteredSetUsingPredicate:(NSPredicate *)predicate NS_AVAILABLE(10_5, 3_0)：作用同NSArray中的方法
 */
@interface NSSet<ObjectType> (NSPredicateSupport)
- (NSSet<ObjectType> *)filteredSetUsingPredicate:(NSPredicate *)predicate API_AVAILABLE(macos(10.5), ios(3.0), watchos(2.0), tvos(9.0));    // evaluate a predicate against a set of objects and return a filtered set
@end


/**
 NSMutableSet提供了如下方法使用谓词来过滤集合
 - (void)filterUsingPredicate:(NSPredicate *)predicate NS_AVAILABLE(10_5, 3_0)：作用同NSMutableArray中的方法。
 */
@interface NSMutableSet<ObjectType> (NSPredicateSupport)
- (void)filterUsingPredicate:(NSPredicate *)predicate API_AVAILABLE(macos(10.5), ios(3.0), watchos(2.0), tvos(9.0));    // evaluate a predicate against a set of objects and filter the mutable set directly
@end

@interface NSOrderedSet<ObjectType> (NSPredicateSupport)

- (NSOrderedSet<ObjectType> *)filteredOrderedSetUsingPredicate:(NSPredicate *)p API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0));    // evaluate a predicate against an ordered set of objects and return a filtered ordered set

@end

@interface NSMutableOrderedSet<ObjectType> (NSPredicateSupport)

- (void)filterUsingPredicate:(NSPredicate *)p API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0));  // evaluate a predicate against an ordered set of objects and filter the mutable ordered set directly

@end
NS_ASSUME_NONNULL_END
