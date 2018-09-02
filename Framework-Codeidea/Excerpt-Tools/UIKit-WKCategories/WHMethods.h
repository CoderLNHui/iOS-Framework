//
//  WHMethods.h
//  WHKit
//  https://github.com/remember17/WHKit
//  Created by 吴浩 on 2017/6/7.
//  Copyright © 2017年 remember17. All rights reserved.
//  http://www.jianshu.com/p/c935314b078e

#import <UIKit/UIKit.h>

@interface WHMethods : UIViewController

//更改iOS状态栏的颜色
+ (void)wh_setStatusBarBackgroundColor:(UIColor *)color;

//为控制器添加背景图片
+ (void)wh_addBackgroundImageWithImageName:(NSString *)imageName forViewController:(UIViewController *)viewController;

//最大,最小,和,平均
+ (CGFloat) wh_maxNumberFromArray:(NSArray *)array;
+ (CGFloat) wh_minNumberFromArray:(NSArray *)array;
+ (CGFloat) wh_sumNumberFromArray:(NSArray *)array;
+ (CGFloat) wh_averageNumberFromArray:(NSArray *)array;

//可用硬件容量
+ (CGFloat) wh_usableHardDriveCapacity;
//硬件总容量
+ (CGFloat) wh_allHardDriveCapacity;

@end
