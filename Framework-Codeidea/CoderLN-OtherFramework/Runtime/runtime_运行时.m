//#import <objc/runtime.h>

#pragma mark - runtime常用函数
 0、class_copyPropertyList 获取类中所有的属性
        objc_property_t *propertyList = class_copyPropertyList([self class], &count);
        for (unsigned int i=0; i<count; i++) {
            const char *propertyName = property_getName(propertyList[i]);
            NSLog(@"property---->%@", [NSString stringWithUTF8String:propertyName]);
        }

 0、class_copyMethodList 获取类的所有方法
        Method *methodList = class_copyMethodList([self class], &count);
        for (unsigned int i; i<count; i++) {
            Method method = methodList[i];
            NSLog(@"method---->%@", NSStringFromSelector(method_getName(method)));
        }

 0、class_copyIvarList 获取类中所有的成员变量（outCount 会返回成员变量的总数）
        Ivar *ivarList = class_copyIvarList([self class], &count);
        for (unsigned int i; i<count; i++) {
            Ivar myIvar = ivarList[i];
            const char *ivarName = ivar_getName(myIvar);
            NSLog(@"Ivar---->%@", [NSString stringWithUTF8String:ivarName]);
        }
 
 0、class_copyProtocolList 获取协议列表
    __unsafe_unretained Protocol **protocolList = class_copyProtocolList([self class], &count);
    for (unsigned int i; i<count; i++) {
        Protocol *myProtocal = protocolList[i];
        const char *protocolName = protocol_getName(myProtocal);
        NSLog(@"protocol---->%@", [NSString stringWithUTF8String:protocolName]);
    }
 
 0、object_getClass 获得类方法
        Class PersonClass = object_getClass([Person class]);
        SEL oriSEL = @selector(test1);
        Method oriMethod = _class_getMethod(xiaomingClass, oriSEL);
 
 0、class_getInstanceMethod 获得实例方法
        Class PersonClass = object_getClass([xiaoming class]);
        SEL oriSEL = @selector(test2);
        Method cusMethod = class_getInstanceMethod(xiaomingClass, oriSEL);
 
 0、class_addMethod 动态添加方法
        BOOL addSucc = class_addMethod(xiaomingClass, oriSEL, method_getImplementation(cusMethod), method_getTypeEncoding(cusMethod));
 
 0、class_replaceMethod 替换原方法实现
        class_replaceMethod(toolClass, cusSEL, method_getImplementation(oriMethod), method_getTypeEncoding(oriMethod));
 
 0、method_exchangeImplementations 交换两个方法的实现
        method_exchangeImplementations(method1, method2);

 0、根据名字得到类变量的Ivar指针，但是这个在OC中好像毫无意义
    Ivar oneCVIvar = class_getClassVariable([Person class], name);

 0、根据名字得到实例变量的Ivar指针
    Ivar oneIVIvar = class_getInstanceVariable([Person class], name);

 0、找到后可以直接对私有成员变量赋值（强制修改name属性）
    object_setIvar(_per, oneIVIvar, @"age");


 0、动态添加方法
    class_addMethod([person class]：Class cls 类型, @selector(eat)：待调用的方法名称, (IMP)myAddingFunction：(IMP)myAddingFunction，IMP是一个函数指针，这里表示指定具体实现方法myAddingFunction, 0：0代表没有参数);

 0、获得某个类的类方法
    Method class_getClassMethod(Class cls , SEL name)

 0、获得成员变量的名字
    const char *ivar_getName(Ivar v);

 0、将某个值跟某个对象关联起来，将某个值存储到某个对象中
    void objc_setAssociatedObject(id object：表示关联者，是一个对象，变量名理所当然也是object , const void *key：获取被关联者的索引key ,id value ：被关联者 ,objc_AssociationPolicy policy：关联时采用的协议，有assign，retain，copy等协议，一般使用OBJC_ASSOCIATION_RETAIN_NONATOMIC)

 0、利用参数key 将对象object中存储的对应值取出来
    id objc_getAssociatedObject(id object , const void *key)



#pragma mark - runtime示例：添加方法、替换方法
    //创建继承自NSObject类的People类
    Class People = objc_allocateClassPair([NSObject class], "People", 0);
    //将People类注册到runtime中
    objc_registerClassPair(People);
    //注册test: 方法选择器
    SEL sel = sel_registerName("test:");
    //函数实现
    IMP imp = imp_implementationWithBlock(^(id this,id args,...){
        NSLog(@"方法的调用者为 %@",this);
        NSLog(@"参数为 %@",args);
        return @"返回值测试";
    });

    //向People类中添加 test:方法;函数签名为@@:@,
    //    第一个@表示返回值类型为id,
    //    第二个@表示的是函数的调用者类型,
    //    第三个:表示 SEL
    //    第四个@表示需要一个id类型的参数
    class_addMethod(People, sel, imp, "@@:@");
    //替换People从NSObject类中继承而来的description方法
    class_replaceMethod(People,@selector(description), imp_implementationWithBlock(^NSString*(id this,...){
        return @"我是Person类的对象";}),
                        "@@:");

    //完成 [[People alloc]init];
    id p1 = objc_msgSend(objc_msgSend(People, @selector(alloc)),@selector(init));
    //调用p1的sel选择器的方法,并传递@"???"作为参数
    id result = objc_msgSend(p1, sel,@"???");
    //输出sel方法的返回值
    NSLog(@"sel 方法的返回值为 ： %@",result);

    //获取People类中实现的方法列表
    NSLog(@"输出People类中实现的方法列表");
    unsigned int methodCount;
    Method * methods = class_copyMethodList(People, &methodCount);
    for (int i = 0; i<methodCount; i++) {
        NSLog(@"方法名称:%s",sel_getName(method_getName(methods[i])));
        NSLog(@"方法Types:%s",method_getDescription(methods[i])->types);
    }
    free(methods);












