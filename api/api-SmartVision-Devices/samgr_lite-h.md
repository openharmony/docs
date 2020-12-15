# samgr\_lite.h<a name="ZH-CN_TOPIC_0000001055518068"></a>

-   [Overview](#section549160462165629)
-   [Summary](#section589973563165629)
-   [Data Structures](#nested-classes)
-   [Macros](#define-members)
-   [Typedefs](#typedef-members)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section549160462165629"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Manages system capabilities. 

This is used when services, features, and functions are registered with and discovered by Samgr. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section589973563165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1691602233165629"></a>
<table><thead align="left"><tr id="row1648841251165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p656882962165629"><a name="p656882962165629"></a><a name="p656882962165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p728250291165629"><a name="p728250291165629"></a><a name="p728250291165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row423439244165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p206028542165629"><a name="p206028542165629"></a><a name="p206028542165629"></a><a href="SamgrLite.md">SamgrLite</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p619397056165629"><a name="p619397056165629"></a><a name="p619397056165629"></a>Represents the system ability management class. </p>
</td>
</tr>
</tbody>
</table>

## Macros<a name="define-members"></a>

<a name="table277174811165629"></a>
<table><thead align="left"><tr id="row1866485136165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p381214952165629"><a name="p381214952165629"></a><a name="p381214952165629"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p71334673165629"><a name="p71334673165629"></a><a name="p71334673165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row929120838165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374394218165629"><a name="p374394218165629"></a><a name="p374394218165629"></a><a href="Samgr.md#gadc00f0568236d4538c867ed7194d8960">BOOTSTRAP_SERVICE</a>   "Bootstrap"</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1685222965165629"><a name="p1685222965165629"></a><a name="p1685222965165629"></a>Starts a bootstrap service, which is used by samgr and implemented by system service developers. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1234710657165629"></a>
<table><thead align="left"><tr id="row1838709564165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1662204629165629"><a name="p1662204629165629"></a><a name="p1662204629165629"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p88442259165629"><a name="p88442259165629"></a><a name="p88442259165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row791747574165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p791785758165629"><a name="p791785758165629"></a><a name="p791785758165629"></a><a href="Samgr.md#gadc486c8d2698eab8a9f26f0eb6cc63c8">BootMessage</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258997390165629"><a name="p1258997390165629"></a><a name="p1258997390165629"></a>typedef enum <a href="Samgr.md#gaf39e482610dca95f0dba85613755eb40">BootMessage</a> </p>
<p id="p2038341502165629"><a name="p2038341502165629"></a><a name="p2038341502165629"></a>Enumerates the IDs of the message to be processed for starting the bootstrap service. </p>
</td>
</tr>
<tr id="row1745739695165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1783992576165629"><a name="p1783992576165629"></a><a name="p1783992576165629"></a><a href="Samgr.md#gaad729fe4f36b7b42a122349af334fb28">SamgrLite</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98059707165629"><a name="p98059707165629"></a><a name="p98059707165629"></a>typedef struct <a href="SamgrLite.md">SamgrLite</a> </p>
<p id="p1540196231165629"><a name="p1540196231165629"></a><a name="p1540196231165629"></a>Represents the system ability management class. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table1358420422165629"></a>
<table><thead align="left"><tr id="row235058232165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p599807092165629"><a name="p599807092165629"></a><a name="p599807092165629"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1636506204165629"><a name="p1636506204165629"></a><a name="p1636506204165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row495358628165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682367274165629"><a name="p682367274165629"></a><a name="p682367274165629"></a><a href="Samgr.md#gaf39e482610dca95f0dba85613755eb40">BootMessage</a> { <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40aee5f1e07de9a8e2e167f97dd2cc0c2d7">BOOT_SYS_COMPLETED</a>, <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40a8b0613200e2b05f9309175fe9bd30ca1">BOOT_APP_COMPLETED</a>, <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40a9aff5f5b8378e898076ee326da5cd572">BOOT_REG_SERVICE</a>, <a href="Samgr.md#ggaf39e482610dca95f0dba85613755eb40a515e06399df48a6d93435e7c30745eec">BOOTSTRAP_BUTT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906655738165629"><a name="p906655738165629"></a><a name="p906655738165629"></a>Enumerates the IDs of the message to be processed for starting the bootstrap service. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table816984457165629"></a>
<table><thead align="left"><tr id="row1675762911165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p167801280165629"><a name="p167801280165629"></a><a name="p167801280165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p721063531165629"><a name="p721063531165629"></a><a name="p721063531165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1867885309165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1496543063165629"><a name="p1496543063165629"></a><a name="p1496543063165629"></a><a href="Samgr.md#ga21f168d6f97d6991115ae1cf8bbd8deb">SAMGR_GetInstance</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194031720165629"><a name="p194031720165629"></a><a name="p194031720165629"></a><a href="SamgrLite.md">SamgrLite</a> * </p>
<p id="p27700425165629"><a name="p27700425165629"></a><a name="p27700425165629"></a>Obtains the singleton Samgr instance. </p>
</td>
</tr>
<tr id="row1523658064165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1002316694165629"><a name="p1002316694165629"></a><a name="p1002316694165629"></a><a href="Samgr.md#ga756ac1f5376c72aa5d14b855a302d7b6">SAMGR_Bootstrap</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2116451284165629"><a name="p2116451284165629"></a><a name="p2116451284165629"></a>void </p>
<p id="p507186952165629"><a name="p507186952165629"></a><a name="p507186952165629"></a>Starts system services and features. </p>
</td>
</tr>
</tbody>
</table>

