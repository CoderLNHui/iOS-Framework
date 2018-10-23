/*
 * NSOperation.h
 *
 * Foundation (c) 2006-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 

#import <Foundation/NSObject.h>
#import <Foundation/NSException.h>
#import <sys/qos.h>
#import <dispatch/dispatch.h>

@class NSArray<ObjectType>, NSSet;

NS_ASSUME_NONNULL_BEGIN

#define NSOperationQualityOfService NSQualityOfService
#define NSOperationQualityOfServiceUserInteractive NSQualityOfServiceUserInteractive
#define NSOperationQualityOfServiceUserInitiated NSQualityOfServiceUserInitiated
#define NSOperationQualityOfServiceUtility NSQualityOfServiceUtility
#define NSOperationQualityOfServiceBackground NSQualityOfServiceBackground


NS_CLASS_AVAILABLE(10_5, 2_0)
@interface NSOperation : NSObject {
@private
    id _private;
    int32_t _private1;
#if __LP64__
    int32_t _private1b;
#endif
}

#pragma mark -启动操作任务
- (void)start;
#pragma mark -自定NSOperation，需要重写main方法
- (void)main;

@property (readonly, getter=isCancelled) BOOL cancelled;
#pragma mark -取消操作任务
- (void)cancel;

@property (readonly, getter=isExecuting) BOOL executing;
@property (readonly, getter=isFinished) BOOL finished;
@property (readonly, getter=isConcurrent) BOOL concurrent; // To be deprecated; use and override 'asynchronous' below
@property (readonly, getter=isAsynchronous) BOOL asynchronous API_AVAILABLE(macos(10.8), ios(7.0), watchos(2.0), tvos(9.0));
@property (readonly, getter=isReady) BOOL ready;

#pragma mark -添加操作依赖,也可以跨队列添加依赖（但是不能相互依赖）
- (void)addDependency:(NSOperation *)op;
#pragma mark -移除依赖
- (void)removeDependency:(NSOperation *)op;

@property (readonly, copy) NSArray<NSOperation *> *dependencies;

typedef NS_ENUM(NSInteger, NSOperationQueuePriority) {
    NSOperationQueuePriorityVeryLow = -8L,
    NSOperationQueuePriorityLow = -4L,
    NSOperationQueuePriorityNormal = 0,
    NSOperationQueuePriorityHigh = 4,
    NSOperationQueuePriorityVeryHigh = 8
};

#pragma mark -队列优先级
@property NSOperationQueuePriority queuePriority;

#pragma mark -添加操作监听（监听到的操作完成后，就会调用到这个Block）
@property (nullable, copy) void (^completionBlock)(void) API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

- (void)waitUntilFinished API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@property double threadPriority API_DEPRECATED("Not supported", macos(10.6,10.10), ios(4.0,8.0), watchos(2.0,2.0), tvos(9.0,9.0));

@property NSQualityOfService qualityOfService API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

@end


#pragma mark - NSBlockOperation
NS_CLASS_AVAILABLE(10_6, 4_0)
@interface NSBlockOperation : NSOperation {
@private
    id _private2;
    void *_reserved2;
}

+ (instancetype)blockOperationWithBlock:(void (^)(void))block;

#pragma mark -追加任务
- (void)addExecutionBlock:(void (^)(void))block;
@property (readonly, copy) NSArray<void (^)(void)> *executionBlocks;

@end


#pragma mark - NSInvocationOperation
NS_CLASS_AVAILABLE(10_5, 2_0)
NS_SWIFT_UNAVAILABLE("NSInvocation and related APIs not available")
@interface NSInvocationOperation : NSOperation {
@private
    id _inv;
    id _exception;
    void *_reserved2;
}

- (nullable instancetype)initWithTarget:(id)target selector:(SEL)sel object:(nullable id)arg;
- (instancetype)initWithInvocation:(NSInvocation *)inv NS_DESIGNATED_INITIALIZER;

@property (readonly, retain) NSInvocation *invocation;

@property (nullable, readonly, retain) id result;

@end

FOUNDATION_EXPORT NSExceptionName const NSInvocationOperationVoidResultException API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));
FOUNDATION_EXPORT NSExceptionName const NSInvocationOperationCancelledException API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0));

static const NSInteger NSOperationQueueDefaultMaxConcurrentOperationCount = -1;

#pragma mark - NSOperationQueue 操作队列
NS_CLASS_AVAILABLE(10_5, 2_0)
@interface NSOperationQueue : NSObject {
@private
    id _private;
    void *_reserved;
}

#pragma mark -添加操作到队列
- (void)addOperation:(NSOperation *)op;
- (void)addOperations:(NSArray<NSOperation *> *)ops waitUntilFinished:(BOOL)wait API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

#pragma mark -添加操作到队列
- (void)addOperationWithBlock:(void (^)(void))block API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@property (readonly, copy) NSArray<__kindof NSOperation *> *operations;
@property (readonly) NSUInteger operationCount API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

#pragma mark -设置队列最大并发数(同一时间最多几个任务可以执行)
@property NSInteger maxConcurrentOperationCount;
#pragma mark -暂停
@property (getter=isSuspended) BOOL suspended;

@property (nullable, copy) NSString *name API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@property NSQualityOfService qualityOfService API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

@property (nullable, assign /* actually retain */) dispatch_queue_t underlyingQueue API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

#pragma mark -取消所有的操作
- (void)cancelAllOperations;

- (void)waitUntilAllOperationsAreFinished;

@property (class, readonly, strong, nullable) NSOperationQueue *currentQueue API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));
@property (class, readonly, strong) NSOperationQueue *mainQueue API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@end
NS_ASSUME_NONNULL_END


