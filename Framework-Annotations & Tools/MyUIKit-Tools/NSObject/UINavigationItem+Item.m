/*
 * UINavigationItem+Item.m
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【Plain Boiled Water ln】 on Elegant programming16.
 * Copyright © Unauthorized shall（https://custompbwaters.github.io）not be reproduced.
 *
 * @PBWLN_LICENSE_HEADER_END@
 */

#import "UINavigationItem+Tool.h"

@implementation UINavigationItem (Item)

@end


#import <objc/runtime.h>

static void *LoaderPositionAssociationKey = &LoaderPositionAssociationKey;
static void *SubstitutedViewAssociationKey = &SubstitutedViewAssociationKey;

@implementation UINavigationItem (Loading)

- (void)startAnimatingAt:(NavBarLoaderPosition)position {
    // stop previous if animated
    [self stopAnimating];
    
    // hold reference for position to stop at the right place
    objc_setAssociatedObject(self, LoaderPositionAssociationKey, @(position), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    
    UIActivityIndicatorView* loader = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    
    // substitute bar views to loader and hold reference to them for restoration
    switch (position) {
        case NavBarLoaderPositionLeft:
            objc_setAssociatedObject(self, SubstitutedViewAssociationKey, self.leftBarButtonItem.customView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            self.leftBarButtonItem.customView = loader;
            break;
            
        case NavBarLoaderPositionCenter:
            objc_setAssociatedObject(self, SubstitutedViewAssociationKey, self.titleView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            self.titleView = loader;
            break;
            
        case NavBarLoaderPositionRight:
            objc_setAssociatedObject(self, SubstitutedViewAssociationKey, self.rightBarButtonItem.customView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
            self.rightBarButtonItem.customView = loader;
            break;
    }
    
    [loader startAnimating];
}

- (void)stopAnimating {
    NSNumber* positionToRestore = objc_getAssociatedObject(self, LoaderPositionAssociationKey);
    id componentToRestore = objc_getAssociatedObject(self, SubstitutedViewAssociationKey);
    
    // restore UI if animation was in a progress
    if (positionToRestore) {
        switch (positionToRestore.intValue) {
            case NavBarLoaderPositionLeft:
                self.leftBarButtonItem.customView = componentToRestore;
                break;
                
            case NavBarLoaderPositionCenter:
                self.titleView = componentToRestore;
                break;
                
            case NavBarLoaderPositionRight:
                self.rightBarButtonItem.customView = componentToRestore;
                break;
        }
    }
    
    objc_setAssociatedObject(self, LoaderPositionAssociationKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    objc_setAssociatedObject(self, SubstitutedViewAssociationKey, nil, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end



#import <objc/runtime.h>

@implementation UINavigationItem (Margin)

+ (void)load
{
    // left
    [self swizzle:@selector(leftBarButtonItem)];
    [self swizzle:@selector(setLeftBarButtonItem:animated:)];
    [self swizzle:@selector(leftBarButtonItems)];
    [self swizzle:@selector(setLeftBarButtonItems:animated:)];
    
    // right
    [self swizzle:@selector(rightBarButtonItem)];
    [self swizzle:@selector(setRightBarButtonItem:animated:)];
    [self swizzle:@selector(rightBarButtonItems)];
    [self swizzle:@selector(setRightBarButtonItems:animated:)];
}

+ (void)swizzle:(SEL)selector
{
    NSString *name = [NSString stringWithFormat:@"swizzled_%@", NSStringFromSelector(selector)];
    
    Method m1 = class_getInstanceMethod(self, selector);
    Method m2 = class_getInstanceMethod(self, NSSelectorFromString(name));
    
    method_exchangeImplementations(m1, m2);
}


#pragma mark - Global

+ (CGFloat)systemMargin
{
    return 16; // iOS 7+
}


#pragma mark - Spacer

- (UIBarButtonItem *)spacerForItem:(UIBarButtonItem *)item withMargin:(CGFloat)margin
{
    UIBarButtonSystemItem type = UIBarButtonSystemItemFixedSpace;
    UIBarButtonItem *spacer = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:type target:self action:nil];
    spacer.width = margin - [self.class systemMargin];
    if (!item.customView)
    {
        spacer.width += 8; // a margin of private class `UINavigationButton` is different from custom view
    }
    return spacer;
}

- (UIBarButtonItem *)leftSpacerForItem:(UIBarButtonItem *)item
{
    return [self spacerForItem:item withMargin:self.leftMargin];
}

- (UIBarButtonItem *)rightSpacerForItem:(UIBarButtonItem *)item
{
    return [self spacerForItem:item withMargin:self.rightMargin];
}


#pragma mark - Margin

- (CGFloat)leftMargin
{
    NSNumber *value = objc_getAssociatedObject(self, @selector(leftMargin));
    return value ? value.floatValue : [self.class systemMargin];
}

- (void)setLeftMargin:(CGFloat)leftMargin
{
    objc_setAssociatedObject(self, @selector(leftMargin), @(leftMargin), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    self.leftBarButtonItems = self.leftBarButtonItems;
}

- (CGFloat)rightMargin
{
    NSNumber *value = objc_getAssociatedObject(self, @selector(rightMargin));
    return value ? value.floatValue : [self.class systemMargin];
}

- (void)setRightMargin:(CGFloat)rightMargin
{
    objc_setAssociatedObject(self, @selector(rightMargin), @(rightMargin), OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    self.rightBarButtonItems = self.rightBarButtonItems;
}


#pragma mark - Original Bar Button Items

- (NSArray *)originalLeftBarButtonItems
{
    NSArray *items = objc_getAssociatedObject(self, @selector(originalLeftBarButtonItems));
    if (!items)
    {
        items = [self swizzled_leftBarButtonItems];
        self.originalLeftBarButtonItems = items;
    }
    return items;
}

- (void)setOriginalLeftBarButtonItems:(NSArray *)items
{
    objc_setAssociatedObject(self, @selector(originalLeftBarButtonItems), items, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSArray *)originalRightBarButtonItems
{
    NSArray *items = objc_getAssociatedObject(self, @selector(originalRightBarButtonItems));
    if (!items)
    {
        items = [self swizzled_rightBarButtonItems];
        self.originalRightBarButtonItems = items;
    }
    return items;
}

- (void)setOriginalRightBarButtonItems:(NSArray *)items
{
    objc_setAssociatedObject(self, @selector(originalRightBarButtonItems), items, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}


#pragma mark - Bar Button Item

- (UIBarButtonItem *)swizzled_leftBarButtonItem
{
    return self.originalLeftBarButtonItems.firstObject;
}

- (void)swizzled_setLeftBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated
{
    if (!item)
    {
        [self setLeftBarButtonItems:nil animated:animated];
    }
    else
    {
        [self setLeftBarButtonItems:@[item] animated:animated];
    }
}

- (UIBarButtonItem *)swizzled_rightBarButtonItem
{
    return self.originalRightBarButtonItems.firstObject;
}

- (void)swizzled_setRightBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated
{
    if (!item)
    {
        [self setRightBarButtonItems:nil animated:animated];
    }
    else
    {
        [self setRightBarButtonItems:@[item] animated:animated];
    }
}


#pragma mark - Bar Button Items

- (NSArray *)swizzled_leftBarButtonItems
{
    return self.originalLeftBarButtonItems;
}

- (void)swizzled_setLeftBarButtonItems:(NSArray *)items animated:(BOOL)animated
{
    if (items.count)
    {
        self.originalLeftBarButtonItems = items;
        UIBarButtonItem *spacer = [self leftSpacerForItem:items.firstObject];
        NSArray *itemsWithMargin = [@[spacer] arrayByAddingObjectsFromArray:items];
        [self swizzled_setLeftBarButtonItems:itemsWithMargin animated:animated];
    }
    else
    {
        self.originalLeftBarButtonItems = nil;
        [self swizzled_setLeftBarButtonItem:nil animated:animated];
    }
}

- (NSArray *)swizzled_rightBarButtonItems
{
    return self.originalRightBarButtonItems;
}

- (void)swizzled_setRightBarButtonItems:(NSArray *)items animated:(BOOL)animated
{
    if (items.count)
    {
        self.originalRightBarButtonItems = items;
        UIBarButtonItem *spacer = [self rightSpacerForItem:items.firstObject];
        NSArray *itemsWithMargin = [@[spacer] arrayByAddingObjectsFromArray:items];
        [self swizzled_setRightBarButtonItems:itemsWithMargin animated:animated];
    }
    else
    {
        self.originalRightBarButtonItems = nil;
        [self swizzled_setRightBarButtonItem:nil animated:animated];
    }
}

@end

