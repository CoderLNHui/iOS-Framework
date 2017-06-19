//
//  UIView+Frame.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Frame)

/*
 *【UIView扩展属性】
 */
@property (nonatomic, assign) CGFloat ln_x;
@property (nonatomic, assign) CGFloat ln_y;
@property (nonatomic, assign) CGFloat ln_width;
@property (nonatomic, assign) CGFloat ln_height;
@property (nonatomic, assign) CGFloat ln_centerX;
@property (nonatomic, assign) CGFloat ln_centerY;


/*
 *【快速加载View对应的Xib】
 */
+ (instancetype)ln_ViewFromNib;


/**
 * 【判断self和view是否重叠】
 */
- (BOOL)ln_intersectsWithView:(UIView *)view;

@end
