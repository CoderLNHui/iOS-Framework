// 完全实现ok
#import <Foundation/Foundation.h>

typedef double UIAccelerationValue;

@interface UIAcceleration : NSObject
@property (nonatomic, readonly) UIAccelerationValue x;
@property (nonatomic, readonly) UIAccelerationValue y;
@property (nonatomic, readonly) UIAccelerationValue z;
@property (nonatomic, readonly) NSTimeInterval timestamp;
@end
