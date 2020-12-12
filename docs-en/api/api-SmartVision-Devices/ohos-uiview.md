# OHOS::UIView<a name="EN-US_TOPIC_0000001054718155"></a>

-   [Overview](#section1312994240165635)
-   [Summary](#section1344888661165635)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1312994240165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the base class of a view, providing basic view attributes and operations. All views are derived from this class. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1344888661165635"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1532101016165635"></a>
<table><thead align="left"><tr id="row295756950165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p296574710165635"><a name="p296574710165635"></a><a name="p296574710165635"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p285310180165635"><a name="p285310180165635"></a><a name="p285310180165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1790711255165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p475721926165635"><a name="p475721926165635"></a><a name="p475721926165635"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1645762488165635"><a name="p1645762488165635"></a><a name="p1645762488165635"></a>Defines a click event listener. You need to register this listener with the view to listen to click events. </p>
</td>
</tr>
<tr id="row769830493165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1582259134165635"><a name="p1582259134165635"></a><a name="p1582259134165635"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p120703794165635"><a name="p120703794165635"></a><a name="p120703794165635"></a>Defines a drag event listener. You need to register this listener with the view to listen to drag events. </p>
</td>
</tr>
<tr id="row2044791212165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1823064649165635"><a name="p1823064649165635"></a><a name="p1823064649165635"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1721408450165635"><a name="p1721408450165635"></a><a name="p1721408450165635"></a>Defines a long-press event listener. You need to register this listener with the view to listen to long-press events. </p>
</td>
</tr>
<tr id="row2044842578165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p316222345165635"><a name="p316222345165635"></a><a name="p316222345165635"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1954149626165635"><a name="p1954149626165635"></a><a name="p1954149626165635"></a>Defines a touch event listener. You need to register this listener with the view to listen to touch events. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1388050778165635"></a>
<table><thead align="left"><tr id="row800724006165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p107841495165635"><a name="p107841495165635"></a><a name="p107841495165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1515677988165635"><a name="p1515677988165635"></a><a name="p1515677988165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1855344792165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1337147250165635"><a name="p1337147250165635"></a><a name="p1337147250165635"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1150735933165635"><a name="p1150735933165635"></a><a name="p1150735933165635"></a> </p>
<p id="p2144815609165635"><a name="p2144815609165635"></a><a name="p2144815609165635"></a>A default constructor used to create an <strong id="b1057474748165635"><a name="b1057474748165635"></a><a name="b1057474748165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1121581059165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1866427485165635"><a name="p1866427485165635"></a><a name="p1866427485165635"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133791233165635"><a name="p1133791233165635"></a><a name="p1133791233165635"></a> </p>
<p id="p1696600735165635"><a name="p1696600735165635"></a><a name="p1696600735165635"></a>A constructor used to create an <strong id="b108058389165635"><a name="b108058389165635"></a><a name="b108058389165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1269620808165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604116880165635"><a name="p604116880165635"></a><a name="p604116880165635"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717754539165635"><a name="p1717754539165635"></a><a name="p1717754539165635"></a>virtual </p>
<p id="p1609347766165635"><a name="p1609347766165635"></a><a name="p1609347766165635"></a>A destructor used to delete the <strong id="b1802681735165635"><a name="b1802681735165635"></a><a name="b1802681735165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1079479914165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641765115165635"><a name="p1641765115165635"></a><a name="p1641765115165635"></a><a href="graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1116636941165635"><a name="p1116636941165635"></a><a name="p1116636941165635"></a>virtual bool </p>
<p id="p2114094915165635"><a name="p2114094915165635"></a><a name="p2114094915165635"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row347001838165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1326333759165635"><a name="p1326333759165635"></a><a name="p1326333759165635"></a><a href="graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203350656165635"><a name="p203350656165635"></a><a name="p203350656165635"></a>virtual void </p>
<p id="p761784964165635"><a name="p761784964165635"></a><a name="p761784964165635"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row225071300165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299526362165635"><a name="p299526362165635"></a><a name="p299526362165635"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p242806893165635"><a name="p242806893165635"></a><a name="p242806893165635"></a>virtual void </p>
<p id="p928825940165635"><a name="p928825940165635"></a><a name="p928825940165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1442314880165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200578593165635"><a name="p200578593165635"></a><a name="p200578593165635"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978889773165635"><a name="p1978889773165635"></a><a name="p1978889773165635"></a>virtual void </p>
<p id="p1114771296165635"><a name="p1114771296165635"></a><a name="p1114771296165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1253769109165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p828708212165635"><a name="p828708212165635"></a><a name="p828708212165635"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249414258165635"><a name="p1249414258165635"></a><a name="p1249414258165635"></a>void </p>
<p id="p1751454189165635"><a name="p1751454189165635"></a><a name="p1751454189165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1587660094165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712844746165635"><a name="p1712844746165635"></a><a name="p1712844746165635"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p126705804165635"><a name="p126705804165635"></a><a name="p126705804165635"></a>void </p>
<p id="p895858618165635"><a name="p895858618165635"></a><a name="p895858618165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1791464603165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p707494448165635"><a name="p707494448165635"></a><a name="p707494448165635"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p539520434165635"><a name="p539520434165635"></a><a name="p539520434165635"></a>virtual bool </p>
<p id="p821431009165635"><a name="p821431009165635"></a><a name="p821431009165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row2025598401165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229031437165635"><a name="p229031437165635"></a><a name="p229031437165635"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1519378380165635"><a name="p1519378380165635"></a><a name="p1519378380165635"></a>virtual bool </p>
<p id="p1328190103165635"><a name="p1328190103165635"></a><a name="p1328190103165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1681963118165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376289466165635"><a name="p376289466165635"></a><a name="p376289466165635"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133110821165635"><a name="p2133110821165635"></a><a name="p2133110821165635"></a>virtual bool </p>
<p id="p1422014778165635"><a name="p1422014778165635"></a><a name="p1422014778165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row2057395645165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1928307061165635"><a name="p1928307061165635"></a><a name="p1928307061165635"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1897771729165635"><a name="p1897771729165635"></a><a name="p1897771729165635"></a>virtual bool </p>
<p id="p1511039776165635"><a name="p1511039776165635"></a><a name="p1511039776165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1413069686165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1585156541165635"><a name="p1585156541165635"></a><a name="p1585156541165635"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405456461165635"><a name="p1405456461165635"></a><a name="p1405456461165635"></a>virtual void </p>
<p id="p653495427165635"><a name="p653495427165635"></a><a name="p653495427165635"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row900323913165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41561581165635"><a name="p41561581165635"></a><a name="p41561581165635"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758266036165635"><a name="p1758266036165635"></a><a name="p1758266036165635"></a>virtual void </p>
<p id="p1057188877165635"><a name="p1057188877165635"></a><a name="p1057188877165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row2012075648165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43315416165635"><a name="p43315416165635"></a><a name="p43315416165635"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258888523165635"><a name="p258888523165635"></a><a name="p258888523165635"></a>virtual void </p>
<p id="p1246852670165635"><a name="p1246852670165635"></a><a name="p1246852670165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1306647458165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655200586165635"><a name="p1655200586165635"></a><a name="p1655200586165635"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1874512537165635"><a name="p1874512537165635"></a><a name="p1874512537165635"></a>virtual void </p>
<p id="p1694592110165635"><a name="p1694592110165635"></a><a name="p1694592110165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1140655509165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813067145165635"><a name="p1813067145165635"></a><a name="p1813067145165635"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1022518736165635"><a name="p1022518736165635"></a><a name="p1022518736165635"></a>void </p>
<p id="p642185378165635"><a name="p642185378165635"></a><a name="p642185378165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1868981199165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616692140165635"><a name="p616692140165635"></a><a name="p616692140165635"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p364170932165635"><a name="p364170932165635"></a><a name="p364170932165635"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1124692125165635"><a name="p1124692125165635"></a><a name="p1124692125165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1708898482165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p269931303165635"><a name="p269931303165635"></a><a name="p269931303165635"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999315261165635"><a name="p1999315261165635"></a><a name="p1999315261165635"></a>void </p>
<p id="p1335219861165635"><a name="p1335219861165635"></a><a name="p1335219861165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1253937766165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1024928856165635"><a name="p1024928856165635"></a><a name="p1024928856165635"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324135305165635"><a name="p1324135305165635"></a><a name="p1324135305165635"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p650704328165635"><a name="p650704328165635"></a><a name="p650704328165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1371673492165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1745714393165635"><a name="p1745714393165635"></a><a name="p1745714393165635"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45065738165635"><a name="p45065738165635"></a><a name="p45065738165635"></a>void </p>
<p id="p1174634400165635"><a name="p1174634400165635"></a><a name="p1174634400165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row855351484165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343365425165635"><a name="p343365425165635"></a><a name="p343365425165635"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786753702165635"><a name="p1786753702165635"></a><a name="p1786753702165635"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p425160974165635"><a name="p425160974165635"></a><a name="p425160974165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1710383607165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392573868165635"><a name="p392573868165635"></a><a name="p392573868165635"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848723965165635"><a name="p1848723965165635"></a><a name="p1848723965165635"></a>void </p>
<p id="p2041728851165635"><a name="p2041728851165635"></a><a name="p2041728851165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row845344348165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032040380165635"><a name="p2032040380165635"></a><a name="p2032040380165635"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p772107362165635"><a name="p772107362165635"></a><a name="p772107362165635"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p1376007952165635"><a name="p1376007952165635"></a><a name="p1376007952165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1340078460165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252747819165635"><a name="p1252747819165635"></a><a name="p1252747819165635"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018325726165635"><a name="p1018325726165635"></a><a name="p1018325726165635"></a>virtual void </p>
<p id="p53040369165635"><a name="p53040369165635"></a><a name="p53040369165635"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row977627676165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1250436684165635"><a name="p1250436684165635"></a><a name="p1250436684165635"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2080881320165635"><a name="p2080881320165635"></a><a name="p2080881320165635"></a>void </p>
<p id="p829810576165635"><a name="p829810576165635"></a><a name="p829810576165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row905226530165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p163204776165635"><a name="p163204776165635"></a><a name="p163204776165635"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1659701330165635"><a name="p1659701330165635"></a><a name="p1659701330165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p2030778830165635"><a name="p2030778830165635"></a><a name="p2030778830165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1665530792165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1074680483165635"><a name="p1074680483165635"></a><a name="p1074680483165635"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1033078008165635"><a name="p1033078008165635"></a><a name="p1033078008165635"></a>void </p>
<p id="p1719184178165635"><a name="p1719184178165635"></a><a name="p1719184178165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row466175897165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604948704165635"><a name="p604948704165635"></a><a name="p604948704165635"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p341154152165635"><a name="p341154152165635"></a><a name="p341154152165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1564504754165635"><a name="p1564504754165635"></a><a name="p1564504754165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1588166846165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423824783165635"><a name="p1423824783165635"></a><a name="p1423824783165635"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667270681165635"><a name="p1667270681165635"></a><a name="p1667270681165635"></a>virtual void </p>
<p id="p1659129496165635"><a name="p1659129496165635"></a><a name="p1659129496165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row478565795165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p892620064165635"><a name="p892620064165635"></a><a name="p892620064165635"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969840697165635"><a name="p1969840697165635"></a><a name="p1969840697165635"></a>bool </p>
<p id="p1515718607165635"><a name="p1515718607165635"></a><a name="p1515718607165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1438999569165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2123392757165635"><a name="p2123392757165635"></a><a name="p2123392757165635"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1352604715165635"><a name="p1352604715165635"></a><a name="p1352604715165635"></a>void </p>
<p id="p2109357294165635"><a name="p2109357294165635"></a><a name="p2109357294165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row745413877165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p266900946165635"><a name="p266900946165635"></a><a name="p266900946165635"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1448951620165635"><a name="p1448951620165635"></a><a name="p1448951620165635"></a>bool </p>
<p id="p166619792165635"><a name="p166619792165635"></a><a name="p166619792165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1507356564165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1055415556165635"><a name="p1055415556165635"></a><a name="p1055415556165635"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670591877165635"><a name="p1670591877165635"></a><a name="p1670591877165635"></a>void </p>
<p id="p2107342638165635"><a name="p2107342638165635"></a><a name="p2107342638165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row806323097165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358063154165635"><a name="p1358063154165635"></a><a name="p1358063154165635"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694939241165635"><a name="p1694939241165635"></a><a name="p1694939241165635"></a>bool </p>
<p id="p1455659291165635"><a name="p1455659291165635"></a><a name="p1455659291165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row574099383165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2040113257165635"><a name="p2040113257165635"></a><a name="p2040113257165635"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1147781761165635"><a name="p1147781761165635"></a><a name="p1147781761165635"></a>void </p>
<p id="p1184248539165635"><a name="p1184248539165635"></a><a name="p1184248539165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1379915570165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664491560165635"><a name="p664491560165635"></a><a name="p664491560165635"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2103672012165635"><a name="p2103672012165635"></a><a name="p2103672012165635"></a>bool </p>
<p id="p37043929165635"><a name="p37043929165635"></a><a name="p37043929165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row5566723165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178364399165635"><a name="p178364399165635"></a><a name="p178364399165635"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p324239372165635"><a name="p324239372165635"></a><a name="p324239372165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p687117271165635"><a name="p687117271165635"></a><a name="p687117271165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1125845454165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p697638629165635"><a name="p697638629165635"></a><a name="p697638629165635"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487292467165635"><a name="p1487292467165635"></a><a name="p1487292467165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1756757124165635"><a name="p1756757124165635"></a><a name="p1756757124165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row835383075165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846811284165635"><a name="p846811284165635"></a><a name="p846811284165635"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1338904553165635"><a name="p1338904553165635"></a><a name="p1338904553165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p71752432165635"><a name="p71752432165635"></a><a name="p71752432165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1297940325165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p85244198165635"><a name="p85244198165635"></a><a name="p85244198165635"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p336957111165635"><a name="p336957111165635"></a><a name="p336957111165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1261420511165635"><a name="p1261420511165635"></a><a name="p1261420511165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1910737061165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p193343226165635"><a name="p193343226165635"></a><a name="p193343226165635"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236283828165635"><a name="p1236283828165635"></a><a name="p1236283828165635"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1053013257165635"><a name="p1053013257165635"></a><a name="p1053013257165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row234042990165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p788342579165635"><a name="p788342579165635"></a><a name="p788342579165635"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129448273165635"><a name="p1129448273165635"></a><a name="p1129448273165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p527055083165635"><a name="p527055083165635"></a><a name="p527055083165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1501033944165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1421069826165635"><a name="p1421069826165635"></a><a name="p1421069826165635"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629926151165635"><a name="p1629926151165635"></a><a name="p1629926151165635"></a>void </p>
<p id="p487741682165635"><a name="p487741682165635"></a><a name="p487741682165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1774368383165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1427131700165635"><a name="p1427131700165635"></a><a name="p1427131700165635"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011335537165635"><a name="p1011335537165635"></a><a name="p1011335537165635"></a>virtual void </p>
<p id="p2010985891165635"><a name="p2010985891165635"></a><a name="p2010985891165635"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row992526822165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p380449743165635"><a name="p380449743165635"></a><a name="p380449743165635"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235516012165635"><a name="p1235516012165635"></a><a name="p1235516012165635"></a>virtual int16_t </p>
<p id="p249216051165635"><a name="p249216051165635"></a><a name="p249216051165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1430325783165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1382263949165635"><a name="p1382263949165635"></a><a name="p1382263949165635"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019333218165635"><a name="p1019333218165635"></a><a name="p1019333218165635"></a>virtual void </p>
<p id="p1060448849165635"><a name="p1060448849165635"></a><a name="p1060448849165635"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row188385902165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p505038633165635"><a name="p505038633165635"></a><a name="p505038633165635"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198149817165635"><a name="p1198149817165635"></a><a name="p1198149817165635"></a>virtual int16_t </p>
<p id="p491286540165635"><a name="p491286540165635"></a><a name="p491286540165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row2100495476165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1019072873165635"><a name="p1019072873165635"></a><a name="p1019072873165635"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p578868836165635"><a name="p578868836165635"></a><a name="p578868836165635"></a>virtual void </p>
<p id="p1485166330165635"><a name="p1485166330165635"></a><a name="p1485166330165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row154366701165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1615927979165635"><a name="p1615927979165635"></a><a name="p1615927979165635"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p525471002165635"><a name="p525471002165635"></a><a name="p525471002165635"></a>virtual void </p>
<p id="p1392950750165635"><a name="p1392950750165635"></a><a name="p1392950750165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row190079391165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862316493165635"><a name="p1862316493165635"></a><a name="p1862316493165635"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1169890279165635"><a name="p1169890279165635"></a><a name="p1169890279165635"></a>int16_t </p>
<p id="p1526179610165635"><a name="p1526179610165635"></a><a name="p1526179610165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row670930727165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58450932165635"><a name="p58450932165635"></a><a name="p58450932165635"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434517800165635"><a name="p434517800165635"></a><a name="p434517800165635"></a>virtual void </p>
<p id="p1247166876165635"><a name="p1247166876165635"></a><a name="p1247166876165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2009171787165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1803673247165635"><a name="p1803673247165635"></a><a name="p1803673247165635"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1206152576165635"><a name="p1206152576165635"></a><a name="p1206152576165635"></a>int16_t </p>
<p id="p1978513011165635"><a name="p1978513011165635"></a><a name="p1978513011165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1817493190165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218404796165635"><a name="p218404796165635"></a><a name="p218404796165635"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480650877165635"><a name="p1480650877165635"></a><a name="p1480650877165635"></a>virtual void </p>
<p id="p207298265165635"><a name="p207298265165635"></a><a name="p207298265165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1169255916165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663727554165635"><a name="p1663727554165635"></a><a name="p1663727554165635"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p613796954165635"><a name="p613796954165635"></a><a name="p613796954165635"></a>virtual void </p>
<p id="p1646552557165635"><a name="p1646552557165635"></a><a name="p1646552557165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row271724549165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032332162165635"><a name="p2032332162165635"></a><a name="p2032332162165635"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1595432766165635"><a name="p1595432766165635"></a><a name="p1595432766165635"></a>bool </p>
<p id="p81030572165635"><a name="p81030572165635"></a><a name="p81030572165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1736660669165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833928754165635"><a name="p833928754165635"></a><a name="p833928754165635"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p948668257165635"><a name="p948668257165635"></a><a name="p948668257165635"></a>void </p>
<p id="p148432243165635"><a name="p148432243165635"></a><a name="p148432243165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1175822882165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217842751165635"><a name="p1217842751165635"></a><a name="p1217842751165635"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p77962619165635"><a name="p77962619165635"></a><a name="p77962619165635"></a>void </p>
<p id="p835543772165635"><a name="p835543772165635"></a><a name="p835543772165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1354700692165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929128657165635"><a name="p929128657165635"></a><a name="p929128657165635"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1429972234165635"><a name="p1429972234165635"></a><a name="p1429972234165635"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p259194457165635"><a name="p259194457165635"></a><a name="p259194457165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1482917738165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p154556490165635"><a name="p154556490165635"></a><a name="p154556490165635"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010653624165635"><a name="p2010653624165635"></a><a name="p2010653624165635"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1669490644165635"><a name="p1669490644165635"></a><a name="p1669490644165635"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row619906382165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641248099165635"><a name="p1641248099165635"></a><a name="p1641248099165635"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p381264858165635"><a name="p381264858165635"></a><a name="p381264858165635"></a>void </p>
<p id="p1552332284165635"><a name="p1552332284165635"></a><a name="p1552332284165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row408433897165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790779080165635"><a name="p1790779080165635"></a><a name="p1790779080165635"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1450358100165635"><a name="p1450358100165635"></a><a name="p1450358100165635"></a>const char * </p>
<p id="p354124521165635"><a name="p354124521165635"></a><a name="p354124521165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1493485296165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1063322144165635"><a name="p1063322144165635"></a><a name="p1063322144165635"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1442482695165635"><a name="p1442482695165635"></a><a name="p1442482695165635"></a>void </p>
<p id="p1737567609165635"><a name="p1737567609165635"></a><a name="p1737567609165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1400804550165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162904977165635"><a name="p162904977165635"></a><a name="p162904977165635"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288558527165635"><a name="p288558527165635"></a><a name="p288558527165635"></a>int16_t </p>
<p id="p525691738165635"><a name="p525691738165635"></a><a name="p525691738165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row85820677165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198432778165635"><a name="p1198432778165635"></a><a name="p1198432778165635"></a><a href="graphic.md#ga6d23780da1faa1071197b716bca365e0">GetViewType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1022489810165635"><a name="p1022489810165635"></a><a name="p1022489810165635"></a>virtual UIViewType </p>
<p id="p936091523165635"><a name="p936091523165635"></a><a name="p936091523165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1927427478165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342196809165635"><a name="p342196809165635"></a><a name="p342196809165635"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125478027165635"><a name="p2125478027165635"></a><a name="p2125478027165635"></a>virtual void </p>
<p id="p1564070965165635"><a name="p1564070965165635"></a><a name="p1564070965165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1059193693165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1364090402165635"><a name="p1364090402165635"></a><a name="p1364090402165635"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1942003245165635"><a name="p1942003245165635"></a><a name="p1942003245165635"></a>void </p>
<p id="p1128891592165635"><a name="p1128891592165635"></a><a name="p1128891592165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row418122787165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p994024183165635"><a name="p994024183165635"></a><a name="p994024183165635"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p324619007165635"><a name="p324619007165635"></a><a name="p324619007165635"></a>void </p>
<p id="p278338818165635"><a name="p278338818165635"></a><a name="p278338818165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1143335091165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1705256894165635"><a name="p1705256894165635"></a><a name="p1705256894165635"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707464503165635"><a name="p1707464503165635"></a><a name="p1707464503165635"></a>void </p>
<p id="p399454394165635"><a name="p399454394165635"></a><a name="p399454394165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1145310791165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p637518780165635"><a name="p637518780165635"></a><a name="p637518780165635"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1297049329165635"><a name="p1297049329165635"></a><a name="p1297049329165635"></a>void </p>
<p id="p587239020165635"><a name="p587239020165635"></a><a name="p587239020165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1256683584165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126196448165635"><a name="p2126196448165635"></a><a name="p2126196448165635"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263990633165635"><a name="p263990633165635"></a><a name="p263990633165635"></a>void </p>
<p id="p1678382819165635"><a name="p1678382819165635"></a><a name="p1678382819165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row2057176987165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929711346165635"><a name="p1929711346165635"></a><a name="p1929711346165635"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858514915165635"><a name="p1858514915165635"></a><a name="p1858514915165635"></a>void </p>
<p id="p1133475363165635"><a name="p1133475363165635"></a><a name="p1133475363165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row791447604165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716052818165635"><a name="p1716052818165635"></a><a name="p1716052818165635"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1286347151165635"><a name="p1286347151165635"></a><a name="p1286347151165635"></a>void </p>
<p id="p2140640937165635"><a name="p2140640937165635"></a><a name="p2140640937165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1244552103165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1706585650165635"><a name="p1706585650165635"></a><a name="p1706585650165635"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p582189582165635"><a name="p582189582165635"></a><a name="p582189582165635"></a>void </p>
<p id="p1955622324165635"><a name="p1955622324165635"></a><a name="p1955622324165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1624362607165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518868846165635"><a name="p518868846165635"></a><a name="p518868846165635"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122984146165635"><a name="p122984146165635"></a><a name="p122984146165635"></a>void </p>
<p id="p1932180740165635"><a name="p1932180740165635"></a><a name="p1932180740165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row543395479165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111466178165635"><a name="p2111466178165635"></a><a name="p2111466178165635"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928047886165635"><a name="p1928047886165635"></a><a name="p1928047886165635"></a>void </p>
<p id="p1959920023165635"><a name="p1959920023165635"></a><a name="p1959920023165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row637713309165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686175448165635"><a name="p686175448165635"></a><a name="p686175448165635"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p678370403165635"><a name="p678370403165635"></a><a name="p678370403165635"></a>void </p>
<p id="p191267598165635"><a name="p191267598165635"></a><a name="p191267598165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row154211275165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846700402165635"><a name="p1846700402165635"></a><a name="p1846700402165635"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1122238516165635"><a name="p1122238516165635"></a><a name="p1122238516165635"></a>void </p>
<p id="p1331477797165635"><a name="p1331477797165635"></a><a name="p1331477797165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row627102152165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320657107165635"><a name="p1320657107165635"></a><a name="p1320657107165635"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26850454165635"><a name="p26850454165635"></a><a name="p26850454165635"></a>void </p>
<p id="p1587935138165635"><a name="p1587935138165635"></a><a name="p1587935138165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row650738014165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2020638472165635"><a name="p2020638472165635"></a><a name="p2020638472165635"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846666845165635"><a name="p846666845165635"></a><a name="p846666845165635"></a>void </p>
<p id="p1224446746165635"><a name="p1224446746165635"></a><a name="p1224446746165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1996281313165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1091013894165635"><a name="p1091013894165635"></a><a name="p1091013894165635"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1689008536165635"><a name="p1689008536165635"></a><a name="p1689008536165635"></a>void </p>
<p id="p1261048063165635"><a name="p1261048063165635"></a><a name="p1261048063165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row2145571394165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p744693559165635"><a name="p744693559165635"></a><a name="p744693559165635"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840597419165635"><a name="p840597419165635"></a><a name="p840597419165635"></a>void </p>
<p id="p1946177946165635"><a name="p1946177946165635"></a><a name="p1946177946165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1956236993165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p928995326165635"><a name="p928995326165635"></a><a name="p928995326165635"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250218839165635"><a name="p1250218839165635"></a><a name="p1250218839165635"></a>virtual void </p>
<p id="p1650230541165635"><a name="p1650230541165635"></a><a name="p1650230541165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row511176606165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058771764165635"><a name="p1058771764165635"></a><a name="p1058771764165635"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175182937165635"><a name="p175182937165635"></a><a name="p175182937165635"></a>virtual int64_t </p>
<p id="p1100007609165635"><a name="p1100007609165635"></a><a name="p1100007609165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1327642407165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32172590165635"><a name="p32172590165635"></a><a name="p32172590165635"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621852294165635"><a name="p621852294165635"></a><a name="p621852294165635"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1458726709165635"><a name="p1458726709165635"></a><a name="p1458726709165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1454834026165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1527105280165635"><a name="p1527105280165635"></a><a name="p1527105280165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139316994165635"><a name="p2139316994165635"></a><a name="p2139316994165635"></a>void * </p>
<p id="p1864383662165635"><a name="p1864383662165635"></a><a name="p1864383662165635"></a>Overrides the <strong id="b1925911930165635"><a name="b1925911930165635"></a><a name="b1925911930165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row217195889165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1648253831165635"><a name="p1648253831165635"></a><a name="p1648253831165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66170346165635"><a name="p66170346165635"></a><a name="p66170346165635"></a>void </p>
<p id="p1624351898165635"><a name="p1624351898165635"></a><a name="p1624351898165635"></a>Overrides the <strong id="b1334931371165635"><a name="b1334931371165635"></a><a name="b1334931371165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

