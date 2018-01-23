/*
 * UIScrollView.m
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2007-2016
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 👣
 */



#pragma mark - ↑
#pragma mark - UIScrollView概念 & 重要属性

/**
 UIScrollView是一个非常重要的控件,其可以展示比设备屏幕更大区域的内容,我们可以通过手指滑动来查看内容视图的每一部分内容,也可以通过手指捏合来对内容视图进行缩放操作,UITableView、UICollectionView和UITextView等常用控件全部继承自UIScrollView,而UIWebView控件内部也是基于UIScrollView实现的,我们每天开发中都不断显式或隐式地与UIScrollView打交道
 
 contentSize.height : 所有内容的总高度
 
 contentInset : 在内容周围额外增加的间距（内边距），始终粘着内容
 
 ontentOffset : 内容距离frame矩形框，偏移了多少
 
 contentOffset.x == contentSize最左边 - frame最左边 的差值
 
 contentOffset.y == contentSize顶部 - frame顶部 的差值
 
 frame : 是以父控件内容的左上角为坐标原点{0, 0}
 
 bounds : 是以自己内容的左上角为坐标原点{0, 0}
 






 
#pragma mark - ↑
#pragma mark - 常见需求原理解析

#pragma mark - 1.导航栏半透明效果
/**
 原理解析:
 
 默认情况下,在有UINavigationBar存在时,系统为了防止UIScrollView被遮挡,其contentInset和scrollIndicatorInsets属性都会被设置为UIEdgeInsetsMake(64, 0, 0, 0);在有UITabBar存在时,系统为了防止UIScrollView被遮挡,其contentInset和scrollIndicatorInsets属性都会被设置为UIEdgeInsetsMake(0, 0, 49, 0)
 
 因此,为了使用此种半透明效果,可以直接将UIScrollView的frame设置为整个屏幕的大小
 
 注1: 系统只在UIScrollView是控制器视图的第0个子视图时才会自动修改contentInset和scrollIndicatorInsets属性
 
 注2: 如果不想让系统自动修改contentInset和scrollIndicatorInsets属性,可以设置self.automaticallyAdjustsScrollViewInsets = NO;

 */





#pragma mark - 2.控件悬停
/**
 原理解析:
 
 方式一: 在悬停位置放置一个与待悬停控件相同的控件,通过-scrollViewDidScroll:代理方法跟踪contentOffset的的变化,当不满足悬停条件时,将该控件hidden属性设置为YES;当满足悬停条件时,将该控件hidden属性设置为NO
 
 方式二: 通过-scrollViewDidScroll:代理方法跟踪contentOffset的的变化,当不满足悬停条件时,待悬停控件属于UIScrollView的子视图,当满足悬停条件时,待悬停控件属于UIScrollView的父视图的子视图
 */



#pragma mark - 3.下拉头部图片放大
/**
 原理解析:
 
 通过-scrollViewDidScroll:代理方法跟踪contentOffset的的变化,根据contentOffset动态设置图片的缩放比例
 
 */



#pragma mark - 4.图片无限轮播
/**
 原理解析:
 
 在已知图片数组有N个元素前提下,在UIScrollView中创建N+2个UIImageView,其中第1个至第N个图片为真实内容,第0个与第N个一样,第N+1个与第1个一样,通过-scrollViewDidScroll:代理方法跟踪contentOffset的的变化,在滑动到首尾两个图片处直接设置contentOffset到真实图片处即可
 */










#pragma mark - ↑
#pragma mark - 常用功能性代码案例

/**
// 以"控件悬停方式二"为例
- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    if (scrollView.contentOffset.y >= 100)
    {
        CGRect rect = label.frame;
        rect.origin.y = 0;
        label.frame = rect;
        
        [self.view addSubview:label];
    }
    else
    {
        CGRect rect = label.frame;
        rect.origin.y = 100;
        label.frame = rect;
        
        [scrollView addSubview:label];
    }
}
*/



/**
// 下拉头部图片放大: 以"动态修改图片缩放比例于1倍和2倍之间"为例
- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    CGFloat scale = 1 - (scrollView.contentOffset.y / 100);
    scale = (scale >= 1) ? scale : 1;
    scale = (scale <= 2) ? scale : 2;
    imageView.transform = CGAffineTransformMakeScale(scale, scale);
}

*/




/**
 1.高效图片轮播，两个ImageView实现
 http://www.jianshu.com/p/ef03ec7f23b2
 
 */







































































