# TIME<a name="ZH-CN_TOPIC_0000001055108017"></a>

-   [Overview](#section537944755165622)
-   [Summary](#section506383298165622)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)
-   [Details](#section1629487800165622)
-   [Function](#section1113575540165622)
-   [asctime\(\)](#ga416a0a99a5bab4c030e93d21152727f4)
-   [asctime\_r\(\)](#ga8eb1bca8a6fdc63173a83f1c8cb28e15)
-   [clock\_getres\(\)](#ga822b364014350d2d70bbd0ccaab1f476)
-   [clock\_gettime\(\)](#ga28ec1219021575a4b9a7c502b2e9a72c)
-   [clock\_nanosleep\(\)](#ga23d3356807a1cb25b5f64651c4aa7d33)
-   [clock\_settime\(\)](#ga04dbb6f7216d70a1b206741564d4d0fb)
-   [ctime\(\)](#ga6e58d33339fabd469b2f4790b0f2b843)
-   [ctime\_r\(\)](#gae6eed522503f70a5cf05be0be558b125)
-   [difftime\(\)](#ga1901c00eb89e8e35ea193c6a4676679c)
-   [ftime\(\)](#gad225ab16a149ff9aab8fb5c36f29ca0c)
-   [getdate\(\)](#gae85b268128fa533b20949464ce34165a)
-   [getitimer\(\)](#ga87cde44d5a31b1524f925d980c959985)
-   [gettimeofday\(\)](#ga5ef4514eca25b6c6b73c5a54b8bc9e2b)
-   [gmtime\(\)](#ga30d9732f32117a94652e28512905bfb9)
-   [gmtime\_r\(\)](#ga91bb7adea9b0b36acde8dba3012c01a5)
-   [localtime\(\)](#ga70311f8aa60fc5ebbd76c55ea10bc899)
-   [localtime\_r\(\)](#gad8c4ed240ddbd645502ac2f0a306aee0)
-   [mktime\(\)](#gafc0e3f373a3ea00b37714f1b621ae0b1)
-   [nanosleep\(\)](#gafbe0e411e8bf89275e7cd46d0aeedc4b)
-   [setitimer\(\)](#ga81245d77d2f570933cc81f13a101bff8)
-   [settimeofday\(\)](#ga6e6617fc349ed4777425d667ff250fa7)
-   [stime\(\)](#ga69f8377385b2eeee376712dc9f0e3f71)
-   [strftime\(\)](#gab94643a711fc91727b668553d4a8806b)
-   [strftime\_l\(\)](#ga74c011f36d0ad959f0312dec8a5c8dc8)
-   [strptime\(\)](#ga8454b83c5b4fb93a9dcdd72ab586de22)
-   [time\(\)](#gae7841e681c8c9d59818568d39553642c)
-   [timegm\(\)](#ga4fd5240e99b2a9bf19bc0fe39f6ffc07)
-   [timer\_create\(\)](#gaf7dce9c851a2e1a65aaf818b95487431)
-   [timer\_delete\(\)](#ga61fa078bdadbd957cfcdfb12d0592ac1)
-   [timer\_getoverrun\(\)](#ga6ecdedfd7f417a3d93aa7a18ff0ac582)
-   [timer\_gettime\(\)](#ga8f65c6a88588c951e0b11629e56714a4)
-   [timer\_settime\(\)](#gade973e87fffe05aed7f1e97c1d15178e)

## **Overview**<a name="section537944755165622"></a>

**Description:**

Provides time-related structures and functions.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section506383298165622"></a>

## Files<a name="files"></a>

<a name="table1626892399165622"></a>
<table><thead align="left"><tr id="row1511212332165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1533304201165622"><a name="p1533304201165622"></a><a name="p1533304201165622"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p365977432165622"><a name="p365977432165622"></a><a name="p365977432165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2092061319165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156231673165622"><a name="p156231673165622"></a><a name="p156231673165622"></a><a href="sys-time-h.md">sys/time.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p281313950165622"><a name="p281313950165622"></a><a name="p281313950165622"></a>Provides structures and functions related to the system time.</p>
</td>
</tr>
<tr id="row1012650641165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2013389099165622"><a name="p2013389099165622"></a><a name="p2013389099165622"></a><a href="timeb-h.md">timeb.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1864618735165622"><a name="p1864618735165622"></a><a name="p1864618735165622"></a>Provides structures and functions related to the curren time.</p>
</td>
</tr>
<tr id="row1639096325165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1800646274165622"><a name="p1800646274165622"></a><a name="p1800646274165622"></a><a href="time-h.md">time.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903758062165622"><a name="p1903758062165622"></a><a name="p1903758062165622"></a>Provides time-related structures and functions.</p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1490335738165622"></a>
<table><thead align="left"><tr id="row1326978346165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p938744497165622"><a name="p938744497165622"></a><a name="p938744497165622"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p741330850165622"><a name="p741330850165622"></a><a name="p741330850165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1136861269165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633857333165622"><a name="p1633857333165622"></a><a name="p1633857333165622"></a><a href="timeval.md">timeval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1364734543165622"><a name="p1364734543165622"></a><a name="p1364734543165622"></a>Describes a period of time, accurate to microseconds.</p>
</td>
</tr>
<tr id="row1367241798165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1566176485165622"><a name="p1566176485165622"></a><a name="p1566176485165622"></a><a href="timespec.md">timespec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591765030165622"><a name="p591765030165622"></a><a name="p591765030165622"></a>Describes a period of time, accurate to nanoseconds.</p>
</td>
</tr>
<tr id="row1978142206165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114756134165622"><a name="p114756134165622"></a><a name="p114756134165622"></a><a href="itimerval.md">itimerval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990088504165622"><a name="p990088504165622"></a><a name="p990088504165622"></a>Describes a timer.</p>
</td>
</tr>
<tr id="row496915709165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1723365055165622"><a name="p1723365055165622"></a><a name="p1723365055165622"></a><a href="timezone.md">timezone</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1931759713165622"><a name="p1931759713165622"></a><a name="p1931759713165622"></a>Describes a time zone.</p>
</td>
</tr>
<tr id="row684814380165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1238833355165622"><a name="p1238833355165622"></a><a name="p1238833355165622"></a><a href="timeb.md">timeb</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380956377165622"><a name="p1380956377165622"></a><a name="p1380956377165622"></a>Describes the time, accurate to millisecond.</p>
</td>
</tr>
<tr id="row1804810363165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p414144803165622"><a name="p414144803165622"></a><a name="p414144803165622"></a><a href="tm.md">tm</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532262130165622"><a name="p1532262130165622"></a><a name="p1532262130165622"></a>Describes date and time information.</p>
</td>
</tr>
<tr id="row1009036191165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145475276165622"><a name="p2145475276165622"></a><a name="p2145475276165622"></a><a href="itimerspec.md">itimerspec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834707202165622"><a name="p834707202165622"></a><a name="p834707202165622"></a>Sets a timer.</p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table66261884165622"></a>
<table><thead align="left"><tr id="row1470864953165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1194505592165622"><a name="p1194505592165622"></a><a name="p1194505592165622"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1824715908165622"><a name="p1824715908165622"></a><a name="p1824715908165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1025575865165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p820742662165622"><a name="p820742662165622"></a><a name="p820742662165622"></a><em id="gace5b149f36c4133045c32d756e2b9a82"><a name="gace5b149f36c4133045c32d756e2b9a82"></a><a name="gace5b149f36c4133045c32d756e2b9a82"></a></em>ITIMER_REAL    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p961474547165622"><a name="p961474547165622"></a><a name="p961474547165622"></a>Defines the timer that runs in real time.</p>
</td>
</tr>
<tr id="row1095193606165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p354204478165622"><a name="p354204478165622"></a><a name="p354204478165622"></a><em id="ga922ce1ae64374c9410c8a999e25e82af"><a name="ga922ce1ae64374c9410c8a999e25e82af"></a><a name="ga922ce1ae64374c9410c8a999e25e82af"></a></em>CLOCK_REALTIME    0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1980983011165622"><a name="p1980983011165622"></a><a name="p1980983011165622"></a>Defines a real-time clock.</p>
</td>
</tr>
<tr id="row1764944070165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900606155165622"><a name="p900606155165622"></a><a name="p900606155165622"></a><em id="ga6fb83f5e91e704391ff796553d5e0f46"><a name="ga6fb83f5e91e704391ff796553d5e0f46"></a><a name="ga6fb83f5e91e704391ff796553d5e0f46"></a></em>CLOCK_MONOTONIC    1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552063515165622"><a name="p1552063515165622"></a><a name="p1552063515165622"></a>Defines a monotonic clock.</p>
</td>
</tr>
<tr id="row2009484571165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1469536833165622"><a name="p1469536833165622"></a><a name="p1469536833165622"></a><em id="gabc28c2ee4e33ae055ef2f737110a7020"><a name="gabc28c2ee4e33ae055ef2f737110a7020"></a><a name="gabc28c2ee4e33ae055ef2f737110a7020"></a></em>CLOCK_MONOTONIC_RAW    4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738364596165622"><a name="p1738364596165622"></a><a name="p1738364596165622"></a>Defines a raw hardware-based monotonic clock.</p>
</td>
</tr>
<tr id="row2064511255165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1455047022165622"><a name="p1455047022165622"></a><a name="p1455047022165622"></a><em id="gaccb072221e0afcac765ec2bb6e4eca04"><a name="gaccb072221e0afcac765ec2bb6e4eca04"></a><a name="gaccb072221e0afcac765ec2bb6e4eca04"></a></em>CLOCK_REALTIME_COARSE    5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779417204165622"><a name="p779417204165622"></a><a name="p779417204165622"></a>Defines a low-precision real-time clock.</p>
</td>
</tr>
<tr id="row872735400165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p473024189165622"><a name="p473024189165622"></a><a name="p473024189165622"></a><em id="gaec7304645b1e13a52fa6dfb11f1c671b"><a name="gaec7304645b1e13a52fa6dfb11f1c671b"></a><a name="gaec7304645b1e13a52fa6dfb11f1c671b"></a></em>CLOCK_MONOTONIC_COARSE    6</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p887583174165622"><a name="p887583174165622"></a><a name="p887583174165622"></a>Defines a low-precision monotonic clock.</p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1819543011165622"></a>
<table><thead align="left"><tr id="row1532632486165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1574157034165622"><a name="p1574157034165622"></a><a name="p1574157034165622"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p323900858165622"><a name="p323900858165622"></a><a name="p323900858165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1010697317165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535019928165622"><a name="p1535019928165622"></a><a name="p1535019928165622"></a><a href="TIME.md#ga5ef4514eca25b6c6b73c5a54b8bc9e2b">gettimeofday</a> (struct <a href="timeval.md">timeval</a> *__restrict value, void *__restrict ovalue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1396659673165622"><a name="p1396659673165622"></a><a name="p1396659673165622"></a>int</p>
<p id="p880856429165622"><a name="p880856429165622"></a><a name="p880856429165622"></a>Obtains the system time and time zone.</p>
</td>
</tr>
<tr id="row1175841568165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1588718037165622"><a name="p1588718037165622"></a><a name="p1588718037165622"></a><a href="TIME.md#ga87cde44d5a31b1524f925d980c959985">getitimer</a> (int w, struct <a href="itimerval.md">itimerval</a> *old)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p792180812165622"><a name="p792180812165622"></a><a name="p792180812165622"></a>int</p>
<p id="p784512783165622"><a name="p784512783165622"></a><a name="p784512783165622"></a>Obtains the value of an intermittent timer.</p>
</td>
</tr>
<tr id="row1051175337165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p389261085165622"><a name="p389261085165622"></a><a name="p389261085165622"></a><a href="TIME.md#ga81245d77d2f570933cc81f13a101bff8">setitimer</a> (int w, const struct <a href="itimerval.md">itimerval</a> *__restrict value, struct <a href="itimerval.md">itimerval</a> *__restrict ovalue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p868993214165622"><a name="p868993214165622"></a><a name="p868993214165622"></a>int</p>
<p id="p303227128165622"><a name="p303227128165622"></a><a name="p303227128165622"></a>Sets the value for a timer.</p>
</td>
</tr>
<tr id="row1666366798165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514818461165622"><a name="p1514818461165622"></a><a name="p1514818461165622"></a><a href="TIME.md#ga6e6617fc349ed4777425d667ff250fa7">settimeofday</a> (const struct <a href="timeval.md">timeval</a> *tv, const struct <a href="timezone.md">timezone</a> *tz)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511053962165622"><a name="p1511053962165622"></a><a name="p1511053962165622"></a>int</p>
<p id="p1924647349165622"><a name="p1924647349165622"></a><a name="p1924647349165622"></a>Sets the system time and time zone.</p>
</td>
</tr>
<tr id="row37777390165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206069357165622"><a name="p1206069357165622"></a><a name="p1206069357165622"></a><a href="TIME.md#gad225ab16a149ff9aab8fb5c36f29ca0c">ftime</a> (struct <a href="timeb.md">timeb</a> *tp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028506935165622"><a name="p2028506935165622"></a><a name="p2028506935165622"></a>int</p>
<p id="p429491088165622"><a name="p429491088165622"></a><a name="p429491088165622"></a>Obtains the current time, accurate to milliseconds.</p>
</td>
</tr>
<tr id="row1173964679165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658180085165622"><a name="p658180085165622"></a><a name="p658180085165622"></a><a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a> (<a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1596723235165622"><a name="p1596723235165622"></a><a name="p1596723235165622"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a></p>
<p id="p110344237165622"><a name="p110344237165622"></a><a name="p110344237165622"></a>Obtains the time.</p>
</td>
</tr>
<tr id="row1113909991165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1749849258165622"><a name="p1749849258165622"></a><a name="p1749849258165622"></a><a href="TIME.md#ga1901c00eb89e8e35ea193c6a4676679c">difftime</a> (<a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> time1, <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> time2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93592937165622"><a name="p93592937165622"></a><a name="p93592937165622"></a>double</p>
<p id="p206381539165622"><a name="p206381539165622"></a><a name="p206381539165622"></a>Calculates the difference between two times, in seconds.</p>
</td>
</tr>
<tr id="row1876579552165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p730192070165622"><a name="p730192070165622"></a><a name="p730192070165622"></a><a href="TIME.md#gafc0e3f373a3ea00b37714f1b621ae0b1">mktime</a> (struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1970736792165622"><a name="p1970736792165622"></a><a name="p1970736792165622"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a></p>
<p id="p920744304165622"><a name="p920744304165622"></a><a name="p920744304165622"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure into seconds.</p>
</td>
</tr>
<tr id="row1336766731165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1438031015165622"><a name="p1438031015165622"></a><a name="p1438031015165622"></a><a href="TIME.md#gab94643a711fc91727b668553d4a8806b">strftime</a> (char *restrict s, size_t n, const char *restrict f, const struct <a href="tm.md">tm</a> *restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1406846948165622"><a name="p1406846948165622"></a><a name="p1406846948165622"></a>size_t</p>
<p id="p1478451707165622"><a name="p1478451707165622"></a><a name="p1478451707165622"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure to a string in the required format.</p>
</td>
</tr>
<tr id="row1633616832165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1669210262165622"><a name="p1669210262165622"></a><a name="p1669210262165622"></a><a href="TIME.md#ga30d9732f32117a94652e28512905bfb9">gmtime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325814558165622"><a name="p325814558165622"></a><a name="p325814558165622"></a>struct <a href="tm.md">tm</a> *</p>
<p id="p268236670165622"><a name="p268236670165622"></a><a name="p268236670165622"></a>Converts the number of seconds to the UTC time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
<tr id="row1149956408165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1357490820165622"><a name="p1357490820165622"></a><a name="p1357490820165622"></a><a href="TIME.md#ga70311f8aa60fc5ebbd76c55ea10bc899">localtime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1417752815165622"><a name="p1417752815165622"></a><a name="p1417752815165622"></a>struct <a href="tm.md">tm</a> *</p>
<p id="p2024707387165622"><a name="p2024707387165622"></a><a name="p2024707387165622"></a>Converts the number of seconds to the local time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
<tr id="row1859792842165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358520396165622"><a name="p1358520396165622"></a><a name="p1358520396165622"></a><a href="TIME.md#ga416a0a99a5bab4c030e93d21152727f4">asctime</a> (const struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024138547165622"><a name="p2024138547165622"></a><a name="p2024138547165622"></a>char *</p>
<p id="p1010526133165622"><a name="p1010526133165622"></a><a name="p1010526133165622"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure into a string.</p>
</td>
</tr>
<tr id="row1992891550165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p575660315165622"><a name="p575660315165622"></a><a name="p575660315165622"></a><a href="TIME.md#ga6e58d33339fabd469b2f4790b0f2b843">ctime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *timep)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1041210635165622"><a name="p1041210635165622"></a><a name="p1041210635165622"></a>char *</p>
<p id="p447729132165622"><a name="p447729132165622"></a><a name="p447729132165622"></a>Converts the date and time into a string.</p>
</td>
</tr>
<tr id="row403590701165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501313983165622"><a name="p501313983165622"></a><a name="p501313983165622"></a><a href="TIME.md#ga74c011f36d0ad959f0312dec8a5c8dc8">strftime_l</a> (char *__restrict s, size_t n, const char *__restrict f, const struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>, locale_t loc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p421680696165622"><a name="p421680696165622"></a><a name="p421680696165622"></a>size_t</p>
<p id="p843829633165622"><a name="p843829633165622"></a><a name="p843829633165622"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure to a string in a specified programming language and format.</p>
</td>
</tr>
<tr id="row429582849165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1553749818165622"><a name="p1553749818165622"></a><a name="p1553749818165622"></a><a href="TIME.md#ga91bb7adea9b0b36acde8dba3012c01a5">gmtime_r</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *__restrict t, struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727896819165622"><a name="p1727896819165622"></a><a name="p1727896819165622"></a>struct <a href="tm.md">tm</a> *</p>
<p id="p848041035165622"><a name="p848041035165622"></a><a name="p848041035165622"></a>Converts the number of seconds to the UTC time in the <a href="tm.md">tm</a> structure. (This function is reentrant.)</p>
</td>
</tr>
<tr id="row748711769165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607068007165622"><a name="p1607068007165622"></a><a name="p1607068007165622"></a><a href="TIME.md#gad8c4ed240ddbd645502ac2f0a306aee0">localtime_r</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *__restrict t, struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487793970165622"><a name="p1487793970165622"></a><a name="p1487793970165622"></a>struct <a href="tm.md">tm</a> *</p>
<p id="p1464042899165622"><a name="p1464042899165622"></a><a name="p1464042899165622"></a>Converts the number of seconds to the local time in the <a href="tm.md">tm</a> structure. (This function is reentrant.)</p>
</td>
</tr>
<tr id="row1015254425165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850979985165622"><a name="p1850979985165622"></a><a name="p1850979985165622"></a><a href="TIME.md#ga8eb1bca8a6fdc63173a83f1c8cb28e15">asctime_r</a> (const struct <a href="tm.md">tm</a> *__restrict <a href="tm.md">tm</a>, char *__restrict buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788722283165622"><a name="p788722283165622"></a><a name="p788722283165622"></a>char *</p>
<p id="p820785834165622"><a name="p820785834165622"></a><a name="p820785834165622"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure into a string. (This function is reentrant.)</p>
</td>
</tr>
<tr id="row1420815213165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p219554194165622"><a name="p219554194165622"></a><a name="p219554194165622"></a><a href="TIME.md#gae6eed522503f70a5cf05be0be558b125">ctime_r</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t, char *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35424631165622"><a name="p35424631165622"></a><a name="p35424631165622"></a>char *</p>
<p id="p1412846634165622"><a name="p1412846634165622"></a><a name="p1412846634165622"></a>Converts the date and time into a string. (This function is reentrant.)</p>
</td>
</tr>
<tr id="row1672952147165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45420564165622"><a name="p45420564165622"></a><a name="p45420564165622"></a><a href="TIME.md#gafbe0e411e8bf89275e7cd46d0aeedc4b">nanosleep</a> (const struct <a href="timespec.md">timespec</a> *tspec1, struct <a href="timespec.md">timespec</a> *tspec2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197612935165622"><a name="p1197612935165622"></a><a name="p1197612935165622"></a>int</p>
<p id="p2052116848165622"><a name="p2052116848165622"></a><a name="p2052116848165622"></a>Pauses the current thread until a specified time arrives.</p>
</td>
</tr>
<tr id="row1442369716165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220738045165622"><a name="p1220738045165622"></a><a name="p1220738045165622"></a><a href="TIME.md#ga822b364014350d2d70bbd0ccaab1f476">clock_getres</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, struct <a href="timespec.md">timespec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304755366165622"><a name="p1304755366165622"></a><a name="p1304755366165622"></a>int</p>
<p id="p594195743165622"><a name="p594195743165622"></a><a name="p594195743165622"></a>Obtains the precision of a clock.</p>
</td>
</tr>
<tr id="row19706343165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p184964350165622"><a name="p184964350165622"></a><a name="p184964350165622"></a><a href="TIME.md#ga28ec1219021575a4b9a7c502b2e9a72c">clock_gettime</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, struct <a href="timespec.md">timespec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p239382841165622"><a name="p239382841165622"></a><a name="p239382841165622"></a>int</p>
<p id="p404762495165622"><a name="p404762495165622"></a><a name="p404762495165622"></a>Obtains the time of a clock.</p>
</td>
</tr>
<tr id="row1491679822165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306520771165622"><a name="p306520771165622"></a><a name="p306520771165622"></a><a href="TIME.md#ga04dbb6f7216d70a1b206741564d4d0fb">clock_settime</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, const struct <a href="timespec.md">timespec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643681638165622"><a name="p1643681638165622"></a><a name="p1643681638165622"></a>int</p>
<p id="p1087577233165622"><a name="p1087577233165622"></a><a name="p1087577233165622"></a>Sets the time for a clock.</p>
</td>
</tr>
<tr id="row1511919351165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71416349165622"><a name="p71416349165622"></a><a name="p71416349165622"></a><a href="TIME.md#ga23d3356807a1cb25b5f64651c4aa7d33">clock_nanosleep</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, int flag, const struct <a href="timespec.md">timespec</a> *tspec1, struct <a href="timespec.md">timespec</a> *tspec2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p919910326165622"><a name="p919910326165622"></a><a name="p919910326165622"></a>int</p>
<p id="p1362209627165622"><a name="p1362209627165622"></a><a name="p1362209627165622"></a>Pauses the current thread until a specified time of a clock arrives.</p>
</td>
</tr>
<tr id="row330611397165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906630340165622"><a name="p1906630340165622"></a><a name="p1906630340165622"></a><a href="TIME.md#gaf7dce9c851a2e1a65aaf818b95487431">timer_create</a> (<a href="UTILS.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> id, struct <a href="sigevent.md">sigevent</a> *__restrict evp, <a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> *__restrict t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583912188165622"><a name="p583912188165622"></a><a name="p583912188165622"></a>int</p>
<p id="p1576885102165622"><a name="p1576885102165622"></a><a name="p1576885102165622"></a>Creates a timer for the process.</p>
</td>
</tr>
<tr id="row1768783257165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702611146165622"><a name="p702611146165622"></a><a name="p702611146165622"></a><a href="TIME.md#ga61fa078bdadbd957cfcdfb12d0592ac1">timer_delete</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520941149165622"><a name="p520941149165622"></a><a name="p520941149165622"></a>int</p>
<p id="p1529614018165622"><a name="p1529614018165622"></a><a name="p1529614018165622"></a>Deletes a timer for the process.</p>
</td>
</tr>
<tr id="row711059475165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p697120550165622"><a name="p697120550165622"></a><a name="p697120550165622"></a><a href="TIME.md#gade973e87fffe05aed7f1e97c1d15178e">timer_settime</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t, int flags, const struct <a href="itimerspec.md">itimerspec</a> *__restrict val, struct <a href="itimerspec.md">itimerspec</a> *__restrict old)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760690915165622"><a name="p1760690915165622"></a><a name="p1760690915165622"></a>int</p>
<p id="p525625068165622"><a name="p525625068165622"></a><a name="p525625068165622"></a>Sets a timer for the process.</p>
</td>
</tr>
<tr id="row1575984648165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p634895114165622"><a name="p634895114165622"></a><a name="p634895114165622"></a><a href="TIME.md#ga8f65c6a88588c951e0b11629e56714a4">timer_gettime</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t, struct <a href="itimerspec.md">itimerspec</a> *tspec)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973935563165622"><a name="p1973935563165622"></a><a name="p1973935563165622"></a>int</p>
<p id="p883578349165622"><a name="p883578349165622"></a><a name="p883578349165622"></a>Obtains a timer of the process.</p>
</td>
</tr>
<tr id="row2030734265165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119495399165622"><a name="p2119495399165622"></a><a name="p2119495399165622"></a><a href="TIME.md#ga6ecdedfd7f417a3d93aa7a18ff0ac582">timer_getoverrun</a> (<a href="UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a">timer_t</a> t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795827372165622"><a name="p795827372165622"></a><a name="p795827372165622"></a>int</p>
<p id="p1135884130165622"><a name="p1135884130165622"></a><a name="p1135884130165622"></a>Obtains the number of times that a timer overruns.</p>
</td>
</tr>
<tr id="row538650532165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2017352652165622"><a name="p2017352652165622"></a><a name="p2017352652165622"></a><a href="TIME.md#ga8454b83c5b4fb93a9dcdd72ab586de22">strptime</a> (const char *s, const char *format, struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1517001396165622"><a name="p1517001396165622"></a><a name="p1517001396165622"></a>char *</p>
<p id="p1141317943165622"><a name="p1141317943165622"></a><a name="p1141317943165622"></a>Converts a time string to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
<tr id="row106922454165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1685655042165622"><a name="p1685655042165622"></a><a name="p1685655042165622"></a><a href="TIME.md#gae85b268128fa533b20949464ce34165a">getdate</a> (const char *buf)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1500655917165622"><a name="p1500655917165622"></a><a name="p1500655917165622"></a>struct <a href="tm.md">tm</a> *</p>
<p id="p1566585516165622"><a name="p1566585516165622"></a><a name="p1566585516165622"></a>Converts a time string to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
<tr id="row41043258165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p505488785165622"><a name="p505488785165622"></a><a name="p505488785165622"></a><a href="TIME.md#ga69f8377385b2eeee376712dc9f0e3f71">stime</a> (const <a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a> *t)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055444421165622"><a name="p1055444421165622"></a><a name="p1055444421165622"></a>int</p>
<p id="p340190987165622"><a name="p340190987165622"></a><a name="p340190987165622"></a>Sets the system time.</p>
</td>
</tr>
<tr id="row30744130165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098859636165622"><a name="p2098859636165622"></a><a name="p2098859636165622"></a><a href="TIME.md#ga4fd5240e99b2a9bf19bc0fe39f6ffc07">timegm</a> (struct <a href="tm.md">tm</a> *<a href="tm.md">tm</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506679630165622"><a name="p506679630165622"></a><a name="p506679630165622"></a><a href="UTILS.md#ga138ad62ac7715e7161bf6223e35d8323">time_t</a></p>
<p id="p1953040402165622"><a name="p1953040402165622"></a><a name="p1953040402165622"></a>Converts the broken-down time in the <a href="tm.md">tm</a> structure to the number of seconds.</p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1629487800165622"></a>

## **Function**<a name="section1113575540165622"></a>

## asctime\(\)<a name="ga416a0a99a5bab4c030e93d21152727f4"></a>

```
char* asctime (const struct [tm](tm.md) * tm)
```

**Description:**

Converts the broken-down time in the  [tm](tm.md)  structure into a string.

**Parameters:**

<a name="table713954155165622"></a>
<table><thead align="left"><tr id="row2101831008165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p304444757165622"><a name="p304444757165622"></a><a name="p304444757165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p332122819165622"><a name="p332122819165622"></a><a name="p332122819165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1008299573165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1909008039165622p0"><a name="entry1909008039165622p0"></a><a name="entry1909008039165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry522740942165622p0"><a name="entry522740942165622p0"></a><a name="entry522740942165622p0"></a>Indicates the pointer to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string in the format of  **week month day hour:minute:second year**, for example,  **Thu Jan 1 08:00:00 1970**. If the conversion fails, the program ends.

## asctime\_r\(\)<a name="ga8eb1bca8a6fdc63173a83f1c8cb28e15"></a>

```
char* asctime_r (const struct [tm](tm.md) *__restrict tm, char *__restrict buf )
```

**Description:**

Converts the broken-down time in the  [tm](tm.md)  structure into a string. \(This function is reentrant.\)

**Parameters:**

<a name="table24453997165622"></a>
<table><thead align="left"><tr id="row112992394165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1974762873165622"><a name="p1974762873165622"></a><a name="p1974762873165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p395399235165622"><a name="p395399235165622"></a><a name="p395399235165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1481781906165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1172071059165622p0"><a name="entry1172071059165622p0"></a><a name="entry1172071059165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry543000346165622p0"><a name="entry543000346165622p0"></a><a name="entry543000346165622p0"></a>Indicates the pointer to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
<tr id="row601209951165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry176398239165622p0"><a name="entry176398239165622p0"></a><a name="entry176398239165622p0"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry262934266165622p0"><a name="entry262934266165622p0"></a><a name="entry262934266165622p0"></a>Indicates the pointer to the buffer for storing the string.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string in the format of  **week month day hour:minute:second year**, for example,  **Thu Jan 1 08:00:00 1970**. If the conversion fails, the program ends.

## clock\_getres\(\)<a name="ga822b364014350d2d70bbd0ccaab1f476"></a>

```
int clock_getres ([clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) id, struct [timespec](timespec.md) * tspec )
```

**Description:**

Obtains the precision of a clock.

**Parameters:**

<a name="table263690188165622"></a>
<table><thead align="left"><tr id="row128894928165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1737471542165622"><a name="p1737471542165622"></a><a name="p1737471542165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1152750936165622"><a name="p1152750936165622"></a><a name="p1152750936165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row567122679165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1236980931165622p0"><a name="entry1236980931165622p0"></a><a name="entry1236980931165622p0"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry615826306165622p0"><a name="entry615826306165622p0"></a><a name="entry615826306165622p0"></a>Indicates the clock ID, which can be <a href="TIME.md#ga922ce1ae64374c9410c8a999e25e82af">CLOCK_REALTIME</a>, <a href="TIME.md#gaccb072221e0afcac765ec2bb6e4eca04">CLOCK_REALTIME_COARSE</a>, <a href="TIME.md#ga6fb83f5e91e704391ff796553d5e0f46">CLOCK_MONOTONIC</a>, <a href="TIME.md#gaec7304645b1e13a52fa6dfb11f1c671b">CLOCK_MONOTONIC_COARSE</a> or <a href="TIME.md#gabc28c2ee4e33ae055ef2f737110a7020">CLOCK_MONOTONIC_RAW</a>.</p>
</td>
</tr>
<tr id="row1817024554165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1461432407165622p0"><a name="entry1461432407165622p0"></a><a name="entry1461432407165622p0"></a>tspec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1450073290165622p0"><a name="entry1450073290165622p0"></a><a name="entry1450073290165622p0"></a>Indicates the pointer to the data obtained.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise.

## clock\_gettime\(\)<a name="ga28ec1219021575a4b9a7c502b2e9a72c"></a>

```
int clock_gettime ([clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) id, struct [timespec](timespec.md) * tspec )
```

**Description:**

Obtains the time of a clock.

**Parameters:**

<a name="table1369911483165622"></a>
<table><thead align="left"><tr id="row452344839165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p76735586165622"><a name="p76735586165622"></a><a name="p76735586165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p966255037165622"><a name="p966255037165622"></a><a name="p966255037165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1771405109165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1862922675165622p0"><a name="entry1862922675165622p0"></a><a name="entry1862922675165622p0"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry477085042165622p0"><a name="entry477085042165622p0"></a><a name="entry477085042165622p0"></a>Indicates the clock ID, which can be <a href="TIME.md#ga922ce1ae64374c9410c8a999e25e82af">CLOCK_REALTIME</a>, <a href="TIME.md#gaccb072221e0afcac765ec2bb6e4eca04">CLOCK_REALTIME_COARSE</a>, <a href="TIME.md#ga6fb83f5e91e704391ff796553d5e0f46">CLOCK_MONOTONIC</a>, <a href="TIME.md#gaec7304645b1e13a52fa6dfb11f1c671b">CLOCK_MONOTONIC_COARSE</a>, or <a href="TIME.md#gabc28c2ee4e33ae055ef2f737110a7020">CLOCK_MONOTONIC_RAW</a>.</p>
</td>
</tr>
<tr id="row583269590165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1411975517165622p0"><a name="entry1411975517165622p0"></a><a name="entry1411975517165622p0"></a>tspec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry690253032165622p0"><a name="entry690253032165622p0"></a><a name="entry690253032165622p0"></a>Indicates the pointer to the time obtained.</p>
</td>
</tr>
</tbody>
</table>

**Attention:**

[CLOCK\_REALTIME\_COARSE](TIME.md#gaccb072221e0afcac765ec2bb6e4eca04)  and  [CLOCK\_MONOTONIC\_COARSE](TIME.md#gaec7304645b1e13a52fa6dfb11f1c671b)  are two new types of clock ID, which are optimized via virtual dynamic shared object \(vDSO\).

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table503521087165622"></a>
<table><thead align="left"><tr id="row1565095388165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1017021878165622"><a name="p1017021878165622"></a><a name="p1017021878165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1735632371165622"><a name="p1735632371165622"></a><a name="p1735632371165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row855132399165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641998132165622"><a name="p641998132165622"></a><a name="p641998132165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044975425165622"><a name="p2044975425165622"></a><a name="p2044975425165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## clock\_nanosleep\(\)<a name="ga23d3356807a1cb25b5f64651c4aa7d33"></a>

```
int clock_nanosleep ([clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) id, int flag, const struct [timespec](timespec.md) * tspec1, struct [timespec](timespec.md) * tspec2 )
```

**Description:**

Pauses the current thread until a specified time of a clock arrives.

A sleeping thread cannot be woken up by a signal.

**Parameters:**

<a name="table915149759165622"></a>
<table><thead align="left"><tr id="row577591072165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1937027335165622"><a name="p1937027335165622"></a><a name="p1937027335165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1651402534165622"><a name="p1651402534165622"></a><a name="p1651402534165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row405328141165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry166642297165622p0"><a name="entry166642297165622p0"></a><a name="entry166642297165622p0"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1269263021165622p0"><a name="entry1269263021165622p0"></a><a name="entry1269263021165622p0"></a>Indicates the clock ID. Only <a href="TIME.md#ga922ce1ae64374c9410c8a999e25e82af">CLOCK_REALTIME</a> is supported.</p>
</td>
</tr>
<tr id="row396621639165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry557053089165622p0"><a name="entry557053089165622p0"></a><a name="entry557053089165622p0"></a>flag</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1189783538165622p0"><a name="entry1189783538165622p0"></a><a name="entry1189783538165622p0"></a>Indicates the clock type. This parameter must be set to <strong id="b1892878901165622"><a name="b1892878901165622"></a><a name="b1892878901165622"></a>0</strong></p>
</td>
</tr>
<tr id="row520466725165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2003800658165622p0"><a name="entry2003800658165622p0"></a><a name="entry2003800658165622p0"></a>tspec1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1401090459165622p0"><a name="entry1401090459165622p0"></a><a name="entry1401090459165622p0"></a>Indicates the pointer to the minimum duration that the current thread is paused. Currently, the unit of precision is tick, and the discrepancy is fewer than 2 ticks.</p>
</td>
</tr>
<tr id="row1783242016165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry560848207165622p0"><a name="entry560848207165622p0"></a><a name="entry560848207165622p0"></a>tspec2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1676667509165622p0"><a name="entry1676667509165622p0"></a><a name="entry1676667509165622p0"></a>This parameter is not used yet.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table2039971471165622"></a>
<table><thead align="left"><tr id="row658580159165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1389912483165622"><a name="p1389912483165622"></a><a name="p1389912483165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1382098588165622"><a name="p1382098588165622"></a><a name="p1382098588165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row971965636165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229370149165622"><a name="p229370149165622"></a><a name="p229370149165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1564807102165622"><a name="p1564807102165622"></a><a name="p1564807102165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## clock\_settime\(\)<a name="ga04dbb6f7216d70a1b206741564d4d0fb"></a>

```
int clock_settime ([clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) id, const struct [timespec](timespec.md) * tspec )
```

**Description:**

Sets the time for a clock.

**Parameters:**

<a name="table1507213847165622"></a>
<table><thead align="left"><tr id="row366883428165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1957027810165622"><a name="p1957027810165622"></a><a name="p1957027810165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1004249228165622"><a name="p1004249228165622"></a><a name="p1004249228165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1341135300165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry701042550165622p0"><a name="entry701042550165622p0"></a><a name="entry701042550165622p0"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry742786780165622p0"><a name="entry742786780165622p0"></a><a name="entry742786780165622p0"></a>Indicates the clock ID. Only <a href="TIME.md#ga922ce1ae64374c9410c8a999e25e82af">CLOCK_REALTIME</a> is supported.</p>
</td>
</tr>
<tr id="row891737314165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry398994421165622p0"><a name="entry398994421165622p0"></a><a name="entry398994421165622p0"></a>tspec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1872740757165622p0"><a name="entry1872740757165622p0"></a><a name="entry1872740757165622p0"></a>Indicates the pointer to the time to set.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table633889712165622"></a>
<table><thead align="left"><tr id="row1326861836165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p795031166165622"><a name="p795031166165622"></a><a name="p795031166165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1347799578165622"><a name="p1347799578165622"></a><a name="p1347799578165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1100348736165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192291745165622"><a name="p1192291745165622"></a><a name="p1192291745165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722826172165622"><a name="p722826172165622"></a><a name="p722826172165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## ctime\(\)<a name="ga6e58d33339fabd469b2f4790b0f2b843"></a>

```
char* ctime (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) * timep)
```

**Description:**

Converts the date and time into a string.

**Parameters:**

<a name="table628023886165622"></a>
<table><thead align="left"><tr id="row1855930157165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p903830184165622"><a name="p903830184165622"></a><a name="p903830184165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1458301662165622"><a name="p1458301662165622"></a><a name="p1458301662165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row118446971165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry238812254165622p0"><a name="entry238812254165622p0"></a><a name="entry238812254165622p0"></a>timep</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry581024946165622p0"><a name="entry581024946165622p0"></a><a name="entry581024946165622p0"></a>Indicates the number of seconds to convert.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string in the format of  **week month day hour:minute:second year**, for example,  **Thu Jan 1 08:00:00 1970**. If the conversion fails, the program ends.

## ctime\_r\(\)<a name="gae6eed522503f70a5cf05be0be558b125"></a>

```
char* ctime_r (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) * t, char * buf )
```

**Description:**

Converts the date and time into a string. \(This function is reentrant.\)

**Parameters:**

<a name="table2138413381165622"></a>
<table><thead align="left"><tr id="row326022319165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p671168714165622"><a name="p671168714165622"></a><a name="p671168714165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2057749346165622"><a name="p2057749346165622"></a><a name="p2057749346165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1436449876165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry435095638165622p0"><a name="entry435095638165622p0"></a><a name="entry435095638165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1787115029165622p0"><a name="entry1787115029165622p0"></a><a name="entry1787115029165622p0"></a>Indicates the pointer to the number of seconds to convert.</p>
</td>
</tr>
<tr id="row756254648165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry818199762165622p0"><a name="entry818199762165622p0"></a><a name="entry818199762165622p0"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1132686601165622p0"><a name="entry1132686601165622p0"></a><a name="entry1132686601165622p0"></a>Indicates the pointer to the buffer for storing the string.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the string in the format of  **week month day hour:minute:second year**, for example,  **Thu Jan 1 08:00:00 1970**. If the conversion fails, the program ends.

## difftime\(\)<a name="ga1901c00eb89e8e35ea193c6a4676679c"></a>

```
double difftime ([time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) time1, [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) time2 )
```

**Description:**

Calculates the difference between two times, in seconds.

**Parameters:**

<a name="table956492406165622"></a>
<table><thead align="left"><tr id="row149919990165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1796511750165622"><a name="p1796511750165622"></a><a name="p1796511750165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p290165053165622"><a name="p290165053165622"></a><a name="p290165053165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1253590872165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry121107787165622p0"><a name="entry121107787165622p0"></a><a name="entry121107787165622p0"></a>time1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry538848888165622p0"><a name="entry538848888165622p0"></a><a name="entry538848888165622p0"></a>Indicates the first time.</p>
</td>
</tr>
<tr id="row271649344165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1435387209165622p0"><a name="entry1435387209165622p0"></a><a name="entry1435387209165622p0"></a>time2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry231881283165622p0"><a name="entry231881283165622p0"></a><a name="entry231881283165622p0"></a>Indicates the second time.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the difference, represented using a double.

## ftime\(\)<a name="gad225ab16a149ff9aab8fb5c36f29ca0c"></a>

```
int ftime (struct [timeb](timeb.md) * tp)
```

**Description:**

Obtains the current time, accurate to milliseconds.

The time obtained is the total number of milliseconds elapsed since January 1, 1970 00:00:00 \(UTC\).

**Parameters:**

<a name="table2049833559165622"></a>
<table><thead align="left"><tr id="row1669036556165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p43569782165622"><a name="p43569782165622"></a><a name="p43569782165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p456457040165622"><a name="p456457040165622"></a><a name="p456457040165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2059856364165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1184129951165622p0"><a name="entry1184129951165622p0"></a><a name="entry1184129951165622p0"></a>tp</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry915399309165622p0"><a name="entry915399309165622p0"></a><a name="entry915399309165622p0"></a>Indicates the pointer to the number of milliseconds. <strong id="b514254916165622"><a name="b514254916165622"></a><a name="b514254916165622"></a>timezone</strong> and <strong id="b519405374165622"><a name="b519405374165622"></a><a name="b519405374165622"></a>dstflag</strong> are set to <strong id="b1850257794165622"><a name="b1850257794165622"></a><a name="b1850257794165622"></a>0</strong>.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  otherwise.

## getdate\(\)<a name="gae85b268128fa533b20949464ce34165a"></a>

```
struct [tm](tm.md)* getdate (const char * buf)
```

**Description:**

Converts a time string to the broken-down time in the  [tm](tm.md)  structure.

**Parameters:**

<a name="table1859393198165622"></a>
<table><thead align="left"><tr id="row328315295165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p533219259165622"><a name="p533219259165622"></a><a name="p533219259165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1458241144165622"><a name="p1458241144165622"></a><a name="p1458241144165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row262568408165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry247353194165622p0"><a name="entry247353194165622p0"></a><a name="entry247353194165622p0"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry901209841165622p0"><a name="entry901209841165622p0"></a><a name="entry901209841165622p0"></a>Indicates the pointer to the time string. The format is specified by the file defined by the environment variable <strong id="b1977238143165622"><a name="b1977238143165622"></a><a name="b1977238143165622"></a>DATEMSK</strong>.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the time in the  [tm](tm.md)  structure if the operation is successful; returns  **NULL**  otherwise.

## getitimer\(\)<a name="ga87cde44d5a31b1524f925d980c959985"></a>

```
int getitimer (int w, struct [itimerval](itimerval.md) * old )
```

**Description:**

Obtains the value of an intermittent timer.

**Parameters:**

<a name="table404200345165622"></a>
<table><thead align="left"><tr id="row1373309093165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p725558522165622"><a name="p725558522165622"></a><a name="p725558522165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p683858332165622"><a name="p683858332165622"></a><a name="p683858332165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1314521288165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1886006950165622p0"><a name="entry1886006950165622p0"></a><a name="entry1886006950165622p0"></a>w</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry366096179165622p0"><a name="entry366096179165622p0"></a><a name="entry366096179165622p0"></a>Indicates the timer type. Only <a href="TIME.md#gace5b149f36c4133045c32d756e2b9a82">ITIMER_REAL</a> is supported.</p>
</td>
</tr>
<tr id="row93156002165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1584839601165622p0"><a name="entry1584839601165622p0"></a><a name="entry1584839601165622p0"></a>old</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry575301494165622p0"><a name="entry575301494165622p0"></a><a name="entry575301494165622p0"></a>Indicates the pointer to the timer value.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table835871196165622"></a>
<table><thead align="left"><tr id="row2032836115165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1313746773165622"><a name="p1313746773165622"></a><a name="p1313746773165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p725298625165622"><a name="p725298625165622"></a><a name="p725298625165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row131129288165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1695342903165622"><a name="p1695342903165622"></a><a name="p1695342903165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p452424110165622"><a name="p452424110165622"></a><a name="p452424110165622"></a>Incorrect input or timer type.</p>
</td>
</tr>
</tbody>
</table>

## gettimeofday\(\)<a name="ga5ef4514eca25b6c6b73c5a54b8bc9e2b"></a>

```
int gettimeofday (struct [timeval](timeval.md) *__restrict value, void *__restrict ovalue )
```

**Description:**

Obtains the system time and time zone.

**Parameters:**

<a name="table1474172595165622"></a>
<table><thead align="left"><tr id="row1523934363165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p151178362165622"><a name="p151178362165622"></a><a name="p151178362165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1711754076165622"><a name="p1711754076165622"></a><a name="p1711754076165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row170630520165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1454009034165622p0"><a name="entry1454009034165622p0"></a><a name="entry1454009034165622p0"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1222637434165622p0"><a name="entry1222637434165622p0"></a><a name="entry1222637434165622p0"></a>Indicates the pointer to the <strong id="b456173181165622"><a name="b456173181165622"></a><a name="b456173181165622"></a>timeval</strong> structure that contains the time.</p>
</td>
</tr>
<tr id="row1043736696165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry548102797165622p0"><a name="entry548102797165622p0"></a><a name="entry548102797165622p0"></a>ovalue</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry227753973165622p0"><a name="entry227753973165622p0"></a><a name="entry227753973165622p0"></a>This parameter is used for compatibility only.</p>
</td>
</tr>
</tbody>
</table>

**Attention:**

Currently, there is no time zone structure. The return value of  **ovalue**  is empty.

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table945897476165622"></a>
<table><thead align="left"><tr id="row487796351165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1645683400165622"><a name="p1645683400165622"></a><a name="p1645683400165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1853499138165622"><a name="p1853499138165622"></a><a name="p1853499138165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row343183810165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p475359518165622"><a name="p475359518165622"></a><a name="p475359518165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828831423165622"><a name="p1828831423165622"></a><a name="p1828831423165622"></a>Incorrect input.</p>
</td>
</tr>
</tbody>
</table>

## gmtime\(\)<a name="ga30d9732f32117a94652e28512905bfb9"></a>

```
struct [tm](tm.md)* gmtime (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) * t)
```

**Description:**

Converts the number of seconds to the UTC time in the  [tm](tm.md)  structure.

**Parameters:**

<a name="table114167038165622"></a>
<table><thead align="left"><tr id="row894689210165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2015129397165622"><a name="p2015129397165622"></a><a name="p2015129397165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p808656867165622"><a name="p808656867165622"></a><a name="p808656867165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row767752844165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry94774480165622p0"><a name="entry94774480165622p0"></a><a name="entry94774480165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1321678699165622p0"><a name="entry1321678699165622p0"></a><a name="entry1321678699165622p0"></a>Indicates the pointer to the number of seconds to convert.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the UTC time in the  [tm](tm.md)  structure if the conversion is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table953115373165622"></a>
<table><thead align="left"><tr id="row2058400670165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p833171098165622"><a name="p833171098165622"></a><a name="p833171098165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2098634856165622"><a name="p2098634856165622"></a><a name="p2098634856165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1642857815165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p821969814165622"><a name="p821969814165622"></a><a name="p821969814165622"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764114141165622"><a name="p1764114141165622"></a><a name="p1764114141165622"></a>Inappropriate input parameter.</p>
</td>
</tr>
</tbody>
</table>

## gmtime\_r\(\)<a name="ga91bb7adea9b0b36acde8dba3012c01a5"></a>

```
struct [tm](tm.md)* gmtime_r (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) *__restrict t, struct [tm](tm.md) *__restrict tm )
```

**Description:**

Converts the number of seconds to the UTC time in the  [tm](tm.md)  structure. \(This function is reentrant.\)

This function is used in the multi-task environment.

**Parameters:**

<a name="table915652527165622"></a>
<table><thead align="left"><tr id="row1403223474165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p732966569165622"><a name="p732966569165622"></a><a name="p732966569165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p284054886165622"><a name="p284054886165622"></a><a name="p284054886165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1203649350165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry622400434165622p0"><a name="entry622400434165622p0"></a><a name="entry622400434165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry696740798165622p0"><a name="entry696740798165622p0"></a><a name="entry696740798165622p0"></a>Indicates the pointer to the number of seconds to convert.</p>
</td>
</tr>
<tr id="row1924928792165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry559469505165622p0"><a name="entry559469505165622p0"></a><a name="entry559469505165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry83677799165622p0"><a name="entry83677799165622p0"></a><a name="entry83677799165622p0"></a>Indicates the pointer to the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the UTC time in the  [tm](tm.md)  structure if the conversion is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table1794877608165622"></a>
<table><thead align="left"><tr id="row1498368175165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1252786866165622"><a name="p1252786866165622"></a><a name="p1252786866165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p750020265165622"><a name="p750020265165622"></a><a name="p750020265165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1826932131165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1605446762165622"><a name="p1605446762165622"></a><a name="p1605446762165622"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p823665138165622"><a name="p823665138165622"></a><a name="p823665138165622"></a>Inappropriate input parameter.</p>
</td>
</tr>
</tbody>
</table>

## localtime\(\)<a name="ga70311f8aa60fc5ebbd76c55ea10bc899"></a>

```
struct [tm](tm.md)* localtime (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) * t)
```

**Description:**

Converts the number of seconds to the local time in the  [tm](tm.md)  structure.

**Parameters:**

<a name="table2117420415165622"></a>
<table><thead align="left"><tr id="row1393502658165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2513432165622"><a name="p2513432165622"></a><a name="p2513432165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1256518580165622"><a name="p1256518580165622"></a><a name="p1256518580165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row156582416165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1690401245165622p0"><a name="entry1690401245165622p0"></a><a name="entry1690401245165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2106764879165622p0"><a name="entry2106764879165622p0"></a><a name="entry2106764879165622p0"></a>Indicates the pointer to the number of seconds to convert.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the local time in the  [tm](tm.md)  structure if the conversion is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table2044973672165622"></a>
<table><thead align="left"><tr id="row1257295333165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p305593058165622"><a name="p305593058165622"></a><a name="p305593058165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p271694426165622"><a name="p271694426165622"></a><a name="p271694426165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1659317593165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735281537165622"><a name="p1735281537165622"></a><a name="p1735281537165622"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p959053811165622"><a name="p959053811165622"></a><a name="p959053811165622"></a>Inappropriate input parameter.</p>
</td>
</tr>
</tbody>
</table>

## localtime\_r\(\)<a name="gad8c4ed240ddbd645502ac2f0a306aee0"></a>

```
struct [tm](tm.md)* localtime_r (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) *__restrict t, struct [tm](tm.md) *__restrict tm )
```

**Description:**

Converts the number of seconds to the local time in the  [tm](tm.md)  structure. \(This function is reentrant.\)

**Parameters:**

<a name="table1740003260165622"></a>
<table><thead align="left"><tr id="row167928467165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p829734563165622"><a name="p829734563165622"></a><a name="p829734563165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1505517252165622"><a name="p1505517252165622"></a><a name="p1505517252165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row724630140165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry272751520165622p0"><a name="entry272751520165622p0"></a><a name="entry272751520165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1691097990165622p0"><a name="entry1691097990165622p0"></a><a name="entry1691097990165622p0"></a>Indicates the pointer to the number of seconds to convert.</p>
</td>
</tr>
<tr id="row1442947074165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry151730699165622p0"><a name="entry151730699165622p0"></a><a name="entry151730699165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1522063227165622p0"><a name="entry1522063227165622p0"></a><a name="entry1522063227165622p0"></a>Indicates the pointer to the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the local time in the  [tm](tm.md)  structure if the conversion is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table316440117165622"></a>
<table><thead align="left"><tr id="row752462573165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2082680251165622"><a name="p2082680251165622"></a><a name="p2082680251165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1646947680165622"><a name="p1646947680165622"></a><a name="p1646947680165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row478508304165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607031258165622"><a name="p607031258165622"></a><a name="p607031258165622"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775905564165622"><a name="p775905564165622"></a><a name="p775905564165622"></a>Inappropriate input parameter.</p>
</td>
</tr>
</tbody>
</table>

## mktime\(\)<a name="gafc0e3f373a3ea00b37714f1b621ae0b1"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) mktime (struct [tm](tm.md) * tm)
```

**Description:**

Converts the broken-down time in the  [tm](tm.md)  structure into seconds.

**Parameters:**

<a name="table1109819617165622"></a>
<table><thead align="left"><tr id="row760420738165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p767185250165622"><a name="p767185250165622"></a><a name="p767185250165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p584630051165622"><a name="p584630051165622"></a><a name="p584630051165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1021722757165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1537266077165622p0"><a name="entry1537266077165622p0"></a><a name="entry1537266077165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1671735264165622p0"><a name="entry1671735264165622p0"></a><a name="entry1671735264165622p0"></a>Indicates the pointer to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the total number of seconds elapsed since January 1, 1970 00:00:00 \(UTC\) if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table15755136165622"></a>
<table><thead align="left"><tr id="row1127295799165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2063946680165622"><a name="p2063946680165622"></a><a name="p2063946680165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1566259996165622"><a name="p1566259996165622"></a><a name="p1566259996165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1367632275165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1213215891165622"><a name="p1213215891165622"></a><a name="p1213215891165622"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1518729693165622"><a name="p1518729693165622"></a><a name="p1518729693165622"></a>Inappropriate input parameter.</p>
</td>
</tr>
</tbody>
</table>

## nanosleep\(\)<a name="gafbe0e411e8bf89275e7cd46d0aeedc4b"></a>

```
int nanosleep (const struct [timespec](timespec.md) * tspec1, struct [timespec](timespec.md) * tspec2 )
```

**Description:**

Pauses the current thread until a specified time arrives.

A sleeping thread cannot be woken up by a signal.

**Parameters:**

<a name="table1517885383165622"></a>
<table><thead align="left"><tr id="row1785865384165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p772103080165622"><a name="p772103080165622"></a><a name="p772103080165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1556179950165622"><a name="p1556179950165622"></a><a name="p1556179950165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1113533994165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry362197908165622p0"><a name="entry362197908165622p0"></a><a name="entry362197908165622p0"></a>tspec1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry168676827165622p0"><a name="entry168676827165622p0"></a><a name="entry168676827165622p0"></a>Indicates the pointer to the minimum duration that the current thread is paused. Currently, the unit of precision is tick, and the discrepancy is fewer than 2 ticks.</p>
</td>
</tr>
<tr id="row288523114165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry813204301165622p0"><a name="entry813204301165622p0"></a><a name="entry813204301165622p0"></a>tspec2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry561310497165622p0"><a name="entry561310497165622p0"></a><a name="entry561310497165622p0"></a>This parameter is not used yet.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table62612718165622"></a>
<table><thead align="left"><tr id="row225628978165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p554238923165622"><a name="p554238923165622"></a><a name="p554238923165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1333036293165622"><a name="p1333036293165622"></a><a name="p1333036293165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row955556453165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591060952165622"><a name="p591060952165622"></a><a name="p591060952165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264491872165622"><a name="p264491872165622"></a><a name="p264491872165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## setitimer\(\)<a name="ga81245d77d2f570933cc81f13a101bff8"></a>

```
int setitimer (int w, const struct [itimerval](itimerval.md) *__restrict value, struct [itimerval](itimerval.md) *__restrict ovalue )
```

**Description:**

Sets the value for a timer.

**Parameters:**

<a name="table652473904165622"></a>
<table><thead align="left"><tr id="row2115201676165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p253955464165622"><a name="p253955464165622"></a><a name="p253955464165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p375805405165622"><a name="p375805405165622"></a><a name="p375805405165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1983659095165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1389381616165622p0"><a name="entry1389381616165622p0"></a><a name="entry1389381616165622p0"></a>w</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry698686639165622p0"><a name="entry698686639165622p0"></a><a name="entry698686639165622p0"></a>Indicates the timer type. Currently, only <a href="TIME.md#gace5b149f36c4133045c32d756e2b9a82">ITIMER_REAL</a> is supported.</p>
</td>
</tr>
<tr id="row200783659165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2125786267165622p0"><a name="entry2125786267165622p0"></a><a name="entry2125786267165622p0"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1980605902165622p0"><a name="entry1980605902165622p0"></a><a name="entry1980605902165622p0"></a>Indicates the pointer to the timer value to set.</p>
</td>
</tr>
<tr id="row436008570165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1071535296165622p0"><a name="entry1071535296165622p0"></a><a name="entry1071535296165622p0"></a>ovalue</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1286459429165622p0"><a name="entry1286459429165622p0"></a><a name="entry1286459429165622p0"></a>Indicates the pointer to the original timer value before the current setting, which can be <strong id="b2141821483165622"><a name="b2141821483165622"></a><a name="b2141821483165622"></a>NULL</strong>.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table2063664752165622"></a>
<table><thead align="left"><tr id="row1501179815165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p918665420165622"><a name="p918665420165622"></a><a name="p918665420165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1429984284165622"><a name="p1429984284165622"></a><a name="p1429984284165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row511844710165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1137601786165622"><a name="p1137601786165622"></a><a name="p1137601786165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786085792165622"><a name="p1786085792165622"></a><a name="p1786085792165622"></a>Incorrect input or timer type.</p>
</td>
</tr>
</tbody>
</table>

## settimeofday\(\)<a name="ga6e6617fc349ed4777425d667ff250fa7"></a>

```
int settimeofday (const struct [timeval](timeval.md) * tv, const struct [timezone](timezone.md) * tz )
```

**Description:**

Sets the system time and time zone.

**Parameters:**

<a name="table1370971001165622"></a>
<table><thead align="left"><tr id="row408575965165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1414940894165622"><a name="p1414940894165622"></a><a name="p1414940894165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p968515809165622"><a name="p968515809165622"></a><a name="p968515809165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1708119711165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry261623727165622p0"><a name="entry261623727165622p0"></a><a name="entry261623727165622p0"></a>tv</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry705621241165622p0"><a name="entry705621241165622p0"></a><a name="entry705621241165622p0"></a>Indicates the pointer to the time to set.</p>
</td>
</tr>
<tr id="row2126784764165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1340131967165622p0"><a name="entry1340131967165622p0"></a><a name="entry1340131967165622p0"></a>tz</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1444869881165622p0"><a name="entry1444869881165622p0"></a><a name="entry1444869881165622p0"></a>Indicates the pointer to the time zone to set. This parameter is not used yet.</p>
</td>
</tr>
</tbody>
</table>

**Attention:**

**tz**  is invalid. The time is set internally using  **clock\_settime**.

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table1421870545165622"></a>
<table><thead align="left"><tr id="row1764500572165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p483344123165622"><a name="p483344123165622"></a><a name="p483344123165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1068345104165622"><a name="p1068345104165622"></a><a name="p1068345104165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1687584380165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863319381165622"><a name="p1863319381165622"></a><a name="p1863319381165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p505885044165622"><a name="p505885044165622"></a><a name="p505885044165622"></a>Incorrect input.</p>
</td>
</tr>
</tbody>
</table>

## stime\(\)<a name="ga69f8377385b2eeee376712dc9f0e3f71"></a>

```
int stime (const [time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) * t)
```

**Description:**

Sets the system time.

**Parameters:**

<a name="table1823904418165622"></a>
<table><thead align="left"><tr id="row2061102968165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p664641235165622"><a name="p664641235165622"></a><a name="p664641235165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p973148260165622"><a name="p973148260165622"></a><a name="p973148260165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2024537335165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1251692982165622p0"><a name="entry1251692982165622p0"></a><a name="entry1251692982165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1614448923165622p0"><a name="entry1614448923165622p0"></a><a name="entry1614448923165622p0"></a>Indicates the pointer to the number of seconds to set.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table2047411807165622"></a>
<table><thead align="left"><tr id="row1992717658165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1890687696165622"><a name="p1890687696165622"></a><a name="p1890687696165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1379472332165622"><a name="p1379472332165622"></a><a name="p1379472332165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row629016337165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41856196165622"><a name="p41856196165622"></a><a name="p41856196165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2032361076165622"><a name="p2032361076165622"></a><a name="p2032361076165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## strftime\(\)<a name="gab94643a711fc91727b668553d4a8806b"></a>

```
size_t strftime (char *restrict s, size_t n, const char *restrict f, const struct [tm](tm.md) *restrict tm )
```

**Description:**

Converts the broken-down time in the  [tm](tm.md)  structure to a string in the required format.

**Parameters:**

<a name="table862764736165622"></a>
<table><thead align="left"><tr id="row2027788557165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2118552927165622"><a name="p2118552927165622"></a><a name="p2118552927165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1623143710165622"><a name="p1623143710165622"></a><a name="p1623143710165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row831975915165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry672675074165622p0"><a name="entry672675074165622p0"></a><a name="entry672675074165622p0"></a>s</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1970616451165622p0"><a name="entry1970616451165622p0"></a><a name="entry1970616451165622p0"></a>Indicates the pointer to the string.</p>
</td>
</tr>
<tr id="row439557413165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1540451833165622p0"><a name="entry1540451833165622p0"></a><a name="entry1540451833165622p0"></a>n</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry549601350165622p0"><a name="entry549601350165622p0"></a><a name="entry549601350165622p0"></a>Indicates the size of the buffer for storing the string.</p>
</td>
</tr>
<tr id="row1928639569165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry311548104165622p0"><a name="entry311548104165622p0"></a><a name="entry311548104165622p0"></a>f</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1473574197165622p0"><a name="entry1473574197165622p0"></a><a name="entry1473574197165622p0"></a>Indicates the pointer to the required format.</p>
</td>
</tr>
<tr id="row471747320165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry655619533165622p0"><a name="entry655619533165622p0"></a><a name="entry655619533165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2068493971165622p0"><a name="entry2068493971165622p0"></a><a name="entry2068493971165622p0"></a>Indicates the pointer to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes in the string if the conversion is successful; returns  **0**  otherwise.

## strftime\_l\(\)<a name="ga74c011f36d0ad959f0312dec8a5c8dc8"></a>

```
size_t strftime_l (char *__restrict s, size_t n, const char *__restrict f, const struct [tm](tm.md) *__restrict tm, locale_t loc )
```

**Description:**

Converts the broken-down time in the  [tm](tm.md)  structure to a string in a specified programming language and format.

**Parameters:**

<a name="table518793083165622"></a>
<table><thead align="left"><tr id="row1802173329165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p224064310165622"><a name="p224064310165622"></a><a name="p224064310165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1687891148165622"><a name="p1687891148165622"></a><a name="p1687891148165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1417112274165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1765261788165622p0"><a name="entry1765261788165622p0"></a><a name="entry1765261788165622p0"></a>s</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1971776909165622p0"><a name="entry1971776909165622p0"></a><a name="entry1971776909165622p0"></a>Indicates the pointer to the string.</p>
</td>
</tr>
<tr id="row1294345137165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1987834634165622p0"><a name="entry1987834634165622p0"></a><a name="entry1987834634165622p0"></a>n</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1862307026165622p0"><a name="entry1862307026165622p0"></a><a name="entry1862307026165622p0"></a>Indicates the size of the buffer for storing the string.</p>
</td>
</tr>
<tr id="row982340585165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry308341663165622p0"><a name="entry308341663165622p0"></a><a name="entry308341663165622p0"></a>f</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1376289609165622p0"><a name="entry1376289609165622p0"></a><a name="entry1376289609165622p0"></a>Indicates the pointer to the required format.</p>
</td>
</tr>
<tr id="row400801583165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry33792949165622p0"><a name="entry33792949165622p0"></a><a name="entry33792949165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1109189981165622p0"><a name="entry1109189981165622p0"></a><a name="entry1109189981165622p0"></a>Indicates the pointer to the broken-down time in the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
<tr id="row1959199881165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1251381692165622p0"><a name="entry1251381692165622p0"></a><a name="entry1251381692165622p0"></a>loc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1989934353165622p0"><a name="entry1989934353165622p0"></a><a name="entry1989934353165622p0"></a>Indicates the required programming language. Currently, only C programming language is supported.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of bytes in the string if the conversion is successful; returns  **0**  otherwise.

## strptime\(\)<a name="ga8454b83c5b4fb93a9dcdd72ab586de22"></a>

```
char* strptime (const char * s, const char * format, struct [tm](tm.md) * tm )
```

**Description:**

Converts a time string to the broken-down time in the  [tm](tm.md)  structure.

This function parses the input string  **s**  based on  **format**  and stores the result in the  [tm](tm.md)  structure.

**Parameters:**

<a name="table22746527165622"></a>
<table><thead align="left"><tr id="row1198892650165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1791762946165622"><a name="p1791762946165622"></a><a name="p1791762946165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p998796389165622"><a name="p998796389165622"></a><a name="p998796389165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1063559872165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1207372301165622p0"><a name="entry1207372301165622p0"></a><a name="entry1207372301165622p0"></a>s</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry540854624165622p0"><a name="entry540854624165622p0"></a><a name="entry540854624165622p0"></a>Indicates the pointer to the string that contains only time data.</p>
</td>
</tr>
<tr id="row1158471456165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry615239730165622p0"><a name="entry615239730165622p0"></a><a name="entry615239730165622p0"></a>format</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2025619325165622p0"><a name="entry2025619325165622p0"></a><a name="entry2025619325165622p0"></a>Indicates the pointer to the required format.</p>
</td>
</tr>
<tr id="row557464458165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry272756665165622p0"><a name="entry272756665165622p0"></a><a name="entry272756665165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry36331599165622p0"><a name="entry36331599165622p0"></a><a name="entry36331599165622p0"></a>Indicates the pointer to the <a href="tm.md">tm</a> structure.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the position to which the string has been processed \(the next character to be processed\) upon the conversion completion if the operation is successful; returns  **NULL**  otherwise.

## time\(\)<a name="gae7841e681c8c9d59818568d39553642c"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) time ([time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) * t)
```

**Description:**

Obtains the time.

The time obtained is the total number of seconds elapsed since January 1, 1970 00:00:00 \(UTC\).

**Parameters:**

<a name="table522680516165622"></a>
<table><thead align="left"><tr id="row161443976165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2137581139165622"><a name="p2137581139165622"></a><a name="p2137581139165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p367091573165622"><a name="p367091573165622"></a><a name="p367091573165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row373431441165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry164094939165622p0"><a name="entry164094939165622p0"></a><a name="entry164094939165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1052629173165622p0"><a name="entry1052629173165622p0"></a><a name="entry1052629173165622p0"></a>Indicates the pointer to the number of seconds. You can also pass <strong id="b242358420165622"><a name="b242358420165622"></a><a name="b242358420165622"></a>NULL</strong> to use the return value.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of seconds.

## timegm\(\)<a name="ga4fd5240e99b2a9bf19bc0fe39f6ffc07"></a>

```
[time_t](UTILS.md#ga138ad62ac7715e7161bf6223e35d8323) timegm (struct [tm](tm.md) * tm)
```

**Description:**

Converts the broken-down time in the  [tm](tm.md)  structure to the number of seconds.

**Parameters:**

<a name="table1175377860165622"></a>
<table><thead align="left"><tr id="row822309734165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1516841489165622"><a name="p1516841489165622"></a><a name="p1516841489165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1056499161165622"><a name="p1056499161165622"></a><a name="p1056499161165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row286813661165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1756861450165622p0"><a name="entry1756861450165622p0"></a><a name="entry1756861450165622p0"></a>tm</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry497554415165622p0"><a name="entry497554415165622p0"></a><a name="entry497554415165622p0"></a>Indicates the pointer to the broken-down time in the <a href="tm.md">tm</a> structure to convert.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of seconds if the operation is successful; returns  **NULL**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table1019227905165622"></a>
<table><thead align="left"><tr id="row567355460165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1777109726165622"><a name="p1777109726165622"></a><a name="p1777109726165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1001370494165622"><a name="p1001370494165622"></a><a name="p1001370494165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1118673700165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897387380165622"><a name="p1897387380165622"></a><a name="p1897387380165622"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2119719296165622"><a name="p2119719296165622"></a><a name="p2119719296165622"></a>The input parameter is too long.</p>
</td>
</tr>
</tbody>
</table>

## timer\_create\(\)<a name="gaf7dce9c851a2e1a65aaf818b95487431"></a>

```
int timer_create ([clockid_t](UTILS.md#ga391e4a62662054e5d3e1e071b8e54329) id, struct [sigevent](sigevent.md) *__restrict evp, [timer_t](UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a) *__restrict t )
```

**Description:**

Creates a timer for the process.

**Parameters:**

<a name="table773769738165622"></a>
<table><thead align="left"><tr id="row1602006490165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1518553119165622"><a name="p1518553119165622"></a><a name="p1518553119165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p787553745165622"><a name="p787553745165622"></a><a name="p787553745165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row396378169165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry832161929165622p0"><a name="entry832161929165622p0"></a><a name="entry832161929165622p0"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1251553058165622p0"><a name="entry1251553058165622p0"></a><a name="entry1251553058165622p0"></a>Indicates the clock ID. Only <a href="TIME.md#ga922ce1ae64374c9410c8a999e25e82af">CLOCK_REALTIME</a> is supported.</p>
</td>
</tr>
<tr id="row8672480165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1519954917165622p0"><a name="entry1519954917165622p0"></a><a name="entry1519954917165622p0"></a>evp</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1193947275165622p0"><a name="entry1193947275165622p0"></a><a name="entry1193947275165622p0"></a>Indicates the pointer to the asynchronous notification signal and action, which can be <strong id="b2062747417165622"><a name="b2062747417165622"></a><a name="b2062747417165622"></a>NULL</strong>.</p>
</td>
</tr>
<tr id="row2054536495165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry408729271165622p0"><a name="entry408729271165622p0"></a><a name="entry408729271165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1213207454165622p0"><a name="entry1213207454165622p0"></a><a name="entry1213207454165622p0"></a>Indicates the pointer to the timer ID.</p>
</td>
</tr>
</tbody>
</table>

**Attention:**

**sigev\_notify**  in the  **sigevent**  structure must be  [SIGEV\_SIGNAL](IPC.md#ga06d5881eeb84e6ac35f5b801c380dbb6).

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table85490655165622"></a>
<table><thead align="left"><tr id="row1025449922165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p321666383165622"><a name="p321666383165622"></a><a name="p321666383165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p171217025165622"><a name="p171217025165622"></a><a name="p171217025165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row437242082165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291786639165622"><a name="p1291786639165622"></a><a name="p1291786639165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519808227165622"><a name="p519808227165622"></a><a name="p519808227165622"></a>Invalid input.</p>
</td>
</tr>
<tr id="row1877410167165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771003074165622"><a name="p1771003074165622"></a><a name="p1771003074165622"></a>ENOTSUP</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490953955165622"><a name="p1490953955165622"></a><a name="p1490953955165622"></a>The value of <strong id="b1814160640165622"><a name="b1814160640165622"></a><a name="b1814160640165622"></a>evp</strong> is not <strong id="b72647120165622"><a name="b72647120165622"></a><a name="b72647120165622"></a>NULL</strong> and <strong id="b1219099201165622"><a name="b1219099201165622"></a><a name="b1219099201165622"></a>sigev_notify</strong> is not <strong id="b125767218165622"><a name="b125767218165622"></a><a name="b125767218165622"></a>SIGEV_SIGNAL</strong>.</p>
</td>
</tr>
</tbody>
</table>

## timer\_delete\(\)<a name="ga61fa078bdadbd957cfcdfb12d0592ac1"></a>

```
int timer_delete ([timer_t](UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a) t)
```

**Description:**

Deletes a timer for the process.

**Parameters:**

<a name="table1940552938165622"></a>
<table><thead align="left"><tr id="row1256312965165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2074831297165622"><a name="p2074831297165622"></a><a name="p2074831297165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1266085081165622"><a name="p1266085081165622"></a><a name="p1266085081165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row596349333165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1609019673165622p0"><a name="entry1609019673165622p0"></a><a name="entry1609019673165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1030093564165622p0"><a name="entry1030093564165622p0"></a><a name="entry1030093564165622p0"></a>Indicates the ID of the timer to delete.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table1112669090165622"></a>
<table><thead align="left"><tr id="row317450905165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1304228199165622"><a name="p1304228199165622"></a><a name="p1304228199165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p809860217165622"><a name="p809860217165622"></a><a name="p809860217165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1139250000165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p108691529165622"><a name="p108691529165622"></a><a name="p108691529165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572068204165622"><a name="p1572068204165622"></a><a name="p1572068204165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## timer\_getoverrun\(\)<a name="ga6ecdedfd7f417a3d93aa7a18ff0ac582"></a>

```
int timer_getoverrun ([timer_t](UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a) t)
```

**Description:**

Obtains the number of times that a timer overruns.

**Parameters:**

<a name="table1975081335165622"></a>
<table><thead align="left"><tr id="row1818998972165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1673494878165622"><a name="p1673494878165622"></a><a name="p1673494878165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1371022788165622"><a name="p1371022788165622"></a><a name="p1371022788165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7832310165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry284234041165622p0"><a name="entry284234041165622p0"></a><a name="entry284234041165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry456939362165622p0"><a name="entry456939362165622p0"></a><a name="entry456939362165622p0"></a>Indicates the ID of the timer to obtain.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the number of times if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table1603121504165622"></a>
<table><thead align="left"><tr id="row2086844244165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1531738348165622"><a name="p1531738348165622"></a><a name="p1531738348165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1839069566165622"><a name="p1839069566165622"></a><a name="p1839069566165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row853643032165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377813155165622"><a name="p377813155165622"></a><a name="p377813155165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32401674165622"><a name="p32401674165622"></a><a name="p32401674165622"></a>Invalid input.</p>
</td>
</tr>
</tbody>
</table>

## timer\_gettime\(\)<a name="ga8f65c6a88588c951e0b11629e56714a4"></a>

```
int timer_gettime ([timer_t](UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a) t, struct [itimerspec](itimerspec.md) * tspec )
```

**Description:**

Obtains a timer of the process.

**Parameters:**

<a name="table1622598150165622"></a>
<table><thead align="left"><tr id="row1639759258165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1654076743165622"><a name="p1654076743165622"></a><a name="p1654076743165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1282470923165622"><a name="p1282470923165622"></a><a name="p1282470923165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row850260620165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2042005630165622p0"><a name="entry2042005630165622p0"></a><a name="entry2042005630165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1010427056165622p0"><a name="entry1010427056165622p0"></a><a name="entry1010427056165622p0"></a>Indicates the ID of the timer to obtain.</p>
</td>
</tr>
<tr id="row753256708165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry184363232165622p0"><a name="entry184363232165622p0"></a><a name="entry184363232165622p0"></a>tspec</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1912984160165622p0"><a name="entry1912984160165622p0"></a><a name="entry1912984160165622p0"></a>Indicates the pointer to the timer duration and interval.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table1794448852165622"></a>
<table><thead align="left"><tr id="row987699793165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p353657696165622"><a name="p353657696165622"></a><a name="p353657696165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p63526015165622"><a name="p63526015165622"></a><a name="p63526015165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row195515398165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979726820165622"><a name="p1979726820165622"></a><a name="p1979726820165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1728536576165622"><a name="p1728536576165622"></a><a name="p1728536576165622"></a>Incorrect parameter or timer operation failure.</p>
</td>
</tr>
</tbody>
</table>

## timer\_settime\(\)<a name="gade973e87fffe05aed7f1e97c1d15178e"></a>

```
int timer_settime ([timer_t](UTILS.md#gacea9f425ec91056458fd7cd0b0923d1a) t, int flags, const struct [itimerspec](itimerspec.md) *__restrict val, struct [itimerspec](itimerspec.md) *__restrict old )
```

**Description:**

Sets a timer for the process.

**Parameters:**

<a name="table1166816701165622"></a>
<table><thead align="left"><tr id="row2004456634165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p806547162165622"><a name="p806547162165622"></a><a name="p806547162165622"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1043979142165622"><a name="p1043979142165622"></a><a name="p1043979142165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row518892572165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1853399468165622p0"><a name="entry1853399468165622p0"></a><a name="entry1853399468165622p0"></a>t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry576906985165622p0"><a name="entry576906985165622p0"></a><a name="entry576906985165622p0"></a>Indicates the ID of the timer to set.</p>
</td>
</tr>
<tr id="row2051186091165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry262577798165622p0"><a name="entry262577798165622p0"></a><a name="entry262577798165622p0"></a>flags</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry175500051165622p0"><a name="entry175500051165622p0"></a><a name="entry175500051165622p0"></a>Indicates the type of the timer to set. This parameter is not supported and must be set to <strong id="b1599959181165622"><a name="b1599959181165622"></a><a name="b1599959181165622"></a>0</strong>.</p>
</td>
</tr>
<tr id="row860796789165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry128147593165622p0"><a name="entry128147593165622p0"></a><a name="entry128147593165622p0"></a>val</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1625894980165622p0"><a name="entry1625894980165622p0"></a><a name="entry1625894980165622p0"></a>Indicates the pointer to the timer duration and interval to set.</p>
</td>
</tr>
<tr id="row987843913165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry844059504165622p0"><a name="entry844059504165622p0"></a><a name="entry844059504165622p0"></a>old</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1796606065165622p0"><a name="entry1796606065165622p0"></a><a name="entry1796606065165622p0"></a>Indicates the pointer to the timer duration and interval before the current setting.</p>
</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns  **-1**  and sets  **errno**  to a value in the following table if the operation fails.

<a name="table910363468165622"></a>
<table><thead align="left"><tr id="row1699037059165622"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p424881658165622"><a name="p424881658165622"></a><a name="p424881658165622"></a>errno</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p601567103165622"><a name="p601567103165622"></a><a name="p601567103165622"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1135707078165622"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624996052165622"><a name="p624996052165622"></a><a name="p624996052165622"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1741962256165622"><a name="p1741962256165622"></a><a name="p1741962256165622"></a>Incorrect parameter or timer operation failure.</p>
</td>
</tr>
</tbody>
</table>

