//
//  UIImage.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UIImageOrientation) {
    UIImageOrientationUp,
    UIImageOrientationDown,   // 180 deg rotation
    UIImageOrientationLeft,   // 90 deg CCW
    UIImageOrientationRight,   // 90 deg CW
    UIImageOrientationUpMirrored,    // as above but image mirrored along
    // other axis. horizontal flip
    UIImageOrientationDownMirrored,  // horizontal flip
    UIImageOrientationLeftMirrored,  // vertical flip
    UIImageOrientationRightMirrored, // vertical flip
};

@interface UIImage : NSObject

+ (UIImage *)imageWithCGImage:(CGImageRef)imageRef scale:(CGFloat)scale orientation:(UIImageOrientation)orientation;

@end
