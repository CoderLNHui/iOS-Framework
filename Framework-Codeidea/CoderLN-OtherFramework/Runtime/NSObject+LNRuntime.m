/*
 * NSObject+LNRuntime.m
 *
 * UIKit
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import "NSObject+LNRuntime.h"
#import <objc/message.h>

#pragma mark - 获取一个类中的所有类方法和对象方法
@implementation NSObject (LNRuntime)

#pragma mark -获取实例方法(-号开头的方法)
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

#pragma mark -获取类方法(+号开头开头的方法)
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
