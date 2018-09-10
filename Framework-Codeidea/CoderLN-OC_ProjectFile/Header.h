/*
 * Header.h 效率开发常用宏
 * 创建 cmd+n -> HeaderFile
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

//#ifndef PchHeader_h
//#define PchHeader_h
//
//#endif /* PchHeader_h */

🏃🏻‍♂️
#pragma mark - 【颜色宏相关】
/*
 概念：
    颜色：3种颜色通道 R G B，颜色表达方式：24位,32位，每一个颜色通道是8位,范围(0~256)
 
 表现方式一：（R:213, G:213, B:213）10进制
    [UIColor colorWithRed:(r) / 255.0 green:(g) / 255.0 blue:(b) / 255.0 alpha:a]
 
 表现方式二：（#ffffff）16进制
    #ffffff   -> f=15
    R:FF => 10进制 15 * 16^0 + 15 * 16^1 = 255
    G:FF => 255
    B:FF => 255
 
 注解：
    #号表示：美工16进制表示形式
    0x符号表示：OC 16进制表达式
 */


#pragma mark -RGB
#define RGBA(r,g,b,a)   [UIColor colorWithRed:(r) / 256.0 green:(g) / 256.0 blue:(b) / 256.0 alpha:a]
#define RGB(r,g,b)      RGBA(r,g,b,1.0)
//随机颜色
#define kRandomColor    RGBA(arc4random_uniform(255),arc4random_uniform(255),arc4random_uniform(255))
//十六进制示例：UIColorFromRGB(0xff6a50);
#define kColorFromRGB(RGBValue) [UIColor colorWithRed:((float)((RGBValue & 0xFF0000) >> 16))/255.0 green:((float)((RGBValue & 0xFF00) >> 8))/255.0 blue:((float)(RGBValue & 0xFF))/255.0 alpha:1.0]


#pragma mark -常用统一颜色的宏
//统一背景颜色
#define kUnifiedBgColor             RGB(206,206,206)
#define kControllerViewBGColor      RGBA(237,237,237,1.0)
//统一控制器的背景颜色
#define kUnifiedBackgroundColor         RGB(237, 236, 239)
//分割线颜色
#define kLineColor                  RGBA(29, 29, 38, 0.05)
//标题黑色颜色
#define kTitleBlackColor            RGBA(28,28,28,1.0)
//标题灰色颜色
#define kTitleGrayColor             RGBA(144,144,144,1.0)
//清空颜色
#define kClearColor                 [UIColor clearColor]



#pragma mark -控制台颜色
//彩色打印
#define LogBlue(frmt, ...)          NSLog((XCODE_COLORS_ESCAPE @"fg0,0,255;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)
#define LogRed(frmt, ...)           NSLog((XCODE_COLORS_ESCAPE @"fg255,0,0;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)
#define LogGreen(frmt, ...)         NSLog((XCODE_COLORS_ESCAPE @"fg0,255,0;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)

//控制台颜色插件
#define XCODE_COLORS_ESCAPE         @"\033["
#define XCODE_COLORS_RESET_FG       XCODE_COLORS_ESCAPE @"fg;" // Clear any foreground color
#define XCODE_COLORS_RESET_BG       XCODE_COLORS_ESCAPE @"bg;" // Clear any background color
#define XCODE_COLORS_RESET          XCODE_COLORS_ESCAPE @";"   // Clear any foreground or background color







🏃🏻‍♂️
#pragma mark - 【系统宏相关】

#pragma mark -屏幕尺寸
// 屏幕尺寸
#define kScreenSize           [[UIScreen mainScreen] bounds].size
#define kScreenWidth          [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight         [[UIScreen mainScreen] bounds].size.height
#define iphone6P              (kScreenH == 736)
#define iphone6               (kScreenH == 667)
#define iphone5               (kScreenH == 568)
#define iphone4               (kScreenH == 480)

#define kScreenHeightScale    [[UIScreen mainScreen] bounds].size.height/667.0
#define kScreenWidthScale     [[UIScreen mainScreen] bounds].size.height/375.0
#define kScaleFor6S(value)    (kScreenWidth/375.0)*value

// 窗体
#define kKEY_WINDOW           [UIApplication sharedApplication].keyWindow
// AppDelegate
#define kAPP_DELEGATE         [UIApplication sharedApplication].delegate
// UserDefaults
#define kUSERDEFAULT          [NSUserDefaults standardUserDefaults]


#pragma mark -版本号
//系统版本号 e.g. @"4.0"
#define kSystemVersion        [[[UIDevice currentDevice] systemVersion] doubleValue]
//设配型号 e.g. @"iPhone", @"iPod touch"
#define DeviceModel [UIDevice currentDevice].model
//系统名称 e.g. @"iOS"
#define DeviceName [UIDevice currentDevice].systemName

// APP版本号
#define KAPP_VERSION          [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
// APP编译版本号
#define KAPP_BUILD            [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

// 获取当前语言
#define KCURRENT_LANGUAGE   ([[NSLocale preferredLanguages] objectAtIndex:0])

// 获取App软件名称（项目Info.plist）
#define KAPP_NAME  [NSBundle mainBundle].infoDictionary[@"CFBundleName"];
#define KAPP_NAME1  [NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey];


#pragma mark -真机
// 判断是否为iPhone
#define KIS_IPHONE          (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

// 判断是真机还是模拟器
#if TARGET_OS_IPHONE
// 真机
#endif
#if TARGET_IPHONE_SIMULATOR
// 模拟器
#endif



🏃🏻‍♂️
#pragma mark - 【带参数的宏】

// 加载图片
#define kImageName(imageName)           [UIImage imageNamed:imageName]

// 设置字体
#define kFontSize(fontSize)             [UIFont systemFontOfSize:fontSize]

// 格式化字符串
#define kFormat(string, parameters...)  [NSString stringWithFormat:string, parameters]

















🏃🏻‍♂️
#pragma mark - 【自定义Log打印日志】


#pragma mark -测试和发布打印
#ifdef  DEBUG // 测试
#define Log(...) NSLog(__VA_ARGS__)
#define Func  Log(@"%s",__func__)
#define Funcline Log(@"%s, line = %d, %@",__FUNCTION__,__LINE__,[NSThread currentThread]);

#else   // 发布
#define Log(...)
#define Func
#define Funcline
#endif


#pragma mark -打印日志示例
// 打印日志示例：时间戳、函数、行数、功能
// 2016-04-28 14:17:07.106977+0800 NetRequest[28405:520744] -[AFNController netRequest]_block_invoke_2 : 55 成功回调 {success:登录成功}
#ifdef DEBUG // 测试
#define MyLog(...) NSLog(@"%s : %d %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else // 发布
#define MyLog(...)
#endif


// 打印日志示例：函数、行数、功能
// -[TestController.m netRequest]_block_invoke_2 : 55     成功回调 {success:登录成功}
#ifdef DEBUG // 测试
#define MyLog(FORMAT, ...) fprintf(stderr,"%s : %d\t%s\n",__func__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else // 发布
#define MyLog(...)
#endif


// 打印日志示例：类、行数、功能
// MyLog(@"成功回调 %@",responseObject);  --->  TestController.m : 55    成功回调 {success:登录成功}
#ifdef DEBUG
#define MyLog(FORMAT, ...) fprintf(stderr,"%s : %d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define MyLog(...)
#endif












🏃🏻‍♂️
#pragma mark - 【获取文件全路径宏】
/**
 NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory directory：获取那个文件路径, NSSearchPathDomainMask domainMask：从那个路径开始, BOOL expandTilde：是否展开);
 */
// 捆绑包目录
#define BundlePath      [NSBundle mainBundle].bundlePath

// 获取bundle资源文件目录(主要存放可执行文件以及copy到bundle中)
#define ResourcePath    [NSBundle mainBundle].resourcePath

// 1.获取 沙盒 主目录
#define HomeDirectory   NSHomeDirectory()

// 2.获取 Documents 路径
#define DocumentsPath    NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject
#define DocumentsPath1   [[NSFileManager defaultManager] URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask].firstObject)
#define DocumentsPath2   [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"]

// 3.获取 Library 路径
#define LibraryPath     NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject
#define LibraryPath1    [[NSFileManager defaultManager] URLsForDirectory:NSLibraryDirectory inDomains:NSUserDomainMask].firstObject)
#define LibraryPath2    [NSHomeDirectory() stringByAppendingPathComponent:@"Library"])

// 4.获取 Caches 路径
#define CachesPath      NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject
#define CachesPath1     [[NSFileManager defaultManager] URLsForDirectory:NSCachesDirectory inDomains:NSUserDomainMask].firstObject)

// 5.获取 tep 路径
#define TmpPath         NSTemporaryDirectory()
#define TmpPath1        [NSHomeDirectory() stringByAppendingPathComponent:@"tmp"]


//通常把数据请求下来的数据写成Plist便于观察
//【#filename -> "filename"】、【@#filename -> @"filename"】
#define WriteToPlist(filename) [responseObject writeToFile:[NSString stringWithFormat:@"/Users/sunhui/Desktop/%@.plist",@#filename] atomically:YES];








🏃🏻‍♂️
#pragma mark - 日期、时间

// 获取一段时间间隔
#define KSTART_TIME             CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define KEND_TIME               NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)

















🏃🏻‍♂️
#pragma mark - 【Xcode 自定义字体】

static NSString* const          FONT_TITLE = @"PingFangSC-Regular";//常规
static NSString* const          FONT_SUBTITLE = @"PingFangSC-Light";//细体
static NSString* const          FONT_PING_FANG_SC_ULTRALIGHT = @"PingFangSC-Ultralight";//超细
static NSString* const          FONT_PING_FANG_SC_MEDIUM = @"PingFangSC-Medium";//中黑

static NSString * const         Arial_BoldMT = @"Arial-BoldMT";//Arial粗体
static NSString * const         Arial_MT = @"ArialMT";//Arial粗体










🏃🏻‍♂️
#pragma mark - 【转换 & 判断】

// 角度 转成 弧度
#define ANGLE_TO_RADIANS(angle)             (angle)/(180.0*M_PI)
// 弧度 转成 角度
#define RADIANS_TO_ANGLE(radians)           (radians)*(180.0/M_PI)

// Number 转 String
#define KINT_TRANSLATE_STR(int_str)         [NSString stringWithFormat:@"%d",int_str];
#define KFLOAT_TRANSLATE_STR(float_str)     [NSString stringWithFormat:@"%.2d",float_str];

// 字符串是否为空
#define KSTRING_IS_EMPTY(str)               ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
// 数组是否为空
#define KARRAY_IS_EMPTY(array)              (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
// 字典是否为空
#define KDICT_IS_EMPTY(dic)                 (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
// 是否是空对象
#define KOBJECT_IS_EMPYT(_object)           (_object == nil \
                                            || [_object isKindOfClass:[NSNull class]] \
                                            || ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
                                            || ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

// 弱引用/强引用
#define KWeak_self(type)        __weak   typeof(type)   weak##type = type;
#define KStrong_self(type)      __strong typeof(type) type = weak##type;























🏃🏻‍♂️
#pragma mark - 【用户提示】


#define ShowHud(str)    do {  \
    MBProgressHUD *hud1 = [MBProgressHUD showHUDAddedTo:self.view animated:YES];\
    hud1.mode = MBProgressHUDModeText;\
    hud1.removeFromSuperViewOnHide = YES;\
    hud1.labelText = str;\
    hud1.yOffset = -50;\
    [hud1 hide:YES afterDelay:1.5];\
} while(0)


---
// View 圆角和加边框
#define KVIEW_BORDER_RADIUS(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

// View 圆角
#define KVIEW_RADIUS(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]








🏃🏻‍♂️
#pragma mark - 【快速创建单例】

// .h 声明
#define single_interface(class)  + (class *)shared##class;

// .m 实现
// \ 代表下一行也属于宏
// ## 是分隔符
#define single_implementation(class) \
static class *_instance; \
\
+ (class *)shared##class \
{ \
    if (_instance == nil) { \
        _instance = [[self alloc] init]; \
    } \
    return _instance; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [super allocWithZone:zone]; \
    }); \
    return _instance; \
}







🏃🏻‍♂️
#pragma mark - 【Random 随机数据】

//随机数据
#define MJRandomData    [NSString stringWithFormat:@"随机数据---%d", arc4random_uniform(1000000)]
#define titleFont(r)    kSystemVersion>=9.0?[UIFont fontWithName:FONT_TITLE size:r*1.0]:[UIFont systemFontOfSize:r*1.0]





































