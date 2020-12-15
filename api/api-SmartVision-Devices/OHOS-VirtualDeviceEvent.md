# OHOS::VirtualDeviceEvent<a name="ZH-CN_TOPIC_0000001054918185"></a>

-   [Overview](#section1554866722165635)
-   [Summary](#section1594771562165635)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1554866722165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a virtual device event, which is used to receive a customized input event and call back the listening function registered. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1594771562165635"></a>

## Public Types<a name="pub-types"></a>

<a name="table1102687905165635"></a>
<table><thead align="left"><tr id="row571801981165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1218428547165635"><a name="p1218428547165635"></a><a name="p1218428547165635"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1341382559165635"><a name="p1341382559165635"></a><a name="p1341382559165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468419948165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p339554704165635"><a name="p339554704165635"></a><a name="p339554704165635"></a><a href="Graphic.md#gaf8133740d5a3cb2f88a7f33cb11c6dbd">DeviceType</a> </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989515362165635"><a name="p989515362165635"></a><a name="p989515362165635"></a>Enumerates virtual device types. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table403907123165635"></a>
<table><thead align="left"><tr id="row751949774165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1161238775165635"><a name="p1161238775165635"></a><a name="p1161238775165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p538283831165635"><a name="p538283831165635"></a><a name="p538283831165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row296329991165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110190898165635"><a name="p110190898165635"></a><a name="p110190898165635"></a><a href="Graphic.md#ga4832bd35eeae9c4402c1cba6294fe55b">VirtualDeviceEvent</a> (uint16_t type, uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p992731706165635"><a name="p992731706165635"></a><a name="p992731706165635"></a> </p>
<p id="p1046298892165635"><a name="p1046298892165635"></a><a name="p1046298892165635"></a>A constructor used to create a <strong id="b51694348165635"><a name="b51694348165635"></a><a name="b51694348165635"></a><a href="OHOS-VirtualDeviceEvent.md">VirtualDeviceEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row1944284629165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p741336463165635"><a name="p741336463165635"></a><a name="p741336463165635"></a><a href="Graphic.md#ga72e6afde17a0376e756b463e04a86ba1">~VirtualDeviceEvent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p569101296165635"><a name="p569101296165635"></a><a name="p569101296165635"></a> </p>
<p id="p2084646451165635"><a name="p2084646451165635"></a><a name="p2084646451165635"></a>A destructor used to delete the <strong id="b1928583040165635"><a name="b1928583040165635"></a><a name="b1928583040165635"></a><a href="OHOS-VirtualDeviceEvent.md">VirtualDeviceEvent</a></strong> instance. </p>
</td>
</tr>
<tr id="row1604072101165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p104736085165635"><a name="p104736085165635"></a><a name="p104736085165635"></a><a href="Graphic.md#ga47a12f474dd7351a303e4959a05b17d1">GetType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690843876165635"><a name="p690843876165635"></a><a name="p690843876165635"></a>uint16_t </p>
<p id="p1183377043165635"><a name="p1183377043165635"></a><a name="p1183377043165635"></a>Obtains the type of the virtual device. </p>
</td>
</tr>
<tr id="row356657992165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p575289575165635"><a name="p575289575165635"></a><a name="p575289575165635"></a><a href="Graphic.md#gae0619e7f8b3c97548f763f281bdd8261">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637193983165635"><a name="p637193983165635"></a><a name="p637193983165635"></a>uint16_t </p>
<p id="p2068451152165635"><a name="p2068451152165635"></a><a name="p2068451152165635"></a>Obtains the state of the virtual event. </p>
</td>
</tr>
<tr id="row1540462149165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265068599165635"><a name="p1265068599165635"></a><a name="p1265068599165635"></a><a href="Graphic.md#ga89cd09ced5537a3479b7901ba8abc6da">Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316452254165635"><a name="p1316452254165635"></a><a name="p1316452254165635"></a> </p>
<p id="p1723041981165635"><a name="p1723041981165635"></a><a name="p1723041981165635"></a>A default constructor used to create an <strong id="b2021260869165635"><a name="b2021260869165635"></a><a name="b2021260869165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row530477043165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p30937075165635"><a name="p30937075165635"></a><a name="p30937075165635"></a><a href="Graphic.md#ga57a9f07c8203c6a60f3b25c4edb526a0">Event</a> (const <a href="OHOS-Point.md">Point</a> &amp;curPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942894874165635"><a name="p942894874165635"></a><a name="p942894874165635"></a> </p>
<p id="p1176735991165635"><a name="p1176735991165635"></a><a name="p1176735991165635"></a>A constructor used to create an <strong id="b1010302871165635"><a name="b1010302871165635"></a><a name="b1010302871165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1156358810165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788874877165635"><a name="p1788874877165635"></a><a name="p1788874877165635"></a><a href="Graphic.md#gabafa07a6393f4757f402bf9437561fa4">~Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827029414165635"><a name="p1827029414165635"></a><a name="p1827029414165635"></a>virtual </p>
<p id="p1104648134165635"><a name="p1104648134165635"></a><a name="p1104648134165635"></a>A destructor used to delete the <strong id="b1225709766165635"><a name="b1225709766165635"></a><a name="b1225709766165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row32751886165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522601891165635"><a name="p1522601891165635"></a><a name="p1522601891165635"></a><a href="Graphic.md#gaea811c661ad416d7f70912ad6fcce269">GetCurrentPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1114755803165635"><a name="p1114755803165635"></a><a name="p1114755803165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p1784253931165635"><a name="p1784253931165635"></a><a name="p1784253931165635"></a>Obtains the position where an event occurs. </p>
</td>
</tr>
<tr id="row581527123165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1562162055165635"><a name="p1562162055165635"></a><a name="p1562162055165635"></a><a href="Graphic.md#ga7d56c2a99ab2c98eec9ebc03f67b7777">GetTimeStamp</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p201655210165635"><a name="p201655210165635"></a><a name="p201655210165635"></a>const TimeType &amp; </p>
<p id="p1682503523165635"><a name="p1682503523165635"></a><a name="p1682503523165635"></a>Obtains the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row245869875165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220733193165635"><a name="p1220733193165635"></a><a name="p1220733193165635"></a><a href="Graphic.md#gabee47ba229e81c44f648cf5b3203010f">SetTimeStamp</a> (const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216075506165635"><a name="p216075506165635"></a><a name="p216075506165635"></a>void </p>
<p id="p1228622931165635"><a name="p1228622931165635"></a><a name="p1228622931165635"></a>Sets the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row271426488165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734967863165635"><a name="p1734967863165635"></a><a name="p1734967863165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p347992200165635"><a name="p347992200165635"></a><a name="p347992200165635"></a>void * </p>
<p id="p1216907796165635"><a name="p1216907796165635"></a><a name="p1216907796165635"></a>Overrides the <strong id="b1774741221165635"><a name="b1774741221165635"></a><a name="b1774741221165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row950933318165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p794858179165635"><a name="p794858179165635"></a><a name="p794858179165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p244664023165635"><a name="p244664023165635"></a><a name="p244664023165635"></a>void </p>
<p id="p426040641165635"><a name="p426040641165635"></a><a name="p426040641165635"></a>Overrides the <strong id="b1481590719165635"><a name="b1481590719165635"></a><a name="b1481590719165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

