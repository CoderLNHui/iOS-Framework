 

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



































