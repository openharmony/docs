# OHOS::UIScrollView<a name="ZH-CN_TOPIC_0000001055078165"></a>

-   [Overview](#section1047639352165634)
-   [Summary](#section263081741165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1047639352165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Supports horizontal or vertical scroll of child views. This class is inherited from  [UIAbstractScroll](OHOS-UIAbstractScroll.md). 

Horizontal or vertical scroll occurs only when the width or height of the child view is greater than that of the  **[UIScrollView](OHOS-UIScrollView.md)**.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section263081741165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1138916691165634"></a>
<table><thead align="left"><tr id="row1616923474165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1469420832165634"><a name="p1469420832165634"></a><a name="p1469420832165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p663782463165634"><a name="p663782463165634"></a><a name="p663782463165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2037626261165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066965285165634"><a name="p1066965285165634"></a><a name="p1066965285165634"></a><a href="OHOS-UIScrollView-OnScrollListener.md">OnScrollListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p132153172165634"><a name="p132153172165634"></a><a name="p132153172165634"></a>Represents a listener that contains a callback to be invoked upon scroll state changes. The state can either be <strong id="b1035762959165634"><a name="b1035762959165634"></a><a name="b1035762959165634"></a>SCROLL_STATE_STOP</strong> or <strong id="b1554195929165634"><a name="b1554195929165634"></a><a name="b1554195929165634"></a>SCROLL_STATE_MOVE</strong>. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table478478819165634"></a>
<table><thead align="left"><tr id="row1092802597165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p292586431165634"><a name="p292586431165634"></a><a name="p292586431165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1291634665165634"><a name="p1291634665165634"></a><a name="p1291634665165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row778482496165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066867089165634"><a name="p2066867089165634"></a><a name="p2066867089165634"></a><a href="Graphic.md#ga83285fe2d337f5d2242204e739e130ab">UIScrollView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307040413165634"><a name="p1307040413165634"></a><a name="p1307040413165634"></a> </p>
<p id="p701852224165634"><a name="p701852224165634"></a><a name="p701852224165634"></a>A constructor used to create a <strong id="b79682723165634"><a name="b79682723165634"></a><a name="b79682723165634"></a><a href="OHOS-UIScrollView.md">UIScrollView</a></strong> instance, with both horizontal and vertical scrolls supported. </p>
</td>
</tr>
<tr id="row613728514165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p159385031165634"><a name="p159385031165634"></a><a name="p159385031165634"></a><a href="Graphic.md#ga1b5f674824f5c27038329aa1223b137b">~UIScrollView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p541499360165634"><a name="p541499360165634"></a><a name="p541499360165634"></a>virtual </p>
<p id="p540316451165634"><a name="p540316451165634"></a><a name="p540316451165634"></a>A destructor used to delete the <strong id="b1855923926165634"><a name="b1855923926165634"></a><a name="b1855923926165634"></a><a href="OHOS-UIScrollView.md">UIScrollView</a></strong> instance. </p>
</td>
</tr>
<tr id="row279751959165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569995347165634"><a name="p1569995347165634"></a><a name="p1569995347165634"></a><a href="Graphic.md#ga1feefd393c568a12ec4e877e207d598c">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062855055165634"><a name="p2062855055165634"></a><a name="p2062855055165634"></a>UIViewType </p>
<p id="p1025451739165634"><a name="p1025451739165634"></a><a name="p1025451739165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row995633441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009085799165634"><a name="p1009085799165634"></a><a name="p1009085799165634"></a><a href="Graphic.md#ga8a7764e5a85e40b497a67fdf54a1b4c8">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45983508165634"><a name="p45983508165634"></a><a name="p45983508165634"></a>void </p>
<p id="p531443101165634"><a name="p531443101165634"></a><a name="p531443101165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row131423300165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811379297165634"><a name="p1811379297165634"></a><a name="p1811379297165634"></a><a href="Graphic.md#ga2fde4511d743ccc257308d9a0c035076">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p856621620165634"><a name="p856621620165634"></a><a name="p856621620165634"></a>bool </p>
<p id="p81407262165634"><a name="p81407262165634"></a><a name="p81407262165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row876578246165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111232019165634"><a name="p111232019165634"></a><a name="p111232019165634"></a><a href="Graphic.md#ga05e30354bc97373fbd30f8c045dbbeea">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198368450165634"><a name="p1198368450165634"></a><a name="p1198368450165634"></a>bool </p>
<p id="p1012768169165634"><a name="p1012768169165634"></a><a name="p1012768169165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row367888930165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p823490952165634"><a name="p823490952165634"></a><a name="p823490952165634"></a><a href="Graphic.md#ga54572308575db6d19997343c65d72fbb">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847531976165634"><a name="p847531976165634"></a><a name="p847531976165634"></a>void </p>
<p id="p255045844165634"><a name="p255045844165634"></a><a name="p255045844165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1645802081165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p31391740165634"><a name="p31391740165634"></a><a name="p31391740165634"></a><a href="Graphic.md#ga233e426fee2ff5b0973637bb3bf545ee">ScrollBy</a> (int16_t xDistance, int16_t yDistance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36430987165634"><a name="p36430987165634"></a><a name="p36430987165634"></a>void </p>
<p id="p1235082638165634"><a name="p1235082638165634"></a><a name="p1235082638165634"></a>Scrolls the content of this view. </p>
</td>
</tr>
<tr id="row766476368165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1512982717165634"><a name="p1512982717165634"></a><a name="p1512982717165634"></a><a href="Graphic.md#ga992fe30e6840d966688154ea96c362f4">SetScrollbarWidth</a> (uint8_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1227800840165634"><a name="p1227800840165634"></a><a name="p1227800840165634"></a>void </p>
<p id="p835562960165634"><a name="p835562960165634"></a><a name="p835562960165634"></a>Sets the width for this scroll bar. </p>
</td>
</tr>
<tr id="row1056496450165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824216171165634"><a name="p1824216171165634"></a><a name="p1824216171165634"></a><a href="Graphic.md#ga53a40f1c665fc7333e6aac156a1f5b81">SetHorizontalScrollState</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1682373105165634"><a name="p1682373105165634"></a><a name="p1682373105165634"></a>void </p>
<p id="p1110006100165634"><a name="p1110006100165634"></a><a name="p1110006100165634"></a>Sets whether a horizontal scroll is enabled. </p>
</td>
</tr>
<tr id="row70453779165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235720236165634"><a name="p1235720236165634"></a><a name="p1235720236165634"></a><a href="Graphic.md#ga0549786419ae52253f832a44cad91afe">GetHorizontalScrollState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1698126809165634"><a name="p1698126809165634"></a><a name="p1698126809165634"></a>bool </p>
<p id="p572162258165634"><a name="p572162258165634"></a><a name="p572162258165634"></a>Checks whether a horizontal scroll is enabled. </p>
</td>
</tr>
<tr id="row1222005258165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721557505165634"><a name="p1721557505165634"></a><a name="p1721557505165634"></a><a href="Graphic.md#ga8a6839614c863229666675c289a5cff4">SetVerticalScrollState</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p545762157165634"><a name="p545762157165634"></a><a name="p545762157165634"></a>void </p>
<p id="p1065876256165634"><a name="p1065876256165634"></a><a name="p1065876256165634"></a>Sets whether a vertical scroll is enabled. </p>
</td>
</tr>
<tr id="row1131510658165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405491750165634"><a name="p405491750165634"></a><a name="p405491750165634"></a><a href="Graphic.md#gac2095a64edba0fe0483a5475b11b45b2">GetVerticalScrollState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894458352165634"><a name="p1894458352165634"></a><a name="p1894458352165634"></a>bool </p>
<p id="p1852648320165634"><a name="p1852648320165634"></a><a name="p1852648320165634"></a>Checks whether a vertical scroll is enabled. </p>
</td>
</tr>
<tr id="row870955696165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p803200486165634"><a name="p803200486165634"></a><a name="p803200486165634"></a><a href="Graphic.md#ga011dae1414a147441e1d32d548545f24">SetXScrollBarVisible</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405700952165634"><a name="p1405700952165634"></a><a name="p1405700952165634"></a>void </p>
<p id="p1484470857165634"><a name="p1484470857165634"></a><a name="p1484470857165634"></a>Sets whether the horizontal scroll bar is visible. </p>
</td>
</tr>
<tr id="row1942083029165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061532231165634"><a name="p2061532231165634"></a><a name="p2061532231165634"></a><a href="Graphic.md#ga36fcdfce31fab72f54a37062d3f4a6f1">SetYScrollBarVisible</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382983377165634"><a name="p1382983377165634"></a><a name="p1382983377165634"></a>void </p>
<p id="p1554334842165634"><a name="p1554334842165634"></a><a name="p1554334842165634"></a>Sets whether the vertical scroll bar is visible. </p>
</td>
</tr>
<tr id="row494671598165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1085278419165634"><a name="p1085278419165634"></a><a name="p1085278419165634"></a><a href="Graphic.md#gad66c58c77db0dd0c507e45290ad5cd24">RegisterScrollListener</a> (<a href="OHOS-UIScrollView-OnScrollListener.md">OnScrollListener</a> *scrollListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368859976165634"><a name="p1368859976165634"></a><a name="p1368859976165634"></a>void </p>
<p id="p1696462123165634"><a name="p1696462123165634"></a><a name="p1696462123165634"></a>Registers a listener that contains a callback to be invoked upon scroll state changes. </p>
</td>
</tr>
<tr id="row986179986165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399707892165634"><a name="p399707892165634"></a><a name="p399707892165634"></a><a href="Graphic.md#ga93a169fba7c98f6534692cba9e8d539b">UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p389154500165634"><a name="p389154500165634"></a><a name="p389154500165634"></a> </p>
<p id="p325363937165634"><a name="p325363937165634"></a><a name="p325363937165634"></a>A constructor used to create a <strong id="b158349974165634"><a name="b158349974165634"></a><a name="b158349974165634"></a><a href="OHOS-UIAbstractScroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row928153112165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p769173156165634"><a name="p769173156165634"></a><a name="p769173156165634"></a><a href="Graphic.md#ga414798ec7357edc85409128fba0a813c">~UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621455615165634"><a name="p621455615165634"></a><a name="p621455615165634"></a>virtual </p>
<p id="p1646706911165634"><a name="p1646706911165634"></a><a name="p1646706911165634"></a>A destructor used to delete the <strong id="b1103959219165634"><a name="b1103959219165634"></a><a name="b1103959219165634"></a><a href="OHOS-UIAbstractScroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row1903369630165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p92886473165634"><a name="p92886473165634"></a><a name="p92886473165634"></a><a href="Graphic.md#ga443783170697bea9a933843ad2a92283">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894618629165634"><a name="p894618629165634"></a><a name="p894618629165634"></a>uint8_t </p>
<p id="p2000158001165634"><a name="p2000158001165634"></a><a name="p2000158001165634"></a>Obtains the scroll direction. </p>
</td>
</tr>
<tr id="row98392170165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1804892436165634"><a name="p1804892436165634"></a><a name="p1804892436165634"></a><a href="Graphic.md#gab37cea97d63ee9ca609c9a1ed0f1e281">SetScrollBlankSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435290549165634"><a name="p1435290549165634"></a><a name="p1435290549165634"></a>void </p>
<p id="p1398916164165634"><a name="p1398916164165634"></a><a name="p1398916164165634"></a>Sets the blank size for this scroll view. </p>
</td>
</tr>
<tr id="row56631285165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073593895165634"><a name="p1073593895165634"></a><a name="p1073593895165634"></a><a href="Graphic.md#gae2d6f5c97a316ecd3b41fecfa35a351f">SetMaxScrollDistance</a> (uint16_t distance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p830203340165634"><a name="p830203340165634"></a><a name="p830203340165634"></a>void </p>
<p id="p1930684423165634"><a name="p1930684423165634"></a><a name="p1930684423165634"></a>Sets the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row455410691165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605929903165634"><a name="p605929903165634"></a><a name="p605929903165634"></a><a href="Graphic.md#ga5d7fefcd2057e868a8f6c6a6000aa7ef">SetReboundSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455537861165634"><a name="p455537861165634"></a><a name="p455537861165634"></a>void </p>
<p id="p1606900378165634"><a name="p1606900378165634"></a><a name="p1606900378165634"></a>Sets the rebound size, which is the distance a knob moves after being released when it reaches the end of a scrollbar. </p>
</td>
</tr>
<tr id="row883807367165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1181676029165634"><a name="p1181676029165634"></a><a name="p1181676029165634"></a><a href="Graphic.md#ga71a2b17d4145479ed2e2ca000eb7e86e">GetMaxScrollDistance</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p831362330165634"><a name="p831362330165634"></a><a name="p831362330165634"></a>uint16_t </p>
<p id="p848958780165634"><a name="p848958780165634"></a><a name="p848958780165634"></a>Obtains the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row2003187376165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836864606165634"><a name="p836864606165634"></a><a name="p836864606165634"></a><a href="Graphic.md#ga957ec65a7efad6818be6df5169158aad">SetDragFunc</a> (EasingFunc func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140561338165634"><a name="p2140561338165634"></a><a name="p2140561338165634"></a>void </p>
<p id="p482699735165634"><a name="p482699735165634"></a><a name="p482699735165634"></a>Sets the easing function that specifies a scroll animation after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row672838678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1188867042165634"><a name="p1188867042165634"></a><a name="p1188867042165634"></a><a href="Graphic.md#ga4dde5f89d70304e77a96d4f4679438c2">SetThrowDrag</a> (bool throwDrag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p887655919165634"><a name="p887655919165634"></a><a name="p887655919165634"></a>void </p>
<p id="p117480308165634"><a name="p117480308165634"></a><a name="p117480308165634"></a>Sets whether to continue scrolling after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row2068280014165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36861889165634"><a name="p36861889165634"></a><a name="p36861889165634"></a><a href="Graphic.md#ga5013215d3075616ae081849ef52bb57a">MoveChildByOffset</a> (int16_t offsetX, int16_t offsetY) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645405444165634"><a name="p645405444165634"></a><a name="p645405444165634"></a>void </p>
<p id="p1697986716165634"><a name="p1697986716165634"></a><a name="p1697986716165634"></a>Moves the position of all child views. </p>
</td>
</tr>
<tr id="row1541836083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149300639165634"><a name="p1149300639165634"></a><a name="p1149300639165634"></a><a href="Graphic.md#gad344babd5b251ed908cdf628fae55093">SetDragACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1243398133165634"><a name="p1243398133165634"></a><a name="p1243398133165634"></a>void </p>
<p id="p25682828165634"><a name="p25682828165634"></a><a name="p25682828165634"></a>Sets the drag acceleration. </p>
</td>
</tr>
<tr id="row1273653922165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1680698404165634"><a name="p1680698404165634"></a><a name="p1680698404165634"></a><a href="Graphic.md#ga29e68195b56783f265d85506f130c664">GetDragACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640233155165634"><a name="p1640233155165634"></a><a name="p1640233155165634"></a>uint8_t </p>
<p id="p715938481165634"><a name="p715938481165634"></a><a name="p715938481165634"></a>Obtains the drag acceleration. </p>
</td>
</tr>
<tr id="row1975603832165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643102855165634"><a name="p1643102855165634"></a><a name="p1643102855165634"></a><a href="Graphic.md#gafab9d1a8f5987b50f9111c733ada6341">SetSwipeACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1792987478165634"><a name="p1792987478165634"></a><a name="p1792987478165634"></a>void </p>
<p id="p626390714165634"><a name="p626390714165634"></a><a name="p626390714165634"></a>Sets the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row932646065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58311220165634"><a name="p58311220165634"></a><a name="p58311220165634"></a><a href="Graphic.md#ga25dad3242949f0fbeff47d6df06053f6">GetSwipeACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1321828057165634"><a name="p1321828057165634"></a><a name="p1321828057165634"></a>uint8_t </p>
<p id="p680343584165634"><a name="p680343584165634"></a><a name="p680343584165634"></a>Obtains the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row108739351165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1190088491165634"><a name="p1190088491165634"></a><a name="p1190088491165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1888743514165634"><a name="p1888743514165634"></a><a name="p1888743514165634"></a> </p>
<p id="p890498576165634"><a name="p890498576165634"></a><a name="p890498576165634"></a>A default constructor used to create a <strong id="b83261555165634"><a name="b83261555165634"></a><a name="b83261555165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row551823875165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118848127165634"><a name="p1118848127165634"></a><a name="p1118848127165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621593848165634"><a name="p1621593848165634"></a><a name="p1621593848165634"></a>virtual </p>
<p id="p1467844448165634"><a name="p1467844448165634"></a><a name="p1467844448165634"></a>A destructor used to delete the <strong id="b1087320387165634"><a name="b1087320387165634"></a><a name="b1087320387165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row2114168759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p727315195165634"><a name="p727315195165634"></a><a name="p727315195165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125853910165634"><a name="p2125853910165634"></a><a name="p2125853910165634"></a>UIViewType </p>
<p id="p471040927165634"><a name="p471040927165634"></a><a name="p471040927165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row915121799165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p108364876165634"><a name="p108364876165634"></a><a name="p108364876165634"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p863108037165634"><a name="p863108037165634"></a><a name="p863108037165634"></a>virtual void </p>
<p id="p1411154192165634"><a name="p1411154192165634"></a><a name="p1411154192165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row2014077261165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2046948978165634"><a name="p2046948978165634"></a><a name="p2046948978165634"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p322325099165634"><a name="p322325099165634"></a><a name="p322325099165634"></a>virtual void </p>
<p id="p1508175532165634"><a name="p1508175532165634"></a><a name="p1508175532165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row2120315004165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1520822157165634"><a name="p1520822157165634"></a><a name="p1520822157165634"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95595479165634"><a name="p95595479165634"></a><a name="p95595479165634"></a>virtual void </p>
<p id="p315901381165634"><a name="p315901381165634"></a><a name="p315901381165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1238926628165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p292521860165634"><a name="p292521860165634"></a><a name="p292521860165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304826344165634"><a name="p304826344165634"></a><a name="p304826344165634"></a>virtual void </p>
<p id="p2032158049165634"><a name="p2032158049165634"></a><a name="p2032158049165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1058741621165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192878588165634"><a name="p1192878588165634"></a><a name="p1192878588165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319124322165634"><a name="p319124322165634"></a><a name="p319124322165634"></a>virtual void </p>
<p id="p2103618913165634"><a name="p2103618913165634"></a><a name="p2103618913165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row488098829165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1132154594165634"><a name="p1132154594165634"></a><a name="p1132154594165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533813496165634"><a name="p533813496165634"></a><a name="p533813496165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p175497525165634"><a name="p175497525165634"></a><a name="p175497525165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row530148665165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385870429165634"><a name="p385870429165634"></a><a name="p385870429165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p934113603165634"><a name="p934113603165634"></a><a name="p934113603165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p891158930165634"><a name="p891158930165634"></a><a name="p891158930165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row2126158861165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2027881486165634"><a name="p2027881486165634"></a><a name="p2027881486165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408087951165634"><a name="p1408087951165634"></a><a name="p1408087951165634"></a>void </p>
<p id="p161187570165634"><a name="p161187570165634"></a><a name="p161187570165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row584552724165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775862207165634"><a name="p1775862207165634"></a><a name="p1775862207165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553344464165634"><a name="p1553344464165634"></a><a name="p1553344464165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1667563001165634"><a name="p1667563001165634"></a><a name="p1667563001165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1631234130165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p609193552165634"><a name="p609193552165634"></a><a name="p609193552165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403090122165634"><a name="p403090122165634"></a><a name="p403090122165634"></a>void </p>
<p id="p1423766195165634"><a name="p1423766195165634"></a><a name="p1423766195165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1721836707165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1557324524165634"><a name="p1557324524165634"></a><a name="p1557324524165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2079184244165634"><a name="p2079184244165634"></a><a name="p2079184244165634"></a> </p>
<p id="p1846782228165634"><a name="p1846782228165634"></a><a name="p1846782228165634"></a>A default constructor used to create an <strong id="b1612229110165634"><a name="b1612229110165634"></a><a name="b1612229110165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1109820948165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1930599826165634"><a name="p1930599826165634"></a><a name="p1930599826165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067362618165634"><a name="p2067362618165634"></a><a name="p2067362618165634"></a> </p>
<p id="p1026197987165634"><a name="p1026197987165634"></a><a name="p1026197987165634"></a>A constructor used to create an <strong id="b465981124165634"><a name="b465981124165634"></a><a name="b465981124165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row24410836165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p260935178165634"><a name="p260935178165634"></a><a name="p260935178165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480374934165634"><a name="p480374934165634"></a><a name="p480374934165634"></a>virtual </p>
<p id="p124891418165634"><a name="p124891418165634"></a><a name="p124891418165634"></a>A destructor used to delete the <strong id="b83797097165634"><a name="b83797097165634"></a><a name="b83797097165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1181480301165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344359963165634"><a name="p1344359963165634"></a><a name="p1344359963165634"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661288683165634"><a name="p661288683165634"></a><a name="p661288683165634"></a>virtual bool </p>
<p id="p1578544378165634"><a name="p1578544378165634"></a><a name="p1578544378165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row445334335165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1318845979165634"><a name="p1318845979165634"></a><a name="p1318845979165634"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001064645165634"><a name="p2001064645165634"></a><a name="p2001064645165634"></a>virtual void </p>
<p id="p1882711398165634"><a name="p1882711398165634"></a><a name="p1882711398165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row2063211902165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861923094165634"><a name="p1861923094165634"></a><a name="p1861923094165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p930925619165634"><a name="p930925619165634"></a><a name="p930925619165634"></a>virtual void </p>
<p id="p1692779884165634"><a name="p1692779884165634"></a><a name="p1692779884165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1677432145165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010496957165634"><a name="p1010496957165634"></a><a name="p1010496957165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1080909081165634"><a name="p1080909081165634"></a><a name="p1080909081165634"></a>void </p>
<p id="p260651515165634"><a name="p260651515165634"></a><a name="p260651515165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row235717239165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604488261165634"><a name="p604488261165634"></a><a name="p604488261165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944500500165634"><a name="p1944500500165634"></a><a name="p1944500500165634"></a>void </p>
<p id="p848135933165634"><a name="p848135933165634"></a><a name="p848135933165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1369891143165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1432327953165634"><a name="p1432327953165634"></a><a name="p1432327953165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28491813165634"><a name="p28491813165634"></a><a name="p28491813165634"></a>virtual bool </p>
<p id="p1052308752165634"><a name="p1052308752165634"></a><a name="p1052308752165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1123513169165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393891571165634"><a name="p393891571165634"></a><a name="p393891571165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p539400820165634"><a name="p539400820165634"></a><a name="p539400820165634"></a>virtual bool </p>
<p id="p1460308869165634"><a name="p1460308869165634"></a><a name="p1460308869165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1135850489165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1516193028165634"><a name="p1516193028165634"></a><a name="p1516193028165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834117162165634"><a name="p834117162165634"></a><a name="p834117162165634"></a>virtual void </p>
<p id="p987910698165634"><a name="p987910698165634"></a><a name="p987910698165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row558900721165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466757018165634"><a name="p466757018165634"></a><a name="p466757018165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p638790491165634"><a name="p638790491165634"></a><a name="p638790491165634"></a>virtual void </p>
<p id="p1082875396165634"><a name="p1082875396165634"></a><a name="p1082875396165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row693870879165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p469452943165634"><a name="p469452943165634"></a><a name="p469452943165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967674357165634"><a name="p1967674357165634"></a><a name="p1967674357165634"></a>virtual void </p>
<p id="p626449512165634"><a name="p626449512165634"></a><a name="p626449512165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row119660076165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1256152785165634"><a name="p1256152785165634"></a><a name="p1256152785165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663141730165634"><a name="p1663141730165634"></a><a name="p1663141730165634"></a>void </p>
<p id="p1282271637165634"><a name="p1282271637165634"></a><a name="p1282271637165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1543383176165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137784115165634"><a name="p137784115165634"></a><a name="p137784115165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197436258165634"><a name="p1197436258165634"></a><a name="p1197436258165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p339985037165634"><a name="p339985037165634"></a><a name="p339985037165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1790286065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528014103165634"><a name="p1528014103165634"></a><a name="p1528014103165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185029685165634"><a name="p185029685165634"></a><a name="p185029685165634"></a>void </p>
<p id="p573387426165634"><a name="p573387426165634"></a><a name="p573387426165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1113523379165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p3681645165634"><a name="p3681645165634"></a><a name="p3681645165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688927954165634"><a name="p1688927954165634"></a><a name="p1688927954165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p536655924165634"><a name="p536655924165634"></a><a name="p536655924165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1442611413165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638705793165634"><a name="p1638705793165634"></a><a name="p1638705793165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p300008569165634"><a name="p300008569165634"></a><a name="p300008569165634"></a>void </p>
<p id="p698307998165634"><a name="p698307998165634"></a><a name="p698307998165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1055490754165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1126462246165634"><a name="p1126462246165634"></a><a name="p1126462246165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p456992230165634"><a name="p456992230165634"></a><a name="p456992230165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1008074123165634"><a name="p1008074123165634"></a><a name="p1008074123165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1321961509165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726283583165634"><a name="p1726283583165634"></a><a name="p1726283583165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1027466154165634"><a name="p1027466154165634"></a><a name="p1027466154165634"></a>void </p>
<p id="p1305739782165634"><a name="p1305739782165634"></a><a name="p1305739782165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row176439470165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p244009723165634"><a name="p244009723165634"></a><a name="p244009723165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1038590416165634"><a name="p1038590416165634"></a><a name="p1038590416165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p2671222165634"><a name="p2671222165634"></a><a name="p2671222165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1322348655165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616414920165634"><a name="p616414920165634"></a><a name="p616414920165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462010717165634"><a name="p1462010717165634"></a><a name="p1462010717165634"></a>void </p>
<p id="p1911879009165634"><a name="p1911879009165634"></a><a name="p1911879009165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1449716069165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33639345165634"><a name="p33639345165634"></a><a name="p33639345165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1476389836165634"><a name="p1476389836165634"></a><a name="p1476389836165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p44211465165634"><a name="p44211465165634"></a><a name="p44211465165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1370109833165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p817526621165634"><a name="p817526621165634"></a><a name="p817526621165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203445808165634"><a name="p1203445808165634"></a><a name="p1203445808165634"></a>void </p>
<p id="p999196134165634"><a name="p999196134165634"></a><a name="p999196134165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1258617411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p389674697165634"><a name="p389674697165634"></a><a name="p389674697165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289017279165634"><a name="p289017279165634"></a><a name="p289017279165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p193672719165634"><a name="p193672719165634"></a><a name="p193672719165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row554675345165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1429542177165634"><a name="p1429542177165634"></a><a name="p1429542177165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952945030165634"><a name="p1952945030165634"></a><a name="p1952945030165634"></a>virtual void </p>
<p id="p2010026228165634"><a name="p2010026228165634"></a><a name="p2010026228165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1369588121165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712195976165634"><a name="p1712195976165634"></a><a name="p1712195976165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185627804165634"><a name="p1185627804165634"></a><a name="p1185627804165634"></a>bool </p>
<p id="p728373935165634"><a name="p728373935165634"></a><a name="p728373935165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1728057228165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657506891165634"><a name="p657506891165634"></a><a name="p657506891165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p791948100165634"><a name="p791948100165634"></a><a name="p791948100165634"></a>void </p>
<p id="p320489544165634"><a name="p320489544165634"></a><a name="p320489544165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1812708838165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627943671165634"><a name="p1627943671165634"></a><a name="p1627943671165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085420662165634"><a name="p2085420662165634"></a><a name="p2085420662165634"></a>bool </p>
<p id="p951885102165634"><a name="p951885102165634"></a><a name="p951885102165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row788100969165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696869512165634"><a name="p696869512165634"></a><a name="p696869512165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591894277165634"><a name="p591894277165634"></a><a name="p591894277165634"></a>void </p>
<p id="p1972055002165634"><a name="p1972055002165634"></a><a name="p1972055002165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1526645773165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52656961165634"><a name="p52656961165634"></a><a name="p52656961165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p673936579165634"><a name="p673936579165634"></a><a name="p673936579165634"></a>bool </p>
<p id="p1329701205165634"><a name="p1329701205165634"></a><a name="p1329701205165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row588239558165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p325699168165634"><a name="p325699168165634"></a><a name="p325699168165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p40125475165634"><a name="p40125475165634"></a><a name="p40125475165634"></a>void </p>
<p id="p2134593160165634"><a name="p2134593160165634"></a><a name="p2134593160165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row536940007165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281083168165634"><a name="p1281083168165634"></a><a name="p1281083168165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39791626165634"><a name="p39791626165634"></a><a name="p39791626165634"></a>bool </p>
<p id="p604314550165634"><a name="p604314550165634"></a><a name="p604314550165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1162276280165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p963977373165634"><a name="p963977373165634"></a><a name="p963977373165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2015354194165634"><a name="p2015354194165634"></a><a name="p2015354194165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1858339876165634"><a name="p1858339876165634"></a><a name="p1858339876165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row543473882165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992246787165634"><a name="p992246787165634"></a><a name="p992246787165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948522769165634"><a name="p1948522769165634"></a><a name="p1948522769165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p738010082165634"><a name="p738010082165634"></a><a name="p738010082165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row94644853165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p303577500165634"><a name="p303577500165634"></a><a name="p303577500165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404091090165634"><a name="p404091090165634"></a><a name="p404091090165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p374647143165634"><a name="p374647143165634"></a><a name="p374647143165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row875926817165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616402654165634"><a name="p616402654165634"></a><a name="p616402654165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p606690332165634"><a name="p606690332165634"></a><a name="p606690332165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p322437979165634"><a name="p322437979165634"></a><a name="p322437979165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row445558199165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1328326796165634"><a name="p1328326796165634"></a><a name="p1328326796165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574419851165634"><a name="p1574419851165634"></a><a name="p1574419851165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p456074707165634"><a name="p456074707165634"></a><a name="p456074707165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row45732065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p123895514165634"><a name="p123895514165634"></a><a name="p123895514165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256747643165634"><a name="p1256747643165634"></a><a name="p1256747643165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p405590498165634"><a name="p405590498165634"></a><a name="p405590498165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1659274251165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2106881735165634"><a name="p2106881735165634"></a><a name="p2106881735165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762786941165634"><a name="p762786941165634"></a><a name="p762786941165634"></a>void </p>
<p id="p1390107616165634"><a name="p1390107616165634"></a><a name="p1390107616165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row269471593165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2138233820165634"><a name="p2138233820165634"></a><a name="p2138233820165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877867694165634"><a name="p1877867694165634"></a><a name="p1877867694165634"></a>virtual void </p>
<p id="p593833846165634"><a name="p593833846165634"></a><a name="p593833846165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row2112748715165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535207506165634"><a name="p1535207506165634"></a><a name="p1535207506165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1739224294165634"><a name="p1739224294165634"></a><a name="p1739224294165634"></a>virtual int16_t </p>
<p id="p538230330165634"><a name="p538230330165634"></a><a name="p538230330165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row194676501165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1463689674165634"><a name="p1463689674165634"></a><a name="p1463689674165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850414218165634"><a name="p1850414218165634"></a><a name="p1850414218165634"></a>virtual void </p>
<p id="p868383724165634"><a name="p868383724165634"></a><a name="p868383724165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row963354363165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411173178165634"><a name="p411173178165634"></a><a name="p411173178165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746044641165634"><a name="p1746044641165634"></a><a name="p1746044641165634"></a>virtual int16_t </p>
<p id="p1666123987165634"><a name="p1666123987165634"></a><a name="p1666123987165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1849069484165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669211286165634"><a name="p669211286165634"></a><a name="p669211286165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1269952584165634"><a name="p1269952584165634"></a><a name="p1269952584165634"></a>virtual void </p>
<p id="p1929432276165634"><a name="p1929432276165634"></a><a name="p1929432276165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1641559807165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1364989172165634"><a name="p1364989172165634"></a><a name="p1364989172165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031614923165634"><a name="p2031614923165634"></a><a name="p2031614923165634"></a>virtual void </p>
<p id="p139836019165634"><a name="p139836019165634"></a><a name="p139836019165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1021135327165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p539337418165634"><a name="p539337418165634"></a><a name="p539337418165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p819199395165634"><a name="p819199395165634"></a><a name="p819199395165634"></a>int16_t </p>
<p id="p304434781165634"><a name="p304434781165634"></a><a name="p304434781165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row244685822165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1798768585165634"><a name="p1798768585165634"></a><a name="p1798768585165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151638126165634"><a name="p1151638126165634"></a><a name="p1151638126165634"></a>virtual void </p>
<p id="p542350099165634"><a name="p542350099165634"></a><a name="p542350099165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row255937845165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1670307439165634"><a name="p1670307439165634"></a><a name="p1670307439165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1589542383165634"><a name="p1589542383165634"></a><a name="p1589542383165634"></a>int16_t </p>
<p id="p1234362605165634"><a name="p1234362605165634"></a><a name="p1234362605165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row709864082165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207100210165634"><a name="p1207100210165634"></a><a name="p1207100210165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1012358472165634"><a name="p1012358472165634"></a><a name="p1012358472165634"></a>virtual void </p>
<p id="p1263837051165634"><a name="p1263837051165634"></a><a name="p1263837051165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row845552543165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378159095165634"><a name="p1378159095165634"></a><a name="p1378159095165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p850787503165634"><a name="p850787503165634"></a><a name="p850787503165634"></a>virtual void </p>
<p id="p9389948165634"><a name="p9389948165634"></a><a name="p9389948165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1082087477165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671693860165634"><a name="p1671693860165634"></a><a name="p1671693860165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p586036099165634"><a name="p586036099165634"></a><a name="p586036099165634"></a>bool </p>
<p id="p1163586626165634"><a name="p1163586626165634"></a><a name="p1163586626165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row665138554165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443487812165634"><a name="p443487812165634"></a><a name="p443487812165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p972062562165634"><a name="p972062562165634"></a><a name="p972062562165634"></a>void </p>
<p id="p2076228215165634"><a name="p2076228215165634"></a><a name="p2076228215165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row702062573165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1945015478165634"><a name="p1945015478165634"></a><a name="p1945015478165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324271326165634"><a name="p1324271326165634"></a><a name="p1324271326165634"></a>void </p>
<p id="p742080428165634"><a name="p742080428165634"></a><a name="p742080428165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1067401128165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p662392555165634"><a name="p662392555165634"></a><a name="p662392555165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724635605165634"><a name="p724635605165634"></a><a name="p724635605165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1402740511165634"><a name="p1402740511165634"></a><a name="p1402740511165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row387255456165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1307116729165634"><a name="p1307116729165634"></a><a name="p1307116729165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p128457180165634"><a name="p128457180165634"></a><a name="p128457180165634"></a>void </p>
<p id="p193848224165634"><a name="p193848224165634"></a><a name="p193848224165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row162370075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603322265165634"><a name="p603322265165634"></a><a name="p603322265165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p597283638165634"><a name="p597283638165634"></a><a name="p597283638165634"></a>const char * </p>
<p id="p900681518165634"><a name="p900681518165634"></a><a name="p900681518165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1133936990165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2130491012165634"><a name="p2130491012165634"></a><a name="p2130491012165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428420014165634"><a name="p1428420014165634"></a><a name="p1428420014165634"></a>void </p>
<p id="p1579326641165634"><a name="p1579326641165634"></a><a name="p1579326641165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row2094737080165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1366923040165634"><a name="p1366923040165634"></a><a name="p1366923040165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p444514380165634"><a name="p444514380165634"></a><a name="p444514380165634"></a>int16_t </p>
<p id="p893120148165634"><a name="p893120148165634"></a><a name="p893120148165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row2037969359165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p514363676165634"><a name="p514363676165634"></a><a name="p514363676165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1041338181165634"><a name="p1041338181165634"></a><a name="p1041338181165634"></a>virtual void </p>
<p id="p409974506165634"><a name="p409974506165634"></a><a name="p409974506165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1911870687165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p484750606165634"><a name="p484750606165634"></a><a name="p484750606165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572905610165634"><a name="p1572905610165634"></a><a name="p1572905610165634"></a>void </p>
<p id="p18268455165634"><a name="p18268455165634"></a><a name="p18268455165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1561551046165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1545634892165634"><a name="p1545634892165634"></a><a name="p1545634892165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914554669165634"><a name="p914554669165634"></a><a name="p914554669165634"></a>void </p>
<p id="p1650999909165634"><a name="p1650999909165634"></a><a name="p1650999909165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1741779451165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031790014165634"><a name="p1031790014165634"></a><a name="p1031790014165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66372743165634"><a name="p66372743165634"></a><a name="p66372743165634"></a>void </p>
<p id="p92629157165634"><a name="p92629157165634"></a><a name="p92629157165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row603210525165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1363523901165634"><a name="p1363523901165634"></a><a name="p1363523901165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2145260266165634"><a name="p2145260266165634"></a><a name="p2145260266165634"></a>void </p>
<p id="p1004031448165634"><a name="p1004031448165634"></a><a name="p1004031448165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row430882723165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p404490270165634"><a name="p404490270165634"></a><a name="p404490270165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653882380165634"><a name="p1653882380165634"></a><a name="p1653882380165634"></a>void </p>
<p id="p451260141165634"><a name="p451260141165634"></a><a name="p451260141165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row708543187165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1099108219165634"><a name="p1099108219165634"></a><a name="p1099108219165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521610888165634"><a name="p521610888165634"></a><a name="p521610888165634"></a>void </p>
<p id="p749382342165634"><a name="p749382342165634"></a><a name="p749382342165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row2138801569165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1672575245165634"><a name="p1672575245165634"></a><a name="p1672575245165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p700497892165634"><a name="p700497892165634"></a><a name="p700497892165634"></a>void </p>
<p id="p1678345504165634"><a name="p1678345504165634"></a><a name="p1678345504165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row2133342378165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p47723656165634"><a name="p47723656165634"></a><a name="p47723656165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p447961688165634"><a name="p447961688165634"></a><a name="p447961688165634"></a>void </p>
<p id="p1516502938165634"><a name="p1516502938165634"></a><a name="p1516502938165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1193636852165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764949583165634"><a name="p764949583165634"></a><a name="p764949583165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879340636165634"><a name="p879340636165634"></a><a name="p879340636165634"></a>void </p>
<p id="p1089304559165634"><a name="p1089304559165634"></a><a name="p1089304559165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1263775308165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p952659343165634"><a name="p952659343165634"></a><a name="p952659343165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394037194165634"><a name="p1394037194165634"></a><a name="p1394037194165634"></a>void </p>
<p id="p325349962165634"><a name="p325349962165634"></a><a name="p325349962165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row875874103165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491295778165634"><a name="p491295778165634"></a><a name="p491295778165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479333024165634"><a name="p479333024165634"></a><a name="p479333024165634"></a>void </p>
<p id="p919714279165634"><a name="p919714279165634"></a><a name="p919714279165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1231386421165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476784078165634"><a name="p1476784078165634"></a><a name="p1476784078165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610651588165634"><a name="p610651588165634"></a><a name="p610651588165634"></a>void </p>
<p id="p1993169373165634"><a name="p1993169373165634"></a><a name="p1993169373165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row353419874165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705074120165634"><a name="p705074120165634"></a><a name="p705074120165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p272584788165634"><a name="p272584788165634"></a><a name="p272584788165634"></a>void </p>
<p id="p45122806165634"><a name="p45122806165634"></a><a name="p45122806165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row490111355165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1507175472165634"><a name="p1507175472165634"></a><a name="p1507175472165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1122004175165634"><a name="p1122004175165634"></a><a name="p1122004175165634"></a>void </p>
<p id="p1616018684165634"><a name="p1616018684165634"></a><a name="p1616018684165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row969748437165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563586045165634"><a name="p563586045165634"></a><a name="p563586045165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290315554165634"><a name="p290315554165634"></a><a name="p290315554165634"></a>void </p>
<p id="p7485387165634"><a name="p7485387165634"></a><a name="p7485387165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row305160710165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p22445060165634"><a name="p22445060165634"></a><a name="p22445060165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635884004165634"><a name="p1635884004165634"></a><a name="p1635884004165634"></a>void </p>
<p id="p1630818185165634"><a name="p1630818185165634"></a><a name="p1630818185165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row453217897165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1353211875165634"><a name="p1353211875165634"></a><a name="p1353211875165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p256207961165634"><a name="p256207961165634"></a><a name="p256207961165634"></a>virtual void </p>
<p id="p1197046851165634"><a name="p1197046851165634"></a><a name="p1197046851165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row524670604165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1052614692165634"><a name="p1052614692165634"></a><a name="p1052614692165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p284292891165634"><a name="p284292891165634"></a><a name="p284292891165634"></a>virtual int64_t </p>
<p id="p2088193753165634"><a name="p2088193753165634"></a><a name="p2088193753165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row847288719165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065178434165634"><a name="p2065178434165634"></a><a name="p2065178434165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797320314165634"><a name="p1797320314165634"></a><a name="p1797320314165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p286148183165634"><a name="p286148183165634"></a><a name="p286148183165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1641600816165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830305650165634"><a name="p1830305650165634"></a><a name="p1830305650165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062208312165634"><a name="p2062208312165634"></a><a name="p2062208312165634"></a>void * </p>
<p id="p2098662098165634"><a name="p2098662098165634"></a><a name="p2098662098165634"></a>Overrides the <strong id="b103940762165634"><a name="b103940762165634"></a><a name="b103940762165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1565498715165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781024806165634"><a name="p1781024806165634"></a><a name="p1781024806165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1545865734165634"><a name="p1545865734165634"></a><a name="p1545865734165634"></a>void </p>
<p id="p1045791069165634"><a name="p1045791069165634"></a><a name="p1045791069165634"></a>Overrides the <strong id="b1265841411165634"><a name="b1265841411165634"></a><a name="b1265841411165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1535413616165634"></a>
<table><thead align="left"><tr id="row492193622165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1951129969165634"><a name="p1951129969165634"></a><a name="p1951129969165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p185460518165634"><a name="p185460518165634"></a><a name="p185460518165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row323605199165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1637062364165634"><a name="p1637062364165634"></a><a name="p1637062364165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091299248165634"><a name="p1091299248165634"></a><a name="p1091299248165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row319462726165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74120168165634"><a name="p74120168165634"></a><a name="p74120168165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320898925165634"><a name="p1320898925165634"></a><a name="p1320898925165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row861617654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345447738165634"><a name="p1345447738165634"></a><a name="p1345447738165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457965757165634"><a name="p457965757165634"></a><a name="p457965757165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row505220165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720355450165634"><a name="p1720355450165634"></a><a name="p1720355450165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421048346165634"><a name="p1421048346165634"></a><a name="p1421048346165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1482574739165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p908369045165634"><a name="p908369045165634"></a><a name="p908369045165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024174596165634"><a name="p2024174596165634"></a><a name="p2024174596165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row345201497165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p285990637165634"><a name="p285990637165634"></a><a name="p285990637165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304521297165634"><a name="p1304521297165634"></a><a name="p1304521297165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row2097295774165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674505237165634"><a name="p674505237165634"></a><a name="p674505237165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351456007165634"><a name="p1351456007165634"></a><a name="p1351456007165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

