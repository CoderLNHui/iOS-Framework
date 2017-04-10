//
//  UIRotationGestureRecognizer.h
//  UIKit
//
//  Created by 白开水ln on 16/-/-.
//  Copyright (c) 2009-2015 Apple Inc. All rights reserved.
//  https://custompbwaters.github.io    http://www.jianshu.com/p/e5b995ecf44d
//

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

// Begins:  when two touches have moved enough to be considered a rotation
// Changes: when a finger moves while two fingers are down
// Ends:    when both fingers have lifted

NS_CLASS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED @interface UIRotationGestureRecognizer : UIGestureRecognizer

@property (nonatomic)          CGFloat rotation;            // rotation in radians
@property (nonatomic,readonly) CGFloat velocity;            // velocity of the pinch in radians/second

@end

NS_ASSUME_NONNULL_END
