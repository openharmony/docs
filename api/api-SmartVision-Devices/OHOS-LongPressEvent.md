# OHOS::LongPressEvent<a name="ZH-CN_TOPIC_0000001055358138"></a>

-   [Overview](#section2143778696165635)
-   [Summary](#section868741400165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section2143778696165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a long-press event, which indicates that the finger is not raised or moved within 1 second after a view is pressed. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section868741400165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1928781398165635"></a>
<table><thead align="left"><tr id="row304788250165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1103691292165635"><a name="p1103691292165635"></a><a name="p1103691292165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2078456882165635"><a name="p2078456882165635"></a><a name="p2078456882165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row338629641165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1672328547165635"><a name="p1672328547165635"></a><a name="p1672328547165635"></a><a href="Graphic.md#ga0ccf400cdc4f55e28ef4680a4a3c5632">LongPressEvent</a> (const <a href="OHOS-Point.md">Point</a> &amp;pos, const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p887590128165635"><a name="p887590128165635"></a><a name="p887590128165635"></a> </p>
<p id="p1671290379165635"><a name="p1671290379165635"></a><a name="p1671290379165635"></a>A constructor used to create a <strong id="b1359422165635"><a name="b1359422165635"></a><a name="b1359422165635"></a><a href="OHOS-LongPressEvent.md">LongPressEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row481726935165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p375232082165635"><a name="p375232082165635"></a><a name="p375232082165635"></a><a href="Graphic.md#gab7cd91a47633f432b39da4f6056f72fc">~LongPressEvent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088390991165635"><a name="p2088390991165635"></a><a name="p2088390991165635"></a>virtual </p>
<p id="p93267240165635"><a name="p93267240165635"></a><a name="p93267240165635"></a>A destructor used to delete the <strong id="b1318393083165635"><a name="b1318393083165635"></a><a name="b1318393083165635"></a><a href="OHOS-LongPressEvent.md">LongPressEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row1850988460165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1156829756165635"><a name="p1156829756165635"></a><a name="p1156829756165635"></a><a href="Graphic.md#ga89cd09ced5537a3479b7901ba8abc6da">Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1418195617165635"><a name="p1418195617165635"></a><a name="p1418195617165635"></a> </p>
<p id="p772013756165635"><a name="p772013756165635"></a><a name="p772013756165635"></a>A default constructor used to create an <strong id="b1606036181165635"><a name="b1606036181165635"></a><a name="b1606036181165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1596164766165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374027156165635"><a name="p1374027156165635"></a><a name="p1374027156165635"></a><a href="Graphic.md#ga57a9f07c8203c6a60f3b25c4edb526a0">Event</a> (const <a href="OHOS-Point.md">Point</a> &amp;curPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141970549165635"><a name="p1141970549165635"></a><a name="p1141970549165635"></a> </p>
<p id="p301934514165635"><a name="p301934514165635"></a><a name="p301934514165635"></a>A constructor used to create an <strong id="b2138138521165635"><a name="b2138138521165635"></a><a name="b2138138521165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1919856229165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1240569033165635"><a name="p1240569033165635"></a><a name="p1240569033165635"></a><a href="Graphic.md#gabafa07a6393f4757f402bf9437561fa4">~Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p449810101165635"><a name="p449810101165635"></a><a name="p449810101165635"></a>virtual </p>
<p id="p811101245165635"><a name="p811101245165635"></a><a name="p811101245165635"></a>A destructor used to delete the <strong id="b2056865494165635"><a name="b2056865494165635"></a><a name="b2056865494165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1861179941165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223758971165635"><a name="p1223758971165635"></a><a name="p1223758971165635"></a><a href="Graphic.md#gaea811c661ad416d7f70912ad6fcce269">GetCurrentPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369533708165635"><a name="p1369533708165635"></a><a name="p1369533708165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p626145967165635"><a name="p626145967165635"></a><a name="p626145967165635"></a>Obtains the position where an event occurs. </p>
</td>
</tr>
<tr id="row337821813165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1544730251165635"><a name="p1544730251165635"></a><a name="p1544730251165635"></a><a href="Graphic.md#ga7d56c2a99ab2c98eec9ebc03f67b7777">GetTimeStamp</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702514880165635"><a name="p702514880165635"></a><a name="p702514880165635"></a>const TimeType &amp; </p>
<p id="p1597804073165635"><a name="p1597804073165635"></a><a name="p1597804073165635"></a>Obtains the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row1722842706165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355443499165635"><a name="p1355443499165635"></a><a name="p1355443499165635"></a><a href="Graphic.md#gabee47ba229e81c44f648cf5b3203010f">SetTimeStamp</a> (const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1003001075165635"><a name="p1003001075165635"></a><a name="p1003001075165635"></a>void </p>
<p id="p450719400165635"><a name="p450719400165635"></a><a name="p450719400165635"></a>Sets the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row582776761165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387746195165635"><a name="p1387746195165635"></a><a name="p1387746195165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813242114165635"><a name="p813242114165635"></a><a name="p813242114165635"></a>void * </p>
<p id="p1712718840165635"><a name="p1712718840165635"></a><a name="p1712718840165635"></a>Overrides the <strong id="b1476745611165635"><a name="b1476745611165635"></a><a name="b1476745611165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row282172534165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930055672165635"><a name="p930055672165635"></a><a name="p930055672165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346137721165635"><a name="p346137721165635"></a><a name="p346137721165635"></a>void </p>
<p id="p1302304863165635"><a name="p1302304863165635"></a><a name="p1302304863165635"></a>Overrides the <strong id="b1261705152165635"><a name="b1261705152165635"></a><a name="b1261705152165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

