//
//  NSDictionary+Property.h
//  Category（https://github.com/CustomPBWaters）
//
//  Created by 白开水ln on 16/-/-.
//  Copyright © 2016年（https://custompbwaters.github.io）All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (Property)

/*
 *【字典转模型KVC实现(自动生成模型属性代码)】
 */
- (void)createPropertyCode;





//--------------------------- [示例:本地Plist文件] ------------------------------//
//
/**

 NSString *filePath = [[NSBundle mainBundle] pathForResource:@"status.plist" ofType:nil];
 NSDictionary *dict = [NSDictionary dictionaryWithContentsOfFile:filePath];
 
 // 字典转模型,生成属性代码 => dict
 [dict createPropertyCode];
 
 
 打印输出:
 2016-03-04 15:27:23.767 字典转模型(自动生成属性代码)[5227:154068]
 @property (nonatomic, strong) NSString *source;
 
 @property (nonatomic, assign) NSInteger reposts_count;
 
 @property (nonatomic, strong) NSArray *pic_urls;
 
 @property (nonatomic, strong) NSString *created_at;
 
 @property (nonatomic, assign) BOOL isA;
 
 @property (nonatomic, assign) NSInteger attitudes_count;
 
 @property (nonatomic, strong) NSString *idstr;
 
 @property (nonatomic, strong) NSString *text;
 
 @property (nonatomic, assign) NSInteger comments_count;
 
 @property (nonatomic, strong) NSDictionary *user;
 */


@end
