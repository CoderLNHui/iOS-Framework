//
//  UITextField+Placeholder.m
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import "UITextField+Placeholder.h"
#import <objc/message.h>

@implementation UITextField (Placeholder)

/*
 *【设置占位文字的颜色】
 */
- (void)setPlaceholderColor:(UIColor *)placeholderColor
{
    
    // 给成员属性赋值 runtime给系统的类添加成员属性
    // 添加成员属性
    objc_setAssociatedObject(self, @"placeholderColor", placeholderColor, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    // 获取占位文字label控件
    UILabel *placeholderLabel = [self valueForKey:@"placeholderLabel"];
    
    // 设置占位文字颜色
    placeholderLabel.textColor = placeholderColor;
}

- (UIColor *)placeholderColor
{
    return objc_getAssociatedObject(self, @"placeholderColor");
}


// 设置占位文字 和 文字颜色
- (void)setLN_Placeholder:(NSString *)placeholder {
    [self setLN_Placeholder:placeholder];
    
    self.placeholderColor = self.placeholderColor;
}


// runtime 交换方法
+ (void)load
{
    // setPlaceholder
    Method setPlaceholderMethod = class_getInstanceMethod(self, @selector(setPlaceholder:));
    Method setLN_PlaceholderMethod = class_getInstanceMethod(self, @selector(setLN_Placeholder:));
    
    method_exchangeImplementations(setPlaceholderMethod, setLN_PlaceholderMethod);
}


@end
