//
//  Foundation
//
//  Created by 白开水ln on 16/-/-.
//  https://custompbwaters.github.io    http://www.jianshu.com/p/e5b995ecf44d
//


//------------- NSNotification & NSNotificationCenter & NSNotificationQueue 官方简明概念 -----------//
//

/*

NSNotification是方便NSNotificationCenter 广播到其他对象时的封装对象，简单讲即通知中心对通知调度表中的对象广播时发送NSNotification对象。
NSNotification对象(称为通知)包含名称、object 和一个可选字典三个属性，名称是用来标识通知的标记（一般为常量字符串），object是任意想要携带的对象（通常为发送者自己 或为nil），字典用来存储发送通知时附带的信息（可为nil）。NSNotification 对象是不可变的对象。

 
 NSNotificationCenter对象(通知中心) 是 Foundation 框架的一个子系统，提供了在程序中广播消息的机制。通过［NSNotificationCenter defaultCenter］获取引用总的通知中心，可以在不同类之间通信的时候使用。
 在通知中心注册观察者，发送者使用通知中心广播时，以NSNotification的name和object来确定需要发送给哪个观察者。为保证观察者能接收到通知，所以应先向通知中心注册观察者，接着再发送通知这样才能在通知中心调度表中查找到相应观察者进行通知。
 
 
 
 NSNotificationQueue 通知队列，更像是通知中心的缓冲区，用来管理多个通知的调用。通知队列通常以先进先出（FIFO）顺序管理通知。当一个通知上升到队列的前面时，队列就将它发送给通知中心(NSNotificationCenter)，通知中心随后将它派发给所有注册为观察者的对象
 

*/





//--------------------------- NSNotificatinonCenter 实现原理 ------------------------------//
//

/**
 1.NSNotificatinonCenter是使用观察者模式来实现的用于跨层传递消息，用来降低耦合度。
 
 2.NSNotificatinonCenter用来管理通知，将观察者注册到NSNotificatinonCenter的通知调度表中，然后发送通知时利用标识符name和object识别出调度表中的观察者，然后调用相应的观察者的方法，即传递消息（在Objective-C中对象调用方法，就是传递消息，消息有name或者selector，可以接受参数，而且可能有返回值），如果是基于block创建的通知就调用NSNotification的block。
 */






//--------------------------- 实战使用 ------------------------------//
//

/*
 // 基本使用：
@property (nonatomic, weak) id observe;
// 1.注册观察者（添加监听）
_observe = [[NSNotificationCenter defaultCenter] addObserverForName:@"note" object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
    NSLog(@"我是block方式注册观察者");
}];
// 2.发送通知
[[NSNotificationCenter defaultCenter] postNotificationName:@"note" object:nil];


总结：这个方法的优点在于添加观察者的操作与回调处理操作的代码更加紧凑，不需要拼命滚动鼠标就能直接找到处理代码，简单直观。个人比较喜欢。

*/

/**
// 通知在多线程中使用

第二种注册观察者方式，以下代码我们将验证这个结论：
接收通知代码 由 发出通知线程决定，即观察者接收到通知后执行任务的代码在发送通知的线程中执行（指定操作队列除外）

// 指定操作队列 [NSOperationQueue mainQueue]
// _observe = [[NSNotificationCenter defaultCenter] addObserverForName:@"note" object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
// 1.注册观察者（添加监听）
_observe = [[NSNotificationCenter defaultCenter] addObserverForName:@"note" object:nil queue:nil usingBlock:^(NSNotification * _Nonnull note) {
    // 只要监听到通知 就会调用
    NSLog(@"%@",[NSThread currentThread]);
    NSLog(@"我是block方式注册观察者");
}];
// 2.发送通知（主线程）
[[NSNotificationCenter defaultCenter] postNotificationName:@"note" object:nil];
// 发送通知（异步线程）
dispatch_async(dispatch_get_global_queue(0, 0), ^{
    [[NSNotificationCenter defaultCenter] postNotificationName:@"note" object:nil];
});


发送通知（主线程）打印输出：
2016-03-28 18:17:08.587 03-通知补充[11305:421194] <NSThread: 0x608000072940>{number = 1, name = main}
2016-03-28 18:17:08.587 03-通知补充[11305:421194] 我是block方式注册观察者
    
发送通知（异步线程）打印输出：
2016-03-28 18:24:56.248 03-通知补充[11503:431482] <NSThread: 0x60000007ec40>{number = 3, name = (null)}
2016-03-28 18:24:56.248 03-通知补充[11503:431482] 我是block方式注册观察者

注册观察者,指定操作队列（不管发送通知在那个线程都按指定操作队列执行）
2016-03-28 18:27:04.567 03-通知补充[11555:433722] <NSThread: 0x600000073e40>{number = 1, name = main}
2016-03-28 18:27:04.567 03-通知补充[11555:433722] 我是block方式注册观察者

*/







//--------------------------- 相关总结 ------------------------------//
//

/**
 1.通知中心的使用流程
 获取通知中心对象后，我们就可以使用它来处理通知相关的操作了，包括注册观察者、发送通知 和 移除观察者。
 
 
 2.获取NSNotificationCenter的方法只有一种，即[NSNotificationCenter defaultCenter]，并且NSNotificationCenter是一个单例模式，一旦创建，这个通知中心的对象会一直存在于一个应用的生命周期。
 
 3.通知的发送与处理是同步的，在某个地方post一个消息时，会等到所有观察者对象执行完处理操作后，才回到post的地方，继续执行后面的代码。
 
 
 4.在我们的应用程序中，两个对象之间如何通信。根据具体应用场景优先选择哪一种通信方式。
 对象之间的通信方式主要有以下几种：
 
 直接方法调用
 Target-Action事件
 Delegate代理
 block回调
 KVO监听
 NSNotification通知
 
 */



//--------------------------- 相关实用文章推荐 ------------------------------//
//

// - [iOS模式详解—「NSNotification通知」]
// https://custompbwaters.github.io/iOS%20UI/iOS模式详解—NSNotification通知.html


















