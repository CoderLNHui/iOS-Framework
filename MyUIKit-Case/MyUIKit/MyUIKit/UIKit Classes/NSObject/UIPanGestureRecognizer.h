//
//  UIPanGestureRecognizer.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/10.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIGestureRecognizer.h"

@interface UIPanGestureRecognizer : UIGestureRecognizer

- (CGPoint)translationInView:(UIView *)view;
- (void)setTranslation:(CGPoint)translation inView:(UIView *)view;
- (CGPoint)velocityInView:(UIView *)view;

@property (nonatomic) NSUInteger maximumNumberOfTouches;
@property (nonatomic) NSUInteger minimumNumberOfTouches;

@end
