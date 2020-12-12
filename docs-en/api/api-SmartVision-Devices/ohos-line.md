# OHOS::Line<a name="EN-US_TOPIC_0000001054718157"></a>

-   [Overview](#section1215086311165635)
-   [Summary](#section62226344165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1215086311165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines a line, which consists of the start and end points. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section62226344165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table280486114165635"></a>
<table><thead align="left"><tr id="row473030309165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p23031925165635"><a name="p23031925165635"></a><a name="p23031925165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1061734868165635"><a name="p1061734868165635"></a><a name="p1061734868165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1724086758165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750086574165635"><a name="p750086574165635"></a><a name="p750086574165635"></a><a href="graphic.md#ga3c8dd952afc5a76f8628c7f702755bd8">Line</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653648830165635"><a name="p653648830165635"></a><a name="p653648830165635"></a> </p>
<p id="p1651946372165635"><a name="p1651946372165635"></a><a name="p1651946372165635"></a>The default constructor used to create a <strong id="b2052027243165635"><a name="b2052027243165635"></a><a name="b2052027243165635"></a><a href="ohos-line.md">Line</a></strong> instance. </p>
</td>
</tr>
<tr id="row1563818678165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643119449165635"><a name="p1643119449165635"></a><a name="p1643119449165635"></a><a href="graphic.md#ga0bda554c3c7d5950637a50ffbbec2269">Line</a> (const <a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; &amp;a, const <a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; &amp;b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p198013755165635"><a name="p198013755165635"></a><a name="p198013755165635"></a> </p>
<p id="p1191837648165635"><a name="p1191837648165635"></a><a name="p1191837648165635"></a>A constructor used to create a <strong id="b412179023165635"><a name="b412179023165635"></a><a name="b412179023165635"></a><a href="ohos-line.md">Line</a></strong> instance. </p>
</td>
</tr>
<tr id="row855262888165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1179227054165635"><a name="p1179227054165635"></a><a name="p1179227054165635"></a><a href="graphic.md#ga216de7fbcb274d28bb5a50d0e0692aa0">Line</a> (int16_t x1, int16_t <a href="math.md#ga369368526a105f3fba6776b11586070c">y1</a>, int16_t x2, int16_t y2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p974371170165635"><a name="p974371170165635"></a><a name="p974371170165635"></a> </p>
<p id="p2056813977165635"><a name="p2056813977165635"></a><a name="p2056813977165635"></a>A constructor used to create a <strong id="b2018531890165635"><a name="b2018531890165635"></a><a name="b2018531890165635"></a><a href="ohos-line.md">Line</a></strong> instance. </p>
</td>
</tr>
<tr id="row1369620947165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p101029229165635"><a name="p101029229165635"></a><a name="p101029229165635"></a><a href="graphic.md#ga86d5bfc47854c5e85363adce571de167">~Line</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2086833042165635"><a name="p2086833042165635"></a><a name="p2086833042165635"></a> </p>
<p id="p290962342165635"><a name="p290962342165635"></a><a name="p290962342165635"></a>A destructor used to delete the <strong id="b1816542252165635"><a name="b1816542252165635"></a><a name="b1816542252165635"></a><a href="ohos-line.md">Line</a></strong> instance. </p>
</td>
</tr>
<tr id="row1715618570165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061653342165635"><a name="p2061653342165635"></a><a name="p2061653342165635"></a><a href="graphic.md#gafeae0169d5e3e92fcbc743c09cd4f6d0">operator[]</a> (uint8_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p275144936165635"><a name="p275144936165635"></a><a name="p275144936165635"></a><a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; &amp; </p>
<p id="p706419025165635"><a name="p706419025165635"></a><a name="p706419025165635"></a>Obtains the start or end point of the line based on the value of <strong id="b381082541165635"><a name="b381082541165635"></a><a name="b381082541165635"></a>index</strong>. </p>
</td>
</tr>
<tr id="row881897858165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1797321558165635"><a name="p1797321558165635"></a><a name="p1797321558165635"></a><a href="graphic.md#ga3f747832db7335f2198c7746140a6631">operator[]</a> (uint8_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1774951951165635"><a name="p1774951951165635"></a><a name="p1774951951165635"></a>const <a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; </p>
<p id="p1626257606165635"><a name="p1626257606165635"></a><a name="p1626257606165635"></a>Obtains the start or end point of the line based on the value of <strong id="b1159827393165635"><a name="b1159827393165635"></a><a name="b1159827393165635"></a>index</strong>. </p>
</td>
</tr>
<tr id="row1866471797165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p215106214165635"><a name="p215106214165635"></a><a name="p215106214165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356934190165635"><a name="p356934190165635"></a><a name="p356934190165635"></a>void * </p>
<p id="p73440000165635"><a name="p73440000165635"></a><a name="p73440000165635"></a>Overrides the <strong id="b69541011165635"><a name="b69541011165635"></a><a name="b69541011165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row2087399524165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790967307165635"><a name="p1790967307165635"></a><a name="p1790967307165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771756686165635"><a name="p771756686165635"></a><a name="p771756686165635"></a>void </p>
<p id="p1529411200165635"><a name="p1529411200165635"></a><a name="p1529411200165635"></a>Overrides the <strong id="b1691841450165635"><a name="b1691841450165635"></a><a name="b1691841450165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

