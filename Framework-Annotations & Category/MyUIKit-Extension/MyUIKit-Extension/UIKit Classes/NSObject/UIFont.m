//
//  UIFont.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIFont.h"
#import <Cocoa/Cocoa.h>


static NSString *UIFontSystemFontName = nil;
static NSString *UIFontBoldSystemFontName = nil;

@implementation UIFont

+ (void)setSystemFontName:(NSString *)aName
{
    UIFontSystemFontName = [aName copy];
}

+ (void)setBoldSystemFontName:(NSString *)aName
{
    UIFontBoldSystemFontName = [aName copy];
}

+ (UIFont *)_fontWithCTFont:(CTFontRef)aFont
{
    UIFont *theFont = [[UIFont alloc] init];
    theFont->_font = CFRetain(aFont);
    return theFont;
}

+ (UIFont *)fontWithNSFont:(NSFont *)aFont
{
    if (aFont) {
        CTFontRef newFont = CTFontCreateWithName((__bridge CFStringRef)[aFont fontName], [aFont pointSize], NULL);
        if (newFont) {
            UIFont *theFont = [self _fontWithCTFont:newFont];
            CFRelease(newFont);
            return theFont;
        }
    }
    return nil;
}

+ (UIFont *)fontWithName:(NSString *)fontName size:(CGFloat)fontSize
{
    return [self fontWithNSFont:[NSFont fontWithName:fontName size:fontSize]];
}

static NSArray *_getFontCollectionNames(CTFontCollectionRef collection, CFStringRef nameAttr)
{
    NSMutableSet *names = [NSMutableSet set];
    if (collection) {
        CFArrayRef descriptors = CTFontCollectionCreateMatchingFontDescriptors(collection);
        if (descriptors) {
            NSInteger count = CFArrayGetCount(descriptors);
            for (NSInteger i = 0; i < count; i++) {
                CTFontDescriptorRef descriptor = (CTFontDescriptorRef) CFArrayGetValueAtIndex(descriptors, i);
                CFTypeRef name = CTFontDescriptorCopyAttribute(descriptor, nameAttr);
                if(name) {
                    if (CFGetTypeID(name) == CFStringGetTypeID()) {
                        [names addObject:(__bridge NSString*)name];
                    }
                    CFRelease(name);
                }
            }
            CFRelease(descriptors);
        }
    }
    return [names allObjects];
}

+ (NSArray *)familyNames
{
    CTFontCollectionRef collection = CTFontCollectionCreateFromAvailableFonts(NULL);
    NSArray* names = _getFontCollectionNames(collection, kCTFontFamilyNameAttribute);
    if (collection) {
        CFRelease(collection);
    }
    return names;
}

+ (NSArray *)fontNamesForFamilyName:(NSString *)familyName
{
    NSArray *names = nil;
    CTFontDescriptorRef descriptor = CTFontDescriptorCreateWithAttributes((__bridge CFDictionaryRef)
                                                                          [NSDictionary dictionaryWithObjectsAndKeys: familyName, (NSString*)kCTFontFamilyNameAttribute, nil, nil]);
    if (descriptor) {
        CFArrayRef descriptors = CFArrayCreate(NULL, (CFTypeRef*) &descriptor, 1, &kCFTypeArrayCallBacks);
        if (descriptors) {
            CTFontCollectionRef collection = CTFontCollectionCreateWithFontDescriptors(descriptors, NULL);
            names = _getFontCollectionNames(collection, kCTFontNameAttribute);
            if (collection) {
                CFRelease(collection);
            }
            CFRelease(descriptors);
        }
        CFRelease(descriptor);
    }
    return names;
}

+ (UIFont *)systemFontOfSize:(CGFloat)fontSize
{
    NSFont *systemFont = UIFontSystemFontName? [NSFont fontWithName:UIFontSystemFontName size:fontSize] : [NSFont systemFontOfSize:fontSize];
    return [self fontWithNSFont:systemFont];
}

+ (UIFont *)boldSystemFontOfSize:(CGFloat)fontSize
{
    NSFont *systemFont = UIFontBoldSystemFontName? [NSFont fontWithName:UIFontBoldSystemFontName size:fontSize] : [NSFont boldSystemFontOfSize:fontSize];
    return [self fontWithNSFont:systemFont];
}

- (void)dealloc
{
    if (_font) CFRelease(_font);
}

- (NSString *)fontName
{
    return (NSString *)CFBridgingRelease(CTFontCopyPostScriptName(_font));
}

- (CGFloat)ascender
{
    return CTFontGetAscent(_font);
}

- (CGFloat)descender
{
    return -CTFontGetDescent(_font);
}

- (CGFloat)pointSize
{
    return CTFontGetSize(_font);
}

- (CGFloat)xHeight
{
    return CTFontGetXHeight(_font);
}

- (CGFloat)capHeight
{
    return CTFontGetCapHeight(_font);
}

- (CGFloat)lineHeight
{
    return ceilf(self.ascender) - floorf(self.descender) + ceilf(CTFontGetLeading(_font));
}

- (NSString *)familyName
{
    return (NSString *)CFBridgingRelease(CTFontCopyFamilyName(_font));
}

- (UIFont *)fontWithSize:(CGFloat)fontSize
{
    CTFontRef newFont = CTFontCreateCopyWithAttributes(_font, fontSize, NULL, NULL);
    if (newFont) {
        UIFont *theFont = [[self class] _fontWithCTFont:newFont];
        CFRelease(newFont);
        return theFont;
    } else {
        return nil;
    }
}

- (NSFont *)NSFont
{
    return [NSFont fontWithName:self.fontName size:self.pointSize];
}

@end

