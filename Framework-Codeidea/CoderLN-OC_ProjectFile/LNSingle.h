/*
 * LNSingle.h 快速创建单例
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

/**
 ARC & MRC
 \ 代表下一行也属于宏
 加互斥锁解决多线程访问安全问题（@synchronized）
 或
 GCD一次性代码,本身就是线程安全的（dispatch_once）
 */



// .h
#define SingleH(name) +(instancetype)share##name;

#if __has_feature(objc_arc)

//条件满足 ARC
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
//MRC
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










#pragma mark --- 单例设计模式示例

// .h
@interface LNManager : NSObject<NSCopying, NSMutableCopying>
+ (instancetype)sharedInstance;

//.m
// 1.定义全局变量
static LNManager *_instance;

// 2.重写alloc-->allocWithZone:
+ (instancetype)allocWithZone:(struct _NSZone *)zone
{
    // 加互斥锁解决多线程访问安全问题
//    @synchronized(self) {
//        if (_instance == nil) {
//            _instance = [super allocWithZone:zone];
//        }
//    }
    
    // 本身就是线程安全的
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


 











