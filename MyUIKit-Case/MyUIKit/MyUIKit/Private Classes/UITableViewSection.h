// 完全实现ok
#import <Foundation/Foundation.h>

@class UIView;

@interface UITableViewSection : NSObject

- (CGFloat)sectionHeight;

- (void)setNumberOfRows:(NSInteger)rows withHeights:(CGFloat *)newRowHeights;

@property (nonatomic, assign) CGFloat rowsHeight;
@property (nonatomic, assign) CGFloat headerHeight;
@property (nonatomic, assign) CGFloat footerHeight;
@property (nonatomic, readonly) NSInteger numberOfRows;
@property (nonatomic, readonly) CGFloat *rowHeights;
@property (nonatomic, strong) UIView *headerView;
@property (nonatomic, strong) UIView *footerView;
@property (nonatomic, copy) NSString *headerTitle;
@property (nonatomic, copy) NSString *footerTitle;

@end

