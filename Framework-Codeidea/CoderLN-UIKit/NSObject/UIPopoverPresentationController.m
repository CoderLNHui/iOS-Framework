/*
 * UIPopoverPresentationController.m
 *
 * UIKit (c) 2014-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */




#pragma mark - 场景

#pragma mark - barButtonItem点击调用
- (void)itemPop {
    //1.创建弹出的视图控制器（UIViewController的子类）
    LNModalTableVC * modalVc = [[LNModalTableVC alloc] init];
    modalVc.preferredContentSize = CGSizeMake(150, 150);
    modalVc.modalPresentationStyle = UIModalPresentationPopover;
    
    UIPopoverPresentationController *popPresentC = modalVc.popoverPresentationController;
    popPresentC.barButtonItem = self.item;
    popPresentC.permittedArrowDirections = UIPopoverArrowDirectionAny;
    popPresentC.delegate = self;
    [self presentViewController:modalVc animated:YES completion:nil];
}



#pragma mark - UIPopoverPresentationC基本使用
/**
 效果：点击PopBtn按钮调用，展示一个气泡控制器
 */
- (IBAction)popBtnClick:(UIButton *)btn {
    
    //1.创建弹出的视图控制器（UIViewController的子类）
    LNModalTableVC * modalVc = [[LNModalTableVC alloc] init];
    //2.设置菜单视图控制器显示大小（UITableView的Size要和preferredContentSize相同）
    modalVc.preferredContentSize = CGSizeMake(200, 200);
    //3.设置视图控制器模态的类型
    modalVc.modalPresentationStyle = UIModalPresentationPopover;
    
    // 创建气泡展示控制器
    UIPopoverPresentationController *popPresentC = modalVc.popoverPresentationController;
    //4.设置弹出的位置
    popPresentC.sourceView = btn;
    //5.设置箭头的位置
    popPresentC.sourceRect = [btn bounds];
    //6.设置弹出框的背景色（不同于视图控制器的视图背景色）
    popPresentC.backgroundColor = [UIColor whiteColor];
    //7.设置箭头的方向
    popPresentC.permittedArrowDirections = UIPopoverArrowDirectionRight;
    /*
     UIPopoverArrowDirectionUp     上,
     UIPopoverArrowDirectionDown   下,
     UIPopoverArrowDirectionLeft   左,
     UIPopoverArrowDirectionRight  右,
     UIPopoverArrowDirectionAny    系统判定
     */
    //8.设置代理，要遵守UIPopoverPresentationControllerDelegate协议
    popPresentC.delegate = self;
    
    //9.显示菜单
    [self presentViewController:modalVc animated:YES completion:nil];
}

#pragma mark - UIAdaptivePresentationControllerDelegate
//要实现的协议方法：
-(UIModalPresentationStyle)adaptivePresentationStyleForPresentationController:(UIPresentationController *)controller{
    return UIModalPresentationNone; //不适配
}
//点击蒙版popover消失， 默认YES，所以该方法可以不用实现。
- (BOOL)popoverPresentationControllerShouldDismissPopover:(UIPopoverPresentationController *)popoverPresentationController{
    return YES;
}
