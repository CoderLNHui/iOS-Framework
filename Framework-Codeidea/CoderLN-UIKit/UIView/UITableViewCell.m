/*
 * UITableViewCell.h
 *
 * UIKit (c) 2005-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */

#pragma mark - UITableViewCell常用属性
 

// 设置右侧显示附加样式（比如右侧的箭头; 优先级: accessoryView > accessoryType）
cell.accessoryType = UITableViewCellAccessoryCheckmark;
cell.accessoryView = [[UISwitch alloc] init];

// 设置选中样式(StyleNone选中不变灰色)
cell.selectionStyle = UITableViewCellSelectionStyleNone;

// 设置cell的背景颜色
cell.backgroundColor = [UIColor clearColor];// 透明

// 设置cell的背景View (优先级: backgroundView > backgroundColor)
UIView *view = [[UIView alloc] init];
view.backgroundColor = [UIColor grayColor];
cell.backgroundView = view;

// 设置cell选中时背景View
UIView *bgView = [[UIView alloc] init];
bgView.backgroundColor = [UIColor blueColor];
cell.selectedBackgroundView = bgView;

//contenView subViews -> UIImageView、textLabel、detailTextLabel
//cell.contentView =



 



































