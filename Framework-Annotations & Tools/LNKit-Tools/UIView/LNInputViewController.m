/*
 * File:  ViewController.m
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 *
 *【占位文字、键盘上附图自适应高度】
 */

#import "ViewController.h"
#import "UIView+Frame.h"
#import "NSString+String.h"

#define MAS_SHORTHAND
#define MAS_SHORTHAND_GLOBALS
#import <Masonry/Masonry.h>

#import "LNInputView.h"

#define kScreenWidth [UIScreen mainScreen].bounds.size.width
#define kScreenHeight [UIScreen mainScreen].bounds.size.height
#define LNRGBA(r,g,b,a) [UIColor colorWithRed:(r) / 256.0 green:(g) / 256.0 blue:(b) / 256.0 alpha:a]


@interface ViewController ()<UITextViewDelegate>

@property (nonatomic, strong) UIView * inputBgView;
@property (nonatomic, strong) LNInputView * textView;
@property (nonatomic, assign) CGFloat textHeight;/** 记录文字高度变化 */
@property (nonatomic, assign) BOOL isTwoLine;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = LNRGBA(235, 235, 235, 1.0);
//    self.view.backgroundColor = [UIColor grayColor];

    [self setupInputView];
    
    NSLog(@"111   %@",NSStringFromUIEdgeInsets(self.textView.textContainerInset));
}


- (void)setupInputView
{
    // 创建控件
    self.inputBgView = [[UIView alloc] init];
    self.inputBgView.backgroundColor = LNRGBA(242, 242, 245, 1.0);
    [self.view addSubview:self.inputBgView];
    [self.inputBgView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.right.mas_equalTo(self.view).mas_offset(0);
        make.bottom.mas_equalTo(self.view).mas_offset(0);
        make.height.mas_equalTo(@(50));
    }];
    
    
    UIButton *leftInputBtn = [UIButton buttonWithType:UIButtonTypeSystem];
    [self createWithButton:leftInputBtn setNormalImage:@"1" setSelectedImage:@"1.1"];
    [leftInputBtn addTarget:self action:@selector(leftBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    [leftInputBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(self.inputBgView).mas_offset(10);
        make.centerY.mas_equalTo(self.inputBgView).mas_offset(0.5);
        make.size.mas_equalTo(CGSizeMake(30, 30));
    }];
    
    
    UIButton *rightInputBtn = [UIButton buttonWithType:UIButtonTypeSystem];
    [self createWithButton:rightInputBtn setNormalImage:@"3" setSelectedImage:@"3.3"];
    [rightInputBtn addTarget:self action:@selector(rightBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    [rightInputBtn mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.mas_equalTo(self.inputBgView).mas_offset(-10);
        make.centerY.mas_equalTo(self.inputBgView).mas_offset(0.5);
        make.size.mas_equalTo(CGSizeMake(30, 30));
    }];
    
    
    // 设置文本框属性
    self.textView = [[LNInputView alloc] init];
    self.textView.backgroundColor = LNRGBA(251, 251, 251, 1.0);
    self.textView.font = [UIFont systemFontOfSize:16.f];
    self.textView.delegate = self;
    //self.textView.textContainerInset = UIEdgeInsetsMake(5, 0, 5, 0);// text内边距,默认8

    [self.inputBgView addSubview:self.textView];
    [self.textView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(leftInputBtn.right).mas_offset(10);
        make.right.mas_equalTo(rightInputBtn.left).mas_offset(-10);
        make.top.mas_equalTo(self.inputBgView).mas_offset(5);
        make.bottom.mas_equalTo(self.inputBgView).mas_offset(-5);
    }];
    
 
    
    // 设置文本框占位文字
    self.textView.placeholder = @"wechat - Codeidea";
    self.textView.placeholderColor = [UIColor redColor];
    
    /**
      监听文本框文字高度改变
      文本框文字高度改变会自动执行这个Block,可在这里修改底部View的高度
     */
    __weak __typeof(self) weakSelf = self;
    self.textView.ln_textHeightChangeBlock = ^(NSString *text, CGFloat textHeight) {

        NSLog(@"监听文本框文字高度改变 %@ %f" ,text ,textHeight);
        weakSelf.textHeight = textHeight;// 记录文字高度的改变
        
        
        // 告诉self.view约束需要更新
        [weakSelf.view setNeedsUpdateConstraints];
        // 调用此方法告诉self.view检测是否需要更新约束，若需要则更新
        [weakSelf.view updateConstraintsIfNeeded];
        [weakSelf.view layoutIfNeeded];
    };
    
    // 设置最大显示行数
    self.textView.maxNumberOfLines = 4;
    
 
    // 将要改变键盘的frame 的监听通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillChangeFrame:) name:UIKeyboardWillChangeFrameNotification object:nil];
    
   
    
}

#pragma mark - updateViewConstraints
// 重写该方法来更新约束
- (void)updateViewConstraints
{
    [self.inputBgView mas_updateConstraints:^(MASConstraintMaker *make) {
        // 这里写需要更新的约束，不用更新的约束将继续存在
        // 底部ViewHeight = 文字高度 + textView距离上下间距的约束
        make.height.mas_equalTo(self.textHeight + 5 + 5);
    }];
   
    [super updateViewConstraints];
}




#pragma mark ------------------
#pragma mark -【键盘弹出下落会调用】
- (void)keyboardWillChangeFrame:(NSNotification *)noti
{
    NSLog(@"keyboardWillChangeFrame: 将要改变键盘的frame");
    // 获取键盘的frame
    CGRect keyBoardFrame = [noti.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    float duration = [noti.userInfo[UIKeyboardAnimationDurationUserInfoKey] floatValue];
    
    [UIView animateWithDuration:duration animations:^{
        //self.inputBgView.transform = CGAffineTransformMakeTranslation(0, keyBoardFrame.origin.y - [UIScreen mainScreen].bounds.size.height);
        
        //【条件运算符】
        CGFloat ty = keyBoardFrame.origin.y != [UIScreen mainScreen].bounds.size.height ? keyBoardFrame.size.height : 0;
        self.inputBgView.transform = CGAffineTransformMakeTranslation(0, -ty);
    }];
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}





- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    [self.textView endEditing:YES];
}
 


#pragma mark ------------------

- (void)leftBtnClick:(UIButton *)btn
{
    NSLog(@"left BtnClick");
}

- (void)rightBtnClick:(UIButton *)btn
{
    NSLog(@"right BtnClick");
}

- (void)createWithButton:(UIButton *)btn setNormalImage:(NSString *)normalStr setSelectedImage:(NSString *)selectedStr
{
    [btn setImage:[[UIImage imageNamed:normalStr] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal] forState:UIControlStateNormal];
    [btn setImage:[[UIImage imageNamed:selectedStr] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal] forState:UIControlStateSelected];
    [self.inputBgView addSubview:btn];
}


/*
#pragma mark ------------------
#pragma mark -【UITextViewDelegate】
// textView文本框输入字符时调用
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
    // 根据一定的宽度和字体大小计算文本高度
    CGSize newSize = [self.textView.text stringHeightWithMaxWidth:kScreenWidth - 100 andFont:[UIFont systemFontOfSize:16.f]];
    // numberLines 输入的行数
    NSInteger numberLines = floor(newSize.height / textView.font.lineHeight);
    NSLog(@"内容高度 %f, 行高 %f, 文本高度 %@",textView.contentSize.height,textView.font.lineHeight,NSStringFromCGSize(newSize));
    
    if (numberLines > 4) {
        return NO;
    }

    return YES;
}

*/






@end























