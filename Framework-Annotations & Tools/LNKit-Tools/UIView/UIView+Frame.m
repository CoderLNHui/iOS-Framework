/*
 * UIView+Frame.m
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

#import "UIView+Frame.h"

@implementation UIView (Frame)


//--------------------------- 【UIView扩展属性】 ------------------------------//
//



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

//---


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

//---



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

//---



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

//---


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




/*
 *【快速加载View对应的Xib】
 */
+ (instancetype)ln_ViewFromNib
{
    return [[NSBundle mainBundle] loadNibNamed:NSStringFromClass([self class]) owner:nil options:nil].firstObject;
}



/**
 * 【判断self和view是否重叠】
 */
- (BOOL)ln_intersectsWithView:(UIView *)view
{
    //都先转换为相对于窗口的坐标，然后进行判断是否重合
    CGRect selfRect = [self convertRect:self.bounds toView:nil];
    CGRect viewRect = [view convertRect:view.bounds toView:nil];
    return CGRectIntersectsRect(selfRect, viewRect);
}

@end








//--------------------------- <#我是分割线#> ------------------------------//
//







@implementation UIView (Frame)

- (void)setX:(CGFloat)x
{
    CGRect frame = self.frame;
    frame.origin.x = x;
    self.frame = frame;
}

- (CGFloat)x
{
    return self.frame.origin.x;
}

- (void)setY:(CGFloat)y
{
    CGRect frame = self.frame;
    frame.origin.y = y;
    self.frame = frame;
}

- (CGFloat)y
{
    return self.frame.origin.y;
}

- (void)setOrigin:(CGPoint)origin
{
    CGRect frame = self.frame;
    frame.origin = origin;
    self.frame = frame;
}

- (CGPoint)origin
{
    return self.frame.origin;
}

- (void)setWidth:(CGFloat)width
{
    CGRect frame = self.frame;
    frame.size.width = width;
    self.frame = frame;
}

- (CGFloat)width
{
    return self.frame.size.width;
}

- (void)setHeight:(CGFloat)height
{
    CGRect frame = self.frame;
    frame.size.height = height;
    self.frame = frame;
}

- (CGFloat)height
{
    return self.frame.size.height;
}

- (void)setSize:(CGSize)size
{
    CGRect frame = self.frame;
    frame.size = size;
    self.frame = frame;
}

- (CGSize)size
{
    return self.frame.size;
}

- (void)setBottom:(CGFloat)bottom
{
    CGRect frame = self.frame;
    frame.origin.y = bottom - frame.size.height;
    self.frame = frame;
}

- (CGFloat)bottom
{
    return CGRectGetMaxY(self.frame);
}

- (CGFloat)tail
{
    return CGRectGetMaxX(self.frame);
}

- (void)setTail:(CGFloat)tail
{
    CGRect frame = self.frame;
    frame.origin.x = tail - frame.size.width;
    self.frame = frame;
}

- (void)setMiddleX:(CGFloat)middleX
{
    CGRect frame = self.frame;
    frame.origin.x = middleX - frame.size.width / 2;
    self.frame = frame;
}

- (CGFloat)middleX
{
    return CGRectGetMidX(self.frame);
}

- (void)setMiddleY:(CGFloat)middleY
{
    CGRect frame = self.frame;
    frame.origin.y = middleY - frame.size.height / 2 ;
    self.frame = frame;
}

- (CGFloat)middleY
{
    return CGRectGetMidY(self.frame);
}

//  返回Y
- (CGFloat)top
{
    return self.frame.origin.y;
}

- (void)setTop:(CGFloat)newtop
{
    CGRect newframe = self.frame;
    newframe.origin.y = newtop;
    self.frame = newframe;
}

//  返回X
- (CGFloat)left
{
    return self.frame.origin.x;
}

- (void)setLeft:(CGFloat) newleft
{
    CGRect newframe = self.frame;
    newframe.origin.x = newleft;
    self.frame = newframe;
}

//  返回X + width
- (CGFloat)right
{
    return self.frame.origin.x + self.frame.size.width;
}

- (void)setRight:(CGFloat)newright
{
    CGFloat delta = newright - (self.frame.origin.x + self.frame.size.width);
    CGRect newframe = self.frame;
    newframe.origin.x += delta ;
    self.frame = newframe;
}

@end










//--------------------------- <#我是分割线#> ------------------------------//
//











#import <objc/runtime.h>

static char kActionHandlerTapBlockKey;
static char kActionHandlerTapGestureKey;
static char kActionHandlerLongPressBlockKey;
static char kActionHandlerLongPressGestureKey;

@implementation UIView (BlockGesture)

- (void)addTapActionWithBlock:(TapActionBlock)block
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

- (void)handleActionForTapGesture:(UITapGestureRecognizer *)gesture
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

- (void)addLongPressActionWithBlock:(LongPressActionBlock)block
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






@implementation UIView (Find)

- (UIView *)findSubViewWithClass:(Class)clazz;
{
    for (UIView * subView in self.subviews)
    {
        if ([subView isKindOfClass:clazz])
        {
            return subView;
        }
    }
    
    return nil;
}

- (NSArray *)findAllSubViewsWithClass:(Class)clazz
{
    NSMutableArray *array = [NSMutableArray array];
    
    for (UIView * subView in self.subviews)
    {
        if ([subView isKindOfClass:clazz])
        {
            [array addObject:subView];
        }
    }
    
    return array;
}

- (UIView *)findSuperViewWithClass:(Class)clazz;
{
    if (self == nil)
    {
        return nil;
    }
    else if (self.superview == nil)
    {
        return nil;
    }
    else if ([self.superview isKindOfClass:clazz])
    {
        return self.superview;
    }
    else
    {
        return [self.superview findSuperViewWithClass:clazz];
    }
}

- (UIView *)findFirstResponder
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

- (UIViewController *)findViewController;
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

- (void)removeAllSubviews
{
    [self.subviews makeObjectsPerformSelector:@selector(removeFromSuperview)];
}

- (NSArray *)allSubviews
{
    NSMutableArray *array = [NSMutableArray arrayWithCapacity:0];
    
    [array addObjectsFromArray:self.subviews];
    
    for (UIView *view in self.subviews)
    {
        [array addObjectsFromArray:[view allSubviews]];
    }
    
    return array;
}

@end




@implementation UIView (IBnspectable)

- (void)setCornerRadius:(NSInteger)cornerRadius
{
    self.layer.cornerRadius = cornerRadius;
    self.layer.masksToBounds = cornerRadius > 0;
}

- (NSInteger)cornerRadius
{
    return self.layer.cornerRadius;
}

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
    if (![scanner scanHexInt:&hexNum])
        return;
    self.layer.borderColor = [self colorWithRGBHex:hexNum].CGColor;
}

-(NSString *)borderHexRgb
{
    return @"0xffffff";
}

- (void)setMasksToBounds:(BOOL)bounds
{
    self.layer.masksToBounds = bounds;
}

- (BOOL)masksToBounds
{
    return self.layer.masksToBounds;
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






//--------------------------- <#我是分割线#> ------------------------------//
//







@implementation UIView (Nib)

+ (instancetype)loadViewFromNib
{
    return [self loadViewFromNibWithName:NSStringFromClass([self class])];
}

+ (instancetype)loadViewFromNibWithName:(NSString *)nibName
{
    return [self loadViewFromNibWithName:nibName owner:nil];
}

+ (instancetype)loadViewFromNibWithName:(NSString *)nibName owner:(id)owner
{
    return [self loadViewFromNibWithName:nibName owner:owner bundle:[NSBundle mainBundle]];
}

+ (instancetype)loadViewFromNibWithName:(NSString *)nibName owner:(id)owner bundle:(NSBundle *)bundle
{
    UIView *result = nil;
    NSArray* elements = [bundle loadNibNamed:nibName owner:owner options:nil];
    for (id object in elements)
    {
        if ([object isKindOfClass:[self class]])
        {
            result = object;
            break;
        }
    }
    return result;
}

@end








//--------------------------- <#我是分割线#> ------------------------------//
//





@implementation UIView (ViewController)
/**
 获取view对象的所在ViewController
 */
+ (UIViewController *)viewControllerOfView:(UIView *)viewObj {
    for (UIView *next = [viewObj superview]; next; next =
         next.superview) {
        UIResponder *nextResponder = [next nextResponder];
        if ([nextResponder isKindOfClass:[UIViewController
                                          class]]) {
            return (UIViewController*)nextResponder;
        }
    }
    return nil;
}

@end

#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END


















