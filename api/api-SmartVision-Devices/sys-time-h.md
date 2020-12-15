# sys/time.h<a name="ZH-CN_TOPIC_0000001057751471"></a>

-   [Overview](#section1315130326165629)
-   [Summary](#section772338641165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1315130326165629"></a>

**Related Modules:**

[TIME](TIME.md)

**Description:**

Provides structures and functions related to the system time. 

You can read and write the system time and set timers.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section772338641165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table730523996165629"></a>
<table><thead align="left"><tr id="row205134357165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1611545160165629"><a name="p1611545160165629"></a><a name="p1611545160165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p26076091165629"><a name="p26076091165629"></a><a name="p26076091165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2121148146165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49244304165629"><a name="p49244304165629"></a><a name="p49244304165629"></a><a href="timeval.md">timeval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p638798325165629"><a name="p638798325165629"></a><a name="p638798325165629"></a>Describes a period of time, accurate to microseconds. </p>
</td>
</tr>
<tr id="row507734120165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1967045843165629"><a name="p1967045843165629"></a><a name="p1967045843165629"></a><a href="timespec.md">timespec</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847497478165629"><a name="p847497478165629"></a><a name="p847497478165629"></a>Describes a period of time, accurate to nanoseconds. </p>
</td>
</tr>
<tr id="row510054114165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504494625165629"><a name="p1504494625165629"></a><a name="p1504494625165629"></a><a href="itimerval.md">itimerval</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954716144165629"><a name="p954716144165629"></a><a name="p954716144165629"></a>Describes a timer. </p>
</td>
</tr>
<tr id="row1589961529165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943221558165629"><a name="p1943221558165629"></a><a name="p1943221558165629"></a><a href="timezone.md">timezone</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324635623165629"><a name="p1324635623165629"></a><a name="p1324635623165629"></a>Describes a time zone. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table974131378165629"></a>
<table><thead align="left"><tr id="row410581841165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1915645611165629"><a name="p1915645611165629"></a><a name="p1915645611165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1532890144165629"><a name="p1532890144165629"></a><a name="p1532890144165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1797368984165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p958268106165629"><a name="p958268106165629"></a><a name="p958268106165629"></a><a href="TIME.md#gace5b149f36c4133045c32d756e2b9a82">ITIMER_REAL</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528871115165629"><a name="p528871115165629"></a><a name="p528871115165629"></a>Defines the timer that runs in real time. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table18314629165629"></a>
<table><thead align="left"><tr id="row2034902718165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p514383938165629"><a name="p514383938165629"></a><a name="p514383938165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1020792994165629"><a name="p1020792994165629"></a><a name="p1020792994165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1889531211165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868640227165629"><a name="p868640227165629"></a><a name="p868640227165629"></a><a href="TIME.md#ga5ef4514eca25b6c6b73c5a54b8bc9e2b">gettimeofday</a> (struct <a href="timeval.md">timeval</a> *__restrict value, void *__restrict ovalue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083611428165629"><a name="p1083611428165629"></a><a name="p1083611428165629"></a>int </p>
<p id="p1465967243165629"><a name="p1465967243165629"></a><a name="p1465967243165629"></a>Obtains the system time and time zone. </p>
</td>
</tr>
<tr id="row54797531165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886045627165629"><a name="p886045627165629"></a><a name="p886045627165629"></a><a href="TIME.md#ga87cde44d5a31b1524f925d980c959985">getitimer</a> (int w, struct <a href="itimerval.md">itimerval</a> *old)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1293190200165629"><a name="p1293190200165629"></a><a name="p1293190200165629"></a>int </p>
<p id="p816689942165629"><a name="p816689942165629"></a><a name="p816689942165629"></a>Obtains the value of an intermittent timer. </p>
</td>
</tr>
<tr id="row1739374909165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p824539167165629"><a name="p824539167165629"></a><a name="p824539167165629"></a><a href="TIME.md#ga81245d77d2f570933cc81f13a101bff8">setitimer</a> (int w, const struct <a href="itimerval.md">itimerval</a> *__restrict value, struct <a href="itimerval.md">itimerval</a> *__restrict ovalue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1458784560165629"><a name="p1458784560165629"></a><a name="p1458784560165629"></a>int </p>
<p id="p28700723165629"><a name="p28700723165629"></a><a name="p28700723165629"></a>Sets the value for a timer. </p>
</td>
</tr>
<tr id="row352221181165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1311346646165629"><a name="p1311346646165629"></a><a name="p1311346646165629"></a><a href="TIME.md#ga6e6617fc349ed4777425d667ff250fa7">settimeofday</a> (const struct <a href="timeval.md">timeval</a> *tv, const struct <a href="timezone.md">timezone</a> *tz)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1951076145165629"><a name="p1951076145165629"></a><a name="p1951076145165629"></a>int </p>
<p id="p480806777165629"><a name="p480806777165629"></a><a name="p480806777165629"></a>Sets the system time and time zone. </p>
</td>
</tr>
</tbody>
</table>

