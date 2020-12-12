# ResizableArray<a name="ZH-CN_TOPIC_0000001054879568"></a>

-   [Overview](#section913156862165635)
-   [Summary](#section1394600722165635)
-   [Data Fields](#pub-attribs)
-   [Details](#section1873355070165635)
-   [Field](#section880674006165635)
-   [actualLen](#a864822557f8d07f467d94fefd787d92a)
-   [element](#ab3aa1ba4f0d61e21e944b03c4a588b90)

## **Overview**<a name="section913156862165635"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Defines a variable-length queue. 

## **Summary**<a name="section1394600722165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1357990133165635"></a>
<table><thead align="left"><tr id="row738810048165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p24374038165635"><a name="p24374038165635"></a><a name="p24374038165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p872631449165635"><a name="p872631449165635"></a><a name="p872631449165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row572356165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893264862165635"><a name="p893264862165635"></a><a name="p893264862165635"></a><a href="ResizableArray.md#ab3aa1ba4f0d61e21e944b03c4a588b90">element</a> [<a href="Codec.md#gab34cc95c32c06b8d63cfbe62247eb6e2">ELEMENT_MAX_LEN</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1633730913165635"><a name="p1633730913165635"></a><a name="p1633730913165635"></a>uint32_t </p>
</td>
</tr>
<tr id="row149247796165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1795654057165635"><a name="p1795654057165635"></a><a name="p1795654057165635"></a><a href="ResizableArray.md#a864822557f8d07f467d94fefd787d92a">actualLen</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p944115000165635"><a name="p944115000165635"></a><a name="p944115000165635"></a>uint32_t </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1873355070165635"></a>

## **Field **<a name="section880674006165635"></a>

## actualLen<a name="a864822557f8d07f467d94fefd787d92a"></a>

```
uint32_t ResizableArray::actualLen
```

 **Description:**

Number of actual parameters 

## element<a name="ab3aa1ba4f0d61e21e944b03c4a588b90"></a>

```
uint32_t ResizableArray::element[[ELEMENT_MAX_LEN](Codec.md#gab34cc95c32c06b8d63cfbe62247eb6e2)]
```

 **Description:**

Array of reserved parameters 

