
#import "UITableViewSection.h"
#import "UIView.h"

@implementation UITableViewSection

- (CGFloat)sectionHeight
{
    return self.rowsHeight + self.headerHeight + self.footerHeight;
}

- (void)setNumberOfRows:(NSInteger)rows withHeights:(CGFloat *)newRowHeights
{
    _rowHeights = realloc(_rowHeights, sizeof(CGFloat) * rows);
    memcpy(_rowHeights, newRowHeights, sizeof(CGFloat) * rows);
    _numberOfRows = rows;
}

- (void)dealloc
{
    if (_rowHeights) free(_rowHeights);
}
@end
