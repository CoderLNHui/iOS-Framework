/*
 * UIDocumentMenuViewController.h 
 *
 * UIKit (c) 2014-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIDocumentPickerViewController.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, UIDocumentMenuOrder) {
    UIDocumentMenuOrderFirst,
    UIDocumentMenuOrderLast
} NS_ENUM_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED;

__TVOS_PROHIBITED @protocol UIDocumentMenuDelegate <NSObject>

- (void)documentMenu:(UIDocumentMenuViewController *)documentMenu didPickDocumentPicker:(UIDocumentPickerViewController *)documentPicker;
@optional
- (void)documentMenuWasCancelled:(UIDocumentMenuViewController *)documentMenu;

@end

NS_CLASS_AVAILABLE_IOS(8_0) __TVOS_PROHIBITED @interface UIDocumentMenuViewController : UIViewController

- (instancetype)initWithDocumentTypes:(NSArray <NSString *> *)allowedUTIs inMode:(UIDocumentPickerMode)mode NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithURL:(NSURL *)url inMode:(UIDocumentPickerMode)mode NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (void)addOptionWithTitle:(NSString *)title image:(nullable UIImage *)image order:(UIDocumentMenuOrder)order handler:(void (^)(void))handler;

@property (nullable, nonatomic, weak) id<UIDocumentMenuDelegate> delegate;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
