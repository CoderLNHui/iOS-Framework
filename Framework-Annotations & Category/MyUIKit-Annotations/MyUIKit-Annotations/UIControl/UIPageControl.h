//
//  UIPageControl.h
//  Annotations（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright (c) 2008-2015（https://custompbwaters.github.io）All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIPageControl : UIControl

/** 圆点的个数 */
@property(nonatomic) NSInteger numberOfPages;          // default is 0
/** 当前显示页码 */
@property(nonatomic) NSInteger currentPage;            // default is 0. value pinned to 0..numberOfPages-1
/** 单页时是否隐藏圆点 */
@property(nonatomic) BOOL hidesForSinglePage;          // hide the the indicator if there is only one page. default is NO

/**
 关闭系统事件page的切换显示效果(YES的时候), 
 并且直到调用updateCurrentPageDisplay这个方法, 才会显示
 */
@property(nonatomic) BOOL defersCurrentPageDisplay;    // if set, clicking to a new page won't update the currently displayed page until -updateCurrentPageDisplay is called. default is NO
/** 更新当前页码 */
- (void)updateCurrentPageDisplay;                      // update page display to match the currentPage. ignored if defersCurrentPageDisplay is NO. setting the page value directly will update immediately

/** 获取点的大小 */
- (CGSize)sizeForNumberOfPages:(NSInteger)pageCount;   // returns minimum size required to display dots for given page count. can be used to size control if page count could change

/** 圆点的颜色 */
@property(nullable, nonatomic,strong) UIColor *pageIndicatorTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;
/** 当前页圆点的颜色 */
@property(nullable, nonatomic,strong) UIColor *currentPageIndicatorTintColor NS_AVAILABLE_IOS(6_0) UI_APPEARANCE_SELECTOR;

@end

NS_ASSUME_NONNULL_END
