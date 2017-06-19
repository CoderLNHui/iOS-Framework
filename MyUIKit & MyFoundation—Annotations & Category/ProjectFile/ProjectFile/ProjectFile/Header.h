//
//  Header.h
//  ☕️（https://github.com/CustomPBWaters）
//
//  Created by 【Plain Boiled Water ln】 on 15/-/-.
//  Copyright © 2015年（https://custompbwaters.github.io）All rights reserved.
//

//#ifndef PchHeader_h
//#define PchHeader_h
//
//#endif /* PchHeader_h */


//--------------------------- 【Header.h】 ------------------------------//
//


#define callCenterPhoneNumber @"400-012-5750"
#define NetConnectIsError @"error"
#define NetConnectIsErrorString(error) [NSString stringWithFormat:@"%@,%ld\n%@",NetConnectIsError,error.code,error.localizedDescription]

#define SERVICE_TYPE TEST_INTERNAL_NETWORK
#define kScaleFor6S(value) (kScreenWidth/375.0)*value

#define kScreenSize           [[UIScreen mainScreen] bounds].size
#define kScreenWidth          [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight         [[UIScreen mainScreen] bounds].size.height

#define  kSystemVersion  [[[UIDevice currentDevice] systemVersion] doubleValue]
#define  kHeightScale [[UIScreen mainScreen] bounds].size.height/667.0
#define  kWidthScale [[UIScreen mainScreen] bounds].size.height/375.0

#define ShowHud(str)           do {  \
MBProgressHUD *hud1 = [MBProgressHUD showHUDAddedTo:self.view animated:YES];\
hud1.mode = MBProgressHUDModeText;\
hud1.removeFromSuperViewOnHide = YES;\
hud1.labelText = str;\
hud1.yOffset = -50;\
[hud1 hide:YES afterDelay:1.5];\
} while(0)

//彩色打印
#define LogBlue(frmt, ...) NSLog((XCODE_COLORS_ESCAPE @"fg0,0,255;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)
#define LogRed(frmt, ...) NSLog((XCODE_COLORS_ESCAPE @"fg255,0,0;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)
#define LogGreen(frmt, ...) NSLog((XCODE_COLORS_ESCAPE @"fg0,255,0;" frmt XCODE_COLORS_RESET), ##__VA_ARGS__)

//控制台颜色插件
#define XCODE_COLORS_ESCAPE @"\033["
#define XCODE_COLORS_RESET_FG  XCODE_COLORS_ESCAPE @"fg;" // Clear any foreground color
#define XCODE_COLORS_RESET_BG  XCODE_COLORS_ESCAPE @"bg;" // Clear any background color
#define XCODE_COLORS_RESET     XCODE_COLORS_ESCAPE @";"   // Clear any foreground or background color

#define titleFont(r) kSystemVersion>=9.0?[UIFont fontWithName:FONT_TITLE size:r*1.0]:[UIFont systemFontOfSize:r*1.0]
#define rgb(r,g,b,a) [UIColor colorWithRed:(r*1.0)/255 green:(g*1.0)/255 blue:(b*1.0)/255 alpha:(a*1.0)]
#define kLineColor rgb(29, 29, 38, 0.05)
#define kControllerViewBackGroundColor rgb(237,237,237,1.0)
#define kSubjectMainColor rgb(0, 185, 255, 1.0)
#define kTitleBlackColor rgb(28,28,28,1.0)
#define kTitleGrayColor rgb(144,144,144,1.0)
#define kClearColor [UIColor clearColor]
#define kTimeOutLength 30.0f

#define kUploadPhotoUrl @"http://192.168.3.18:8191/Default.aspx/"
#define kDownloadPhotoUrl @"download"
#define kDefaultServiceUrl @"defaultService"

static NSString* const FONT_TITLE = @"PingFangSC-Regular";//常规
static NSString* const FONT_SUBTITLE = @"PingFangSC-Light";//细体
static NSString* const FONT_PING_FANG_SC_ULTRALIGHT = @"PingFangSC-Ultralight";//超细
static NSString* const FONT_PING_FANG_SC_MEDIUM = @"PingFangSC-Medium";//中黑

static NSString * const Arial_BoldMT = @"Arial-BoldMT";//Arial粗体
static NSString * const Arial_MT = @"ArialMT";//Arial粗体







#define KeyWindow [UIApplication sharedApplication].keyWindow

// 角度转成弧度
#define ANGLE_TO_RADIANS(angle) (angle)/(180.0*M_PI)
// 弧度转成角度
#define RADIANS_TO_ANGLE(radians) (radians)*(180.0/M_PI)




#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#define debugMethod() NSLog(@"%s", __func__)
#else
#define NSLog(...)
#define debugMethod()
#endif






















































