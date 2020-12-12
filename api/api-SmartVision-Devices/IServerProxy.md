# IServerProxy<a name="ZH-CN_TOPIC_0000001054718129"></a>

-   [Overview](#section677920033165631)
-   [Summary](#section420049199165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1818799670165631)
-   [Field](#section1007420859165631)
-   [INHERIT\_IUNKNOWN](#a98683c7eaf7a11036cddf8207ddcadbe)
-   [Invoke](#a0275e8b826a3de89ab9021906c8360a7)

## **Overview**<a name="section677920033165631"></a>

**Related Modules:**

[Registry](Registry.md)

**Description:**

Defines the base class of the server proxy object. 

When the server provides cross-process system capabilities, it uses  **INHERIT\_SERVER\_IPROXY**  to define the server proxy. 

## **Summary**<a name="section420049199165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table187500545165631"></a>
<table><thead align="left"><tr id="row2023798006165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1514483581165631"><a name="p1514483581165631"></a><a name="p1514483581165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1525455165631"><a name="p1525455165631"></a><a name="p1525455165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1581957203165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112960641165631"><a name="p1112960641165631"></a><a name="p1112960641165631"></a><a href="IServerProxy.md#a98683c7eaf7a11036cddf8207ddcadbe">INHERIT_IUNKNOWN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;&nbsp;</td>
</tr>
<tr id="row347393666165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2135296985165631"><a name="p2135296985165631"></a><a name="p2135296985165631"></a><a href="IServerProxy.md#a0275e8b826a3de89ab9021906c8360a7">Invoke</a> )(<a href="IServerProxy.md">IServerProxy</a> *iProxy, int funcId, void *origin, IpcIo *req, IpcIo *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1949102423165631"><a name="p1949102423165631"></a><a name="p1949102423165631"></a>int32(* </p>
<p id="p1183333081165631"><a name="p1183333081165631"></a><a name="p1183333081165631"></a>Unmarshals the IPC message received by the server. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1818799670165631"></a>

## **Field **<a name="section1007420859165631"></a>

## INHERIT\_IUNKNOWN<a name="a98683c7eaf7a11036cddf8207ddcadbe"></a>

```
IServerProxy::INHERIT_IUNKNOWN
```

 **Description:**

This class inherits from  **[IUnknown](IUnknown.md)**. 

## Invoke<a name="a0275e8b826a3de89ab9021906c8360a7"></a>

```
int32(* IServerProxy::Invoke) ([IServerProxy](IServerProxy.md) *iProxy, int funcId, void *origin, IpcIo *req, IpcIo *reply)
```

 **Description:**

Unmarshals the IPC message received by the server. 

This function is implemented by developers and called by the system. This function runs in the message processing thread of the service. Do not block the message processing thread; otherwise, the function may fail to be executed. 

**Parameters:**

<a name="table1061244579165631"></a>
<table><thead align="left"><tr id="row560708721165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1304091566165631"><a name="p1304091566165631"></a><a name="p1304091566165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1271339767165631"><a name="p1271339767165631"></a><a name="p1271339767165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row151925477165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">Proxy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the server proxy object. </td>
</tr>
<tr id="row870580262165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">funcId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the server function to be invoked by the client. </td>
</tr>
<tr id="row1670411544165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">origin</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the original IPC message, from which the header information can be obtained. </td>
</tr>
<tr id="row1104739532165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">req</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">ipc Indicates the message body, from which data can be obtained. </td>
</tr>
<tr id="row1691871887165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">reply</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the output parameter, which is used to respond to the message. The value can contain a maximum of five objects and 200 bytes. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the unmarshalling is successful; returns other error codes if the unmarshalling fails. 

