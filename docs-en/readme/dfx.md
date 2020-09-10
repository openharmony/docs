# DFX<a name="EN-US_TOPIC_0000001051742157"></a>

## Introduction<a name="section11660541593"></a>

This repository is used to store the code of Design for X \(DFX\) frameworks, including Design for Reliability \(DFR\) and Design for Testability \(DFT\).

As chip resources are limited and hardware platforms are diversified, component-based and customizable DFX frameworks need to be provided for different hardware architectures and resources. Two types of lightweight DFX frameworks \(mini and featured\) are available for hardware platforms powered by RISC-V, Cortex-M, and Cortex-A.

-   mini: This framework is intended for hardware platforms with Cortex-M or equivalent processing capabilities. The system memory is generally less than 512 KB. There is only one lightweight file system that can be used in limited scenarios, or no file system at all. The mini framework complies with the Cortex Microcontroller Software Interface Standard \(CMSIS\).

-   featured: This framework is intended for hardware platforms with Cortex-A or equivalent processing capabilities. The system memory is greater than 512 KB. There is a comprehensive file system for storing a large amount of data. The featured framework complies with the Portable Operating System Interface \(POSIX\) specifications.


## Directory Structure<a name="section1464106163817"></a>

**Table  1**  Directory structure of the source code for lightweight DFX

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="30.34%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="69.66%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>interface</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>Stores all header files for open APIs.</p>
</td>
</tr>
<tr id="row259142201312"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p5197366257"><a name="p5197366257"></a><a name="p5197366257"></a>interfaces/kits/hilog</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p10406450131319"><a name="p10406450131319"></a><a name="p10406450131319"></a>Defines open APIs available for logs in the featured framework.</p>
</td>
</tr>
<tr id="row580915918401"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p9809189144014"><a name="p9809189144014"></a><a name="p9809189144014"></a>interfaces/kits/hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p168101694401"><a name="p168101694401"></a><a name="p168101694401"></a>Defines open APIs available for logs in the mini framework.</p>
</td>
</tr>
<tr id="row1188919458130"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p14561174816401"><a name="p14561174816401"></a><a name="p14561174816401"></a>interfaces/innerkits/hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p1254413131146"><a name="p1254413131146"></a><a name="p1254413131146"></a>Defines open APIs available for event printing in the mini framework.</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>services/hilogcat_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a>Stores services and commands related to logs.</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p1738210441049"><a name="p1738210441049"></a><a name="p1738210441049"></a>services/hilogcat_lite/apphilogcat</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p1629020401941"><a name="p1629020401941"></a><a name="p1629020401941"></a>Provides the log flushing to disk service in the featured framework.</p>
</td>
</tr>
<tr id="row1596814581415"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p158313363613"><a name="p158313363613"></a><a name="p158313363613"></a>services/hilogcat_lite/command</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p12969358749"><a name="p12969358749"></a><a name="p12969358749"></a>Provides DFX commands specific to the mini framework.</p>
</td>
</tr>
<tr id="row175618551244"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p73791172718"><a name="p73791172718"></a><a name="p73791172718"></a>services/hilogcat_lite/hilogcat</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p107568558416"><a name="p107568558416"></a><a name="p107568558416"></a>Provides commands to output logs in the featured framework.</p>
</td>
</tr>
<tr id="row11587111583"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p4491153104614"><a name="p4491153104614"></a><a name="p4491153104614"></a>services/hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p159210361388"><a name="p159210361388"></a><a name="p159210361388"></a>Registers the DFX service specific to the mini framework.</p>
</td>
</tr>
<tr id="row144311669479"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p443219624716"><a name="p443219624716"></a><a name="p443219624716"></a>frameworks/ddrdump_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p343218604718"><a name="p343218604718"></a><a name="p343218604718"></a>Dumps Double Data Rate (DDR) memory in the mini framework.</p>
</td>
</tr>
<tr id="row1125881215472"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p52581712124718"><a name="p52581712124718"></a><a name="p52581712124718"></a>frameworks/hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p1825921284710"><a name="p1825921284710"></a><a name="p1825921284710"></a>Records event printing in the DFX-mini framework.</p>
</td>
</tr>
<tr id="row13101195476"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p1210117994714"><a name="p1210117994714"></a><a name="p1210117994714"></a>frameworks/hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p910159144719"><a name="p910159144719"></a><a name="p910159144719"></a>Defines APIs for logging.</p>
</td>
</tr>
<tr id="row2442416175011"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p14911117105011"><a name="p14911117105011"></a><a name="p14911117105011"></a>frameworks/hilog_lite/featured</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p18491171775019"><a name="p18491171775019"></a><a name="p18491171775019"></a>Defines APIs for logging in the featured framework.</p>
</td>
</tr>
<tr id="row481417116116"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p468592018492"><a name="p468592018492"></a><a name="p468592018492"></a>frameworks/hilog_lite/mini</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p2051115253494"><a name="p2051115253494"></a><a name="p2051115253494"></a>Defines APIs for logging in the mini framework.</p>
</td>
</tr>
<tr id="row13247163492"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p710851611910"><a name="p710851611910"></a><a name="p710851611910"></a>utils/lite</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p112471431895"><a name="p112471431895"></a><a name="p112471431895"></a>Stores utils. It contains the configuration items of the mini framework.</p>
</td>
</tr>
</tbody>
</table>

## Constraints<a name="section1718733212019"></a>

The overall code of the mini framework is developed based on the C standard library.

## Usage \(mini Framework\)<a name="section99168524220"></a>

The mini framework is a simple and compact DFX design that provides the logging function.

-   **The following takes Module A as an example to describe how to add a module and print logs.**
    1.  **Step 1: Add the module ID.**

        Define  **HILOG\_MODULE\_A**  in  **HiLogModuleDef**  of  **interfaces/kits/hilog\_lite/hiview\_log.h**.

        ```
        typedef enum {
            /** DFX */    
            HILOG_MODULE_HIVIEW = 0,    
            /** System Module A */    
            HILOG_MODULE_A,    
            /** Maximum number of modules */
            HILOG_MODULE_MAX
        } HiLogModuleType;
        ```


    1.  **Step 2: Register the module.**

        Add the following code to the initialization process of Module A to register it with the logging framework:

        ```
        HiLogRegisterModule(HILOG_MODULE_SAMGR, "A");
        ```


    1.  **Step 3: Modify the static configuration of the DFX framework.**

        Modify  **g\_hiviewConfig**  in the following file as required \(By default, modification is not required and logs are output to the serial port\):

        ```
        utils/lite/hiview_config.c
        ```

        <a name="table15664428164516"></a>
        <table><thead align="left"><tr id="row07061028154510"><th class="cellrowborder" valign="top" width="25.180000000000003%" id="mcps1.1.3.1.1"><p id="p10706128184514"><a name="p10706128184514"></a><a name="p10706128184514"></a>Configuration Item</p>
        </th>
        <th class="cellrowborder" valign="top" width="74.82%" id="mcps1.1.3.1.2"><p id="p11706928194520"><a name="p11706928194520"></a><a name="p11706928194520"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row8706828154511"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p19706112824514"><a name="p19706112824514"></a><a name="p19706112824514"></a>outputOption</p>
        </td>
        <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p9706528104512"><a name="p9706528104512"></a><a name="p9706528104512"></a>Log output mode. The value can be:</p>
        <p id="p107061428124515"><a name="p107061428124515"></a><a name="p107061428124515"></a><strong id="b6352161513619"><a name="b6352161513619"></a><a name="b6352161513619"></a>OUTPUT_OPTION_DEBUG</strong>: Logs are directly output to the serial port without cross-task scheduling. This value is used only for temporary debugging.</p>
        <p id="p870682819450"><a name="p870682819450"></a><a name="p870682819450"></a><strong id="b15600163173718"><a name="b15600163173718"></a><a name="b15600163173718"></a>OUTPUT_OPTION_FLOW</strong> (default value): Logs are output as data flow to the serial port.</p>
        <p id="p16707182819454"><a name="p16707182819454"></a><a name="p16707182819454"></a><strong id="b18859428385"><a name="b18859428385"></a><a name="b18859428385"></a>OUTPUT_OPTION_TEXT_FILE</strong>: Logs are output as text files.</p>
        <p id="p117071528184514"><a name="p117071528184514"></a><a name="p117071528184514"></a><strong id="b20341927163912"><a name="b20341927163912"></a><a name="b20341927163912"></a>OUTPUT_OPTION_BIN_FILE</strong> (to be supported): Logs are output as binary files.</p>
        </td>
        </tr>
        <tr id="row1270720281453"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p137071528164516"><a name="p137071528164516"></a><a name="p137071528164516"></a>level</p>
        </td>
        <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p177071428154510"><a name="p177071428154510"></a><a name="p177071428154510"></a>Log level for output. Only the logs whose levels are higher than or equal to the level specified by this parameter can be output. The value can be:</p>
        <p id="p1470712824515"><a name="p1470712824515"></a><a name="p1470712824515"></a><strong id="b388817225412"><a name="b388817225412"></a><a name="b388817225412"></a>HILOG_LV_DEBUG</strong>, <strong id="b1010817302414"><a name="b1010817302414"></a><a name="b1010817302414"></a>HILOG_LV_INFO</strong>, <strong id="b1888283212411"><a name="b1888283212411"></a><a name="b1888283212411"></a>HILOG_LV_WARN</strong>, <strong id="b863582564112"><a name="b863582564112"></a><a name="b863582564112"></a>HILOG_LV_ERROR</strong>, or <strong id="b108501827164112"><a name="b108501827164112"></a><a name="b108501827164112"></a>HILOG_LV_FATAL</strong></p>
        </td>
        </tr>
        <tr id="row17707142814513"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p11707192814517"><a name="p11707192814517"></a><a name="p11707192814517"></a>logSwitch</p>
        </td>
        <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p870711281452"><a name="p870711281452"></a><a name="p870711281452"></a>Logging switch. The <strong id="b1250835814425"><a name="b1250835814425"></a><a name="b1250835814425"></a>log</strong> component can be successfully initialized even if this switch is turned off before compilation. By default, this switch is turned on. The value can be:</p>
        <p id="p1570822810456"><a name="p1570822810456"></a><a name="p1570822810456"></a><strong id="b860151584911"><a name="b860151584911"></a><a name="b860151584911"></a>HIVIEW_FEATURE_ON</strong> or <strong id="b63541819493"><a name="b63541819493"></a><a name="b63541819493"></a>HIVIEW_FEATURE_OFF</strong></p>
        </td>
        </tr>
        <tr id="row6708132813453"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p1570813280453"><a name="p1570813280453"></a><a name="p1570813280453"></a>dumpSwitch</p>
        </td>
        <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p970852810459"><a name="p970852810459"></a><a name="p970852810459"></a>Dumping switch. If this switch is turned off before compilation, the <strong id="b16360195184914"><a name="b16360195184914"></a><a name="b16360195184914"></a>DUMP</strong> component will not be initialized. By default, this switch is turned off. The value can be:</p>
        <p id="p147081328174519"><a name="p147081328174519"></a><a name="p147081328174519"></a><strong id="b1139516363532"><a name="b1139516363532"></a><a name="b1139516363532"></a>HIVIEW_FEATURE_ON</strong> or <strong id="b16939113816534"><a name="b16939113816534"></a><a name="b16939113816534"></a>HIVIEW_FEATURE_OFF</strong></p>
        </td>
        </tr>
        <tr id="row87081282452"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p11708128124511"><a name="p11708128124511"></a><a name="p11708128124511"></a>eventSwitch</p>
        </td>
        <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p17708202834519"><a name="p17708202834519"></a><a name="p17708202834519"></a>Event output switch. If this switch is turned off before compilation, the <strong id="b20168720541"><a name="b20168720541"></a><a name="b20168720541"></a>Event</strong> component will not be initialized. By default, this switch is turned off. The value can be:</p>
        <p id="p1670852894513"><a name="p1670852894513"></a><a name="p1670852894513"></a><strong id="b146761815543"><a name="b146761815543"></a><a name="b146761815543"></a>HIVIEW_FEATURE_ON</strong> or <strong id="b1816422311548"><a name="b1816422311548"></a><a name="b1816422311548"></a>HIVIEW_FEATURE_OFF</strong></p>
        </td>
        </tr>
        </tbody>
        </table>

    2.  **Step 4: Print logs.**

        Include  **\#include "log.h"**  in the  **.c**  file where logs need to be printed, call the following function:

        HILOG\_INFO\(HILOG\_MODULE\_SAMGR, "log test: %d", 88\);

        Parameter description:

        <a name="table119971217175510"></a>
        <table><thead align="left"><tr id="row1350818135519"><th class="cellrowborder" valign="top" width="11.57%" id="mcps1.1.5.1.1"><p id="p175031855513"><a name="p175031855513"></a><a name="p175031855513"></a>Parameter</p>
        </th>
        <th class="cellrowborder" valign="top" width="11.83%" id="mcps1.1.5.1.2"><p id="p250131825511"><a name="p250131825511"></a><a name="p250131825511"></a>Mandatory</p>
        </th>
        <th class="cellrowborder" valign="top" width="15.21%" id="mcps1.1.5.1.3"><p id="p3501418175516"><a name="p3501418175516"></a><a name="p3501418175516"></a>Data Type</p>
        </th>
        <th class="cellrowborder" valign="top" width="61.39%" id="mcps1.1.5.1.4"><p id="p12501718125512"><a name="p12501718125512"></a><a name="p12501718125512"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row195016185559"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p6503180557"><a name="p6503180557"></a><a name="p6503180557"></a>mod</p>
        </td>
        <td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p45061835518"><a name="p45061835518"></a><a name="p45061835518"></a>Yes</p>
        </td>
        <td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1050618155511"><a name="p1050618155511"></a><a name="p1050618155511"></a>uint8</p>
        </td>
        <td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p1051618115519"><a name="p1051618115519"></a><a name="p1051618115519"></a>Module or service ID.</p>
        <p id="p2511918165511"><a name="p2511918165511"></a><a name="p2511918165511"></a>IDs are planned and allocated in a unified manner. A maximum of 64 IDs are supported. Third-party applications use <strong id="b0632102212343"><a name="b0632102212343"></a><a name="b0632102212343"></a>HILOG_MODULE_APP</strong> as their module ID.</p>
        </td>
        </tr>
        <tr id="row451818105516"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p15151845520"><a name="p15151845520"></a><a name="p15151845520"></a>fmt</p>
        </td>
        <td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p251111817557"><a name="p251111817557"></a><a name="p251111817557"></a>Yes</p>
        </td>
        <td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p1351151814555"><a name="p1351151814555"></a><a name="p1351151814555"></a>char *</p>
        </td>
        <td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p95117189556"><a name="p95117189556"></a><a name="p95117189556"></a>Format specifier for output.</p>
        <p id="p25171895512"><a name="p25171895512"></a><a name="p25171895512"></a>1. A maximum of six variable parameters are supported. %s is not supported.</p>
        <p id="p351181875510"><a name="p351181875510"></a><a name="p351181875510"></a>2. The maximum length of a formatted log record is 128 bytes. If the length of a log exceeds 128 bytes, the log cannot be printed.</p>
        </td>
        </tr>
        <tr id="row95213183550"><td class="cellrowborder" valign="top" width="11.57%" headers="mcps1.1.5.1.1 "><p id="p15291815518"><a name="p15291815518"></a><a name="p15291815518"></a>Variable parameters</p>
        </td>
        <td class="cellrowborder" valign="top" width="11.83%" headers="mcps1.1.5.1.2 "><p id="p1852151815514"><a name="p1852151815514"></a><a name="p1852151815514"></a>No</p>
        </td>
        <td class="cellrowborder" valign="top" width="15.21%" headers="mcps1.1.5.1.3 "><p id="p145221855520"><a name="p145221855520"></a><a name="p145221855520"></a>int32</p>
        </td>
        <td class="cellrowborder" valign="top" width="61.39%" headers="mcps1.1.5.1.4 "><p id="p15521018115510"><a name="p15521018115510"></a><a name="p15521018115510"></a>Only numeric types are supported. A maximum of six variable parameters are allowed.</p>
        </td>
        </tr>
        </tbody>
        </table>



## Usage \(featured Framework\)<a name="section166251104236"></a>

The featured framework provides comprehensive DFX features and logging APIs.

**Native C/C++**  APIs

Available hilog APIs:

```
HILOGD(fmt,...) HILOGI(fmt,...) HILOGW(fmt,...) HILOGE(fmt,...)
```

Usage guidelines:

1. Define the log tag.

2. Perform local debugging. \(The domain value  **0**  can be used.\)

3. Include the header file: \#include <hilog/log.h\>

4. Add the dependent library  **libhilog**  to  **BUILD.gn**.

API rules:

1. The format specifier is labeled public by default, for example,  **HILOGI\("Hello World\\n"\); \>\> Hello World**.

2. The formatted parameter is labeled private by default, for example,  **HILOGI\("Age is %d\\n", 10\); \>\> Age is <private\>**.

3. Parameters labeled  **%\{private\}**  are private data, for example,  **HILOGI\("Age is %\{private\}d\\n", 10\); \>\> Age is <private\>**.

4. Parameters labeled  **%\{public\}**  are public data, for example,  **HILOGI\("Age is %\{public\}d\\n", 10\); \>\>Age is 10**.

Parameter description:

<a name="table2021218594324"></a>
<table><thead align="left"><tr id="row72672598321"><th class="cellrowborder" valign="top" width="25.94%" id="mcps1.1.3.1.1"><p id="p1226718595323"><a name="p1226718595323"></a><a name="p1226718595323"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="74.06%" id="mcps1.1.3.1.2"><p id="p1026765918324"><a name="p1026765918324"></a><a name="p1026765918324"></a>Description:</p>
</th>
</tr>
</thead>
<tbody><tr id="row152675592321"><td class="cellrowborder" valign="top" width="25.94%" headers="mcps1.1.3.1.1 "><p id="p12267135915328"><a name="p12267135915328"></a><a name="p12267135915328"></a>domain</p>
</td>
<td class="cellrowborder" valign="top" width="74.06%" headers="mcps1.1.3.1.2 "><p id="p1826745953219"><a name="p1826745953219"></a><a name="p1826745953219"></a>Domain ID</p>
</td>
</tr>
<tr id="row20267135963212"><td class="cellrowborder" valign="top" width="25.94%" headers="mcps1.1.3.1.1 "><p id="p152675591328"><a name="p152675591328"></a><a name="p152675591328"></a>tag</p>
</td>
<td class="cellrowborder" valign="top" width="74.06%" headers="mcps1.1.3.1.2 "><p id="p4267145920323"><a name="p4267145920323"></a><a name="p4267145920323"></a>Log tag</p>
</td>
</tr>
<tr id="row02671159203214"><td class="cellrowborder" valign="top" width="25.94%" headers="mcps1.1.3.1.1 "><p id="p1926785953216"><a name="p1926785953216"></a><a name="p1926785953216"></a>isFmtPrivate</p>
</td>
<td class="cellrowborder" valign="top" width="74.06%" headers="mcps1.1.3.1.2 "><p id="p326785963220"><a name="p326785963220"></a><a name="p326785963220"></a>Whether the format specifier is private</p>
</td>
</tr>
<tr id="row326795910325"><td class="cellrowborder" valign="top" width="25.94%" headers="mcps1.1.3.1.1 "><p id="p72678597327"><a name="p72678597327"></a><a name="p72678597327"></a>fmt</p>
</td>
<td class="cellrowborder" valign="top" width="74.06%" headers="mcps1.1.3.1.2 "><p id="p11267195914324"><a name="p11267195914324"></a><a name="p11267195914324"></a>Format specifier</p>
</td>
</tr>
<tr id="row1226825913326"><td class="cellrowborder" valign="top" width="25.94%" headers="mcps1.1.3.1.1 "><p id="p142681259203215"><a name="p142681259203215"></a><a name="p142681259203215"></a>args</p>
</td>
<td class="cellrowborder" valign="top" width="74.06%" headers="mcps1.1.3.1.2 "><p id="p1326895911325"><a name="p1326895911325"></a><a name="p1326895911325"></a>Parameters to be displayed using the format specifier</p>
</td>
</tr>
</tbody>
</table>

**Viewing logs**

1.  Go to the  **/storage/data/log/hilogs**  directory to view hilog logs for debugging purpose.

2.  Run the  **hilogcat**  command to view hilog logs in real time.


**Logging system architecture**

![](figures/en-us_image_0000001054762887.png)

1.  hilogtask: kernel task for logging
    -   This is a task or thread of the Linux kernel. It is initialized during system startup.
    -   When a module in the kernel calls its logging API, it transfers the formatted log content to the task and stores it in a ringbuffer.
    -   When the logging API is called in user space, the formatted log content is written into the driver node by calling  **ioctl**. The driver node then sends the log content to hilogtask, and hilogtask stores the log content in the ringbuffer.

2.  hilogcatd: storing logs in user space
    -   This is a user-space process. It periodically reads the log content from the ringbuffer and stores it in the log file.
    -   Log files can be compressed in  **gzip**  format by using  **zlib**.
    -   The size of a single file and the number of files can be configured during compilation.

3.  hilogcat: command line tool for viewing logs

    This tool reads the content in the ringbuffer content via the kernel driver API, and then outputs the content to  **stdout**.

4.  ringbuffer: configurable
    -   The ringbuffer size can be configured during compilation.


## Repositories Involved<a name="section6899131818455"></a>

hiviewdfx\_frameworks\_hievent\_lite

hiviewdfx\_frameworks\_ddrdump\_lite

hiviewdfx\_frameworks\_hilog\_lite

hiviewdfx\_interfaces\_innerkits\_hilog

hiviewdfx\_interfaces\_innerkits\_hievent\_lite

hiviewdfx\_interfaces\_kits\_hilog

hiviewdfx\_interfaces\_kits\_hilog\_lite

hiviewdfx\_services\_hiview\_lite

hiviewdfx\_services\_hilogcat\_lite

hiviewdfx\_utils\_lite

