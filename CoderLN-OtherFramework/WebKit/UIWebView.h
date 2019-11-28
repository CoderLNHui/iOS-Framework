/*
 * UIWebView.h 
 *
 * UIKit (c) 2007-2017
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>
#import <UIKit/UIDataDetectors.h>
#import <UIKit/UIScrollView.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - NS_ENUM
#pragma mark -导航类型
typedef NS_ENUM(NSInteger, UIWebViewNavigationType) {
    UIWebViewNavigationTypeLinkClicked,
    UIWebViewNavigationTypeFormSubmitted,
    UIWebViewNavigationTypeBackForward,
    UIWebViewNavigationTypeReload,
    UIWebViewNavigationTypeFormResubmitted,
    UIWebViewNavigationTypeOther
} __TVOS_PROHIBITED;

#pragma mark -标记页码方式
typedef NS_ENUM(NSInteger, UIWebPaginationMode) {
    UIWebPaginationModeUnpaginated,
    UIWebPaginationModeLeftToRight,
    UIWebPaginationModeTopToBottom,
    UIWebPaginationModeBottomToTop,
    UIWebPaginationModeRightToLeft
} __TVOS_PROHIBITED;

#pragma mark -标记页码阻断方式
typedef NS_ENUM(NSInteger, UIWebPaginationBreakingMode) {
    UIWebPaginationBreakingModePage,
    UIWebPaginationBreakingModeColumn
} __TVOS_PROHIBITED;

@class UIWebViewInternal;
@protocol UIWebViewDelegate;

NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UIWebView : UIView <NSCoding, UIScrollViewDelegate>

@property (nullable, nonatomic, assign) id <UIWebViewDelegate> delegate;

@property (nonatomic, readonly, strong) UIScrollView *scrollView NS_AVAILABLE_IOS(5_0);



#pragma mark - API提供了三种方法加载
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


#pragma mark - OC与JS交互方法
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

#pragma mark -即将加载某个请求的时候调用  OC与JS交互代理方法
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;

#pragma mark -开始加载调用
- (void)webViewDidStartLoad:(UIWebView *)webView;

#pragma mark -加载完成调用
- (void)webViewDidFinishLoad:(UIWebView *)webView;

#pragma mark -加载失败调用
- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error;

@end

