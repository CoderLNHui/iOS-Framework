/*
 * File:  UIPickerView.h 
 *
 * (c) 2006-2017
 * Framework: UIKit
 *
 * Author: 白开水ln,（https://github.com/CoderLN）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming.
 * Copyright © Reprinted（Blog https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 *
 * 🐾 |Codeidea 用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 | 👣
 */
 

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIView.h>
#import <UIKit/UIKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

@protocol UIPickerViewDataSource, UIPickerViewDelegate;





NS_CLASS_AVAILABLE_IOS(2_0) __TVOS_PROHIBITED @interface UIPickerView : UIView <NSCoding>

@property(nullable,nonatomic,weak) id<UIPickerViewDataSource> dataSource;                // default is nil. weak reference
@property(nullable,nonatomic,weak) id<UIPickerViewDelegate>   delegate;                  // default is nil. weak reference

//【是否显示UIPickerView中的选中标记（以高亮背景作为选中标记）,无效果】
@property(nonatomic)        BOOL                       showsSelectionIndicator;   // default is NO

// info that was fetched and cached from the data source and delegate
@property(nonatomic,readonly) NSInteger numberOfComponents; //【包含多少组】
- (NSInteger)numberOfRowsInComponent:(NSInteger)component; //【组包含多少行】
- (CGSize)rowSizeForComponent:(NSInteger)component; //【指定组中列表项的大小】

// returns the view provided by the delegate via pickerView:viewForRow:forComponent:reusingView:
// or nil if the row/component is not visible or the delegate does not implement
// pickerView:viewForRow:forComponent:reusingView:
//【指定组的列表项所使用的UIView控件】
- (nullable UIView *)viewForRow:(NSInteger)row forComponent:(NSInteger)component;

// Reloading whole view or single component
- (void)reloadAllComponents;//【刷新所有分组】
- (void)reloadComponent:(NSInteger)component; //【刷新指定分组】

// selection. in this case, it means showing the appropriate row in the middle
//【选中指定组的哪一行】,设置联动第1组默认选中
- (void)selectRow:(NSInteger)row inComponent:(NSInteger)component animated:(BOOL)animated;  // scrolls the specified row to center.

//【获取指定组选中的行】
- (NSInteger)selectedRowInComponent:(NSInteger)component;                                   // returns selected row. -1 if nothing selected

@end











__TVOS_PROHIBITED
@protocol UIPickerViewDataSource<NSObject>
@required

// returns the number of 'columns' to display.
//【多少组】
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView;

// returns the # of rows in each component..
//【多少行】
- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component;
@end









__TVOS_PROHIBITED
@protocol UIPickerViewDelegate<NSObject>
@optional




// returns width of column and height of row for each component.
//【组的宽度】
- (CGFloat)pickerView:(UIPickerView *)pickerView widthForComponent:(NSInteger)component __TVOS_PROHIBITED;
//【组中每行的高度】
- (CGFloat)pickerView:(UIPickerView *)pickerView rowHeightForComponent:(NSInteger)component __TVOS_PROHIBITED;




// these methods return either a plain NSString, a NSAttributedString, or a view (e.g UILabel) to display the row for the component.
// for the view versions, we cache any hidden and thus unused views and pass them back for reuse.
// If you return back a different object, the old one will be released. the view will be centered in the row rect
//【行内容(title)】
- (nullable NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component __TVOS_PROHIBITED;
//【行内容(富文本)】
- (nullable NSAttributedString *)pickerView:(UIPickerView *)pickerView attributedTitleForRow:(NSInteger)row forComponent:(NSInteger)component NS_AVAILABLE_IOS(6_0) __TVOS_PROHIBITED; // attributed title is favored if both methods are implemented
//【行内容(UIView)】
- (UIView *)pickerView:(UIPickerView *)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(nullable UIView *)view __TVOS_PROHIBITED;



//【选中行】
- (void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component __TVOS_PROHIBITED;

@end

NS_ASSUME_NONNULL_END

