/*
 * File:  UIVisualEffectView.h
 *
 * Framework: UIKit (c) 2014-2017
 *
 * About ME『https://github.com/CoderLN / https://dwz.cn/rC1LGk2f』
 */


import Foundation
import UIKit

// 链接：https://www.jianshu.com/p/27926fa8c5ac

/* UIVisualEffectView is a class that provides a simple abstraction over complex visual effects.
 Depending on the desired effect, the results may affect content layered behind the view or content added to the view's contentView.
 Please see the notes for each UIVisualEffect for more details.
 
 UIVisualEffectView 是一个类,它提供了一个简单的抽象复杂的视觉效果。根据预期的效果,结果可能会影响效果视图后面的内容 或者是 添加到效果视图的contentView中的内容。详细信息,请参阅每个UIVisualEffect的笔记。
 
 Proper use of this class requires some assistance on your part. Namely:
 正确使用这个类的需要一些帮助
 
 • Avoid alpha values < 1 - By default, when a view is partially transparent, the system composites that view and all of its subviews in an offscreen render pass to get the correct translucency. However, UIVisualEffects require being composited as part of the content they are logically layered on top of to look correct. If alpha is less than 1 on the UIVisualEffectView or any of its superviews, many effects will look incorrect or won't show up at all. Setting the alpha on views placed inside the contentView is supported.
 * 避免 alpha 的值 小于 1。 当一个 view 是部分透明的时候，视图的 view 和 子view会在离屏渲染的时候来获取正确的透明度。然而,UIVisualEffects需要被合成为内容的一部分,他们在逻辑上是分层的正确。 如果UIVisualEffectView透明度小于1 或任何它的父视图的透明度小于1 ,许多影响会看起来不正确或根本不会出现。设置视图放置在contentView 透明度是支持。
 
 • Judicious masking - Masks have similar semantics to non-opaque views with regards to offscreen rendering.
 Masks applied to the UIVisualEffectView itself are forwarded to all internal views, including the contentView.
 You are free to apply a mask to just the contentView. The mask you provide to UIVisualEffectView will not be the view that actually performs the mask. UIKit will make copies of the view to apply to each subview.
 To reflect a size change to the mask, you must apply the change to the original mask view and reset it on the effect view.
 Applying a mask to a superview of a UIVisualEffectView (via setMaskView: or the layer's mask property) will cause the effect to fail.
 谨慎的遮罩 -
 
 • Correctly capturing snapshots - Many effects require support from the window that hosts the view.
 As such, attempting to take a snapshot of just the UIVisualEffectView will result in the snapshot not containing the effect at all or it appearing incorrectly. To properly snapshot a view hierarchy that contains a UIVisualEffectView, you must snapshot the entire UIWindow or UIScreen that contains it.
 正确的获取快照 - 大多数的效果是需要主视图窗口的支持。因此，试着去获取 UIVisualEffectView 的截屏，可能截取到的视图是不会包含任何效果的，有可能出现显示错误。 为了正确的截取一个包含该 UIVisualEffectView 视图的的层级视图，你必须截取 UIWindow 或者 UIScreen 包含的内容。
 */

@available(iOS 8.0, *)

// 模糊效果样式枚举
public enum UIBlurEffectStyle : Int {
    
    // Creates a blurring effect in the view. The area of the view is lighter in hue than the underlying view.
    // 区域视图比下面的视图在色调更加的亮
case extraLight
    
    // Creates a blurring effect in the view. The area of the view is the same approximate hue of the underlying view.
    // 区域视图和下面的视图在色调上近似
case light
    
    // Creates a blurring effect in the view. The area of the view is darker in hue than the underlying view.
    // 区域视图和下面的视图在色调上更加的暗
case dark
    
    
    
    // --------------  在 iOS10 可以用- 适应用户界面风格 ---------
    @available(iOS 10.0, *)
case regular // Adapts to user interface style
    
    @available(iOS 10.0, *)
case prominent // Adapts to user interface style
}



@available(iOS 8.0, *)
// 视觉效果
public class UIVisualEffect : NSObject, NSCopying, NSSecureCoding {
}



/* UIBlurEffect will provide a blur that appears to have been applied to the content layered behind the UIVisualEffectView.
 Views added to the contentView of a blur visual effect are not blurred themselves.
 UIBlurEffect 将给 UIVisualEffectView content layered 下面的视图产生一个模糊显示的效果。
 view 添加到 UIVisualEffectView 的 contentView 中是不会产生模糊效果的。
 */
@available(iOS 8.0, *)
// 模糊效果
public class UIBlurEffect : UIVisualEffect {
    
    public /*not inherited*/ init(style: UIBlurEffectStyle)
}

/* UIVibrancyEffect amplifies and adjusts the color of content layered behind the view, allowing content placed inside the contentView to become more vivid.
 UIVibrancyEffect 增强和调整 UIVibrancyEffect content layered 后面视图的颜色，会使在 contentView 中的内容变的更加的生动。
 
 It is intended to be placed over, or as a subview of, a UIVisualEffectView that has been configured with a UIBlurEffect.
 UIVisualEffectView 作为一个 UIBlurEffect 的子视图被添加到 UIBlurEffect 上面。
 
 This effect only affects content added to the contentView.
 这个效果只会影响添加到 contentView 中的内容。
 
 Because the vibrancy effect is color dependent, subviews added to the contentView need to be tintColorDidChange aware and must be prepared to update themselves accordingly.
 因为 vibrancy effect 的颜色依靠 添加到 contentView 中 subviews 的 tintColorDidChange 时时的更新自己。
 
 UIImageView will need its image to have a rendering mode of UIImageRenderingModeAlwaysTemplate to receive the proper effect.
 UIImageView 需要调整 image 的渲染模式为 UIImageRenderingModeAlwaysTemplate 来适应 vibrancy effect 的效果。
 
 */
@available(iOS 8.0, *)
// 视觉效果视图
public class UIVibrancyEffect : UIVisualEffect {
    
    public /*not inherited*/ init(blurEffect: UIBlurEffect)
}

@available(iOS 8.0, *)
// 高亮视觉效果视图
public class UIVisualEffectView : UIView, NSSecureCoding {
    
    // 内容视图（需要进行视觉效果处理的视图就添加到 content 中）
    public var contentView: UIView { get } // Do not add subviews directly to UIVisualEffectView, use this view instead.
    
    // 视觉效果（模糊和高亮）
    @NSCopying public var effect: UIVisualEffect?
    
    public init(effect: UIVisualEffect?)
    public init?(coder aDecoder: NSCoder)
}




//----------------------- <#<--- 不知名开发者 --->#> ------------------------//
//
/**

UIVisualEffect

UIVisualEffect 是一个集成自 NSObject 的基类。
两个子类：
| -- UIBlurEffect (模糊效果)
| -- UIVibrancyEffect （在模糊效果上实现特殊效果）

一个UIBlurEffect对象用于将blur(毛玻璃)效果应用于UIVisualEffectView视图下面的内容。如上面的示例所示。不过，这个对象的效果并不影响UIVisualEffectView对象的contentView中的内容。
UIVibrancyEffect主要用于放大和调整UIVisualEffectView视图下面的内容的颜色，同时让UIVisualEffectView的contentView中的内容看起来更加生动。（可以理解为在毛玻璃上滴了一滴水，用水在毛玻璃上进行写字。 写字的效果就是 UIVibrancyEffect 效果的简单使用）
通常UIVibrancyEffect对象是与UIBlurEffect一起使用，主要用于处理在UIBlurEffect特效上的一些显示效果。
 
 */










