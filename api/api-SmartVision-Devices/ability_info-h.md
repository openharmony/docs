# ability\_info.h<a name="ZH-CN_TOPIC_0000001054479523"></a>

-   [Overview](#section16434738165626)
-   [Summary](#section955928244165626)
-   [Data Structures](#nested-classes)
-   [Enumerations](#enum-members)
-   [Functions](#func-members)

## **Overview**<a name="section16434738165626"></a>

**Related Modules:**

[BundleManager](BundleManager.md)

**Description:**

Declares structures and functions for managing ability information. 

You can use the function provided in this file to clear ability information.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section955928244165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table248670706165626"></a>
<table><thead align="left"><tr id="row675828041165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p665652263165626"><a name="p665652263165626"></a><a name="p665652263165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p453054746165626"><a name="p453054746165626"></a><a name="p453054746165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2028803478165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686140661165626"><a name="p686140661165626"></a><a name="p686140661165626"></a><a href="AbilityInfo.md">AbilityInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024044014165626"><a name="p1024044014165626"></a><a name="p1024044014165626"></a>Defines the ability information. </p>
</td>
</tr>
</tbody>
</table>

## Enumerations<a name="enum-members"></a>

<a name="table535420925165626"></a>
<table><thead align="left"><tr id="row1372575849165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p456918762165626"><a name="p456918762165626"></a><a name="p456918762165626"></a>Enumeration Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p980846865165626"><a name="p980846865165626"></a><a name="p980846865165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1923323290165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201189748165626"><a name="p201189748165626"></a><a name="p201189748165626"></a><a href="BundleManager.md#ga44b675d687acff3d739404c1227b4259">AbilityType</a> { <a href="BundleManager.md#gga44b675d687acff3d739404c1227b4259a6ce26a62afab55d7606ad4e92428b30c">UNKNOWN</a> = 0, <a href="BundleManager.md#gga44b675d687acff3d739404c1227b4259ab788d9e2cde88d51a5cda409f75db490">PAGE</a>, <a href="BundleManager.md#gga44b675d687acff3d739404c1227b4259a5f6d448017ecd0a56245e38b76596e07">SERVICE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507090948165626"><a name="p507090948165626"></a><a name="p507090948165626"></a>Enumerates types of templates used by an ability. </p>
</td>
</tr>
<tr id="row1404702314165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1765228835165626"><a name="p1765228835165626"></a><a name="p1765228835165626"></a><a href="BundleManager.md#ga605d46d860e356a74db6842e66522854">LaunchMode</a> { <a href="BundleManager.md#gga605d46d860e356a74db6842e66522854a57da18394d2f90538c40b0b8d4a3a3c7">SINGLETON</a> = 0, <a href="BundleManager.md#gga605d46d860e356a74db6842e66522854a9de934790934fe831fe946c851e8338e">STANDARD</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p664042501165626"><a name="p664042501165626"></a><a name="p664042501165626"></a>Enumerates startup modes of an ability. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1588188847165626"></a>
<table><thead align="left"><tr id="row649737844165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p186892221165626"><a name="p186892221165626"></a><a name="p186892221165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1827120758165626"><a name="p1827120758165626"></a><a name="p1827120758165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2040372253165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p723798383165626"><a name="p723798383165626"></a><a name="p723798383165626"></a><a href="BundleManager.md#ga7377545918725f75645b59b1b7a319fa">ClearAbilityInfo</a> (<a href="AbilityInfo.md">AbilityInfo</a> *abilityInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p109750362165626"><a name="p109750362165626"></a><a name="p109750362165626"></a>void </p>
<p id="p1054575148165626"><a name="p1054575148165626"></a><a name="p1054575148165626"></a>Clears an <a href="AbilityInfo.md">AbilityInfo</a> object. </p>
</td>
</tr>
</tbody>
</table>

