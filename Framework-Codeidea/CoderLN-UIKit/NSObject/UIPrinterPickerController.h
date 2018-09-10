/*
 * UIPrinterPickerController.h
 *
 * UIKit (c) 2013-2016
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class UIPrinterPickerController, UIPrinter, UIView, UIViewController, UIBarButtonItem;

typedef void (^UIPrinterPickerCompletionHandler)(UIPrinterPickerController *printerPickerController, BOOL userDidSelect, NSError * __nullable error);

__TVOS_PROHIBITED
@protocol UIPrinterPickerControllerDelegate <NSObject>
@optional

- (nullable UIViewController *)printerPickerControllerParentViewController:(UIPrinterPickerController *)printerPickerController;
/*!
 *  @method     printerPickerController:shouldShowPrinter:
 *  @discussion	Use to filter out specific printers from the printer picker.
 * 	        Evaluate the UIPrinter object and returns YES if the printer should
 * 	        be shown, NO otherwise.
 *		This delegate can assume that all UIPrinter properties are available
 *		(the contactPrinter: method need not be called).
 * 	        This method may be called from threads other than the main thread,
 * 	        and may be called simultaneously from several different threads.
 */
- (BOOL)printerPickerController:(UIPrinterPickerController *)printerPickerController shouldShowPrinter:(UIPrinter *)printer;

- (void)printerPickerControllerWillPresent:(UIPrinterPickerController *)printerPickerController;
- (void)printerPickerControllerDidPresent:(UIPrinterPickerController *)printerPickerController;
- (void)printerPickerControllerWillDismiss:(UIPrinterPickerController *)printerPickerController;
- (void)printerPickerControllerDidDismiss:(UIPrinterPickerController *)printerPickerController;

- (void)printerPickerControllerDidSelectPrinter:(UIPrinterPickerController *)printerPickerController;

@end

NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UIPrinterPickerController : NSObject

/*!
 *  @method     printerPickerControllerWithInitiallySelectedPrinter:
 *  @discussion This method returns a printer picker controller object for showing the
 *              UI that allows the user to select a printer. This is only used with the
 *              UIPrintInteractionController's printWithoutUIToPrinter: method.
 *              If no printer should be preselected, use a value of nil for the parameter.
 */
+ (UIPrinterPickerController *)printerPickerControllerWithInitiallySelectedPrinter:(nullable UIPrinter *)printer;

/*!
 * @discussion	The selected printer. Set this before presenting the UI to show the currently
 * 	        selected printer. Use this to determine which printer the user selected.
 */
@property(nullable,nonatomic,readonly) UIPrinter *selectedPrinter;

@property(nullable,nonatomic,weak) id<UIPrinterPickerControllerDelegate> delegate;

- (BOOL)presentAnimated:(BOOL)animated completionHandler:(nullable UIPrinterPickerCompletionHandler)completion;                                                // iPhone
- (BOOL)presentFromRect:(CGRect)rect inView:(UIView *)view animated:(BOOL)animated completionHandler:(nullable UIPrinterPickerCompletionHandler)completion;    // iPad
- (BOOL)presentFromBarButtonItem:(UIBarButtonItem *)item animated:(BOOL)animated completionHandler:(nullable UIPrinterPickerCompletionHandler)completion;      // iPad
- (void)dismissAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
