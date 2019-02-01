/*
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#import "UILabel+LNLabel.h"
#import <CoreText/CoreText.h>

@implementation UILabel (LNLabel)

#pragma mark - 设置指定label某些文字之间的间距
- (void)ln_labelTextSpacingValue:(NSInteger)spacing Range:(NSRange)range
{
    // 方法一：#import <CoreText/CoreText.h>
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:self.label.text];
    // 调整间距
    [attributedString addAttribute:(__bridge NSString *)kCTKernAttributeName value:@(spacing) range:range];
    self.attributedText = attributedString;
    
    // 方法二：
    /**
     NSMutableAttributedString *attributeString =  [[NSMutableAttributedString alloc] initWithString:self.text];
     CGSize attributeSize = [attributeString.string sizeWithAttributes:@{NSFontAttributeName:self.font}];
     CGSize adjustedSize = CGSizeMake(ceilf(attributeSize.width), ceilf(attributeSize.height));
     CGSize frame = self.frame.size;
     NSNumber *wordSpace = [NSNumber numberWithInt:((frame.width-adjustedSize.width)/(attributeString.length-1))];
     // 调整指定位置文字间距
     [attributeString addAttribute:NSKernAttributeName value:wordSpace range:range];
     */
}
/**
 使用：
 [label ln_labelTextSpacingValue:2 Range:NSMakeRange(0, label.text.length)];
 */

#pragma mark - 设置行距
- (void)ln_setRowSpace:(CGFloat)rowSpace
{
    self.numberOfLines = 0;
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithAttributedString:self.attributedText];
    // 调整行距
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    paragraphStyle.lineSpacing = rowSpace;
    paragraphStyle.baseWritingDirection = NSWritingDirectionLeftToRight;
    paragraphStyle.lineBreakMode = NSLineBreakByTruncatingTail;
    [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, [self.text length])];
    self.attributedText = attributedString;
}

@end



#pragma mark - 每句歌词渐变播放进度
@implementation LNLrcLabel
- (void)drawRect:(CGRect)rect
{
    [super drawRect:rect];
    
    [[UIColor whiteColor] set];
    CGRect fileRect = CGRectMake(0, 0, self.frame.size.width * self.progress, self.frame.size.height);
    
    //UIRectFill(CGRect rect); // 一句全部绘制
    UIRectFillUsingBlendMode(fileRect, kCGBlendModeSourceIn); // 渐变绘制
}

- (void)setProgress:(CGFloat)progress
{
    _progress = progress;
    [self setNeedsDisplay];// 重新绘制
}
@end


















 
