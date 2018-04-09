/*
 * UIFactory.m【效率开发常用工厂类-阶段续更】
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

#import "UIFactory.h"

@implementation UIFactory


#pragma mark - ↑
#pragma mark - UIView

//创建一个UIView，指定frame 背景色
+ (UIView*)ln_createViewFrame:(CGRect)frame backgroundColor:(UIColor*)color
{
    UIView *view = [[UIView alloc]initWithFrame:frame];
    view.backgroundColor = color;
    return view;
}





#pragma mark - ↑
#pragma mark - UILabel

//创建一个UILabel，指定frame，text，textColor
+ (UILabel*)ln_createLabelFrame:(CGRect)frame text:(NSString*)text textColor:(UIColor*)color
{
    UILabel *label = [[UILabel alloc]initWithFrame:frame];
    label.text = text;
    label.textColor = color;
    return label;
}





#pragma mark - ↑
#pragma mark - UIImageView

//创建一个UIImageView 指定frame 和 显示的图片
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame image:(UIImage*)image
{
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:frame];
    imageView.image = image;
    return imageView;
}

//创建一个UIImageView 指定frame 和 图片的名称
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame imageName:(NSString*)imageName
{
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:frame];
    imageView.image = [UIImage imageNamed:imageName];
    return imageView;
}




#pragma mark - ↑
#pragma mark - UIButton

//创建一个UIButton 指定frame title 和背景色
+ (UIButton*)ln_createButtonFrame:(CGRect)frame title:(NSString*)title backgroundColor:(UIColor*)color
{
    UIButton *button = [[UIButton alloc ]initWithFrame:frame];
    [button setTitle:title forState:UIControlStateNormal];
    button.backgroundColor = color;
    
    return button;
}


@end
