# HiLog开发指导<a name="ZH-CN_TOPIC_0000001081129329"></a>

-   [概述](#section8154107175019)
-   [接口说明](#section6748124155012)
-   [开发实例](#section102728581536)
    -   [C使用示例](#section12916224185417)
    -   [C++使用示例](#section19399185610547)


## 概述<a name="section8154107175019"></a>

HiLog是OpenHarmony日志系统，提供给系统框架、服务、以及应用打印日志，记录用户操作、系统运行状态等。

本章节内容对标准系统类设备（参考内存≥128MB）适用。

## 接口说明<a name="section6748124155012"></a>

**表 1**  C++、C的函数接口

<a name="table94501354193619"></a>
<table><thead align="left"><tr id="row954285483614"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.4.1.1"><p id="p16542254203611"><a name="p16542254203611"></a><a name="p16542254203611"></a><strong id="b17542185414366"><a name="b17542185414366"></a><a name="b17542185414366"></a>C++</strong></p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.4.1.2"><p id="p185431554163619"><a name="p185431554163619"></a><a name="p185431554163619"></a><strong id="b175431054123617"><a name="b175431054123617"></a><a name="b175431054123617"></a>C</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row954305418361"><td class="cellrowborder" valign="top" width="18.388161183881614%" headers="mcps1.2.4.1.1 "><p id="p3543754183618"><a name="p3543754183618"></a><a name="p3543754183618"></a><strong id="b45431554113615"><a name="b45431554113615"></a><a name="b45431554113615"></a>类</strong></p>
</td>
<td class="cellrowborder" valign="top" width="43.53564643535647%" headers="mcps1.2.4.1.1 "><p id="p10544105453610"><a name="p10544105453610"></a><a name="p10544105453610"></a><strong id="b22281259122314"><a name="b22281259122314"></a><a name="b22281259122314"></a>方法</strong></p>
</td>
<td class="cellrowborder" valign="top" width="38.076192380761924%" headers="mcps1.2.4.1.2 "><p id="p17969916192614"><a name="p17969916192614"></a><a name="p17969916192614"></a><strong id="b1654320344267"><a name="b1654320344267"></a><a name="b1654320344267"></a>方法/宏</strong></p>
</td>
</tr>
<tr id="row8544115410361"><td class="cellrowborder" rowspan="7" valign="top" width="18.388161183881614%" headers="mcps1.2.4.1.1 "><p id="p16544154183615"><a name="p16544154183615"></a><a name="p16544154183615"></a>HiLog</p>
</td>
<td class="cellrowborder" valign="top" width="43.53564643535647%" headers="mcps1.2.4.1.1 "><p id="p1326662513016"><a name="p1326662513016"></a><a name="p1326662513016"></a>int Debug(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" width="38.076192380761924%" headers="mcps1.2.4.1.2 "><p id="p18697644105619"><a name="p18697644105619"></a><a name="p18697644105619"></a>HILOG_DEBUG(type, ...)</p>
</td>
</tr>
<tr id="row754495418366"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p86951544155610"><a name="p86951544155610"></a><a name="p86951544155610"></a>int Info(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p96931344145615"><a name="p96931344145615"></a><a name="p96931344145615"></a>HILOG_INFO(type, ...)</p>
</td>
</tr>
<tr id="row95441954113614"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1769224485619"><a name="p1769224485619"></a><a name="p1769224485619"></a>int Warn(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1969194465613"><a name="p1969194465613"></a><a name="p1969194465613"></a>HILOG_WARN(type, ...)</p>
</td>
</tr>
<tr id="row45448547369"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4748102365615"><a name="p4748102365615"></a><a name="p4748102365615"></a>int Error(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15747142375613"><a name="p15747142375613"></a><a name="p15747142375613"></a>HILOG_ERROR(type, ...)</p>
</td>
</tr>
<tr id="row12545125453610"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5745132318560"><a name="p5745132318560"></a><a name="p5745132318560"></a>int Fatal(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p107441123175615"><a name="p107441123175615"></a><a name="p107441123175615"></a>HILOG_FATAL(type, ...)</p>
</td>
</tr>
<tr id="row1454565433611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1574242345618"><a name="p1574242345618"></a><a name="p1574242345618"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p197416239562"><a name="p197416239562"></a><a name="p197416239562"></a>int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...)</p>
</td>
</tr>
<tr id="row165451854193617"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p64411913343"><a name="p64411913343"></a><a name="p64411913343"></a>boolean IsLoggable(unsigned int domain, const char *tag, LogLevel level)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p107388238561"><a name="p107388238561"></a><a name="p107388238561"></a>bool HiLogIsLoggable(unsigned int domain, const char *tag, LogLevel level)</p>
</td>
</tr>
<tr id="row154535415367"><td class="cellrowborder" valign="top" width="18.388161183881614%" headers="mcps1.2.4.1.1 "><p id="p795821952317"><a name="p795821952317"></a><a name="p795821952317"></a>HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="43.53564643535647%" headers="mcps1.2.4.1.1 "><p id="p20464133712224"><a name="p20464133712224"></a><a name="p20464133712224"></a>struct HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="38.076192380761924%" headers="mcps1.2.4.1.2 "><p id="p1360616314276"><a name="p1360616314276"></a><a name="p1360616314276"></a>LOG_DOMAIN</p>
<p id="p4698145992513"><a name="p4698145992513"></a><a name="p4698145992513"></a>LOG_TAG</p>
</td>
</tr>
</tbody>
</table>

**表 2**  C++接口说明函数参数和功能

<a name="table19597131833715"></a>
<table><thead align="left"><tr id="row7839141817375"><th class="cellrowborder" valign="top" width="8.27%" id="mcps1.2.4.1.1"><p id="p383919182379"><a name="p383919182379"></a><a name="p383919182379"></a><strong id="b0839191863717"><a name="b0839191863717"></a><a name="b0839191863717"></a>类</strong></p>
</th>
<th class="cellrowborder" valign="top" width="31.41%" id="mcps1.2.4.1.2"><p id="p168392018203711"><a name="p168392018203711"></a><a name="p168392018203711"></a><strong id="b4208111244510"><a name="b4208111244510"></a><a name="b4208111244510"></a>方法</strong></p>
</th>
<th class="cellrowborder" valign="top" width="60.31999999999999%" id="mcps1.2.4.1.3"><p id="p168391618193717"><a name="p168391618193717"></a><a name="p168391618193717"></a><strong id="b521141218453"><a name="b521141218453"></a><a name="b521141218453"></a>描述</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row383911183378"><td class="cellrowborder" rowspan="6" valign="top" width="8.27%" headers="mcps1.2.4.1.1 "><p id="p10839318133713"><a name="p10839318133713"></a><a name="p10839318133713"></a>HiLog</p>
</td>
<td class="cellrowborder" valign="top" width="31.41%" headers="mcps1.2.4.1.2 "><p id="p12483951497"><a name="p12483951497"></a><a name="p12483951497"></a>int Debug(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" width="60.31999999999999%" headers="mcps1.2.4.1.3 "><p id="p684013182375"><a name="p684013182375"></a><a name="p684013182375"></a>功能：输出 debug 级别日志。</p>
<p id="p1384081812377"><a name="p1384081812377"></a><a name="p1384081812377"></a>输入参数：</p>
<a name="ul169441595136"></a><a name="ul169441595136"></a><ul id="ul169441595136"><li>label：用于标识输出日志的类型、业务领域、TAG。</li><li>format：常量格式字符串，包含参数类型、隐私标识。未加隐私标识的缺省为隐私参数。</li><li>fmt：格式化变参描述字符串。</li></ul>
<p id="p591585615123"><a name="p591585615123"></a><a name="p591585615123"></a>输出参数：无</p>
<p id="p1620144161310"><a name="p1620144161310"></a><a name="p1620144161310"></a>返回值：大于等于0，成功；小于0，失败。</p>
</td>
</tr>
<tr id="row16840101803720"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p482832616141"><a name="p482832616141"></a><a name="p482832616141"></a>int Info(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9562039395"><a name="p9562039395"></a><a name="p9562039395"></a>功能：输出 info 级别日志。</p>
<p id="p198849129150"><a name="p198849129150"></a><a name="p198849129150"></a>参数说明同 Debug 接口。</p>
</td>
</tr>
<tr id="row198401818193712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1705727151413"><a name="p1705727151413"></a><a name="p1705727151413"></a>int Warn(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p873814715151"><a name="p873814715151"></a><a name="p873814715151"></a>功能：输出 warn 级别日志。</p>
<p id="p17738847151515"><a name="p17738847151515"></a><a name="p17738847151515"></a>参数说明同 Debug 接口。</p>
</td>
</tr>
<tr id="row118401118203714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p55044284141"><a name="p55044284141"></a><a name="p55044284141"></a>int Error(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1558516489153"><a name="p1558516489153"></a><a name="p1558516489153"></a>功能：输出 error 级别日志。</p>
<p id="p1558534841512"><a name="p1558534841512"></a><a name="p1558534841512"></a>参数说明同 Debug 接口。</p>
</td>
</tr>
<tr id="row3840171813374"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8306152914144"><a name="p8306152914144"></a><a name="p8306152914144"></a>int Fatal(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p625734912152"><a name="p625734912152"></a><a name="p625734912152"></a>功能：输出 fatal 级别日志。</p>
<p id="p1125712491157"><a name="p1125712491157"></a><a name="p1125712491157"></a>参数说明同 Debug 接口。</p>
</td>
</tr>
<tr id="row6840818193716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p421952291617"><a name="p421952291617"></a><a name="p421952291617"></a>boolean IsLoggable(unsigned int domain, const char *tag, LogLevel level)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3722152951615"><a name="p3722152951615"></a><a name="p3722152951615"></a>功能：检查指定业务领域、TAG、级别的日志是否可以打印。</p>
<p id="p117221929201613"><a name="p117221929201613"></a><a name="p117221929201613"></a>输入参数：</p>
<a name="ul1372214296164"></a><a name="ul1372214296164"></a><ul id="ul1372214296164"><li>domain：指定日志业务领域。</li><li>tag: 指定日志TAG。</li><li>level: 指定日志level。</li></ul>
<p id="p572242911167"><a name="p572242911167"></a><a name="p572242911167"></a>输出参数：无</p>
<p id="p6722162991617"><a name="p6722162991617"></a><a name="p6722162991617"></a>返回值：如果指定domain、tag、level日志可以打印则返回true；否则返回false。</p>
</td>
</tr>
<tr id="row15841191813371"><td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.2.4.1.1 "><p id="p98771141182714"><a name="p98771141182714"></a><a name="p98771141182714"></a>HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="31.41%" headers="mcps1.2.4.1.2 "><p id="p137234972715"><a name="p137234972715"></a><a name="p137234972715"></a>struct HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="60.31999999999999%" headers="mcps1.2.4.1.3 "><p id="p48419181372"><a name="p48419181372"></a><a name="p48419181372"></a>功能：初始化日志标签参数。</p>
<p id="p335055115288"><a name="p335055115288"></a><a name="p335055115288"></a>成员参数：</p>
<a name="ul1235085115287"></a><a name="ul1235085115287"></a><ul id="ul1235085115287"><li>domain：指定日志业务领域。</li><li>tag: 指定日志TAG。</li><li>level: 指定日志level。</li></ul>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section102728581536"></a>

### C使用示例<a name="section12916224185417"></a>

1.  在.c源文件中，包含hilog头文件：

    ```
    #include "hilog/log.h"
    ```

    定义domain、tag：

    ```
    #undef LOG_DOMAIN
    #undef LOG_TAG
    #define LOG_DOMAIN 0  // 标识业务领域，范围0x0~0xFFFFF
    #define LOG_TAG "MY_TAG"
    ```

    打印日志：

    ```
    HILOG_INFO(LOG_CORE, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
    ```

2.  编译设置，在BUILD.gn里增加子系统SDK依赖：

    ```
    external_deps = [ "hiviewdfx_hilog_native:libhilog" ]
    ```


### C++使用示例<a name="section19399185610547"></a>

1.  在.h类定义头文件中，包含hilog头文件：

    ```
    #include "hilog/log.h"
    ```

    如果类头文件中需要日志打印，在头文件中类定义起始处 定义 LABEL：

    ```
    class MyClass {
    static constexpr OHOS::HiviewDFX::HiLogLabel LABEL = {LOG_CORE, 0, "MY_TAG"}; 
    ......
    }
    ```

    如果类头文件中没有日志打印，在类实现文件中 定义 LABEL：

    ```
    using namespace OHOS::HiviewDFX;
    static constexpr HiLogLabel LABEL = {LOG_CORE, 0, "MY_TAG"}; 
    ```

    打印日志：

    ```
    HiLog::Info(LABEL, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
    ```

2.  编译设置，在BUILD.gn里增加子系统SDK依赖：

    ```
    external_deps = [ "hiviewdfx:libhilog" ]
    ```


