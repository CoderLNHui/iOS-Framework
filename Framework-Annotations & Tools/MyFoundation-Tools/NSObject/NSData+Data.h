/*
 * NSData+Data.h
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import <Foundation/Foundation.h>

@interface NSData (Data)

@end

@interface NSData (APNSToken)
/**
 *  @brief  将APNS NSData类型token 格式化成字符串
 *
 *  @return 整理过后的字符串token
 */
- (NSString *)APNSTokenString;
@end



// (https://github.com/shaojiankui/JKCategories)
@interface NSData (Base64)
/**
 *  @brief  字符串base64后转data
 *
 *  @param string 传入字符串
 *
 *  @return 传入字符串 base64后的data
 */
+ (NSData *)dataWithBase64EncodedString:(NSString *)string;
/**
 *  @brief  NSData转string
 *
 *  @param wrapWidth 换行长度  76  64
 *
 *  @return base64后的字符串
 */
- (NSString *)base64EncodedStringWithWrapWidth:(NSUInteger)wrapWidth;
/**
 *  @brief  NSData转string 换行长度默认64
 *
 *  @return base64后的字符串
 */
- (NSString *)base64EncodedString;
@end



@interface NSData (DataCache)

/**
 *  将URL作为key保存到磁盘里缓存起来
 *
 *  @param identifier url.absoluteString
 */
- (void)saveDataCacheWithIdentifier:(NSString *)identifier;

/**
 *  取出缓存data
 *
 *  @param identifier url.absoluteString
 *
 *  @return 缓存
 */
+ (NSData *)getDataCacheWithIdentifier:(NSString *)identifier;

@end



//  (https://github.com/shaojiankui/JKCategories)
@interface NSData (Encrypt)

/**
 *  利用AES加密数据
 *
 *  @param key key
 *  @param iv  iv description
 *
 *  @return data
 */
- (NSData *)encryptedWithAESUsingKey:(NSString*)key andIV:(NSData*)iv;
/**
 *  @brief  利用AES解密据
 *
 *  @param key key
 *  @param iv  iv
 *
 *  @return 解密后数据
 */
- (NSData *)decryptedWithAESUsingKey:(NSString*)key andIV:(NSData*)iv;

/**
 *  利用3DES加密数据
 *
 *  @param key key
 *  @param iv  iv description
 *
 *  @return data
 */
- (NSData *)encryptedWith3DESUsingKey:(NSString*)key andIV:(NSData*)iv;
/**
 *  @brief   利用3DES解密数据
 *
 *  @param key key
 *  @param iv  iv
 *
 *  @return 解密后数据
 */
- (NSData *)decryptedWith3DESUsingKey:(NSString*)key andIV:(NSData*)iv;

/**
 *  @brief  NSData 转成UTF8 字符串
 *
 *  @return 转成UTF8 字符串
 */
- (NSString *)UTF8String;
@end



// (https://github.com/shaojiankui/JKCategories)
@interface NSData (Hash)
/**
 *  @brief  md5 NSData
 */
@property (readonly) NSData *md5Data;
/**
 *  @brief  sha1Data NSData
 */
@property (readonly) NSData *sha1Data;
/**
 *  @brief  sha256Data NSData
 */
@property (readonly) NSData *sha256Data;
/**
 *  @brief  sha512Data NSData
 */
@property (readonly) NSData *sha512Data;

/**
 *  @brief  md5 NSData
 *
 *  @param key 密钥
 *
 *  @return 结果
 */
- (NSData *)hmacMD5DataWithKey:(NSData *)key;
/**
 *  @brief  sha1Data NSData
 *
 *  @param key 密钥
 *
 *  @return 结果
 */
- (NSData *)hmacSHA1DataWithKey:(NSData *)key;
/**
 *  @brief  sha256Data NSData
 *
 *  @param key 密钥
 *
 *  @return 结果
 */
- (NSData *)hmacSHA256DataWithKey:(NSData *)key;
/**
 *  @brief  sha512Data NSData
 *
 *  @param key 密钥
 *
 *  @return 结果
 */
- (NSData *)hmacSHA512DataWithKey:(NSData *)key;
@end


//
//  GZIP.h
//
//  Version 1.1.1
//
//  Created by Nick Lockwood on 03/06/2012.
//  Copyright (C) 2012 Charcoal Design
//
//  Distributed under the permissive zlib License
//  Get the latest version from here:
//
//  https://github.com/nicklockwood/GZIP
@interface NSData (Gzip)
/**
 *  @brief  GZIP压缩
 *
 *  @param level 压缩级别
 *
 *  @return 压缩后的数据
 */
- (NSData *)gzippedDataWithCompressionLevel:(float)level;

/**
 *  @brief  GZIP压缩 压缩级别 默认-1
 *
 *  @return 压缩后的数据
 */
- (NSData *)gzippedData;

/**
 *  @brief  GZIP解压
 *
 *  @return 解压后数据
 */
- (NSData *)gunzippedData;

- (BOOL)isGzippedData;
@end




#import <AVFoundation/AVFoundation.h>
/*
 
 AudioStreamBasicDescription _format;
 _format.mFormatID = kAudioFormatLinearPCM;
 _format.mFormatFlags = kLinearPCMFormatFlagIsSignedInteger | kLinearPCMFormatFlagIsPacked;
 _format.mBitsPerChannel = 16;
 _format.mChannelsPerFrame = 1;
 _format.mBytesPerPacket = _format.mBytesPerFrame = (_format.mBitsPerChannel / 8) * _format.mChannelsPerFrame;
 _format.mFramesPerPacket = 1;
 _format.mSampleRate = 8000.0f;
 */

@interface NSData (PCM)
/**
 *  format wav data
 *
 *  @param self   raw audio data
 *  @param pcmFormat format of pcm
 *
 *  @return wav data
 */
- (NSData *)wavDataWithPCMFormat:(AudioStreamBasicDescription)PCMFormat;
@end




//https://github.com/bitbasenyc/nsdata-zlib
@interface NSData (zlib)

/**
 ZLib error domain
 */
extern NSString *const ZlibErrorDomain;
/**
 When a zlib error occurs, querying this key in the @p userInfo dictionary of the
 @p NSError object will return the underlying zlib error code.
 */
extern NSString *const ZlibErrorInfoKey;

typedef NS_ENUM(NSUInteger, ZlibErrorCode) {
    ZlibErrorCodeFileTooLarge = 0,
    ZlibErrorCodeDeflationError = 1,
    ZlibErrorCodeInflationError = 2,
    ZlibErrorCodeCouldNotCreateFileError = 3,
};

/**
 Apply zlib compression.
 
 @param error If an error occurs during compression, upon return contains an
 NSError object describing the problem.
 
 @returns An NSData instance containing the result of applying zlib
 compression to this instance.
 */
- (NSData *)dataByDeflatingWithError:(NSError *__autoreleasing *)error;

/**
 Apply zlib decompression.
 
 @param error If an error occurs during decompression, upon return contains an
 NSError object describing the problem.
 
 @returns An NSData instance containing the result of applying zlib
 decompression to this instance.
 */
- (NSData *)dataByInflatingWithError:(NSError *__autoreleasing *)error;

/**
 Apply zlib compression and write the result to a file at path
 
 @param path The path at which the file should be written
 
 @param error If an error occurs during compression, upon return contains an
 NSError object describing the problem.
 
 @returns @p YES if the compression succeeded; otherwise, @p NO.
 */
- (BOOL)writeDeflatedToFile:(NSString *)path
                      error:(NSError *__autoreleasing *)error;

/**
 Apply zlib decompression and write the result to a file at path
 
 @param path The path at which the file should be written
 
 @param error If an error occurs during decompression, upon return contains an
 NSError object describing the problem.
 
 @returns @p YES if the compression succeeded; otherwise, @p NO.
 */
- (BOOL)writeInflatedToFile:(NSString *)path
                      error:(NSError *__autoreleasing *)error;
@end










