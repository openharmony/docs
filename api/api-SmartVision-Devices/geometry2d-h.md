# geometry2d.h<a name="ZH-CN_TOPIC_0000001054799567"></a>

-   [Overview](#section1261063187165627)
-   [Summary](#section616742317165627)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1261063187165627"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines attributes of 2D geometries \(including points, lines, rectangles, and polygons\) of the lightweight graphics system and provides functions for performing operations on the geometries. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section616742317165627"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table566262098165627"></a>
<table><thead align="left"><tr id="row1772302927165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1692320582165627"><a name="p1692320582165627"></a><a name="p1692320582165627"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p311799613165627"><a name="p311799613165627"></a><a name="p311799613165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2066747614165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483404254165627"><a name="p1483404254165627"></a><a name="p1483404254165627"></a><a href="OHOS-Line.md">OHOS::Line</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100894737165627"><a name="p1100894737165627"></a><a name="p1100894737165627"></a>Defines a line, which consists of the start and end points. </p>
</td>
</tr>
<tr id="row1344225321165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12857762165627"><a name="p12857762165627"></a><a name="p12857762165627"></a><a href="OHOS-Polygon.md">OHOS::Polygon</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1147764751165627"><a name="p1147764751165627"></a><a name="p1147764751165627"></a>Defines a polygon, including vertex coordinates and the maximum number of vertices (defined by <a href="Graphic.md#gafff78acb69e2b147b6f33d68e570ef54">MAX_VERTEX_NUM</a>). </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1427973054165627"></a>
<table><thead align="left"><tr id="row2094262397165627"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p777384451165627"><a name="p777384451165627"></a><a name="p777384451165627"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1257165700165627"><a name="p1257165700165627"></a><a name="p1257165700165627"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row880379445165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p346584718165627"><a name="p346584718165627"></a><a name="p346584718165627"></a><a href="Graphic.md#ga1779d4dd0671282d297f1693252ca9d9">OHOS::Intersect</a> (const Line &amp;a, const Line &amp;b, Vector2&lt; int16_t &gt; &amp;out)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1124880501165627"><a name="p1124880501165627"></a><a name="p1124880501165627"></a>bool </p>
<p id="p1722192775165627"><a name="p1722192775165627"></a><a name="p1722192775165627"></a>Checks whether line segment a and line segment b intersect, and returns the intersection point (if available). </p>
</td>
</tr>
<tr id="row634236858165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263487931165627"><a name="p1263487931165627"></a><a name="p1263487931165627"></a><a href="Graphic.md#gace8a8524c6f91aa2f0f9be73a628da20">OHOS::IsIntersect</a> (const Line &amp;a, const Line &amp;b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382764824165627"><a name="p382764824165627"></a><a name="p382764824165627"></a>bool </p>
<p id="p143094697165627"><a name="p143094697165627"></a><a name="p143094697165627"></a>Chekcs whether line segment a and line segment b intersect. </p>
</td>
</tr>
<tr id="row470282196165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591420432165627"><a name="p591420432165627"></a><a name="p591420432165627"></a><a href="Graphic.md#ga0001387a136a87fb2c2e2b5eb3363c72">OHOS::Clip</a> (Polygon &amp;poly, const Line &amp;line)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1433081978165627"><a name="p1433081978165627"></a><a name="p1433081978165627"></a>void </p>
<p id="p1721829473165627"><a name="p1721829473165627"></a><a name="p1721829473165627"></a>Clips a polygon by using a line segment. </p>
</td>
</tr>
<tr id="row1438713481165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6591647165627"><a name="p6591647165627"></a><a name="p6591647165627"></a><a href="Graphic.md#ga9fd2882e4813fbf4dbe77baa50d97b5c">OHOS::SuthHodgClip</a> (const <a href="Rect.md">Rect</a> &amp;clipRect, const Polygon &amp;polygon)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p177736534165627"><a name="p177736534165627"></a><a name="p177736534165627"></a>Polygon </p>
<p id="p389496884165627"><a name="p389496884165627"></a><a name="p389496884165627"></a>Implements Sutherland-Hodgman, an algorithm used for clipping polygons. </p>
</td>
</tr>
<tr id="row1391652714165627"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107885318165627"><a name="p2107885318165627"></a><a name="p2107885318165627"></a><a href="Graphic.md#ga22219a4351530d5a6914bdc5dcf406d0">OHOS::Clip</a> (const Line &amp;line, const Polygon &amp;poly, Vector2&lt; int16_t &gt; *pOut, uint8_t *pNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p673628810165627"><a name="p673628810165627"></a><a name="p673628810165627"></a>void </p>
<p id="p1159435521165627"><a name="p1159435521165627"></a><a name="p1159435521165627"></a>Clips a polygon by using a line segment and obtains the intersections. </p>
</td>
</tr>
</tbody>
</table>

