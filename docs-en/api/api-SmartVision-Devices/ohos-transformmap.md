# OHOS::TransformMap<a name="EN-US_TOPIC_0000001055078173"></a>

-   [Overview](#section1211423715165635)
-   [Summary](#section827625912165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1211423715165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Transforms a rectangle, including rotation and scaling. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section827625912165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1368306344165635"></a>
<table><thead align="left"><tr id="row1682035340165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2070243221165635"><a name="p2070243221165635"></a><a name="p2070243221165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p928342860165635"><a name="p928342860165635"></a><a name="p928342860165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1985044128165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1791087002165635"><a name="p1791087002165635"></a><a name="p1791087002165635"></a><a href="graphic.md#ga3b20453b0a161da3a1a761fd75da9975">TransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006055129165635"><a name="p2006055129165635"></a><a name="p2006055129165635"></a> </p>
<p id="p1124883474165635"><a name="p1124883474165635"></a><a name="p1124883474165635"></a>The default constructor used to create a <strong id="b2063908787165635"><a name="b2063908787165635"></a><a name="b2063908787165635"></a><a href="ohos-transformmap.md">TransformMap</a></strong> instance. </p>
</td>
</tr>
<tr id="row563615386165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771621224165635"><a name="p1771621224165635"></a><a name="p1771621224165635"></a><a href="graphic.md#ga84f0243719d4b43d0ee3a22e74c165bb">TransformMap</a> (const <a href="ohos-rect.md">Rect</a> &amp;rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1730573579165635"><a name="p1730573579165635"></a><a name="p1730573579165635"></a> </p>
<p id="p569562348165635"><a name="p569562348165635"></a><a name="p569562348165635"></a>A constructor used to create a <strong id="b1726124673165635"><a name="b1726124673165635"></a><a name="b1726124673165635"></a><a href="ohos-transformmap.md">TransformMap</a></strong> instance. </p>
</td>
</tr>
<tr id="row155640203165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p691131251165635"><a name="p691131251165635"></a><a name="p691131251165635"></a><a href="graphic.md#gaaa46c8a5a343df76b418423a9f2344ba">~TransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1867270788165635"><a name="p1867270788165635"></a><a name="p1867270788165635"></a> </p>
<p id="p1454573730165635"><a name="p1454573730165635"></a><a name="p1454573730165635"></a>A destructor used to delete the <strong id="b200275188165635"><a name="b200275188165635"></a><a name="b200275188165635"></a><a href="ohos-transformmap.md">TransformMap</a></strong> instance. </p>
</td>
</tr>
<tr id="row410642658165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p298682489165635"><a name="p298682489165635"></a><a name="p298682489165635"></a><a href="graphic.md#ga6a50a29fe85e89c6d4445822c7a2946b">GetClockWise</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330576867165635"><a name="p1330576867165635"></a><a name="p1330576867165635"></a>bool </p>
<p id="p1381839732165635"><a name="p1381839732165635"></a><a name="p1381839732165635"></a>Checks whether the vertex coordinates of a polygon are clockwise. </p>
</td>
</tr>
<tr id="row1926370801165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550017567165635"><a name="p1550017567165635"></a><a name="p1550017567165635"></a><a href="graphic.md#gaaf0b94adde30d2ee1f3c82ef5d8c60c9">SetPolygon</a> (const <a href="ohos-polygon.md">Polygon</a> &amp;polygon)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797956192165635"><a name="p1797956192165635"></a><a name="p1797956192165635"></a>void </p>
<p id="p1725962748165635"><a name="p1725962748165635"></a><a name="p1725962748165635"></a>Sets a polygon after rectangle transformation. </p>
</td>
</tr>
<tr id="row628622229165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868837171165635"><a name="p868837171165635"></a><a name="p868837171165635"></a><a href="graphic.md#ga84f8d315da89e7aae7bf29478dbb51df">GetPolygon</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p233846154165635"><a name="p233846154165635"></a><a name="p233846154165635"></a><a href="ohos-polygon.md">Polygon</a> </p>
<p id="p1177929046165635"><a name="p1177929046165635"></a><a name="p1177929046165635"></a>Obtains the polygon after rectangle transformation. </p>
</td>
</tr>
<tr id="row1191748454165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246778072165635"><a name="p1246778072165635"></a><a name="p1246778072165635"></a><a href="graphic.md#ga8a44fb7a813f5f183307191e96e18670">GetPivot</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166112786165635"><a name="p166112786165635"></a><a name="p166112786165635"></a><a href="ohos-point.md">Point</a> </p>
<p id="p253771564165635"><a name="p253771564165635"></a><a name="p253771564165635"></a>Obtains the pivot for the rotation or scaling operation. </p>
</td>
</tr>
<tr id="row1057128037165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446210562165635"><a name="p1446210562165635"></a><a name="p1446210562165635"></a><a href="graphic.md#ga84ec8032b9c8a4121c7464e6c14c7d01">IsInvalid</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1701082177165635"><a name="p1701082177165635"></a><a name="p1701082177165635"></a>bool </p>
<p id="p429790735165635"><a name="p429790735165635"></a><a name="p429790735165635"></a>Checks whether the <strong id="b680740994165635"><a name="b680740994165635"></a><a name="b680740994165635"></a><a href="ohos-transformmap.md">TransformMap</a></strong> instance is invalid. When the vertices are all 0, the <strong id="b1971653630165635"><a name="b1971653630165635"></a><a name="b1971653630165635"></a><a href="ohos-transformmap.md">TransformMap</a></strong> is invalid. </p>
</td>
</tr>
<tr id="row948936102165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990064449165635"><a name="p990064449165635"></a><a name="p990064449165635"></a><a href="graphic.md#gaa2d8a5d822e40757f98c2a2820efed99">GetBoxRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1081581908165635"><a name="p1081581908165635"></a><a name="p1081581908165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1893318013165635"><a name="p1893318013165635"></a><a name="p1893318013165635"></a>Obtains the minimum rectangle that can contain a polygon. All vertices of the polygon are inside this rectangle. </p>
</td>
</tr>
<tr id="row1978706591165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190927007165635"><a name="p190927007165635"></a><a name="p190927007165635"></a><a href="graphic.md#gaea4c507789bf4c27daef3e81176c656d">Rotate</a> (int16_t angle, const <a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; &amp;pivot)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599120706165635"><a name="p599120706165635"></a><a name="p599120706165635"></a>void </p>
<p id="p55916495165635"><a name="p55916495165635"></a><a name="p55916495165635"></a>Rotates the rectangle. </p>
</td>
</tr>
<tr id="row417684678165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864324099165635"><a name="p1864324099165635"></a><a name="p1864324099165635"></a><a href="graphic.md#gae9344b31226a5a35035ccb845bf9cff2">Scale</a> (const <a href="ohos-vector2-t.md">Vector2</a>&lt; float &gt; scale, const <a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; &amp;pivot)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1451024218165635"><a name="p1451024218165635"></a><a name="p1451024218165635"></a>void </p>
<p id="p1090966922165635"><a name="p1090966922165635"></a><a name="p1090966922165635"></a>Scales the rectangle. </p>
</td>
</tr>
<tr id="row1160209453165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302679728165635"><a name="p1302679728165635"></a><a name="p1302679728165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734487395165635"><a name="p1734487395165635"></a><a name="p1734487395165635"></a>void * </p>
<p id="p681453989165635"><a name="p681453989165635"></a><a name="p681453989165635"></a>Overrides the <strong id="b1197131075165635"><a name="b1197131075165635"></a><a name="b1197131075165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row626343942165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1001455227165635"><a name="p1001455227165635"></a><a name="p1001455227165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333027055165635"><a name="p333027055165635"></a><a name="p333027055165635"></a>void </p>
<p id="p1891808813165635"><a name="p1891808813165635"></a><a name="p1891808813165635"></a>Overrides the <strong id="b1570580037165635"><a name="b1570580037165635"></a><a name="b1570580037165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

