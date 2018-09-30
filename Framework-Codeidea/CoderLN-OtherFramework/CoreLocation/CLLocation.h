/*
 * CLLocation.h 
 *
 * CoreLocation (c) 2008-2010
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */


#import <Foundation/Foundation.h>
#import <CoreLocation/CLAvailability.h>

NS_ASSUME_NONNULL_BEGIN

/*
 *  CLLocationDegrees
 *
 *  Discussion:
 *    Type used to represent a latitude or longitude coordinate in degrees under the WGS 84 reference
 *    frame. The degree can be positive (North and East) or negative (South and West).
 */
typedef double CLLocationDegrees;

/*
 *  CLLocationAccuracy
 *
 *  Discussion:
 *    Type used to represent a location accuracy level in meters. The lower the value in meters, the
 *    more physically precise the location is. A negative accuracy value indicates an invalid location.
 */
typedef double CLLocationAccuracy;

/*
 *  CLLocationSpeed
 *
 *  Discussion:
 *    Type used to represent the speed in meters per second.
 */
typedef double CLLocationSpeed;

/*
 *  CLLocationDirection
 *
 *  Discussion:
 *    Type used to represent the direction in degrees from 0 to 359.9. A negative value indicates an
 *    invalid direction.
 */
typedef double CLLocationDirection;

/*
 *  CLLocationCoordinate2D
 *
 *  Discussion:
 *    A structure that contains a geographical coordinate.
 *
 *  Fields:
 *    latitude:
 *      The latitude in degrees.
 *    longitude:
 *      The longitude in degrees.
 */
struct CLLocationCoordinate2D {
    CLLocationDegrees latitude;
    CLLocationDegrees longitude;
};
typedef struct CLLocationCoordinate2D CLLocationCoordinate2D;

/*
 *  CLLocationDistance
 *
 *  Discussion:
 *    Type used to represent a distance in meters.
 */
typedef double CLLocationDistance;

/*
 *  kCLDistanceFilterNone
 *
 *  Discussion:
 *    Use as the distanceFilter property for CLLocationManager. This indicates
 *    to the location service that no minimum movement filter is desired - ie, client will be informed
 *    of any movement.
 */
extern const CLLocationDistance kCLDistanceFilterNone;

/*
 *  kCLLocationAccuracy<x>
 * 【设置位置精确度】_manager.desiredAccuracy
 *
 *  Discussion:
 *    Used to specify the accuracy level desired. The location service will try its best to achieve
 *    your desired accuracy. However, it is not guaranteed. To optimize
 *    power performance, be sure to specify an appropriate accuracy for your usage scenario (eg,
 *    use a large accuracy value when only a coarse location is needed).
 *
 * 【NOTE】：定位精度越高，耗电越多且定位时间越长，可根据实际情况而定。
 */
extern const CLLocationAccuracy kCLLocationAccuracyBestForNavigation __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0); // 最适合导航
extern const CLLocationAccuracy kCLLocationAccuracyBest;// 精确度最佳
extern const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters;// 精确度10米以内;
extern const CLLocationAccuracy kCLLocationAccuracyHundredMeters;// 精确度100米以内;
extern const CLLocationAccuracy kCLLocationAccuracyKilometer;// 精确度1000米以内;
extern const CLLocationAccuracy kCLLocationAccuracyThreeKilometers;// 精确度3000米以内;
/** 【NOTE】：定位精度越高，耗电越多且定位时间越长，可根据实际情况而定。 */



/*
 *  CLLocationDistanceMax
 *
 *  Discussion:
 *  	Used to specify the maximum CLLocationDistance
 */
extern const CLLocationDistance CLLocationDistanceMax __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

/*
 *  CLTimeIntervalMax
 *
 *  Discussion:
 *  	Used to specify the maximum NSTimeInterval
 */
extern const NSTimeInterval CLTimeIntervalMax __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_6_0);

/*
 *  kCLLocationCoordinate2DInvalid
 *
 *  Discussion:
 *    Used to specify an invalid CLLocationCoordinate2D.
 */
extern const CLLocationCoordinate2D kCLLocationCoordinate2DInvalid __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

#ifdef __cplusplus
extern "C" {
#endif
    
    /*
     *  CLLocationCoordinate2DIsValid
     *
     *  Discussion:
     *    Returns YES if the specified coordinate is valid, NO otherwise.
     */
    BOOL CLLocationCoordinate2DIsValid(CLLocationCoordinate2D coord) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
    
    /*
     *  CLLocationCoordinate2DMake:
     *
     *  Discussion:
     *    Returns a new CLLocationCoordinate2D at the given latitude and longitude
     */
    CLLocationCoordinate2D CLLocationCoordinate2DMake(CLLocationDegrees latitude, CLLocationDegrees longitude) __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
    
#ifdef __cplusplus
}
#endif

/*
 *  CLFloor
 *
 *  Discussion:
 *    Encapsulates the information about a floor.
 */
NS_CLASS_AVAILABLE(NA, 8_0)
@interface CLFloor : NSObject <NSCopying, NSSecureCoding>

/*
 *  level
 *
 *  Discussion:
 *    This is a logical representation that will vary on definition from building-to-building.
 *    Floor 0 will always represent the floor designated as "ground".
 *    This number may be negative to designate floors below the ground floor
 *    and positive to indicate floors above the ground floor.
 *    It is not intended to match any numbering that might actually be used in the building.
 *    It is erroneous to use as an estimate of altitude.
 */
@property(readonly, nonatomic) NSInteger level;

@end

/*
 *  CLLocation
 *
 *  Discussion:
 *    Represents a geographical coordinate along with accuracy and timestamp information.
 */
NS_CLASS_AVAILABLE(10_6, 2_0)
@interface CLLocation : NSObject <NSCopying, NSSecureCoding>
{
@private
    id _internal;
}

/*
 *  initWithLatitude:longitude:
 *
 *  Discussion:
 *    Initialize with the specified latitude and longitude.
 */
- (instancetype)initWithLatitude:(CLLocationDegrees)latitude
                       longitude:(CLLocationDegrees)longitude;

/*
 *  initWithCoordinate:altitude:horizontalAccuracy:verticalAccuracy:timestamp:
 *
 *  Discussion:
 *    Initialize with the specified parameters.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                          altitude:(CLLocationDistance)altitude
                horizontalAccuracy:(CLLocationAccuracy)hAccuracy
                  verticalAccuracy:(CLLocationAccuracy)vAccuracy
                         timestamp:(NSDate *)timestamp;

/*
 *  initWithCoordinate:altitude:horizontalAccuracy:verticalAccuracy:course:speed:timestamp:
 *
 *  Discussion:
 *    Initialize with the specified parameters.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate
                          altitude:(CLLocationDistance)altitude
                horizontalAccuracy:(CLLocationAccuracy)hAccuracy
                  verticalAccuracy:(CLLocationAccuracy)vAccuracy
                            course:(CLLocationDirection)course
                             speed:(CLLocationSpeed)speed
                         timestamp:(NSDate *)timestamp __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_2);

/*
 *  coordinate【经纬度】
 *  用来存储地理位置的 latitude和 longitude,分别表示纬度和经度,都是foat类型
 *  如：float latitude = location.coordinate.latitude;
 *
 *  Discussion:
 *    Returns the coordinate of the current location.
 */
@property(readonly, nonatomic) CLLocationCoordinate2D coordinate;

/*
 *  altitude【海拔】
 *  表示位置的海拔高度,这个值是极不准确的
 *
 *  Discussion:
 *    Returns the altitude of the location. Can be positive (above sea level) or negative (below sea level).
 */
@property(readonly, nonatomic) CLLocationDistance altitude;

/*
 *  horizontalAccuracy【表示水平准确度】
 *  是以 coordinate为圆心的半径,返回的值越小,证明准确度越好,如果是负数,则表示 core location定位失败(当前位置数据不可用)。
 *
 *  Discussion:
 *    Returns the horizontal accuracy of the location. Negative if the lateral location is invalid.
 */
@property(readonly, nonatomic) CLLocationAccuracy horizontalAccuracy;

/*
 *  verticalAccuracy【表示垂直准确度】
 *  它的返回值与 altitude相关,所以不准确（如果是负数,代表当前位置数据不可用）。
 *
 *  Discussion:
 *    Returns the vertical accuracy of the location. Negative if the altitude is invalid.
 */
@property(readonly, nonatomic) CLLocationAccuracy verticalAccuracy;

/*
 *  course【航向 (0.0----359.9)】
 *
 *  Discussion:
 *    Returns the course of the location in degrees true North. Negative if course is invalid.
 *
 *  Range:
 *    0.0 - 359.9 degrees, 0 being true North
 */
@property(readonly, nonatomic) CLLocationDirection course __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_2_2) __TVOS_PROHIBITED;

/*
 *  speed【速度】
 *
 *  Discussion:
 *    Returns the speed of the location in m/s. Negative if speed is invalid.
 */
@property(readonly, nonatomic) CLLocationSpeed speed __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_2_2) __TVOS_PROHIBITED;

/*
 *  timestamp【用于返回定位时的时间,为 Nsdate类型。】
 *
 *  Discussion:
 *    Returns the timestamp when this location was determined.
 */
@property(readonly, nonatomic, copy) NSDate *timestamp;

/*
 *  floor【具体楼层】
 *
 *  Discussion:
 *    Contains information about the logical floor that you are on
 *    in the current building if you are inside a supported venue.
 *    This will be nil if the floor is unavailable.
 */
@property(readonly, nonatomic, copy, nullable) CLFloor *floor __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_8_0);

/*
 *  getDistanceFrom:
 *
 *  Discussion:
 *    Deprecated. Use -distanceFromLocation: instead.
 */
- (CLLocationDistance)getDistanceFrom:(const CLLocation *)location __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA,__MAC_NA,__IPHONE_2_0,__IPHONE_3_2) __TVOS_PROHIBITED __WATCHOS_PROHIBITED;

/*
 *  distanceFromLocation:【计算两个坐标之间的物理直线距离】
 *
 *  Discussion:
 *    Returns the lateral distance between two locations.
 */
- (CLLocationDistance)distanceFromLocation:(const CLLocation *)location __OSX_AVAILABLE_STARTING(__MAC_10_6,__IPHONE_3_2);

@end

#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

