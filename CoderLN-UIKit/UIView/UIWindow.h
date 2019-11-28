/*
 * UIWindow.h 
 *
 * UIKit (c) 2005-2017
 */
 

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef CGFloat UIWindowLevel;

@class UIEvent, UIScreen, NSUndoManager, UIViewController;

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIWindow : UIView

/**
 屏幕大小 [UIScreen mainScreen]
 */
@property(nonatomic,strong) UIScreen *screen NS_AVAILABLE_IOS(3_2);  // default is [UIScreen mainScreen]. changing the screen may be an expensive operation and should not be done in performance-sensitive code

/**
 default = 0.0，窗口级别越高，显示越靠前
 */
@property(nonatomic) UIWindowLevel windowLevel;                   // default = 0.0

/**
 是否是主窗口
 */
@property(nonatomic,readonly,getter=isKeyWindow) BOOL keyWindow;

/**
 为子类提供。不要直接调用
 */
- (void)becomeKeyWindow;                               // override point for subclass. Do not call directly
- (void)resignKeyWindow;                               // override point for subclass. Do not call directly

/**
 成为主窗口
 */
- (void)makeKeyWindow;
/**
 简化方法，让窗口成为主窗口并且可见，如果要不可见，可以使用view的hidden属性
 */
- (void)makeKeyAndVisible;                             // convenience. most apps call this to show the main window and also make it key. otherwise use view hidden property

/**
 根控制器，默认nil
 */
@property(nullable, nonatomic,strong) UIViewController *rootViewController NS_AVAILABLE_IOS(4_0);  // default is nil

/**
 由UIApplication调用向窗口中的子视图派发事件
 */
- (void)sendEvent:(UIEvent *)event;                    // called by UIApplication to dispatch events to views inside the window

/**
 转换坐标系 (传入nil，表示主屏幕)
 */
- (CGPoint)convertPoint:(CGPoint)point toWindow:(nullable UIWindow *)window;    // can be used to convert to another window
- (CGPoint)convertPoint:(CGPoint)point fromWindow:(nullable UIWindow *)window;  // pass in nil to mean screen
- (CGRect)convertRect:(CGRect)rect toWindow:(nullable UIWindow *)window;
- (CGRect)convertRect:(CGRect)rect fromWindow:(nullable UIWindow *)window;

@end

UIKIT_EXTERN const UIWindowLevel UIWindowLevelNormal;
UIKIT_EXTERN const UIWindowLevel UIWindowLevelAlert;
UIKIT_EXTERN const UIWindowLevel UIWindowLevelStatusBar __TVOS_PROHIBITED;

UIKIT_EXTERN NSNotificationName const UIWindowDidBecomeVisibleNotification; // 窗口成为可见时的通知 nil
UIKIT_EXTERN NSNotificationName const UIWindowDidBecomeHiddenNotification;  // 窗口成为隐藏时的通知 nil
UIKIT_EXTERN NSNotificationName const UIWindowDidBecomeKeyNotification;     // nil
UIKIT_EXTERN NSNotificationName const UIWindowDidResignKeyNotification;     // nil




// Each notification includes a nil object and a userInfo dictionary containing the
// begining and ending keyboard frame in screen coordinates. Use the various UIView and
// UIWindow convertRect facilities to get the frame in the desired coordinate system.
// Animation key/value pairs are only available for the "will" family of notification.
UIKIT_EXTERN NSNotificationName const UIKeyboardWillShowNotification __TVOS_PROHIBITED;// 键盘 将要显示 的通知
UIKIT_EXTERN NSNotificationName const UIKeyboardDidShowNotification __TVOS_PROHIBITED;// 键盘 已经显示 的通知
UIKIT_EXTERN NSNotificationName const UIKeyboardWillHideNotification __TVOS_PROHIBITED;// 键盘 将要隐藏 的通知
UIKIT_EXTERN NSNotificationName const UIKeyboardDidHideNotification __TVOS_PROHIBITED;// 键盘 已经隐藏 的通知





UIKIT_EXTERN NSString *const UIKeyboardFrameBeginUserInfoKey        NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED; // 键盘 NSValue of CGRect
UIKIT_EXTERN NSString *const UIKeyboardFrameEndUserInfoKey          NS_AVAILABLE_IOS(3_2) __TVOS_PROHIBITED; // 键盘Frame NSValue of CGRect
UIKIT_EXTERN NSString *const UIKeyboardAnimationDurationUserInfoKey NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // 键盘弹出所需要的时间 NSNumber of double
UIKIT_EXTERN NSString *const UIKeyboardAnimationCurveUserInfoKey    NS_AVAILABLE_IOS(3_0) __TVOS_PROHIBITED; // NSNumber of NSUInteger (UIViewAnimationCurve)
UIKIT_EXTERN NSString *const UIKeyboardIsLocalUserInfoKey           NS_AVAILABLE_IOS(9_0) __TVOS_PROHIBITED; // NSNumber of BOOL

// Like the standard keyboard notifications above, these additional notifications include
// a nil object and begin/end frames of the keyboard in screen coordinates in the userInfo dictionary.
// 键盘的frame将要改变
UIKIT_EXTERN NSNotificationName const UIKeyboardWillChangeFrameNotification  NS_AVAILABLE_IOS(5_0)  __TVOS_PROHIBITED;
// 键盘的frame已经改变
UIKIT_EXTERN NSNotificationName const UIKeyboardDidChangeFrameNotification   NS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED;

// These keys are superseded by UIKeyboardFrameBeginUserInfoKey and UIKeyboardFrameEndUserInfoKey.
UIKIT_EXTERN NSString *const UIKeyboardCenterBeginUserInfoKey   NS_DEPRECATED_IOS(2_0, 3_2) __TVOS_PROHIBITED;
UIKIT_EXTERN NSString *const UIKeyboardCenterEndUserInfoKey     NS_DEPRECATED_IOS(2_0, 3_2) __TVOS_PROHIBITED;
UIKIT_EXTERN NSString *const UIKeyboardBoundsUserInfoKey        NS_DEPRECATED_IOS(2_0, 3_2) __TVOS_PROHIBITED;
NS_ASSUME_NONNULL_END



//--------------------------- <#我是分割线#> ------------------------------//
//
/*
- (void)keyBoardShowHide:(NSNotification *)notifi
{
    // 获取键盘的frame
    CGRect keyBoardFrame = [notifi.userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    // 键盘弹出所需的时间
    float duration = [notifi.userInfo[UIKeyboardAnimationDurationUserInfoKey] floatValue];
    
    NSLog(@"键盘弹起落下的高度：%f",keyBoardFrame.size.height);
    if ([[notifi name] isEqualToString:UIKeyboardWillShowNotification]) {
        [UIView animateWithDuration:duration animations:^{
            self.inputBgView.transform = CGAffineTransformMakeTranslation(0, keyBoardFrame.origin.y - kScreenHeight);
        }];
    } else if ([[notifi name] isEqualToString:UIKeyboardWillHideNotification]) {
        [UIView animateWithDuration:duration animations:^{
            self.inputBgView.transform = CGAffineTransformIdentity;
        }];
    }
}

*/
















