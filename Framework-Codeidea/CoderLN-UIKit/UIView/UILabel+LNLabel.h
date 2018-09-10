/*
 * UILabel+LNLabel.h
 *
 * UIKit
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <UIKit/UIKit.h>

@interface UILabel (LNLabel)
 
#pragma mark - 设置指定label某些文字之间的间距
- (void)ln_labelTextSpacingValue:(NSInteger)spacing Range:(NSRange)range

#pragma mark - 设置行距
- (void)ln_setRowSpace:(CGFloat)rowSpace;

@end
 

@interface LNLrcLabel : UILabel
#pragma mark - 每句歌词渐变播放进度
@property (nonatomic, assign) CGFloat progress;
@end
