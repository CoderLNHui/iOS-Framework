/*
 * UIControl+Control.m
 *
 * Framework: UIKit
 *
 * About ME - Public：Codeidea / https://www.jianshu.com/u/fd745d76c816
 * Copyright © All members (Star|Fork) have the right to read and write -> https://github.com/CoderLN
 *
 * 作用：
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import "UIControl+Contro.h"

@implementation UIControl (LNControl)

@end


#import <objc/runtime.h>
@implementation UIControl (LNDelay)

+ (void)load
{
    Method a = class_getInstanceMethod(self, @selector(sendAction:to:forEvent:));
    Method b = class_getInstanceMethod(self, @selector(sendAction:to:forEvent:));
    
    method_exchangeImplementations(a, b);
}

#pragma mark -每次响应的间隔
- (NSTimeInterval)acceptEventInterval
{
    return [objc_getAssociatedObject(self, @selector(acceptEventInterval)) doubleValue];
}

- (void)setAcceptEventInterval:(NSTimeInterval)acceptEventInterval
{
    objc_setAssociatedObject(self, @selector(acceptEventInterval), @(acceptEventInterval), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)sendAction:(SEL)action to:(id)target forEvent:(UIEvent *)event
{
    [self sendAction:action to:target forEvent:event];
    
    self.userInteractionEnabled = NO;
    
    //第一种
    //[self performSelector:@selector(setUserInteractionEnabled:) withObject:@(YES) afterDelay:self.acceptEventInterval];
    
    //第二种
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(self.acceptEventInterval * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.userInteractionEnabled = YES;
    });
}

@end

