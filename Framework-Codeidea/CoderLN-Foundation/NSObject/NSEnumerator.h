/*
 * NSEnumerator.h
 *
 * Foundation (c) 1995-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/NSObject.h>

@class NSArray<ObjectType>;

NS_ASSUME_NONNULL_BEGIN

/*
 * The fast enumeration protocol NSFastEnumeration is adopted and
 * implemented by objects wishing to make use of a fast and safe
 * enumeration style.  The language "foreach" construct then can
 * be used with such objects.
 *
 * The abstract class NSEnumerator itself is taught how to do this
 * for convenience by using -nextObject to return items one at a time.
 */

typedef struct {
    unsigned long state;
    id __unsafe_unretained _Nullable * _Nullable itemsPtr;
    unsigned long * _Nullable mutationsPtr;
    unsigned long extra[5];
} NSFastEnumerationState;

@protocol NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __unsafe_unretained _Nullable [_Nonnull])buffer count:(NSUInteger)len;

@end

@interface NSEnumerator<ObjectType> : NSObject <NSFastEnumeration>

- (nullable ObjectType)nextObject;

@end

@interface NSEnumerator<ObjectType> (NSExtendedEnumerator)

@property (readonly, copy) NSArray<ObjectType> *allObjects;

@end

NS_ASSUME_NONNULL_END
