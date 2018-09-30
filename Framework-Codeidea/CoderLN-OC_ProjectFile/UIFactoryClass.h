/*
 * UIFactoryClass.h 效率开发常用工厂类
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

/**
 作用：效率开发常用工厂类 - 阶段总结
 所谓工厂方法，就是把对象的生成和对象的使用分开，减少代码重复
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface UIFactoryClass : NSObject


#pragma mark - UIView
#pragma mark -创建一个UIView，指定frame 背景色
+ (UIView*)ln_createViewFrame:(CGRect)frame backgroundColor:(UIColor*)color;



#pragma mark - UILabel
#pragma mark -创建一个UILabel，指定frame，text，textColor
+ (UILabel*)ln_createLabelFrame:(CGRect)frame text:(NSString*)text textColor:(UIColor*)color;



#pragma mark - UIImageView
#pragma mark -创建一个UIImageView 指定frame 和 显示的图片
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame image:(UIImage*)image;

#pragma mark -创建一个UIImageView 指定frame 和 图片的名称
+ (UIImageView*)ln_createImageViewFrame:(CGRect)frame imageName:(NSString*)imageName;


#pragma mark - UIButton
#pragma mark -创建一个UIButton 指定frame、title、背景色
+ (UIButton*)ln_createButtonFrame:(CGRect)frame title:(NSString*)title backgroundColor:(UIColor*)color;

#pragma mark -创建一个UIButton 指定frame、target、事件、图片、背景图片
+ (UIButton*)ln_createButtonWithFrame: (CGRect) frame Target:(id)target Selector:(SEL)selector Image:(NSString *)image ImagePressed:(NSString *)imagePressed;

#pragma mark -创建一个UIButton 指定frame、title、target、事件
+ (UIButton *)ln_createButtonWithFrame:(CGRect)frame Title:(NSString *)title Target:(id)target Selector:(SEL)selector;


#pragma mark - 添加绘制
#pragma mark -图片上添加文字水印
+(UIImage *)ln_addText:(UIImage *)image text:(NSString *)text;

#pragma mark -图片上添加图片水印
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage;

#pragma mark -图片上添加图片和文字水印
+ (UIImage *)ln_waterMark:(UIImage *)useImage andImage:(UIImage *)newImage text:(NSString *)text;

#pragma mark -截屏
+ (UIImage *)ln_screenShot:(UIView *)view;







@end






