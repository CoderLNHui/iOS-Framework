/*
 * NSDictionary+Property.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */

#import <Foundation/Foundation.h>

@interface NSDictionary (Dictionary)



/*
 *【利用链式编程去实现富文本属性的赋值】
 * @param headerUrl    字体 & 颜色
 */
-(NSMutableDictionary *(^)(CGFloat))Font;
-(NSMutableDictionary *(^)(UIColor *))Color;





//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//

/*
 *【字典转模型KVC实现(自动生成模型属性代码)】
 */
- (void)createPropertyCode;





//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
// 结合NSString+String.h 使用


/**
 
 *  获取字典指定的NSDictionary的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空NSDictionary
 */
-(NSDictionary*)dictionaryObjectForKey:(id)aKey;

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 */
-(NSArray*)arrayObjectForKey:(id)aKey;

/**
 
 * 获取字典指定的对象为空是返回默认对象
 * @param aKey key
 * @param defaultObject value值如果为nil或者null会返回默认对象
 * @return 对象
 */
-(id)objectExtForKey:(id)aKey defaultObject:(id)defaultObject;

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSMutableArray*)mutableArrayObjectForKey:(id)aKey;

/**
 
 * @brief 如果akey找不到，返回@"" (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @return 字典value
 
 */
- (NSString *)stringForKey:(id)aKey;

/**
 
 * @brief @brief 如果akey找不到，返回默认值 (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @param defValue 为空时的默认值
 * @return 字典value
 */
- (NSString *)stringForKey:(id)aKey withDefaultValue:(NSString *)defValue;

/**
 
 * @brief 替换&nbsp;为空
 * @param aKey 字典key值
 * @return 字典value
 
 */
- (NSString *)replaceNBSPforKey:(id)aKey ;

/**
 
 *获取字典指定的key的数值字符
 * @param aKey key
 * @return value值如果为nil或者null会返回0字符串
 
 */
-(NSString*)numberStringForKey:(id)aKey;


@end



@interface NSDictionary (Merge)

/** 合并两个NSDictionary */
+ (NSDictionary *)dictionaryByMerging:(NSDictionary *)dict1 with:(NSDictionary *)dict2;

/** 并入一个NSDictionary */
- (NSDictionary *)dictionaryByMergingWith:(NSDictionary *)dict;

#pragma mark - Manipulation
- (NSDictionary *)dictionaryByAddingEntriesFromDictionary:(NSDictionary *)dictionary;
- (NSDictionary *)dictionaryByRemovingEntriesWithKeys:(NSSet *)keys;

@end


@interface NSDictionary (URL)

/**
 *  @brief  将url参数转换成NSDictionary
 *
 *  @param query url参数
 *
 *  @return NSDictionary
 */
+ (NSDictionary *)dictionaryWithURLQuery:(NSString *)query;

/**
 *  @brief  将NSDictionary转换成url 参数字符串
 *
 *  @return url 参数字符串
 */
- (NSString *)URLQueryString;























//--------------------------- <#我是分割线#> ------------------------------//
//
//--------------------------- [字典转模型示例:本地Plist文件] ------------------------------//
//
/**

 NSString *filePath = [[NSBundle mainBundle] pathForResource:@"status.plist" ofType:nil];
 NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:filePath];
 
 // 字典转模型,生成属性代码 => dict
 [dict createPropertyCode];
 
 
 打印输出:
 2015-03-04 15:27:23.767 字典转模型-自动生成属性代码 [5227:154068]
 @property (nonatomic, strong) NSString *source;
 
 @property (nonatomic, assign) NSInteger reposts_count;
 
 @property (nonatomic, strong) NSArray *pic_urls;
 
 @property (nonatomic, strong) NSString *created_at;
 
 @property (nonatomic, assign) BOOL isA;
 
 @property (nonatomic, assign) NSInteger attitudes_count;
 
 @property (nonatomic, strong) NSString *idstr;
 
 @property (nonatomic, strong) NSString *text;
 
 @property (nonatomic, assign) NSInteger comments_count;
 
 @property (nonatomic, strong) NSDictionary *user;
 */


@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
