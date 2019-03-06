/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import "NSString+Hash.h"
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>
#import <CommonCrypto/CommonHMAC.h>
#import "GTMBase64.h"




#pragma mark - Base64编码方案
@implementation NSString (BASE64)

//从iOS7.0 开始，苹果就提供了base64的编码和解码支持
// 对一个字符串进行base64编码,并且返回
- (NSString *)base64EncodeString
{
    //1.先转换为二进制数据
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    
    //2.对二进制数据进行base64编码,完成之后返回字符串
    return [data base64EncodedStringWithOptions:0];
}

// 对base64编码之后的字符串解码,并且返回
-(NSString *)base64DecodeString
{
    //注意:该字符串是base64编码后的字符串
    //1.转换为二进制数据(完成了解码的过程)
    NSData *data = [[NSData alloc] initWithBase64EncodedString:self options:0];
    
    //2.把二进制数据在转换为字符串
    return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}

@end


#pragma mark - 哈希(散列)函数
@implementation NSString (Hash)

#pragma mark -md5/sha 字符串加密
//#import <CommonCrypto/CommonDigest.h>
- (NSString *)md5String
{
    const char *str = self.UTF8String;
    uint8_t buffer[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5(str, (CC_LONG)strlen(str), buffer);
    
    return [self stringFromBytes:buffer length:CC_MD5_DIGEST_LENGTH];
}

- (NSString *)sha1String
{
    const char *str = self.UTF8String;
    uint8_t buffer[CC_SHA1_DIGEST_LENGTH];
    
    CC_SHA1(str, (CC_LONG)strlen(str), buffer);
    
    return [self stringFromBytes:buffer length:CC_SHA1_DIGEST_LENGTH];
}

- (NSString *)sha256String
{
    const char *str = self.UTF8String;
    uint8_t buffer[CC_SHA256_DIGEST_LENGTH];
    
    CC_SHA256(str, (CC_LONG)strlen(str), buffer);
    
    return [self stringFromBytes:buffer length:CC_SHA256_DIGEST_LENGTH];
}

- (NSString *)sha512String
{
    const char *str = self.UTF8String;
    uint8_t buffer[CC_SHA512_DIGEST_LENGTH];
    
    CC_SHA512(str, (CC_LONG)strlen(str), buffer);
    
    return [self stringFromBytes:buffer length:CC_SHA512_DIGEST_LENGTH];
}

#pragma mark -HMAC 字符串加密
- (NSString *)hmacMD5StringWithKey:(NSString *)key
{
    const char *keyData = key.UTF8String;
    const char *strData = self.UTF8String;
    uint8_t buffer[CC_MD5_DIGEST_LENGTH];
    
    CCHmac(kCCHmacAlgMD5, keyData, strlen(keyData), strData, strlen(strData), buffer);
    
    return [self stringFromBytes:buffer length:CC_MD5_DIGEST_LENGTH];
}

- (NSString *)hmacSHA1StringWithKey:(NSString *)key
{
    const char *keyData = key.UTF8String;
    const char *strData = self.UTF8String;
    uint8_t buffer[CC_SHA1_DIGEST_LENGTH];
    
    CCHmac(kCCHmacAlgSHA1, keyData, strlen(keyData), strData, strlen(strData), buffer);
    
    return [self stringFromBytes:buffer length:CC_SHA1_DIGEST_LENGTH];
}

- (NSString *)hmacSHA256StringWithKey:(NSString *)key
{
    const char *keyData = key.UTF8String;
    const char *strData = self.UTF8String;
    uint8_t buffer[CC_SHA256_DIGEST_LENGTH];
    
    CCHmac(kCCHmacAlgSHA256, keyData, strlen(keyData), strData, strlen(strData), buffer);
    
    return [self stringFromBytes:buffer length:CC_SHA256_DIGEST_LENGTH];
}

- (NSString *)hmacSHA512StringWithKey:(NSString *)key
{
    const char *keyData = key.UTF8String;
    const char *strData = self.UTF8String;
    uint8_t buffer[CC_SHA512_DIGEST_LENGTH];
    
    CCHmac(kCCHmacAlgSHA512, keyData, strlen(keyData), strData, strlen(strData), buffer);
    
    return [self stringFromBytes:buffer length:CC_SHA512_DIGEST_LENGTH];
}


#pragma mark -文件加密
#define FileHashDefaultChunkSizeForReadingData 4096
- (NSString *)fileMD5Hash
{
    NSFileHandle *fp = [NSFileHandle fileHandleForReadingAtPath:self];
    if (fp == nil) {
        return nil;
    }
    
    CC_MD5_CTX hashCtx;
    CC_MD5_Init(&hashCtx);
    
    while (YES) {
        @autoreleasepool {
            NSData *data = [fp readDataOfLength:FileHashDefaultChunkSizeForReadingData];
            
            CC_MD5_Update(&hashCtx, data.bytes, (CC_LONG)data.length);
            
            if (data.length == 0) {
                break;
            }
        }
    }
    [fp closeFile];
    
    uint8_t buffer[CC_MD5_DIGEST_LENGTH];
    CC_MD5_Final(buffer, &hashCtx);
    
    return [self stringFromBytes:buffer length:CC_MD5_DIGEST_LENGTH];
}

- (NSString *)fileSHA1Hash
{
    NSFileHandle *fp = [NSFileHandle fileHandleForReadingAtPath:self];
    if (fp == nil) {
        return nil;
    }
    
    CC_SHA1_CTX hashCtx;
    CC_SHA1_Init(&hashCtx);
    
    while (YES) {
        @autoreleasepool {
            NSData *data = [fp readDataOfLength:FileHashDefaultChunkSizeForReadingData];
            
            CC_SHA1_Update(&hashCtx, data.bytes, (CC_LONG)data.length);
            
            if (data.length == 0) {
                break;
            }
        }
    }
    [fp closeFile];
    
    uint8_t buffer[CC_SHA1_DIGEST_LENGTH];
    CC_SHA1_Final(buffer, &hashCtx);
    
    return [self stringFromBytes:buffer length:CC_SHA1_DIGEST_LENGTH];
}

- (NSString *)fileSHA256Hash
{
    NSFileHandle *fp = [NSFileHandle fileHandleForReadingAtPath:self];
    if (fp == nil) {
        return nil;
    }
    
    CC_SHA256_CTX hashCtx;
    CC_SHA256_Init(&hashCtx);
    
    while (YES) {
        @autoreleasepool {
            NSData *data = [fp readDataOfLength:FileHashDefaultChunkSizeForReadingData];
            
            CC_SHA256_Update(&hashCtx, data.bytes, (CC_LONG)data.length);
            
            if (data.length == 0) {
                break;
            }
        }
    }
    [fp closeFile];
    
    uint8_t buffer[CC_SHA256_DIGEST_LENGTH];
    CC_SHA256_Final(buffer, &hashCtx);
    
    return [self stringFromBytes:buffer length:CC_SHA256_DIGEST_LENGTH];
}

- (NSString *)fileSHA512Hash
{
    NSFileHandle *fp = [NSFileHandle fileHandleForReadingAtPath:self];
    if (fp == nil) {
        return nil;
    }
    
    CC_SHA512_CTX hashCtx;
    CC_SHA512_Init(&hashCtx);
    
    while (YES) {
        @autoreleasepool {
            NSData *data = [fp readDataOfLength:FileHashDefaultChunkSizeForReadingData];
            
            CC_SHA512_Update(&hashCtx, data.bytes, (CC_LONG)data.length);
            
            if (data.length == 0) {
                break;
            }
        }
    }
    [fp closeFile];
    
    uint8_t buffer[CC_SHA512_DIGEST_LENGTH];
    CC_SHA512_Final(buffer, &hashCtx);
    
    return [self stringFromBytes:buffer length:CC_SHA512_DIGEST_LENGTH];
}

// 返回二进制 Bytes 流的字符串表示形式
// bytes  二进制 Bytes 数组,length 数组长度
- (NSString *)stringFromBytes:(uint8_t *)bytes length:(int)length
{
    NSMutableString *strM = [NSMutableString string];
    
    for (int i = 0; i < length; i++) {
        [strM appendFormat:@"%02x", bytes[i]];
    }
    
    return [strM copy];
}
@end

 






/**
 HMAC ：使用一个密钥加密并且两次的散列！
 
 以用户账号登录注册为例
 
 注册：
 1.客户端向服务器发起注册请求，这时服务器生成一个密钥key（并保存）,然后将密钥返回给客户端。
 2.客户端根据密钥对密码进行HMAC加密生成密文，传给服务器，服务器保存（不允许明文保存用户的隐私信息）。
 3.服务器返回注册成功后，客户端将密钥保存到手机钥匙串（减少密钥传递次数，提高安全性）。
 
 登录：
 1.客户端读取手机钥匙串中的密钥，对密码进行HMAC加密后，向服务器发出登录请求。
 2.服务器根据账号读取数据库中的密文与客户端提交的进行比较。
 
 
 引申：可以利用这个做出类型于设备锁或QQ手机令牌的功能，目的就是为了在他人设备上无法登录自己的账号。
 这里说下大致的流程，在客户端发出登录请求时，在手机钥匙串读取密钥，当这个密钥不存在的时，就说明是在他人设备上操作的，这时可以利用推送通知或短信告诉自己，是否允许他人设备登录，只允许此次登录还是授权永久登录。如果仅登陆一次则不保存密钥到钥匙串，下次登录重复以上操作；如果授权永久登录可以再他人设备保存密钥。
 
 那么这样就安全了吗？too young！！！
 如果在第2步中，拦截post内容获取加密后的密文，再模拟客户端向服务器发出请求，就成功黑了！
 
 再次提高安全性：添加时间戳
 
 第一步：客户端将HMAC得到的数据拼接当前服务器时间，再用MD5加密。
 即(HMAC+201802271633).md5String，将加密后的数据post到服务器。
 注：201802271633 须为当前服务器时间，避免客户端时间不统一。
 
 第二步：服务器开始验证：根据账号在数据库中读取HMAC，将当前服务器时间拼接后，再用MD5加密，得到32位字符与客户端提交的32位字符进行比较。这里会有两种情况，1.服务器拼接的时间与客户端拼接的时间一致，得到相同的密文，则通过验证；2.服务器拼接的时间与客户端拼接的时间不一致，得到的密文不相同。这是服务器就拼接上一个时间，即：客服端密文是：(HMAC+201802271633).md5String，服务器第一次拼接时间密文是：(HMAC+201802271634).md5String。两者不一致，服务器第二次拼接上一个时间段密文：(HMAC+201802271633).md5String，一致则通过。
 
 进行这样的操作就是让客户端发出的请求的时间有效性只维持1分钟，如果还觉得不安全可以再拼接时间的时候添加秒，进一步缩短时间的有效性，以提高安全性。
 
 */








