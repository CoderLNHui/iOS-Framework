/*
 * Swift_Header.h 效率开发常用宏
 * 创建 cmd+n -> HeaderFile
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
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
