## 内容目录
1、以Framework（UIKit、UIFoundation 为主）功能模块相关的 API 注解；
2、与上一条相对应的工具类 Tools；
3、Framework 类结构图解
4、模块知识梳理脑图

>每月末(`争取`)、更新 ~  ❓ [译文 & 源码](https://github.com/CoderLN/Apple-GitHub-Codeidea)
>补充：按系统结构分类文件层次，对应点击进去浏览，可以很直观的 get 到具体属性、方法的作用、使用、注解；


***
>附: 快捷键
| 类别 | 快捷键 |
| :- | :- |
|【Xcode】 |  |
| Cmd + Shirt + N | 新建工程 |
| Cmd + N | 新建 |
| Cmd + R | 运行 |
| Cmd + . | 停止运行 |
| Cmd + B | 编译 |
| Cmd + Shirt + B | 编译（静态内存分析） |
| Cmd + Q | 退出应用程序 |
| — | — |
| Cmd + 0 | 左侧导航窗口开启和关闭 |
| Cmd + (1 - 7) | 左侧导航窗口的选择（项目，符号，搜索，问题，调试，断点，日志） |
| Cmd + option + 0 | 右侧工具窗口开启和关闭 |
| Cmd + option + (1 - 6) | 右侧工具窗口的选择 |
| Cmd + option + 回车 | 打开控制器对应的文件（Storyboard） |
| Cmd + 回车 | 关闭控制器对应的文件,只显示主窗口(微众：Codeidea) |
| Cmd ＋ ↑／↓ ／←／→ | 光标移动到文字的最上／下／左／右 |
| Cmd + ctrl + ←/→ | 按浏览的先后顺序切换文件 |
| Cmd + ctrl + ↑／↓ | .h 和 .m 切换 |
| Cmd + 鼠标左键(出现小手) | 进入查看一些类/方法 |
| option + 鼠标左键(出现问号) | 查看官方文档 |
| — | — |
| Cmd + / | 选中后，加注释// |
| Cmd + / | 选中后，取消注释 |
| Cmd + shift + 箭头 | 快速选中 / 快速点击鼠标三下 |
| Cmd + delete | 删除光标之前的内容 |
| Cmd + [ | 缩退 |
| Cmd + ] | 缩进 |
| Cmd + option + [ | 向上移动 |
| Cmd + option + ] | 向下缩进 |
| — | — |
| Cmd + F | 搜索 |
| Cmd + shift + f | 全局搜索 |
| Cmd + ctrl + e | 全局修改 |
| Cmd + L | 点位搜索当前行 |
| control + 6 | 弹出当前文件方法列表 |
| 按 esc | 修改方法后,调用此方法的代码自动补全 |
| Control + i | 格式化代码(规范) |
| — | — |
| Ctrl + 脱线 | 添加属性或方法 |
| option + 拖动 | 复制选中的控件 |
| Cmd + option + = | 更新选中控件的约束 |
| option + 回车 | 场景:Xib中，Label控件换行显示 |
| 【模拟器】 |  |
| Cmd + Shift + H | 按一次，取消晃动 / 按一次，回到首页 |
| Cmd + ←/→ | 旋转 |
| Cmd + k | 弹出键盘 |
| Cmd + T | Slow Animations 慢放运行 |




## 说明：
向优秀的创作者致敬！向优秀的分享者致敬！
欢迎来自大厂的你，把你的创作（GitHub相关）、来此分享！

内部有注解均摘录网络加以自己理解总结的 Data，在文件中都会有对应的链接体现， (`由于不知原因`) 如果你看到内部 Data 是你的 Data 且这里没有注明你的链接，请你[简信](https://www.jianshu.com/u/fd745d76c816)我，我会及时补充上。 

