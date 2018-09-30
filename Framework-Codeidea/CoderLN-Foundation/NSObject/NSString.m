/*
 * NSString.m
 *
 * Foundation (c) 1994-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#pragma mark - 【字符串属性】

```objc
NSString *str1 = @"string";

NSLog(@"长度:                   %ld", str1.length);
NSLog(@"描述:                   %@", str1.description);
NSLog(@"哈希地址:                %lu", (unsigned long)str1.hash);
NSLog(@"字符串对应下标字符:        %c", [str1 characterAtIndex:2]);

//打印：   长度:                   6
//打印：   描述:                   string
//打印：   哈希地址:                10152471993823965
//打印：   字符串对应下标字符:        r
```


#pragma mark - 【字符串截取】

```objc
NSString * str = @"abcdefghikj";

NSString * str1 = [str substringFromIndex:3];//截取从下标为3之后字符串（包含3）
NSString * str2 = [str substringToIndex:4];//截取下标为4之前的字符串（不包含4）
NSString * str3 = [str substringWithRange:NSMakeRange(2, 5)];//截取下标为2 长度为5个的字符串

NSLog(@"%@",str1);
NSLog(@"%@",str1);
NSLog(@"%@",str1);

//打印：defghikj
//打印：abcd
//打印：cdefg
```


#pragma mark - 【字符串比较】




#pragma mark - 【字符串搜索】

#pragma mark -判断是否包含前后缀和包含字符串
```objc
NSString *string = @"I love China";
NSString *string1 = @"love";

BOOL isHasI = [string hasPrefix:@"I"];// 前缀
BOOL isHasChina = [string hasSuffix:@"China"];// 后缀
BOOL isContainsStr = [string containsString:string1];;// 包含字符串
```


#pragma mark -截取指定字符串
```objc
//source = <a href="http://app.weibo.com/t/feed/6vtZb0" rel="nofollow">微博 weibo.com</a>

NSString *source = status.source;
if (![source isEqualToString:@""]) {
    NSUInteger startIndex = [source rangeOfString:@">"].location + 1;
    NSUInteger length = [source rangeOfString:@"</"].location - startIndex;
    self.sourceText = [source substringWithRange:NSMakeRange(startIndex, length)];
    
    NSLog(@"需要截取内容为 - %@",self.sourceText);
    //打印：需要截取内容为 - 微博 weibo.com
}

- - -
NSString * result = @"<a>:\\登录成功</a>";

NSUInteger loc = [result rangeOfString:@":\\"].location + 2;
NSUInteger len =  [result rangeOfString:@"</a"].location - loc;
NSString *msg = [result substringWithRange:NSMakeRange(loc, len)];

NSLog(@"%@",msg);
//打印：登录成功
```


#pragma mark - 【字符串拼接】
```objc
NSString * str1 = @"/Users/CoderLN/Desktop";
NSString * str2 = @"CoderLN.plist";

NSString * str3 = [str1 stringByAppendingString:[NSString stringWithFormat:@"/%@",str2]];//需要手动添加斜线/
NSString * str4 = [str1 stringByAppendingFormat:@"+%@", str2];//格式化拼接
NSString * str5 = [str1 stringByAppendingPathComponent:str2];//自动添加斜线/
NSString * str6 = [str1 stringByAppendingPathExtension:str2];//自动添加点.

NSLog(@"\n%@\n %@\n %@\n %@\n",str3,str4,str5,str6);
//打印：3/Users/CoderLN/Desktop/CoderLN.plist
//打印：4/Users/CoderLN/Desktop+CoderLN.plist
//打印：5/Users/CoderLN/Desktop/CoderLN.plist
//打印：6/Users/CoderLN/Desktop.CoderLN.plist
```


#pragma mark - 【字符串基本类型转换】
```objc
NSString *numStr = @"87234.2345";

NSLog(@"double型:        %f", numStr.doubleValue);
NSLog(@"float型:         %f", numStr.floatValue);
NSLog(@"int型:           %d", numStr.intValue);
NSLog(@"NSInteger型:     %ld", numStr.integerValue);
NSLog(@"long long型:     %lld", numStr.longLongValue);
NSLog(@"BOOL型:          %d", numStr.boolValue);

//打印：   double型:        87234.234500
//打印：   float型:         87234.234375
//打印：   int型:           87234
//打印：   NSInteger型:     87234
//打印：   long long型:     87234
//打印：   BOOL型:          1
```



#pragma mark - 【字符串大小写转换】
```objc
NSString *string = @"string";

NSLog(@"大写:         %@", string.uppercaseString);
NSLog(@"小写:         %@", string.lowercaseString);
NSLog(@"首字母大写:    %@", string.capitalizedString);

//输出:   大写:         STRING
//输出:   小写:         string
//输出:   首字母大写:    String
```



#pragma mark - 【字符串分行,分段】

#pragma mark -获取指定范围 该行、该段的范围
```objc
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

#pragma mark -字符串列举
```objc
NSString *string = @"123456\nABCDEF\nabcdef";
//列举(按行)
[string enumerateLinesUsingBlock:^(NSString * _Nonnull line, BOOL * _Nonnull stop) {
    NSLog(@"每行:   %@", line);
}];
//输出:    每行:   123456
//输出:    每行:   ABCDEF
//输出:    每行:   abcdef


//列举(范围,条件)
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
```

#pragma mark - 【字符串编码和转换】
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






#pragma mark - 【字符串操作(分割,修剪,填充,折叠,替换)】

#pragma mark -分割字符串
```objc
//指定符号分割字符串（分割之后是一个数组）
NSString *string = @"This is a iOSDevTip";
NSArray *array = [string componentsSeparatedByString:@"a"];
NSString *string1 = [array objectAtIndex:0];
NSString *string2 = [array objectAtIndex:1];

NSLog(@"string1:%@  string2:%@",string1,string2);
// 打印 string1:This is   string2: iOSDevTip

- - -
//通过空格符来分隔字符串
NSString *str = @"ABC fgh jkl";
NSArray *arr = [str componentsSeparatedByString:@" "];

NSLog(@"分隔的数组为：%@",arr);
// 打印 分隔的数组为：(ABC,fgh,jkl)

- - -
//分割(指定字符集合)
NSString *strr = @"AbCDeFGHjK";
NSArray *resultAry = [strr componentsSeparatedByCharactersInSet:[NSCharacterSet lowercaseLetterCharacterSet]];//小写字母字符集

NSLog(@"%@", resultAry);
//输出:   (A,CD,FGH,K)
```




#pragma mark -修剪,填充,折叠,替换
```objc
NSString *string = @"3aEWRs a;af";

//修剪
NSString *result1 = [string stringByTrimmingCharactersInSet:[NSCharacterSet lowercaseLetterCharacterSet]];//小写字母
NSLog(@"%@", result1);
//输出:   3aEWRs a;


//填充
NSString *result2 = [string stringByPaddingToLength:20 withString:@"填充" startingAtIndex:1];
NSLog(@"%@", result2);
//输出:   3aEWRs a;af充填充填充填充填充


//折叠
NSString *result3 = [string stringByFoldingWithOptions:NSNumericSearch locale:[NSLocale systemLocale]];
NSLog(@"%@", result3);
//输出:   3aEWRs a;af


//替换
//替换(指定字符串)
NSString *result4 = [string stringByReplacingOccurrencesOfString:@" " withString:@"替换"];
NSLog(@"%@", result4);
//输出:   3aEWRs替换a;af


//替换(指定字符串,条件,范围)
NSString *result5 = [string stringByReplacingOccurrencesOfString:@"a" withString:@"替换" options:NSRegularExpressionSearch range:NSMakeRange(0, string.length - 4)];
NSLog(@"%@", result5);
//输出:   3替换EWRs a;af


//替换(指定范围)
NSString *result6 = [string stringByReplacingCharactersInRange:NSMakeRange(0, 3) withString:@"替换"];
NSLog(@"%@", result6);
//输出:   替换WRs a;af
```

#pragma mark -字符串翻译
```objc
NSString *dalian = @"大连";
NSString *result = [dalian stringByApplyingTransform:NSStringTransformMandarinToLatin reverse:NO];

NSLog(@"%@", result);
//输出:   dà lián
```

#pragma mark -字符串写入
```objc
//字符串写入
//写入到指定路径,编码的文件中
[string writeToFile:@"/Users/Desktop/LuisX.txt" atomically:YES encoding:NSUTF8StringEncoding error:nil];

//写入到指定URL,编码的文件中
[string writeToURL:[NSURL URLWithString:@"file://LuisX.text"] atomically:YES encoding:NSUTF8StringEncoding error:nil];
```






#pragma mark - 【NSMutableString 插入,删除,拼接,替换】

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
[str appendFormat:@"789"];
NSLog(@"%@", str);
//输出:   st3ring456789


//设置新字符串
[str setString:@"string"];
NSLog(@"%@", str);
//输出:   string

//字符串替换
//1.指定范围替换
[str replaceCharactersInRange:NSMakeRange(2, 2) withString:@"n替换"];
NSLog(@"%@", str);
//输出:   stn替换ng


//2.指定字符串,条件,范围替换
[str replaceOccurrencesOfString:@"n" withString:@"开发" options:NSRegularExpressionSearch range:NSMakeRange(0, str.length - 2)];
NSLog(@"%@", str);
//输出:   st开发替换ng
```






#pragma mark - 【场景】

#pragma mark -场景：判断字符串的值为空
```objc
- (BOOL)isBlankString:(NSString *)string {
    NSLog(@"判断是否为空的字符串：%@",string);
    if (string == nil || string == NULL) return YES;
    if ([string isKindOfClass:[NSNull class]]) return YES;
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) return YES;
    
    return NO;
}
```

#pragma mark -场景：遍历字符串
```objc
//1.通过查找的方式来遍历(这方式适合所有格式的子符串，推荐使用)
NSString *str =@"asdfghjkl1234欢迎";
NSString *temp = nil;
for(int i =0; i < [str length]; i++) {
    temp = [str substringWithRange:NSMakeRange(i, 1)];
    NSLog(@"第%d个字是:%@",i,temp);
}

//2.通过遍历字符的方式遍历字符串(只适合不包含中文的字符串)
NSString *str1 =@"asdfghjkl1234欢迎";
for(int i =0; i < [str1 length]; i++) {
    NSLog(@"第%d个字是:%c",i,[str1 characterAtIndex:i]);
}

- - -
 第0个字是:a
 第1个字是:s
 第2个字是:d
 第3个字是:f
 第4个字是:g
 第5个字是:h
 第6个字是:j
 第7个字是:k
 第8个字是:l
 第9个字是:1
 第10个字是:2
 第11个字是:3
 第12个字是:4
 第13个字是:欢
 第14个字是:迎
```


#pragma mark -场景：数据请求返回后判断url是否是GIF（判断后缀或扩展名）
```objc
// 数据请求返回后判断url是否是GIF
- (void)dealGIF
{
    LNTopicItem *topicItem = [[LNTopicItem alloc] init];
    // 判断url是否是GIF方法一：（lowercaseString 转小写; uppercaseString 转大写）
    // containsString: 字符串包含; hasSuffix: 后缀
    if ([topicItem.image1.lowercaseString hasSuffix:@"gif"]){
        
    }
    
    // 判断url是否是GIF方法二：（pathExtension 扩展名）
    if ([topicItem.image1.pathExtension.lowercaseString isEqualToString:@"gif"]) {
        self.gifView.hidden = NO;
    } else {
        self.gifView.hidden = YES;
    }
}
```



#pragma mark -场景：截取字符串(延迟执行,弹框提示用户登录请求结果)
```objc
// 截取字符串(延迟执行,弹框提示用户登录请求结果)
- (void)showWithResult:(NSString *)result {
    
    NSUInteger loc = [result rangeOfString:@":\""].location + 2;
    NSUInteger len =  [result rangeOfString:@"\"}"].location - loc;
    NSString *msg = [result substringWithRange:NSMakeRange(loc, len)];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if ([result containsString:@"error"]) {
            [SVProgressHUD showErrorWithStatus:msg];
        }else {
            [SVProgressHUD showSuccessWithStatus:msg];
        }
    });
    NSLog(@"\n%@",[NSThread currentThread]);
}
```

































