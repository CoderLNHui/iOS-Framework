//
//  UIButton.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/8.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIButton.h"
#import "UIImage.h"
#import "UILabel.h"
#import "UIImageView.h"


static NSString *UIButtonContentTypeTitle = @"UIButtonContentTypeTitle";
static NSString *UIButtonContentTypeTitleColor = @"UIButtonContentTypeTitleColor";
static NSString *UIButtonContentTypeTitleShadowColor = @"UIButtonContentTypeTitleShadowColor";
static NSString *UIButtonContentTypeBackgroundImage = @"UIButtonContentTypeBackgroundImage";
static NSString *UIButtonContentTypeImage = @"UIButtonContentTypeImage";

@implementation UIButton
{
    UIImageView *_backgroundImageView;
    NSMutableDictionary *_content;
    UIImage *_adjustedHighlightImage;
    UIImage *_adjustedDisabledImage;
}




@end
