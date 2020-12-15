# OHOS::Polygon<a name="ZH-CN_TOPIC_0000001055678124"></a>

-   [Overview](#section1782396468165635)
-   [Summary](#section1199869771165635)
-   [Public Member Functions](#pub-methods)
-   [Static Public Attributes](#pub-static-attribs)

## **Overview**<a name="section1782396468165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a polygon, including vertex coordinates and the maximum number of vertices \(defined by  [MAX\_VERTEX\_NUM](Graphic.md#gafff78acb69e2b147b6f33d68e570ef54)\). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1199869771165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1333158243165635"></a>
<table><thead align="left"><tr id="row1240968868165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p543168693165635"><a name="p543168693165635"></a><a name="p543168693165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1046364270165635"><a name="p1046364270165635"></a><a name="p1046364270165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1518332221165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1382318339165635"><a name="p1382318339165635"></a><a name="p1382318339165635"></a><a href="Graphic.md#ga56fa89b7be39ff928c8ad488bbaddac3">Polygon</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916912601165635"><a name="p916912601165635"></a><a name="p916912601165635"></a> </p>
<p id="p2076813365165635"><a name="p2076813365165635"></a><a name="p2076813365165635"></a>The default constructor used to create a <strong id="b423876747165635"><a name="b423876747165635"></a><a name="b423876747165635"></a><a href="OHOS-Polygon.md">Polygon</a></strong> instance. </p>
</td>
</tr>
<tr id="row699137694165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807881490165635"><a name="p1807881490165635"></a><a name="p1807881490165635"></a><a href="Graphic.md#gaa3be3f3605efe49629c024974e56da6a">Polygon</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p784022495165635"><a name="p784022495165635"></a><a name="p784022495165635"></a> </p>
<p id="p116567836165635"><a name="p116567836165635"></a><a name="p116567836165635"></a>A constructor used to construct a <strong id="b380393719165635"><a name="b380393719165635"></a><a name="b380393719165635"></a><a href="OHOS-Polygon.md">Polygon</a></strong> instance based on a rectangle. </p>
</td>
</tr>
<tr id="row1355122968165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p227189656165635"><a name="p227189656165635"></a><a name="p227189656165635"></a><a href="Graphic.md#ga54df053b5f430ed2ee7be14a898f668d">Polygon</a> (const <a href="OHOS-Vector2-T.md">Vector2</a>&lt; int16_t &gt; *vertexes, const uint8_t vertexNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058213800165635"><a name="p1058213800165635"></a><a name="p1058213800165635"></a> </p>
<p id="p1614851811165635"><a name="p1614851811165635"></a><a name="p1614851811165635"></a>A constructor used to create a <strong id="b759402617165635"><a name="b759402617165635"></a><a name="b759402617165635"></a><a href="OHOS-Polygon.md">Polygon</a></strong> instance based on the vertex coordinates and the number of coordinates. </p>
</td>
</tr>
<tr id="row234270128165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2086231217165635"><a name="p2086231217165635"></a><a name="p2086231217165635"></a><a href="Graphic.md#gab27ef37ff8b5462c771aed96f58dcac6">~Polygon</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457021037165635"><a name="p457021037165635"></a><a name="p457021037165635"></a> </p>
<p id="p1647757986165635"><a name="p1647757986165635"></a><a name="p1647757986165635"></a>A destructor used to delete the <strong id="b179433688165635"><a name="b179433688165635"></a><a name="b179433688165635"></a><a href="OHOS-Polygon.md">Polygon</a></strong> instance. </p>
</td>
</tr>
<tr id="row132805589165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846573130165635"><a name="p1846573130165635"></a><a name="p1846573130165635"></a><a href="Graphic.md#ga73295e4e05e9063082fb33b9847f4831">MakeAABB</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p689039265165635"><a name="p689039265165635"></a><a name="p689039265165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p838391891165635"><a name="p838391891165635"></a><a name="p838391891165635"></a>Obtains the minimum rectangle that can contain the polygon. All vertices of the polygon are inside this rectangle. </p>
</td>
</tr>
<tr id="row220288810165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102788396165635"><a name="p2102788396165635"></a><a name="p2102788396165635"></a><a href="Graphic.md#gaca0240aa7a65b24365064f296ff38a63">GetVertexNum</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267699236165635"><a name="p267699236165635"></a><a name="p267699236165635"></a>uint8_t </p>
<p id="p277780212165635"><a name="p277780212165635"></a><a name="p277780212165635"></a>Obtains the number of vertices of the polygon. </p>
</td>
</tr>
<tr id="row2110602109165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257222737165635"><a name="p257222737165635"></a><a name="p257222737165635"></a><a href="Graphic.md#gad1990bc3055e0155d324479a2bb3baf1">SetVertexNum</a> (uint8_t vertexNum)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1482389057165635"><a name="p1482389057165635"></a><a name="p1482389057165635"></a>void </p>
<p id="p766717377165635"><a name="p766717377165635"></a><a name="p766717377165635"></a>Sets the number of vertices of a polygon. </p>
</td>
</tr>
<tr id="row299742873165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1802912289165635"><a name="p1802912289165635"></a><a name="p1802912289165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p701602986165635"><a name="p701602986165635"></a><a name="p701602986165635"></a>void * </p>
<p id="p727867929165635"><a name="p727867929165635"></a><a name="p727867929165635"></a>Overrides the <strong id="b514248711165635"><a name="b514248711165635"></a><a name="b514248711165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row300697994165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208600202165635"><a name="p1208600202165635"></a><a name="p1208600202165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403578269165635"><a name="p403578269165635"></a><a name="p403578269165635"></a>void </p>
<p id="p430322359165635"><a name="p430322359165635"></a><a name="p430322359165635"></a>Overrides the <strong id="b1387850890165635"><a name="b1387850890165635"></a><a name="b1387850890165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Attributes<a name="pub-static-attribs"></a>

<a name="table369501568165635"></a>
<table><thead align="left"><tr id="row2105351184165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1656547124165635"><a name="p1656547124165635"></a><a name="p1656547124165635"></a>Static Public Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2108929653165635"><a name="p2108929653165635"></a><a name="p2108929653165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row767284033165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p785794173165635"><a name="p785794173165635"></a><a name="p785794173165635"></a><a href="Graphic.md#gafff78acb69e2b147b6f33d68e570ef54">MAX_VERTEX_NUM</a> = 8</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;</td>
</tr>
</tbody>
</table>

