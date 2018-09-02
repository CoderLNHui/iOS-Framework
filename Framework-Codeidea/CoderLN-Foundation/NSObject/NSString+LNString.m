/*
 * NSString+String.m
 *
 * Framework: Foundation
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 作用：
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import "NSString+String.h"

@implementation NSString (String)




#pragma mark --- 【字符串相关】↓

/**
 *  计算字符串宽度(指当该字符串放在view时的自适应宽度)
 */
- (CGRect)ln_stringWidthRectWithSize:(CGSize)size fontOfSize:(CGFloat)fontOfSize isBold:(BOOL)isBold
{
    NSDictionary * attributes;
    if (isBold) {
        attributes = @{NSFontAttributeName: [UIFont boldSystemFontOfSize:fontOfSize]};
    }else{
        attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:fontOfSize]};
    }
    
    return [self boundingRectWithSize:size options:NSStringDrawingUsesLineFragmentOrigin attributes:attributes context:nil];
}



/**
 *  据字数的不同,返回UILabel中的text文字需要占用多少Size
 */
- (CGSize)ln_textSizeWithContentSize:(CGSize)size font:(UIFont *)font
{
    return [self boundingRectWithSize:size options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName : font} context:nil].size;
}


 

/**
 *  根据一定宽度和字体计算高度
 */
- (CGSize)ln_stringHeightWithMaxWidth:(CGFloat)maxWidth andFont:(UIFont*)font
{
    return  [self boundingRectWithSize:CGSizeMake(maxWidth, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading attributes:@{NSFontAttributeName:font} context:nil].size;
}




/**
 *  根据一定高度和字体计算宽度
 */
- (CGSize)ln_stringWidthWithMaxHeight:(CGFloat)maxHeight andFont:(UIFont*)font
{
    return  [self boundingRectWithSize:CGSizeMake(MAXFLOAT, maxHeight) options:NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading attributes:@{NSFontAttributeName:font} context:nil].size;
}




/**
 *  根据字符串的字体和size,返回多行显示时的字符串大小
 */
- (CGSize)ln_stringSizeWithFont:(UIFont *)font Size:(CGSize)size
{
    CGSize resultSize;
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 7) {
        // 段落样式
        NSMutableParagraphStyle *style = [[NSMutableParagraphStyle alloc] init];
        style.lineBreakMode = NSLineBreakByWordWrapping;
        
        // 字体大小，换行模式
        NSDictionary *attributes = @{NSFontAttributeName : font , NSParagraphStyleAttributeName : style};
        resultSize = [self boundingRectWithSize:size options:NSStringDrawingUsesLineFragmentOrigin attributes:attributes context:nil].size;
    } else {
        // 计算正文的高度
        resultSize = [self sizeWithFont:font constrainedToSize:size lineBreakMode:NSLineBreakByWordWrapping];
    }
    return resultSize;
}


#pragma mark - 判断字符串是否为空
+ (BOOL)isBlankString:(NSString *)string
{
    NSLog(@"判断字符串是否为空：%@",string);
    if (string == nil || string == NULL) {
        return YES;
    }
    if ([string isKindOfClass:[NSNull class]]) {
        return YES;
    }
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) {
        return YES;
    }
    return NO;
}




#pragma mark ---  ↑
#pragma mark --- 【生成目录路径】↓


/**
 *  根据文件名计算出文件大小
 */
- (unsigned long long)ln_fileSize
{
    // 文件管理者
    NSFileManager *mgr = [NSFileManager defaultManager];
    
    // 文件类型
    NSDictionary *attrs = [mgr attributesOfItemAtPath:self error:nil];
    NSString *fileType = attrs.fileType;
    
    if ([fileType isEqualToString:NSFileTypeDirectory]) { // 文件夹
        // 获得文件夹的遍历器
        NSDirectoryEnumerator *enumerator = [mgr enumeratorAtPath:self];
        
        // 总大小
        unsigned long long fileSize = 0;
        
        // 遍历所有子路径
        for (NSString *subpath in enumerator) {
            // 获得子路径的全路径
            NSString *fullSubpath = [self stringByAppendingPathComponent:subpath];
            fileSize += [mgr attributesOfItemAtPath:fullSubpath error:nil].fileSize;
        }
        
        return fileSize;
    }
    
    // 文件
    return attrs.fileSize;
}


/**
 *  生成缓存目录全路径
 */
- (instancetype)ln_cacheDirectory
{
    NSString *dir = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject];
    return [dir stringByAppendingPathComponent:[self lastPathComponent]];
}


/**
 *  生成文档目录全路径
 */
- (instancetype)ln_docDirectory
{
    NSString *dir = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    return [dir stringByAppendingPathComponent:[self lastPathComponent]];
}


/**
 *  生成临时目录全路径
 */
- (instancetype)ln_tmpDirectory
{
    NSString *dir = NSTemporaryDirectory();
    return [dir stringByAppendingPathComponent:[self lastPathComponent]];
}









#pragma mark ---  ↑
#pragma mark --- 【正则表达式相关】↓

/**
 * 正则运用之判断一个字符串中是否只含有英文字母数字下划线[a-zA-Z0-9_]
 */
- (BOOL)isValidVar
{
    NSString *regex = @"[a-zA-Z_]+[a-zA-Z0-9_]*"; // +是一次或多次，*是0次或多次, []是字符集合
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    // evaluateWithObject: 用正则评估字符串是否符合它
    return [predicate evaluateWithObject:self]; // self就是一个字符串，这句代码用predicate评估（判断）字符串本身符不符合要求
    
    // return [self evaluateWithRegex:@"[a-zA-Z_]+[a-zA-Z0-9_]*"];
}


/**
 * 判断是否是合法的 email
 */
- (BOOL)isValidEmail
{
    NSString *regex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{1,5}";
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [predicate evaluateWithObject:self];
}




























@end





















