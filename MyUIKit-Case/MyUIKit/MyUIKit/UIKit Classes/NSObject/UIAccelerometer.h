// 完全实现ok
#import <Foundation/Foundation.h>

@class UIAccelerometer, UIAcceleration;

@protocol UIAccelerometerDelegate <NSObject>
- (void)accelerometer:(UIAccelerometer *)accelerometer didAccelerate:(UIAcceleration *)acceleration;
@end

@interface UIAccelerometer : NSObject
+ (UIAccelerometer *)sharedAccelerometer;

@property (nonatomic, assign) id<UIAccelerometerDelegate> delegate;
@property (nonatomic) NSTimeInterval updateInterval;
@end
