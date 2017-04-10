//  完全实现ok
//  UIGeometry.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
typedef struct UIEdgeInsets {
    CGFloat top, left, bottom, right;  // specify amount to inset (positive) for each of the edges. values can be negative to 'outset'
} UIEdgeInsets;

static inline UIEdgeInsets UIEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right) {
    return (UIEdgeInsets){top, left, bottom, right};
}

static inline CGRect UIEdgeInsetsInsetRect(CGRect rect, UIEdgeInsets insets) {
    rect.origin.x    += insets.left;
    rect.origin.y    += insets.top;
    rect.size.width  -= (insets.left + insets.right);
    rect.size.height -= (insets.top  + insets.bottom);
    return rect;
}

static inline BOOL UIEdgeInsetsEqualToEdgeInsets(UIEdgeInsets insets1, UIEdgeInsets insets2) {
    return CGRectEqualToRect(CGRectMake(insets1.left, insets1.top, insets1.right, insets1.bottom),
                             CGRectMake(insets2.left, insets2.top, insets2.right, insets2.bottom));
}

extern const UIEdgeInsets UIEdgeInsetsZero;

typedef struct UIOffset {
    CGFloat horizontal, vertical;
} UIOffset;

static inline UIOffset UIOffsetMake(CGFloat horizontal, CGFloat vertical) {
    return (UIOffset){horizontal, vertical};
}

static inline BOOL UIOffsetEqualToOffset(UIOffset offset1, UIOffset offset2) {
    return offset1.horizontal == offset2.horizontal && offset1.vertical == offset2.vertical;
}

extern const UIOffset UIOffsetZero;

NSString *NSStringFromCGPoint(CGPoint p);
NSString *NSStringFromCGRect(CGRect r);
NSString *NSStringFromCGSize(CGSize s);

NSString *NSStringFromCGAffineTransform(CGAffineTransform transform);

NSString *NSStringFromUIEdgeInsets(UIEdgeInsets insets);

NSString *NSStringFromUIOffset(UIOffset offset);

@interface NSValue (NSValueUIGeometryExtensions)
+ (NSValue *)valueWithCGPoint:(CGPoint)point;
+ (NSValue *)valueWithCGRect:(CGRect)rect;
+ (NSValue *)valueWithCGSize:(CGSize)size;
+ (NSValue *)valueWithUIEdgeInsets:(UIEdgeInsets)insets;
+ (NSValue *)valueWithUIOffset:(UIOffset)offset;
- (CGPoint)CGPointValue;
- (CGRect)CGRectValue;
- (CGSize)CGSizeValue;
- (UIEdgeInsets)UIEdgeInsetsValue;
- (UIOffset)UIOffsetValue;
@end

@interface NSCoder (NSCoderUIGeometryExtensions)
- (void)encodeCGPoint:(CGPoint)point forKey:(NSString *)key;
- (CGPoint)decodeCGPointForKey:(NSString *)key;
- (void)encodeCGRect:(CGRect)rect forKey:(NSString *)key;
- (CGRect)decodeCGRectForKey:(NSString *)key;
@end

