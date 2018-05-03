/*
 * UserNotifications.h 
 *
 * (c) 2015
 * Framework: UserNotifications
 *
 * About ME『Public：Codeidea / https://githubidea.github.io』.
 * Copyright © All members (Star|Fork) have the right to read and write『https://github.com/CoderLN』.
 *
 * 🏃🏻‍♂️ ◕该模块将系统化学习，后续替换、补充文章内容 ~
 */


//--------------------------- 【学习思想-分享 -> 对你有新思想或是习惯 -> Star&Fork】 ------------------------------//


/*
 iOS10新增了UserNotificationKit框架，整合了关于通知的方法。增加了很多新特性
 
 本地推送步骤
 1.设置推送内容
 2.设置通知触发器(4种)
 3.添加通知（需要创建request,给request设置content和trigger）
 4.管理通知
 
 
 远程推送步骤
 1.注册推送，获取deviceToken
 2.收到普通推送
 3.收到后台推送
 4.收到静默推送
 5.管理通知
 
 
 //--------------------------- <#我是分割线#> ------------------------------//
 //
 
 附件通知（图片、音频、视频）:有大小、格式限制，而且附件要在本地。
 本地：content.attachments = @[attachment];
      本地推送通知增加附件，只需给content.attachments设置UNNotificationAttachment附件对象
 远程：apns中包含一个"mutable-content":1字段,使用UNNotificationServiceExtension，你有30秒的时间处理这个通知，可以同步下载图像和视频到本地，然后包装为一个UNNotificationAttachment扔给通知，这样就能展示用服务器获取的图像或者视频了。这里需要注意：如果数据处理失败，超时，extension会报一个崩溃信息，但是通知会用默认的形式展示出来，app不会崩溃。
 
 
 管理推送周期
 本地：通过id更新request。
    1. addNotificationRequest:withCompletionHandler: 在 id 不变的情况下重新添加，就可以刷新原有的推送。
    2. 删除计划的推送 [center removePendingNotificationRequestsWithIdentifiers:@[requestIdentifier]];
 远程：通过新的字段 apns-collapse-id
 此外 UNUserNotificationCenter.h 中还有诸如删除所有推送、查看已经发出的推送、删除已经发出的推送等等强大的接口
 
 
 收到通知的回调：
 本地推送：
    1. 用户不在前台(后台、杀死)时，未知。
    2. 用户在前台，收到通知时触发（userNotificationCenter:willPresentNotification:withCompletionHandler）
 远程推送：
    1. 被用户手动划掉的用户不能收到远程推送的回调。
    2. 并且应用在前台或者后台时收到远程推送，将触发该方法。（注意：应用被手动划掉将无法触发），需要增加"content-available":1字段。
       可以在这个方法里做一些后台操作（下载数据，更新UI等），记得修改Background Modes
       (application:didReceiveRemoteNotification:fetchCompletionHandler:)
    3. 在前台，没有"content-available":1字段时，只调用（userNotificationCenter:willPresentNotification:withCompletionHandler）。有"content-available":1字段，则先调用(application:didReceiveRemoteNotification:fetchCompletionHandler),再调用(userNotificationCenter:willPresentNotification:withCompletionHandler)。
 
 
 操作的回调：
 本地推送：
    1. 用户在前台、后台，点击通知时触发（userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler）
    2. 被手动划掉的用户，可以收到本地推送操作的回调。(userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:) //并且想获取清除通知的回调，category需要配置UNNotificationCategoryOptionCustomDismissAction。
 远程推送：
    1. 与本地推送的操作回调相同。增加"category":"categoryId"字段
 
 
 
 如果App在前台，你接收到通知，不想显示系统提示框，想使用App 自定义的通知消息弹窗，可以在completionHandler回调的时候传入的opinion不要带上UNAuthorizationOptionAlert，然后直接弹自定义的弹窗就Ok。
 
 */


/**
【思想】-> Jane's book <Neo_joke>
 iOS10的通知使用场景 分析示例 & 解决方案, 如下？
 
 1.运营活动可以配上活动海报或者是动图海报，在用户点击好能更好的查看运营活动详情
 2.即时通讯类的App可以通过自定义ContentExtension来在通知上完成回复消息
 3.比方说，你有个秒杀活动，通知一下来，用户立马可以通过iOS10的通知交互完成秒杀预定，然后再启动App慢慢付款~这个用户体验的提升那是相当巨大的
 4.比方说，你可以通过推送收取一些用户对某个活动或者新版本的反馈意见？使用TextAction来做
 5.你是否可可以发个可视化的账单给用户，在自定义UI上显示？
   ...
 
 解决方案图解
 
 
 
 */







//--------------------------- 【iOS10通知建议参考文章】 ------------------------------//
//

【iOS10 推送通知】http://www.jianshu.com/p/9c9035212af0


【iOS10 推送通知】http://www.jianshu.com/p/78ef7bc04655


【iOS10 推送通知】http://www.jianshu.com/p/f5337e8f336d


【iOS10 推送通知】http://www.jianshu.com/p/f77d070a8812


【iOS10 集成极光推送】http://www.jianshu.com/p/53e0244e6081










































