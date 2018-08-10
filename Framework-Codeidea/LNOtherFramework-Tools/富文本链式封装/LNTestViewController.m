/*
 * LNTestViewController.m
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import "LNTestViewController.h"
#import "NSMutableDictionary+Dictionary.h"
#import "NSMutableAttributedString+AttributedString.h"

@interface LNTestViewController ()

@end

@implementation LNTestViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor grayColor];
    UILabel *testLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, kScreenH - 50, kScreenW, 30)];
    [self.view addSubview:testLabel];
    
    //【常用方式】
    NSMutableAttributedString *AttributedStr = [[NSMutableAttributedString alloc]initWithString:@"你的我的小苹果"];
    [AttributedStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:16.0] range:NSMakeRange(2, 2)];
    [AttributedStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(2, 2)];
    //    testLabel.attributedText = AttributedStr;
    
    
    [testLabel addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(testClick)]];
    
    
    //【封装工具类】【利用链式编程去实现富文本属性的赋值】
    NSMutableAttributedString * testAS = [NSMutableAttributedString makeAttributeString:@"直接创建" Attribute:^(NSMutableDictionary *attributes) {
        attributes.Font(24).Color([UIColor yellowColor]);
       
        
        
    }];
    
    
    
    [testAS makeAttributeStringAdd:@"拼接新的文字" Attribute:^(NSMutableDictionary *attributes) {
        attributes.Font(12).Color([UIColor redColor]);
    }];
    testLabel.attributedText = testAS;
}

- (void)testClick
{
    LNFunc;
}


@end

















