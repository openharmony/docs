# COMMON<a name="ZH-CN_TOPIC_0000001054479513"></a>

-   [Overview](#section1730551614165623)
-   [Summary](#section1213833944165623)
-   [Files](#files)
-   [Typedefs](#typedef-members)
-   [Details](#section1237214918165623)
-   [Typedef](#section197799551165623)
-   [DevHandle](#gab8c2d38e46eec50bd097a27d3d8bf041)

## **Overview**<a name="section1730551614165623"></a>

**Description:**

Provides common APIs of the platform driver. 

This module also provides  **DevHandle**, which represents the common data structure of the platform driver.

**Since:**

1.0

## **Summary**<a name="section1213833944165623"></a>

## Files<a name="files"></a>

<a name="table436744830165623"></a>
<table><thead align="left"><tr id="row1234793242165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p961857939165623"><a name="p961857939165623"></a><a name="p961857939165623"></a>File Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1386473312165623"><a name="p1386473312165623"></a><a name="p1386473312165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1381000068165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2003731035165623"><a name="p2003731035165623"></a><a name="p2003731035165623"></a><a href="hdf_platform-h.md">hdf_platform.h</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451896301165623"><a name="p451896301165623"></a><a name="p451896301165623"></a>Declares common APIs of the platform driver. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table225992841165623"></a>
<table><thead align="left"><tr id="row1787325095165623"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p953758150165623"><a name="p953758150165623"></a><a name="p953758150165623"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p679395405165623"><a name="p679395405165623"></a><a name="p679395405165623"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1420941272165623"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p390752215165623"><a name="p390752215165623"></a><a name="p390752215165623"></a><a href="COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041">DevHandle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059296519165623"><a name="p2059296519165623"></a><a name="p2059296519165623"></a>typedef void * </p>
<p id="p145350080165623"><a name="p145350080165623"></a><a name="p145350080165623"></a>Defines the common device handle of the platform driver. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1237214918165623"></a>

## **Typedef **<a name="section197799551165623"></a>

## DevHandle<a name="gab8c2d38e46eec50bd097a27d3d8bf041"></a>

```
typedef void* [DevHandle](COMMON.md#gab8c2d38e46eec50bd097a27d3d8bf041)
```

 **Description:**

Defines the common device handle of the platform driver. 

The handle is associated with a specific platform device and is used as the first input parameter for all APIs of the platform driver.

