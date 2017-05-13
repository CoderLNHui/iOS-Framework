

//--------------------------- 【Code】 ------------------------------//
//

Code1

NSString *str = @"人生若只如初见，何事悲风秋画扇。\n等闲变却故人心，却道故人心易变。\n骊山语罢清宵半，泪雨霖铃终不怨。\n何如薄幸锦衣郎，比翼连枝当日愿。";

// 创建 NSMutableAttributedString
NSMutableAttributedString *attrStr = [[NSMutableAttributedString alloc] initWithString:str];

// 设置字体和设置字体的范围
[attrStr addAttribute:NSFontAttributeName
                value:[UIFont systemFontOfSize:30.0f]
                range:NSMakeRange(0, 3)];
// 添加文字颜色
[attrStr addAttribute:NSForegroundColorAttributeName
                value:[UIColor redColor]
                range:NSMakeRange(17, 7)];
// 添加文字背景颜色
[attrStr addAttribute:NSBackgroundColorAttributeName
                value:[UIColor orangeColor]
                range:NSMakeRange(17, 7)];
// 添加下划线
[attrStr addAttribute:NSUnderlineStyleAttributeName
                value:[NSNumber numberWithInteger:NSUnderlineStyleSingle]
                range:NSMakeRange(8, 7)];

UILabel *label = [[UILabel alloc]initWithFrame:CGRectMake(60, 100, 200, 0)];
label.backgroundColor = [UIColor greenColor];
// 自动换行
label.numberOfLines = 0;
// 设置label的富文本
label.attributedText = attrStr;
// label高度自适应
[label sizeToFit];
[self.view addSubview:label];







Code2

//创建属性字典
NSDictionary *attrDict = @{ NSFontAttributeName: [UIFont fontWithName: @"Zapfino" size: 15],
                            NSForegroundColorAttributeName: [UIColor blueColor] };
//创建 NSAttributedString 并赋值
_label.attributedText = [[NSAttributedString alloc] initWithString: originStr attributes: attrDict]



//===============方式2=======================
UIFont *fond = [UIFont systemFontOfSize:20];
UIColor *color = [UIColor redColor];

NSMutableDictionary *attributes = [NSMutableDictionary new];
[attributes setObject:fond forKey:NSFontAttributeName];
[attributes setObject:color forKey:NSForegroundColorAttributeName];
return [[NSAttributedString alloc]initWithString:text attributes:attributes];










//--------------------------- 【code】 ------------------------------//
//













































