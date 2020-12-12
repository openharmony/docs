# pms\_interface.h<a name="ZH-CN_TOPIC_0000001054718103"></a>

-   [Overview](#section762553512165628)
-   [Summary](#section775866580165628)
-   [Functions](#func-members)

## **Overview**<a name="section762553512165628"></a>

**Related Modules:**

[PMS](PMS.md)

**Description:**

Declares interfaces for managing permissions. 

The interfaces can be used to authenticate native APIs, query, grant, and revoke permissions, and grant runtime permissions.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section775866580165628"></a>

## Functions<a name="func-members"></a>

<a name="table1702523553165628"></a>
<table><thead align="left"><tr id="row1758203890165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p460765552165628"><a name="p460765552165628"></a><a name="p460765552165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p371572445165628"><a name="p371572445165628"></a><a name="p371572445165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1771578655165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535994625165628"><a name="p1535994625165628"></a><a name="p1535994625165628"></a><a href="PMS.md#gaaaf2b952db3d8336c9b2309eaf67d1f7">CheckPermission</a> (int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289114178165628"><a name="p289114178165628"></a><a name="p289114178165628"></a>int </p>
<p id="p376875452165628"><a name="p376875452165628"></a><a name="p376875452165628"></a>Checks whether the caller (generally a third-party application) has a specified permission of a system service API. </p>
</td>
</tr>
<tr id="row499232440165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862523943165628"><a name="p862523943165628"></a><a name="p862523943165628"></a><a href="PMS.md#ga099c9ba42ace42091cbd15d9d7f202fb">CheckSelfPermission</a> (const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528866566165628"><a name="p528866566165628"></a><a name="p528866566165628"></a>int </p>
<p id="p1744220688165628"><a name="p1744220688165628"></a><a name="p1744220688165628"></a>Checks whether the caller (generally a third-party application) has a specified permission of a system service API. </p>
</td>
</tr>
<tr id="row1542684568165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584226469165628"><a name="p1584226469165628"></a><a name="p1584226469165628"></a><a href="PMS.md#gab279d23a1850f03e73de08b25e734679">QueryPermission</a> (const char *identifier, <a href="PermissionSaved.md">PermissionSaved</a> **permissions, int *permNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445644980165628"><a name="p445644980165628"></a><a name="p445644980165628"></a>int </p>
<p id="p919237237165628"><a name="p919237237165628"></a><a name="p919237237165628"></a>Queries all permissions requested by the application and checks whether these permissions are granted. </p>
</td>
</tr>
<tr id="row719153614165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p727370150165628"><a name="p727370150165628"></a><a name="p727370150165628"></a><a href="PMS.md#gad6c5889b56e196477152bbf4ce9f462c">GrantPermission</a> (const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p549926411165628"><a name="p549926411165628"></a><a name="p549926411165628"></a>int </p>
<p id="p2018129657165628"><a name="p2018129657165628"></a><a name="p2018129657165628"></a>Grants a specified permission to the application. </p>
</td>
</tr>
<tr id="row804300675165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1533246777165628"><a name="p1533246777165628"></a><a name="p1533246777165628"></a><a href="PMS.md#ga75cad2f174190a59d40e963481ddcbd7">RevokePermission</a> (const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1526428052165628"><a name="p1526428052165628"></a><a name="p1526428052165628"></a>int </p>
<p id="p2066963904165628"><a name="p2066963904165628"></a><a name="p2066963904165628"></a>Revokes a specified permission from the application. </p>
</td>
</tr>
<tr id="row846867985165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987119187165628"><a name="p1987119187165628"></a><a name="p1987119187165628"></a><a href="PMS.md#ga5e1343c802844acc6b2d95181ca36b66">GrantRuntimePermission</a> (int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945091048165628"><a name="p945091048165628"></a><a name="p945091048165628"></a>int </p>
<p id="p2051478572165628"><a name="p2051478572165628"></a><a name="p2051478572165628"></a>Grants a specified runtime permission to an application. </p>
</td>
</tr>
</tbody>
</table>

