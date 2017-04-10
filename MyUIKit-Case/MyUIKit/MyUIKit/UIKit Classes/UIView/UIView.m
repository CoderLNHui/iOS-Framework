//
//  UIView.m
//  MyUIKit
//
//  Created by Jackdx on 17/1/5.
//  Copyright © 2017年 Jack. All rights reserved.
//

#import "UIView.h"
#import "UIViewAnimationGroup.h"
#import <QuartzCore/CALayer.h>
#import "UIViewLayoutManager.h"
#import "UIView+UIPrivate.h"
#import "UIViewController.h"
#import "UIAppearanceInstance.h"
#import "UIWindow.h"
#import "UIScreen.h"
#import "UIColor.h"
#import "UIColor+UIPrivate.h"
#import <CoreGraphics/CoreGraphics.h>
#import "UIColorRep.h"
#import "UIGestureRecognizer.h"
#import "UIGestureRecognizer+UIPrivate.h"

NSString *const UIViewFrameDidChangeNotification = @"UIViewFrameDidChangeNotification";
NSString *const UIViewBoundsDidChangeNotification = @"UIViewBoundsDidChangeNotification";
NSString *const UIViewDidMoveToSuperviewNotification = @"UIViewDidMoveToSuperviewNotification";
NSString *const UIViewHiddenDidChangeNotification = @"UIViewHiddenDidChangeNotification";

static NSMutableArray *_animationGroups;
static BOOL _animationsEnabled = YES;

@implementation UIView
{
    __unsafe_unretained UIView *_superview;
    __unsafe_unretained UIViewController *_viewController;
    NSMutableSet *_subviews; // subviews前面的属性是NSArray，在.m里面是NSMutableSet类型
    BOOL _implementsDrawRect;
    NSMutableSet *_gestureRecognizers; // gestureRecognizers 同理
}

+ (void)initialize
{
    if (self == [UIView class]) {
        _animationGroups = [[NSMutableArray alloc] init];
    }
}

+ (Class)layerClass
{
    return [CALayer class];
}
+ (BOOL)_instanceImplementsDrawRect
{
    return [UIView instanceMethodForSelector:@selector(drawRect:)] != [self instanceMethodForSelector:@selector(drawRect:)];
}

- (id)init
{
    return [self initWithFrame:CGRectZero];
}
- (id)initWithFrame:(CGRect)theFrame
{
    if ((self=[super init])) {
        _implementsDrawRect = [[self class] _instanceImplementsDrawRect];
        _clearsContextBeforeDrawing = YES;
        _autoresizesSubviews = YES;
        _userInteractionEnabled = YES;
        _subviews = [[NSMutableSet alloc] init];
        _gestureRecognizers = [[NSMutableSet alloc] init];
        
        _layer = [[[[self class] layerClass] alloc] init];
        _layer.delegate = self;
        _layer.layoutManager = [UIViewLayoutManager layoutManager];
        
        self.contentMode = UIViewContentModeScaleToFill;
        self.contentScaleFactor = 0;
        self.frame = theFrame;
        self.alpha = 1;
        self.opaque = YES;
        [self setNeedsDisplay];
    }
    return self;
}
- (void)dealloc
{
    [_gestureRecognizers makeObjectsPerformSelector:@selector(_setView:) withObject:nil];
    [[_subviews allObjects] makeObjectsPerformSelector:@selector(_removeFromDeallocatedSuperview)];
    
    _layer.layoutManager = nil;
    _layer.delegate = nil;
    [_layer removeFromSuperlayer];
}

- (void)_setViewController:(UIViewController *)theViewController
{
    _viewController = theViewController;
}

- (UIViewController *)_viewController
{
    return _viewController;
}

- (UIWindow *)window
{
    return _superview.window;
}

- (UIResponder *)nextResponder
{
    return (UIResponder *)[self _viewController] ?: (UIResponder *)_superview;
}
- (id)_UIAppearanceContainer
{
    return self.superview;
}

- (NSArray *)subviews
{
    NSArray *sublayers = _layer.sublayers;
    NSMutableArray *subviews = [NSMutableArray arrayWithCapacity:[sublayers count]];
    
    for (CALayer *layer in sublayers) {
        id potentialView = [layer delegate];
        if ([_subviews containsObject:potentialView]) {
            [subviews addObject:potentialView];
        }
    }
    return subviews;
}
- (void)_willMoveFromWindow:(UIWindow *)fromWindow toWindow:(UIWindow *)toWindow
{
    if (fromWindow != toWindow) {
        
        if ([self isFirstResponder]) {
            [self resignFirstResponder];
        }
        
        [self _UIAppearanceSetNeedsUpdate];
        [self willMoveToWindow:toWindow];
        
        for (UIView *subview in self.subviews) {
            [subview _willMoveFromWindow:fromWindow toWindow:toWindow];
        }
        
        [[self _viewController] beginAppearanceTransition:(toWindow != nil) animated:NO];
    }
}
- (void)_didMoveToScreen
{
    if (_implementsDrawRect && self.contentScaleFactor != self.window.screen.scale) {
        self.contentScaleFactor = self.window.screen.scale;
    } else {
        [self setNeedsDisplay];
    }
    
    for (UIView *subview in self.subviews) {
        [subview _didMoveToScreen];
    }
}

- (void)_didMoveFromWindow:(UIWindow *)fromWindow toWindow:(UIWindow *)toWindow
{
    if (fromWindow != toWindow) {
        [self didMoveToWindow];
        
        for (UIView *subview in self.subviews) {
            [subview _didMoveFromWindow:fromWindow toWindow:toWindow];
        }
        
        UIViewController *controller = [self _viewController];
        
        if (controller) {
            if ([[self class] _isAnimating]) {
                void (^completionBlock)(BOOL) = [[self class] _animationCompletionBlock];
                
                [[self class] _setAnimationCompletionBlock:^(BOOL finished) {
                    [controller endAppearanceTransition];
                    
                    if (completionBlock) {
                        completionBlock(finished);
                    }
                }];
            } else {
                
                [controller performSelector:@selector(endAppearanceTransition) withObject:nil afterDelay:0];
            }
        }
    }
}
- (void)addSubview:(UIView *)subview
{
    NSAssert((!subview || [subview isKindOfClass:[UIView class]]), @"the subview must be a UIView");
    
    if (subview && subview.superview != self) {
        UIWindow *oldWindow = subview.window;
        UIWindow *newWindow = self.window;
        
        [subview _willMoveFromWindow:oldWindow toWindow:newWindow];
        [subview willMoveToSuperview:self];
        
        if (subview.superview) {
            [subview.layer removeFromSuperlayer];
            [subview.superview->_subviews removeObject:subview];
        }
        
        [subview willChangeValueForKey:@"superview"];
        [_subviews addObject:subview];
        subview->_superview = self;
        [_layer addSublayer:subview.layer];
        [subview didChangeValueForKey:@"superview"];
        
        if (oldWindow.screen != newWindow.screen) {
            [subview _didMoveToScreen];
        }
        
        [subview _didMoveFromWindow:oldWindow toWindow:newWindow];
        [subview didMoveToSuperview];
        
        [[NSNotificationCenter defaultCenter] postNotificationName:UIViewDidMoveToSuperviewNotification object:subview];
        
        [self didAddSubview:subview];
    }
}
- (void)insertSubview:(UIView *)subview atIndex:(NSInteger)index
{
    [self addSubview:subview];
    [_layer insertSublayer:subview.layer atIndex:index];
}

- (void)insertSubview:(UIView *)subview belowSubview:(UIView *)below
{
    [self addSubview:subview];
    [_layer insertSublayer:subview.layer below:below.layer];
}

- (void)insertSubview:(UIView *)subview aboveSubview:(UIView *)above
{
    [self addSubview:subview];
    [_layer insertSublayer:subview.layer above:above.layer];
}

- (void)bringSubviewToFront:(UIView *)subview
{
    if (subview.superview == self) {
        [_layer insertSublayer:subview.layer above:[[_layer sublayers] lastObject]];
    }
}

- (void)sendSubviewToBack:(UIView *)subview
{
    if (subview.superview == self) {
        [_layer insertSublayer:subview.layer atIndex:0];
    }
}
- (void)_abortGestureRecognizers
{
    UIApplicationInterruptTouchesInView(self);
}

- (void)_removeFromDeallocatedSuperview
{
    _superview = nil;
    [self _abortGestureRecognizers];
}
- (void)removeFromSuperview
{
    if (_superview) {
        UIWindow *oldWindow = self.window;
        
        [_superview willRemoveSubview:self];
        [self _willMoveFromWindow:oldWindow toWindow:nil];
        [self willMoveToSuperview:nil];
        
        [self willChangeValueForKey:@"superview"];
        [_layer removeFromSuperlayer];
        [_superview->_subviews removeObject:self];
        _superview = nil;
        [self didChangeValueForKey:@"superview"];
        
        [self _abortGestureRecognizers];
        
        [[NSNotificationCenter defaultCenter] postNotificationName:UIViewDidMoveToSuperviewNotification object:self];
        
        [self _didMoveFromWindow:oldWindow toWindow:nil];
        [self didMoveToSuperview];
    }
}

- (void)didAddSubview:(UIView *)subview
{
}

- (void)didMoveToSuperview
{
}

- (void)didMoveToWindow
{
}

- (void)willMoveToSuperview:(UIView *)newSuperview
{
}

- (void)willMoveToWindow:(UIWindow *)newWindow
{
}

- (void)willRemoveSubview:(UIView *)subview
{
}

- (CGPoint)convertPoint:(CGPoint)toConvert fromView:(UIView *)fromView
{
       if (fromView) {
        
           if (fromView && (self.window.screen == fromView.window.screen)) {
            return [fromView.layer convertPoint:toConvert toLayer:self.layer];
        } else {
            
            toConvert = [fromView.layer convertPoint:toConvert toLayer:fromView.window.layer];
            
            
            toConvert = [fromView.window convertPoint:toConvert toWindow:self.window];
        }
    }
    
    return [self.window.layer convertPoint:toConvert toLayer:self.layer];
}

- (CGPoint)convertPoint:(CGPoint)toConvert toView:(UIView *)toView
{
    
    if (toView && (self.window.screen == toView.window.screen)) {
        return [self.layer convertPoint:toConvert toLayer:toView.layer];
    } else {
        
        toConvert = [self.layer convertPoint:toConvert toLayer:self.window.layer];
        
        if (toView) {
            
            toConvert = [self.window convertPoint:toConvert toWindow:toView.window];
            
            
            toConvert = [toView.window.layer convertPoint:toConvert toLayer:toView.layer];
        }
        
        return toConvert;
    }
}
- (CGRect)convertRect:(CGRect)toConvert fromView:(UIView *)fromView
{
    CGPoint origin = [self convertPoint:CGPointMake(CGRectGetMinX(toConvert),CGRectGetMinY(toConvert)) fromView:fromView];
    CGPoint bottom = [self convertPoint:CGPointMake(CGRectGetMaxX(toConvert),CGRectGetMaxY(toConvert)) fromView:fromView];
    return CGRectMake(origin.x, origin.y, bottom.x-origin.x, bottom.y-origin.y);
}

- (CGRect)convertRect:(CGRect)toConvert toView:(UIView *)toView
{
    CGPoint origin = [self convertPoint:CGPointMake(CGRectGetMinX(toConvert),CGRectGetMinY(toConvert)) toView:toView];
    CGPoint bottom = [self convertPoint:CGPointMake(CGRectGetMaxX(toConvert),CGRectGetMaxY(toConvert)) toView:toView];
    return CGRectMake(origin.x, origin.y, bottom.x-origin.x, bottom.y-origin.y);
}

- (void)sizeToFit
{
    CGRect frame = self.frame;
    frame.size = [self sizeThatFits:frame.size];
    self.frame = frame;
}

- (CGSize)sizeThatFits:(CGSize)size
{
    return size;
}

- (UIView *)viewWithTag:(NSInteger)tagToFind
{
    UIView *foundView = nil;
    
    if (self.tag == tagToFind) {
        foundView = self;
    } else {
        for (UIView *view in [self.subviews reverseObjectEnumerator]) {
            foundView = [view viewWithTag:tagToFind];
            if (foundView)
                break;
        }
    }
    
    return foundView;
}

- (BOOL)isDescendantOfView:(UIView *)view
{
    if (view) {
        UIView *testView = self;
        while (testView) {
            if (testView == view) {
                return YES;
            } else {
                testView = testView.superview;
            }
        }
    }
    return NO;
}

- (void)setNeedsDisplay
{
    [_layer setNeedsDisplay];
}

- (void)setNeedsDisplayInRect:(CGRect)invalidRect
{
    [_layer setNeedsDisplayInRect:invalidRect];
}

- (void)drawRect:(CGRect)rect
{
}
- (void)displayLayer:(CALayer *)theLayer
{
   
    _layer.backgroundColor = [self.backgroundColor _bestRepresentationForProposedScale:self.window.screen.scale].CGColor;
}

- (BOOL)respondsToSelector:(SEL)aSelector
{
    if (aSelector == @selector(displayLayer:)) {
        return !_implementsDrawRect;
    } else {
        return [super respondsToSelector:aSelector];
    }
}

- (void)drawLayer:(CALayer *)layer inContext:(CGContextRef)ctx
{
    const CGRect bounds = CGContextGetClipBoundingBox(ctx);
    
    UIGraphicsPushContext(ctx);
    CGContextSaveGState(ctx);
    
    if (_clearsContextBeforeDrawing) {
        CGContextClearRect(ctx, bounds);
    }
    
    if (_backgroundColor) {
        [_backgroundColor setFill];
        CGContextFillRect(ctx,bounds);
    }
    
    CGContextSetShouldSmoothFonts(ctx, NO);
    
    CGContextSetShouldSubpixelPositionFonts(ctx, YES);
    CGContextSetShouldSubpixelQuantizeFonts(ctx, YES);
    
    [[UIColor blackColor] set];
    [self drawRect:bounds];
    
    CGContextRestoreGState(ctx);
    UIGraphicsPopContext();
}

- (id)actionForLayer:(CALayer *)theLayer forKey:(NSString *)event
{
    if (_animationsEnabled && [_animationGroups lastObject] && theLayer == _layer) {
        return [[_animationGroups lastObject] actionForView:self forKey:event] ?: (id)[NSNull null];
    } else {
        return [NSNull null];
    }
}

- (void)_superviewSizeDidChangeFrom:(CGSize)oldSize to:(CGSize)newSize
{
    if (_autoresizingMask != UIViewAutoresizingNone) {
        CGRect frame = self.frame;
        const CGSize delta = CGSizeMake(newSize.width-oldSize.width, newSize.height-oldSize.height);
#define hasAutoresizingFor(x) ((_autoresizingMask & (x)) == (x))
        
        if (hasAutoresizingFor(UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleHeight | UIViewAutoresizingFlexibleBottomMargin)) {
            frame.origin.y = floorf(frame.origin.y + (frame.origin.y / oldSize.height * delta.height));
            frame.size.height = floorf(frame.size.height + (frame.size.height / oldSize.height * delta.height));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleHeight)) {
            const CGFloat t = frame.origin.y + frame.size.height;
            frame.origin.y = floorf(frame.origin.y + (frame.origin.y / t * delta.height));
            frame.size.height = floorf(frame.size.height + (frame.size.height / t * delta.height));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleHeight)) {
            frame.size.height = floorf(frame.size.height + (frame.size.height / (oldSize.height - frame.origin.y) * delta.height));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleTopMargin)) {
            frame.origin.y = floorf(frame.origin.y + (delta.height / 2.f));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleHeight)) {
            frame.size.height = floorf(frame.size.height + delta.height);
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleTopMargin)) {
            frame.origin.y = floorf(frame.origin.y + delta.height);
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleBottomMargin)) {
            frame.origin.y = floorf(frame.origin.y);
        }
        
        if (hasAutoresizingFor(UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleRightMargin)) {
            frame.origin.x = floorf(frame.origin.x + (frame.origin.x / oldSize.width * delta.width));
            frame.size.width = floorf(frame.size.width + (frame.size.width / oldSize.width * delta.width));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleWidth)) {
            const CGFloat t = frame.origin.x + frame.size.width;
            frame.origin.x = floorf(frame.origin.x + (frame.origin.x / t * delta.width));
            frame.size.width = floorf(frame.size.width + (frame.size.width / t * delta.width));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleWidth)) {
            frame.size.width = floorf(frame.size.width + (frame.size.width / (oldSize.width - frame.origin.x) * delta.width));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleLeftMargin)) {
            frame.origin.x = floorf(frame.origin.x + (delta.width / 2.f));
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleWidth)) {
            frame.size.width = floorf(frame.size.width + delta.width);
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleLeftMargin)) {
            frame.origin.x = floorf(frame.origin.x + delta.width);
        } else if (hasAutoresizingFor(UIViewAutoresizingFlexibleRightMargin)) {
            frame.origin.x = floorf(frame.origin.x);
        }
        
        self.frame = frame;
    }
}

- (void)_boundsDidChangeFrom:(CGRect)oldBounds to:(CGRect)newBounds
{
    if (!CGRectEqualToRect(oldBounds, newBounds)) {
        
        [self setNeedsLayout];
        
        if (!CGSizeEqualToSize(oldBounds.size, newBounds.size)) {
            if (_autoresizesSubviews) {
                for (UIView *subview in [_subviews allObjects]) {
                    [subview _superviewSizeDidChangeFrom:oldBounds.size to:newBounds.size];
                }
            }
        }
    }
}
+ (NSSet *)keyPathsForValuesAffectingFrame
{
    return [NSSet setWithObject:@"center"];
}

- (CGRect)frame
{
    return _layer.frame;
}

- (void)setFrame:(CGRect)newFrame
{
    if (!CGRectEqualToRect(newFrame,_layer.frame)) {
        CGRect oldBounds = _layer.bounds;
        _layer.frame = newFrame;
        [self _boundsDidChangeFrom:oldBounds to:_layer.bounds];
        [[NSNotificationCenter defaultCenter] postNotificationName:UIViewFrameDidChangeNotification object:self];
    }
}

- (CGRect)bounds
{
    return _layer.bounds;
}

- (void)setBounds:(CGRect)newBounds
{
    if (!CGRectEqualToRect(newBounds,_layer.bounds)) {
        CGRect oldBounds = _layer.bounds;
        _layer.bounds = newBounds;
        [self _boundsDidChangeFrom:oldBounds to:newBounds];
        [[NSNotificationCenter defaultCenter] postNotificationName:UIViewBoundsDidChangeNotification object:self];
    }
}

- (CGPoint)center
{
    return _layer.position;
}

- (void)setCenter:(CGPoint)newCenter
{
    if (!CGPointEqualToPoint(newCenter,_layer.position)) {
        _layer.position = newCenter;
    }
}

- (CGAffineTransform)transform
{
    return _layer.affineTransform;
}

- (void)setTransform:(CGAffineTransform)transform
{
    if (!CGAffineTransformEqualToTransform(transform,_layer.affineTransform)) {
        _layer.affineTransform = transform;
    }
}

- (CGFloat)alpha
{
    return _layer.opacity;
}

- (void)setAlpha:(CGFloat)newAlpha
{
    if (newAlpha != _layer.opacity) {
        _layer.opacity = newAlpha;
    }
}

- (BOOL)isOpaque
{
    return _layer.opaque;
}

- (void)setOpaque:(BOOL)newO
{
    if (newO != _layer.opaque) {
        _layer.opaque = newO;
    }
}

- (void)setBackgroundColor:(UIColor *)newColor
{
    if (_backgroundColor != newColor) {
        _backgroundColor = newColor;
        self.opaque = [_backgroundColor _isOpaque];
        [self setNeedsDisplay];
    }
}

- (BOOL)clipsToBounds
{
    return _layer.masksToBounds;
}

- (void)setClipsToBounds:(BOOL)clips
{
    if (clips != _layer.masksToBounds) {
        _layer.masksToBounds = clips;
    }
}

- (void)setContentStretch:(CGRect)rect
{
    if (!CGRectEqualToRect(rect,_layer.contentsCenter)) {
        _layer.contentsCenter = rect;
    }
}

- (CGRect)contentStretch
{
    return _layer.contentsCenter;
}

- (void)setContentScaleFactor:(CGFloat)scale
{
    if (scale <= 0 && _implementsDrawRect) {
        scale = [UIScreen mainScreen].scale;
    }
    
    if (scale > 0 && scale != self.contentScaleFactor) {
        if ([_layer respondsToSelector:@selector(setContentsScale:)]) {
            [_layer setContentsScale:scale];
            [self setNeedsDisplay];
        }
    }
}

- (CGFloat)contentScaleFactor
{
    return [_layer respondsToSelector:@selector(contentsScale)]? [_layer contentsScale] : 1;
}

- (void)setHidden:(BOOL)h
{
    if (h != _layer.hidden) {
        _layer.hidden = h;
        [[NSNotificationCenter defaultCenter] postNotificationName:UIViewHiddenDidChangeNotification object:self];
    }
}

- (BOOL)isHidden
{
    return _layer.hidden;
}

- (void)setNeedsLayout
{
    [_layer setNeedsLayout];
}

- (void)layoutIfNeeded
{
    [_layer layoutIfNeeded];
}

- (void)layoutSubviews
{
}

- (void)_layoutSubviews
{
    const BOOL wereEnabled = [UIView areAnimationsEnabled];
    [UIView setAnimationsEnabled:NO];
    [self _UIAppearanceUpdateIfNeeded];
    [[self _viewController] viewWillLayoutSubviews];
    [self layoutSubviews];
    [[self _viewController] viewDidLayoutSubviews];
    [UIView setAnimationsEnabled:wereEnabled];
}

- (BOOL)pointInside:(CGPoint)point withEvent:(UIEvent *)event
{
    return CGRectContainsPoint(self.bounds, point);
}

- (BOOL)_isAnimatedUserInteractionEnabled
{
    for (UIViewAnimationGroup *group in _animationGroups) {
        if (!group.allowUserInteraction) {
            for (UIView *animatingView in group.allAnimatingViews) {
                if ([self isDescendantOfView:animatingView]) {
                    return NO;
                }
            }
        }
    }
    
    return YES;
}

- (UIView *)hitTest:(CGPoint)point withEvent:(UIEvent *)event
{
    if (self.hidden || !self.userInteractionEnabled || self.alpha < 0.01 || ![self pointInside:point withEvent:event] || ![self _isAnimatedUserInteractionEnabled]) {
        return nil;
    } else {
        for (UIView *subview in [self.subviews reverseObjectEnumerator]) {
            UIView *hitView = [subview hitTest:[subview convertPoint:point fromView:self] withEvent:event];
            if (hitView) {
                return hitView;
            }
        }
        return self;
    }
}

- (void)setContentMode:(UIViewContentMode)mode
{
    if (mode != _contentMode) {
        _contentMode = mode;
        switch(_contentMode) {
            case UIViewContentModeScaleToFill:
                _layer.contentsGravity = kCAGravityResize;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeScaleAspectFit:
                _layer.contentsGravity = kCAGravityResizeAspect;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeScaleAspectFill:
                _layer.contentsGravity = kCAGravityResizeAspectFill;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeRedraw:
                _layer.needsDisplayOnBoundsChange = YES;
                break;
                
            case UIViewContentModeCenter:
                _layer.contentsGravity = kCAGravityCenter;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeTop:
                _layer.contentsGravity = kCAGravityTop;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeBottom:
                _layer.contentsGravity = kCAGravityBottom;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeLeft:
                _layer.contentsGravity = kCAGravityLeft;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeRight:
                _layer.contentsGravity = kCAGravityRight;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeTopLeft:
                _layer.contentsGravity = kCAGravityTopLeft;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeTopRight:
                _layer.contentsGravity = kCAGravityTopRight;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeBottomLeft:
                _layer.contentsGravity = kCAGravityBottomLeft;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
                
            case UIViewContentModeBottomRight:
                _layer.contentsGravity = kCAGravityBottomRight;
                _layer.needsDisplayOnBoundsChange = NO;
                break;
        }
    }
}

- (void)addGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
    if (![_gestureRecognizers containsObject:gestureRecognizer]) {
        [gestureRecognizer.view removeGestureRecognizer:gestureRecognizer];
        [_gestureRecognizers addObject:gestureRecognizer];
        [gestureRecognizer _setView:self];
    }
}

- (void)removeGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
    if ([_gestureRecognizers containsObject:gestureRecognizer]) {
        [gestureRecognizer _setView:nil];
        [_gestureRecognizers removeObject:gestureRecognizer];
    }
}

- (void)setGestureRecognizers:(NSArray *)newRecognizers
{
    for (UIGestureRecognizer *gesture in [_gestureRecognizers allObjects]) {
        [self removeGestureRecognizer:gesture];
    }
    
    for (UIGestureRecognizer *gesture in newRecognizers) {
        [self addGestureRecognizer:gesture];
    }
}

- (NSArray *)gestureRecognizers
{
    return [_gestureRecognizers allObjects];
}

+ (void)_beginAnimationsWithOptions:(UIViewAnimationOptions)options
{
    [_animationGroups addObject:[[UIViewAnimationGroup alloc] initWithAnimationOptions:options]];
}

+ (void)_setAnimationName:(NSString *)name context:(void *)context
{
    [[_animationGroups lastObject] setName:name];
    [[_animationGroups lastObject] setContext:context];
}

+ (void)_setAnimationCompletionBlock:(void (^)(BOOL finished))completion
{
    [(UIViewAnimationGroup *)[_animationGroups lastObject] setCompletionBlock:completion];
}

+ (void (^)(BOOL))_animationCompletionBlock
{
    return [(UIViewAnimationGroup *)[_animationGroups lastObject] completionBlock];
}

+ (void)_setAnimationTransitionView:(UIView *)view
{
    [[_animationGroups lastObject] setTransitionView:view shouldCache:NO];
}

+ (BOOL)_isAnimating
{
    return ([_animationGroups count] != 0);
}

+ (void)animateWithDuration:(NSTimeInterval)duration delay:(NSTimeInterval)delay options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion
{
    [self _beginAnimationsWithOptions:options | UIViewAnimationOptionTransitionNone];
    [self setAnimationDuration:duration];
    [self setAnimationDelay:delay];
    [self _setAnimationCompletionBlock:completion];
    
    animations();
    
    [self commitAnimations];
}

+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion
{
    [self animateWithDuration:duration
                        delay:0
                      options:UIViewAnimationOptionCurveEaseInOut
                   animations:animations
                   completion:completion];
}

+ (void)animateWithDuration:(NSTimeInterval)duration animations:(void (^)(void))animations
{
    [self animateWithDuration:duration animations:animations completion:NULL];
}

+ (void)transitionWithView:(UIView *)view duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options animations:(void (^)(void))animations completion:(void (^)(BOOL finished))completion
{
    [self _beginAnimationsWithOptions:options];
    [self setAnimationDuration:duration];
    [self _setAnimationCompletionBlock:completion];
    [self _setAnimationTransitionView:view];
    
    if (animations) {
        animations();
    }
    
    [self commitAnimations];
}

+ (void)transitionFromView:(UIView *)fromView toView:(UIView *)toView duration:(NSTimeInterval)duration options:(UIViewAnimationOptions)options completion:(void (^)(BOOL finished))completion
{
    [self transitionWithView:fromView.superview
                    duration:duration
                     options:options
                  animations:^{
                      if (UIViewAnimationOptionIsSet(options, UIViewAnimationOptionShowHideTransitionViews)) {
                          fromView.hidden = YES;
                          toView.hidden = NO;
                      } else {
                          [fromView.superview addSubview:toView];
                          [fromView removeFromSuperview];
                      }
                  }
                  completion:completion];
}

+ (void)beginAnimations:(NSString *)animationID context:(void *)context
{
    [self _beginAnimationsWithOptions:UIViewAnimationCurveEaseInOut];
    [self _setAnimationName:animationID context:context];
}

+ (void)commitAnimations
{
    if ([_animationGroups count] > 0) {
        [[_animationGroups lastObject] commit];
        [_animationGroups removeLastObject];
    }
}

+ (void)setAnimationBeginsFromCurrentState:(BOOL)beginFromCurrentState
{
    [[_animationGroups lastObject] setBeginsFromCurrentState:beginFromCurrentState];
}

+ (void)setAnimationCurve:(UIViewAnimationCurve)curve
{
    [[_animationGroups lastObject] setCurve:curve];
}

+ (void)setAnimationDelay:(NSTimeInterval)delay
{
    [[_animationGroups lastObject] setDelay:delay];
}

+ (void)setAnimationDelegate:(id)delegate
{
    [[_animationGroups lastObject] setDelegate:delegate];
}

+ (void)setAnimationDidStopSelector:(SEL)selector
{
    [[_animationGroups lastObject] setDidStopSelector:selector];
}

+ (void)setAnimationDuration:(NSTimeInterval)duration
{
    [[_animationGroups lastObject] setDuration:duration];
}

+ (void)setAnimationRepeatAutoreverses:(BOOL)repeatAutoreverses
{
    [[_animationGroups lastObject] setRepeatAutoreverses:repeatAutoreverses];
}

+ (void)setAnimationRepeatCount:(float)repeatCount
{
    [[_animationGroups lastObject] setRepeatCount:repeatCount];
}

+ (void)setAnimationWillStartSelector:(SEL)selector
{
    [[_animationGroups lastObject] setWillStartSelector:selector];
}

+ (void)setAnimationTransition:(UIViewAnimationTransition)transition forView:(UIView *)view cache:(BOOL)cache
{
    [self _setAnimationTransitionView:view];
    
    switch (transition) {
        case UIViewAnimationTransitionNone:
            [[_animationGroups lastObject] setTransition:UIViewAnimationGroupTransitionNone];
            break;
            
        case UIViewAnimationTransitionFlipFromLeft:
            [[_animationGroups lastObject] setTransition:UIViewAnimationGroupTransitionFlipFromLeft];
            break;
            
        case UIViewAnimationTransitionFlipFromRight:
            [[_animationGroups lastObject] setTransition:UIViewAnimationGroupTransitionFlipFromRight];
            break;
            
        case UIViewAnimationTransitionCurlUp:
            [[_animationGroups lastObject] setTransition:UIViewAnimationGroupTransitionCurlUp];
            break;
            
        case UIViewAnimationTransitionCurlDown:
            [[_animationGroups lastObject] setTransition:UIViewAnimationGroupTransitionCurlDown];
            break;
    }
}

+ (BOOL)areAnimationsEnabled
{
    return _animationsEnabled;
}

+ (void)setAnimationsEnabled:(BOOL)enabled
{
    _animationsEnabled = enabled;
}

- (NSString *)description
{
    return [NSString stringWithFormat:@"<%@: %p; frame = %@; hidden = %@; layer = %@>", [self className], self, NSStringFromCGRect(self.frame), (self.hidden ? @"YES" : @"NO"), self.layer];
}
@end
