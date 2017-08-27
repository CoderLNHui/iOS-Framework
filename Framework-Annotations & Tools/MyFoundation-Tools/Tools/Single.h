/*
 * Single.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 * 快速创建一个单例
 */


//--------------------------- 【快速创建一个单例】 ------------------------------//
//
// MRC单例模式 & ARC单例模式

#define SingleH(name) +(instancetype)share##name;

#if __has_feature(objc_arc)
//条件满足 ARC
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

START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
