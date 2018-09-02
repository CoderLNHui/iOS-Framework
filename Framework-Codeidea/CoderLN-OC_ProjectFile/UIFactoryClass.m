/*
 * UIFactoryClass.m
 *
 * About ME Public：Codeidea / https://githubidea.github.io
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 作用：效率开发常用工厂类 - 阶段总结
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import "UIFactoryClass.h"

@implementation UIFactoryClass

#pragma mark - UIView
#pragma mark -创建一个UIView，指定frame 背景色
+ (UIView*)ln_createViewFrame:(CGRect)frame backgroundColor:(UIColor*)color
{
    UIView *view = [[UIView alloc]initWithFrame:frame];
    view.backgroundColor = color;
    return view;
}


#pragma mark - UILabel
#pragma mark -创建一个UILabel，指定frame，text，textColor
+ (UILabel*)ln_createLabelFrame:(CGRect)frame text:(NSString*)text textColor:(UIColor*)color
{
    UILabel *label = [[UILabel alloc]initWithFrame:frame];
    label.text = text;
    label.textColor = color;
    return label;
}


#pragma mark - UIImageView
#pragma mark -创建一个UIImageView 指定frame 和 显示的图片
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame image:(UIImage*)image
{
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:frame];
    imageView.image = image;
    return imageView;
}

#pragma mark -创建一个UIImageView 指定frame 和 图片的名称
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame imageName:(NSString*)imageName
{
    UIImageView *imageView = [[UIImageView alloc]initWithFrame:frame];
    imageView.image = [UIImage imageNamed:imageName];
    return imageView;
}


#pragma mark - UIButton
#pragma mark -创建一个UIButton 指定frame、title、背景色
+ (UIButton*)ln_createButtonFrame:(CGRect)frame title:(NSString*)title backgroundColor:(UIColor*)color
{
    UIButton *button = [[UIButton alloc ]initWithFrame:frame];
    [button setTitle:title forState:UIControlStateNormal];
    button.backgroundColor = color;
    
    return button;
}

#pragma mark -创建一个UIButton 指定frame、target、事件、图片、背景图片
+ (UIButton*)ln_createButtonWithFrame: (CGRect) frame Target:(id)target Selector:(SEL)selector Image:(NSString *)image ImagePressed:(NSString *)imagePressed
{
    UIButton * button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setFrame:frame];
    UIImage *newImage = [UIImage imageNamed: image];
    [button setBackgroundImage:newImage forState:UIControlStateNormal];
    UIImage *newPressedImage = [UIImage imageNamed: imagePressed];
    [button setBackgroundImage:newPressedImage forState:UIControlStateHighlighted];
    [button addTarget:target action:selector forControlEvents:UIControlEventTouchUpInside];
    return button;
}

#pragma mark -创建一个UIButton 指定frame、title、target、事件
+ (UIButton *)ln_createButtonWithFrame:(CGRect)frame Title:(NSString *)title Target:(id)target Selector:(SEL)selector
{
    UIButton * button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [button setFrame:frame];
    [button setTitle:title forState:UIControlStateNormal];
    [button addTarget:target action:selector forControlEvents:UIControlEventTouchUpInside];
    return button;
}




#pragma mark - 添加绘制
#pragma mark -图片上添加文字水印
+ (UIImage *)ln_addText:(UIImage *)useImage text:(NSString *)text
{
    float width = useImage.size.width;
    float height = useImage.size.height;
    UIGraphicsBeginImageContext(useImage.size);
    [useImage drawInRect:CGRectMake(0, 0, useImage.size.width, useImage.size.height)];
    
    [text drawAtPoint:CGPointMake(width/2, height-20) withAttributes:@{NSFontAttributeName:[UIFont fontWithName:@"Georgia" size:15],NSForegroundColorAttributeName:[UIColor whiteColor]}];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return resultingImage;
}

#pragma mark -图片上添加图片水印
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage
{
    float width = useImage.size.width;
    float height = useImage.size.height;
    UIGraphicsBeginImageContext(useImage.size);
    [useImage drawInRect:CGRectMake(0, 0, useImage.size.width, useImage.size.height)];
    
    [newImage drawInRect:CGRectMake(width/2, height-20, 18, 18)];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return resultingImage;
}

#pragma mark -图片上添加图片和文字水印
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage text:(NSString *)text
{
    float width = useImage.size.width;
    float height = useImage.size.height;
    UIGraphicsBeginImageContext(useImage.size);
    [useImage drawInRect:CGRectMake(0, 0, useImage.size.width, useImage.size.height)];
    
    [newImage drawInRect:CGRectMake(width/2, height-20, 18, 18)];
    [text drawAtPoint:CGPointMake(width/2 + 25, height-20) withAttributes:@{NSFontAttributeName:[UIFont fontWithName:@"Georgia" size:15],NSForegroundColorAttributeName:[UIColor whiteColor]}];
    
    UIImage *resultingImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return resultingImage;
}

#pragma mark - 截屏
+ (UIImage *)ln_screenShot:(UIView *)view
{
    CGRect mainRect = [[UIScreen mainScreen] bounds];
    
    UIGraphicsBeginImageContext(mainRect.size);
    
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextFillRect(context, mainRect);
    [view.layer renderInContext:context];
    
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return newImage;
}






@end






