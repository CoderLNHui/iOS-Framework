/*
 * NSCompoundPredicate.h
 *
 * Foundation (c) 2004-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <Foundation/NSPredicate.h>

@class NSArray<ObjectType>;

NS_ASSUME_NONNULL_BEGIN

// Compound predicates are predicates which act on the results of evaluating other operators. We provide the basic boolean operators: AND, OR, and NOT.

typedef NS_ENUM(NSUInteger, NSCompoundPredicateType) {
    NSNotPredicateType = 0,
    NSAndPredicateType,
    NSOrPredicateType,
};

NS_CLASS_AVAILABLE(10_4, 3_0)
@interface NSCompoundPredicate : NSPredicate {
@private
    void *_reserved2;
    NSUInteger _type;
    NSArray *_subpredicates;
}

- (instancetype)initWithType:(NSCompoundPredicateType)type subpredicates:(NSArray<NSPredicate *> *)subpredicates NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@property (readonly) NSCompoundPredicateType compoundPredicateType;
@property (readonly, copy) NSArray *subpredicates;

/*** Convenience Methods ***/
+ (NSCompoundPredicate *)andPredicateWithSubpredicates:(NSArray<NSPredicate *> *)subpredicates NS_SWIFT_NAME(init(andPredicateWithSubpredicates:));
+ (NSCompoundPredicate *)orPredicateWithSubpredicates:(NSArray<NSPredicate *> *)subpredicates NS_SWIFT_NAME(init(orPredicateWithSubpredicates:));
+ (NSCompoundPredicate *)notPredicateWithSubpredicate:(NSPredicate *)predicate NS_SWIFT_NAME(init(notPredicateWithSubpredicate:));

@end
NS_ASSUME_NONNULL_END

