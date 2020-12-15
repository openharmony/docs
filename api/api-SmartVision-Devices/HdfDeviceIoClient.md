# HdfDeviceIoClient<a name="ZH-CN_TOPIC_0000001054879532"></a>

-   [Overview](#section651574459165631)
-   [Summary](#section1237984387165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1682215971165631)
-   [Field](#section1250885591165631)
-   [device](#a49e622cbc385f17b3800580157558031)
-   [priv](#aef6d8dd955ee8305554d89d1c64486c7)

## **Overview**<a name="section651574459165631"></a>

**Related Modules:**

[Core](Core.md)

**Description:**

Defines the client object structure of the I/O service. 

This structure describes the invoker information of the I/O servcie.

**Since:**

1.0

## **Summary**<a name="section1237984387165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table2103166115165631"></a>
<table><thead align="left"><tr id="row1702488970165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2040520688165631"><a name="p2040520688165631"></a><a name="p2040520688165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1950457704165631"><a name="p1950457704165631"></a><a name="p1950457704165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row622251290165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457581868165631"><a name="p457581868165631"></a><a name="p457581868165631"></a><a href="HdfDeviceIoClient.md#a49e622cbc385f17b3800580157558031">device</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1753503105165631"><a name="p1753503105165631"></a><a name="p1753503105165631"></a>struct <a href="HdfDeviceObject.md">HdfDeviceObject</a> * </p>
</td>
</tr>
<tr id="row646909152165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200713734165631"><a name="p1200713734165631"></a><a name="p1200713734165631"></a><a href="HdfDeviceIoClient.md#aef6d8dd955ee8305554d89d1c64486c7">priv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p232132458165631"><a name="p232132458165631"></a><a name="p232132458165631"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1682215971165631"></a>

## **Field **<a name="section1250885591165631"></a>

## device<a name="a49e622cbc385f17b3800580157558031"></a>

```
struct [HdfDeviceObject](HdfDeviceObject.md)* HdfDeviceIoClient::device
```

 **Description:**

Device object corresponding to the client object 

## priv<a name="aef6d8dd955ee8305554d89d1c64486c7"></a>

```
void* HdfDeviceIoClient::priv
```

 **Description:**

Private data of the client object. The driver can use  **priv**  to bind the internal data with the client. 

