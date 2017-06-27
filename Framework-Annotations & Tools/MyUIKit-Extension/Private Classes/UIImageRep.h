//  完全实现
//  UIImageRep.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIImageRep : NSObject
+ (NSArray *)imageRepsWithContentsOfFile:(NSString *)file;

- (id)initWithCGImageSource:(CGImageSourceRef)source imageIndex:(NSUInteger)index scale:(CGFloat)scale;
- (id)initWithCGImage:(CGImageRef)image scale:(CGFloat)scale;
- (id)initWithData:(NSData *)data;

- (void)drawInRect:(CGRect)rect fromRect:(CGRect)fromRect;

@property (nonatomic, readonly) CGSize imageSize;
@property (nonatomic, readonly) CGImageRef CGImage;
@property (nonatomic, readonly, getter=isLoaded) BOOL loaded;
@property (nonatomic, readonly) CGFloat scale;
@property (nonatomic, readonly, getter=isOpaque) BOOL opaque;
@end
