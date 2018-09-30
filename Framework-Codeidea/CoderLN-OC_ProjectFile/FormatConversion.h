/*
 * FormatConversion.h 常用数据格式转换
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */



#### 汉字 - UTF8
```objc
 NSString* strA = [@"%E4%B8%AD%E5%9B%BD" stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
 // 中国

 - - -
 NSString *strB = [@"中国" stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
 // %E4%B8%AD%E5%9B%BD
```

#### Unicode - 汉字
 
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


#### Byte字节 - NSData
 
```objc
 Byte byte[] = {0x55, 0x07, 0x02, 0x01, 0x1A, 0x01, 0xAA};
 NSData *data = [NSData dataWithBytes:byte lenght:7];

 - - -
 NSString *testString = @"1234567890";
 NSData *testData = [testString dataUsingEncoding:NSUTF8StringEncoding];
 Byte *testByte = (Byte *)[testData bytes];
```


 


#### int - NSData
```objc
 int i = 1;
 NSData *data = [NSData dataWithBytes:&i length: sizeof(i)];

 - - -
 int k;
 [data getBytes: &k length: sizeof(k)];
```



#### NSData - NSString
```objc
 NSString *str = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];

 - - -
 NSString *str = @"1234";
 NSData *data = [str dataUsingEncoding:NSUTF8StringEncoding];
```


#### UIImage - NSData
```objc
 NSData *imagePngData = UIImagePNGRepresentation(image);
 NSData *imageJpgData = UIImageJPEGRepresentation(image,0);

 - - -
 NSData *imageData = [NSData dataWithContentsOfFile:filePath];
 UIImage *image = [UIImage imageWithData:imageData];
```

#### NSURL - NSString
```objc
 NSURL * url = [NSURL URLWithString:@""];

 - - -
 NSString * urlStr = url.absoluteString;
```




 
 
 
