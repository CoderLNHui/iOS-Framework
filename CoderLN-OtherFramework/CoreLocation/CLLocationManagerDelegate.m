
#import <CoreLocation/CoreLocation.h>

#define isIOS(version) ([[UIDevice currentDevice].systemVersion doubleValue] >= version)

@interface ListeningViewController ()<CLLocationManagerDelegate>

@property (nonatomic, strong) CLLocationManager *locationManager;

@property (weak, nonatomic) IBOutlet UILabel *noticeLabel;
@end

@implementation ListeningViewController

/** 位置管理者 */
- (CLLocationManager *)locationManager
{
    if(_locationManager == nil) {
        _locationManager = [[CLLocationManager alloc] init];
        _locationManager.delegate = self;
        
        // 判断版本号8.0之后需要请求获取权限
        if (isIOS(8.0)) {
            [_locationManager requestAlwaysAuthorization];
        }
        
    }
    return _locationManager;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    
    //【判断当前设置是否支持区域监听（区域类型）】
    if (![CLLocationManager isMonitoringAvailableForClass:[CLCircularRegion class]]) return;
    
    // 创建区域中心
    CLLocationCoordinate2D center = CLLocationCoordinate2DMake(21.123, 121.234);
    
    // 创建区域半径
    CLLocationDistance distance = 1000.0;
    
    // 创建一个区域
    CLCircularRegion *region = [[CLCircularRegion alloc] initWithCenter:center radius:distance identifier:@"测试区域监听标识1"];
    
    //【监听一个区域（只有用户进入区域，或者离开区域动作的时候，才会通过代理告诉外界）】
    [self.locationManager startMonitoringForRegion:region];
    
    //【请求某个区域的状态（不止可以获取到指定区域的状态, 而且当状态发生变化时, 也会调用对应的代理方法, 告诉我们）】
    [self.locationManager requestStateForRegion:region];
}




#pragma mark ------------------
#pragma mark - <CLLocationManagerDelegate>

/**
 *  进入指定区域时调用
 *
 *  @param manager 位置管理者
 *  @param region  区域
 */
- (void)locationManager:(CLLocationManager *)manager didEnterRegion:(CLRegion *)region
{
    NSLog(@"进入区域 -- %@",region.identifier);
    self.noticeLabel.text = [NSString stringWithFormat:@"进入区域 -- %@",region.identifier];
}


/**
 *  离开指定区域时调用
 *
 *  @param manager 位置管理者
 *  @param region  区域
 */
- (void)locationManager:(CLLocationManager *)manager didExitRegion:(CLRegion *)region
{
    NSLog(@"离开区域 -- %@",region.identifier);
    self.noticeLabel.text = [NSString stringWithFormat:@"离开区域 -- %@",region.identifier];
}


/**
 *  当前请求指定区域状态时, 回调的代理方法
 *
 *  @param manager 位置管理者
 *  @param state   状态
 *  @param region  区域
 */
- (void)locationManager:(CLLocationManager *)manager didDetermineState:(CLRegionState)state forRegion:(CLRegion *)region
{
    /**
     CLRegionStateUnknown, // 不知道
     CLRegionStateInside, // 在区域内部
     CLRegionStateOutside // 在区域外部
     */
    if (state == CLRegionStateInside) {
        self.noticeLabel.text = @"状态：在区域内部";
    } else if (state == CLRegionStateOutside){
        self.noticeLabel.text = @"状态：在区域外部";
    }
}

# 


@end
