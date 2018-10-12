/*
 * UILabel+LNLabel.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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
