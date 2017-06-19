//  完全实现
//  UIAppearanceInstance.h
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIAppearance.h"

@class UIAppearanceProperty;

@interface NSObject (UIAppearanceInstance)
+ (id)appearance;
+ (id)appearanceWhenContainedIn:(Class <UIAppearanceContainer>)containerClass, ...;

- (id)_UIAppearanceContainer;
- (void)_UIAppearancePropertyDidChange:(id)property;
- (void)_UIAppearanceUpdateIfNeeded;
- (void)_UIAppearanceSetNeedsUpdate;
@end
