# OHOS::DragEvent<a name="ZH-CN_TOPIC_0000001054479593"></a>

-   [Overview](#section1869934673165635)
-   [Summary](#section855427081165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1869934673165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a drag event, which indicates a certain movement \(more than 10 pixels\) after a view is pressed. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section855427081165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table254690770165635"></a>
<table><thead align="left"><tr id="row2051320529165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p845894509165635"><a name="p845894509165635"></a><a name="p845894509165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p291387417165635"><a name="p291387417165635"></a><a name="p291387417165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1332240989165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628802062165635"><a name="p1628802062165635"></a><a name="p1628802062165635"></a><a href="Graphic.md#gae9af79f667fc1324739d2a07fdd5d94e">DragEvent</a> (const <a href="OHOS-Point.md">Point</a> &amp;newPos, const <a href="OHOS-Point.md">Point</a> &amp;lastPos, const <a href="OHOS-Point.md">Point</a> &amp;totalLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1355298281165635"><a name="p1355298281165635"></a><a name="p1355298281165635"></a> </p>
<p id="p1622243846165635"><a name="p1622243846165635"></a><a name="p1622243846165635"></a>A constructor used to create a <strong id="b2115239055165635"><a name="b2115239055165635"></a><a name="b2115239055165635"></a><a href="OHOS-DragEvent.md">DragEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row1424840111165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1847153492165635"><a name="p1847153492165635"></a><a name="p1847153492165635"></a><a href="Graphic.md#gabed19ea6c1b15b861653485349133468">~DragEvent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591962487165635"><a name="p591962487165635"></a><a name="p591962487165635"></a>virtual </p>
<p id="p1066519197165635"><a name="p1066519197165635"></a><a name="p1066519197165635"></a>A destructor used to delete the <strong id="b1668021538165635"><a name="b1668021538165635"></a><a name="b1668021538165635"></a><a href="OHOS-DragEvent.md">DragEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row115193794165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284761124165635"><a name="p284761124165635"></a><a name="p284761124165635"></a><a href="Graphic.md#ga2b5a66f36249b23e69cccfc2859847c1">GetLastPoint</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1728828851165635"><a name="p1728828851165635"></a><a name="p1728828851165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p1627734080165635"><a name="p1627734080165635"></a><a name="p1627734080165635"></a>Obtains the coordinates of the last position in the drag event. </p>
</td>
</tr>
<tr id="row448008348165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616259817165635"><a name="p616259817165635"></a><a name="p616259817165635"></a><a href="Graphic.md#gadeada49639b81e405b8b54e2629361ee">GetStartPoint</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019610030165635"><a name="p1019610030165635"></a><a name="p1019610030165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p1054402475165635"><a name="p1054402475165635"></a><a name="p1054402475165635"></a>Obtains the start coordinates in the drag event. </p>
</td>
</tr>
<tr id="row1047106429165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p494995073165635"><a name="p494995073165635"></a><a name="p494995073165635"></a><a href="Graphic.md#ga8399680c67bc048745257a1b56250834">SetPreLastPoint</a> (const <a href="OHOS-Point.md">Point</a> &amp;preLastPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383351970165635"><a name="p383351970165635"></a><a name="p383351970165635"></a>void </p>
<p id="p876364739165635"><a name="p876364739165635"></a><a name="p876364739165635"></a>Sets the coordinates of the stay position before the last position in the drag event. </p>
</td>
</tr>
<tr id="row1208802490165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1940945749165635"><a name="p1940945749165635"></a><a name="p1940945749165635"></a><a href="Graphic.md#ga7a7198c95326af4ad0d2e2a85fb99ef6">GetPreLastPoint</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324445032165635"><a name="p1324445032165635"></a><a name="p1324445032165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p466779288165635"><a name="p466779288165635"></a><a name="p466779288165635"></a>Obtains the coordinates of the stay position before the last position in the drag event. </p>
</td>
</tr>
<tr id="row659294599165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1290016174165635"><a name="p1290016174165635"></a><a name="p1290016174165635"></a><a href="Graphic.md#gaf0ab47609e2dc46109f889847d9d7f9d">GetDragDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241420422165635"><a name="p1241420422165635"></a><a name="p1241420422165635"></a>uint8_t </p>
<p id="p1316299462165635"><a name="p1316299462165635"></a><a name="p1316299462165635"></a>Obtains the direction in the drag event. </p>
</td>
</tr>
<tr id="row1759280532165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643252796165635"><a name="p1643252796165635"></a><a name="p1643252796165635"></a><a href="Graphic.md#ga4e504ef2c5ef58bb0c79bbfdb0168d0d">GetDeltaX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24237005165635"><a name="p24237005165635"></a><a name="p24237005165635"></a>int16_t </p>
<p id="p1648992298165635"><a name="p1648992298165635"></a><a name="p1648992298165635"></a>Obtains the difference between the current position and the last position of the view in the x-axis. </p>
</td>
</tr>
<tr id="row526381519165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987254140165635"><a name="p1987254140165635"></a><a name="p1987254140165635"></a><a href="Graphic.md#ga13e3996546917d71612b34285f8b9dd7">GetDeltaY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p348415003165635"><a name="p348415003165635"></a><a name="p348415003165635"></a>int16_t </p>
<p id="p231630493165635"><a name="p231630493165635"></a><a name="p231630493165635"></a>Obtains the difference between the current position and the last position of the view in the y-axis. </p>
</td>
</tr>
<tr id="row1804898180165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p977719344165635"><a name="p977719344165635"></a><a name="p977719344165635"></a><a href="Graphic.md#ga89cd09ced5537a3479b7901ba8abc6da">Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p562015024165635"><a name="p562015024165635"></a><a name="p562015024165635"></a> </p>
<p id="p1113804360165635"><a name="p1113804360165635"></a><a name="p1113804360165635"></a>A default constructor used to create an <strong id="b859003536165635"><a name="b859003536165635"></a><a name="b859003536165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row629618224165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903216160165635"><a name="p903216160165635"></a><a name="p903216160165635"></a><a href="Graphic.md#ga57a9f07c8203c6a60f3b25c4edb526a0">Event</a> (const <a href="OHOS-Point.md">Point</a> &amp;curPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p141566341165635"><a name="p141566341165635"></a><a name="p141566341165635"></a> </p>
<p id="p1506928730165635"><a name="p1506928730165635"></a><a name="p1506928730165635"></a>A constructor used to create an <strong id="b1267198802165635"><a name="b1267198802165635"></a><a name="b1267198802165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row824723681165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242098923165635"><a name="p1242098923165635"></a><a name="p1242098923165635"></a><a href="Graphic.md#gabafa07a6393f4757f402bf9437561fa4">~Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p824215032165635"><a name="p824215032165635"></a><a name="p824215032165635"></a>virtual </p>
<p id="p1817459115165635"><a name="p1817459115165635"></a><a name="p1817459115165635"></a>A destructor used to delete the <strong id="b243881073165635"><a name="b243881073165635"></a><a name="b243881073165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row2017559049165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p309054584165635"><a name="p309054584165635"></a><a name="p309054584165635"></a><a href="Graphic.md#gaea811c661ad416d7f70912ad6fcce269">GetCurrentPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446231505165635"><a name="p446231505165635"></a><a name="p446231505165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p741118607165635"><a name="p741118607165635"></a><a name="p741118607165635"></a>Obtains the position where an event occurs. </p>
</td>
</tr>
<tr id="row15080833165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870623738165635"><a name="p870623738165635"></a><a name="p870623738165635"></a><a href="Graphic.md#ga7d56c2a99ab2c98eec9ebc03f67b7777">GetTimeStamp</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1352257119165635"><a name="p1352257119165635"></a><a name="p1352257119165635"></a>const TimeType &amp; </p>
<p id="p1791181561165635"><a name="p1791181561165635"></a><a name="p1791181561165635"></a>Obtains the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row705968532165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p449765599165635"><a name="p449765599165635"></a><a name="p449765599165635"></a><a href="Graphic.md#gabee47ba229e81c44f648cf5b3203010f">SetTimeStamp</a> (const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764038646165635"><a name="p1764038646165635"></a><a name="p1764038646165635"></a>void </p>
<p id="p1512193718165635"><a name="p1512193718165635"></a><a name="p1512193718165635"></a>Sets the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row288003312165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993538060165635"><a name="p1993538060165635"></a><a name="p1993538060165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1990544757165635"><a name="p1990544757165635"></a><a name="p1990544757165635"></a>void * </p>
<p id="p721595110165635"><a name="p721595110165635"></a><a name="p721595110165635"></a>Overrides the <strong id="b1730746920165635"><a name="b1730746920165635"></a><a name="b1730746920165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1105204423165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402019599165635"><a name="p1402019599165635"></a><a name="p1402019599165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507367754165635"><a name="p507367754165635"></a><a name="p507367754165635"></a>void </p>
<p id="p1276886446165635"><a name="p1276886446165635"></a><a name="p1276886446165635"></a>Overrides the <strong id="b101347929165635"><a name="b101347929165635"></a><a name="b101347929165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

