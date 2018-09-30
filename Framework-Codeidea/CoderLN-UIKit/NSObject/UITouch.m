/*
 * UITouch.h
 *
 * UIKit (c) 2007-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */


















#pragma mark - 场景思维

#pragma mark -view跟着手指移动
// 触摸时开始移动时调用
- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    // 做UIView的拖拽(anyObject任意一个)
    UITouch *touch = [touches anyObject];
    
    // 求偏移量 = 手指当前点的X - 手指上一点的X
    CGPoint curP = [touch locationInView:self];
    CGPoint preP = [touch previousLocationInView:self];
    //NSLog(@"curP=%@,preP=%@",NSStringFromCGPoint(curP),NSStringFromCGPoint(preP));

    CGFloat offsetX = curP.x - preP.x;
    CGFloat offsetY = curP.y - preP.y;
    // 平移
    self.transform = CGAffineTransformTranslate(self.transform, offsetX, offsetY);
}
