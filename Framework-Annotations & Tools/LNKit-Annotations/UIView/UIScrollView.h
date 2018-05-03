/*
 * UIScrollView.h 
 *
 * Framework: UIKit (c) 2007-2017
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */



#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIRefreshControl.h>


NS_ASSUME_NONNULL_BEGIN

#pragma mark - 枚举 & 常量

typedef NS_ENUM(NSInteger, UIScrollViewIndicatorStyle) {
    UIScrollViewIndicatorStyleDefault, // 黑内容白边框,适用于任何背景    // black with white border. good against any background
    UIScrollViewIndicatorStyleBlack,  // 全黑     // black only. smaller. good against a white background
    UIScrollViewIndicatorStyleWhite  // 全白      // white only. smaller. good against a black background
}; // 设置滚动条的样式

typedef NS_ENUM(NSInteger, UIScrollViewKeyboardDismissMode) {
    UIScrollViewKeyboardDismissModeNone, // 不隐藏键盘
    UIScrollViewKeyboardDismissModeOnDrag,  // 当拖拽scrollView时隐藏键盘    // dismisses the keyboard when a drag begins
    UIScrollViewKeyboardDismissModeInteractive,// 当拖拽键盘上方时隐藏键盘 // the keyboard follows the dragging touch off screen, and may be pulled upward again to cancel the dismiss
} NS_ENUM_AVAILABLE_IOS(7_0);// 键盘的消失模式



UIKIT_EXTERN const CGFloat UIScrollViewDecelerationRateNormal NS_AVAILABLE_IOS(3_0); // 慢慢停止
UIKIT_EXTERN const CGFloat UIScrollViewDecelerationRateFast NS_AVAILABLE_IOS(3_0); // 快速停止

@class UIEvent, UIImageView, UIPanGestureRecognizer, UIPinchGestureRecognizer;
@protocol UIScrollViewDelegate;






#pragma mark - ↑
#pragma mark - 常用属性

NS_CLASS_AVAILABLE_IOS(2_0) @interface UIScrollView : UIView <NSCoding>



#pragma mark - 内容视图属性/方法

/**
 作用： 内容视图大小, 是指定scollView能显示的内容的大小
 使用：
    self.scrollView.contentSize = CGSizeMake(image.size.width, image.size.height);
 注解：
    如果不设置contentSize的大小默认contentSize的大小就是scrollView的view的frame的大小
 */
@property(nonatomic)         CGSize                       contentSize;                    // default CGSizeZero


/**
 作用： 内容偏移量, (xy: 上左为正,下右为负)
 使用：
    [self.scrollView setContentOffset:CGPointMake(self.scrollView.contentOffset.x, 100) animated:YES];
 注解：
    contentOffset = scrollView.frame.size.width左上角 - contentSize.width内容视图的左上角
    x轴不滑动: 可以写成 self.scrollView.contentOffset.x 不建议直接写成0
    y轴滑动:   y = 100 向上滑动偏移100(显示下部内容)
 */
@property(nonatomic)         CGPoint                      contentOffset;                  // default CGPointZero


/**
 作用： 内边距, (上左下右: 向里为正,向外为负), 在内容周围额外增加的间距始终粘着内容;
 使用：
    self.scrollView.contentInset = UIEdgeInsetsMake(20, 20, 20, 20);
 */
@property(nonatomic)         UIEdgeInsets                 contentInset;                   // default UIEdgeInsetsZero. add additional scroll area around content


@property(nullable,nonatomic,weak) id<UIScrollViewDelegate>        delegate;// 代理【id 任何对象】         // default nil. weak reference


/**
 作用： 设置内容视图的原点相对于scrollView的原点的【内容偏移量】，带动画效果;
 使用：
    [self.scrollView setContentOffset:CGPointMake(0, 100) animated:YES];
 注解：
    方法动画结束时调用 scrollViewDidEndScrollingAnimation: (仅当animated设置为YES时才调用)
 */
- (void)setContentOffset:(CGPoint)contentOffset animated:(BOOL)animated;  // animate at constant velocity to new offset






#pragma mark - ↑
#pragma mark - 滑动属性方法


/**
 作用：是否允许多个方向(水平/竖直)同时滑动,默认为NO,
 注解：
    如果设置为YES,用户在水平/竖直方向开始进行滑动,便禁止同时在竖直/水平方向滑动
 */
@property(nonatomic,getter=isDirectionalLockEnabled) BOOL directionalLockEnabled;         // default NO. if YES, try to lock vertical or horizontal scrolling while dragging


/**
 作用：是否有触底反弹效果(可以看到背景颜色),默认为YES
 */
@property(nonatomic)         BOOL                         bounces;                        // default YES. if YES, bounces past edge of content and back again


/**
 作用：是否总是有触底反弹效果(即使内容视图小于scrollView的大小),默认为NO
 注解：
    生效的前提条件为bounces = YES
 */
@property(nonatomic)         BOOL                         alwaysBounceVertical;           // default NO. if YES and bounces is YES, even if content is smaller than bounds, allow drag vertically
@property(nonatomic)         BOOL                         alwaysBounceHorizontal;         // default NO. if YES and bounces is YES, even if content is smaller than bounds, allow drag horizontally

/**
 作用：是否按页数进行滑动,默认为NO
 注解：如果设置为YES,则在滑动时只会停止在scrollView的bounds的倍数处
 */
@property(nonatomic,getter=isPagingEnabled) BOOL          pagingEnabled __TVOS_PROHIBITED;// default NO. if YES, stop on multiples of view bounds

/**
 作用：是否允许滑动,默认为YES
 */
@property(nonatomic,getter=isScrollEnabled) BOOL          scrollEnabled;                  // default YES. turn off any dragging temporarily


// When the user taps the status bar, the scroll view beneath the touch which is closest to the status bar will be scrolled to top, but only if its `scrollsToTop` property is YES, its delegate does not return NO from `shouldScrollViewScrollToTop`, and it is not already at the top.
// On iPhone, we execute this gesture only if there's one on-screen scroll view with `scrollsToTop` == YES. If more than one is found, none will be scrolled.
/**
 作用：是否允许点击状态栏让距离状态栏最近的scrollView滑动到顶部,默认为YES
 注解：
    在iPhone中如果有多个scrollView时，将该属性设置为YES的,则该方法无效;在iPad中则将距离状态栏最近的scrollView滑动到顶部
 */
@property(nonatomic) BOOL  scrollsToTop __TVOS_PROHIBITED;          // default is YES.


/**
 作用：指定用户手指离开屏幕后滑动减速的比率,默认为UIScrollViewDecelerationRateNormal(慢慢停止)
 注解：
    其余可选项为UIScrollViewDecelerationRateFast(快速停止)
 */
@property(nonatomic)         CGFloat                      decelerationRate NS_AVAILABLE_IOS(3_0);


/**
 作用：将指定区域滑动到刚好可见处(即距离边缘最近处)
 */
- (void)scrollRectToVisible:(CGRect)rect animated:(BOOL)animated;         // scroll so rect is just visible (nearest edges). nothing if rect completely visible








#pragma mark - ↑
#pragma mark - 指示器属性方法

/**
 作用：是否在滑动时指示器可见【水平】,默认为YES
 */
@property(nonatomic)         BOOL                         showsHorizontalScrollIndicator; // default YES. show indicator while we are tracking. fades out after tracking


/**
 作用：是否在滑动时指示器可见【竖直】,默认为YES
 */
@property(nonatomic)         BOOL                         showsVerticalScrollIndicator;   // default YES. show indicator while we are tracking. fades out after tracking

/**
 作用：为指示器周围增加可滚动区域【滚动条内边距】,默认为UIEdgeInsetsZero
 */
@property(nonatomic)         UIEdgeInsets                 scrollIndicatorInsets;          // default is UIEdgeInsetsZero. adjust indicators inside of insets


/**
 作用：指示器样式,默认为UIScrollViewIndicatorStyleDefault(黑内容白边框,适用于任何背景), Black(全黑)、White(全白)
 */
@property(nonatomic)         UIScrollViewIndicatorStyle   indicatorStyle;                 // default is UIScrollViewIndicatorStyleDefault

/**
 作用：闪一下指示器(注: 建议在scrollView展示给用户时调用一下,以提醒用户该处可滑动)
 */
- (void)flashScrollIndicators;             // displays the scroll indicators for a short time. This should be done whenever you bring the scroll view to front.






/*
 Scrolling with no scroll bars is a bit complex. on touch down, we don't know if the user will want to scroll or track a subview like a control.
 on touch down, we start a timer and also look at any movement. if the time elapses without sufficient change in position, we start sending events to
 the hit view in the content subview. if the user then drags far enough, we switch back to dragging and cancel any tracking in the subview.
 the methods below are called by the scroll view and give subclasses override points to add in custom behaviour.
 you can remove the delay in delivery of touchesBegan:withEvent: to subviews by setting delaysContentTouches to NO.
 */
#pragma mark - ↑
#pragma mark - 事件属性方法


/**
 作用：返回是否用户已经触碰了内容视图准备进行滑动
 注解：该值被设置为YES的时候可能用户只是触碰了内容视图,但是并没有开始进行滑动
 */
@property(nonatomic,readonly,getter=isTracking)     BOOL tracking;        // returns YES if user has touched. may not yet have started dragging

/**
 作用：返回是否用户已经开始滑动内容视图
 注解：该值被设置为YES之前可能需要先滑动一段时间或距离
 */
@property(nonatomic,readonly,getter=isDragging)     BOOL dragging;        // returns YES if user has started scrolling. this may require some time and or distance to move to initiate dragging


/**
 作用：返回是否处于减速状态(即手指已经离开屏幕,但scrollView仍然处于滑动中)
 */
@property(nonatomic,readonly,getter=isDecelerating) BOOL decelerating;    // returns YES if user isn't dragging (touch up) but scroll view is still moving


/**
 作用：是否延迟事件传递,默认为YES,
 注解：如果设置为NO,scrollView会立即调用-touchesShouldBegin:withEvent:inContentView:方法以进行下一步操作
 */
@property(nonatomic) BOOL delaysContentTouches;       // default is YES. if NO, we immediately call -touchesShouldBegin:withEvent:inContentView:. this has no effect on presses


/**
 作用：是否可以取消内容视图被触摸,默认为YES,
 注解：如果设置为NO,则一旦开始跟踪事件,即使手指进行移动也不会取消已经传递给子视图的事件
 */
@property(nonatomic) BOOL canCancelContentTouches;    // default is YES. if NO, then once we start tracking, we don't try to drag if the touch moves. this has no effect on presses


// override points for subclasses to control delivery of touch events to subviews of the scroll view
// called before touches are delivered to a subview of the scroll view. if it returns NO the touches will not be delivered to the subview
// this has no effect on presses
// default returns YES
/**
 作用：在UIScrollView的子类中重写该方法,用于返回是否将事件传递给对应的子视图,默认返回YES,
 注解：如果返回NO,该事件不会传递给对应的子视图
 */
- (BOOL)touchesShouldBegin:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event inContentView:(UIView *)view;

// called before scrolling begins if touches have already been delivered to a subview of the scroll view. if it returns NO the touches will continue to be delivered to the subview and scrolling will not occur
// not called if canCancelContentTouches is NO. default returns YES if view isn't a UIControl
// this has no effect on presses
/**
 作用：在UIScrollView的子类中重写该方法,用于返回是否取消已经传递给子视图的事件,默认当子视图是UIControl时返回NO,否则返回YES
 注解：该方法被调用的前提是canCancelContentTouches = YES
 */
- (BOOL)touchesShouldCancelInContentView:(UIView *)view;







/*
 the following properties and methods are for zooming. as the user tracks with two fingers, we adjust the offset and the scale of the content. When the gesture ends, you should update the content
 as necessary. Note that the gesture can end and a finger could still be down. While the gesture is in progress, we do not send any tracking calls to the subview.
 the delegate must implement both viewForZoomingInScrollView: and scrollViewDidEndZooming:withView:atScale: in order for zooming to work and the max/min zoom scale must be different
 note that we are not scaling the actual scroll view but the 'content view' returned by the delegate. the delegate must return a subview, not the scroll view itself, from viewForZoomingInScrollview:
 */
#pragma mark - ↑
#pragma mark - 缩放属性方法


/**
 作用：最小缩放比例,默认为1.0
 */
@property(nonatomic) CGFloat minimumZoomScale;     // default is 1.0

/**
 作用：最大缩放比例,默认为1.0(必须大于minimumZoomScale才能正常工作)
 */
@property(nonatomic) CGFloat maximumZoomScale;     // default is 1.0. must be > minimum zoom scale to enable zooming

/**
 作用：缩放比例,默认为1.0
 */
@property(nonatomic) CGFloat zoomScale NS_AVAILABLE_IOS(3_0);            // default is 1.0

/**
 作用：设置缩放比例
 */
- (void)setZoomScale:(CGFloat)scale animated:(BOOL)animated NS_AVAILABLE_IOS(3_0);

/**
 作用：缩放到指定区域
 */
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated NS_AVAILABLE_IOS(3_0);

/**
 作用：是否允许触底反弹,默认为YES
 */
@property(nonatomic) BOOL  bouncesZoom;          // default is YES. if set, user can go past min/max zoom while gesturing and the zoom will animate to the min/max value at gesture end

/**
 作用：返回是否正在缩放
 */
@property(nonatomic,readonly,getter=isZooming)       BOOL zooming;       // returns YES if user in zoom gesture

/**
 作用：返回是否正在触底反弹
 */
@property(nonatomic,readonly,getter=isZoomBouncing)  BOOL zoomBouncing;  // returns YES if we are in the middle of zooming back to the min/max value








// Use these accessors to configure the scroll view's built-in gesture recognizers.
// Do not change the gestures' delegates or override the getters for these properties.
#pragma mark - ↑
#pragma mark - 内置手势识别器

// Change `panGestureRecognizer.allowedTouchTypes` to limit scrolling to a particular set of touch types.
/**
 作用：拖动手势
 */
@property(nonatomic, readonly) UIPanGestureRecognizer *panGestureRecognizer NS_AVAILABLE_IOS(5_0);

// `pinchGestureRecognizer` will return nil when zooming is disabled.
/**
 作用：捏合手势
 */
@property(nullable, nonatomic, readonly) UIPinchGestureRecognizer *pinchGestureRecognizer NS_AVAILABLE_IOS(5_0);

// `directionalPressGestureRecognizer` is disabled by default, but can be enabled to perform scrolling in response to up / down / left / right arrow button presses directly, instead of scrolling indirectly in response to focus updates.
/**
 作用：定向手势识别器
 */
@property(nonatomic, readonly) UIGestureRecognizer *directionalPressGestureRecognizer API_DEPRECATED("Configuring the panGestureRecognizer for indirect scrolling automatically supports directional presses now, so this property is no longer useful.", tvos(9.0, 11.0));






#pragma mark - ↑
#pragma mark - 键盘的消失模式
/**
 作用：设置隐藏键盘模式,默认为UIScrollViewKeyboardDismissModeNone(不隐藏键盘),
      ModeOnDrag(当拖拽scrollView时隐藏键盘)、
      ModeInteractive(当拖拽键盘上方时隐藏键盘)
 */
@property(nonatomic) UIScrollViewKeyboardDismissMode keyboardDismissMode NS_AVAILABLE_IOS(7_0); // default is UIScrollViewKeyboardDismissModeNone

@property (nonatomic, strong, nullable) UIRefreshControl *refreshControl NS_AVAILABLE_IOS(10_0) __TVOS_PROHIBITED;

@end





#pragma mark - ↑
#pragma mark - 滑动代理方法

@protocol UIScrollViewDelegate<NSObject>

@optional (可选)

/**
 作用：只要scrollView滚动就会调用该方法
 注解：
    由于该方法在视图滚动中一直调用，所以不要在这里做耗时的计算
 */
- (void)scrollViewDidScroll:(UIScrollView *)scrollView;                                               // any offset changes

// called on start of dragging (may require some time and or distance to move)
/**
 作用：手指滑动: 将要开始拖动调用, 停止定时器
 注解：
    该方法可能需要先滑动一段时间或距离才会被调用
 */
- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView;

// called on finger up if the user dragged. velocity is in points/millisecond. targetContentOffset may be changed to adjust where the scroll view comes to rest
/**
 作用：用户即将停止拖拽时调用
 注解：
    应用程序可以通过修改targetContentOffset参数的值来调整内容视图content view停止的位置
 */
- (void)scrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset NS_AVAILABLE_IOS(5_0);

// called on finger up if the user dragged. decelerate is true if it will continue moving afterwards
/**
 作用：用户已经停止拖拽时调用
 注解：
    如果内容视图content view在停止拖拽后但由于惯性会继续滚动，减速,则decelerate参数为YES
 */
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

/**
 作用：将要开始减速时调用
 注解：
    仅当停止拖拽后继续移动时才会被调用
 */
- (void)scrollViewWillBeginDecelerating:(UIScrollView *)scrollView;   // called on finger up as we are moving

/**
 作用：手指滑动: 减速完成调用, 开启定时器
 注解：
    只要设置了scrollView的分页显示，当手动(使用手指)滚动结束后，该代理方法会被调用
 */
- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView;      // called when scroll view grinds to a halt

/**
 作用：当-setContentOffset:animated:/-scrollRectVisible:animated:方法动画结束时调用(仅当animated设置为YES时才调用)
 */
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView; // called when setContentOffset/scrollRectVisible:animated: finishes. not called if not animating

/**
 作用：返回是否允许点击状态栏让scrollView滑动到顶部,如果未实现该方法,则默认为YES(仅当scrollsToTop属性为YES时才调用)
 */
- (BOOL)scrollViewShouldScrollToTop:(UIScrollView *)scrollView;   // return a yes if you want to scroll to the top. if not defined, assumes YES

/**
 作用：当scrollView已经滑动到顶部时调用(仅当点击状态栏让scrollView滑动到顶部才调用)
 */
- (void)scrollViewDidScrollToTop:(UIScrollView *)scrollView;      // called when scrolling animation finished. may be called immediately if already at top







#pragma mark ------------------
#pragma mark - 缩放代理方法

/**
 作用：只要scrollView缩放就会调用该方法
 */
- (void)scrollViewDidZoom:(UIScrollView *)scrollView NS_AVAILABLE_IOS(3_2); // any zoom scale changes

/**
 作用：指定在scollView上哪一个视图被缩放
 */
- (nullable UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView;     // return a view that will be scaled. if delegate returns nil, nothing happens

/**
 作用：将要开始缩放时调用
 */
- (void)scrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view NS_AVAILABLE_IOS(3_2); // called before the scroll view begins zooming its content

/**
 作用：已经结束缩放时调用
 */
- (void)scrollViewDidEndZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view atScale:(CGFloat)scale; // scale between minimum and maximum. called after any 'bounce' animations












#pragma mark - ↑
#pragma mark - ios(11.0)


typedef NS_ENUM(NSInteger, UIScrollViewIndexDisplayMode) {
    UIScrollViewIndexDisplayModeAutomatic,    // the index will show or hide automatically as needed
    UIScrollViewIndexDisplayModeAlwaysHidden, // the index will never be displayed
} API_AVAILABLE(tvos(10.2));


/**
 注解：ios11 之前，不想让scrollView偏移64px，设置automaticallyAdjustsScrollViewInsets=NO就可以了。
      ios11以后就废弃了，使用scrollView的属性contentInsetAdjustmentBehavior来防止偏移
 */
typedef NS_ENUM(NSInteger, UIScrollViewContentInsetAdjustmentBehavior) {
    UIScrollViewContentInsetAdjustmentAutomatic,// 自动计算内边距. // Similar to .scrollableAxes, but for backward compatibility will also adjust the top & bottom contentInset when the scroll view is owned by a view controller with automaticallyAdjustsScrollViewInsets = YES inside a navigation controller, regardless of whether the scroll view is scrollable
    UIScrollViewContentInsetAdjustmentScrollableAxes,// 自动计算内边距. // Edges for scrollable axes are adjusted (i.e., contentSize.width/height > frame.size.width/height or alwaysBounceHorizontal/Vertical = YES)
    UIScrollViewContentInsetAdjustmentNever,// 不计算内边距 // contentInset is not adjusted
    UIScrollViewContentInsetAdjustmentAlways,// 根据safeAreaInsets 计算内边距 // contentInset is always adjusted by the scroll view's safeAreaInsets
} API_AVAILABLE(ios(11.0),tvos(11.0));



@property(nonatomic)         UIScrollViewIndexDisplayMode indexDisplayMode API_AVAILABLE(tvos(10.2));



/* When contentInsetAdjustmentBehavior allows, UIScrollView may incorporate
 its safeAreaInsets into the adjustedContentInset.
 */
@property(nonatomic, readonly) UIEdgeInsets adjustedContentInset API_AVAILABLE(ios(11.0),tvos(11.0));

/* Also see -scrollViewDidChangeAdjustedContentInset: in the UIScrollViewDelegate protocol.
 */
- (void)adjustedContentInsetDidChange API_AVAILABLE(ios(11.0),tvos(11.0)) NS_REQUIRES_SUPER;

/* Configure the behavior of adjustedContentInset.
 Default is UIScrollViewContentInsetAdjustmentAutomatic.
 */
@property(nonatomic) UIScrollViewContentInsetAdjustmentBehavior contentInsetAdjustmentBehavior API_AVAILABLE(ios(11.0),tvos(11.0));

/* contentLayoutGuide anchors (e.g., contentLayoutGuide.centerXAnchor, etc.) refer to
 the untranslated content area of the scroll view.
 */
@property(nonatomic,readonly,strong) UILayoutGuide *contentLayoutGuide API_AVAILABLE(ios(11.0),tvos(11.0));

/* frameLayoutGuide anchors (e.g., frameLayoutGuide.centerXAnchor) refer to
 the untransformed frame of the scroll view.
 */
@property(nonatomic,readonly,strong) UILayoutGuide *frameLayoutGuide API_AVAILABLE(ios(11.0),tvos(11.0));




/* Also see -[UIScrollView adjustedContentInsetDidChange]
 */
- (void)scrollViewDidChangeAdjustedContentInset:(UIScrollView *)scrollView API_AVAILABLE(ios(11.0), tvos(11.0));









@end



