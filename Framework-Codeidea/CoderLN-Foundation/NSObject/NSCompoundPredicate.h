/*
 * NSCompoundPredicate.h
 *
 * Foundation (c) 2004-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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

