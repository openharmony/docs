# DriverConfig<a name="EN-US_TOPIC_0000001055678040"></a>

-   [Overview](#section343659875165623)
-   [Summary](#section758624607165623)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)
-   [Details](#section1336663313165623)
-   [Macro Definition](#section1194593549165623)
-   [DEV\_RES\_NODE\_FOR\_EACH\_ATTR](#gaea582d01be42ff534e33b0484094af9b)
-   [DEV\_RES\_NODE\_FOR\_EACH\_CHILD\_NODE](#ga1b848db724617a3cf0e5b3f2453b8846)
-   [Enumeration Type](#section1597354189165623)
-   [DeviceResourceType](#ga09c9585a5d95c79fd5ee4bd8863ba66a)
-   [Function](#section240152397165623)
-   [DeviceResourceGetIfaceInstance\(\)](#gabfbfb1ffec32f04e8f3660eadb7677a0)

## **Overview**<a name="section343659875165623"></a>

**Description:**

Defines an API for HDF driver developers to read driver configuration information. 

During version compilation of the device resource source file defined by developers, the compilation tool \(for example, the compilation tool of the HCS file is hc-gen\) generates bytecodes. When the HDF starts, it transfers the bytecode memory to the  **DriverConfig**  module. The  **DriverConfig**  module converts the bytecodes into a configuration tree and provides an API for developers to query the tree.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section758624607165623"></a>

## Files<a name="files"></a>

<a name="table1657814011165623"></a>
<table><thead align="left"><tr id="row37805738165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p68418642165623"><a name="p68418642165623"></a><a name="p68418642165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1433241240165623"><a name="p1433241240165623"></a><a name="p1433241240165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1135184966165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212914934165623"><a name="p212914934165623"></a><a name="p212914934165623"></a><a href="device_resource_if-h.md">device_resource_if.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271100745165623"><a name="p1271100745165623"></a><a name="p1271100745165623"></a>Declares the API for querying the configuration tree. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table1112946833165623"></a>
<table><thead align="left"><tr id="row527727034165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1296238104165623"><a name="p1296238104165623"></a><a name="p1296238104165623"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1450991747165623"><a name="p1450991747165623"></a><a name="p1450991747165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row400405190165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011417945165623"><a name="p2011417945165623"></a><a name="p2011417945165623"></a><a href="deviceresourceattr.md">DeviceResourceAttr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498698976165623"><a name="p1498698976165623"></a><a name="p1498698976165623"></a>Defines the attributes of a tree node in the configuration tree. </p>
</td>
</tr>
<tr id="row766906359165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1080653117165623"><a name="p1080653117165623"></a><a name="p1080653117165623"></a><a href="deviceresourcenode.md">DeviceResourceNode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p604111219165623"><a name="p604111219165623"></a><a name="p604111219165623"></a>Defines a tree node in the configuration tree. </p>
</td>
</tr>
<tr id="row446544060165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1271213401165623"><a name="p1271213401165623"></a><a name="p1271213401165623"></a><a href="deviceresourceiface.md">DeviceResourceIface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462829499165623"><a name="p462829499165623"></a><a name="p462829499165623"></a>Provides functions for obtaining information about the device resource configuration tree. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table1585419762165623"></a>
<table><thead align="left"><tr id="row121607440165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p98919430165623"><a name="p98919430165623"></a><a name="p98919430165623"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1797152129165623"><a name="p1797152129165623"></a><a name="p1797152129165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1512440277165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p677285085165623"><a name="p677285085165623"></a><a name="p677285085165623"></a><a href="driverconfig.md#gaea582d01be42ff534e33b0484094af9b">DEV_RES_NODE_FOR_EACH_ATTR</a>(node, attr)   for ((attr) = (node)-&gt;attrData; (attr) != <a href="utils.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4">NULL</a>; (attr) = (attr)-&gt;next)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778105460165623"><a name="p778105460165623"></a><a name="p778105460165623"></a>Traverses the attributes of the current configuration tree node. </p>
</td>
</tr>
<tr id="row127066267165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2030945638165623"><a name="p2030945638165623"></a><a name="p2030945638165623"></a><a href="driverconfig.md#ga1b848db724617a3cf0e5b3f2453b8846">DEV_RES_NODE_FOR_EACH_CHILD_NODE</a>(node, childNode)   for ((childNode) = (node)-&gt;child; (childNode) != <a href="utils.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4">NULL</a>; (childNode) = (childNode)-&gt;sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226425803165623"><a name="p1226425803165623"></a><a name="p1226425803165623"></a>Traverses the child nodes of the current configuration tree node. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table575332457165623"></a>
<table><thead align="left"><tr id="row1454246535165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p198072466165623"><a name="p198072466165623"></a><a name="p198072466165623"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p177893410165623"><a name="p177893410165623"></a><a name="p177893410165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row869641416165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1415174002165623"><a name="p1415174002165623"></a><a name="p1415174002165623"></a><a href="driverconfig.md#ga09c9585a5d95c79fd5ee4bd8863ba66a">DeviceResourceType</a> { <a href="driverconfig.md#gga09c9585a5d95c79fd5ee4bd8863ba66aa7827b61588e550672bc41a3710e13ce9">HDF_CONFIG_SOURCE</a> = 0, <a href="driverconfig.md#gga09c9585a5d95c79fd5ee4bd8863ba66aaef2863a469df3ea6871d640e3669a2f2">INVALID</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490408716165623"><a name="p1490408716165623"></a><a name="p1490408716165623"></a>Enumerates configuration file types. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1321507283165623"></a>
<table><thead align="left"><tr id="row2079073621165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p190151278165623"><a name="p190151278165623"></a><a name="p190151278165623"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1569692277165623"><a name="p1569692277165623"></a><a name="p1569692277165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row84819539165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p285347206165623"><a name="p285347206165623"></a><a name="p285347206165623"></a><a href="driverconfig.md#gabfbfb1ffec32f04e8f3660eadb7677a0">DeviceResourceGetIfaceInstance</a> (<a href="driverconfig.md#ga09c9585a5d95c79fd5ee4bd8863ba66a">DeviceResourceType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787875800165623"><a name="p787875800165623"></a><a name="p787875800165623"></a>struct <a href="deviceresourceiface.md">DeviceResourceIface</a> * </p>
<p id="p196037390165623"><a name="p196037390165623"></a><a name="p196037390165623"></a>Obtains the device resource interface handle of the corresponding configuration tree type. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1336663313165623"></a>

## **Macro Definition **<a name="section1194593549165623"></a>

## DEV\_RES\_NODE\_FOR\_EACH\_ATTR<a name="gaea582d01be42ff534e33b0484094af9b"></a>

```
#define DEV_RES_NODE_FOR_EACH_ATTR( node,  attr )   for ((attr) = (node)->attrData; (attr) != [NULL](utils.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4); (attr) = (attr)->next)
```

 **Description:**

Traverses the attributes of the current configuration tree node. 

This operation is a  **for**  loop in essence.

**Parameters:**

<a name="table1795313923165623"></a>
<table><thead align="left"><tr id="row1620278329165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p448098370165623"><a name="p448098370165623"></a><a name="p448098370165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1679107037165623"><a name="p1679107037165623"></a><a name="p1679107037165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1611780291165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the configuration tree node to traverse. </td>
</tr>
<tr id="row1324655113165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">attr</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the traversed attributes. </td>
</tr>
</tbody>
</table>

## DEV\_RES\_NODE\_FOR\_EACH\_CHILD\_NODE<a name="ga1b848db724617a3cf0e5b3f2453b8846"></a>

```
#define DEV_RES_NODE_FOR_EACH_CHILD_NODE( node,  childNode )   for ((childNode) = (node)->child; (childNode) != [NULL](utils.md#ga070d2ce7b6bb7e5c05602aa8c308d0c4); (childNode) = (childNode)->sibling)
```

 **Description:**

Traverses the child nodes of the current configuration tree node. 

This operation is a  **for**  loop in essence.

**Parameters:**

<a name="table1488664231165623"></a>
<table><thead align="left"><tr id="row364776976165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1050004596165623"><a name="p1050004596165623"></a><a name="p1050004596165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1499101972165623"><a name="p1499101972165623"></a><a name="p1499101972165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1988776191165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">node</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the configuration tree node to traverse. </td>
</tr>
<tr id="row985516923165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">childNode</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the traversed child nodes. </td>
</tr>
</tbody>
</table>

## **Enumeration Type **<a name="section1597354189165623"></a>

## DeviceResourceType<a name="ga09c9585a5d95c79fd5ee4bd8863ba66a"></a>

```
enum [DeviceResourceType](driverconfig.md#ga09c9585a5d95c79fd5ee4bd8863ba66a)
```

 **Description:**

Enumerates configuration file types. 

<a name="table1822043582165623"></a>
<table><thead align="left"><tr id="row1824715035165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p625206914165623"><a name="p625206914165623"></a><a name="p625206914165623"></a>Enumerator</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1617748688165623"><a name="p1617748688165623"></a><a name="p1617748688165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row719992399165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga09c9585a5d95c79fd5ee4bd8863ba66aa7827b61588e550672bc41a3710e13ce9"><a name="gga09c9585a5d95c79fd5ee4bd8863ba66aa7827b61588e550672bc41a3710e13ce9"></a><a name="gga09c9585a5d95c79fd5ee4bd8863ba66aa7827b61588e550672bc41a3710e13ce9"></a></strong>HDF_CONFIG_SOURCE </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137888993165623"><a name="p137888993165623"></a><a name="p137888993165623"></a>HDF configuration file </p>
 </td>
</tr>
<tr id="row1161247209165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><strong id="gga09c9585a5d95c79fd5ee4bd8863ba66aaef2863a469df3ea6871d640e3669a2f2"><a name="gga09c9585a5d95c79fd5ee4bd8863ba66aaef2863a469df3ea6871d640e3669a2f2"></a><a name="gga09c9585a5d95c79fd5ee4bd8863ba66aaef2863a469df3ea6871d640e3669a2f2"></a></strong>INVALID </td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493138798165623"><a name="p1493138798165623"></a><a name="p1493138798165623"></a>Invalid configuration file type </p>
 </td>
</tr>
</tbody>
</table>

## **Function **<a name="section240152397165623"></a>

## DeviceResourceGetIfaceInstance\(\)<a name="gabfbfb1ffec32f04e8f3660eadb7677a0"></a>

```
struct [DeviceResourceIface](deviceresourceiface.md)* DeviceResourceGetIfaceInstance ([DeviceResourceType](driverconfig.md#ga09c9585a5d95c79fd5ee4bd8863ba66a) type)
```

 **Description:**

Obtains the device resource interface handle of the corresponding configuration tree type. 

You can use the obtained handle to use the device resource interface.

**Parameters:**

<a name="table960969779165623"></a>
<table><thead align="left"><tr id="row1551484185165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1872940341165623"><a name="p1872940341165623"></a><a name="p1872940341165623"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1328879017165623"><a name="p1328879017165623"></a><a name="p1328879017165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1041018166165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the type of the device resource interface handle to obtain.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns the device resource interface handle if the operation is successful; returns  **NULL**  otherwise. 

