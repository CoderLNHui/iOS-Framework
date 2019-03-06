/*
 * UIActivityViewController.h 
 *
 * UIKit (c) 2012-2017
 * 不知名开发者 - 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIActivity.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^UIActivityViewControllerCompletionHandler)(UIActivityType __nullable activityType, BOOL completed);
typedef void (^UIActivityViewControllerCompletionWithItemsHandler)(UIActivityType __nullable activityType, BOOL completed, NSArray * __nullable returnedItems, NSError * __nullable activityError);

NS_CLASS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED @interface UIActivityViewController : UIViewController

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithActivityItems:(NSArray *)activityItems applicationActivities:(nullable NSArray<__kindof UIActivity *> *)applicationActivities NS_DESIGNATED_INITIALIZER;

@property(nullable, nonatomic, copy) UIActivityViewControllerCompletionHandler completionHandler NS_DEPRECATED_IOS(6_0, 8_0, "Use completionWithItemsHandler instead.");  // set to nil after call
@property(nullable, nonatomic, copy) UIActivityViewControllerCompletionWithItemsHandler completionWithItemsHandler NS_AVAILABLE_IOS(8_0); // set to nil after call

@property(nullable, nonatomic, copy) NSArray<UIActivityType> *excludedActivityTypes; // default is nil. activity types listed will not be displayed

@end
NS_ASSUME_NONNULL_END
