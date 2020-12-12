# OHOS::UIViewGroup<a name="EN-US_TOPIC_0000001055678122"></a>

-   [Overview](#section255601631165635)
-   [Summary](#section1539644998165635)
-   [Public Member Functions](#pub-methods)
-   [Protected Member Functions](#pro-methods)
-   [Protected Attributes](#pro-attribs)

## **Overview**<a name="section255601631165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a view group that consists of its child views. 

The child views can be added to, inserted in, and removed from the view group. Child views that are added later are displayed at the upper layer of this view group. All child views are stored in a linked list.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1539644998165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1146890172165635"></a>
<table><thead align="left"><tr id="row240768120165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p818871482165635"><a name="p818871482165635"></a><a name="p818871482165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1551248923165635"><a name="p1551248923165635"></a><a name="p1551248923165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row206191430165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p736192047165635"><a name="p736192047165635"></a><a name="p736192047165635"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1012227439165635"><a name="p1012227439165635"></a><a name="p1012227439165635"></a> </p>
<p id="p707726333165635"><a name="p707726333165635"></a><a name="p707726333165635"></a>A default constructor used to create a <strong id="b1781296831165635"><a name="b1781296831165635"></a><a name="b1781296831165635"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1974253539165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866474279165635"><a name="p866474279165635"></a><a name="p866474279165635"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1889409230165635"><a name="p1889409230165635"></a><a name="p1889409230165635"></a>virtual </p>
<p id="p1258269244165635"><a name="p1258269244165635"></a><a name="p1258269244165635"></a>A destructor used to delete the <strong id="b34569434165635"><a name="b34569434165635"></a><a name="b34569434165635"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row910420954165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1312882979165635"><a name="p1312882979165635"></a><a name="p1312882979165635"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p373500576165635"><a name="p373500576165635"></a><a name="p373500576165635"></a>UIViewType </p>
<p id="p37263380165635"><a name="p37263380165635"></a><a name="p37263380165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1793456030165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107958453165635"><a name="p2107958453165635"></a><a name="p2107958453165635"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p673108461165635"><a name="p673108461165635"></a><a name="p673108461165635"></a>virtual void </p>
<p id="p1833304999165635"><a name="p1833304999165635"></a><a name="p1833304999165635"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row458725636165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425385345165635"><a name="p425385345165635"></a><a name="p425385345165635"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1011027279165635"><a name="p1011027279165635"></a><a name="p1011027279165635"></a>virtual void </p>
<p id="p924572974165635"><a name="p924572974165635"></a><a name="p924572974165635"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1388980527165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p224501341165635"><a name="p224501341165635"></a><a name="p224501341165635"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1670368723165635"><a name="p1670368723165635"></a><a name="p1670368723165635"></a>virtual void </p>
<p id="p453569468165635"><a name="p453569468165635"></a><a name="p453569468165635"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row2129330411165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445294794165635"><a name="p445294794165635"></a><a name="p445294794165635"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761113743165635"><a name="p761113743165635"></a><a name="p761113743165635"></a>virtual void </p>
<p id="p196549085165635"><a name="p196549085165635"></a><a name="p196549085165635"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row285960066165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1271567207165635"><a name="p1271567207165635"></a><a name="p1271567207165635"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105686195165635"><a name="p105686195165635"></a><a name="p105686195165635"></a>virtual void </p>
<p id="p993664635165635"><a name="p993664635165635"></a><a name="p993664635165635"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1766693263165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1503145138165635"><a name="p1503145138165635"></a><a name="p1503145138165635"></a><a href="graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926060118165635"><a name="p1926060118165635"></a><a name="p1926060118165635"></a>virtual void </p>
<p id="p167999129165635"><a name="p167999129165635"></a><a name="p167999129165635"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row530378667165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122019449165635"><a name="p1122019449165635"></a><a name="p1122019449165635"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134861003165635"><a name="p1134861003165635"></a><a name="p1134861003165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1887104593165635"><a name="p1887104593165635"></a><a name="p1887104593165635"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row2066057165165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p837622295165635"><a name="p837622295165635"></a><a name="p837622295165635"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084665319165635"><a name="p2084665319165635"></a><a name="p2084665319165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1197777877165635"><a name="p1197777877165635"></a><a name="p1197777877165635"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1457225822165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1825939702165635"><a name="p1825939702165635"></a><a name="p1825939702165635"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88036578165635"><a name="p88036578165635"></a><a name="p88036578165635"></a>void </p>
<p id="p828149537165635"><a name="p828149537165635"></a><a name="p828149537165635"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row2116339879165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970244344165635"><a name="p1970244344165635"></a><a name="p1970244344165635"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p699401575165635"><a name="p699401575165635"></a><a name="p699401575165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1527387759165635"><a name="p1527387759165635"></a><a name="p1527387759165635"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1111333991165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2129868869165635"><a name="p2129868869165635"></a><a name="p2129868869165635"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226705292165635"><a name="p1226705292165635"></a><a name="p1226705292165635"></a>void </p>
<p id="p290378133165635"><a name="p290378133165635"></a><a name="p290378133165635"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row480504745165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393382766165635"><a name="p1393382766165635"></a><a name="p1393382766165635"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202139302165635"><a name="p1202139302165635"></a><a name="p1202139302165635"></a> </p>
<p id="p1776500370165635"><a name="p1776500370165635"></a><a name="p1776500370165635"></a>A default constructor used to create an <strong id="b736676455165635"><a name="b736676455165635"></a><a name="b736676455165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1893032280165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026107629165635"><a name="p1026107629165635"></a><a name="p1026107629165635"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460149324165635"><a name="p460149324165635"></a><a name="p460149324165635"></a> </p>
<p id="p25077522165635"><a name="p25077522165635"></a><a name="p25077522165635"></a>A constructor used to create an <strong id="b598128784165635"><a name="b598128784165635"></a><a name="b598128784165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1877258016165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145012557165635"><a name="p145012557165635"></a><a name="p145012557165635"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424128229165635"><a name="p1424128229165635"></a><a name="p1424128229165635"></a>virtual </p>
<p id="p1023873763165635"><a name="p1023873763165635"></a><a name="p1023873763165635"></a>A destructor used to delete the <strong id="b1608688191165635"><a name="b1608688191165635"></a><a name="b1608688191165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1865800992165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1189105906165635"><a name="p1189105906165635"></a><a name="p1189105906165635"></a><a href="graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372341478165635"><a name="p1372341478165635"></a><a name="p1372341478165635"></a>virtual bool </p>
<p id="p119351259165635"><a name="p119351259165635"></a><a name="p119351259165635"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1248770154165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p469064881165635"><a name="p469064881165635"></a><a name="p469064881165635"></a><a href="graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304158892165635"><a name="p304158892165635"></a><a name="p304158892165635"></a>virtual void </p>
<p id="p1154158186165635"><a name="p1154158186165635"></a><a name="p1154158186165635"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row387339994165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p918093466165635"><a name="p918093466165635"></a><a name="p918093466165635"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1417875064165635"><a name="p1417875064165635"></a><a name="p1417875064165635"></a>virtual void </p>
<p id="p2007032889165635"><a name="p2007032889165635"></a><a name="p2007032889165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row478856483165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835597296165635"><a name="p835597296165635"></a><a name="p835597296165635"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682899528165635"><a name="p682899528165635"></a><a name="p682899528165635"></a>virtual void </p>
<p id="p897524691165635"><a name="p897524691165635"></a><a name="p897524691165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row637806613165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990376582165635"><a name="p990376582165635"></a><a name="p990376582165635"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35162069165635"><a name="p35162069165635"></a><a name="p35162069165635"></a>void </p>
<p id="p1133267349165635"><a name="p1133267349165635"></a><a name="p1133267349165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row165719567165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p590210259165635"><a name="p590210259165635"></a><a name="p590210259165635"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p421968701165635"><a name="p421968701165635"></a><a name="p421968701165635"></a>void </p>
<p id="p1285409031165635"><a name="p1285409031165635"></a><a name="p1285409031165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1172661950165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328204508165635"><a name="p328204508165635"></a><a name="p328204508165635"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1125834591165635"><a name="p1125834591165635"></a><a name="p1125834591165635"></a>virtual bool </p>
<p id="p1892535733165635"><a name="p1892535733165635"></a><a name="p1892535733165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row486111603165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1366441850165635"><a name="p1366441850165635"></a><a name="p1366441850165635"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p999689079165635"><a name="p999689079165635"></a><a name="p999689079165635"></a>virtual bool </p>
<p id="p107492039165635"><a name="p107492039165635"></a><a name="p107492039165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1898367243165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p135759847165635"><a name="p135759847165635"></a><a name="p135759847165635"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178356945165635"><a name="p1178356945165635"></a><a name="p1178356945165635"></a>virtual bool </p>
<p id="p397571959165635"><a name="p397571959165635"></a><a name="p397571959165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1708739786165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2068776584165635"><a name="p2068776584165635"></a><a name="p2068776584165635"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073394773165635"><a name="p2073394773165635"></a><a name="p2073394773165635"></a>virtual bool </p>
<p id="p1054334507165635"><a name="p1054334507165635"></a><a name="p1054334507165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1772661316165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1371664200165635"><a name="p1371664200165635"></a><a name="p1371664200165635"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1463204072165635"><a name="p1463204072165635"></a><a name="p1463204072165635"></a>virtual void </p>
<p id="p1498816571165635"><a name="p1498816571165635"></a><a name="p1498816571165635"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row2045391732165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p5045603165635"><a name="p5045603165635"></a><a name="p5045603165635"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962389356165635"><a name="p962389356165635"></a><a name="p962389356165635"></a>virtual void </p>
<p id="p412175138165635"><a name="p412175138165635"></a><a name="p412175138165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1892475245165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008938168165635"><a name="p1008938168165635"></a><a name="p1008938168165635"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492639059165635"><a name="p1492639059165635"></a><a name="p1492639059165635"></a>virtual void </p>
<p id="p509446410165635"><a name="p509446410165635"></a><a name="p509446410165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row826049562165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268501952165635"><a name="p1268501952165635"></a><a name="p1268501952165635"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826986572165635"><a name="p826986572165635"></a><a name="p826986572165635"></a>virtual void </p>
<p id="p79359975165635"><a name="p79359975165635"></a><a name="p79359975165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1051450349165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1586740485165635"><a name="p1586740485165635"></a><a name="p1586740485165635"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664594730165635"><a name="p1664594730165635"></a><a name="p1664594730165635"></a>void </p>
<p id="p59573950165635"><a name="p59573950165635"></a><a name="p59573950165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row443393188165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p864406378165635"><a name="p864406378165635"></a><a name="p864406378165635"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690180126165635"><a name="p1690180126165635"></a><a name="p1690180126165635"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1426982998165635"><a name="p1426982998165635"></a><a name="p1426982998165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row352535886165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p453476483165635"><a name="p453476483165635"></a><a name="p453476483165635"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033334508165635"><a name="p2033334508165635"></a><a name="p2033334508165635"></a>void </p>
<p id="p1714976164165635"><a name="p1714976164165635"></a><a name="p1714976164165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1543619580165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p326619526165635"><a name="p326619526165635"></a><a name="p326619526165635"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p548636586165635"><a name="p548636586165635"></a><a name="p548636586165635"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p783542173165635"><a name="p783542173165635"></a><a name="p783542173165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row16774462165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p935968468165635"><a name="p935968468165635"></a><a name="p935968468165635"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767953123165635"><a name="p1767953123165635"></a><a name="p1767953123165635"></a>void </p>
<p id="p592917287165635"><a name="p592917287165635"></a><a name="p592917287165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row64501006165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456251792165635"><a name="p1456251792165635"></a><a name="p1456251792165635"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p329578251165635"><a name="p329578251165635"></a><a name="p329578251165635"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p860638598165635"><a name="p860638598165635"></a><a name="p860638598165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1119057633165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1301698075165635"><a name="p1301698075165635"></a><a name="p1301698075165635"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121663297165635"><a name="p1121663297165635"></a><a name="p1121663297165635"></a>void </p>
<p id="p95734035165635"><a name="p95734035165635"></a><a name="p95734035165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1063666672165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p814568137165635"><a name="p814568137165635"></a><a name="p814568137165635"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p670161373165635"><a name="p670161373165635"></a><a name="p670161373165635"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p344921764165635"><a name="p344921764165635"></a><a name="p344921764165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row229229786165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122899680165635"><a name="p122899680165635"></a><a name="p122899680165635"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957426034165635"><a name="p957426034165635"></a><a name="p957426034165635"></a>void </p>
<p id="p1970968205165635"><a name="p1970968205165635"></a><a name="p1970968205165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1082426610165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235224667165635"><a name="p235224667165635"></a><a name="p235224667165635"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p911258414165635"><a name="p911258414165635"></a><a name="p911258414165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p2093463937165635"><a name="p2093463937165635"></a><a name="p2093463937165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1539835849165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p944317129165635"><a name="p944317129165635"></a><a name="p944317129165635"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p81148101165635"><a name="p81148101165635"></a><a name="p81148101165635"></a>void </p>
<p id="p1353742767165635"><a name="p1353742767165635"></a><a name="p1353742767165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1175655975165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p63975746165635"><a name="p63975746165635"></a><a name="p63975746165635"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1901132697165635"><a name="p1901132697165635"></a><a name="p1901132697165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p868543180165635"><a name="p868543180165635"></a><a name="p868543180165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1799481480165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218470838165635"><a name="p1218470838165635"></a><a name="p1218470838165635"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p891526172165635"><a name="p891526172165635"></a><a name="p891526172165635"></a>virtual void </p>
<p id="p162447158165635"><a name="p162447158165635"></a><a name="p162447158165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1242490669165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p751066295165635"><a name="p751066295165635"></a><a name="p751066295165635"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435893312165635"><a name="p435893312165635"></a><a name="p435893312165635"></a>bool </p>
<p id="p692378823165635"><a name="p692378823165635"></a><a name="p692378823165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row772330409165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548775636165635"><a name="p1548775636165635"></a><a name="p1548775636165635"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492507093165635"><a name="p1492507093165635"></a><a name="p1492507093165635"></a>void </p>
<p id="p2031059075165635"><a name="p2031059075165635"></a><a name="p2031059075165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1397756882165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379234214165635"><a name="p379234214165635"></a><a name="p379234214165635"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328931301165635"><a name="p328931301165635"></a><a name="p328931301165635"></a>bool </p>
<p id="p575974998165635"><a name="p575974998165635"></a><a name="p575974998165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1804118823165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1768044527165635"><a name="p1768044527165635"></a><a name="p1768044527165635"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1590071276165635"><a name="p1590071276165635"></a><a name="p1590071276165635"></a>void </p>
<p id="p497939745165635"><a name="p497939745165635"></a><a name="p497939745165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1049776927165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52243192165635"><a name="p52243192165635"></a><a name="p52243192165635"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215069378165635"><a name="p215069378165635"></a><a name="p215069378165635"></a>bool </p>
<p id="p1198652792165635"><a name="p1198652792165635"></a><a name="p1198652792165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1097791314165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2138442335165635"><a name="p2138442335165635"></a><a name="p2138442335165635"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294654050165635"><a name="p294654050165635"></a><a name="p294654050165635"></a>void </p>
<p id="p1256905816165635"><a name="p1256905816165635"></a><a name="p1256905816165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row937305655165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476857030165635"><a name="p1476857030165635"></a><a name="p1476857030165635"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2051852104165635"><a name="p2051852104165635"></a><a name="p2051852104165635"></a>bool </p>
<p id="p1516432270165635"><a name="p1516432270165635"></a><a name="p1516432270165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row514474717165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853588035165635"><a name="p853588035165635"></a><a name="p853588035165635"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961103193165635"><a name="p1961103193165635"></a><a name="p1961103193165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p709768235165635"><a name="p709768235165635"></a><a name="p709768235165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1555686423165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523036486165635"><a name="p1523036486165635"></a><a name="p1523036486165635"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1526966979165635"><a name="p1526966979165635"></a><a name="p1526966979165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1132254734165635"><a name="p1132254734165635"></a><a name="p1132254734165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row709369165165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1941715077165635"><a name="p1941715077165635"></a><a name="p1941715077165635"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p662745284165635"><a name="p662745284165635"></a><a name="p662745284165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1919458280165635"><a name="p1919458280165635"></a><a name="p1919458280165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1016561455165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p987187998165635"><a name="p987187998165635"></a><a name="p987187998165635"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813518504165635"><a name="p813518504165635"></a><a name="p813518504165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1568594464165635"><a name="p1568594464165635"></a><a name="p1568594464165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1262782892165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32439236165635"><a name="p32439236165635"></a><a name="p32439236165635"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076945595165635"><a name="p2076945595165635"></a><a name="p2076945595165635"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1267205585165635"><a name="p1267205585165635"></a><a name="p1267205585165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1062311051165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p251248871165635"><a name="p251248871165635"></a><a name="p251248871165635"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727363307165635"><a name="p1727363307165635"></a><a name="p1727363307165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1242446037165635"><a name="p1242446037165635"></a><a name="p1242446037165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row246673903165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005073573165635"><a name="p1005073573165635"></a><a name="p1005073573165635"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p872587265165635"><a name="p872587265165635"></a><a name="p872587265165635"></a>void </p>
<p id="p1467812113165635"><a name="p1467812113165635"></a><a name="p1467812113165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1207221969165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871682996165635"><a name="p871682996165635"></a><a name="p871682996165635"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258030601165635"><a name="p1258030601165635"></a><a name="p1258030601165635"></a>virtual void </p>
<p id="p372476023165635"><a name="p372476023165635"></a><a name="p372476023165635"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1494253610165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427660351165635"><a name="p427660351165635"></a><a name="p427660351165635"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1104013702165635"><a name="p1104013702165635"></a><a name="p1104013702165635"></a>virtual int16_t </p>
<p id="p1025792498165635"><a name="p1025792498165635"></a><a name="p1025792498165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1919123245165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p582061785165635"><a name="p582061785165635"></a><a name="p582061785165635"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763503906165635"><a name="p1763503906165635"></a><a name="p1763503906165635"></a>virtual void </p>
<p id="p44796896165635"><a name="p44796896165635"></a><a name="p44796896165635"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1372122073165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605039579165635"><a name="p605039579165635"></a><a name="p605039579165635"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p516763154165635"><a name="p516763154165635"></a><a name="p516763154165635"></a>virtual int16_t </p>
<p id="p1518482200165635"><a name="p1518482200165635"></a><a name="p1518482200165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1739913621165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358753620165635"><a name="p358753620165635"></a><a name="p358753620165635"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1385985309165635"><a name="p1385985309165635"></a><a name="p1385985309165635"></a>virtual void </p>
<p id="p1390248377165635"><a name="p1390248377165635"></a><a name="p1390248377165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row615806594165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977753387165635"><a name="p1977753387165635"></a><a name="p1977753387165635"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1617354594165635"><a name="p1617354594165635"></a><a name="p1617354594165635"></a>virtual void </p>
<p id="p1056718712165635"><a name="p1056718712165635"></a><a name="p1056718712165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1583829343165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p508403268165635"><a name="p508403268165635"></a><a name="p508403268165635"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p212614095165635"><a name="p212614095165635"></a><a name="p212614095165635"></a>int16_t </p>
<p id="p582527541165635"><a name="p582527541165635"></a><a name="p582527541165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1394327265165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856997771165635"><a name="p856997771165635"></a><a name="p856997771165635"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717903769165635"><a name="p1717903769165635"></a><a name="p1717903769165635"></a>virtual void </p>
<p id="p179283943165635"><a name="p179283943165635"></a><a name="p179283943165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row48184218165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p54341699165635"><a name="p54341699165635"></a><a name="p54341699165635"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p48307767165635"><a name="p48307767165635"></a><a name="p48307767165635"></a>int16_t </p>
<p id="p879586503165635"><a name="p879586503165635"></a><a name="p879586503165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1206011308165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102119664165635"><a name="p2102119664165635"></a><a name="p2102119664165635"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088158157165635"><a name="p1088158157165635"></a><a name="p1088158157165635"></a>virtual void </p>
<p id="p1528254565165635"><a name="p1528254565165635"></a><a name="p1528254565165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row446636235165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029574251165635"><a name="p2029574251165635"></a><a name="p2029574251165635"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p238394280165635"><a name="p238394280165635"></a><a name="p238394280165635"></a>virtual void </p>
<p id="p1196086026165635"><a name="p1196086026165635"></a><a name="p1196086026165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row2022645840165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1571505966165635"><a name="p1571505966165635"></a><a name="p1571505966165635"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1980156101165635"><a name="p1980156101165635"></a><a name="p1980156101165635"></a>bool </p>
<p id="p278932791165635"><a name="p278932791165635"></a><a name="p278932791165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row801306578165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155627941165635"><a name="p1155627941165635"></a><a name="p1155627941165635"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p497559003165635"><a name="p497559003165635"></a><a name="p497559003165635"></a>void </p>
<p id="p1190552538165635"><a name="p1190552538165635"></a><a name="p1190552538165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1112959819165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930830290165635"><a name="p930830290165635"></a><a name="p930830290165635"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717494491165635"><a name="p1717494491165635"></a><a name="p1717494491165635"></a>void </p>
<p id="p1259117552165635"><a name="p1259117552165635"></a><a name="p1259117552165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1574131002165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317262414165635"><a name="p1317262414165635"></a><a name="p1317262414165635"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016511597165635"><a name="p1016511597165635"></a><a name="p1016511597165635"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p1264853293165635"><a name="p1264853293165635"></a><a name="p1264853293165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row667972687165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p809711976165635"><a name="p809711976165635"></a><a name="p809711976165635"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962205501165635"><a name="p962205501165635"></a><a name="p962205501165635"></a>void </p>
<p id="p559869067165635"><a name="p559869067165635"></a><a name="p559869067165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row410685786165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p766456039165635"><a name="p766456039165635"></a><a name="p766456039165635"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1162950702165635"><a name="p1162950702165635"></a><a name="p1162950702165635"></a>const char * </p>
<p id="p1689291802165635"><a name="p1689291802165635"></a><a name="p1689291802165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1996135877165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208769244165635"><a name="p1208769244165635"></a><a name="p1208769244165635"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939638834165635"><a name="p939638834165635"></a><a name="p939638834165635"></a>void </p>
<p id="p1863627528165635"><a name="p1863627528165635"></a><a name="p1863627528165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1197291539165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p46723652165635"><a name="p46723652165635"></a><a name="p46723652165635"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p170167951165635"><a name="p170167951165635"></a><a name="p170167951165635"></a>int16_t </p>
<p id="p147716815165635"><a name="p147716815165635"></a><a name="p147716815165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1600635660165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2033367004165635"><a name="p2033367004165635"></a><a name="p2033367004165635"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p992488358165635"><a name="p992488358165635"></a><a name="p992488358165635"></a>virtual void </p>
<p id="p171519811165635"><a name="p171519811165635"></a><a name="p171519811165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row650454285165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510732762165635"><a name="p1510732762165635"></a><a name="p1510732762165635"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987759615165635"><a name="p987759615165635"></a><a name="p987759615165635"></a>void </p>
<p id="p702137970165635"><a name="p702137970165635"></a><a name="p702137970165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row998550381165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p415463295165635"><a name="p415463295165635"></a><a name="p415463295165635"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p858783615165635"><a name="p858783615165635"></a><a name="p858783615165635"></a>void </p>
<p id="p732218965165635"><a name="p732218965165635"></a><a name="p732218965165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row109685367165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306542568165635"><a name="p1306542568165635"></a><a name="p1306542568165635"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p257630284165635"><a name="p257630284165635"></a><a name="p257630284165635"></a>void </p>
<p id="p1460159540165635"><a name="p1460159540165635"></a><a name="p1460159540165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1312439663165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156947356165635"><a name="p156947356165635"></a><a name="p156947356165635"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1190919017165635"><a name="p1190919017165635"></a><a name="p1190919017165635"></a>void </p>
<p id="p1314556970165635"><a name="p1314556970165635"></a><a name="p1314556970165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row918315147165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1095026024165635"><a name="p1095026024165635"></a><a name="p1095026024165635"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615100850165635"><a name="p1615100850165635"></a><a name="p1615100850165635"></a>void </p>
<p id="p1377892280165635"><a name="p1377892280165635"></a><a name="p1377892280165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1536827990165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075370359165635"><a name="p2075370359165635"></a><a name="p2075370359165635"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p313714901165635"><a name="p313714901165635"></a><a name="p313714901165635"></a>void </p>
<p id="p22171274165635"><a name="p22171274165635"></a><a name="p22171274165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row2010436214165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1923640146165635"><a name="p1923640146165635"></a><a name="p1923640146165635"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1697783776165635"><a name="p1697783776165635"></a><a name="p1697783776165635"></a>void </p>
<p id="p642397717165635"><a name="p642397717165635"></a><a name="p642397717165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row2083975722165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816715019165635"><a name="p1816715019165635"></a><a name="p1816715019165635"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498140224165635"><a name="p1498140224165635"></a><a name="p1498140224165635"></a>void </p>
<p id="p1290095162165635"><a name="p1290095162165635"></a><a name="p1290095162165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row344339194165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2132882239165635"><a name="p2132882239165635"></a><a name="p2132882239165635"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978158831165635"><a name="p1978158831165635"></a><a name="p1978158831165635"></a>void </p>
<p id="p1289236261165635"><a name="p1289236261165635"></a><a name="p1289236261165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1216305865165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391565894165635"><a name="p1391565894165635"></a><a name="p1391565894165635"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1451041415165635"><a name="p1451041415165635"></a><a name="p1451041415165635"></a>void </p>
<p id="p1492293960165635"><a name="p1492293960165635"></a><a name="p1492293960165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row726235335165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p23835149165635"><a name="p23835149165635"></a><a name="p23835149165635"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p980944566165635"><a name="p980944566165635"></a><a name="p980944566165635"></a>void </p>
<p id="p1117005678165635"><a name="p1117005678165635"></a><a name="p1117005678165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1732658841165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198243900165635"><a name="p1198243900165635"></a><a name="p1198243900165635"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267403370165635"><a name="p267403370165635"></a><a name="p267403370165635"></a>void </p>
<p id="p1635495548165635"><a name="p1635495548165635"></a><a name="p1635495548165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1649068947165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1875876578165635"><a name="p1875876578165635"></a><a name="p1875876578165635"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083686994165635"><a name="p1083686994165635"></a><a name="p1083686994165635"></a>void </p>
<p id="p1381194139165635"><a name="p1381194139165635"></a><a name="p1381194139165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row483944002165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427008299165635"><a name="p427008299165635"></a><a name="p427008299165635"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283022865165635"><a name="p283022865165635"></a><a name="p283022865165635"></a>void </p>
<p id="p606338268165635"><a name="p606338268165635"></a><a name="p606338268165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row778237565165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p102908693165635"><a name="p102908693165635"></a><a name="p102908693165635"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434445531165635"><a name="p434445531165635"></a><a name="p434445531165635"></a>void </p>
<p id="p918622388165635"><a name="p918622388165635"></a><a name="p918622388165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1349030502165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1702643916165635"><a name="p1702643916165635"></a><a name="p1702643916165635"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465905219165635"><a name="p1465905219165635"></a><a name="p1465905219165635"></a>void </p>
<p id="p1144763722165635"><a name="p1144763722165635"></a><a name="p1144763722165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1188918554165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320122120165635"><a name="p1320122120165635"></a><a name="p1320122120165635"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964670397165635"><a name="p1964670397165635"></a><a name="p1964670397165635"></a>virtual void </p>
<p id="p231320095165635"><a name="p231320095165635"></a><a name="p231320095165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row2082089556165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p652216742165635"><a name="p652216742165635"></a><a name="p652216742165635"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p840467130165635"><a name="p840467130165635"></a><a name="p840467130165635"></a>virtual int64_t </p>
<p id="p501771387165635"><a name="p501771387165635"></a><a name="p501771387165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row174573565165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685706165635"><a name="p685706165635"></a><a name="p685706165635"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1416394131165635"><a name="p1416394131165635"></a><a name="p1416394131165635"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p107145646165635"><a name="p107145646165635"></a><a name="p107145646165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1457442330165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2082140115165635"><a name="p2082140115165635"></a><a name="p2082140115165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1857467894165635"><a name="p1857467894165635"></a><a name="p1857467894165635"></a>void * </p>
<p id="p1871584529165635"><a name="p1871584529165635"></a><a name="p1871584529165635"></a>Overrides the <strong id="b1562042821165635"><a name="b1562042821165635"></a><a name="b1562042821165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1108169892165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1085014514165635"><a name="p1085014514165635"></a><a name="p1085014514165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p231673338165635"><a name="p231673338165635"></a><a name="p231673338165635"></a>void </p>
<p id="p461908827165635"><a name="p461908827165635"></a><a name="p461908827165635"></a>Overrides the <strong id="b641290468165635"><a name="b641290468165635"></a><a name="b641290468165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Protected Member Functions<a name="pro-methods"></a>

<a name="table557114345165635"></a>
<table><thead align="left"><tr id="row454539780165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1165685907165635"><a name="p1165685907165635"></a><a name="p1165685907165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p873117088165635"><a name="p873117088165635"></a><a name="p873117088165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row180054082165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2099498816165635"><a name="p2099498816165635"></a><a name="p2099498816165635"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371726058165635"><a name="p1371726058165635"></a><a name="p1371726058165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1945410613165635"><a name="p1945410613165635"></a><a name="p1945410613165635"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row170605130165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1466623037165635"><a name="p1466623037165635"></a><a name="p1466623037165635"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619605295165635"><a name="p1619605295165635"></a><a name="p1619605295165635"></a>virtual void </p>
<p id="p439039979165635"><a name="p439039979165635"></a><a name="p439039979165635"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
</tbody>
</table>

## Protected Attributes<a name="pro-attribs"></a>

<a name="table1087899640165635"></a>
<table><thead align="left"><tr id="row1514371725165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p172722613165635"><a name="p172722613165635"></a><a name="p172722613165635"></a>Protected Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1200762025165635"><a name="p1200762025165635"></a><a name="p1200762025165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1689370118165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p860688571165635"><a name="p860688571165635"></a><a name="p860688571165635"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1691354549165635"><a name="p1691354549165635"></a><a name="p1691354549165635"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1271822691165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136482265165635"><a name="p136482265165635"></a><a name="p136482265165635"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345677581165635"><a name="p1345677581165635"></a><a name="p1345677581165635"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row54363627165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p527554818165635"><a name="p527554818165635"></a><a name="p527554818165635"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134553806165635"><a name="p134553806165635"></a><a name="p134553806165635"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row154097190165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1531636787165635"><a name="p1531636787165635"></a><a name="p1531636787165635"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1010149277165635"><a name="p1010149277165635"></a><a name="p1010149277165635"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row544910293165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379659145165635"><a name="p379659145165635"></a><a name="p379659145165635"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550851072165635"><a name="p550851072165635"></a><a name="p550851072165635"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1547717260165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440956892165635"><a name="p1440956892165635"></a><a name="p1440956892165635"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507072538165635"><a name="p507072538165635"></a><a name="p507072538165635"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

