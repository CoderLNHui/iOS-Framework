/*
 * NSRange.h
 *
 * Framework: Foundation (c) 1994-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕ 该模块将系统化学习，后续替换、补充文章内容 ~
 */
 
#import <Foundation/NSValue.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

NS_ASSUME_NONNULL_BEGIN

typedef struct _NSRange {
    NSUInteger location;
    NSUInteger length;
} NSRange;

typedef NSRange *NSRangePointer;

NS_INLINE NSRange NSMakeRange(NSUInteger loc, NSUInteger len) {
    NSRange r;
    r.location = loc;
    r.length = len;
    return r;
}

NS_INLINE NSUInteger NSMaxRange(NSRange range) {
    return (range.location + range.length);
}

NS_INLINE BOOL NSLocationInRange(NSUInteger loc, NSRange range) {
    return (!(loc < range.location) && (loc - range.location) < range.length) ? YES : NO;
}

NS_INLINE BOOL NSEqualRanges(NSRange range1, NSRange range2) {
    return (range1.location == range2.location && range1.length == range2.length);
}

FOUNDATION_EXPORT NSRange NSUnionRange(NSRange range1, NSRange range2);
FOUNDATION_EXPORT NSRange NSIntersectionRange(NSRange range1, NSRange range2);
FOUNDATION_EXPORT NSString *NSStringFromRange(NSRange range);
FOUNDATION_EXPORT NSRange NSRangeFromString(NSString *aString);

@interface NSValue (NSValueRangeExtensions)

+ (NSValue *)valueWithRange:(NSRange)range;
@property (readonly) NSRange rangeValue;

@end

NS_ASSUME_NONNULL_END
