/*
 * UIScreenMode.h
 *
 * UIKit (c) 2009-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>
#import <CoreGraphics/CoreGraphics.h>

NS_CLASS_AVAILABLE_IOS(3_2) @interface UIScreenMode : NSObject

@property(readonly,nonatomic) CGSize  size;             // The width and height in pixels
@property(readonly,nonatomic) CGFloat pixelAspectRatio; // The aspect ratio of a single pixel. The ratio is defined as X/Y.

@end_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
