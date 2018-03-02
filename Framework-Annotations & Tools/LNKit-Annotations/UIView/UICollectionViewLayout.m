
/************************************************************************
 *                                                                      *
 *                    👣 WechatPublic - Codeidea 👣                     *
 *                      @Email: pbwaterln@sina.com                      *
 *                                                                      *
 *         |用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 |      *
 *                                                                      *
 *                      ⚠️ 转载请告知 且 注明出处 蟹蟹 ⚠️                   *
 ************************************************************************/


#pragma mark - ↑
#pragma mark - 注解

/*
 自定义布局:只要了解5个方法
 重写方法,扩展功能
 
 // 调用:collectionView第一次布局,collectionView刷新的时候也会调用
 // 作用:计算cell的布局，条件:ell的位置是固定不变的.
 - (void)prepareLayout;
 
 // 作用:指定一段区域给你这段区域cell的尺寸(可以一次性返回所有cell尺寸,也可以每隔一个距离返回cell)
 - (nullable NSArray<__kindof UICollectionViewLayoutAttributes *> *)layoutAttributesForElementsInRect:(CGRect)rect;
 
 // 在滚动的时候是否允许刷新(Invalidate)布局
 - (BOOL)shouldInvalidateLayoutForBoundsChange:(CGRect)newBounds;
 
 // 调用:用户手指一松开就会调用
 // 作用:确定最终偏移量
 - (CGPoint)targetContentOffsetForProposedContentOffset:(CGPoint)proposedContentOffset withScrollingVelocity:(CGPoint)velocity;
 
 // 由于UICollectionVeiw继承自UIScrollView，所以需要重写该函数，告诉contentSize内容尺寸大小
 - (CGSize)collectionViewContentSize;
 
 UICollectionViewLayoutAttributes:确定cell的尺寸,一个LayoutAttributes对象就对应一个cell,拿到LayoutAttributes相当于拿到cell
 */


/**
 在初始化一个UICollectionViewLayout实例后,会有一系列准备方法被自动调用,以保证layout实例的正确
 首先, - (void)prepareLayout;将被调用, 默认该方法什么没做,但是在自己的子类实现中,一般在该方法中设定一些必要的layout的结果和初始需要的参数等;
 
 其次, - (CGSize)collectionViewContentSize;将被调用, 以确定collection应该占据的尺寸, 注意这里的尺寸不是指可视部分的尺寸,而应该是所有内容所占的尺寸,collectionView的本质是一个scrollView, 因此需要这个尺寸来配置滚动范围.
 
 然后, - (nullable NSArray *)layoutAttributesForElementsInRect; 被调用。 初始的layout的外观由该方法返回的LayoutAttributes决定的。
 */
