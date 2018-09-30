/*
 * NSPathUtilities.h 开发常用路径设置相关
 *
 * Foundation (c) 1994-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */


#import <Foundation/NSString.h>
#import <Foundation/NSArray.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (NSStringPathExtensions)

+ (NSString *)pathWithComponents:(NSArray<NSString *> *)components;
@property (readonly, copy) NSArray<NSString *> *pathComponents;

@property (getter=isAbsolutePath, readonly) BOOL absolutePath;

@property (readonly, copy) NSString *lastPathComponent;
@property (readonly, copy) NSString *stringByDeletingLastPathComponent;
/**
 拼接字符串
 自动添加 /
 */
- (NSString *)stringByAppendingPathComponent:(NSString *)str;

@property (readonly, copy) NSString *pathExtension;
@property (readonly, copy) NSString *stringByDeletingPathExtension;
- (nullable NSString *)stringByAppendingPathExtension:(NSString *)str;

@property (readonly, copy) NSString *stringByAbbreviatingWithTildeInPath;
@property (readonly, copy) NSString *stringByExpandingTildeInPath;

@property (readonly, copy) NSString *stringByStandardizingPath;

@property (readonly, copy) NSString *stringByResolvingSymlinksInPath;

- (NSArray<NSString *> *)stringsByAppendingPaths:(NSArray<NSString *> *)paths;

- (NSUInteger)completePathIntoString:(NSString * _Nullable * _Nullable)outputName caseSensitive:(BOOL)flag matchesIntoArray:(NSArray<NSString *> * _Nullable * _Nullable)outputArray filterTypes:(nullable NSArray<NSString *> *)filterTypes;

@property (readonly) const char *fileSystemRepresentation NS_RETURNS_INNER_POINTER;
- (BOOL)getFileSystemRepresentation:(char *)cname maxLength:(NSUInteger)max;

@end

@interface NSArray<ObjectType> (NSArrayPathExtensions)

- (NSArray<NSString *> *)pathsMatchingExtensions:(NSArray<NSString *> *)filterTypes;

@end

FOUNDATION_EXPORT NSString *NSUserName(void);
FOUNDATION_EXPORT NSString *NSFullUserName(void);

FOUNDATION_EXPORT NSString *NSHomeDirectory(void);
FOUNDATION_EXPORT NSString * _Nullable NSHomeDirectoryForUser(NSString * _Nullable userName);

FOUNDATION_EXPORT NSString *NSTemporaryDirectory(void);

FOUNDATION_EXPORT NSString *NSOpenStepRootDirectory(void);

typedef NS_ENUM(NSUInteger, NSSearchPathDirectory) {
    NSApplicationDirectory = 1,             // supported applications (Applications)
    NSDemoApplicationDirectory,             // unsupported applications, demonstration versions (Demos)
    NSDeveloperApplicationDirectory,        // developer applications (Developer/Applications). DEPRECATED - there is no one single Developer directory.
    NSAdminApplicationDirectory,            // system and network administration applications (Administration)
    NSLibraryDirectory,【Library】                     // various documentation, support, and configuration files, resources (Library)
    NSDeveloperDirectory,                   // developer resources (Developer) DEPRECATED - there is no one single Developer directory.
    NSUserDirectory,                        // user home directories (Users)
    NSDocumentationDirectory,               // documentation (Documentation)
    NSDocumentDirectory,【Documents】                    // documents (Documents)
    NSCoreServiceDirectory,                 // location of CoreServices directory (System/Library/CoreServices)
    NSAutosavedInformationDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 11,   // location of autosaved documents (Documents/Autosaved)
    NSDesktopDirectory = 12,                // location of user's desktop
    NSCachesDirectory = 13,                 // location of discardable cache files (Library/Caches)
    NSApplicationSupportDirectory = 14,     // location of application support files (plug-ins, etc) (Library/Application Support)
    NSDownloadsDirectory API_AVAILABLE(macos(10.5), ios(2.0), watchos(2.0), tvos(9.0)) = 15,              // location of the user's "Downloads" directory
    NSInputMethodsDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 16,           // input methods (Library/Input Methods)
    NSMoviesDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 17,                 // location of user's Movies directory (~/Movies)
    NSMusicDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 18,                  // location of user's Music directory (~/Music)
    NSPicturesDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 19,               // location of user's Pictures directory (~/Pictures)
    NSPrinterDescriptionDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 20,     // location of system's PPDs directory (Library/Printers/PPDs)
    NSSharedPublicDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 21,           // location of user's Public sharing directory (~/Public)
    NSPreferencePanesDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 22,        // location of the PreferencePanes directory for use with System Preferences (Library/PreferencePanes)
    NSApplicationScriptsDirectory NS_ENUM_AVAILABLE(10_8, NA) = 23,      // location of the user scripts folder for the calling application (~/Library/Application Scripts/code-signing-id)
    NSItemReplacementDirectory API_AVAILABLE(macos(10.6), ios(4.0), watchos(2.0), tvos(9.0)) = 99,        // For use with NSFileManager's URLForDirectory:inDomain:appropriateForURL:create:error:
    NSAllApplicationsDirectory = 100,       // all directories where applications can occur
    NSAllLibrariesDirectory = 101,          // all directories where resources can occur
    NSTrashDirectory API_AVAILABLE(macos(10.8), ios(11.0)) API_UNAVAILABLE(watchos, tvos) = 102             // location of Trash directory
    
};

typedef NS_OPTIONS(NSUInteger, NSSearchPathDomainMask) {
    NSUserDomainMask = 1,       // user's home directory --- place to install user's personal items (~)
    NSLocalDomainMask = 2,      // local to the current machine --- place to install items available to everyone on this machine (/Library)
    NSNetworkDomainMask = 4,    // publically available location in the local area network --- place to install items available on the network (/Network)
    NSSystemDomainMask = 8,     // provided by Apple, unmodifiable (/System)
    NSAllDomainsMask = 0x0ffff  // all domains: all of the above and future items
};

FOUNDATION_EXPORT NSArray<NSString *> *NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory directory, NSSearchPathDomainMask domainMask, BOOL expandTilde);

NS_ASSUME_NONNULL_END
# * Author: 白开水ln  -  WechatPublic：Codeidea  -  Repository：github.com/CoderLN/Framework-CoderLN













//----------------------- 获取目录全路径 ------------------------//
//





 // 1.
 NSLog(@"bundlePath %@",[NSBundle mainBundle].bundlePath); // 捆绑包目录
 NSLog(@"bundlePath %@",[NSBundle mainBundle].resourcePath); // 获取bundle资源文件目录(主要存放可执行文件以及copy到bundle中)

 // 2.沙盒主目录
 NSString *homeDir = NSHomeDirectory();
 NSLog(@"homeDir %@",homeDir);

 // 3.Documents目录
 NSLog(@"Documents url %@",[[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask].firstObject);
 NSLog(@"Documents pathA %@",NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject);
 NSLog(@"Documents pathB %@",[NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]);

 // 4.Library目录
 NSLog(@"Library url %@",[[NSFileManager defaultManager] URLsForDirectory:NSLibraryDirectory inDomains:NSUserDomainMask].firstObject);
 NSLog(@"Library pathA %@",NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject);
 NSLog(@"Library pathB %@",[NSHomeDirectory() stringByAppendingPathComponent:@"Library"]);

 // 5.Caches目录
 NSLog(@"Caches url %@",[[NSFileManager defaultManager] URLsForDirectory:NSCachesDirectory inDomains:NSUserDomainMask].firstObject);
 NSLog(@"Caches path %@",NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject);

 // 6.Preferences目录
    求解 ？ 求解 ？ 求解 ？


 // 7.tmp目录
 NSLog(@"tmpA %@",NSTemporaryDirectory());
 NSLog(@"tmpB %@",[NSHomeDirectory() stringByAppendingPathComponent:@"tmp"]);





