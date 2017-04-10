//  完全实现
//  UIAppearanceProperty.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIAppearanceProperty : NSObject

- (id)initWithInvocation:(NSInvocation *)setterInvocation;
- (void)invokeUsingTarget:(id)target;
- (void)setReturnValueForInvocation:(NSInvocation *)getterInvocation;

@end
