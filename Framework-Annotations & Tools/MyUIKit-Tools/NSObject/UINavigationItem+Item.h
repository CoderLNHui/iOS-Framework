/*
 * UINavigationItem+Item.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <UIKit/UIKit.h>

@interface UINavigationItem (Item)

@end


// https://github.com/Just-/UINavigationItem-Loading
@interface UINavigationItem (Loading)
/** 在navigationbar上显示UIActivityIndicatorView的位置*/
typedef NS_ENUM(NSUInteger, NavBarLoaderPosition)
{
    NavBarLoaderPositionCenter = 0,
    
    NavBarLoaderPositionLeft,
    
    NavBarLoaderPositionRight
};

/** 开始在position位置显示UIActivityIndicatorView */
- (void)startAnimatingAt:(NavBarLoaderPosition)position;

/** 结束显示UIActivityIndicatorView*/
- (void)stopAnimating;

@end



//https://github.com/devxoul/UINavigationItem-Margin
FOUNDATION_EXPORT double UINavigationItem_MarginVersionNumber;
FOUNDATION_EXPORT const unsigned char UINavigationItem_MarginVersionString[];

@interface UINavigationItem (Margin)

@property (nonatomic, assign) CGFloat leftMargin;
@property (nonatomic, assign) CGFloat rightMargin;

+ (CGFloat)systemMargin;

@end


