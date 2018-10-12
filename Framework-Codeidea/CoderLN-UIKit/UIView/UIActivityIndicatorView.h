/*
 * UIActivityIndicatorView.h
 *
 * UIKit (c) 2005-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

 
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIActivityIndicatorViewStyle) {
    UIActivityIndicatorViewStyleWhiteLarge,
    UIActivityIndicatorViewStyleWhite,
    UIActivityIndicatorViewStyleGray __TVOS_PROHIBITED,
};

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIActivityIndicatorView : UIView <NSCoding>

- (instancetype)initWithActivityIndicatorStyle:(UIActivityIndicatorViewStyle)style NS_DESIGNATED_INITIALIZER; // sizes the view according to the style
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (instancetype) initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@property(nonatomic) UIActivityIndicatorViewStyle activityIndicatorViewStyle; // default is UIActivityIndicatorViewStyleWhite
@property(nonatomic) BOOL                         hidesWhenStopped;           // default is YES. calls -setHidden when animating gets set to NO

@property (nullable, readwrite, nonatomic, strong) UIColor *color NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;

- (void)startAnimating;
- (void)stopAnimating;
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic, readonly, getter=isAnimating) BOOL animating;
#else
- (BOOL)isAnimating;
#endif

@end
NS_ASSUME_NONNULL_END

