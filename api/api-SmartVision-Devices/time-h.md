# time.h<a name="ZH-CN_TOPIC_0000001055189451"></a>

-   [Overview](#section7017532165629)
-   [Summary](#section1775605915165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section7017532165629"></a>

**Related Modules:**

[TIME](TIME.md)

**Description:**

Provides time-related structures and functions. 

You can perform time-related management operations, including obtaining and setting broken-down time and system ticks, and manipulating timers.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1775605915165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1028035493165629"></a>
<table><thead align="left"><tr id="row2102267951165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1476004678165629"><a name="p1476004678165629"></a><a name="p1476004678165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p260941273165629"><a name="p260941273165629"></a><a name="p260941273165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row282543477165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p731856987165629"><a name="p731856987165629"></a><a name="p731856987165629"></a><a href="tm.md">tm</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474274823165629"><a name="p474274823165629"></a><a name="p474274823165629"></a>Describes date and time information. </p>
</td>
</tr>
<tr id="row111523539165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p926647389165629"><a name="p926647389165629"></a><a name="p926647389165629"></a><a href="itimerspec.md">itimerspec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p971011232165629"><a name="p971011232165629"></a><a name="p971011232165629"></a>Sets a timer. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1425660247165629"></a>
<table><thead align="left"><tr id="row979014210165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1852644528165629"><a name="p1852644528165629"></a><a name="p1852644528165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p423297994165629"><a name="p423297994165629"></a><a name="p423297994165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1136735202165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p897700506165629"><a name="p897700506165629"></a><a name="p897700506165629"></a><a href="TIME.md#ga922ce1ae64374c9410c8a999e25e82af">CLOCK_REALTIME</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p235488063165629"><a name="p235488063165629"></a><a name="p235488063165629"></a>Defines a real-time clock. </p>
</td>
</tr>
<tr id="row178048234165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1125741856165629"><a name="p1125741856165629"></a><a name="p1125741856165629"></a><a href="TIME.md#ga6fb83f5e91e704391ff796553d5e0f46">CLOCK_MONOTONIC</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441151734165629"><a name="p1441151734165629"></a><a name="p1441151734165629"></a>Defines a monotonic clock. </p>
</td>
</tr>
<tr id="row202597127165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691391721165629"><a name="p691391721165629"></a><a name="p691391721165629"></a><a href="TIME.md#gabc28c2ee4e33ae055ef2f737110a7020">CLOCK_MONOTONIC_RAW</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p89520009165629"><a name="p89520009165629"></a><a name="p89520009165629"></a>Defines a raw hardware-based monotonic clock. </p>
</td>
</tr>
<tr id="row851267661165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117667068165629"><a name="p117667068165629"></a><a name="p117667068165629"></a><a href="TIME.md#gaccb072221e0afcac765ec2bb6e4eca04">CLOCK_REALTIME_COARSE</a>   5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p827094481165629"><a name="p827094481165629"></a><a name="p827094481165629"></a>Defines a low-precision real-time clock. </p>
</td>
</tr>
<tr id="row603956288165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340947807165629"><a name="p1340947807165629"></a><a name="p1340947807165629"></a><a href="TIME.md#gaec7304645b1e13a52fa6dfb11f1c671b">CLOCK_MONOTONIC_COARSE</a>   6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1649448882165629"><a name="p1649448882165629"></a><a name="p1649448882165629"></a>Defines a low-precision monotonic clock. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table109450030165629"></a>
<table><thead align="left"><tr id="row1727943046165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p767642272165629"><a name="p767642272165629"></a><a name="p767642272165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1760362220165629"><a name="p1760362220165629"></a><a name="p1760362220165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1800679212165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388439890165629"><a name="p1388439890165629"></a><a name="p1388439890165629"></a><a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a> (<a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p140001002165629"><a name="p140001002165629"></a><a name="p140001002165629"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
<p id="p1553125315165629"><a name="p1553125315165629"></a><a name="p1553125315165629"></a>Obtains the time. </p>
</td>
</tr>
<tr id="row1821735577165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328564868165629"><a name="p328564868165629"></a><a name="p328564868165629"></a><a href="TIME.md#ga1901c00eb89e8e35ea193c6a4676679c">difftime</a> (<a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> time1, <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> time2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858657917165629"><a name="p1858657917165629"></a><a name="p1858657917165629"></a>double </p>
<p id="p279266887165629"><a name="p279266887165629"></a><a name="p279266887165629"></a>Calculates the difference between two times, in seconds. </p>
</td>
</tr>
<tr id="row1883009742165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p219717153165629"><a name="p219717153165629"></a><a name="p219717153165629"></a><a href="TIME.md#gafc0e3f373a3ea00b37714f1b621ae0b1">mktime</a> (struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p243394096165629"><a name="p243394096165629"></a><a name="p243394096165629"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
<p id="p899636401165629"><a name="p899636401165629"></a><a name="p899636401165629"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure into seconds. </p>
</td>
</tr>
<tr id="row433361101165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871966209165629"><a name="p871966209165629"></a><a name="p871966209165629"></a><a href="TIME.md#gab94643a711fc91727b668553d4a8806b">strftime</a> (char *restrict s, size_t n, const char *restrict f, const struct <a href="tm.md">tm</a> *restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748433606165629"><a name="p748433606165629"></a><a name="p748433606165629"></a>size_t </p>
<p id="p350616882165629"><a name="p350616882165629"></a><a name="p350616882165629"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure to a string in the required format. </p>
</td>
</tr>
<tr id="row1033997119165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782870314165629"><a name="p782870314165629"></a><a name="p782870314165629"></a><a href="TIME.md#ga30d9732f32117a94652e28512905bfb9">gmtime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p837564625165629"><a name="p837564625165629"></a><a name="p837564625165629"></a>struct <a href="tm.md">tm</a> * </p>
<p id="p1753834657165629"><a name="p1753834657165629"></a><a name="p1753834657165629"></a>Converts the number of seconds to the UTC time in the <a href="tm.md">tm</a> structure. </p>
</td>
</tr>
<tr id="row315094483165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1174041520165629"><a name="p1174041520165629"></a><a name="p1174041520165629"></a><a href="TIME.md#ga70311f8aa60fc5ebbd76c55ea10bc899">localtime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173837466165629"><a name="p1173837466165629"></a><a name="p1173837466165629"></a>struct <a href="tm.md">tm</a> * </p>
<p id="p1445056169165629"><a name="p1445056169165629"></a><a name="p1445056169165629"></a>Converts the number of seconds to the local time in the <a href="tm.md">tm</a> structure. </p>
</td>
</tr>
<tr id="row1257122201165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387678883165629"><a name="p1387678883165629"></a><a name="p1387678883165629"></a><a href="TIME.md#ga416a0a99a5bab4c030e93d21152727f4">asctime</a> (const struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465019700165629"><a name="p465019700165629"></a><a name="p465019700165629"></a>char * </p>
<p id="p2080829668165629"><a name="p2080829668165629"></a><a name="p2080829668165629"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure into a string. </p>
</td>
</tr>
<tr id="row312570281165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1297980037165629"><a name="p1297980037165629"></a><a name="p1297980037165629"></a><a href="TIME.md#ga6e58d33339fabd469b2f4790b0f2b843">ctime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *timep)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769510930165629"><a name="p769510930165629"></a><a name="p769510930165629"></a>char * </p>
<p id="p588393911165629"><a name="p588393911165629"></a><a name="p588393911165629"></a>Converts the date and time into a string. </p>
</td>
</tr>
<tr id="row1989894494165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1216444300165629"><a name="p1216444300165629"></a><a name="p1216444300165629"></a><a href="TIME.md#ga74c011f36d0ad959f0312dec8a5c8dc8">strftime_l</a> (char *__restrict s, size_t n, const char *__restrict f, const struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>, locale_t loc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2077401759165629"><a name="p2077401759165629"></a><a name="p2077401759165629"></a>size_t </p>
<p id="p1780722360165629"><a name="p1780722360165629"></a><a name="p1780722360165629"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure to a string in a specified programming language and format. </p>
</td>
</tr>
<tr id="row1044657053165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392304903165629"><a name="p392304903165629"></a><a name="p392304903165629"></a><a href="TIME.md#ga91bb7adea9b0b36acde8dba3012c01a5">gmtime_r</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *__restrict t, struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p549234033165629"><a name="p549234033165629"></a><a name="p549234033165629"></a>struct <a href="tm.md">tm</a> * </p>
<p id="p512094107165629"><a name="p512094107165629"></a><a name="p512094107165629"></a>Converts the number of seconds to the UTC time in the <a href="tm.md">tm</a> structure. (This function is reentrant.) </p>
</td>
</tr>
<tr id="row1185603247165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p250235968165629"><a name="p250235968165629"></a><a name="p250235968165629"></a><a href="TIME.md#gad8c4ed240ddbd645502ac2f0a306aee0">localtime_r</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *__restrict t, struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1856199221165629"><a name="p1856199221165629"></a><a name="p1856199221165629"></a>struct <a href="tm.md">tm</a> * </p>
<p id="p1378580313165629"><a name="p1378580313165629"></a><a name="p1378580313165629"></a>Converts the number of seconds to the local time in the <a href="tm.md">tm</a> structure. (This function is reentrant.) </p>
</td>
</tr>
<tr id="row753498551165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p330297242165629"><a name="p330297242165629"></a><a name="p330297242165629"></a><a href="TIME.md#ga8eb1bca8a6fdc63173a83f1c8cb28e15">asctime_r</a> (const struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>, char *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1452864433165629"><a name="p1452864433165629"></a><a name="p1452864433165629"></a>char * </p>
<p id="p1687484620165629"><a name="p1687484620165629"></a><a name="p1687484620165629"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure into a string. (This function is reentrant.) </p>
</td>
</tr>
<tr id="row89974333165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p521151477165629"><a name="p521151477165629"></a><a name="p521151477165629"></a><a href="TIME.md#gae6eed522503f70a5cf05be0be558b125">ctime_r</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t, char *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630396426165629"><a name="p1630396426165629"></a><a name="p1630396426165629"></a>char * </p>
<p id="p483156790165629"><a name="p483156790165629"></a><a name="p483156790165629"></a>Converts the date and time into a string. (This function is reentrant.) </p>
</td>
</tr>
<tr id="row1489274054165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1389762473165629"><a name="p1389762473165629"></a><a name="p1389762473165629"></a><a href="TIME.md#gafbe0e411e8bf89275e7cd46d0aeedc4b">nanosleep</a> (const struct <a href="timespec.md">timespec</a> *tspec1, struct <a href="timespec.md">timespec</a> *tspec2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37175580165629"><a name="p37175580165629"></a><a name="p37175580165629"></a>int </p>
<p id="p1099032584165629"><a name="p1099032584165629"></a><a name="p1099032584165629"></a>Pauses the current thread until a specified time arrives. </p>
</td>
</tr>
<tr id="row205109183165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073400042165629"><a name="p1073400042165629"></a><a name="p1073400042165629"></a><a href="TIME.md#ga822b364014350d2d70bbd0ccaab1f476">clock_getres</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, struct <a href="timespec.md">timespec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502333473165629"><a name="p1502333473165629"></a><a name="p1502333473165629"></a>int </p>
<p id="p139986418165629"><a name="p139986418165629"></a><a name="p139986418165629"></a>Obtains the precision of a clock. </p>
</td>
</tr>
<tr id="row12083476165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440063339165629"><a name="p1440063339165629"></a><a name="p1440063339165629"></a><a href="TIME.md#ga28ec1219021575a4b9a7c502b2e9a72c">clock_gettime</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, struct <a href="timespec.md">timespec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1311801117165629"><a name="p1311801117165629"></a><a name="p1311801117165629"></a>int </p>
<p id="p510572539165629"><a name="p510572539165629"></a><a name="p510572539165629"></a>Obtains the time of a clock. </p>
</td>
</tr>
<tr id="row1696083521165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p417292769165629"><a name="p417292769165629"></a><a name="p417292769165629"></a><a href="TIME.md#ga04dbb6f7216d70a1b206741564d4d0fb">clock_settime</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, const struct <a href="timespec.md">timespec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1562158996165629"><a name="p1562158996165629"></a><a name="p1562158996165629"></a>int </p>
<p id="p497437163165629"><a name="p497437163165629"></a><a name="p497437163165629"></a>Sets the time for a clock. </p>
</td>
</tr>
<tr id="row103347078165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2089200976165629"><a name="p2089200976165629"></a><a name="p2089200976165629"></a><a href="TIME.md#ga23d3356807a1cb25b5f64651c4aa7d33">clock_nanosleep</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, int flag, const struct <a href="timespec.md">timespec</a> *tspec1, struct <a href="timespec.md">timespec</a> *tspec2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p745023938165629"><a name="p745023938165629"></a><a name="p745023938165629"></a>int </p>
<p id="p455340520165629"><a name="p455340520165629"></a><a name="p455340520165629"></a>Pauses the current thread until a specified time of a clock arrives. </p>
</td>
</tr>
<tr id="row412086320165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805634985165629"><a name="p805634985165629"></a><a name="p805634985165629"></a><a href="TIME.md#gaf7dce9c851a2e1a65aaf818b95487431">timer_create</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, struct <a href="sigevent.md">sigevent</a> *__restrict evp, <a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> *__restrict t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p153253870165629"><a name="p153253870165629"></a><a name="p153253870165629"></a>int </p>
<p id="p1569695086165629"><a name="p1569695086165629"></a><a name="p1569695086165629"></a>Creates a timer for the process. </p>
</td>
</tr>
<tr id="row1061067067165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296567326165629"><a name="p1296567326165629"></a><a name="p1296567326165629"></a><a href="TIME.md#ga61fa078bdadbd957cfcdfb12d0592ac1">timer_delete</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706659594165629"><a name="p1706659594165629"></a><a name="p1706659594165629"></a>int </p>
<p id="p338541285165629"><a name="p338541285165629"></a><a name="p338541285165629"></a>Deletes a timer for the process. </p>
</td>
</tr>
<tr id="row1992274125165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p901212883165629"><a name="p901212883165629"></a><a name="p901212883165629"></a><a href="TIME.md#gade973e87fffe05aed7f1e97c1d15178e">timer_settime</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t, int flags, const struct <a href="itimerspec.md">itimerspec</a> *__restrict val, struct <a href="itimerspec.md">itimerspec</a> *__restrict old)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738664664165629"><a name="p1738664664165629"></a><a name="p1738664664165629"></a>int </p>
<p id="p780438803165629"><a name="p780438803165629"></a><a name="p780438803165629"></a>Sets a timer for the process. </p>
</td>
</tr>
<tr id="row1475275481165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812220028165629"><a name="p812220028165629"></a><a name="p812220028165629"></a><a href="TIME.md#ga8f65c6a88588c951e0b11629e56714a4">timer_gettime</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t, struct <a href="itimerspec.md">itimerspec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426235947165629"><a name="p426235947165629"></a><a name="p426235947165629"></a>int </p>
<p id="p509826523165629"><a name="p509826523165629"></a><a name="p509826523165629"></a>Obtains a timer of the process. </p>
</td>
</tr>
<tr id="row396401765165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p394043665165629"><a name="p394043665165629"></a><a name="p394043665165629"></a><a href="TIME.md#ga6ecdedfd7f417a3d93aa7a18ff0ac582">timer_getoverrun</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599456592165629"><a name="p599456592165629"></a><a name="p599456592165629"></a>int </p>
<p id="p1547036578165629"><a name="p1547036578165629"></a><a name="p1547036578165629"></a>Obtains the number of times that a timer overruns. </p>
</td>
</tr>
<tr id="row1656847430165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755396213165629"><a name="p755396213165629"></a><a name="p755396213165629"></a><a href="TIME.md#ga8454b83c5b4fb93a9dcdd72ab586de22">strptime</a> (const char *s, const char *format, struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p252646842165629"><a name="p252646842165629"></a><a name="p252646842165629"></a>char * </p>
<p id="p53193786165629"><a name="p53193786165629"></a><a name="p53193786165629"></a>Converts a time string to the broken-down time in the <a href="tm.md">tm</a> structure. </p>
</td>
</tr>
<tr id="row804482307165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771550302165629"><a name="p1771550302165629"></a><a name="p1771550302165629"></a><a href="TIME.md#gae85b268128fa533b20949464ce34165a">getdate</a> (const char *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680190349165629"><a name="p1680190349165629"></a><a name="p1680190349165629"></a>struct <a href="tm.md">tm</a> * </p>
<p id="p662840763165629"><a name="p662840763165629"></a><a name="p662840763165629"></a>Converts a time string to the broken-down time in the <a href="tm.md">tm</a> structure. </p>
</td>
</tr>
<tr id="row1259069025165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996172570165629"><a name="p996172570165629"></a><a name="p996172570165629"></a><a href="TIME.md#ga69f8377385b2eeee376712dc9f0e3f71">stime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504724832165629"><a name="p1504724832165629"></a><a name="p1504724832165629"></a>int </p>
<p id="p1063031561165629"><a name="p1063031561165629"></a><a name="p1063031561165629"></a>Sets the system time. </p>
</td>
</tr>
<tr id="row249756717165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317425613165629"><a name="p1317425613165629"></a><a name="p1317425613165629"></a><a href="TIME.md#ga4fd5240e99b2a9bf19bc0fe39f6ffc07">timegm</a> (struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342592653165629"><a name="p1342592653165629"></a><a name="p1342592653165629"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> </p>
<p id="p733696456165629"><a name="p733696456165629"></a><a name="p733696456165629"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure to the number of seconds. </p>
</td>
</tr>
</tbody>
</table>

