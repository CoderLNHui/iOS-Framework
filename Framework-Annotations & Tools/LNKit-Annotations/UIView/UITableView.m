/*
 * File:  UITableView.m
 * Framework:  UIKit
 * Author:  白水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2005-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


#pragma mark - UITableView常用属性

// 全局设置行row高
self.tableView.rowHeight = 100;

// 全局设置区头(区尾)高
self.tableView.sectionHeaderHeight = 50;
self.tableView.sectionFooterHeight = 50;

// 设置分割线的样式、颜色和铺满
self.tableView.separatorStyle = UITableViewCellSeparatorStyleSingleLine;
self.tableView.separatorColor = [UIColor redColor];
_tableView.separatorInset = UIEdgeInsetsMake(0, 0, 0, 0);


// 设置tableView表格头(尾)视图
self.tableView.tableHeaderView = [[UISwitch alloc] init];
self.tableView.tableFooterView = [[UISwitch alloc] init];


// 隐藏多余分割线
self.tableView.tableFooterView = [[UIView alloc] init];

// 背景视图 和 背景颜色
self.tableView.backgroundView = [[UIView alloc] init];
self.tableView.backgroundColor = [UIColor grayColor];


// 设置TableView的cell的估算高度(性能优化), 这里高度也不是越大越好，要适时而定
self.tableView.estimatedRowHeight = 100;

// 索引文字 和 背景颜色
self.tableView.sectionIndexColor = [UIColor grayColor];
self.tableView.sectionIndexBackgroundColor = [UIColor yellowColor];











#pragma mark - ↑
#pragma mark - UITableView代理方法




























#pragma mark - ↑
#pragma mark - UITableView场景
#pragma mark - 分割线顶头
/**
 方式一:iOS7之前
 self.tableView.separatorInset = UIEdgeInsetsZero;
 
 方式二:iOS7之后，但是我们还是能够达到同样的效果，你可以在你的tablevView的代理协议实现界面加上下面这段代码：
-(void)viewDidLayoutSubviews
{
    if ([self.tableView respondsToSelector:@selector(setSeparatorInset:)]) {
        [self.tableView setSeparatorInset:UIEdgeInsetsMake(0,0,0,0)];
    }
    
    if ([self.tableView respondsToSelector:@selector(setLayoutMargins:)]) {
        [self.tableView setLayoutMargins:UIEdgeInsetsMake(0,0,0,0)];
    }
}
-(void)tableView:(UITableView *)tableView willDisplayCell:(UITableViewCell *)cell forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([cell respondsToSelector:@selector(setSeparatorInset:)]) {
        [cell setSeparatorInset:UIEdgeInsetsZero];
    }
    if ([cell respondsToSelector:@selector(setLayoutMargins:)]) {
        [cell setLayoutMargins:UIEdgeInsetsZero];
    }
}
 

 */





#pragma mark - 动态的计算cell的高度
//
/**
 很多情况下我们的UITableViewCell的高度是动态不确定的，比如说很多聊天的界面都需要我们去动态的计算cell的高度，你可能会在heightForRowAtIndexPath代理协议方法中返回你计算好的cell高度，然后在苹果推出约束以后，我们其实有更加方便的方法去实现相同的效果。你可以尝试在你的代码中加入以下两行代码：这两行代码必须配合约束来使用。

 self.tableView.estimatedRowHeight = 68.0;
 self.tableView.rowHeight = UITableViewAutomaticDimension;
 
 
 */






#pragma mark - UITableView的优化
/**
 
 UITableView的优化主要从三个方面入手：
 
 1.提前计算并缓存好高度（布局），因为heightForRowAtIndexPath:是调用最频繁的方法；
 2.异步绘制，遇到复杂界面，遇到性能瓶颈时，可能就是突破口；
 3.滑动时按需加载，这个在大量图片展示，网络加载的时候很管用！（SDWebImage已经实现异步加载，配合这条性能杠杠的）。
 
 
 
 除了上面最主要的三个方面外，还有很多几乎大伙都很熟知的优化点：
 
 1.正确使用reuseIdentifier来重用Cells
 2.尽量使所有的view opaque，包括Cell自身
 3.尽量少用或不用透明图层
 4.如果Cell内现实的内容来自web，使用异步加载，缓存请求结果
 5.减少subviews的数量
 6.在heightForRowAtIndexPath:中尽量不使用cellForRowAtIndexPath:，如果你需要用到它，只用一次然后缓存结果
 7.尽量少用addView给Cell动态添加View，可以初始化时就添加，然后通过hide来控制是否显示
 
 */
















































