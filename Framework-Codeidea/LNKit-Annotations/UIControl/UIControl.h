/*
 * UIControl.h 
 *
 * Framework: UIKit (c) 2008-2015
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>


#pragma mark ------------------
#pragma mark - 屏幕点击事件
NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UIControlEvents) {
    UIControlEventTouchDown                                         = 1 <<  0,      // on all touch downs
    UIControlEventTouchDownRepeat【在短时间内连续店家按钮】                                   = 1 <<  1,      // on multiple touchdowns (tap count > 1)
    UIControlEventTouchDragInside【】                                   = 1 <<  2,
    UIControlEventTouchDragOutside【】                                  = 1 <<  3,
    UIControlEventTouchDragEnter【】                                    = 1 <<  4,
    UIControlEventTouchDragExit【】                                     = 1 <<  5,
    UIControlEventTouchUpInside【】                                     = 1 <<  6,
    UIControlEventTouchUpOutside【】                                    = 1 <<  7,
    UIControlEventTouchCancel【】                                       = 1 <<  8,
    
    /** 可以用在开关的监听、值改变 */
    UIControlEventValueChanged【值改变】                                      = 1 << 12,     // sliders, etc.
    UIControlEventPrimaryActionTriggered NS_ENUM_AVAILABLE_IOS(9_0) = 1 << 13,【】     // semantic action: for buttons, etc.
    
    /** 监听文本框的事件 */
    UIControlEventEditingDidBegin【】                                   = 1 << 16,     // UITextField
    UIControlEventEditingChanged【】                                    = 1 << 17,
    UIControlEventEditingDidEnd【】                                     = 1 << 18,
    UIControlEventEditingDidEndOnExit【】                               = 1 << 19,     // 'return key' ending editing
    
    /** 垂直对齐方式 */
    UIControlEventAllTouchEvents【】                                    = 0x00000FFF,  // for touch events
    UIControlEventAllEditingEvents【】                                  = 0x000F0000,  // for UITextField
    UIControlEventApplicationReserved【】                               = 0x0F000000,  // range available for application use
    UIControlEventSystemReserved【】                                    = 0xF0000000,  // range reserved for internal framework use
    UIControlEventAllEvents【】                                         = 0xFFFFFFFF
};

typedef NS_ENUM(NSInteger, UIControlContentVerticalAlignment) {
    /** 水平对齐方式 */
    UIControlContentVerticalAlignmentCenter  = 0,
    UIControlContentVerticalAlignmentTop     = 1,
    UIControlContentVerticalAlignmentBottom  = 2,
    UIControlContentVerticalAlignmentFill    = 3,
};

typedef NS_ENUM(NSInteger, UIControlContentHorizontalAlignment) {
    UIControlContentHorizontalAlignmentCenter = 0,
    UIControlContentHorizontalAlignmentLeft   = 1,
    UIControlContentHorizontalAlignmentRight  = 2,
    UIControlContentHorizontalAlignmentFill   = 3,
};

typedef NS_OPTIONS(NSUInteger, UIControlState) {
    UIControlStateNormal       = 0,
    UIControlStateHighlighted  = 1 << 0,                  // used when UIControl isHighlighted is set
    UIControlStateDisabled     = 1 << 1,
    UIControlStateSelected     = 1 << 2,                  // flag usable by app (see below)
    UIControlStateFocused NS_ENUM_AVAILABLE_IOS(9_0) = 1 << 3, // Applicable only when the screen supports focus
    UIControlStateApplication  = 0x00FF0000,              // additional flags available for application use
    UIControlStateReserved     = 0xFF000000               // flags reserved for internal framework use
};

@class UITouch;
@class UIEvent;

//______________________________________________________

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIControl : UIView

#pragma mark ------------------
#pragma mark - 状态
@property(nonatomic,getter=isEnabled) BOOL enabled;                                  // default is YES. if NO, ignores touch events and subclasses may draw differently
@property(nonatomic,getter=isSelected) BOOL selected;                                // default is NO may be used by some subclasses or by application
@property(nonatomic,getter=isHighlighted) BOOL highlighted;                          // default is NO. this gets set/cleared automatically when touch enters/exits during tracking and cleared on up
@property(nonatomic) UIControlContentVerticalAlignment contentVerticalAlignment;     // how to position content vertically inside control. default is center
@property(nonatomic) UIControlContentHorizontalAlignment contentHorizontalAlignment; // how to position content hozontally inside control. default is center

@property(nonatomic,readonly) UIControlState state;                  // could be more than one state (e.g. disabled|selected). synthesized from other flags.
@property(nonatomic,readonly,getter=isTracking) BOOL tracking;
@property(nonatomic,readonly,getter=isTouchInside) BOOL touchInside; // valid during tracking only

- (BOOL)beginTrackingWithTouch:(UITouch *)touch withEvent:(nullable UIEvent *)event;
- (BOOL)continueTrackingWithTouch:(UITouch *)touch withEvent:(nullable UIEvent *)event;
- (void)endTrackingWithTouch:(nullable UITouch *)touch withEvent:(nullable UIEvent *)event; // touch is sometimes nil if cancelTracking calls through to this.
- (void)cancelTrackingWithEvent:(nullable UIEvent *)event;   // event may be nil if cancelled for non-event reasons, e.g. removed from window

// add target/action for particular event. you can call this multiple times and you can specify multiple target/actions for a particular event.
// passing in nil as the target goes up the responder chain. The action may optionally include the sender and the event in that order
// the action cannot be NULL. Note that the target is not retained.
/** 【监听控件的点击】 */
- (void)addTarget:(nullable id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;

// remove the target/action for a set of events. pass in NULL for the action to remove all actions for that target
/** 【移除监听】 */
- (void)removeTarget:(nullable id)target action:(nullable SEL)action forControlEvents:(UIControlEvents)controlEvents;

// get info about target & actions. this makes it possible to enumerate all target/actions by checking for each event kind
#if UIKIT_DEFINE_AS_PROPERTIES
@property(nonatomic,readonly) NSSet *allTargets;
@property(nonatomic,readonly) UIControlEvents allControlEvents;                            // list of all events that have at least one action
#else
- (NSSet *)allTargets;                                                                     // set may include NSNull to indicate at least one nil target
- (UIControlEvents)allControlEvents;                                                       // list of all events that have at least one action
#endif

- (nullable NSArray<NSString *> *)actionsForTarget:(nullable id)target forControlEvent:(UIControlEvents)controlEvent;    // single event. returns NSArray of NSString selector names. returns nil if none

// send the action. the first method is called for the event and is a point at which you can observe or override behavior. it is called repeately by the second.
- (void)sendAction:(SEL)action to:(nullable id)target forEvent:(nullable UIEvent *)event;
- (void)sendActionsForControlEvents:(UIControlEvents)controlEvents;                        // send all actions associated with events

@end

START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
NS_ASSUME_NONNULL_END
