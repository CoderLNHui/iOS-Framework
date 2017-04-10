//  完全实现ok  UIBezierPath其实是对cg框架的包装，面向对象，便于使用
//  UIBezierPath.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, UIRectCorner) {
    UIRectCornerTopLeft     = 1 << 0,
    UIRectCornerTopRight    = 1 << 1,
    UIRectCornerBottomLeft  = 1 << 2,
    UIRectCornerBottomRight = 1 << 3,
    UIRectCornerAllCorners  = ~0
};

@interface UIBezierPath : NSObject <NSCopying>

+ (UIBezierPath *)bezierPath;
+ (UIBezierPath *)bezierPathWithRect:(CGRect)rect;
+ (UIBezierPath *)bezierPathWithOvalInRect:(CGRect)rect;
+ (UIBezierPath *)bezierPathWithRoundedRect:(CGRect)rect cornerRadius:(CGFloat)cornerRadius;
+ (UIBezierPath *)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)corners cornerRadii:(CGSize)cornerRadii;
+ (UIBezierPath *)bezierPathWithArcCenter:(CGPoint)center radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(BOOL)clockwise;
+ (UIBezierPath *)bezierPathWithCGPath:(CGPathRef)CGPath;

- (void)moveToPoint:(CGPoint)point;
- (void)addLineToPoint:(CGPoint)point;
- (void)addArcWithCenter:(CGPoint)center radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(BOOL)clockwise;
- (void)addCurveToPoint:(CGPoint)endPoint controlPoint1:(CGPoint)controlPoint1 controlPoint2:(CGPoint)controlPoint2;
- (void)addQuadCurveToPoint:(CGPoint)endPoint controlPoint:(CGPoint)controlPoint;
- (void)closePath;
- (void)removeAllPoints;
- (void)appendPath:(UIBezierPath *)bezierPath;
- (void)setLineDash:(const CGFloat *)pattern count:(NSInteger)count phase:(CGFloat)phase;
- (void)getLineDash:(CGFloat *)pattern count:(NSInteger *)count phase:(CGFloat *)phase;
- (void)fill;
- (void)fillWithBlendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha;
- (void)stroke;
- (void)strokeWithBlendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha;
- (void)addClip;
- (BOOL)containsPoint:(CGPoint)point;
- (void)applyTransform:(CGAffineTransform)transform;

@property (nonatomic) CGPathRef CGPath;
@property (nonatomic, readonly) CGPoint currentPoint;
@property (nonatomic) CGFloat lineWidth;
@property (nonatomic) CGLineCap lineCapStyle;
@property (nonatomic) CGLineJoin lineJoinStyle;
@property (nonatomic) CGFloat miterLimit;
@property (nonatomic) CGFloat flatness;
@property (nonatomic) BOOL usesEvenOddFillRule;
@property (readonly, getter=isEmpty) BOOL empty;
@property (nonatomic, readonly) CGRect bounds;

@end
