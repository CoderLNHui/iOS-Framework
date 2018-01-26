
/************************************************************************
 *                                                                      *
 *                    👣 WechatPublic - Codeidea 👣                     *
 *                      @Email: pbwaterln@sina.com                      *
 *                                                                      *
 *         |用文字记录自己的思想与经验 | 编程 | 职场 | 阅读 | 摄影 | 体验 |      *
 *                                                                      *
 *                      ⚠️ 转载请告知 且 注明出处 蟹蟹 ⚠️                   *
 ************************************************************************/


@interface UITextViewController ()<UITextFieldDelegate,UITextViewDelegate>


@property (nonatomic, strong) UITextView *textView;


@end

@implementation UITextViewController

//--------------------------- 【键盘落下】 ------------------------------//
//

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    /**
     【结束文本框编辑】
     1.结束编辑
     [self.view endEditing:YES];
     
     2.失去第一响应
     [self.textView resignFirstResponder];
     */
    [self.view endEditing:YES];
}


- (void) viewDidLoad {
    [super viewDidLoad];
    
    UITextView *textView = [[UITextView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width - 100, 80)];
    textView.center = self.view.center;
    self.textView = textView;
    textView.backgroundColor = [UIColor cyanColor];
    
    //textView.text = @"我是白开水ln开发工程师"; // 文字
    textView.textColor = [UIColor whiteColor]; // 字体颜色
    textView.font = [UIFont systemFontOfSize:18.f]; // 字体大小
    
    //【文本对齐样式】
    textView.textAlignment = NSTextAlignmentLeft;
    
    //【圆角】
    textView.layer.cornerRadius = textView.frame.size.height * 0.5;
    textView.layer.masksToBounds = YES;
    
    //【边框】
    textView.layer.borderWidth = 5;
    textView.layer.borderColor = [UIColor redColor].CGColor;
    
    //【是否可以滚动】
    textView.scrollEnabled = YES;
    
    //【是否允许编辑内容，输入】
    //textView.editable = NO;
    
    //【是否允许选中内容，复制】
    //textView.selectable = NO;
    
    //【待：验证❓显示数据类型的连接模式（如电话号码、网址、地址等）】
    //textView.dataDetectorTypes = UIDataDetectorTypeAll;
    //textView.allowsEditingTextAttributes = NO;
    
    //【富文本：设置文字】
    NSMutableAttributedString *attStr = [[NSMutableAttributedString alloc] initWithString:@"我是白开水ln开发工程师"];
    [attStr addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:18.f] range:NSMakeRange(0, attStr.length)];
    [attStr addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:NSMakeRange(0, attStr.length)];
    //textView.attributedText = attStr;
    
    
    //【return键模式】
    textView.returnKeyType = UIReturnKeyNext;
    
    //【textView代理】
    textView.delegate = self;
    
    
    
    //【设置输入框成为第一响应时弹出的inputView视图(自定义键盘) 和 inputAccessoryView辅助视图(系统弹出键盘上的配件视图)】
    UIView *greenView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, 40)];
    greenView.backgroundColor = [UIColor greenColor];
    //textView.inputView = greenView;
    textView.inputAccessoryView = greenView;
    
    //【是否显示删除按钮】
    textView.clearsOnInsertion = YES;
    
    //【待：验证❓文本容器内边距8、文本容器5】textView.textContainerInset(CGFloat top 8, left 0, bottom 8, right 0;)
    //    textView.textContainerInset = UIEdgeInsetsZero;
    //    textView.textContainer.lineFragmentPadding = 0;
    
    //【待：验证❓】
    //[textView scrollRangeToVisible:NSMakeRange(0, 0)];
    
    [self.view addSubview:textView];
    
    
}



#pragma mark ------------------
#pragma mark -【textView代理方法】
//【是否允许开始编辑】
- (BOOL)textViewShouldBeginEditing:(UITextView *)textView
{
    return YES;
}

//【是否允许结束编辑】
- (BOOL)textViewShouldEndEditing:(UITextView *)textView
{
    return YES;
}

//【点击文本框开始编辑时调用】
- (void)textViewDidBeginEditing:(UITextView *)textView
{
    NSLog(@"DidBeginEditing 点击文本框开始编辑时调用 = %@",textView.text);
}


//【输入字符时调用，只要是输入就会一直调用】
- (void)textViewDidChange:(UITextView *)textView
{
    NSString *didChangeChar = @"空值";
    if (textView.text.length > 0) {
        didChangeChar  = [textView.text substringFromIndex:textView.text.length - 1];
    }
    // 这里的 最后字符 如果输入的是emoj表情 打印是空格
    NSLog(@"DidChange 输入字符时调用 = %@，输入最后字符 = %@",textView.text, didChangeChar);
}


//【文本框结束编辑】
- (void)textViewDidEndEditing:(UITextView *)textView
{
    NSString *didChangeChar = @"空值";
    if (textView.text.length > 0) {
        didChangeChar  = [textView.text substringFromIndex:textView.text.length - 1];
    }
    NSLog(@"DidEndEditing 文本框结束编辑 = %@，结束最后字符 = %@",textView.text, didChangeChar);
}


//【是否允许改变文本框内容(拦截用户输入)】
- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
    return YES;
}


//【选中内容改变】
- (void)textViewDidChangeSelection:(UITextView *)textView
{
    NSLog(@"DidChangeSelection 选中内容 = %@",textView.text);
}



//--------------------------- 【通知：监听文本框开始编辑、输入字符、结束编辑】 ------------------------------//
//
- (void)textViewWithNotification
{
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textViewDidBeginEdit:) name:UITextViewTextDidBeginEditingNotification object:self.textView];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textViewDidChangeEdit:) name:UITextViewTextDidChangeNotification object:self.textView];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textViewDidEndEdit:) name:UITextViewTextDidEndEditingNotification object:self.textView];
}

//【移除通知】
- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}


- (void)textViewDidBeginEdit:(NSNotification *) notification
{
    NSLog(@"通知：点击文本框开始编辑");
}

- (void)textViewDidChangeEdit:(NSNotification *) notification
{
    NSLog(@"通知：输入字符时调用");
}

- (void)textViewDidEndEdit:(NSNotification *) notification
{
    NSLog(@"通知：文本框结束编辑");
}







//--------------------------- <#我是分割线#> ------------------------------//
//

添加监听很简单：

/**
 *  监听UITextField文字改变
 *
 *  @param textFieldTextDidChange 文本改变时通知方法
 *
 *  @param name UITextFieldTextDidChangeNotification（通知类型）
 *
 *  @param object （可用于传递数据）
 */
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textFieldTextDidChange) name:UITextFieldTextDidChangeNotification object:telephone];
监听方法

- (void)textFieldTextDidChange
{
    if(telephone.text.length > 11 ){
        NSRange range = NSMakeRange(0, 11);
        telephone.text = [telephone.text substringWithRange:range];
        [self endEditing:YES];
        [MBProgressUtil showToast:@"手机号码最多为11位" inView:self];
    }
}































