# OHOS::UIView::OnDragListener<a name="ZH-CN_TOPIC_0000001054598189"></a>

-   [Overview](#section1280632194165635)
-   [Summary](#section1268837786165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1280632194165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a drag event listener. You need to register this listener with the view to listen to drag events. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1268837786165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1958573911165635"></a>
<table><thead align="left"><tr id="row650867782165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p52653963165635"><a name="p52653963165635"></a><a name="p52653963165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1751994258165635"><a name="p1751994258165635"></a><a name="p1751994258165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row745697578165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p255587892165635"><a name="p255587892165635"></a><a name="p255587892165635"></a><a href="Graphic.md#ga876bada94186d79c03de6da64c26e636">OnDragStart</a> (<a href="OHOS-UIView.md">UIView</a> &amp;view, const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1327000579165635"><a name="p1327000579165635"></a><a name="p1327000579165635"></a>virtual bool </p>
<p id="p1255349123165635"><a name="p1255349123165635"></a><a name="p1255349123165635"></a>Called when a view starts to drag. </p>
</td>
</tr>
<tr id="row1303625665165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1059918794165635"><a name="p1059918794165635"></a><a name="p1059918794165635"></a><a href="Graphic.md#gac112ce602c6939a52781d13440255b0c">OnDrag</a> (<a href="OHOS-UIView.md">UIView</a> &amp;view, const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1160314512165635"><a name="p1160314512165635"></a><a name="p1160314512165635"></a>virtual bool </p>
<p id="p1053771027165635"><a name="p1053771027165635"></a><a name="p1053771027165635"></a>Called when a view is being dragged. </p>
</td>
</tr>
<tr id="row90327875165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94060356165635"><a name="p94060356165635"></a><a name="p94060356165635"></a><a href="Graphic.md#gab9e57971ae7e9925eaa3ccef245cbd72">OnDragEnd</a> (<a href="OHOS-UIView.md">UIView</a> &amp;view, const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p654898647165635"><a name="p654898647165635"></a><a name="p654898647165635"></a>virtual bool </p>
<p id="p1533252796165635"><a name="p1533252796165635"></a><a name="p1533252796165635"></a>Called when a view stops dragging. </p>
</td>
</tr>
<tr id="row703163142165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1472664320165635"><a name="p1472664320165635"></a><a name="p1472664320165635"></a><a href="Graphic.md#ga34c01de74c319674fc94d1d74bb6e77e">~OnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766090283165635"><a name="p766090283165635"></a><a name="p766090283165635"></a>virtual </p>
<p id="p1665502756165635"><a name="p1665502756165635"></a><a name="p1665502756165635"></a>A destructor used to delete the <strong id="b992054861165635"><a name="b992054861165635"></a><a name="b992054861165635"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a></strong> instance. </p>
</td>
</tr>
<tr id="row1848980908165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105916245165635"><a name="p2105916245165635"></a><a name="p2105916245165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p607238620165635"><a name="p607238620165635"></a><a name="p607238620165635"></a>void * </p>
<p id="p1733507301165635"><a name="p1733507301165635"></a><a name="p1733507301165635"></a>Overrides the <strong id="b1951439999165635"><a name="b1951439999165635"></a><a name="b1951439999165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1870032389165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p101753768165635"><a name="p101753768165635"></a><a name="p101753768165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p324921026165635"><a name="p324921026165635"></a><a name="p324921026165635"></a>void </p>
<p id="p613808767165635"><a name="p613808767165635"></a><a name="p613808767165635"></a>Overrides the <strong id="b1593576296165635"><a name="b1593576296165635"></a><a name="b1593576296165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

