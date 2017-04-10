//  完全实现
//  UIAppearanceProxy.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIAppearance.h"

@interface UIAppearanceProxy : NSObject
- (id)initWithClass:(Class<UIAppearance>)k;
- (NSDictionary *)_appearancePropertiesAndValues;
@end
