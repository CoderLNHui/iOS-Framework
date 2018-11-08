/*
 * UIMenuController.h
 *
 * UIKit (c) 2009-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIMenuControllerArrowDirection) {
    UIMenuControllerArrowDefault, // up or down based on screen location
    UIMenuControllerArrowUp NS_ENUM_AVAILABLE_IOS(3_2),
    UIMenuControllerArrowDown NS_ENUM_AVAILABLE_IOS(3_2),
    UIMenuControllerArrowLeft NS_ENUM_AVAILABLE_IOS(3_2),
    UIMenuControllerArrowRight NS_ENUM_AVAILABLE_IOS(3_2),
} __TVOS_PROHIBITED;

@class UIView, UIMenuItem;

NS_CLASS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED @interface UIMenuController : NSObject

#if UIKIT_DEFINE_AS_PROPERTIES
@property(class, nonatomic, readonly) UIMenuController *sharedMenuController;
#else
+ (UIMenuController *)sharedMenuController;
#endif

@property(nonatomic,getter=isMenuVisible) BOOL menuVisible;	    // default is NO
- (void)setMenuVisible:(BOOL)menuVisible animated:(BOOL)animated;

- (void)setTargetRect:(CGRect)targetRect inView:(UIView *)targetView;
@property(nonatomic) UIMenuControllerArrowDirection arrowDirection NS_AVAILABLE_IOS(3_2); // default is UIMenuControllerArrowDefault

@property(nullable, nonatomic,copy) NSArray<UIMenuItem *> *menuItems NS_AVAILABLE_IOS(3_2); // default is nil. these are in addition to the standard items

- (void)update;

@property(nonatomic,readonly) CGRect menuFrame;

@end

UIKIT_EXTERN NSNotificationName const UIMenuControllerWillShowMenuNotification __TVOS_PROHIBITED;
UIKIT_EXTERN NSNotificationName const UIMenuControllerDidShowMenuNotification __TVOS_PROHIBITED;
UIKIT_EXTERN NSNotificationName const UIMenuControllerWillHideMenuNotification __TVOS_PROHIBITED;
UIKIT_EXTERN NSNotificationName const UIMenuControllerDidHideMenuNotification __TVOS_PROHIBITED;
UIKIT_EXTERN NSNotificationName const UIMenuControllerMenuFrameDidChangeNotification __TVOS_PROHIBITED;

NS_CLASS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED @interface UIMenuItem : NSObject

- (instancetype)initWithTitle:(NSString *)title action:(SEL)action NS_DESIGNATED_INITIALIZER;

@property(nonatomic,copy) NSString *title;
@property(nonatomic)      SEL       action;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
