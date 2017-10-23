/*
 * File:  UITextView.m
 * Framework:  UIKit
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 2007-2017
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook: http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */


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































