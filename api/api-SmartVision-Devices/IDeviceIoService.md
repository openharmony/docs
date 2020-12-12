# IDeviceIoService<a name="ZH-CN_TOPIC_0000001055198134"></a>

-   [Overview](#section2117197142165632)
-   [Summary](#section98086035165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1152369888165632)
-   [Field](#section1851010388165632)
-   [Dispatch](#acbd0a5848800672aaa0048b73ab725c8)
-   [object](#ae79da6a452d1b93d09f1a034a4a7c8d2)
-   [Open](#aa655b184dee58c697cd25c9a7367d401)
-   [Release](#a45681535736fb530c71da45a259aa128)

## **Overview**<a name="section2117197142165632"></a>

**Related Modules:**

[Core](Core.md)

**Description:**

Defines the driver service. 

When a driver releases services to user-level applications, the service interface must inherit this structure and implements the  **Dispatch**  function in the structure.

**Since:**

1.0

## **Summary**<a name="section98086035165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1630265638165632"></a>
<table><thead align="left"><tr id="row188983284165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p418702276165632"><a name="p418702276165632"></a><a name="p418702276165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p185730751165632"><a name="p185730751165632"></a><a name="p185730751165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1907371823165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1731209789165632"><a name="p1731209789165632"></a><a name="p1731209789165632"></a><a href="IDeviceIoService.md#ae79da6a452d1b93d09f1a034a4a7c8d2">object</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174766994165632"><a name="p174766994165632"></a><a name="p174766994165632"></a>struct <a href="HdfObject.md">HdfObject</a> </p>
</td>
</tr>
<tr id="row205659898165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p977256284165632"><a name="p977256284165632"></a><a name="p977256284165632"></a><a href="IDeviceIoService.md#aa655b184dee58c697cd25c9a7367d401">Open</a> )(struct <a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a> *client)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454875078165632"><a name="p454875078165632"></a><a name="p454875078165632"></a>int32_t(* </p>
<p id="p358896457165632"><a name="p358896457165632"></a><a name="p358896457165632"></a>Called when the driver service is enabled by a user-level application. </p>
</td>
</tr>
<tr id="row403732911165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p215703170165632"><a name="p215703170165632"></a><a name="p215703170165632"></a><a href="IDeviceIoService.md#acbd0a5848800672aaa0048b73ab725c8">Dispatch</a> )(struct <a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a> *client, int cmdId, struct <a href="HdfSBuf.md">HdfSBuf</a> *data, struct <a href="HdfSBuf.md">HdfSBuf</a> *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700753259165632"><a name="p1700753259165632"></a><a name="p1700753259165632"></a>int32_t(* </p>
<p id="p1146207706165632"><a name="p1146207706165632"></a><a name="p1146207706165632"></a>Called when the driver service is invoked by a user-level application. </p>
</td>
</tr>
<tr id="row1809819884165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1898930514165632"><a name="p1898930514165632"></a><a name="p1898930514165632"></a><a href="IDeviceIoService.md#a45681535736fb530c71da45a259aa128">Release</a> )(struct <a href="HdfDeviceIoClient.md">HdfDeviceIoClient</a> *client)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1348865475165632"><a name="p1348865475165632"></a><a name="p1348865475165632"></a>void(* </p>
<p id="p360571340165632"><a name="p360571340165632"></a><a name="p360571340165632"></a>Called when the driver service is released by a user-level application. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1152369888165632"></a>

## **Field **<a name="section1851010388165632"></a>

## Dispatch<a name="acbd0a5848800672aaa0048b73ab725c8"></a>

```
int32_t(* IDeviceIoService::Dispatch) (struct [HdfDeviceIoClient](HdfDeviceIoClient.md) *client, int cmdId, struct [HdfSBuf](HdfSBuf.md) *data, struct [HdfSBuf](HdfSBuf.md) *reply)
```

 **Description:**

Called when the driver service is invoked by a user-level application. 

**Parameters:**

<a name="table1930547923165632"></a>
<table><thead align="left"><tr id="row689507938165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p679138155165632"><a name="p679138155165632"></a><a name="p679138155165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1424046246165632"><a name="p1424046246165632"></a><a name="p1424046246165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row275163243165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">client</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the client object of the service. </td>
</tr>
<tr id="row1328423306165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">cmdId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the command word of the service interface. </td>
</tr>
<tr id="row1061425422165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">data</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data passed by the invoker. </td>
</tr>
<tr id="row1329212757165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">reply</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the data that needs to be returned to the invoker. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## object<a name="ae79da6a452d1b93d09f1a034a4a7c8d2"></a>

```
struct [HdfObject](HdfObject.md) IDeviceIoService::object
```

 **Description:**

Driver service object ID 

## Open<a name="aa655b184dee58c697cd25c9a7367d401"></a>

```
int32_t(* IDeviceIoService::Open) (struct [HdfDeviceIoClient](HdfDeviceIoClient.md) *client)
```

 **Description:**

Called when the driver service is enabled by a user-level application. 

**Parameters:**

<a name="table1429628443165632"></a>
<table><thead align="left"><tr id="row833774466165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p673729482165632"><a name="p673729482165632"></a><a name="p673729482165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2138872348165632"><a name="p2138872348165632"></a><a name="p2138872348165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1363480230165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">client</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the client object of the service. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a negative value otherwise.

## Release<a name="a45681535736fb530c71da45a259aa128"></a>

```
void(* IDeviceIoService::Release) (struct [HdfDeviceIoClient](HdfDeviceIoClient.md) *client)
```

 **Description:**

Called when the driver service is released by a user-level application. 

**Parameters:**

<a name="table604817128165632"></a>
<table><thead align="left"><tr id="row1106492927165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p796204769165632"><a name="p796204769165632"></a><a name="p796204769165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p992357285165632"><a name="p992357285165632"></a><a name="p992357285165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1645574269165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">client</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the client object of the service.</td>
</tr>
</tbody>
</table>

