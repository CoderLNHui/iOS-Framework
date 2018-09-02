//[TOC]
#pragma mark - UIImage常用属性
```objc
1、图片渲染模式
    // 返回一张不渲染图片
    UIImage *image = [[UIImage imageNamed:@"rightItem.png"] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];

2、创建一张可拉伸的图片
    UIImage *image  = [UIImage imageNamed:@"navBarBackgroundImage.png"];
    //UIImageResizingModeTile,     平铺
    //UIImageResizingModeStretch,  拉伸
    image = [image resizableImageWithCapInsets:UIEdgeInsetsMake(5, 5, 5, 5) resizingMode:UIImageResizingModeStretch];
    [self.navigationController.navigationBar setBackgroundImage:image forBarMetrics:UIBarMetricsCompact];
```


#pragma mark -加载图片
```objc
0、注解
    1.imageNamed:(图片缓存)，可以加载项目中 和 Assets.xcassets(只适合存放系统常用的，占用内存小的图片资源)中的图片资源.
    2.imageWithContentsOfFile:(图片不缓存)，只能加载项目中的图片资源.
    3.Xcode默认支持.png图片加载可以不写后缀，但.jpg图片必须写后缀.

- - -
1、从【应用程序包中】加载图片
    从应用程序包中加载图片会建立图像缓存，第一次从文件中加载，以后都是从缓存中直接读取，效率比较高，通常加载小图片)
    UIImage * image = [UIImage iamgeNamed:@"img"];// 作为.png格式的图片，我们可以不添加后缀
    UIImage * image = [UIImage iamgeNamed:@"img.jpg"];// 其他格式需要加，如.jpg

2、通过文件路径加载图片
    1.从【应用程序包】加载每次从硬盘上加载，不会缓存，通常大的图片使用这种方式。(只能加载项目中的图片)
    NSString * path = [[NSBundle mainBundle] pathForResource:@"img" ofType:@"png"];
    UIImage * image = [UIImage imageWithContentsOfFile:path];

    2.从【沙盒Document文件夹】下加载
    NSString * path = [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"img.png"];
    UIImage * image = [UIImage imageWithContentsOfFile:path];

3、通过内存中的NSData对象加载图片
    1.从【应用程序包中】加载
    NSString * path = [[NSBundle mainBundle] pathForResource:@"img" ofType:@"png"];
    NSData * data = [[NSData alloc] initWithContentsFile:path];
    UIImage * image = [UIImage imageWithData:path];

    2.从【沙盒Document文件夹】下加载
    NSString * path = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    path = [path stringByAppendingPathComponent:@"img.png"];
    NSData * data = [[NSData alloc] initWithContentsOfFile:path];
    UIImage * image = [UIImage imageWithData:path];

    3.从【网络】上加载
    NSURL * url = [NSURL URLWithString:@"http://xxx/img.png"];
    NSData * data = [[NSData alloc] initWithContentsOfURL:url];
    UIImage * image = [UIImage imageWithData:path];

4、通过【CGImageRef对象】加载图片
    在创建时还可以指定方法倍数以及旋转方向。当scale设置为1的时候，新创建的图像将和原图像尺寸一摸一样，而orientaion则可以指定新的图像的绘制方向
    CGImageRef imageRef = nil;
    UIImage * image = [UIImage imageWithCGImage:imageRef scale:1.0 orientation:UIImageOrientationLeft];

5、加载.bundle资源包里面的图片（格式：bundle文件名/图片名）
    imageView.image= [UIImage imageNamed:@"SVProgressHUD.bundle/error"];
```







#pragma mark - UIImageView常用属性
```objc
// 初始化
UIImageView * imageView =[[UIImageView alloc] initWithFrame:CGRectMake(100, 100, 100, 100)];

imageView.image = [UIImage imageNamed:@""];//图片

imageView.highlightedImage = [UIImage imageNamed:@""];//高亮图片

imageView.highlighted = YES;//是否高亮

// 图片交互
imageView.alpha = 0.02;//alpha值大于0.01时才会相应事件
imageView.userInteractionEnabled = YES;

// 渲染
imageView.tintColor = [UIColor redColor];

// 设置圆角
imageView.layer.masksToBounds = YES;
imageView.layer.cornerRadius = 10;

// 设置边框大小和颜色
imageView.layer.borderWidth = 2;
imageView.layer.borderColor = [UIColor orangeColor].CGColor;

// 内容显示模式（当图片小于imageView的大小处理图片显示：如居中、居右，是否缩放等）
imageView.contentMode = UIViewContentModeLeft;
// 隐藏或者显示图片
imageView.hidden = NO;
// 设置透明度
imageView.alpha = 0.9;

// 图片添加单击事件
imageView.userInteractionEnabled = YES;
[imageView addGestureRecognizer:[[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapImageView:)]];
```



#pragma mark - 场景思维
#pragma mark -动画图片数组
```objc
UIImage animatedImageWithImages 动画图片
UIImageView animationImages 动画图片

    //【系统】动画图片数组
    NSMutableArray *images = [NSMutableArray array];
    for (NSInteger i = 1; i<= 4; i++) {
        NSString *imageName = [NSString stringWithFormat:@"%ld.png",i];
        UIImage *image = [UIImage imageNamed:imageName];
        [images addObject:image];
    }
    imageView.animationImages = images;//图片动画
    imageView.animationDuration = 3;//持续时间
    imageView.animationRepeatCount = 0;//0表示一直重复
    [imageView startAnimating];//开始动画
    [imageView stopAnimating];//结束动画
```
![UIImageView 动画图片数组](https://upload-images.jianshu.io/upload_images/2230763-cde2e28584ddd99e.gif?imageMogr2/auto-orient/strip)


#pragma mark -imageView加毛玻璃
```objc
方式一：
    // 1.加毛玻璃
    UIToolbar *toolbar = [[UIToolbar alloc] init];
    // 2. 设置frame
    toolbar.frame = self.bgImageView.bounds;
    // 3. 设置样式和透明度
    toolbar.barStyle = UIBarStyleBlack;
    toolbar.alpha = 0.98;
    // 4.加到背景图片上
    [self.bgImageView addSubview:toolbar];

方式二：
    UIImageView *backImageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"leftBackView"]];
    [self.view addSubview:backImageView];

    //添加毛玻璃效果
    UIBlurEffect *blur = [UIBlurEffect effectWithStyle:UIBlurEffectStyleLight];
    UIVisualEffectView *effectview = [[UIVisualEffectView alloc] initWithEffect:blur];
    effectview.alpha = 0.90f;
    effectview.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    [backImageView addSubview:effectview];
```
![imageView加毛玻璃](https://upload-images.jianshu.io/upload_images/2230763-4c5a5a1ec642ccf7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


#pragma mark -图片截屏
```objc
// 保存
- (IBAction)save:(id)sender {
    // 1.开启同等大小的图片上下文
    UIGraphicsBeginImageContextWithOptions(self.drawV.frame.size, NO, 0);

    // 2.获取当前上下文
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    // 渲染上下文到layer中
    [self.drawV.layer renderInContext:ctx];
    
    // 3.从当前上下文中获取一张图片
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();

    // 4.关闭上下文
    UIGraphicsEndImageContext();
    
    // 5.把图片保存到系统相册中（保存图片成功必须得要调用下面方法）
    // image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo
    UIImageWriteToSavedPhotosAlbum(newImage, self, @selector(image:didFinishSavingWithError:contextInfo:), nil);
}

// 保存图片成功时调用
- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo
{
    NSLog(@"保存完成");
}
```

#pragma mark -加载Gif图片（本地/网络）
```objc
1、使用UIWebView
    // 读取gif图片数据
    UIWebView *webView = [[UIWebView alloc] initWithFrame:CGRectMake(0,0,200,200)];
    [self.view addSubview:webView];
         
    NSString *path = [[NSBundle mainBundle] pathForResource:@"001" ofType:@"gif"];
    NSURL *url = [NSURL URLWithString:path];

    // 不能设置Gif动画的播放时间。
    [webView loadRequest:[NSURLRequest requestWithURL:url]];

2、使用UIImageView
    - (NSArray *)animationImages
    {
        // 加载Loading.bundle中的图片
        NSFileManager *fielM = [NSFileManager defaultManager];
        NSString *path = [[NSBundle mainBundle] pathForResource:@"Loading" ofType:@"bundle"];
        NSArray *arrays = [fielM contentsOfDirectoryAtPath:path error:nil];
        NSMutableArray *imagesArr = [NSMutableArray array];
        for (NSString *name in arrays) {
            UIImage *image = [UIImage imageNamed:[(@"Loading.bundle") stringByAppendingPathComponent:name]];
            if (image) {
                [imagesArr addObject:image];
            }
        }
        return imagesArr;
    }

    - (void)viewDidLoad {
        [super viewDidLoad];
        
        UIImageView *gifImageView = [[UIImageView alloc] initWithFrame:frame];
        gifImageView.animationImages = [self animationImages]; //获取Gif图片列表
        gifImageView.animationDuration = 5;     //执行一次完整动画所需的时长
        gifImageView.animationRepeatCount = 0;  //动画重复次数
        [gifImageView startAnimating];
        [self.view addSubview:gifImageView];
    }
```

 
