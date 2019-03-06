/*
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import "UIViewController+Dealloc.h"
#import <objc/runtime.h>

@implementation UIViewController (Dealloc)

// 先交换，再调用；只交换一次
+ (void)load
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        Method method1 = class_getInstanceMethod(self, NSSelectorFromString(@"dealloc"));
        Method method2 = class_getInstanceMethod(self, @selector(my_dealloc));
        method_exchangeImplementations(method1, method2);
    });
}

- (void)my_dealloc
{
    NSLog(@"%@ 销毁了", self);
    [self my_dealloc];
}

@end
