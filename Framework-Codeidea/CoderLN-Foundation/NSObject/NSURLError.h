/*
 * NSURLError.h 苹果相应的错误码
 *
 * Foundation (c) 2003-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#if TARGET_OS_IPHONE
#if __has_include(<CFNetwork/CFNetwork.h>)
#import <CFNetwork/CFNetwork.h>
#endif
#elif TARGET_OS_WIN32
#import <CFNetwork/CFNetwork.h>
#else
#import <CoreServices/CoreServices.h>
#endif

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSError.h>

@class NSString;

NS_ASSUME_NONNULL_BEGIN

/*
 @discussion Constants used by NSError to differentiate between "domains" of error codes, serving as a discriminator for error codes that originate from different subsystems or sources.
 @constant NSURLErrorDomain Indicates an NSURL error.
 */
FOUNDATION_EXPORT NSErrorDomain const NSURLErrorDomain;

/*!
 @const NSURLErrorFailingURLErrorKey
 @abstract The NSError userInfo dictionary key used to store and retrieve the URL which caused a load to fail.
 */
FOUNDATION_EXPORT NSString * const NSURLErrorFailingURLErrorKey API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

/*!
 @const NSURLErrorFailingURLStringErrorKey
 @abstract The NSError userInfo dictionary key used to store and retrieve the NSString object for the URL which caused a load to fail.
 @discussion This constant supersedes NSErrorFailingURLStringKey, which was deprecated in Mac OS X 10.6.  Both constants refer to the same value for backward-compatibility, but this symbol name has a better prefix.
 */
FOUNDATION_EXPORT NSString * const NSURLErrorFailingURLStringErrorKey API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

/*!
 @const NSErrorFailingURLStringKey
 @abstract The NSError userInfo dictionary key used to store and retrieve the NSString object for the URL which caused a load to fail.
 @discussion This constant is deprecated in Mac OS X 10.6, and is superseded by NSURLErrorFailingURLStringErrorKey.  Both constants refer to the same value for backward-compatibility, but the new symbol name has a better prefix.
 */
FOUNDATION_EXPORT NSString * const NSErrorFailingURLStringKey API_DEPRECATED("Use NSURLErrorFailingURLStringErrorKey instead", macos(10.0,10.6), ios(2.0,4.0), watchos(2.0,2.0), tvos(9.0,9.0));

/*!
 @const NSURLErrorFailingURLPeerTrustErrorKey
 @abstract The NSError userInfo dictionary key used to store and retrieve the SecTrustRef object representing the state of a failed SSL handshake.
 */
FOUNDATION_EXPORT NSString * const NSURLErrorFailingURLPeerTrustErrorKey API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0));

/*!
 @const NSURLErrorBackgroundTaskCancelledReasonKey
 @abstract The NSError userInfo dictionary key used to store and retrieve the NSNumber corresponding to the reason why a background
 NSURLSessionTask was cancelled
 */
FOUNDATION_EXPORT NSString * const NSURLErrorBackgroundTaskCancelledReasonKey API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0));

/*!
 @enum Codes associated with NSURLErrorBackgroundTaskCancelledReasonKey
 @abstract Constants used by NSError to indicate why a background NSURLSessionTask was cancelled.
 */

NS_ENUM(NSInteger)
{
    NSURLErrorCancelledReasonUserForceQuitApplication =    0,
    NSURLErrorCancelledReasonBackgroundUpdatesDisabled =   1,
    NSURLErrorCancelledReasonInsufficientSystemResources API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = 2,
    
    } API_AVAILABLE(macos(10.10), ios(7.0), watchos(2.0), tvos(9.0));
    
    /*!
     @enum NSURL-related Error Codes：NSURL相关的错误码
     @abstract Constants used by NSError to indicate errors in the NSURL domain
     */
    NS_ERROR_ENUM(NSURLErrorDomain)
    {
        NSURLErrorUnknown =             -1,//【未知错误】
        NSURLErrorCancelled =             -999,//【取消请求】
        NSURLErrorBadURL =                 -1000,//【url错误】
        NSURLErrorTimedOut =             -1001,//【请求超时】
        NSURLErrorUnsupportedURL =             -1002,//【不支持的URL】
        NSURLErrorCannotFindHost =             -1003,//【未能找到使用指定主机名的服务器】
        NSURLErrorCannotConnectToHost =         -1004,//【无法连接主机】
        NSURLErrorNetworkConnectionLost =         -1005,//【网络连接已中断】
        NSURLErrorDNSLookupFailed =         -1006,//【DNS查找失败】
        NSURLErrorHTTPTooManyRedirects =         -1007,//【HTTP太多重定向】
        NSURLErrorResourceUnavailable =         -1008,//【资源不可用】
        NSURLErrorNotConnectedToInternet =         -1009,//【没有网络】
        NSURLErrorRedirectToNonExistentLocation =     -1010,//【重定向到不存在的位置】
        NSURLErrorBadServerResponse =         -1011,//【服务器响应不良】
        NSURLErrorUserCancelledAuthentication =     -1012,//【用户取消认证】
        NSURLErrorUserAuthenticationRequired =     -1013,//【需要用户身份验证】
        NSURLErrorZeroByteResource =         -1014,//【-】
        NSURLErrorCannotDecodeRawData =             -1015,//【-】
        NSURLErrorCannotDecodeContentData =         -1016,//【-】
        NSURLErrorCannotParseResponse =             -1017,//【-】
        NSURLErrorAppTransportSecurityRequiresSecureConnection API_AVAILABLE(macos(10.11), ios(9.0), watchos(2.0), tvos(9.0)) = -1022,//【-】
        NSURLErrorFileDoesNotExist =         -1100,//【-】
        NSURLErrorFileIsDirectory =         -1101,//【-】
        NSURLErrorNoPermissionsToReadFile =     -1102,//【-】
        NSURLErrorDataLengthExceedsMaximum API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) =    -1103,//【-】
        NSURLErrorFileOutsideSafeArea API_AVAILABLE(macos(10.12.4), ios(10.3), watchos(3.2), tvos(10.2)) = -1104,//【-】
        
        // SSL errors
        NSURLErrorSecureConnectionFailed =         -1200,//【-】
        NSURLErrorServerCertificateHasBadDate =     -1201,//【-】
        NSURLErrorServerCertificateUntrusted =     -1202,//【-】
        NSURLErrorServerCertificateHasUnknownRoot = -1203,//【-】
        NSURLErrorServerCertificateNotYetValid =     -1204,//【-】
        NSURLErrorClientCertificateRejected =     -1205,//【-】
        NSURLErrorClientCertificateRequired =    -1206,//【-】
        NSURLErrorCannotLoadFromNetwork =         -2000,//【-】
        
        // Download and file I/O errors
        NSURLErrorCannotCreateFile =         -3000,//【-】
        NSURLErrorCannotOpenFile =             -3001,//【-】
        NSURLErrorCannotCloseFile =         -3002,//【-】
        NSURLErrorCannotWriteToFile =         -3003,//【-】
        NSURLErrorCannotRemoveFile =         -3004,//【-】
        NSURLErrorCannotMoveFile =             -3005,//【-】
        NSURLErrorDownloadDecodingFailedMidStream = -3006,//【-】
        NSURLErrorDownloadDecodingFailedToComplete =-3007,//【-】
        
        NSURLErrorInternationalRoamingOff API_AVAILABLE(macos(10.7), ios(3.0), watchos(2.0), tvos(9.0)) =         -1018,//【-】
        NSURLErrorCallIsActive API_AVAILABLE(macos(10.7), ios(3.0), watchos(2.0), tvos(9.0)) =                    -1019,//【-】
        NSURLErrorDataNotAllowed API_AVAILABLE(macos(10.7), ios(3.0), watchos(2.0), tvos(9.0)) =                  -1020,//【-】
        NSURLErrorRequestBodyStreamExhausted API_AVAILABLE(macos(10.7), ios(3.0), watchos(2.0), tvos(9.0)) =      -1021,//【-】
        
        NSURLErrorBackgroundSessionRequiresSharedContainer API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = -995,//【-】
        NSURLErrorBackgroundSessionInUseByAnotherProcess API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0)) = -996,//【-】
        NSURLErrorBackgroundSessionWasDisconnected API_AVAILABLE(macos(10.10), ios(8.0), watchos(2.0), tvos(9.0))= -997,//【-】
    };
    
## Status Code：常见状态代码、状态描述、说明：
    200 OK      //客户端请求成功
    400 Bad Request  //客户端请求有语法错误，不能被服务器所理解
    401 Unauthorized //请求未经授权，这个状态代码必须和WWW-Authenticate报头域一起使用
    403 Forbidden  //服务器收到请求，但是拒绝提供服务
    404 Not Found  //请求资源不存在，eg：输入了错误的URL
    500 Internal Server Error //服务器发生不可预期的错误
    503 Server Unavailable  //服务器当前不能处理客户端的请求，一段时间后可能恢复正常
    eg：HTTP/1.1 200 OK （CRLF）
 
    
NS_ASSUME_NONNULL_END
    

