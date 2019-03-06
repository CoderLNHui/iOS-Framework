/*
 * MKMapView.h
 *
 * (c) 2009-2014
 * MapKit
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */


#import <MapKit/MKAnnotationView.h>
#import <MapKit/MKFoundation.h>
#import <MapKit/MKGeometry.h>
#import <MapKit/MKTypes.h>
#import <MapKit/MKOverlay.h>
#import <MapKit/MKOverlayRenderer.h>
#if TARGET_OS_IPHONE
#import <MapKit/MKOverlayView.h>
#endif

@class MKUserLocation;
@class MKMapCamera;

@protocol MKMapViewDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 【用户跟踪类型：】
 */
typedef NS_ENUM(NSInteger, MKUserTrackingMode) {
    MKUserTrackingModeNone = 0, 【不跟踪】// the user's location is not followed
    MKUserTrackingModeFollow, 【跟踪】// the map follows the user's location
    MKUserTrackingModeFollowWithHeading __TVOS_PROHIBITED, 【导航跟踪】// the map follows the user's location and heading
} NS_ENUM_AVAILABLE(NA, 5_0) __TVOS_AVAILABLE(9_2) __WATCHOS_PROHIBITED;

#if TARGET_OS_IPHONE
NS_CLASS_AVAILABLE(NA, 3_0) __TVOS_AVAILABLE(9_2) __WATCHOS_PROHIBITED
@interface MKMapView : UIView <NSCoding>
#else
NS_CLASS_AVAILABLE(10_9, NA)
@interface MKMapView : NSView <NSCoding>
#endif

@property (nonatomic, weak, nullable) id <MKMapViewDelegate> delegate;

// Changing the map type or region can cause the map to start loading map content.
// The loading delegate methods will be called as map content is loaded.
/**
 【地图类型：枚举】
    typedef NS_ENUM(NSUInteger, MKMapType) {
    MKMapTypeStandard = 0,// 标准地图
    MKMapTypeSatellite,// 卫星地图
    MKMapTypeHybrid,// 混合模式(标准+卫星)
    MKMapTypeSatelliteFlyover,// 3D立体卫星(iOS9.0)
    MKMapTypeHybridFlyover,// 3D立体混合(iOS9.0)
} */
@property (nonatomic) MKMapType mapType;



/**
 【设置显示区域以及地图中心坐标】
 */
// Region is the coordinate and span of the map.
// Region may be modified to fit the aspect ratio of the view using regionThatFits:.
@property (nonatomic) MKCoordinateRegion region;
- (void)setRegion:(MKCoordinateRegion)region animated:(BOOL)animated;

// centerCoordinate allows the coordinate of the region to be changed without changing the zoom level.
@property (nonatomic) CLLocationCoordinate2D centerCoordinate;
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

// Returns a region of the aspect ratio of the map view that contains the given region, with the same center point.
- (MKCoordinateRegion)regionThatFits:(MKCoordinateRegion)region;

// Access the visible region of the map in projected coordinates.
@property (nonatomic) MKMapRect visibleMapRect;
- (void)setVisibleMapRect:(MKMapRect)mapRect animated:(BOOL)animate;

// Returns an MKMapRect modified to fit the aspect ratio of the map.
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect;

// Edge padding is the minumum padding on each side around the specified MKMapRect.
#if TARGET_OS_IPHONE
- (void)setVisibleMapRect:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animate;
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)insets;
#else
- (void)setVisibleMapRect:(MKMapRect)mapRect edgePadding:(NSEdgeInsets)insets animated:(BOOL)animate;
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect edgePadding:(NSEdgeInsets)insets;
#endif

@property (nonatomic, copy) MKMapCamera *camera NS_AVAILABLE(10_9, 7_0);
- (void)setCamera:(MKMapCamera *)camera animated:(BOOL)animated NS_AVAILABLE(10_9, 7_0);

#if TARGET_OS_IPHONE
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(nullable UIView *)view;
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(nullable UIView *)view;
- (CGRect)convertRegion:(MKCoordinateRegion)region toRectToView:(nullable UIView *)view;
- (MKCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(nullable UIView *)view;
#else

/**
 【经纬度坐标转UIKit坐标点，UIKit坐标点转经纬度】
 */
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(nullable NSView *)view;
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(nullable NSView *)view;
- (CGRect)convertRegion:(MKCoordinateRegion)region toRectToView:(nullable NSView *)view;
- (MKCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(nullable NSView *)view;
#endif

#pragma mark ------------------
#pragma mark - 【设置地图 操控项】

// Control the types of user interaction available
// Zoom and scroll are enabled by default.
@property (nonatomic, getter=isZoomEnabled) BOOL zoomEnabled; //【是否可以 缩放】
@property (nonatomic, getter=isScrollEnabled) BOOL scrollEnabled; //【是否可以 滚动】
// Rotate and pitch are enabled by default on Mac OS X and on iOS 7.0 and later.
@property (nonatomic, getter=isRotateEnabled) BOOL rotateEnabled NS_AVAILABLE(10_9, 7_0)  __TVOS_PROHIBITED; //【是否可以 旋转】
@property (nonatomic, getter=isPitchEnabled) BOOL pitchEnabled NS_AVAILABLE(10_9, 7_0) __TVOS_PROHIBITED; //【是否显示 3D视角】

#if !TARGET_OS_IPHONE
@property (nonatomic) BOOL showsZoomControls NS_AVAILABLE(10_9, NA);
#endif

#pragma mark ------------------
#pragma mark - 【设置地图 显示项】

@property (nonatomic) BOOL showsCompass NS_AVAILABLE(10_9, 9_0) __TVOS_PROHIBITED;//【指南针】
@property (nonatomic) BOOL showsScale NS_AVAILABLE(10_10, 9_0);//【比例尺】

@property (nonatomic) BOOL showsPointsOfInterest NS_AVAILABLE(10_9, 7_0); //【兴趣点】// Affects MKMapTypeStandard and MKMapTypeHybrid
@property (nonatomic) BOOL showsBuildings NS_AVAILABLE(10_9, 7_0); //【建筑物】// Affects MKMapTypeStandard
@property (nonatomic) BOOL showsTraffic NS_AVAILABLE(10_11, 9_0); //【交通】 // Affects MKMapTypeStandard and MKMapTypeHybrid




// Set to YES to add the user location annotation to the map and start updating its location
/**
 【是否在地图上标注用户位置】
  只是在地图上, 添加一个蓝点 , 标示用户当前位置, 不会自动放大地图, 不会追踪用户的位置信息
 */
@property (nonatomic) BOOL showsUserLocation;

// The annotation representing the user's location
/**
 【用户位置】
 */
@property (nonatomic, readonly) MKUserLocation *userLocation;

#if TARGET_OS_IPHONE
/**
 【用户跟踪类型：枚举_line34】
  在地图上, 添加一个蓝点 , 标示用户当前位置, 会自动放大地图, 还会, 自动追踪用户的位置, (不灵光)
 */
@property (nonatomic) MKUserTrackingMode userTrackingMode NS_AVAILABLE(NA, 5_0);
- (void)setUserTrackingMode:(MKUserTrackingMode)mode animated:(BOOL)animated NS_AVAILABLE(NA, 5_0);
#endif

// Returns YES if the user's location is displayed within the currently visible map region.
@property (nonatomic, readonly, getter=isUserLocationVisible) BOOL userLocationVisible;

// Annotations are models used to annotate coordinates on the map.
// Implement mapView:viewForAnnotation: on MKMapViewDelegate to return the annotation view for each annotation.

/** 添加大头针数据模型 */
- (void)addAnnotation:(id <MKAnnotation>)annotation;
- (void)addAnnotations:(NSArray<id<MKAnnotation>> *)annotations;

/** 移除大头针数据模型 */
- (void)removeAnnotation:(id <MKAnnotation>)annotation;
- (void)removeAnnotations:(NSArray<id<MKAnnotation>> *)annotations;

/**
 【大头针数据模型数组】
 */
@property (nonatomic, readonly) NSArray<id<MKAnnotation>> *annotations;
- (NSSet<id<MKAnnotation>> *)annotationsInMapRect:(MKMapRect)mapRect NS_AVAILABLE(10_9, 4_2);

// Currently displayed view for an annotation; returns nil if the view for the annotation isn't being displayed.
- (nullable MKAnnotationView *)viewForAnnotation:(id <MKAnnotation>)annotation;

// Used by the delegate to acquire an already allocated annotation view, in lieu of allocating a new one.
/** 从缓冲池中取出大头针视图控件 */
- (nullable MKAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

// Select or deselect a given annotation.  Asks the delegate for the corresponding annotation view if necessary.

/** 选中一个大头针 和 取消选中 */
- (void)selectAnnotation:(id <MKAnnotation>)annotation animated:(BOOL)animated;
- (void)deselectAnnotation:(nullable id <MKAnnotation>)annotation animated:(BOOL)animated;
@property (nonatomic, copy) NSArray<id<MKAnnotation>> *selectedAnnotations;

// annotationVisibleRect is the visible rect where the annotations views are currently displayed.
// The delegate can use annotationVisibleRect when animating the adding of the annotations views in mapView:didAddAnnotationViews:
@property (nonatomic, readonly) CGRect annotationVisibleRect;

// Position the map such that the provided array of annotations are all visible to the fullest extent possible.
- (void)showAnnotations:(NSArray<id<MKAnnotation>> *)annotations animated:(BOOL)animated NS_AVAILABLE(10_9, 7_0);

@end

typedef NS_ENUM(NSInteger, MKOverlayLevel) {
    MKOverlayLevelAboveRoads = 0, // note that labels include shields and point of interest icons.
    MKOverlayLevelAboveLabels
} NS_ENUM_AVAILABLE(10_9, 7_0) __TVOS_AVAILABLE(9_2) __WATCHOS_PROHIBITED;

@interface MKMapView (OverlaysAPI)

// Overlays are models used to represent areas to be drawn on top of the map.
// This is in contrast to annotations, which represent points on the map.
// Implement -mapView:rendererForOverlay: on MKMapViewDelegate to return the renderer for each overlay.
- (void)addOverlay:(id <MKOverlay>)overlay level:(MKOverlayLevel)level NS_AVAILABLE(10_9, 7_0);
- (void)addOverlays:(NSArray<id<MKOverlay>> *)overlays level:(MKOverlayLevel)level NS_AVAILABLE(10_9, 7_0);

- (void)removeOverlay:(id <MKOverlay>)overlay NS_AVAILABLE(10_9, 4_0);
- (void)removeOverlays:(NSArray<id<MKOverlay>> *)overlays NS_AVAILABLE(10_9, 4_0);

- (void)insertOverlay:(id <MKOverlay>)overlay atIndex:(NSUInteger)index level:(MKOverlayLevel)level NS_AVAILABLE(10_9, 7_0);

- (void)insertOverlay:(id <MKOverlay>)overlay aboveOverlay:(id <MKOverlay>)sibling NS_AVAILABLE(10_9, 4_0);
- (void)insertOverlay:(id <MKOverlay>)overlay belowOverlay:(id <MKOverlay>)sibling NS_AVAILABLE(10_9, 4_0);

- (void)exchangeOverlay:(id <MKOverlay>)overlay1 withOverlay:(id <MKOverlay>)overlay2 NS_AVAILABLE(10_9, 7_0);

@property (nonatomic, readonly) NSArray<id<MKOverlay>> *overlays NS_AVAILABLE(10_9, 4_0);
- (NSArray<id<MKOverlay>> *)overlaysInLevel:(MKOverlayLevel)level NS_AVAILABLE(10_9, 7_0);

// Current renderer for overlay; returns nil if the overlay is not shown.
- (nullable MKOverlayRenderer *)rendererForOverlay:(id <MKOverlay>)overlay NS_AVAILABLE(10_9, 7_0);

#if TARGET_OS_IPHONE
// Currently displayed view for overlay; returns nil if the view has not been created yet.
// Prefer using MKOverlayRenderer and -rendererForOverlay.
- (MKOverlayView *)viewForOverlay:(id <MKOverlay>)overlay NS_DEPRECATED_IOS(4_0, 7_0) __TVOS_PROHIBITED;
#endif

// These methods operate implicitly on overlays in MKOverlayLevelAboveLabels and may be deprecated in a future release in favor of the methods that specify the level.
- (void)addOverlay:(id <MKOverlay>)overlay NS_AVAILABLE(10_9, 4_0);
- (void)addOverlays:(NSArray<id<MKOverlay>> *)overlays NS_AVAILABLE(10_9, 4_0);

- (void)insertOverlay:(id <MKOverlay>)overlay atIndex:(NSUInteger)index NS_AVAILABLE(10_9, 4_0);
- (void)exchangeOverlayAtIndex:(NSUInteger)index1 withOverlayAtIndex:(NSUInteger)index2 NS_AVAILABLE(10_9, 4_0);

@end

__WATCHOS_PROHIBITED
@protocol MKMapViewDelegate <NSObject>
@optional

- (void)mapView:(MKMapView *)mapView regionWillChangeAnimated:(BOOL)animated;
/** 显示区域改变会调用 */
- (void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated;

- (void)mapViewWillStartLoadingMap:(MKMapView *)mapView;
- (void)mapViewDidFinishLoadingMap:(MKMapView *)mapView;
/** 地图加载失败会调用 */
- (void)mapViewDidFailLoadingMap:(MKMapView *)mapView withError:(NSError *)error;

- (void)mapViewWillStartRenderingMap:(MKMapView *)mapView NS_AVAILABLE(10_9, 7_0);
- (void)mapViewDidFinishRenderingMap:(MKMapView *)mapView fullyRendered:(BOOL)fullyRendered NS_AVAILABLE(10_9, 7_0);

// mapView:viewForAnnotation: provides the view for each annotation.
// This method may be called for all or some of the added annotations.
// For MapKit provided annotations (eg. MKUserLocation) return nil to use the MapKit provided annotation view.
/**
 * 增加大头针数据模型时会调用 (大头针也有重复利用机制)
 *
 * @参数: mapView 地图
 * @参数: annotation 数据模型
 * @注解: 当该方法不实现或者返回nil时，就会默认显示系统的大头针。
 * 功能类似于UITableView的tableView:cellForRowAtIndexPath:方法
 */
- (nullable MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation;

// mapView:didAddAnnotationViews: is called after the annotation views have been added and positioned in the map.
// The delegate can implement this method to animate the adding of the annotations views.
// Use the current positions of the annotation views as the destinations of the animation.
- (void)mapView:(MKMapView *)mapView didAddAnnotationViews:(NSArray<MKAnnotationView *> *)views;

#if TARGET_OS_IPHONE
// mapView:annotationView:calloutAccessoryControlTapped: is called when the user taps on left & right callout accessory UIControls.
/**
 【点击了大头针副展示图调用】

 */
- (void)mapView:(MKMapView *)mapView annotationView:(MKAnnotationView *)view calloutAccessoryControlTapped:(UIControl *)control __TVOS_PROHIBITED;
#endif

/** 点击选中大头针时会调用 */
- (void)mapView:(MKMapView *)mapView didSelectAnnotationView:(MKAnnotationView *)view NS_AVAILABLE(10_9, 4_0);
/** 取消选中大头针时会调用 */
- (void)mapView:(MKMapView *)mapView didDeselectAnnotationView:(MKAnnotationView *)view NS_AVAILABLE(10_9, 4_0);

- (void)mapViewWillStartLocatingUser:(MKMapView *)mapView NS_AVAILABLE(10_9, 4_0);
- (void)mapViewDidStopLocatingUser:(MKMapView *)mapView NS_AVAILABLE(10_9, 4_0);
/** 用户位置发生改变会调用 */
- (void)mapView:(MKMapView *)mapView didUpdateUserLocation:(MKUserLocation *)userLocation NS_AVAILABLE(10_9, 4_0);
- (void)mapView:(MKMapView *)mapView didFailToLocateUserWithError:(NSError *)error NS_AVAILABLE(10_9, 4_0);

- (void)mapView:(MKMapView *)mapView annotationView:(MKAnnotationView *)view didChangeDragState:(MKAnnotationViewDragState)newState
   fromOldState:(MKAnnotationViewDragState)oldState NS_AVAILABLE(10_9, 4_0) __TVOS_PROHIBITED;

#if TARGET_OS_IPHONE
- (void)mapView:(MKMapView *)mapView didChangeUserTrackingMode:(MKUserTrackingMode)mode animated:(BOOL)animated NS_AVAILABLE(NA, 5_0);
#endif

- (MKOverlayRenderer *)mapView:(MKMapView *)mapView rendererForOverlay:(id <MKOverlay>)overlay NS_AVAILABLE(10_9, 7_0);
- (void)mapView:(MKMapView *)mapView didAddOverlayRenderers:(NSArray<MKOverlayRenderer *> *)renderers NS_AVAILABLE(10_9, 7_0);

#if TARGET_OS_IPHONE
// Prefer -mapView:rendererForOverlay:
- (MKOverlayView *)mapView:(MKMapView *)mapView viewForOverlay:(id <MKOverlay>)overlay NS_DEPRECATED_IOS(4_0, 7_0) __TVOS_PROHIBITED;
// Called after the provided overlay views have been added and positioned in the map.
// Prefer -mapView:didAddOverlayRenderers:
- (void)mapView:(MKMapView *)mapView didAddOverlayViews:(NSArray *)overlayViews NS_DEPRECATED_IOS(4_0, 7_0) __TVOS_PROHIBITED;
#endif

@end

CoderLN_NOTE NS_ASSUME_NONNULL_END

