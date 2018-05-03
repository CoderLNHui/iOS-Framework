/*
 * UIWebView.h 
 *
 * Framework: UIKit  (c) 2007-2015
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDataDetectors.h>
#import <UIKit/UIScrollView.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, UIWebViewNavigationType) {
    UIWebViewNavigationTypeLinkClicked,
    UIWebViewNavigationTypeFormSubmitted,
    UIWebViewNavigationTypeBackForward,
    UIWebViewNavigationTypeReload,
    UIWebViewNavigationTypeFormResubmitted,
    UIWebViewNavigationTypeOther
} __TVOS_PROHIBITED;

typedef NS_ENUM(NSInteger, UIWebPaginationMode) {
    UIWebPaginationModeUnpaginated,
    UIWebPaginationModeLeftToRight,
    UIWebPaginationModeTopToBottom,
    UIWebPaginationModeBottomToTop,
    UIWebPaginationModeRightToLeft
} __TVOS_PROHIBITED;

typedef NS_ENUM(NSInteger, UIWebPaginationBreakingMode) {
    UIWebPaginationBreakingModePage,
    UIWebPaginationBreakingModeColumn
} __TVOS_PROHIBITED;

@class UIWebViewInternal;
@protocol UIWebViewDelegate;

NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UIWebView : UIView <NSCoding, UIScrollViewDelegate>

@property (nullable, nonatomic, assign) id <UIWebViewDelegate> delegate;

@property (nonatomic, readonly, strong) UIScrollView *scrollView NS_AVAILABLE_IOS(5_0);



/**
 API提供了三种方法：
 */
- (void)loadRequest:(NSURLRequest *)request;
- (void)loadHTMLString:(NSString *)string baseURL:(nullable NSURL *)baseURL;
- (void)loadData:(NSData *)data MIMEType:(NSString *)MIMEType textEncodingName:(NSString *)textEncodingName baseURL:(NSURL *)baseURL;





@property (nullable, nonatomic, readonly, strong) NSURLRequest *request;

- (void)reload;// 刷新
- (void)stopLoading;// 停止刷新

- (void)goBack;// 返回
- (void)goForward;// 前进

@property (nonatomic, readonly, getter=canGoBack) BOOL canGoBack;// 返回
@property (nonatomic, readonly, getter=canGoForward) BOOL canGoForward;// 前进
@property (nonatomic, readonly, getter=isLoading) BOOL loading;// 刷新


// OC与JS交互方法
- (nullable NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)script;

// 设置网页自适应显示
@property (nonatomic) BOOL scalesPageToFit;

@property (nonatomic) BOOL detectsPhoneNumbers NS_DEPRECATED_IOS(2_0, 3_0);

// 设置显示特殊字符显示样式 (如：电话、网址 链接显示)
@property (nonatomic) UIDataDetectorTypes dataDetectorTypes NS_AVAILABLE_IOS(3_0);

@property (nonatomic) BOOL allowsInlineMediaPlayback NS_AVAILABLE_IOS(4_0); // iPhone Safari defaults to NO. iPad Safari defaults to YES
@property (nonatomic) BOOL mediaPlaybackRequiresUserAction NS_AVAILABLE_IOS(4_0); // iPhone and iPad Safari both default to YES

@property (nonatomic) BOOL mediaPlaybackAllowsAirPlay NS_AVAILABLE_IOS(5_0); // iPhone and iPad Safari both default to YES

@property (nonatomic) BOOL suppressesIncrementalRendering NS_AVAILABLE_IOS(6_0); // iPhone and iPad Safari both default to NO

@property (nonatomic) BOOL keyboardDisplayRequiresUserAction NS_AVAILABLE_IOS(6_0); // default is YES

@property (nonatomic) UIWebPaginationMode paginationMode NS_AVAILABLE_IOS(7_0);
@property (nonatomic) UIWebPaginationBreakingMode paginationBreakingMode NS_AVAILABLE_IOS(7_0);
@property (nonatomic) CGFloat pageLength NS_AVAILABLE_IOS(7_0);
@property (nonatomic) CGFloat gapBetweenPages NS_AVAILABLE_IOS(7_0);
@property (nonatomic, readonly) NSUInteger pageCount NS_AVAILABLE_IOS(7_0);

@property (nonatomic) BOOL allowsPictureInPictureMediaPlayback NS_AVAILABLE_IOS(9_0);

@property (nonatomic) BOOL allowsLinkPreview NS_AVAILABLE_IOS(9_0); // default is NO
@end

__TVOS_PROHIBITED @protocol UIWebViewDelegate <NSObject>

@optional
// 即将加载某个请求的时候调用  OC与JS交互代理方法
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;

// 开始加载调用
- (void)webViewDidStartLoad:(UIWebView *)webView;

// 加载完成调用
- (void)webViewDidFinishLoad:(UIWebView *)webView;

// 加载失败调用
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
