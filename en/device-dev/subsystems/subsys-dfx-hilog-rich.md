# HiLog Development<a name="EN-US_TOPIC_0000001185655870"></a>

## Overview<a name="section8154107175019"></a>

HiLog is the log system of OpenHarmony that provides logging for the system framework, services, and applications to record information on user operations and system running status.

This development guide is applicable to standard-system devices \(reference memory ≥ 128 MB\).

## Available APIs<a name="section6748124155012"></a>

**Table  1**  List of C++ and C APIs

<a name="table94501354193619"></a>
<table><thead align="left"><tr id="row954285483614"><th class="cellrowborder" valign="top" width="18.258174182581744%" id="mcps1.2.4.1.1"><p id="p16542254203611"><a name="p16542254203611"></a><a name="p16542254203611"></a><strong id="b17542185414366"><a name="b17542185414366"></a><a name="b17542185414366"></a>C++</strong></p>
</th>
<th class="cellrowborder" valign="top" width="43.39566043395661%" id="mcps1.2.4.1.2">&nbsp;&nbsp;</th>
<th class="cellrowborder" valign="top" width="38.34616538346165%" id="mcps1.2.4.1.3"><p id="p185431554163619"><a name="p185431554163619"></a><a name="p185431554163619"></a><strong id="b175431054123617"><a name="b175431054123617"></a><a name="b175431054123617"></a>C</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row954305418361"><td class="cellrowborder" valign="top" width="18.258174182581744%" headers="mcps1.2.4.1.1 "><p id="p3543754183618"><a name="p3543754183618"></a><a name="p3543754183618"></a><strong id="b2050619101839"><a name="b2050619101839"></a><a name="b2050619101839"></a>Class</strong></p>
</td>
<td class="cellrowborder" valign="top" width="43.39566043395661%" headers="mcps1.2.4.1.2 "><p id="p10544105453610"><a name="p10544105453610"></a><a name="p10544105453610"></a><strong id="b185619133317"><a name="b185619133317"></a><a name="b185619133317"></a>API</strong></p>
</td>
<td class="cellrowborder" valign="top" width="38.34616538346165%" headers="mcps1.2.4.1.3 "><p id="p17969916192614"><a name="p17969916192614"></a><a name="p17969916192614"></a><strong id="b1316016214312"><a name="b1316016214312"></a><a name="b1316016214312"></a>API/Macro</strong></p>
</td>
</tr>
<tr id="row8544115410361"><td class="cellrowborder" rowspan="7" valign="top" width="18.258174182581744%" headers="mcps1.2.4.1.1 "><p id="p16544154183615"><a name="p16544154183615"></a><a name="p16544154183615"></a>HiLog</p>
<p id="p956013011212"><a name="p956013011212"></a><a name="p956013011212"></a></p>
<p id="p1356013309127"><a name="p1356013309127"></a><a name="p1356013309127"></a></p>
<p id="p756011303129"><a name="p756011303129"></a><a name="p756011303129"></a></p>
<p id="p135601330191211"><a name="p135601330191211"></a><a name="p135601330191211"></a></p>
<p id="p756183091215"><a name="p756183091215"></a><a name="p756183091215"></a></p>
<p id="p1956115302128"><a name="p1956115302128"></a><a name="p1956115302128"></a></p>
</td>
<td class="cellrowborder" valign="top" width="43.39566043395661%" headers="mcps1.2.4.1.2 "><p id="p1326662513016"><a name="p1326662513016"></a><a name="p1326662513016"></a>int Debug(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" width="38.34616538346165%" headers="mcps1.2.4.1.3 "><p id="p18697644105619"><a name="p18697644105619"></a><a name="p18697644105619"></a>HILOG_DEBUG(type, ...)</p>
</td>
</tr>
<tr id="row754495418366"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p86951544155610"><a name="p86951544155610"></a><a name="p86951544155610"></a>int Info(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p96931344145615"><a name="p96931344145615"></a><a name="p96931344145615"></a>HILOG_INFO(type, ...)</p>
</td>
</tr>
<tr id="row95441954113614"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1769224485619"><a name="p1769224485619"></a><a name="p1769224485619"></a>int Warn(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1969194465613"><a name="p1969194465613"></a><a name="p1969194465613"></a>HILOG_WARN(type, ...)</p>
</td>
</tr>
<tr id="row45448547369"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4748102365615"><a name="p4748102365615"></a><a name="p4748102365615"></a>int Error(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15747142375613"><a name="p15747142375613"></a><a name="p15747142375613"></a>HILOG_ERROR(type, ...)</p>
</td>
</tr>
<tr id="row12545125453610"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5745132318560"><a name="p5745132318560"></a><a name="p5745132318560"></a>int Fatal(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107441123175615"><a name="p107441123175615"></a><a name="p107441123175615"></a>HILOG_FATAL(type, ...)</p>
</td>
</tr>
<tr id="row1454565433611"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1574242345618"><a name="p1574242345618"></a><a name="p1574242345618"></a>NA</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p197416239562"><a name="p197416239562"></a><a name="p197416239562"></a>int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...)</p>
</td>
</tr>
<tr id="row165451854193617"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p64411913343"><a name="p64411913343"></a><a name="p64411913343"></a>boolean IsLoggable(unsigned int domain, const char *tag, LogLevel level)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107388238561"><a name="p107388238561"></a><a name="p107388238561"></a>bool HiLogIsLoggable(unsigned int domain, const char *tag, LogLevel level)</p>
</td>
</tr>
<tr id="row154535415367"><td class="cellrowborder" valign="top" width="18.258174182581744%" headers="mcps1.2.4.1.1 "><p id="p795821952317"><a name="p795821952317"></a><a name="p795821952317"></a>HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="43.39566043395661%" headers="mcps1.2.4.1.2 "><p id="p20464133712224"><a name="p20464133712224"></a><a name="p20464133712224"></a>struct HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="38.34616538346165%" headers="mcps1.2.4.1.3 "><p id="p1360616314276"><a name="p1360616314276"></a><a name="p1360616314276"></a>LOG_DOMAIN</p>
<p id="p4698145992513"><a name="p4698145992513"></a><a name="p4698145992513"></a>LOG_TAG</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Parameters of C++ APIs

<a name="table19597131833715"></a>
<table><thead align="left"><tr id="row7839141817375"><th class="cellrowborder" valign="top" width="8.27%" id="mcps1.2.4.1.1"><p id="p383919182379"><a name="p383919182379"></a><a name="p383919182379"></a><strong id="b1768458647"><a name="b1768458647"></a><a name="b1768458647"></a>Class</strong></p>
</th>
<th class="cellrowborder" valign="top" width="31.41%" id="mcps1.2.4.1.2"><p id="p168392018203711"><a name="p168392018203711"></a><a name="p168392018203711"></a><strong id="b278081916236"><a name="b278081916236"></a><a name="b278081916236"></a>API</strong></p>
</th>
<th class="cellrowborder" valign="top" width="60.31999999999999%" id="mcps1.2.4.1.3"><p id="p168391618193717"><a name="p168391618193717"></a><a name="p168391618193717"></a><strong id="b399622116235"><a name="b399622116235"></a><a name="b399622116235"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row383911183378"><td class="cellrowborder" rowspan="6" valign="top" width="8.27%" headers="mcps1.2.4.1.1 "><p id="p10839318133713"><a name="p10839318133713"></a><a name="p10839318133713"></a>HiLog</p>
<p id="p58561944151216"><a name="p58561944151216"></a><a name="p58561944151216"></a></p>
<p id="p5856744201215"><a name="p5856744201215"></a><a name="p5856744201215"></a></p>
<p id="p1985664413120"><a name="p1985664413120"></a><a name="p1985664413120"></a></p>
<p id="p138562442123"><a name="p138562442123"></a><a name="p138562442123"></a></p>
<p id="p485612447125"><a name="p485612447125"></a><a name="p485612447125"></a></p>
</td>
<td class="cellrowborder" valign="top" width="31.41%" headers="mcps1.2.4.1.2 "><p id="p12483951497"><a name="p12483951497"></a><a name="p12483951497"></a>int Debug(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" width="60.31999999999999%" headers="mcps1.2.4.1.3 "><p id="p684013182375"><a name="p684013182375"></a><a name="p684013182375"></a>Generates debug logs.</p>
<p id="p1384081812377"><a name="p1384081812377"></a><a name="p1384081812377"></a>Input arguments:</p>
<a name="ul169441595136"></a><a name="ul169441595136"></a><ul id="ul169441595136"><li><strong id="b19571183520407"><a name="b19571183520407"></a><a name="b19571183520407"></a>label</strong>: Identifies the log type, service domain, and tag.</li><li><strong id="b1283512366405"><a name="b1283512366405"></a><a name="b1283512366405"></a>format</strong>: Indicates the constant format, including the parameter type and privacy identifier. If the privacy identifier is not specified, a parameter is treated as a privacy parameter by default.</li><li><strong id="b095016383402"><a name="b095016383402"></a><a name="b095016383402"></a>fmt</strong>: Indicates the string describing the format variable parameter.</li></ul>
<p id="p591585615123"><a name="p591585615123"></a><a name="p591585615123"></a>Output arguments: none</p>
<p id="p1620144161310"><a name="p1620144161310"></a><a name="p1620144161310"></a>Return value: Returns a value greater than or equal to <strong id="b267625003111"><a name="b267625003111"></a><a name="b267625003111"></a>0</strong> if the operation is successful; returns a value less than <strong id="b525912610327"><a name="b525912610327"></a><a name="b525912610327"></a>0</strong> otherwise.</p>
</td>
</tr>
<tr id="row16840101803720"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p482832616141"><a name="p482832616141"></a><a name="p482832616141"></a>int Info(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9562039395"><a name="p9562039395"></a><a name="p9562039395"></a>Generates info logs.</p>
<p id="p198849129150"><a name="p198849129150"></a><a name="p198849129150"></a>Arguments: See argument description of the <strong id="b672105414170"><a name="b672105414170"></a><a name="b672105414170"></a>Debug</strong> function.</p>
</td>
</tr>
<tr id="row198401818193712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1705727151413"><a name="p1705727151413"></a><a name="p1705727151413"></a>int Warn(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p873814715151"><a name="p873814715151"></a><a name="p873814715151"></a>Generates warn logs.</p>
<p id="p17738847151515"><a name="p17738847151515"></a><a name="p17738847151515"></a>Arguments: See argument description of the <strong id="b36421511178"><a name="b36421511178"></a><a name="b36421511178"></a>Debug</strong> function.</p>
</td>
</tr>
<tr id="row118401118203714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p55044284141"><a name="p55044284141"></a><a name="p55044284141"></a>int Error(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1558516489153"><a name="p1558516489153"></a><a name="p1558516489153"></a>Generates error logs.</p>
<p id="p1558534841512"><a name="p1558534841512"></a><a name="p1558534841512"></a>Arguments: See argument description of the <strong id="b752514831712"><a name="b752514831712"></a><a name="b752514831712"></a>Debug</strong> function.</p>
</td>
</tr>
<tr id="row3840171813374"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8306152914144"><a name="p8306152914144"></a><a name="p8306152914144"></a>int Fatal(const HiLogLabel &amp;label, const char *fmt, ...)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p625734912152"><a name="p625734912152"></a><a name="p625734912152"></a>Generates fatal logs.</p>
<p id="p1125712491157"><a name="p1125712491157"></a><a name="p1125712491157"></a>Arguments: See argument description of the <strong id="b16446443111715"><a name="b16446443111715"></a><a name="b16446443111715"></a>Debug</strong> function.</p>
</td>
</tr>
<tr id="row6840818193716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p421952291617"><a name="p421952291617"></a><a name="p421952291617"></a>boolean IsLoggable(unsigned int domain, const char *tag, LogLevel level)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3722152951615"><a name="p3722152951615"></a><a name="p3722152951615"></a>Checks whether logs of the specified service domain, tag, and level can be printed.</p>
<p id="p117221929201613"><a name="p117221929201613"></a><a name="p117221929201613"></a>Input arguments:</p>
<a name="ul1372214296164"></a><a name="ul1372214296164"></a><ul id="ul1372214296164"><li><strong id="b0822517410"><a name="b0822517410"></a><a name="b0822517410"></a>domain</strong>: Indicates the service domain of logs.</li><li><strong id="b953419064117"><a name="b953419064117"></a><a name="b953419064117"></a>tag</strong>: Indicates the log tag.</li><li><strong id="b6256659194017"><a name="b6256659194017"></a><a name="b6256659194017"></a>level</strong>: Indicates the log level.</li></ul>
<p id="p572242911167"><a name="p572242911167"></a><a name="p572242911167"></a>Output arguments: none</p>
<p id="p6722162991617"><a name="p6722162991617"></a><a name="p6722162991617"></a>Return value: Returns <strong id="b8852118175419"><a name="b8852118175419"></a><a name="b8852118175419"></a>true</strong> if the specified logs can be printed; returns <strong id="b1019141735419"><a name="b1019141735419"></a><a name="b1019141735419"></a>false</strong> otherwise.</p>
</td>
</tr>
<tr id="row15841191813371"><td class="cellrowborder" valign="top" width="8.27%" headers="mcps1.2.4.1.1 "><p id="p98771141182714"><a name="p98771141182714"></a><a name="p98771141182714"></a>HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="31.41%" headers="mcps1.2.4.1.2 "><p id="p137234972715"><a name="p137234972715"></a><a name="p137234972715"></a>struct HiLogLabel</p>
</td>
<td class="cellrowborder" valign="top" width="60.31999999999999%" headers="mcps1.2.4.1.3 "><p id="p48419181372"><a name="p48419181372"></a><a name="p48419181372"></a>Initializes log tag parameters.</p>
<p id="p335055115288"><a name="p335055115288"></a><a name="p335055115288"></a>Members:</p>
<a name="ul1235085115287"></a><a name="ul1235085115287"></a><ul id="ul1235085115287"><li><strong id="b521813144117"><a name="b521813144117"></a><a name="b521813144117"></a>type</strong>: Indicates the log type.</li><li><strong id="b1014691044111"><a name="b1014691044111"></a><a name="b1014691044111"></a>domain</strong>: Indicates the service domain of logs.</li><li><strong id="b1843710115416"><a name="b1843710115416"></a><a name="b1843710115416"></a>tag</strong>: Indicates the log tag.</li></ul>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section102728581536"></a>

### C <a name="section12916224185417"></a>

1.  Include the  **hilog**  header file in the  **.c**  source file.

    ```
    #include "hilog/log.h"
    ```

    Construct  **domain**  and  **tag**.

    ```
    #undef LOG_DOMAIN
    #undef LOG_TAG
    #define LOG_DOMAIN 0xD003200  // Indicates the service domain. The value ranges from 0xD000000 to 0xFFFFF.
    #define LOG_TAG "MY_TAG"
    ```

    Print logs.

    ```
    HILOG_INFO(LOG_CORE, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
    ```

2.  Configure compilation information. Specifically, add the subsystem SDK dependency to  **BUILD.gn**.

    ```
    external_deps = [ "hilog:libhilog" ]
    ```


### C++ <a name="section19399185610547"></a>

1.  Include the  **hilog**  header file in the  **.h**  class definition header file.

    ```
    #include "hilog/log.h"
    ```

    If log printing is required for the class header file, define  **LABEL**  at the beginning of the class definition in the header file.

    ```
    class MyClass {
    static constexpr OHOS::HiviewDFX::HiLogLabel LABEL = {LOG_CORE, 0xD003200, "MY_TAG"};
    ...
    }
    ```

    If log printing is not required for the class definition header file, define  **LABEL**  in the class implementation file.

    ```
    using namespace OHOS::HiviewDFX;
    static constexpr HiLogLabel LABEL = {LOG_CORE, 0xD003200, "MY_TAG"};
    ```

    Print logs.

    ```
    HiLog::Info(LABEL, "Failed to visit %{private}s, reason:%{public}d.", url, errno);
    ```

2.  Configure compilation information. Specifically, add the subsystem SDK dependency to  **BUILD.gn**.

    ```
    external_deps = [ "hiviewdfx:libhilog" ]
    ```


