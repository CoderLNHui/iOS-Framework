/*
 * File:  AVPlayerViewController.h 
 *
 * © 2014-2017
 * Framework: AVFoundation
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */

#import <AVKit/AVKit.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AVPlayerViewControllerDelegate;

/*!
 @class        AVPlayerViewController
 @abstract    AVPlayerViewController is a subclass of UIViewController that can be used to display the visual content of an AVPlayer object and the standard playback controls.
 */

API_AVAILABLE(ios(8.0))
@interface AVPlayerViewController : UIViewController

#pragma mark ------------------
#pragma mark -【属性】


/*!
【AVPlayerViewController内部封装的播放器】
 @property    player
 @abstract    The player from which to source the media content for the view controller.
 */
@property (nonatomic, strong, nullable) AVPlayer *player;

/*!
【是否显示媒体播放组件,默认为YES】
 @property    showsPlaybackControls
 @abstract    Whether or not the receiver shows playback controls. Default is YES.
 @discussion    Clients can set this property to NO when they don't want to have any playback controls on top of the visual content (e.g. for a game splash screen).
 */
@property (nonatomic) BOOL showsPlaybackControls;

/*!
【拉伸模式,默认为AVLayerVideoGravityResizeAspect】
 @property    videoGravity
 @abstract    A string defining how the video is displayed within an AVPlayerLayer bounds rect.
 @discussion    Options are AVLayerVideoGravityResizeAspect 不进行比例缩放 以宽高中长的一边充满为基准,
                AVLayerVideoGravityResizeAspectFill 不进行比例缩放 以宽高中短的一边充满为基准
                AVLayerVideoGravityResize. 进行缩放充满屏幕
                AVLayerVideoGravityResizeAspect is default.
 See <AVFoundation/AVAnimation.h> for a description of these options.
 */
@property (nonatomic, copy) NSString *videoGravity;

/*!
【是否准备好播放】
 @property    readyForDisplay
 @abstract    Boolean indicating that the first video frame has been made ready for display for the current item of the associated AVPlayer.
 */
@property (nonatomic, readonly, getter = isReadyForDisplay) BOOL readyForDisplay;

/*!
【播放视频界面的尺寸】
 @property    videoBounds
 @abstract    The current size and position of the video image as displayed within the receiver's view's bounds.
 */
@property (nonatomic, readonly) CGRect videoBounds;

/*!
【视频播放器的视图 自定义的控件可以添加在其上】
 @property    contentOverlayView
 @abstract    Use the content overlay view to add additional custom views between the video content and the controls.
 */
@property (nonatomic, readonly, nullable) UIView *contentOverlayView;

/*!
【接收方是否允许画中画回放。默认YES。9.0之后可以使用】
 @property    allowsPictureInPicturePlayback
 @abstract    Whether or not the receiver allows Picture in Picture playback. Default is YES.
 */
@property (nonatomic) BOOL allowsPictureInPicturePlayback API_AVAILABLE(ios(9.0));

/*!
【是否更新信息中心,10.0之后可以使用】
 @property    updatesNowPlayingInfoCenter
 @abstract    Whether or not the now playing info center should be updated. Default is YES.
 */
@property (nonatomic) BOOL updatesNowPlayingInfoCenter API_AVAILABLE(ios(10.0));

/*!
【】
 @property    entersFullScreenWhenPlaybackBegins
 @abstract    Whether or not the receiver automatically enters full screen when the play button is tapped. Default is NO.
 @discussion    If YES, the receiver will show a user interface tailored to this behavior.
 */
@property (nonatomic) BOOL entersFullScreenWhenPlaybackBegins API_AVAILABLE(ios(11.0));

/*!
 @property    exitsFullScreenWhenPlaybackEnds
 @abstract    Whether or not the receiver automatically exits full screen when playback ends. Default is NO.
 @discussion    If multiple player items have been enqueued, the receiver exits fullscreen once no more items are remaining in the queue.
 */
@property (nonatomic) BOOL exitsFullScreenWhenPlaybackEnds API_AVAILABLE(ios(11.0));

/*!
 @property    delegate
 @abstract    The receiver's delegate.
 */
@property (nonatomic, weak, nullable) id <AVPlayerViewControllerDelegate> delegate API_AVAILABLE(ios(9.0));

@end


/*!
 @protocol    AVPlayerViewControllerDelegate
 @abstract    A protocol for delegates of AVPlayerViewController.
 */
#pragma mark ------------------
#pragma mark -【代理】

@protocol AVPlayerViewControllerDelegate <NSObject>
@optional

/*!
【将要开始画中画时调用的方法】
 @method        playerViewControllerWillStartPictureInPicture:
 @param        playerViewController
 The player view controller.
 @abstract    Delegate can implement this method to be notified when Picture in Picture will start.
 */
- (void)playerViewControllerWillStartPictureInPicture:(AVPlayerViewController *)playerViewController;

/*!
【已经开始画中画时调用的方法】
 @method        playerViewControllerDidStartPictureInPicture:
 @param        playerViewController
 The player view controller.
 @abstract    Delegate can implement this method to be notified when Picture in Picture did start.
 */
- (void)playerViewControllerDidStartPictureInPicture:(AVPlayerViewController *)playerViewController;

/*!
【开始画中画失败调用的方法】
 @method        playerViewController:failedToStartPictureInPictureWithError:
 @param        playerViewController
 The player view controller.
 @param        error
 An error describing why it failed.
 @abstract    Delegate can implement this method to be notified when Picture in Picture failed to start.
 */
- (void)playerViewController:(AVPlayerViewController *)playerViewController failedToStartPictureInPictureWithError:(NSError *)error;

/*!
【将要停止画中画时调用的方法】
 @method        playerViewControllerWillStopPictureInPicture:
 @param        playerViewController
 The player view controller.
 @abstract    Delegate can implement this method to be notified when Picture in Picture will stop.
 */
- (void)playerViewControllerWillStopPictureInPicture:(AVPlayerViewController *)playerViewController;

/*!
【已经停止画中画时调用的方法】
 @method        playerViewControllerDidStopPictureInPicture:
 @param        playerViewController
 The player view controller.
 @abstract    Delegate can implement this method to be notified when Picture in Picture did stop.
 */
- (void)playerViewControllerDidStopPictureInPicture:(AVPlayerViewController *)playerViewController;

/*!
【是否在开始画中画时自动将当前的播放界面dismiss掉 返回YES则自动dismiss 返回NO则不会自动dismiss】
 @method        playerViewControllerShouldAutomaticallyDismissAtPictureInPictureStart:
 @param        playerViewController
 The player view controller.
 @abstract    Delegate can implement this method and return NO to prevent player view controller from automatically being dismissed when Picture in Picture starts.
 */
- (BOOL)playerViewControllerShouldAutomaticallyDismissAtPictureInPictureStart:(AVPlayerViewController *)playerViewController;

/*!
【用户点击还原按钮 从画中画模式还原回app内嵌模式时调用的方法】
 @method        playerViewController:restoreUserInterfaceForPictureInPictureStopWithCompletionHandler:
 @param        playerViewController
 The player view controller.
 @param        completionHandler
 The completion handler the delegate needs to call after restore.
 @abstract    Delegate can implement this method to restore the user interface before Picture in Picture stops.
 */
- (void)playerViewController:(AVPlayerViewController *)playerViewController restoreUserInterfaceForPictureInPictureStopWithCompletionHandler:(void (^)(BOOL restored))completionHandler;

@end

#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END


