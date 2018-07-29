/*
 * NSString.m
 *
 * Framework: Foundation (c) 1994-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */



#pragma mark - 字符串列举
NSString *string = @"123456\nABCDEF\nabcdef
//1.列举(按行)
[string enumerateLinesUsingBlock:^(NSString * _Nonnull line, BOOL * _Nonnull stop) {
    NSLog(@"每行:   %@", line);
}];
//输出:    每行:   123456
//输出:    每行:   ABCDEF
//输出:    每行:   abcdef


//2.列举(范围,条件)
[string enumerateSubstringsInRange:NSMakeRange(5, 10) options:NSStringEnumerationByLines usingBlock:^(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL * _Nonnull stop) {
    
    NSLog(@"%@", substring);
    NSLog(@"%ld   %ld", substringRange.location, substringRange.length);
    NSLog(@"%ld   %ld", enclosingRange.location, enclosingRange.length);
    
}];
//输出:   6
//输出:   5 1
//输出:   5 2

//输出:   ABCDEF
//输出:   7   6
//输出:   7   7

//输出:   a
//输出:   14   1
//输出:   14   1








#pragma mark - 字符串分割
NSString *string = @"A_B_c_D_E_F";

//分割(指定字符串)
NSArray *resultArr1 = [string componentsSeparatedByString:@"_"];
NSLog(@"%@", resultArr1);
//输出:   (A, B, c, D, E, F)

//分割(指定字符集合)
NSArray *resultArr2 = [string componentsSeparatedByCharactersInSet:[NSCharacterSet lowercaseLetterCharacterSet]];
NSLog(@"%@", resultArr2);
//输出:   ("A_B_" , "_D_E_F")





NSString
#pragma mark -【字符串属性】

//////////字符串属性//////////
NSString *str1 = @"string";

NSLog(@"长度:                   %ld", str1.length);
NSLog(@"描述:                   %@", str1.description);
NSLog(@"哈希地址:                %lu", (unsigned long)str1.hash);
NSLog(@"字符串对应下标字符:        %c", [str1 characterAtIndex:2]);
//输出:   长度:                   6
//输出:   描述:                   string
//输出:   哈希地址:                10152471993823965
//输出:   字符串对应下标字符:        r

字符集合:
NSCharacterSet    说明
controlCharacterSet    控制符
whitespaceCharacterSet    空格符
whitespaceAndNewlineCharacterSet    空格换行符
decimalDigitCharacterSet    小数
letterCharacterSet    文字
lowercaseLetterCharacterSet    小写字母
uppercaseLetterCharacterSet    大写字母
nonBaseCharacterSet    非基础
alphanumericCharacterSet    数字字母
decomposableCharacterSet    可分解
illegalCharacterSet    非法
punctuationCharacterSet    标点
capitalizedLetterCharacterSet    大写
symbolCharacterSet    符号
newlineCharacterSet    换行符




#pragma mark -【字符串截取】

//截取指定位置之后的字符串
- (NSString *)substringFromIndex:(NSUInteger)from;
//从0下标开始截取到指定位置的字符串
- (NSString *)substringToIndex:(NSUInteger)to;
//截取指定范围的字符串
- (NSString *)substringWithRange:(NSRange)range;
//截取字符串指定范围的字符
- (void)getCharacters:(unichar *)buffer range:(NSRange)range;


#pragma mark -【字符串比较】

将两个字符串进行计较,返回NSComparisonResult枚举结果
比较结果:

NSComparisonResult    说明
NSOrderedAscending    升序 (左小右大)
NSOrderedSame    相同 (内容相同)
NSOrderedDescending    降序 (左大右小)
比较选项:

NSStringCompareOptions    说明
NSCaseInsensitiveSearch    不区分大小写比较
NSLiteralSearch    区分大小写比较
NSBackwardsSearch    从字符串末尾开始搜索
NSAnchoredSearch    搜索限制范围的字符串
NSNumericSearch    按照字符串里的数字为依据，算出顺序
NSDiacriticInsensitiveSearch    忽略 "-" 符号的比较
NSWidthInsensitiveSearch    忽略字符串的长度，比较出结果
NSForcedOrderingSearch    忽略不区分大小写比较的选项
NSRegularExpressionSearch    只能应用于 rangeOfString:..., stringByReplacingOccurrencesOfString:...和 replaceOccurrencesOfString:...方法

//////////字符串比较//////////
//1.比较
- (NSComparisonResult)compare:(NSString *)string;
//2.比较(指定字符串,条件)
- (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask;
//3.比较(指定字符串,条件,范围)
- (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask range:(NSRange)compareRange;
//4.比较(指定字符串,条件,范围,本地化)
- (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask range:(NSRange)compareRange locale:(nullable id)locale;
//5.比较(不区分大小写)
- (NSComparisonResult)caseInsensitiveCompare:(NSString *)string;

//6.本地化比较
- (NSComparisonResult)localizedCompare:(NSString *)string;
//7.本地化比较(不区分大小写)
- (NSComparisonResult)localizedCaseInsensitiveCompare:(NSString *)string;
//8.本地化比较(标准)
- (NSComparisonResult)localizedStandardCompare:(NSString *)string;

//9.判断两个字符串是否内容一致
- (BOOL)isEqualToString:(NSString *)aString;


#pragma mark -【字符串搜索】

//////////搜索基本//////////
//1.是否包含前缀(以str开头)
- (BOOL)hasPrefix:(NSString *)str;
//2.是否包含后缀(以str结尾)
- (BOOL)hasSuffix:(NSString *)str;
//3.获取公共前缀
- (NSString *)commonPrefixWithString:(NSString *)str options:(NSStringCompareOptions)mask;
//4.是否包含字符串
- (BOOL)containsString:(NSString *)str;
//5.本地化是否包含字符串(不区分大小写)
- (BOOL)localizedCaseInsensitiveContainsString:(NSString *)str;
//6.本地化是否包含字符串(标准)
- (BOOL)localizedStandardContainsString:(NSString *)str;
//7.本地化搜索字符串范围(标准)
- (NSRange)localizedStandardRangeOfString:(NSString *)str;

//////////搜索字符串//////////
//8.搜索(指定字符串)
- (NSRange)rangeOfString:(NSString *)searchString;
//9.搜索(指定字符串,条件)
- (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask;
//10.搜索(指定字符串,条件,范围)
- (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask range:(NSRange)searchRange;
//11.搜索(指定字符串,条件,范围,本地化)
- (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask range:(NSRange)searchRange locale:(nullable NSLocale *)locale;

//////////搜索字符集合//////////
//12.搜索(指定字符集合)
- (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet;
//13.搜索(指定字符集合,条件)
- (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet options:(NSStringCompareOptions)mask;
//14.搜索(指定字符集合,条件,范围)
- (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet options:(NSStringCompareOptions)mask range:(NSRange)searchRange;

//15.用字符串的字符编码指定索引查找位置
- (NSRange)rangeOfComposedCharacterSequenceAtIndex:(NSUInteger)index;
//16.用字符串的字符编码指定区域段查找位置
- (NSRange)rangeOfComposedCharacterSequencesForRange:(NSRange)range;


#pragma mark -【字符串拼接】

//////////字符串拼接//////////
NSString *string = @"1";
NSString *appStr = @"2";
NSString *resultStr1 = [string stringByAppendingString:appStr];
NSString *resultStr2 = [string stringByAppendingFormat:@" + %@", appStr];

NSLog(@"普通拼接:     %@", resultStr1);
NSLog(@"格式化拼接:   %@", resultStr2);
//输出:   普通拼接:     12
//输出:   格式化拼接:   1 + 2




#pragma mark -【字符串基本类型转换】

//////////字符串基本类型转换//////////
NSString *numStr = @"87234.2345";

NSLog(@"double型:        %f", numStr.doubleValue);
NSLog(@"float型:         %f", numStr.floatValue);
NSLog(@"int型:           %d", numStr.intValue);
NSLog(@"NSInteger型:     %ld", numStr.integerValue);
NSLog(@"long long型:     %lld", numStr.longLongValue);
NSLog(@"BOOL型:          %d", numStr.boolValue);
//输出:   double型:        87234.234500
//输出:   float型:         87234.234375
//输出:   int型:           87234
//输出:   NSInteger型:     87234
//输出:   long long型:     87234
//输出:   BOOL型:          1

#pragma mark - 字符串大小写转换

//////////字符串大小写转换//////////
NSString *string = @"string";

NSLog(@"大写:         %@", string.uppercaseString);
NSLog(@"小写:         %@", string.lowercaseString);
NSLog(@"首字母大写:    %@", string.capitalizedString);
//输出:   大写:         STRING
//输出:   小写:         string
//输出:   首字母大写:    String

//本地化(大写)
- (NSString *)uppercaseStringWithLocale:(nullable NSLocale *)locale;
//本地化(小写)
- (NSString *)lowercaseStringWithLocale:(nullable NSLocale *)locale;
//本地化(首字母大写)
- (NSString *)capitalizedStringWithLocale:(nullable NSLocale *)locale;

#pragma mark - 字符串分行,分段

//////////分行//////////
//1.指定范围,分行取字符串
- (void)getLineStart:(nullable NSUInteger *)startPtr end:(nullable NSUInteger *)lineEndPtr contentsEnd:(nullable NSUInteger *)contentsEndPtr forRange:(NSRange)range;
//2.获取指定范围该行的范围
- (NSRange)lineRangeForRange:(NSRange)range;

//////////分段//////////
//3.指定范围,分段取字符串
- (void)getParagraphStart:(nullable NSUInteger *)startPtr end:(nullable NSUInteger *)parEndPtr contentsEnd:(nullable NSUInteger *)contentsEndPtr forRange:(NSRange)range;
//4.获取指定范围该段落的范围
- (NSRange)paragraphRangeForRange:(NSRange)range;

//////////字符串分行,分段//////////
NSString *string = @"123 456\nABC,DEF\nabc.def";
//获取该行的范围(指定范围)
NSRange range1 = [string lineRangeForRange:NSMakeRange(0, 10)];
NSLog(@"%ld 行长度:     %ld", range1.location, range1.length);
//输出:       0 行长度:     16

//获取该段落范围(指定范围)
NSRange range2 = [string paragraphRangeForRange:NSMakeRange(0, 3)];
NSLog(@"%ld 段落长度:   %ld", range2.location, range2.length);
//输出:       0 段落长度:   8
*/



//----------------------- <#我是分割线#> ------------------------//
//----------------------- <#我是分割线#> ------------------------//
//----------------------- <#我是分割线#> ------------------------//
//


#pragma mark - 字符串基本类型转换
```objc
NSString *numStr = @"87234.2345";

NSLog(@"double型:        %f", numStr.doubleValue);
NSLog(@"float型:         %f", numStr.floatValue);
NSLog(@"int型:           %d", numStr.intValue);
NSLog(@"NSInteger型:     %ld", numStr.integerValue);
NSLog(@"long long型:     %lld", numStr.longLongValue);
NSLog(@"BOOL型:          %d", numStr.boolValue);
//打印:   double型:        87234.234500
//打印:   float型:         87234.234375
//打印:   int型:           87234
//打印:   NSInteger型:     87234
//打印:   long long型:     87234
//打印:   BOOL型:          1
```

#pragma mark - 首字母大写
```objc
//首字母大写
NSString *string = @"ligang";
NSLog(@"string: %@",[string capitalizedString]);
// 打印 sting: Ligang


//字符串大小写转换
NSString *string = @"string";

NSLog(@"大写:         %@", string.uppercaseString);
NSLog(@"小写:         %@", string.lowercaseString);
NSLog(@"首字母大写:    %@", string.capitalizedString);
//输出:   大写:         STRING
//输出:   小写:         string
//输出:   首字母大写:    String
```


#pragma mark - 分割字符串
```objc
//分割字符串（分割之后是一个数组）
NSString *string = @"This is a iOSDevTip";
NSArray *array = [string componentsSeparatedByString:@"a"];
NSString *string1 = [array objectAtIndex:0];
NSString *string2 = [array objectAtIndex:1];

NSLog(@"string1:%@  string2:%@",string1,string2);
// 打印 string1:This is   string2: iOSDevTip


NSString *str = @"asd fgh jkl";
NSArray *arr = [str componentsSeparatedByString:@" "];//通过空格符来分隔字符串
NSLog(@"分隔的数组为：%@",arr);// 打印 分隔的数组为：(asd,fgh,jkl)
```


#pragma mark - 追加字符串
```objc
//追加字符串
NSMutableString *string = [[NSMutableString alloc] initWithString:@"I Love "];
[string appendString:@"China"];

NSLog(@"string:%@",string);
// 打印 string:I Love China
```



#pragma mark - 插入字符串
```objc
//插入字符串
NSMutableString *string = [[NSMutableString alloc] initWithString:@"I China"];
[string insertString:@"Love " atIndex:2];

NSLog(@"string: %@",string);
// 打印 string: I Love China
```


#pragma mark - 删除字符串
```objc
//删除字符串
NSMutableString *string = [[NSMutableString alloc] initWithString:@"I love China"];
[string deleteCharactersInRange:NSMakeRange(2, 4)];

NSLog(@"String1: %@",string);
// 打印 String1: I  China
```

#pragma mark - 判断是否包含前后缀
```objc
//判断是否包含前后缀
NSString *string = @"I love China";
BOOL isHasI = [string hasPrefix:@"I"];
BOOL isHasChina = [string hasSuffix:@"China"];
```



#pragma mark - 拼接字符串
```objc
NSString *str3 = @"Coder";
NSString *str4 = [str3 stringByAppendingString:@"LN"];

NSLog(@"%@",str4); // CoderLN


NSString *str5 = [str4 stringByAppendingPathComponent:@"Desktop"];自动添加/线
NSLog(@"%@",str5); // CoderLN/Desktop
```


#pragma mark - 替换字符串
```objc
//替换字符串
NSString *string = @"I love China";
NSString *replaceString = [string stringByReplacingOccurrencesOfString:@"love" withString:@"like"];

NSLog(@"replaceString:  %@",replaceString);
// 打印 replaceString:  I like China
```


#pragma mark - 去除字符串首尾的空格和换行符
```objc
//去除字符串首尾的空格和换行符
NSString *string = @" I love China ";
NSString *text = [string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];

NSLog(@"text:%@",text);
// 打印 text:I love China
```



#pragma mark - 截取字符串
```objc
1.-substringToIndex:// 从字符串的开头一直截取到指定的位置，但不包括该位置的字符

NSString *str = @"asdfghjkl";
str = [str substringToIndex:4];//截取下标4之前的字符串
NSLog(@"截取的值为：%@",str);//截取的值为：asdf

2.-substringFromIndex: //以指定位置开始（包括指定位置的字符），并包括之后的全部字符

NSString *str = @"asdfghjkl";
str = [str substringFromIndex:3];//截取下标3之后的字符串
NSLog(@"截取的值为：%@",str);//截取的值为：fghjkl

3.-substringWithRange: //按照所给出的位置（包括该位置的字符），长度，任意地从字符串中截取子串

NSString *str = @"asdfghjkl";
NSRange range = NSMakeRange(0, 4);
str = [str substringWithRange:range];//截取下标为0长度为4的字符串
NSLog(@"截取的值为：%@",str);//截取的值为：asdf
```


#pragma mark - 遍历字符串
```objc
1.通过查找的方式来遍历(这方式适合所有格式的子符串，推荐使用)

NSString *str =@"asdfghjkl1234欢迎";
NSString *temp = nil;
for(int i =0; i < [str length]; i++) {
    temp = [str substringWithRange:NSMakeRange(i, 1)];
    NSLog(@"第%d个字是:%@",i,temp);
}

2.通过遍历字符的方式遍历字符串(只适合不包含中文的字符串)

NSString *str =@"asdfghjkl1234欢迎";
for(int i =0; i < [str length]; i++) {
    NSLog(@"第%d个字是:%c",i,[str characterAtIndex:i]);
}
```

#pragma mark - 字符串分行,分段
```objc
//字符串分行,分段
NSString *string = @"123 456\nABC,DEF\nabc.def";
//获取该行的范围(指定范围)
NSRange range1 = [string lineRangeForRange:NSMakeRange(0, 10)];
NSLog(@"%ld 行长度:     %ld", range1.location, range1.length);
//输出:       0 行长度:     16

//获取该段落范围(指定范围)
NSRange range2 = [string paragraphRangeForRange:NSMakeRange(0, 3)];
NSLog(@"%ld 段落长度:   %ld", range2.location, range2.length);
//输出:       0 段落长度:   8
```


#pragma mark - 字符串编码和转换
```objc
//字符串编码和转换
NSString *string = @"string";

NSLog(@"最快编码值(枚举):      %lu", (unsigned long)string.fastestEncoding);
NSLog(@"最小编码值(枚举):      %lu", (unsigned long)string.smallestEncoding);
NSLog(@"UTF8编码值:           %s", string.UTF8String);
//输出:     最快编码值(枚举):      1
//输出:     最小编码值(枚举):      1
//输出:     UTF8编码值:           string
```


#pragma mark - 字符串操作(修剪,填充,折叠,替换)
```objc
NSString *string = @"3EWRs a;af";

//修剪
NSString *result1 = [string stringByTrimmingCharactersInSet:[NSCharacterSet lowercaseLetterCharacterSet]];
NSLog(@"%@", result1);
//输出:   3EWRs a;


//填充
NSString *result2 = [string stringByPaddingToLength:20 withString:@"填充" startingAtIndex:1];
NSLog(@"%@", result2);
//输出:   3EWRs a;af充填充填充填充填充填


//折叠
NSString *result3 = [string stringByFoldingWithOptions:NSNumericSearch locale:[NSLocale systemLocale]];
NSLog(@"%@", result3);
//输出:   3EWRs a;af


//替换
//替换(指定字符串)
NSString *result4 = [string stringByReplacingOccurrencesOfString:@" " withString:@"替换"];
NSLog(@"%@", result4);
//输出:   3EWRs替换a;af


//替换(指定字符串,条件,范围)
NSString *result5 = [string stringByReplacingOccurrencesOfString:@"a" withString:@"替换" options:NSRegularExpressionSearch range:NSMakeRange(0, string.length - 2)];
NSLog(@"%@", result5);
//输出:   3EWRs 替换;af


//替换(指定范围)
NSString *result6 = [string stringByReplacingCharactersInRange:NSMakeRange(0, string.length) withString:@"替换"];
NSLog(@"%@", result6);
//输出:   替换
```


#pragma mark - 字符串写入
```objc
//字符串写入
//写入到指定路径,编码的文件中
[string writeToFile:@"/Users/Desktop/LuisX.txt" atomically:YES encoding:NSUTF8StringEncoding error:nil];

//写入到指定URL,编码的文件中
[string writeToURL:[NSURL URLWithString:@"file://LuisX.text"] atomically:YES encoding:NSUTF8StringEncoding error:nil];
```


#pragma mark - NSMutableString 可变字符串扩展方法
```objc
NSMutableString *str = [NSMutableString stringWithString:@"string"];

//插入
[str insertString:@"123" atIndex:2];
NSLog(@"%@", str);
//输出:   st123ring


//删除
[str deleteCharactersInRange:NSMakeRange(2, 2)];
NSLog(@"%@", str);
//输出:   st3ring


//拼接
[str appendString:@"456"];
NSLog(@"%@", str);
//输出:   st3ring456


//格式化拼接
[str appendFormat:@"7 89"];
NSLog(@"%@", str);
//输出:   st3ring4567 89


//设置新字符串
[str setString:@"string"];
NSLog(@"%@", str);
//输出:   string

//字符串替换
//1.指定范围替换
[str1 replaceCharactersInRange:NSMakeRange(2, 2) withString:@"123"];
NSLog(@"%@", str1);
//输出:   st123ng


//2.指定字符串,条件,范围替换
[str1 replaceOccurrencesOfString:@"123" withString:@"--" options:NSRegularExpressionSearch range:NSMakeRange(0, str1.length)];
NSLog(@"%@", str1);
//输出:   st--ng
```

#pragma mark - 比较字符串
```objc

NSString *str11 = @"123";

// 判断字符串是否以abc开头
BOOL flag =  [str10 hasPrefix:@"abc"];

NSLog(@"%zd",flag); //1
// 判断字符串是否bcd结尾
BOOL flag1 = [str10 hasSuffix:@"2"];

NSLog(@"%zd",flag1); //0

NSLog(@"%d", [str10 containsString:str11]);//1
```


#pragma mark - 字符串翻译
```objc
NSString *dalian = @"大连";
NSString *result = [dalian stringByApplyingTransform:NSStringTransformMandarinToLatin reverse:NO];

NSLog(@"%@", result);
//输出:   dà lián
```







