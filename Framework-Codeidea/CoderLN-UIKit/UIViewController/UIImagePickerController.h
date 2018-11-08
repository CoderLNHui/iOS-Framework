/*
 * UIImagePickerController.h 
 *
 * UIKit (c) 2008-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */

#import <Foundation/Foundation.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIImage;
@protocol UIImagePickerControllerDelegate;

#pragma mark - NS_ENUM
#pragma mark -数据源类型
typedef NS_ENUM(NSInteger, UIImagePickerControllerSourceType) {

    UIImagePickerControllerSourceTypePhotoLibrary,//图库即相簿
    UIImagePickerControllerSourceTypeCamera,//相机
    UIImagePickerControllerSourceTypeSavedPhotosAlbum//相机胶卷
} __TVOS_PROHIBITED;

#pragma mark -视频质量类型
typedef NS_ENUM(NSInteger, UIImagePickerControllerQualityType) {
    UIImagePickerControllerQualityTypeHigh = 0,       //高清质量
    UIImagePickerControllerQualityTypeMedium = 1,     // 中等质量，适合WiFi传输
    UIImagePickerControllerQualityTypeLow = 2,         // 低质量，适合蜂窝网
    UIImagePickerControllerQualityType640x480 NS_ENUM_AVAILABLE_IOS(4_0) = 3,    // VGA质量，一般不常用
    UIImagePickerControllerQualityTypeIFrame1280x720 NS_ENUM_AVAILABLE_IOS(5_0) = 4,
    UIImagePickerControllerQualityTypeIFrame960x540 NS_ENUM_AVAILABLE_IOS(5_0) = 5,
} __TVOS_PROHIBITED;

#pragma mark -相机捕获模式（拍照、录制）
typedef NS_ENUM(NSInteger, UIImagePickerControllerCameraCaptureMode) {
    UIImagePickerControllerCameraCaptureModePhoto,//拍照模式
    UIImagePickerControllerCameraCaptureModeVideo//视频录制模式
} __TVOS_PROHIBITED;

#pragma mark -相机支持装置（前置、后置）
typedef NS_ENUM(NSInteger, UIImagePickerControllerCameraDevice) {
    UIImagePickerControllerCameraDeviceRear,//后摄像头
    UIImagePickerControllerCameraDeviceFront//前摄像头
} __TVOS_PROHIBITED;

#pragma mark -相机闪光灯模式
typedef NS_ENUM(NSInteger, UIImagePickerControllerCameraFlashMode) {
    UIImagePickerControllerCameraFlashModeOff  = -1,// 关闭
    UIImagePickerControllerCameraFlashModeAuto = 0,// 自动
    UIImagePickerControllerCameraFlashModeOn   = 1// 打开
} __TVOS_PROHIBITED;


typedef NS_ENUM(NSInteger, UIImagePickerControllerImageURLExportPreset) {
    UIImagePickerControllerImageURLExportPresetCompatible = 0,
    UIImagePickerControllerImageURLExportPresetCurrent
} NS_AVAILABLE_IOS(11_0) __TVOS_PROHIBITED;




#pragma mark - info dictionary keys（UIImagePickerControllerMediaType：获取媒体类型信息）
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaType __TVOS_PROHIBITED; // an NSString (UTI, i.e. kUTTypeImage)获取媒体类型信息
UIKIT_EXTERN NSString *const UIImagePickerControllerOriginalImage __TVOS_PROHIBITED; // a UIImage 获取原始照片
UIKIT_EXTERN NSString *const UIImagePickerControllerEditedImage __TVOS_PROHIBITED; // a UIImage 获取编辑后的照片
UIKIT_EXTERN NSString *const UIImagePickerControllerCropRect __TVOS_PROHIBITED; // an NSValue (CGRect) 获得包含编辑界面的剪裁窗的CGRect值(以此尺寸配合原图得到的新图为正方形图，同时该图旋转了90度)
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaURL __TVOS_PROHIBITED; // an NSURL //获取拍摄后图片或者视频路径（在SourceType为UIImagePickerControllerSourceTypeCamera时可以获取到）
UIKIT_EXTERN NSString *const UIImagePickerControllerReferenceURL NS_AVAILABLE_IOS(4_1) __TVOS_PROHIBITED; //选取到的图片或者视频所在素材库的URL（在SourceType不为UIImagePickerControllerSourceTypeCamera时可以获取到）
UIKIT_EXTERN NSString *const UIImagePickerControllerMediaMetadata NS_AVAILABLE_IOS(4_1) __TVOS_PROHIBITED;  // 获取对象的元数据在SourceType为UIImagePickerControllerSourceTypeCamera时可以获取到）
UIKIT_EXTERN NSString *const UIImagePickerControllerLivePhoto NS_AVAILABLE_IOS(9_1) __TVOS_PROHIBITED;  // a PHLivePhoto，得到LivePhoto对象
UIKIT_EXTERN NSString *const UIImagePickerControllerPHAsset NS_AVAILABLE_IOS(11_0) __TVOS_PROHIBITED;  // a PHAsset
UIKIT_EXTERN NSString *const UIImagePickerControllerImageURL NS_AVAILABLE_IOS(11_0) __TVOS_PROHIBITED;  // an NSURL




NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UIImagePickerController : UINavigationController <NSCoding>



#pragma mark - 🏃🏻‍♂️Method 方法
#pragma mark -用于判断设备是否支持某一数据源
+ (BOOL)isSourceTypeAvailable:(UIImagePickerControllerSourceType)sourceType;                 // returns YES if source is available (i.e. camera present)

#pragma mark -用于获得相机模式下支持的媒体类型
/**
 该方法主要用于获得相机模式下支持的媒体类型：sourceType是UIImagePickerControllerSourceTypeCamera时打印数组为：("public.image","public.movie") public.image表示静态图片，public.movie表示视频。当然也可以是图库或者是相机胶卷的，但是结果只有一个("public.image")

 使用：
for (NSString* mediaType in [UIImagePickerController availableMediaTypesForSourceType:UIImagePickerControllerSourceTypeCamera]) {
    if ([mediaType isEqualToString: (NSString *)kUTTypeImage]) {
        //支持拍照
        break;
    }
    if ([mediaType isEqualToString: (NSString *)kUTTypeMovie]) {
        //支持摄像
        break;
    }
}

 注解：
从上面的代码可以看到使用了两个常量：kUTTypeImage和kUTTypeMovie 这两个常量。在这里就要提一下UTI：iOS系统中为了更好的进行类型标识，而提供的一套共用的规范，也就是“Uniform Type Identifier”，一般称为“统一类型标识符”,简称为“UTI”。这两个常量是使用UTI定义的常量，表示"public.image","public.movie"。可以查看UTCoreTypes.h 文件
 */
+ (nullable NSArray<NSString *> *)availableMediaTypesForSourceType:(UIImagePickerControllerSourceType)sourceType; // returns array of available media types (i.e. kUTTypeImage)


#pragma mark -用于判断设备是否支持前置摄像头／后置摄像头
+ (BOOL)isCameraDeviceAvailable:(UIImagePickerControllerCameraDevice)cameraDevice                   NS_AVAILABLE_IOS(4_0); // returns YES if camera device is available

#pragma mark -用于判断设备前置摄像头／后置摄像头是否支持闪光灯
+ (BOOL)isFlashAvailableForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice           NS_AVAILABLE_IOS(4_0); // returns YES if camera device supports flash and torch.

#pragma mark -获得指定摄像头上的可用捕获模式，返回的是NSNumber *类型
/**
 使用：
for (NSNumber* captureMode in [UIImagePickerController availableCaptureModesForCameraDevice:(UIImagePickerControllerCameraDeviceRear)]) {
    if ([captureMode integerValue] == UIImagePickerControllerCameraCaptureModePhoto) {
        NSLog(@"拍照模式");
    }
    if ([captureMode integerValue] == UIImagePickerControllerCameraCaptureModeVideo) {
        NSLog(@"视频录制模式 ");
    }
}
 */
+ (nullable NSArray<NSNumber *> *)availableCaptureModesForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice NS_AVAILABLE_IOS(4_0); // returns array of NSNumbers (UIImagePickerControllerCameraCaptureMode)




#pragma mark - 🏃🏻‍♂️property 属性
#pragma mark -必须遵循里面的两个代理
@property(nullable,nonatomic,weak)      id <UINavigationControllerDelegate, UIImagePickerControllerDelegate> delegate;

#pragma mark -数据源类型
@property(nonatomic)           UIImagePickerControllerSourceType     sourceType;                                                        // default value is UIImagePickerControllerSourceTypePhotoLibrary.

#pragma mark -设置相机模式或者图库、相机胶卷模式下支持的媒体类型
/**
 默认是包含kUTTypeImage即("public.image")的数组，所以拍照时可以不用设置；但是当要录像的时候必须设置，可以设置为kUTTypeVideo（视频，但不带声音）或者kUTTypeMovie（视频并带有声音）
 */
@property(nonatomic,copy)      NSArray<NSString *>                   *mediaTypes;
// default value is an array containing kUTTypeImage.


#pragma mark -是否允许编辑，默认是NO
/**
 1、调用相机时
    allowsEditing = NO时，拍摄后的图片是不能拖动和缩放的，即不能编辑只能使用原图
 2、使用图库或相机胶卷时
    allowsEditing = NO时，只要你选中了图片不会出现上图中界面而知直接会调用代理方法，即无法查看大图及编辑。
 */
@property(nonatomic)           BOOL                                  allowsEditing NS_AVAILABLE_IOS(3_1);     // replacement for -allowsImageEditing; default value is NO.
@property(nonatomic)           BOOL                                  allowsImageEditing NS_DEPRECATED_IOS(2_0, 3_1);

@property(nonatomic)           UIImagePickerControllerImageURLExportPreset imageExportPreset NS_AVAILABLE_IOS(11_0);   // default value is UIImagePickerControllerImageExportPresetCompatible.

#pragma mark -视频最大录制时长，默认为10分钟。
/**
 video properties apply only if mediaTypes includes kUTTypeMovie
 仅适用于如果媒体类型（mediaTypes）包括kUTTypeMovie视频属性。
 */
@property(nonatomic)           NSTimeInterval                        videoMaximumDuration NS_AVAILABLE_IOS(3_1); // default value is 10 minutes.

#pragma mark -设置视频的质量
/**
 该属性默认是 UIImagePickerControllerQualityTypeMedium，如果相机设备不支持调整视频质量将使用默认值。
 */
@property(nonatomic)           UIImagePickerControllerQualityType    videoQuality NS_AVAILABLE_IOS(3_1);         // default value is UIImagePickerControllerQualityTypeMedium. If the cameraDevice does not support the videoQuality, it will use the default value.

@property(nonatomic, copy)     NSString                              *videoExportPreset NS_AVAILABLE_IOS(11_0);  // videoExportPreset can be used to specify the transcoding quality for videos (via a AVAssetExportPreset* string). If the value is nil (the default) then the transcodeQuality is determined by videoQuality instead. Not valid if the source type is UIImagePickerControllerSourceTypeCamera

#pragma mark - 是否显示默认相机UI
/**
 只有当sourceType是UIImagePickerControllerSourceTypeCamera时，才会添加使用。
 */
// camera additions available only if sourceType is UIImagePickerControllerSourceTypeCamera.
@property(nonatomic)           BOOL                                  showsCameraControls NS_AVAILABLE_IOS(3_1);   // set to NO to hide all standard camera UI. default is YES

#pragma mark -摄像头上覆盖的视图(浮于UIImagePickerController视图的最上方)
/**
 可用通过这个视图来自定义拍照或录像界面。值得注意的是当拍照/录像完成后该界面依然存在。
 */
@property(nullable, nonatomic,strong) __kindof UIView                *cameraOverlayView  NS_AVAILABLE_IOS(3_1);   // set a view to overlay the preview view.

#pragma mark -设置摄像头拍摄角度的形变
/**
 如 cameraPC.cameraViewTransform = CGAffineTransformMakeRotation(M_PI_2);// 平面旋转90度
 */
@property(nonatomic)           CGAffineTransform                     cameraViewTransform NS_AVAILABLE_IOS(3_1);   // set the transform of the preview view.

#pragma mark -编程方式拍照，在该方法执行结束会直接调用代理方法
- (void)takePicture NS_AVAILABLE_IOS(3_1);
// programatically initiates still image capture. ignored if image capture is in-flight.
// clients can initiate additional captures after receiving -imagePickerController:didFinishPickingMediaWithInfo: delegate callback

#pragma mark -编程方式开始录制视频
- (BOOL)startVideoCapture NS_AVAILABLE_IOS(4_0);
#pragma mark -编程方式停止录制视频
- (void)stopVideoCapture  NS_AVAILABLE_IOS(4_0);

#pragma mark -设置摄像头捕获模式
@property(nonatomic) UIImagePickerControllerCameraCaptureMode cameraCaptureMode NS_AVAILABLE_IOS(4_0); // default is UIImagePickerControllerCameraCaptureModePhoto

#pragma mark -设置摄像头装置
@property(nonatomic) UIImagePickerControllerCameraDevice      cameraDevice      NS_AVAILABLE_IOS(4_0); // default is UIImagePickerControllerCameraDeviceRear

#pragma mark -设置闪光灯模式
@property(nonatomic) UIImagePickerControllerCameraFlashMode   cameraFlashMode   NS_AVAILABLE_IOS(4_0); // default is UIImagePickerControllerCameraFlashModeAuto.
// cameraFlashMode controls the still-image flash when cameraCaptureMode is Photo. cameraFlashMode controls the video torch when cameraCaptureMode is Video.

@end


#pragma mark - 🏃🏻‍♂️Delegate 代理方法
__TVOS_PROHIBITED @protocol UIImagePickerControllerDelegate<NSObject>
@optional
// The picker does not dismiss itself; the client dismisses it in these callbacks.
// The delegate will receive one or the other, but not both, depending whether the user
// confirms or cancels.
#pragma mark -当拍照/录像完成或选择图片完成后都会走此代理方法
// 需要手动调用 dismiss方法
//- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(nullable NSDictionary<NSString *,id> *)editingInfo NS_DEPRECATED_IOS(2_0, 3_0);// 弃用
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info;

#pragma mark -当点击原生界面中的取消按钮后会执行此代理方法
// 需要手动调用 dismiss方法
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker;

@end



#pragma mark - 关于图片和视频的保存到相簿扩展方法
// Adds a photo to the saved photos album.  The optional completionSelector should have the form:
#pragma mark -将照片保存到相机胶卷 UIImageWriteToSavedPhotosAlbum
UIKIT_EXTERN void UIImageWriteToSavedPhotosAlbum(UIImage *image, __nullable id completionTarget, __nullable SEL completionSelector, void * __nullable contextInfo) __TVOS_PROHIBITED;
//将照片保存到相机胶卷回调
- (void)image:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;


#pragma mark -是否允许视频保存到相机胶卷 UIVideoAtPathIsCompatibleWithSavedPhotosAlbum
UIKIT_EXTERN BOOL UIVideoAtPathIsCompatibleWithSavedPhotosAlbum(NSString *videoPath) NS_AVAILABLE_IOS(3_1) __TVOS_PROHIBITED;
#pragma mark -将视频保存到相机胶卷 UISaveVideoAtPathToSavedPhotosAlbum
UIKIT_EXTERN void UISaveVideoAtPathToSavedPhotosAlbum(NSString *videoPath, __nullable id completionTarget, __nullable SEL completionSelector, void * __nullable contextInfo) NS_AVAILABLE_IOS(3_1) __TVOS_PROHIBITED;
// 将视频保存到相机胶卷回调
- (void)video:(NSString *)videoPath didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;

