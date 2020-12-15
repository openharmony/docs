# GrallocBuffer<a name="ZH-CN_TOPIC_0000001054718125"></a>

-   [Overview](#section1994522661165631)
-   [Summary](#section197328879165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section694221750165631)
-   [Field](#section924837173165631)
-   [hdl](#a6bdce5004be0cb1c41326c0621581fff)
-   [size](#a756f3d9e23d7e97a28a5228765cb8cf3)
-   [type](#ad66bdf06909350cd1a4e5c45349e72ae)
-   [virAddr](#a3196376b8b938cf96e008152f1ddceee)

## **Overview**<a name="section1994522661165631"></a>

**Related Modules:**

[Display](Display.md)

**Description:**

Defines the memory buffer, including the buffer handle, memory type, memory size, and virtual memory address. 

## **Summary**<a name="section197328879165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1983617942165631"></a>
<table><thead align="left"><tr id="row342083585165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p955829571165631"><a name="p955829571165631"></a><a name="p955829571165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1665117093165631"><a name="p1665117093165631"></a><a name="p1665117093165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1486559222165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152676891165631"><a name="p1152676891165631"></a><a name="p1152676891165631"></a><a href="GrallocBuffer.md#a6bdce5004be0cb1c41326c0621581fff">hdl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282765638165631"><a name="p282765638165631"></a><a name="p282765638165631"></a><a href="BufferHandle.md">BufferHandle</a> </p>
</td>
</tr>
<tr id="row1316329232165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1955849843165631"><a name="p1955849843165631"></a><a name="p1955849843165631"></a><a href="GrallocBuffer.md#ad66bdf06909350cd1a4e5c45349e72ae">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1416116134165631"><a name="p1416116134165631"></a><a name="p1416116134165631"></a><a href="Display.md#gabd31f838aefffa46191d0d7dc36a96b2">MemType</a> </p>
</td>
</tr>
<tr id="row2109833494165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1525220670165631"><a name="p1525220670165631"></a><a name="p1525220670165631"></a><a href="GrallocBuffer.md#a756f3d9e23d7e97a28a5228765cb8cf3">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2061653179165631"><a name="p2061653179165631"></a><a name="p2061653179165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1276490407165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1333979981165631"><a name="p1333979981165631"></a><a name="p1333979981165631"></a><a href="GrallocBuffer.md#a3196376b8b938cf96e008152f1ddceee">virAddr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1074708220165631"><a name="p1074708220165631"></a><a name="p1074708220165631"></a>void * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section694221750165631"></a>

## **Field **<a name="section924837173165631"></a>

## hdl<a name="a6bdce5004be0cb1c41326c0621581fff"></a>

```
[BufferHandle](BufferHandle.md) GrallocBuffer::hdl
```

 **Description:**

Buffer handle 

## size<a name="a756f3d9e23d7e97a28a5228765cb8cf3"></a>

```
uint32_t GrallocBuffer::size
```

 **Description:**

Size of the requested memory 

## type<a name="ad66bdf06909350cd1a4e5c45349e72ae"></a>

```
[MemType](Display.md#gabd31f838aefffa46191d0d7dc36a96b2) GrallocBuffer::type
```

 **Description:**

Type of the requested memory 

## virAddr<a name="a3196376b8b938cf96e008152f1ddceee"></a>

```
void* GrallocBuffer::virAddr
```

 **Description:**

Virtual address of the requested memory 

