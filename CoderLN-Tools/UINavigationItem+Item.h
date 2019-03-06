/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>

@interface UINavigationItem (LNItem)

@end


#pragma mark - 在navigationbar上显示UIActivityIndicatorView的位置
// https://github.com/Just-/UINavigationItem-Loading
@interface UINavigationItem (LNLoading)
typedef NS_ENUM(NSUInteger, NavBarLoaderPosition) {
    NavBarLoaderPositionCenter = 0,
    NavBarLoaderPositionLeft,
    NavBarLoaderPositionRight
};

/** 开始在position位置显示UIActivityIndicatorView */
- (void)startAnimatingAt:(NavBarLoaderPosition)position;

/** 结束显示UIActivityIndicatorView*/
- (void)stopAnimating;

@end



#pragma mark - 导航栏左右间隔
//https://github.com/devxoul/UINavigationItem-Margin
FOUNDATION_EXPORT double UINavigationItem_MarginVersionNumber;
FOUNDATION_EXPORT const unsigned char UINavigationItem_MarginVersionString[];

@interface UINavigationItem (Margin)

@property (nonatomic, assign) CGFloat leftMargin;
@property (nonatomic, assign) CGFloat rightMargin;

+ (CGFloat)systemMargin;

@end
 

