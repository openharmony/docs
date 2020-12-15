# Registry<a name="EN-US_TOPIC_0000001055358060"></a>

-   [Overview](#section1024898275165625)
-   [Summary](#section997159289165625)
-   [Files](#files)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)
-   [Details](#section473233789165625)
-   [Macro Definition](#section353553314165625)
-   [INHERIT\_CLIENT\_IPROXY](#ga86734e6a03eb089309e87ec628002034)
-   [INHERIT\_IPROXY\_ENTRY](#ga9ad9b5f0e1f50f2528cbef67957b2319)
-   [INHERIT\_SERVER\_IPROXY](#ga58e6d24ef278dceb3fb9c77527acdb5c)
-   [IPROXY\_END](#ga59b6c10043506af716ce9052a5a964a7)
-   [SERVER\_IPROXY\_BEGIN](#ga3c3f1e77cc1a495f48a4b3cd0f8934be)
-   [SERVER\_PROXY\_VER](#gad513d97bfb873f27c9b8f69a5a418d55)
-   [Typedef](#section172190079165625)
-   [Creator](#ga0c8aa2ef9883bd97b4f1309895adaa4c)
-   [Destroyer](#ga1e6298b1246357f70ad0b581e0eb9305)
-   [INotify](#ga362a17c1bda1aace88d42dcbc88bdfac)
-   [Function](#section890168117165625)
-   [SAMGR\_GetRemoteIdentity\(\)](#gaa9bb385bfe593f4377a83cf513189bf1)
-   [SAMGR\_RegisterFactory\(\)](#ga64797e3f63201c40dbdf21b90cff23d2)

## **Overview**<a name="section1024898275165625"></a>

**Description:**

Provides APIs for registering and discovering inter-process communication \(IPC\) capabilities. 

Based on the Samgr development framework, this module helps you to develop system capabilities and implement cross-process calls. This module is used when system capabilities need to be provided across processes. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section997159289165625"></a>

## Files<a name="files"></a>

<a name="table493499241165625"></a>
<table><thead align="left"><tr id="row1429222307165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1092312736165625"><a name="p1092312736165625"></a><a name="p1092312736165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1759310616165625"><a name="p1759310616165625"></a><a name="p1759310616165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1809954868165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565370045165625"><a name="p1565370045165625"></a><a name="p1565370045165625"></a><a href="iproxy_client-h.md">iproxy_client.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p205442939165625"><a name="p205442939165625"></a><a name="p205442939165625"></a>Provides the client proxy class. </p>
</td>
</tr>
<tr id="row1535531797165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p716492864165625"><a name="p716492864165625"></a><a name="p716492864165625"></a><a href="iproxy_server-h.md">iproxy_server.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p681335735165625"><a name="p681335735165625"></a><a name="p681335735165625"></a>Provides the server proxy. </p>
</td>
</tr>
<tr id="row2085722168165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664826449165625"><a name="p664826449165625"></a><a name="p664826449165625"></a><a href="registry-h.md">registry.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653993481165625"><a name="p1653993481165625"></a><a name="p1653993481165625"></a>Provides basic APIs for remote service registration and discovery. </p>
</td>
</tr>
</tbody>
</table>

## Data Structures<a name="nested-classes"></a>

<a name="table670496496165625"></a>
<table><thead align="left"><tr id="row1889835842165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2115006782165625"><a name="p2115006782165625"></a><a name="p2115006782165625"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2005583723165625"><a name="p2005583723165625"></a><a name="p2005583723165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row157248250165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423204064165625"><a name="p1423204064165625"></a><a name="p1423204064165625"></a><a href="iclientproxy.md">IClientProxy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756842577165625"><a name="p756842577165625"></a><a name="p756842577165625"></a>Defines the client proxy object. </p>
</td>
</tr>
<tr id="row178824933165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461062001165625"><a name="p1461062001165625"></a><a name="p1461062001165625"></a><a href="iserverproxy.md">IServerProxy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p670637049165625"><a name="p670637049165625"></a><a name="p670637049165625"></a>Defines the base class of the server proxy object. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table329117510165625"></a>
<table><thead align="left"><tr id="row1057287365165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p224024463165625"><a name="p224024463165625"></a><a name="p224024463165625"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p915370052165625"><a name="p915370052165625"></a><a name="p915370052165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row608055959165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896351753165625"><a name="p896351753165625"></a><a name="p896351753165625"></a><a href="registry.md#ga86734e6a03eb089309e87ec628002034">INHERIT_CLIENT_IPROXY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1510093768165625"><a name="p1510093768165625"></a><a name="p1510093768165625"></a>Indicates the inherited macro of the client proxy. </p>
</td>
</tr>
<tr id="row1981336978165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p634880485165625"><a name="p634880485165625"></a><a name="p634880485165625"></a><a href="registry.md#ga9ad9b5f0e1f50f2528cbef67957b2319">INHERIT_IPROXY_ENTRY</a>(T)   <a href="samgr.md#gad6324fd90dd636180efa2a59b377e65c">INHERIT_IUNKNOWNENTRY</a>(T)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876601801165625"><a name="p1876601801165625"></a><a name="p1876601801165625"></a>Inherits the server proxy class. </p>
</td>
</tr>
<tr id="row15204396165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102809050165625"><a name="p2102809050165625"></a><a name="p2102809050165625"></a><a href="registry.md#ga59b6c10043506af716ce9052a5a964a7">IPROXY_END</a>   <a href="samgr.md#ga4ef734474ece49aa938d8ebd5b54bdb3">IUNKNOWN_ENTRY_END</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p539284945165625"><a name="p539284945165625"></a><a name="p539284945165625"></a>Defines the end of the default initialization for the server proxy class. </p>
</td>
</tr>
<tr id="row1690940743165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1624856570165625"><a name="p1624856570165625"></a><a name="p1624856570165625"></a><a href="registry.md#gad513d97bfb873f27c9b8f69a5a418d55">SERVER_PROXY_VER</a>   0x80</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474056086165625"><a name="p474056086165625"></a><a name="p474056086165625"></a>Defines the default version number of the server proxy. </p>
</td>
</tr>
<tr id="row67676281165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p248525762165625"><a name="p248525762165625"></a><a name="p248525762165625"></a><a href="registry.md#ga58e6d24ef278dceb3fb9c77527acdb5c">INHERIT_SERVER_IPROXY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1701494463165625"><a name="p1701494463165625"></a><a name="p1701494463165625"></a>Inherits the server proxy function. </p>
</td>
</tr>
<tr id="row1979119020165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1899394885165625"><a name="p1899394885165625"></a><a name="p1899394885165625"></a><a href="registry.md#ga3c3f1e77cc1a495f48a4b3cd0f8934be">SERVER_IPROXY_BEGIN</a>   <a href="samgr.md#ga52ec6b5b03d56b0dfe7277785246bda1">IUNKNOWN_ENTRY_BEGIN</a>(<a href="registry.md#gad513d97bfb873f27c9b8f69a5a418d55">SERVER_PROXY_VER</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1678467396165625"><a name="p1678467396165625"></a><a name="p1678467396165625"></a>Defines the beginning of the default initialization for the server proxy class. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table206141927165625"></a>
<table><thead align="left"><tr id="row1305875013165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p560609117165625"><a name="p560609117165625"></a><a name="p560609117165625"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p551474978165625"><a name="p551474978165625"></a><a name="p551474978165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1718353386165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384260198165625"><a name="p384260198165625"></a><a name="p384260198165625"></a><a href="registry.md#ga362a17c1bda1aace88d42dcbc88bdfac">INotify</a>) (IOwner owner, int code, IpcIo *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2049678795165625"><a name="p2049678795165625"></a><a name="p2049678795165625"></a>typedef int(* </p>
<p id="p675368108165625"><a name="p675368108165625"></a><a name="p675368108165625"></a>Called when a client request is responded. </p>
</td>
</tr>
<tr id="row1960519857165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p499655571165625"><a name="p499655571165625"></a><a name="p499655571165625"></a><a href="registry.md#ga0c8aa2ef9883bd97b4f1309895adaa4c">Creator</a>) (const char *service, const char *feature, uint32 size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479986549165625"><a name="p479986549165625"></a><a name="p479986549165625"></a>typedef void *(* </p>
<p id="p1753241859165625"><a name="p1753241859165625"></a><a name="p1753241859165625"></a>Indicates the creator of the customized client proxy. </p>
</td>
</tr>
<tr id="row1714012819165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36015185165625"><a name="p36015185165625"></a><a name="p36015185165625"></a><a href="registry.md#ga1e6298b1246357f70ad0b581e0eb9305">Destroyer</a>) (const char *service, const char *feature, void *iproxy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1172920219165625"><a name="p1172920219165625"></a><a name="p1172920219165625"></a>typedef void(* </p>
<p id="p254511061165625"><a name="p254511061165625"></a><a name="p254511061165625"></a>Indicates the destroyer of the customized client proxy. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table646418901165625"></a>
<table><thead align="left"><tr id="row489207949165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p622402591165625"><a name="p622402591165625"></a><a name="p622402591165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1901901160165625"><a name="p1901901160165625"></a><a name="p1901901160165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1694946025165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p675404070165625"><a name="p675404070165625"></a><a name="p675404070165625"></a><a href="registry.md#gaa9bb385bfe593f4377a83cf513189bf1">SAMGR_GetRemoteIdentity</a> (const char *service, const char *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22749776165625"><a name="p22749776165625"></a><a name="p22749776165625"></a>SvcIdentity </p>
<p id="p1025066003165625"><a name="p1025066003165625"></a><a name="p1025066003165625"></a>Obtains the IPC address of a remote service and feature based on the service name and feature name. </p>
</td>
</tr>
<tr id="row1759982273165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660886614165625"><a name="p1660886614165625"></a><a name="p1660886614165625"></a><a href="registry.md#ga64797e3f63201c40dbdf21b90cff23d2">SAMGR_RegisterFactory</a> (const char *service, const char *feature, <a href="registry.md#ga0c8aa2ef9883bd97b4f1309895adaa4c">Creator</a> creator, <a href="registry.md#ga1e6298b1246357f70ad0b581e0eb9305">Destroyer</a> destroyer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1254500407165625"><a name="p1254500407165625"></a><a name="p1254500407165625"></a>int </p>
<p id="p439997916165625"><a name="p439997916165625"></a><a name="p439997916165625"></a>Registers the factory method of the client proxy object with the Samgr. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section473233789165625"></a>

## **Macro Definition **<a name="section353553314165625"></a>

## INHERIT\_CLIENT\_IPROXY<a name="ga86734e6a03eb089309e87ec628002034"></a>

```
#define INHERIT_CLIENT_IPROXY
```

```
Values: [INHERIT_IUNKNOWN](samgr.md#gab74532a22d6993d0ffc014d36253397f); \

 int (*Invoke)([IClientProxy](iclientproxy.md) *proxy, int funcId, IpcIo *request, IOwner owner, [INotify](registry.md#ga362a17c1bda1aace88d42dcbc88bdfac) notify)


```

 **Description:**

Indicates the inherited macro of the client proxy. 

This constant is used when a client proxy needs to be customized or generated by a tool. 

## INHERIT\_IPROXY\_ENTRY<a name="ga9ad9b5f0e1f50f2528cbef67957b2319"></a>

```
#define INHERIT_IPROXY_ENTRY( T)   [INHERIT_IUNKNOWNENTRY](samgr.md#gad6324fd90dd636180efa2a59b377e65c)(T)
```

 **Description:**

Inherits the server proxy class. 

When the server provides cross-process system capabilities, it uses  **INHERIT\_IPROXY\_ENTRY**  to define the server proxy class. 

## INHERIT\_SERVER\_IPROXY<a name="ga58e6d24ef278dceb3fb9c77527acdb5c"></a>

```
#define INHERIT_SERVER_IPROXY
```

```
Values: [INHERIT_IUNKNOWN](samgr.md#gab74532a22d6993d0ffc014d36253397f); \

 int32 (*Invoke)([IServerProxy](iserverproxy.md) *iProxy, int funcId, void *origin, IpcIo *req, IpcIo *reply)


```

 **Description:**

Inherits the server proxy function. 

When the server provides cross-process system capabilities, it uses  **INHERIT\_SERVER\_IPROXY**  to define the server proxy function. 

## IPROXY\_END<a name="ga59b6c10043506af716ce9052a5a964a7"></a>

```
#define IPROXY_END   [IUNKNOWN_ENTRY_END](samgr.md#ga4ef734474ece49aa938d8ebd5b54bdb3)
```

 **Description:**

Defines the end of the default initialization for the server proxy class. 

This macro is used for developing the server proxy class. You can inherit this macro to reduce the code amount and prevent class definition inconsistency. 

## SERVER\_IPROXY\_BEGIN<a name="ga3c3f1e77cc1a495f48a4b3cd0f8934be"></a>

```
#define SERVER_IPROXY_BEGIN   [IUNKNOWN_ENTRY_BEGIN](samgr.md#ga52ec6b5b03d56b0dfe7277785246bda1)([SERVER_PROXY_VER](registry.md#gad513d97bfb873f27c9b8f69a5a418d55))
```

 **Description:**

Defines the beginning of the default initialization for the server proxy class. 

This macro is used for developing the server proxy class. You can inherit this macro to reduce the code amount and prevent class definition inconsistency. 

## SERVER\_PROXY\_VER<a name="gad513d97bfb873f27c9b8f69a5a418d55"></a>

```
#define SERVER_PROXY_VER   0x80
```

 **Description:**

Defines the default version number of the server proxy. 

The cross-process system capabilities are registered when Samgr uses  **SERVER\_PROXY\_VER**  to query the registered server proxy. 

## **Typedef **<a name="section172190079165625"></a>

## Creator<a name="ga0c8aa2ef9883bd97b4f1309895adaa4c"></a>

```
typedef void*(* Creator) (const char *service, const char *feature, uint32 size)
```

 **Description:**

Indicates the creator of the customized client proxy. 

This macro creates a local client proxy for remote service APIs. If you want to call the remote APIs in the way that local APIs are called, implement this macro to encapsulate serialized data into the proxy. The system automatically calls this macro when creating a proxy object. 

**Parameters:**

<a name="table125679121165625"></a>
<table><thead align="left"><tr id="row783169924165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p841485431165625"><a name="p841485431165625"></a><a name="p841485431165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p603679463165625"><a name="p603679463165625"></a><a name="p603679463165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1705391856165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the service to which the function belongs. </td>
</tr>
<tr id="row348912858165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the feature to which the function belongs. </td>
</tr>
<tr id="row922006094165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">size</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the size of the head to be added when a client proxy is created. The required memory capacity is the head size plus the object size. </td>
</tr>
</tbody>
</table>

**Returns:**

void \* Returns the applied memory capacity and initialize the memory for the client proxy. 

## Destroyer<a name="ga1e6298b1246357f70ad0b581e0eb9305"></a>

```
typedef void(* Destroyer) (const char *service, const char *feature, void *iproxy)
```

 **Description:**

Indicates the destroyer of the customized client proxy. 

This macro destroys local client proxy for remote service APIs. If you want to call the remote APIs in the way that local APIs are called, implement this macro to encapsulate serialized data into the proxy. The system automatically calls this macro when destroying a proxy object. 

**Parameters:**

<a name="table1882078055165625"></a>
<table><thead align="left"><tr id="row2007399149165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p181513028165625"><a name="p181513028165625"></a><a name="p181513028165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p931977951165625"><a name="p931977951165625"></a><a name="p931977951165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1604994159165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the service to which the function belongs. </td>
</tr>
<tr id="row541584396165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the feature to which the function belongs. </td>
</tr>
<tr id="row723374507165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">iproxy</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the start address of the memory that is applied by <strong id="b470764432165625"><a name="b470764432165625"></a><a name="b470764432165625"></a>Creator</strong>. </td>
</tr>
</tbody>
</table>

## INotify<a name="ga362a17c1bda1aace88d42dcbc88bdfac"></a>

```
typedef int(* INotify) (IOwner owner, int code, IpcIo *reply)
```

 **Description:**

Called when a client request is responded. 

The client implements this  **INotify**  callback to receive response data from the server.  **owner**  indicates the client proxy that receives the response data;  **code**  indicates the error code of the response data from the server;  **reply**  indicates the response data. 

## **Function **<a name="section890168117165625"></a>

## SAMGR\_GetRemoteIdentity\(\)<a name="gaa9bb385bfe593f4377a83cf513189bf1"></a>

```
SvcIdentity SAMGR_GetRemoteIdentity (const char * service, const char * feature )
```

 **Description:**

Obtains the IPC address of a remote service and feature based on the service name and feature name. 

This function is used when  [IClientProxy](iclientproxy.md)  cannot meet your requirements for calling IPCs. For example, if you need to receive the death notification of a remote service or feature, you can call this function to obtain the address of the remote service or feature and subscribe to the death notification from the IPC. 

**Parameters:**

<a name="table2009177034165625"></a>
<table><thead align="left"><tr id="row1116801620165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2108341067165625"><a name="p2108341067165625"></a><a name="p2108341067165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1984573053165625"><a name="p1984573053165625"></a><a name="p1984573053165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1606087582165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the remote service. </td>
</tr>
<tr id="row1195929896165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the name of the remote feature. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns the IPC address of the remote service or feature. When the handle of the obtained address structure  **SvcIdentity**  is  **0xFFFFFFFF**, the address is invalid. 

**Attention:**

This function can be called only after  **GetFeatureApi**  in  [SamgrLite](samgrlite.md)  is successfully called. Otherwise, an invalid address is returned. When the service or feature does not support IPC communication, an invalid address will be returned. 

## SAMGR\_RegisterFactory\(\)<a name="ga64797e3f63201c40dbdf21b90cff23d2"></a>

```
int SAMGR_RegisterFactory (const char * service, const char * feature, [Creator](registry.md#ga0c8aa2ef9883bd97b4f1309895adaa4c) creator, [Destroyer](registry.md#ga1e6298b1246357f70ad0b581e0eb9305) destroyer )
```

 **Description:**

Registers the factory method of the client proxy object with the Samgr. 

If you want to call the remote APIs in the way that local APIs are called, implement this function to encapsulate serialized data into the proxy. During system initialization, the module that uses the remote proxy calls the function as required. 

**Parameters:**

<a name="table1446011529165625"></a>
<table><thead align="left"><tr id="row1423875050165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p430418700165625"><a name="p430418700165625"></a><a name="p430418700165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1352456307165625"><a name="p1352456307165625"></a><a name="p1352456307165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1524561680165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">service</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the service name of the client proxy. </td>
</tr>
<tr id="row1486364955165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">feature</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the feature name of the client proxy. </td>
</tr>
<tr id="row1384003953165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">creator</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b1812747358165625"><a name="b1812747358165625"></a><a name="b1812747358165625"></a>Creator</strong> function of the client proxy. </td>
</tr>
<tr id="row1119000486165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">destroyer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the <strong id="b837282820165625"><a name="b837282820165625"></a><a name="b837282820165625"></a>Destroyer</strong> function of the client proxy. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **EC\_SUCCESS**  if the registration is successful; returns other error codes if the registration fails. 

