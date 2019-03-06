//
//  NSObject+JKAppInfo.h
//  JKCategories
//
//  Created by nidom on 15/9/29.
//  Copyright (c) 2015年 www.skyfox.org. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (JKAppInfo)
-(NSString *)jk_version;
-(NSInteger)jk_build;
-(NSString *)jk_identifier;
-(NSString *)jk_currentLanguage;
-(NSString *)jk_deviceModel;
@end
