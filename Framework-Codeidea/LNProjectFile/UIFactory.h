/*
 * UIFactory.h【效率开发常用工厂类-阶段续更】
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

/**
 所谓工厂方法，就是把对象的生成和对象的使用分开，减少代码重复
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface UIFactory : NSObject

#pragma mark - ↑
#pragma mark - UIView

//创建一个UIView，指定frame 背景色
+ (UIView*)ln_createViewFrame:(CGRect)frame backgroundColor:(UIColor*)color;







#pragma mark - ↑
#pragma mark - UILabel

//创建一个UILabel，指定frame，text，textColor
+ (UILabel*)ln_createLabelFrame:(CGRect)frame text:(NSString*)text textColor:(UIColor*)color;








#pragma mark - ↑
#pragma mark - UIImageView

//创建一个UIImageView 指定frame 和 显示的图片
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame image:(UIImage*)image;

//创建一个UIImageView 指定frame 和 图片的名称
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame imageName:(NSString*)imageName;




 
#pragma mark - ↑
#pragma mark - UIButton

//创建一个UIButton 指定frame title 和背景色
+ (UIButton*)ln_createButtonFrame:(CGRect)frame title:(NSString*)title backgroundColor:(UIColor*)color;









# * Author: 白开水ln  -  WechatPublic：Codeidea  -  Repository：github.com/CoderLN/Framework-Codeidea
@end






