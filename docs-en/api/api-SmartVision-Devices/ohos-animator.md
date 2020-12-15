# OHOS::Animator<a name="EN-US_TOPIC_0000001055518106"></a>

-   [Overview](#section1147755146165633)
-   [Summary](#section914359666165633)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1147755146165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents an animator. 

This class is used to set the animator attributes, such as the duration, whether an animator is repeated, start and stop of an animator.

See also
:   [Animator](ohos-animator.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section914359666165633"></a>

## Public Types<a name="pub-types"></a>

<a name="table2088028907165633"></a>
<table><thead align="left"><tr id="row123610619165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1760995729165633"><a name="p1760995729165633"></a><a name="p1760995729165633"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1956945452165633"><a name="p1956945452165633"></a><a name="p1956945452165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1668298889165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p48220440165633"><a name="p48220440165633"></a><a name="p48220440165633"></a>: uint8_t { <a href="graphic.md#gga771fc52d017036dfa9c9625b16c20650a6618a5c1c0e9e4be3acba1aaee15cb8d">STOP</a>, <a href="graphic.md#gga771fc52d017036dfa9c9625b16c20650a49f9e652157f467df5de3be9e8758f91">START</a>, <a href="graphic.md#gga771fc52d017036dfa9c9625b16c20650ae5db6c9a921eec21a2990d73400ff507">PAUSE</a>, <a href="graphic.md#gga771fc52d017036dfa9c9625b16c20650a6ef6036766e105b2cd6bf2fb94e92e1b">RUNNING</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155247926165633"><a name="p1155247926165633"></a><a name="p1155247926165633"></a>Enumerates the states of this animator. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1052373529165633"></a>
<table><thead align="left"><tr id="row1555460185165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1036922342165633"><a name="p1036922342165633"></a><a name="p1036922342165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1650201456165633"><a name="p1650201456165633"></a><a name="p1650201456165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row490116902165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1015013358165633"><a name="p1015013358165633"></a><a name="p1015013358165633"></a><a href="graphic.md#gabcc3afbe99010e70e3e6dbd780cb5974">Animator</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1319525245165633"><a name="p1319525245165633"></a><a name="p1319525245165633"></a> </p>
<p id="p1186006574165633"><a name="p1186006574165633"></a><a name="p1186006574165633"></a>A default constructor used to create an <strong id="b1604928788165633"><a name="b1604928788165633"></a><a name="b1604928788165633"></a><a href="ohos-animator.md">Animator</a></strong> instance. </p>
</td>
</tr>
<tr id="row1482411756165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643823951165633"><a name="p1643823951165633"></a><a name="p1643823951165633"></a><a href="graphic.md#ga79be500c40ba8743dd58dc633a732b53">Animator</a> (<a href="ohos-animatorcallback.md">AnimatorCallback</a> *callback, <a href="ohos-uiview.md">UIView</a> *view, uint32_t <a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>, bool repeat)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808944301165633"><a name="p808944301165633"></a><a name="p808944301165633"></a> </p>
<p id="p568409841165633"><a name="p568409841165633"></a><a name="p568409841165633"></a>A constructor used to create an <strong id="b1783774905165633"><a name="b1783774905165633"></a><a name="b1783774905165633"></a><a href="ohos-animator.md">Animator</a></strong> instance. </p>
</td>
</tr>
<tr id="row89170843165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491523157165633"><a name="p1491523157165633"></a><a name="p1491523157165633"></a><a href="graphic.md#gaee2a71f97b102654ca3b7ded4b5ce350">~Animator</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442942483165633"><a name="p442942483165633"></a><a name="p442942483165633"></a>virtual </p>
<p id="p1646843590165633"><a name="p1646843590165633"></a><a name="p1646843590165633"></a>A destructor used to delete the <strong id="b1979735616165633"><a name="b1979735616165633"></a><a name="b1979735616165633"></a><a href="ohos-animator.md">Animator</a></strong> instance. </p>
</td>
</tr>
<tr id="row1878616436165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p407017500165633"><a name="p407017500165633"></a><a name="p407017500165633"></a><a href="graphic.md#gad56477fe4b6d0158082e841e327c1bf6">Start</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926282868165633"><a name="p1926282868165633"></a><a name="p1926282868165633"></a>void </p>
<p id="p1455780025165633"><a name="p1455780025165633"></a><a name="p1455780025165633"></a>Starts this animator. </p>
</td>
</tr>
<tr id="row1439082124165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1094404593165633"><a name="p1094404593165633"></a><a name="p1094404593165633"></a><a href="graphic.md#gad670cee429a5535149db0f8b3828e951">Stop</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1722322362165633"><a name="p1722322362165633"></a><a name="p1722322362165633"></a>void </p>
<p id="p267452180165633"><a name="p267452180165633"></a><a name="p267452180165633"></a>Stops this animator. </p>
</td>
</tr>
<tr id="row818704062165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651260723165633"><a name="p1651260723165633"></a><a name="p1651260723165633"></a><a href="graphic.md#ga4dd9d23ebff1359bd1145fd2f26e1be2">Pause</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138247903165633"><a name="p138247903165633"></a><a name="p138247903165633"></a>void </p>
<p id="p1638373299165633"><a name="p1638373299165633"></a><a name="p1638373299165633"></a>Pauses this animator. </p>
</td>
</tr>
<tr id="row629794937165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p772526676165633"><a name="p772526676165633"></a><a name="p772526676165633"></a><a href="graphic.md#ga645bbd33356bd708636a94c3d95c282d">Resume</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2146082306165633"><a name="p2146082306165633"></a><a name="p2146082306165633"></a>void </p>
<p id="p1078294999165633"><a name="p1078294999165633"></a><a name="p1078294999165633"></a>Resumes this animator from where it was paused. </p>
</td>
</tr>
<tr id="row319563982165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1011728084165633"><a name="p1011728084165633"></a><a name="p1011728084165633"></a><a href="graphic.md#gafd0166df63bed582022ed93175dd3179">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699309250165633"><a name="p1699309250165633"></a><a name="p1699309250165633"></a>uint8_t </p>
<p id="p2113510324165633"><a name="p2113510324165633"></a><a name="p2113510324165633"></a>Obtains the current state of this animator. </p>
</td>
</tr>
<tr id="row1779227379165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1757453230165633"><a name="p1757453230165633"></a><a name="p1757453230165633"></a><a href="graphic.md#gab8ec3815f5e42605a51a328c1b0857dd">SetState</a> (uint8_t state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552353930165633"><a name="p1552353930165633"></a><a name="p1552353930165633"></a>void </p>
<p id="p1794499157165633"><a name="p1794499157165633"></a><a name="p1794499157165633"></a>Sets the current state for this animator. </p>
</td>
</tr>
<tr id="row1624493069165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043998494165633"><a name="p1043998494165633"></a><a name="p1043998494165633"></a><a href="graphic.md#gac05ba70bafa9887dc23ea4ba69da632d">GetTime</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1060868792165633"><a name="p1060868792165633"></a><a name="p1060868792165633"></a>uint32_t </p>
<p id="p1706841825165633"><a name="p1706841825165633"></a><a name="p1706841825165633"></a>Obtains the total duration of this animator. </p>
</td>
</tr>
<tr id="row1112984237165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682893016165633"><a name="p1682893016165633"></a><a name="p1682893016165633"></a><a href="graphic.md#ga5a2bfa5fb257b2116d08ad5ae254327c">SetTime</a> (uint32_t <a href="time.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p235715127165633"><a name="p235715127165633"></a><a name="p235715127165633"></a>void </p>
<p id="p2088120403165633"><a name="p2088120403165633"></a><a name="p2088120403165633"></a>Sets the total duration for this animator. </p>
</td>
</tr>
<tr id="row1436286790165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019363975165633"><a name="p2019363975165633"></a><a name="p2019363975165633"></a><a href="graphic.md#ga18a8b8b9ceb344e6660a5c0de5a9ce1f">GetRunTime</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507686168165633"><a name="p1507686168165633"></a><a name="p1507686168165633"></a>uint32_t </p>
<p id="p1646719716165633"><a name="p1646719716165633"></a><a name="p1646719716165633"></a>Obtains the running time of this animator. </p>
</td>
</tr>
<tr id="row520351947165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748801213165633"><a name="p1748801213165633"></a><a name="p1748801213165633"></a><a href="graphic.md#ga4d5ff5057df28da1bc99d08070312f24">SetRunTime</a> (uint32_t runTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666309580165633"><a name="p666309580165633"></a><a name="p666309580165633"></a>void </p>
<p id="p1146712693165633"><a name="p1146712693165633"></a><a name="p1146712693165633"></a>Sets the running time for this animator. </p>
</td>
</tr>
<tr id="row125460064165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1649577461165633"><a name="p1649577461165633"></a><a name="p1649577461165633"></a><a href="graphic.md#gacd3c360c8a3f6b5aeffcf10c1a1588da">IsRepeat</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883429648165633"><a name="p883429648165633"></a><a name="p883429648165633"></a>bool </p>
<p id="p1811717804165633"><a name="p1811717804165633"></a><a name="p1811717804165633"></a>Checks whether this animator is repeated. </p>
</td>
</tr>
<tr id="row19643148165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139879673165633"><a name="p1139879673165633"></a><a name="p1139879673165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010849197165633"><a name="p2010849197165633"></a><a name="p2010849197165633"></a>void * </p>
<p id="p560827470165633"><a name="p560827470165633"></a><a name="p560827470165633"></a>Overrides the <strong id="b164317420165633"><a name="b164317420165633"></a><a name="b164317420165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1143117061165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1964795897165633"><a name="p1964795897165633"></a><a name="p1964795897165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43994238165633"><a name="p43994238165633"></a><a name="p43994238165633"></a>void </p>
<p id="p835369422165633"><a name="p835369422165633"></a><a name="p835369422165633"></a>Overrides the <strong id="b918609204165633"><a name="b918609204165633"></a><a name="b918609204165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

