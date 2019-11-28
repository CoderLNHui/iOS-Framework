/*
 * UITableViewHeaderFooterView.h 
 *
 * UIKit (c) 2008-2017
 */
 
#import <Foundation/Foundation.h>
#import <UIKit/UIView.h>
#import <UIKit/UITableView.h>

// Either the header or footer for a section
NS_ASSUME_NONNULL_BEGIN

#pragma mark - 头尾视图
NS_CLASS_AVAILABLE_IOS(6_0) @interface UITableViewHeaderFooterView : UIView

#pragma mark -初始化
- (instancetype)initWithReuseIdentifier:(nullable NSString *)reuseIdentifier NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

#pragma mark -文字
@property (nonatomic, readonly, strong, nullable) UILabel *textLabel;
#pragma mark -详情文字
@property (nonatomic, readonly, strong, nullable) UILabel *detailTextLabel; // only supported for headers in grouped style

#pragma mark -内容视图
@property (nonatomic, readonly, strong) UIView *contentView;
#pragma mark -背景视图
@property (nonatomic, strong, nullable) UIView *backgroundView;
#pragma mark -标识
@property (nonatomic, readonly, copy, nullable) NSString *reuseIdentifier;

#pragma mark -复用时调用
- (void)prepareForReuse NS_REQUIRES_SUPER;  // if the view is reusable (has a reuse identifier), this is called just before the view is returned from the table view method dequeueReusableHeaderFooterViewWithIdentifier:.  If you override, you MUST call super.

@end
NS_ASSUME_NONNULL_END
