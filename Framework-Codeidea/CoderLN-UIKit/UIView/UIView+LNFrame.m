/*
 * UIView+LNFrame.m
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import "UIView+LNFrame.h"

#pragma mark - UIView (LNFrame)
@implementation UIView (LNFrame)

#pragma mark - 常用扩展属性
- (void)setLn_width:(CGFloat)ln_width
{
    CGRect rect = self.frame;
    rect.size.width = ln_width;
    self.frame = rect;
}

- (void)setLn_height:(CGFloat)ln_height
{
    CGRect rect = self.frame;
    rect.size.height = ln_height;
    self.frame = rect;
}

-(CGFloat)ln_width
{
    return self.frame.size.width;
}

- (CGFloat)ln_height
{
    return self.frame.size.height;
}


# - - -
- (void)setLn_x:(CGFloat)ln_x
{
    CGRect rect = self.frame;
    rect.origin.x = ln_x;
    self.frame = rect;
}

- (void)setLn_y:(CGFloat)ln_y
{
    CGRect rect = self.frame;
    rect.origin.y = ln_y;
    self.frame = rect;
}

- (CGFloat)ln_x
{
    return self.frame.origin.x;
}

- (CGFloat)ln_y
{
    return self.frame.origin.y;
}


# - - -
- (void)setLn_size:(CGSize)ln_size
{
    CGRect rect = self.frame;
    rect.size = ln_size;
    self.frame = rect;
}


- (void)setLn_origin:(CGPoint)ln_origin
{
    CGRect rect = self.frame;
    rect.origin = ln_origin;
    self.frame = rect;
}


- (CGSize)ln_size
{
    return self.frame.size;
}

- (CGPoint)ln_origin
{
    return self.frame.origin;
}


# - - -

-(void)setLn_centerX:(CGFloat)ln_centerX {
    CGPoint center = self.center;
    center.x = ln_centerX;
    self.center = center;
}

- (void)setLn_centerY:(CGFloat)ln_centerY {
    CGPoint center = self.center;
    center.y = ln_centerY;
    self.center = center;
}

- (CGFloat)ln_centerX {
    return self.center.x;
}

- (CGFloat)ln_centerY {
    return self.center.y;
}


# - - -
- (void)setLn_maxX:(CGFloat)ln_maxX
{
    self.ln_x = ln_maxX - self.ln_width;
}

- (void)setLn_maxY:(CGFloat)ln_maxY
{
    self.ln_y = ln_maxY - self.ln_height;
}

- (CGFloat)ln_maxX
{
    return CGRectGetMaxX(self.frame);
}

- (CGFloat)ln_minX
{
    return CGRectGetMaxX(self.frame);
}

- (CGFloat)ln_maxY
{
    return CGRectGetMaxY(self.frame);
}

- (CGFloat)ln_minY
{
    return CGRectGetMinY(self.frame);
}


#pragma mark -快速加载view类名对应的Xib
+ (instancetype)ln_ViewFromXib
{
    return [[NSBundle mainBundle] loadNibNamed:NSStringFromClass(self) owner:nil options:nil].firstObject;
}


#pragma mark -给UIView设置圆角
- (void)setCornerRadius:(NSInteger)cornerRadius
{
    self.layer.cornerRadius = cornerRadius;
    self.layer.masksToBounds = cornerRadius > 0;
}

- (NSInteger)cornerRadius
{
    return self.layer.cornerRadius;
}

- (void)setMasksToBounds:(BOOL)bounds
{
    self.layer.masksToBounds = bounds;
}
- (BOOL)masksToBounds
{
    return self.layer.masksToBounds;
}




#pragma mark -设置view的边框宽度、边框的颜色、Hex颜色
- (void)setBorderWidth:(NSInteger)borderWidth
{
    self.layer.borderWidth = borderWidth;
}

- (NSInteger)borderWidth
{
    return self.layer.borderWidth;
}

- (void)setBorderColor:(UIColor *)borderColor
{
    self.layer.borderColor = borderColor.CGColor;
}

- (UIColor *)borderColor
{
    return [UIColor colorWithCGColor:self.layer.borderColor];
}

- (void)setBorderHexRgb:(NSString *)borderHexRgb
{
    NSScanner *scanner = [NSScanner scannerWithString:borderHexRgb];
    unsigned hexNum;
    //这里是将16进制转化为10进制
    if (![scanner scanHexInt:&hexNum]) return;
    
    self.layer.borderColor = [self colorWithRGBHex:hexNum].CGColor;
}

-(NSString *)borderHexRgb
{
    return @"0xffffff";
}
- (UIColor *)colorWithRGBHex:(UInt32)hex
{
    int r = (hex >> 16) & 0xFF;
    int g = (hex >> 8) & 0xFF;
    int b = (hex) & 0xFF;
    
    return [UIColor colorWithRed:r / 255.0f
                           green:g / 255.0f
                            blue:b / 255.0f
                           alpha:1.0f];
}

@end





 

#pragma mark - UIView (BlockGesture)
#import <objc/runtime.h>

static char kActionHandlerTapBlockKey;
static char kActionHandlerTapGestureKey;
static char kActionHandlerLongPressBlockKey;
static char kActionHandlerLongPressGestureKey;

@implementation UIView (BlockGesture)

#pragma mark - 给UIView添加tap手势
- (void)ln_addTapActionWithBlock:(TapActionBlock)block
{
    UITapGestureRecognizer *gesture = objc_getAssociatedObject(self, &kActionHandlerTapGestureKey);
    if (!gesture)
    {
        gesture = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleActionForTapGesture:)];
        [self addGestureRecognizer:gesture];
        objc_setAssociatedObject(self, &kActionHandlerTapGestureKey, gesture, OBJC_ASSOCIATION_RETAIN);
    }
    objc_setAssociatedObject(self, &kActionHandlerTapBlockKey, block, OBJC_ASSOCIATION_COPY);
}

#pragma mark - 给UIView添加Long手势
- (void)ln_handleActionForTapGesture:(UITapGestureRecognizer *)gesture
{
    if (gesture.state == UIGestureRecognizerStateRecognized)
    {
        TapActionBlock block = objc_getAssociatedObject(self, &kActionHandlerTapBlockKey);
        if (block)
        {
            block(gesture);
        }
    }
}

- (void)ln_addLongPressActionWithBlock:(LongPressActionBlock)block
{
    UILongPressGestureRecognizer *gesture = objc_getAssociatedObject(self, &kActionHandlerLongPressGestureKey);
    if (!gesture)
    {
        gesture = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleActionForLongPressGesture:)];
        [self addGestureRecognizer:gesture];
        objc_setAssociatedObject(self, &kActionHandlerLongPressGestureKey, gesture, OBJC_ASSOCIATION_RETAIN);
    }
    objc_setAssociatedObject(self, &kActionHandlerLongPressBlockKey, block, OBJC_ASSOCIATION_COPY);
}

- (void)handleActionForLongPressGesture:(UILongPressGestureRecognizer *)gesture
{
    if (gesture.state == UIGestureRecognizerStateRecognized)
    {
        LongPressActionBlock block = objc_getAssociatedObject(self, &kActionHandlerLongPressBlockKey);
        if (block)
        {
            block(gesture);
        }
    }
}

@end





#pragma mark - UIView (FindView)
@implementation UIView (FindView)


#pragma mark -判断self和view是否重叠
- (BOOL)ln_intersectsWithView:(UIView *)view
{
    //都先转换为相对于窗口的坐标，然后进行判断是否重合
    CGRect selfRect = [self convertRect:self.bounds toView:nil];
    CGRect viewRect = [view convertRect:view.bounds toView:nil];
    return CGRectIntersectsRect(selfRect, viewRect);
}

#pragma mark -找到view上的第一响应者
- (UIView *)ln_findFirstResponder
{
    if (([self isKindOfClass:[UITextField class]] || [self isKindOfClass:[UITextView class]])
        && (self.isFirstResponder))
    {
        return self;
    }
    
    for (UIView *v in self.subviews)
    {
        UIView *fv = [v findFirstResponder];
        if (fv)
        {
            return fv;
        }
    }
    
    return nil;
}

#pragma mark -找到当前view所在的viewControler
- (UIViewController *)ln_findViewController;
{
    UIResponder *responder = self.nextResponder;
    do
    {
        if ([responder isKindOfClass:[UIViewController class]])
        {
            return (UIViewController *)responder;
        }
        responder = responder.nextResponder;
    }
    while (responder);
    
    return nil;
}

@end

























