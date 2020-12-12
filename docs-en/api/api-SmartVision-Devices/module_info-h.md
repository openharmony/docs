# module\_info.h<a name="EN-US_TOPIC_0000001054799573"></a>

-   [Overview](#section340055970165628)
-   [Summary](#section1463508847165628)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section340055970165628"></a>

**Related Modules:**

[BundleManager](bundlemanager.md)

**Description:**

Declares structures and functions for managing HAP package information. 

The HAP package is used to deploy  **Ability**  instances. It is a module package consisting of the code, resources, third-party libraries, and an application configuration file. You can use the function provided in this file to clear HAP information.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1463508847165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1657341243165628"></a>
<table><thead align="left"><tr id="row1057050521165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1417088841165628"><a name="p1417088841165628"></a><a name="p1417088841165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p941856129165628"><a name="p941856129165628"></a><a name="p941856129165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row646486397165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1080494591165628"><a name="p1080494591165628"></a><a name="p1080494591165628"></a><a href="metadata.md">MetaData</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p589485919165628"><a name="p589485919165628"></a><a name="p589485919165628"></a>Defines the metadata information in a <a href="moduleinfo.md">ModuleInfo</a> object. </p>
</td>
</tr>
<tr id="row1880966089165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043945722165628"><a name="p1043945722165628"></a><a name="p1043945722165628"></a><a href="moduleinfo.md">ModuleInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941621135165628"><a name="p941621135165628"></a><a name="p941621135165628"></a>Defines the HAP information. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table988761447165628"></a>
<table><thead align="left"><tr id="row200734540165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1636310425165628"><a name="p1636310425165628"></a><a name="p1636310425165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p758087904165628"><a name="p758087904165628"></a><a name="p758087904165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row907440629165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p989357519165628"><a name="p989357519165628"></a><a name="p989357519165628"></a><a href="bundlemanager.md#ga6c2242cc10f135d129b95444faacb345">ClearModuleInfo</a> (<a href="moduleinfo.md">ModuleInfo</a> *moduleInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1601779749165628"><a name="p1601779749165628"></a><a name="p1601779749165628"></a>void </p>
<p id="p677162299165628"><a name="p677162299165628"></a><a name="p677162299165628"></a>Clears a <a href="moduleinfo.md">ModuleInfo</a> object. </p>
</td>
</tr>
</tbody>
</table>

