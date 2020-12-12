# hdf\_io\_service\_if.h<a name="EN-US_TOPIC_0000001055518058"></a>

-   [Overview](#section45843369165627)
-   [Summary](#section1743319531165627)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section45843369165627"></a>

**Related Modules:**

[Core](core.md)

**Description:**

Declares the structures defining driver service objects and event listeners, as well as the functions for obtaining a driver service object, dispatching a driver service call, and registering or unregistering an event listener. 

**Since:**

1.0

## **Summary**<a name="section1743319531165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1580004011165627"></a>
<table><thead align="left"><tr id="row1777373577165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1682212153165627"><a name="p1682212153165627"></a><a name="p1682212153165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1004792500165627"><a name="p1004792500165627"></a><a name="p1004792500165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row466386293165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846236552165627"><a name="p846236552165627"></a><a name="p846236552165627"></a><a href="hdfdeveventlistener.md">HdfDevEventlistener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383025515165627"><a name="p383025515165627"></a><a name="p383025515165627"></a>Defines a driver event listener object. </p>
</td>
</tr>
<tr id="row294300030165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1886097510165627"><a name="p1886097510165627"></a><a name="p1886097510165627"></a><a href="hdfiodispatcher.md">HdfIoDispatcher</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1009488061165627"><a name="p1009488061165627"></a><a name="p1009488061165627"></a>Defines a driver service call dispatcher. </p>
</td>
</tr>
<tr id="row1411723482165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522089433165627"><a name="p1522089433165627"></a><a name="p1522089433165627"></a><a href="hdfioservice.md">HdfIoService</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541230719165627"><a name="p1541230719165627"></a><a name="p1541230719165627"></a>Defines a driver service object. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table260779499165627"></a>
<table><thead align="left"><tr id="row1226278364165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p244157430165627"><a name="p244157430165627"></a><a name="p244157430165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1131105365165627"><a name="p1131105365165627"></a><a name="p1131105365165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row906101625165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406819354165627"><a name="p1406819354165627"></a><a name="p1406819354165627"></a><a href="core.md#gae314b850ba4b0927007038cf8cc32580">OnEventReceived</a>) (void *priv, uint32_t id, struct <a href="hdfsbuf.md">HdfSBuf</a> *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403491551165627"><a name="p403491551165627"></a><a name="p403491551165627"></a>typedef int(* </p>
<p id="p1744543506165627"><a name="p1744543506165627"></a><a name="p1744543506165627"></a>Called when a driver event occurs. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1635237119165627"></a>
<table><thead align="left"><tr id="row1138783083165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1591774968165627"><a name="p1591774968165627"></a><a name="p1591774968165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1030766697165627"><a name="p1030766697165627"></a><a name="p1030766697165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2113549959165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1240662648165627"><a name="p1240662648165627"></a><a name="p1240662648165627"></a><a href="core.md#ga31198b68423805193274d3973c178ab5">HdfIoServiceBind</a> (const char *serviceName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646422870165627"><a name="p1646422870165627"></a><a name="p1646422870165627"></a>struct <a href="hdfioservice.md">HdfIoService</a> * </p>
<p id="p1200616951165627"><a name="p1200616951165627"></a><a name="p1200616951165627"></a>Obtains a driver service object. </p>
</td>
</tr>
<tr id="row921269320165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708137702165627"><a name="p1708137702165627"></a><a name="p1708137702165627"></a><a href="core.md#gada2867af690aac9e6c3b2c8812b3037c">HdfIoServiceRecycle</a> (struct <a href="hdfioservice.md">HdfIoService</a> *service)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273754538165627"><a name="p273754538165627"></a><a name="p273754538165627"></a>void </p>
<p id="p1409893224165627"><a name="p1409893224165627"></a><a name="p1409893224165627"></a>Destroys a specified driver service object to release resources if it is no longer required. </p>
</td>
</tr>
<tr id="row803043719165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501071808165627"><a name="p1501071808165627"></a><a name="p1501071808165627"></a><a href="core.md#gaa7855b3930b5378954927548e5623663">HdfDeviceRegisterEventListener</a> (struct <a href="hdfioservice.md">HdfIoService</a> *target, struct <a href="hdfdeveventlistener.md">HdfDevEventlistener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1881333920165627"><a name="p1881333920165627"></a><a name="p1881333920165627"></a>int </p>
<p id="p1339322795165627"><a name="p1339322795165627"></a><a name="p1339322795165627"></a>Registers a custom <a href="hdfdeveventlistener.md">HdfDevEventlistener</a> for listening for events reported by a specified driver service object. </p>
</td>
</tr>
<tr id="row539671251165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p547211992165627"><a name="p547211992165627"></a><a name="p547211992165627"></a><a href="core.md#gab95668359f0b6a47f48c47541caed7fd">HdfDeviceUnregisterEventListener</a> (struct <a href="hdfioservice.md">HdfIoService</a> *target, struct <a href="hdfdeveventlistener.md">HdfDevEventlistener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1000127133165627"><a name="p1000127133165627"></a><a name="p1000127133165627"></a>int </p>
<p id="p453607185165627"><a name="p453607185165627"></a><a name="p453607185165627"></a>Unregisters a previously registered <a href="hdfdeveventlistener.md">HdfDevEventlistener</a> to release resources if it is no longer required. </p>
</td>
</tr>
</tbody>
</table>

