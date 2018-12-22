//----------------------- <--- <#将含有Block的Objective-C代码转换成C++的源代码#> ---> ------------------------//
// # 欢迎关注，简书|众-不知名开发者，更多干货.

# block是一个指针结构体，在终端下使用LLVM编译器的clang命令可将含有Block的Objective-C代码转换成C++的源代码，以探查其具体实现方式：`clang -rewrite-objc main.m`
#import <Foundation/Foundation.h>
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int age = 10;
        # 声明block
        void(^block)(int ,int) = ^(int a, int b){
            NSLog(@"this is block,a = %d,b = %d",a,b);
            NSLog(@"this is block,age = %d",age);
        };
        age = 20;
        # 回调block
        block(3,5);
    }
    return 0;
}
// this is block,a = 3,b = 5
// this is block,age = 10



//----------------------- <--- <#c++中block的声明和定义#> ---> ------------------------//
// # 欢迎关注，简书|众-不知名开发者，更多干货；

# __block_impl 这是一个结构体，也是C面向对象的体现，可以理解为block的基类;
struct __block_impl {
    void *isa; # 指向所属类的指针，也就是block的类型
    int Flags; # 标志变量，在实现block的内部操作时会用到
    int Reserved; # 保留变量
    void *FuncPtr; # block执行时调用的函数指针
};
# 注解：从__block_impl结构体zhong可以看出，
//它包含了isa指针（包含isa指针的皆为对象），也就是说block也是一个对象(runtime里面，对象和类都是用结构体表示)。


# __main_block_impl_0: 可以理解为block需要捕获的变量;
struct __main_block_impl_0 {
    struct __block_impl impl;   -> <#truct __block_impl { }#>
    struct __main_block_desc_0* Desc;   -> <#static struct __main_block_desc_0 { }#>
    int age;
    
    # 结构体内有一个同名构造函数（类似于OC的init方法），构造函数中对一些变量进行了赋值最终会返回一个结构体。
    # 其中flage有默认值，也就说flage参数在调用的时候可以省略不传。而最后的 age(_age)则表示传入的_age参数会自动赋值给age成员，相当于age = _age。
    __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, int _age, int flags=0) : age(_age) {
        impl.isa = &_NSConcreteStackBlock; # 默认指向栈块
        impl.Flags = flags; # 默认标记
        impl.FuncPtr = fp; # block内代码块地址
        Desc = desc; # 存放着block的 保留变量 和 block大小
    }
};
# 注解：从上面构造函数可以看出，
/**
 1. __block_impl结构体中isa指针存指向了&_NSConcreteStackBlock地址，可以暂时理解为其类对象地址，block就是_NSConcreteStackBlock类型的。
 2. block代码块中的代码被封装成__main_block_func_0函数，FuncPtr则存储着__main_block_func_0函数的地址。
 3. Desc指向__main_block_desc_0结构体对象时就创建的__main_block_desc_0_DATA，其中存储__main_block_impl_0 block结构体所占用的内存。
 */


# __main_block_func_0 可以理解为匿名函数，封装了block执行代码；
static void __main_block_func_0(struct __main_block_impl_0 *__cself, int a, int b) {
    int age = __cself->age; // bound by copy
    
    NSLog((NSString *)&__NSConstantStringImpl__var_folders_8n_22vs8t4j10d8hnyfp0ct7l040000gn_T_main_430fdd_mi_0,a,b);
    NSLog((NSString *)&__NSConstantStringImpl__var_folders_8n_22vs8t4j10d8hnyfp0ct7l040000gn_T_main_430fdd_mi_1,age);
}
# 注解：从上面的__main_block_func_0匿名函数可以看出
/**
 在__main_block_func_0函数中首先取出block中age的值，紧接着可以看到两个熟悉的NSLog，可以发现这两段代码恰恰是我们在block块中写下的代码。那么__main_block_func_0函数中其实存储着我们block中写下的代码。
 而__main_block_impl_0函数中传入的是(void *)__main_block_func_0，也就说将我们写在block块中的代码封装成__main_block_func_0函数，并将__main_block_func_0函数的地址传入了__main_block_impl_0的构造函数中保存在结构体内。
 */



# __main_block_desc_0 block描述信息
static struct __main_block_desc_0 {
    size_t reserved; # 保留变量
    size_t Block_size; # block大小(sizeof(struct __main_block_impl_0))
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0)}; #
# 注解：从__main_block_desc_0描述信息中可以看出
/**
 1.定义__main_block_desc_0结构体时，同时创建了__main_block_desc_0_DATA，并给它赋值，以供在main函数中对__main_block_impl_0进行初始化。
 2.可以看到__main_block_desc_0中存储着两个参数，reserved和Block_size，并且reserved赋值为0而Block_size则存储着__main_block_impl_0的占用空间大小。最终将__main_block_desc_0结构体的地址传入__main_block_func_0中赋值给Desc。
 */


int main(int argc, const char * argv[]) {
    /* @autoreleasepool */ { __AtAutoreleasePool __autoreleasepool;
        int age = 10;
        # 定义block
        void(*block)(int ,int) = ((void (*)(int, int))&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, age));
        //可以发现，block定义中调用了__main_block_impl_0函数，并且将__main_block_impl_0函数的地址赋值给了block。
        
        # 执行block内部的代码
        ((void (*)(__block_impl *, int, int))((__block_impl *)block)->FuncPtr)((__block_impl *)block, 3, 5);
    }
    return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
# 注解：从上面定义block可以看出
/**
 1.age也就是我们定义的局部变量。因为在block块中使用到age局部变量，所以在block声明的时候这里才会将age作为参数传入，也就说block会捕获age，
   如果没有在block中使用age，这里将只会传入(void *)__main_block_func_0，&__main_block_desc_0_DATA两个参数。
 2.因为block在定义的之后已经将age的值传入存储在__main_block_imp_0结构体中并在调用的时候将age从block中取出来使用，
   因此在block定义之后对局部变量进行改变是无法被block捕获的。
 */

# 注解：从上面执行block内部的代码可以看出
/**
 通过上述代码可以发现调用block是通过block找到FunPtr直接调用，通过上面分析我们知道block指向的是__main_block_impl_0类型结构体，但是我们发现__main_block_impl_0结构体中并不直接就可以找到FunPtr，而FunPtr是存储在__block_impl中的，为什么block可以直接调用__block_impl中的FunPtr呢？
 重新查看上述源代码可以发现，(__block_impl *)block将block强制转化为__block_impl类型的，因为__block_impl是__main_block_impl_0结构体的第一个成员，相当于将__block_impl结构体的成员直接拿出来放在__main_block_impl_0中，那么也就说明__block_impl的内存地址就是__main_block_impl_0结构体的内存地址开头。所以可以转化成功。并找到FunPtr成员。
 上面我们知道，FunPtr中存储着通过代码块封装的函数地址，那么调用此函数，也就是会执行代码块中的代码。并且回头查看__main_block_func_0函数，可以发现第一个参数就是__main_block_impl_0类型的指针。也就是说将block传入__main_block_func_0函数中，便于重中取出block捕获的值。
 */






