# transform.h<a name="ZH-CN_TOPIC_0000001054799581"></a>

-   [Overview](#section1344393400165629)
-   [Summary](#section1626555434165629)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1344393400165629"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Provides functions to transform components, points, and line segments, including rotation and scaling. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1626555434165629"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1311342459165629"></a>
<table><thead align="left"><tr id="row723922258165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1684391041165629"><a name="p1684391041165629"></a><a name="p1684391041165629"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p27498225165629"><a name="p27498225165629"></a><a name="p27498225165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1725802711165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890291274165629"><a name="p1890291274165629"></a><a name="p1890291274165629"></a><a href="OHOS-TransformMap.md">OHOS::TransformMap</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230270168165629"><a name="p1230270168165629"></a><a name="p1230270168165629"></a>Transforms a rectangle, including rotation and scaling. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table1833634665165629"></a>
<table><thead align="left"><tr id="row1999198569165629"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p950315557165629"><a name="p950315557165629"></a><a name="p950315557165629"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p233174221165629"><a name="p233174221165629"></a><a name="p233174221165629"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1381140741165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p206896124165629"><a name="p206896124165629"></a><a name="p206896124165629"></a><a href="Graphic.md#ga9bb4f3256ad01b5abdd347de1fea09ee">OHOS::Rotate</a> (const Vector2&lt; int16_t &gt; &amp;point, int16_t angle, const Vector2&lt; int16_t &gt; &amp;pivot, Vector2&lt; int16_t &gt; &amp;out)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p364869833165629"><a name="p364869833165629"></a><a name="p364869833165629"></a>void </p>
<p id="p1647579977165629"><a name="p1647579977165629"></a><a name="p1647579977165629"></a>Rotates a point around the pivot by a certain angle. </p>
</td>
</tr>
<tr id="row142228895165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111827791165629"><a name="p111827791165629"></a><a name="p111827791165629"></a><a href="Graphic.md#gac57d591450b239f8e375f4c7b287f0d8">OHOS::Rotate</a> (const Line &amp;origLine, int16_t angle, const Vector2&lt; int16_t &gt; &amp;pivot, Line &amp;out)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p44948928165629"><a name="p44948928165629"></a><a name="p44948928165629"></a>void </p>
<p id="p632493127165629"><a name="p632493127165629"></a><a name="p632493127165629"></a>Rotates a line around the pivot by a certain angle. </p>
</td>
</tr>
<tr id="row550669960165629"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098255051165629"><a name="p2098255051165629"></a><a name="p2098255051165629"></a><a href="Graphic.md#ga77d0dea6024cd2bb980f27f789db77c3">OHOS::Rotate</a> (const <a href="Rect.md">Rect</a> &amp;origRect, int16_t angle, const Vector2&lt; int16_t &gt; &amp;pivot, Polygon &amp;out)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501156371165629"><a name="p501156371165629"></a><a name="p501156371165629"></a>void </p>
<p id="p2131553966165629"><a name="p2131553966165629"></a><a name="p2131553966165629"></a>Rotates a rectangle around the pivot by a certain angle. </p>
</td>
</tr>
</tbody>
</table>

