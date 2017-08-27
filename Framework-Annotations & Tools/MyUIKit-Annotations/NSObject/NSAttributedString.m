/*
 * NSAttributedString.m
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2011-2015
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */

//--------------------------- 【Code】 ------------------------------//
//

Code1

NSString *str = @"人生若只如初见，何事悲风秋画扇。\n等闲变却故人心，却道故人心易变。\n骊山语罢清宵半，泪雨霖铃终不怨。\n何如薄幸锦衣郎，比翼连枝当日愿。";

// 创建 NSMutableAttributedString
NSMutableAttributedString *attrStr = [[NSMutableAttributedString alloc] initWithString:str];

// 设置字体和设置字体的范围
[attrStr addAttribute:NSFontAttributeName
                value:[UIFont systemFontOfSize:30.0f]
                range:NSMakeRange(0, 3)];
// 添加文字颜色
[attrStr addAttribute:NSForegroundColorAttributeName
                value:[UIColor redColor]
                range:NSMakeRange(17, 7)];
// 添加文字背景颜色
[attrStr addAttribute:NSBackgroundColorAttributeName
                value:[UIColor orangeColor]
                range:NSMakeRange(17, 7)];
// 添加下划线
[attrStr addAttribute:NSUnderlineStyleAttributeName
                value:[NSNumber numberWithInteger:NSUnderlineStyleSingle]
                range:NSMakeRange(8, 7)];

UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(60, 100, 200, 0)];
label.backgroundColor = [UIColor greenColor];
// 自动换行
label.numberOfLines = 0;
// 设置label的富文本
label.attributedText = attrStr;
// label高度自适应
[label sizeToFit];
[self.view addSubview:label];







Code2

//创建属性字典
NSDictionary *attrDict = @{ NSFontAttributeName: [UIFont fontWithName: @"Zapfino" size: 15],
                            NSForegroundColorAttributeName: [UIColor blueColor] };
//创建 NSAttributedString 并赋值
_label.attributedText = [[NSAttributedString alloc] initWithString: originStr attributes: attrDict]



//===============方式2=======================
UIFont *fond = [UIFont systemFontOfSize:20];
UIColor *color = [UIColor redColor];

NSMutableDictionary *attributes = [NSMutableDictionary new];
[attributes setObject:fond forKey:NSFontAttributeName];
[attributes setObject:color forKey:NSForegroundColorAttributeName];
return [[NSAttributedString alloc]initWithString:text attributes:attributes];











//--------------------------- 【NSMutableParagraphStyle类使用范例】 ------------------------------//
//

1.
NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
paragraphStyle.lineSpacing = 10;// 字体的行间距
paragraphStyle.firstLineHeadIndent = 20.0f;//首行缩进
paragraphStyle.alignment = NSTextAlignmentJustified;//（两端对齐的）文本对齐方式：（左，中，右，两端对齐，自然）
paragraphStyle.lineBreakMode = NSLineBreakByTruncatingTail;//结尾部分的内容以……方式省略 ( "...wxyz" ,"abcd..." ,"ab...yz")
paragraphStyle.headIndent = 20;//整体缩进(首行除外)
paragraphStyle.tailIndent = 20;//尾部缩进
paragraphStyle.minimumLineHeight = 10;//最低行高
paragraphStyle.maximumLineHeight = 20;//最大行高
paragraphStyle.paragraphSpacing = 15;//段与段之间的间距
paragraphStyle.paragraphSpacingBefore = 22.0f;//段首行空白空间/* Distance between the bottom of the previous paragraph (or the end of its paragraphSpacing, if any) and the top of this paragraph. */paragraphStyle.baseWritingDirection = NSWritingDirectionLeftToRight;//从左到右的书写方向（一共➡️⬇️⬅️三种）
paragraphStyle.lineHeightMultiple = 15;/* Natural line height is multiplied by this factor (if positive) before being constrained by minimum and maximum line height. */
paragraphStyle.hyphenationFactor = 1;//连字属性 在iOS，唯一支持的值分别为0和1



2.
NSShadowAttributeName对应的是NSShadow对象,单一使用不会有任何效果,需要配合着NSVerticalGlyphFormAttributeName(文字排版方向)、NSObliquenessAttributeName(文字倾斜)、NSExpansionAttributeName(文字扁平化)配合使用,NSShadow相关属性设置如下所示.

NSShadow *shadow = [[NSShadow alloc]init];
shadow.shadowBlurRadius = 5;//模糊度
shadow.shadowColor = [UIColor whiteColor];//阴影颜色
shadow.shadowOffset = CGSizeMake(1, 5);//阴影的大小














































