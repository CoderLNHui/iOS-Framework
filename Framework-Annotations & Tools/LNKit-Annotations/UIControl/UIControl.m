/*
 * UIControl.m 
 *
 * (c) 2008-2015
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */


//--------------------------- <#我是分割线#> ------------------------------//
//


/*
UIControl是UIView的子类，当然也是UIResponder的子类。UIControl是诸如UISwitch、UIButton、UISegmentedControl、UISlider、UITextField、UIPageControl等控件的父类，它本身也包含了一些属性和方法，但是不能直接使用UIControl类，它只是定义了子类都需要使用的方法。

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIButton : UIControl <NSCoding>
NS_CLASS_AVAILABLE_IOS(2_0) @interface UIControl : UIView
@property(nonatomic,getter=isEnabled) BOOL enabled;                                  // default is YES. if NO, ignores touch events and subclasses may draw differently
@property(nonatomic,getter=isSelected) BOOL selected;                                // default is NO may be used by some subclasses or by application
@property(nonatomic,getter=isHighlighted) BOOL highlighted;                          // default is NO. this gets set/cleared automatically when touch enters/exits during tracking and cleared on up
@property(nonatomic) UIControlContentVerticalAlignment contentVerticalAlignment;     // how to position content vertically inside control. default is center
@property(nonatomic) UIControlContentHorizontalAlignment contentHorizontalAlignment; // how to position content hozontally inside control. default is center
@property(nonatomic,readonly) UIControlState state;
进去各个控件的头文件里面可以发现 , UIControl是诸如UIButton、UISwitch、UITextField等控件的父类，它本身也包含了一些属性和方法，但是不能直接使用UIControl类，它只是定义了子类都需要使用的方法。UIControl是UIView的子类，当然也是UIResponder的子类。下面就简单讲讲UIControl一些属性和方法。
属性
enabled
控件默认是启用的。要禁用控件，可以将enabled属性设置为NO，这将导致控件忽略任何触摸事件。被禁用后，控件还可以用不同的方式显示自己，比如变成灰色不可用。虽然是由控件的子类完成的，这个属性却存在于UIControl中。
selected
当用户选中控件时，UIControl类会将其selected属性设置为YES。子类有时使用这个属性来让控件选择自身，或者来表现不同的行为方式。
contentVerticalAlignment
控件如何在垂直方向上布置自身的内容。默认是将内容顶端对其，对于文本字段，可能会改成UIControlContentVerticalAlignmentCenter。对于这个字段，可以使用下列诸值：

UIControlContentVerticalAlignmentCenter
UIControlContentVerticalAlignmentTop
UIControlContentVerticalAlignmentBottom
UIControlContentVerticalAlignmentFill
contentHorizontalAlignment
水平对齐方式，可以只用下列值：

UIControlContentHorizontalAlignmentCenter
UIControlContentHorizontalAlignmentTop
UIControlContentHorizontalAlignmentBottom
UIControlContentHorizontalAlignmentFill
事件通知
UIControl类提供了一个标准机制，来进行事件登记和接收。这令你可以指定你的控件在发生特定事件时，通知代理类的一个方法。如果要注册一个事件，可以使用addTarget方法：

[myControl addTarget: myDelegate
              action:@selector(myActionmethod:)
    forControlEvents:UIControlEventValueChanged];
事件可以用逻辑OR合并在一起，因此可以再一次单独的addTarget调用中指定多个事件。下列事件为基类UIControl所支持，除非另有说明，也适用于所有控件。
 下列事件为基类UIControl所支持，除非另有说明，也适用于所有控件:
 UIControlEventTouchDown
 
 单点触摸按下事件：用户点触屏幕，或者又有新手指落下的时候。
 
 UIControlEventTouchDownRepeat
 
 多点触摸按下事件，点触计数大于1：用户按下第二、三、或第四根手指的时候。
 
 UIControlEventTouchDragInside
 
 当一次触摸在控件窗口内拖动时。
 
 UIControlEventTouchDragOutside
 
 当一次触摸在控件窗口之外拖动时。
 
 UIControlEventTouchDragEnter
 
 当一次触摸从控件窗口之外拖动到内部时。
 
 UIControlEventTouchDragExit
 
 当一次触摸从控件窗口内部拖动到外部时。
 
 UIControlEventTouchUpInside
 
 所有在控件之内触摸抬起事件。
 
 UIControlEventTouchUpOutside
 
 所有在控件之外触摸抬起事件(点触必须开始与控件内部才会发送通知)。
 
 UIControlEventTouchCancel
 
 所有触摸取消事件，即一次触摸因为放上了太多手指而被取消，或者被上锁或者电话呼叫打断。
 
 UIControlEventTouchChanged
 
 当控件的值发生改变时，发送通知。用于滑块、分段控件、以及其他取值的控件。你可以配置滑块控件何时发送通知，在滑块被放下时发送，或者在被拖动时发送。
 
 UIControlEventEditingDidBegin
 
 当文本控件中开始编辑时发送通知。
 
 UIControlEventEditingChanged
 
 当文本控件中的文本被改变时发送通知。
 
 UIControlEventEditingDidEnd
 
 当文本控件中编辑结束时发送通知。
 
 UIControlEventEditingDidOnExit
 
 当文本控件内通过按下回车键（或等价行为）结束编辑时，发送通知。
 
 UIControlEventAllEditingEvents
 
 通知所有关于文本编辑的事件。
 
 UIControlEventAllEvents
 
 通知所有事件。
 


要删除一个或多个事件的相应动作，可以使用UIControl类的removeTarget方法。使用nil值就可以将给定事件目标的所有动作删除：

[myControl removeTarget:myDelegate
                 action:nil
       forControlEvents:UIControlEventAllEvents];
如果设计了一个自定义控件类，可以使用sendActionsForControlEvent方法，为基本的UIControl事件或自己的自定义事件发送通知。例如，如果你的控件值正在发生变化，就可以发送相应通知，通过控件的代码可以指定时间目标，这个通知将被传播到这些指定的目标。例：

[self sendActionsForControlEvents:UIControlEventValueChanged];
UITouch类中包含如下成员函数：
- (CGPoint)locationInView:(UIView *)view;
函数返回一个CGPoint类型的值，表示触摸在view这个视图上的位置，这里返回的位置是针对view的坐标系的。调用时传入的view参数为空的话，返回的时触摸点在整个窗口的位置。

- (CGPoint)previousLocationInView:(UIView *)view;
该方法记录了前一个坐标值，函数返回也是一个CGPoint类型的值， 表示触摸在view这个视图上的位置，这里返回的位置是针对view的坐标系的。调用时传入的view参数为空的话，返回的时触摸点在整个窗口的位置。

当手指接触到屏幕，不管是单点触摸还是多点触摸，事件都会开始，直到用户所有的手指都离开屏幕。期间所有的UITouch对象都被包含在UIEvent事件对象中，由程序分发给处理者。事件记录了这个周期中所有触摸对象状态的变化。
只要屏幕被触摸，系统就会报若干个触摸的信息封装到UIEvent对象中发送给程序，由管理程序UIApplication对象将事件分发。一般来说，事件将被发给主窗口，然后传给第一响应者对象(FirstResponder)处理。


*/





