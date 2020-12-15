# OHOS::UIScrollView::OnScrollListener<a name="EN-US_TOPIC_0000001055358134"></a>

-   [Overview](#section756313590165634)
-   [Summary](#section1844655871165634)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section756313590165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a listener that contains a callback to be invoked upon scroll state changes. The state can either be  **SCROLL\_STATE\_STOP**  or  **SCROLL\_STATE\_MOVE**. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1844655871165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table359729986165634"></a>
<table><thead align="left"><tr id="row1503636170165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p362195062165634"><a name="p362195062165634"></a><a name="p362195062165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2128251767165634"><a name="p2128251767165634"></a><a name="p2128251767165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row334555218165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496924616165634"><a name="p496924616165634"></a><a name="p496924616165634"></a><a href="graphic.md#gad065bfe4e322d036b5bd9e30667754a6">OnScrollListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p890298262165634"><a name="p890298262165634"></a><a name="p890298262165634"></a> </p>
<p id="p249090010165634"><a name="p249090010165634"></a><a name="p249090010165634"></a>A constructor used to create an <strong id="b156537258165634"><a name="b156537258165634"></a><a name="b156537258165634"></a><a href="ohos-uiscrollview-onscrolllistener.md">OnScrollListener</a></strong> instance with the default scroll state <strong id="b1306428270165634"><a name="b1306428270165634"></a><a name="b1306428270165634"></a>SCROLL_STATE_STOP</strong>. </p>
</td>
</tr>
<tr id="row1143957032165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838638877165634"><a name="p1838638877165634"></a><a name="p1838638877165634"></a><a href="graphic.md#ga14fe076dffea62fdd281cd13e846de2d">~OnScrollListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789124536165634"><a name="p1789124536165634"></a><a name="p1789124536165634"></a>virtual </p>
<p id="p656763674165634"><a name="p656763674165634"></a><a name="p656763674165634"></a>A destructor used to delete the <strong id="b94823436165634"><a name="b94823436165634"></a><a name="b94823436165634"></a><a href="ohos-uiscrollview-onscrolllistener.md">OnScrollListener</a></strong> instance. </p>
</td>
</tr>
<tr id="row1189648919165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1145216483165634"><a name="p1145216483165634"></a><a name="p1145216483165634"></a><a href="graphic.md#ga8000c484a999483edc66e8dd1b7ceaf6">OnScrollStart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696053857165634"><a name="p1696053857165634"></a><a name="p1696053857165634"></a>virtual void </p>
<p id="p1690039585165634"><a name="p1690039585165634"></a><a name="p1690039585165634"></a>Called when a scroll starts. </p>
</td>
</tr>
<tr id="row1947245644165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1015252586165634"><a name="p1015252586165634"></a><a name="p1015252586165634"></a><a href="graphic.md#ga958c02ddc348eadaaf08f917f55aba63">OnScrollEnd</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742849166165634"><a name="p1742849166165634"></a><a name="p1742849166165634"></a>virtual void </p>
<p id="p321898865165634"><a name="p321898865165634"></a><a name="p321898865165634"></a>Called when a scroll ends. </p>
</td>
</tr>
<tr id="row1493383224165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1985513627165634"><a name="p1985513627165634"></a><a name="p1985513627165634"></a><a href="graphic.md#ga15a8abaeb958bfa972b541b59fabd8a7">GetScrollState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228741903165634"><a name="p1228741903165634"></a><a name="p1228741903165634"></a>uint8_t </p>
<p id="p1399136541165634"><a name="p1399136541165634"></a><a name="p1399136541165634"></a>Obtains the scroll state of this view. </p>
</td>
</tr>
<tr id="row1752644221165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p287205590165634"><a name="p287205590165634"></a><a name="p287205590165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p477756897165634"><a name="p477756897165634"></a><a name="p477756897165634"></a>void * </p>
<p id="p50965953165634"><a name="p50965953165634"></a><a name="p50965953165634"></a>Overrides the <strong id="b1295923373165634"><a name="b1295923373165634"></a><a name="b1295923373165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1454800731165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p703743774165634"><a name="p703743774165634"></a><a name="p703743774165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p119706897165634"><a name="p119706897165634"></a><a name="p119706897165634"></a>void </p>
<p id="p1433933690165634"><a name="p1433933690165634"></a><a name="p1433933690165634"></a>Overrides the <strong id="b1505881620165634"><a name="b1505881620165634"></a><a name="b1505881620165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

