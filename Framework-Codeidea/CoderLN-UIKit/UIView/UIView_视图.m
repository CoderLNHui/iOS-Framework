
#pragma mark - 释义
```objc
UIView
An object that manages the content for a rectangular area on the screen.
一个用于管理屏幕上矩形区域内容的对象
```
 
#pragma mark - 层次结构（内部组成）
#pragma mark -概念
```objc
1、UIView 视图
    0、UIView表示屏幕上的矩形区域，iOS中几乎所有可视化控件都是UIView的子类。负责渲染区域的内容，用它来显示操作界面并且响应该区域内发生的触摸事件。
    1、frame 和 center 参照是父视图的坐标系统，
       bounds 参照的是当前视图的坐标系统，所以 bounds 的坐标原点一般是{0,0}（注意：在 UIScrollView 中设置 bounds 原点不为{0,0}，来显示不一样的效果）
    2、UIView的三个结构体：
        CGPoint (x，y)点、CGSize (width，height)大小、CGRect (origin，size)尺寸 、CGVector (dx，dy)矢量
    3、UIView 的动画
        UIView (UIViewAnimation) // 基础动画
        UIView (UIViewAnimationWithBlocks) // UIView+block动画
        UIView (UIViewKeyframeAnimations) // 关键帧动画
    4、作用：1.显示layer渲染出来的界面，2.与用户进行交互

2、CALayer 图层
    1.每一个view都会对应一个layer，layer帮我们做的事情是渲染view的内容
    2.layer中有一些属性是view没有的，这样我们可以通过设置layer对UIView做进一步的设置
    3.所有发生在view上的动画，都是layer完成的。
    4.不具备与用户交互的作用
```

#pragma mark -初始化
```objc
[alloc init];
initWithFrame:
```

#pragma mark -常用属性
```objc
1、创建View
    CGRect rect = [UIScreen mainScreen].bounds;
    self.view = [[UIView alloc]initWithFrame:rect];

2、bounds + center：根据自身的宽高 加 中心点 的方式生成View (frame 本身就是靠bounds + center 计算出来的)
    UIView *view2 = [[UIView alloc] initWithFrame:CGRectZero];// Frame为0
    view2.bounds = CGRectMake(0, 0, 150, 150);// 指定  宽高
    view2.center = CGPointMake(200, 300);// 中心点的坐标
    [self.window addSubview:view2];

3、从父视图中移除
    [self.redView removeFromSuperview];
    // 从父视图中批量删除子视图
    NSArray *subViews = self.subViews;
    if([subViews count] != 0) {
        [subViews makeObjectPerformSelector:@selector(removeFromSuperview)];
    }

4、CGRectInset 收缩：矩形框通过一个矩形得到另一个矩形(输入矩形的中心点不变，向内收缩指定大小，正收缩  负拉伸)
    rect = CGRectInset(rect, 10, 10);//(rect,10左向—>右,10上向—>下)
    UIView *view = [[UIView alloc]initWithFrame:rect];

5、递归遍历找到相对应的View的tag值
    UIView *view = [self.window viewWithTag:_currentTag];
    redView.clipsToBounds = YES;// UIView裁剪
    redView.layer.maskeToBounds = YES;// CALayer裁剪

6、autoresizingMask 自动布局：设置子视图怎么根据父视图的大小变化而变化的属性
    blueView.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
    [redView addSubview:blueView];

7、设置view居中显示
    imgView.frame = CGRectMake((kScreenW - imgW) * 0.5, (kScreenH - imgW) * 0.5, imgW, imgW);


```



#pragma mark -常用方法
```objc


视图之间坐标点的转换（从view(self父视图)上的坐标系转换成子控件publishBtn上的坐标系）
CGPoint newPoint = [self.publishBtn convertPoint:point fromView:self];
```





#pragma mark - 总结笔记
#pragma mark -基本使用
#pragma mark -Animation 动画
```objc
1、系统自带的 animationImages动画
    UIImageView * imageView = [[UIImageView alloc] init];
    NSMutableArray * images = [NSMutableArray array];
    for (NSInteger i = 0; i <= 6; i++) {
        UIImage * image = [UIImage imageNamed:[NSString stringWithFormat:@"image%zd",i]];
        [images addObject:image];
    }
    imageView.animationImages = images;
    imageView.animationDuration = 0.3;
    imageView.animationRepeatCount = 0;
    [imageView startAnimating];
    [imageView stopAnimating];

- - -
2、UIView [begin commit] 动画
- (void)viewAnimation {
    // 可以嵌套但是必须成对出现
    UIViewAnimationTransition type = UIViewAnimationTransitionNone;
    
    // 开始动画
    [UIView beginAnimations:nil context:nil];
    
    // 动画的持续时间
    [UIView setAnimationDuration:1];
    // 动画类型
    [UIView setAnimationTransition:type forView:_redView cache:YES];
    // 动画代理
    //[UIView setAnimationDelegate:self];
    //[UIView setAnimationWillStartSelector:@selector(annimationStart)];
    //[UIView setAnimationDidStopSelector:@selector(annimationStop)];
    
    // 提交动画
    [UIView commitAnimations];
}
- (void)animationDidStart:(CAAnimation *)anim;//动画开始调用
- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag;//动画结束调用

- - -
3、[UIView animateBlock] 代码块动画
    1、弹性动画
    [UIView animateWithDuration:<#(NSTimeInterval)#>：动画持续时间
                          delay:<#(NSTimeInterval)#>：动画延迟多长时间开始
         usingSpringWithDamping:<#(CGFloat)#>：阻尼(范围0-1，一般为0.7 阻尼越接近于0弹性效果越明显)
          initialSpringVelocity:<#(CGFloat)#>：弹性复位的速度(一般为0)
                        options:<#(UIViewAnimationOptions)#>：动画类型(速度曲线、翻转方式等)
                     animations:<#^(void)animations#>：执行动画过程
                     completion:<#^(BOOL finished)completion#>：动画完成的回调
     
    2、关键帧动画
    [UIView animateKeyframesWithDuration:<#(NSTimeInterval)#><#(NSTimeInterval)#>：动画持续时间
                                    delay:<#(NSTimeInterval)#>：等待时间
                              options:<#(UIViewKeyframeAnimationOptions)#>：动画类型
                           animations:<#^(void)animations#>：执行动画过程
                           completion:<#^(BOOL finished)completion#>：动画完成的回调
```
  
  
#pragma mark -Transform 形变
```objc
1、使用分解
    // Translation 平移
    CGAffineTransformMakeTranslation(CGFloat tx：在x轴上平移, CGFloat ty：是在y上平移);
    // Rotation 旋转
    CGAffineTransformMakeRotation(CGFloat angle：角度 M_PI <－> 180);
    // Scale 缩放
    CGAffineTransformMakeScale(CGFloat sx：指x轴缩放的比例, CGFloat sy：在y轴上的缩放比例);

    // 旋转（使用Make，相对原始位置只形变一次）
    self.imageView.transform = CGAffineTransformMakeRotation(M_PI_4);
    // 缩放（不使用Make，相对于上一次做形变，一直形变）
    self.imageView.transform = CGAffineTransformScale(self.imageView.transform, 0.8, 0.8);

- - -
2、使用步骤
    [UIView animateWithDuration:0.5 delay:0 usingSpringWithDamping:0.5 initialSpringVelocity:0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
     
         // 指定在y轴向上平移100
         ballView.transform = CGAffineTransformMakeTranslation(0, -100);
    } completion:^(BOOL finished) {
        
         // 形变动画完成后回到 原始状态
         ballView.transform = CGAffineTransformIdentity;
    }];
```
  
  
#pragma mark - 自定义控件（抽取封装）
#pragma mark - 场景思维
#pragma mark -UIView设置半透明颜色
```objc
1、UIView 设置半透明三种方式
    方式一：更灵活哪种颜色都可以设置半透明
    titlesView.backgroundColor = [[UIColor whiteColor] colorWithAlphaComponent:0.5];
    方式二：专门为白色设置
    titlesView.backgroundColor = [UIColor colorWithWhite:1.0 alpha:0.5];
    方式三：RGB
    titlesView.backgroundColor = [UIColor colorWithRed:1.0 green:1.0 blue:1.0 alpha:0.5];

2、alpha 半透明
    透明度取值范围[0~1]，0是完全透明，1是完全不透明
    view.alpha = 0.02 > 0.01 才有响应

3、随机颜色
    #define randomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0];
```




















