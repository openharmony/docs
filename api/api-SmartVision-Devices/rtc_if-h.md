# rtc\_if.h<a name="ZH-CN_TOPIC_0000001054879510"></a>

-   [Overview](#section468934416165628)
-   [Summary](#section1696974119165628)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section468934416165628"></a>

**Related Modules:**

[RTC](RTC.md)

**Description:**

Declares the standard RTC APIs. 

**Since:**

1.0

## **Summary**<a name="section1696974119165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1849554983165628"></a>
<table><thead align="left"><tr id="row582453969165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1323462242165628"><a name="p1323462242165628"></a><a name="p1323462242165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1562697575165628"><a name="p1562697575165628"></a><a name="p1562697575165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1632588695165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528598911165628"><a name="p1528598911165628"></a><a name="p1528598911165628"></a><a href="RtcTime.md">RtcTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2008209392165628"><a name="p2008209392165628"></a><a name="p2008209392165628"></a>Defines the RTC information. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1291703513165628"></a>
<table><thead align="left"><tr id="row1669433736165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p617130780165628"><a name="p617130780165628"></a><a name="p617130780165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1201457678165628"><a name="p1201457678165628"></a><a name="p1201457678165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1503579854165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916276660165628"><a name="p916276660165628"></a><a name="p916276660165628"></a><a href="RTC.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a>) (enum <a href="RTC.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1831570425165628"><a name="p1831570425165628"></a><a name="p1831570425165628"></a>typedef int32_t(* </p>
<p id="p1918385724165628"><a name="p1918385724165628"></a><a name="p1918385724165628"></a>Defines a callback that will be invoked when an alarm is generated at the specified time. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table223125523165628"></a>
<table><thead align="left"><tr id="row2118741624165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p309009063165628"><a name="p309009063165628"></a><a name="p309009063165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p668971372165628"><a name="p668971372165628"></a><a name="p668971372165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row605138542165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246292521165628"><a name="p1246292521165628"></a><a name="p1246292521165628"></a><a href="RTC.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> { <a href="RTC.md#ggad7b3a575c848e2669db5e5b6f7e74330a4a768788d6e3932637aed682317a7c6b">RTC_ALARM_INDEX_A</a> = 0, <a href="RTC.md#ggad7b3a575c848e2669db5e5b6f7e74330a15a8e9ba8ffd5b1ebf1f8353ca581352">RTC_ALARM_INDEX_B</a> = 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p841981954165628"><a name="p841981954165628"></a><a name="p841981954165628"></a>Enumerates alarm indexes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table870141412165628"></a>
<table><thead align="left"><tr id="row1254117620165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p639577661165628"><a name="p639577661165628"></a><a name="p639577661165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p576878831165628"><a name="p576878831165628"></a><a name="p576878831165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1224719544165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p444201513165628"><a name="p444201513165628"></a><a name="p444201513165628"></a><a href="RTC.md#ga35004a866f23081ce2a446f1b0f88e32">RtcOpen</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1461803985165628"><a name="p1461803985165628"></a><a name="p1461803985165628"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p584966216165628"><a name="p584966216165628"></a><a name="p584966216165628"></a>Opens the RTC device to obtain its handle. </p>
</td>
</tr>
<tr id="row212141985165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1079304635165628"><a name="p1079304635165628"></a><a name="p1079304635165628"></a><a href="RTC.md#ga395aa79ef260bfcd603ed56f9839d73b">RtcClose</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1914577146165628"><a name="p1914577146165628"></a><a name="p1914577146165628"></a>void </p>
<p id="p1185873130165628"><a name="p1185873130165628"></a><a name="p1185873130165628"></a>Releases a specified handle of the RTC device. </p>
</td>
</tr>
<tr id="row474847692165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922964021165628"><a name="p1922964021165628"></a><a name="p1922964021165628"></a><a href="RTC.md#gae8b242769eacd00b71eb1debce9be4de">RtcReadTime</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, struct <a href="RtcTime.md">RtcTime</a> *<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386844612165628"><a name="p386844612165628"></a><a name="p386844612165628"></a>int32_t </p>
<p id="p483217988165628"><a name="p483217988165628"></a><a name="p483217988165628"></a>Reads time from the RTC driver. </p>
</td>
</tr>
<tr id="row1386204565165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768081468165628"><a name="p768081468165628"></a><a name="p768081468165628"></a><a href="RTC.md#ga7b6da87bfe9af2bcbfeebe9793876eb8">RtcWriteTime</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, const struct <a href="RtcTime.md">RtcTime</a> *<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688285323165628"><a name="p1688285323165628"></a><a name="p1688285323165628"></a>int32_t </p>
<p id="p1610409548165628"><a name="p1610409548165628"></a><a name="p1610409548165628"></a>Writes format-compliant time to the RTC driver. </p>
</td>
</tr>
<tr id="row1031182728165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752496384165628"><a name="p752496384165628"></a><a name="p752496384165628"></a><a href="RTC.md#gabc4a137f0aed13e41da2db2dccc32b08">RtcReadAlarm</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="RTC.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, struct <a href="RtcTime.md">RtcTime</a> *<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242604343165628"><a name="p1242604343165628"></a><a name="p1242604343165628"></a>int32_t </p>
<p id="p1297283495165628"><a name="p1297283495165628"></a><a name="p1297283495165628"></a>Reads the RTC alarm time that was set last time. </p>
</td>
</tr>
<tr id="row994594246165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1545775795165628"><a name="p1545775795165628"></a><a name="p1545775795165628"></a><a href="RTC.md#gaf4dd53c3e5b6c7a1766f6b15a77c96e9">RtcWriteAlarm</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="RTC.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, const struct <a href="RtcTime.md">RtcTime</a> *<a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144276789165628"><a name="p2144276789165628"></a><a name="p2144276789165628"></a>int32_t </p>
<p id="p183615453165628"><a name="p183615453165628"></a><a name="p183615453165628"></a>Writes the RTC alarm time based on the alarm index. </p>
</td>
</tr>
<tr id="row1899895955165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863178147165628"><a name="p1863178147165628"></a><a name="p1863178147165628"></a><a href="RTC.md#ga0c42d787adde8d56a82b0c21624049d5">RtcRegisterAlarmCallback</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="RTC.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, <a href="RTC.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a> cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p563868113165628"><a name="p563868113165628"></a><a name="p563868113165628"></a>int32_t </p>
<p id="p63883916165628"><a name="p63883916165628"></a><a name="p63883916165628"></a>Registers <a href="RTC.md#gaf9932b7e647bce0503f1314bbe5eef8d">RtcAlarmCallback</a> that will be invoked when an alarm is generated at the specified time. </p>
</td>
</tr>
<tr id="row1062181781165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28136432165628"><a name="p28136432165628"></a><a name="p28136432165628"></a><a href="RTC.md#ga8b0f2951646ebd17313d905553bd8e0e">RtcAlarmInterruptEnable</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, enum <a href="RTC.md#gad7b3a575c848e2669db5e5b6f7e74330">RtcAlarmIndex</a> alarmIndex, uint8_t enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1735402908165628"><a name="p1735402908165628"></a><a name="p1735402908165628"></a>int32_t </p>
<p id="p1267379849165628"><a name="p1267379849165628"></a><a name="p1267379849165628"></a>Enables or disables alarm interrupts. </p>
</td>
</tr>
<tr id="row786078973165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1593002361165628"><a name="p1593002361165628"></a><a name="p1593002361165628"></a><a href="RTC.md#ga766e2df8045177cd030e1133df4cba12">RtcGetFreq</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t *freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393864819165628"><a name="p393864819165628"></a><a name="p393864819165628"></a>int32_t </p>
<p id="p1801682692165628"><a name="p1801682692165628"></a><a name="p1801682692165628"></a>Reads the RTC external frequency. </p>
</td>
</tr>
<tr id="row788805953165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858330543165628"><a name="p1858330543165628"></a><a name="p1858330543165628"></a><a href="RTC.md#ga17fdfb7ba3c876974cf9099aab092345">RtcSetFreq</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t freq)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p81168186165628"><a name="p81168186165628"></a><a name="p81168186165628"></a>int32_t </p>
<p id="p1397366831165628"><a name="p1397366831165628"></a><a name="p1397366831165628"></a>Sets the frequency of the external crystal oscillator connected to the RTC driver. </p>
</td>
</tr>
<tr id="row2013748044165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684164352165628"><a name="p1684164352165628"></a><a name="p1684164352165628"></a><a href="RTC.md#ga7eb8a5ecf1058b9f90a133e2caa14573">RtcReset</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1245205862165628"><a name="p1245205862165628"></a><a name="p1245205862165628"></a>int32_t </p>
<p id="p723630232165628"><a name="p723630232165628"></a><a name="p723630232165628"></a>Resets the RTC driver. </p>
</td>
</tr>
<tr id="row1397834172165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155474284165628"><a name="p155474284165628"></a><a name="p155474284165628"></a><a href="RTC.md#gaec39316c639860a032f802628276d366">RtcReadReg</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t usrDefIndex, uint8_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470885596165628"><a name="p470885596165628"></a><a name="p470885596165628"></a>int32_t </p>
<p id="p735098641165628"><a name="p735098641165628"></a><a name="p735098641165628"></a>Reads the configuration of a custom RTC register based on the register index. </p>
</td>
</tr>
<tr id="row1602441609165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p184531926165628"><a name="p184531926165628"></a><a name="p184531926165628"></a><a href="RTC.md#gab8cc20f50b103acef06aa7887610be1c">RtcWriteReg</a> (<a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint8_t usrDefIndex, uint8_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1195983641165628"><a name="p1195983641165628"></a><a name="p1195983641165628"></a>int32_t </p>
<p id="p611699457165628"><a name="p611699457165628"></a><a name="p611699457165628"></a>Writes the configuration of a custom RTC register based on the register index. </p>
</td>
</tr>
</tbody>
</table>

