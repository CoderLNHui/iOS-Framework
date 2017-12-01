/*
 * MKMapView.m
 * MapKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2009-2014
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


/*
 参考：http://www.jianshu.com/p/81122d98fbc5
 
【MapKit核心类：MKMapView 展示地图】
 
1.【属性】：
 
    -【用户位置跟踪】
    @property (nonatomic) BOOL showsUserLocation;//【是否在地图上标注用户位置】
    @property (nonatomic, readonly) MKUserLocation *userLocation;//【用户位置】
    @property (nonatomic) MKUserTrackingMode userTrackingMode;//【用户跟踪类型】
    typedef NS_ENUM(NSInteger, MKUserTrackingMode) {
        MKUserTrackingModeNone = 0, //【不跟踪】
        MKUserTrackingModeFollow, //【跟踪】
        MKUserTrackingModeFollowWithHeading,  //【导航跟踪】
    };

    -【设置地图配置项】
    @property (nonatomic) MKMapType mapType;//【地图类型】
    @property (nonatomic, readonly) NSArray *annotations;//【大头针数组】
    typedef NS_ENUM(NSUInteger, MKMapType) {
        MKMapTypeStandard = 0,//【标准地图】
        MKMapTypeSatellite,//【卫星地图】
        MKMapTypeHybrid,//【混合模式(标准+卫星)】
        MKMapTypeSatelliteFlyover,// 3D立体卫星(iOS9.0)
        MKMapTypeHybridFlyover,// 3D立体混合(iOS9.0)
    }

    -【设置地图控制项】
    @property (nonatomic) BOOL zoomEnabled;// 是否可以缩放 
    @property (nonatomic) BOOL scrollEnabled;// 是否可以滚动 
    @property (nonatomic) BOOL rotateEnabled;// 是否可以旋转 
    @property (nonatomic) BOOL pitchEnabled;// 是否显示3D视角 
     
    -【设置地图显示项】
    @property (nonatomic) BOOL showsBuildings;// 是否显示建筑物，只影响标准地图 
    @property (nonatomic) BOOL showsPointsOfInterest;// 是否显示兴趣点
    @property (nonatomic) BOOL showsTraffic;// 是否显示交通，iOS9
    @property (nonatomic) BOOL showsCompass;// 是否显示指南针，iOS9 
    @property (nonatomic) BOOL showsScale;// 是否显示比例尺，iOS9



2.【对象方法】：

    // 添加大头针
    - (void)addAnnotation:(id <MKAnnotation>)annotation;
    - (void)addAnnotations:(NSArray<id<MKAnnotation>> *)annotations;
    // 移除大头针 
    - (void)removeAnnotation:(id <MKAnnotation>)annotation;
    - (void)removeAnnotations:(NSArray<id<MKAnnotation>> *)annotations;
    // 选中大头针与取消选中大头针 
    - (void)selectAnnotation:(id <MKAnnotation>)annotation
                    animated:(BOOL)animated;
    - (void)deselectAnnotation:(id <MKAnnotation>)annotation
                      animated:(BOOL)animated;
    // 获取大头针视图 
    - (MKAnnotationView *)viewForAnnotation:(id <MKAnnotation>)annotation;
    // 从缓冲池中取出大头针视图控件 
    - (MKAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;
    // 设置显示区域以及地图中心坐标 
    - (void)setRegion:(MKCoordinateRegion)region
             animated:(BOOL)animated;
    - (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
                       animated:(BOOL)animated;
    // 经纬度坐标转UIKit坐标点，UIKit坐标点转经纬度坐标
    - (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate
                   toPointToView:(UIView *)view;
    - (CLLocationCoordinate2D)convertPoint:(CGPoint)point
                      toCoordinateFromView:(UIView *)view;

3.【常用代理方法 MKMapViewDelegate】：

    // 地图加载完成会调用
    - (void)mapViewDidFinishLoadingMap:(MKMapView *)mapView;
    // 地图加载失败会调用 
    - (void)mapViewDidFailLoadingMap:(MKMapView *)mapView withError:(NSError *)error;
    // 用户位置发生改变会调用 
    - (void)mapView:(MKMapView *)mapView didUpdateUserLocation:(MKUserLocation *)userLocation;
    // 显示区域改变会调用 
    - (void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated;
    // 点击选中大头针时会调用 
    - (void)mapView:(MKMapView *)mapView didSelectAnnotationView:(MKAnnotationView *)view;
    // 取消选中大头针时会调用 
    - (void)mapView:(MKMapView *)mapView didDeselectAnnotationView:(MKAnnotationView *)view;
    // 显示地图上的大头针，注解: 当该方法不实现或者返回nil时，就会默认显示系统的大头针
    - (MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id<MKAnnotation>)annotation;

 
 
 
 
【MKAnnotationView：用于标注具体位置的大头针】
 
 1.【属性】
 
    @property (nonatomic, strong, nullable)     id <MKAnnotation> annotation;//数据模型
    @property (nonatomic, strong, nullable)     UIImage *image;//大头针的图像
    @property (strong, nonatomic, nullable)     UIView *leftCalloutAccessoryView;//左附属对话框
    @property (strong, nonatomic, nullable)     UIView *rightCalloutAccessoryView;//右附属对话框
    @property (nonatomic, getter=isDraggable)   BOOL draggable //是否可拖动
 
 
 2.【对象方法】
 
    // 增加大头针数据模型时会调用，类似于tableView的cellForRowAtIndexPath:《WechatPublic-Codeidea》
    - (nullable MKAnnotationView *)mapView:(MKMapView *)mapView viewForAnnotation:(id <MKAnnotation>)annotation;


    // 大头针被点击时调用
    - (void)mapView:(MKMapView *)mapView didSelectAnnotationView:(MKAnnotationView *)view NS_AVAILABLE(10_9, 4_0);
 

3.【MKAnnotation：是MKAnnotationView的数据源】
    @interface LNAnnotation : NSObject <MKAnnotation>；任何遵守该协议的对象都可以成为MKAnnotationView的数据源

    @property (nonatomic, readonly) CLLocationCoordinate2D coordinate; //坐标
    @property (nonatomic, readonly, copy, nullable) NSString *title;//标题
    @property (nonatomic, readonly, copy, nullable) NSString *subtitle;//副标题

    - (void)setCoordinate:(CLLocationCoordinate2D)newCoordinate ;//设置坐标
 
 
4.【补充：Callout(大头针弹框)】
    点击大头针（MKAnnotationView大头针），会出现一个白底的对话框，它被叫做 Callout，可以设置它的主标题和副标题。还有左右附属示图，它们可以显示图片或者按钮，也可被点击。
    annotationView.canShowCallout = YES; // 显示弹框
 
 
 
 
*/
@end
