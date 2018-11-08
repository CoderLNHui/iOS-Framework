/*
 * UIApplication.m
 *
 * UIKit (c) 2005-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#pragma mark - 程序代理方法和程序状态
/**
 1、应用程序启动，并进行初始化时候调用该方法: aaaplication:didFimnishLanuchingWithOptions:
 2、应用进入前台并处于活动状态时候调用: applicationDidBecomeActive:
 3、应用从活动状态进入到非活动状态: applicationWillResignActive :
 4、应用进入到后台时候调用的方法: applicationDidEnterBackground:
 5、应用进入到前台时候调用的方法: appplicationWillEnterForeground:
 6、应用被终止退出的状态: applicationWillTeminate:
 7、应用出现内存警告: applicationDidReceiveMemoryWarning:
 
 UIApplicationStateActive,// 前台活动状态。处于前台，能接受事件处理。
 UIApplicationStateInactive,// 前台非活动状态。处于前台，但是不能接受事件处理。
 UIApplicationStateBackground// 后台状态。进入后台，如果有可执行代码，会执行代码，代码执行完毕，程序进行挂起。
 */


#pragma mark - 用户对程序操作对应调用流程
#pragma mark -1.程序启动完成到可以接收事件处理
/**
 场景: 点击应用图标时，会经历三个状态: 没有运行（Not Running）------->没有激活（Inactive） ------>激活（Active）
 
 过程1: 没有运行（Not Running）------->没有激活（Inactive）；
     这个过程会调用aaaplication:didFinishLaunchingWithOptions:方法，发出UIApplicationDidFinishLaunchingNotification通知；
 
 过程2: 没有激活（Inactive） ------>激活（Active）
     这个过程会调用applicationDidBecomeActive:方法，发出UIApplicationDidBecomeActiveNOtification通知；
 */


#pragma mark -2.按Home键
/**
 场景: 点击Home键---程序挂起或者进入后台；（一种是退到后台，没有退出程序；一种是退到后台，且退出程序）
 
 情况1: 如果可以在后台运行或者挂起（默认情况）会经历: Active-->Inactive-->Background-->Suspended，注意: 挂起状态会占用内存；
     Active-->Inactive
     调用 applicationWillResignActive:  发送: UIApplicationWillResignActiveNotification
     Background-->Suspended
     调用 applicationDidEnterBackground:  发送: UIApplicationDidEnterBackgroundNotification
 
 
 情况2: 点击home键之后，进入后台直接退出程序；Active-->Inactive-->Background-->Suspended-->Not Running
 
     Suspended-->Not Running
     调用 applicationWillTerminate:  发送: UIApplicationWillTerminateNotification
 
     注意: 默认的情况下，程序进入后台是不会终止程序的；如果要做到可以退出程序，到info.plist文件修改一下的值:
     找到Application does not run in backgroud设置为yes，在文件中保存的键应该是UIApplicationExitsOnSuspend设置为Yes。
 */


#pragma mark -3.后台挂起的程序重新运行
/**
 场景: 挂起的程序重新运行: Suspended-->Background-->Inactive-->Active
 
 Background-->Inactive
 调用 applicationWillEnterForeground:  发送: UIApplicationWillEnterForegroundNotification
 Inactive-->Active
 调用 applicationDidBecomeActive:  发送: UIApplicationDidBecomeActiveNotification
 
 注意: application:didFinishLaunchingWithOptions:这个方法只会在程序初始化的时候才会被调用，而且只调用一次；
 所以这里不会调用didFinishLaunchingWithOptions这个方法；
 */

#pragma mark -4.出现内存警告
/**
 出现内存警告 
 applicationDidReceiveMemoryWarning: 发送: UIApplicationDidReceiveMemoryWarningNotification
 
 
 实现内存警告有三种方法。
 
 第一种:模拟器菜单：Hardware —> Simulate Memory Warning
 
 第二种:用程序的方法实现，只需要一句代码：
 
 CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFStringRef)@"UISimulatedMemoryWarningNotification",NULL,NULL,true);
 
 第三种:这是私有的 API 方法:
 
 SEL memoryWarningSel = @selector(_performMemoryWarning);
 if ([[UIApplication sharedApplication] respondsToSelector:memoryWarningSel]) {
 [[UIApplication sharedApplication] performSelector:memoryWarningSel];
 }else {
 NSLog(@"%@",@"Whoops UIApplication no loger responds to -_performMemoryWarning");
 }
 
 或者:
 
 iOS中使用代码模拟内存警告
 [[UIApplication sharedApplication] performSelector:@selector(_performMemoryWarning)];
 
 注意:最好只在测试的时候使用，发布到App Store的时候不要将上面的代码编译进去，使用这种没有文档化的方法有可能导致审核不通过，或者根本无法上传。
 */







































































































































































