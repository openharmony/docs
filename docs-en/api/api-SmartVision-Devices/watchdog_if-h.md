# watchdog\_if.h<a name="EN-US_TOPIC_0000001055683462"></a>

-   [Overview](#section621015195165630)
-   [Summary](#section1204927856165630)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section621015195165630"></a>

**Related Modules:**

[WATCHDOG](watchdog.md)

**Description:**

Declares standard watchdog APIs. 

**Since:**

1.0

## **Summary**<a name="section1204927856165630"></a>

## Enumerations<a name="enum-members"></a>

<a name="table825080865165630"></a>
<table><thead align="left"><tr id="row2091199588165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2231881165630"><a name="p2231881165630"></a><a name="p2231881165630"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1092725775165630"><a name="p1092725775165630"></a><a name="p1092725775165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row444866838165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178610170165630"><a name="p178610170165630"></a><a name="p178610170165630"></a><a href="watchdog.md#ga3c77a35e1051e3f99238029519ac1954">WatchdogStatus</a> { <a href="watchdog.md#gga3c77a35e1051e3f99238029519ac1954a2579c5f1c789b94d99988476031ec2a6">WATCHDOG_STOP</a>, <a href="watchdog.md#gga3c77a35e1051e3f99238029519ac1954aec39073df0b03eb51cc0e17380b86c68">WATCHDOG_START</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587086751165630"><a name="p587086751165630"></a><a name="p587086751165630"></a>Enumerates watchdog statuses. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table229890448165630"></a>
<table><thead align="left"><tr id="row1427995201165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p812326772165630"><a name="p812326772165630"></a><a name="p812326772165630"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1160344097165630"><a name="p1160344097165630"></a><a name="p1160344097165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row509417781165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p934776026165630"><a name="p934776026165630"></a><a name="p934776026165630"></a><a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a> (int16_t wdtId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319317254165630"><a name="p319317254165630"></a><a name="p319317254165630"></a><a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p1539604332165630"><a name="p1539604332165630"></a><a name="p1539604332165630"></a>Opens a watchdog. </p>
</td>
</tr>
<tr id="row1501355297165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p176047536165630"><a name="p176047536165630"></a><a name="p176047536165630"></a><a href="watchdog.md#ga9ba18801b59154c986aef6bb5cc92bf5">WatchdogClose</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2057880685165630"><a name="p2057880685165630"></a><a name="p2057880685165630"></a>void </p>
<p id="p1323818443165630"><a name="p1323818443165630"></a><a name="p1323818443165630"></a>Closes a watchdog. </p>
</td>
</tr>
<tr id="row455587576165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081223975165630"><a name="p1081223975165630"></a><a name="p1081223975165630"></a><a href="watchdog.md#ga2fc274833b7dd18cc61209454d1fa82b">WatchdogGetStatus</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, int32_t *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756185016165630"><a name="p1756185016165630"></a><a name="p1756185016165630"></a>int32_t </p>
<p id="p1515215565165630"><a name="p1515215565165630"></a><a name="p1515215565165630"></a>Obtains the watchdog status. </p>
</td>
</tr>
<tr id="row1627983185165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273812904165630"><a name="p1273812904165630"></a><a name="p1273812904165630"></a><a href="watchdog.md#ga6d15226fbc2fe5da184decb6370b0122">WatchdogStart</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088245960165630"><a name="p1088245960165630"></a><a name="p1088245960165630"></a>int32_t </p>
<p id="p1383540761165630"><a name="p1383540761165630"></a><a name="p1383540761165630"></a>Starts a watchdog. </p>
</td>
</tr>
<tr id="row2129379227165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p642612523165630"><a name="p642612523165630"></a><a name="p642612523165630"></a><a href="watchdog.md#gac41a51b5d663f7963c06cb1241d50239">WatchdogStop</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176490856165630"><a name="p176490856165630"></a><a name="p176490856165630"></a>int32_t </p>
<p id="p1513724784165630"><a name="p1513724784165630"></a><a name="p1513724784165630"></a>Stops a watchdog. </p>
</td>
</tr>
<tr id="row865252767165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124903609165630"><a name="p2124903609165630"></a><a name="p2124903609165630"></a><a href="watchdog.md#ga508bea0dac2cac12b0819bb7af81e628">WatchdogSetTimeout</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t seconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339565497165630"><a name="p339565497165630"></a><a name="p339565497165630"></a>int32_t </p>
<p id="p1806783831165630"><a name="p1806783831165630"></a><a name="p1806783831165630"></a>Sets the watchdog timeout duration. </p>
</td>
</tr>
<tr id="row1699053662165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560328087165630"><a name="p1560328087165630"></a><a name="p1560328087165630"></a><a href="watchdog.md#ga525602b8cacd030fb1630ea07f2a5b07">WatchdogGetTimeout</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t *seconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p595167111165630"><a name="p595167111165630"></a><a name="p595167111165630"></a>int32_t </p>
<p id="p1314559535165630"><a name="p1314559535165630"></a><a name="p1314559535165630"></a>Obtains the watchdog timeout duration. </p>
</td>
</tr>
<tr id="row67496957165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p221364271165630"><a name="p221364271165630"></a><a name="p221364271165630"></a><a href="watchdog.md#ga32e7d3939e8682e52502d9112ad6732a">WatchdogFeed</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428778222165630"><a name="p428778222165630"></a><a name="p428778222165630"></a>int32_t </p>
<p id="p372344503165630"><a name="p372344503165630"></a><a name="p372344503165630"></a>Feeds a watchdog, that is, resets a watchdog timer. </p>
</td>
</tr>
</tbody>
</table>

