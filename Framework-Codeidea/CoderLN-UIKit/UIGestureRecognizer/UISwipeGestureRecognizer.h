/*
 * UISwipeGestureRecognizer.h 
 *
 * UIKit (c) 2008-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

// Recognizes: when numberOfTouchesRequired have moved mostly in the specified direction, enough to be considered a swipe.
//             a slow swipe requires high directional precision but a small distance
//             a fast swipe requires low directional precision but a large distance

// Touch Location Behaviors:
//     locationInView:         location where the swipe began. this is the centroid if more than one touch was involved
//     locationOfTouch:inView: location of a particular touch when the swipe began

typedef NS_OPTIONS(NSUInteger, UISwipeGestureRecognizerDirection) {
    UISwipeGestureRecognizerDirectionRight = 1 << 0,
    UISwipeGestureRecognizerDirectionLeft  = 1 << 1,
    UISwipeGestureRecognizerDirectionUp    = 1 << 2,
    UISwipeGestureRecognizerDirectionDown  = 1 << 3
};

NS_CLASS_AVAILABLE_IOS(3_2) @interface UISwipeGestureRecognizer : UIGestureRecognizer

@property(nonatomic) NSUInteger                        numberOfTouchesRequired __TVOS_PROHIBITED; // default is 1. the number of fingers that must swipe
@property(nonatomic) UISwipeGestureRecognizerDirection direction;               // default is UISwipeGestureRecognizerDirectionRight. the desired direction of the swipe. multiple directions may be specified if they will result in the same behavior (for example, UITableView swipe delete)

@end

NS_ASSUME_NONNULL_END
