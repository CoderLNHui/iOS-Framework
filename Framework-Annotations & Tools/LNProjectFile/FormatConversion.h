/*
 * FormatConversion.h【常用数据格式转换-阶段续更】
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */




/**
 
#### 汉字 - UTF8

```objc
 NSString* strA = [@"%E4%B8%AD%E5%9B%BD" stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
 NSString *strB = [@"中国" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
 NSLog(@"%@",strA); // 中国
 NSLog(@"%@",strB); // %E4%B8%AD%E5%9B%BD
```
 
 
 
#### Unicode 转汉字
 
```objc
 NSString *content = @"\\u4e2d\\u56fd";
 content = [self replaceUnicode:content];
 NSLog(@"%@",content); // 中国
 
 - (NSString *)replaceUnicode:(NSString *)unicodeStr {
 
    NSString *tempStr1 = [unicodeStr stringByReplacingOccurrencesOfString:@"\\u"withString:@"\\U"];
    NSString *tempStr2 = [tempStr1 stringByReplacingOccurrencesOfString:@"\""withString:@"\\\""];
    NSString *tempStr3 = [[@"\""stringByAppendingString:tempStr2]stringByAppendingString:@"\""];
    NSData *tempData = [tempStr3 dataUsingEncoding:NSUTF8StringEncoding];
    NSString* returnStr = [NSPropertyListSerialization propertyListFromData:tempData
    mutabilityOption:NSPropertyListImmutable
    format:NULL
    errorDescription:NULL];

    return [returnStr stringByReplacingOccurrencesOfString:@"\\r\\n"withString:@"\n"];
 }
```

 
 
 
 
#### Byte字节 - NSData
 
```objc
 Byte 转化为 NSData
 Byte byte[] = {0x55, 0x07, 0x02, 0x01, 0x1A, 0x01, 0xAA};
 NSData *data = [NSData dataWithBytes:byte lenght:7];
 
 
 NSData 转化为 Byte
 NSString *testString = @"1234567890";
 NSData *testData = [testString dataUsingEncoding: NSUTF8StringEncoding];
 Byte *testByte = (Byte *)[testData bytes];
```





#### int - NSData
 
```objc
 int 转化为 NSData
 int i = 1;
 NSData *data = [NSData dataWithBytes:&i length: sizeof(i)];
 
 
 NSData 转化为 int
 int k;
 [data getBytes: &k length: sizeof(k)];
```



#### NSData - NSString
 
```objc
 NSData 转化为 NSString
 NSString *aString = [[NSString alloc] initWithData:adata encoding:NSUTF8StringEncoding];
 
 
 NSString 转化为 NSData
 NSString *aString = @"1234";
 NSData *aData = [aString dataUsingEncoding: NSUTF8StringEncoding];
```





#### UIImage - NSData
 
```objc
 UIImage 转化为 NSData
 NSData *imageData = UIImagePNGRepresentation(image);
 
 
 NSData 转化为 UIImage
 NSData *imageData = [NSData dataWithContentsOfFile: filePath];
 UIImage *image = [UIImage imageWithData: imageData];
```



#### 大小端
 
```objc
 假如你们公司后台是java开发的，而之间又要进行数据传输，那么可能就会涉及大小端的数据问题。因为java默认是大端，iOS采用的是小端模式，所以需要转化。具体操作如下：
 
 先进行大小端判断
 int checkCPUendian() {//返回1，为小端；反之，为大端；
    union
    {
        unsigned int  a;
        unsigned char b;
    }c;
    c.a = 1;
    return 1 == c.b;
 }
 
 再将小端转化为大端, 利用C语言函数ntohl()进行转换
 int newSize = size;
 if (checkCPUendian() == 1) {
    newSize = ntohl(size);//小端转大端
 }
```





 
####
 
```objc


```


####
 
```objc


```





####
 
```objc


```
 
 
 
 
 
 */
