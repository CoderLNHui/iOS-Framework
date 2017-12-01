/*
 * UINavigationItem+Item.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
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
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END


