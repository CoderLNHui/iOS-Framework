/*
 * File:  NSAttributedString.m
 * Framework:  UIKit
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2011-2015
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 👣
 */

//--------------------------- 【属性】 ------------------------------//
//
/*
NSFontAttributeName               字号 UIFont 默认12
NSParagraphStyleAttributeName     段落样式  NSParagraphStyle
NSForegroundColorAttributeName    前景色   UIColor
NSBackgroundColorAttributeName    背景色   UIColor
NSObliquenessAttributeName        字体倾斜     NSNumber
NSExpansionAttributeName          字体加粗     NSNumber  比例 0就是不变 1增加一倍
NSKernAttributeName               字间距   CGFloat
NSUnderlineStyleAttributeName     下划线     1或0
NSUnderlineColorAttributeName     下划线颜色
NSStrikethroughStyleAttributeName 删除线   1或0
NSStrikethroughColorAttributeName 某种颜色
NSStrokeColorAttributeName        空心字颜色
NSStrokeWidthAttributeName        空心字
NSLigatureAttributeName           连笔字  1或0  没看出效果
NSShadowAttributeName             阴影    NSShawdow
NSTextEffectAttributeName         设置文本特殊效果，取值为 NSString 对象，目前只有凸版印刷效果可用：
NSAttachmentAttributeName         NSTextAttachment  设置文本附件,常用插入图片
NSLinkAttributeName               链接  NSURL (preferred) or NSString
NSBaselineOffsetAttributeName     基准线偏移   NSNumber
NSWritingDirectionAttributeName   书写方向  @[@(NSWritingDirectionRightToLeft | NSWritingDirectionOverride)] 我的/的我
NSVerticalGlyphFormAttributeName  水平或者竖直文本  1竖直 0水平 在iOS没卵用，不支持竖版
*/


- (void)code3
{
    //--------------------------- 【富文本：段落】 ------------------------------//
    // 其他属性请自行查阅NSMutableParagraphStyle头文件WechatPublic-Codeidea
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    // 行间距
    paragraphStyle.lineSpacing = 10.f;
    // 段落间距
    paragraphStyle.paragraphSpacing = 20.f;
    // 首行缩进
    paragraphStyle.firstLineHeadIndent = 40.f;
    // 整体缩进
    paragraphStyle.headIndent = 15.f;
    // 对齐方式
    paragraphStyle.alignment = NSTextAlignmentLeft;
    
    NSMutableAttributedString *attrStr = [[NSMutableAttributedString alloc] initWithString:@"这是一个富文本字符串。这是一个富文本字符串。这是一个富文本字符串。这是一个富文本字符串。\n这是一个富文本字符串？这是一个富文本字符串？这是一个富文本字符串？\n这是一个富文本字符串！这是一个富文本字符串！这是一个富文本字符串！"];
    [attrStr addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, attrStr.length)];
    
    
    UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 400)];
    label.center = self.view.center;
    label.backgroundColor = [UIColor grayColor];
    label.numberOfLines = 0;
    // 设置label的富文本
    label.attributedText = attrStr;
    [self.view addSubview:label];
}






- (void)code4
{
    //--------------------------- 【富文本：图文混排】 ------------------------------//
    // WechatPublic-Codeidea
    NSMutableAttributedString * attrStr = [[NSMutableAttributedString alloc] initWithString:@"这是一个富文本字符串！"];
    
    // 创建一个文字附件对象
    NSTextAttachment *textAttachment = [[NSTextAttachment alloc] init];
    textAttachment.image = [UIImage imageNamed:@"1.png"];  //设置图片源
    textAttachment.bounds = CGRectMake(0, -6, 30, 30);  //设置图片位置和大小
    // 将文字附件转换成属性字符串
    NSAttributedString *attachmentAttrStr = [NSAttributedString attributedStringWithAttachment:textAttachment];
    // 将转换成属性字符串插入到目标字符串
    [attrStr insertAttributedString:attachmentAttrStr atIndex:8];
    
    
    UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 400)];
    label.center = self.view.center;
    label.backgroundColor = [UIColor grayColor];
    label.numberOfLines = 0;
    // 设置label的富文本
    label.attributedText = attrStr;
    [self.view addSubview:label];
}














