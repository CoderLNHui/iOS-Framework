/*
 * UIPress.h
 *
 * UIKit (c) 2005-2015
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <UIKit/UITouch.h>

@class UIGestureRecognizer;
@class UIResponder;
@class UIWindow;

NS_ENUM_AVAILABLE_IOS(9_0) typedef NS_ENUM(NSInteger, UIPressPhase) {
    UIPressPhaseBegan,         // whenever a button press begins.
    UIPressPhaseChanged,       // whenever a button moves.
    UIPressPhaseStationary,    // whenever a buttons was pressed and is still being held down.
    UIPressPhaseEnded,         // whenever a button is releasd.
    UIPressPhaseCancelled,     // whenever a button press doesn't end but we need to stop tracking.
};

NS_ENUM_AVAILABLE_IOS(9_0) typedef NS_ENUM(NSInteger, UIPressType) {
    UIPressTypeUpArrow,
    UIPressTypeDownArrow,
    UIPressTypeLeftArrow,
    UIPressTypeRightArrow,
    
    UIPressTypeSelect,
    UIPressTypeMenu,
    UIPressTypePlayPause,
};

NS_CLASS_AVAILABLE_IOS(9_0) @interface UIPress : NSObject

@property(nonatomic,readonly) NSTimeInterval   timestamp;
@property(nonatomic,readonly) UIPressPhase     phase;
@property(nonatomic,readonly) UIPressType      type;

@property(nullable,nonatomic,readonly,strong) UIWindow                        *window;
@property(nullable,nonatomic,readonly,strong) UIResponder                     *responder;
@property(nullable,nonatomic,readonly,copy)   NSArray <UIGestureRecognizer *> *gestureRecognizers;

// For analog buttons, returns a value between 0 and 1.  Digital buttons return 0 or 1.
@property(nonatomic, readonly) CGFloat force;
@end_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
