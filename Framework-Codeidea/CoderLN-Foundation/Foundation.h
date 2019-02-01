/*
 * Foundation.h
 *
 * Foundation (c) 1994-2017
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

/**
 iOS Foundation 框架 是 Objective-C 语言应用于苹果移动设备的基础功能库，功能之强大，本专题 致力于将苹果官网的海量的文档进行 归类整理，框架各分类文件注解，并对每一类中常用的功能进行案例渐进式解析，以 简化初学者入门和老手回顾的繁索过程，尽快切入主题，快速应用起来。
 */


#include <CoreFoundation/CoreFoundation.h>    <#注解完成#>

#import <Foundation/NSObjCRuntime.h>    <#注解完成#>

#import <Foundation/NSArray.h>    <#注解完成#>
#import <Foundation/NSAutoreleasePool.h>    <#注解完成#>
#import <Foundation/NSBundle.h>    <#注解完成#>
#import <Foundation/NSByteOrder.h>    <#注解完成#>
#import <Foundation/NSCalendar.h>    <#注解完成#>
#import <Foundation/NSCharacterSet.h>    <#注解完成#>
#import <Foundation/NSCoder.h>    <#注解完成#>
#import <Foundation/NSData.h>    <#注解完成#>
#import <Foundation/NSDate.h>    <#注解完成#>
#import <Foundation/NSDateInterval.h>    <#注解完成#>
#import <Foundation/NSDateFormatter.h>    <#注解完成#>
#import <Foundation/NSDateIntervalFormatter.h>    <#注解完成#>
#import <Foundation/NSISO8601DateFormatter.h>    <#注解完成#>
#import <Foundation/NSMassFormatter.h>    <#注解完成#>
#import <Foundation/NSLengthFormatter.h>    <#注解完成#>
#import <Foundation/NSEnergyFormatter.h>    <#注解完成#>
#import <Foundation/NSMeasurement.h>    <#注解完成#>
#import <Foundation/NSMeasurementFormatter.h>    <#注解完成#>
#import <Foundation/NSPersonNameComponents.h>    <#注解完成#>
#import <Foundation/NSPersonNameComponentsFormatter.h>    <#注解完成#>
#import <Foundation/NSDecimal.h>    <#注解完成#>
#import <Foundation/NSDecimalNumber.h>    <#注解完成#>
#import <Foundation/NSDictionary.h>    <#注解完成#>
#import <Foundation/NSEnumerator.h>    <#注解完成#>
#import <Foundation/NSError.h>    <#注解完成#>
#import <Foundation/NSException.h>    <#注解完成#>
#import <Foundation/NSFileHandle.h>    <#注解完成#>
#import <Foundation/NSFileManager.h>    <#注解完成#>
#import <Foundation/NSFormatter.h>    <#注解完成#>
#import <Foundation/NSHashTable.h>    <#注解完成#>
#import <Foundation/NSHTTPCookie.h>    <#注解完成#>
#import <Foundation/NSHTTPCookieStorage.h>    <#注解完成#>
#import <Foundation/NSIndexPath.h>    <#注解完成#>
#import <Foundation/NSIndexSet.h>    <#注解完成#>
#import <Foundation/NSInvocation.h>    <#注解完成#>
#import <Foundation/NSJSONSerialization.h>    <#注解完成#>
#import <Foundation/NSKeyValueCoding.h>    <#注解完成#>
#import <Foundation/NSKeyValueObserving.h>    <#注解完成#>
#import <Foundation/NSKeyedArchiver.h>    <#注解完成#>
#import <Foundation/NSLocale.h>    <#注解完成#>
#import <Foundation/NSLock.h>    <#注解完成#>
#import <Foundation/NSMapTable.h>    <#注解完成#>
#import <Foundation/NSMethodSignature.h>    <#注解完成#>
#import <Foundation/NSNotification.h>    <#注解完成#>
#import <Foundation/NSNotificationQueue.h>    <#注解完成#>
#import <Foundation/NSNull.h>    <#注解完成#>
#import <Foundation/NSNumberFormatter.h>    <#注解完成#>
#import <Foundation/NSObject.h>    <#注解完成#>
#import <Foundation/NSOperation.h>    <#注解完成#>
#import <Foundation/NSOrderedSet.h>    <#注解完成#>
#import <Foundation/NSOrthography.h>    <#注解完成#>
#import <Foundation/NSPathUtilities.h>    <#注解完成#>
#import <Foundation/NSPointerArray.h>    <#注解完成#>
#import <Foundation/NSPointerFunctions.h>    <#注解完成#>
#import <Foundation/NSPort.h>    <#注解完成#>
#import <Foundation/NSProcessInfo.h>    <#注解完成#>
#import <Foundation/NSPropertyList.h>    <#注解完成#>
#import <Foundation/NSProxy.h>    <#注解完成#>
#import <Foundation/NSRange.h>    <#注解完成#>
#import <Foundation/NSRegularExpression.h>    <#注解完成#>
#import <Foundation/NSRunLoop.h>    <#注解完成#>
#import <Foundation/NSScanner.h>    <#注解完成#>
#import <Foundation/NSSet.h>    <#注解完成#>
#import <Foundation/NSSortDescriptor.h>    <#注解完成#>
#import <Foundation/NSStream.h>    <#注解完成#>
#import <Foundation/NSString.h>    <#注解完成#>
#import <Foundation/NSTextCheckingResult.h>    <#注解完成#>
#import <Foundation/NSThread.h>    <#注解完成#>
#import <Foundation/NSTimeZone.h>    <#注解完成#>
#import <Foundation/NSTimer.h>    <#注解完成#>
#import <Foundation/NSUnit.h>    <#注解完成#>
#import <Foundation/NSURL.h>    <#注解完成#>
#import <Foundation/NSURLAuthenticationChallenge.h>    <#注解完成#>
#import <Foundation/NSURLCache.h>    <#注解完成#>
#import <Foundation/NSURLConnection.h>    <#注解完成#>
#import <Foundation/NSURLCredential.h>    <#注解完成#>
#import <Foundation/NSURLCredentialStorage.h>    <#注解完成#>
#import <Foundation/NSURLError.h>    <#注解完成#>
#import <Foundation/NSURLProtectionSpace.h>    <#注解完成#>
#import <Foundation/NSURLProtocol.h>    <#注解完成#>
#import <Foundation/NSURLRequest.h>    <#注解完成#>
#import <Foundation/NSURLResponse.h>    <#注解完成#>
#import <Foundation/NSUserDefaults.h>    <#注解完成#>
#import <Foundation/NSValue.h>    <#注解完成#>
#import <Foundation/NSValueTransformer.h>    <#注解完成#>
#import <Foundation/NSXMLParser.h>    <#注解完成#>
#import <Foundation/NSXPCConnection.h>    <#注解完成#>
#import <Foundation/NSZone.h>    <#注解完成#>

#import <Foundation/FoundationErrors.h>    <#注解完成#>

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || (TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)

#import <Foundation/NSAttributedString.h>    <#注解完成#>
#import <Foundation/NSByteCountFormatter.h>    <#注解完成#>
#import <Foundation/NSCache.h>    <#注解完成#>
#import <Foundation/NSComparisonPredicate.h>    <#注解完成#>
#import <Foundation/NSCompoundPredicate.h>    <#注解完成#>
#import <Foundation/NSDateComponentsFormatter.h>    <#注解完成#>
#import <Foundation/NSExpression.h>    <#注解完成#>
#import <Foundation/NSExtensionContext.h>    <#注解完成#>
#import <Foundation/NSExtensionItem.h>    <#注解完成#>
#import <Foundation/NSExtensionRequestHandling.h>    <#注解完成#>
#import <Foundation/NSFileCoordinator.h>    <#注解完成#>
#import <Foundation/NSFilePresenter.h>    <#注解完成#>
#import <Foundation/NSFileVersion.h>    <#注解完成#>
#import <Foundation/NSFileWrapper.h>    <#注解完成#>
#import <Foundation/NSItemProvider.h>    <#注解完成#>
#import <Foundation/NSLinguisticTagger.h>    <#注解完成#>
#import <Foundation/NSMetadata.h>    <#注解完成#>
#import <Foundation/NSMetadataAttributes.h>    <#注解完成#>
#import <Foundation/NSNetServices.h>    <#注解完成#>
#import <Foundation/NSPredicate.h>    <#注解完成#>
#import <Foundation/NSProgress.h>    <#注解完成#>
#import <Foundation/NSUbiquitousKeyValueStore.h>    <#注解完成#>
#import <Foundation/NSUndoManager.h>    <#注解完成#>
#import <Foundation/NSURLSession.h>    <#注解完成#>
#import <Foundation/NSUserActivity.h>    <#注解完成#>
#import <Foundation/NSUUID.h>    <#注解完成#>
#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE)) || TARGET_OS_WIN32

#import <Foundation/NSArchiver.h>    <#注解完成#>
#import <Foundation/NSBackgroundActivityScheduler.h>    <#注解完成#>
#import <Foundation/NSCalendarDate.h>    <#注解完成#>
#import <Foundation/NSConnection.h>    <#注解完成#>
#import <Foundation/NSDistantObject.h>    <#注解完成#>
#import <Foundation/NSDistributedNotificationCenter.h>    <#注解完成#>
#import <Foundation/NSGeometry.h>    <#注解完成#>
#import <Foundation/NSPortCoder.h>    <#注解完成#>
#import <Foundation/NSPortMessage.h>    <#注解完成#>
#import <Foundation/NSPortNameServer.h>    <#注解完成#>
#import <Foundation/NSProtocolChecker.h>    <#注解完成#>
#import <Foundation/NSTask.h>    <#注解完成#>
#import <Foundation/NSXMLDTD.h>    <#注解完成#>
#import <Foundation/NSXMLDTDNode.h>    <#注解完成#>
#import <Foundation/NSXMLDocument.h>    <#注解完成#>
#import <Foundation/NSXMLElement.h>    <#注解完成#>
#import <Foundation/NSXMLNode.h>    <#注解完成#>
#import <Foundation/NSXMLNodeOptions.h>    <#注解完成#>
#import <Foundation/NSURLDownload.h>    <#注解完成#>
#import <Foundation/NSURLHandle.h>    <#注解完成#>

#endif

#if (TARGET_OS_MAC && !(TARGET_OS_EMBEDDED || TARGET_OS_IPHONE))

#import <Foundation/NSAffineTransform.h>    <#注解完成#>
#import <Foundation/NSAppleEventDescriptor.h>    <#注解完成#>
#import <Foundation/NSAppleEventManager.h>    <#注解完成#>
#import <Foundation/NSAppleScript.h>    <#注解完成#>
#import <Foundation/NSClassDescription.h>    <#注解完成#>
#import <Foundation/NSDistributedLock.h>    <#注解完成#>
#import <Foundation/NSGarbageCollector.h>    <#注解完成#>
#import <Foundation/NSHFSFileTypes.h>    <#注解完成#>
#import <Foundation/NSHost.h>    <#注解完成#>
#import <Foundation/NSObjectScripting.h>    <#注解完成#>
#import <Foundation/NSScriptClassDescription.h>    <#注解完成#>
#import <Foundation/NSScriptCoercionHandler.h>    <#注解完成#>
#import <Foundation/NSScriptCommand.h>    <#注解完成#>
#import <Foundation/NSScriptCommandDescription.h>    <#注解完成#>
#import <Foundation/NSScriptExecutionContext.h>    <#注解完成#>
#import <Foundation/NSScriptKeyValueCoding.h>    <#注解完成#>
#import <Foundation/NSScriptObjectSpecifiers.h>    <#注解完成#>
#import <Foundation/NSScriptStandardSuiteCommands.h>    <#注解完成#>
#import <Foundation/NSScriptSuiteRegistry.h>    <#注解完成#>
#import <Foundation/NSScriptWhoseTests.h>    <#注解完成#>
#import <Foundation/NSSpellServer.h>    <#注解完成#>
#import <Foundation/NSUserNotification.h>    <#注解完成#>
#import <Foundation/NSUserScriptTask.h>    <#注解完成#>

#endif

#import <Foundation/FoundationLegacySwiftCompatibility.h>    <#注解完成#>

