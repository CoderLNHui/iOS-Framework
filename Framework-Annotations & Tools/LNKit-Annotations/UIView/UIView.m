 


//--------------------------- 【属性】 ------------------------------//
//

1.
frame 和 center 参照是父视图的坐标系统，而 bounds 参照的是当前视图的坐标系统，所以 bounds 的坐标原点一般是{0,0}（注意：在 UIScrollView 中设置 bounds 原点不为{0,0}，来显示不一样的效果）

2.
UIView 的动画
苹果分别在如下几个类别中提供了很多动画处理的静态方法：
UIView (UIViewAnimation)
UIView (UIViewAnimationWithBlocks)
UIView (UIViewKeyframeAnimations)






//--------------------------- 【方法】 ------------------------------//
//

1.
#warning【File: UIView.h】
- (void)setNeedsLayout;




2.
#warning【File: UIView.h】
- (void)layoutIfNeeded;






3.
#warning【File: UIView.h】
- (void)layoutSubviews;
/**
【layoutSubviews: 一下情况会触发调用】
 init 初始化不会触发 layoutSubviews
 addSubview 会触发 layoutSubviews
 设置 view的Frame 会触发 layoutSubviews，当然前提是frame的值设置前后发生了变化
 滚动一个 UIScrollView 会触发 layoutSubviews
 旋转Screen会触发父UIView上的 layoutSubviews 事件
 改变一个UIView大小的时候也会触发父UIView上的 layoutSubviews 事件
 */




//--------------------------- 【需求】 ------------------------------//
//

1.如果需要从父视图中批量删除子视图，可以使用下面的代码：

NSArray *subViews = self.subViews;
if([subViews count] != 0) {
    [subViews makeObjectPerformSelector:@selector(removeFromSuperview)];
}


2.
UIView与CLayer之间的关系
1).UIView和CALayer是相互依赖的关系，UIView依赖与CALayer提供的内容(又高于CALayer)，通过调用drawRect方法来渲染自身的内容，调节CALayer属性可以调整UIView的外观；

2).CALayer依赖UIView提供的容器来显示绘制的内容。CALayer基于图像管理内容并允许你在这些内容上创建动画。UIView本身，更像是一个CALayer的管理器，访问它的跟绘图和坐标有关的属性，如frame，bounds等，实际上内部都是访问它所在CALayer的相关属性

3).如果没有CALayer，UIView自身也不会存在，UIView是一个特殊的CALayer实现，添加了响应事件的能力。一言以蔽之，UIView来自CALayer，高于CALayer，是CALayer高层实现与封装；UIView的很多特性都源于CALayer对它的支持。

4).在创建UIView对象时，UIView内部会自动创建一个图层(即CALayer对象)，通过UIView的layer属性可以访问这个层

5).当UIView需要显示到屏幕上时 4.1 会调用drawRect:方法进行绘图，并且会将所有内容绘制在自己的图层layer属性上 4.2 绘图完毕后，系统会将图层拷贝到屏幕上，于是就完成了UIView的显示

6).通过CALayer改变UIView的形状

borderColor属性：边框颜色。
borderWidth属性：边框宽度。
cornerRadius属性：边框转角半径（实现圆角效果）。
7).通过CALayer添加动画效果

transforms属性：指定对CALayer中的内容做怎样的变换，支持3D效果和动画。
 








