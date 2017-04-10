//
//  UITabBarItem.m
//  UIKit
//
//  Created by Jack
//

#import "UITabBarItem.h"
#import "UIImage.h"

@implementation UITabBarItem

- (id)initWithTitle:(NSString *)title image:(UIImage *)image tag:(NSInteger)tag
{
    if ((self = [super init])) {
        self.title = title;
        self.image = image;
    }
    return self;
}

- (id)initWithTabBarSystemItem:(UITabBarSystemItem)systemItem tag:(NSInteger)tag
{
    if ((self = [super init])) {
    }
    return self;
}

@end
