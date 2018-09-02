//[TOC]
#pragma mark - 释义
```objc
UIButton
A control that executes your custom code in response to user interactions.
在用户交互响应中执行自定义代码的控件
```
#pragma mark - 层次结构（内部组成）
#pragma mark -初始化
```objc
1、初始化
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];// 自定义，点击没有切换效果
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];// 系统，点击有切换效果（就是一闪一闪的）
    button.frame =  CGRectMake(100, 100, 50, 50) ;
    button.bounds = CGRectMake(0, 0, 150, 150);//【指定 宽高】
    button.center = CGPointMake(200, 300);//【中心点的坐标】
2、内部组成
    内部子控件有，imageView（默认左）、titleLabel（默认右），默认紧贴组合居中在Button中间显示.
```
#pragma mark -常用属性
```objc
1、背景颜色
    button.backgroundColor = [UIColor blueColor];
    // 设置背景半透明(三种方式)，这里不要设置alpha，效果是内容和背景都会设置上透明
    button.backgroundColor = [[UIColor whiteColor] colorWithAlphaComponent:0.5];
    button.backgroundColor = [UIColor colorWithWhite:1.0 alpha:0.5];
    button.backgroundColor = [UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.5];

2、内边距
    button.imageEdgeInsets = UIEdgeInsetsMake(0, 0, 0, 10);//【内部image】
    button.titleEdgeInsets = UIEdgeInsetsMake(0, 10, 0, 0);//【内部titleLabel】

    //【内部控件整体处理】
    button.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;//【水平】
    button.contentVerticalAlignment = UIControlContentVerticalAlignmentTop;//【竖直】
    button.contentEdgeInsets = UIEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right);//【内容】

3、圆角 边框
    button.layer.cornerRadius = 25;//【圆角半径】
    button.layer.masksToBounds = YES;//【layer-超出裁剪】
    button.clipsToBounds = YES;//【View-超出裁剪】
    button.layer.borderWidth = 5;//【边框宽】
    button.layer.borderColor = [UIColor blueColor].CGColor;//【边框颜色】

4、设置文字
    [button setTitle:@"普通按钮" forState:UIControlStateNormal];//【普通状态】
    [button setTitle:@"高亮按钮" forState:UIControlStateHighlighted];//【高亮状态】
    [button setTitle:@"失效按钮" forState:UIControlStateDisabled];//【失效状态】就是变灰色点击无反应
    [button setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];//【普通状态】

5、设置字体
    button.titleLabel.font = [UIFont systemFontOfSize:30];//【字体大小】
    button.titleLabel.font = [UIFont boldSystemFontOfSize:13.0f];//【字体加粗】

6、设置图片
    [button setImage:[UIImage imageNamed:@"play_normal"] forState:UIControlStateNormal];//【普通状态】
    [button setBackgroundImage:[UIImage imageNamed:@"play_normal"] forState:UIControlStateNormal];//【普通状态】

    1.Button设置图片setImage或是setBackgroundImage
        setImage: 按钮改变大小图片始终是原始大小，可扩展点击区域（尽量采用设置Image）
        setBackgroundImage: 按钮有多大图片就显示多大，图片可能会变形（要保证按钮大小设置为图片的大小才不变形）
7、点击处变亮
    button.showsTouchWhenHighlighted = YES;

```


#pragma mark -常用方法
#pragma mark -取消长按按钮时出现高亮效果highlighted
```objc
// 重写该方法取消长按按钮时出现高亮效果重写setHighlighted:
- (void)setHighlighted:(BOOL)highlighted
{
    
}
```

#pragma mark -添加点击事件
```objc
// 添加点击事件
// TouchDown 一旦按钮被按下就触发的buttonClickDown
[button addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchDown];
// TouchUpInside 当手指按下后开始起来，inside意思是手指在UIButton的区域范围
[button addTarget:self action:@selector(btnClick:) forControlEvents:UIControlEventTouchUpInside];

- (void)btnClick
{
    // 注解：button的选中状态一定要 手动取反.
    self.button.selected = !self.button.selected;
}
```

#pragma mark -获取按钮某种状态下属性值
```objc
//【获取 按钮某种状态下属性值】
[button titleForState:UIControlStateNormal];//【设置和按钮标题某种状态下 文字相同】
[button backgroundImageForState:UIControlStateNormal];//【设置和按钮标题某种状态下 背景图片相同】

//【获取 按钮当前状态下属性值】
NSString *title = button.currentTitle;//【设置和按钮标题当前状态下 文字相同】
UIImage *image = button.currentBackgroundImage;//【设置和按钮标题当前状态下 背景图片相同】
```

#pragma mark -更改titleLabel在按钮当中的位置
```objc
@implementation LNButton
background、content、title、image

- (CGRect)titleRectForContentRect:(CGRect)contentRect
{
    return CGRectMake(0, 0, 100, 30);
}
```
![更改titleLabel在按钮当中的位置](https://upload-images.jianshu.io/upload_images/2230763-38536b5b4410b742.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)




#pragma mark - 总结笔记
#pragma mark -UIButton按钮状态说明
```objc
 1、按钮的状态
    1.UIControlStateNormal
        1.除开UIControlStateHighlighted、UIControlStateDisabled、UIControlStateSelected以外的其他情况，都是normal状态
        2.这种状态下的按钮【可以】接收点击事件

    2.UIControlStateHighlighted
        1.【当按住按钮不松开】或者【highlighted = YES】时就能达到这种状态
        2.这种状态下的按钮【可以】接收点击事件

    3.UIControlStateDisabled
        1.【button.enabled = NO】时就能达到这种状态
        2.这种状态下的按钮【无法】接收点击事件

    4.UIControlStateSelected
        1.【button.selected = YES】时就能达到这种状态
        2.这种状态下的按钮【可以】接收点击事件

 2、让按钮无法点击的2种方法
     1.button.enabled = NO;【会】进入UIControlStateDisabled状态
     2.button.userInteractionEnabled = NO;【不会】进入UIControlStateDisabled状态，继续保持当前状态
```
                        
#pragma mark -Button按钮点击切换状态(三步)
```objc
1.取消上次选中按钮(记录按钮)
    self.recordBtn.selected = NO;
2.选中当前点击的按钮
    btn.selected = YES;
3.记录(赋值给记录按钮)当前点击的按钮
    self.recordBtn = btn;
```

#pragma mark -基本使用
#pragma mark - 自定义控件（抽取封装）
#pragma mark -抽取封装：当子控件超出父视图frame范围，子视图超出部分点击事件无响应❓
```objc
/**
 问题：当子控件超出父视图frame范围，子视图超出部分点击事件无响应❓
 解决：在使用的地方，重写hitTest: withEvent:
 */
- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event {
    // 1.判断当前控件能否接收事件
    if (self.userInteractionEnabled == NO || self.hidden == YES || self.alpha <= 0.01) return nil;
    
    UIView *view = [super hitTest:point withEvent:event];
    if (view == nil) {
        // 2.转换坐标系（把view上的坐标系转换成子控件publishBtn上的坐标系）
        CGPoint newPoint = [self.publishBtn convertPoint:point fromView:self];
        
        // 3.判断触摸点是否在publishBtn上
        // if (CGRectContainsPoint(self.publishBtn.bounds,newPoint))
        if ([self.publishBtn pointInside:newPoint withEvent:event]) {
            view = self.publishBtn;
        } else {
            return [super hitTest:point withEvent:event];
        }
    }
    return view;
}
```
![抽取封装：当子控件超出父视图frame范围，子视图超出部分点击事件无响应❓](https://upload-images.jianshu.io/upload_images/2230763-9c9c4fc253163825.gif?imageMogr2/auto-orient/strip)

#pragma mark -抽取封装：调整UIButton内部子控件imageView和titleLabel的位置
```objc
/**
 2.设置子控件的frame
    需求：修改发布按钮内部子控件位置，显示imageView在上，titleLabel在下
    @interface LNPublishButton : UIButton
 */
- (void)layoutSubviews
{
    [super layoutSubviews];
    
    self.imageView.ln_y = 0;
    CGFloat imageViewMaxY = self.ln_height - self.titleLabel.ln_height;
    self.imageView.ln_width = self.imageView.ln_height = imageViewMaxY;
    self.imageView.ln_centerX = self.ln_width * 0.5;
    
    self.titleLabel.ln_y = imageViewMaxY;
    [self.titleLabel sizeToFit];
    self.titleLabel.ln_centerX = self.ln_width * 0.5;// 一定先计算，后修改center
}
```
![抽取封装：调整UIButton内部子控件imageView和titleLabel的位置](https://upload-images.jianshu.io/upload_images/2230763-e0956531f9ed4d00.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

#pragma mark - 场景思维



