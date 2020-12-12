# osal\_thread.h<a name="ZH-CN_TOPIC_0000001055198106"></a>

-   [Overview](#section1403175274165628)
-   [Summary](#section423289735165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1403175274165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares thread types and interfaces. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section423289735165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1752669107165628"></a>
<table><thead align="left"><tr id="row1356936945165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1293471644165628"><a name="p1293471644165628"></a><a name="p1293471644165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1488022005165628"><a name="p1488022005165628"></a><a name="p1488022005165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1970561699165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p82835979165628"><a name="p82835979165628"></a><a name="p82835979165628"></a><a href="OsalThreadParam.md">OsalThreadParam</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p251587275165628"><a name="p251587275165628"></a><a name="p251587275165628"></a>Describes thread parameters. </p>
</td>
</tr>
<tr id="row1614167763165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060443492165628"><a name="p1060443492165628"></a><a name="p1060443492165628"></a><a href="OsalThread.md">OsalThread</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719554593165628"><a name="p1719554593165628"></a><a name="p1719554593165628"></a>Describes a thread. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1342662433165628"></a>
<table><thead align="left"><tr id="row2023364666165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2138285868165628"><a name="p2138285868165628"></a><a name="p2138285868165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p115997394165628"><a name="p115997394165628"></a><a name="p115997394165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1350587162165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1986504255165628"><a name="p1986504255165628"></a><a name="p1986504255165628"></a><a href="OSAL.md#ga6178591bdeb64df97a5232350cc9bc26">OSAL_DECLARE_THREAD</a>(thread)   struct <a href="OsalThread.md">OsalThread</a> thread</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28490279165628"><a name="p28490279165628"></a><a name="p28490279165628"></a>Defines a thread macro. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1853487998165628"></a>
<table><thead align="left"><tr id="row668973974165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1213472650165628"><a name="p1213472650165628"></a><a name="p1213472650165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1197905184165628"><a name="p1197905184165628"></a><a name="p1197905184165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1035442209165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1382123736165628"><a name="p1382123736165628"></a><a name="p1382123736165628"></a><a href="OSAL.md#ga21ea0f87d53e65ec86a424c532d688d8">OsalThreadEntry</a>) (void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1847124368165628"><a name="p1847124368165628"></a><a name="p1847124368165628"></a> typedef int(* </p>
<p id="p1844071661165628"><a name="p1844071661165628"></a><a name="p1844071661165628"></a>Defines a thread callback function type. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table898123936165628"></a>
<table><thead align="left"><tr id="row1682500104165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1881468009165628"><a name="p1881468009165628"></a><a name="p1881468009165628"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1161922618165628"><a name="p1161922618165628"></a><a name="p1161922618165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1812678214165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1016088521165628"><a name="p1016088521165628"></a><a name="p1016088521165628"></a><a href="OSAL.md#gab8c099a9c39fdde73c74b3f7367be5d0">OSAL_THREAD_PRIORITY</a> { <a href="OSAL.md#ggab8c099a9c39fdde73c74b3f7367be5d0a077e53412997ddef962069a7cea4def6">OSAL_THREAD_PRI_LOW</a>, <a href="OSAL.md#ggab8c099a9c39fdde73c74b3f7367be5d0abc9ef48a9fc95f359a5c4d52041111e5">OSAL_THREAD_PRI_DEFAULT</a>, <a href="OSAL.md#ggab8c099a9c39fdde73c74b3f7367be5d0a61697eda5c5265d6d62271d00c098121">OSAL_THREAD_PRI_HIGH</a>, <a href="OSAL.md#ggab8c099a9c39fdde73c74b3f7367be5d0a9e66435e6d967adc68606b359a8753bd">OSAL_THREAD_PRI_HIGHEST</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265853452165628"><a name="p265853452165628"></a><a name="p265853452165628"></a>Enumerates thread priorities. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table2016532015165628"></a>
<table><thead align="left"><tr id="row1856199093165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2001910937165628"><a name="p2001910937165628"></a><a name="p2001910937165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1395180319165628"><a name="p1395180319165628"></a><a name="p1395180319165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row294074525165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1431544377165628"><a name="p1431544377165628"></a><a name="p1431544377165628"></a><a href="OSAL.md#gad598b3f4b91f5e6aeeaf7b8a6e507f1e">OsalThreadCreate</a> (struct <a href="OsalThread.md">OsalThread</a> *thread, <a href="OSAL.md#ga21ea0f87d53e65ec86a424c532d688d8">OsalThreadEntry</a> threadEntry, void *entryPara)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1311991605165628"><a name="p1311991605165628"></a><a name="p1311991605165628"></a>int32_t </p>
<p id="p1616599002165628"><a name="p1616599002165628"></a><a name="p1616599002165628"></a>Creates a thread. </p>
</td>
</tr>
<tr id="row1905961241165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220567492165628"><a name="p1220567492165628"></a><a name="p1220567492165628"></a><a href="OSAL.md#ga74c93bd48d27cde830451f63b224307a">OsalThreadStart</a> (struct <a href="OsalThread.md">OsalThread</a> *thread, const struct <a href="OsalThreadParam.md">OsalThreadParam</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470851519165628"><a name="p470851519165628"></a><a name="p470851519165628"></a>int32_t </p>
<p id="p380421654165628"><a name="p380421654165628"></a><a name="p380421654165628"></a>Starts a thread. </p>
</td>
</tr>
<tr id="row1372808022165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496033788165628"><a name="p496033788165628"></a><a name="p496033788165628"></a><a href="OSAL.md#ga223ce6b94770348a93168525c536e6f9">OsalThreadDestroy</a> (struct <a href="OsalThread.md">OsalThread</a> *thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1434664686165628"><a name="p1434664686165628"></a><a name="p1434664686165628"></a>int32_t </p>
<p id="p1308792610165628"><a name="p1308792610165628"></a><a name="p1308792610165628"></a>Destroys a thread. </p>
</td>
</tr>
<tr id="row1043005976165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895347504165628"><a name="p1895347504165628"></a><a name="p1895347504165628"></a><a href="OSAL.md#gad556075f625d01557c0075a2c092a1da">OsalThreadSuspend</a> (struct <a href="OsalThread.md">OsalThread</a> *thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828333675165628"><a name="p828333675165628"></a><a name="p828333675165628"></a>int32_t </p>
<p id="p1083448517165628"><a name="p1083448517165628"></a><a name="p1083448517165628"></a>Suspends a thread. </p>
</td>
</tr>
<tr id="row2027655942165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334618912165628"><a name="p1334618912165628"></a><a name="p1334618912165628"></a><a href="OSAL.md#ga32f0b5c622518b7453f758d95b137a94">OsalThreadResume</a> (struct <a href="OsalThread.md">OsalThread</a> *thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22713142165628"><a name="p22713142165628"></a><a name="p22713142165628"></a>int32_t </p>
<p id="p70862102165628"><a name="p70862102165628"></a><a name="p70862102165628"></a>Resumes a thread. </p>
</td>
</tr>
</tbody>
</table>

