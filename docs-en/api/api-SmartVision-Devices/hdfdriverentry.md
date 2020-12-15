# HdfDriverEntry<a name="EN-US_TOPIC_0000001055198130"></a>

-   [Overview](#section1763684766165631)
-   [Summary](#section1310304761165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1675080252165631)
-   [Field](#section1229555281165631)
-   [Bind](#a9e26ffb43d0d3ab221aad844cd172582)
-   [Init](#a1009f6ddf7188c63ed4b66597edbc446)
-   [moduleName](#af889c158a46b9805a96bd2281c024191)
-   [moduleVersion](#a3c5f146bd9494eb0f052454157e2b4b0)
-   [Release](#a5ff4bb43cf9d0a89ebf17876adbbff50)

## **Overview**<a name="section1763684766165631"></a>

**Related Modules:**

[Core](core.md)

**Description:**

Defines the entry structure of the driver in the HDF. 

This structure must be used as the entry for the driver to use the HDF mechanism.

**Since:**

1.0

## **Summary**<a name="section1310304761165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1657354295165631"></a>
<table><thead align="left"><tr id="row480190107165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p764186450165631"><a name="p764186450165631"></a><a name="p764186450165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2121781732165631"><a name="p2121781732165631"></a><a name="p2121781732165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row777976304165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p409179274165631"><a name="p409179274165631"></a><a name="p409179274165631"></a><a href="hdfdriverentry.md#a3c5f146bd9494eb0f052454157e2b4b0">moduleVersion</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194909732165631"><a name="p194909732165631"></a><a name="p194909732165631"></a>int32_t </p>
</td>
</tr>
<tr id="row352564899165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164189903165631"><a name="p164189903165631"></a><a name="p164189903165631"></a><a href="hdfdriverentry.md#af889c158a46b9805a96bd2281c024191">moduleName</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2074732293165631"><a name="p2074732293165631"></a><a name="p2074732293165631"></a>const char * </p>
</td>
</tr>
<tr id="row50815810165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p573387982165631"><a name="p573387982165631"></a><a name="p573387982165631"></a><a href="hdfdriverentry.md#a9e26ffb43d0d3ab221aad844cd172582">Bind</a> )(struct <a href="hdfdeviceobject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299323932165631"><a name="p299323932165631"></a><a name="p299323932165631"></a>int32_t(* </p>
<p id="p1990826256165631"><a name="p1990826256165631"></a><a name="p1990826256165631"></a>Binds the external service interface of a driver to the HDF. This function is implemented by the driver developer and called by the HDF. </p>
</td>
</tr>
<tr id="row1140975606165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930428301165631"><a name="p930428301165631"></a><a name="p930428301165631"></a><a href="hdfdriverentry.md#a1009f6ddf7188c63ed4b66597edbc446">Init</a> )(struct <a href="hdfdeviceobject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1489974837165631"><a name="p1489974837165631"></a><a name="p1489974837165631"></a>int32_t(* </p>
<p id="p1457585196165631"><a name="p1457585196165631"></a><a name="p1457585196165631"></a>Initializes the driver. This function is implemented by the driver developer and called by the HDF. </p>
</td>
</tr>
<tr id="row1716313500165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124928928165631"><a name="p2124928928165631"></a><a name="p2124928928165631"></a><a href="hdfdriverentry.md#a5ff4bb43cf9d0a89ebf17876adbbff50">Release</a> )(struct <a href="hdfdeviceobject.md">HdfDeviceObject</a> *deviceObject)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742222633165631"><a name="p1742222633165631"></a><a name="p1742222633165631"></a>void(* </p>
<p id="p420573835165631"><a name="p420573835165631"></a><a name="p420573835165631"></a>Releases driver resources. This function is implemented by the driver developer. When an exception occurs during driver loading or the driver is uninstalled, the HDF calls this function to release the driver resources. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1675080252165631"></a>

## **Field **<a name="section1229555281165631"></a>

## Bind<a name="a9e26ffb43d0d3ab221aad844cd172582"></a>

```
int32_t(* HdfDriverEntry::Bind) (struct [HdfDeviceObject](hdfdeviceobject.md) *deviceObject)
```

 **Description:**

Binds the external service interface of a driver to the HDF. This function is implemented by the driver developer and called by the HDF. 

**Parameters:**

<a name="table1261838252165631"></a>
<table><thead align="left"><tr id="row113212470165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p927414023165631"><a name="p927414023165631"></a><a name="p927414023165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1883526764165631"><a name="p1883526764165631"></a><a name="p1883526764165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row526442241165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceObject</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable of the <a href="hdfdeviceobject.md">HdfDeviceObject</a> type. This variable is generated by the HDF and passed to the driver. Then, the service object of the driver is bound to the <strong id="b1904517940165631"><a name="b1904517940165631"></a><a name="b1904517940165631"></a>service</strong> parameter of <strong id="b2032226979165631"><a name="b2032226979165631"></a><a name="b2032226979165631"></a>deviceObject</strong>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## Init<a name="a1009f6ddf7188c63ed4b66597edbc446"></a>

```
int32_t(* HdfDriverEntry::Init) (struct [HdfDeviceObject](hdfdeviceobject.md) *deviceObject)
```

 **Description:**

Initializes the driver. This function is implemented by the driver developer and called by the HDF. 

**Parameters:**

<a name="table1585505822165631"></a>
<table><thead align="left"><tr id="row202752113165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p897111660165631"><a name="p897111660165631"></a><a name="p897111660165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2065231910165631"><a name="p2065231910165631"></a><a name="p2065231910165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row148850728165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceObject</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable of the <a href="hdfdeviceobject.md">HdfDeviceObject</a> type. It is the same as the parameter of <a href="hdfdriverentry.md#a9e26ffb43d0d3ab221aad844cd172582">Bind</a>. </td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns a non-zero value otherwise.

## moduleName<a name="af889c158a46b9805a96bd2281c024191"></a>

```
const char* HdfDriverEntry::moduleName
```

 **Description:**

Driver module name, which is used to match the driver information in the configuration file. 

## moduleVersion<a name="a3c5f146bd9494eb0f052454157e2b4b0"></a>

```
int32_t HdfDriverEntry::moduleVersion
```

 **Description:**

Driver version 

## Release<a name="a5ff4bb43cf9d0a89ebf17876adbbff50"></a>

```
void(* HdfDriverEntry::Release) (struct [HdfDeviceObject](hdfdeviceobject.md) *deviceObject)
```

 **Description:**

Releases driver resources. This function is implemented by the driver developer. When an exception occurs during driver loading or the driver is uninstalled, the HDF calls this function to release the driver resources. 

**Parameters:**

<a name="table822303443165631"></a>
<table><thead align="left"><tr id="row849975518165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2050705727165631"><a name="p2050705727165631"></a><a name="p2050705727165631"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1053571423165631"><a name="p1053571423165631"></a><a name="p1053571423165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1751727442165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">deviceObject</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable of the <a href="hdfdeviceobject.md">HdfDeviceObject</a> type. It is the same as the parameter of <a href="hdfdriverentry.md#a9e26ffb43d0d3ab221aad844cd172582">Bind</a>.</td>
</tr>
</tbody>
</table>

