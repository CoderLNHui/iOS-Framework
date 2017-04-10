//
//  UIViewController.m
//  MyUIKit
//
//  Created by dengxiang on 2017/1/6.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIViewController.h"
#import "UIViewController+UIPrivate.h"
#import "UIView+UIPrivate.h"
#import "UINavigationItem.h"
#import "UINavigationController.h"
#import "UIToolbar.h"
#import "UIBarButtonItem.h"
#import "UISplitViewController.h"
#import "UIWindow.h"
#import "UIScreen.h"

typedef NS_ENUM(NSInteger, _UIViewControllerParentageTransition) {
    _UIViewControllerParentageTransitionNone = 0,
    _UIViewControllerParentageTransitionToParent,
    _UIViewControllerParentageTransitionFromParent,
};

@implementation UIViewController
{
    UIView *_view;
    UINavigationItem *_navigationItem;
    NSMutableArray *_childViewControllers;
    __unsafe_unretained UIViewController *_parentViewController;
    
    NSUInteger _appearanceTransitionStack;// 定义一个NSUInteger来管理栈的数量
    BOOL _appearanceTransitionIsAnimated;
    BOOL _viewIsAppearing;
    _UIViewControllerParentageTransition _parentageTransition;
    
    NSString *_nibName;
    NSBundle *_nibBundle;
}

- (id)init
{
    return [self initWithNibName:nil bundle:nil];
}
- (id)initWithNibName:(NSString *)nibName bundle:(NSBundle *)nibBundle
{
    if ((self = [super init])) {
        _contentSizeForViewInPopover = CGSizeMake(320,1100);
        _hidesBottomBarWhenPushed = NO;
        _nibName = nibName;
        _nibBundle = nibBundle;
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(didReceiveMemoryWarning) name:UIApplicationDidReceiveMemoryWarningNotification object:[UIApplication sharedApplication]];
    }
    return self;
}
- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidReceiveMemoryWarningNotification object:[UIApplication sharedApplication]];
    [_view _setViewController:nil];
}
- (NSString *)nibName
{
    return _nibName;
}

- (NSBundle *)nibBundle
{
    return _nibBundle;
}
- (UIResponder *)nextResponder
{
    return _view.superview;
}

- (BOOL)isViewLoaded
{
    return (_view != nil);
}
- (UIView *)view
{
    if ([self isViewLoaded]) {
        return _view;
    } else {
        const BOOL wereEnabled = [UIView areAnimationsEnabled];
        [UIView setAnimationsEnabled:NO];
        [self loadView];
        [self viewDidLoad];
        [UIView setAnimationsEnabled:wereEnabled];
        return _view;
    }
}
- (void)setView:(UIView *)aView
{
    if (aView != _view) {
        [_view _setViewController:nil];
        _view = aView;
        [_view _setViewController:self];
    }
}
- (void)loadView
{
    // 为了方便，长宽写死了，应该用全屏长宽
    self.view = [[UIView alloc] initWithFrame:CGRectMake(0,0,320,480)];
}
- (void)viewDidLoad
{
}

- (void)viewDidUnload
{
}

- (void)didReceiveMemoryWarning
{
}

- (void)viewWillAppear:(BOOL)animated
{
}

- (void)viewDidAppear:(BOOL)animated
{
}

- (void)viewWillDisappear:(BOOL)animated
{
}

- (void)viewDidDisappear:(BOOL)animated
{
}

- (void)viewWillLayoutSubviews
{
}

- (void)viewDidLayoutSubviews
{
}

- (UIInterfaceOrientation)interfaceOrientation
{
    return (UIInterfaceOrientation)UIDeviceOrientationPortrait;
}

- (UINavigationItem *)navigationItem
{
    if (!_navigationItem) {
        _navigationItem = [[UINavigationItem alloc] initWithTitle:self.title];
    }
    return _navigationItem;
}
- (void)setTitle:(NSString *)title
{
    if (![_title isEqual:title]) {
        _title = [title copy];
        _navigationItem.title = _title;
    }
}
- (void)setToolbarItems:(NSArray *)theToolbarItems animated:(BOOL)animated
{
    if (![_toolbarItems isEqual:theToolbarItems]) {
        _toolbarItems = theToolbarItems;
        [self.navigationController.toolbar setItems:_toolbarItems animated:animated];
    }
}
- (void)setToolbarItems:(NSArray *)theToolbarItems
{
    [self setToolbarItems:theToolbarItems animated:NO];
}

- (void)setEditing:(BOOL)editing animated:(BOOL)animated
{
    _editing = editing;
}

- (void)setEditing:(BOOL)editing
{
    [self setEditing:editing animated:NO];
}
- (UIBarButtonItem *)editButtonItem
{
    // this should really return a fancy bar button item that toggles between edit/done and sends setEditing:animated: messages to this controller
    
    UIBarButtonItem *editButtonItem = nil;
    // 这里应该调用[UIBarButtonItem alloc] initWithCustomView方法 这是一个button，分2种状态，文字分别为edit/done
    return editButtonItem;
}

- (void)presentViewController:(UIViewController *)viewControllerToPresent animated:(BOOL)flag completion:(void (^)(void))completion
{
    //iOS6 以后，苹果抛弃了下面这个方法，使用上面的方法，可以多一个回调
    [self presentModalViewController:viewControllerToPresent animated:YES];
    completion();
}

- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion
{
    [self dismissModalViewControllerAnimated:YES];
    completion();
}

- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated
{
    // 总结来说，这个方法就是把selfView隐藏，然后把newView加上来，然后在合适的时机调用了viewWillAppear，viewWillDisappear，viewDidDisappear，viewDidAppear  这就是为什么这四个方法是按这样的顺序调用的根本原因
     if (!_modalViewController && _modalViewController != self) {
     _modalViewController = modalViewController;
     [_modalViewController _setParentViewController:self];
     
     UIWindow *window = self.view.window;
     UIView *selfView = self.view;
     UIView *newView = _modalViewController.view;
     
     newView.autoresizingMask = selfView.autoresizingMask;
     newView.frame = _wantsFullScreenLayout? window.screen.bounds : window.screen.applicationFrame;
        if (animated)
         {
             // 这里加了个UIView动画，除此之外跟下面一样，就不写了
             switch (self.modalTransitionStyle) {
                     //  根据样式的不同，调用不同的uiview动画
                 case UIModalTransitionStyleCoverVertical:
                     
                     break;
                 case UIModalTransitionStyleFlipHorizontal:
                     
                     break;
                 case UIModalTransitionStyleCrossDissolve:
                     
                     break;
                 case UIModalTransitionStylePartialCurl:
                     
                     break;
                     
                 default:
                     break;
             }
         }
         else
         {
             [window addSubview:newView];
             [_modalViewController viewWillAppear:animated];
             
             [self viewWillDisappear:animated];
             selfView.hidden = YES;
             [self viewDidDisappear:animated];
             
             [_modalViewController viewDidAppear:animated];
         }
     
         
     }
}

- (void)dismissModalViewControllerAnimated:(BOOL)animated
{
    // 有动画的情况我就不写了，无非是多加了个UIView方法
     if (_modalViewController)
     {
    
         if (_modalViewController.modalViewController)
         {
            [_modalViewController dismissModalViewControllerAnimated:animated];
         }
         
         self.view.hidden = NO;
         [self viewWillAppear:animated];
         
         [_modalViewController.view removeFromSuperview];
         [_modalViewController _setParentViewController:nil];
         _modalViewController = nil;
         
         [self viewDidAppear:animated];
         
     } else
     {
         [self.parentViewController dismissModalViewControllerAnimated:animated];
     }

}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
}

- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation duration:(NSTimeInterval)duration
{
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
}

- (id)_nearestParentViewControllerThatIsKindOf:(Class)c
{
    UIViewController *controller = _parentViewController;
    
    while (controller && ![controller isKindOfClass:c]) {
        controller = [controller parentViewController];
    }
    
    return controller;
}

- (UINavigationController *)navigationController
{
    return [self _nearestParentViewControllerThatIsKindOf:[UINavigationController class]];
}

- (UISplitViewController *)splitViewController
{
    Class c = NSClassFromString(@"UISplitViewController");
    return [self _nearestParentViewControllerThatIsKindOf:c];
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@: %p; title = %@; view = %@>", [self className], self, self.title, self.view];
}


- (BOOL)isMovingFromParentViewController
{
    return (_appearanceTransitionStack > 0) && (_parentageTransition == _UIViewControllerParentageTransitionFromParent);
}

- (BOOL)isMovingToParentViewController
{
    return (_appearanceTransitionStack > 0) && (_parentageTransition == _UIViewControllerParentageTransitionToParent);
}

- (BOOL)isBeingPresented
{
    return (_appearanceTransitionStack > 0) && (NO);
}

- (BOOL)isBeingDismissed
{
    return (_appearanceTransitionStack > 0) && (NO);
}

- (UIViewController *)presentingViewController
{
    // TODO
    return nil;
}

- (UIViewController *)presentedViewController
{
    // TODO
    return nil;
}

- (NSArray *)childViewControllers
{
    return [_childViewControllers copy];
}

- (void)addChildViewController:(UIViewController *)childController
{
    NSAssert(childController != nil, @"cannot add nil child view controller");
    NSAssert(childController.parentViewController == nil, @"thou shalt have no other parent before me");
    
    if (!_childViewControllers) {
        _childViewControllers = [NSMutableArray arrayWithCapacity:1];
    }
    
    [childController willMoveToParentViewController:self];
    [_childViewControllers addObject:childController];
    childController->_parentViewController = self;
}

- (void)_removeFromParentViewController
{
    if (_parentViewController) {
        [_parentViewController->_childViewControllers removeObject:self];
        
        if ([_parentViewController->_childViewControllers count] == 0) {
            _parentViewController->_childViewControllers = nil;
        }
        
        _parentViewController = nil;
    }
}
- (void)_setParentViewController:(UIViewController *)theViewController
{
    _parentViewController = theViewController;
}
- (void)removeFromParentViewController
{
    NSAssert(self.parentViewController != nil, @"view controller has no parent");
    
    [self _removeFromParentViewController];
    [self didMoveToParentViewController:nil];
}

- (BOOL)shouldAutomaticallyForwardRotationMethods
{
    return YES;
}

- (BOOL)shouldAutomaticallyForwardAppearanceMethods
{
    return YES;
}

- (void)transitionFromViewController:(UIViewController *)fromViewController toViewController:(UIViewController *)toViewController duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion
{
    NSAssert(fromViewController.parentViewController == toViewController.parentViewController && fromViewController.parentViewController != nil, @"child controllers must share common parent");
    const BOOL animated = (duration > 0);
    
    [fromViewController beginAppearanceTransition:NO animated:animated];
    [toViewController beginAppearanceTransition:YES animated:animated];
    
    [UIView transitionWithView:self.view
                      duration:duration
                       options:options
                    animations:^{
                        if (animations) {
                            animations();
                        }
                        
                        [self.view addSubview:toViewController.view];
                    }
                    completion:^(BOOL finished) {
                        if (completion) {
                            completion(finished);
                        }
                        
                        [fromViewController.view removeFromSuperview];
                        
                        [fromViewController endAppearanceTransition];
                        [toViewController endAppearanceTransition];
                    }];
}

- (void)beginAppearanceTransition:(BOOL)isAppearing animated:(BOOL)animated
{
    if (_appearanceTransitionStack == 0 || (_appearanceTransitionStack > 0 && _viewIsAppearing != isAppearing)) {
        _appearanceTransitionStack = 1;
        _appearanceTransitionIsAnimated = animated;
        _viewIsAppearing = isAppearing;
        
        if ([self shouldAutomaticallyForwardAppearanceMethods]) {
            for (UIViewController *child in self.childViewControllers) {
                if ([child isViewLoaded] && [child.view isDescendantOfView:self.view]) {
                    [child beginAppearanceTransition:isAppearing animated:animated];
                }
            }
        }
        
        if (_viewIsAppearing) {
            [self view];    // ensures the view is loaded before viewWillAppear: happens
            [self viewWillAppear:_appearanceTransitionIsAnimated];
        } else {
            [self viewWillDisappear:_appearanceTransitionIsAnimated];
        }
    } else {
        _appearanceTransitionStack++;
    }
}

- (void)endAppearanceTransition
{
    if (_appearanceTransitionStack > 0) {
        _appearanceTransitionStack--;
        
        if (_appearanceTransitionStack == 0) {
            if ([self shouldAutomaticallyForwardAppearanceMethods]) {
                for (UIViewController *child in self.childViewControllers) {
                    [child endAppearanceTransition];
                }
            }
            
            if (_viewIsAppearing) {
                [self viewDidAppear:_appearanceTransitionIsAnimated];
            } else {
                [self viewDidDisappear:_appearanceTransitionIsAnimated];
            }
        }
    }
}

- (void)willMoveToParentViewController:(UIViewController *)parent
{
    if (parent) {
        _parentageTransition = _UIViewControllerParentageTransitionToParent;
    } else {
        _parentageTransition = _UIViewControllerParentageTransitionFromParent;
    }
}

- (void)didMoveToParentViewController:(UIViewController *)parent
{
    _parentageTransition = _UIViewControllerParentageTransitionNone;
}



@end
