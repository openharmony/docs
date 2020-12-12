# FormatFrame<a name="ZH-CN_TOPIC_0000001055039514"></a>

-   [Overview](#section1358808790165631)
-   [Summary](#section204336603165631)
-   [Data Fields](#pub-attribs)
-   [Details](#section1167159755165631)
-   [Field](#section1590948647165631)
-   [data](#a632575f46669a67c78ab28049e5654c6)
-   [durationUs](#ab342d9f6536876e5d0a5952a9043ca2d)
-   [frameIndex](#a1a966266639de3b0b8db994232c71687)
-   [frameType](#a9cb91c927687f9875efa0d5600e04d1a)
-   [isKeyFrame](#a6a1cd875ac96a43d01524249a7f32026)
-   [item](#a9739fdfe949e2464d14a0a2c56f3fff6)
-   [itemCnt](#ace44c0b0dfc642c8a296e69b6a3e7d9d)
-   [len](#aa8bb4e843e90b0f4a7dd95d23faee65f)
-   [position](#a8d0f0f738cab6d389423afd66dddcab2)
-   [timestampUs](#a290ab46c3660d73cde08b268bf36c323)
-   [trackId](#a36d27cb02e6d06479354618e959a429a)

## **Overview**<a name="section1358808790165631"></a>

**Related Modules:**

[Format](Format.md)

**Description:**

Defines the data frame, which is used for data transferring. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section204336603165631"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1669161731165631"></a>
<table><thead align="left"><tr id="row1356109936165631"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1312613761165631"><a name="p1312613761165631"></a><a name="p1312613761165631"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p577645112165631"><a name="p577645112165631"></a><a name="p577645112165631"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1742667383165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p29947338165631"><a name="p29947338165631"></a><a name="p29947338165631"></a><a href="FormatFrame.md#a9cb91c927687f9875efa0d5600e04d1a">frameType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520162054165631"><a name="p520162054165631"></a><a name="p520162054165631"></a><a href="Format.md#gad495a9f61af7fff07d7e97979d1ab854">FrameType</a> </p>
</td>
</tr>
<tr id="row617658790165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302629778165631"><a name="p1302629778165631"></a><a name="p1302629778165631"></a><a href="FormatFrame.md#a36d27cb02e6d06479354618e959a429a">trackId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053955853165631"><a name="p1053955853165631"></a><a name="p1053955853165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row2063789734165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482343615165631"><a name="p482343615165631"></a><a name="p482343615165631"></a><a href="FormatFrame.md#a6a1cd875ac96a43d01524249a7f32026">isKeyFrame</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p312691522165631"><a name="p312691522165631"></a><a name="p312691522165631"></a>bool </p>
</td>
</tr>
<tr id="row598925687165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195559109165631"><a name="p195559109165631"></a><a name="p195559109165631"></a><a href="FormatFrame.md#a290ab46c3660d73cde08b268bf36c323">timestampUs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117203077165631"><a name="p1117203077165631"></a><a name="p1117203077165631"></a>int64_t </p>
</td>
</tr>
<tr id="row431169604165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16807577165631"><a name="p16807577165631"></a><a name="p16807577165631"></a><a href="FormatFrame.md#ab342d9f6536876e5d0a5952a9043ca2d">durationUs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719437132165631"><a name="p1719437132165631"></a><a name="p1719437132165631"></a>int64_t </p>
</td>
</tr>
<tr id="row1796296709165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1503699907165631"><a name="p1503699907165631"></a><a name="p1503699907165631"></a><a href="FormatFrame.md#a632575f46669a67c78ab28049e5654c6">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332308655165631"><a name="p332308655165631"></a><a name="p332308655165631"></a>uint8_t * </p>
</td>
</tr>
<tr id="row1967541260165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p957131561165631"><a name="p957131561165631"></a><a name="p957131561165631"></a><a href="FormatFrame.md#aa8bb4e843e90b0f4a7dd95d23faee65f">len</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190876507165631"><a name="p190876507165631"></a><a name="p190876507165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1155339629165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1428454039165631"><a name="p1428454039165631"></a><a name="p1428454039165631"></a><a href="FormatFrame.md#a1a966266639de3b0b8db994232c71687">frameIndex</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592200552165631"><a name="p592200552165631"></a><a name="p592200552165631"></a>uint32_t </p>
</td>
</tr>
<tr id="row1595532452165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p413105474165631"><a name="p413105474165631"></a><a name="p413105474165631"></a><a href="FormatFrame.md#a8d0f0f738cab6d389423afd66dddcab2">position</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889193039165631"><a name="p889193039165631"></a><a name="p889193039165631"></a>int64_t </p>
</td>
</tr>
<tr id="row1112432885165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295438268165631"><a name="p295438268165631"></a><a name="p295438268165631"></a><a href="FormatFrame.md#ace44c0b0dfc642c8a296e69b6a3e7d9d">itemCnt</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1941503674165631"><a name="p1941503674165631"></a><a name="p1941503674165631"></a>int32_t </p>
</td>
</tr>
<tr id="row116436525165631"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977856048165631"><a name="p1977856048165631"></a><a name="p1977856048165631"></a><a href="FormatFrame.md#a9739fdfe949e2464d14a0a2c56f3fff6">item</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1854524508165631"><a name="p1854524508165631"></a><a name="p1854524508165631"></a><a href="ParameterItem.md">ParameterItem</a> * </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1167159755165631"></a>

## **Field **<a name="section1590948647165631"></a>

## data<a name="a632575f46669a67c78ab28049e5654c6"></a>

```
uint8_t* FormatFrame::data
```

 **Description:**

Address of the data frame buffer 

## durationUs<a name="ab342d9f6536876e5d0a5952a9043ca2d"></a>

```
int64_t FormatFrame::durationUs
```

 **Description:**

Data frame duration, in us 

## frameIndex<a name="a1a966266639de3b0b8db994232c71687"></a>

```
uint32_t FormatFrame::frameIndex
```

 **Description:**

Data frame index. For the MPF container, the value indicates the index of the sub-image frame. 

## frameType<a name="a9cb91c927687f9875efa0d5600e04d1a"></a>

```
[FrameType](Format.md#gad495a9f61af7fff07d7e97979d1ab854) FormatFrame::frameType
```

 **Description:**

Data frame type. For details, see  [FrameType](Format.md#gad495a9f61af7fff07d7e97979d1ab854). 

## isKeyFrame<a name="a6a1cd875ac96a43d01524249a7f32026"></a>

```
bool FormatFrame::isKeyFrame
```

 **Description:**

Keyframe flag.  **false**: The data frame is not a keyframe.  **true**: The data frame is a keyframe. 

## item<a name="a9739fdfe949e2464d14a0a2c56f3fff6"></a>

```
[ParameterItem](ParameterItem.md)* FormatFrame::item
```

 **Description:**

Pointer to the parameter array 

## itemCnt<a name="ace44c0b0dfc642c8a296e69b6a3e7d9d"></a>

```
int32_t FormatFrame::itemCnt
```

 **Description:**

Number of parameters, which can be used for information such as side data, PSSH, DRM, and HDR. 

## len<a name="aa8bb4e843e90b0f4a7dd95d23faee65f"></a>

```
uint32_t FormatFrame::len
```

 **Description:**

Data frame length 

## position<a name="a8d0f0f738cab6d389423afd66dddcab2"></a>

```
int64_t FormatFrame::position
```

 **Description:**

Position of the data frame in the file 

## timestampUs<a name="a290ab46c3660d73cde08b268bf36c323"></a>

```
int64_t FormatFrame::timestampUs
```

 **Description:**

Timestamp of a data frame, in us 

## trackId<a name="a36d27cb02e6d06479354618e959a429a"></a>

```
uint32_t FormatFrame::trackId
```

 **Description:**

Index of the track where the data frame is located 

