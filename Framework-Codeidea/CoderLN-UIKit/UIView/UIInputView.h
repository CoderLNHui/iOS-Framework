/*
 * UIInputView.h
 *
 * UIKit (c) 2012-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <UIKit/UIView.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIInputViewStyle) {
    UIInputViewStyleDefault,
    UIInputViewStyleKeyboard,       // mimics the keyboard background
} NS_ENUM_AVAILABLE_IOS(7_0);

NS_CLASS_AVAILABLE_IOS(7_0) @interface UIInputView : UIView

@property (nonatomic, readonly) UIInputViewStyle inputViewStyle;

@property (nonatomic, assign) BOOL allowsSelfSizing NS_AVAILABLE_IOS(9_0); // defaults to NO

- (instancetype)initWithFrame:(CGRect)frame inputViewStyle:(UIInputViewStyle)inputViewStyle NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
