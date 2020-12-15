# element\_name.h<a name="ZH-CN_TOPIC_0000001055039482"></a>

-   [Overview](#section221536493165626)
-   [Summary](#section880640720165626)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section221536493165626"></a>

**Related Modules:**

[BundleManager](BundleManager.md)

**Description:**

Declares the structure that defines the required information for querying  [AbilityInfo](AbilityInfo.md), including the device ID, bundle name, and class name, and functions for setting such information. 

You can use functions provided in this file to specify the information for querying  [AbilityInfo](AbilityInfo.md).

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section880640720165626"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1803595257165626"></a>
<table><thead align="left"><tr id="row2105681051165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p992882320165626"><a name="p992882320165626"></a><a name="p992882320165626"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1487568544165626"><a name="p1487568544165626"></a><a name="p1487568544165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row748411907165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1639912421165626"><a name="p1639912421165626"></a><a name="p1639912421165626"></a><a href="ElementName.md">ElementName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1711151887165626"><a name="p1711151887165626"></a><a name="p1711151887165626"></a>Defines the ability information. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1535209096165626"></a>
<table><thead align="left"><tr id="row767474654165626"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p783788316165626"><a name="p783788316165626"></a><a name="p783788316165626"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p860055670165626"><a name="p860055670165626"></a><a name="p860055670165626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row968709098165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336304522165626"><a name="p1336304522165626"></a><a name="p1336304522165626"></a><a href="BundleManager.md#ga3abe15ac14571de84ca72c98f4009724">ClearElement</a> (<a href="ElementName.md">ElementName</a> *element)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1098521408165626"><a name="p1098521408165626"></a><a name="p1098521408165626"></a>void </p>
<p id="p1959182144165626"><a name="p1959182144165626"></a><a name="p1959182144165626"></a>Clears the internal data of a specified <strong id="b1856405011165626"><a name="b1856405011165626"></a><a name="b1856405011165626"></a><a href="ElementName.md">ElementName</a></strong>. </p>
</td>
</tr>
<tr id="row1196290623165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788367129165626"><a name="p1788367129165626"></a><a name="p1788367129165626"></a><a href="BundleManager.md#ga90e16f159ee8e7f1a9385feebb3dbc0c">SetElementDeviceID</a> (<a href="ElementName.md">ElementName</a> *element, const char *deviceId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144140828165626"><a name="p2144140828165626"></a><a name="p2144140828165626"></a>bool </p>
<p id="p534346159165626"><a name="p534346159165626"></a><a name="p534346159165626"></a>Sets the device ID used to query <a href="AbilityInfo.md">AbilityInfo</a>. </p>
</td>
</tr>
<tr id="row1722869698165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1212501802165626"><a name="p1212501802165626"></a><a name="p1212501802165626"></a><a href="BundleManager.md#ga60692e66a3a204a2f16f70c5cd452c1d">SetElementBundleName</a> (<a href="ElementName.md">ElementName</a> *element, const char *bundleName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447494859165626"><a name="p1447494859165626"></a><a name="p1447494859165626"></a>bool </p>
<p id="p1415278907165626"><a name="p1415278907165626"></a><a name="p1415278907165626"></a>Sets the bundle name used to query <a href="AbilityInfo.md">AbilityInfo</a>. </p>
</td>
</tr>
<tr id="row332536678165626"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635258054165626"><a name="p635258054165626"></a><a name="p635258054165626"></a><a href="BundleManager.md#ga93a575cc428cb96526ae02b3997f1f3b">SetElementAbilityName</a> (<a href="ElementName.md">ElementName</a> *element, const char *abilityName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1939608546165626"><a name="p1939608546165626"></a><a name="p1939608546165626"></a>bool </p>
<p id="p1268168664165626"><a name="p1268168664165626"></a><a name="p1268168664165626"></a>Sets the class name of the ability used to query <a href="AbilityInfo.md">AbilityInfo</a>. </p>
</td>
</tr>
</tbody>
</table>

