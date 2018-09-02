//[TOC]
#pragma mark - LaunchScreen启动图片
```objc
 1、设置启动图片
    1、优先级 LaunchScreen > LaunchImage
        在xcode配置了,不起作用 1.清空xcode缓存 2.直接删掉程序 重新运行
    2、LaunchImage
        如果是通过LaunchImage设置启动界面,那么屏幕的可视范围由图片决定；
        如果使用LaunchImage,必须让你的美工提供各种尺寸的启动图片。
    3、LaunchScreen：（Xcode6：LaunchScreen.Xib，Xcode7.0：LaunchScreen.storyboard）
        1.自动识别当前真机或者模拟器的尺寸
        2.只要让美工提供一个可拉伸图片
        3.展示更多东西
        4.LaunchScreen设置启动图片，图片放在 [Barand Assets] 不识别（应把图片放到Assets.xcassets目录下）

 2、LaunchScreen 启动原理
    1.如果在Target当中指定了LaunchScreen file，会自动加载LaunchScreen
    2.如果没有设置启动图片，模拟器默认的尺寸大小是4s的尺寸大小(可以打印屏幕尺寸验证) NSStringFromCGSize([UIScreen mainScreen].bounds.size)
    3.它的底层实现其实把LaunchScreen上的东西，截屏生成了一张图片，然后把这张图片设为程序的启动图片
        可以进入沙盒当中查看，找到应用程序根目录:NSLog(@"%@",NSHomeDirectory());打印出来后前往文件夹，找到Library->Caches->Snapshots目录下面,最后一层就是程序自动生成的图片
```

#pragma mark - UIApplication对象
```objc
 1、UIApplication对象
    1.是应用程序的象征,每一个应用都有自己的UIApplication对象,这个对象是系统自动帮我们创建的, 它是一个单例对象[UIApplication sharedApplication]
    2.利用UIApplication对象,能进行一些应用级别的操作
```

#pragma mark -常用属性
```objc
1、获取窗口
    LNTabBarViewController * tabVc = [[UIViewController alloc] init];
    [UIApplication sharedApplication].keyWindow.rootViewController = tabVc;



```


#pragma mark -设置应用程序图标右上角的红色提醒数字
```objc
    // 1.获取单例 (UIApplication对象)
    UIApplication *app =  [UIApplication sharedApplication];

    // 2.注册通知 (从ios8之后,都要先注册一个通知对象.才能够接收到提醒)
    UIUserNotificationSettings *setting = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeBadge categories:nil];
    [app registerUserNotificationSettings:setting];

    // 3.设置提醒数字
    app.applicationIconBadgeNumber = 10;
```

#pragma mark -设置联网指示器的可见性
```objc
    // 获取单例，设置联网状态
    [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
```

#pragma mark -UIApplication全局设置来管理状态栏
```objc
 1、控制器管理状态栏
 - (UIStatusBarStyle)preferredStatusBarStyle{//返回状态栏的样式
    return UIStatusBarStyleLightContent;
 }
 - (BOOL)prefersStatusBarHidden{//是否隐藏状态栏
    return YES;// NO
 }
 
- - -
 2、UIApplication全局设置来管理状态栏
    UIApplication *app =  [UIApplication sharedApplication];
    //样式
    app.statusBarStyle = UIStatusBarStyleLightContent;
    //隐藏
    app.statusBarHidden = NO;
```

#pragma mark -进行应用之间的跳转
```objc
    // 1.获取单例对象
    UIApplication *app =  [UIApplication sharedApplication];

    // 2.设置URL
    NSURL *url = [NSURL URLWithString:@"http://www.520it.com"];
    // 打电话
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"tel://10086"]];
    // 发短信
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"sms://10086"]];
    // 发邮件
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"mailto://123456@qq.com"]];

    // 3.把开网络请求
    [[UIApplication sharedApplication] openURL:url];
```

#pragma mark -UIApplication代理方法
```objc
0、UIApplication代理方法作用
    监听应用程序的生命周期
    监听系统事件
    处理内存警告

/**
 作用：启动完成时调用
 注解：
    当应用程序正常启动时调用（不包括已在后台转到前台的情况），launchOptions是启动参数。
    假如用户通过点击push通知启动的应用，(这是非正常启动的情况，包括本地通知和远程通知)，这个参数里会存储一些push通知的信息。
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 作用：将要失去活动状态时调用
 注解：
    当应用从活动状态主动变为非活动状态的时候会调用，这可导致产生某些类型的临时中断（如传入电话呼叫或SMS消息）。
    当用户退出应用程序，它开始过渡到的背景状态。使用此方法可以暂停正在进行的任务，禁用定时器，降低OpenGL ES的帧速率。游戏应该使用这个方法来暂停游戏。
    调用时机可能有以下几种：锁屏，单击HOME键，下拉状态栏，双击HOME键弹出底栏等情况。
 */
- (void)applicationWillResignActive:(UIApplication *)application;

/**
 作用：进入到后台时调用
 注解：
    使用此方法来释放资源共享，保存用户数据，无效计时器，并储存足够的应用程序状态信息,以便程序被终止后，将应用程序恢复到目前的状态。
    如果您的应用程序支持后台运行，这个方法被调用，否则调用applicationWillTerminate：用户退出。
 */
- (void)applicationDidEnterBackground:(UIApplication *)application;

/**
 作用：将要进入到前台时调用
 注解：
    当应用在后台状态，将要进入到前台运行时，会调用此方法。
    用来撤销applicationWillResignActive中做的改变
    如果应用不在后台状态，而是直接启动，则不会回调此方法。
 */
- (void)applicationWillEnterForeground:(UIApplication *)application;

/**
 作用：将要成为活动状态时调用
 注解：
    当应用程序全新启动，或者在后台转到前台，都会调用这个方法。
    如果应用程序是以前运行在后台，这时可以选择刷新用户界面。
 */
- (void)applicationDidBecomeActive:(UIApplication *)application;

/**
 作用：将要退出时调用
 注解：
    当应用退出，并且进程即将结束时会调到这个方法，一般很少主动调到，更多是内存不足时是被迫调到的，我们应该在这个方法里做一些数据存储操作。
 */
- (void)applicationWillTerminate:(UIApplication *)application;

/**
 作用：收到内存警告时调用
 注解：
    当应用可用内存不足 内存警告时，会调用此方法，在这个方法中，应该尽量去清理可能释放的内存。如果实在不行，可能会被强行退出应用。
 */
-(void)applicationDidReceiveMemoryWarning:(UIApplication *)application;

/**
 作用：打开网址调用
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options NS_AVAILABLE_IOS(9_0);

```


#pragma mark -app生命周期
```objc
程序入口：进入main函数，初始话UIApplication对象，设置AppDelegate为函数的代理

- - -
场景方法调用示例：
程序启动
didFinishLaunchingWithOptions:  程序启动加载完成时调用
    创建window窗口，显示窗口：self.window、makeKeyAndVisible
applicationDidBecomeActive:     程序获取焦点

程序进入后台（按下 Command + H + SHIFT）
applicationWillResignActive:    程序将要失去焦点时调用
applicationDidEnterBackground:  程序进入到后台时调用

程序进入前台（从后台重新点击 进入程序）
applicationWillEnterForeground: 程序进入到前台时调用
applicationDidBecomeActive:     程序获取焦点

程序退出（杀死）
applicationWillResignActive:    程序将要失去焦点时调用
applicationDidEnterBackground:  程序进入到后台时调用
applicationWillTerminate:       程序退出的时候调用

模拟内存警告（选择模拟器的Simulate Memory Warning）
applicationDidReceiveMemoryWarning: 内存不足，系统内存警告
```
![app生命周期](https://upload-images.jianshu.io/upload_images/2230763-03ca1ff2347077f3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


#pragma mark -UIApplication通知方法
```objc
/**
 作用：当客户端注册远程通知时调用
    如果成功，则回调第一个didRegister，客户端把deviceToken取出来发给服务端，push消息的时候要用。
    如果失败了，则回调第二个didFailToRegister，可以从error参数中看一下失败原因。
 */
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken NS_AVAILABLE_IOS(3_0);
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error NS_AVAILABLE_IOS(3_0);

/**
 作用：收到远程通知时(不会弹出系统通知界面)调用
    当应用在后台状态时，点击push消息启动应用，也会回调这个方法。
    当应用完全没有启动时，点击push消息启动应用，就不会回调这个方法。
 */
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo NS_DEPRECATED_IOS(3_0, 10_0);


/**
 作用：当应用收到本地通知时会调用
    如果在前台运行状态直接调用
    如果在后台状态，点击通知启动时，也会回调这个方法
    当应用完全没有启动时，点击push消息启动应用，就不会回调这个方法。
 */
- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification NS_DEPRECATED_IOS(4_0, 10_0);

- - -
 注解：注册远程通知使用如下方法：
    7.0及其以下版本的系统
    UIRemoteNotificationType type = UIRemoteNotificationTypeBadge|UIRemoteNotificationTypeAlert|UIRemoteNotificationTypeSound;
    [application registerForRemoteNotificationTypes:type];

    8.0及其以上版本的系统
    UIUserNotificationSettings *setting = [UIUserNotificationSettings settingsForTypes: (UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert) categories:nil];
    [application registerUserNotificationSettings:setting];
 */
```


#pragma mark - UIWindow窗体
#pragma mark -应用程序的启动原理
```objc
//  main.m
#import <UIKit/UIKit.h>
#import "AppDelegate.h"

int main(int argc, char * argv[]) {
    @autoreleasepool {
        参数12：argc和argv 参数是为了与C语言保持一致
        参数3：UIApplication类名或子类的名称，指定为nil = 默认为@"UIApplication"
        参数4：UIApplication代理的代理名称
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
    UIApplicationMain(int argc, char *argv[], NSString *principalClassName, NSString *delegateClassName);
}


- - -
 1、应用程序的启动原理
    1.执行Main.m
    2.执行UIApplication main函数.
    3.创建AppDelegate代理对象，并设置UIApplication对象的代理
    4.开启主运行循环，保证程序一直运行 (其实就是死循环：保证应用程序不退出)
    5.加载info.plist.配置文件，判断一下info.plist文件当中有没有指定main.storyboard；如果有就去加载main.storyboard，如果没有那么程序就加载完毕，在程序加载完毕时要自己手动去创建窗口
```

#pragma mark -手动创建窗口
```objc
 在程序启动完成Application代理方法 didFinishLaunchingWithOptions: 中
    1.创建窗口（系统默认定义了window strong强引用对象）
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    2.设置窗口的根控制器
    self.window.rootViewController = [[Vc alloc] init];
    3.显示窗口
    [self.window makeKeyAndVisible];
 
 实现原理：[self.window makeKeyAndVisible]
    1.让窗口成为显示状态.
        窗口默认是隐藏的.hidden = yes.
        底层做的事件就是:self.window.hidden = NO;
    2.把控制器的View添加到窗口上面.
        [self.window addSubView:rootVC.view];
    3.把当前窗口设置成应用程序的主窗口
        application.keyWindow 获得应用程序的主窗口.
```

#pragma mark - iPhone尺寸

```objc
 设备                     分辨率             PPI     状态栏高度    导航栏高度    标签栏高度
 iPhone6 plus设计版        1242×2208 px    401PPI     60px         66pt        73pt
 iPhone6 plus放大版        1125×2001 px    401PPI     54px         66pt        73pt
 iPhone6 plus物理版        1080×1920 px    401PPI     54px         66pt        73pt
 iPhone6                  750×1334 px     326PPI     40px         44pt        49pt
 iPhone5 - 5C - 5S        640×1136 px     326PPI     40px         44pt        49pt
 iPhone4 - 4S             640×960 px      326PPI     40px         44pt        49pt
 
 
 
 启动图片
 LaunchImage-320×480-iphone.png
 LaunchImage-640×960-ip4.png
 LaunchImage-640×1136-ip5.png
 LaunchImage-750×1334-ip6.png
 LaunchImage-1242×2208-ip6p.png
```




 
























