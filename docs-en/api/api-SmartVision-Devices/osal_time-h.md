# osal\_time.h<a name="EN-US_TOPIC_0000001055358084"></a>

-   [Overview](#section1499329245165628)
-   [Summary](#section148107057165628)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1499329245165628"></a>

**Related Modules:**

[OSAL](osal.md)

**Description:**

Declares the time, sleep, and delay interfaces. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section148107057165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table2057580817165628"></a>
<table><thead align="left"><tr id="row1851202266165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p508512508165628"><a name="p508512508165628"></a><a name="p508512508165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1239168243165628"><a name="p1239168243165628"></a><a name="p1239168243165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1102947520165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1075562340165628"><a name="p1075562340165628"></a><a name="p1075562340165628"></a><a href="osaltimespec.md">OsalTimespec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36782555165628"><a name="p36782555165628"></a><a name="p36782555165628"></a>Defines time. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1710275157165628"></a>
<table><thead align="left"><tr id="row806176299165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p871837117165628"><a name="p871837117165628"></a><a name="p871837117165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1154960454165628"><a name="p1154960454165628"></a><a name="p1154960454165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row624134476165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764739104165628"><a name="p764739104165628"></a><a name="p764739104165628"></a><a href="osal.md#ga8b9ca3498c54b11dcbe88a2a456f23ab">OsalSleep</a> (uint32_t sec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624935922165628"><a name="p624935922165628"></a><a name="p624935922165628"></a>void </p>
<p id="p70065126165628"><a name="p70065126165628"></a><a name="p70065126165628"></a>Describes thread sleep, in seconds. </p>
</td>
</tr>
<tr id="row656213322165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p565188832165628"><a name="p565188832165628"></a><a name="p565188832165628"></a><a href="osal.md#ga2361dc099952df28aaef8968f9f4b9a7">OsalMSleep</a> (uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1107408722165628"><a name="p1107408722165628"></a><a name="p1107408722165628"></a>void </p>
<p id="p1985288077165628"><a name="p1985288077165628"></a><a name="p1985288077165628"></a>Describes thread sleep, in milliseconds. </p>
</td>
</tr>
<tr id="row1794288792165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p959679263165628"><a name="p959679263165628"></a><a name="p959679263165628"></a><a href="osal.md#ga649d3090dcf9ba0e22649e11ac40831f">OsalGetTime</a> (<a href="osaltimespec.md">OsalTimespec</a> *<a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1550240841165628"><a name="p1550240841165628"></a><a name="p1550240841165628"></a>int32_t </p>
<p id="p335669182165628"><a name="p335669182165628"></a><a name="p335669182165628"></a>Obtains the second and microsecond time. </p>
</td>
</tr>
<tr id="row1991264488165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1653678327165628"><a name="p1653678327165628"></a><a name="p1653678327165628"></a><a href="osal.md#ga36b0af6646f887175993e78391a5cabc">OsalDiffTime</a> (const <a href="osaltimespec.md">OsalTimespec</a> *start, const <a href="osaltimespec.md">OsalTimespec</a> *end, <a href="osaltimespec.md">OsalTimespec</a> *diff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408369767165628"><a name="p1408369767165628"></a><a name="p1408369767165628"></a>int32_t </p>
<p id="p1818627836165628"><a name="p1818627836165628"></a><a name="p1818627836165628"></a>Obtains time difference. </p>
</td>
</tr>
<tr id="row31642675165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201737023165628"><a name="p201737023165628"></a><a name="p201737023165628"></a><a href="osal.md#gaf91cb1945b66e324fbb0761aa2f98ea3">OsalGetSysTimeMs</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174175245165628"><a name="p1174175245165628"></a><a name="p1174175245165628"></a>uint64_t </p>
<p id="p1996504223165628"><a name="p1996504223165628"></a><a name="p1996504223165628"></a>Obtains the system time. </p>
</td>
</tr>
<tr id="row1226871352165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p695814930165628"><a name="p695814930165628"></a><a name="p695814930165628"></a><a href="osal.md#ga82ddd682a2441a22dd6148f634a6cea4">OsalMDelay</a> (uint32_t ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p487521087165628"><a name="p487521087165628"></a><a name="p487521087165628"></a>void </p>
<p id="p1285136729165628"><a name="p1285136729165628"></a><a name="p1285136729165628"></a>Describes thread delay, in milliseconds. </p>
</td>
</tr>
<tr id="row208387962165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891134532165628"><a name="p1891134532165628"></a><a name="p1891134532165628"></a><a href="osal.md#ga7ae78fa3318a82dbd769827d4f373958">OsalUDelay</a> (uint32_t us)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2063999046165628"><a name="p2063999046165628"></a><a name="p2063999046165628"></a>void </p>
<p id="p834137429165628"><a name="p834137429165628"></a><a name="p834137429165628"></a>Describes thread delay, in microseconds. </p>
</td>
</tr>
</tbody>
</table>

