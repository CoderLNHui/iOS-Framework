/*
 * CLGeocoder.h
 *
 * CoreLocation (c) 2010
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

//【CoreLocation 地理编码】

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <CoreLocation/CLAvailability.h>

NS_ASSUME_NONNULL_BEGIN

@class CLRegion;
@class CLPlacemark; //【地标对象】
@class CLGeocoderInternal;

// geocoding handler, CLPlacemarks are provided in order of most confident to least confident
typedef void (^CLGeocodeCompletionHandler)(NSArray< CLPlacemark *> * __nullable placemarks, NSError * __nullable error);

NS_CLASS_AVAILABLE(10_8,5_0)
@interface CLGeocoder : NSObject
{
@private
    CLGeocoderInternal *_internal;
}

@property (nonatomic, readonly, getter=isGeocoding) BOOL geocoding;

// reverse geocode requests
/**
 *【everseGeocodeLocation: 反地理编码(把经纬度---> 详细地址)】
 * @参数: location 对应的位置对象
 */
- (void)reverseGeocodeLocation:(CLLocation *)location completionHandler:(CLGeocodeCompletionHandler)completionHandler;

// forward geocode requests
// geocodeAddressDictionary:completionHandler: takes an address dictionary as defined by the AddressBook framework.
// You can obtain an address dictionary from an ABPerson by retrieving the kABPersonAddressProperty property.
// Alternately, one can be constructed using the kABPersonAddress* keys defined in <AddressBook/ABPerson.h>.


/**
 *【geocodeAddressString: 地理编码(地址关键字 ->经纬度)】
 * @参数: region 区域
 */
- (void)geocodeAddressDictionary:(NSDictionary *)addressDictionary completionHandler:(CLGeocodeCompletionHandler)completionHandler;
- (void)geocodeAddressString:(NSString *)addressString completionHandler:(CLGeocodeCompletionHandler)completionHandler;
- (void)geocodeAddressString:(NSString *)addressString inRegion:(nullable CLRegion *)region completionHandler:(CLGeocodeCompletionHandler)completionHandler;

//【取消编码】
- (void)cancelGeocode;

@end

#NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END


