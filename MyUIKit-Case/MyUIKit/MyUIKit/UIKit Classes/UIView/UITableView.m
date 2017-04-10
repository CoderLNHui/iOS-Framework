//
//  UITableView.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//
/*
 UITableView的实现原理
 
 UITableView的难点在UITableViewCell和UITableViewHeaderFooterView的复用上。使用了_cachedCells，_reusableCells，_sections，_cachedHeaderFooterViews，_reusableHeaderFooterViews等可变字典和可变集合来实现复用。
 重点关注_layoutTableView方法,建议从layoutSubviews方法开始阅读
 
 */
//  http://www.jianshu.com/p/487020a72371  UITableView实现的文章
#import "UITableView.h"
#import "UIColor.h"
#import "UITableViewSection.h"
#import "UITableViewSectionLabel.h"
#import "UITableViewCell+UIPrivate.h"
#import "UITouch.h"
#import "UITableViewHeaderFooterView.h"

NSString *const UITableViewIndexSearch = @"{search}";

const CGFloat _UITableViewDefaultRowHeight = 43;
const CGFloat _UITableViewDefaultHeaderFooterView = 43;

@implementation UITableView
{
    BOOL _needsReload;
    NSIndexPath *_selectedRow;
    NSIndexPath *_highlightedRow;
    NSMutableDictionary *_cachedCells;/**<用于保存正在显示的Cell对象的引用*/
    NSMutableSet *_reusableCells;/**<用于保存存在但未显示在界面上的可复用的Cell*/
    NSMutableArray *_sections;/**<用于保存UITableViewSection的数组*/
    
    NSMutableDictionary *_cachedHeaderFooterViews;/**<用于保存正在显示的HeaderFooterView对象的引用*/
    NSMutableSet *_reusableHeaderFooterViews;/**<用于保存存在但未显示在界面上的可复用的HeaderFooterView*/
    
    struct {
        unsigned heightForRowAtIndexPath : 1;
        unsigned heightForHeaderInSection : 1;
        unsigned heightForFooterInSection : 1;
        unsigned viewForHeaderInSection : 1;
        unsigned viewForFooterInSection : 1;
        unsigned willSelectRowAtIndexPath : 1;
        unsigned didSelectRowAtIndexPath : 1;
        unsigned willDeselectRowAtIndexPath : 1;
        unsigned didDeselectRowAtIndexPath : 1;
        unsigned willBeginEditingRowAtIndexPath : 1;
        unsigned didEndEditingRowAtIndexPath : 1;
        unsigned titleForDeleteConfirmationButtonForRowAtIndexPath: 1;
    } _delegateHas;
    
    struct {
        unsigned numberOfSectionsInTableView : 1;
        unsigned titleForHeaderInSection : 1;
        unsigned titleForFooterInSection : 1;
        unsigned commitEditingStyle : 1;
        unsigned canEditRowAtIndexPath : 1;
    } _dataSourceHas;
}

- (id)initWithFrame:(CGRect)frame
{
    return [self initWithFrame:frame style:UITableViewStylePlain];
}

- (id)initWithFrame:(CGRect)frame style:(UITableViewStyle)theStyle
{
    if ((self = [super initWithFrame:frame])) {
        _style = theStyle;
        
        //_cachedCells 用于保存正在显示的Cell对象的引用
        
        _cachedCells = [[NSMutableDictionary alloc] init];
        
        //在计算完每个 section 包含的 section 头部，尾部视图的高度，和包含的每个 row 的整体高度后，
        //使用 UITableViewSection 对象对这些高度值进行保存，并将该 UITableViewSection 对象的引用
        //保存到 _sections中。在指定完 dataSource 后，至下一次数据源变化调用 reloadData 方法，
        //由于数据源没有变化，section 相关的高度值是不会变化，只需计算一次，所以需要缓存起来。
        _sections = [[NSMutableArray alloc] init];
        
         //_reusableCells用于保存存在但未显示在界面上的可复用的Cell
        _reusableCells = [[NSMutableSet alloc] init];
        
        _cachedHeaderFooterViews = [[NSMutableDictionary alloc] init];
        _reusableHeaderFooterViews = [[NSMutableSet alloc] init];
        
        self.separatorColor = [UIColor colorWithRed:.88f green:.88f blue:.88f alpha:1];
        self.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
        self.showsHorizontalScrollIndicator = NO;
        self.allowsSelection = YES;
        self.allowsSelectionDuringEditing = NO;
        self.sectionHeaderHeight = self.sectionFooterHeight = 22;
        self.alwaysBounceVertical = YES;
        
        if (_style == UITableViewStylePlain) {
            self.backgroundColor = [UIColor whiteColor];
        }
        
        [self _setNeedsReload];
    }
    return self;
}

- (void)setRowHeight:(CGFloat)newHeight
{
    _rowHeight = newHeight;
    [self setNeedsLayout];
}

#pragma mark - 更新Sections缓存
- (void)_updateSectionsCache
{
    for (UITableViewSection *previousSectionRecord in _sections) {
        [previousSectionRecord.headerView removeFromSuperview];
        [previousSectionRecord.footerView removeFromSuperview];
    }
    
    [_sections removeAllObjects];
    
    //如果数据源为空，不做任何处理
    if (_dataSource) {
        const CGFloat defaultRowHeight = _rowHeight ?: _UITableViewDefaultRowHeight;
        const NSInteger numberOfSections = [self numberOfSections];
        for (NSInteger section=0; section<numberOfSections; section++) {
            const NSInteger numberOfRowsInSection = [self numberOfRowsInSection:section];
            
            UITableViewSection *sectionRecord = [[UITableViewSection alloc] init];
            sectionRecord.headerTitle = _dataSourceHas.titleForHeaderInSection? [self.dataSource tableView:self titleForHeaderInSection:section] : nil;
            sectionRecord.footerTitle = _dataSourceHas.titleForFooterInSection? [self.dataSource tableView:self titleForFooterInSection:section] : nil;
            
            sectionRecord.headerHeight = _delegateHas.heightForHeaderInSection? [self.delegate tableView:self heightForHeaderInSection:section] : _sectionHeaderHeight;
            sectionRecord.footerHeight = _delegateHas.heightForFooterInSection ? [self.delegate tableView:self heightForFooterInSection:section] : _sectionFooterHeight;
            
            sectionRecord.headerView = (sectionRecord.headerHeight > 0 && _delegateHas.viewForHeaderInSection)? [self.delegate tableView:self viewForHeaderInSection:section] : nil;
            sectionRecord.footerView = (sectionRecord.footerHeight > 0 && _delegateHas.viewForFooterInSection)? [self.delegate tableView:self viewForFooterInSection:section] : nil;
            
            if (!sectionRecord.headerView && sectionRecord.headerHeight > 0 && sectionRecord.headerTitle) {
                sectionRecord.headerView = [UITableViewSectionLabel sectionLabelWithTitle:sectionRecord.headerTitle];
            }
            
            if (!sectionRecord.footerView && sectionRecord.footerHeight > 0 && sectionRecord.footerTitle) {
                sectionRecord.footerView = [UITableViewSectionLabel sectionLabelWithTitle:sectionRecord.footerTitle];
            }
            
            if (sectionRecord.headerView) {
                [self addSubview:sectionRecord.headerView];
            } else {
                sectionRecord.headerHeight = 0;
            }
            
            if (sectionRecord.footerView) {
                [self addSubview:sectionRecord.footerView];
            } else {
                sectionRecord.footerHeight = 0;
            }
            
            //section 中每个 row 的高度使用了数组指针来保存
            CGFloat *rowHeights = malloc(numberOfRowsInSection * sizeof(CGFloat));
            CGFloat totalRowsHeight = 0;
            
            //每行 row 的高度通过数据源实现的协议方法 heightForRowAtIndexPath: 返回，
            //若数据源没有实现该协议方法则使用默认的高度
            for (NSInteger row=0; row<numberOfRowsInSection; row++) {
                const CGFloat rowHeight = _delegateHas.heightForRowAtIndexPath? [self.delegate tableView:self heightForRowAtIndexPath:[NSIndexPath indexPathForRow:row inSection:section]] : defaultRowHeight;
                rowHeights[row] = rowHeight;
                totalRowsHeight += rowHeight;
            }
            
            sectionRecord.rowsHeight = totalRowsHeight;
            [sectionRecord setNumberOfRows:numberOfRowsInSection withHeights:rowHeights];
            free(rowHeights);
            
            //将所有高度信息缓存起来
            [_sections addObject:sectionRecord];
        }
    }
}

- (void)_updateSectionsCacheIfNeeded
{
    // 当_sections元素为空的时候，不执行任何操作
    if ([_sections count] == 0) {
        [self _updateSectionsCache];
    }
}

#pragma mark - 设置contentSize
- (void)_setContentSize
{
    [self _updateSectionsCacheIfNeeded];
    
    CGFloat height = _tableHeaderView? _tableHeaderView.frame.size.height : 0;
    
    for (UITableViewSection *section in _sections) {
        height += [section sectionHeight];
    }
    
    if (_tableFooterView) {
        height += _tableFooterView.frame.size.height;
    }
    // 高度主要由3部分组成，所有section的总高度，_tableHeaderView，_tableFooterView
    
    self.contentSize = CGSizeMake(0,height);
}

#pragma mark - 这个方法实现了UITableViewCell和UITableViewHeaderFooterView的复用
// 布局TableView的方法，这个是关键方法，需要仔细阅读
- (void)_layoutTableView
{
    //这个方法实现了 UITableViewCell和UITableViewHeaderFooterView 的复用
    
    const CGSize boundsSize = self.bounds.size;
    const CGFloat contentOffset = self.contentOffset.y;
    const CGRect visibleBounds = CGRectMake(0,contentOffset,boundsSize.width,boundsSize.height);
    CGFloat tableHeight = 0;
    
    if (_tableHeaderView) {
        CGRect tableHeaderFrame = _tableHeaderView.frame;
        tableHeaderFrame.origin = CGPointZero;
        tableHeaderFrame.size.width = boundsSize.width;
        _tableHeaderView.frame = tableHeaderFrame;
        tableHeight += tableHeaderFrame.size.height;
    }
    
    NSMutableDictionary *availableCells = [_cachedCells mutableCopy];
    NSMutableDictionary *availableHeaderFooterViews = [_cachedHeaderFooterViews mutableCopy];
    const NSInteger numberOfSections = [_sections count];
    [_cachedCells removeAllObjects];
    
    for (NSInteger section=0; section<numberOfSections; section++) {
        CGRect sectionRect = [self rectForSection:section];
        tableHeight += sectionRect.size.height;
        if (CGRectIntersectsRect(sectionRect, visibleBounds)) {
            const CGRect headerRect = [self rectForHeaderInSection:section];
            const CGRect footerRect = [self rectForFooterInSection:section];
            UITableViewSection *sectionRecord = [_sections objectAtIndex:section];
            const NSInteger numberOfRows = sectionRecord.numberOfRows;
            
            NSIndexPath *sectionIndexPath = [NSIndexPath indexPathWithIndex:section];
            // 复用sectionHeaderView
            UITableViewHeaderFooterView *sectionHeaderView = [availableHeaderFooterViews objectForKey:sectionIndexPath]?:[self.delegate tableView:self viewForHeaderInSection:section];
            sectionRecord.headerView = sectionHeaderView;
            if (sectionRecord.headerView) {
                sectionRecord.headerView.frame = headerRect;
            }
            
            // 复用sectionFooterView
            UITableViewHeaderFooterView *sectionFooterView = [availableHeaderFooterViews objectForKey:sectionIndexPath]?:[self.delegate tableView:self viewForFooterInSection:section];
            sectionRecord.footerView = sectionFooterView;
            if (sectionRecord.footerView) {
                sectionRecord.footerView.frame = footerRect;
            }
            
            for (NSInteger row=0; row<numberOfRows; row++) {
                NSIndexPath *indexPath = [NSIndexPath indexPathForRow:row inSection:section];
                CGRect rowRect = [self rectForRowAtIndexPath:indexPath];
                if (CGRectIntersectsRect(rowRect,visibleBounds) && rowRect.size.height > 0) {
                    
                    // 复用cell
                    UITableViewCell *cell = [availableCells objectForKey:indexPath] ?: [self.dataSource tableView:self cellForRowAtIndexPath:indexPath];
                    if (cell) {
                        [_cachedCells setObject:cell forKey:indexPath];
                        [availableCells removeObjectForKey:indexPath];
                        cell.highlighted = [_highlightedRow isEqual:indexPath];
                        cell.selected = [_selectedRow isEqual:indexPath];
                        cell.frame = rowRect;
                        cell.backgroundColor = self.backgroundColor;
                        [cell _setSeparatorStyle:_separatorStyle color:_separatorColor];
                        [self addSubview:cell];
                    }
                }
            }
        }
    }
    
    // 移除老的cells,保存任何可以被复用的cell
    for (UITableViewCell *cell in [availableCells allValues]) {
        if (cell.reuseIdentifier) {
            [_reusableCells addObject:cell];
        } else {
            [cell removeFromSuperview];
        }
    }
    
    // 把未出现在视野内的cell移除
    NSArray* allCachedCells = [_cachedCells allValues];
    for (UITableViewCell *cell in _reusableCells) {
        if (CGRectIntersectsRect(cell.frame,visibleBounds) && ![allCachedCells containsObject: cell]) {
            [cell removeFromSuperview];
        }
    }
    
    // 跟cell类似的操作
    for (UITableViewHeaderFooterView *headerFooterView in [availableHeaderFooterViews allKeys]) {
        if (headerFooterView.reuseIdentifier) {
            [_reusableHeaderFooterViews addObject:headerFooterView];
        }else {
            [headerFooterView removeFromSuperview];
        }
    }
    
    NSArray* allCachedHeaderFooterViews = [_cachedHeaderFooterViews allValues];
    for (UITableViewHeaderFooterView *headerFooterView in _reusableHeaderFooterViews) {
        if (CGRectIntersectsRect(headerFooterView.frame,visibleBounds) && ![allCachedHeaderFooterViews containsObject: headerFooterView]) {
            [headerFooterView removeFromSuperview];
        }
    }
    
    if (_tableFooterView) {
        CGRect tableFooterFrame = _tableFooterView.frame;
        tableFooterFrame.origin = CGPointMake(0,tableHeight);
        tableFooterFrame.size.width = boundsSize.width;
        _tableFooterView.frame = tableFooterFrame;
    }
}

- (CGRect)_CGRectFromVerticalOffset:(CGFloat)offset height:(CGFloat)height
{
    return CGRectMake(0,offset,self.bounds.size.width,height);
}

- (CGFloat)_offsetForSection:(NSInteger)index
{
    CGFloat offset = _tableHeaderView? _tableHeaderView.frame.size.height : 0;
    
    for (NSInteger s=0; s<index; s++) {
        offset += [[_sections objectAtIndex:s] sectionHeight];
    }
    
    return offset;
}

- (CGRect)rectForSection:(NSInteger)section
{
    [self _updateSectionsCacheIfNeeded];
    return [self _CGRectFromVerticalOffset:[self _offsetForSection:section] height:[[_sections objectAtIndex:section] sectionHeight]];
}

- (CGRect)rectForHeaderInSection:(NSInteger)section
{
    [self _updateSectionsCacheIfNeeded];
    return [self _CGRectFromVerticalOffset:[self _offsetForSection:section] height:[[_sections objectAtIndex:section] headerHeight]];
}

- (CGRect)rectForFooterInSection:(NSInteger)section
{
    [self _updateSectionsCacheIfNeeded];
    UITableViewSection *sectionRecord = [_sections objectAtIndex:section];
    CGFloat offset = [self _offsetForSection:section];
    offset += sectionRecord.headerHeight;
    offset += sectionRecord.rowsHeight;
    return [self _CGRectFromVerticalOffset:offset height:sectionRecord.footerHeight];
}

- (CGRect)rectForRowAtIndexPath:(NSIndexPath *)indexPath
{
    [self _updateSectionsCacheIfNeeded];
    
    if (indexPath && indexPath.section < [_sections count]) {
        UITableViewSection *sectionRecord = [_sections objectAtIndex:indexPath.section];
        const NSUInteger row = indexPath.row;
        
        if (row < sectionRecord.numberOfRows) {
            CGFloat *rowHeights = sectionRecord.rowHeights;
            CGFloat offset = [self _offsetForSection:indexPath.section];
            
            offset += sectionRecord.headerHeight;
            
            for (NSInteger currentRow=0; currentRow<row; currentRow++) {
                offset += rowHeights[currentRow];
            }
            
            return [self _CGRectFromVerticalOffset:offset height:rowHeights[row]];
        }
    }
    
    return CGRectZero;
}


- (UITableViewCell *)cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return [_cachedCells objectForKey:indexPath];
}

- (NSArray *)indexPathsForRowsInRect:(CGRect)rect
{
    
    [self _updateSectionsCacheIfNeeded];
    
    NSMutableArray *results = [[NSMutableArray alloc] init];
    const NSInteger numberOfSections = [_sections count];
    CGFloat offset = _tableHeaderView? _tableHeaderView.frame.size.height : 0;
    
    for (NSInteger section=0; section<numberOfSections; section++) {
        UITableViewSection *sectionRecord = [_sections objectAtIndex:section];
        CGFloat *rowHeights = sectionRecord.rowHeights;
        const NSInteger numberOfRows = sectionRecord.numberOfRows;
        
        offset += sectionRecord.headerHeight;
        
        if (offset + sectionRecord.rowsHeight >= rect.origin.y) {
            for (NSInteger row=0; row<numberOfRows; row++) {
                const CGFloat height = rowHeights[row];
                CGRect simpleRowRect = CGRectMake(rect.origin.x, offset, rect.size.width, height);
                
                if (CGRectIntersectsRect(rect,simpleRowRect)) {
                    [results addObject:[NSIndexPath indexPathForRow:row inSection:section]];
                } else if (simpleRowRect.origin.y > rect.origin.y+rect.size.height) {
                    break;
                }
                
                offset += height;
            }
        } else {
            offset += sectionRecord.rowsHeight;
        }
        
        offset += sectionRecord.footerHeight;
    }
    
    return results;
}

- (NSIndexPath *)indexPathForRowAtPoint:(CGPoint)point
{
    NSArray *paths = [self indexPathsForRowsInRect:CGRectMake(point.x,point.y,1,1)];
    return ([paths count] > 0)? [paths objectAtIndex:0] : nil;
}

#pragma mark - 可见的indexes的数组
- (NSArray *)indexPathsForVisibleRows
{
    [self _layoutTableView];
    
    NSMutableArray *indexes = [NSMutableArray arrayWithCapacity:[_cachedCells count]];
    const CGRect bounds = self.bounds;
    
    
    for (NSIndexPath *indexPath in [[_cachedCells allKeys] sortedArrayUsingSelector:@selector(compare:)]) {
        if (CGRectIntersectsRect(bounds,[self rectForRowAtIndexPath:indexPath])) {
            [indexes addObject:indexPath];
        }
    }
    
    return indexes;
}

- (NSArray *)visibleCells
{
    NSMutableArray *cells = [[NSMutableArray alloc] init];
    for (NSIndexPath *index in [self indexPathsForVisibleRows]) {
        UITableViewCell *cell = [self cellForRowAtIndexPath:index];
        if (cell) {
            [cells addObject:cell];
        }
    }
    return cells;
}

- (void)setTableHeaderView:(UIView *)newHeader
{
    if (newHeader != _tableHeaderView) {
        [_tableHeaderView removeFromSuperview];
        _tableHeaderView = newHeader;
        [self _setContentSize];
        [self addSubview:_tableHeaderView];
    }
}

- (void)setTableFooterView:(UIView *)newFooter
{
    if (newFooter != _tableFooterView) {
        [_tableFooterView removeFromSuperview];
        _tableFooterView = newFooter;
        [self _setContentSize];
        [self addSubview:_tableFooterView];
    }
}

- (void)setBackgroundView:(UIView *)backgroundView
{
    if (_backgroundView != backgroundView) {
        [_backgroundView removeFromSuperview];
        _backgroundView = backgroundView;
        [self insertSubview:_backgroundView atIndex:0];
    }
}

- (NSInteger)numberOfSections
{
    if (_dataSourceHas.numberOfSectionsInTableView) {
        return [self.dataSource numberOfSectionsInTableView:self];
    } else {
        return 1;
    }
}

- (NSInteger)numberOfRowsInSection:(NSInteger)section
{
    return [self.dataSource tableView:self numberOfRowsInSection:section];
}

- (void)reloadData
{
    //当数据源更新后，需要将所有显示的UITableViewCell和未显示可复用的UITableViewCell全部从父视图移除，
    //重新创建
    [[_cachedCells allValues] makeObjectsPerformSelector:@selector(removeFromSuperview)];
    [_reusableCells makeObjectsPerformSelector:@selector(removeFromSuperview)];
    [[_cachedHeaderFooterViews allKeys] makeObjectsPerformSelector:@selector(removeFromSuperview)];
    [_reusableHeaderFooterViews makeObjectsPerformSelector:@selector(removeFromSuperview)];
    [_reusableCells removeAllObjects];
    [_cachedCells removeAllObjects];
    [_reusableHeaderFooterViews removeAllObjects];
    [_cachedHeaderFooterViews removeAllObjects];
    
    // clear prior selection
    _selectedRow = nil;
    _highlightedRow = nil;
    
     // 重新计算 section 相关的高度值，并缓存起来
    [self _updateSectionsCache];
    [self _setContentSize];
    
    _needsReload = NO;
}

- (void)reloadRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation
{
    [self reloadData];
}

- (void)_reloadDataIfNeeded
{
    if (_needsReload) {
        [self reloadData];
    }
}

- (void)_setNeedsReload
{
    // 打上了需要reload的标志
    _needsReload = YES;
    [self setNeedsLayout];
}

- (void)layoutSubviews
{
    //对子视图进行布局，该方法会在第一次设置数据源调用 setNeedsLayout 方法后自动调用。
    //并且 UITableView 是继承自 UIScrollview ，当滚动时也会触发该方法的调用
    
    _backgroundView.frame = self.bounds;
    
    //在进行布局前必须确保 section 已经缓存了所有高度相关的信息
    [self _reloadDataIfNeeded];
    
    //对 UITableView 的 section 进行布局，包含 section 的头部，尾部，每一行 Cell
    [self _layoutTableView];
    
    //对 UITableView 的头视图，尾视图进行布局
    [super layoutSubviews];
}

- (void)setFrame:(CGRect)frame
{
    const CGRect oldFrame = self.frame;
    if (!CGRectEqualToRect(oldFrame,frame)) {
        [super setFrame:frame];
        
        if (oldFrame.size.width != frame.size.width) {
            [self _updateSectionsCache];
        }
        
        [self _setContentSize];
    }
}

- (NSIndexPath *)indexPathForSelectedRow
{
    return _selectedRow;
}

- (NSIndexPath *)indexPathForCell:(UITableViewCell *)cell
{
    for (NSIndexPath *index in [_cachedCells allKeys]) {
        if ([_cachedCells objectForKey:index] == cell) {
            return index;
        }
    }
    
    return nil;
}

- (void)deselectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated
{
    if (indexPath && [indexPath isEqual:_selectedRow]) {
        [self cellForRowAtIndexPath:_selectedRow].selected = NO;
        _selectedRow = nil;
    }
}

- (void)selectRowAtIndexPath:(NSIndexPath *)indexPath animated:(BOOL)animated scrollPosition:(UITableViewScrollPosition)scrollPosition
{
    [self _reloadDataIfNeeded];
    
    if (![_selectedRow isEqual:indexPath]) {
        [self deselectRowAtIndexPath:_selectedRow animated:animated];
        _selectedRow = indexPath;
        [self cellForRowAtIndexPath:_selectedRow].selected = YES;
    }
    
    [self scrollToRowAtIndexPath:_selectedRow atScrollPosition:scrollPosition animated:animated];
}

- (void)_setUserSelectedRowAtIndexPath:(NSIndexPath *)rowToSelect
{
    if (_delegateHas.willSelectRowAtIndexPath) {
        rowToSelect = [self.delegate tableView:self willSelectRowAtIndexPath:rowToSelect];
    }
    
    NSIndexPath *selectedRow = [self indexPathForSelectedRow];
    
    if (selectedRow && ![selectedRow isEqual:rowToSelect]) {
        NSIndexPath *rowToDeselect = selectedRow;
        
        if (_delegateHas.willDeselectRowAtIndexPath) {
            rowToDeselect = [self.delegate tableView:self willDeselectRowAtIndexPath:rowToDeselect];
        }
        
        [self deselectRowAtIndexPath:rowToDeselect animated:NO];
        
        if (_delegateHas.didDeselectRowAtIndexPath) {
            [self.delegate tableView:self didDeselectRowAtIndexPath:rowToDeselect];
        }
    }
    
    [self selectRowAtIndexPath:rowToSelect animated:NO scrollPosition:UITableViewScrollPositionNone];
    
    if (_delegateHas.didSelectRowAtIndexPath) {
        [self.delegate tableView:self didSelectRowAtIndexPath:rowToSelect];
    }
}

- (void)_scrollRectToVisible:(CGRect)aRect atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated
{
    if (!CGRectIsNull(aRect) && aRect.size.height > 0) {
        
        switch (scrollPosition) {
            case UITableViewScrollPositionNone:
                break;
                
            case UITableViewScrollPositionTop:
                aRect.size.height = self.bounds.size.height;
                break;
                
            case UITableViewScrollPositionMiddle:
                aRect.origin.y -= (self.bounds.size.height / 2.f) - aRect.size.height;
                aRect.size.height = self.bounds.size.height;
                break;
                
            case UITableViewScrollPositionBottom:
                aRect.origin.y -= self.bounds.size.height - aRect.size.height;
                aRect.size.height = self.bounds.size.height;
                break;
        }
        
        [self scrollRectToVisible:aRect animated:animated];
    }
}

- (void)scrollToNearestSelectedRowAtScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated
{
    [self _scrollRectToVisible:[self rectForRowAtIndexPath:[self indexPathForSelectedRow]] atScrollPosition:scrollPosition animated:animated];
}

- (void)scrollToRowAtIndexPath:(NSIndexPath *)indexPath atScrollPosition:(UITableViewScrollPosition)scrollPosition animated:(BOOL)animated
{
    [self _scrollRectToVisible:[self rectForRowAtIndexPath:indexPath] atScrollPosition:scrollPosition animated:animated];
}

- (void)setEditing:(BOOL)editing animated:(BOOL)animate
{
    _editing = editing;
    // 调用开始编辑的方法
    [self _beginEditingRowAtIndexPath:nil];
}

- (void)setEditing:(BOOL)editing
{
    [self setEditing:editing animated:NO];
}

- (void)insertSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation
{
    [self reloadData];
}

- (void)deleteSections:(NSIndexSet *)sections withRowAnimation:(UITableViewRowAnimation)animation
{
    [self reloadData];
}

- (void)insertRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation
{
    [self reloadData];
}

- (void)deleteRowsAtIndexPaths:(NSArray *)indexPaths withRowAnimation:(UITableViewRowAnimation)animation
{
    [self reloadData];
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (!_highlightedRow) {
        UITouch *touch = [touches anyObject];
        const CGPoint location = [touch locationInView:self];
        
        _highlightedRow = [self indexPathForRowAtPoint:location];
        [self cellForRowAtIndexPath:_highlightedRow].highlighted = YES;
    }
    
    if (_highlightedRow) {
        [self cellForRowAtIndexPath:_highlightedRow].highlighted = NO;
        [self _setUserSelectedRowAtIndexPath:_highlightedRow];
        _highlightedRow = nil;
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (_highlightedRow) {
        [self cellForRowAtIndexPath:_highlightedRow].highlighted = NO;
        _highlightedRow = nil;
    }
}

- (BOOL)_canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    return _dataSourceHas.commitEditingStyle && (!_dataSourceHas.canEditRowAtIndexPath || [_dataSource tableView:self canEditRowAtIndexPath:indexPath]);
}
- (void)_beginEditingRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([self _canEditRowAtIndexPath:indexPath]) {
        self.editing = YES;
        
        if (_delegateHas.willBeginEditingRowAtIndexPath) {
            [self.delegate tableView:self willBeginEditingRowAtIndexPath:indexPath];
        }
        for (UITableViewCell *cell in [_cachedCells allValues]) {
            cell.editing = YES;
        }
        
        [self performSelector:@selector(_showEditMenuForRowAtIndexPath:) withObject:indexPath afterDelay:0];
    }
}

#pragma mark - 这里是监听cell右边点击删除按钮的代理方法，在UITableViewCell里面我就没写实现了
- (void)clickDeleteButton:(UITableViewCell *)cell
{
    if (_dataSourceHas.commitEditingStyle) {
        [_dataSource tableView:self commitEditingStyle:UITableViewCellEditingStyleDelete forRowAtIndexPath:nil];
    }
    
    cell.highlighted = NO;

    [self _endEditingRowAtIndexPath:nil];
}

- (void)_endEditingRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (self.editing) {
        self.editing = NO;
        
        if (_delegateHas.didEndEditingRowAtIndexPath) {
            [self.delegate tableView:self didEndEditingRowAtIndexPath:indexPath];
        }
        for (UITableViewCell *cell in [_cachedCells allValues]) {
            cell.editing = NO;
        }
    }
}
- (void)_showEditMenuForRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([self _canEditRowAtIndexPath:indexPath]) {
        NSArray *visibleCells = [self visibleCells];
        for (UITableViewCell *cell in visibleCells) {
            NSString *menuItemTitle = nil;
            
            // fetch the title for the delete menu item
            if (_delegateHas.titleForDeleteConfirmationButtonForRowAtIndexPath) {
                menuItemTitle = [self.delegate tableView:self titleForDeleteConfirmationButtonForRowAtIndexPath:indexPath];
            }
            if ([menuItemTitle length] == 0) {
                menuItemTitle = @"Delete";
            }
            
            cell.highlighted = YES;
        }
    }
}


#pragma mark - 根据identifier取出对应的UITableViewCell
- (UITableViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier
{
    //遍历_reusableCells，根据identifier取对应的UITableViewCell，取到就返回，否则返回nil
    for (UITableViewCell *cell in _reusableCells) {
        if ([cell.reuseIdentifier isEqualToString:identifier]) {
            
            // 这里strongCell的作用是防止cell立刻被释放，增加一个强引用
            UITableViewCell *strongCell = cell;
            [_reusableCells removeObject:cell];
            [strongCell prepareForReuse];
            return strongCell;
        }
    }
    
    return nil;
}

#pragma mark - 设置dataSource代理
- (void)setDataSource:(id<UITableViewDataSource>)newSource
{
    _dataSource = newSource;
    
    _dataSourceHas.numberOfSectionsInTableView = [_dataSource respondsToSelector:@selector(numberOfSectionsInTableView:)];
    _dataSourceHas.titleForHeaderInSection = [_dataSource respondsToSelector:@selector(tableView:titleForHeaderInSection:)];
    _dataSourceHas.titleForFooterInSection = [_dataSource respondsToSelector:@selector(tableView:titleForFooterInSection:)];
    _dataSourceHas.commitEditingStyle = [_dataSource respondsToSelector:@selector(tableView:commitEditingStyle:forRowAtIndexPath:)];
    _dataSourceHas.canEditRowAtIndexPath = [_dataSource respondsToSelector:@selector(tableView:canEditRowAtIndexPath:)];
    
    [self _setNeedsReload];
}

#pragma mark - 设置delegate代理
- (void)setDelegate:(id<UITableViewDelegate>)newDelegate
{
    [super setDelegate:newDelegate];
    
    _delegateHas.heightForRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:heightForRowAtIndexPath:)];
    _delegateHas.heightForHeaderInSection = [newDelegate respondsToSelector:@selector(tableView:heightForHeaderInSection:)];
    _delegateHas.heightForFooterInSection = [newDelegate respondsToSelector:@selector(tableView:heightForFooterInSection:)];
    _delegateHas.viewForHeaderInSection = [newDelegate respondsToSelector:@selector(tableView:viewForHeaderInSection:)];
    _delegateHas.viewForFooterInSection = [newDelegate respondsToSelector:@selector(tableView:viewForFooterInSection:)];
    _delegateHas.willSelectRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:willSelectRowAtIndexPath:)];
    _delegateHas.didSelectRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:didSelectRowAtIndexPath:)];
    _delegateHas.willDeselectRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:willDeselectRowAtIndexPath:)];
    _delegateHas.didDeselectRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:didDeselectRowAtIndexPath:)];
    _delegateHas.willBeginEditingRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:willBeginEditingRowAtIndexPath:)];
    _delegateHas.didEndEditingRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:didEndEditingRowAtIndexPath:)];
    _delegateHas.titleForDeleteConfirmationButtonForRowAtIndexPath = [newDelegate respondsToSelector:@selector(tableView:titleForDeleteConfirmationButtonForRowAtIndexPath:)];
}

@end

@implementation NSIndexPath (UITableView)

+ (instancetype)indexPathForRow:(NSInteger)row inSection:(NSInteger)section
{
    NSUInteger path[2] = {section, row};
    return [self indexPathWithIndexes:path length:2];
}

- (NSInteger)row
{
    return [self indexAtPosition:1];
}

- (NSInteger)section
{
    return [self indexAtPosition:0];
}

@end
