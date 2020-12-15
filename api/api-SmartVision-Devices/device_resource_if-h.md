# device\_resource\_if.h<a name="ZH-CN_TOPIC_0000001055518054"></a>

-   [Overview](#section1360663492165626)
-   [Summary](#section991756132165626)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section1360663492165626"></a>

**Related Modules:**

[DriverConfig](DriverConfig.md)

**Description:**

Declares the API for querying the configuration tree. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section991756132165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1667846344165626"></a>
<table><thead align="left"><tr id="row150237110165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2119097560165626"><a name="p2119097560165626"></a><a name="p2119097560165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p739028093165626"><a name="p739028093165626"></a><a name="p739028093165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row500088232165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283739984165626"><a name="p283739984165626"></a><a name="p283739984165626"></a><a href="DeviceResourceAttr.md">DeviceResourceAttr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663218692165626"><a name="p663218692165626"></a><a name="p663218692165626"></a>Defines the attributes of a tree node in the configuration tree. </p>
</td>
</tr>
<tr id="row294364227165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p863968857165626"><a name="p863968857165626"></a><a name="p863968857165626"></a><a href="DeviceResourceNode.md">DeviceResourceNode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91202695165626"><a name="p91202695165626"></a><a name="p91202695165626"></a>Defines a tree node in the configuration tree. </p>
</td>
</tr>
<tr id="row1634224646165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p407215229165626"><a name="p407215229165626"></a><a name="p407215229165626"></a><a href="DeviceResourceIface.md">DeviceResourceIface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187879497165626"><a name="p187879497165626"></a><a name="p187879497165626"></a>Provides functions for obtaining information about the device resource configuration tree. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table728607486165626"></a>
<table><thead align="left"><tr id="row1908643703165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p46820464165626"><a name="p46820464165626"></a><a name="p46820464165626"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1555824671165626"><a name="p1555824671165626"></a><a name="p1555824671165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1253195168165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495905341165626"><a name="p1495905341165626"></a><a name="p1495905341165626"></a><a href="DriverConfig.md#gaea582d01be42ff534e33b0484094af9b">DEV_RES_NODE_FOR_EACH_ATTR</a>(node, attr)   for ((attr) = (node)-&gt;attrData; (attr) != <a href="UTILS.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4">NULL</a>; (attr) = (attr)-&gt;next)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031193880165626"><a name="p2031193880165626"></a><a name="p2031193880165626"></a>Traverses the attributes of the current configuration tree node. </p>
</td>
</tr>
<tr id="row2060518293165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972211754165626"><a name="p972211754165626"></a><a name="p972211754165626"></a><a href="DriverConfig.md#ga1b848db724617a3cf0e5b3f2453b8846">DEV_RES_NODE_FOR_EACH_CHILD_NODE</a>(node, childNode)   for ((childNode) = (node)-&gt;child; (childNode) != <a href="UTILS.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4">NULL</a>; (childNode) = (childNode)-&gt;sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p146441881165626"><a name="p146441881165626"></a><a name="p146441881165626"></a>Traverses the child nodes of the current configuration tree node. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1155683440165626"></a>
<table><thead align="left"><tr id="row1762127024165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1797781587165626"><a name="p1797781587165626"></a><a name="p1797781587165626"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p671775454165626"><a name="p671775454165626"></a><a name="p671775454165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row183654441165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1377466239165626"><a name="p1377466239165626"></a><a name="p1377466239165626"></a><a href="DriverConfig.md#ga09c9585a5d95c79fd5ee4bd8863ba66a">DeviceResourceType</a> { <a href="DriverConfig.md#gga09c9585a5d95c79fd5ee4bd8863ba66aa7827b61588e550672bc41a3710e13ce9">HDF_CONFIG_SOURCE</a> = 0, <a href="DriverConfig.md#gga09c9585a5d95c79fd5ee4bd8863ba66aaef2863a469df3ea6871d640e3669a2f2">INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1539772760165626"><a name="p1539772760165626"></a><a name="p1539772760165626"></a>Enumerates configuration file types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1238964497165626"></a>
<table><thead align="left"><tr id="row339992848165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1387071279165626"><a name="p1387071279165626"></a><a name="p1387071279165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p897278491165626"><a name="p897278491165626"></a><a name="p897278491165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row100259917165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1224020343165626"><a name="p1224020343165626"></a><a name="p1224020343165626"></a><a href="DriverConfig.md#gabfbfb1ffec32f04e8f3660eadb7677a0">DeviceResourceGetIfaceInstance</a> (<a href="DriverConfig.md#ga09c9585a5d95c79fd5ee4bd8863ba66a">DeviceResourceType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572069130165626"><a name="p572069130165626"></a><a name="p572069130165626"></a>struct <a href="DeviceResourceIface.md">DeviceResourceIface</a> * </p>
<p id="p1626260806165626"><a name="p1626260806165626"></a><a name="p1626260806165626"></a>Obtains the device resource interface handle of the corresponding configuration tree type. </p>
</td>
</tr>
</tbody>
</table>

