/*
 * UIView+Frame.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */

#import <UIKit/UIKit.h>

@interface UIView (Frame)

/*
 *【UIView扩展属性】
 */
@property (nonatomic, assign) CGFloat ln_x;
@property (nonatomic, assign) CGFloat ln_y;
@property (nonatomic, assign) CGFloat ln_width;
@property (nonatomic, assign) CGFloat ln_height;
@property (nonatomic, assign) CGFloat ln_centerX;
@property (nonatomic, assign) CGFloat ln_centerY;


/*
 *【快速加载View对应的Xib】
 */
+ (instancetype)ln_ViewFromNib;


/**
 * 【判断self和view是否重叠】
 */
- (BOOL)ln_intersectsWithView:(UIView *)view;


@end




//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//

@interface UIView (Frame)

@property (assign, nonatomic) CGFloat x;/**< 起始x值 */
@property (assign, nonatomic) CGFloat y;/**< 起始y值 */
@property (assign, nonatomic) CGPoint origin;/**< 起始点坐标 */

@property (assign, nonatomic) CGFloat middleX;/**< 中点x值 */
@property (assign, nonatomic) CGFloat middleY;/**< 中点y值 */

@property (assign, nonatomic) CGFloat tail;  /**< 最大x值 */
@property (assign, nonatomic) CGFloat bottom;/**< 最大y值 */

@property (assign, nonatomic) CGFloat width; /**< 宽度 */
@property (assign, nonatomic) CGFloat height;/**< 高度 */
@property (assign, nonatomic) CGSize  size;  /**< 尺寸 */


@property (nonatomic,assign) CGFloat top; /**< 最小y值 */
@property (nonatomic,assign) CGFloat left; /**< 最小x值 */
@property (nonatomic,assign) CGFloat right; /**< 最大x值 */

@end



@interface UIView (BlockGesture)

typedef void (^TapActionBlock)(UITapGestureRecognizer *gestureRecoginzer);
typedef void (^LongPressActionBlock)(UILongPressGestureRecognizer *gestureRecoginzer);

/**
 *  @brief  添加tap手势
 *
 *  @param block 代码块
 */
- (void)addTapActionWithBlock:(TapActionBlock)block;
/**
 *  @brief  添加长按手势
 *
 *  @param block 代码块
 */
- (void)addLongPressActionWithBlock:(LongPressActionBlock)block;

@end


@interface UIView (Find)

/** 找到指定类名的subView : 从SubViews中返回第一个符合条件的 */
- (UIView *)findSubViewWithClass:(Class)clazz;

- (NSArray *)findAllSubViewsWithClass:(Class)clazz;

/** 找到指定类名的superView对象 */
- (UIView *)findSuperViewWithClass:(Class)clazz;

/** 找到view上的第一响应者 */
- (UIView *)findFirstResponder;

/** 找到当前view所在的viewControler */
- (UIViewController *)findViewController;

- (NSArray *)allSubviews;

- (void)removeAllSubviews;

@end



#pragma mark - View的XIB可视化扩展类
IB_DESIGNABLE
/** View的XIB可视化扩展类> */
@interface UIView (IBnspectable)
/*!
 * 给UIView 设置圆角
 */
@property (assign,nonatomic) IBInspectable NSInteger cornerRadius;
@property (assign,nonatomic) IBInspectable BOOL  masksToBounds;

/*!
 * 设置 view的 边框颜色(选择器和Hex颜色)
 * 以及 边框的宽度
 */
@property (assign,nonatomic) IBInspectable NSInteger borderWidth;
@property (strong,nonatomic) IBInspectable NSString  *borderHexRgb;
@property (strong,nonatomic) IBInspectable UIColor   *borderColor;

@end


@interface UIView (Nib)

+ (instancetype)loadViewFromNib;
+ (instancetype)loadViewFromNibWithName:(NSString *)nibName;
+ (instancetype)loadViewFromNibWithName:(NSString *)nibName owner:(id)owner;
+ (instancetype)loadViewFromNibWithName:(NSString *)nibName owner:(id)owner bundle:(NSBundle *)bundle;

@end



@interface UIView (ViewController)

/**
 *  获取view对象的所在ViewController
 *
 *  @param viewObj 视图对象
 *
 *  @return 视图所在的控制器
 */
+ (UIViewController*)viewControllerOfView:(UIView *)viewObj;

@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
