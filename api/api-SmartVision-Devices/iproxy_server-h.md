# iproxy\_server.h<a name="ZH-CN_TOPIC_0000001054799571"></a>

-   [Overview](#section528707649165627)
-   [Summary](#section211687506165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)

## **Overview**<a name="section528707649165627"></a>

**Related Modules:**

[Registry](Registry.md)

**Description:**

Provides the server proxy. 

This feature is required for providing cross-process system capabilities. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section211687506165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1689785410165627"></a>
<table><thead align="left"><tr id="row1534807075165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p525593014165627"><a name="p525593014165627"></a><a name="p525593014165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p41070737165627"><a name="p41070737165627"></a><a name="p41070737165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1499216102165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722323172165627"><a name="p722323172165627"></a><a name="p722323172165627"></a><a href="IServerProxy.md">IServerProxy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117361120165627"><a name="p1117361120165627"></a><a name="p1117361120165627"></a>Defines the base class of the server proxy object. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table2012037077165627"></a>
<table><thead align="left"><tr id="row2137212851165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1861979651165627"><a name="p1861979651165627"></a><a name="p1861979651165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1239673668165627"><a name="p1239673668165627"></a><a name="p1239673668165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1107402571165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p954717539165627"><a name="p954717539165627"></a><a name="p954717539165627"></a><a href="Registry.md#gad513d97bfb873f27c9b8f69a5a418d55">SERVER_PROXY_VER</a>   0x80</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p901167543165627"><a name="p901167543165627"></a><a name="p901167543165627"></a>Defines the default version number of the server proxy. </p>
</td>
</tr>
<tr id="row1588013821165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838338288165627"><a name="p838338288165627"></a><a name="p838338288165627"></a><a href="Registry.md#ga58e6d24ef278dceb3fb9c77527acdb5c">INHERIT_SERVER_IPROXY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253344015165627"><a name="p1253344015165627"></a><a name="p1253344015165627"></a>Inherits the server proxy function. </p>
</td>
</tr>
<tr id="row345693924165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391605172165627"><a name="p391605172165627"></a><a name="p391605172165627"></a><a href="Registry.md#ga9ad9b5f0e1f50f2528cbef67957b2319">INHERIT_IPROXY_ENTRY</a>(T)   <a href="Samgr.md#gad6324fd90dd636180efa2a59b377e65c">INHERIT_IUNKNOWNENTRY</a>(T)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107892401165627"><a name="p107892401165627"></a><a name="p107892401165627"></a>Inherits the server proxy class. </p>
</td>
</tr>
<tr id="row1354268040165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162369215165627"><a name="p162369215165627"></a><a name="p162369215165627"></a><a href="Registry.md#ga3c3f1e77cc1a495f48a4b3cd0f8934be">SERVER_IPROXY_BEGIN</a>   <a href="Samgr.md#ga52ec6b5b03d56b0dfe7277785246bda1">IUNKNOWN_ENTRY_BEGIN</a>(<a href="Registry.md#gad513d97bfb873f27c9b8f69a5a418d55">SERVER_PROXY_VER</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455273663165627"><a name="p1455273663165627"></a><a name="p1455273663165627"></a>Defines the beginning of the default initialization for the server proxy class. </p>
</td>
</tr>
<tr id="row1473600069165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p730036070165627"><a name="p730036070165627"></a><a name="p730036070165627"></a><a href="Registry.md#ga59b6c10043506af716ce9052a5a964a7">IPROXY_END</a>   <a href="Samgr.md#ga4ef734474ece49aa938d8ebd5b54bdb3">IUNKNOWN_ENTRY_END</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p444921961165627"><a name="p444921961165627"></a><a name="p444921961165627"></a>Defines the end of the default initialization for the server proxy class. </p>
</td>
</tr>
</tbody>
</table>

