# OHOS::Event<a name="ZH-CN_TOPIC_0000001054879562"></a>

-   [Overview](#section421010522165635)
-   [Summary](#section665395145165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section421010522165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines the base class of a user input event and provides functions to record information such as the event position and timestamp. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section665395145165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1693879392165635"></a>
<table><thead align="left"><tr id="row1221342037165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p903419464165635"><a name="p903419464165635"></a><a name="p903419464165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1255920345165635"><a name="p1255920345165635"></a><a name="p1255920345165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1613429482165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p751976488165635"><a name="p751976488165635"></a><a name="p751976488165635"></a><a href="Graphic.md#ga89cd09ced5537a3479b7901ba8abc6da">Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1731058343165635"><a name="p1731058343165635"></a><a name="p1731058343165635"></a> </p>
<p id="p327695071165635"><a name="p327695071165635"></a><a name="p327695071165635"></a>A default constructor used to create an <strong id="b1989811152165635"><a name="b1989811152165635"></a><a name="b1989811152165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1373722336165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1740205310165635"><a name="p1740205310165635"></a><a name="p1740205310165635"></a><a href="Graphic.md#ga57a9f07c8203c6a60f3b25c4edb526a0">Event</a> (const <a href="OHOS-Point.md">Point</a> &amp;curPos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1139836396165635"><a name="p1139836396165635"></a><a name="p1139836396165635"></a> </p>
<p id="p1990906249165635"><a name="p1990906249165635"></a><a name="p1990906249165635"></a>A constructor used to create an <strong id="b1145499843165635"><a name="b1145499843165635"></a><a name="b1145499843165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row212154966165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p434386928165635"><a name="p434386928165635"></a><a name="p434386928165635"></a><a href="Graphic.md#gabafa07a6393f4757f402bf9437561fa4">~Event</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684708794165635"><a name="p684708794165635"></a><a name="p684708794165635"></a>virtual </p>
<p id="p1935088240165635"><a name="p1935088240165635"></a><a name="p1935088240165635"></a>A destructor used to delete the <strong id="b816700540165635"><a name="b816700540165635"></a><a name="b816700540165635"></a><a href="OHOS-Event.md">Event</a></strong> instance. </p>
</td>
</tr>
<tr id="row1763511189165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514203832165635"><a name="p1514203832165635"></a><a name="p1514203832165635"></a><a href="Graphic.md#gaea811c661ad416d7f70912ad6fcce269">GetCurrentPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546847481165635"><a name="p546847481165635"></a><a name="p546847481165635"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p761623137165635"><a name="p761623137165635"></a><a name="p761623137165635"></a>Obtains the position where an event occurs. </p>
</td>
</tr>
<tr id="row1753258428165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004433388165635"><a name="p1004433388165635"></a><a name="p1004433388165635"></a><a href="Graphic.md#ga7d56c2a99ab2c98eec9ebc03f67b7777">GetTimeStamp</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2145523933165635"><a name="p2145523933165635"></a><a name="p2145523933165635"></a>const TimeType &amp; </p>
<p id="p2021159048165635"><a name="p2021159048165635"></a><a name="p2021159048165635"></a>Obtains the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row443051527165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732171411165635"><a name="p732171411165635"></a><a name="p732171411165635"></a><a href="Graphic.md#gabee47ba229e81c44f648cf5b3203010f">SetTimeStamp</a> (const TimeType &amp;timeStamp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435278797165635"><a name="p435278797165635"></a><a name="p435278797165635"></a>void </p>
<p id="p688342592165635"><a name="p688342592165635"></a><a name="p688342592165635"></a>Sets the timestamp when an event occurs. </p>
</td>
</tr>
<tr id="row1767228081165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399485616165635"><a name="p399485616165635"></a><a name="p399485616165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22548529165635"><a name="p22548529165635"></a><a name="p22548529165635"></a>void * </p>
<p id="p518415239165635"><a name="p518415239165635"></a><a name="p518415239165635"></a>Overrides the <strong id="b931161996165635"><a name="b931161996165635"></a><a name="b931161996165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1264563583165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752034156165635"><a name="p752034156165635"></a><a name="p752034156165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1038102020165635"><a name="p1038102020165635"></a><a name="p1038102020165635"></a>void </p>
<p id="p504723823165635"><a name="p504723823165635"></a><a name="p504723823165635"></a>Overrides the <strong id="b1841621994165635"><a name="b1841621994165635"></a><a name="b1841621994165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

