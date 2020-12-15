# DriverUtils<a name="EN-US_TOPIC_0000001055518036"></a>

-   [Overview](#section955198948165623)
-   [Summary](#section1440107053165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1185566655165623)
-   [Macro Definition](#section2134126864165623)
-   [CONTAINER\_OF](#ga818b9cca761fe7bc18e4e417da772976)
-   [DLIST\_FIRST\_ENTRY](#ga203de9c01fefc8bbbae746685794cfcc)
-   [DLIST\_FOR\_EACH\_ENTRY](#ga2b53b2bcf35b8cfb32e429cacbcc0a8d)
-   [DLIST\_FOR\_EACH\_ENTRY\_SAFE](#ga8e6f49c1fed85c031f29e8acce377ea0)
-   [DLIST\_LAST\_ENTRY](#ga25ac08cc864bd59050f7e2ca77df1f23)
-   [HDF\_LOGD](#gaa0411582f697619cdb045ae61ac42539)
-   [HDF\_LOGE](#gaacd0eb778948960a7f97af155287ce8c)
-   [HDF\_LOGI](#ga369d56841d17e6908fc6885fcb814b80)
-   [HDF\_LOGV](#ga4abebfca1aaeb8125f85800425caf304)
-   [HDF\_LOGW](#ga72f232dade88b85aff2d8c0e42b82df0)
-   [LOG\_TAG\_MARK\_EXTEND](#ga7e862bda9f0b95d1628f6f62598f1f42)
-   [Typedef](#section1521632851165623)
-   [HdfWorkFunc](#ga30665d61b03fae4a2ebc778c3d775ce5)
-   [Enumeration Type](#section758644115165623)
-   [anonymous enum](#gac205be2172292384dd687b5471a87edd)
-   [HDF\_STATUS](#ga7e01536ecbe9b17563dd3fe256202a67)
-   [Function](#section636459406165623)
-   [DListHeadInit\(\)](#ga0a86a18ad591f485663834799dd38dea)
-   [DListInsertHead\(\)](#ga60e796c868630dd403ef4fdcc60c12e8)
-   [DListInsertTail\(\)](#gaa1d386162f8f6401fe8ac6d70d237517)
-   [DListIsEmpty\(\)](#ga9b4053294ad63f0bdacb4841a14ba208)
-   [DListMerge\(\)](#gac4acad10a7c49cc4b2d773aedbfa1e11)
-   [DListRemove\(\)](#ga42d23fa1f55097bae91664c5e4a78e1e)
-   [HdfAddDelayedWork\(\)](#gaef781ccc1579db3070745088da47b2c5)
-   [HdfAddWork\(\)](#ga82cc68d656aa17317634b07d49dae160)
-   [HdfCancelDelayedWorkSync\(\)](#gad53e46938809200db3caafdc85decc5a)
-   [HdfCancelWorkSync\(\)](#gaab300487bdb9f3496bb823c657275dd3)
-   [HdfDelayedWorkDestroy\(\)](#gaaaced5c0365d1a1232167b738f08b5ce)
-   [HdfDelayedWorkInit\(\)](#ga55bf669dc6740c65e4d45a4f641db2f1)
-   [HdfWorkBusy\(\)](#ga37595ed36b8ce7be84c914aebfd99d00)
-   [HdfWorkDestroy\(\)](#gae6166caaf1b114e17834c50414b2d52e)
-   [HdfWorkInit\(\)](#gad171adc8eda320fd01049a2b87ea62fb)
-   [HdfWorkQueueDestroy\(\)](#ga04ec328639aefd71683175e4c214fb80)
-   [HdfWorkQueueInit\(\)](#gad7afae1dc691818c513094c873decabd)

## **Overview**<a name="section955198948165623"></a>

**Description:**

Defines common macros and interfaces of the driver module. 

This module provides interfaces such as log printing, doubly linked list operations, and work queues.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1440107053165623"></a>

## Files<a name="files"></a>

<a name="table476546687165623"></a>
<table><thead align="left"><tr id="row1029313017165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p575715792165623"><a name="p575715792165623"></a><a name="p575715792165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p906472895165623"><a name="p906472895165623"></a><a name="p906472895165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1008655046165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1455719018165623"><a name="p1455719018165623"></a><a name="p1455719018165623"></a><a href="hdf_base-h.md">hdf_base.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250395734165623"><a name="p250395734165623"></a><a name="p250395734165623"></a>Declares driver common types, including the enumerated values returned by the function and the macro for obtaining the array size. </p>
</td>
</tr>
<tr id="row1431990836165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p259293870165623"><a name="p259293870165623"></a><a name="p259293870165623"></a><a href="hdf_dlist-h.md">hdf_dlist.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476543444165623"><a name="p476543444165623"></a><a name="p476543444165623"></a>Declares doubly linked list structures and interfaces. </p>
</td>
</tr>
<tr id="row1918003666165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p222976164165623"><a name="p222976164165623"></a><a name="p222976164165623"></a><a href="hdf_log-h.md">hdf_log.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1701495186165623"><a name="p1701495186165623"></a><a name="p1701495186165623"></a>Declares log printing functions of the driver module. This module provides functions for printing logs at the verbose, debug, information, warning, and error levels. </p>
</td>
</tr>
<tr id="row1801494437165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862781165165623"><a name="p862781165165623"></a><a name="p862781165165623"></a><a href="hdf_workqueue-h.md">hdf_workqueue.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166672169165623"><a name="p1166672169165623"></a><a name="p1166672169165623"></a>Declares work queue structures and interfaces. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table761272803165623"></a>
<table><thead align="left"><tr id="row1049583100165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1995329391165623"><a name="p1995329391165623"></a><a name="p1995329391165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p417227401165623"><a name="p417227401165623"></a><a name="p417227401165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2123985320165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997229622165623"><a name="p1997229622165623"></a><a name="p1997229622165623"></a><a href="dlisthead.md">DListHead</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2004442375165623"><a name="p2004442375165623"></a><a name="p2004442375165623"></a>Describes a doubly linked list. </p>
</td>
</tr>
<tr id="row1274413970165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523337850165623"><a name="p1523337850165623"></a><a name="p1523337850165623"></a><a href="hdfwork.md">HdfWork</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544071360165623"><a name="p1544071360165623"></a><a name="p1544071360165623"></a>Describes a work item and a delayed work item. This structure defines the work and delayed work items, and then calls the initialization function <a href="driverutils.md#gad171adc8eda320fd01049a2b87ea62fb">HdfWorkInit</a> or <a href="driverutils.md#ga55bf669dc6740c65e4d45a4f641db2f1">HdfDelayedWorkInit</a> to perform initialization. The <strong id="b696621352165623"><a name="b696621352165623"></a><a name="b696621352165623"></a><a href="driverutils.md#ga82cc68d656aa17317634b07d49dae160">HdfAddWork()</a></strong> function is to add a work item to a work queue immediately, and the <strong id="b89755323165623"><a name="b89755323165623"></a><a name="b89755323165623"></a><a href="driverutils.md#gaef781ccc1579db3070745088da47b2c5">HdfAddDelayedWork()</a></strong> function is to add a work item to a work queue after the configured delayed time. </p>
</td>
</tr>
<tr id="row1717455025165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34099543165623"><a name="p34099543165623"></a><a name="p34099543165623"></a><a href="hdfworkqueue.md">HdfWorkQueue</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758510417165623"><a name="p758510417165623"></a><a name="p758510417165623"></a>Describes a work queue. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1288794269165623"></a>
<table><thead align="left"><tr id="row395535621165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1711476038165623"><a name="p1711476038165623"></a><a name="p1711476038165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p855001024165623"><a name="p855001024165623"></a><a name="p855001024165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2132932438165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996383488165623"><a name="p996383488165623"></a><a name="p996383488165623"></a><em id="ga4dc11d1abeb6b0d2a40e20a553f491f4"><a name="ga4dc11d1abeb6b0d2a40e20a553f491f4"></a><a name="ga4dc11d1abeb6b0d2a40e20a553f491f4"></a></em>HDF_WAIT_FOREVER    0xFFFFFFFF</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p601800025165623"><a name="p601800025165623"></a><a name="p601800025165623"></a>Indicates that the function keeps waiting to obtain a semaphore or mutex. </p>
</td>
</tr>
<tr id="row222029721165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264697637165623"><a name="p1264697637165623"></a><a name="p1264697637165623"></a><em id="ga5255c6a1e2a87df682c1c0ed36fc1b2f"><a name="ga5255c6a1e2a87df682c1c0ed36fc1b2f"></a><a name="ga5255c6a1e2a87df682c1c0ed36fc1b2f"></a></em>HDF_ARRAY_SIZE (a)   (sizeof(a) / sizeof((a)[0]))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920428666165623"><a name="p920428666165623"></a><a name="p920428666165623"></a>Defines the array size. </p>
</td>
</tr>
<tr id="row1301752767165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1693350876165623"><a name="p1693350876165623"></a><a name="p1693350876165623"></a><em id="ga8f2520dfc5a6cd0bac044845318b020c"><a name="ga8f2520dfc5a6cd0bac044845318b020c"></a><a name="ga8f2520dfc5a6cd0bac044845318b020c"></a></em>HDF_KILO_UNIT    1000</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400011919165623"><a name="p400011919165623"></a><a name="p400011919165623"></a>Defines a time conversion unit, for example, the unit for converting from second to millisecond. </p>
</td>
</tr>
<tr id="row326332385165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p958685644165623"><a name="p958685644165623"></a><a name="p958685644165623"></a><a href="driverutils.md#ga818b9cca761fe7bc18e4e417da772976">CONTAINER_OF</a>(ptr, type, member)   (type *)((char *)(ptr) - (char *)&amp;((type *)0)-&gt;member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p936141196165623"><a name="p936141196165623"></a><a name="p936141196165623"></a>Obtains the address of a structure variable from its member address. </p>
</td>
</tr>
<tr id="row2109620766165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1232825929165623"><a name="p1232825929165623"></a><a name="p1232825929165623"></a><a href="driverutils.md#ga203de9c01fefc8bbbae746685794cfcc">DLIST_FIRST_ENTRY</a>(ptr, type, member)   <a href="driverutils.md#ga818b9cca761fe7bc18e4e417da772976">CONTAINER_OF</a>((ptr)-&gt;next, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608834436165623"><a name="p608834436165623"></a><a name="p608834436165623"></a>Obtains the first node of a doubly linked list. </p>
</td>
</tr>
<tr id="row787355082165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200138417165623"><a name="p1200138417165623"></a><a name="p1200138417165623"></a><a href="driverutils.md#ga25ac08cc864bd59050f7e2ca77df1f23">DLIST_LAST_ENTRY</a>(ptr, type, member)   <a href="driverutils.md#ga818b9cca761fe7bc18e4e417da772976">CONTAINER_OF</a>((ptr)-&gt;prev, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1214599976165623"><a name="p1214599976165623"></a><a name="p1214599976165623"></a>Obtains the last node of a doubly linked list. </p>
</td>
</tr>
<tr id="row656990027165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060415450165623"><a name="p1060415450165623"></a><a name="p1060415450165623"></a><a href="driverutils.md#ga2b53b2bcf35b8cfb32e429cacbcc0a8d">DLIST_FOR_EACH_ENTRY</a>(pos, head, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830387134165623"><a name="p1830387134165623"></a><a name="p1830387134165623"></a>Traverses all nodes in a doubly linked list. </p>
</td>
</tr>
<tr id="row470933284165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p246484950165623"><a name="p246484950165623"></a><a name="p246484950165623"></a><a href="driverutils.md#ga8e6f49c1fed85c031f29e8acce377ea0">DLIST_FOR_EACH_ENTRY_SAFE</a>(pos, tmp, head, type, member)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1387998048165623"><a name="p1387998048165623"></a><a name="p1387998048165623"></a>Traverses all nodes in a doubly linked list. This function is used to delete the nodes pointed to by <strong id="b521435680165623"><a name="b521435680165623"></a><a name="b521435680165623"></a>pos</strong> during traversal. </p>
</td>
</tr>
<tr id="row1315163624165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218036174165623"><a name="p1218036174165623"></a><a name="p1218036174165623"></a><a href="driverutils.md#ga7e862bda9f0b95d1628f6f62598f1f42">LOG_TAG_MARK_EXTEND</a>(HDF_TAG)   #HDF_TAG</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
<tr id="row1856489688165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1304755707165623"><a name="p1304755707165623"></a><a name="p1304755707165623"></a><a href="driverutils.md#ga4abebfca1aaeb8125f85800425caf304">HDF_LOGV</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:V/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579337710165623"><a name="p1579337710165623"></a><a name="p1579337710165623"></a>Prints logs at the verbose level. </p>
</td>
</tr>
<tr id="row616026819165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1794840605165623"><a name="p1794840605165623"></a><a name="p1794840605165623"></a><a href="driverutils.md#gaa0411582f697619cdb045ae61ac42539">HDF_LOGD</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:D/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p800075571165623"><a name="p800075571165623"></a><a name="p800075571165623"></a>Prints logs at the debug level. </p>
</td>
</tr>
<tr id="row21451086165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379092774165623"><a name="p379092774165623"></a><a name="p379092774165623"></a><a href="driverutils.md#ga369d56841d17e6908fc6885fcb814b80">HDF_LOGI</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:I/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185697003165623"><a name="p185697003165623"></a><a name="p185697003165623"></a>Prints logs at the information level. </p>
</td>
</tr>
<tr id="row920609166165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p494131360165623"><a name="p494131360165623"></a><a name="p494131360165623"></a><a href="driverutils.md#ga72f232dade88b85aff2d8c0e42b82df0">HDF_LOGW</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:W/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2046229946165623"><a name="p2046229946165623"></a><a name="p2046229946165623"></a>Prints logs at the warning level. </p>
</td>
</tr>
<tr id="row1094005030165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1814462532165623"><a name="p1814462532165623"></a><a name="p1814462532165623"></a><a href="driverutils.md#gaacd0eb778948960a7f97af155287ce8c">HDF_LOGE</a>(fmt, arg...)   <a href="io.md#ga98631211a4a8aee62f572375d5b637be">printf</a>("[HDF:E/" LOG_TAG "]" fmt "\r\n", ##arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820934283165623"><a name="p820934283165623"></a><a name="p820934283165623"></a>Prints logs at the error level. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table2133591339165623"></a>
<table><thead align="left"><tr id="row790498175165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1619021292165623"><a name="p1619021292165623"></a><a name="p1619021292165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1379470940165623"><a name="p1379470940165623"></a><a name="p1379470940165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row980634719165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909536891165623"><a name="p909536891165623"></a><a name="p909536891165623"></a><a href="driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5">HdfWorkFunc</a>) (void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884802105165623"><a name="p884802105165623"></a><a name="p884802105165623"></a>typedef void(* </p>
<p id="p116009812165623"><a name="p116009812165623"></a><a name="p116009812165623"></a>Describes a work execution function type. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1413305689165623"></a>
<table><thead align="left"><tr id="row1288968344165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p603427586165623"><a name="p603427586165623"></a><a name="p603427586165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p946677219165623"><a name="p946677219165623"></a><a name="p946677219165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row755857636165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p901338561165623"><a name="p901338561165623"></a><a name="p901338561165623"></a><a href="driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67">HDF_STATUS</a> {   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a66cefc3d8cb74728358899034d8d141f">HDF_SUCCESS</a> = 0, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a454a8a08dd1a4b166b2aff6af90266d0">HDF_FAILURE</a> = -1, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67ac6e0c4313436d7222b7dc9bf21e092ed">HDF_ERR_NOT_SUPPORT</a> = -2, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a87e9e0ca4600bc8967556e668abf6718">HDF_ERR_INVALID_PARAM</a> = -3,   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a14a42b17e53bbd65b4f15d56df41ae70">HDF_ERR_INVALID_OBJECT</a> = -4, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a0ad904f070baaf23e6a4bf8fbdf928f5">HDF_ERR_MALLOC_FAIL</a> = -6, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a0c698c789d0dec0b054d5f1cf10003d7">HDF_ERR_TIMEOUT</a> = -7, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a77fd634e04dc131c2ca0435372c1f13b">HDF_ERR_THREAD_CREATE_FAIL</a> = -10,   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a44e8f39984cb2b4f7790b2ceab8b7670">HDF_ERR_QUEUE_FULL</a> = -15, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a9c98586b0a30928afdd3f8fee5083e9b">HDF_ERR_DEVICE_BUSY</a> = -16, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a79c1aa5fb70b16b6b62b9f92e06b76d8">HDF_ERR_IO</a> = -17, <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a140804bae8a12c1ae2f3bbb07dd942d9">HDF_ERR_BAD_FD</a> = -18,   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a0d6ae6ce941fe02f540dc38897e9aac6">HDF_BSP_ERR_OP</a> = HDF_BSP_ERR_NUM(-1), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a6005454a71463ece52e0aa518f5032c2">HDF_ERR_BSP_PLT_API_ERR</a> = HDF_BSP_ERR_NUM(-2), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a520a898768b87a190ead33e693196946">HDF_PAL_ERR_DEV_CREATE</a> = HDF_BSP_ERR_NUM(-3), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a0cd3b31917d5ebb591bcbc7bd1099d55">HDF_PAL_ERR_INNER</a> = HDF_BSP_ERR_NUM(-4),   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67ac7475bfa5f540b4324e551f5e7d7b2bd">HDF_DEV_ERR_NO_MEMORY</a> = HDF_DEV_ERR_NUM(-1), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67abde6ef565b453d3fc7734338db4db62d">HDF_DEV_ERR_NO_DEVICE</a> = HDF_DEV_ERR_NUM(-2), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a7d31e3b26c26010b0b1cf64596982005">HDF_DEV_ERR_NO_DEVICE_SERVICE</a> = HDF_DEV_ERR_NUM(-3), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a50fbd0d6fba63406ee384eb0c2ddaab5">HDF_DEV_ERR_DEV_INIT_FAIL</a> = HDF_DEV_ERR_NUM(-4),   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a318d4f725c1e85fb8c55acac7ed80112">HDF_DEV_ERR_PUBLISH_FAIL</a> = HDF_DEV_ERR_NUM(-5), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a676ff9d5ba402e93f44465d309cf4f94">HDF_DEV_ERR_ATTACHDEV_FAIL</a> = HDF_DEV_ERR_NUM(-6), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67a4cfc60685fac5ac921651fdaea845c1a">HDF_DEV_ERR_NODATA</a> = HDF_DEV_ERR_NUM(-7), <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67adbecc6285acfc5030abff4612b9cf916">HDF_DEV_ERR_NORANGE</a> = HDF_DEV_ERR_NUM(-8),   <a href="driverutils.md#gga7e01536ecbe9b17563dd3fe256202a67aace3a9148b526f670290e7829f3dd9df">HDF_DEV_ERR_OP</a> = HDF_DEV_ERR_NUM(-10) }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1373973739165623"><a name="p1373973739165623"></a><a name="p1373973739165623"></a>Enumerates HDF return value types. </p>
</td>
</tr>
<tr id="row2008065294165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1662023329165623"><a name="p1662023329165623"></a><a name="p1662023329165623"></a>{ <a href="driverutils.md#ggac205be2172292384dd687b5471a87edda75df1ca644f77f78bf3539e356f2e446">HDF_WORK_BUSY_PENDING</a> = 1 &lt;&lt; 0, <a href="driverutils.md#ggac205be2172292384dd687b5471a87edda56532f81e262cca4680e754627d6dc44">HDF_WORK_BUSY_RUNNING</a> = 1 &lt;&lt; 1 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898465754165623"><a name="p898465754165623"></a><a name="p898465754165623"></a>Enumerates statuses of a work item or a delayed work item. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1571976786165623"></a>
<table><thead align="left"><tr id="row262566989165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1964573810165623"><a name="p1964573810165623"></a><a name="p1964573810165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2055583374165623"><a name="p2055583374165623"></a><a name="p2055583374165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row990507591165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990110476165623"><a name="p990110476165623"></a><a name="p990110476165623"></a><a href="driverutils.md#ga0a86a18ad591f485663834799dd38dea">DListHeadInit</a> (struct <a href="dlisthead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654017378165623"><a name="p654017378165623"></a><a name="p654017378165623"></a>static void </p>
<p id="p314458625165623"><a name="p314458625165623"></a><a name="p314458625165623"></a>Initializes a doubly linked list. </p>
</td>
</tr>
<tr id="row1446999151165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633779433165623"><a name="p1633779433165623"></a><a name="p1633779433165623"></a><a href="driverutils.md#ga9b4053294ad63f0bdacb4841a14ba208">DListIsEmpty</a> (const struct <a href="dlisthead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1898778649165623"><a name="p1898778649165623"></a><a name="p1898778649165623"></a>static bool </p>
<p id="p1297596009165623"><a name="p1297596009165623"></a><a name="p1297596009165623"></a>Checks whether a doubly linked list is empty. </p>
</td>
</tr>
<tr id="row1446668968165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195298299165623"><a name="p195298299165623"></a><a name="p195298299165623"></a><a href="driverutils.md#ga42d23fa1f55097bae91664c5e4a78e1e">DListRemove</a> (struct <a href="dlisthead.md">DListHead</a> *<a href="entry.md">entry</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297460825165623"><a name="p1297460825165623"></a><a name="p1297460825165623"></a>static void </p>
<p id="p748489219165623"><a name="p748489219165623"></a><a name="p748489219165623"></a>Removes a node from a doubly linked list. </p>
</td>
</tr>
<tr id="row1350867553165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078676204165623"><a name="p2078676204165623"></a><a name="p2078676204165623"></a><a href="driverutils.md#ga60e796c868630dd403ef4fdcc60c12e8">DListInsertHead</a> (struct <a href="dlisthead.md">DListHead</a> *<a href="entry.md">entry</a>, struct <a href="dlisthead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267320862165623"><a name="p1267320862165623"></a><a name="p1267320862165623"></a>static void </p>
<p id="p687978407165623"><a name="p687978407165623"></a><a name="p687978407165623"></a>Inserts a node from the head of a doubly linked list. </p>
</td>
</tr>
<tr id="row1136186287165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1679891970165623"><a name="p1679891970165623"></a><a name="p1679891970165623"></a><a href="driverutils.md#gaa1d386162f8f6401fe8ac6d70d237517">DListInsertTail</a> (struct <a href="dlisthead.md">DListHead</a> *<a href="entry.md">entry</a>, struct <a href="dlisthead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p593352378165623"><a name="p593352378165623"></a><a name="p593352378165623"></a>static void </p>
<p id="p1663826441165623"><a name="p1663826441165623"></a><a name="p1663826441165623"></a>Inserts a node from the tail of a doubly linked list. </p>
</td>
</tr>
<tr id="row1664202130165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p859075472165623"><a name="p859075472165623"></a><a name="p859075472165623"></a><a href="driverutils.md#gac4acad10a7c49cc4b2d773aedbfa1e11">DListMerge</a> (struct <a href="dlisthead.md">DListHead</a> *list, struct <a href="dlisthead.md">DListHead</a> *head)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163308234165623"><a name="p163308234165623"></a><a name="p163308234165623"></a>static void </p>
<p id="p2039212265165623"><a name="p2039212265165623"></a><a name="p2039212265165623"></a>Merges two linked lists by adding the list specified by <strong id="b1855759797165623"><a name="b1855759797165623"></a><a name="b1855759797165623"></a>list</strong> to the head of the list specified by <strong id="b977915063165623"><a name="b977915063165623"></a><a name="b977915063165623"></a>head</strong> and initializes the merged list. </p>
</td>
</tr>
<tr id="row1142420756165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p439135581165623"><a name="p439135581165623"></a><a name="p439135581165623"></a><a href="driverutils.md#gad7afae1dc691818c513094c873decabd">HdfWorkQueueInit</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue, char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891363089165623"><a name="p891363089165623"></a><a name="p891363089165623"></a>int32_t </p>
<p id="p1816968654165623"><a name="p1816968654165623"></a><a name="p1816968654165623"></a>Initializes a work queue. </p>
</td>
</tr>
<tr id="row1916169062165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449144556165623"><a name="p1449144556165623"></a><a name="p1449144556165623"></a><a href="driverutils.md#gad171adc8eda320fd01049a2b87ea62fb">HdfWorkInit</a> (<a href="hdfwork.md">HdfWork</a> *work, <a href="driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5">HdfWorkFunc</a> func, void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299792639165623"><a name="p299792639165623"></a><a name="p299792639165623"></a>int32_t </p>
<p id="p407375283165623"><a name="p407375283165623"></a><a name="p407375283165623"></a>Initializes a work item. </p>
</td>
</tr>
<tr id="row1397609005165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1339112096165623"><a name="p1339112096165623"></a><a name="p1339112096165623"></a><a href="driverutils.md#ga55bf669dc6740c65e4d45a4f641db2f1">HdfDelayedWorkInit</a> (<a href="hdfwork.md">HdfWork</a> *work, <a href="driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5">HdfWorkFunc</a> func, void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208466719165623"><a name="p208466719165623"></a><a name="p208466719165623"></a>int32_t </p>
<p id="p1355846636165623"><a name="p1355846636165623"></a><a name="p1355846636165623"></a>Initializes a delayed work item. </p>
</td>
</tr>
<tr id="row1580962266165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060248042165623"><a name="p1060248042165623"></a><a name="p1060248042165623"></a><a href="driverutils.md#gae6166caaf1b114e17834c50414b2d52e">HdfWorkDestroy</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p631923154165623"><a name="p631923154165623"></a><a name="p631923154165623"></a>void </p>
<p id="p1725715662165623"><a name="p1725715662165623"></a><a name="p1725715662165623"></a>Destroys a work item. </p>
</td>
</tr>
<tr id="row1297790470165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p264401832165623"><a name="p264401832165623"></a><a name="p264401832165623"></a><a href="driverutils.md#ga04ec328639aefd71683175e4c214fb80">HdfWorkQueueDestroy</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299698302165623"><a name="p299698302165623"></a><a name="p299698302165623"></a>void </p>
<p id="p909475123165623"><a name="p909475123165623"></a><a name="p909475123165623"></a>Destroys a work queue. </p>
</td>
</tr>
<tr id="row1163951074165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p945519434165623"><a name="p945519434165623"></a><a name="p945519434165623"></a><a href="driverutils.md#gaaaced5c0365d1a1232167b738f08b5ce">HdfDelayedWorkDestroy</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283878070165623"><a name="p283878070165623"></a><a name="p283878070165623"></a>void </p>
<p id="p1303737636165623"><a name="p1303737636165623"></a><a name="p1303737636165623"></a>Destroys a delayed work item. </p>
</td>
</tr>
<tr id="row1798259707165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574910186165623"><a name="p1574910186165623"></a><a name="p1574910186165623"></a><a href="driverutils.md#ga82cc68d656aa17317634b07d49dae160">HdfAddWork</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue, <a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1280394808165623"><a name="p1280394808165623"></a><a name="p1280394808165623"></a>bool </p>
<p id="p2039362547165623"><a name="p2039362547165623"></a><a name="p2039362547165623"></a>Adds a work item to a work queue. </p>
</td>
</tr>
<tr id="row153174241165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p675202689165623"><a name="p675202689165623"></a><a name="p675202689165623"></a><a href="driverutils.md#gaef781ccc1579db3070745088da47b2c5">HdfAddDelayedWork</a> (<a href="hdfworkqueue.md">HdfWorkQueue</a> *queue, <a href="hdfwork.md">HdfWork</a> *work, unsigned long ms)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151736608165623"><a name="p1151736608165623"></a><a name="p1151736608165623"></a>bool </p>
<p id="p46814911165623"><a name="p46814911165623"></a><a name="p46814911165623"></a>Adds a delayed work item to a work queue. </p>
</td>
</tr>
<tr id="row1365153293165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p509368999165623"><a name="p509368999165623"></a><a name="p509368999165623"></a><a href="driverutils.md#ga37595ed36b8ce7be84c914aebfd99d00">HdfWorkBusy</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p822461712165623"><a name="p822461712165623"></a><a name="p822461712165623"></a>unsigned int </p>
<p id="p76523603165623"><a name="p76523603165623"></a><a name="p76523603165623"></a>Obtains the status of a work item or delayed work item. </p>
</td>
</tr>
<tr id="row2000934198165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358185165165623"><a name="p358185165165623"></a><a name="p358185165165623"></a><a href="driverutils.md#gaab300487bdb9f3496bb823c657275dd3">HdfCancelWorkSync</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1613269509165623"><a name="p1613269509165623"></a><a name="p1613269509165623"></a>bool </p>
<p id="p635310933165623"><a name="p635310933165623"></a><a name="p635310933165623"></a>Cancels a work item. This function waits until the work item is complete. </p>
</td>
</tr>
<tr id="row1610340876165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500363103165623"><a name="p1500363103165623"></a><a name="p1500363103165623"></a><a href="driverutils.md#gad53e46938809200db3caafdc85decc5a">HdfCancelDelayedWorkSync</a> (<a href="hdfwork.md">HdfWork</a> *work)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064327821165623"><a name="p1064327821165623"></a><a name="p1064327821165623"></a>bool </p>
<p id="p301163495165623"><a name="p301163495165623"></a><a name="p301163495165623"></a>Cancels a delayed work item. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1185566655165623"></a>

## **Macro Definition **<a name="section2134126864165623"></a>

## CONTAINER\_OF<a name="ga818b9cca761fe7bc18e4e417da772976"></a>

```
#define CONTAINER_OF( ptr,  type,  member )   (type *)((char *)(ptr) - (char *)&((type *)0)->member)
```

 **Description:**

Obtains the address of a structure variable from its member address. 

**Parameters:**

<a name="table1916285764165623"></a>
<table><thead align="left"><tr id="row461451966165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1361607695165623"><a name="p1361607695165623"></a><a name="p1361607695165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p472672258165623"><a name="p472672258165623"></a><a name="p472672258165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row712551898165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure member address. </td>
</tr>
<tr id="row1175734498165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure type. </td>
</tr>
<tr id="row797610862165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">member</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure member. </td>
</tr>
</tbody>
</table>

## DLIST\_FIRST\_ENTRY<a name="ga203de9c01fefc8bbbae746685794cfcc"></a>

```
#define DLIST_FIRST_ENTRY( ptr,  type,  member )   [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((ptr)->next, type, member)
```

 **Description:**

Obtains the first node of a doubly linked list. 

**Parameters:**

<a name="table1824789549165623"></a>
<table><thead align="left"><tr id="row1386424705165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p667815551165623"><a name="p667815551165623"></a><a name="p667815551165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1915062592165623"><a name="p1915062592165623"></a><a name="p1915062592165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1213235414165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure member address. </td>
</tr>
<tr id="row398209042165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure type. </td>
</tr>
<tr id="row264142470165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">member</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure member. </td>
</tr>
</tbody>
</table>

## DLIST\_FOR\_EACH\_ENTRY<a name="ga2b53b2bcf35b8cfb32e429cacbcc0a8d"></a>

```
#define DLIST_FOR_EACH_ENTRY( pos,  head,  type,  member )
```

```
Values: for ((pos) = [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((head)->next, type, member); \

 &(pos)->member != (head); \

 (pos) = [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((pos)->member.next, type, member))


```

 **Description:**

Traverses all nodes in a doubly linked list. 

**Parameters:**

<a name="table613065547165623"></a>
<table><thead align="left"><tr id="row752053958165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p803538893165623"><a name="p803538893165623"></a><a name="p803538893165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p683641789165623"><a name="p683641789165623"></a><a name="p683641789165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row251822306165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the structure variable. </td>
</tr>
<tr id="row881873362165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list head. </td>
</tr>
<tr id="row2118581841165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure type. </td>
</tr>
<tr id="row875715404165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">member</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the member type of the structure. </td>
</tr>
</tbody>
</table>

## DLIST\_FOR\_EACH\_ENTRY\_SAFE<a name="ga8e6f49c1fed85c031f29e8acce377ea0"></a>

```
#define DLIST_FOR_EACH_ENTRY_SAFE( pos,  tmp,  head,  type,  member )
```

```
Values: for ((pos) = [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((head)->next, type, member), \

 (tmp) = [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((pos)->member.next, type, member); \

 &(pos)->member != (head); \

 (pos) = (tmp), (tmp) = [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((pos)->member.next, type, member))


```

 **Description:**

Traverses all nodes in a doubly linked list. This function is used to delete the nodes pointed to by  **pos**  during traversal. 

**Parameters:**

<a name="table876429335165623"></a>
<table><thead align="left"><tr id="row474647043165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1259588665165623"><a name="p1259588665165623"></a><a name="p1259588665165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p134928034165623"><a name="p134928034165623"></a><a name="p134928034165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row21752009165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">pos</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the structure variable. </td>
</tr>
<tr id="row1351354951165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">tmp</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the structure variable, pointing to the next node of <strong id="b1147155929165623"><a name="b1147155929165623"></a><a name="b1147155929165623"></a>pos</strong>. </td>
</tr>
<tr id="row553387575165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list head. </td>
</tr>
<tr id="row1576814434165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure type. </td>
</tr>
<tr id="row449897637165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">member</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the member type of the structure. </td>
</tr>
</tbody>
</table>

## DLIST\_LAST\_ENTRY<a name="ga25ac08cc864bd59050f7e2ca77df1f23"></a>

```
#define DLIST_LAST_ENTRY( ptr,  type,  member )   [CONTAINER_OF](driverutils.md#ga818b9cca761fe7bc18e4e417da772976)((ptr)->prev, type, member)
```

 **Description:**

Obtains the last node of a doubly linked list. 

**Parameters:**

<a name="table736094753165623"></a>
<table><thead align="left"><tr id="row1409373733165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p69991140165623"><a name="p69991140165623"></a><a name="p69991140165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1214476726165623"><a name="p1214476726165623"></a><a name="p1214476726165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1006582124165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">ptr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure member address. </td>
</tr>
<tr id="row2046224542165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure type. </td>
</tr>
<tr id="row703323919165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">member</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the structure member. </td>
</tr>
</tbody>
</table>

## HDF\_LOGD<a name="gaa0411582f697619cdb045ae61ac42539"></a>

```
#define HDF_LOGD( fmt,  arg... )   [printf](io.md#ga98631211a4a8aee62f572375d5b637be)("[HDF:D/" LOG_TAG "]" fmt "\r\n", ##arg)
```

 **Description:**

Prints logs at the debug level. 

To use this function, you must define  **HDF\_LOG\_TAG**, for example, \#define HDF\_LOG\_TAG evt.

## HDF\_LOGE<a name="gaacd0eb778948960a7f97af155287ce8c"></a>

```
#define HDF_LOGE( fmt,  arg... )   [printf](io.md#ga98631211a4a8aee62f572375d5b637be)("[HDF:E/" LOG_TAG "]" fmt "\r\n", ##arg)
```

 **Description:**

Prints logs at the error level. 

To use this function, you must define  **HDF\_LOG\_TAG**, for example, \#define HDF\_LOG\_TAG evt.

## HDF\_LOGI<a name="ga369d56841d17e6908fc6885fcb814b80"></a>

```
#define HDF_LOGI( fmt,  arg... )   [printf](io.md#ga98631211a4a8aee62f572375d5b637be)("[HDF:I/" LOG_TAG "]" fmt "\r\n", ##arg)
```

 **Description:**

Prints logs at the information level. 

To use this function, you must define  **HDF\_LOG\_TAG**, for example, \#define HDF\_LOG\_TAG evt.

## HDF\_LOGV<a name="ga4abebfca1aaeb8125f85800425caf304"></a>

```
#define HDF_LOGV( fmt,  arg... )   [printf](io.md#ga98631211a4a8aee62f572375d5b637be)("[HDF:V/" LOG_TAG "]" fmt "\r\n", ##arg)
```

 **Description:**

Prints logs at the verbose level. 

To use this function, you must define  **HDF\_LOG\_TAG**, for example, \#define HDF\_LOG\_TAG evt.

## HDF\_LOGW<a name="ga72f232dade88b85aff2d8c0e42b82df0"></a>

```
#define HDF_LOGW( fmt,  arg... )   [printf](io.md#ga98631211a4a8aee62f572375d5b637be)("[HDF:W/" LOG_TAG "]" fmt "\r\n", ##arg)
```

 **Description:**

Prints logs at the warning level. 

To use this function, you must define  **HDF\_LOG\_TAG**, for example, \#define HDF\_LOG\_TAG evt.

## LOG\_TAG\_MARK\_EXTEND<a name="ga7e862bda9f0b95d1628f6f62598f1f42"></a>

```
#define LOG_TAG_MARK_EXTEND( HDF_TAG)   #HDF_TAG
```

 **Description:**

Add quotation mark 

## **Typedef **<a name="section1521632851165623"></a>

## HdfWorkFunc<a name="ga30665d61b03fae4a2ebc778c3d775ce5"></a>

```
typedef void(* HdfWorkFunc) (void *)
```

 **Description:**

Describes a work execution function type. 

The thread of the work queue executes this function after the work item is added to the work queue. 

## **Enumeration Type **<a name="section758644115165623"></a>

## anonymous enum<a name="gac205be2172292384dd687b5471a87edd"></a>

```
anonymous enum
```

 **Description:**

Enumerates statuses of a work item or a delayed work item. 

<a name="table1718087851165623"></a>
<table><thead align="left"><tr id="row892320746165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p191519323165623"><a name="p191519323165623"></a><a name="p191519323165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2092543102165623"><a name="p2092543102165623"></a><a name="p2092543102165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row770614071165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac205be2172292384dd687b5471a87edda75df1ca644f77f78bf3539e356f2e446"><a name="ggac205be2172292384dd687b5471a87edda75df1ca644f77f78bf3539e356f2e446"></a><a name="ggac205be2172292384dd687b5471a87edda75df1ca644f77f78bf3539e356f2e446"></a></strong>HDF_WORK_BUSY_PENDING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100765768165623"><a name="p100765768165623"></a><a name="p100765768165623"></a>The work item or delayed work item is pending. </p>
 </td>
</tr>
<tr id="row1970975774165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="ggac205be2172292384dd687b5471a87edda56532f81e262cca4680e754627d6dc44"><a name="ggac205be2172292384dd687b5471a87edda56532f81e262cca4680e754627d6dc44"></a><a name="ggac205be2172292384dd687b5471a87edda56532f81e262cca4680e754627d6dc44"></a></strong>HDF_WORK_BUSY_RUNNING </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591650213165623"><a name="p591650213165623"></a><a name="p591650213165623"></a>The work item or delayed work item is running. </p>
 </td>
</tr>
</tbody>
</table>

## HDF\_STATUS<a name="ga7e01536ecbe9b17563dd3fe256202a67"></a>

```
enum [HDF_STATUS](driverutils.md#ga7e01536ecbe9b17563dd3fe256202a67)
```

 **Description:**

Enumerates HDF return value types. 

<a name="table766819856165623"></a>
<table><thead align="left"><tr id="row638643611165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1173902114165623"><a name="p1173902114165623"></a><a name="p1173902114165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1804952977165623"><a name="p1804952977165623"></a><a name="p1804952977165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row661831299165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a66cefc3d8cb74728358899034d8d141f"><a name="gga7e01536ecbe9b17563dd3fe256202a67a66cefc3d8cb74728358899034d8d141f"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a66cefc3d8cb74728358899034d8d141f"></a></strong>HDF_SUCCESS </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1194050977165623"><a name="p1194050977165623"></a><a name="p1194050977165623"></a>The operation is successful. </p>
 </td>
</tr>
<tr id="row354583844165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a454a8a08dd1a4b166b2aff6af90266d0"><a name="gga7e01536ecbe9b17563dd3fe256202a67a454a8a08dd1a4b166b2aff6af90266d0"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a454a8a08dd1a4b166b2aff6af90266d0"></a></strong>HDF_FAILURE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1589926008165623"><a name="p1589926008165623"></a><a name="p1589926008165623"></a>Failed to invoke the OS underlying function. </p>
 </td>
</tr>
<tr id="row2016701736165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67ac6e0c4313436d7222b7dc9bf21e092ed"><a name="gga7e01536ecbe9b17563dd3fe256202a67ac6e0c4313436d7222b7dc9bf21e092ed"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67ac6e0c4313436d7222b7dc9bf21e092ed"></a></strong>HDF_ERR_NOT_SUPPORT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1350966939165623"><a name="p1350966939165623"></a><a name="p1350966939165623"></a>Not supported. </p>
 </td>
</tr>
<tr id="row1243595310165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a87e9e0ca4600bc8967556e668abf6718"><a name="gga7e01536ecbe9b17563dd3fe256202a67a87e9e0ca4600bc8967556e668abf6718"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a87e9e0ca4600bc8967556e668abf6718"></a></strong>HDF_ERR_INVALID_PARAM </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353628289165623"><a name="p1353628289165623"></a><a name="p1353628289165623"></a>Invalid parameter. </p>
 </td>
</tr>
<tr id="row869375815165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a14a42b17e53bbd65b4f15d56df41ae70"><a name="gga7e01536ecbe9b17563dd3fe256202a67a14a42b17e53bbd65b4f15d56df41ae70"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a14a42b17e53bbd65b4f15d56df41ae70"></a></strong>HDF_ERR_INVALID_OBJECT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920995687165623"><a name="p1920995687165623"></a><a name="p1920995687165623"></a>Invalid object. </p>
 </td>
</tr>
<tr id="row1617835327165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a0ad904f070baaf23e6a4bf8fbdf928f5"><a name="gga7e01536ecbe9b17563dd3fe256202a67a0ad904f070baaf23e6a4bf8fbdf928f5"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a0ad904f070baaf23e6a4bf8fbdf928f5"></a></strong>HDF_ERR_MALLOC_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p919218415165623"><a name="p919218415165623"></a><a name="p919218415165623"></a>Memory allocation fails. </p>
 </td>
</tr>
<tr id="row411361679165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a0c698c789d0dec0b054d5f1cf10003d7"><a name="gga7e01536ecbe9b17563dd3fe256202a67a0c698c789d0dec0b054d5f1cf10003d7"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a0c698c789d0dec0b054d5f1cf10003d7"></a></strong>HDF_ERR_TIMEOUT </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173225012165623"><a name="p1173225012165623"></a><a name="p1173225012165623"></a>Timeout occurs. </p>
 </td>
</tr>
<tr id="row960897799165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a77fd634e04dc131c2ca0435372c1f13b"><a name="gga7e01536ecbe9b17563dd3fe256202a67a77fd634e04dc131c2ca0435372c1f13b"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a77fd634e04dc131c2ca0435372c1f13b"></a></strong>HDF_ERR_THREAD_CREATE_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1069224646165623"><a name="p1069224646165623"></a><a name="p1069224646165623"></a>Failed to create a thread. </p>
 </td>
</tr>
<tr id="row1906654854165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a44e8f39984cb2b4f7790b2ceab8b7670"><a name="gga7e01536ecbe9b17563dd3fe256202a67a44e8f39984cb2b4f7790b2ceab8b7670"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a44e8f39984cb2b4f7790b2ceab8b7670"></a></strong>HDF_ERR_QUEUE_FULL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137465183165623"><a name="p2137465183165623"></a><a name="p2137465183165623"></a>The queue is full. </p>
 </td>
</tr>
<tr id="row2124789427165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a9c98586b0a30928afdd3f8fee5083e9b"><a name="gga7e01536ecbe9b17563dd3fe256202a67a9c98586b0a30928afdd3f8fee5083e9b"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a9c98586b0a30928afdd3f8fee5083e9b"></a></strong>HDF_ERR_DEVICE_BUSY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2005125057165623"><a name="p2005125057165623"></a><a name="p2005125057165623"></a>The device is busy. </p>
 </td>
</tr>
<tr id="row1311620877165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a79c1aa5fb70b16b6b62b9f92e06b76d8"><a name="gga7e01536ecbe9b17563dd3fe256202a67a79c1aa5fb70b16b6b62b9f92e06b76d8"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a79c1aa5fb70b16b6b62b9f92e06b76d8"></a></strong>HDF_ERR_IO </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002178200165623"><a name="p2002178200165623"></a><a name="p2002178200165623"></a>I/O error. </p>
 </td>
</tr>
<tr id="row1411689789165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a140804bae8a12c1ae2f3bbb07dd942d9"><a name="gga7e01536ecbe9b17563dd3fe256202a67a140804bae8a12c1ae2f3bbb07dd942d9"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a140804bae8a12c1ae2f3bbb07dd942d9"></a></strong>HDF_ERR_BAD_FD </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1125987868165623"><a name="p1125987868165623"></a><a name="p1125987868165623"></a>Incorrect file descriptor. </p>
 </td>
</tr>
<tr id="row445784707165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a0d6ae6ce941fe02f540dc38897e9aac6"><a name="gga7e01536ecbe9b17563dd3fe256202a67a0d6ae6ce941fe02f540dc38897e9aac6"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a0d6ae6ce941fe02f540dc38897e9aac6"></a></strong>HDF_BSP_ERR_OP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789781760165623"><a name="p1789781760165623"></a><a name="p1789781760165623"></a>Failed to operate a BSP module. </p>
 </td>
</tr>
<tr id="row2028902181165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a6005454a71463ece52e0aa518f5032c2"><a name="gga7e01536ecbe9b17563dd3fe256202a67a6005454a71463ece52e0aa518f5032c2"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a6005454a71463ece52e0aa518f5032c2"></a></strong>HDF_ERR_BSP_PLT_API_ERR </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287262435165623"><a name="p1287262435165623"></a><a name="p1287262435165623"></a>The platform API of the BSP module is incorrect. </p>
 </td>
</tr>
<tr id="row1525272138165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a520a898768b87a190ead33e693196946"><a name="gga7e01536ecbe9b17563dd3fe256202a67a520a898768b87a190ead33e693196946"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a520a898768b87a190ead33e693196946"></a></strong>HDF_PAL_ERR_DEV_CREATE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342542103165623"><a name="p1342542103165623"></a><a name="p1342542103165623"></a>Failed to create a BSP module device. </p>
 </td>
</tr>
<tr id="row964503386165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a0cd3b31917d5ebb591bcbc7bd1099d55"><a name="gga7e01536ecbe9b17563dd3fe256202a67a0cd3b31917d5ebb591bcbc7bd1099d55"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a0cd3b31917d5ebb591bcbc7bd1099d55"></a></strong>HDF_PAL_ERR_INNER </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p110992043165623"><a name="p110992043165623"></a><a name="p110992043165623"></a>Internal error codes of the BSP module. </p>
 </td>
</tr>
<tr id="row1439292938165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67ac7475bfa5f540b4324e551f5e7d7b2bd"><a name="gga7e01536ecbe9b17563dd3fe256202a67ac7475bfa5f540b4324e551f5e7d7b2bd"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67ac7475bfa5f540b4324e551f5e7d7b2bd"></a></strong>HDF_DEV_ERR_NO_MEMORY </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1577320723165623"><a name="p1577320723165623"></a><a name="p1577320723165623"></a>Failed to allocate memory to the device module. </p>
 </td>
</tr>
<tr id="row479052634165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67abde6ef565b453d3fc7734338db4db62d"><a name="gga7e01536ecbe9b17563dd3fe256202a67abde6ef565b453d3fc7734338db4db62d"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67abde6ef565b453d3fc7734338db4db62d"></a></strong>HDF_DEV_ERR_NO_DEVICE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779409989165623"><a name="p779409989165623"></a><a name="p779409989165623"></a>The device module has no device. </p>
 </td>
</tr>
<tr id="row782597944165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a7d31e3b26c26010b0b1cf64596982005"><a name="gga7e01536ecbe9b17563dd3fe256202a67a7d31e3b26c26010b0b1cf64596982005"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a7d31e3b26c26010b0b1cf64596982005"></a></strong>HDF_DEV_ERR_NO_DEVICE_SERVICE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p994631484165623"><a name="p994631484165623"></a><a name="p994631484165623"></a>The device module has no device service. </p>
 </td>
</tr>
<tr id="row1277442125165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a50fbd0d6fba63406ee384eb0c2ddaab5"><a name="gga7e01536ecbe9b17563dd3fe256202a67a50fbd0d6fba63406ee384eb0c2ddaab5"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a50fbd0d6fba63406ee384eb0c2ddaab5"></a></strong>HDF_DEV_ERR_DEV_INIT_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1655963974165623"><a name="p1655963974165623"></a><a name="p1655963974165623"></a>Failed to initialize a device module. </p>
 </td>
</tr>
<tr id="row580270593165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a318d4f725c1e85fb8c55acac7ed80112"><a name="gga7e01536ecbe9b17563dd3fe256202a67a318d4f725c1e85fb8c55acac7ed80112"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a318d4f725c1e85fb8c55acac7ed80112"></a></strong>HDF_DEV_ERR_PUBLISH_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1682709619165623"><a name="p1682709619165623"></a><a name="p1682709619165623"></a>The device module failed to release a service. </p>
 </td>
</tr>
<tr id="row85847986165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a676ff9d5ba402e93f44465d309cf4f94"><a name="gga7e01536ecbe9b17563dd3fe256202a67a676ff9d5ba402e93f44465d309cf4f94"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a676ff9d5ba402e93f44465d309cf4f94"></a></strong>HDF_DEV_ERR_ATTACHDEV_FAIL </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1844994149165623"><a name="p1844994149165623"></a><a name="p1844994149165623"></a>Failed to attach a device to a device module. </p>
 </td>
</tr>
<tr id="row1627822103165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67a4cfc60685fac5ac921651fdaea845c1a"><a name="gga7e01536ecbe9b17563dd3fe256202a67a4cfc60685fac5ac921651fdaea845c1a"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67a4cfc60685fac5ac921651fdaea845c1a"></a></strong>HDF_DEV_ERR_NODATA </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20264669165623"><a name="p20264669165623"></a><a name="p20264669165623"></a>Failed to read data from a device module. </p>
 </td>
</tr>
<tr id="row1570090492165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67adbecc6285acfc5030abff4612b9cf916"><a name="gga7e01536ecbe9b17563dd3fe256202a67adbecc6285acfc5030abff4612b9cf916"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67adbecc6285acfc5030abff4612b9cf916"></a></strong>HDF_DEV_ERR_NORANGE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241491799165623"><a name="p1241491799165623"></a><a name="p1241491799165623"></a>The device module data is out of range. </p>
 </td>
</tr>
<tr id="row39155184165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga7e01536ecbe9b17563dd3fe256202a67aace3a9148b526f670290e7829f3dd9df"><a name="gga7e01536ecbe9b17563dd3fe256202a67aace3a9148b526f670290e7829f3dd9df"></a><a name="gga7e01536ecbe9b17563dd3fe256202a67aace3a9148b526f670290e7829f3dd9df"></a></strong>HDF_DEV_ERR_OP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1604153756165623"><a name="p1604153756165623"></a><a name="p1604153756165623"></a>Failed to operate a device module. </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section636459406165623"></a>

## DListHeadInit\(\)<a name="ga0a86a18ad591f485663834799dd38dea"></a>

```
static void DListHeadInit (struct [DListHead](dlisthead.md) * head)
```

 **Description:**

Initializes a doubly linked list. 

**Parameters:**

<a name="table400228463165623"></a>
<table><thead align="left"><tr id="row1900406592165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p64402282165623"><a name="p64402282165623"></a><a name="p64402282165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p959578312165623"><a name="p959578312165623"></a><a name="p959578312165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1566696732165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
</tbody>
</table>

## DListInsertHead\(\)<a name="ga60e796c868630dd403ef4fdcc60c12e8"></a>

```
static void DListInsertHead (struct [DListHead](dlisthead.md) * entry, struct [DListHead](dlisthead.md) * head )
```

 **Description:**

Inserts a node from the head of a doubly linked list. 

**Parameters:**

<a name="table718729953165623"></a>
<table><thead align="left"><tr id="row260576586165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p401705679165623"><a name="p401705679165623"></a><a name="p401705679165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p677185495165623"><a name="p677185495165623"></a><a name="p677185495165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row390763633165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">entry</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the node to insert. For details, see <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
<tr id="row668062736165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
</tbody>
</table>

## DListInsertTail\(\)<a name="gaa1d386162f8f6401fe8ac6d70d237517"></a>

```
static void DListInsertTail (struct [DListHead](dlisthead.md) * entry, struct [DListHead](dlisthead.md) * head )
```

 **Description:**

Inserts a node from the tail of a doubly linked list. 

**Parameters:**

<a name="table885056163165623"></a>
<table><thead align="left"><tr id="row29571845165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p157219800165623"><a name="p157219800165623"></a><a name="p157219800165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p644280109165623"><a name="p644280109165623"></a><a name="p644280109165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1481761455165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">entry</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the node to insert. For details, see <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
<tr id="row2110021848165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
</tbody>
</table>

## DListIsEmpty\(\)<a name="ga9b4053294ad63f0bdacb4841a14ba208"></a>

```
static bool DListIsEmpty (const struct [DListHead](dlisthead.md) * head)
```

 **Description:**

Checks whether a doubly linked list is empty. 

**Parameters:**

<a name="table1180223809165623"></a>
<table><thead align="left"><tr id="row1463835100165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p692125528165623"><a name="p692125528165623"></a><a name="p692125528165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p74183792165623"><a name="p74183792165623"></a><a name="p74183792165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row646154445165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
</tbody>
</table>

## DListMerge\(\)<a name="gac4acad10a7c49cc4b2d773aedbfa1e11"></a>

```
static void DListMerge (struct [DListHead](dlisthead.md) * list, struct [DListHead](dlisthead.md) * head )
```

 **Description:**

Merges two linked lists by adding the list specified by  **list**  to the head of the list specified by  **head**  and initializes the merged list. 

**Parameters:**

<a name="table2130157407165623"></a>
<table><thead align="left"><tr id="row2059840720165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1029723260165623"><a name="p1029723260165623"></a><a name="p1029723260165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p948299395165623"><a name="p948299395165623"></a><a name="p948299395165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row873580182165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">list</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
<tr id="row154477157165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">head</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the linked list <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
</tbody>
</table>

## DListRemove\(\)<a name="ga42d23fa1f55097bae91664c5e4a78e1e"></a>

```
static void DListRemove (struct [DListHead](dlisthead.md) * entry)
```

 **Description:**

Removes a node from a doubly linked list. 

**Parameters:**

<a name="table1679182462165623"></a>
<table><thead align="left"><tr id="row2090244441165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p531691792165623"><a name="p531691792165623"></a><a name="p531691792165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1008134683165623"><a name="p1008134683165623"></a><a name="p1008134683165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1286839860165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">entry</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the node to remove. For details, see <a href="dlisthead.md">DListHead</a>. The parameter cannot be empty. </td>
</tr>
</tbody>
</table>

## HdfAddDelayedWork\(\)<a name="gaef781ccc1579db3070745088da47b2c5"></a>

```
bool HdfAddDelayedWork ([HdfWorkQueue](hdfworkqueue.md) * queue, [HdfWork](hdfwork.md) * work, unsigned long ms )
```

 **Description:**

Adds a delayed work item to a work queue. 

A delayed work item is added to a work queue after the configured delayed time \(ms\), and the thread of the work queue executes the work function.

**Parameters:**

<a name="table57244605165623"></a>
<table><thead align="left"><tr id="row1801084276165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1181790840165623"><a name="p1181790840165623"></a><a name="p1181790840165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p822163370165623"><a name="p822163370165623"></a><a name="p822163370165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row166763999165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">queue</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work queue <a href="hdfworkqueue.md">HdfWorkQueue</a>. </td>
</tr>
<tr id="row1506935425165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the delayed work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise. 

## HdfAddWork\(\)<a name="ga82cc68d656aa17317634b07d49dae160"></a>

```
bool HdfAddWork ([HdfWorkQueue](hdfworkqueue.md) * queue, [HdfWork](hdfwork.md) * work )
```

 **Description:**

Adds a work item to a work queue. 

After a work item is added to a work queue, the thread of the work queue executes the function of the work item.

**Parameters:**

<a name="table2079673012165623"></a>
<table><thead align="left"><tr id="row210924607165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p333889280165623"><a name="p333889280165623"></a><a name="p333889280165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p162233785165623"><a name="p162233785165623"></a><a name="p162233785165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1433942891165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">queue</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work queue <a href="hdfworkqueue.md">HdfWorkQueue</a>. </td>
</tr>
<tr id="row497079627165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise. 

## HdfCancelDelayedWorkSync\(\)<a name="gad53e46938809200db3caafdc85decc5a"></a>

```
bool HdfCancelDelayedWorkSync ([HdfWork](hdfwork.md) * work)
```

 **Description:**

Cancels a delayed work item. 

**Parameters:**

<a name="table1447608221165623"></a>
<table><thead align="left"><tr id="row937376556165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p151553259165623"><a name="p151553259165623"></a><a name="p151553259165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1328049085165623"><a name="p1328049085165623"></a><a name="p1328049085165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row249555461165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the delayed work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise. 

## HdfCancelWorkSync\(\)<a name="gaab300487bdb9f3496bb823c657275dd3"></a>

```
bool HdfCancelWorkSync ([HdfWork](hdfwork.md) * work)
```

 **Description:**

Cancels a work item. This function waits until the work item is complete. 

**Parameters:**

<a name="table1149858667165623"></a>
<table><thead align="left"><tr id="row195816397165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p820428261165623"><a name="p820428261165623"></a><a name="p820428261165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1451585688165623"><a name="p1451585688165623"></a><a name="p1451585688165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row209362163165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **true**  if the operation is successful; returns  **false**  otherwise. 

## HdfDelayedWorkDestroy\(\)<a name="gaaaced5c0365d1a1232167b738f08b5ce"></a>

```
void HdfDelayedWorkDestroy ([HdfWork](hdfwork.md) * work)
```

 **Description:**

Destroys a delayed work item. 

**Parameters:**

<a name="table757927621165623"></a>
<table><thead align="left"><tr id="row431450310165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p519491379165623"><a name="p519491379165623"></a><a name="p519491379165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p301559116165623"><a name="p301559116165623"></a><a name="p301559116165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row103005477165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the delayed work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

## HdfDelayedWorkInit\(\)<a name="ga55bf669dc6740c65e4d45a4f641db2f1"></a>

```
int32_t HdfDelayedWorkInit ([HdfWork](hdfwork.md) * work, [HdfWorkFunc](driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5) func, void * arg )
```

 **Description:**

Initializes a delayed work item. 

This function uses  **func**  and  **arg**  to initialize a work item. The work item is added to a work queue after the configured delayed time. The thread of the work queue executes this function, and  **arg**  is passed to  **func**.

**Parameters:**

<a name="table437227452165623"></a>
<table><thead align="left"><tr id="row155990501165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p233400667165623"><a name="p233400667165623"></a><a name="p233400667165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p965274915165623"><a name="p965274915165623"></a><a name="p965274915165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1267148335165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the delayed work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
<tr id="row566076278165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the work execution function. </td>
</tr>
<tr id="row347825966165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">arg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the argument of the work execution function.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1502524036165623"></a>
<table><thead align="left"><tr id="row1966170065165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p478720705165623"><a name="p478720705165623"></a><a name="p478720705165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p773352194165623"><a name="p773352194165623"></a><a name="p773352194165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row146195935165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813574579165623"><a name="p1813574579165623"></a><a name="p1813574579165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1184679763165623"><a name="p1184679763165623"></a><a name="p1184679763165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row473994232165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1190419671165623"><a name="p1190419671165623"></a><a name="p1190419671165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371449751165623"><a name="p1371449751165623"></a><a name="p1371449751165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row187372423165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p899827945165623"><a name="p899827945165623"></a><a name="p899827945165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p635436579165623"><a name="p635436579165623"></a><a name="p635436579165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

## HdfWorkBusy\(\)<a name="ga37595ed36b8ce7be84c914aebfd99d00"></a>

```
unsigned int HdfWorkBusy ([HdfWork](hdfwork.md) * work)
```

 **Description:**

Obtains the status of a work item or delayed work item. 

**Parameters:**

<a name="table1709902752165623"></a>
<table><thead align="left"><tr id="row480079293165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2104992026165623"><a name="p2104992026165623"></a><a name="p2104992026165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1666195681165623"><a name="p1666195681165623"></a><a name="p1666195681165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1868813317165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work item or delayed work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **HDF\_WORK\_BUSY\_PENDING**  if the work item is pending; returns  **HDF\_WORK\_BUSY\_RUNNING**  if the work item is running. 

## HdfWorkDestroy\(\)<a name="gae6166caaf1b114e17834c50414b2d52e"></a>

```
void HdfWorkDestroy ([HdfWork](hdfwork.md) * work)
```

 **Description:**

Destroys a work item. 

**Parameters:**

<a name="table1151238895165623"></a>
<table><thead align="left"><tr id="row2068264616165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1392464664165623"><a name="p1392464664165623"></a><a name="p1392464664165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p460509548165623"><a name="p460509548165623"></a><a name="p460509548165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1972942746165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
</tbody>
</table>

## HdfWorkInit\(\)<a name="gad171adc8eda320fd01049a2b87ea62fb"></a>

```
int32_t HdfWorkInit ([HdfWork](hdfwork.md) * work, [HdfWorkFunc](driverutils.md#ga30665d61b03fae4a2ebc778c3d775ce5) func, void * arg )
```

 **Description:**

Initializes a work item. 

This function uses  **func**  and  **arg**  to initialize a work item. After the work item is added to a work queue, the thread of the work queue executes this function, and  **arg**  is passed to  **func**.

**Parameters:**

<a name="table410832628165623"></a>
<table><thead align="left"><tr id="row1753421826165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1978509440165623"><a name="p1978509440165623"></a><a name="p1978509440165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p339557081165623"><a name="p339557081165623"></a><a name="p339557081165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1712159777165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">work</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work item <a href="hdfwork.md">HdfWork</a>. </td>
</tr>
<tr id="row459104186165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">func</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the work execution function. </td>
</tr>
<tr id="row2126440785165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">arg</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the argument of the work execution function.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table1177641760165623"></a>
<table><thead align="left"><tr id="row707566480165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p103938140165623"><a name="p103938140165623"></a><a name="p103938140165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1423211391165623"><a name="p1423211391165623"></a><a name="p1423211391165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row1692592331165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p977802235165623"><a name="p977802235165623"></a><a name="p977802235165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p308487880165623"><a name="p308487880165623"></a><a name="p308487880165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row394282940165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p680404407165623"><a name="p680404407165623"></a><a name="p680404407165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p131363549165623"><a name="p131363549165623"></a><a name="p131363549165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row243184801165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p794040914165623"><a name="p794040914165623"></a><a name="p794040914165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696788304165623"><a name="p1696788304165623"></a><a name="p1696788304165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

## HdfWorkQueueDestroy\(\)<a name="ga04ec328639aefd71683175e4c214fb80"></a>

```
void HdfWorkQueueDestroy ([HdfWorkQueue](hdfworkqueue.md) * queue)
```

 **Description:**

Destroys a work queue. 

**Parameters:**

<a name="table1842933291165623"></a>
<table><thead align="left"><tr id="row863576724165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p985290979165623"><a name="p985290979165623"></a><a name="p985290979165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p495286544165623"><a name="p495286544165623"></a><a name="p495286544165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row807910547165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">queue</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work queue <a href="hdfworkqueue.md">HdfWorkQueue</a>. </td>
</tr>
</tbody>
</table>

## HdfWorkQueueInit\(\)<a name="gad7afae1dc691818c513094c873decabd"></a>

```
int32_t HdfWorkQueueInit ([HdfWorkQueue](hdfworkqueue.md) * queue, char * name )
```

 **Description:**

Initializes a work queue. 

When a work queue is initialized, a thread is created. The thread cyclically executes the work items in the work queue, that is, executes their functions.

**Parameters:**

<a name="table1421917186165623"></a>
<table><thead align="left"><tr id="row355753155165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1189547665165623"><a name="p1189547665165623"></a><a name="p1189547665165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1895336326165623"><a name="p1895336326165623"></a><a name="p1895336326165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row356072548165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">queue</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work queue <strong id="b1047312232165623"><a name="b1047312232165623"></a><a name="b1047312232165623"></a>OsalWorkQueue</strong>. </td>
</tr>
<tr id="row22249003165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">name</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the work queue name.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns a value listed below: 

<a name="table604703698165623"></a>
<table><thead align="left"><tr id="row511039307165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1464611876165623"><a name="p1464611876165623"></a><a name="p1464611876165623"></a>HDF_STATUS </p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2049163360165623"><a name="p2049163360165623"></a><a name="p2049163360165623"></a>Description  </p>
</th>
</tr>
</thead>
<tbody><tr id="row101828440165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863382514165623"><a name="p1863382514165623"></a><a name="p1863382514165623"></a>HDF_SUCCESS </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924616648165623"><a name="p924616648165623"></a><a name="p924616648165623"></a>The operation is successful. </p>
</td>
</tr>
<tr id="row1785500506165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496916052165623"><a name="p496916052165623"></a><a name="p496916052165623"></a>HDF_ERR_INVALID_PARAM </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637398458165623"><a name="p637398458165623"></a><a name="p637398458165623"></a>Invalid parameter. </p>
</td>
</tr>
<tr id="row1032001784165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265090078165623"><a name="p1265090078165623"></a><a name="p1265090078165623"></a>HDF_ERR_MALLOC_FAIL </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1012389007165623"><a name="p1012389007165623"></a><a name="p1012389007165623"></a>Memory allocation fails. </p>
</td>
</tr>
</tbody>
</table>

