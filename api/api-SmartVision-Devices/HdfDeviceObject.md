# HdfDeviceObject<a name="ZH-CN_TOPIC_0000001054479563"></a>

-   [Overview](#section1715265701165631)
-   [Summary](#section1845297948165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section469785400165631)
-   [Field](#section1570096397165631)
-   [property](#aff597a0d23dbf2c6581a4ea6f261e953)
-   [service](#a4a56df841dab2ca990594daea3ad0107)

## **Overview**<a name="section1715265701165631"></a>

**Related Modules:**

[Core](Core.md)

**Description:**

Defines the device object. 

This structure is a device object defined by the HDF and is used to store private data and interface information of a device.

**Since:**

1.0

## **Summary**<a name="section1845297948165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table266155287165631"></a>
<table><thead align="left"><tr id="row428362002165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1699208320165631"><a name="p1699208320165631"></a><a name="p1699208320165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1874056226165631"><a name="p1874056226165631"></a><a name="p1874056226165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row931371151165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p804669755165631"><a name="p804669755165631"></a><a name="p804669755165631"></a><a href="HdfDeviceObject.md#a4a56df841dab2ca990594daea3ad0107">service</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p983686722165631"><a name="p983686722165631"></a><a name="p983686722165631"></a>struct <a href="IDeviceIoService.md">IDeviceIoService</a> * </p>
</td>
</tr>
<tr id="row1017520414165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552965820165631"><a name="p1552965820165631"></a><a name="p1552965820165631"></a><a href="HdfDeviceObject.md#aff597a0d23dbf2c6581a4ea6f261e953">property</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734460687165631"><a name="p734460687165631"></a><a name="p734460687165631"></a>const struct <a href="DeviceResourceNode.md">DeviceResourceNode</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section469785400165631"></a>

## **Field **<a name="section1570096397165631"></a>

## property<a name="aff597a0d23dbf2c6581a4ea6f261e953"></a>

```
const struct [DeviceResourceNode](DeviceResourceNode.md)* HdfDeviceObject::property
```

 **Description:**

Pointer to the private data of the device, which is read by the HDF from the configuration file and transmitted to the driver. 

## service<a name="a4a56df841dab2ca990594daea3ad0107"></a>

```
struct [IDeviceIoService](IDeviceIoService.md)* HdfDeviceObject::service
```

 **Description:**

Pointer to the service interface object, which is registered with the HDF by the driver 

