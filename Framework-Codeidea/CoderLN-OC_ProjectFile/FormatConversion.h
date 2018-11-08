/*
 * FormatConversion.h 常用数据格式转换
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */



#pragma mark - 汉字 - UTF8
```objc
 NSString* strA = [@"%E4%B8%AD%E5%9B%BD" stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
 // 中国

 - - -
 NSString *strB = [@"中国" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
 // %E4%B8%AD%E5%9B%BD
```

#pragma mark - Unicode - 汉字
 
```objc
 NSString *content = @"\\u4e2d\\u56fd";
 content = [self replaceUnicode:content];
 // 中国
 
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


#pragma mark - Byte字节 - NSData
 
```objc
 Byte byte[] = {0x55, 0x07, 0x02, 0x01, 0x1A, 0x01, 0xAA};
 NSData *data = [NSData dataWithBytes:byte lenght:7];

 - - -
 NSString *testString = @"1234567890";
 NSData *testData = [testString dataUsingEncoding:NSUTF8StringEncoding];
 Byte *testByte = (Byte *)[testData bytes];
```


 


#pragma mark - int - NSData
```objc
 int i = 1;
 NSData *data = [NSData dataWithBytes:&i length: sizeof(i)];

 - - -
 int k;
 [data getBytes: &k length: sizeof(k)];
```



#pragma mark - NSData - NSString
```objc
 NSString *str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];

 - - -
 NSString *str = @"1234";
 NSData *data = [str dataUsingEncoding:NSUTF8StringEncoding];
```


#pragma mark - UIImage - NSData
```objc
 NSData *imagePngData = UIImagePNGRepresentation(image);
 NSData *imageJpgData = UIImageJPEGRepresentation(image,0);

 - - -
 NSData *imageData = [NSData dataWithContentsOfFile:filePath];
 UIImage *image = [UIImage imageWithData:imageData];
```

#pragma mark - NSURL - NSString
```objc
 NSURL * url = [NSURL URLWithString:@""];

 - - -
 NSString * urlStr = url.absoluteString;
```




 
 
 
