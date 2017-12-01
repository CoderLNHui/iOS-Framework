/*
 * UIReferenceLibraryViewController.h
 * UIKit
 * 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2011-2012
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */
 
#import <UIKit/UIViewController.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(5_0) __TVOS_PROHIBITED
@interface UIReferenceLibraryViewController : UIViewController {}

/*! Returns YES if any installed dictionary has a definition for the provided term.
 */
+ (BOOL)dictionaryHasDefinitionForTerm:(NSString *)term;

/*! Initializes an instance of a UIReferenceLibraryViewController with the term provided.
 */
- (instancetype)initWithTerm:(NSString *)term NS_DESIGNATED_INITIALIZER;
- (instancetype) initWithCoder:(nonnull NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER; // Declared solely for the sake of potential subclassers.

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END_START_COPYRIGHT__JIANSHU_BAIKAISHUILN__WechatPublic_Codeidea__END
