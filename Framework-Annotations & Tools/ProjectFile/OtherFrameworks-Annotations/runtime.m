//
//  Class.h
//  🔍白开水ln（https://github.com/CustomPBWaters）
//
//  Created by 【🔍Plain Boiled Water ln】 on Elegant programming16.
//  Copyright © Unauthorized shall（https://githubidea.github.io）not be reproduced reprinted.
//
//  @PBWLN_LICENSE_HEADER_END@
//
/** iOS 底层-Class注解 */


// 获得某个类的类方法
Method class_getClassMethod(Class cls , SEL name)

// 获得某个类的实例对象方法
Method class_getInstanceMethod(Class cls , SEL name)

// 交换两个方法的实现
void method_exchangeImplementations(Method m1 , Method m2)

// 将某个值跟某个对象关联起来，将某个值存储到某个对象中
void objc_setAssociatedObject(id object , const void *key ,id value ,objc_AssociationPolicy policy)

// 利用参数key 将对象object中存储的对应值取出来
id objc_getAssociatedObject(id object , const void *key)

// 获得某个类的所有成员变量（outCount 会返回成员变量的总数）
Ivar *class_copyIvarList(Class cls , unsigned int *outCount)

// 获得成员变量的名字
const char *ivar_getName(Ivar v)

// 获得成员变量的类型
const char *ivar_getTypeEndcoding(Ivar v)

// 获取类里面所有方法
class_copyMethodList(__unsafe_unretained Class cls, unsigned int *outCount)// 本质:创建谁的对象

// 获取类里面属性
class_copyPropertyList(__unsafe_unretained Class cls, unsigned int *outCount)





























//--------------------------- <#我是分割线#> ------------------------------//
// runtime.h里的Class的定义

struct objc_class {
    Class isa  OBJC_ISA_AVAILABILITY;//每个Class都有一个isa指针
    
#if !__OBJC2__
    Class super_class                                        OBJC2_UNAVAILABLE;//父类
    const char *name                                         OBJC2_UNAVAILABLE;//类名
    long version                                             OBJC2_UNAVAILABLE;//类版本
    long info                                                OBJC2_UNAVAILABLE;//!*!供运行期使用的一些位标识。如：CLS_CLASS (0x1L)表示该类为普通class; CLS_META(0x2L)表示该类为metaclass等(runtime.h中有详细列出)
    long instance_size                                       OBJC2_UNAVAILABLE;//实例大小
    struct objc_ivar_list *ivars                             OBJC2_UNAVAILABLE;//存储每个实例变量的内存地址
    struct objc_method_list **methodLists                    OBJC2_UNAVAILABLE;//!*!根据info的信息确定是类还是实例，运行什么函数方法等
    struct objc_cache *cache                                 OBJC2_UNAVAILABLE;//缓存
    struct objc_protocol_list *protocols                     OBJC2_UNAVAILABLE;//协议
#endif
    
} OBJC2_UNAVAILABLE;





//--------------------------- <#我是分割线#> ------------------------------//
// runtime下Class的各项操作


3.1 add*(增加)
3.1.1 static IMP addMethod(Class cls, SEL name, IMP imp, const char *types, BOOL replace);//增加方法
3.1.2 BOOL class_addMethod(Class cls, SEL name, IMP imp, const char *types);//增加类方法
3.1.3 BOOL class_addIvar(Class cls, const char *name, size_t size,uint8_t alignment, const char *type);//增加实例变量
3.1.4 static BOOL _class_addProperty(Class cls, const char *name,const objc_property_attribute_t *attrs, unsigned int count,BOOL replace);//增加属性
3.2 replace*(修改)
3.2.1 IMP class_replaceMethod(Class cls, SEL name, IMP imp, const char *types); //修改方法
3.2.2 void class_replaceProperty(Class cls, const char *name,const objc_property_attribute_t *attrs, unsigned int n);//修改属性
3.3 get*(获取)
3.3.1 static Class getClass(const char *name);//获取类
3.3.2 static ivar_t *getIvar(Class cls, const char *name);//获取类变量(static相当于“+“)
3.3.3 Method class_getInstanceMethod(Class cls, SEL sel);//获取实例方法
3.3.4 static Method _class_getMethod(Class cls, SEL sel);;//获取类方法
3.3.5 static Protocol *getProtocol(const char *name);//获取协议
3.4 set*(设置)
3.4.1 objc_class::setInitialized();//set的initialized初始化
3.4.2 static Class setSuperclass(Class cls, Class newSuper);//设置父类
3.5 其他还有类似于 void *objc_destructInstance(id obj);//摧毁实例对象等等





//--------------------------- <#我是分割线#> ------------------------------//
// Class的重要函数

4.1 get*(获取)
4.1.1 object_getClass(id obj);
4.1.2 IMP object_getMethodImplementation(id obj, SEL name);//获得实例方法实现
4.1.3 Ivar object_getInstanceVariable(id obj, const char *name, void **value)//获取实例属性
4.2 set*(设置)
4.2.1 Class object_setClass(id obj, Class cls);
4.2.2 Ivar object_setInstanceVariable(id obj, const char *name, void *value);//设置实例属性
4.2.3 void object_setIvar(id obj, Ivar ivar, id value);//设置实例变量
4.3 其他
4.3.1 static void _class_resolveClassMethod(Class cls, SEL sel, id inst);//动态添加类方法，不必在乎方法是否存在
4.3.2 static void _class_resolveInstanceMethod(Class cls, SEL sel, id inst);//动态添加实现方法，不必在乎方法是否存在
4.3.3 unsigned _class_createInstancesFromZone(Class cls, size_t extraBytes, void *zone,id *results, unsigned num_requested);//创建实例存储空间
4.4 消息转发
4.4.1 void    instrumentObjcMessageSends(BOOL flag);//flag传入YES，运行时发送的所有消息都会打印到/tmp/msgSend-xxxx文件里了。


































