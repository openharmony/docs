# LayerBuffer<a name="ZH-CN_TOPIC_0000001055039524"></a>

-   [Overview](#section1817957125165632)
-   [Summary](#section635176130165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section924765344165632)
-   [Field](#section1571466726165632)
-   [data](#a9a1831091916905de22145585cf8b682)
-   [fenceId](#a46aa174ae3d0eb28fa7f3e53749fd5d1)
-   [height](#aec2e142ea67776ec4e91fc3d8d3389ae)
-   [pitch](#a62a06a9381ac2d6fa48115ce7d01920d)
-   [pixFormat](#a1ac426fb1997d872b347cae9cce94eb6)
-   [width](#a71196d704bd8a6a69b9bccf497b8224b)

## **Overview**<a name="section1817957125165632"></a>

**Related Modules:**

[Display](Display.md)

**Description:**

Defines the buffer, which is used to store layer data. 

## **Summary**<a name="section635176130165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1308352752165632"></a>
<table><thead align="left"><tr id="row484121331165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1098182050165632"><a name="p1098182050165632"></a><a name="p1098182050165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1834226265165632"><a name="p1834226265165632"></a><a name="p1834226265165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row192378663165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p308191026165632"><a name="p308191026165632"></a><a name="p308191026165632"></a><a href="LayerBuffer.md#a46aa174ae3d0eb28fa7f3e53749fd5d1">fenceId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759320707165632"><a name="p1759320707165632"></a><a name="p1759320707165632"></a>int32_t </p>
</td>
</tr>
<tr id="row754438395165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192368689165632"><a name="p1192368689165632"></a><a name="p1192368689165632"></a><a href="LayerBuffer.md#a71196d704bd8a6a69b9bccf497b8224b">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p177264162165632"><a name="p177264162165632"></a><a name="p177264162165632"></a>int32_t </p>
</td>
</tr>
<tr id="row191161255165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119526997165632"><a name="p2119526997165632"></a><a name="p2119526997165632"></a><a href="LayerBuffer.md#aec2e142ea67776ec4e91fc3d8d3389ae">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1443151036165632"><a name="p1443151036165632"></a><a name="p1443151036165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1473962906165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342140239165632"><a name="p342140239165632"></a><a name="p342140239165632"></a><a href="LayerBuffer.md#a62a06a9381ac2d6fa48115ce7d01920d">pitch</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320161235165632"><a name="p1320161235165632"></a><a name="p1320161235165632"></a>int32_t </p>
</td>
</tr>
<tr id="row2042950523165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p873802542165632"><a name="p873802542165632"></a><a name="p873802542165632"></a><a href="LayerBuffer.md#a1ac426fb1997d872b347cae9cce94eb6">pixFormat</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055362025165632"><a name="p1055362025165632"></a><a name="p1055362025165632"></a><a href="Codec.md#ga60883d4958a60b91661e97027a85072a">PixelFormat</a> </p>
</td>
</tr>
<tr id="row2120327821165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578591127165632"><a name="p578591127165632"></a><a name="p578591127165632"></a><a href="LayerBuffer.md#a9a1831091916905de22145585cf8b682">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65571335165632"><a name="p65571335165632"></a><a name="p65571335165632"></a><a href="BufferData.md">BufferData</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section924765344165632"></a>

## **Field **<a name="section1571466726165632"></a>

## data<a name="a9a1831091916905de22145585cf8b682"></a>

```
[BufferData](BufferData.md) LayerBuffer::data
```

 **Description:**

Layer buffer data 

## fenceId<a name="a46aa174ae3d0eb28fa7f3e53749fd5d1"></a>

```
int32_t LayerBuffer::fenceId
```

 **Description:**

Fence ID of the buffer 

## height<a name="aec2e142ea67776ec4e91fc3d8d3389ae"></a>

```
int32_t LayerBuffer::height
```

 **Description:**

Buffer height 

## pitch<a name="a62a06a9381ac2d6fa48115ce7d01920d"></a>

```
int32_t LayerBuffer::pitch
```

 **Description:**

Number of bytes from one row of pixels in memory to the next 

## pixFormat<a name="a1ac426fb1997d872b347cae9cce94eb6"></a>

```
[PixelFormat](Codec.md#ga60883d4958a60b91661e97027a85072a) LayerBuffer::pixFormat
```

 **Description:**

Pixel format of the buffer 

## width<a name="a71196d704bd8a6a69b9bccf497b8224b"></a>

```
int32_t LayerBuffer::width
```

 **Description:**

Buffer width 

