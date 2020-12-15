# OHOS::CancelEvent<a name="ZH-CN_TOPIC_0000001054799629"></a>

-   [Overview](#section1875250411165635)
-   [Summary](#section917318045165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1875250411165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a cancel event, which usually occurs when the target view changes due to user sliding. For example, this event is triggered if you, after pressing a button, does not release the button but slides. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section917318045165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table599199299165635"></a>
<table><thead align="left"><tr id="row435757016165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p802032932165635"><a name="p802032932165635"></a><a name="p802032932165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p896218138165635"><a name="p896218138165635"></a><a name="p896218138165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row218110624165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377890364165635"><a name="p377890364165635"></a><a name="p377890364165635"></a><a href="Graphic.md#gaf3b75ee84a33ffcbc640328b2747b0a1">CancelEvent</a> (const <a href="OHOS-Point.md">Point</a> &amp;pos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700485053165635"><a name="p1700485053165635"></a><a name="p1700485053165635"></a> </p>
<p id="p1186387188165635"><a name="p1186387188165635"></a><a name="p1186387188165635"></a>A constructor used to create a <strong id="b745628986165635"><a name="b745628986165635"></a><a name="b745628986165635"></a><a href="OHOS-CancelEvent.md">CancelEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row609655290165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606504668165635"><a name="p1606504668165635"></a><a name="p1606504668165635"></a><a href="Graphic.md#ga5f8a22ac27c5ffc2b8801b4687a38394">~CancelEvent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985426588165635"><a name="p985426588165635"></a><a name="p985426588165635"></a>virtual </p>
<p id="p2137466620165635"><a name="p2137466620165635"></a><a name="p2137466620165635"></a>A destructor used to delete the <strong id="b1777994177165635"><a name="b1777994177165635"></a><a name="b1777994177165635"></a><a href="OHOS-CancelEvent.md">CancelEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row1118317657165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p808189664165635"><a name="p808189664165635"></a><a name="p808189664165635"></a><a href="Graphic.md#ga89cd09ced5537a3479b7901ba8abc6da">Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p593752397165635"><a name="p593752397165635"></a><a name="p593752397165635"></a> </p>
<p id="p1888735420165635"><a name="p1888735420165635"></a><a name="p1888735420165635"></a>A default constructor used to create an <strong id="b879995960165635"><a name="b879995960165635"></a><a name="b879995960165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1887096064165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1594886235165635"><a name="p1594886235165635"></a><a name="p1594886235165635"></a><a href="Graphic.md#ga57a9f07c8203c6a60f3b25c4edb526a0">Event</a> (const <a href="OHOS-Point.md">Point</a> &amp;curPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1855923252165635"><a name="p1855923252165635"></a><a name="p1855923252165635"></a> </p>
<p id="p2631387165635"><a name="p2631387165635"></a><a name="p2631387165635"></a>A constructor used to create an <strong id="b961555514165635"><a name="b961555514165635"></a><a name="b961555514165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1207771784165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034584067165635"><a name="p2034584067165635"></a><a name="p2034584067165635"></a><a href="Graphic.md#gabafa07a6393f4757f402bf9437561fa4">~Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p742314634165635"><a name="p742314634165635"></a><a name="p742314634165635"></a>virtual </p>
<p id="p1192582037165635"><a name="p1192582037165635"></a><a name="p1192582037165635"></a>A destructor used to delete the <strong id="b1187793443165635"><a name="b1187793443165635"></a><a name="b1187793443165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1634186651165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755710774165635"><a name="p755710774165635"></a><a name="p755710774165635"></a><a href="Graphic.md#gaea811c661ad416d7f70912ad6fcce269">GetCurrentPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677810156165635"><a name="p1677810156165635"></a><a name="p1677810156165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p1363808978165635"><a name="p1363808978165635"></a><a name="p1363808978165635"></a>Obtains the position where an event occurs. </p>
</td>
</tr>
<tr id="row818572308165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1741165969165635"><a name="p1741165969165635"></a><a name="p1741165969165635"></a><a href="Graphic.md#ga7d56c2a99ab2c98eec9ebc03f67b7777">GetTimeStamp</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1739608699165635"><a name="p1739608699165635"></a><a name="p1739608699165635"></a>const TimeType &amp; </p>
<p id="p454783089165635"><a name="p454783089165635"></a><a name="p454783089165635"></a>Obtains the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row1335795732165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532263895165635"><a name="p532263895165635"></a><a name="p532263895165635"></a><a href="Graphic.md#gabee47ba229e81c44f648cf5b3203010f">SetTimeStamp</a> (const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345609150165635"><a name="p345609150165635"></a><a name="p345609150165635"></a>void </p>
<p id="p176218025165635"><a name="p176218025165635"></a><a name="p176218025165635"></a>Sets the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row374438602165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060273943165635"><a name="p1060273943165635"></a><a name="p1060273943165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632694186165635"><a name="p1632694186165635"></a><a name="p1632694186165635"></a>void * </p>
<p id="p2091465886165635"><a name="p2091465886165635"></a><a name="p2091465886165635"></a>Overrides the <strong id="b904200280165635"><a name="b904200280165635"></a><a name="b904200280165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1663932377165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726748477165635"><a name="p1726748477165635"></a><a name="p1726748477165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732414166165635"><a name="p1732414166165635"></a><a name="p1732414166165635"></a>void </p>
<p id="p227074387165635"><a name="p227074387165635"></a><a name="p227074387165635"></a>Overrides the <strong id="b1153159344165635"><a name="b1153159344165635"></a><a name="b1153159344165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

