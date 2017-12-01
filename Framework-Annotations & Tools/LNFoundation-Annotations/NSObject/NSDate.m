/*
 * File:  NSDate.m
 * Framework:  Foundation
 * Author: 白开水ln（https://github.com/CustomPBWaters）
 *
 * (c) 1994-2017
 *
 * Created by 【WechatPublic-Codeidea】 on Elegant programming16.
 * Copyright © Reprinted（https://githubidea.github.io）Please indicate the source.Mustbe.
 *
 * JaneBook: http://www.jianshu.com/u/fd745d76c816
 *
 * @HEADER_WELCOME YOU TO JOIN_GitHub & Codeidea_END@
 */

/*
NSDateFormatter转换时间各种格式总结

年份
1、yyyy 表示四位年份，例如2017；
2、yy 表示年份的后两位，例如”2017“会显示“17”；

月份
1、MM 表示两位月份，例如：”十二月“显示为”12“、“4月”显示为“04”；
2、M 在两位月份时，依旧为两位，但是对于一位的月份，则去除前面的0，只显示一位，例如：”十二月“显示为”12“、“4月”显示为“4”。同理，天、小时、分钟、秒一样。

天
1、dd 表示当前月份的哪一天；
2、DD 表示是今年的第*天。
上下午
1、a 表示上下午。

小时
1、hh 表示12小时制；
2、HH 表示24小时制。

分钟
1、mm 表示分钟。

秒
1、s 表示秒。

星期
1、EEEE 表示“星期几”；
2、EEE 表示“周几”。

作者：最后还是个农
链接：http://www.jianshu.com/p/adec8b6aefe2
來源：简书

