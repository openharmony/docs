# HdfDevEventlistener<a name="ZH-CN_TOPIC_0000001055358108"></a>

-   [Overview](#section1479646434165631)
-   [Summary](#section1528394413165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1429703049165631)
-   [Field](#section1957606536165631)
-   [callBack](#ab242c593bb5f92f775087c86b7b6bba4)
-   [listNode](#a4cf02802e185796f2d373f7c938f8e24)
-   [priv](#a518808817b32cbb1e70a96f7009cbf5f)

## **Overview**<a name="section1479646434165631"></a>

**Related Modules:**

[Core](Core.md)

**Description:**

Defines a driver event listener object. 

**Since:**

1.0

## **Summary**<a name="section1528394413165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1464978174165631"></a>
<table><thead align="left"><tr id="row1106345817165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1038743169165631"><a name="p1038743169165631"></a><a name="p1038743169165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1100035069165631"><a name="p1100035069165631"></a><a name="p1100035069165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1949974808165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2076208782165631"><a name="p2076208782165631"></a><a name="p2076208782165631"></a><a href="HdfDevEventlistener.md#ab242c593bb5f92f775087c86b7b6bba4">callBack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885467067165631"><a name="p1885467067165631"></a><a name="p1885467067165631"></a><a href="Core.md#gae314b850ba4b0927007038cf8cc32580">OnEventReceived</a> </p>
</td>
</tr>
<tr id="row1855040346165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1696845928165631"><a name="p1696845928165631"></a><a name="p1696845928165631"></a><a href="HdfDevEventlistener.md#a4cf02802e185796f2d373f7c938f8e24">listNode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700143057165631"><a name="p1700143057165631"></a><a name="p1700143057165631"></a>struct <a href="DListHead.md">DListHead</a> </p>
</td>
</tr>
<tr id="row714936379165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904428178165631"><a name="p904428178165631"></a><a name="p904428178165631"></a><a href="HdfDevEventlistener.md#a518808817b32cbb1e70a96f7009cbf5f">priv</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641709165165631"><a name="p1641709165165631"></a><a name="p1641709165165631"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1429703049165631"></a>

## **Field **<a name="section1957606536165631"></a>

## callBack<a name="ab242c593bb5f92f775087c86b7b6bba4"></a>

```
[OnEventReceived](Core.md#gae314b850ba4b0927007038cf8cc32580) HdfDevEventlistener::callBack
```

 **Description:**

Callback invoked when the monitored device reports an event 

## listNode<a name="a4cf02802e185796f2d373f7c938f8e24"></a>

```
struct [DListHead](DListHead.md) HdfDevEventlistener::listNode
```

 **Description:**

Intrusive list node used by the HDF to manage listeners. You can ignore this node. 

## priv<a name="a518808817b32cbb1e70a96f7009cbf5f"></a>

```
void* HdfDevEventlistener::priv
```

 **Description:**

Private data of the listener, which is passed as the first input parameter in  **callback** 

