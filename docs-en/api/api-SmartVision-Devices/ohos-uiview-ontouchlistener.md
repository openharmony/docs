# OHOS::UIView::OnTouchListener<a name="EN-US_TOPIC_0000001054918183"></a>

-   [Overview](#section189944701165635)
-   [Summary](#section1859733688165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section189944701165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines a touch event listener. You need to register this listener with the view to listen to touch events. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1859733688165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table26566345165635"></a>
<table><thead align="left"><tr id="row137748023165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1948393554165635"><a name="p1948393554165635"></a><a name="p1948393554165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1214249976165635"><a name="p1214249976165635"></a><a name="p1214249976165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row518104559165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461872689165635"><a name="p1461872689165635"></a><a name="p1461872689165635"></a><a href="graphic.md#ga2cfaed7013dc76bcbe9a5ea5d51caac3">OnPress</a> (<a href="ohos-uiview.md">UIView</a> &amp;view, const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1375592958165635"><a name="p1375592958165635"></a><a name="p1375592958165635"></a>virtual bool </p>
<p id="p1671917966165635"><a name="p1671917966165635"></a><a name="p1671917966165635"></a>Called when a view is pressed. </p>
</td>
</tr>
<tr id="row808338076165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p777296912165635"><a name="p777296912165635"></a><a name="p777296912165635"></a><a href="graphic.md#ga16fa19e254ae19fe181dba0ac9dd5d1f">OnRelease</a> (<a href="ohos-uiview.md">UIView</a> &amp;view, const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p838639962165635"><a name="p838639962165635"></a><a name="p838639962165635"></a>virtual bool </p>
<p id="p269860580165635"><a name="p269860580165635"></a><a name="p269860580165635"></a>Called when a view is released. </p>
</td>
</tr>
<tr id="row2007463970165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1791901112165635"><a name="p1791901112165635"></a><a name="p1791901112165635"></a><a href="graphic.md#ga7ce030676f1222599dd6367cd4b9cf7e">OnCancel</a> (<a href="ohos-uiview.md">UIView</a> &amp;view, const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p370799266165635"><a name="p370799266165635"></a><a name="p370799266165635"></a>virtual bool </p>
<p id="p187176516165635"><a name="p187176516165635"></a><a name="p187176516165635"></a>Called when a click event on a view is canceled. </p>
</td>
</tr>
<tr id="row264726049165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175243739165635"><a name="p175243739165635"></a><a name="p175243739165635"></a><a href="graphic.md#gacf19bb5f0c979bb6889d30a20b2737e1">~OnTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1791906852165635"><a name="p1791906852165635"></a><a name="p1791906852165635"></a>virtual </p>
<p id="p682970715165635"><a name="p682970715165635"></a><a name="p682970715165635"></a>A destructor used to delete the <strong id="b697999237165635"><a name="b697999237165635"></a><a name="b697999237165635"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a></strong> instance. </p>
</td>
</tr>
<tr id="row1391192566165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063133012165635"><a name="p2063133012165635"></a><a name="p2063133012165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86275503165635"><a name="p86275503165635"></a><a name="p86275503165635"></a>void * </p>
<p id="p782873943165635"><a name="p782873943165635"></a><a name="p782873943165635"></a>Overrides the <strong id="b254385852165635"><a name="b254385852165635"></a><a name="b254385852165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row647093719165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50516505165635"><a name="p50516505165635"></a><a name="p50516505165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812620075165635"><a name="p812620075165635"></a><a name="p812620075165635"></a>void </p>
<p id="p314157598165635"><a name="p314157598165635"></a><a name="p314157598165635"></a>Overrides the <strong id="b1486715504165635"><a name="b1486715504165635"></a><a name="b1486715504165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

