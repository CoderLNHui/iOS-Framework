/*
 * NSObject+LNRuntime.m
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import "NSObject+LNRuntime.h"
#import <objc/message.h>

#pragma mark - 获取一个类中的所有对象方法和类方法
@implementation NSObject (LNRuntime)

#pragma mark -获取类中所有实例方法名(-号开头的方法)
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

#pragma mark -获取类中所有的方法(+号开头开头的方法)
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



#pragma mark -获取类中所有实例方法名
+ (void)printMethodNamesOfClass
{
    unsigned int count;
    // 获得方法数组
    Method * methodList = class_copyMethodList(self, &count);
    // 存储方法名
    NSMutableString *methodNames = [NSMutableString string];
    // 遍历所有的方法
    for (int i = 0; i < count; i++) {
        // 获得方法
        Method method = methodList[I];
        // 获得方法名
        NSString *methodName = NSStringFromSelector(method_getName(method));
        // 拼接方法名
        [methodNames appendString:methodName];
        [methodNames appendString:@", "];
    }
    // 释放
    free(methodList);
    // 打印方法名
    NSLog(@"%@ %@", cls, methodNames);
}

 

















@end
