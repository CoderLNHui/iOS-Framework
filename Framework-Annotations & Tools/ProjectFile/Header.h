/*
 * Header.h【高效开发常用宏-适时慎用】
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 *
 * 说明：转载请注明出处，GitHub(https://github.com/CustomPBWaters) 和 简书(http://www.jianshu.com/u/fd745d76c816)，谢谢。
 */

//#ifndef PchHeader_h
//#define PchHeader_h
//
//#endif /* PchHeader_h */







//--------------------------- 『WechatPublic-Codeidea』【Xcode】 ------------------------------//
// ↓


//彩色打印
#define LogBlue(frmt, ...)          NSLog((XCODE_COLORS_ESCAPE @"fg0,0,255;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)
#define LogRed(frmt, ...)           NSLog((XCODE_COLORS_ESCAPE @"fg255,0,0;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)
#define LogGreen(frmt, ...)         NSLog((XCODE_COLORS_ESCAPE @"fg0,255,0;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)

---

//控制台颜色插件
#define XCODE_COLORS_ESCAPE         @"\033["
#define XCODE_COLORS_RESET_FG       XCODE_COLORS_ESCAPE @"fg;" // Clear any foreground color
#define XCODE_COLORS_RESET_BG       XCODE_COLORS_ESCAPE @"bg;" // Clear any background color
#define XCODE_COLORS_RESET          XCODE_COLORS_ESCAPE @";"   // Clear any foreground or background color


---

#define titleFont(r)                kSystemVersion>=9.0?[UIFont fontWithName:FONT_TITLE size:r*1.0]:[UIFont systemFontOfSize:r*1.0]
#define rgb(r,g,b,a)                [UIColor colorWithRed:(r*1.0)/255 green:(g*1.0)/255 blue:(b*1.0)/255 alpha:(a*1.0)]
#define kLineColor                  rgb(29, 29, 38, 0.05)
#define kControllerViewBackGroundColor      rgb(237,237,237,1.0)
#define kSubjectMainColor                   rgb(0, 185, 255, 1.0)
#define kTitleBlackColor                    rgb(28,28,28,1.0)
#define kTitleGrayColor                     rgb(144,144,144,1.0)
#define kClearColor                         [UIColor clearColor]
#define kTimeOutLength                      30.0f

---

static NSString* const          FONT_TITLE = @"PingFangSC-Regular";//常规
static NSString* const          FONT_SUBTITLE = @"PingFangSC-Light";//细体
static NSString* const          FONT_PING_FANG_SC_ULTRALIGHT = @"PingFangSC-Ultralight";//超细
static NSString* const          FONT_PING_FANG_SC_MEDIUM = @"PingFangSC-Medium";//中黑

static NSString * const         Arial_BoldMT = @"Arial-BoldMT";//Arial粗体
static NSString * const         Arial_MT = @"ArialMT";//Arial粗体





// ↑
//--------------------------- 【Xcode】 ------------------------------//

















//--------------------------- 『WechatPublic-Codeidea』【系统相关】 ------------------------------//
// ↓

// 屏幕尺寸
#define kScreenSize           [[UIScreen mainScreen] bounds].size
#define kScreenWidth          [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight         [[UIScreen mainScreen] bounds].size.height

#define kHeightScale          [[UIScreen mainScreen] bounds].size.height/667.0
#define kWidthScale           [[UIScreen mainScreen] bounds].size.height/375.0
#define kScaleFor6S(value)    (kScreenWidth/375.0)*value

// 窗体
#define kKEY_WINDOW         [UIApplication sharedApplication].keyWindow
// Aplication
#define kAPPLICATION        [UIApplication sharedApplication]
// AppDelegate
#define kAPPDELEGATE        [UIApplication sharedApplication].delegate
// UserDefaults
#define kUSERDEFAULT        [NSUserDefaults standardUserDefaults]
// NSNotificationCenter
#define kNOTIFICATIONCENTER [NSNotificationCenter defaultCenter]


// 系统版本号
#define kSystemVersion        [[[UIDevice currentDevice] systemVersion] floatValue]

// APP版本号
#define KAPP_VERSION          [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]


---

// 屏幕宽度
#define KSCREEN_WIDTH \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)

// 屏幕高度
#define KSCREEN_HEIGHT \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
// 屏幕Size
#define KSCREEN_SIZE \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)

---

// 获取当前语言
#define KCURRENT_LANGUAGE   ([[NSLocale preferredLanguages] objectAtIndex:0])
// 判断是否为iPhone
#define KIS_IPHONE          (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
// 判断是否为iPad
#define KIS_IPAD            (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// 获取沙盒Document路径
#define KDOCUMENT_PATH      [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
// 获取沙盒temp路径
#define KTEMP_PATH          NSTemporaryDirectory()
// 获取沙盒Cache路径
#define KCACHE_PATH         [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

---

// 判断是真机还是模拟器
#if TARGET_OS_IPHONE
// 真机
#endif

#if TARGET_IPHONE_SIMULATOR
// 模拟器
#endif




---

// 黑色和白色
#define KWHITE_COLOR            [UIColor whiteColor]
#define KBLACK_COLOR            [UIColor blackColor]


// 颜色
#define KRGB_COLOR(r, g, b)     [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define KRGBA_COLOR(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define KRANDOM_COLOR           KRGB_COLOR(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))
#define KCOLOR_WITH_HEX(rgbValue) \
                                [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
                                green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
                                blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]


// 获取一段时间间隔
#define KSTART_TIME             CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define KEND_TIME               NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)


// 弱引用/强引用
#define KWEAK_SELF(type)        __weak   typeof(type)   weak##type = type;
#define KSTRONG_SELF(type)      __strong typeof(type) type = weak##type;








// ↑ * 说明：转载请注明出处，GitHub(https://github.com/CustomPBWaters) 和 简书(http://www.jianshu.com/u/fd745d76c816)，谢谢。
//--------------------------- 【系统相关】 ------------------------------//





























//--------------------------- 『WechatPublic-Codeidea』【转换 & 判断】 ------------------------------//
// ↓


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





// ↑
//--------------------------- 【转换 & 判断】 ------------------------------//


























//--------------------------- 『WechatPublic-Codeidea』【用户提示】 ------------------------------//
// ↓


#define ShowHud(str)           do {  \
MBProgressHUD *hud1 = [MBProgressHUD showHUDAddedTo:self.view animated:YES];\
hud1.mode = MBProgressHUDModeText;\
hud1.removeFromSuperViewOnHide = YES;\
hud1.labelText = str;\
hud1.yOffset = -50;\
[hud1 hide:YES afterDelay:1.5];\
} while(0)


---



//NSLog
#ifdef DEBUG
#define NSLog(...) NSLog(@"%s 第%d行: %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define NSLog(...)
#endif


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









// ↑
//--------------------------- 【用户提示】 ------------------------------//

























 




//--------------------------- 『WechatPublic-Codeidea』【单例快速创建宏】 ------------------------------//
// ↓

/** 【单例快速创建宏】 */

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


// ↑
//--------------------------- 【单例快速创建宏】 ------------------------------//





//--------------------------- 『WechatPublic-Codeidea』【自定义Log打印日志】 ------------------------------//
// ↓

#ifdef  DEBUG // 测试
#define LNLog(...) NSLog(__VA_ARGS__)
#define LNFunc  LNLog(@"%s",__func__)
#define LNFuncline LNLog(@"%s, line = %d, %@",__FUNCTION__,__LINE__,[NSThread currentThread]);

#else   // 发布
#define LNLog(...)
#define LNFunc
#define LNFuncline
#endif




// ↑
//--------------------------- 【自定义Log】 ------------------------------//















/*
 * NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
 * 说明：转载请注明出处，GitHub(https://github.com/CustomPBWaters) 和 简书(http://www.jianshu.com/u/fd745d76c816)，谢谢。
 */







































