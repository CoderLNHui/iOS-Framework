/*
 * File:  CLLocationManager.h 
 *
 * (c) 2008-2010
 * Framework: CoreLocation
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */


#import <Foundation/Foundation.h>
#import <CoreLocation/CLAvailability.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLRegion.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  CLDeviceOrientation
 *
 *  Discussion:
 *      Specifies a physical device orientation, equivalent to UIDeviceOrientation.
 *
 */
typedef NS_ENUM(int, CLDeviceOrientation) {
    CLDeviceOrientationUnknown = 0,
    CLDeviceOrientationPortrait,
    CLDeviceOrientationPortraitUpsideDown,
    CLDeviceOrientationLandscapeLeft,
    CLDeviceOrientationLandscapeRight,
    CLDeviceOrientationFaceUp,
    CLDeviceOrientationFaceDown
};

/*
 *  CLAuthorizationStatus
 *
 *  Discussion:
 *      Represents the current authorization state of the application.
 *
 */
typedef NS_ENUM(int, CLAuthorizationStatus) {
    // User has not yet made a choice with regards to this application
    kCLAuthorizationStatusNotDetermined = 0, /* 用户尚未决定是否启用定位服务 */
    
    // This application is not authorized to use location services.  Due
    // to active restrictions on location services, the user cannot change
    // this status, and may not have personally denied authorization
    kCLAuthorizationStatusRestricted, /* 没有获得用户授权 */
    
    // User has explicitly denied authorization for this application, or
    // location services are disabled in Settings.
    kCLAuthorizationStatusDenied, /* 用户禁止使用定位或者定位服务处于关闭状态 */
    
    // User has granted authorization to use their location at any time,
    // including monitoring for regions, visits, or significant location changes.
    //
    // This value should be used on iOS, tvOS and watchOS.  It is available on
    // MacOS, but kCLAuthorizationStatusAuthorized is synonymous and preferred.
    kCLAuthorizationStatusAuthorizedAlways NS_ENUM_AVAILABLE(10_12, 8_0), /* 前台、后台定位授权 */
    
    // User has granted authorization to use their location only when your app
    // is visible to them (it will be made visible to them if you continue to
    // receive location updates while in the background).  Authorization to use
    // launch APIs has not been granted.
    //
    // This value is not available on MacOS.  It should be used on iOS, tvOS and
    // watchOS.
    kCLAuthorizationStatusAuthorizedWhenInUse NS_ENUM_AVAILABLE(NA, 8_0), /* 前台定位授权 */
    
    // User has authorized this application to use location services.
    //
    // This value is deprecated or prohibited on iOS, tvOS and watchOS.
    // It should be used on MacOS.
    kCLAuthorizationStatusAuthorized NS_ENUM_DEPRECATED(10_6, NA, 2_0, 8_0, "Use kCLAuthorizationStatusAuthorizedAlways") __TVOS_PROHIBITED __WATCHOS_PROHIBITED = kCLAuthorizationStatusAuthorizedAlways
};

/*
 *	CLActivityType
 *
 *  Discussion:
 *		Enumerates the different possible activity types. This currently
 *		affects behavior such as the determination of when location updates
 *		may be automatically paused.
 */
typedef NS_ENUM(NSInteger, CLActivityType) {
    CLActivityTypeOther = 1,
    CLActivityTypeAutomotiveNavigation,	// for automotive navigation
    CLActivityTypeFitness,				// includes any pedestrian activities
    CLActivityTypeOtherNavigation 		// for other navigation cases (excluding pedestrian navigation), e.g. navigation for boats, trains, or planes
};

@class CLLocation;
@class CLHeading;
@class CLBeaconRegion;
@protocol CLLocationManagerDelegate;

/*
 *  CLLocationManager
 *
 *  Discussion:
 *    The CLLocationManager object is your entry point to the location service.
 */
NS_CLASS_AVAILABLE(10_6, 2_0)
@interface CLLocationManager : NSObject
{
@private
    id _internal;
}

/*
 *  locationServicesEnabled 【返回用户是否启用定位服务】
 *
 *  Discussion:
 *      Determines whether the user has location services enabled.
 *      If NO, and you proceed to call other CoreLocation API, user will be prompted with the warning
 *      dialog. You may want to check this property and use location services only when explicitly requested by the user.
 */
+ (BOOL)locationServicesEnabled __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

/*
 *  headingAvailable
 *
 *  Discussion:
 *      Returns YES if the device supports the heading service, otherwise NO.
 */
+ (BOOL)headingAvailable __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  significantLocationChangeMonitoringAvailable
 *
 *  Discussion:
 *      Returns YES if the device supports significant location change monitoring, otherwise NO.
 */
+ (BOOL)significantLocationChangeMonitoringAvailable __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  isMonitoringAvailableForClass:
 *
 *  Discussion:
 *      Determines whether the device supports monitoring for the specified type of region.
 *      If NO, all attempts to monitor the specified type of region will fail.
 */
+ (BOOL)isMonitoringAvailableForClass:(Class)regionClass __OSX_AVAILABLE_STARTING(__MAC_10_10,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  regionMonitoringAvailable
 *
 *  Discussion:
 *      Deprecated. Use +isMonitoringAvailableForClass: instead.
 */
+ (BOOL)regionMonitoringAvailable __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_8,__MAC_10_10,__IPHONE_4_0,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  regionMonitoringEnabled
 *
 *  Discussion:
 *      Deprecated. Use +isMonitoringAvailableForClass: and +authorizationStatus instead.
 */
+ (BOOL)regionMonitoringEnabled __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_8, __MAC_10_10,__IPHONE_4_0, __IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  isRangingAvailable
 *
 *  Discussion:
 *      Determines whether the device supports ranging.
 *      If NO, all attempts to range beacons will fail.
 */
+ (BOOL)isRangingAvailable __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  authorizationStatus 【定位服务授权状态，返回枚举类型】
 *
 *  Discussion:
 *      Returns the current authorization status of the calling application.
 */
+ (CLAuthorizationStatus)authorizationStatus __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_2);

@property(assign, nonatomic, nullable) id<CLLocationManagerDelegate> delegate;

/*
 *  locationServicesEnabled
 *
 *  Discussion:
 *      Deprecated. Use +locationServicesEnabled instead.
 */
@property(readonly, nonatomic) BOOL locationServicesEnabled __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_2_0,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  purpose
 *
 *  Discussion:
 *      Allows the application to specify what location will be used for in their app. This
 *      will be displayed along with the standard Location permissions dialogs. This property will need to be
 *      set prior to calling startUpdatingLocation.
 *
 *      Deprecated.  Set the purpose string in Info.plist using key NSLocationUsageDescription.
 */
@property(copy, nonatomic, nullable) NSString *purpose __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_7, __MAC_NA, __IPHONE_3_2, __IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *	activityType
 *
 *  Discussion:
 *		Specifies the type of user activity. Currently affects behavior such as
 *		the determination of when location updates may be automatically paused.
 *		By default, CLActivityTypeOther is used.
 */
@property(assign, nonatomic) CLActivityType activityType __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;


/*
 *  distanceFilter
 * 【位置信息更新最小距离 distanceFilter：浮点数，默认为kCLDistanceFilterNone，表示不进行距离限制】
 *
 *  Discussion:
 *      Specifies the minimum update distance in meters. Client will not be notified of movements of less
 *      than the stated value, unless the accuracy has improved. Pass in kCLDistanceFilterNone to be
 *      notified of all movements. By default, kCLDistanceFilterNone is used.
 */
@property(assign, nonatomic) CLLocationDistance distanceFilter;

/*
 *  desiredAccuracy
 *
 *  Discussion:
 *      The desired location accuracy. The location service will try its best to achieve
 *      your desired accuracy. However, it is not guaranteed. To optimize
 *      power performance, be sure to specify an appropriate accuracy for your usage scenario (eg,
 *      use a large accuracy value when only a coarse location is needed). Use kCLLocationAccuracyBest to
 *      achieve the best possible accuracy. Use kCLLocationAccuracyBestForNavigation for navigation.
 *      The default value varies by platform.
 */
@property(assign, nonatomic) CLLocationAccuracy desiredAccuracy;

/*
 *	pausesLocationUpdatesAutomatically
 *
 *  Discussion:
 *		Specifies that location updates may automatically be paused when possible.
 *		By default, this is YES for applications linked against iOS 6.0 or later.
 */
@property(assign, nonatomic) BOOL pausesLocationUpdatesAutomatically __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  allowsBackgroundLocationUpdates
 *
 *  Discussion:
 *      By default, this is NO for applications linked against iOS 9.0 or later,
 *      regardless of minimum deployment target.
 *
 *      With UIBackgroundModes set to include "location" in Info.plist, you must
 *      also set this property to YES at runtime whenever calling
 *      -startUpdatingLocation with the intent to continue in the background.
 *
 *      Setting this property to YES when UIBackgroundModes does not include
 *      "location" is a fatal error.
 *
 *      Resetting this property to NO is equivalent to omitting "location" from
 *      the UIBackgroundModes value.  Access to location is still permitted
 *      whenever the application is running (ie not suspended), and has
 *      sufficient authorization (ie it has WhenInUse authorization and is in
 *      use, or it has Always authorization).  However, the app will still be
 *      subject to the usual task suspension rules.
 *
 *      See -requestWhenInUseAuthorization and -requestAlwaysAuthorization for
 *      more details on possible authorization values.
 */
@property(assign, nonatomic) BOOL allowsBackgroundLocationUpdates __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_9_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  location
 *
 *  Discussion:
 *      The last location received. Will be nil until a location has been received.
 */
@property(readonly, nonatomic, copy, nullable) CLLocation *location;

/*
 *  headingAvailable
 *
 *  Discussion:
 *      Deprecated. Use +headingAvailable instead.
 */
@property(readonly, nonatomic) BOOL headingAvailable __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_3_0,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  headingFilter
 *
 *  Discussion:
 *      Specifies the minimum amount of change in degrees needed for a heading service update. Client will not
 *      be notified of updates less than the stated filter value. Pass in kCLHeadingFilterNone to be
 *      notified of all updates. By default, 1 degree is used.
 */
@property(assign, nonatomic) CLLocationDegrees headingFilter __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  headingOrientation
 *
 *  Discussion:
 *      Specifies a physical device orientation from which heading calculation should be referenced. By default,
 *      CLDeviceOrientationPortrait is used. CLDeviceOrientationUnknown, CLDeviceOrientationFaceUp, and
 *      CLDeviceOrientationFaceDown are ignored.
 *
 */
@property(assign, nonatomic) CLDeviceOrientation headingOrientation __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  heading
 *
 *  Discussion:
 *      Returns the latest heading update received, or nil if none is available.
 */
@property(readonly, nonatomic, copy, nullable) CLHeading *heading __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  maximumRegionMonitoringDistance【通过一个信标来监控：设置最大监控距离】
 *
 *  Discussion:
 *       the maximum region size, in terms of a distance from a central point, that the framework can support.
 *       Attempts to register a region larger than this will generate a kCLErrorRegionMonitoringFailure.
 *       This value may vary based on the hardware features of the device, as well as on dynamically changing resource constraints.
 */
@property (readonly, nonatomic) CLLocationDistance maximumRegionMonitoringDistance __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  monitoredRegions
 *
 *  Discussion:
 *       Retrieve a set of objects for the regions that are currently being monitored.  If any location manager
 *       has been instructed to monitor a region, during this or previous launches of your application, it will
 *       be present in this set.
 */
@property (readonly, nonatomic, copy) NSSet<__kindof CLRegion *> *monitoredRegions __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  rangedRegions
 *
 *  Discussion:
 *       Retrieve a set of objects representing the regions for which this location manager is actively providing ranging.
 */
@property (readonly, nonatomic, copy) NSSet<__kindof CLRegion *> *rangedRegions __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;


#pragma mark - 授权请求
/*
 *  requestWhenInUseAuthorization 【请求获得应用前台定位授权】
 *
 *  Discussion:
 *      When +authorizationStatus == kCLAuthorizationStatusNotDetermined,
 *      calling this method will trigger a prompt to request "when-in-use"
 *      authorization from the user.  If possible, perform this call in response
 *      to direct user request for a location-based service so that the reason
 *      for the prompt will be clear.  Any authorization change as a result of
 *      the prompt will be reflected via the usual delegate callback:
 *      -locationManager:didChangeAuthorizationStatus:.
 *
 *      If received, "when-in-use" authorization grants access to the user's
 *      location via -startUpdatingLocation/-startRangingBeaconsInRegion while
 *      in the foreground.  If updates have been started when going to the
 *      background, then a status bar banner will be displayed to maintain
 *      visibility to the user, and updates will continue until stopped
 *      normally, or the app is killed by the user.
 *
 *      "When-in-use" authorization does NOT enable monitoring API on regions,
 *      significant location changes, or visits, and -startUpdatingLocation will
 *      not succeed if invoked from the background.
 *
 *      When +authorizationStatus != kCLAuthorizationStatusNotDetermined, (ie
 *      generally after the first call) this method will do nothing.
 *
 *      If the NSLocationWhenInUseUsageDescription key is not specified in your
 *      Info.plist, this method will do nothing, as your app will be assumed not
 *      to support WhenInUse authorization.
 */
- (void)requestWhenInUseAuthorization __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0);

/*
 *  requestAlwaysAuthorization 【请求获得应用前后台定位授权】
 *
 *  Discussion:
 *      When +authorizationStatus == kCLAuthorizationStatusNotDetermined,
 *      calling this method will trigger a prompt to request "always"
 *      authorization from the user.  If possible, perform this call in response
 *      to direct user request for a location-based service so that the reason
 *      for the prompt will be clear.  Any authorization change as a result of
 *      the prompt will be reflected via the usual delegate callback:
 *      -locationManager:didChangeAuthorizationStatus:.
 *
 *      If received, "always" authorization grants access to the user's
 *      location via any CLLocationManager API, and grants access to
 *      launch-capable monitoring API such as geofencing/region monitoring,
 *      significante location visits, etc.  Even if killed by the user, launch
 *      events triggered by monitored regions or visit patterns will cause a
 *      relaunch.
 *
 *      "Always" authorization presents a significant risk to user privacy, and
 *      as such requesting it is discouraged unless background launch behavior
 *      is genuinely required.  Do not call +requestAlwaysAuthorization unless
 *      you think users will thank you for doing so.
 *
 *      When +authorizationStatus != kCLAuthorizationStatusNotDetermined, (ie
 *      generally after the first call) this method will do nothing.
 *
 *      If the NSLocationAlwaysUsageDescription key is not specified in your
 *      Info.plist, this method will do nothing, as your app will be assumed not
 *      to support Always authorization.
 */
- (void)requestAlwaysAuthorization __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_8_0) __TVOS_PROHIBITED;


#pragma mark - 定位追踪
/*
 *  startUpdatingLocation 【开始定位追踪】
 *
 *  Discussion:
 *      Start updating locations.
 */
- (void)startUpdatingLocation __TVOS_PROHIBITED;

/*
 *  stopUpdatingLocation 【停止定位追踪】
 *
 *  Discussion:
 *      Stop updating locations.
 */
- (void)stopUpdatingLocation;

/*
 *  requestLocation 【单次定位请求】
 *
 *  按照精确度从低到高，逐个进行定位。如果在有效时间内, 定位到, 精确度最高的位置, 直接通过代理告诉外界；
 *  如果当前还没有定位到精确度最高的位置, 但是已经超时, 这时, 就会把当前精确度对应的位置信息, 通过代理告诉外界
 *  如果定位失败, 就会调用定位失败的代理方法
 *  不能与 startUpdatingLocation 一起使用
 *
 *  Discussion:
 *      Request a single location update.
 *
 *      The service will attempt to determine location with accuracy according
 *      to the desiredAccuracy property.  The location update will be delivered
 *      via the standard delegate callback, i.e. locationManager:didUpdateLocations:
 *
 *      If the best available location has lower accuracy, then it will be
 *      delivered via the standard delegate callback after timeout.
 *
 *      If no location can be determined, the locationManager:didFailWithError:
 *      delegate callback will be delivered with error location unknown.
 *
 *      There can only be one outstanding location request and this method can
 *      not be used concurrently with startUpdatingLocation or
 *      allowDeferredLocationUpdates.  Calling either of those methods will
 *      immediately cancel the location request.  The method
 *      stopUpdatingLocation can be used to explicitly cancel the request.
 */
- (void)requestLocation __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_9_0);



#pragma mark - 导航追踪
/*
 *  startUpdatingHeading 【开始导航方向追踪】
 *
 *  Discussion:
 *      Start updating heading.
 */
- (void)startUpdatingHeading __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  stopUpdatingHeading 【停止导航方向追踪】
 *
 *  Discussion:
 *      Stop updating heading.
 */
- (void)stopUpdatingHeading __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  dismissHeadingCalibrationDisplay
 *
 *  Discussion:
 *      Dismiss the heading calibration immediately.
 */
- (void)dismissHeadingCalibrationDisplay __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_3_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  startMonitoringSignificantLocationChanges【位置发生重大变化时更新】
 *
 *  Discussion:
 *      Start monitoring significant location changes.  The behavior of this service is not affected by the desiredAccuracy
 *      or distanceFilter properties.  Locations will be delivered through the same delegate callback as the standard
 *      location service.
 *
 */
- (void)startMonitoringSignificantLocationChanges __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  stopMonitoringSignificantLocationChanges【位置发生重大变化时更新】
 *
 *  Discussion:
 *      Stop monitoring significant location changes.
 *
 */
- (void)stopMonitoringSignificantLocationChanges __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;




/*
 *  startMonitoringForRegion:desiredAccuracy:
 *
 *  Discussion:
 *      Start monitoring the specified region.  desiredAccuracy represents the distance past the border of the region at
 *      which the application would like to be notified that the region border has been crossed.  This is useful to prevent
 *      repeated notifications when the user is on the border of the region.  This value will be honored on a best-effort basis,
 *      and may not be respected if desiredAccuracy is large with respect to the size of the region, or if the device is not
 *      capable of providing the precision desired.
 *
 *      If a region of the same type with the same identifier is already being monitored for this application, it will be
 *      removed from monitoring.
 *
 *      This is done asynchronously and may not be immediately reflected in monitoredRegions.
 */
- (void)startMonitoringForRegion:(CLRegion *)region
                 desiredAccuracy:(CLLocationAccuracy)accuracy __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA, __MAC_NA,__IPHONE_4_0, __IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;


#pragma mark - 区域定位追踪
/*
 *  stopMonitoringForRegion: 【停止对某个区域进行定位追踪】
 *
 *  Discussion:
 *      Stop monitoring the specified region.  It is valid to call stopMonitoringForRegion: for a region that was registered
 *      for monitoring with a different location manager object, during this or previous launches of your application.
 *
 *      This is done asynchronously and may not be immediately reflected in monitoredRegions.
 */
- (void)stopMonitoringForRegion:(CLRegion *)region __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_4_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  startMonitoringForRegion: 【开始对某个区域进行定位追踪】
 *
 *  Discussion:
 *      Start monitoring the specified region.
 *
 *      If a region of the same type with the same identifier is already being monitored for this application,
 *      it will be removed from monitoring. For circular regions, the region monitoring service will prioritize
 *      regions by their size, favoring smaller regions over larger regions.
 *
 *      This is done asynchronously and may not be immediately reflected in monitoredRegions.
 */
- (void)startMonitoringForRegion:(CLRegion *)region __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_5_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  requestStateForRegion:
 *
 *  Discussion:
 *      Asynchronously retrieve the cached state of the specified region. The state is returned to the delegate via
 *      locationManager:didDetermineState:forRegion:.
 */
- (void)requestStateForRegion:(CLRegion *)region __OSX_AVAILABLE_STARTING(__MAC_10_10,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  startRangingBeaconsInRegion:【设置信标】
 *
 *  Discussion:
 *      Start calculating ranges for beacons in the specified region.
 */
- (void)startRangingBeaconsInRegion:(CLBeaconRegion *)region __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  stopRangingBeaconsInRegion:
 *
 *  Discussion:
 *      Stop calculating ranges for the specified region.
 */
- (void)stopRangingBeaconsInRegion:(CLBeaconRegion *)region __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *	allowDeferredLocationUpdatesUntilTraveled:timeout:
 *
 *	Discussion:
 *		Indicate that the application will allow the location manager to defer
 *		location updates until an exit criterion is met. This may allow the
 *		device to enter a low-power state in which updates are held for later
 *		delivery. Once an exit condition is met, the location manager will
 *		continue normal updates until this method is invoked again.
 *
 *		Exit conditions, distance and timeout, can be specified using the constants
 *		CLLocationDistanceMax and CLTimeIntervalMax, respectively, if you are
 *		trying to achieve an unlimited distance or timeout.
 *
 *		The CLLocationManagerDelegate will continue to receive normal updates as
 *		long as the application remains in the foreground. While the process is
 *		in the background, the device may be able to enter a low-power state for
 *		portions of the specified distance and time interval. While in this
 *		state, locations will be coalesced for later delivery.
 *
 *		Location updates will be deferred as much as is reasonable to save
 *		power. If another process is using location, the device may not enter a
 *		low-power state and instead updates will continue normally. Deferred
 *		updates may be interspersed with normal updates if the device exits and
 *		re-enters a low-power state.
 *
 *		All location updates, including deferred updates, will be delivered via
 *		the delegate callback locationManager:didUpdateLocations:
 *
 *		When deferred updates have ended, the manager will invoke the delegate
 *		callback locationManagerDidFinishDeferredUpdates:withError:. An error
 *		will be returned if the manager will not defer updates and the exit
 *		criteria have not been met.
 */
- (void)allowDeferredLocationUpdatesUntilTraveled:(CLLocationDistance)distance
                                          timeout:(NSTimeInterval)timeout __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *	disallowDeferredLocationUpdates
 *
 *	Discussion:
 *		Disallow deferred location updates if previously enabled. Any outstanding
 *		updates will be sent and regular location updates will resume.
 */
- (void)disallowDeferredLocationUpdates __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  deferredLocationUpdatesAvailable
 *
 *  Discussion:
 *      Returns YES if the device supports deferred location updates, otherwise NO.
 */
+ (BOOL)deferredLocationUpdatesAvailable __OSX_AVAILABLE_STARTING(__MAC_10_9,__IPHONE_6_0) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

@end

#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END


