/*
 * File:  LNInputView.h
 * Framework: UIScrollView - UIView
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook:  http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 *
 *【占位文字、键盘上附图自适应高度】
 */

#import <UIKit/UIKit.h>

@interface LNInputView : UITextView

/**
  圆角
 */
@property (nonatomic, assign) NSUInteger cornerRadius;
/**
  占位文字
 */
@property (nonatomic, strong) NSString * placeholder;
/**
  占位文字颜色
 */
@property (nonatomic, strong) UIColor * placeholderColor;


/**
  textView最大显示行数
 */
@property (nonatomic, assign) NSUInteger maxNumberOfLines;


/**
  文字高度改变会自动调用Block text:文字内容, textHeight:文字高度
 */
@property (nonatomic, strong) void(^ln_textHeightChangeBlock)(NSString *text, CGFloat textHeight);







//--------------------------- <#我是分割线#> ------------------------------//
//

/*
1.
// 自适应
[self sizeThatFits:CGSizeMake(self.bounds.size.width, MAXFLOAT)].height



2.
// 根据一定宽度和字体计算高度
[self boundingRectWithSize:CGSizeMake(maxWidth, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading attributes:@{NSFontAttributeName:font} context:nil].size;


3.
// numberlines用来控制输入的行数
NSInteger numberLines = textView.contentSize.height / textView.font.lineHeight;

4.
 [self sizeToFit];

*/





@end
