# PMS<a name="EN-US_TOPIC_0000001054479519"></a>

-   [Overview](#section458050375165625)
-   [Summary](#section2001005409165625)
-   [Files](#files)
-   [Functions](#func-members)
-   [Details](#section211281568165625)
-   [Function](#section1914856096165625)
-   [CheckPermission\(\)](#gaaaf2b952db3d8336c9b2309eaf67d1f7)
-   [CheckSelfPermission\(\)](#ga099c9ba42ace42091cbd15d9d7f202fb)
-   [GrantPermission\(\)](#gad6c5889b56e196477152bbf4ce9f462c)
-   [GrantRuntimePermission\(\)](#ga5e1343c802844acc6b2d95181ca36b66)
-   [QueryPermission\(\)](#gab279d23a1850f03e73de08b25e734679)
-   [RevokePermission\(\)](#ga75cad2f174190a59d40e963481ddcbd7)

## **Overview**<a name="section458050375165625"></a>

**Description:**

Manages permissions. 

This module provides interfaces for managing permissions of third-party applications.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2001005409165625"></a>

## Files<a name="files"></a>

<a name="table1276992177165625"></a>
<table><thead align="left"><tr id="row2034431786165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p279399236165625"><a name="p279399236165625"></a><a name="p279399236165625"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2073326632165625"><a name="p2073326632165625"></a><a name="p2073326632165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row359215703165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65160550165625"><a name="p65160550165625"></a><a name="p65160550165625"></a><a href="pms_interface-h.md">pms_interface.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827393994165625"><a name="p1827393994165625"></a><a name="p1827393994165625"></a>Declares interfaces for managing permissions. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1754754673165625"></a>
<table><thead align="left"><tr id="row1115917650165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1250639264165625"><a name="p1250639264165625"></a><a name="p1250639264165625"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p628406968165625"><a name="p628406968165625"></a><a name="p628406968165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1474633105165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850787425165625"><a name="p1850787425165625"></a><a name="p1850787425165625"></a><a href="pms.md#gaaaf2b952db3d8336c9b2309eaf67d1f7">CheckPermission</a> (int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1970994393165625"><a name="p1970994393165625"></a><a name="p1970994393165625"></a>int </p>
<p id="p79181391165625"><a name="p79181391165625"></a><a name="p79181391165625"></a>Checks whether the caller (generally a third-party application) has a specified permission of a system service API. </p>
</td>
</tr>
<tr id="row247582365165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1656827882165625"><a name="p1656827882165625"></a><a name="p1656827882165625"></a><a href="pms.md#ga099c9ba42ace42091cbd15d9d7f202fb">CheckSelfPermission</a> (const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151229087165625"><a name="p151229087165625"></a><a name="p151229087165625"></a>int </p>
<p id="p1260355285165625"><a name="p1260355285165625"></a><a name="p1260355285165625"></a>Checks whether the caller (generally a third-party application) has a specified permission of a system service API. </p>
</td>
</tr>
<tr id="row1996140204165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330831119165625"><a name="p1330831119165625"></a><a name="p1330831119165625"></a><a href="pms.md#gab279d23a1850f03e73de08b25e734679">QueryPermission</a> (const char *identifier, <a href="permissionsaved.md">PermissionSaved</a> **permissions, int *permNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p876861528165625"><a name="p876861528165625"></a><a name="p876861528165625"></a>int </p>
<p id="p771825492165625"><a name="p771825492165625"></a><a name="p771825492165625"></a>Queries all permissions requested by the application and checks whether these permissions are granted. </p>
</td>
</tr>
<tr id="row1280339219165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1665344016165625"><a name="p1665344016165625"></a><a name="p1665344016165625"></a><a href="pms.md#gad6c5889b56e196477152bbf4ce9f462c">GrantPermission</a> (const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733545184165625"><a name="p733545184165625"></a><a name="p733545184165625"></a>int </p>
<p id="p1333894665165625"><a name="p1333894665165625"></a><a name="p1333894665165625"></a>Grants a specified permission to the application. </p>
</td>
</tr>
<tr id="row2123213308165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p24194016165625"><a name="p24194016165625"></a><a name="p24194016165625"></a><a href="pms.md#ga75cad2f174190a59d40e963481ddcbd7">RevokePermission</a> (const char *identifier, const char *permName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181955283165625"><a name="p181955283165625"></a><a name="p181955283165625"></a>int </p>
<p id="p581396780165625"><a name="p581396780165625"></a><a name="p581396780165625"></a>Revokes a specified permission from the application. </p>
</td>
</tr>
<tr id="row939102699165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283978946165625"><a name="p283978946165625"></a><a name="p283978946165625"></a><a href="pms.md#ga5e1343c802844acc6b2d95181ca36b66">GrantRuntimePermission</a> (int uid, const char *permissionName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p158823031165625"><a name="p158823031165625"></a><a name="p158823031165625"></a>int </p>
<p id="p1341207406165625"><a name="p1341207406165625"></a><a name="p1341207406165625"></a>Grants a specified runtime permission to an application. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section211281568165625"></a>

## **Function **<a name="section1914856096165625"></a>

## CheckPermission\(\)<a name="gaaaf2b952db3d8336c9b2309eaf67d1f7"></a>

```
int CheckPermission (int uid, const char * permissionName )
```

 **Description:**

Checks whether the caller \(generally a third-party application\) has a specified permission of a system service API. 

**Parameters:**

<a name="table356294461165625"></a>
<table><thead align="left"><tr id="row97681608165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1532123439165625"><a name="p1532123439165625"></a><a name="p1532123439165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1908453990165625"><a name="p1908453990165625"></a><a name="p1908453990165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row20286455165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">uid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the process uid of the caller. The range is [0, INT_MAX]. </td>
</tr>
<tr id="row1781256896165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permissionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the permission name. For details, see the developer documentation. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if the caller has the permission; returns  **0**  otherwise.

## CheckSelfPermission\(\)<a name="ga099c9ba42ace42091cbd15d9d7f202fb"></a>

```
int CheckSelfPermission (const char * permissionName)
```

 **Description:**

Checks whether the caller \(generally a third-party application\) has a specified permission of a system service API. 

**Parameters:**

<a name="table811315985165625"></a>
<table><thead align="left"><tr id="row631153276165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1369805217165625"><a name="p1369805217165625"></a><a name="p1369805217165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p606745521165625"><a name="p606745521165625"></a><a name="p606745521165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1733292349165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permissionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the permission name. For details, see the developer documentation. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **1**  if the caller has the permission; returns  **0**  otherwise.

## GrantPermission\(\)<a name="gad6c5889b56e196477152bbf4ce9f462c"></a>

```
int GrantPermission (const char * identifier, const char * permName )
```

 **Description:**

Grants a specified permission to the application. 

**Parameters:**

<a name="table814886451165625"></a>
<table><thead align="left"><tr id="row1569822869165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p173399432165625"><a name="p173399432165625"></a><a name="p173399432165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p129627787165625"><a name="p129627787165625"></a><a name="p129627787165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1364523338165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identifier</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the application bundle name. </td>
</tr>
<tr id="row1662440837165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the permission name. For details, see the developer documentation. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the permission is successfully granted; returns an error code defined in  [PmsErrorCode](pms_types.md#gacb79d7f5cd64c73479e0bdd9525265a8)  otherwise.

## GrantRuntimePermission\(\)<a name="ga5e1343c802844acc6b2d95181ca36b66"></a>

```
int GrantRuntimePermission (int uid, const char * permissionName )
```

 **Description:**

Grants a specified runtime permission to an application. 

This function applies to sensitive permissions that can be granted to the application only when the application is running.

**Parameters:**

<a name="table1969440878165625"></a>
<table><thead align="left"><tr id="row1205453691165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p632006880165625"><a name="p632006880165625"></a><a name="p632006880165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1456815650165625"><a name="p1456815650165625"></a><a name="p1456815650165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2041019986165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">uid</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the user ID of the application. The range is [0, INT_MAX]. </td>
</tr>
<tr id="row1131770540165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permissionName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the permission name. For details, see the developer documentation. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the permission is successfully granted; returns an error code defined in  [PmsErrorCode](pms_types.md#gacb79d7f5cd64c73479e0bdd9525265a8)  otherwise.

## QueryPermission\(\)<a name="gab279d23a1850f03e73de08b25e734679"></a>

```
int QueryPermission (const char * identifier, [PermissionSaved](permissionsaved.md) ** permissions, int * permNum )
```

 **Description:**

Queries all permissions requested by the application and checks whether these permissions are granted. 

**Parameters:**

<a name="table857067728165625"></a>
<table><thead align="left"><tr id="row1246033582165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1345612881165625"><a name="p1345612881165625"></a><a name="p1345612881165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p427835481165625"><a name="p427835481165625"></a><a name="p427835481165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1692671053165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identifier</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the application bundle name. </td>
</tr>
<tr id="row201077221165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permissions</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the double pointer to the array of permissions. You need to pass the <a href="permissionsaved.md">PermissionSaved</a> pointer and release it after finishing using it. </td>
</tr>
<tr id="row11786050165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permNum</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the number of permissions in the array, which is an integer. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [PmsErrorCode](pms_types.md#gacb79d7f5cd64c73479e0bdd9525265a8)  otherwise.

## RevokePermission\(\)<a name="ga75cad2f174190a59d40e963481ddcbd7"></a>

```
int RevokePermission (const char * identifier, const char * permName )
```

 **Description:**

Revokes a specified permission from the application. 

**Parameters:**

<a name="table956390229165625"></a>
<table><thead align="left"><tr id="row2129406258165625"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1723698453165625"><a name="p1723698453165625"></a><a name="p1723698453165625"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1383298309165625"><a name="p1383298309165625"></a><a name="p1383298309165625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row402012528165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">identifier</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the application bundle name. </td>
</tr>
<tr id="row89282493165625"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">permName</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the permission name. For details, see the developer documentation. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the permission is successfully revoked; returns an error code defined in  [PmsErrorCode](pms_types.md#gacb79d7f5cd64c73479e0bdd9525265a8)  otherwise.

