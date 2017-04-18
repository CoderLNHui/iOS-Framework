//
//  UIGeometry.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIGeometry.h"

const UIEdgeInsets UIEdgeInsetsZero = {0,0,0,0};
const UIOffset UIOffsetZero = {0,0};

NSString *NSStringFromCGPoint(CGPoint p)
{
    return NSStringFromPoint(NSPointFromCGPoint(p));
}

NSString *NSStringFromCGRect(CGRect r)
{
    return NSStringFromRect(NSRectFromCGRect(r));
}

NSString *NSStringFromCGSize(CGSize s)
{
    return NSStringFromSize(NSSizeFromCGSize(s));
}

NSString *NSStringFromCGAffineTransform(CGAffineTransform transform)
{
    return [NSString stringWithFormat:@"[%g, %g, %g, %g, %g, %g]", transform.a, transform.b, transform.c, transform.d, transform.tx, transform.ty];
}

NSString *NSStringFromUIEdgeInsets(UIEdgeInsets insets)
{
    return [NSString stringWithFormat:@"{%g, %g, %g, %g}", insets.top, insets.left, insets.bottom, insets.right];
}

NSString *NSStringFromUIOffset(UIOffset offset)
{
    return [NSString stringWithFormat:@"{%g, %g}", offset.horizontal, offset.vertical];
}

@implementation NSValue (NSValueUIGeometryExtensions)
+ (NSValue *)valueWithCGPoint:(CGPoint)point
{
    return [NSValue valueWithPoint:NSPointFromCGPoint(point)];
}

- (CGPoint)CGPointValue
{
    return NSPointToCGPoint([self pointValue]);
}

+ (NSValue *)valueWithCGRect:(CGRect)rect
{
    return [NSValue valueWithRect:NSRectFromCGRect(rect)];
}

- (CGRect)CGRectValue
{
    return NSRectToCGRect([self rectValue]);
}

+ (NSValue *)valueWithCGSize:(CGSize)size
{
    return [NSValue valueWithSize:NSSizeFromCGSize(size)];
}

- (CGSize)CGSizeValue
{
    return NSSizeToCGSize([self sizeValue]);
}

+ (NSValue *)valueWithUIEdgeInsets:(UIEdgeInsets)insets
{
    return [NSValue valueWithBytes: &insets objCType: @encode(UIEdgeInsets)];
}

- (UIEdgeInsets)UIEdgeInsetsValue
{
    if(strcmp([self objCType], @encode(UIEdgeInsets)) == 0)
    {
        UIEdgeInsets insets;
        [self getValue: &insets];
        return insets;
    }
    return UIEdgeInsetsZero;
}

+ (NSValue *)valueWithUIOffset:(UIOffset)offset
{
    return [NSValue valueWithBytes: &offset objCType: @encode(UIOffset)];
}

- (UIOffset)UIOffsetValue
{
    if(strcmp([self objCType], @encode(UIOffset)) == 0)
    {
        UIOffset offset;
        [self getValue: &offset];
        return offset;
    }
    return UIOffsetZero;
}
@end

@implementation NSCoder (NSCoderUIGeometryExtensions)
- (void)encodeCGPoint:(CGPoint)point forKey:(NSString *)key
{
    [self encodePoint:NSPointFromCGPoint(point) forKey:key];
}

- (CGPoint)decodeCGPointForKey:(NSString *)key
{
    return NSPointToCGPoint([self decodePointForKey:key]);
}

- (void)encodeCGRect:(CGRect)rect forKey:(NSString *)key
{
    [self encodeRect:NSRectFromCGRect(rect) forKey:key];
}

- (CGRect)decodeCGRectForKey:(NSString *)key
{
    return NSRectToCGRect([self decodeRectForKey:key]);
}

@end