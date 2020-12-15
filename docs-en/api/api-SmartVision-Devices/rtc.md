# RTC<a name="EN-US_TOPIC_0000001055039466"></a>

-   [Overview](#section471241871165623)
-   [Summary](#section162759248165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1063913536165623)
-   [Typedef](#section1614801129165623)
-   [RtcAlarmCallback](#gaf9932b7e647bce0503f1314bbe5eef8d)
-   [Enumeration Type](#section1322628777165623)
-   [RtcAlarmIndex](#gad7b3a575c848e2669db5e5b6f7e74330)
-   [Function](#section173008276165623)
-   [RtcAlarmInterruptEnable\(\)](#ga8b0f2951646ebd17313d905553bd8e0e)
-   [RtcClose\(\)](#ga395aa79ef260bfcd603ed56f9839d73b)
-   [RtcGetFreq\(\)](#ga766e2df8045177cd030e1133df4cba12)
-   [RtcOpen\(\)](#ga35004a866f23081ce2a446f1b0f88e32)
-   [RtcReadAlarm\(\)](#gabc4a137f0aed13e41da2db2dccc32b08)
-   [RtcReadReg\(\)](#gaec39316c639860a032f802628276d366)
-   [RtcReadTime\(\)](#gae8b242769eacd00b71eb1debce9be4de)
-   [RtcRegisterAlarmCallback\(\)](#ga0c42d787adde8d56a82b0c21624049d5)
-   [RtcReset\(\)](#ga7eb8a5ecf1058b9f90a133e2caa14573)
-   [RtcSetFreq\(\)](#ga17fdfb7ba3c876974cf9099aab092345)
-   [RtcWriteAlarm\(\)](#gaf4dd53c3e5b6c7a1766f6b15a77c96e9)
-   [RtcWriteReg\(\)](#gab8cc20f50b103acef06aa7887610be1c)
-   [RtcWriteTime\(\)](#ga7b6da87bfe9af2bcbfeebe9793876eb8)

## **Overview**<a name="section471241871165623"></a>

**Description:**

Provides standard real-time clock \(RTC\) APIs. 

These APIs allow you to perform operations such as reading or writing system time, reading or writing alarm time, setting alarm interrupts, registering alarm callbacks, setting the external frequency, resetting the RTC driver, and customizing RTC configurations. The RTC driver provides precise real time for the operating system \(OS\). If the OS is powered off, the RTC driver continues to keep track of the system time using an external battery.

**Since:**

1.0

## **Summary**<a name="section162759248165623"></a>

## Files<a name="files"></a>

<a name="table1571742485165623"></a>
<table><thead align="left"><tr id="row27504757165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p27042430165623"><a name="p27042430165623"></a><a name="p27042430165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1832083458165623"><a name="p1832083458165623"></a><a name="p1832083458165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1957794699165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323590233165623"><a name="p1323590233165623"></a><a name="p1323590233165623"></a><a href="rtc_if-h.md">rtc_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016002406165623"><a name="p1016002406165623"></a><a name="p1016002406165623"></a>Declares the standard RTC APIs. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table508019297165623"></a>
<table><thead align="left"><tr id="row1029355419165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p941827414165623"><a name="p941827414165623"></a><a name="p941827414165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1867337281165623"><a name="p1867337281165623"></a><a name="p1867337281165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1380272211165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931244063165623"><a name="p931244063165623"></a><a name="p931244063165623"></a><a href="rtctime.md">RtcTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657005899165623"><a name="p1657005899165623"></a><a name="p1657005899165623"></a>Defines the RTC information. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table568933711165623"></a>
<table><thead align="left"><tr id="row789194022165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p745976579165623"><a name="p745976579165623"></a><a name="p745976579165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1268180874165623"><a name="p1268180874165623"></a><a name="p1268180874165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1164232056165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725355956165623"><a name="p1725355956165623"></a><a name="p1725355956165623"></a><a href="rtc.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a>) (enum <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830785880165623"><a name="p1830785880165623"></a><a name="p1830785880165623"></a>typedef int32_t(* </p>
<p id="p232689678165623"><a name="p232689678165623"></a><a name="p232689678165623"></a>Defines a callback that will be invoked when an alarm is generated at the specified time. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1839146482165623"></a>
<table><thead align="left"><tr id="row497250337165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p572722870165623"><a name="p572722870165623"></a><a name="p572722870165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1125178140165623"><a name="p1125178140165623"></a><a name="p1125178140165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1574409609165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6640370165623"><a name="p6640370165623"></a><a name="p6640370165623"></a><a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> { <a href="rtc.md#ggad7b3a575c848e2669db5e5b6f7e74330a4a768788d6e3932637aed682317a7c6b">RTC_ALARM_INDEX_A</a> = 0, <a href="rtc.md#ggad7b3a575c848e2669db5e5b6f7e74330a15a8e9ba8ffd5b1ebf1f8353ca581352">RTC_ALARM_INDEX_B</a> = 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618447960165623"><a name="p1618447960165623"></a><a name="p1618447960165623"></a>Enumerates alarm indexes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1987287144165623"></a>
<table><thead align="left"><tr id="row1142045917165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p133568589165623"><a name="p133568589165623"></a><a name="p133568589165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p791930282165623"><a name="p791930282165623"></a><a name="p791930282165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1153382687165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772075848165623"><a name="p1772075848165623"></a><a name="p1772075848165623"></a><a href="rtc.md#ga35004a866f23081ce2a446f1b0f88e32">RtcOpen</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1971350446165623"><a name="p1971350446165623"></a><a name="p1971350446165623"></a><a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p970270196165623"><a name="p970270196165623"></a><a name="p970270196165623"></a>Opens the RTC device to obtain its handle. </p>
</td>
</tr>
<tr id="row1763748533165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1104769890165623"><a name="p1104769890165623"></a><a name="p1104769890165623"></a><a href="rtc.md#ga395aa79ef260bfcd603ed56f9839d73b">RtcClose</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076397964165623"><a name="p2076397964165623"></a><a name="p2076397964165623"></a>void </p>
<p id="p1579684755165623"><a name="p1579684755165623"></a><a name="p1579684755165623"></a>Releases a specified handle of the RTC device. </p>
</td>
</tr>
<tr id="row1835620604165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2117642633165623"><a name="p2117642633165623"></a><a name="p2117642633165623"></a><a href="rtc.md#gae8b242769eacd00b71eb1debce9be4de">RtcReadTime</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="rtctime.md">RtcTime</a> *<a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830098561165623"><a name="p1830098561165623"></a><a name="p1830098561165623"></a>int32_t </p>
<p id="p286918814165623"><a name="p286918814165623"></a><a name="p286918814165623"></a>Reads time from the RTC driver. </p>
</td>
</tr>
<tr id="row1028908492165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655513628165623"><a name="p1655513628165623"></a><a name="p1655513628165623"></a><a href="rtc.md#ga7b6da87bfe9af2bcbfeebe9793876eb8">RtcWriteTime</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, const struct <a href="rtctime.md">RtcTime</a> *<a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428122832165623"><a name="p1428122832165623"></a><a name="p1428122832165623"></a>int32_t </p>
<p id="p906667708165623"><a name="p906667708165623"></a><a name="p906667708165623"></a>Writes format-compliant time to the RTC driver. </p>
</td>
</tr>
<tr id="row1210209121165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532931305165623"><a name="p1532931305165623"></a><a name="p1532931305165623"></a><a href="rtc.md#gabc4a137f0aed13e41da2db2dccc32b08">RtcReadAlarm</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, struct <a href="rtctime.md">RtcTime</a> *<a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p422758783165623"><a name="p422758783165623"></a><a name="p422758783165623"></a>int32_t </p>
<p id="p1974908701165623"><a name="p1974908701165623"></a><a name="p1974908701165623"></a>Reads the RTC alarm time that was set last time. </p>
</td>
</tr>
<tr id="row1231926966165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p584895522165623"><a name="p584895522165623"></a><a name="p584895522165623"></a><a href="rtc.md#gaf4dd53c3e5b6c7a1766f6b15a77c96e9">RtcWriteAlarm</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, const struct <a href="rtctime.md">RtcTime</a> *<a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983306512165623"><a name="p983306512165623"></a><a name="p983306512165623"></a>int32_t </p>
<p id="p1733817565165623"><a name="p1733817565165623"></a><a name="p1733817565165623"></a>Writes the RTC alarm time based on the alarm index. </p>
</td>
</tr>
<tr id="row326420216165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1161832165165623"><a name="p1161832165165623"></a><a name="p1161832165165623"></a><a href="rtc.md#ga0c42d787adde8d56a82b0c21624049d5">RtcRegisterAlarmCallback</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, <a href="rtc.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a> cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64712861165623"><a name="p64712861165623"></a><a name="p64712861165623"></a>int32_t </p>
<p id="p362964069165623"><a name="p362964069165623"></a><a name="p362964069165623"></a>Registers <a href="rtc.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a> that will be invoked when an alarm is generated at the specified time. </p>
</td>
</tr>
<tr id="row1040457254165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622023988165623"><a name="p1622023988165623"></a><a name="p1622023988165623"></a><a href="rtc.md#ga8b0f2951646ebd17313d905553bd8e0e">RtcAlarmInterruptEnable</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, uint8_t enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236145395165623"><a name="p1236145395165623"></a><a name="p1236145395165623"></a>int32_t </p>
<p id="p346656430165623"><a name="p346656430165623"></a><a name="p346656430165623"></a>Enables or disables alarm interrupts. </p>
</td>
</tr>
<tr id="row1925969605165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17537217165623"><a name="p17537217165623"></a><a name="p17537217165623"></a><a href="rtc.md#ga766e2df8045177cd030e1133df4cba12">RtcGetFreq</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t *freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p849104665165623"><a name="p849104665165623"></a><a name="p849104665165623"></a>int32_t </p>
<p id="p1791694194165623"><a name="p1791694194165623"></a><a name="p1791694194165623"></a>Reads the RTC external frequency. </p>
</td>
</tr>
<tr id="row762084757165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755606977165623"><a name="p1755606977165623"></a><a name="p1755606977165623"></a><a href="rtc.md#ga17fdfb7ba3c876974cf9099aab092345">RtcSetFreq</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153618139165623"><a name="p1153618139165623"></a><a name="p1153618139165623"></a>int32_t </p>
<p id="p1583876276165623"><a name="p1583876276165623"></a><a name="p1583876276165623"></a>Sets the frequency of the external crystal oscillator connected to the RTC driver. </p>
</td>
</tr>
<tr id="row2044505511165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396875395165623"><a name="p1396875395165623"></a><a name="p1396875395165623"></a><a href="rtc.md#ga7eb8a5ecf1058b9f90a133e2caa14573">RtcReset</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96266623165623"><a name="p96266623165623"></a><a name="p96266623165623"></a>int32_t </p>
<p id="p437895476165623"><a name="p437895476165623"></a><a name="p437895476165623"></a>Resets the RTC driver. </p>
</td>
</tr>
<tr id="row135001762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p372070518165623"><a name="p372070518165623"></a><a name="p372070518165623"></a><a href="rtc.md#gaec39316c639860a032f802628276d366">RtcReadReg</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t usrDefIndex, uint8_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1576497132165623"><a name="p1576497132165623"></a><a name="p1576497132165623"></a>int32_t </p>
<p id="p1540192612165623"><a name="p1540192612165623"></a><a name="p1540192612165623"></a>Reads the configuration of a custom RTC register based on the register index. </p>
</td>
</tr>
<tr id="row1262262940165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552803729165623"><a name="p552803729165623"></a><a name="p552803729165623"></a><a href="rtc.md#gab8cc20f50b103acef06aa7887610be1c">RtcWriteReg</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t usrDefIndex, uint8_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p660967104165623"><a name="p660967104165623"></a><a name="p660967104165623"></a>int32_t </p>
<p id="p1203500521165623"><a name="p1203500521165623"></a><a name="p1203500521165623"></a>Writes the configuration of a custom RTC register based on the register index. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1063913536165623"></a>

## **Typedef **<a name="section1614801129165623"></a>

## RtcAlarmCallback<a name="gaf9932b7e647bce0503f1314bbe5eef8d"></a>

```
typedef int32_t(* RtcAlarmCallback) (enum [RtcAlarmIndex](rtc.md#gad7b3a575c848e2669db5e5b6f7e74330))
```

 **Description:**

Defines a callback that will be invoked when an alarm is generated at the specified time. 

## **Enumeration Type **<a name="section1322628777165623"></a>

## RtcAlarmIndex<a name="gad7b3a575c848e2669db5e5b6f7e74330"></a>

```
enum [RtcAlarmIndex](rtc.md#gad7b3a575c848e2669db5e5b6f7e74330)
```

 **Description:**

Enumerates alarm indexes. 

The alarm indexes will be used when you perform operations related to alarms.

<a name="table572178946165623"></a>
<table><thead align="left"><tr id="row1569507459165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1273952966165623"><a name="p1273952966165623"></a><a name="p1273952966165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p436054423165623"><a name="p436054423165623"></a><a name="p436054423165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row110248306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad7b3a575c848e2669db5e5b6f7e74330a4a768788d6e3932637aed682317a7c6b"><a name="ggad7b3a575c848e2669db5e5b6f7e74330a4a768788d6e3932637aed682317a7c6b"></a><a name="ggad7b3a575c848e2669db5e5b6f7e74330a4a768788d6e3932637aed682317a7c6b"></a></strong>RTC_ALARM_INDEX_A </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2045148054165623"><a name="p2045148054165623"></a><a name="p2045148054165623"></a>Index of alarm A </p>
 </td>
</tr>
<tr id="row1058102924165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggad7b3a575c848e2669db5e5b6f7e74330a15a8e9ba8ffd5b1ebf1f8353ca581352"><a name="ggad7b3a575c848e2669db5e5b6f7e74330a15a8e9ba8ffd5b1ebf1f8353ca581352"></a><a name="ggad7b3a575c848e2669db5e5b6f7e74330a15a8e9ba8ffd5b1ebf1f8353ca581352"></a></strong>RTC_ALARM_INDEX_B </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p548978504165623"><a name="p548978504165623"></a><a name="p548978504165623"></a>Index of alarm B </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section173008276165623"></a>

## RtcAlarmInterruptEnable\(\)<a name="ga8b0f2951646ebd17313d905553bd8e0e"></a>

```
int32_t RtcAlarmInterruptEnable ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, enum [RtcAlarmIndex](rtc.md#gad7b3a575c848e2669db5e5b6f7e74330) alarmIndex, uint8_t enable )
```

 **Description:**

Enables or disables alarm interrupts. 

Before performing alarm operations, you need to call this function to enable alarm interrupts, so that the  [RtcRegisterAlarmCallback](rtc.md#ga0c42d787adde8d56a82b0c21624049d5)  will be called when the alarm is not generated upon a timeout.

**Parameters:**

<a name="table435187390165623"></a>
<table><thead align="left"><tr id="row493455537165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p323234331165623"><a name="p323234331165623"></a><a name="p323234331165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p140741809165623"><a name="p140741809165623"></a><a name="p140741809165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row41724253165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b1496300104165623"><a name="b1496300104165623"></a><a name="b1496300104165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row905506449165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alarmIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the RTC alarm index. For details, see <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a>. </td>
</tr>
<tr id="row1426905571165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">enable</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether to enable RTC alarm interrupts. The value <strong id="b2144735423165623"><a name="b2144735423165623"></a><a name="b2144735423165623"></a>1</strong> means to enable alarm interrupts and value <strong id="b1110317906165623"><a name="b1110317906165623"></a><a name="b1110317906165623"></a>0</strong> means to disable alarm interrupts.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcClose\(\)<a name="ga395aa79ef260bfcd603ed56f9839d73b"></a>

```
void RtcClose ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Releases a specified handle of the RTC device. 

**Parameters:**

<a name="table570058525165623"></a>
<table><thead align="left"><tr id="row379918104165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p644815053165623"><a name="p644815053165623"></a><a name="p644815053165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1407343045165623"><a name="p1407343045165623"></a><a name="p1407343045165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row769508509165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle to release, which is created via <strong id="b952330451165623"><a name="b952330451165623"></a><a name="b952330451165623"></a>RtcGetHandle</strong>.</td>
</tr>
</tbody>
</table>

## RtcGetFreq\(\)<a name="ga766e2df8045177cd030e1133df4cba12"></a>

```
int32_t RtcGetFreq ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t * freq )
```

 **Description:**

Reads the RTC external frequency. 

This function reads the frequency of the external crystal oscillator connected to the RTC driver.

**Parameters:**

<a name="table1249918021165623"></a>
<table><thead align="left"><tr id="row1352646327165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1714362373165623"><a name="p1714362373165623"></a><a name="p1714362373165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p875419695165623"><a name="p875419695165623"></a><a name="p875419695165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1019766062165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b236824185165623"><a name="b236824185165623"></a><a name="b236824185165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row243034752165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">freq</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the frequency of the external crystal oscillator, in Hz.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcOpen\(\)<a name="ga35004a866f23081ce2a446f1b0f88e32"></a>

```
[DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) RtcOpen (void )
```

 **Description:**

Opens the RTC device to obtain its handle. 

The OS supports only one RTC device.

**Returns:**

Returns  [DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041)  if the operation is successful; returns  **NULL**  if the operation fails. 

## RtcReadAlarm\(\)<a name="gabc4a137f0aed13e41da2db2dccc32b08"></a>

```
int32_t RtcReadAlarm ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, enum [RtcAlarmIndex](rtc.md#gad7b3a575c848e2669db5e5b6f7e74330) alarmIndex, struct [RtcTime](rtctime.md) * time )
```

 **Description:**

Reads the RTC alarm time that was set last time. 

**Parameters:**

<a name="table2017015443165623"></a>
<table><thead align="left"><tr id="row565100307165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p182726196165623"><a name="p182726196165623"></a><a name="p182726196165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1606150799165623"><a name="p1606150799165623"></a><a name="p1606150799165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row859089252165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b1001264631165623"><a name="b1001264631165623"></a><a name="b1001264631165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row354932673165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alarmIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the RTC alarm index. For details, see <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a>. </td>
</tr>
<tr id="row1700778259165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC alarm time information. For details, see <a href="rtctime.md">RtcTime</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcReadReg\(\)<a name="gaec39316c639860a032f802628276d366"></a>

```
int32_t RtcReadReg ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t usrDefIndex, uint8_t * value )
```

 **Description:**

Reads the configuration of a custom RTC register based on the register index. 

One index corresponds to one byte of the configuration value.

**Parameters:**

<a name="table976552511165623"></a>
<table><thead align="left"><tr id="row318015889165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p704960702165623"><a name="p704960702165623"></a><a name="p704960702165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p464830013165623"><a name="p464830013165623"></a><a name="p464830013165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1422971248165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b1636195880165623"><a name="b1636195880165623"></a><a name="b1636195880165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row19257765165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">usrDefIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of the custom register. </td>
</tr>
<tr id="row1169451841165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the configuration value of the specified register index.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcReadTime\(\)<a name="gae8b242769eacd00b71eb1debce9be4de"></a>

```
int32_t RtcReadTime ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, struct [RtcTime](rtctime.md) * time )
```

 **Description:**

Reads time from the RTC driver. 

The time information includes the year, month, day, day of the week, hour, minute, second, and millisecond.

**Parameters:**

<a name="table331956472165623"></a>
<table><thead align="left"><tr id="row1243296127165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p381800623165623"><a name="p381800623165623"></a><a name="p381800623165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1771047860165623"><a name="p1771047860165623"></a><a name="p1771047860165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2018499715165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b1898004995165623"><a name="b1898004995165623"></a><a name="b1898004995165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row889388569165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the time information read from the RTC driver. For details, see <a href="rtctime.md">RtcTime</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcRegisterAlarmCallback\(\)<a name="ga0c42d787adde8d56a82b0c21624049d5"></a>

```
int32_t RtcRegisterAlarmCallback ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, enum [RtcAlarmIndex](rtc.md#gad7b3a575c848e2669db5e5b6f7e74330) alarmIndex, [RtcAlarmCallback](rtc.md#gaf9932b7e647bce0503f1314bbe5eef8d) cb )
```

 **Description:**

Registers  [RtcAlarmCallback](rtc.md#gaf9932b7e647bce0503f1314bbe5eef8d)  that will be invoked when an alarm is generated at the specified time. 

**Parameters:**

<a name="table1228163297165623"></a>
<table><thead align="left"><tr id="row1760455861165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p899778512165623"><a name="p899778512165623"></a><a name="p899778512165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p432298711165623"><a name="p432298711165623"></a><a name="p432298711165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row969470638165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b1300545211165623"><a name="b1300545211165623"></a><a name="b1300545211165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row2115411806165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alarmIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the RTC alarm index. For details, see <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a>. </td>
</tr>
<tr id="row1688128585165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cb</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback to register. For details, see <a href="rtc.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcReset\(\)<a name="ga7eb8a5ecf1058b9f90a133e2caa14573"></a>

```
int32_t RtcReset ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Resets the RTC driver. 

After the reset, the configuration registers are restored to the default values.

**Parameters:**

<a name="table488118312165623"></a>
<table><thead align="left"><tr id="row1999932336165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1389850158165623"><a name="p1389850158165623"></a><a name="p1389850158165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p679100673165623"><a name="p679100673165623"></a><a name="p679100673165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1103377339165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b590429706165623"><a name="b590429706165623"></a><a name="b590429706165623"></a>RtcGetHandle</strong>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcSetFreq\(\)<a name="ga17fdfb7ba3c876974cf9099aab092345"></a>

```
int32_t RtcSetFreq ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t freq )
```

 **Description:**

Sets the frequency of the external crystal oscillator connected to the RTC driver. 

Note that the frequency must be configured in accordance with the requirements specified in the product manual of the in-use component.

**Parameters:**

<a name="table413379912165623"></a>
<table><thead align="left"><tr id="row37092378165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p185519290165623"><a name="p185519290165623"></a><a name="p185519290165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1275254587165623"><a name="p1275254587165623"></a><a name="p1275254587165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1528386661165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b1695642743165623"><a name="b1695642743165623"></a><a name="b1695642743165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row1021535954165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">freq</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the frequency to set for the external crystal oscillator, in Hz.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcWriteAlarm\(\)<a name="gaf4dd53c3e5b6c7a1766f6b15a77c96e9"></a>

```
int32_t RtcWriteAlarm ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, enum [RtcAlarmIndex](rtc.md#gad7b3a575c848e2669db5e5b6f7e74330) alarmIndex, const struct [RtcTime](rtctime.md) * time )
```

 **Description:**

Writes the RTC alarm time based on the alarm index. 

Note that the RTC start time is 1970/01/01 Thursday 00:00:00 \(UTC\). Set the maximum value of  **year**  based on the requirements specified in the product manual of the in-use component.

**Parameters:**

<a name="table641593273165623"></a>
<table><thead align="left"><tr id="row1330273047165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1297849157165623"><a name="p1297849157165623"></a><a name="p1297849157165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1695099436165623"><a name="p1695099436165623"></a><a name="p1695099436165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row307815348165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b143532466165623"><a name="b143532466165623"></a><a name="b143532466165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row185810314165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alarmIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the RTC alarm index. For details, see <a href="rtc.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a>. </td>
</tr>
<tr id="row1564427852165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tm</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC alarm time information. For details, see <a href="rtctime.md">RtcTime</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcWriteReg\(\)<a name="gab8cc20f50b103acef06aa7887610be1c"></a>

```
int32_t RtcWriteReg ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint8_t usrDefIndex, uint8_t value )
```

 **Description:**

Writes the configuration of a custom RTC register based on the register index. 

One index corresponds to one byte of the configuration value.

**Parameters:**

<a name="table453707851165623"></a>
<table><thead align="left"><tr id="row1677010335165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1199399409165623"><a name="p1199399409165623"></a><a name="p1199399409165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p285445909165623"><a name="p285445909165623"></a><a name="p285445909165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1875519441165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b239068854165623"><a name="b239068854165623"></a><a name="b239068854165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row2058273234165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">usrDefIndex</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the index of the custom register. </td>
</tr>
<tr id="row287143180165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">value</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the configuration value to write at the index of the register.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

## RtcWriteTime\(\)<a name="ga7b6da87bfe9af2bcbfeebe9793876eb8"></a>

```
int32_t RtcWriteTime ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, const struct [RtcTime](rtctime.md) * time )
```

 **Description:**

Writes format-compliant time to the RTC driver. 

Note that the RTC start time is 1970/01/01 Thursday 00:00:00 \(UTC\). Set the maximum value of  **year**  based on the requirements specified in the product manual of the in-use component.

**Parameters:**

<a name="table1240516278165623"></a>
<table><thead align="left"><tr id="row61782621165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p413605318165623"><a name="p413605318165623"></a><a name="p413605318165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1153310295165623"><a name="p1153310295165623"></a><a name="p1153310295165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1129188031165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the RTC device handle, which is obtained via <strong id="b576900403165623"><a name="b576900403165623"></a><a name="b576900403165623"></a>RtcGetHandle</strong>. </td>
</tr>
<tr id="row109866393165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">time</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the time information to write. For details, see <a href="rtctime.md">RtcTime</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value if the operation fails. For details, see  [HDF\_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67). 

