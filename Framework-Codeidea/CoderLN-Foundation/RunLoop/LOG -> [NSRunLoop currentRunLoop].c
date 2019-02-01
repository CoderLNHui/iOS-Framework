/**
 Public|Jshu_不知名开发者
 
 在应用程序刚刚启动时打印 `currentRunLoop`可以看到系统默认注册了很多个`Observer`，NSLog(@"%@",[NSRunLoop currentRunLoop]);
 其中两个是关于AutoreleasePool的。


<CFRunLoop 0x6040001ef800 [0x108b60c80]>{wakeup port = 0x210b, stopped = false, ignoreWakeUps = false,
    current mode = kCFRunLoopDefaultMode,
    common modes = <CFBasicHash 0x604000241590 [0x108b60c80]>{type = mutable set, count = 2,
        entries =>
        0 : <CFString 0x10a886e88 [0x108b60c80]>{contents = "UITrackingRunLoopMode"}
        2 : <CFString 0x108b36818 [0x108b60c80]>{contents = "kCFRunLoopDefaultMode"}
    }
    ,
    common mode items = <CFBasicHash 0x604000241650 [0x108b60c80]>{type = mutable set, count = 13,
        entries =>
        0 : <CFRunLoopSource 0x60000016f240 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x0, callout = PurpleEventSignalCallback (0x10e95475a)}}
        1 : <CFRunLoopObserver 0x604000126ea0 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2000000, callout = _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv (0x1094bd4ce), context = <CFRunLoopObserver context 0x0>}
        6 : <CFRunLoopObserver 0x604000126ae0 [0x108b60c80]>{valid = Yes, activities = 0x20, repeats = Yes, order = 0, callout = _UIGestureRecognizerUpdateObserver (0x109caa6b3), context = <CFRunLoopObserver context 0x6040000dc7e0>}
        7 : <CFRunLoopSource 0x60000016f9c0 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x60400014d7e0, callout = __handleEventQueue (0x10a021bb2)}}
        8 : <CFRunLoopSource 0x60000016f180 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 1, info = 0x2f03, callout = PurpleEventCallback (0x10e956bf7)}}
        13 : <CFRunLoopObserver 0x600000126f40 [0x108b60c80]>{valid = Yes, activities = 0x1, repeats = Yes, order = -2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1096c4d92), context = <CFArray 0x600000258db0 [0x108b60c80]>{type = mutable-small, count = 1, values = (
                                                                                                                                                                                                                                                                                             0 : <0x7f9f62003048>
                                                                                                                                                                                                                                                                                             )}}
        14 : <CFRunLoopObserver 0x600000126ea0 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 1999000, callout = _beforeCACommitHandler (0x1096f3da1), context = <CFRunLoopObserver context 0x7f9f61f00a70>}
        15 : <CFRunLoopObserver 0x600000126e00 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2001000, callout = _afterCACommitHandler (0x1096f3e1c), context = <CFRunLoopObserver context 0x7f9f61f00a70>}
        16 : <CFRunLoopObserver 0x600000126d60 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1096c4d92), context = <CFArray 0x600000258db0 [0x108b60c80]>{type = mutable-small, count = 1, values = (
                                                                                                                                                                                                                                                                                             0 : <0x7f9f62003048>
                                                                                                                                                                                                                                                                                             )}}
        17 : <CFRunLoopSource 0x60000016fd80 [0x108b60c80]>{signalled = No, valid = Yes, order = -2, context = <CFRunLoopSource context>{version = 0, info = 0x604000241560, callout = __handleHIDEventFetcherDrain (0x10a021bbe)}}
        18 : <CFRunLoopSource 0x60000016fe40 [0x108b60c80]>{signalled = No, valid = Yes, order = 0, context = <CFRunLoopSource MIG Server> {port = 14091, subsystem = 0x10a83dfe8, context = 0x0}}
        19 : <CFRunLoopSource 0x60400016fb40 [0x108b60c80]>{signalled = Yes, valid = Yes, order = 0, context = <CFRunLoopSource context>{version = 0, info = 0x6040000b8900, callout = FBSSerialQueueRunLoopSourceHandler (0x1100e782f)}}
        20 : <CFRunLoopSource 0x6000001729c0 [0x108b60c80]>{signalled = No, valid = Yes, order = 0, context = <CFRunLoopSource MIG Server> {port = 22531, subsystem = 0x10a858668, context = 0x6040002263a0}}
    }
    ,
    modes = <CFBasicHash 0x6040002415f0 [0x108b60c80]>{type = mutable set, count = 4,
        entries =>
        2 : <CFRunLoopMode 0x6040001927c0 [0x108b60c80]>{name = UITrackingRunLoopMode, port set = 0x5103, queue = 0x60400014d940, source = 0x604000192890 (not fired), timer port = 0x2d03,
            sources0 = <CFBasicHash 0x60400004b9d0 [0x108b60c80]>{type = mutable set, count = 4,
                entries =>
                0 : <CFRunLoopSource 0x60000016f240 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x0, callout = PurpleEventSignalCallback (0x10e95475a)}}
                1 : <CFRunLoopSource 0x60000016fd80 [0x108b60c80]>{signalled = No, valid = Yes, order = -2, context = <CFRunLoopSource context>{version = 0, info = 0x604000241560, callout = __handleHIDEventFetcherDrain (0x10a021bbe)}}
                3 : <CFRunLoopSource 0x60400016fb40 [0x108b60c80]>{signalled = Yes, valid = Yes, order = 0, context = <CFRunLoopSource context>{version = 0, info = 0x6040000b8900, callout = FBSSerialQueueRunLoopSourceHandler (0x1100e782f)}}
                4 : <CFRunLoopSource 0x60000016f9c0 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x60400014d7e0, callout = __handleEventQueue (0x10a021bb2)}}
            }
            ,
            sources1 = <CFBasicHash 0x60400004bfa0 [0x108b60c80]>{type = mutable set, count = 3,
                entries =>
                0 : <CFRunLoopSource 0x60000016fe40 [0x108b60c80]>{signalled = No, valid = Yes, order = 0, context = <CFRunLoopSource MIG Server> {port = 14091, subsystem = 0x10a83dfe8, context = 0x0}}
                1 : <CFRunLoopSource 0x6000001729c0 [0x108b60c80]>{signalled = No, valid = Yes, order = 0, context = <CFRunLoopSource MIG Server> {port = 22531, subsystem = 0x10a858668, context = 0x6040002263a0}}
                2 : <CFRunLoopSource 0x60000016f180 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 1, info = 0x2f03, callout = PurpleEventCallback (0x10e956bf7)}}
            }
            ,
            observers = (
                         1."<CFRunLoopObserver 0x600000126f40 [0x108b60c80]>{valid = Yes, activities = 0x1, repeats = Yes, order = -2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1096c4d92), context = <CFArray 0x600000258db0 [0x108b60c80]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7f9f62003048>\n)}}",
                         2."<CFRunLoopObserver 0x604000126ae0 [0x108b60c80]>{valid = Yes, activities = 0x20, repeats = Yes, order = 0, callout = _UIGestureRecognizerUpdateObserver (0x109caa6b3), context = <CFRunLoopObserver context 0x6040000dc7e0>}",
                         3."<CFRunLoopObserver 0x600000126ea0 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 1999000, callout = _beforeCACommitHandler (0x1096f3da1), context = <CFRunLoopObserver context 0x7f9f61f00a70>}",
                         4."<CFRunLoopObserver 0x604000126ea0 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2000000, callout = _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv (0x1094bd4ce), context = <CFRunLoopObserver context 0x0>}",
                         5."<CFRunLoopObserver 0x600000126e00 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2001000, callout = _afterCACommitHandler (0x1096f3e1c), context = <CFRunLoopObserver context 0x7f9f61f00a70>}",
                         6."<CFRunLoopObserver 0x600000126d60 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1096c4d92), context = <CFArray 0x600000258db0 [0x108b60c80]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7f9f62003048>\n)}}"
                         ),
            timers = (null),
            currently 561805773 (26393322068960) / soft deadline in: 1.84467177e+10 sec (@ -1) / hard deadline in: 1.84467177e+10 sec (@ -1)
        },
        
        3 : <CFRunLoopMode 0x604000192960 [0x108b60c80]>{name = GSEventReceiveRunLoopMode, port set = 0x2e03, queue = 0x60400014d890, source = 0x6000001926f0 (not fired), timer port = 0x4f03,
            sources0 = <CFBasicHash 0x6040002414a0 [0x108b60c80]>{type = mutable set, count = 1,
                entries =>
                0 : <CFRunLoopSource 0x60000016f240 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x0, callout = PurpleEventSignalCallback (0x10e95475a)}}
            }
            ,
            sources1 = <CFBasicHash 0x604000241470 [0x108b60c80]>{type = mutable set, count = 1,
                entries =>
                2 : <CFRunLoopSource 0x60000016f0c0 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 1, info = 0x2f03, callout = PurpleEventCallback (0x10e956bf7)}}
            }
            ,
            observers = (null),
            timers = (null),
            currently 561805773 (26393323363984) / soft deadline in: 1.84467177e+10 sec (@ -1) / hard deadline in: 1.84467177e+10 sec (@ -1)
        },
        
        4 : <CFRunLoopMode 0x6040001923b0 [0x108b60c80]>{name = kCFRunLoopDefaultMode, port set = 0x1c03, queue = 0x60400014daa0, source = 0x604000192480 (not fired), timer port = 0x1e03,
            sources0 = <CFBasicHash 0x6000002584e0 [0x108b60c80]>{type = mutable set, count = 4,
                entries =>
                0 : <CFRunLoopSource 0x60000016f240 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x0, callout = PurpleEventSignalCallback (0x10e95475a)}}
                1 : <CFRunLoopSource 0x60000016fd80 [0x108b60c80]>{signalled = No, valid = Yes, order = -2, context = <CFRunLoopSource context>{version = 0, info = 0x604000241560, callout = __handleHIDEventFetcherDrain (0x10a021bbe)}}
                3 : <CFRunLoopSource 0x60400016fb40 [0x108b60c80]>{signalled = Yes, valid = Yes, order = 0, context = <CFRunLoopSource context>{version = 0, info = 0x6040000b8900, callout = FBSSerialQueueRunLoopSourceHandler (0x1100e782f)}}
                4 : <CFRunLoopSource 0x60000016f9c0 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 0, info = 0x60400014d7e0, callout = __handleEventQueue (0x10a021bb2)}}
            }
            ,
            sources1 = <CFBasicHash 0x600000258570 [0x108b60c80]>{type = mutable set, count = 3,
                entries =>
                0 : <CFRunLoopSource 0x60000016fe40 [0x108b60c80]>{signalled = No, valid = Yes, order = 0, context = <CFRunLoopSource MIG Server> {port = 14091, subsystem = 0x10a83dfe8, context = 0x0}}
                1 : <CFRunLoopSource 0x6000001729c0 [0x108b60c80]>{signalled = No, valid = Yes, order = 0, context = <CFRunLoopSource MIG Server> {port = 22531, subsystem = 0x10a858668, context = 0x6040002263a0}}
                2 : <CFRunLoopSource 0x60000016f180 [0x108b60c80]>{signalled = No, valid = Yes, order = -1, context = <CFRunLoopSource context>{version = 1, info = 0x2f03, callout = PurpleEventCallback (0x10e956bf7)}}
            }
            ,
            observers = (
                         "<CFRunLoopObserver 0x600000126f40 [0x108b60c80]>{valid = Yes, activities = 0x1, repeats = Yes, order = -2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1096c4d92), context = <CFArray 0x600000258db0 [0x108b60c80]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7f9f62003048>\n)}}",
                         "<CFRunLoopObserver 0x604000126ae0 [0x108b60c80]>{valid = Yes, activities = 0x20, repeats = Yes, order = 0, callout = _UIGestureRecognizerUpdateObserver (0x109caa6b3), context = <CFRunLoopObserver context 0x6040000dc7e0>}",
                         "<CFRunLoopObserver 0x600000126ea0 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 1999000, callout = _beforeCACommitHandler (0x1096f3da1), context = <CFRunLoopObserver context 0x7f9f61f00a70>}",
                         "<CFRunLoopObserver 0x604000126ea0 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2000000, callout = _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv (0x1094bd4ce), context = <CFRunLoopObserver context 0x0>}",
                         "<CFRunLoopObserver 0x600000126e00 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2001000, callout = _afterCACommitHandler (0x1096f3e1c), context = <CFRunLoopObserver context 0x7f9f61f00a70>}",
                         "<CFRunLoopObserver 0x600000126d60 [0x108b60c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler (0x1096c4d92), context = <CFArray 0x600000258db0 [0x108b60c80]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7f9f62003048>\n)}}"
                         ),
            timers = <CFArray 0x6040000b8960 [0x108b60c80]>{type = mutable-small, count = 1, values = (
                                                                                                       0 : <CFRunLoopTimer 0x60400016ef40 [0x108b60c80]>{valid = Yes, firing = No, interval = 0, tolerance = 0, next fire date = 561805774 (1.34173799 @ 26394667220059), callout = (Delayed Perform) UIApplication _accessibilitySetUpQuickSpeak (0x10756a849 / 0x109bb531b) (/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/Library/CoreSimulator/Profiles/Runtimes/iOS.simruntime/Contents/Resources/RuntimeRoot/System/Library/Frameworks/UIKit.framework/UIKit), context = <CFRunLoopTimer context 0x604000277000>}
                                                                                                       )},
            currently 561805773 (26393323402674) / soft deadline in: 1.34381737 sec (@ 26394667220059) / hard deadline in: 1.34381734 sec (@ 26394667220059)
        },
        
        5 : <CFRunLoopMode 0x6000001927c0 [0x108b60c80]>{name = kCFRunLoopCommonModes, port set = 0x4813, queue = 0x60000014e440, source = 0x600000192a30 (not fired), timer port = 0x3c07,
            sources0 = (null),
            sources1 = (null),
            observers = (null),
            timers = (null),
            currently 561805773 (26393325516974) / soft deadline in: 1.84467177e+10 sec (@ -1) / hard deadline in: 1.84467177e+10 sec (@ -1)
        },
        
    }
    }

 */


#pragma mark - 程序启动后打印currentRunLoop
/**
 在应用程序刚刚启动时打印 `currentRunLoop`可以看到系统默认注册了很多个`Observer`，其中两个是关于AutoreleasePool的。
 NSLog(@"%@",[NSRunLoop currentRunLoop]);
 
 runloopModes = (
    系统默认注册5种运行模式，常用3种（Defaults默认、Tracking界面追踪、CommonModes占位模式,上两者结合）
 )
 
 摘录一部分
 observers = (
     1."<CFRunLoopObserver 0x60400012c080 [0x1046f8c80]>{valid = Yes, activities = 0x1, repeats = Yes, order = -2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler【自动释放池-监听RunLoop的进入】 (0x105497d92), context = <CFArray 0x604000251400 [0x1046f8c80]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7fdb35002048>\n)}}",
     2."<CFRunLoopObserver 0x60000012ba40 [0x1046f8c80]>{valid = Yes, activities = 0x20, repeats = Yes, order = 0, callout = _UIGestureRecognizerUpdateObserver【手势识别】 (0x105a7d6b3), context = <CFRunLoopObserver context 0x6000000d2e50>}",
     3."<CFRunLoopObserver 0x60400012c120 [0x1046f8c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 1999000, callout = _beforeCACommitHandler【】 (0x1054c6da1), context = <CFRunLoopObserver context 0x7fdb33e00d60>}",
     4."<CFRunLoopObserver 0x60400012bd60 [0x1046f8c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2000000, callout = _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv【监听UI界面更新】 (0x1052904ce), context = <CFRunLoopObserver context 0x0>}",
     5."<CFRunLoopObserver 0x60400012bfe0 [0x1046f8c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2001000, callout = _afterCACommitHandler【】 (0x1054c6e1c), context = <CFRunLoopObserver context 0x7fdb33e00d60>}",
     6."<CFRunLoopObserver 0x60400012bf40 [0x1046f8c80]>{valid = Yes, activities = 0xa0, repeats = Yes, order = 2147483647, callout = _wrapRunLoopWithAutoreleasePoolHandler【自动释放池-监听RunLoop的进入休眠和即将退出】 (0x105497d92), context = <CFArray 0x604000251400 [0x1046f8c80]>{type = mutable-small, count = 1, values = (\n\t0 : <0x7fdb35002048>\n)}}"
 ),
 1.自动释放池
     第一个 Observer 会监听 RunLoop 的进入，它会回调objc_autoreleasePoolPush() 向当前的 AutoreleasePoolPage 增加一个标志对象创建自动释放池。这个 Observer 的 order(命令/顺序) 是 -2147483647 优先级最高，确保发生在所有回调操作之前。
 
 2.手势识别
     当上面的 _UIApplicationHandleEventQueue() 识别了一个手势时，其首先会调用 Cancel 将当前的 touchesBegin/Move/End 系列回调打断。随后系统将对应的 UIGestureRecognizer 标记为待处理。
     苹果注册了一个 Observer 监测 BeforeWaiting (Loop即将进入休眠) 事件，这个Observer的回调函数是 _UIGestureRecognizerUpdateObserver()，其内部会获取所有刚被标记为待处理的 GestureRecognizer，并执行GestureRecognizer的回调。
     当有 UIGestureRecognizer 的变化(创建/销毁/状态改变)时，这个回调都会进行相应处理。

 4.UI界面更新
     如果打印App启动之后的主线程RunLoop可以发现另外一个callout为 _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv 的 Observer，这个是专门负责监听UI变化后的更新，比如修改了frame、调整了UI层级（UIView/CALayer）或者手动设置了setNeedsDisplay/setNeedsLayout 之后就会将这些操作提交到全局容器。而这个Observer监听了主线程RunLoop的即将进入休眠和退出状态，一旦进入这两种状态则会遍历所有的UI更新并提交进行实际绘制更新。
     苹果注册了一个 Observer 监听 BeforeWaiting(即将进入休眠) 和 Exit (即将退出Loop) 事件，回调去执行一个很长的函数：
     _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv()。这个函数里会遍历所有待处理的 UIView/CAlayer 以执行实际的绘制和调整，并更新 UI 界面。
 
     通常情况下这种方式是完美的，因为除了系统的更新，还可以利用 setNeedsDisplay 等方法手动触发下一次 RunLoop 运行的更新。但是如果当前正在执行大量的逻辑运算可能UI的更新就会比较卡，因此facebook 推出了 AsyncDisplayKit（用于保持界面流畅性的框架） 来解决这个问题。AsyncDisplayKit 其实是将UI排版和绘制运算尽可能放到后台，将UI的最终更新操作放到主线程（这一步也必须在主线程完成），同时提供一套类 UIView 或 CALayer 的相关属性，尽可能保证开发者的开发习惯。这个过程中 AsyncDisplayKit 在主线程 RunLoop 中增加了一个Observer 监听即将进入休眠和退出 RunLoop 两种状态，收到回调时遍历队列中的待处理任务一一执行。
     https://github.com/facebook/AsyncDisplayKit

 6.自动释放池
     第二个 Observer 会监听 RunLoop 的进入休眠和即将退出 RunLoop 两种状态，在即将进入休眠时会调用 objc_autoreleasePoolPop() 和 objc_autoreleasePoolPush() 根据情况从最新加入的对象一直往前清理直到遇到标志对象。而在即将退出 RunLoop 时会调用 objc_autoreleasePoolPop() 释放自动释放池内对象。这个Observer 的 order 是 2147483647 ，优先级最低，确保发生在所有回调操作之后。
 */
    
    
    


