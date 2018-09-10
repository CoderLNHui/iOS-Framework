/*
 * UIControl.h 
 *
 * UIKit (c) 2008-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

#pragma mark - 事件监听
NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, UIControlEvents) {
#pragma mark -所有的触摸事件
    UIControlEventTouchDown                                         = 1 <<  0,      // on all touch downs
    UIControlEventTouchDownRepeat【在短时间内连续店家按钮】                                   = 1 <<  1,      // on multiple touchdowns (tap count > 1)
    UIControlEventTouchDragInside【】                                   = 1 <<  2,
    UIControlEventTouchDragOutside【】                                  = 1 <<  3,
    UIControlEventTouchDragEnter【】                                    = 1 <<  4,
    UIControlEventTouchDragExit【】                                     = 1 <<  5,
    UIControlEventTouchUpInside【】                                     = 1 <<  6,
    UIControlEventTouchUpOutside【】                                    = 1 <<  7,
    UIControlEventTouchCancel【】                                       = 1 <<  8,

#pragma mark - sliders滑块事件
    UIControlEventValueChanged【值改变】                                      = 1 << 12,     // sliders, etc.
#pragma mark -semantic事件
    UIControlEventPrimaryActionTriggered NS_ENUM_AVAILABLE_IOS(9_0) = 1 << 13,【】     // semantic action: for buttons, etc.
    
#pragma mark -textField事件
    UIControlEventEditingDidBegin【】                                   = 1 << 16,     // UITextField
    UIControlEventEditingChanged【】                                    = 1 << 17,
    UIControlEventEditingDidEnd【】                                     = 1 << 18,
#pragma mark -return返回键结束编辑事件
    UIControlEventEditingDidEndOnExit【】                               = 1 << 19,     // 'return key' ending editing

    
    UIControlEventAllTouchEvents【触摸】                                    = 0x00000FFF,  // for touch events
    UIControlEventAllEditingEvents【编辑】                                  = 0x000F0000,  // for UITextField
    UIControlEventApplicationReserved【】                               = 0x0F000000,  // range available for application use
    UIControlEventSystemReserved【】                                    = 0xF0000000,  // range reserved for internal framework use
    UIControlEventAllEvents【】                                         = 0xFFFFFFFF
};

#pragma mark -竖直对齐方式事件
typedef NS_ENUM(NSInteger, UIControlContentVerticalAlignment) {
    UIControlContentVerticalAlignmentCenter  = 0,
    UIControlContentVerticalAlignmentTop     = 1,
    UIControlContentVerticalAlignmentBottom  = 2,
    UIControlContentVerticalAlignmentFill    = 3,
};

#pragma mark -水平对齐方式事件
typedef NS_ENUM(NSInteger, UIControlContentHorizontalAlignment) {
    UIControlContentHorizontalAlignmentCenter = 0,
    UIControlContentHorizontalAlignmentLeft   = 1,
    UIControlContentHorizontalAlignmentRight  = 2,
    UIControlContentHorizontalAlignmentFill   = 3,
};

#pragma mark -控件状态
typedef NS_OPTIONS(NSUInteger, UIControlState) {
    UIControlStateNormal       = 0,普通
    UIControlStateHighlighted  = 1 << 0,高亮                  // used when UIControl isHighlighted is set
    UIControlStateDisabled     = 1 << 1,失效
    UIControlStateSelected     = 1 << 2,选中                  // flag usable by app (see below)
    UIControlStateFocused NS_ENUM_AVAILABLE_IOS(9_0) = 1 << 3,焦点 // Applicable only when the screen supports focus
    UIControlStateApplication  = 0x00FF0000,              // additional flags available for application use
    UIControlStateReserved     = 0xFF000000               // flags reserved for internal framework use
};



@class UITouch;
@class UIEvent;
//______________________________________________________

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIControl : UIView

#pragma mark - 状态
@property(nonatomic,getter=isEnabled) BOOL enabled;                                  // default is YES. if NO, ignores touch events and subclasses may draw differently
@property(nonatomic,getter=isSelected) BOOL selected;                                // default is NO may be used by some subclasses or by application
@property(nonatomic,getter=isHighlighted) BOOL highlighted;                          // default is NO. this gets set/cleared automatically when touch enters/exits during tracking and cleared on up
@property(nonatomic) UIControlContentVerticalAlignment contentVerticalAlignment;     // how to position content vertically inside control. default is center
@property(nonatomic) UIControlContentHorizontalAlignment contentHorizontalAlignment; // how to position content hozontally inside control. default is center

@property(nonatomic,readonly) UIControlState state;                  // could be more than one state (e.g. disabled|selected). synthesized from other flags.
@property(nonatomic,readonly,getter=isTracking) BOOL tracking;
@property(nonatomic,readonly,getter=isTouchInside) BOOL touchInside; // valid during tracking only


#pragma mark - 方法
- (BOOL)beginTrackingWithTouch:(UITouch *)touch withEvent:(nullable UIEvent *)event;
- (BOOL)continueTrackingWithTouch:(UITouch *)touch withEvent:(nullable UIEvent *)event;
- (void)endTrackingWithTouch:(nullable UITouch *)touch withEvent:(nullable UIEvent *)event; // touch is sometimes nil if cancelTracking calls through to this.
- (void)cancelTrackingWithEvent:(nullable UIEvent *)event;   // event may be nil if cancelled for non-event reasons, e.g. removed from window

// add target/action for particular event. you can call this multiple times and you can specify multiple target/actions for a particular event.
// passing in nil as the target goes up the responder chain. The action may optionally include the sender and the event in that order
// the action cannot be NULL. Note that the target is not retained.
#pragma mark -添加事件
- (void)addTarget:(nullable id)target action:(SEL)action forControlEvents:(UIControlEvents)controlEvents;

// remove the target/action for a set of events. pass in NULL for the action to remove all actions for that target
#pragma mark -移除监听
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

NS_ASSUME_NONNULL_END
