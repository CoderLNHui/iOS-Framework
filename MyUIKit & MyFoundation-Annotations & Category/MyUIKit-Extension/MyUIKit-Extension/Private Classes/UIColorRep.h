//  完全实现ok
//  UIColorRep.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>
@class UIImageRep;

@interface UIColorRep : NSObject

- (id)initWithPatternImageRepresentation:(UIImageRep *)patternImageRep;
- (id)initWithCGColor:(CGColorRef)color;

@property (nonatomic, readonly) CGColorRef CGColor;
@property (nonatomic, readonly) CGFloat scale;
@property (nonatomic, readonly) UIImageRep *patternImageRep;
@property (nonatomic, readonly, getter=isOpaque) BOOL opaque;

@end
