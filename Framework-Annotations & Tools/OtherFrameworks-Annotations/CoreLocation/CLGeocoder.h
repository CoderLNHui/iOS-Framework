/*
 * CLGeocoder.h
 * CoreLocation
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2010
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
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

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END

