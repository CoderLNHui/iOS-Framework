/*
 * UIApplication.m
 *
 * UIKit (c) 2005-2017
 */


#####用户对app操作对应调用流程
```objc
# ApplicationDelegate方法 和 ApplicationState应用状态
1、应用启动加载完成，并进行初始化时调用该方法: didFinishLaunchingWithOptions:
2、应用进入前台并成为活跃状态时调用: applicationDidBecomeActive:
3、应用从活跃状态进入到非活跃状态时调用: applicationWillResignActive :
4、应用从前台进入到后台时调用: applicationDidEnterBackground:
5、应用从后台进入到前台时调用: appplicationWillEnterForeground:
6、应用被终止退出时调用: applicationWillTerminate:
7、应用收到内存警告时调用: applicationDidReceiveMemoryWarning:
8、应用的状态
    UIApplicationStateActive,// 前台活跃状态。处于前台，能接受事件处理。
    UIApplicationStateInactive,// 前台非活跃状态。处于前台，但是不能接受事件处理。
    UIApplicationStateBackground// 后台状态。进入后台，如果有可执行代码，会执行代码，代码执行完毕，程序进行挂起。

- - -
# 程序入口：进入UIApplicationMain函数，初始话UIApplication对象，设置AppDelegate为函数的代理

# 场景1:程序启动完成到可以接收事件处理
调用 didFinishLaunchingWithOptions:（应用启动加载完成）方法，  发送 UIApplicationDidFinishLaunchingNotification 通知;
调用 applicationDidBecomeActive:（进入前台并成为活跃状态）方法，发送 UIApplicationDidBecomeActiveNOtification 通知；

# 场景2:按Home键,退到后台，没有退出程序
调用 applicationWillResignActive:（从活跃状态进入到非活跃状态）方法，发送 UIApplicationWillResignActiveNotification 通知;
调用 applicationDidEnterBackground:（进入到后台）方法，           发送 UIApplicationDidEnterBackgroundNotification 通知;


# 场景3:按Home键,退到后台且退出程序
调用 applicationWillResignActive:（从活跃状态进入到非活跃状态）方法，发送 UIApplicationWillResignActiveNotification 通知;
调用 applicationDidEnterBackground:（进入到后台）方法，           发送 UIApplicationDidEnterBackgroundNotification 通知;
调用 applicationWillTerminate:（被终止退出）方法，                发送 UIApplicationWillTerminateNotification 通知;
注解：默认的情况下，程序进入后台是不会终止程序的；如果要做到可以退出程序，到info.plist文件修改一下的值:
找到Application does not run in backgroud设置为yes，在文件中保存的键应该是UIApplicationExitsOnSuspend设置为Yes。



# 场景4:后台挂起的程序重新运行
调用 applicationWillEnterForeground:（进入到前台）方法，       发送 UIApplicationWillEnterForegroundNotification 通知;
调用 applicationDidBecomeActive:（进入前台并成为活跃状态）方法， 发送 UIApplicationDidBecomeActiveNotification 通知;
注解：didFinishLaunchingWithOptions:这个方法只会在程序初始化的时才会被调用，而且只调用一次，所以这里后台进入前台不会调用。

# 场景5:出现内存警告
调用 applicationDidReceiveMemoryWarning:（出现内存警告）方法，  发送 UIApplicationDidReceiveMemoryWarningNotification 通知;
注解：实现内存警告有三种方法。
第一种:模拟器菜单：Hardware —> Simulate Memory Warning
第二种:用程序的方法实现，只需要一句代码：
CFNotificationCenterPostNotification(CFNotificationCenterGetDarwinNotifyCenter(), (CFStringRef)@"UISimulatedMemoryWarningNotification",NULL,NULL,true);
第三种:这是私有的 API 方法:
[[UIApplication sharedApplication] performSelector:@selector(_performMemoryWarning)];
```
