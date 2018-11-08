/*
 * LNSingle.h 快速创建单例
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

/**
 ARC & MRC
 \ 代表下一行也属于宏
 资源安全问题：
 加互斥锁解决多线程访问安全问题（@synchronized）
 GCD一次性代码,本身就是线程安全的（dispatch_once）
 */

#pragma mark - 快速创建单例
// .h
#define SingleH(name) +(instancetype)share##name;

#if __has_feature(objc_arc)
// ARC环境
// .m
#define SingleM(name) static id _instance;\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super allocWithZone:zone];\
    });\
    return _instance;\
}\
+(instancetype)share##name\
{\
    return [[self alloc]init];\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
    return _instance;\
}\
-(id)mutableCopyWithZone:(NSZone *)zone\
{\
    return _instance;\
}

#else
//MRC环境
#define SingleM(name) static id _instance;\
+(instancetype)allocWithZone:(struct _NSZone *)zone\
{\
    static dispatch_once_t onceToken;\
    dispatch_once(&onceToken, ^{\
        _instance = [super allocWithZone:zone];\
    });\
    return _instance;\
}\
+(instancetype)share##name\
{\
    return [[self alloc]init];\
}\
-(id)copyWithZone:(NSZone *)zone\
{\
    return _instance;\
}\
-(id)mutableCopyWithZone:(NSZone *)zone\
{\
    return _instance;\
}\
-(oneway void)release{}\
-(instancetype)retain\
{\
    return _instance;\
}\
-(NSUInteger)retainCount\
{\
    return MAXFLOAT;\
}
#endif





#pragma mark - 单例设计模式示例

// .h
@interface LNManager : NSObject<NSCopying, NSMutableCopying>
// 提供类方法（一般格式：shared+类名，sharedManager | defaultManager | shared | default）
+ (instancetype)sharedInstance;

//.m
// 1.定义全局变量
static LNManager *_instance;

// 2.重写allocWithZone:（alloc内部也是调用allocWithZone:方法）
+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    // 方式一：加互斥锁解决多线程访问安全问题
    @synchronized(self) {
        if (_instance == nil) {
            _instance = [super allocWithZone:zone];
        }
    }
    
    // 方式二：使用GCD一次性代码，不用担心资源争夺问题，因为本身就是线程安全的
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super allocWithZone:zone];
    });
    return _instance;
}

// 严谨一点：重写copyWithZoone: 和 mutableCopyWithZoone:，遵守<NSCopying, NSMutableCopying>协议
- (id)copyWithZone
{
    return _instance;
}

- (id)mutableCopyWithZoone
{
    return _instance;
}

// 3.提供类方法
+ (instancetype)sharedInstance
{
    return [[self alloc] init];
}


 











