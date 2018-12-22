/*
 * NSObject+LNRuntime.h
 *
 * UIKit
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>

@interface NSObject (LNRuntime)


#pragma mark - 获取一个类中的所有类方法和对象方法
#pragma mark -获取类中所有实例方法名(-号开头的方法)
+ (void)ln_getInstanceMethodList;

#pragma mark -获取类所有的方法(+号开头开头的方法)
+ (void)ln_getClassMethodList;

#pragma mark -获取类中所有实例方法名
+ (void)printMethodNamesOfClass



//----------------------- <#<--- 不知名开发者 --->#> ------------------------//
//
// 元类:类对象的类,所有的类方法都是保存到元类(metaClass),并成方法列表
// 类对象:[Person class],所有的对象方法都是保存到类对象中,并成方法列表
// objc_getClass:获取类对象
// objc_getMetaClass:获取元类,

@end
