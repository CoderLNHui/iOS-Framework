/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <UIKit/UIKit.h>

@interface UIView (Frame)


#pragma mark - UIView常用扩展属性

@property (nonatomic, assign) CGFloat ln_x;
@property (nonatomic, assign) CGFloat ln_y;
@property (nonatomic, assign) CGFloat ln_width;
@property (nonatomic, assign) CGFloat ln_height;
@property (nonatomic, assign) CGFloat ln_centerX;
@property (nonatomic, assign) CGFloat ln_centerY;
@property (nonatomic, assign) CGSize  ln_size;
@property (nonatomic, assign) CGPoint ln_origin;
@property (nonatomic, assign) CGFloat ln_maxX;
@property (nonatomic, assign) CGFloat ln_maxY;
@property (nonatomic, assign) CGFloat ln_minX;
@property (nonatomic, assign) CGFloat ln_minY;


#pragma mark -快速加载view类名对应的Xib
+ (instancetype)ln_ViewFromXib;

#pragma mark -给UIView设置圆角
@property (assign,nonatomic) IBInspectable NSInteger cornerRadius;
@property (assign,nonatomic) IBInspectable BOOL  masksToBounds;

#pragma mark -设置view的边框宽度、边框的颜色、Hex颜色
@property (assign,nonatomic) IBInspectable NSInteger  borderWidth;
@property (strong,nonatomic) IBInspectable NSString  *borderHexRgb;
@property (strong,nonatomic) IBInspectable UIColor   *borderColor;
@end



@interface UIView (BlockGesture)

typedef void (^TapActionBlock)(UITapGestureRecognizer *gestureRecoginzer);
typedef void (^LongPressActionBlock)(UILongPressGestureRecognizer *gestureRecoginzer);

#pragma mark -给UIView添加tap手势
- (void)ln_addTapActionWithBlock:(TapActionBlock)block;

#pragma mark -给UIView添加Long手势
- (void)ln_addLongPressActionWithBlock:(LongPressActionBlock)block;

@end



@interface UIView (FindView)

#pragma mark -判断self和view是否重叠
- (BOOL)ln_intersectsWithView:(UIView *)view;

#pragma mark -找到view上的第一响应者
- (UIView *)ln_findFirstResponder;

#pragma mark -找到当前view所在的viewControler
- (UIViewController *)ln_findViewController;

@end




 









