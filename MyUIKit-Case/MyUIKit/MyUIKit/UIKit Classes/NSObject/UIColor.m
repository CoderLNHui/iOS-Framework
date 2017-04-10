//
//  UIColor.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIColor.h"
#import <AppKit/NSColor.h>
#import <AppKit/NSColorSpace.h>
#import "UIColorRep.h"
#import "UIImage+UIPrivate.h"


static UIColor *BlackColor = nil;
static UIColor *DarkGrayColor = nil;
static UIColor *LightGrayColor = nil;
static UIColor *WhiteColor = nil;
static UIColor *GrayColor = nil;
static UIColor *RedColor = nil;
static UIColor *GreenColor = nil;
static UIColor *BlueColor = nil;
static UIColor *CyanColor = nil;
static UIColor *YellowColor = nil;
static UIColor *MagentaColor = nil;
static UIColor *OrangeColor = nil;
static UIColor *PurpleColor = nil;
static UIColor *BrownColor = nil;
static UIColor *ClearColor = nil;
static UIColor *LightTextColor = nil;

@implementation UIColor
{
    NSArray *_representations;
}

- (id)initWithNSColor:(NSColor *)aColor
{
    if (!aColor) {
        self = nil;
    } else {
        NSColor *c = [aColor colorUsingColorSpace:[NSColorSpace deviceRGBColorSpace]];
        CGFloat components[[c numberOfComponents]];
        [c getComponents:components];
        CGColorRef color = CGColorCreate([[c colorSpace] CGColorSpace], components);
        self = [self initWithCGColor:color];
        CGColorRelease(color);
    }
    return self;
}


+ (id)colorWithNSColor:(NSColor *)c
{
    return [[self alloc] initWithNSColor:c];
}

+ (UIColor *)colorWithWhite:(CGFloat)white alpha:(CGFloat)alpha
{
    return [[self alloc] initWithWhite:white alpha:alpha];
}

+ (UIColor *)colorWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha
{
    return [[self alloc] initWithHue:hue saturation:saturation brightness:brightness alpha:alpha];
}

+ (UIColor *)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha
{
    return [[self alloc] initWithRed:red green:green blue:blue alpha:alpha];
}

+ (UIColor *)colorWithCGColor:(CGColorRef)ref
{
    return [[self alloc] initWithCGColor:ref];
}

+ (UIColor *)colorWithPatternImage:(UIImage *)patternImage
{
    return [[self alloc] initWithPatternImage:patternImage];
}

+ (UIColor *)blackColor			{ return BlackColor ?: (BlackColor = [[self alloc] initWithNSColor:[NSColor blackColor]]); }
+ (UIColor *)darkGrayColor		{ return DarkGrayColor ?: (DarkGrayColor = [[self alloc] initWithNSColor:[NSColor darkGrayColor]]); }
+ (UIColor *)lightGrayColor		{ return LightGrayColor ?: (LightGrayColor = [[self alloc] initWithNSColor:[NSColor lightGrayColor]]); }
+ (UIColor *)whiteColor			{ return WhiteColor ?: (WhiteColor = [[self alloc] initWithNSColor:[NSColor whiteColor]]); }
+ (UIColor *)grayColor			{ return GrayColor ?: (GrayColor = [[self alloc] initWithNSColor:[NSColor grayColor]]); }
+ (UIColor *)redColor			{ return RedColor ?: (RedColor = [[self alloc] initWithNSColor:[NSColor redColor]]); }
+ (UIColor *)greenColor			{ return GreenColor ?: (GreenColor = [[self alloc] initWithNSColor:[NSColor greenColor]]); }
+ (UIColor *)blueColor			{ return BlueColor ?: (BlueColor = [[self alloc] initWithNSColor:[NSColor blueColor]]); }
+ (UIColor *)cyanColor			{ return CyanColor ?: (CyanColor = [[self alloc] initWithNSColor:[NSColor cyanColor]]); }
+ (UIColor *)yellowColor		{ return YellowColor ?: (YellowColor = [[self alloc] initWithNSColor:[NSColor yellowColor]]); }
+ (UIColor *)magentaColor		{ return MagentaColor ?: (MagentaColor = [[self alloc] initWithNSColor:[NSColor magentaColor]]); }
+ (UIColor *)orangeColor		{ return OrangeColor ?: (OrangeColor = [[self alloc] initWithNSColor:[NSColor orangeColor]]); }
+ (UIColor *)purpleColor		{ return PurpleColor ?: (PurpleColor = [[self alloc] initWithNSColor:[NSColor purpleColor]]); }
+ (UIColor *)brownColor			{ return BrownColor ?: (BrownColor = [[self alloc] initWithNSColor:[NSColor brownColor]]); }
+ (UIColor *)clearColor			{ return ClearColor ?: (ClearColor = [[self alloc] initWithNSColor:[NSColor clearColor]]); }
+ (UIColor *)lightTextColor		{ return LightTextColor ?: (LightTextColor = [[self alloc] initWithWhite:1 alpha:0.6]); }
+ (UIColor *)darkTextColor      { return [self blackColor]; }

- (id)initWithWhite:(CGFloat)white alpha:(CGFloat)alpha
{
    return [self initWithNSColor:[NSColor colorWithDeviceWhite:white alpha:alpha]];
}

- (id)initWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha
{
    return [self initWithNSColor:[NSColor colorWithDeviceHue:hue saturation:saturation brightness:brightness alpha:alpha]];
}

- (id)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha
{
    return [self initWithNSColor:[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha]];
}

- (id)_initWithRepresentations:(NSArray *)reps
{
    if ([reps count] == 0) {
        self = nil;
    } else if ((self=[super init])) {
        _representations = [reps copy];
    }
    return self;
}

- (id)initWithCGColor:(CGColorRef)ref
{
    return [self _initWithRepresentations:[NSArray arrayWithObjects:[[UIColorRep alloc] initWithCGColor:ref], nil]];
}

- (id)initWithPatternImage:(UIImage *)patternImage
{
    NSArray *imageReps = [patternImage _representations];
    NSMutableArray *colorReps = [NSMutableArray arrayWithCapacity:[imageReps count]];
    
    for (UIImageRep *imageRep in imageReps) {
        [colorReps addObject:[[UIColorRep alloc] initWithPatternImageRepresentation:imageRep]];
    }
    
    return [self _initWithRepresentations:colorReps];
}

- (UIColorRep *)_bestRepresentationForProposedScale:(CGFloat)scale
{
    UIColorRep *bestRep = nil;
    
    for (UIColorRep *rep in _representations) {
        if (rep.scale > scale) {
            break;
        } else {
            bestRep = rep;
        }
    }
    
    return bestRep ?: [_representations lastObject];
}

- (BOOL)_isOpaque
{
    for (UIColorRep *rep in _representations) {
        if (!rep.opaque) {
            return NO;
        }
    }
    
    return YES;
}

- (void)set
{
    [self setFill];
    [self setStroke];
}

- (void)setFill
{
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(ctx, [self _bestRepresentationForProposedScale:_UIGraphicsGetContextScaleFactor(ctx)].CGColor);
}

- (void)setStroke
{
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetStrokeColorWithColor(ctx, [self _bestRepresentationForProposedScale:_UIGraphicsGetContextScaleFactor(ctx)].CGColor);
}

- (CGColorRef)CGColor
{
    return [self _bestRepresentationForProposedScale:1].CGColor;
}

- (UIColor *)colorWithAlphaComponent:(CGFloat)alpha
{
    CGColorRef newColor = CGColorCreateCopyWithAlpha(self.CGColor, alpha);
    UIColor *resultingUIColor = [UIColor colorWithCGColor:newColor];
    CGColorRelease(newColor);
    return resultingUIColor;
}

- (NSColor *)NSColor
{
    CGColorRef color = self.CGColor;
    NSColorSpace *colorSpace = [[NSColorSpace alloc] initWithCGColorSpace:CGColorGetColorSpace(color)];
    const NSInteger numberOfComponents = CGColorGetNumberOfComponents(color);
    const CGFloat *components = CGColorGetComponents(color);
    NSColor *theColor = [NSColor colorWithColorSpace:colorSpace components:components count:numberOfComponents];
    return theColor;
}

- (NSString *)description
{
    CGColorSpaceRef colorSpaceRef = CGColorGetColorSpace(self.CGColor);
    NSString *colorSpace = [NSString stringWithFormat:@"%@", (NSString *)CFBridgingRelease(CGColorSpaceCopyName(colorSpaceRef))];
    
    const size_t numberOfComponents = CGColorGetNumberOfComponents(self.CGColor);
    const CGFloat *components = CGColorGetComponents(self.CGColor);
    NSMutableString *componentsString = [NSMutableString stringWithString:@"{"];
    
    for (NSInteger index = 0; index < numberOfComponents; index++) {
        if (index) [componentsString appendString:@", "];
        [componentsString appendFormat:@"%.0f", components[index]];
    }
    [componentsString appendString:@"}"];
    
    return [NSString stringWithFormat:@"<%@: %p; colorSpace = %@; components = %@>", [self className], self, colorSpace, componentsString];
}

- (BOOL) isEqual:(id)object {
    if (![object isKindOfClass:[self class]]) {
        return NO;
    }
    UIColor* color = (UIColor*) object;
    return CGColorEqualToColor(self.CGColor, color.CGColor);
}

@end

