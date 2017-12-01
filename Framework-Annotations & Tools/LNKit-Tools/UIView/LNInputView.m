/*
 * File:  LNInputView.m
 * Framework:  UIScrollView - UIView
 * Author:  白开水ln（https://github.com/CustomPBWaters）
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook:  http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 *
 *【占位文字、键盘上附图自适应高度】
 */


/**
 自定义控件View步骤:Wechat - Codeidea
 1.在【initWithFrame:】添加子控件(或是【懒加载只添加一次】,这里可以写子控件的一次性设置 如:字体大小和颜色)
 2.在【layoutSubviews】设置子控件的frame（一定要记得调用父类）
 3.重写模型【setItem:】方法中 赋值子控件属性模型数据
 
 4.从Xib加载后会调用到【awakeFromNib】(一次)，可以修改Xib子控件【如：cell的 backgroundView背景视图、selectionStyle选中cell不变灰色】
 
 【注解：这里设置子控件的frame】
 可以使用masory 在initWithFrame:添加子控件的时候，设置约束；
 也可以将子控件的frame 封装到模型类中，在模型setItem:方法中 给子控件frame赋值。
 
 三目运算符：A ? B : C
 A为真 - B
 A为假 - C
 */

#import "LNInputView.h"

#define LNRGBA(r,g,b,a) [UIColor colorWithRed:(r) / 256.0 green:(g) / 256.0 blue:(b) / 256.0 alpha:a]

@interface LNInputView ()

/**
  占位文字View：这里使用UITextView可直接让占位文字View 等于 当前textView，文字就会重叠显示
 */
@property (nonatomic, strong) UITextView * placeholderTextView;
/**
  文字高度
 */
@property (nonatomic, assign) NSInteger textHeight;
/**
  文字最大高度
 */
@property (nonatomic, assign) NSInteger maxTextHeight;

@end

@implementation LNInputView

- (UITextView *)placeholderTextView
{
    if(_placeholderTextView == nil) {
        UITextView * placeholderTextView = [[UITextView alloc] init];
        _placeholderTextView = placeholderTextView;
        _placeholderTextView.scrollEnabled = NO;
        _placeholderTextView.showsHorizontalScrollIndicator = NO;
        _placeholderTextView.showsVerticalScrollIndicator = NO;
        _placeholderTextView.userInteractionEnabled = NO;
        _placeholderTextView.font = self.font;
        _placeholderTextView.backgroundColor = [UIColor clearColor];
        //_placeholderTextView.textContainerInset = UIEdgeInsetsMake(5, 0, 0, 0);// text内边距,默认8
        //_placeholderTextView.textContainer.lineFragmentPadding = 0;// text两边空白,默认5
        
        [self addSubview:_placeholderTextView];
    }
    return _placeholderTextView;
}


// 严谨点加上，从xib加载 和 代码创建 textView
- (void)awakeFromNib
{
    [super awakeFromNib];
    [self setupInputTextView];
    self.textHeight = self.font.lineHeight;
}


- (instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
         [self setupInputTextView];
    }
    return self;
}

- (void)setupInputTextView
{
    self.scrollsToTop = NO;
    self.scrollEnabled = NO;
    self.showsHorizontalScrollIndicator = NO;
    self.showsVerticalScrollIndicator = NO;
    self.layer.cornerRadius = 5;
    self.layer.borderWidth = 1;
    self.layer.borderColor = LNRGBA(212,212,214,1.0).CGColor;
 
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textDidChange) name:UITextViewTextDidChangeNotification object:nil];
}


#pragma mark ------------------

-(void)setCornerRadius:(NSUInteger)cornerRadius
{
    _cornerRadius = cornerRadius;
    self.layer.cornerRadius = cornerRadius;
}

- (void)setPlaceholder:(NSString *)placeholder
{
    _placeholder = placeholder;
    self.placeholderTextView.text = placeholder;
}

- (void)setPlaceholderColor:(UIColor *)placeholderColor
{
    _placeholderColor = placeholderColor;
    self.placeholderTextView.textColor = placeholderColor;
}

- (void)setMaxNumberOfLines:(NSUInteger)maxNumberOfLines
{
    _maxNumberOfLines = maxNumberOfLines;
    
    // 计算最大高度 = (每行高度 * 总行数 + 文字上下内间距) / ceil 取整
    self.maxTextHeight = ceil(self.font.lineHeight *maxNumberOfLines + self.textContainerInset.top + self.textContainerInset.bottom);
}



#pragma mark ------------------

- (void)setLn_textHeightChangeBlock:(void (^)(NSString *, CGFloat))ln_textHeightChangeBlock
{
    _ln_textHeightChangeBlock = ln_textHeightChangeBlock;
    
    [self textDidChange];
}


- (void)textDidChange
{
    // 占位文字是否显示
    self.placeholderTextView.hidden = self.text.length > 0;
    
    //【numberlines用来控制输入的行数或是文本框最多显示行数, floor向下取整】➕
    NSInteger numberLines = floor(self.contentSize.height / self.font.lineHeight);
    if (numberLines > 1 && self.text.length > 0) {
        self.textContainerInset = UIEdgeInsetsMake(8, 0, 3, 0);// text内边距,默认8
    } else if (numberLines <= 1 || self.text.length == 0)  {
        self.textContainerInset = UIEdgeInsetsMake(8, 0, 8, 0);
    }
    
    
    NSInteger height = ceilf([self sizeThatFits:CGSizeMake(self.bounds.size.width, MAXFLOAT)].height);
 
    
    // 高度不一样，就改变显示高度
    if (self.textHeight != height) {

        // 最大高度时，可以滚动
        self.scrollEnabled = height > self.maxTextHeight && self.maxTextHeight > 0;
        
        if (self.ln_textHeightChangeBlock && self.scrollEnabled == NO) {
            self.ln_textHeightChangeBlock(self.text,height);
            [self.superview layoutIfNeeded];//【】
            self.placeholderTextView.frame = self.bounds;
        }
        
        self.textHeight = height;
    }
 
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UITextViewTextDidChangeNotification object:nil];
}



/**
 *  创建UITextField 的catgory ，将此方法粘贴到.m文件。
 *  也就是重写长按方法 ,将长按的菜单关闭掉 (禁止textField和textView的复制粘贴菜单).
 *  @return 在需要使用的类直接引入.h文件即可 无需调用
 */
- (BOOL)canPerformAction:(SEL)action withSender:(id)sender {
//        if (action == @selector(paste:))//禁止粘贴
//            return NO;
//        if (action == @selector(select:))// 禁止选择
//            return NO;
//        if (action == @selector(selectAll:))// 禁止全选
//            return NO;
        return [super canPerformAction:action withSender:sender];
//    UIMenuController *menuController = [UIMenuController sharedMenuController];
//    if (menuController)
//    {
//        [UIMenuController sharedMenuController].menuVisible = NO;
//    }
//    return NO;
}



@end













































