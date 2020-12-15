# iproxy\_client.h<a name="ZH-CN_TOPIC_0000001055518060"></a>

-   [Overview](#section2015427267165627)
-   [Summary](#section498246058165627)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section2015427267165627"></a>

**Related Modules:**

[Registry](Registry.md)

**Description:**

Provides the client proxy class. 

When you need to call system capabilities of other processes, obtain the class from Samgr. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section498246058165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table436830504165627"></a>
<table><thead align="left"><tr id="row891201121165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1041597224165627"><a name="p1041597224165627"></a><a name="p1041597224165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2121430816165627"><a name="p2121430816165627"></a><a name="p2121430816165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1084496579165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p618655914165627"><a name="p618655914165627"></a><a name="p618655914165627"></a><a href="IClientProxy.md">IClientProxy</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072732562165627"><a name="p1072732562165627"></a><a name="p1072732562165627"></a>Defines the client proxy object. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table258851761165627"></a>
<table><thead align="left"><tr id="row1614572835165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1833677577165627"><a name="p1833677577165627"></a><a name="p1833677577165627"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p596781137165627"><a name="p596781137165627"></a><a name="p596781137165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row558779045165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140572485165627"><a name="p140572485165627"></a><a name="p140572485165627"></a><a href="Registry.md#ga86734e6a03eb089309e87ec628002034">INHERIT_CLIENT_IPROXY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840358077165627"><a name="p840358077165627"></a><a name="p840358077165627"></a>Indicates the inherited macro of the client proxy. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1884081204165627"></a>
<table><thead align="left"><tr id="row1409083449165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p254931780165627"><a name="p254931780165627"></a><a name="p254931780165627"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p832618928165627"><a name="p832618928165627"></a><a name="p832618928165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1224809169165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p302294247165627"><a name="p302294247165627"></a><a name="p302294247165627"></a><a href="Registry.md#ga362a17c1bda1aace88d42dcbc88bdfac">INotify</a>) (IOwner owner, int code, IpcIo *reply)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p140267179165627"><a name="p140267179165627"></a><a name="p140267179165627"></a>typedef int(* </p>
<p id="p963608008165627"><a name="p963608008165627"></a><a name="p963608008165627"></a>Called when a client request is responded. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table2067506898165627"></a>
<table><thead align="left"><tr id="row1829463597165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1932296070165627"><a name="p1932296070165627"></a><a name="p1932296070165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p918286492165627"><a name="p918286492165627"></a><a name="p918286492165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1908526344165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708994885165627"><a name="p1708994885165627"></a><a name="p1708994885165627"></a><a href="Registry.md#gaa9bb385bfe593f4377a83cf513189bf1">SAMGR_GetRemoteIdentity</a> (const char *service, const char *feature)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1775574389165627"><a name="p1775574389165627"></a><a name="p1775574389165627"></a>SvcIdentity </p>
<p id="p1704887560165627"><a name="p1704887560165627"></a><a name="p1704887560165627"></a>Obtains the IPC address of a remote service and feature based on the service name and feature name. </p>
</td>
</tr>
</tbody>
</table>

