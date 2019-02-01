/*
 * 简/众_不知名开发者 | https://github.com/CoderLN
 *
 * 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - 字符串相关
@interface NSString (String)
/**
 *  计算字符串宽度(指当该字符串放在view时的自适应宽度)
 *
 *  @param size   填入预留的大小
 *  @param font   字体大小
 *  @param isBold 字体是否加粗
 *
 *  @return  返回CGRect
 */
- (CGRect)ln_stringWidthRectWithSize:(CGSize)size fontOfSize:(CGFloat)font isBold:(BOOL)isBold;


/**
 *  根据字数的不同,返回UILabel中的text文字需要占用多少Size
 *
 *  @param size 约束的尺寸
 *  @param font 文本字体
 *
 *  @return  文本的实际尺寸
 */
- (CGSize)ln_textSizeWithContentSize:(CGSize)size font:(UIFont *)font;



/**
 *  根据一定宽度和字体计算高度
 *
 *  @param maxWidth 最大宽度
 *  @param font     字体
 *
 *  @return  返回计算好高度的size
 */
- (CGSize)ln_stringHeightWithMaxWidth:(CGFloat)maxWidth andFont:(UIFont*)font ;


/**
 *  根据一定高度和字体计算宽度
 *
 *  @param maxHeight  最大高度
 *  @param font       字体
 *
 *  @return  返回计算宽度的size
 */
- (CGSize)ln_stringWidthWithMaxHeight:(CGFloat)maxHeight andFont:(UIFont*)font;




/**
 *  根据字符串的字体和size,返回多行显示时的字符串大小
 *
 *  @param font  字体
 *  @param size  字符串宽和MAXFLOAT
 *
 *  @return  返回计算size
 */
- (CGSize)ln_stringSizeWithFont:(UIFont *)font Size:(CGSize)size;



#pragma mark - 判断字符串是否为空
+ (BOOL)isBlankString:(NSString *)string;






#pragma mark - 生成目录路径
/**
 *  根据文件名计算出文件大小,计算self这个文件夹\文件的大小
 *
 *  @return 文件大小
 */
- (unsigned long long)ln_fileSize;


/**
 *  生成缓存目录全路径
 *
 *  @return 缓存目录
 */
- (instancetype)ln_cacheDirectory;



/**
 *  生成文档目录全路径
 *
 *  @return 文档目录
 */
- (instancetype)ln_docDirectory;



/**
 *  生成临时目录全路径
 *
 *  @return 临时目录
 */
- (instancetype)ln_tmpDirectory;
@end





#pragma mark - 加密相关
@interface NSString (Encrypt)

#pragma mark -将文件名md5加密
- (NSString *)encryptFileNameWithMD5:(NSString *)str;

@end






#pragma mark - 正则表达式相关
@interface NSString (Regular)

/**
 * 正则运用之判断一个字符串中是否只含有英文字母数字下划线[a-zA-Z0-9_]
 *
 * @return
 */
- (BOOL)isValidVar;

 
/**
 * 判断是否是合法的 email
 *
 * @return
 */
- (BOOL)isValidEmail;

@end





























