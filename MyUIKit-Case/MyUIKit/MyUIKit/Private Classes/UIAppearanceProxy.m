//
//  UIAppearanceProxy.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIAppearanceProxy.h"
#import "UIGeometry.h"
#import "UIAppearanceInstance.h"
#import <objc/runtime.h>
#import "UIAppearanceProperty.h"

static const char *UIAppearanceSetterOverridesAssociatedObjectKey = "UIAppearanceSetterOverridesAssociatedObjectKey";

static BOOL TypeIsSignedInteger(const char *t)
{
    return (t != NULL) && (strcmp(t,@encode(char)) == 0
                           || strcmp(t,@encode(int)) == 0
                           || strcmp(t,@encode(short)) == 0
                           || strcmp(t,@encode(long)) == 0
                           || strcmp(t,@encode(long long)) == 0);
}

static BOOL TypeIsUnsignedInteger(const char *t)
{
    return (t != NULL) && (strcmp(t,@encode(unsigned char)) == 0
                           || strcmp(t,@encode(unsigned int)) == 0
                           || strcmp(t,@encode(unsigned short)) == 0
                           || strcmp(t,@encode(unsigned long)) == 0
                           || strcmp(t,@encode(unsigned long long)) == 0);
}

static BOOL TypeIsObject(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(id)) == 0;
}

static BOOL TypeIsCGFloat(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(CGFloat)) == 0;
}

static BOOL TypeIsCGPoint(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(CGPoint)) == 0;
}

static BOOL TypeIsCGSize(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(CGSize)) == 0;
}

static BOOL TypeIsCGRect(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(CGRect)) == 0;
}

static BOOL TypeIsUIEdgeInsets(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(UIEdgeInsets)) == 0;
}

static BOOL TypeIsUIOffset(const char *t)
{
    return (t != NULL) && strcmp(t,@encode(UIOffset)) == 0;
}

static BOOL TypeIsIntegerType(const char *t)
{
    return TypeIsSignedInteger(t) || TypeIsUnsignedInteger(t);
}

static BOOL TypeIsPropertyType(const char *t)
{
    return TypeIsIntegerType(t)
    || TypeIsObject(t)
    || TypeIsCGFloat(t)
    || TypeIsCGPoint(t)
    || TypeIsCGSize(t)
    || TypeIsCGRect(t)
    || TypeIsUIEdgeInsets(t)
    || TypeIsUIOffset(t);
}

static IMP GetOriginalMethodIMP(id self, SEL cmd)
{
    NSValue *boxedMethodImp = nil;
    Class klass = [self class];
    
    while (klass && !boxedMethodImp) {
        NSDictionary *overrides = objc_getAssociatedObject(klass, UIAppearanceSetterOverridesAssociatedObjectKey);
        boxedMethodImp = [overrides objectForKey:NSStringFromSelector(cmd)];
        klass = [klass superclass];
    }
    
    if (boxedMethodImp && strcmp(@encode(IMP), [boxedMethodImp objCType]) == 0) {
        IMP imp;
        [boxedMethodImp getValue:&imp];
        return imp;
    } else {
        return NULL;
    }
}


static void DidSetPropertyWithAxisValues(id self, SEL cmd, NSInteger numberOfAxisValues, NSInteger *axisValues)
{
    NSMutableArray *propertyKey = [NSMutableArray array];
    
    for (NSInteger i=0; i<numberOfAxisValues; i++) {
        [propertyKey addObject:@(axisValues[i])];
    }
    
    [propertyKey addObject:NSStringFromSelector(cmd)];
    
    [self _UIAppearancePropertyDidChange:propertyKey];
}

#define UIAppearanceSetterOverride(TYPE) \
static void UIAppearanceSetterOverride_##TYPE(id self, SEL cmd, TYPE property, ...) { \
typedef void(*SetterMethod)(id, SEL, TYPE, ...); \
SetterMethod imp = (SetterMethod)GetOriginalMethodIMP(self, cmd); \
const NSInteger numberOfAxisValues = [[self methodSignatureForSelector:cmd] numberOfArguments] - 3; \
if (imp && numberOfAxisValues >= 0) { \
va_list args; va_start(args, property); \
NSInteger axisValues[numberOfAxisValues]; \
if (numberOfAxisValues == 0) { \
imp(self, cmd, property); \
} else if (numberOfAxisValues == 1) { \
axisValues[0]=va_arg(args, NSInteger); \
imp(self, cmd, property, axisValues[0]); \
} else if (numberOfAxisValues == 2) { \
axisValues[0]=va_arg(args, NSInteger); axisValues[1]=va_arg(args, NSInteger); \
imp(self, cmd, property, axisValues[0], axisValues[1]); \
} else if (numberOfAxisValues == 3) { \
axisValues[0]=va_arg(args, NSInteger); axisValues[1]=va_arg(args, NSInteger); axisValues[2]=va_arg(args, NSInteger); \
imp(self, cmd, property, axisValues[0], axisValues[1], axisValues[2]); \
} else if (numberOfAxisValues == 4) { \
axisValues[0]=va_arg(args, NSInteger); axisValues[1]=va_arg(args, NSInteger); axisValues[2]=va_arg(args, NSInteger); axisValues[3]=va_arg(args, NSInteger); \
imp(self, cmd, property, axisValues[0], axisValues[1], axisValues[2], axisValues[3]); \
} else { \
@throw [NSException exceptionWithName:NSInternalInconsistencyException reason:@"argument count mismatch" userInfo:nil]; \
} \
DidSetPropertyWithAxisValues(self, cmd, numberOfAxisValues, axisValues); \
va_end(args); \
} else { \
@throw [NSException exceptionWithName:NSInternalInconsistencyException reason:@"something terrible has happened" userInfo:nil]; \
} \
}

UIAppearanceSetterOverride(NSInteger)
UIAppearanceSetterOverride(NSUInteger)
UIAppearanceSetterOverride(id)
UIAppearanceSetterOverride(CGFloat)
UIAppearanceSetterOverride(CGPoint)
UIAppearanceSetterOverride(CGSize)
UIAppearanceSetterOverride(CGRect)
UIAppearanceSetterOverride(UIEdgeInsets)
UIAppearanceSetterOverride(UIOffset)

static IMP ImplementationForPropertyType(const char *t)
{
    if (TypeIsSignedInteger(t)) {
        return (IMP)UIAppearanceSetterOverride_NSInteger;
    } else if (TypeIsUnsignedInteger(t)) {
        return (IMP)UIAppearanceSetterOverride_NSUInteger;
    } else if (TypeIsObject(t)) {
        return (IMP)UIAppearanceSetterOverride_id;
    } else if (TypeIsCGFloat(t)) {
        return (IMP)UIAppearanceSetterOverride_CGFloat;
    } else if (TypeIsCGPoint(t)) {
        return (IMP)UIAppearanceSetterOverride_CGPoint;
    } else if (TypeIsCGSize(t)) {
        return (IMP)UIAppearanceSetterOverride_CGSize;
    } else if (TypeIsCGRect(t)) {
        return (IMP)UIAppearanceSetterOverride_CGRect;
    } else if (TypeIsUIEdgeInsets(t)) {
        return (IMP)UIAppearanceSetterOverride_UIEdgeInsets;
    } else if (TypeIsUIOffset(t)) {
        return (IMP)UIAppearanceSetterOverride_UIOffset;
    } else {
        @throw [NSException exceptionWithName:NSInternalInconsistencyException reason:@"no setter implementation for property type" userInfo:nil];
    }
}

@implementation UIAppearanceProxy {
    Class<UIAppearance> _targetClass;
    NSMutableDictionary *_settings;
}

- (id)initWithClass:(Class<UIAppearance>)k
{
    if ((self = [super init])) {
        _targetClass = k;
        _settings = [[NSMutableDictionary alloc] initWithCapacity:0];
    }
    return self;
}

- (void)forwardInvocation:(NSInvocation *)anInvocation
{
    NSMethodSignature *methodSignature = [anInvocation methodSignature];
    NSMutableArray *propertyKey = [NSMutableArray array];
    
    const BOOL isSetter = [NSStringFromSelector([anInvocation selector]) hasPrefix:@"set"] && [methodSignature numberOfArguments] > 2 && strcmp([methodSignature methodReturnType], @encode(void)) == 0;
    const BOOL isGetter = !isSetter && strcmp([methodSignature methodReturnType], @encode(void)) != 0;
    
    const char *propertyType = isSetter? [methodSignature getArgumentTypeAtIndex:2] : (isGetter? [methodSignature methodReturnType] : NULL);
    if (!TypeIsPropertyType(propertyType)) {
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"property type must be id, NSInteger, NSUInteger, CGFloat, CGPoint, CGSize, CGRect, UIEdgeInsets or UIOffset" userInfo:nil];
    }
    
    const int axisStartIndex = isSetter? 3 : 2;
    for (int i=axisStartIndex; i<[methodSignature numberOfArguments]; i++) {
        const char *type = [methodSignature getArgumentTypeAtIndex:i];
        
        if (!TypeIsIntegerType(type)) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"axis type must be NSInteger or NSUInteger" userInfo:nil];
        }
        
        NSInteger axisValue = 0;
        [anInvocation getArgument:&axisValue atIndex:i];
        [propertyKey addObject:@(axisValue)];
    }
    
    if (isGetter) {
       
        NSMutableString *selectorKeyString = [NSStringFromSelector([anInvocation selector]) mutableCopy];
        [selectorKeyString replaceCharactersInRange:NSMakeRange(0, 1) withString:[[selectorKeyString substringToIndex:1] uppercaseString]];
        [selectorKeyString insertString:@"set" atIndex:0];
        
        if ([methodSignature numberOfArguments] > 2) {
            const NSRange colonRange = [selectorKeyString rangeOfString:@":"];
            const NSRange forRange = [selectorKeyString rangeOfString:@"For"];
            
            if (colonRange.location != NSNotFound && forRange.location != NSNotFound && colonRange.location > NSMaxRange(forRange)) {
                const NSRange axisNameRange = NSMakeRange(forRange.location+3, colonRange.location-forRange.location-3);
                NSString *axisName = [selectorKeyString substringWithRange:axisNameRange];
                axisName = [axisName stringByReplacingCharactersInRange:NSMakeRange(0, 1) withString:[[axisName substringToIndex:1] uppercaseString]];
                NSString *axisSelectorPartName = [NSString stringWithFormat:@"for%@:", axisName];
                [selectorKeyString insertString:axisSelectorPartName atIndex:NSMaxRange(colonRange)];
                [selectorKeyString replaceCharactersInRange:NSMakeRange(forRange.location, colonRange.location-forRange.location) withString:@""];
            }
        } else {
            [selectorKeyString appendString:@":"];
        }
        
        [propertyKey addObject:[selectorKeyString copy]];
        
        UIAppearanceProperty *propertyValue = [_settings objectForKey:propertyKey];
        [propertyValue setReturnValueForInvocation:anInvocation];
    }
    else if (isSetter) {
        NSString *selectorString = NSStringFromSelector([anInvocation selector]);
        
        [propertyKey addObject:selectorString];
        
        [_settings setObject:[[UIAppearanceProperty alloc] initWithInvocation:anInvocation] forKey:propertyKey];
        
        NSMutableDictionary *methodOverrides = objc_getAssociatedObject(_targetClass, UIAppearanceSetterOverridesAssociatedObjectKey);
        
        if (!methodOverrides) {
            methodOverrides = [NSMutableDictionary dictionaryWithCapacity:1];
            objc_setAssociatedObject(_targetClass, UIAppearanceSetterOverridesAssociatedObjectKey, methodOverrides, OBJC_ASSOCIATION_RETAIN);
        }
        
        if (![methodOverrides objectForKey:selectorString]) {
            Method method = class_getInstanceMethod(_targetClass, [anInvocation selector]);
            
            if (method) {
                IMP implementation = method_getImplementation(method);
                IMP overrideImplementation =  ImplementationForPropertyType([methodSignature getArgumentTypeAtIndex:2]);
                
                if (implementation != overrideImplementation) {
                    [methodOverrides setObject:[NSValue valueWithBytes:&implementation objCType:@encode(IMP)] forKey:selectorString];
                    class_replaceMethod(_targetClass, [anInvocation selector], overrideImplementation, method_getTypeEncoding(method));
                }
            }
        }
    }
    else {
       
        [self doesNotRecognizeSelector:[anInvocation selector]];
    }
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector
{
    return [super methodSignatureForSelector:aSelector] ?: [(id)_targetClass instanceMethodSignatureForSelector:aSelector];
}

- (NSDictionary *)_appearancePropertiesAndValues
{
    return [_settings copy];
}

@end
