
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
 注解：
 在初始化一个UICollectionViewLayout实例后,会有一系列准备方法被自动调用，从开始加载内容的时候，便默默的做了很多事：首先是去调用 prepareLayout; 准备布局，然后根据当前屏幕所处位置返回该位置layoutAttributesForElementsInRect:所有cell尺寸，得到每一个视图的UICollectionViewLayoutAttributes属性，然后在把视图按UICollectionViewLayoutAttributes中的属性描述设置视图collectionViewContentSize;具体的center、size等等，期间也会去调用其他方法去确定一些间距。所以UICollectionViewLayoutAttributes是每个视图决定性的布局的属性。
 
 在需要更新 layout 时，需要给当前 layout 发送 -invalidateLayout，该消息会立即返回，并且预约在下一个 loop 的时候刷新当前的 layout，这一点和 UIView 的 setNeedsLayout 方法类似。在 -invalidateLayout 后的下一个collectionView的刷新loop中，又会从 perpareLayout 开始，一次再调用 -collectionViewContentSize: 和 layoutAttributesForElementsInRect: 来生成更新后的布局。
 
 
 
 
    1.首先, - (void)prepareLayout;将被调用, 默认该方法什么没做,但是在自己的子类实现中,一般在该方法中设定一些必要的layout的结果和初始需要的参数等;

    2.其次, - (CGSize)collectionViewContentSize;将被调用, 以确定collection应该占据的尺寸, 注意这里的尺寸不是指可视部分的尺寸,而应该是所有内容所占的尺寸,collectionView的本质是一个scrollView, 因此需要这个尺寸来配置滚动范围.

    3.然后, - (nullable NSArray *)layoutAttributesForElementsInRect; 被调用。 初始的layout的外观由该方法返回的LayoutAttributes决定的。
 */


























