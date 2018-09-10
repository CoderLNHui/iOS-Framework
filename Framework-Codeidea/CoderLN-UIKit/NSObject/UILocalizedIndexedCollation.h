/*
 * UILocalizedIndexedCollation.h
 *
 * UIKit (c) 2009-2017
 *
 * 不知名刘先生
 * Public - CoderLN / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Our sharing can be combined; Convenient to review and help others.
 *
 * 🏃🏻‍♂️ ◕ 尊重熬夜整理的作者，该模块将系统化学习，后续替换、补充文章内容 ~
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(3_0) @interface UILocalizedIndexedCollation : NSObject

+ (instancetype)currentCollation;

// Provides the list of section titles used to group results (e.g. A-Z,# in US/English)
@property(nonatomic, readonly) NSArray<NSString *> * sectionTitles;

// Provides the list of index titles used to quickly jump to particular sections
@property(nonatomic, readonly) NSArray<NSString *> *sectionIndexTitles;

// Specifies the section that should be scrolled to for the title at the given index.
// This method allows you to map between a given item in the index
// and a given section where there isn't a one-to-one mapping.
- (NSInteger)sectionForSectionIndexTitleAtIndex:(NSInteger)indexTitleIndex;

// Returns the index of the section that will contain the object.
// selector must not take any arguments and return an NSString.
- (NSInteger)sectionForObject:(id)object collationStringSelector:(SEL)selector;

// Used for sorting objects within the same section.
// selector must not take any arguments and return an NSString.
// In the process of sorting the array, each object may receive
// selector multiple times, so this method should be fast.
- (NSArray *)sortedArrayFromArray:(NSArray *)array collationStringSelector:(SEL)selector;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
