/*
 * NSShadow.h
 *
 * Framework: UIKit (c) 2002-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */
 

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/*
 NSShadow stores the properties of a drop shadow for drawing text.
 To set a shadow on an NSAttributedString use it as a value for NSShadowAttributeName.
 */

NS_CLASS_AVAILABLE_IOS(6_0) @interface NSShadow : NSObject <NSCopying, NSCoding>

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@property (nonatomic, assign) CGSize shadowOffset;      // offset in user space of the shadow from the original drawing
@property (nonatomic, assign) CGFloat shadowBlurRadius; // blur radius of the shadow in default user space units
@property (nullable, nonatomic, strong) id shadowColor;           // color used for the shadow (default is black with an alpha value of 1/3)

@end

NS_ASSUME_NONNULL_END

