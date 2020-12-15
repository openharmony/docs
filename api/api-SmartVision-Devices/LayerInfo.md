# LayerInfo<a name="ZH-CN_TOPIC_0000001055518096"></a>

-   [Overview](#section888913598165632)
-   [Summary](#section1769336437165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1646535589165632)
-   [Field](#section369910035165632)
-   [bpp](#abf13f41732fac1713e51ab377c27922a)
-   [height](#aab83825af07139338b4536e45fe6d8fc)
-   [pixFormat](#a3a05038829a72f6afa87d504712f9117)
-   [type](#ade3a008d2aeccc966c226a60eb59e7ae)
-   [width](#a31b0ef7b0a83950c56dd1cafd20c9509)

## **Overview**<a name="section888913598165632"></a>

**Related Modules:**

[Display](Display.md)

**Description:**

Defines layer information. 

**[LayerInfo](LayerInfo.md)**  must be passed to the  **OpenLayer**  function, which creates a layer based on the layer information. 

## **Summary**<a name="section1769336437165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1673649684165632"></a>
<table><thead align="left"><tr id="row1455584651165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p945822237165632"><a name="p945822237165632"></a><a name="p945822237165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2109416329165632"><a name="p2109416329165632"></a><a name="p2109416329165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1522685044165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542813985165632"><a name="p542813985165632"></a><a name="p542813985165632"></a><a href="LayerInfo.md#a31b0ef7b0a83950c56dd1cafd20c9509">width</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691344271165632"><a name="p691344271165632"></a><a name="p691344271165632"></a>int32_t </p>
</td>
</tr>
<tr id="row760382017165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824357132165632"><a name="p1824357132165632"></a><a name="p1824357132165632"></a><a href="LayerInfo.md#aab83825af07139338b4536e45fe6d8fc">height</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42933487165632"><a name="p42933487165632"></a><a name="p42933487165632"></a>int32_t </p>
</td>
</tr>
<tr id="row1965801145165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638402671165632"><a name="p1638402671165632"></a><a name="p1638402671165632"></a><a href="LayerInfo.md#ade3a008d2aeccc966c226a60eb59e7ae">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989212539165632"><a name="p989212539165632"></a><a name="p989212539165632"></a><a href="Display.md#ga56943a0946e5f15e5e58054b8e7a04a4">LayerType</a> </p>
</td>
</tr>
<tr id="row1381989533165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817862482165632"><a name="p1817862482165632"></a><a name="p1817862482165632"></a><a href="LayerInfo.md#abf13f41732fac1713e51ab377c27922a">bpp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053404019165632"><a name="p1053404019165632"></a><a name="p1053404019165632"></a>int32_t </p>
</td>
</tr>
<tr id="row107362431165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1153942617165632"><a name="p1153942617165632"></a><a name="p1153942617165632"></a><a href="LayerInfo.md#a3a05038829a72f6afa87d504712f9117">pixFormat</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1138524533165632"><a name="p1138524533165632"></a><a name="p1138524533165632"></a><a href="Codec.md#ga60883d4958a60b91661e97027a85072a">PixelFormat</a> </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1646535589165632"></a>

## **Field **<a name="section369910035165632"></a>

## bpp<a name="abf13f41732fac1713e51ab377c27922a"></a>

```
int32_t LayerInfo::bpp
```

 **Description:**

Number of bits occupied by each pixel 

## height<a name="aab83825af07139338b4536e45fe6d8fc"></a>

```
int32_t LayerInfo::height
```

 **Description:**

Layer height 

## pixFormat<a name="a3a05038829a72f6afa87d504712f9117"></a>

```
[PixelFormat](Codec.md#ga60883d4958a60b91661e97027a85072a) LayerInfo::pixFormat
```

 **Description:**

Pixel format of the layer 

## type<a name="ade3a008d2aeccc966c226a60eb59e7ae"></a>

```
[LayerType](Display.md#ga56943a0946e5f15e5e58054b8e7a04a4) LayerInfo::type
```

 **Description:**

Layer type, which can be a graphics layer, overlay layer, and sideband layer 

## width<a name="a31b0ef7b0a83950c56dd1cafd20c9509"></a>

```
int32_t LayerInfo::width
```

 **Description:**

Layer width 

