//
//  UIBarButtonItem+Item.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (Item)

/*
 *【创建UIBarButtonItem,高亮】
 *
 * @param image      普通状态下的图片
 * @param hightImage 高亮状态下的图片
 * @param target     一般为self
 * @param action     BarButton点击方法
 */
+ (UIBarButtonItem *)itemWithImage:(UIImage *)image hightImage:(UIImage *)hightImage target:(id)target action:(SEL)action;


/*
 *【创建UIBarButtonItem,选中】
 *
 * @param image      普通状态下的图片
 * @param seleImage  选中状态下的图片
 * @param target     一般为self
 * @param action     BarButton点击方法
 */
+ (UIBarButtonItem *)itemWithImage:(UIImage *)image seleImage:(UIImage *)seleImage target:(id)target action:(SEL)action;


/*
 *【创建UIBarButtonItem,高亮,标题文字】
 *
 * @param image      普通状态下的图片
 * @param hightImage 高亮状态下的图片
 * @param target     一般为self
 * @param action     BarButton点击方法
 * @param title      标题文字
 */
+ (UIBarButtonItem *)backWithImage:(UIImage *)image hightImage:(UIImage *)hightImage target:(id)target action:(SEL)action title:(NSString *)title;


@end
