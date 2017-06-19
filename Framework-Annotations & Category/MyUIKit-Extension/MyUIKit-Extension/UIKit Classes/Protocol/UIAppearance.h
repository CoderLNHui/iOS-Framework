//  完全实现
//  UIAppearance.h
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import <Foundation/Foundation.h>

#define UI_APPEARANCE_SELECTOR __attribute__((annotate("ui_appearance_selector")))

@protocol UIAppearanceContainer <NSObject>
@end

@protocol UIAppearance <NSObject>
+ (id)appearance;
+ (id)appearanceWhenContainedIn:(Class <UIAppearanceContainer>)ContainerClass, ... NS_REQUIRES_NIL_TERMINATION; //ns_requirst_nil_termnation
@end
