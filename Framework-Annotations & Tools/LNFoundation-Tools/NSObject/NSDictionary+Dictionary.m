/*
 * NSDictionary+Property.m
 * Framework:  Foundation
 * Author:  白开水ln（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 👣
 */

#import "NSDictionary+Property.h"

@implementation NSDictionary (Dictionary)




/*
 *【利用链式编程去实现富文本属性的赋值】
 * @param headerUrl    字体 & 颜色
 */
-(NSMutableDictionary *(^)(CGFloat))Font
{
    return ^id(CGFloat font)
    {
        [self setValue:[UIFont systemFontOfSize:font] forKey:NSFontAttributeName];
        return self;
    };
}

-(NSMutableDictionary *(^)(UIColor *))Color
{
    return ^id(UIColor * color)
    {
        [self setValue:color forKey:NSForegroundColorAttributeName];
        return self;
    };
}





//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//







// isKindOfClass:判断是否是当前类或者子类
// 生成属性代码 => 根据字典中所有key
- (void)createPropertyCode
{
    // 拼接属性字符串代码
    NSMutableString *codes = [NSMutableString string];
    // 遍历字典
    [self enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull value, BOOL * _Nonnull stop) {
        
        NSString *code;
        if ([value isKindOfClass:[NSString class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, strong) NSString *%@;",key];
            
        } else if ([value isKindOfClass:NSClassFromString(@"__NSCFBoolean")]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, assign) BOOL %@;",key];
            
        } else if ([value isKindOfClass:[NSNumber class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, assign) NSInteger %@;",key];
            
        } else if ([value isKindOfClass:[NSArray class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, strong) NSArray *%@;",key];
            
        } else if ([value isKindOfClass:[NSDictionary class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, strong) NSDictionary *%@;",key];
        }
        
        // 每生成属性字符串，就自动换行。
        [codes appendFormat:@"\n%@\n",code];
        
    }];
    
    // 把拼接好的字符串打印出来
    NSLog(@"%@",codes);
    
}






//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//

@implementation NSDictionary(ObjectExt)

/**
 
 *获取字典指定的NSDictionary的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSDictionary*)dictionaryObjectForKey:(id)aKey

{
    
    id value = [self objectForKey:aKey];
    if (value == nil || [value isKindOfClass:[NSNull class]]||![value isKindOfClass:[NSDictionary class]])
    {
        return nil;
        
    }
    
    return value;
    
}

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSArray*)arrayObjectForKey:(id)aKey

{
    
    id value = [self objectForKey:aKey];
    if (value == nil || [value isKindOfClass:[NSNull class]])
    {
        return nil;
        
    }
    
    return value;
    
}

/**
 
 *获取字典指定的array的对象
 * @param aKey key
 * @return value值如果为nil或者null会返回空列表
 
 */
-(NSMutableArray*)mutableArrayObjectForKey:(id)aKey

{
    
    id value = [self objectForKey:aKey];
    
    if (value == nil || [value isKindOfClass:[NSNull class]])
        
    {
        
        return nil;
        
    }
    
    return value;
    
}

/**
 * 获取字典指定的对象为空是返回默认对象
 * @param aKey key
 * @param defaultObject value值如果为nil或者null会返回默认对象
 * @return 对象
 
 */
-(id)objectExtForKey:(id)aKey defaultObject:(id)defaultObject

{
    
    id value = [self objectForKey:aKey];
    
    if (value == nil || [value isKindOfClass:[NSNull class]])
        
    {
        
        return defaultObject;
        
    }
    
    return value;
    
}

/**
 
 * @brief 如果akey找不到，返回@"" (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @return 字典value
 
 */
- (NSString*) stringForKey:(id)aKey
{
    
    return [self stringForKey:aKey withDefaultValue:@""];
    
}

/**
 
 *获取字典指定的key的数值字符
 * @param aKey key
 * @return value值如果为nil或者null会返回0字符串
 
 */
-(NSString*)numberStringForKey:(id)aKey

{
    
    return [self stringForKey:aKey withDefaultValue:@"0"];
    
}

/**
 
 * @brief @brief 如果akey找不到，返回默认值 (防止出现nil，使程序崩溃)
 * @param aKey 字典key值
 * @param defValue 为空时的默认值
 * @return 字典value
 
 */
- (NSString *)stringForKey:(id)aKey withDefaultValue:(NSString *)defValue

{
    
    NSString *value = [self objectForKey:aKey];
    
    if (value == nil || [value isKindOfClass:[NSNull class]])
        
    {
        
        value = defValue;
        
    }
    
    return [[NSString stringWithFormat:@"%@",value] replaceNullString];
    
}

/**
 
 * @brief 替换&nbsp;为空
 * @param aKey 字典key值
 * @return 字典value
 
 */
-(NSString*)replaceNBSPforKey:(id)aKey

{
    
    NSString *value = [self objectForKey:aKey];
    
    if (!value)
        
    {
        
        value = @"";
        
    }
    
    NSString* str = [value stringByReplacingOccurrencesOfString:@"&nbsp;" withString:@" "] ;
    
    return [[NSString stringWithFormat:@"%@",str] replaceNullString];
    
}
@end




@implementation NSDictionary (Merge)

+ (NSDictionary *)dictionaryByMerging:(NSDictionary *)dict1 with:(NSDictionary *)dict2
{
    NSMutableDictionary * result = [NSMutableDictionary dictionaryWithDictionary:dict1];
    NSMutableDictionary * resultTemp = [NSMutableDictionary dictionaryWithDictionary:dict1];
    [resultTemp addEntriesFromDictionary:dict2];
    
    [resultTemp enumerateKeysAndObjectsUsingBlock: ^(id key, id obj, BOOL *stop) {
        if ([dict1 objectForKey:key])
        {
            if ([obj isKindOfClass:[NSDictionary class]])
            {
                NSDictionary * newVal = [[dict1 objectForKey: key] dictionaryByMergingWith: (NSDictionary *) obj];
                [result setObject: newVal forKey: key];
            }
            else
            {
                [result setObject: obj forKey: key];
            }
        }
        else if([dict2 objectForKey:key])
        {
            if ([obj isKindOfClass:[NSDictionary class]])
            {
                NSDictionary * newVal = [[dict2 objectForKey: key] dictionaryByMergingWith: (NSDictionary *) obj];
                [result setObject: newVal forKey: key];
            }
            else
            {
                [result setObject: obj forKey: key];
            }
        }
    }];
    return (NSDictionary *) [result mutableCopy];
    
}

- (NSDictionary *)dictionaryByMergingWith:(NSDictionary *)dict
{
    return [[self class] dictionaryByMerging:self with: dict];
}

#pragma mark - Manipulation
- (NSDictionary *)dictionaryByAddingEntriesFromDictionary:(NSDictionary *)dictionary
{
    NSMutableDictionary *result = [self mutableCopy];
    [result addEntriesFromDictionary:dictionary];
    return result;
}

- (NSDictionary *)dictionaryByRemovingEntriesWithKeys:(NSSet *)keys
{
    NSMutableDictionary *result = [self mutableCopy];
    [result removeObjectsForKeys:keys.allObjects];
    return result;
}

@end




@implementation NSDictionary (URI)
/**
 *  @brief  将url参数转换成NSDictionary
 *
 *  @param query url参数
 *
 *  @return NSDictionary
 */
+ (NSDictionary *)dictionaryWithURLQuery:(NSString *)query
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    NSArray *parameters = [query componentsSeparatedByString:@"&"];
    for(NSString *parameter in parameters)
    {
        NSArray *contents = [parameter componentsSeparatedByString:@"="];
        if([contents count] == 2)
        {
            NSString *key = [contents objectAtIndex:0];
            NSString *value = [contents objectAtIndex:1];
            value = [value stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
            if (key && value)
            {
                [dict setObject:value forKey:key];
            }
        }
    }
    return [NSDictionary dictionaryWithDictionary:dict];
}
/**
 *  @brief  将NSDictionary转换成url 参数字符串
 *
 *  @return url 参数字符串
 */
- (NSString *)URLQueryString
{
    NSMutableString *string = [NSMutableString string];
    for (NSString *key in [self allKeys])
    {
        if ([string length])
        {
            [string appendString:@"&"];
        }
        CFStringRef escaped = CFURLCreateStringByAddingPercentEscapes(NULL,(CFStringRef)[[self objectForKey:key] description],
                                                                      NULL,(CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                      kCFStringEncodingUTF8);
        [string appendFormat:@"%@=%@", key, escaped];
        CFRelease(escaped);
    }
    return string;
}

 

@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
