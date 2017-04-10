//
//  UIAppearanceProperty.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIAppearanceProperty.h"

@implementation UIAppearanceProperty
{
    NSInvocation *_invocation;
}

- (id)initWithInvocation:(NSInvocation *)setterInvocation
{
    if ((self=[super init])) {
        NSMethodSignature *methodSignature = [setterInvocation methodSignature];
        _invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
        
        for (int i = 1; i < [methodSignature numberOfArguments]; i++) {
            const char *valueType = [methodSignature getArgumentTypeAtIndex:i];
            NSUInteger bufferSize = 0;
            NSGetSizeAndAlignment(valueType, &bufferSize, NULL);
            UInt8 valueBuffer[bufferSize];
            memset(valueBuffer, 0, bufferSize);
            
            [setterInvocation getArgument:valueBuffer atIndex:i];
            [_invocation setArgument:valueBuffer atIndex:i];
        }
        
        [_invocation retainArguments];
    }
    return self;
}

- (void)invokeUsingTarget:(id)target
{
    [_invocation invokeWithTarget:target];
}

- (void)setReturnValueForInvocation:(NSInvocation *)getterInvocation
{
    NSMethodSignature *methodSignature = [_invocation methodSignature];
    
    NSAssert([methodSignature numberOfArguments] >= 2, @"stored invocation has no property value");
    
    const char *valueType = [methodSignature getArgumentTypeAtIndex:2];
    NSUInteger bufferSize = 0;
    NSGetSizeAndAlignment(valueType, &bufferSize, NULL);
    UInt8 valueBuffer[bufferSize];
    memset(valueBuffer, 0, bufferSize);
    [_invocation getArgument:valueBuffer atIndex:2];

    NSAssert(bufferSize == [[getterInvocation methodSignature] methodReturnLength], @"getter return length not equal to property value size");
    
    [getterInvocation setReturnValue:valueBuffer];
}


@end
