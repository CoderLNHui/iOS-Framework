/*
 * NSURLSession.h
 *
 * Foundation (c) 2013-2016
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

/**
 NSURLSessionConfiguration 配置信息
 
 1.
 NSURLSessionConfiguration对象用于初始化NSURLSession对象。
 
 展开请求级别中与NSMutableURLRequest相关的可供选择的方案，我们可以看到NSURLSessionConfiguration对于会话如何产生请求，提供了相当多的控制和灵活性。从网络访问性能，到cookie，安全性，缓存策略，自定义协议，启动事件设置，以及用于移动设备优化的几个新属性，你会发现你一直在寻找的，正是NSURLSessionConfiguration。
 
 会话在初始化时复制它们的配置，NSURLSession有一个只读的配置属性，使得该配置对象上的变化对这个会话的政策无效。配置在初始化时被读取一次，之后都是不会变化的。
 
 
 2.
 －构造方法
 
 NSURLSessionConfiguration有三个类构造函数，这很好地说明了NSURLSession是为不同的用例而设计的。
 
 + "defaultSessionConfiguration"返回标准配置，这实际上与NSURLConnection的网络协议栈是一样的，具有相同的共享NSHTTPCookieStorage，共享NSURLCache和共享NSURLCredentialStorage。
 + "ephemeralSessionConfiguration"返回一个预设配置，没有持久性存储的缓存，Cookie或证书。这对于实现像"秘密浏览"功能的功能来说，是很理想的。
 + "backgroundSessionConfiguration"：独特之处在于，它会创建一个后台会话。后台会话不同于常规的，普通的会话，它甚至可以在应用程序挂起，退出，崩溃的情况下运行上传和下载任务。初始化时指定的标识符，被用于向任何可能在进程外恢复后台传输的守护进程提供上下文。
 
 想要查看更多关于后台会话的信息，可以查看WWDC Session 204: “What’s New with Multitasking”

 
 
 
 3.
 －NSURLSessionConfiguration的属性
 
 NSURLSessionConfiguration拥有20个属性。熟练掌握这些属性的用处，将使应用程序充分利用其网络环境。

 最重要的属性：
 # 替代 request 中的 forHTTPHeaderField 告诉服务器有关客户端的附加信息
 "HTTPAdditionalHeaders"指定了一组默认的可以设置出站请求的数据头。这对于跨会话共享信息，如内容类型，语言，用户代理，身份认证，是很有用的。
 
 
 
 
 
 
 4.
 # WebDav的身份验证
 NSString *userPasswordString = [NSString stringWithFormat:@"%@:%@", user, password];
 NSData * userPasswordData = [userPasswordString dataUsingEncoding:NSUTF8StringEncoding];
 NSString *base64EncodedCredential = [userPasswordData base64EncodedStringWithOptions:0];
 NSString *authString = [NSString stringWithFormat:@"Basic: %@", base64EncodedCredential];
 
 
 
 
 
 5.
 # 设置客户端类型
 NSString *userAgentString = @"iPhone AppleWebKit";
 
 configuration.HTTPAdditionalHeaders = @{@"Accept": @"application/json",
 @"Accept-Language": @"en",
 @"Authorization": authString,
 @"User-Agent": userAgentString};
 
 "networkServiceType（网络服务类型）"对标准的网络流量，网络电话，语音，视频，以及由一个后台进程使用的流量进行了区分。大多数应用程序都不需要设置这个
 
 "allowsCellularAccess（允许蜂窝访问）"和"discretionary（自行决定）"被用于节省通过蜂窝连接的带宽。建议在使用后台传输的时候，使用discretionary属性，而不是allowsCellularAccess属性，因为它会把WiFi和电源可用性考虑在内
 
 "timeoutIntervalForRequest"和"timeoutIntervalForResource"指定了请求以及该资源的超时时间间隔。许多开发人员试图使用timeoutInterval去限制发送请求的总时间，但这误会了timeoutInterval的意思：报文之间的时间。timeoutIntervalForResource实际上提供了整体超时的特性，这应该只用于后台传输，而不是用户实际上可能想要等待的任何东西
 
 "HTTPMaximumConnectionsPerHost"是 Foundation 框架中URL加载系统的一个新的配置选项。它曾经被用于NSURLConnection管理私人连接池。现在有了NSURLSession，开发者可以在需要时限制连接到特定主机的数量
 
 "HTTPShouldUsePipelining"也出现在NSMutableURLRequest，它可以被用于开启HTTP管道，这可以显着降低请求的加载时间，但是由于没有被服务器广泛支持，默认是禁用的
 
 "sessionSendsLaunchEvents" 是另一个新的属性，该属性指定该会话是否应该从后台启动
 
 "connectionProxyDictionary"指定了会话连接中的代理服务器。同样地，大多数面向消费者的应用程序都不需要代理，所以基本上不需要配置这个属性
 关于连接代理的更多信息可以在 CFProxySupport Reference 找到。
 
 "Cookie Policies"
 －"HTTPCookieStorage" 是被会话使用的cookie存储。默认情况下，NSHTTPCookieShorage的 + sharedHTTPCookieStorage会被使用，这与NSURLConnection是相同的
 －"HTTPCookieAcceptPolicy" 决定了该会话应该接受从服务器发出的cookie的条件
 －"HTTPShouldSetCookies" 指定了请求是否应该使用会话HTTPCookieStorage的cookie
 
 "Security Policies"
 　　URLCredentialStorage 是会话使用的证书存储。默认情况下，NSURLCredentialStorage 的+ sharedCredentialStorage 会被使用使用，这与NSURLConnection是相同的
 
 "TLSMaximumSupportedProtocol" 和 "TLSMinimumSupportedProtocol" 确定是否支持SSLProtocol版本的会话
 
 "Caching Policies"
 URLCache 是会话使用的缓存。默认情况下，NSURLCache 的 + sharedURLCache 会被使用，这与NSURLConnection是相同的
 requestCachePolicy 指定了一个请求的缓存响应应该在什么时候返回。这相当于NSURLRequest 的-cachePolicy方法
 
 "Custom Protocols"
 protocolClasses是注册NSURLProtocol类的特定会话数组

 */
