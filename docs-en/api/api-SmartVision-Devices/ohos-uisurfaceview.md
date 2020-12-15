# OHOS::UISurfaceView<a name="EN-US_TOPIC_0000001054718153"></a>

-   [Overview](#section1163806064165634)
-   [Summary](#section833176623165634)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1163806064165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a surface view that interacts with the multimedia to achieve camera preview and video playback. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section833176623165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table851113911165634"></a>
<table><thead align="left"><tr id="row1339568409165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1667016598165634"><a name="p1667016598165634"></a><a name="p1667016598165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1799151855165634"><a name="p1799151855165634"></a><a name="p1799151855165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row374933749165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p601744079165634"><a name="p601744079165634"></a><a name="p601744079165634"></a><a href="graphic.md#gab8acc0b7172486e8e5d48c09fcd4c878">UISurfaceView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640479631165634"><a name="p1640479631165634"></a><a name="p1640479631165634"></a> </p>
<p id="p1352792581165634"><a name="p1352792581165634"></a><a name="p1352792581165634"></a>A constructor used to create a <strong id="b1673199753165634"><a name="b1673199753165634"></a><a name="b1673199753165634"></a><a href="ohos-uisurfaceview.md">UISurfaceView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1522112531165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891898313165634"><a name="p1891898313165634"></a><a name="p1891898313165634"></a><a href="graphic.md#gabf32743913a2a061ace3a5a3c88fe6fa">~UISurfaceView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1724628632165634"><a name="p1724628632165634"></a><a name="p1724628632165634"></a> </p>
<p id="p35240545165634"><a name="p35240545165634"></a><a name="p35240545165634"></a>A destructor used to delete the <strong id="b687920830165634"><a name="b687920830165634"></a><a name="b687920830165634"></a><a href="ohos-uisurfaceview.md">UISurfaceView</a></strong> instance. </p>
</td>
</tr>
<tr id="row75520411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1618324986165634"><a name="p1618324986165634"></a><a name="p1618324986165634"></a><a href="graphic.md#ga0d19e491e590bdfeeb2a6b3fa1a6b090">GetSurface</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973183432165634"><a name="p1973183432165634"></a><a name="p1973183432165634"></a><a href="ohos-surface.md">Surface</a> * </p>
<p id="p282397969165634"><a name="p282397969165634"></a><a name="p282397969165634"></a>Obtains the surface, which should be used together with the camera and video modules. </p>
</td>
</tr>
<tr id="row955462975165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p190681296165634"><a name="p190681296165634"></a><a name="p190681296165634"></a><a href="graphic.md#ga5d9af67ba074697876ff97f8ece305b7">SetPosition</a> (int16_t x, int16_t y) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1067424888165634"><a name="p1067424888165634"></a><a name="p1067424888165634"></a>void </p>
<p id="p847342082165634"><a name="p847342082165634"></a><a name="p847342082165634"></a>Sets the position for this view. </p>
</td>
</tr>
<tr id="row428604993165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323181028165634"><a name="p1323181028165634"></a><a name="p1323181028165634"></a><a href="graphic.md#ga4a505b3b207653c60161d90750f88a9d">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1092412454165634"><a name="p1092412454165634"></a><a name="p1092412454165634"></a>void </p>
<p id="p809925850165634"><a name="p809925850165634"></a><a name="p809925850165634"></a>Sets the position and size for this view. </p>
</td>
</tr>
<tr id="row1576930852165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019541055165634"><a name="p2019541055165634"></a><a name="p2019541055165634"></a><a href="graphic.md#gaa860971513d96f553be4e251f25c0262">Resize</a> (int16_t width, int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758033600165634"><a name="p1758033600165634"></a><a name="p1758033600165634"></a>void </p>
<p id="p895423177165634"><a name="p895423177165634"></a><a name="p895423177165634"></a>Adjusts the size of this view. </p>
</td>
</tr>
<tr id="row1157237316165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357775237165634"><a name="p357775237165634"></a><a name="p357775237165634"></a><a href="graphic.md#ga87457cce8ab3daa62852815ad36e9692">SetX</a> (int16_t x) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723869512165634"><a name="p723869512165634"></a><a name="p723869512165634"></a>void </p>
<p id="p420040539165634"><a name="p420040539165634"></a><a name="p420040539165634"></a>Sets the x-coordinate for this view. </p>
</td>
</tr>
<tr id="row1573585958165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360564378165634"><a name="p1360564378165634"></a><a name="p1360564378165634"></a><a href="graphic.md#gad7e27c2508753b6752594c3615b5d2fe">SetY</a> (int16_t y) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353004150165634"><a name="p1353004150165634"></a><a name="p1353004150165634"></a>void </p>
<p id="p1517750173165634"><a name="p1517750173165634"></a><a name="p1517750173165634"></a>Sets the y-coordinate for this view. </p>
</td>
</tr>
<tr id="row726959570165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28427230165634"><a name="p28427230165634"></a><a name="p28427230165634"></a><a href="graphic.md#ga54c350b75cf87ca112b3c21791f9c559">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043685914165634"><a name="p2043685914165634"></a><a name="p2043685914165634"></a>void </p>
<p id="p1863206829165634"><a name="p1863206829165634"></a><a name="p1863206829165634"></a>Sets the width for this view. </p>
</td>
</tr>
<tr id="row2085358314165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191564064165634"><a name="p191564064165634"></a><a name="p191564064165634"></a><a href="graphic.md#gaf90ada30a3336b947951d408b685787e">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p486566012165634"><a name="p486566012165634"></a><a name="p486566012165634"></a>void </p>
<p id="p570913592165634"><a name="p570913592165634"></a><a name="p570913592165634"></a>Sets the height for this view. </p>
</td>
</tr>
<tr id="row1055548737165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p258629208165634"><a name="p258629208165634"></a><a name="p258629208165634"></a><a href="graphic.md#gaa6b5efec0684a2800dba70c697d3902e">SetVisible</a> (bool visible) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1697879367165634"><a name="p1697879367165634"></a><a name="p1697879367165634"></a>void </p>
<p id="p1598979652165634"><a name="p1598979652165634"></a><a name="p1598979652165634"></a>Sets whether this view is visible. </p>
</td>
</tr>
<tr id="row1406633468165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984304907165634"><a name="p984304907165634"></a><a name="p984304907165634"></a><a href="graphic.md#gaeb15d1fb86ad2e2aabddc9c36676894a">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1325043750165634"><a name="p1325043750165634"></a><a name="p1325043750165634"></a>bool </p>
<p id="p511607992165634"><a name="p511607992165634"></a><a name="p511607992165634"></a>Called before this view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so that the drawing process is optimized. </p>
</td>
</tr>
<tr id="row1826576181165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1050674409165634"><a name="p1050674409165634"></a><a name="p1050674409165634"></a><a href="graphic.md#ga30a99c506c6d8d8fc0e0bd81d52e2d52">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454423490165634"><a name="p454423490165634"></a><a name="p454423490165634"></a>void </p>
<p id="p1183984033165634"><a name="p1183984033165634"></a><a name="p1183984033165634"></a>Called when this view is drawn. </p>
</td>
</tr>
<tr id="row209922812165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1889354277165634"><a name="p1889354277165634"></a><a name="p1889354277165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727050439165634"><a name="p727050439165634"></a><a name="p727050439165634"></a> </p>
<p id="p1340721979165634"><a name="p1340721979165634"></a><a name="p1340721979165634"></a>A default constructor used to create an <strong id="b468918075165634"><a name="b468918075165634"></a><a name="b468918075165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1456271041165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1518669698165634"><a name="p1518669698165634"></a><a name="p1518669698165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1675070381165634"><a name="p1675070381165634"></a><a name="p1675070381165634"></a> </p>
<p id="p1538389394165634"><a name="p1538389394165634"></a><a name="p1538389394165634"></a>A constructor used to create an <strong id="b1555327688165634"><a name="b1555327688165634"></a><a name="b1555327688165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1903578279165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1857459341165634"><a name="p1857459341165634"></a><a name="p1857459341165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2014188319165634"><a name="p2014188319165634"></a><a name="p2014188319165634"></a>virtual </p>
<p id="p1403100872165634"><a name="p1403100872165634"></a><a name="p1403100872165634"></a>A destructor used to delete the <strong id="b167600580165634"><a name="b167600580165634"></a><a name="b167600580165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row797632080165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p878318926165634"><a name="p878318926165634"></a><a name="p878318926165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215133276165634"><a name="p215133276165634"></a><a name="p215133276165634"></a>virtual void </p>
<p id="p627946225165634"><a name="p627946225165634"></a><a name="p627946225165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1332820352165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198965508165634"><a name="p1198965508165634"></a><a name="p1198965508165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p991655281165634"><a name="p991655281165634"></a><a name="p991655281165634"></a>virtual void </p>
<p id="p1140085436165634"><a name="p1140085436165634"></a><a name="p1140085436165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row953843370165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1086007515165634"><a name="p1086007515165634"></a><a name="p1086007515165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128519509165634"><a name="p1128519509165634"></a><a name="p1128519509165634"></a>void </p>
<p id="p1823269341165634"><a name="p1823269341165634"></a><a name="p1823269341165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1785039081165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p595305870165634"><a name="p595305870165634"></a><a name="p595305870165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256982078165634"><a name="p1256982078165634"></a><a name="p1256982078165634"></a>void </p>
<p id="p1569624054165634"><a name="p1569624054165634"></a><a name="p1569624054165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1340976645165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2125447745165634"><a name="p2125447745165634"></a><a name="p2125447745165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384683596165634"><a name="p1384683596165634"></a><a name="p1384683596165634"></a>virtual bool </p>
<p id="p688158069165634"><a name="p688158069165634"></a><a name="p688158069165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1763413381165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1570766237165634"><a name="p1570766237165634"></a><a name="p1570766237165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240402647165634"><a name="p1240402647165634"></a><a name="p1240402647165634"></a>virtual bool </p>
<p id="p2084372407165634"><a name="p2084372407165634"></a><a name="p2084372407165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row479078928165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136925763165634"><a name="p136925763165634"></a><a name="p136925763165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p315603948165634"><a name="p315603948165634"></a><a name="p315603948165634"></a>virtual bool </p>
<p id="p1844413340165634"><a name="p1844413340165634"></a><a name="p1844413340165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row579606754165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p885901809165634"><a name="p885901809165634"></a><a name="p885901809165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1466868614165634"><a name="p1466868614165634"></a><a name="p1466868614165634"></a>virtual bool </p>
<p id="p55951553165634"><a name="p55951553165634"></a><a name="p55951553165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1696606096165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p554876609165634"><a name="p554876609165634"></a><a name="p554876609165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173646095165634"><a name="p1173646095165634"></a><a name="p1173646095165634"></a>virtual void </p>
<p id="p1504700370165634"><a name="p1504700370165634"></a><a name="p1504700370165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1576130104165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056672861165634"><a name="p1056672861165634"></a><a name="p1056672861165634"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p692076274165634"><a name="p692076274165634"></a><a name="p692076274165634"></a>virtual void </p>
<p id="p1144906424165634"><a name="p1144906424165634"></a><a name="p1144906424165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1423317659165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722679079165634"><a name="p1722679079165634"></a><a name="p1722679079165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p516776048165634"><a name="p516776048165634"></a><a name="p516776048165634"></a>virtual void </p>
<p id="p1734762943165634"><a name="p1734762943165634"></a><a name="p1734762943165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1837326366165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641249022165634"><a name="p641249022165634"></a><a name="p641249022165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p307859963165634"><a name="p307859963165634"></a><a name="p307859963165634"></a>virtual void </p>
<p id="p646308587165634"><a name="p646308587165634"></a><a name="p646308587165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1717499979165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930264588165634"><a name="p930264588165634"></a><a name="p930264588165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663206239165634"><a name="p663206239165634"></a><a name="p663206239165634"></a>void </p>
<p id="p174498605165634"><a name="p174498605165634"></a><a name="p174498605165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1029170147165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1042850369165634"><a name="p1042850369165634"></a><a name="p1042850369165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1073431200165634"><a name="p1073431200165634"></a><a name="p1073431200165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1656063044165634"><a name="p1656063044165634"></a><a name="p1656063044165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1525150684165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1886867679165634"><a name="p1886867679165634"></a><a name="p1886867679165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1526078619165634"><a name="p1526078619165634"></a><a name="p1526078619165634"></a>void </p>
<p id="p733535844165634"><a name="p733535844165634"></a><a name="p733535844165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1573256981165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2146702928165634"><a name="p2146702928165634"></a><a name="p2146702928165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047670433165634"><a name="p2047670433165634"></a><a name="p2047670433165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p589488330165634"><a name="p589488330165634"></a><a name="p589488330165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row521363100165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659362602165634"><a name="p659362602165634"></a><a name="p659362602165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p767976186165634"><a name="p767976186165634"></a><a name="p767976186165634"></a>void </p>
<p id="p2061792914165634"><a name="p2061792914165634"></a><a name="p2061792914165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1786269283165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374838873165634"><a name="p374838873165634"></a><a name="p374838873165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001737453165634"><a name="p1001737453165634"></a><a name="p1001737453165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1545012112165634"><a name="p1545012112165634"></a><a name="p1545012112165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1382977037165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1594782069165634"><a name="p1594782069165634"></a><a name="p1594782069165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p856307417165634"><a name="p856307417165634"></a><a name="p856307417165634"></a>void </p>
<p id="p841693827165634"><a name="p841693827165634"></a><a name="p841693827165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row367161351165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p950074419165634"><a name="p950074419165634"></a><a name="p950074419165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719559617165634"><a name="p719559617165634"></a><a name="p719559617165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p230922055165634"><a name="p230922055165634"></a><a name="p230922055165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1725816022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209238927165634"><a name="p209238927165634"></a><a name="p209238927165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p527326727165634"><a name="p527326727165634"></a><a name="p527326727165634"></a>virtual void </p>
<p id="p1256791212165634"><a name="p1256791212165634"></a><a name="p1256791212165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row59005079165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1882720881165634"><a name="p1882720881165634"></a><a name="p1882720881165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p818590077165634"><a name="p818590077165634"></a><a name="p818590077165634"></a>void </p>
<p id="p2088837911165634"><a name="p2088837911165634"></a><a name="p2088837911165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row987877453165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1194173153165634"><a name="p1194173153165634"></a><a name="p1194173153165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139821461165634"><a name="p139821461165634"></a><a name="p139821461165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p390447247165634"><a name="p390447247165634"></a><a name="p390447247165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1187985465165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155960083165634"><a name="p155960083165634"></a><a name="p155960083165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570402111165634"><a name="p570402111165634"></a><a name="p570402111165634"></a>void </p>
<p id="p463438517165634"><a name="p463438517165634"></a><a name="p463438517165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row247296666165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1185638880165634"><a name="p1185638880165634"></a><a name="p1185638880165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p218347549165634"><a name="p218347549165634"></a><a name="p218347549165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p76782290165634"><a name="p76782290165634"></a><a name="p76782290165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row2057358895165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995548866165634"><a name="p1995548866165634"></a><a name="p1995548866165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428092422165634"><a name="p1428092422165634"></a><a name="p1428092422165634"></a>bool </p>
<p id="p1140301776165634"><a name="p1140301776165634"></a><a name="p1140301776165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row318398715165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686873486165634"><a name="p686873486165634"></a><a name="p686873486165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889923592165634"><a name="p889923592165634"></a><a name="p889923592165634"></a>void </p>
<p id="p53313422165634"><a name="p53313422165634"></a><a name="p53313422165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1403059685165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279329827165634"><a name="p1279329827165634"></a><a name="p1279329827165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p401424075165634"><a name="p401424075165634"></a><a name="p401424075165634"></a>bool </p>
<p id="p676906497165634"><a name="p676906497165634"></a><a name="p676906497165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row787205157165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208761728165634"><a name="p1208761728165634"></a><a name="p1208761728165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1932373366165634"><a name="p1932373366165634"></a><a name="p1932373366165634"></a>void </p>
<p id="p564751329165634"><a name="p564751329165634"></a><a name="p564751329165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row486209670165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1706897215165634"><a name="p1706897215165634"></a><a name="p1706897215165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789369948165634"><a name="p1789369948165634"></a><a name="p1789369948165634"></a>bool </p>
<p id="p619488081165634"><a name="p619488081165634"></a><a name="p619488081165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1235465229165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1590778468165634"><a name="p1590778468165634"></a><a name="p1590778468165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230105570165634"><a name="p1230105570165634"></a><a name="p1230105570165634"></a>void </p>
<p id="p888670502165634"><a name="p888670502165634"></a><a name="p888670502165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row627208093165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1506980018165634"><a name="p1506980018165634"></a><a name="p1506980018165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724588548165634"><a name="p724588548165634"></a><a name="p724588548165634"></a>bool </p>
<p id="p1654166472165634"><a name="p1654166472165634"></a><a name="p1654166472165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1283031039165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2050160545165634"><a name="p2050160545165634"></a><a name="p2050160545165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764982641165634"><a name="p1764982641165634"></a><a name="p1764982641165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1018682327165634"><a name="p1018682327165634"></a><a name="p1018682327165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row833641929165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p312205112165634"><a name="p312205112165634"></a><a name="p312205112165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1184222837165634"><a name="p1184222837165634"></a><a name="p1184222837165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1570100685165634"><a name="p1570100685165634"></a><a name="p1570100685165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1624007775165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087437444165634"><a name="p2087437444165634"></a><a name="p2087437444165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652298538165634"><a name="p652298538165634"></a><a name="p652298538165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1947474914165634"><a name="p1947474914165634"></a><a name="p1947474914165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row421304026165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p272656993165634"><a name="p272656993165634"></a><a name="p272656993165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p101424711165634"><a name="p101424711165634"></a><a name="p101424711165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1028991142165634"><a name="p1028991142165634"></a><a name="p1028991142165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row797365791165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1870519332165634"><a name="p1870519332165634"></a><a name="p1870519332165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175587710165634"><a name="p1175587710165634"></a><a name="p1175587710165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p625778181165634"><a name="p625778181165634"></a><a name="p625778181165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row87276654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567323839165634"><a name="p1567323839165634"></a><a name="p1567323839165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1565088883165634"><a name="p1565088883165634"></a><a name="p1565088883165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1365956146165634"><a name="p1365956146165634"></a><a name="p1365956146165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row583313127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1589000689165634"><a name="p1589000689165634"></a><a name="p1589000689165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449750526165634"><a name="p1449750526165634"></a><a name="p1449750526165634"></a>void </p>
<p id="p90656882165634"><a name="p90656882165634"></a><a name="p90656882165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row119130155165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1083615380165634"><a name="p1083615380165634"></a><a name="p1083615380165634"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1323286997165634"><a name="p1323286997165634"></a><a name="p1323286997165634"></a>virtual int16_t </p>
<p id="p1481198621165634"><a name="p1481198621165634"></a><a name="p1481198621165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1543123470165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1696006423165634"><a name="p1696006423165634"></a><a name="p1696006423165634"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1766524536165634"><a name="p1766524536165634"></a><a name="p1766524536165634"></a>virtual int16_t </p>
<p id="p358767333165634"><a name="p358767333165634"></a><a name="p358767333165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1682728663165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1901668031165634"><a name="p1901668031165634"></a><a name="p1901668031165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p463291686165634"><a name="p463291686165634"></a><a name="p463291686165634"></a>int16_t </p>
<p id="p1492352919165634"><a name="p1492352919165634"></a><a name="p1492352919165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row446897866165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821818398165634"><a name="p1821818398165634"></a><a name="p1821818398165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928808167165634"><a name="p1928808167165634"></a><a name="p1928808167165634"></a>int16_t </p>
<p id="p1388061733165634"><a name="p1388061733165634"></a><a name="p1388061733165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1148440251165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p373071455165634"><a name="p373071455165634"></a><a name="p373071455165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1982480100165634"><a name="p1982480100165634"></a><a name="p1982480100165634"></a>bool </p>
<p id="p135113150165634"><a name="p135113150165634"></a><a name="p135113150165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1444415944165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1668584537165634"><a name="p1668584537165634"></a><a name="p1668584537165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343931889165634"><a name="p1343931889165634"></a><a name="p1343931889165634"></a>void </p>
<p id="p1519159191165634"><a name="p1519159191165634"></a><a name="p1519159191165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row79671722165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118162859165634"><a name="p118162859165634"></a><a name="p118162859165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102752008165634"><a name="p1102752008165634"></a><a name="p1102752008165634"></a>void </p>
<p id="p1719957606165634"><a name="p1719957606165634"></a><a name="p1719957606165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row135833931165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1096350553165634"><a name="p1096350553165634"></a><a name="p1096350553165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675527222165634"><a name="p675527222165634"></a><a name="p675527222165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p1327756811165634"><a name="p1327756811165634"></a><a name="p1327756811165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1190078565165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049081041165634"><a name="p2049081041165634"></a><a name="p2049081041165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1468538834165634"><a name="p1468538834165634"></a><a name="p1468538834165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p617983457165634"><a name="p617983457165634"></a><a name="p617983457165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row544608307165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295792275165634"><a name="p295792275165634"></a><a name="p295792275165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876518367165634"><a name="p1876518367165634"></a><a name="p1876518367165634"></a>void </p>
<p id="p512270729165634"><a name="p512270729165634"></a><a name="p512270729165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row642036228165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p404234153165634"><a name="p404234153165634"></a><a name="p404234153165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p975689285165634"><a name="p975689285165634"></a><a name="p975689285165634"></a>const char * </p>
<p id="p298308011165634"><a name="p298308011165634"></a><a name="p298308011165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row266106339165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897389476165634"><a name="p1897389476165634"></a><a name="p1897389476165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206117129165634"><a name="p206117129165634"></a><a name="p206117129165634"></a>void </p>
<p id="p1190525942165634"><a name="p1190525942165634"></a><a name="p1190525942165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row561862236165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1356790716165634"><a name="p1356790716165634"></a><a name="p1356790716165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p756303704165634"><a name="p756303704165634"></a><a name="p756303704165634"></a>int16_t </p>
<p id="p1998063129165634"><a name="p1998063129165634"></a><a name="p1998063129165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row686368572165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856089379165634"><a name="p856089379165634"></a><a name="p856089379165634"></a><a href="graphic.md#ga6d23780da1faa1071197b716bca365e0">GetViewType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1079060835165634"><a name="p1079060835165634"></a><a name="p1079060835165634"></a>virtual UIViewType </p>
<p id="p2019297048165634"><a name="p2019297048165634"></a><a name="p2019297048165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row39245891165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133968383165634"><a name="p2133968383165634"></a><a name="p2133968383165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1378673069165634"><a name="p1378673069165634"></a><a name="p1378673069165634"></a>virtual void </p>
<p id="p1735020717165634"><a name="p1735020717165634"></a><a name="p1735020717165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1497137809165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p527453412165634"><a name="p527453412165634"></a><a name="p527453412165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034375195165634"><a name="p1034375195165634"></a><a name="p1034375195165634"></a>void </p>
<p id="p1760573112165634"><a name="p1760573112165634"></a><a name="p1760573112165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row832045183165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p706551768165634"><a name="p706551768165634"></a><a name="p706551768165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98843183165634"><a name="p98843183165634"></a><a name="p98843183165634"></a>void </p>
<p id="p177023982165634"><a name="p177023982165634"></a><a name="p177023982165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1778183695165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p7582775165634"><a name="p7582775165634"></a><a name="p7582775165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p673319703165634"><a name="p673319703165634"></a><a name="p673319703165634"></a>void </p>
<p id="p668543202165634"><a name="p668543202165634"></a><a name="p668543202165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row90242611165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603356798165634"><a name="p603356798165634"></a><a name="p603356798165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p582696121165634"><a name="p582696121165634"></a><a name="p582696121165634"></a>void </p>
<p id="p1919684350165634"><a name="p1919684350165634"></a><a name="p1919684350165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1007974142165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1585380038165634"><a name="p1585380038165634"></a><a name="p1585380038165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657701299165634"><a name="p1657701299165634"></a><a name="p1657701299165634"></a>void </p>
<p id="p445859319165634"><a name="p445859319165634"></a><a name="p445859319165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row526123136165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p68535060165634"><a name="p68535060165634"></a><a name="p68535060165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95858805165634"><a name="p95858805165634"></a><a name="p95858805165634"></a>void </p>
<p id="p1713801260165634"><a name="p1713801260165634"></a><a name="p1713801260165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row975647590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858315196165634"><a name="p1858315196165634"></a><a name="p1858315196165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900307732165634"><a name="p1900307732165634"></a><a name="p1900307732165634"></a>void </p>
<p id="p1495850421165634"><a name="p1495850421165634"></a><a name="p1495850421165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row979424179165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p523931278165634"><a name="p523931278165634"></a><a name="p523931278165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1347166643165634"><a name="p1347166643165634"></a><a name="p1347166643165634"></a>void </p>
<p id="p1209835639165634"><a name="p1209835639165634"></a><a name="p1209835639165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row343496795165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066915658165634"><a name="p2066915658165634"></a><a name="p2066915658165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117159667165634"><a name="p1117159667165634"></a><a name="p1117159667165634"></a>void </p>
<p id="p847550693165634"><a name="p847550693165634"></a><a name="p847550693165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row697704948165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1486662793165634"><a name="p1486662793165634"></a><a name="p1486662793165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p640066985165634"><a name="p640066985165634"></a><a name="p640066985165634"></a>void </p>
<p id="p1310628823165634"><a name="p1310628823165634"></a><a name="p1310628823165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1031588676165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p825388105165634"><a name="p825388105165634"></a><a name="p825388105165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320940097165634"><a name="p1320940097165634"></a><a name="p1320940097165634"></a>void </p>
<p id="p158025539165634"><a name="p158025539165634"></a><a name="p158025539165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row495455738165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641932335165634"><a name="p641932335165634"></a><a name="p641932335165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p660971742165634"><a name="p660971742165634"></a><a name="p660971742165634"></a>void </p>
<p id="p427572019165634"><a name="p427572019165634"></a><a name="p427572019165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1814106842165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p960562597165634"><a name="p960562597165634"></a><a name="p960562597165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669084487165634"><a name="p1669084487165634"></a><a name="p1669084487165634"></a>void </p>
<p id="p1771066745165634"><a name="p1771066745165634"></a><a name="p1771066745165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1287028894165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800150989165634"><a name="p800150989165634"></a><a name="p800150989165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804371694165634"><a name="p1804371694165634"></a><a name="p1804371694165634"></a>void </p>
<p id="p528191470165634"><a name="p528191470165634"></a><a name="p528191470165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row817169445165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105090177165634"><a name="p2105090177165634"></a><a name="p2105090177165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001693645165634"><a name="p1001693645165634"></a><a name="p1001693645165634"></a>void </p>
<p id="p1457006502165634"><a name="p1457006502165634"></a><a name="p1457006502165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row834001019165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828558654165634"><a name="p1828558654165634"></a><a name="p1828558654165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1069782962165634"><a name="p1069782962165634"></a><a name="p1069782962165634"></a>void </p>
<p id="p1908656113165634"><a name="p1908656113165634"></a><a name="p1908656113165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row2093491538165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186749511165634"><a name="p186749511165634"></a><a name="p186749511165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100232932165634"><a name="p100232932165634"></a><a name="p100232932165634"></a>virtual void </p>
<p id="p342235821165634"><a name="p342235821165634"></a><a name="p342235821165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row525198883165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1902282442165634"><a name="p1902282442165634"></a><a name="p1902282442165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2120403156165634"><a name="p2120403156165634"></a><a name="p2120403156165634"></a>virtual int64_t </p>
<p id="p957755574165634"><a name="p957755574165634"></a><a name="p957755574165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row921505620165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970676320165634"><a name="p1970676320165634"></a><a name="p1970676320165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p494317661165634"><a name="p494317661165634"></a><a name="p494317661165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p513889062165634"><a name="p513889062165634"></a><a name="p513889062165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1670940173165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117626751165634"><a name="p117626751165634"></a><a name="p117626751165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687342161165634"><a name="p1687342161165634"></a><a name="p1687342161165634"></a>void * </p>
<p id="p1524679642165634"><a name="p1524679642165634"></a><a name="p1524679642165634"></a>Overrides the <strong id="b785576102165634"><a name="b785576102165634"></a><a name="b785576102165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1973801641165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1067104882165634"><a name="p1067104882165634"></a><a name="p1067104882165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059351143165634"><a name="p2059351143165634"></a><a name="p2059351143165634"></a>void </p>
<p id="p1549558275165634"><a name="p1549558275165634"></a><a name="p1549558275165634"></a>Overrides the <strong id="b1423170918165634"><a name="b1423170918165634"></a><a name="b1423170918165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

