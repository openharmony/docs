# osal\_timer.h<a name="ZH-CN_TOPIC_0000001055078115"></a>

-   [Overview](#section1177199249165628)
-   [Summary](#section910346918165628)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1177199249165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares timer types and interfaces. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section910346918165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1026789788165628"></a>
<table><thead align="left"><tr id="row535914632165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p100391132165628"><a name="p100391132165628"></a><a name="p100391132165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p749382654165628"><a name="p749382654165628"></a><a name="p749382654165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1878633829165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74960813165628"><a name="p74960813165628"></a><a name="p74960813165628"></a><a href="OsalTimer.md">OsalTimer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346755590165628"><a name="p346755590165628"></a><a name="p346755590165628"></a>Describes a timer. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2048569474165628"></a>
<table><thead align="left"><tr id="row786040460165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1373872356165628"><a name="p1373872356165628"></a><a name="p1373872356165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1683351265165628"><a name="p1683351265165628"></a><a name="p1683351265165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1376509467165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1575727256165628"><a name="p1575727256165628"></a><a name="p1575727256165628"></a><a href="OSAL.md#ga556360caa9ece72fcbbc6aef5fc648f1">OSAL_DECLARE_TIMER</a>(timer)   <a href="OsalTimer.md">OsalTimer</a> timer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621550508165628"><a name="p1621550508165628"></a><a name="p1621550508165628"></a>Defines a timer macro. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table359462017165628"></a>
<table><thead align="left"><tr id="row1538930911165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p825354413165628"><a name="p825354413165628"></a><a name="p825354413165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p414989967165628"><a name="p414989967165628"></a><a name="p414989967165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row427440353165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1893790666165628"><a name="p1893790666165628"></a><a name="p1893790666165628"></a><a href="OSAL.md#gaf3e7a12075b25df5971049d8cd77c25c">OsalTimerFunc</a>) (uintptr_t arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p256337625165628"><a name="p256337625165628"></a><a name="p256337625165628"></a> typedef void(* </p>
<p id="p1707200553165628"><a name="p1707200553165628"></a><a name="p1707200553165628"></a>Describes a timer execution function type. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1692715153165628"></a>
<table><thead align="left"><tr id="row689604826165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1123962143165628"><a name="p1123962143165628"></a><a name="p1123962143165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1564212406165628"><a name="p1564212406165628"></a><a name="p1564212406165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row416713709165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431078891165628"><a name="p431078891165628"></a><a name="p431078891165628"></a><a href="OSAL.md#ga879d9a437e1423021f95cb9341f0d6af">OsalTimerCreate</a> (<a href="OsalTimer.md">OsalTimer</a> *timer, uint32_t interval, <a href="OSAL.md#gaf3e7a12075b25df5971049d8cd77c25c">OsalTimerFunc</a> func, uintptr_t arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p51985233165628"><a name="p51985233165628"></a><a name="p51985233165628"></a>int32_t </p>
<p id="p709107241165628"><a name="p709107241165628"></a><a name="p709107241165628"></a>Creates a timer. </p>
</td>
</tr>
<tr id="row882786386165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1253084792165628"><a name="p1253084792165628"></a><a name="p1253084792165628"></a><a href="OSAL.md#gab754f3522245e6b2f9ee1cdecae62b52">OsalTimerDelete</a> (<a href="OsalTimer.md">OsalTimer</a> *timer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p146923889165628"><a name="p146923889165628"></a><a name="p146923889165628"></a>int32_t </p>
<p id="p198545349165628"><a name="p198545349165628"></a><a name="p198545349165628"></a>Deletes a timer. </p>
</td>
</tr>
<tr id="row173969465165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732287903165628"><a name="p1732287903165628"></a><a name="p1732287903165628"></a><a href="OSAL.md#gaf2e49d5b01b49e5f64a7701da8667141">OsalTimerStartOnce</a> (<a href="OsalTimer.md">OsalTimer</a> *timer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624230991165628"><a name="p624230991165628"></a><a name="p624230991165628"></a>int32_t </p>
<p id="p994162789165628"><a name="p994162789165628"></a><a name="p994162789165628"></a>Starts a timer. </p>
</td>
</tr>
<tr id="row134653940165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960214261165628"><a name="p1960214261165628"></a><a name="p1960214261165628"></a><a href="OSAL.md#ga575e4f41359c737ab9690ab28838b99f">OsalTimerStartLoop</a> (<a href="OsalTimer.md">OsalTimer</a> *timer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368710211165628"><a name="p1368710211165628"></a><a name="p1368710211165628"></a>int32_t </p>
<p id="p550147858165628"><a name="p550147858165628"></a><a name="p550147858165628"></a>Starts a periodic timer. </p>
</td>
</tr>
<tr id="row1283563375165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p729151803165628"><a name="p729151803165628"></a><a name="p729151803165628"></a><a href="OSAL.md#ga49c2fe3f54d548fe5ec0d03a79691376">OsalTimerSetTimeout</a> (<a href="OsalTimer.md">OsalTimer</a> *timer, uint32_t interval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1120281561165628"><a name="p1120281561165628"></a><a name="p1120281561165628"></a>int32_t </p>
<p id="p776270626165628"><a name="p776270626165628"></a><a name="p776270626165628"></a>Sets the interval of a timer. </p>
</td>
</tr>
</tbody>
</table>

