/*
 * File: NSObject+Runtime.m
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

#import "NSObject+Runtime.h"
#import <objc/message.h>

@implementation NSObject (Runtime)

+ (void)ln_getInstanceMethodList
{
    
    NSMutableString *methodStr = [NSMutableString string];
    // 获取某个类中所有方法
    // Class:获取哪个类的方法
    // outCount:类中方法总数
    // class_copyMethodList:只能获取当前类
    unsigned int count = 0;
    // 获取Method数组
    Method *methodList = class_copyMethodList(self, &count);
    
    for (int i = 0; i < count; i++) {
        // 获取方法
        Method method = methodList[i];
        
        // 获取方法名
        SEL sel = method_getName(method);
        
        [methodStr appendFormat:@"\n%@\n",NSStringFromSelector(sel)];
        
    }
    
    NSLog(@"%@",methodStr);
    
}

+ (void)ln_getClassMethodList
{
    NSMutableString *methodStr = [NSMutableString string];
    
    // 获取某个类中所有方法
    // 获取某个类中所有方法
    // Class:获取哪个类的方法
    // outCount:类中方法总数
    // class_copyMethodList:只能获取当前类
    unsigned int count = 0;
    
    // 获取类对象类名
    NSString *className = NSStringFromClass(self);
    
    // OC -> C .UTF8String
    // 获取元类
    Class metaClass = objc_getMetaClass(className.UTF8String);
    
    // 获取Method数组
    Method *methodList = class_copyMethodList(metaClass, &count);
    
    for (int i = 0; i < count; i++) {
        // 获取方法
        Method method = methodList[i];
        
        // 获取方法名
        SEL sel = method_getName(method);
        
        [methodStr appendFormat:@"\n%@\n",NSStringFromSelector(sel)];
        
    }
    
    NSLog(@"%@",methodStr);
}


@end
#START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
