/*
 * Swift_Header.h
 * 创建 cmd+n -> HeaderFile
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/Coder』.
 *
 * 作用：效率开发常用宏 - 适时慎用
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */

// MARK:- 自定义打印Log
func LNPrint<T>(messsage : T, file : String = #file, funcName : String = #function, lineNum : Int = #line)
{
    #if DEBUG
        let fileName = (file as NSString).lastPathComponent
        print("\(fileName):【\(funcName)】(\(lineNum))-\(messsage)")
        //print("\(fileName):(\(lineNum))-\(messsage)")
    #endif
}
打印：类 + 函数 + 行数 + 描述信息
ViewController.swift:【setupUI()】(46)-Swift自定义Log
