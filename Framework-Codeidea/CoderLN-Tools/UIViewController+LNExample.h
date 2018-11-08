/*
 * UIViewController+LNExample.h
 *
 * MJRefreshExample
 *「Public_不知名开发者 | https://github.com/CoderLN | https://www.jianshu.com/u/fd745d76c816」
 *
 * 各位厂友, 由于「时间 & 知识」有限, 总结的文章难免有「未全、不足」, 该模块将系统化学习, 后续「坚持新增文章, 替换、补充文章内容」
 */
 
/**
 利用runtime交换控制器的dealloc 和 自写deallocSwizzle两个方法的实现
 */


#import <UIKit/UIKit.h>

@interface UIViewController (LNExample)
@property (copy, nonatomic) NSString *method;
@end
