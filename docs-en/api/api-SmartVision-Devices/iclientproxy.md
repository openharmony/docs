# IClientProxy<a name="EN-US_TOPIC_0000001054918157"></a>

-   [Overview](#section1650213286165631)
-   [Summary](#section984856840165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1736297768165631)
-   [Field](#section1786390938165631)
-   [INHERIT\_IUNKNOWN](#ac0ffdbb3582a99ba237a70d26320075b)
-   [Invoke](#a18d8a9e57b05be9fd3e5772e445f474d)

## **Overview**<a name="section1650213286165631"></a>

**Related Modules:**

[Registry](registry.md)

**Description:**

Defines the client proxy object. 

This object is used for the IPC with the server. If you want to use the same invocation mode as that on the server, create an object inherited from

[IClientProxy](iclientproxy.md) 

 and implement serialization.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section984856840165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table809692225165631"></a>
<table><thead align="left"><tr id="row99312297165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p194875103165631"><a name="p194875103165631"></a><a name="p194875103165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2121963391165631"><a name="p2121963391165631"></a><a name="p2121963391165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1091272318165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117247223165631"><a name="p1117247223165631"></a><a name="p1117247223165631"></a><a href="iclientproxy.md#ac0ffdbb3582a99ba237a70d26320075b">INHERIT_IUNKNOWN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;&nbsp;</td>
</tr>
<tr id="row2063358132165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1690664274165631"><a name="p1690664274165631"></a><a name="p1690664274165631"></a><a href="iclientproxy.md#a18d8a9e57b05be9fd3e5772e445f474d">Invoke</a> )(<a href="iclientproxy.md">IClientProxy</a> *proxy, int funcId, IpcIo *request, IOwner owner, <a href="registry.md#ga362a17c1bda1aace88d42dcbc88bdfac">INotify</a> notify)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249805385165631"><a name="p249805385165631"></a><a name="p249805385165631"></a>int(* </p>
<p id="p1022821655165631"><a name="p1022821655165631"></a><a name="p1022821655165631"></a>Sends an IPC message from the client to the <strong id="b1871402066165631"><a name="b1871402066165631"></a><a name="b1871402066165631"></a><a href="iserverproxy.md">IServerProxy</a></strong>. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1736297768165631"></a>

## **Field **<a name="section1786390938165631"></a>

## INHERIT\_IUNKNOWN<a name="ac0ffdbb3582a99ba237a70d26320075b"></a>

```
IClientProxy::INHERIT_IUNKNOWN
```

 **Description:**

Inherites the  **[IUnknown](iunknown.md)**  base class. 

## Invoke<a name="a18d8a9e57b05be9fd3e5772e445f474d"></a>

```
int(* IClientProxy::Invoke) ([IClientProxy](iclientproxy.md) *proxy, int funcId, IpcIo *request, IOwner owner, [INotify](registry.md#ga362a17c1bda1aace88d42dcbc88bdfac) notify)
```

 **Description:**

Sends an IPC message from the client to the  **[IServerProxy](iserverproxy.md)**. 

This function is used for IPC. The passed  **proxy**  is used to obtain the server information. Then,  **request**  carries the request message to be sent to the server and processed by the function specified by  **funcId**.  **notify**  is a callback function used to process the response message. 

**Parameters:**

<a name="table712976976165631"></a>
<table><thead align="left"><tr id="row1816280158165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p858917523165631"><a name="p858917523165631"></a><a name="p858917523165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2038840638165631"><a name="p2038840638165631"></a><a name="p2038840638165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1286737312165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">proxy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer of the client proxy object. </td>
</tr>
<tr id="row812705893165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">funcId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of the function implemented on the server. </td>
</tr>
<tr id="row130176343165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">request</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the serialized request message. </td>
</tr>
<tr id="row1331218135165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">owner</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the receiver (generics type) of the response message. </td>
</tr>
<tr id="row1718149606165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">notify</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the callback function that notifies the client of the response message. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the IPC message is sent successfully; returns other error codes if the message fails to be sent. 

