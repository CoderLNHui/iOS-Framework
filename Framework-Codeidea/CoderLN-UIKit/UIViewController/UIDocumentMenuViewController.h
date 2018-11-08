/*
 * UIDocumentMenuViewController.h 
 *
 * UIKit (c) 2014-2017
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
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
