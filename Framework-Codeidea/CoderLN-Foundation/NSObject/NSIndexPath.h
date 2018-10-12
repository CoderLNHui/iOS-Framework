/*
 * NSIndexPath.h 
 *
 * Foundation (c) 2003-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSIndexPath : NSObject <NSCopying, NSSecureCoding> {
@private
    NSUInteger *_indexes;
#if !__OBJC2__
    NSUInteger _hash;
#endif
    NSUInteger _length;
    void *_reserved;
}

+ (instancetype)indexPathWithIndex:(NSUInteger)index;
+ (instancetype)indexPathWithIndexes:(const NSUInteger [_Nullable])indexes length:(NSUInteger)length;

- (instancetype)initWithIndexes:(const NSUInteger [_Nullable])indexes length:(NSUInteger)length NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithIndex:(NSUInteger)index;


- (NSIndexPath *)indexPathByAddingIndex:(NSUInteger)index;
- (NSIndexPath *)indexPathByRemovingLastIndex;

- (NSUInteger)indexAtPosition:(NSUInteger)position;
@property (readonly) NSUInteger length;

/*!
 @abstract Copies the indexes stored in this index path from the positions specified by positionRange into indexes.
 @param indexes Buffer of at least as many NSUIntegers as specified by the length of positionRange. On return, this memory will hold the index path's indexes.
 @param positionRange A range of valid positions within this index path.  If the location plus the length of positionRange is greater than the length of this index path, this method raises an NSRangeException.
 @discussion
 It is the developer’s responsibility to allocate the memory for the C array.
 */
- (void)getIndexes:(NSUInteger *)indexes range:(NSRange)positionRange API_AVAILABLE(macos(10.9), ios(7.0), watchos(2.0), tvos(9.0));

// comparison support
- (NSComparisonResult)compare:(NSIndexPath *)otherObject; // sorting an array of indexPaths using this comparison results in an array representing nodes in depth-first traversal order

@end

@interface NSIndexPath (NSDeprecated)
/// This method is unsafe because it could potentially cause buffer overruns. You should use -getIndexes:range: instead.
- (void)getIndexes:(NSUInteger *)indexes; // use -getIndexes:range: instead
@end
NS_ASSUME_NONNULL_END

