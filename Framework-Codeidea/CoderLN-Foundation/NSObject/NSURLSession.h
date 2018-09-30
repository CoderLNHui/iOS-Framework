/*
 * NSURLSession.h
 *
 * Foundation (c) 2013-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */



#import <Foundation/NSObject.h>
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSHTTPCookieStorage.h>
#import <Foundation/NSProgress.h>

#include <Security/SecureTransport.h>

@class NSString;
@class NSURL;
@class NSError;
@class NSArray<ObjectType>;
@class NSDictionary<KeyType, ObjectType>;
@class NSInputStream;
@class NSOutputStream;
@class NSData;
@class NSOperationQueue;

@class NSURLCache;
@class NSURLResponse;
@class NSHTTPURLResponse;
@class NSHTTPCookie;
@class NSCachedURLResponse;
@class NSURLAuthenticationChallenge;
@class NSURLProtectionSpace;
@class NSURLCredential;//证书授权信息
@class NSURLCredentialStorage;
@class NSURLSessionDataTask;
@class NSURLSessionUploadTask;
@class NSURLSessionDownloadTask;
@class NSNetService;

/*
 
 NSURLSession is a replacement API for NSURLConnection.  It provides
 options that affect the policy of, and various aspects of the
 mechanism by which NSURLRequest objects are retrieved from the
 network.
 
 An NSURLSession may be bound to a delegate object.  The delegate is
 invoked for certain events during the lifetime of a session, such as
 server authentication or determining whether a resource to be loaded
 should be converted into a download.
 
 NSURLSession instances are threadsafe.
 
 The default NSURLSession uses a system provided delegate and is
 appropriate to use in place of existing code that uses
 +[NSURLConnection sendAsynchronousRequest:queue:completionHandler:]
 
 An NSURLSession creates NSURLSessionTask objects which represent the
 action of a resource being loaded.  These are analogous to
 NSURLConnection objects but provide for more control and a unified
 delegate model.
 
 NSURLSessionTask objects are always created in a suspended state and
 must be sent the -resume message before they will execute.
 
 Subclasses of NSURLSessionTask are used to syntactically
 differentiate between data and file downloads.
 
 An NSURLSessionDataTask receives the resource as a series of calls to
 the URLSession:dataTask:didReceiveData: delegate method.  This is type of
 task most commonly associated with retrieving objects for immediate parsing
 by the consumer.
 
 An NSURLSessionUploadTask differs from an NSURLSessionDataTask
 in how its instance is constructed.  Upload tasks are explicitly created
 by referencing a file or data object to upload, or by utilizing the
 -URLSession:task:needNewBodyStream: delegate message to supply an upload
 body.
 
 An NSURLSessionDownloadTask will directly write the response data to
 a temporary file.  When completed, the delegate is sent
 URLSession:downloadTask:didFinishDownloadingToURL: and given an opportunity
 to move this file to a permanent location in its sandboxed container, or to
 otherwise read the file. If canceled, an NSURLSessionDownloadTask can
 produce a data blob that can be used to resume a download at a later
 time.
 
 Beginning with iOS 9 and Mac OS X 10.11, NSURLSessionStream is
 available as a task type.  This allows for direct TCP/IP connection
 to a given host and port with optional secure handshaking and
 navigation of proxies.  Data tasks may also be upgraded to a
 NSURLSessionStream task via the HTTP Upgrade: header and appropriate
 use of the pipelining option of NSURLSessionConfiguration.  See RFC
 2817 and RFC 6455 for information about the Upgrade: header, and
 comments below on turning data tasks into stream tasks.
 */

@class NSURLSession; // 请求基类
@class NSURLSessionDataTask; // 数据GET、POST请求、离线下载                /* DataTask objects receive the payload through zero or more delegate messages */
@class NSURLSessionUploadTask; // 上传请求               /* UploadTask objects receive periodic progress updates but do not return a body */
@class NSURLSessionDownloadTask;// 下载请求            /* DownloadTask objects represent an active download to disk.  They can provide resume data when canceled. */
@class NSURLSessionStreamTask;// 流任务，用于建立一个TCP/IP连接 ios(9.0)              /* StreamTask objects may be used to create NSInput and NSOutputStreams, or used directly in reading and writing. */
@class NSURLSessionConfiguration;// 配置信息
@protocol NSURLSessionDelegate;// 代理

@class NSURLSessionTaskMetrics;// 请求统计(对发送请求/DNS查询/TLS握手/请求响应等各种环节时间上的统计)
@class NSDateInterval;

NS_ASSUME_NONNULL_BEGIN

/*
 
 NSURLSession is not available for i386 targets before Mac OS X 10.10.
 
 */

#if __OBJC2__
#define NSURLSESSION_AVAILABLE    10_9
#else
#define NSURLSESSION_AVAILABLE    10_10
#endif


// 指示一个未知传输大小的常量
FOUNDATION_EXPORT const int64_t NSURLSessionTransferSizeUnknown NS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0);    /* -1LL */

NS_CLASS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0)





#pragma mark - ↑
#pragma mark - NSURLSession

@interface NSURLSession : NSObject



#pragma mark - Session创建、初始化
/*
 * The shared session uses the currently set global NSURLCache,
 * NSHTTPCookieStorage and NSURLCredentialStorage objects.
 */
@property (class, readonly, strong) NSURLSession *sharedSession;// 初始化单例

/*
 * Customization of NSURLSession occurs during creation of a new session.
 * If you only need to use the convenience routines with custom
 * configuration options it is not necessary to specify a delegate.
 * If you do specify a delegate, the delegate will be retained until after
 * the delegate has been sent the URLSession:didBecomeInvalidWithError: message.
 */
// 创建一个指定配置的session
+ (NSURLSession *)sessionWithConfiguration:(NSURLSessionConfiguration *)configuration;

// 创建一个指定配置, 代理和代理方法执行队列的session
+ (NSURLSession *)sessionWithConfiguration:(NSURLSessionConfiguration *)configuration delegate:(nullable id <NSURLSessionDelegate>)delegate delegateQueue:(nullable NSOperationQueue *)queue;



#pragma mark - Session属性

@property (readonly, retain) NSOperationQueue *delegateQueue;// 代理方法执行的队列
@property (nullable, readonly, retain) id <NSURLSessionDelegate> delegate;// 代理
@property (readonly, copy) NSURLSessionConfiguration *configuration;// 配置信息

/*
 * The sessionDescription property is available for the developer to
 * provide a descriptive label for the session.
 */
@property (nullable, copy) NSString *sessionDescription;// app定义的对于该session的描述













#pragma mark - ↑
#pragma mark - 管理session

/* -finishTasksAndInvalidate returns immediately and existing tasks will be allowed
 * to run to completion.  New tasks may not be created.  The session
 * will continue to make delegate callbacks until URLSession:didBecomeInvalidWithError:
 * has been issued.
 *
 * -finishTasksAndInvalidate and -invalidateAndCancel do not
 * have any effect on the shared session singleton.
 *
 * When invalidating a background session, it is not safe to create another background
 * session with the same identifier until URLSession:didBecomeInvalidWithError: has
 * been issued.
 */
/**
 销毁session
 
 NSURLSession 如果设置代理的话会有一个强引用不会被释放掉, 如果你不再需要一个session了, 一定要在dealloc方法中调用它的invalidateAndCancel或finishTasksAndInvalidate方法. (前者是取消所有未完成的任务然后使session失效, 后者是等待正在执行的任务完成之后再使session失效). 否则的话, 有可能造成内存泄漏.
 另外 session失效后会调用URLSession:​did​Become​Invalid​With​Error:方法, 之后session释放对代理的强引用.
 */

// 任务全部完成后销毁session 释放掉
- (void)finishTasksAndInvalidate;

/* -invalidateAndCancel acts as -finishTasksAndInvalidate, but issues
 * -cancel to all outstanding tasks for this session.  Note task
 * cancellation is subject to the state of the task, and some tasks may
 * have already have completed at the time they are sent -cancel.
 */
// 取消所有未完成的任务并销毁session
- (void)invalidateAndCancel;


// 清空cookies, 缓存和证书存储, 移除所有磁盘文件, 清理正在执行的下载任务, 确保未来能响应一个新的socket请求
- (void)resetWithCompletionHandler:(void (^)(void))completionHandler;    /* empty all cookies, cache and credential stores, removes disk files, issues -flushWithCompletionHandler:. Invokes completionHandler() on the delegate queue if not nil. */


// 清除硬盘上的cookies和证书, 清理暂时的缓存, 确保未来能响应一个新的TCP请求
- (void)flushWithCompletionHandler:(void (^)(void))completionHandler;    /* flush storage to disk and clear transient network caches.  Invokes completionHandler() on the delegate queue if not nil. */


// 异步调用session中所有upload, download, data tasks的completion回调.
- (void)getTasksWithCompletionHandler:(void (^)(NSArray<NSURLSessionDataTask *> *dataTasks, NSArray<NSURLSessionUploadTask *> *uploadTasks, NSArray<NSURLSessionDownloadTask *> *downloadTasks))completionHandler; /* invokes completionHandler with outstanding data, upload and download tasks. */

// 异步调用SessionTask的completion回调.
- (void)getAllTasksWithCompletionHandler:(void (^)(NSArray<__kindof NSURLSessionTask *> *tasks))completionHandler API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)); /* invokes completionHandler with all outstanding tasks. */















#pragma mark - ↑
#pragma mark - NSURLSessionTask
/*
 * NSURLSessionTask objects are always created in a suspended state and
 * must be sent the -resume message before they will execute.
 */

#pragma mark - 添加dataTask(数据)任务

/* Creates a data task with the given request.  The request may have a body stream. */
// 获取指定URLRequest内容
- (NSURLSessionDataTask *)dataTaskWithRequest:(NSURLRequest *)request;

// 获取指定URLRequest内容, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionDataTask *)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;



/* Creates a data task to retrieve the contents of the given URL. */
// 获取指定URL内容
- (NSURLSessionDataTask *)dataTaskWithURL:(NSURL *)url;

// 获取指定URL内容, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionDataTask *)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;







#pragma mark - 添加uploadTask(上传)任务

/* Creates an upload task with the given request.  The previously set body stream of the request (if any) is ignored and the URLSession:task:needNewBodyStream: delegate will be called when the body payload is required. */
// 通过HTTP请求发送指定URLRequest数据流给指定URL
- (NSURLSessionUploadTask *)uploadTaskWithStreamedRequest:(NSURLRequest *)request;


/* Creates an upload task with the given request.  The body of the request will be created from the file referenced by fileURL */
// 通过HTTP请求发送指定文件给指定URL
- (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromFile:(NSURL *)fileURL;

// upload convenience method.
// 通过HTTP请求发送指定文件给指定URL, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromFile:(NSURL *)fileURL completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;



/* Creates an upload task with the given request.  The body of the request is provided from the bodyData. */
// 通过HTTP请求发送data给指定URL
- (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromData:(NSData *)bodyData;

// upload convenience method.
// 通过HTTP请求发送data给指定URL, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromData:(nullable NSData *)bodyData completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;







#pragma mark - 添加downloadTask(下载)任务

/* Creates a download task with the given request. */
// 下载指定URLRequest内容
- (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request;

// 下载指定URLRequest内容, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;



/* Creates a download task to download the contents of the given URL. */
// 下载指定URL内容
- (NSURLSessionDownloadTask *)downloadTaskWithURL:(NSURL *)url;

// 下载指定URL内容, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionDownloadTask *)downloadTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;



/* Creates a download task with the resume data.  If the download cannot be successfully resumed, URLSession:task:didCompleteWithError: will be called. */
// 创建一个之前被取消/下载失败的download task
- (NSURLSessionDownloadTask *)downloadTaskWithResumeData:(NSData *)resumeData;

// 创建一个之前被取消/下载失败的download task, 在completionHandler中处理数据. 该方法会绕过代理方法(除了身份认证挑战的代理方法)
- (NSURLSessionDownloadTask *)downloadTaskWithResumeData:(NSData *)resumeData completionHandler:(void (^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;





#pragma mark - 添加streamTask(流)任务

/* Creates a bidirectional stream task to a given host and port.
 */
//  通过给定的域名和端口建立双向TCP/IP连接
- (NSURLSessionStreamTask *)streamTaskWithHostName:(NSString *)hostname port:(NSInteger)port API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0)) __WATCHOS_PROHIBITED;

/* Creates a bidirectional stream task with an NSNetService to identify the endpoint.
 * The NSNetService will be resolved before any IO completes.
 */
// 通过给定的network service建立双向TCP/IP连接
- (NSURLSessionStreamTask *)streamTaskWithNetService:(NSNetService *)service API_AVAILABLE(macos(10.11), ios(9.0), tvos(9.0)) __WATCHOS_PROHIBITED;

@end
#pragma mark - ---














typedef NS_ENUM(NSInteger, NSURLSessionTaskState) {
    NSURLSessionTaskStateRunning = 0,                     /* The task is currently being serviced by the session */
    NSURLSessionTaskStateSuspended = 1,
    NSURLSessionTaskStateCanceling = 2,                   /* The task has been told to cancel.  The session will receive a URLSession:task:didCompleteWithError: message. */
    NSURLSessionTaskStateCompleted = 3,                   /* The task has completed and the session will receive no more delegate notifications */
} NS_ENUM_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0);

/*
 * NSURLSessionTask - a cancelable object that refers to the lifetime
 * of processing a given request.
 */
NS_CLASS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0)
@interface NSURLSessionTask : NSObject <NSCopying, NSProgressReporting>

@property (readonly)                 NSUInteger    taskIdentifier;    /* an identifier for this task, assigned by and unique to the owning session */
@property (nullable, readonly, copy) NSURLRequest  *originalRequest;  /* may be nil if this is a stream task */
@property (nullable, readonly, copy) NSURLRequest  *currentRequest;   /* may differ from originalRequest due to http server redirection */
@property (nullable, readonly, copy) NSURLResponse *response;         /* may be nil if no response has been received */

/*
 * NSProgress object which represents the task progress.
 * It can be used for task progress tracking.
 */
@property (readonly, strong) NSProgress *progress API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));

/*
 * Start the network load for this task no earlier than the specified date. If
 * not specified, no start delay is used.
 *
 * Only applies to tasks created from background NSURLSession instances; has no
 * effect for tasks created from other session types.
 */
@property (nullable, copy) NSDate *earliestBeginDate API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));

/*
 * The number of bytes that the client expects (a best-guess upper-bound) will
 * be sent and received by this task. These values are used by system scheduling
 * policy. If unspecified, NSURLSessionTransferSizeUnknown is used.
 */
@property int64_t countOfBytesClientExpectsToSend API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));
@property int64_t countOfBytesClientExpectsToReceive API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));


/* Byte count properties may be zero if no body is expected,
 * or NSURLSessionTransferSizeUnknown if it is not possible
 * to know how many bytes will be transferred.
 */

/* number of body bytes already received */
@property (readonly) int64_t countOfBytesReceived;

/* number of body bytes already sent */
@property (readonly) int64_t countOfBytesSent;

/* number of body bytes we expect to send, derived from the Content-Length of the HTTP request */
@property (readonly) int64_t countOfBytesExpectedToSend;

/* number of byte bytes we expect to receive, usually derived from the Content-Length header of an HTTP response. */
@property (readonly) int64_t countOfBytesExpectedToReceive;

/*
 * The taskDescription property is available for the developer to
 * provide a descriptive label for the task.
 */
@property (nullable, copy) NSString *taskDescription;

/* -cancel returns immediately, but marks a task as being canceled.
 * The task will signal -URLSession:task:didCompleteWithError: with an
 * error value of { NSURLErrorDomain, NSURLErrorCancelled }.  In some
 * cases, the task may signal other work before it acknowledges the
 * cancelation.  -cancel may be sent to a task that has been suspended.
 */
- (void)cancel;// 取消task

/*
 * The current state of the task within the session.
 */
@property (readonly) NSURLSessionTaskState state;

/*
 * The error, if any, delivered via -URLSession:task:didCompleteWithError:
 * This property will be nil in the event that no error occured.
 */
@property (nullable, readonly, copy) NSError *error;

/*
 * Suspending a task will prevent the NSURLSession from continuing to
 * load data.  There may still be delegate calls made on behalf of
 * this task (for instance, to report data received while suspending)
 * but no further transmissions will be made on behalf of the task
 * until -resume is sent.  The timeout timer associated with the task
 * will be disabled while a task is suspended. -suspend and -resume are
 * nestable.
 */
- (void)suspend;// 暂停task
- (void)resume;// 执行Task

/*
 * Sets a scaling factor for the priority of the task. The scaling factor is a
 * value between 0.0 and 1.0 (inclusive), where 0.0 is considered the lowest
 * priority and 1.0 is considered the highest.
 *
 * The priority is a hint and not a hard requirement of task performance. The
 * priority of a task may be changed using this API at any time, but not all
 * protocols support this; in these cases, the last priority that took effect
 * will be used.
 *
 * If no priority is specified, the task will operate with the default priority
 * as defined by the constant NSURLSessionTaskPriorityDefault. Two additional
 * priority levels are provided: NSURLSessionTaskPriorityLow and
 * NSURLSessionTaskPriorityHigh, but use is not restricted to these.
 */
@property float priority API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

@end

FOUNDATION_EXPORT const float NSURLSessionTaskPriorityDefault API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityLow API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));
FOUNDATION_EXPORT const float NSURLSessionTaskPriorityHigh API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

/*
 * An NSURLSessionDataTask does not provide any additional
 * functionality over an NSURLSessionTask and its presence is merely
 * to provide lexical differentiation from download and upload tasks.
 */
@interface NSURLSessionDataTask : NSURLSessionTask
@end

/*
 * An NSURLSessionUploadTask does not currently provide any additional
 * functionality over an NSURLSessionDataTask.  All delegate messages
 * that may be sent referencing an NSURLSessionDataTask equally apply
 * to NSURLSessionUploadTasks.
 */
@interface NSURLSessionUploadTask : NSURLSessionDataTask
@end

/*
 * NSURLSessionDownloadTask is a task that represents a download to
 * local storage.
 */
@interface NSURLSessionDownloadTask : NSURLSessionTask

/* Cancel the download (and calls the superclass -cancel).  If
 * conditions will allow for resuming the download in the future, the
 * callback will be called with an opaque data blob, which may be used
 * with -downloadTaskWithResumeData: to attempt to resume the download.
 * If resume data cannot be created, the completion handler will be
 * called with nil resumeData.
 */
- (void)cancelByProducingResumeData:(void (^)(NSData * _Nullable resumeData))completionHandler;

@end

/*
 * An NSURLSessionStreamTask provides an interface to perform reads
 * and writes to a TCP/IP stream created via NSURLSession.  This task
 * may be explicitly created from an NSURLSession, or created as a
 * result of the appropriate disposition response to a
 * -URLSession:dataTask:didReceiveResponse: delegate message.
 *
 * NSURLSessionStreamTask can be used to perform asynchronous reads
 * and writes.  Reads and writes are enquened and executed serially,
 * with the completion handler being invoked on the sessions delegate
 * queuee.  If an error occurs, or the task is canceled, all
 * outstanding read and write calls will have their completion
 * handlers invoked with an appropriate error.
 *
 * It is also possible to create NSInputStream and NSOutputStream
 * instances from an NSURLSessionTask by sending
 * -captureStreams to the task.  All outstanding read and writess are
 * completed before the streams are created.  Once the streams are
 * delivered to the session delegate, the task is considered complete
 * and will receive no more messsages.  These streams are
 * disassociated from the underlying session.
 */

NS_CLASS_AVAILABLE(10_11, 9_0)
@interface NSURLSessionStreamTask : NSURLSessionTask

/* Read minBytes, or at most maxBytes bytes and invoke the completion
 * handler on the sessions delegate queue with the data or an error.
 * If an error occurs, any outstanding reads will also fail, and new
 * read requests will error out immediately.
 */
- (void)readDataOfMinLength:(NSUInteger)minBytes maxLength:(NSUInteger)maxBytes timeout:(NSTimeInterval)timeout completionHandler:(void (^) (NSData * _Nullable data, BOOL atEOF, NSError * _Nullable error))completionHandler;

/* Write the data completely to the underlying socket.  If all the
 * bytes have not been written by the timeout, a timeout error will
 * occur.  Note that invocation of the completion handler does not
 * guarantee that the remote side has received all the bytes, only
 * that they have been written to the kernel. */
- (void)writeData:(NSData *)data timeout:(NSTimeInterval)timeout completionHandler:(void (^) (NSError * _Nullable error))completionHandler;

/* -captureStreams completes any already enqueued reads
 * and writes, and then invokes the
 * URLSession:streamTask:didBecomeInputStream:outputStream: delegate
 * message. When that message is received, the task object is
 * considered completed and will not receive any more delegate
 * messages. */
- (void)captureStreams;

/* Enqueue a request to close the write end of the underlying socket.
 * All outstanding IO will complete before the write side of the
 * socket is closed.  The server, however, may continue to write bytes
 * back to the client, so best practice is to continue reading from
 * the server until you receive EOF.
 */
- (void)closeWrite;

/* Enqueue a request to close the read side of the underlying socket.
 * All outstanding IO will complete before the read side is closed.
 * You may continue writing to the server.
 */
- (void)closeRead;

/*
 * Begin encrypted handshake.  The hanshake begins after all pending
 * IO has completed.  TLS authentication callbacks are sent to the
 * session's -URLSession:task:didReceiveChallenge:completionHandler:
 */
- (void)startSecureConnection;

/*
 * Cleanly close a secure connection after all pending secure IO has
 * completed.
 */
- (void)stopSecureConnection;

@end

/*!
 @enum NSURLSessionMultipathServiceType
 
 @discussion The NSURLSessionMultipathServiceType enum defines constants that
 can be used to specify the multipath service type to associate an NSURLSession.  The
 multipath service type determines whether multipath TCP should be attempted and the conditions
 for creating and switching between subflows.  Using these service types requires the appropriate entitlement.  Any connection attempt will fail if the process does not have the required entitlement.
 A primary interface is a generally less expensive interface in terms of both cost and power (such as WiFi or ethernet).  A secondary interface is more expensive (such as 3G or LTE).
 
 @constant NSURLSessionMultipathServiceTypeNone Specifies that multipath tcp should not be used.  Connections will use a single flow.
 This is the default value.  No entitlement is required to set this value.
 
 @constant NSURLSessionMultipathServiceTypeHandover Specifies that a secondary subflow should only be used
 when the primary subflow is not performing adequately.   Requires the com.apple.developer.networking.multipath entilement.
 
 @constant NSURLSessionMultipathServiceTypeInteractive Specifies that a secodary subflow should be used if the
 primary subflow is not performing adequately (packet loss, high round trip times, bandwidth issues).  The secondary
 subflow will be created more aggressively than with NSURLSessionMultipathServiceTypeHandover.  Requires the com.apple.developer.networking.multipath entitlement.
 
 @constant NSURLSessionMultipathServiceTypeAggregate Specifies that multiple subflows across multiple interfaces should be
 used for better bandwidth.  This mode is only available for experimentation on devices configured for development use.
 It can be enabled in the Developer section of the Settings app.
 
 */
typedef NS_ENUM(NSInteger, NSURLSessionMultipathServiceType)
{
    NSURLSessionMultipathServiceTypeNone = 0,          /* None - no multipath (default) */
    NSURLSessionMultipathServiceTypeHandover = 1,       /* Handover - secondary flows brought up when primary flow is not performing adequately. */
    NSURLSessionMultipathServiceTypeInteractive = 2, /* Interactive - secondary flows created more aggressively. */
    NSURLSessionMultipathServiceTypeAggregate = 3    /* Aggregate - multiple subflows used for greater bandwitdh. */
} API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos) NS_SWIFT_NAME(URLSessionConfiguration.MultipathServiceType);













/*
 * Configuration options for an NSURLSession.  When a session is
 * created, a copy of the configuration object is made - you cannot
 * modify the configuration of a session after it has been created.
 *
 * The shared session uses the global singleton credential, cache
 * and cookie storage objects.
 *
 * An ephemeral session has no persistent disk storage for cookies,
 * cache or credentials.
 *
 * A background session can be used to perform networking operations
 * on behalf of a suspended application, within certain constraints.
 */
NS_CLASS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0)

#pragma mark - ↑
#pragma mark - NSURLSessionConfiguration 配置信息

@interface NSURLSessionConfiguration : NSObject <NSCopying>

// 默认配置 (使用磁盘缓存,用将证书存在用户的钥匙串)
@property (class, readonly, strong) NSURLSessionConfiguration *defaultSessionConfiguration;
// 临时配置 (内存缓存不做磁盘缓存,也存储证书,它的信息存于RAM中)
@property (class, readonly, strong) NSURLSessionConfiguration *ephemeralSessionConfiguration;

// 后台配置 (需要指定一个identifier用来后台重连session对象,做后台上传/下载,但是有一个独立进程来操作上传/下载)
+ (NSURLSessionConfiguration *)backgroundSessionConfigurationWithIdentifier:(NSString *)identifier API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));



/* identifier for the background session configuration */
@property (nullable, readonly, copy) NSString *identifier;// 标识

/* default cache policy for requests */
/**
 指定了一个请求的缓存响应应该在什么时候返回。这相当于 NSURLRequest 的 -cachePolicy 方法。
 */
@property NSURLRequestCachePolicy requestCachePolicy;//请求缓存策略

/* default timeout for requests.  This will cause a timeout if no data is transmitted for the given timeout value, and is reset whenever data is transmitted. */
@property NSTimeInterval timeoutIntervalForRequest; //请求超时

/* default timeout for requests.  This will cause a timeout if a resource is not able to be retrieved within a given timeout. */
@property NSTimeInterval timeoutIntervalForResource;//响应超时

/* type of service for requests. */
/**
 作用：对标准的网络流量、网络电话、语音、视频，以及由一个后台进程使用的流量进行了区分。大多数应用程序都不需要设置这个。
 */
@property NSURLRequestNetworkServiceType networkServiceType;// 请求服务的类型 如：语音、电话

/* allow request to route over cellular. */
/**
 注解：
    allowsCellularAccess 和 discretionary 被用于节省通过蜂窝网络连接的带宽。对于后台传输的情况，推荐大家使用 discretionary 这个属性，而不是 allowsCellularAccess，因为前者会把 WiFi 和电源的可用性考虑在内。
 */
@property BOOL allowsCellularAccess; //是否允许蜂窝网络下的数据请求


#pragma mark -

/*
 * Causes tasks to wait for network connectivity to become available, rather
 * than immediately failing with an error (such as NSURLErrorNotConnectedToInternet)
 * when it is not. When waiting for connectivity, the timeoutIntervalForRequest
 * property does not apply, but the timeoutIntervalForResource property does.
 *
 * Unsatisfactory connectivity (that requires waiting) includes cases where the
 * device has limited or insufficient connectivity for a task (e.g., only has a
 * cellular connection but the allowsCellularAccess property is NO, or requires
 * a VPN connection in order to reach the desired host).
 *
 * Default value is NO. Ignored by background sessions, as background sessions
 * always wait for connectivity.
 */
@property BOOL waitsForConnectivity API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));

/* allows background tasks to be scheduled at the discretion of the system for optimal performance. */
/**
 允许后台任务在性能最优状态下进行(当电量不足或者是蜂窝时将不进行,后台任务推荐设置该属性)
 */
@property (getter=isDiscretionary) BOOL discretionary API_AVAILABLE(macos(10.10), ios(7.0), watchos(2.0), tvos(9.0));

/* The identifier of the shared data container into which files in background sessions should be downloaded.
 * App extensions wishing to use background sessions *must* set this property to a valid container identifier, or
 * all transfers in that session will fail with NSURLErrorBackgroundSessionRequiresSharedContainer.
 */
@property (nullable, copy) NSString *sharedContainerIdentifier API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

/*
 * Allows the app to be resumed or launched in the background when tasks in background sessions complete
 * or when auth is required. This only applies to configurations created with +backgroundSessionConfigurationWithIdentifier:
 * and the default value is YES.
 */
/**
 是另一个新的属性，该属性指定该 session 是否应该从后台启动。
 */
@property BOOL sessionSendsLaunchEvents API_AVAILABLE(ios(7.0), watchos(2.0), tvos(9.0)) API_UNAVAILABLE(macos);

/* The proxy dictionary, as described by <CFNetwork/CFHTTPStream.h> */
/**
 指定了 session 连接中的代理服务器。同样地，大多数面向消费者的应用程序都不需要代理，所以基本上不需要配置这个属性。
 */
@property (nullable, copy) NSDictionary *connectionProxyDictionary;


/**
 安全策略：
 确定 `session 是否支持 SSL 协议。
 */
/* The minimum allowable versions of the TLS protocol, from <Security/SecureTransport.h> */
@property SSLProtocol TLSMinimumSupportedProtocol;
/* The maximum allowable versions of the TLS protocol, from <Security/SecureTransport.h> */
@property SSLProtocol TLSMaximumSupportedProtocol;

/* Allow the use of HTTP pipelining */
/**
 这个属性在 NSMutableURLRequest 下也有，它可以被用于开启 HTTP 管线化（HTTP pipelining），这可以显着降低请求的加载时间，但是由于没有被服务器广泛支持，默认是禁用的。
 */
@property BOOL HTTPShouldUsePipelining;

/* Allow the session to set cookies on requests */
/**
 指定了请求是否应该使用 session 存储的 cookie，即 HTTPCookieSorage 属性的值。
 */
@property BOOL HTTPShouldSetCookies;

/* Policy for accepting cookies.  This overrides the policy otherwise specified by the cookie storage. */
/**
 决定了什么情况下 session 应该接受从服务器发出的 cookie。
 */
@property NSHTTPCookieAcceptPolicy HTTPCookieAcceptPolicy;

/* Specifies additional headers which will be set on outgoing requests.
 Note that these headers are added to the request only if not already present. */
/**
 作用：指定了一组默认的可以设置请求（outbound request）的数据头。这对于跨 session 共享信息，如内容类型、语言、用户代理和身份认证，是很有用的。
 
 使用：
    // 设置请求的header
    NSString *userPasswordString = [NSString stringWithFormat:@"%@:%@", user, password];
    NSData * userPasswordData = [userPasswordString dataUsingEncoding:NSUTF8StringEncoding];
    NSString *base64EncodedCredential = [userPasswordData base64EncodedStringWithOptions:0];
    NSString *authString = [NSString stringWithFormat:@"Basic %@", base64EncodedCredential];
    NSString *userAgentString = @"AppName/com.example.app (iPhone 5s; iOS 7.0.2; Scale/2.0)";

    configuration.HTTPAdditionalHeaders = @{@"Accept": @"application/json",
                                            @"Accept-Language": @"en",
                                            @"Authorization": authString,
                                            @"User-Agent": userAgentString};
 */
@property (nullable, copy) NSDictionary *HTTPAdditionalHeaders;

/* The maximum number of simultanous persistent connections per host */
/**
 注解：
    是 Foundation 框架中 URL 加载系统的一个新的配置选项。它曾经被 NSURLConnection 用于管理私有的连接池。现在有了 NSURLSession，开发者可以在需要时限制连接到特定主机的数量。
 */
@property NSInteger HTTPMaximumConnectionsPerHost;// 每端口的 最大并发HTTP请求数目

/* The cookie storage object to use, or nil to indicate that no cookies should be handled */
/**
 存储了 session 所使用的 cookie。默认情况下会使用 NSHTTPCookieShorage 的 +sharedHTTPCookieStorage 这个单例对象，这与 NSURLConnection 是相同的。
 */
@property (nullable, retain) NSHTTPCookieStorage *HTTPCookieStorage;

/* The credential storage object, or nil to indicate that no credential storage is to be used */
/**
 安全策略：
 存储了 session 所使用的证书。默认情况下会使用 NSURLCredentialStorage 的 +sharedCredentialStorage 这个单例对象，这与 NSURLConnection 是相同的。
 */
@property (nullable, retain) NSURLCredentialStorage *URLCredentialStorage;

/* The URL resource cache, or nil to indicate that no caching is to be performed */
/**
 缓存策略：
 是 session 使用的缓存。默认情况下会使用 NSURLCache 的 +sharedURLCache 这个单例对象，这与 NSURLConnection 是相同的。
 */
@property (nullable, retain) NSURLCache *URLCache;

/* Enable extended background idle mode for any tcp sockets created.    Enabling this mode asks the system to keep the socket open
 *  and delay reclaiming it when the process moves to the background (see https://developer.apple.com/library/ios/technotes/tn2277/_index.html)
 */
@property BOOL shouldUseExtendedBackgroundIdleMode API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0));

/* An optional array of Class objects which subclass NSURLProtocol.
 The Class will be sent +canInitWithRequest: when determining if
 an instance of the class can be used for a given URL scheme.
 You should not use +[NSURLProtocol registerClass:], as that
 method will register your class with the default session rather
 than with an instance of NSURLSession.
 Custom NSURLProtocol subclasses are not available to background
 sessions.
 */
/**
 自定义协议
 用来配置特定某个 session 所使用的自定义协议（该协议是 NSURLProtocol 的子类）的数组。
 */
@property (nullable, copy) NSArray<Class> *protocolClasses;

/* multipath service type to use for connections.  The default is NSURLSessionMultipathServiceTypeNone */
@property NSURLSessionMultipathServiceType multipathServiceType API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos, watchos, tvos);

@end

/*
 * Disposition options for various delegate messages
 */
typedef NS_ENUM(NSInteger, NSURLSessionDelayedRequestDisposition) {
    NSURLSessionDelayedRequestContinueLoading = 0,  /* Use the original request provided when the task was created; the request parameter is ignored. */
    NSURLSessionDelayedRequestUseNewRequest = 1,    /* Use the specified request, which may not be nil. */
    NSURLSessionDelayedRequestCancel = 2,           /* Cancel the task; the request parameter is ignored. */
} NS_SWIFT_NAME(URLSession.DelayedRequestDisposition) API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));

typedef NS_ENUM(NSInteger, NSURLSessionAuthChallengeDisposition) {// 判断服务器传给我们的证书类型
    NSURLSessionAuthChallengeUseCredential = 0,//使用该证书 安装该证书                                       /* Use the specified credential, which may be nil */
    NSURLSessionAuthChallengePerformDefaultHandling = 1,//默认采用的方式,该证书被忽略                              /* Default handling for the challenge - as if this delegate were not implemented; the credential parameter is ignored. */
    NSURLSessionAuthChallengeCancelAuthenticationChallenge = 2,//取消请求,证书忽略                       /* The entire request will be canceled; the credential parameter is ignored. */
    NSURLSessionAuthChallengeRejectProtectionSpace = 3,//拒绝                               /* This challenge is rejected and the next authentication protection space should be tried; the credential parameter is ignored. */
} NS_ENUM_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0);


typedef NS_ENUM(NSInteger, NSURLSessionResponseDisposition) {
    NSURLSessionResponseCancel = 0,                                      /* Cancel the load, this is the same as -[task cancel] */
    NSURLSessionResponseAllow = 1,                                       /* Allow the load to continue */
    NSURLSessionResponseBecomeDownload = 2,                              /* Turn this request into a download */
    NSURLSessionResponseBecomeStream API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = 3,  /* Turn this task into a stream task */
} NS_ENUM_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0);










#pragma mark - ↑
#pragma mark - NSURLSessionDelegate
// 处理鉴权、后台下载任务完成通知
/*
 * NSURLSessionDelegate specifies the methods that a session delegate
 * may respond to.  There are both session specific messages (for
 * example, connection based auth) as well as task based messages.
 */
/*
 * Messages related to the URL session as a whole
 */

@protocol NSURLSessionDelegate <NSObject>
@optional

/* The last message a session receives.  A session will only become
 * invalid because of a systemic error or when it has been
 * explicitly invalidated, in which case the error parameter will be nil.
 */
// 当一个session遇到系统错误或者未检测到的错误的时候，就会调用这个方法。
- (void)URLSession:(NSURLSession *)session didBecomeInvalidWithError:(nullable NSError *)error;

/* If implemented, when a connection level authentication challenge
 * has occurred, this delegate will be given the opportunity to
 * provide authentication credentials to the underlying
 * connection. Some types of authentication will apply to more than
 * one request on a given connection to a server (SSL Server Trust
 * challenges).  If this delegate message is not implemented, the
 * behavior will be to use the default handling, which may involve user
 * interaction.
 */
/**
 方法：URLSession:​did​Receive​Challenge:​completion​Handler: 身份验证或TLS握手
 
    1.这是所有task都必须经历的一个过程. 当一个服务器请求身份验证或TLS握手期间需要提供证书的话, URLSession会调用他的代理方法URLSession:​did​Receive​Challenge:​completion​Handler:​去处理, 如果连接途中收到服务器返回需要身份认证的response, 也会调用该代理方法.

    2.如果你没有实现该代理方法, URLSession就会这么做 :
        1.使用身份认证信息作为请求URL的一部分(如果可用的话)
        2.在用户的keychain中查找网络密码和证书(in macOS), 在app的keychain中查找(in iOS)

    3.如果证书还是不可用或服务器拒绝该证书, 就会继续缺少身份认证的连接.
        1.对于HTTP(S)连接, 请求失败并返回一个状态码, 可能会提供一些替代的内容, 例如一个私人网站的公共网页.
        2.对于其他URL类型(如FTP等), 则连接请求失败, 直接返回错误信息
 */
- (void)URLSession:(NSURLSession *)session didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;

/* If an application has received an
 * -application:handleEventsForBackgroundURLSession:completionHandler:
 * message, the session delegate will receive this message to indicate
 * that all messages previously enqueued for this session have been
 * delivered.  At this time it is safe to invoke the previously stored
 * completion handler, or to begin any internal updates that will
 * result in invoking the completion handler.
 */
// 应用在后台，而且后台所有下载任务完成方法会被调用。我们在这里可以对session发起的请求做各种操作比如请求完成的回调等。
- (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)session API_AVAILABLE(ios(7.0), watchos(2.0), tvos(9.0)) API_UNAVAILABLE(macos);

@end






#pragma mark - ↑
#pragma mark - NSURLSessionTaskDelegate
// 主要处理收到鉴权响应、任务结束(无论是正常还是异常)

/*
 * Messages related to the operation of a specific task.
 */
@protocol NSURLSessionTaskDelegate <NSURLSessionDelegate>
@optional

/*
 * Sent when the system is ready to begin work for a task with a delayed start
 * time set (using the earliestBeginDate property). The completionHandler must
 * be invoked in order for loading to proceed. The disposition provided to the
 * completion handler continues the load with the original request provided to
 * the task, replaces the request with the specified task, or cancels the task.
 * If this delegate is not implemented, loading will proceed with the original
 * request.
 *
 * Recommendation: only implement this delegate if tasks that have the
 * earliestBeginDate property set may become stale and require alteration prior
 * to starting the network load.
 *
 * If a new request is specified, the allowsCellularAccess property from the
 * new request will not be used; the allowsCellularAccess property from the
 * original request will continue to be used.
 *
 * Canceling the task is equivalent to calling the task's cancel method; the
 * URLSession:task:didCompleteWithError: task delegate will be called with error
 * NSURLErrorCancelled.
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
willBeginDelayedRequest:(NSURLRequest *)request
 completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition disposition, NSURLRequest * _Nullable newRequest))completionHandler
API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));

/*
 * Sent when a task cannot start the network loading process because the current
 * network connectivity is not available or sufficient for the task's request.
 *
 * This delegate will be called at most one time per task, and is only called if
 * the waitsForConnectivity property in the NSURLSessionConfiguration has been
 * set to YES.
 *
 * This delegate callback will never be called for background sessions, because
 * the waitForConnectivity property is ignored by those sessions.
 */
- (void)URLSession:(NSURLSession *)session taskIsWaitingForConnectivity:(NSURLSessionTask *)task
API_AVAILABLE(macos(10.13), ios(11.0), watchos(4.0), tvos(11.0));

/* An HTTP request is attempting to perform a redirection to a different
 * URL. You must invoke the completion routine to allow the
 * redirection, allow the redirection with a modified request, or
 * pass nil to the completionHandler to cause the body of the redirection
 * response to be delivered as the payload of this request. The default
 * is to follow redirections.
 *
 * For tasks in background sessions, redirections will always be followed and this method will not be called.
 */
/**
 方法：URLSession:​task:​will​Perform​HTTPRedirection:​new​Request:​completion​Handler: 重定位response
 
    这也是所有task都有可能经历的一个过程, 如果response是HTTP重定位, session会调用代理的URLSession:​task:​will​Perform​HTTPRedirection:​new​Request:​completion​Handler:方法. 这里需要调用completionHandler告诉session是否允许重定位, 或者重定位到另一个URL, 或者传nil表示重定位的响应body有效并返回. 如果代理没有实现该方法, 则允许重定位直到达到最大重定位次数.
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
willPerformHTTPRedirection:(NSHTTPURLResponse *)response
        newRequest:(NSURLRequest *)request
 completionHandler:(void (^)(NSURLRequest * _Nullable))completionHandler;

/* The task has received a request specific authentication challenge.
 * If this delegate is not implemented, the session specific authentication challenge
 * will *NOT* be called and the behavior will be the same as using the default handling
 * disposition.
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
 completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;





/* Sent if a task requires a new, unopened body stream.  This may be
 * necessary when authentication has failed for any request that
 * involves a body stream.
 */
/**
 调用方法：StreamTask
 
 如果任务的数据是由一个stream发出的, session就会调用代理的URLSession:​task:​need​New​Body​Stream:​方法去获取一个NSInputStream对象并提供一个新请求的body data.
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
 needNewBodyStream:(void (^)(NSInputStream * _Nullable bodyStream))completionHandler;





/* Sent periodically to notify the delegate of upload progress.  This
 * information is also available as properties of the task.
 */
/*
 调用方法：uploadTask
 
 上传数据去服务器期间, 代理会周期性收到URLSession:​task:​did​Send​Body​Data:​total​Bytes​Sent:​total​Bytes​Expected​To​Send:回调并获得上传进度.
 
 *  监听上传进度设置代理
 *  @param bytesSent                本次发送的数据
 *  @param totalBytesSent           上传完成的数据大小
 *  @param totalBytesExpectedToSend 文件的总大小
 *  1.0 * totalBytesSent / totalBytesExpectedToSend
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
   didSendBodyData:(int64_t)bytesSent
    totalBytesSent:(int64_t)totalBytesSent
totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;




/*
 * Sent when complete statistics information has been collected for the task.
 */
/**
 当task的统计信息收集好了以后，调用这个方法。
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));





/* Sent as the last message related to a specific task.  Error may be
 * nil, which implies that no error occurred and this task is complete.
 */

/**
 调用方法：Sessiontask 回调
 
 任何task完成(成功 或 失败)的时候, 都会调用URLSession:​task:​did​Complete​With​Error:​方法, error有可能为nil(请求成功), 不为nil(请求失败)
 
    1.请求失败, 但是该任务是可恢复下载的, 那么error对象的userInfo字典里有一个NSURLSession​Download​Task​Resume​Data对应的value, 你应该把这个值传给download​Task​With​Resume​Data:​方法重新恢复下载

    2.请求失败, 但是任务无法恢复下载, 那么应该重新创建一个下载任务并从头开始下载.

    3.因为其他原因(如服务器错误等等), 创建并恢复请求.

    4.NSURLSession不会收到服务器传来的错误, 代理只会收到客户端出现的错误, 例如无法解析主机名或无法连接上主机等等. 客户端错误定义在URL Loading System Error Codes. 服务端错误通过HTTP状态法进行传输, 详情请看NSHTTPURLResponse和NSURLResponse类.
 */
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
didCompleteWithError:(nullable NSError *)error;

@end









#pragma mark - ↑
#pragma mark - NSURLSessionDataDelegate
// 处理数据的接收、dataTask转downloadTask、缓存

/**
 调用原理：DataTask Delegate
 
    1.对于一个data task来说, session会调用代理的URLSession:​data​Task:​did​Receive​Response:​completion​Handler:​方法, 决定是否将一个data dask转换成download task, 然后调用completion回调继续接收data或下载data.
    2.如果你的app选择转换成download task, session会调用代理的URLSession:​data​Task:​did​Become​Download​Task:​方法并把新的download task对象以方法参数的形式传给你. 之后代理不会再收到data task的回调而是转为收到download task的回调
    3.在服务器传输数据给客户端期间, 代理会周期性地收到URLSession:​data​Task:​did​Receive​Data:​回调

    4.session会调用URLSession:​data​Task:​will​Cache​Response:​completion​Handler:​询问你的app是否允许缓存. 如果代理不实现这个方法的话, 默认使用session绑定的Configuration的缓存策略.
 */

/*
 * Messages related to the operation of a task that delivers data
 * directly to the delegate.
 */
@protocol NSURLSessionDataDelegate <NSURLSessionTaskDelegate>
@optional
/* The task has received a response and no further messages will be
 * received until the completion block is called. The disposition
 * allows you to cancel a request or to turn a data task into a
 * download task. This delegate message is optional - if you do not
 * implement it, you can get the response as a property of the task.
 *
 * This method will not be called for background upload tasks (which cannot be converted to download tasks).
 */

/**
 1.当一个task接收到服务器的响应。当所有信息都接收完毕以后，completionHandler会被调用。它默认会取消网络请求或者把一个datatask转换为downloadtask。如果没有实现这个代理方法，我们也可以通过task的response属性获取到对应的数据。background模式的uploadtask不会调用这个方法。
 
    session 会话对象
    dataTask 请求任务
    response 响应头信息
    completionHandler 回调 传给系统
    response.expectedContentLength 本次请求的数据大小
 */
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
didReceiveResponse:(NSURLResponse *)response
 completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler;

/* Notification that a data task has become a download task.  No
 * future messages will be sent to the data task.
 */
/*
 当一个datatask转换为一个downloadtask以后会调用。
 */
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
didBecomeDownloadTask:(NSURLSessionDownloadTask *)downloadTask;

/*
 * Notification that a data task has become a bidirectional stream
 * task.  No future messages will be sent to the data task.  The newly
 * created streamTask will carry the original request and response as
 * properties.
 *
 * For requests that were pipelined, the stream object will only allow
 * reading, and the object will immediately issue a
 * -URLSession:writeClosedForStream:.  Pipelining can be disabled for
 * all requests in a session, or by the NSURLRequest
 * HTTPShouldUsePipelining property.
 *
 * The underlying connection is no longer considered part of the HTTP
 * connection cache and won't count against the total number of
 * connections per host.
 */
/*
 这个是和数据流相关的
 */
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
didBecomeStreamTask:(NSURLSessionStreamTask *)streamTask;

/* Sent when data is available for the delegate to consume.  It is
 * assumed that the delegate will retain and not copy the data.  As
 * the data may be discontiguous, you should use
 * [NSData enumerateByteRangesUsingBlock:] to access it.
 */
// 2.接收到服务器返回的数据(调用多次)
/**
    session 会话对象
    dataTask 请求任务
    data 本次下载的数据
 */
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
    didReceiveData:(NSData *)data;

/* Invoke the completion routine with a valid NSCachedURLResponse to
 * allow the resulting data to be cached, or pass nil to prevent
 * caching. Note that there is no guarantee that caching will be
 * attempted for a given resource, and you should not rely on this
 * message to receive the resource data.
 */
/*
 允许我们在这里调用completionHandler缓存data，或者传入nil来禁止缓存
 */
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
 willCacheResponse:(NSCachedURLResponse *)proposedResponse
 completionHandler:(void (^)(NSCachedURLResponse * _Nullable cachedResponse))completionHandler;

@end




#pragma mark - ↑
#pragma mark - NSURLSessionDownloadDelegate
// 主要处理数据下载、数据进度通知

/**
 调用原理：downloadTask Delegate
 
    1.对于一个通过download​Task​With​Resume​Data:​创建的下载任务, session会调用代理的URLSession:​download​Task:​did​Resume​At​Offset:​expected​Total​Bytes:​方法.
    2.在服务器传输数据给客户端期间, 调用URLSession:​download​Task:​did​Write​Data:​total​Bytes​Written:​total​Bytes​Expected​To​Write:给用户传数据
        1.当用户暂停下载时, 调用cancel​By​Producing​Resume​Data:​给用户传已下好的数据.
        2.如果用户想要恢复下载, 把刚刚的resumeData以参数的形式传给download​Task​With​Resume​Data:​方法创建新的task继续下载.
    3.如果download task成功完成了, 调用URLSession:​download​Task:​did​Finish​Downloading​To​URL:把临时文件的URL路径给你. 此时你需要剪切文件把它移动(NSFileManager moveItemAtURL:)到我们指定的位置fullPath.
 */
/*
 * Messages related to the operation of a task that writes data to a
 * file and notifies the delegate upon completion.
 */
@protocol NSURLSessionDownloadDelegate <NSURLSessionTaskDelegate>

/* Sent when a download task that has completed a download.  The delegate should
 * copy or move the file at the given location to a new location as it will be
 * removed when the delegate message returns. URLSession:task:didCompleteWithError: will
 * still be called.
 */
/**
 3.当下载完成的时候调用
 location 文件的临时存储路径tmp, 需要剪切文件把它移动(moveItemAtURL:)到我们指定的位置
 */
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
didFinishDownloadingToURL:(NSURL *)location;



@optional
/* Sent periodically to notify the delegate of download progress. */
/**
 2.写数据(监听下载进度)
 
    session 会话对象
    downloadTask 下载任务
    bytesWritten 本次写入的数据大小
    totalBytesWritten 下载的数据总大小
    totalBytesExpectedToWrite 文件的总大小
    1.0 * totalBytesWritten/totalBytesExpectedToWrite;
 */
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
      didWriteData:(int64_t)bytesWritten
 totalBytesWritten:(int64_t)totalBytesWritten
totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;



/* Sent when a download has been resumed. If a download failed with an
 * error, the -userInfo dictionary of the error will contain an
 * NSURLSessionDownloadTaskResumeData key, whose value is the resume
 * data.
 */
/**
 1.当恢复下载的时候调用方法
    fileOffset 从什么地方下载
    expectedTotalBytes 文件的总大小
 */
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
 didResumeAtOffset:(int64_t)fileOffset
expectedTotalBytes:(int64_t)expectedTotalBytes;

@end





#pragma mark - ↑
#pragma mark - NSURLSessionStreamDelegate

@protocol NSURLSessionStreamDelegate <NSURLSessionTaskDelegate>
@optional

/* Indiciates that the read side of a connection has been closed.  Any
 * outstanding reads complete, but future reads will immediately fail.
 * This may be sent even when no reads are in progress. However, when
 * this delegate message is received, there may still be bytes
 * available.  You only know that no more bytes are available when you
 * are able to read until EOF. */
- (void)URLSession:(NSURLSession *)session readClosedForStreamTask:(NSURLSessionStreamTask *)streamTask;

/* Indiciates that the write side of a connection has been closed.
 * Any outstanding writes complete, but future writes will immediately
 * fail.
 */
- (void)URLSession:(NSURLSession *)session writeClosedForStreamTask:(NSURLSessionStreamTask *)streamTask;

/* A notification that the system has determined that a better route
 * to the host has been detected (eg, a wi-fi interface becoming
 * available.)  This is a hint to the delegate that it may be
 * desirable to create a new task for subsequent work.  Note that
 * there is no guarantee that the future task will be able to connect
 * to the host, so callers should should be prepared for failure of
 * reads and writes over any new interface. */
- (void)URLSession:(NSURLSession *)session betterRouteDiscoveredForStreamTask:(NSURLSessionStreamTask *)streamTask;

/* The given task has been completed, and unopened NSInputStream and
 * NSOutputStream objects are created from the underlying network
 * connection.  This will only be invoked after all enqueued IO has
 * completed (including any necessary handshakes.)  The streamTask
 * will not receive any further delegate messages.
 */
- (void)URLSession:(NSURLSession *)session streamTask:(NSURLSessionStreamTask *)streamTask
didBecomeInputStream:(NSInputStream *)inputStream
      outputStream:(NSOutputStream *)outputStream;

@end
#pragma mark -




















//----------------------- <#我是分割线#> ------------------------//
//




/* Key in the userInfo dictionary of an NSError received during a failed download. */
FOUNDATION_EXPORT NSString * const NSURLSessionDownloadTaskResumeData NS_AVAILABLE(NSURLSESSION_AVAILABLE, 7_0);

@interface NSURLSessionConfiguration (NSURLSessionDeprecated)
+ (NSURLSessionConfiguration *)backgroundSessionConfiguration:(NSString *)identifier NS_DEPRECATED(NSURLSESSION_AVAILABLE, 10_10, 7_0, 8_0, "Please use backgroundSessionConfigurationWithIdentifier: instead");
@end


/*
 * The resource fetch type.
 */
typedef NS_ENUM(NSInteger, NSURLSessionTaskMetricsResourceFetchType) {
    NSURLSessionTaskMetricsResourceFetchTypeUnknown,
    NSURLSessionTaskMetricsResourceFetchTypeNetworkLoad,   /* The resource was loaded over the network. */
    NSURLSessionTaskMetricsResourceFetchTypeServerPush,    /* The resource was pushed by the server to the client. */
    NSURLSessionTaskMetricsResourceFetchTypeLocalCache,    /* The resource was retrieved from the local storage. */
} API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0));

/*
 * This class defines the performance metrics collected for a request/response transaction during the task execution.
 */
API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0))
@interface NSURLSessionTaskTransactionMetrics : NSObject

/*
 * Represents the transaction request.
 */
@property (copy, readonly) NSURLRequest *request;

/*
 * Represents the transaction response. Can be nil if error occurred and no response was generated.
 */
@property (nullable, copy, readonly) NSURLResponse *response;

/*
 * For all NSDate metrics below, if that aspect of the task could not be completed, then the corresponding “EndDate” metric will be nil.
 * For example, if a name lookup was started but the name lookup timed out, failed, or the client canceled the task before the name could be resolved -- then while domainLookupStartDate may be set, domainLookupEndDate will be nil along with all later metrics.
 */

/*
 * fetchStartDate returns the time when the user agent started fetching the resource, whether or not the resource was retrieved from the server or local resources.
 *
 * The following metrics will be set to nil, if a persistent connection was used or the resource was retrieved from local resources:
 *
 *   domainLookupStartDate
 *   domainLookupEndDate
 *   connectStartDate
 *   connectEndDate
 *   secureConnectionStartDate
 *   secureConnectionEndDate
 */
@property (nullable, copy, readonly) NSDate *fetchStartDate;

/*
 * domainLookupStartDate returns the time immediately before the user agent started the name lookup for the resource.
 */
@property (nullable, copy, readonly) NSDate *domainLookupStartDate;

/*
 * domainLookupEndDate returns the time after the name lookup was completed.
 */
@property (nullable, copy, readonly) NSDate *domainLookupEndDate;

/*
 * connectStartDate is the time immediately before the user agent started establishing the connection to the server.
 *
 * For example, this would correspond to the time immediately before the user agent started trying to establish the TCP connection.
 */
@property (nullable, copy, readonly) NSDate *connectStartDate;

/*
 * If an encrypted connection was used, secureConnectionStartDate is the time immediately before the user agent started the security handshake to secure the current connection.
 *
 * For example, this would correspond to the time immediately before the user agent started the TLS handshake.
 *
 * If an encrypted connection was not used, this attribute is set to nil.
 */
@property (nullable, copy, readonly) NSDate *secureConnectionStartDate;

/*
 * If an encrypted connection was used, secureConnectionEndDate is the time immediately after the security handshake completed.
 *
 * If an encrypted connection was not used, this attribute is set to nil.
 */
@property (nullable, copy, readonly) NSDate *secureConnectionEndDate;

/*
 * connectEndDate is the time immediately after the user agent finished establishing the connection to the server, including completion of security-related and other handshakes.
 */
@property (nullable, copy, readonly) NSDate *connectEndDate;

/*
 * requestStartDate is the time immediately before the user agent started requesting the source, regardless of whether the resource was retrieved from the server or local resources.
 *
 * For example, this would correspond to the time immediately before the user agent sent an HTTP GET request.
 */
@property (nullable, copy, readonly) NSDate *requestStartDate;

/*
 * requestEndDate is the time immediately after the user agent finished requesting the source, regardless of whether the resource was retrieved from the server or local resources.
 *
 * For example, this would correspond to the time immediately after the user agent finished sending the last byte of the request.
 */
@property (nullable, copy, readonly) NSDate *requestEndDate;

/*
 * responseStartDate is the time immediately after the user agent received the first byte of the response from the server or from local resources.
 *
 * For example, this would correspond to the time immediately after the user agent received the first byte of an HTTP response.
 */
@property (nullable, copy, readonly) NSDate *responseStartDate;

/*
 * responseEndDate is the time immediately after the user agent received the last byte of the resource.
 */
@property (nullable, copy, readonly) NSDate *responseEndDate;

/*
 * The network protocol used to fetch the resource, as identified by the ALPN Protocol ID Identification Sequence [RFC7301].
 * E.g., h2, http/1.1, spdy/3.1.
 *
 * When a proxy is configured AND a tunnel connection is established, then this attribute returns the value for the tunneled protocol.
 *
 * For example:
 * If no proxy were used, and HTTP/2 was negotiated, then h2 would be returned.
 * If HTTP/1.1 were used to the proxy, and the tunneled connection was HTTP/2, then h2 would be returned.
 * If HTTP/1.1 were used to the proxy, and there were no tunnel, then http/1.1 would be returned.
 *
 */
@property (nullable, copy, readonly) NSString *networkProtocolName;

/*
 * This property is set to YES if a proxy connection was used to fetch the resource.
 */
@property (assign, readonly, getter=isProxyConnection) BOOL proxyConnection;

/*
 * This property is set to YES if a persistent connection was used to fetch the resource.
 */
@property (assign, readonly, getter=isReusedConnection) BOOL reusedConnection;

/*
 * Indicates whether the resource was loaded, pushed or retrieved from the local cache.
 */
@property (assign, readonly) NSURLSessionTaskMetricsResourceFetchType resourceFetchType;


-(instancetype)init;


@end


API_AVAILABLE(macosx(10.12), ios(10.0), watchos(3.0), tvos(10.0))
@interface NSURLSessionTaskMetrics : NSObject

/*
 * transactionMetrics array contains the metrics collected for every request/response transaction created during the task execution.
 */
@property (copy, readonly) NSArray<NSURLSessionTaskTransactionMetrics *> *transactionMetrics;

/*
 * Interval from the task creation time to the task completion time.
 * Task creation time is the time when the task was instantiated.
 * Task completion time is the time when the task is about to change its internal state to completed.
 */
@property (copy, readonly) NSDateInterval *taskInterval;

/*
 * redirectCount is the number of redirects that were recorded.
 */
@property (assign, readonly) NSUInteger redirectCount;

-(instancetype)init;

@end

NS_ASSUME_NONNULL_END

