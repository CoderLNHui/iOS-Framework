/*
 * NSFileHandle.h 文件句柄
 *
 * Foundation (c) 1995-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSException.h>
#import <Foundation/NSNotification.h>
#import <Foundation/NSRunLoop.h>

@class NSString, NSData, NSError;

NS_ASSUME_NONNULL_BEGIN

@interface NSFileHandle : NSObject <NSSecureCoding>

#pragma mark -从设置或通道放回可用的数据
@property (readonly, copy) NSData *availableData;

#pragma mark -从当前的节点读取到文件的结尾
- (NSData *)readDataToEndOfFile;
#pragma mark -从当前的节点读取到指定的长度数据
- (NSData *)readDataOfLength:(NSUInteger)length;

#pragma mark -向文件写入数据,写入数据时会覆盖掉原来的内容
- (void)writeData:(NSData *)data;

@property (readonly) unsigned long long offsetInFile;
#pragma mark -将文件内容指针定位到文件的末尾
- (unsigned long long)seekToEndOfFile;

#pragma mark -将文件内容指针定位到指定位置（偏移量,0 表示定位到文件的起始位置
- (void)seekToFileOffset:(unsigned long long)offset;

#pragma mark -文件的截取,截取指定长度的内容,0清空文件内容
- (void)truncateFileAtOffset:(unsigned long long)offset;

#pragma mark -将修改的内容立即同步到文件
- (void)synchronizeFile;

#pragma mark -关闭文件
- (void)closeFile;

- (instancetype)initWithFileDescriptor:(int)fd closeOnDealloc:(BOOL)closeopt NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

@end

@interface NSFileHandle (NSFileHandleCreation)

@property (class, readonly, strong) NSFileHandle *fileHandleWithStandardInput;
@property (class, readonly, strong) NSFileHandle *fileHandleWithStandardOutput;
@property (class, readonly, strong) NSFileHandle *fileHandleWithStandardError;
@property (class, readonly, strong) NSFileHandle *fileHandleWithNullDevice;

#pragma mark -以读取、写入、更新 的方式打开文件
+ (nullable instancetype)fileHandleForReadingAtPath:(NSString *)path;
+ (nullable instancetype)fileHandleForWritingAtPath:(NSString *)path;
+ (nullable instancetype)fileHandleForUpdatingAtPath:(NSString *)path;

+ (nullable instancetype)fileHandleForReadingFromURL:(NSURL *)url error:(NSError **)error API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));
+ (nullable instancetype)fileHandleForWritingToURL:(NSURL *)url error:(NSError **)error API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));
+ (nullable instancetype)fileHandleForUpdatingURL:(NSURL *)url error:(NSError **)error API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

@end

FOUNDATION_EXPORT NSExceptionName const NSFileHandleOperationException;

FOUNDATION_EXPORT NSNotificationName const NSFileHandleReadCompletionNotification;
FOUNDATION_EXPORT NSNotificationName const NSFileHandleReadToEndOfFileCompletionNotification;
FOUNDATION_EXPORT NSNotificationName const NSFileHandleConnectionAcceptedNotification;
FOUNDATION_EXPORT NSNotificationName const NSFileHandleDataAvailableNotification;

FOUNDATION_EXPORT NSString * const NSFileHandleNotificationDataItem;
FOUNDATION_EXPORT NSString * const NSFileHandleNotificationFileHandleItem;
FOUNDATION_EXPORT NSString * const NSFileHandleNotificationMonitorModes API_DEPRECATED("Not supported", macos(10.0,10.7), ios(2.0,5.0), watchos(2.0,2.0), tvos(9.0,9.0));

@interface NSFileHandle (NSFileHandleAsynchronousAccess)

- (void)readInBackgroundAndNotifyForModes:(nullable NSArray<NSRunLoopMode> *)modes;
- (void)readInBackgroundAndNotify;

- (void)readToEndOfFileInBackgroundAndNotifyForModes:(nullable NSArray<NSRunLoopMode> *)modes;
- (void)readToEndOfFileInBackgroundAndNotify;

- (void)acceptConnectionInBackgroundAndNotifyForModes:(nullable NSArray<NSRunLoopMode> *)modes;
- (void)acceptConnectionInBackgroundAndNotify;

- (void)waitForDataInBackgroundAndNotifyForModes:(nullable NSArray<NSRunLoopMode> *)modes;
- (void)waitForDataInBackgroundAndNotify;

#ifdef __BLOCKS__
@property (nullable, copy) void (^readabilityHandler)(NSFileHandle *)  API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0));
@property (nullable, copy) void (^writeabilityHandler)(NSFileHandle *) API_AVAILABLE(macos(10.7), ios(5.0), watchos(2.0), tvos(9.0));
#endif

@end

@interface NSFileHandle (NSFileHandlePlatformSpecific)

- (instancetype)initWithFileDescriptor:(int)fd;

@property (readonly) int fileDescriptor;

@end

@interface NSPipe : NSObject

@property (readonly, retain) NSFileHandle *fileHandleForReading;
@property (readonly, retain) NSFileHandle *fileHandleForWriting;

+ (NSPipe *)pipe;

@end
NS_ASSUME_NONNULL_END

