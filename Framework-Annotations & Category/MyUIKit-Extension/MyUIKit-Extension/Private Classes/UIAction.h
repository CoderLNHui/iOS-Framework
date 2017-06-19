//  完全实现ok
//  UIAction.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UIAction : NSObject
@property (nonatomic, weak) id target;
@property (nonatomic, assign) SEL action;
@end
