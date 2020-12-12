# OHOS::SysInfo<a name="EN-US_TOPIC_0000001054479597"></a>

-   [Overview](#section86132521165635)
-   [Summary](#section1337621223165635)
-   [Data Structures](#nested-classes)
-   [Public Types](#pub-types)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section86132521165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Obtains the system information. Currently, the FPS information can be obtained. To enable the FPS feature, enable the  **ENABLE\_FPS\_SUPPORT**  macro. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1337621223165635"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1921180439165635"></a>
<table><thead align="left"><tr id="row254530623165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p341610216165635"><a name="p341610216165635"></a><a name="p341610216165635"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1597694410165635"><a name="p1597694410165635"></a><a name="p1597694410165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row600646679165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214957607165635"><a name="p214957607165635"></a><a name="p214957607165635"></a><a href="ohos-sysinfo-onfpschangedlistener.md">OnFPSChangedListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449281327165635"><a name="p1449281327165635"></a><a name="p1449281327165635"></a>Called when the FPS changes. </p>
</td>
</tr>
</tbody>
</table>

## Public Types<a name="pub-types"></a>

<a name="table1878621525165635"></a>
<table><thead align="left"><tr id="row1616893529165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p323176368165635"><a name="p323176368165635"></a><a name="p323176368165635"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1761890734165635"><a name="p1761890734165635"></a><a name="p1761890734165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1628378774165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433323189165635"><a name="p1433323189165635"></a><a name="p1433323189165635"></a><a href="graphic.md#ga75d850e3abff6c2f617b689a0cb9a3d1">FPSCalculateType</a> { <a href="graphic.md#gga75d850e3abff6c2f617b689a0cb9a3d1a26a841fb9a10881591dc79dae38e2d7f">FPS_CT_FIXED_TIME</a>, <a href="graphic.md#gga75d850e3abff6c2f617b689a0cb9a3d1a17fdb75ff7e9afb4165349a3d8300f3c">FPS_CT_AVERAGE_SAMPLING</a>, <a href="graphic.md#gga75d850e3abff6c2f617b689a0cb9a3d1afcc7226b2c9012f2993b7044a80cbed5">FPS_CT_PRECISE_SAMPLING</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p948736723165635"><a name="p948736723165635"></a><a name="p948736723165635"></a>Enumerates the FPS capture types. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table1507008020165635"></a>
<table><thead align="left"><tr id="row1612108670165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1433773786165635"><a name="p1433773786165635"></a><a name="p1433773786165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1185947246165635"><a name="p1185947246165635"></a><a name="p1185947246165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row890496419165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p350404836165635"><a name="p350404836165635"></a><a name="p350404836165635"></a><a href="graphic.md#gaa028189de9bf2968948578c8e09a9101">GetFPS</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1748350242165635"><a name="p1748350242165635"></a><a name="p1748350242165635"></a>static float </p>
<p id="p877139990165635"><a name="p877139990165635"></a><a name="p877139990165635"></a>Obtains the FPS data. </p>
</td>
</tr>
<tr id="row813820443165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764957507165635"><a name="p1764957507165635"></a><a name="p1764957507165635"></a><a href="graphic.md#gac885a43e87f57ae57e0d8b6d213e9fa1">RegisterFPSChangedListener</a> (<a href="ohos-sysinfo-onfpschangedlistener.md">OnFPSChangedListener</a> *onFPSChangedListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263702807165635"><a name="p263702807165635"></a><a name="p263702807165635"></a>static void </p>
<p id="p487450253165635"><a name="p487450253165635"></a><a name="p487450253165635"></a>Registers the listener for notifying the FPS changes. </p>
</td>
</tr>
</tbody>
</table>

