/*
 * UIButton+LNButton.h
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#import <UIKit/UIKit.h>

@interface UIButton (LNButton)

@end


@interface UIButton (LNBackgroundColor)

#pragma mark -设置state状态下的背景颜色
- (void)ln_setBackgroundColor:(UIColor *)backgroundColor forState:(UIControlState)state;

@end




@interface UIButton (LNBlock)

typedef void (^TouchedButtonBlock)(void);
#pragma mark -添加点击事件Block回调
- (void)addActionHandler:(TouchedButtonBlock)touchHandler;

@end



@interface UIButton (LNClickEdgeInsets)

#pragma mark -改变按钮的响应区域（上左下右分别增加或减小多少  正数为增加 负数为减小）
@property (nonatomic, assign) UIEdgeInsets clickEdgeInsets;

@end



@interface UIButton (LNCountDown)

#pragma mark -倒计时按钮
/**
 @param timeout     总时间
 @param waitBlock   倒计时过程中可以再里面做一些操作
 @param finishBlock 完成时执行的block
 */
- (void)startTime:(NSInteger)timeout waitBlock:(void(^)(NSInteger remainTime))waitBlock finishBlock:(void(^)())finishBlock;

@end


@interface UIButton (Indicator)

#pragma mark -提交按钮时在中间显示一个菊花
#pragma mark -显示菊花
- (void)showIndicator;

#pragma mark -隐藏菊花
- (void)hideIndicator;

@end






