//
//  UIAppearanceInstance.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIAppearanceInstance.h"
#import <objc/runtime.h>
#import "UIAppearanceProxy.h"
#import "UIAppearanceProperty.h"

static const char *UIAppearanceClassAssociatedObjectKey = "UIAppearanceClassAssociatedObjectKey";
static const char *UIAppearanceChangedPropertiesKey = "UIAppearanceChangedPropertiesKey";
static const char *UIAppearancePropertiesAreUpToDateKey = "UIAppearancePropertiesAreUpToDateKey";


// 只要有类遵守了协议，就把它插入到类数组中的第0个位置
static NSArray *UIAppearanceHierarchyForClass(Class klass)
{
    NSMutableArray *classes = [[NSMutableArray alloc] initWithCapacity:0];
    
    while ([(id)klass conformsToProtocol:@protocol(UIAppearance)]) {
        [classes insertObject:klass atIndex:0];
        klass = [klass superclass];
    }
    
    return classes;
}

@implementation NSObject (UIAppearanceInstance)

+ (id)appearance
{
    return [self appearanceWhenContainedIn:nil];
}

+ (id)appearanceWhenContainedIn:(Class <UIAppearanceContainer>)containerClass, ...
{
    // 取当前类的关联的可变字典
    NSMutableDictionary *appearanceRules = objc_getAssociatedObject(self, UIAppearanceClassAssociatedObjectKey);
    
    // 如果还没设置关联，就给当前类设置一个关联的可变字典属性
    if (!appearanceRules) {
        appearanceRules = [NSMutableDictionary dictionaryWithCapacity:1];
        objc_setAssociatedObject(self, UIAppearanceClassAssociatedObjectKey, appearanceRules, OBJC_ASSOCIATION_RETAIN);
    }
    
    NSMutableArray *containmentPath = [NSMutableArray arrayWithCapacity:1];
    
    va_list args;
    va_start(args, containerClass);
    for (; containerClass != nil; containerClass = va_arg(args, Class <UIAppearanceContainer>)) {
        [containmentPath addObject:containerClass];
    }
    va_end(args);
    
    UIAppearanceProxy *record = [appearanceRules objectForKey:containmentPath];
    
    if (!record) {
        record = [[UIAppearanceProxy alloc] initWithClass:self];
        [appearanceRules setObject:record forKey:containmentPath];
    }
    
    return record;
}

- (id)_UIAppearanceContainer
{
    return nil;
}

- (void)_UIAppearanceUpdateIfNeeded
{
    if (objc_getAssociatedObject(self, UIAppearancePropertiesAreUpToDateKey)) {
        return;
    }
    
    NSArray *classes = UIAppearanceHierarchyForClass([self class]);
    NSMutableDictionary *propertiesToSet = [NSMutableDictionary dictionaryWithCapacity:0];
    
    for (Class klass in classes) {
        NSMutableDictionary *rules = objc_getAssociatedObject(klass, UIAppearanceClassAssociatedObjectKey);
        
        NSArray *sortedRulePaths = [[rules allKeys] sortedArrayUsingComparator:^NSComparisonResult(NSArray *path1, NSArray *path2) {
            if ([path1 count] == [path2 count]) {
                if ([[path2 lastObject] isKindOfClass:[path1 lastObject]]) {
                    return (NSComparisonResult)NSOrderedAscending;
                } else if ([[path1 lastObject] isKindOfClass:[path2 lastObject]]) {
                    return (NSComparisonResult)NSOrderedDescending;
                } else {
                    return (NSComparisonResult)NSOrderedSame;
                }
            } else if ([path1 count] < [path2 count]) {
                return (NSComparisonResult)NSOrderedAscending;
            } else {
                return (NSComparisonResult)NSOrderedDescending;
            }
        }];
        
        for (NSArray *rule in sortedRulePaths) {
            BOOL shouldApplyRule = YES;
            
            for (Class klass in [rule reverseObjectEnumerator]) {
                id container = [self _UIAppearanceContainer];
                
                while (container && ![container isKindOfClass:klass]) {
                    container = [container _UIAppearanceContainer];
                }
                
                if (!container) {
                    shouldApplyRule = NO;
                    break;
                }
            }
            
            if (shouldApplyRule) {
                UIAppearanceProxy *proxy = [rules objectForKey:rule];
                [propertiesToSet addEntriesFromDictionary:[proxy _appearancePropertiesAndValues]];
            }
        }
    }
    
    NSSet *originalProperties = objc_getAssociatedObject(self, UIAppearanceChangedPropertiesKey);
    
    [propertiesToSet removeObjectsForKeys:[originalProperties allObjects]];
    
    for (UIAppearanceProperty *property in [propertiesToSet allValues]) {
        [property invokeUsingTarget:self];
    }
    
    objc_setAssociatedObject(self, UIAppearanceChangedPropertiesKey, originalProperties, OBJC_ASSOCIATION_RETAIN);
    
    objc_setAssociatedObject(self, UIAppearancePropertiesAreUpToDateKey, @(1), OBJC_ASSOCIATION_RETAIN);
}

- (void)_UIAppearanceSetNeedsUpdate
{
    objc_setAssociatedObject(self, UIAppearancePropertiesAreUpToDateKey, nil, OBJC_ASSOCIATION_RETAIN);
}

- (void)_UIAppearancePropertyDidChange:(id)property
{
    NSSet *changedProperties = [NSSet setWithSet:objc_getAssociatedObject(self, UIAppearanceChangedPropertiesKey)];
    objc_setAssociatedObject(self, UIAppearanceChangedPropertiesKey, [changedProperties setByAddingObject:property], OBJC_ASSOCIATION_RETAIN);
}


@end
