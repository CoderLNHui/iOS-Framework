/*
 * UILabel+LNLabel.h
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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
