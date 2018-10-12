/*
 * NSMutableAttributedString+LNAttributedString.m
 *
 * Foundation
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import "NSMutableAttributedString+LNAttributedString.h"

@implementation NSMutableAttributedString (LNAttributedString)

#pragma mark - 快速创建属性字符串
+(NSMutableAttributedString *)makeAttributeString:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block
{
    NSMutableDictionary * attributes = [NSMutableDictionary dictionary];
    block(attributes);
    NSMutableAttributedString * as = [[NSMutableAttributedString alloc] initWithString:string attributes:attributes];
    return as;
}


#pragma mark - 拼接属性字符串
-(NSMutableAttributedString *)makeAttributeStringAdd:(NSString *)string Attribute:(void(^)(NSMutableDictionary * attributes))block
{
    NSMutableDictionary * attributes = [NSMutableDictionary dictionary];
    block(attributes);
    NSMutableAttributedString * as = [[NSMutableAttributedString alloc] initWithString:string attributes:attributes];
    [self appendAttributedString:as];
    return self;
}


#pragma mark - +LNAttributedString 使用示例
- (void)attributedString
{
    //【常用方式】
    NSMutableAttributedString *AttributedStr = [[NSMutableAttributedString alloc]initWithString:@"我是CoderLN,你是核仁？"];
    [AttributedStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:16.0] range:NSMakeRange(2, 2)];
    [AttributedStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(2, 2)];
    //    testLabel.attributedText = AttributedStr;
    
    //【封装工具类】
    NSMutableAttributedString * testAS = [NSMutableAttributedString makeAttributeString:@"直接创建" Attribute:^(NSMutableDictionary *attributes) {
        attributes.Font(24).Color([UIColor yellowColor]);
    }];
    [testAS makeAttributeStringAdd:@"拼接新的文字" Attribute:^(NSMutableDictionary *attributes) {
        attributes.Font(12).Color([UIColor redColor]);
    }];
    testLabel.attributedText = testAS;
}



@end

















