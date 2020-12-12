# bundle\_status\_callback.h<a name="EN-US_TOPIC_0000001057747360"></a>

-   [Overview](#section365157127165626)
-   [Summary](#section1285246220165626)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section365157127165626"></a>

**Related Modules:**

[BundleManager](bundlemanager.md)

**Description:**

Declares the callback invoked upon state changes of an application and the structure defining the callback information. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1285246220165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1672391868165626"></a>
<table><thead align="left"><tr id="row186282853165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p760870885165626"><a name="p760870885165626"></a><a name="p760870885165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2046696430165626"><a name="p2046696430165626"></a><a name="p2046696430165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row234406360165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1309670134165626"><a name="p1309670134165626"></a><a name="p1309670134165626"></a><a href="bundlestatuscallback.md">BundleStatusCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278813123165626"><a name="p1278813123165626"></a><a name="p1278813123165626"></a>Defines the application state callback information. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1797852399165626"></a>
<table><thead align="left"><tr id="row263763788165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1578777169165626"><a name="p1578777169165626"></a><a name="p1578777169165626"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1569003227165626"><a name="p1569003227165626"></a><a name="p1569003227165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1585878610165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786756160165626"><a name="p1786756160165626"></a><a name="p1786756160165626"></a><a href="bundlemanager.md#gad7ea6d0bf78db2d59e6d339c31819885">BundleStateCallback</a>) (const uint8_t installType, const uint8_t resultCode, const void *resultMessage, const char *bundleName, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574856141165626"><a name="p1574856141165626"></a><a name="p1574856141165626"></a>typedef void(* </p>
<p id="p295446638165626"><a name="p295446638165626"></a><a name="p295446638165626"></a>Called when the installation, update, or uninstallation state of an application changes. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table271521178165626"></a>
<table><thead align="left"><tr id="row672446347165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2143533500165626"><a name="p2143533500165626"></a><a name="p2143533500165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1905036408165626"><a name="p1905036408165626"></a><a name="p1905036408165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row881276292165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p874900502165626"><a name="p874900502165626"></a><a name="p874900502165626"></a><a href="bundlemanager.md#gae5e0593438f073199bf6d69e47a84975">ClearBundleStatusCallback</a> (<a href="bundlestatuscallback.md">BundleStatusCallback</a> *bundleStatusCallback)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1195133642165626"><a name="p1195133642165626"></a><a name="p1195133642165626"></a>void </p>
<p id="p985682753165626"><a name="p985682753165626"></a><a name="p985682753165626"></a>Clears and releases the memory occupied by the <a href="bundlestatuscallback.md">BundleStatusCallback</a> structure. </p>
</td>
</tr>
</tbody>
</table>

