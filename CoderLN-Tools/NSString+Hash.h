/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


/**
 常用加密方式
 1. 编码方案：Base64
 2. 哈希（散列）函数：MD5、hmacMD5、SHA1、SHA256、SHA512
 3. 对称加密算法：DES、3DES、AES
 4. 非对称加密算法：RSA
 5. HTTPS：HTTP+SSL协议
 */

#import <Foundation/Foundation.h>

#pragma mark - Base64编码方案
@interface NSString (BASE64)

/**
 *  终端测试命令：
 *  -o 表示输入；-D 表示解码
 *  base64 123.png -o 123.txt
 *  base64 123.txt -o test.png -D
 *  echo -n A | base64
 *  echo -n QQ== |base64 -D
 */
/**
 *  对一个字符串进行base64编码,并且返回
 */
- (NSString *)base64EncodeString;

/**
 *  对base64编码之后的字符串解码,并且返回
 */
- (NSString *)base64DecodeString;
@end


#pragma mark - 哈希(散列)函数
@interface NSString (Hash)
#pragma mark -md5/sha 字符串加密
/**
 *  散列函数--md5对字符串加密
 *
 *  终端测试命令：
 *  @code
 *  md5 -s "string"
 *  @endcode
 *
 *  <p>提示：随着 MD5 碰撞生成器的出现，MD5 算法不应被用于任何软件完整性检查或代码签名的用途。<p>
 *
 *  @return 32个字符的MD5散列字符串
 */
- (NSString *)md5String;


/**
 *  散列函数--sha1对字符串加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha1
 *  @endcode
 *
 *  @return 40个字符的SHA1散列字符串
 */
- (NSString *)sha1String;


/**
 *  散列函数--sha256对字符串加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha256
 *  @endcode
 *
 *  @return 64个字符的SHA256散列字符串
 */
- (NSString *)sha256String;


/**
 *  散列函数--sha512对字符串加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha512
 *  @endcode
 *
 *  @return 128个字符的SHA 512散列字符串
 */
- (NSString *)sha512String;

#pragma mark -HMAC 字符串加密
/**
 *  散列函数--HMAC md5加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl dgst -md5 -hmac "key"
 *  @endcode
 *
 *  @return 32个字符的HMAC MD5散列字符串
 */
- (NSString *)hmacMD5StringWithKey:(NSString *)key;


/**
 *  散列函数--HMAC sha1加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha1 -hmac "key"
 *  @endcode
 *
 *  @return 40个字符的HMAC SHA1散列字符串
 */
- (NSString *)hmacSHA1StringWithKey:(NSString *)key;


/**
 *  散列函数--HMAC sha256加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha256 -hmac "key"
 *  @endcode
 *
 *  @return 64个字符的HMAC SHA256散列字符串
 */
- (NSString *)hmacSHA256StringWithKey:(NSString *)key;


/**
 *  散列函数--HMAC sha512加密
 *
 *  终端测试命令：
 *  @code
 *  echo -n "string" | openssl sha -sha512 -hmac "key"
 *  @endcode
 *
 *  @return 128个字符的HMAC SHA512散列字符串
 */
- (NSString *)hmacSHA512StringWithKey:(NSString *)key;


#pragma mark -对文件加密
/**
 *  散列函数--md5对文件加密
 *
 *  终端测试命令：
 *  @code
 *  md5 file.dat
 *  @endcode
 *
 *  @return 32个字符的MD5散列字符串
 */
- (NSString *)fileMD5Hash;


/**
 *  散列函数--sha1对文件加密
 *
 *  终端测试命令：
 *  @code
 *  openssl sha -sha1 file.dat
 *  @endcode
 *
 *  @return 40个字符的SHA1散列字符串
 */
- (NSString *)fileSHA1Hash;


/**
 *  散列函数--sha256对文件加密
 *
 *  终端测试命令：
 *  @code
 *  openssl sha -sha256 file.dat
 *  @endcode
 *
 *  @return 64个字符的SHA256散列字符串
 */
- (NSString *)fileSHA256Hash;


/**
 *  散列函数--sha512对文件加密
 *
 *  终端测试命令：
 *  @code
 *  openssl sha -sha512 file.dat
 *  @endcode
 *
 *  @return 128个字符的SHA512散列字符串
 */
- (NSString *)fileSHA512Hash;
@end

 


