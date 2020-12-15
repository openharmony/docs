# OHOS::KeyEvent<a name="EN-US_TOPIC_0000001055198160"></a>

-   [Overview](#section628384899165635)
-   [Summary](#section1291846480165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section628384899165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines a key event, which indicates that a physical button is pressed or released. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1291846480165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1035499283165635"></a>
<table><thead align="left"><tr id="row1205592068165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1289970861165635"><a name="p1289970861165635"></a><a name="p1289970861165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p404480367165635"><a name="p404480367165635"></a><a name="p404480367165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1333165911165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385082070165635"><a name="p385082070165635"></a><a name="p385082070165635"></a><a href="graphic.md#ga3a52d91ac5d8fd7779baafae6ec92f9b">KeyEvent</a> (uint16_t keyId, uint16_t state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748513168165635"><a name="p748513168165635"></a><a name="p748513168165635"></a> </p>
<p id="p1292056428165635"><a name="p1292056428165635"></a><a name="p1292056428165635"></a>A constructor used to create a <strong id="b510153467165635"><a name="b510153467165635"></a><a name="b510153467165635"></a><a href="ohos-keyevent.md">KeyEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row223551182165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1054463492165635"><a name="p1054463492165635"></a><a name="p1054463492165635"></a><a href="graphic.md#ga468e77700a90ef155a2428af9176551e">~KeyEvent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453448000165635"><a name="p453448000165635"></a><a name="p453448000165635"></a> </p>
<p id="p850405281165635"><a name="p850405281165635"></a><a name="p850405281165635"></a>A destructor used to delete the <strong id="b1163681193165635"><a name="b1163681193165635"></a><a name="b1163681193165635"></a><a href="ohos-keyevent.md">KeyEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row1940082814165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903405422165635"><a name="p903405422165635"></a><a name="p903405422165635"></a><a href="graphic.md#gae2b2b83cc3a562b3173f69c95722db99">GetKeyId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1798953297165635"><a name="p1798953297165635"></a><a name="p1798953297165635"></a>uint16_t </p>
<p id="p1318326396165635"><a name="p1318326396165635"></a><a name="p1318326396165635"></a>Obtains the key ID. </p>
</td>
</tr>
<tr id="row1961889737165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p11668494165635"><a name="p11668494165635"></a><a name="p11668494165635"></a><a href="graphic.md#gaf93661e10da4b4df75c04d8fd199a5e8">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733996564165635"><a name="p733996564165635"></a><a name="p733996564165635"></a>uint16_t </p>
<p id="p1546636084165635"><a name="p1546636084165635"></a><a name="p1546636084165635"></a>Obtains the key state. </p>
</td>
</tr>
<tr id="row1115806803165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p227734025165635"><a name="p227734025165635"></a><a name="p227734025165635"></a><a href="graphic.md#ga89cd09ced5537a3479b7901ba8abc6da">Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1290803494165635"><a name="p1290803494165635"></a><a name="p1290803494165635"></a> </p>
<p id="p150069842165635"><a name="p150069842165635"></a><a name="p150069842165635"></a>A default constructor used to create an <strong id="b588104745165635"><a name="b588104745165635"></a><a name="b588104745165635"></a><a href="ohos-event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1494662073165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061662627165635"><a name="p2061662627165635"></a><a name="p2061662627165635"></a><a href="graphic.md#ga57a9f07c8203c6a60f3b25c4edb526a0">Event</a> (const <a href="ohos-point.md">Point</a> &amp;curPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090355009165635"><a name="p2090355009165635"></a><a name="p2090355009165635"></a> </p>
<p id="p662283641165635"><a name="p662283641165635"></a><a name="p662283641165635"></a>A constructor used to create an <strong id="b747802606165635"><a name="b747802606165635"></a><a name="b747802606165635"></a><a href="ohos-event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1161042416165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856672752165635"><a name="p1856672752165635"></a><a name="p1856672752165635"></a><a href="graphic.md#gabafa07a6393f4757f402bf9437561fa4">~Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1665889694165635"><a name="p1665889694165635"></a><a name="p1665889694165635"></a>virtual </p>
<p id="p2128036889165635"><a name="p2128036889165635"></a><a name="p2128036889165635"></a>A destructor used to delete the <strong id="b1889970023165635"><a name="b1889970023165635"></a><a name="b1889970023165635"></a><a href="ohos-event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1378602015165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p231661948165635"><a name="p231661948165635"></a><a name="p231661948165635"></a><a href="graphic.md#gaea811c661ad416d7f70912ad6fcce269">GetCurrentPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912494638165635"><a name="p1912494638165635"></a><a name="p1912494638165635"></a>const <a href="ohos-point.md">Point</a> &amp; </p>
<p id="p354542736165635"><a name="p354542736165635"></a><a name="p354542736165635"></a>Obtains the position where an event occurs. </p>
</td>
</tr>
<tr id="row1197746740165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p873986124165635"><a name="p873986124165635"></a><a name="p873986124165635"></a><a href="graphic.md#ga7d56c2a99ab2c98eec9ebc03f67b7777">GetTimeStamp</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2013782873165635"><a name="p2013782873165635"></a><a name="p2013782873165635"></a>const TimeType &amp; </p>
<p id="p1247374170165635"><a name="p1247374170165635"></a><a name="p1247374170165635"></a>Obtains the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row1627016220165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1988627863165635"><a name="p1988627863165635"></a><a name="p1988627863165635"></a><a href="graphic.md#gabee47ba229e81c44f648cf5b3203010f">SetTimeStamp</a> (const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174990296165635"><a name="p1174990296165635"></a><a name="p1174990296165635"></a>void </p>
<p id="p390363915165635"><a name="p390363915165635"></a><a name="p390363915165635"></a>Sets the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row301515447165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526475257165635"><a name="p1526475257165635"></a><a name="p1526475257165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155866447165635"><a name="p155866447165635"></a><a name="p155866447165635"></a>void * </p>
<p id="p1978392730165635"><a name="p1978392730165635"></a><a name="p1978392730165635"></a>Overrides the <strong id="b836843868165635"><a name="b836843868165635"></a><a name="b836843868165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row851657575165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034536464165635"><a name="p2034536464165635"></a><a name="p2034536464165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846374235165635"><a name="p846374235165635"></a><a name="p846374235165635"></a>void </p>
<p id="p771744864165635"><a name="p771744864165635"></a><a name="p771744864165635"></a>Overrides the <strong id="b1836398034165635"><a name="b1836398034165635"></a><a name="b1836398034165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

