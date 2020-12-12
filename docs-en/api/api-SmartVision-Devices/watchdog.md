# WATCHDOG<a name="EN-US_TOPIC_0000001055203508"></a>

-   [Overview](#section1290618846165623)
-   [Summary](#section1568879816165623)
-   [Files](#files)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section403189386165623)
-   [Enumeration Type](#section1022114787165623)
-   [WatchdogStatus](#ga3c77a35e1051e3f99238029519ac1954)
-   [Function](#section1817390180165623)
-   [WatchdogClose\(\)](#ga9ba18801b59154c986aef6bb5cc92bf5)
-   [WatchdogFeed\(\)](#ga32e7d3939e8682e52502d9112ad6732a)
-   [WatchdogGetStatus\(\)](#ga2fc274833b7dd18cc61209454d1fa82b)
-   [WatchdogGetTimeout\(\)](#ga525602b8cacd030fb1630ea07f2a5b07)
-   [WatchdogOpen\(\)](#ga0a88b7f3b90bf528cdc8b7589b125e85)
-   [WatchdogSetTimeout\(\)](#ga508bea0dac2cac12b0819bb7af81e628)
-   [WatchdogStart\(\)](#ga6d15226fbc2fe5da184decb6370b0122)
-   [WatchdogStop\(\)](#gac41a51b5d663f7963c06cb1241d50239)

## **Overview**<a name="section1290618846165623"></a>

**Description:**

Provides watchdog APIs, such as setting the watchdog timeout duration and feeding a watchdog \(resetting a watchdog timer\). 

If an error occurs in the main program of the system, for example, if the program crashes or the watchdog timer is not reset in time, the watchdog timer generates a reset signal, and the system restores from the suspending state to the normal state.

**Since:**

1.0

## **Summary**<a name="section1568879816165623"></a>

## Files<a name="files"></a>

<a name="table1175826909165623"></a>
<table><thead align="left"><tr id="row1720399872165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p998480682165623"><a name="p998480682165623"></a><a name="p998480682165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p240691931165623"><a name="p240691931165623"></a><a name="p240691931165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row896841102165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126712860165623"><a name="p2126712860165623"></a><a name="p2126712860165623"></a><a href="watchdog_if-h.md">watchdog_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717001120165623"><a name="p1717001120165623"></a><a name="p1717001120165623"></a>Declares standard watchdog APIs. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1075131199165623"></a>
<table><thead align="left"><tr id="row73277973165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1520108795165623"><a name="p1520108795165623"></a><a name="p1520108795165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p865264797165623"><a name="p865264797165623"></a><a name="p865264797165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row448141890165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1800129627165623"><a name="p1800129627165623"></a><a name="p1800129627165623"></a><a href="watchdog.md#ga3c77a35e1051e3f99238029519ac1954">WatchdogStatus</a> { <a href="watchdog.md#gga3c77a35e1051e3f99238029519ac1954a2579c5f1c789b94d99988476031ec2a6">WATCHDOG_STOP</a>, <a href="watchdog.md#gga3c77a35e1051e3f99238029519ac1954aec39073df0b03eb51cc0e17380b86c68">WATCHDOG_START</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p821531749165623"><a name="p821531749165623"></a><a name="p821531749165623"></a>Enumerates watchdog statuses. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table248432793165623"></a>
<table><thead align="left"><tr id="row2102722352165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1396869331165623"><a name="p1396869331165623"></a><a name="p1396869331165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p292795305165623"><a name="p292795305165623"></a><a name="p292795305165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row850595004165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830295459165623"><a name="p1830295459165623"></a><a name="p1830295459165623"></a><a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a> (int16_t wdtId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p123265122165623"><a name="p123265122165623"></a><a name="p123265122165623"></a><a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> </p>
<p id="p790624787165623"><a name="p790624787165623"></a><a name="p790624787165623"></a>Opens a watchdog. </p>
</td>
</tr>
<tr id="row280410612165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p226700949165623"><a name="p226700949165623"></a><a name="p226700949165623"></a><a href="watchdog.md#ga9ba18801b59154c986aef6bb5cc92bf5">WatchdogClose</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786100711165623"><a name="p786100711165623"></a><a name="p786100711165623"></a>void </p>
<p id="p380016899165623"><a name="p380016899165623"></a><a name="p380016899165623"></a>Closes a watchdog. </p>
</td>
</tr>
<tr id="row1595049618165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p261984408165623"><a name="p261984408165623"></a><a name="p261984408165623"></a><a href="watchdog.md#ga2fc274833b7dd18cc61209454d1fa82b">WatchdogGetStatus</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, int32_t *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141964001165623"><a name="p1141964001165623"></a><a name="p1141964001165623"></a>int32_t </p>
<p id="p1360968731165623"><a name="p1360968731165623"></a><a name="p1360968731165623"></a>Obtains the watchdog status. </p>
</td>
</tr>
<tr id="row1920974757165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217862466165623"><a name="p1217862466165623"></a><a name="p1217862466165623"></a><a href="watchdog.md#ga6d15226fbc2fe5da184decb6370b0122">WatchdogStart</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p648390164165623"><a name="p648390164165623"></a><a name="p648390164165623"></a>int32_t </p>
<p id="p686873855165623"><a name="p686873855165623"></a><a name="p686873855165623"></a>Starts a watchdog. </p>
</td>
</tr>
<tr id="row394527762165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1738678589165623"><a name="p1738678589165623"></a><a name="p1738678589165623"></a><a href="watchdog.md#gac41a51b5d663f7963c06cb1241d50239">WatchdogStop</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283900085165623"><a name="p1283900085165623"></a><a name="p1283900085165623"></a>int32_t </p>
<p id="p1990065240165623"><a name="p1990065240165623"></a><a name="p1990065240165623"></a>Stops a watchdog. </p>
</td>
</tr>
<tr id="row1491106670165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p537393793165623"><a name="p537393793165623"></a><a name="p537393793165623"></a><a href="watchdog.md#ga508bea0dac2cac12b0819bb7af81e628">WatchdogSetTimeout</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t seconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p448237758165623"><a name="p448237758165623"></a><a name="p448237758165623"></a>int32_t </p>
<p id="p253239539165623"><a name="p253239539165623"></a><a name="p253239539165623"></a>Sets the watchdog timeout duration. </p>
</td>
</tr>
<tr id="row224216782165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1639203573165623"><a name="p1639203573165623"></a><a name="p1639203573165623"></a><a href="watchdog.md#ga525602b8cacd030fb1630ea07f2a5b07">WatchdogGetTimeout</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle, uint32_t *seconds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660302614165623"><a name="p1660302614165623"></a><a name="p1660302614165623"></a>int32_t </p>
<p id="p1607427833165623"><a name="p1607427833165623"></a><a name="p1607427833165623"></a>Obtains the watchdog timeout duration. </p>
</td>
</tr>
<tr id="row1726102103165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p642083663165623"><a name="p642083663165623"></a><a name="p642083663165623"></a><a href="watchdog.md#ga32e7d3939e8682e52502d9112ad6732a">WatchdogFeed</a> (<a href="common.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175907896165623"><a name="p175907896165623"></a><a name="p175907896165623"></a>int32_t </p>
<p id="p1825058165623"><a name="p1825058165623"></a><a name="p1825058165623"></a>Feeds a watchdog, that is, resets a watchdog timer. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section403189386165623"></a>

## **Enumeration Type **<a name="section1022114787165623"></a>

## WatchdogStatus<a name="ga3c77a35e1051e3f99238029519ac1954"></a>

```
enum [WatchdogStatus](watchdog.md#ga3c77a35e1051e3f99238029519ac1954)
```

 **Description:**

Enumerates watchdog statuses. 

To obtain the watchdog status, call the  [WatchdogGetStatus](watchdog.md#ga2fc274833b7dd18cc61209454d1fa82b)  function.

<a name="table385706252165623"></a>
<table><thead align="left"><tr id="row1240094662165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p213036995165623"><a name="p213036995165623"></a><a name="p213036995165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1074811153165623"><a name="p1074811153165623"></a><a name="p1074811153165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row994693297165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3c77a35e1051e3f99238029519ac1954a2579c5f1c789b94d99988476031ec2a6"><a name="gga3c77a35e1051e3f99238029519ac1954a2579c5f1c789b94d99988476031ec2a6"></a><a name="gga3c77a35e1051e3f99238029519ac1954a2579c5f1c789b94d99988476031ec2a6"></a></strong>WATCHDOG_STOP </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p80031024165623"><a name="p80031024165623"></a><a name="p80031024165623"></a>Stopped </p>
 </td>
</tr>
<tr id="row449739727165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga3c77a35e1051e3f99238029519ac1954aec39073df0b03eb51cc0e17380b86c68"><a name="gga3c77a35e1051e3f99238029519ac1954aec39073df0b03eb51cc0e17380b86c68"></a><a name="gga3c77a35e1051e3f99238029519ac1954aec39073df0b03eb51cc0e17380b86c68"></a></strong>WATCHDOG_START </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501582009165623"><a name="p501582009165623"></a><a name="p501582009165623"></a>Started </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section1817390180165623"></a>

## WatchdogClose\(\)<a name="ga9ba18801b59154c986aef6bb5cc92bf5"></a>

```
void WatchdogClose ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Closes a watchdog. 

If you no longer need a watchdog, call this function to close it and release its device handle to prevent unnecessary use of memory resources.

**Parameters:**

<a name="table1359934866165623"></a>
<table><thead align="left"><tr id="row420512158165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p205252417165623"><a name="p205252417165623"></a><a name="p205252417165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1400466171165623"><a name="p1400466171165623"></a><a name="p1400466171165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row370931894165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog device handle.</td>
</tr>
</tbody>
</table>

## WatchdogFeed\(\)<a name="ga32e7d3939e8682e52502d9112ad6732a"></a>

```
int32_t WatchdogFeed ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Feeds a watchdog, that is, resets a watchdog timer. 

After a watchdog is started, you must feed it to reset the watchdog timer periodically. If you do not do so, the watchdog hardware will reset the system upon a timeout.

**Parameters:**

<a name="table1371532969165623"></a>
<table><thead align="left"><tr id="row1763167532165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1868466227165623"><a name="p1868466227165623"></a><a name="p1868466227165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1271414229165623"><a name="p1271414229165623"></a><a name="p1271414229165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1234831932165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog handle, which is obtained via <a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the watchdog is fed; returns a negative value otherwise. 

## WatchdogGetStatus\(\)<a name="ga2fc274833b7dd18cc61209454d1fa82b"></a>

```
int32_t WatchdogGetStatus ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, int32_t * status )
```

 **Description:**

Obtains the watchdog status. 

For the available watchdog statuses, see  [WatchdogStatus](watchdog.md#ga3c77a35e1051e3f99238029519ac1954).

**Parameters:**

<a name="table962431724165623"></a>
<table><thead align="left"><tr id="row1469758221165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p368080990165623"><a name="p368080990165623"></a><a name="p368080990165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1720418823165623"><a name="p1720418823165623"></a><a name="p1720418823165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1996399640165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog handle, which is obtained via <a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a>. </td>
</tr>
<tr id="row560886460165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">status</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog status.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the watchdog status is obtained; returns a negative value otherwise.

## WatchdogGetTimeout\(\)<a name="ga525602b8cacd030fb1630ea07f2a5b07"></a>

```
int32_t WatchdogGetTimeout ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t * seconds )
```

 **Description:**

Obtains the watchdog timeout duration. 

**Parameters:**

<a name="table1319217900165623"></a>
<table><thead align="left"><tr id="row243019783165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1292105176165623"><a name="p1292105176165623"></a><a name="p1292105176165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p912657098165623"><a name="p912657098165623"></a><a name="p912657098165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row345631198165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog handle, which is obtained via <a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a>. </td>
</tr>
<tr id="row981541168165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">seconds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the timeout duration, in seconds.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the watchdog timeout duration is obtained; returns a negative value otherwise. 

## WatchdogOpen\(\)<a name="ga0a88b7f3b90bf528cdc8b7589b125e85"></a>

```
[DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) WatchdogOpen (int16_t wdtId)
```

 **Description:**

Opens a watchdog. 

Before operating a watchdog, you must call this function to open it and obtain its device handle.

**Parameters:**

<a name="table954182258165623"></a>
<table><thead align="left"><tr id="row1338462074165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1812145863165623"><a name="p1812145863165623"></a><a name="p1812145863165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1196815715165623"><a name="p1196815715165623"></a><a name="p1196815715165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row250983192165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">wdtId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the watchdog ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the pointer to the device handle of the watch dog if the operation is successful; returns  **NULL**  otherwise.

## WatchdogSetTimeout\(\)<a name="ga508bea0dac2cac12b0819bb7af81e628"></a>

```
int32_t WatchdogSetTimeout ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle, uint32_t seconds )
```

 **Description:**

Sets the watchdog timeout duration. 

**Parameters:**

<a name="table528053890165623"></a>
<table><thead align="left"><tr id="row652362622165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p262533996165623"><a name="p262533996165623"></a><a name="p262533996165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p289542987165623"><a name="p289542987165623"></a><a name="p289542987165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1874503050165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog handle, which is obtained via <a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a>. </td>
</tr>
<tr id="row2128372384165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">seconds</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the timeout duration, in seconds.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the setting is successful; returns a negative value otherwise. 

## WatchdogStart\(\)<a name="ga6d15226fbc2fe5da184decb6370b0122"></a>

```
int32_t WatchdogStart ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Starts a watchdog. 

This function starts the watchdog timer. You must feed the watchdog periodically; otherwise, the watchdog hardware will reset the system upon a timeout.

**Parameters:**

<a name="table726611490165623"></a>
<table><thead align="left"><tr id="row146173173165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p479143740165623"><a name="p479143740165623"></a><a name="p479143740165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p410968943165623"><a name="p410968943165623"></a><a name="p410968943165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row383309009165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog handle, which is obtained via <a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the watchdog is successfully started; returns a negative value otherwise. 

**Attention:**

If the watchdog timer has started before this function is called, calling this function will succeed; however, the watchdog hardware determines whether to reset the timer.

## WatchdogStop\(\)<a name="gac41a51b5d663f7963c06cb1241d50239"></a>

```
int32_t WatchdogStop ([DevHandle](common.md#gab8c2d38e46eec50bd097a27d3d8bf041) handle)
```

 **Description:**

Stops a watchdog. 

If the watchdog has stopped before this function is called, calling this function will succeed.

**Parameters:**

<a name="table812427850165623"></a>
<table><thead align="left"><tr id="row1850409747165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1699990483165623"><a name="p1699990483165623"></a><a name="p1699990483165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2137767904165623"><a name="p2137767904165623"></a><a name="p2137767904165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row479446079165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">handle</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the watchdog handle, which is obtained via <a href="watchdog.md#ga0a88b7f3b90bf528cdc8b7589b125e85">WatchdogOpen</a>.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the watchdog is successfully stopped; returns a negative value otherwise. 

