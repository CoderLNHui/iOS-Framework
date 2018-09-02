[TOC]
#pragma mark - 释义
```objc
UILabel
A view that displays one or more lines of read-only text, often used in conjunction with controls to describe their intended purpose.
显示一行或多行只读文本的视图，通常与控件一起使用以描述其预期作用
```

#pragma mark - 层次结构（内部组成）
#pragma mark -常用属性
```objc
 // 初始化
 UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(10, 40, 200, 40)];
 
 // 文字(可以手动添加\n换行)
 label.text = @"窗前明月光\n疑似地上霜\n";
 label.text = [NSString stringWithFormat:@"%02ld:%02ld",Min,Sec];// 时间格式处理 03:12/25:04;
 
 // 文字颜色
 label.textColor = [UIColor redColor];
 
 // 是否高亮显示
 label.highlighted = YES;
 // 高亮显示时文本颜色
 label.highlightedTextColor = [UIColor cyanColor];
 
 // 对齐方式（居中）
 label.textAlignment = NSTextAlignmentCenter;
 
 // 字体大小，默认是17
 label.font = [UIFont systemFontOfSize:25];
 label.font = [UIFont fontWithName:fontName size:15];// 字体大小，指定字体的方法
 
 // 多行显示(0意思是不限制多少行)
 label.numberOfLines= 0;
 
 // 是否可以用户交互
 label.userInteractionEnabled = YES;
 
 // 会根据指定的宽度自动计算高度
 [label sizeToFit];
 
 // 自动调整字体的大小以适应整个的区域
 label.adjustsFontSizeToFitWidth = YES;
 
 // 阴影
 label.shadowColor = [UIColor blackColor];// 阴影颜色
 label.shadowOffset = CGSizeMake(-2, 1);// 阴影偏移量
 
 // 换行+打断模式
 label.lineBreakMode =  NSLineBreakByTruncatingTail;
 
 //手动设置label文字的最大宽度 (目地是为了能过计算label真实的高度)
 label.preferredMaxLayoutWidth = 100;
 
 // 设置属性字符串
 NSString * string = @"CoderLN";
 NSMutableAttributedString * abString = [[NSMutableAttributedString alloc] initWithString:string];
 [abString addAttributes:@{
                           NSForegroundColorAttributeName:[UIColor redColor],//颜色
                           NSFontAttributeName:[UIFont systemFontOfSize:20],//文字大小
                           NSUnderlineStyleAttributeName:@(1),//下划线1或0
                           } range:NSMakeRange(0, string.length)];
 label.attributedText = abString;
 
 // 控制文本的基线位置，当adjustsFontSizeToFitWidth=YES且行数为1，如果文本font要缩小时，才有效果
 label.adjustsFontSizeToFitWidth = YES;
 label.baselineAdjustment = UIBaselineAdjustmentAlignBaselines;
```

#pragma mark -常用方法
```objc

```



#pragma mark - 总结笔记
#pragma mark -基本使用
 
#pragma mark - 自定义控件（抽取封装）
 
#pragma mark - 场景思维
#pragma mark -UI自定义字体
```objc
步骤一：找到UI效果图中的字体文件，字体文件术语称为矢量字库，一般是以TTF结尾的，这里假设就是方正正纤黑.TTF，双击该文件用字体册查看，记录下显示的字体名称FZZhengHeiS-EL-GB，后面会用到。

步骤二：将TTF文件导入Xcode工程，

步骤三：在plist文件中添加配置 (Fonts provided by application)
<key>UIAppFonts</key>
<array>
<string>方正正纤黑.TTF</string>
</array>

步骤四：查看系统加载的字体
// 获取系统字体名称：
for(NSString *fontfamilyname in [UIFont familyNames]) {
    NSLog(@"family:'%@'",fontfamilyname);
    for (NSString *fontName in [UIFont fontNamesForFamilyName:fontfamilyname]) {
        NSLog(@"\\\\tfont:'%@'",fontName);
    }
}
在输出控制台查找（快捷键⌘F）步骤一最后查出的字体名称FZZhengHeiS-EL-GB，复制font:后面的FZZXHJW--GB1-0，这才是最后我们要用的字体名称。

步骤五：使用导入的字体，
label.font = [UIFont fontWithName:fontName size:15];// 字体大小，指定字体的方法
```
 


#pragma mark -UILabel Masonry包裹约束
```objc
// Masonry大于等于和小于等于某个值的约束
- (void)wrapShowLabel
{
    UILabel *textLabel = [[UILabel alloc] init];
    textLabel.numberOfLines = 0;
    textLabel.backgroundColor = [UIColor colorWithRed:0.2 green:1 blue:1 alpha:1.0];
    textLabel.text = @"这是测试的字符串。自检 代码不会可以多敲几次，学习的重点是思想；思路都没有就去写代码这是没有意义的，也没有必须非得 第一步干嘛/第二步干嘛。多数情况下是采用逆向思维，先考虑你要干什么，缺什么补...。";
    [self.view addSubview:textLabel];

    [textLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.view);
        // 设置宽度小于等于200
        make.width.lessThanOrEqualTo(@200);
        // 设置高度大于等于10
        make.height.greaterThanOrEqualTo(@(10));
    }];
}
```
![UILabel Masonry包裹约束](https://upload-images.jianshu.io/upload_images/2230763-3dab832b348edb22.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



#pragma mark -给文本UILabel添加点击事件Block、Dlegate回调
https://github.com/lyb5834/YBAttributeTextTapAction
![给文本Label添加点击事件Block回调](https://upload-images.jianshu.io/upload_images/2230763-2542bdf089b1826a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
![给文本Label添加点击事件Dlegate回调](https://upload-images.jianshu.io/upload_images/2230763-9b678de47f3d0abc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

                           
#pragma mark -UILabel显示html标签(字体的颜色和大小)
```objc
UILabel *label  = [[UILabel alloc] initWithFrame:CGRectMake(20, 100, 350, 100)];
label.backgroundColor = [UIColor cyanColor];
NSAttributedString *attributedString = [[NSAttributedString alloc] initWithData:[@"<font  style='font-size:20px;color:red'> HTMLText  </font>wechat-Codeidea" dataUsingEncoding:NSUnicodeStringEncoding] options:@{ NSDocumentTypeDocumentAttribute: NSHTMLTextDocumentType } documentAttributes:nil error:nil];
label.attributedText = attributedString;
[self.view addSubview:label];
```
![UILabel显示html标签(字体的颜色和大小)](https://upload-images.jianshu.io/upload_images/2230763-9d7b6d3a39b1b31e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
 
                             
#pragma mark -UILabel计算文字动态宽高
```objc
 1、计算单行文字动态宽高（根据字体大小）
    1.self.undleLineView.ln_width = [titleButton.currentTitle sizeWithAttributes:@{NSFontAttributeName:titleButton.titleLabel.font}].width;
    2.弃用
        [topic.text sizeWithFont:[UIFont systemFontOfSize:14]].width;
        [UIFont systemFontOfSize:14].lineHeight;
        CGFloat fontHeight = [self.text sizeWithFont:[UIFont systemFontOfSize:16.0] constrainedToSize:CGSizeMake(kScreenW - 2 * LNMarin, MAXFLOAT)].height;// 多行

 - - -
 2、计算多行文字动态宽高（根据字体大小 和 指定宽度，高度不限制）
    CGFloat * height = [self.text boundingRectWithSize:CGSizeMake(kScreenW - 2*LNMarin, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:16.0]} context:nil].size.height + LNMarin;
```
![UILabel计算文字动态宽高](https://upload-images.jianshu.io/upload_images/2230763-a9aa9c6f3d48bc18.gif?imageMogr2/auto-orient/strip)


#pragma mark -设置指定UILabel某个位置圆角
```objc
- (void)setLabelCricleCorner
{
    // 需求：将一个label右边切圆角，左边不切
    UILabel * label = [[UILabel alloc]initWithFrame:CGRectMake(60, 60, 160 , 60)];
    [label setCricleCornerWithLabel:label byRoundingCorners:UIRectCornerBottomRight | UIRectCornerTopRight cornerRadius:CGSizeMake(label.ln_height * 0.5, label.ln_height * 0.5) text:@"小刘"];
    [self.view addSubview:label];
}


#pragma mark -指定设置label某个位置圆角
- (void)setCricleCornerWithLabel:(UILabel *)label byRoundingCorners:(UIRectCorner)corners cornerRadius:(CGSize)cornerRadius text:(NSString *)text
{
    label.backgroundColor = [UIColor lightGrayColor];
    label.textAlignment = NSTextAlignmentCenter;
    label.textColor = [UIColor whiteColor];
    label.text = text;
    
    UIBezierPath *maskPath = [UIBezierPath bezierPathWithRoundedRect:label.bounds byRoundingCorners:UIRectCornerBottomRight | UIRectCornerTopRight cornerRadii:CGSizeMake(label.frame.size.height * 0.5, label.frame.size.height * 0.5)];
    CAShapeLayer *maskLayer = [[CAShapeLayer alloc] init];
    maskLayer.frame = label.bounds;
    maskLayer.path = maskPath.CGPath;
    label.layer.mask  = maskLayer;
}
```
![设置指定UILabel某个位置圆角](https://upload-images.jianshu.io/upload_images/2230763-033e44fd01a2ba51.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)



