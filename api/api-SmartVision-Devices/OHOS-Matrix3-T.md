# OHOS::Matrix3< T \><a name="ZH-CN_TOPIC_0000001055039548"></a>

-   [Overview](#section386546175165635)
-   [Summary](#section157087823165635)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section386546175165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

template<typename T\> class OHOS::Matrix3< T \>

Defines a 3 x 3 matrix. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section157087823165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table933725830165635"></a>
<table><thead align="left"><tr id="row1115124459165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1897201397165635"><a name="p1897201397165635"></a><a name="p1897201397165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p602531282165635"><a name="p602531282165635"></a><a name="p602531282165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1117874391165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p971055069165635"><a name="p971055069165635"></a><a name="p971055069165635"></a><a href="Graphic.md#ga8fedd026cac422882e9c0a0d5d1f3b50">Matrix3</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826514908165635"><a name="p1826514908165635"></a><a name="p1826514908165635"></a> </p>
<p id="p259212125165635"><a name="p259212125165635"></a><a name="p259212125165635"></a>Defines a <strong id="b1260905481165635"><a name="b1260905481165635"></a><a name="b1260905481165635"></a><a href="OHOS-Matrix3-T.md">Matrix3</a></strong> instance and initializes the 3 x 3 matrix data. </p>
</td>
</tr>
<tr id="row2024278348165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p188332237165635"><a name="p188332237165635"></a><a name="p188332237165635"></a><a href="Graphic.md#ga068d055d130c7c46269072bf65254082">Matrix3</a> (T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560715822165635"><a name="p560715822165635"></a><a name="p560715822165635"></a> </p>
<p id="p575347166165635"><a name="p575347166165635"></a><a name="p575347166165635"></a>Defines a <strong id="b635026736165635"><a name="b635026736165635"></a><a name="b635026736165635"></a><a href="OHOS-Matrix3-T.md">Matrix3</a></strong> instance and initializes the 3 x 3 matrix data. </p>
</td>
</tr>
<tr id="row906829433165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p923363680165635"><a name="p923363680165635"></a><a name="p923363680165635"></a><a href="Graphic.md#ga9cf7c2656623468c34003bb3c4056a72">~Matrix3</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1589326720165635"><a name="p1589326720165635"></a><a name="p1589326720165635"></a> </p>
<p id="p1224616503165635"><a name="p1224616503165635"></a><a name="p1224616503165635"></a>A destructor used to delete the <strong id="b846736227165635"><a name="b846736227165635"></a><a name="b846736227165635"></a><a href="OHOS-Matrix3-T.md">Matrix3</a></strong> instance. </p>
</td>
</tr>
<tr id="row1990190063165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116314066165635"><a name="p2116314066165635"></a><a name="p2116314066165635"></a><a href="Graphic.md#ga8fd60ee68cc3a51d8c7ea9d3d665323c">GetData</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401512352165635"><a name="p1401512352165635"></a><a name="p1401512352165635"></a>const T * </p>
<p id="p1275152485165635"><a name="p1275152485165635"></a><a name="p1275152485165635"></a>Obtains the 3 x 3 matrix data. </p>
</td>
</tr>
<tr id="row579771177165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1746217482165635"><a name="p1746217482165635"></a><a name="p1746217482165635"></a><a href="Graphic.md#ga5464ffd57d0abbd0381b2a6cf3a7d2fb">Determinant</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722175195165635"><a name="p722175195165635"></a><a name="p722175195165635"></a>T </p>
<p id="p1098789654165635"><a name="p1098789654165635"></a><a name="p1098789654165635"></a>Obtains the determinant of the matrix. </p>
</td>
</tr>
<tr id="row1031145129165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847194281165635"><a name="p847194281165635"></a><a name="p847194281165635"></a><a href="Graphic.md#gabf1edc9a01bace13596de01615ae20a2">Inverse</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088287770165635"><a name="p1088287770165635"></a><a name="p1088287770165635"></a><a href="OHOS-Matrix3-T.md">Matrix3</a> </p>
<p id="p101818777165635"><a name="p101818777165635"></a><a name="p101818777165635"></a>Obtains the inverse matrix. </p>
</td>
</tr>
<tr id="row1868685041165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391330888165635"><a name="p1391330888165635"></a><a name="p1391330888165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832983104165635"><a name="p1832983104165635"></a><a name="p1832983104165635"></a>void * </p>
<p id="p11037352165635"><a name="p11037352165635"></a><a name="p11037352165635"></a>Overrides the <strong id="b1412025819165635"><a name="b1412025819165635"></a><a name="b1412025819165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1400609230165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921271886165635"><a name="p921271886165635"></a><a name="p921271886165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501414129165635"><a name="p1501414129165635"></a><a name="p1501414129165635"></a>void </p>
<p id="p848396715165635"><a name="p848396715165635"></a><a name="p848396715165635"></a>Overrides the <strong id="b1458441360165635"><a name="b1458441360165635"></a><a name="b1458441360165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table114274627165635"></a>
<table><thead align="left"><tr id="row1712795427165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1789722799165635"><a name="p1789722799165635"></a><a name="p1789722799165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1205841079165635"><a name="p1205841079165635"></a><a name="p1205841079165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row273776524165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1148074840165635"><a name="p1148074840165635"></a><a name="p1148074840165635"></a><a href="Graphic.md#ga8bd72462c8fdba21d3a805a415a88d06">Rotate</a> (T angle, const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; T &gt; &amp;pivot)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p529217774165635"><a name="p529217774165635"></a><a name="p529217774165635"></a>static <a href="OHOS-Matrix3-T.md">Matrix3</a> </p>
<p id="p90326044165635"><a name="p90326044165635"></a><a name="p90326044165635"></a>Obtains a rotation matrix. After a matrix is rotated, its data is shifted leftwards by 15 bits. Therefore, the result data needs to be shifted rightwards by 15 bits. </p>
</td>
</tr>
<tr id="row725059262165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081853051165635"><a name="p1081853051165635"></a><a name="p1081853051165635"></a><a href="Graphic.md#ga915aa59cac37c6584fafb06a06046087">Scale</a> (const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; T &gt; &amp;scale, const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; T &gt; &amp;fixed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1460390300165635"><a name="p1460390300165635"></a><a name="p1460390300165635"></a>static <a href="OHOS-Matrix3-T.md">Matrix3</a> </p>
<p id="p2073623022165635"><a name="p2073623022165635"></a><a name="p2073623022165635"></a>Obtains the scaling matrix. After a matrix is scaled, its data is shifted leftwards by 8 bits. Therefore, the result data needs to be shifted rightwards by 8 bits. </p>
</td>
</tr>
<tr id="row38496955165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p484214865165635"><a name="p484214865165635"></a><a name="p484214865165635"></a><a href="Graphic.md#gab1cbae80ef16538294c97ba81626970e">Translate</a> (const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; T &gt; &amp;trans)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169427457165635"><a name="p169427457165635"></a><a name="p169427457165635"></a>static <a href="OHOS-Matrix3-T.md">Matrix3</a>&lt; T &gt; </p>
<p id="p1951420762165635"><a name="p1951420762165635"></a><a name="p1951420762165635"></a>Obtains a matrix translation. </p>
</td>
</tr>
</tbody>
</table>

