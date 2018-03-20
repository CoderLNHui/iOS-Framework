/*
 * File:  LNTextField.m
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

#import "LNTextField.h"
#import "UITextField+TextField.h"
@implementation LNTextField

- (void)awakeFromNib
{
    [super awakeFromNib];
 
    [self addTarget:self action:@selector(textBegin) forControlEvents:UIControlEventEditingDidBegin];
    [self addTarget:self action:@selector(textEnd) forControlEvents:UIControlEventEditingDidEnd];

    // 默认设置文本框占位文字颜色
    self.placeholderColor = [UIColor redColor];
}


- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
 
        [self addTarget:self action:@selector(textBegin) forControlEvents:UIControlEventEditingDidBegin];
        [self addTarget:self action:@selector(textEnd) forControlEvents:UIControlEventEditingDidEnd];
        
        // 默认设置文本框占位文字颜色
        self.placeholderColor = [UIColor redColor];
    }
    return self;
}


#pragma mark ------------------
#pragma mark - 文本框开始编辑
- (void)textBegin
{
    //--------------------------- 方式一:【富文本设置文本框占位文字颜色】 ------------------------------//
    //
    //NSMutableDictionary *attrs = [NSMutableDictionary dictionary];
    //attrs[NSForegroundColorAttributeName] = [UIColor whiteColor];
    //[self setAttributedPlaceholder:[[NSAttributedString alloc] initWithString:self.placeholder attributes:attrs]];
    
    
    
    
    
    
    
    //--------------------- 方式二:【KVC设置文本框占位文字颜色】 -----------------------//
    //
    // 通过对UITextField打断点方式(获取内部label属性名"placeholderLabel")
    //UILabel *placeholderLabel = [self valueForKeyPath:@"placeholderLabel"];
    //placeholderLabel.textColor = [UIColor blueColor];
    
    
    
    
    
    
    
    
    
    
    
    //--------------------- 方式三:【工具类改进placeholderColor属性,设置文本框占位文字颜色】 -----------------------//
    //
    //runtime交换方法(修改UITextField的占位文字，且设置文字和文字颜色是无序的)
    self.placeholderColor = [UIColor whiteColor];
}









#pragma mark ------------------
#pragma mark - 文本框结束编辑
- (void)textEnd
{
    // 默认设置文本框占位文字颜色
    self.placeholderColor = [UIColor redColor];
}


@end









