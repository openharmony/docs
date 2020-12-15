# OHOS::AbilityEventHandler<a name="EN-US_TOPIC_0000001055198142"></a>

-   [Overview](#section1945428263165632)
-   [Summary](#section556883900165632)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section1945428263165632"></a>

**Related Modules:**

[AbilityKit](abilitykit.md)

**Description:**

Declares functions for performing operations during inter-thread communication, including running and quitting the event loop of the current thread and posting tasks to an asynchronous thread. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section556883900165632"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1745891565165632"></a>
<table><thead align="left"><tr id="row1593591473165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1657287286165632"><a name="p1657287286165632"></a><a name="p1657287286165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1904444121165632"><a name="p1904444121165632"></a><a name="p1904444121165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1188956204165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p595408032165632"><a name="p595408032165632"></a><a name="p595408032165632"></a><a href="abilitykit.md#gac534b1e3746d252944475b3ed9cb5bc7">Run</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1565023342165632"><a name="p1565023342165632"></a><a name="p1565023342165632"></a> void </p>
<p id="p1097640031165632"><a name="p1097640031165632"></a><a name="p1097640031165632"></a>Starts running the event loop of the current thread. </p>
</td>
</tr>
<tr id="row11668317165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131588037165632"><a name="p131588037165632"></a><a name="p131588037165632"></a><a href="abilitykit.md#gad4d0911a8bccd5aca32464bad867cb13">PostTask</a> (const Task &amp;task)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905200095165632"><a name="p1905200095165632"></a><a name="p1905200095165632"></a>void </p>
<p id="p548479506165632"><a name="p548479506165632"></a><a name="p548479506165632"></a>Posts a task to an asynchronous thread. </p>
</td>
</tr>
<tr id="row1731870255165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1533218698165632"><a name="p1533218698165632"></a><a name="p1533218698165632"></a><a href="abilitykit.md#ga075bfbf9e5c9c2178f3183efd664dbaf">PostQuit</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465150164165632"><a name="p1465150164165632"></a><a name="p1465150164165632"></a> void </p>
<p id="p1874827055165632"><a name="p1874827055165632"></a><a name="p1874827055165632"></a>Quits the event loop of the current thread. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table843942478165632"></a>
<table><thead align="left"><tr id="row909800215165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p842761265165632"><a name="p842761265165632"></a><a name="p842761265165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2005556387165632"><a name="p2005556387165632"></a><a name="p2005556387165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1207629358165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p159791155165632"><a name="p159791155165632"></a><a name="p159791155165632"></a><a href="abilitykit.md#gad26d144aaecd3185be6902e6d7399b9e">GetCurrentHandler</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2075324327165632"><a name="p2075324327165632"></a><a name="p2075324327165632"></a>static <a href="ohos-abilityeventhandler.md">AbilityEventHandler</a> * </p>
<p id="p629708274165632"><a name="p629708274165632"></a><a name="p629708274165632"></a>Obtains the event handler of the current thread. </p>
</td>
</tr>
</tbody>
</table>

