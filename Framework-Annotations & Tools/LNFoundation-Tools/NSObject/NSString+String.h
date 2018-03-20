/*
 * NSString+String.h
 * Framework: Foundation
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */


#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

@interface NSString (String)

/**
 *  计算字符串宽度(指当该字符串放在view时的自适应宽度)
 *
 *  @param size 填入预留的大小
 *  @param font 字体大小
 *  @param isBold 字体是否加粗
 *
 *  @return 返回CGRect
 */
- (CGRect)ln_stringWidthRectWithSize:(CGSize)size fontOfSize:(CGFloat)font isBold:(BOOL)isBold;


/**
 *  @brief 根据字数的不同,返回UILabel中的text文字需要占用多少Size
 *  @param size 约束的尺寸
 *  @param font 文本字体
 *  @return 文本的实际尺寸
 */
- (CGSize)ln_textSizeWithContentSize:(CGSize)size font:(UIFont *)font;

/**
 *  @brief  根据文本字数/文本宽度约束/文本字体 求得text的Size
 *  @param width 宽度约束
 *  @param font  文本字体
 *  @return 文本的实际高度
 */
- (CGFloat)ln_textHeightWithContentWidth:(CGFloat)width font:(UIFont *)font;

/**
 *  @brief  根据文本字数/文本宽度约束/文本字体 求得text的Size
 *  @param height 宽度约束
 *  @param font  文本字体
 *  @return 文本的实际长度
 */
- (CGFloat)ln_textWidthWithContentHeight:(CGFloat)height font:(UIFont *)font;







/**
 *  根据一定宽度和字体计算高度
 *
 *  @param maxWidth 最大宽度
 *  @param font  字体
 *
 *  @return 返回计算好高度的size
 */
- (CGSize)ln_stringHeightWithMaxWidth:(CGFloat)maxWidth andFont:(UIFont*)font ;


/**
 *  根据一定高度和字体计算宽度
 *
 *  @param maxHeight 最大高度
 *  @param font      字体
 *
 *  @return 返回计算宽度的size
 */
- (CGSize)ln_stringWidthWithMaxHeight:(CGFloat)maxHeight andFont:(UIFont*)font;

































//--------------------------- 【正则表达式】 ------------------------------//
//

- (BOOL)isQQ;
- (BOOL)isPhoneNumber;
- (BOOL)isIPAddress;






//--------------------------- 【目录全路径】 ------------------------------//
//

/**
 *  md5加密
 */
+ (NSString*)md5HexDigest:(NSString*)input;
/**
 *  根据文件名计算出文件大小
 */
- (unsigned long long)lx_fileSize;
/**
 *  生成缓存目录全路径
 */
- (instancetype)cacheDir;
/**
 *  生成文档目录全路径
 */
- (instancetype)docDir;
/**
 *  生成临时目录全路径
 */
- (instancetype)tmpDir;



//--------------------------- <#我是分割线#> ------------------------------//
//



@interface NSString (Hash)

@property (readonly) NSString *md5String;
@property (readonly) NSString *sha1String;
@property (readonly) NSString *sha256String;
@property (readonly) NSString *sha512String;

- (NSString *)hmacSHA1StringWithKey:(NSString *)key;
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;

@end



@interface NSString (MD5)
+ (NSString *)md5:(NSString *)originalStr;
@end



#define __BASE64( text )        [NSString base64StringFromText:text]
#define __TEXT( base64 )        [NSString textFromBase64String:base64]
@interface NSString (base64)
/******************************************************************
 函数名称 : + (NSString *)base64StringFromText:(NSString *)text
 函数描述 : 将文本转换为base64格式字符串
 输入参数 : (NSString *)text    文本
 输出参数 : N/A
 返回参数 : (NSString *)    base64格式字符串
 备注信息 :
 ***************************************************************/
+ (NSString *)base64StringFromText:(NSString *)text;

/******************************************************************
 函数名称 : + (NSString *)textFromBase64String:(NSString *)base64
 函数描述 : 将base64格式字符串转换为文本
 输入参数 : (NSString *)base64  base64格式字符串
 输出参数 : N/A
 返回参数 : (NSString *)    文本
 备注信息 :
 *****************************************************************/
+ (NSString *)textFromBase64String:(NSString *)base64;


@end


@interface NSString (Extensions)
- (NSString *)lowercaseFirstCharacter;
- (NSString *)uppercaseFirstCharacter;
- (BOOL)isEmpty;
- (NSString *)replaceNullString;
- (NSString *)trim;
- (NSString *)trimTheExtraSpaces;
- (NSString *)escapeHTML;
- (NSString *)stringByDecodingXMLEntities;
- (NSString *)md5;
- (NSString *)md5ForUTF16;
- (CGFloat)fontSizeWithFont:(UIFont *)font constrainedToSize:(CGSize)size;
- (NSMutableArray *)tokenizationStringByNSStringEnumerationOptions:(NSStringEnumerationOptions)opts;
- (NSString *)languageForString;
- (NSMutableArray *)analyseTextOfSentences;
// app的版本
+ (NSString *)appVersion;
// 手机机型
+ (NSString *)deviceModel;

// 获取Documents路径
+ (NSString *)documentPath;

// 获取缓存路径
+ (NSString *)cachePath;

+ (NSString *)imageCachePath;


//! 是否是合法邮箱
- (BOOL)isValidEmail;
//! 是否是合法号码
- (BOOL)isValidPhoneNumber;
//! 是否是合法的18位身份证号码
- (BOOL)isValidPersonID;
/**
 * 功能:判断是否在地区码内
 * 参数:地区码
 */
- (BOOL)areaCode:(NSString *)code;

//! 根据文件名返回路径
+ (NSString *)pathWithFileName:(NSString *)fileName;
+ (NSString *)pathWithFileName:(NSString *)fileName ofType:(NSString *)type;

// 根据秒数返回日期
+ (NSString *)dateWithSeconds:(NSUInteger)seconds;

@end



@interface NSString (Contains)

/** 判断URL中是否包含中文 */
- (BOOL)isContainChinese;

/** 获取字符数量 */
- (int)wordsCount;

@end



@interface NSString (DictionaryValue)

/** JSON字符串转成NSDictionary */
-(NSDictionary *)dictionaryValue;

@end



//--------------------------- <#我是分割线#> ------------------------------//
// https://github.com/damienromito/NSString-Matcher


@interface NSString(Matcher)

- (NSArray *)matchWithRegex:(NSString *)regex;

- (NSString *)matchWithRegex:(NSString *)regex atIndex:(NSUInteger)index;

- (NSString *)firstMatchedGroupWithRegex:(NSString *)regex;

- (NSTextCheckingResult *)firstMatchedResultWithRegex:(NSString *)regex;

@end



@interface NSString (NormalRegex)
/**
 *  手机号码的有效性:分电信、联通、移动和小灵通
 */
- (BOOL)isMobileNumberClassification;
/**
 *  手机号有效性
 */
- (BOOL)isMobileNumber;

/**
 *  邮箱的有效性
 */
- (BOOL)isEmailAddress;

/**
 *  简单的身份证有效性
 *
 */
- (BOOL)simpleVerifyIdentityCardNum;

/**
 *  精确的身份证号码有效性检测
 *
 *  @param value 身份证号
 */
+ (BOOL)accurateVerifyIDCardNumber:(NSString *)value;

/**
 *  车牌号的有效性
 */
- (BOOL)isCarNumber;

/**
 *  银行卡的有效性
 */
- (BOOL)bankCardluhmCheck;

/**
 *  IP地址有效性
 */
- (BOOL)isIPAddress;

/**
 *  Mac地址有效性
 */
- (BOOL)isMacAddress;

/**
 *  网址有效性
 */
- (BOOL)isValidUrl;

/**
 *  纯汉字
 */
- (BOOL)isValidChinese;

/**
 *  邮政编码
 */
- (BOOL)isValidPostalcode;

/**
 *  工商税号
 */
- (BOOL)isValidTaxNo;

@end





//--------------------------- <#我是分割线#> ------------------------------//
// https://github.com/croath/NSString-Pinyin


@interface NSString (Pinyin)

- (NSString*)pinyinWithPhoneticSymbol;

- (NSString*)pinyin;

- (NSArray*)pinyinArray;

- (NSString*)pinyinWithoutBlank;

- (NSArray*)pinyinInitialsArray;

- (NSString*)pinyinInitialsString;

@end


@interface NSString (Size)

- (CGFloat)heightWithFont:(UIFont *)font constrainedToWidth:(CGFloat)width;

- (CGFloat)widthWithFont:(UIFont *)font constrainedToHeight:(CGFloat)height;


- (CGSize)sizeWithFont:(UIFont *)font constrainedToWidth:(CGFloat)width;

- (CGSize)sizeWithFont:(UIFont *)font constrainedToHeight:(CGFloat)height;


+ (NSString *)reverseString:(NSString *)strSrc;

@end




@interface NSString (StringPages)
/**
 *  根据字符串进行分页
 *
 *  @param cache 需要进行分页的字符串
 *  @param font  你想显示的字体大小，这个要保持统一
 *  @param r     你想在多大的窗口显示
 *
 *  @return 返回一个数组，数组的元素是NSrange，根据NSRange来进行截取字符串
 */
- (NSArray *)getPagesOfString:(NSString *)cache withFont:(UIFont*)font inRect:(CGRect)r;

@end



@interface NSString (Trims)

/** 清除html标签 */
- (NSString *)stringByStrippingHTML;

/** 清除js脚本 */
- (NSString *)stringByRemovingScriptsAndStrippingHTML;

/** 去除空格 */
- (NSString *)trimmingWhitespace;

/** 去除空格与空行 */
- (NSString *)trimmingWhitespaceAndNewlines;

@end




@interface NSString (MIMEType)
/**  获得文件的MIMEType */
- (NSString *)MIMEType;
- (NSString *)MIMEType2;

@end


@interface NSString (Category)

/** 根据字符串的字体和size(此处size设置为字符串宽和MAXFLOAT)返回多行显示时的字符串size */
- (CGSize)stringSizeWithFont:(UIFont *)font Size:(CGSize)size;



//--------------------------- <#我是分割线#> ------------------------------//
//--------------------------- <#我是分割线#> ------------------------------//
//
/**
 *  正则表达式简单说明
 *  语法：
 .       匹配除换行符以外的任意字符
 \w      匹配字母或数字或下划线或汉字
 \s      匹配任意的空白符
 \d      匹配数字
 \b      匹配单词的开始或结束
 ^       匹配字符串的开始
 $       匹配字符串的结束
 *       重复零次或更多次
 +       重复一次或更多次
 ?       重复零次或一次
 {n} 	重复n次
 {n,} 	重复n次或更多次
 {n,m} 	重复n到m次
 \W      匹配任意不是字母，数字，下划线，汉字的字符
 \S      匹配任意不是空白符的字符
 \D      匹配任意非数字的字符
 \B      匹配不是单词开头或结束的位置
 [^x] 	匹配除了x以外的任意字符
 [^aeiou]匹配除了aeiou这几个字母以外的任意字符
 *?      重复任意次，但尽可能少重复
 +?      重复1次或更多次，但尽可能少重复
 ??      重复0次或1次，但尽可能少重复
 {n,m}? 	重复n到m次，但尽可能少重复
 {n,}? 	重复n次以上，但尽可能少重复
 \a      报警字符(打印它的效果是电脑嘀一声)
 \b      通常是单词分界位置，但如果在字符类里使用代表退格
 \t      制表符，Tab
 \r      回车
 \v      竖向制表符
 \f      换页符
 \n      换行符
 \e      Escape
 \0nn 	ASCII代码中八进制代码为nn的字符
 \xnn 	ASCII代码中十六进制代码为nn的字符
 \unnnn 	Unicode代码中十六进制代码为nnnn的字符
 \cN 	ASCII控制字符。比如\cC代表Ctrl+C
 \A      字符串开头(类似^，但不受处理多行选项的影响)
 \Z      字符串结尾或行尾(不受处理多行选项的影响)
 \z      字符串结尾(类似$，但不受处理多行选项的影响)
 \G      当前搜索的开头
 \p{name} 	Unicode中命名为name的字符类，例如\p{IsGreek}
 (?>exp) 	贪婪子表达式
 (?<x>-<y>exp) 	平衡组
 (?im-nsx:exp) 	在子表达式exp中改变处理选项
 (?im-nsx)       为表达式后面的部分改变处理选项
 (?(exp)yes|no) 	把exp当作零宽正向先行断言，如果在这个位置能匹配，使用yes作为此组的表达式；否则使用no
 (?(exp)yes) 	同上，只是使用空表达式作为no
 (?(name)yes|no) 如果命名为name的组捕获到了内容，使用yes作为表达式；否则使用no
 (?(name)yes) 	同上，只是使用空表达式作为no
 
 捕获
 (exp)               匹配exp,并捕获文本到自动命名的组里
 (?<name>exp)        匹配exp,并捕获文本到名称为name的组里，也可以写成(?'name'exp)
 (?:exp)             匹配exp,不捕获匹配的文本，也不给此分组分配组号
 零宽断言
 (?=exp)             匹配exp前面的位置
 (?<=exp)            匹配exp后面的位置
 (?!exp)             匹配后面跟的不是exp的位置
 (?<!exp)            匹配前面不是exp的位置
 注释
 (?#comment)         这种类型的分组不对正则表达式的处理产生任何影响，用于提供注释让人阅读
 
 *  表达式：\(?0\d{2}[) -]?\d{8}
 *  这个表达式可以匹配几种格式的电话号码，像(010)88886666，或022-22334455，或02912345678等。
 *  我们对它进行一些分析吧：
 *  首先是一个转义字符\(,它能出现0次或1次(?),然后是一个0，后面跟着2个数字(\d{2})，然后是)或-或空格中的一个，它出现1次或不出现(?)，
 *  最后是8个数字(\d{8})
 */


@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
