# OHOS::UIList<a name="EN-US_TOPIC_0000001054799625"></a>

-   [Overview](#section412399980165634)
-   [Summary](#section301810272165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section412399980165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a scrollable list which is used with the adapter  [AbstractAdapter](ohos-abstractadapter.md)  to implement scrolling, inertial scrolling, automatic alignment, and invoking of a callback when a child view is selected at the preset position as this list scrolls. 

You need to override  [AbstractAdapter](ohos-abstractadapter.md)  to implement functions for setting and saving data, obtaining data quantity, and creating child views.  **[UIList](ohos-uilist.md)**  is used when there is a large number of child views with a fixed format. This list automatically reclaims the child views removed out of the current view as it scrolls so that as many as child views can be displayed with a lower memory consumption.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section301810272165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table2092789389165634"></a>
<table><thead align="left"><tr id="row1894853343165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p194385411165634"><a name="p194385411165634"></a><a name="p194385411165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p206797954165634"><a name="p206797954165634"></a><a name="p206797954165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1032117291165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1871122009165634"><a name="p1871122009165634"></a><a name="p1871122009165634"></a><a href="graphic.md#ga56c15f8c21c433c8a08a151e33b521cf">UIList</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050530276165634"><a name="p2050530276165634"></a><a name="p2050530276165634"></a> </p>
<p id="p473133264165634"><a name="p473133264165634"></a><a name="p473133264165634"></a>A constructor used to create a <strong id="b2010733098165634"><a name="b2010733098165634"></a><a name="b2010733098165634"></a><a href="ohos-uilist.md">UIList</a></strong> instance in the vertical direction. </p>
</td>
</tr>
<tr id="row1872450360165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047424041165634"><a name="p2047424041165634"></a><a name="p2047424041165634"></a><a href="graphic.md#ga2da1983fedabd5ea06a8a544aeb2cf04">UIList</a> (uint8_t direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p796898277165634"><a name="p796898277165634"></a><a name="p796898277165634"></a> </p>
<p id="p2123074826165634"><a name="p2123074826165634"></a><a name="p2123074826165634"></a>A constructor used to create a <strong id="b683786577165634"><a name="b683786577165634"></a><a name="b683786577165634"></a><a href="ohos-uilist.md">UIList</a></strong> instance in the specified direction. </p>
</td>
</tr>
<tr id="row224597028165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638659401165634"><a name="p638659401165634"></a><a name="p638659401165634"></a><a href="graphic.md#ga84de0a8214747d118abfd3d1185ffa63">~UIList</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415017875165634"><a name="p1415017875165634"></a><a name="p1415017875165634"></a>virtual </p>
<p id="p407342031165634"><a name="p407342031165634"></a><a name="p407342031165634"></a>A destructor used to delete the <strong id="b880603311165634"><a name="b880603311165634"></a><a name="b880603311165634"></a><a href="ohos-uilist.md">UIList</a></strong> instance. </p>
</td>
</tr>
<tr id="row389116171165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550503140165634"><a name="p1550503140165634"></a><a name="p1550503140165634"></a><a href="graphic.md#ga6e11e5de67f87ed6cf6c44f60b7d4096">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639348006165634"><a name="p639348006165634"></a><a name="p639348006165634"></a>UIViewType </p>
<p id="p1772309584165634"><a name="p1772309584165634"></a><a name="p1772309584165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1538611467165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2012858332165634"><a name="p2012858332165634"></a><a name="p2012858332165634"></a><a href="graphic.md#ga7e99d1fb891879195c19c211c6de6600">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1914582227165634"><a name="p1914582227165634"></a><a name="p1914582227165634"></a>bool </p>
<p id="p1165578575165634"><a name="p1165578575165634"></a><a name="p1165578575165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1029881184165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041352128165634"><a name="p2041352128165634"></a><a name="p2041352128165634"></a><a href="graphic.md#ga225e59d60271c9012a017136d2aab0d6">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405081922165634"><a name="p1405081922165634"></a><a name="p1405081922165634"></a>bool </p>
<p id="p1347527304165634"><a name="p1347527304165634"></a><a name="p1347527304165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row596148679165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p134671298165634"><a name="p134671298165634"></a><a name="p134671298165634"></a><a href="graphic.md#gaa6ba86e78d4a12ea47b6aaa8dd88f882">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p500049143165634"><a name="p500049143165634"></a><a name="p500049143165634"></a>void </p>
<p id="p1029455271165634"><a name="p1029455271165634"></a><a name="p1029455271165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row678146635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443139229165634"><a name="p443139229165634"></a><a name="p443139229165634"></a><a href="graphic.md#gaa44fd515481de0f1de5d20a62be63267">SetAdapter</a> (<a href="ohos-abstractadapter.md">AbstractAdapter</a> *adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726221974165634"><a name="p1726221974165634"></a><a name="p1726221974165634"></a>void </p>
<p id="p351571142165634"><a name="p351571142165634"></a><a name="p351571142165634"></a>Sets the adapter for this list. The content of this list is initialized when the adapter is set. </p>
</td>
</tr>
<tr id="row726588604165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p848108333165634"><a name="p848108333165634"></a><a name="p848108333165634"></a><a href="graphic.md#gafe121e0cc150122486049dcaf83f3c26">MoveChildByOffset</a> (int16_t x, int16_t y) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307703501165634"><a name="p1307703501165634"></a><a name="p1307703501165634"></a>virtual void </p>
<p id="p1464299135165634"><a name="p1464299135165634"></a><a name="p1464299135165634"></a>Moves the position of all child views. </p>
</td>
</tr>
<tr id="row1689099430165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1216024128165634"><a name="p1216024128165634"></a><a name="p1216024128165634"></a><a href="graphic.md#ga9a760e34ff783d738d414d26af3903e5">ScrollTo</a> (uint16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503328486165634"><a name="p1503328486165634"></a><a name="p1503328486165634"></a>void </p>
<p id="p806048573165634"><a name="p806048573165634"></a><a name="p806048573165634"></a>Scrolls to change the index of the first row or column of the current view. </p>
</td>
</tr>
<tr id="row343552559165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1992745478165634"><a name="p1992745478165634"></a><a name="p1992745478165634"></a><a href="graphic.md#gaf97d599fe1147a71e44a5a107edeac77">ScrollBy</a> (int16_t distance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036507602165634"><a name="p1036507602165634"></a><a name="p1036507602165634"></a>void </p>
<p id="p1938475105165634"><a name="p1938475105165634"></a><a name="p1938475105165634"></a>Scrolls the content in this list. </p>
</td>
</tr>
<tr id="row89077091165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093970090165634"><a name="p1093970090165634"></a><a name="p1093970090165634"></a><a href="graphic.md#gaa8023e5c4e0688841263d0f576e76218">SetStartIndex</a> (uint16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667913394165634"><a name="p667913394165634"></a><a name="p667913394165634"></a>void </p>
<p id="p764055792165634"><a name="p764055792165634"></a><a name="p764055792165634"></a>Sets the start index for this list. </p>
</td>
</tr>
<tr id="row2083467336165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1974834482165634"><a name="p1974834482165634"></a><a name="p1974834482165634"></a><a href="graphic.md#ga0ce3080df2c5226d20d446bc9c28b694">GetStartIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p503239206165634"><a name="p503239206165634"></a><a name="p503239206165634"></a>uint16_t </p>
<p id="p1193025689165634"><a name="p1193025689165634"></a><a name="p1193025689165634"></a>Obtains the start index of this list. The default value is <strong id="b590409318165634"><a name="b590409318165634"></a><a name="b590409318165634"></a>0</strong>. </p>
</td>
</tr>
<tr id="row79170614165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p258159967165634"><a name="p258159967165634"></a><a name="p258159967165634"></a><a href="graphic.md#gaa07b156ab757cd20486ec0bcbf4c17ac">SetLoopState</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1587968433165634"><a name="p1587968433165634"></a><a name="p1587968433165634"></a>void </p>
<p id="p1584024682165634"><a name="p1584024682165634"></a><a name="p1584024682165634"></a>Sets the loop state for this list, in which a loop scroll is possible since the top and bottom of the list are connected together. </p>
</td>
</tr>
<tr id="row1395039225165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1760509903165634"><a name="p1760509903165634"></a><a name="p1760509903165634"></a><a href="graphic.md#ga78d73f33cc63d0121342f52a818881d5">GetLoopState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372195588165634"><a name="p1372195588165634"></a><a name="p1372195588165634"></a>bool </p>
<p id="p381624528165634"><a name="p381624528165634"></a><a name="p381624528165634"></a>Checks whether this list is in a loop state. </p>
</td>
</tr>
<tr id="row361621597165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397473254165634"><a name="p397473254165634"></a><a name="p397473254165634"></a><a href="graphic.md#ga919b4f3116ca0d0971a48b7a14921954">SetSelectPosition</a> (uint16_t position)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p472562669165634"><a name="p472562669165634"></a><a name="p472562669165634"></a>void </p>
<p id="p2042146635165634"><a name="p2042146635165634"></a><a name="p2042146635165634"></a>Sets the position where a child view is selected as this list scrolls. </p>
</td>
</tr>
<tr id="row670731477165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p174483668165634"><a name="p174483668165634"></a><a name="p174483668165634"></a><a href="graphic.md#ga199fdcf3ef797e5f61073a4be3b06642">GetSelectView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p726606098165634"><a name="p726606098165634"></a><a name="p726606098165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1168000862165634"><a name="p1168000862165634"></a><a name="p1168000862165634"></a>Obtains the child view being selected at the preset position. </p>
</td>
</tr>
<tr id="row2111910453165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2844760165634"><a name="p2844760165634"></a><a name="p2844760165634"></a><a href="graphic.md#gad6b2f7598033f4e1d0d73e30b0e41f02">SetScrollStateListener</a> (<a href="ohos-listscrolllistener.md">ListScrollListener</a> *scrollListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623834946165634"><a name="p623834946165634"></a><a name="p623834946165634"></a>void </p>
<p id="p66521530165634"><a name="p66521530165634"></a><a name="p66521530165634"></a>Sets the listener that contains a callback to be invoked when a child view is selected as this list scrolls. </p>
</td>
</tr>
<tr id="row2110932685165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066520996165634"><a name="p1066520996165634"></a><a name="p1066520996165634"></a><a href="graphic.md#gaf2aabfa8e8edd803d034c23efe45f57b">RefreshList</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p584875643165634"><a name="p584875643165634"></a><a name="p584875643165634"></a>void </p>
<p id="p1004405050165634"><a name="p1004405050165634"></a><a name="p1004405050165634"></a>Refreshes this list. The number of child views in the current view is fixed and the positions of those reserved child views as this list scrolls remain unchanged. </p>
</td>
</tr>
<tr id="row1079960641165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1701064749165634"><a name="p1701064749165634"></a><a name="p1701064749165634"></a><a href="graphic.md#ga034799920648552008146a0d9aca3424">EnableAutoAlign</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1186513723165634"><a name="p1186513723165634"></a><a name="p1186513723165634"></a>void </p>
<p id="p1362049122165634"><a name="p1362049122165634"></a><a name="p1362049122165634"></a>Sets the automatic alignment state for this list. When a scroll stops, a child view is selected and its position is automatically aligned with the preset position. </p>
</td>
</tr>
<tr id="row1501642690165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p31565829165634"><a name="p31565829165634"></a><a name="p31565829165634"></a><a href="graphic.md#gaa55aae2e8066fecc5941e021a7f30d7e">RemoveAll</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p140920186165634"><a name="p140920186165634"></a><a name="p140920186165634"></a>void </p>
<p id="p1754829153165634"><a name="p1754829153165634"></a><a name="p1754829153165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row2003279217165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564557673165634"><a name="p564557673165634"></a><a name="p564557673165634"></a><a href="graphic.md#ga93a169fba7c98f6534692cba9e8d539b">UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580184211165634"><a name="p1580184211165634"></a><a name="p1580184211165634"></a> </p>
<p id="p1216654404165634"><a name="p1216654404165634"></a><a name="p1216654404165634"></a>A constructor used to create a <strong id="b1257692761165634"><a name="b1257692761165634"></a><a name="b1257692761165634"></a><a href="ohos-uiabstractscroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row949715683165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247645375165634"><a name="p247645375165634"></a><a name="p247645375165634"></a><a href="graphic.md#ga414798ec7357edc85409128fba0a813c">~UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2038171870165634"><a name="p2038171870165634"></a><a name="p2038171870165634"></a>virtual </p>
<p id="p1009656608165634"><a name="p1009656608165634"></a><a name="p1009656608165634"></a>A destructor used to delete the <strong id="b924103818165634"><a name="b924103818165634"></a><a name="b924103818165634"></a><a href="ohos-uiabstractscroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row3515445165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p490273934165634"><a name="p490273934165634"></a><a name="p490273934165634"></a><a href="graphic.md#ga443783170697bea9a933843ad2a92283">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393471134165634"><a name="p1393471134165634"></a><a name="p1393471134165634"></a>uint8_t </p>
<p id="p2026756879165634"><a name="p2026756879165634"></a><a name="p2026756879165634"></a>Obtains the scroll direction. </p>
</td>
</tr>
<tr id="row1579048129165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1164407334165634"><a name="p1164407334165634"></a><a name="p1164407334165634"></a><a href="graphic.md#gab37cea97d63ee9ca609c9a1ed0f1e281">SetScrollBlankSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p316178685165634"><a name="p316178685165634"></a><a name="p316178685165634"></a>void </p>
<p id="p1410766700165634"><a name="p1410766700165634"></a><a name="p1410766700165634"></a>Sets the blank size for this scroll view. </p>
</td>
</tr>
<tr id="row1832223058165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410413902165634"><a name="p1410413902165634"></a><a name="p1410413902165634"></a><a href="graphic.md#gae2d6f5c97a316ecd3b41fecfa35a351f">SetMaxScrollDistance</a> (uint16_t distance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519578827165634"><a name="p519578827165634"></a><a name="p519578827165634"></a>void </p>
<p id="p1171776303165634"><a name="p1171776303165634"></a><a name="p1171776303165634"></a>Sets the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1089790314165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1187185094165634"><a name="p1187185094165634"></a><a name="p1187185094165634"></a><a href="graphic.md#ga5d7fefcd2057e868a8f6c6a6000aa7ef">SetReboundSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782826447165634"><a name="p782826447165634"></a><a name="p782826447165634"></a>void </p>
<p id="p1526234692165634"><a name="p1526234692165634"></a><a name="p1526234692165634"></a>Sets the rebound size, which is the distance a knob moves after being released when it reaches the end of a scrollbar. </p>
</td>
</tr>
<tr id="row1097301353165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265039763165634"><a name="p1265039763165634"></a><a name="p1265039763165634"></a><a href="graphic.md#ga71a2b17d4145479ed2e2ca000eb7e86e">GetMaxScrollDistance</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p545955166165634"><a name="p545955166165634"></a><a name="p545955166165634"></a>uint16_t </p>
<p id="p2107389926165634"><a name="p2107389926165634"></a><a name="p2107389926165634"></a>Obtains the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row791570339165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080856889165634"><a name="p2080856889165634"></a><a name="p2080856889165634"></a><a href="graphic.md#ga957ec65a7efad6818be6df5169158aad">SetDragFunc</a> (EasingFunc func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823983976165634"><a name="p1823983976165634"></a><a name="p1823983976165634"></a>void </p>
<p id="p1652455070165634"><a name="p1652455070165634"></a><a name="p1652455070165634"></a>Sets the easing function that specifies a scroll animation after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1019651601165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1428099612165634"><a name="p1428099612165634"></a><a name="p1428099612165634"></a><a href="graphic.md#ga4dde5f89d70304e77a96d4f4679438c2">SetThrowDrag</a> (bool throwDrag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p863916151165634"><a name="p863916151165634"></a><a name="p863916151165634"></a>void </p>
<p id="p1668894970165634"><a name="p1668894970165634"></a><a name="p1668894970165634"></a>Sets whether to continue scrolling after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row923536627165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1583061149165634"><a name="p1583061149165634"></a><a name="p1583061149165634"></a><a href="graphic.md#gad344babd5b251ed908cdf628fae55093">SetDragACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134472177165634"><a name="p1134472177165634"></a><a name="p1134472177165634"></a>void </p>
<p id="p929778284165634"><a name="p929778284165634"></a><a name="p929778284165634"></a>Sets the drag acceleration. </p>
</td>
</tr>
<tr id="row102100213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614264571165634"><a name="p614264571165634"></a><a name="p614264571165634"></a><a href="graphic.md#ga29e68195b56783f265d85506f130c664">GetDragACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p279223794165634"><a name="p279223794165634"></a><a name="p279223794165634"></a>uint8_t </p>
<p id="p200486384165634"><a name="p200486384165634"></a><a name="p200486384165634"></a>Obtains the drag acceleration. </p>
</td>
</tr>
<tr id="row696400885165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p195203932165634"><a name="p195203932165634"></a><a name="p195203932165634"></a><a href="graphic.md#gafab9d1a8f5987b50f9111c733ada6341">SetSwipeACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1038501776165634"><a name="p1038501776165634"></a><a name="p1038501776165634"></a>void </p>
<p id="p149570309165634"><a name="p149570309165634"></a><a name="p149570309165634"></a>Sets the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row445491126165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p622786796165634"><a name="p622786796165634"></a><a name="p622786796165634"></a><a href="graphic.md#ga25dad3242949f0fbeff47d6df06053f6">GetSwipeACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1306998304165634"><a name="p1306998304165634"></a><a name="p1306998304165634"></a>uint8_t </p>
<p id="p1303751909165634"><a name="p1303751909165634"></a><a name="p1303751909165634"></a>Obtains the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row707843586165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009198498165634"><a name="p1009198498165634"></a><a name="p1009198498165634"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559079021165634"><a name="p1559079021165634"></a><a name="p1559079021165634"></a> </p>
<p id="p719189452165634"><a name="p719189452165634"></a><a name="p719189452165634"></a>A default constructor used to create a <strong id="b705472260165634"><a name="b705472260165634"></a><a name="b705472260165634"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1122068589165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p819653405165634"><a name="p819653405165634"></a><a name="p819653405165634"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801476012165634"><a name="p1801476012165634"></a><a name="p1801476012165634"></a>virtual </p>
<p id="p1355922612165634"><a name="p1355922612165634"></a><a name="p1355922612165634"></a>A destructor used to delete the <strong id="b2114708701165634"><a name="b2114708701165634"></a><a name="b2114708701165634"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row48060793165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376736061165634"><a name="p376736061165634"></a><a name="p376736061165634"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301205829165634"><a name="p1301205829165634"></a><a name="p1301205829165634"></a>UIViewType </p>
<p id="p1215337401165634"><a name="p1215337401165634"></a><a name="p1215337401165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1114989233165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1036475013165634"><a name="p1036475013165634"></a><a name="p1036475013165634"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p971033849165634"><a name="p971033849165634"></a><a name="p971033849165634"></a>virtual void </p>
<p id="p1059816817165634"><a name="p1059816817165634"></a><a name="p1059816817165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row683075623165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p473320563165634"><a name="p473320563165634"></a><a name="p473320563165634"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1646812225165634"><a name="p1646812225165634"></a><a name="p1646812225165634"></a>virtual void </p>
<p id="p2017320104165634"><a name="p2017320104165634"></a><a name="p2017320104165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1534446692165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034619088165634"><a name="p2034619088165634"></a><a name="p2034619088165634"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1884566599165634"><a name="p1884566599165634"></a><a name="p1884566599165634"></a>virtual void </p>
<p id="p1023442895165634"><a name="p1023442895165634"></a><a name="p1023442895165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row2023634837165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317861015165634"><a name="p1317861015165634"></a><a name="p1317861015165634"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p937809237165634"><a name="p937809237165634"></a><a name="p937809237165634"></a>virtual void </p>
<p id="p1978411103165634"><a name="p1978411103165634"></a><a name="p1978411103165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row516203035165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846771146165634"><a name="p846771146165634"></a><a name="p846771146165634"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97963186165634"><a name="p97963186165634"></a><a name="p97963186165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1462356367165634"><a name="p1462356367165634"></a><a name="p1462356367165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row2017877801165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1290402387165634"><a name="p1290402387165634"></a><a name="p1290402387165634"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1463908473165634"><a name="p1463908473165634"></a><a name="p1463908473165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p218441150165634"><a name="p218441150165634"></a><a name="p218441150165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1482846269165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1968590912165634"><a name="p1968590912165634"></a><a name="p1968590912165634"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p900437823165634"><a name="p900437823165634"></a><a name="p900437823165634"></a>void </p>
<p id="p54600096165634"><a name="p54600096165634"></a><a name="p54600096165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1783326430165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1118833162165634"><a name="p1118833162165634"></a><a name="p1118833162165634"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837145336165634"><a name="p1837145336165634"></a><a name="p1837145336165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p560471773165634"><a name="p560471773165634"></a><a name="p560471773165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1633855129165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2036449532165634"><a name="p2036449532165634"></a><a name="p2036449532165634"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202156848165634"><a name="p202156848165634"></a><a name="p202156848165634"></a>void </p>
<p id="p191545324165634"><a name="p191545324165634"></a><a name="p191545324165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row2106454184165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1310164527165634"><a name="p1310164527165634"></a><a name="p1310164527165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768313386165634"><a name="p1768313386165634"></a><a name="p1768313386165634"></a> </p>
<p id="p1292830725165634"><a name="p1292830725165634"></a><a name="p1292830725165634"></a>A default constructor used to create an <strong id="b148401747165634"><a name="b148401747165634"></a><a name="b148401747165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row92045350165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1662364761165634"><a name="p1662364761165634"></a><a name="p1662364761165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892254609165634"><a name="p1892254609165634"></a><a name="p1892254609165634"></a> </p>
<p id="p1555341095165634"><a name="p1555341095165634"></a><a name="p1555341095165634"></a>A constructor used to create an <strong id="b471836239165634"><a name="b471836239165634"></a><a name="b471836239165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1263745842165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472174693165634"><a name="p472174693165634"></a><a name="p472174693165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812398868165634"><a name="p812398868165634"></a><a name="p812398868165634"></a>virtual </p>
<p id="p1767898984165634"><a name="p1767898984165634"></a><a name="p1767898984165634"></a>A destructor used to delete the <strong id="b1834697433165634"><a name="b1834697433165634"></a><a name="b1834697433165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row982429862165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1018219092165634"><a name="p1018219092165634"></a><a name="p1018219092165634"></a><a href="graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096064194165634"><a name="p1096064194165634"></a><a name="p1096064194165634"></a>virtual bool </p>
<p id="p2018604179165634"><a name="p2018604179165634"></a><a name="p2018604179165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1452415388165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856034338165634"><a name="p856034338165634"></a><a name="p856034338165634"></a><a href="graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1269795885165634"><a name="p1269795885165634"></a><a name="p1269795885165634"></a>virtual void </p>
<p id="p1292303502165634"><a name="p1292303502165634"></a><a name="p1292303502165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1135034913165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p588972653165634"><a name="p588972653165634"></a><a name="p588972653165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342499420165634"><a name="p1342499420165634"></a><a name="p1342499420165634"></a>virtual void </p>
<p id="p1181503690165634"><a name="p1181503690165634"></a><a name="p1181503690165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1064258368165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1752789812165634"><a name="p1752789812165634"></a><a name="p1752789812165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877503156165634"><a name="p1877503156165634"></a><a name="p1877503156165634"></a>virtual void </p>
<p id="p1011821565165634"><a name="p1011821565165634"></a><a name="p1011821565165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row381435341165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668000123165634"><a name="p668000123165634"></a><a name="p668000123165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35208878165634"><a name="p35208878165634"></a><a name="p35208878165634"></a>void </p>
<p id="p822950507165634"><a name="p822950507165634"></a><a name="p822950507165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row241585541165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2048543313165634"><a name="p2048543313165634"></a><a name="p2048543313165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886470764165634"><a name="p1886470764165634"></a><a name="p1886470764165634"></a>void </p>
<p id="p693297416165634"><a name="p693297416165634"></a><a name="p693297416165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1797001503165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718801263165634"><a name="p1718801263165634"></a><a name="p1718801263165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1338256675165634"><a name="p1338256675165634"></a><a name="p1338256675165634"></a>virtual bool </p>
<p id="p1104013960165634"><a name="p1104013960165634"></a><a name="p1104013960165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1273214856165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732067178165634"><a name="p732067178165634"></a><a name="p732067178165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p860986439165634"><a name="p860986439165634"></a><a name="p860986439165634"></a>virtual bool </p>
<p id="p1030003127165634"><a name="p1030003127165634"></a><a name="p1030003127165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1626482644165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p660841115165634"><a name="p660841115165634"></a><a name="p660841115165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432692173165634"><a name="p1432692173165634"></a><a name="p1432692173165634"></a>virtual void </p>
<p id="p1205516879165634"><a name="p1205516879165634"></a><a name="p1205516879165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1641131173165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192429033165634"><a name="p1192429033165634"></a><a name="p1192429033165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p87054382165634"><a name="p87054382165634"></a><a name="p87054382165634"></a>virtual void </p>
<p id="p949293485165634"><a name="p949293485165634"></a><a name="p949293485165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1887073869165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1092424970165634"><a name="p1092424970165634"></a><a name="p1092424970165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076510464165634"><a name="p2076510464165634"></a><a name="p2076510464165634"></a>virtual void </p>
<p id="p74260116165634"><a name="p74260116165634"></a><a name="p74260116165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row536938003165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128154811165634"><a name="p2128154811165634"></a><a name="p2128154811165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462964625165634"><a name="p462964625165634"></a><a name="p462964625165634"></a>void </p>
<p id="p1159543533165634"><a name="p1159543533165634"></a><a name="p1159543533165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1723032623165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83468128165634"><a name="p83468128165634"></a><a name="p83468128165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p121422819165634"><a name="p121422819165634"></a><a name="p121422819165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1324450415165634"><a name="p1324450415165634"></a><a name="p1324450415165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row951568729165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1547059469165634"><a name="p1547059469165634"></a><a name="p1547059469165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769649291165634"><a name="p1769649291165634"></a><a name="p1769649291165634"></a>void </p>
<p id="p1933323798165634"><a name="p1933323798165634"></a><a name="p1933323798165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row938356174165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658907981165634"><a name="p658907981165634"></a><a name="p658907981165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p514909870165634"><a name="p514909870165634"></a><a name="p514909870165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1696100205165634"><a name="p1696100205165634"></a><a name="p1696100205165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row473735541165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1377174631165634"><a name="p1377174631165634"></a><a name="p1377174631165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26824986165634"><a name="p26824986165634"></a><a name="p26824986165634"></a>void </p>
<p id="p1333778309165634"><a name="p1333778309165634"></a><a name="p1333778309165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1633382026165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379585656165634"><a name="p379585656165634"></a><a name="p379585656165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1865498690165634"><a name="p1865498690165634"></a><a name="p1865498690165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1152164827165634"><a name="p1152164827165634"></a><a name="p1152164827165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row305389296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p338063282165634"><a name="p338063282165634"></a><a name="p338063282165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p153520305165634"><a name="p153520305165634"></a><a name="p153520305165634"></a>void </p>
<p id="p130323571165634"><a name="p130323571165634"></a><a name="p130323571165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row911266188165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1812323664165634"><a name="p1812323664165634"></a><a name="p1812323664165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215054935165634"><a name="p1215054935165634"></a><a name="p1215054935165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p224169751165634"><a name="p224169751165634"></a><a name="p224169751165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row50114397165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916338247165634"><a name="p1916338247165634"></a><a name="p1916338247165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1416624644165634"><a name="p1416624644165634"></a><a name="p1416624644165634"></a>void </p>
<p id="p111236694165634"><a name="p111236694165634"></a><a name="p111236694165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1678209872165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496766858165634"><a name="p496766858165634"></a><a name="p496766858165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p882480324165634"><a name="p882480324165634"></a><a name="p882480324165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1118787152165634"><a name="p1118787152165634"></a><a name="p1118787152165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1972479076165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838035877165634"><a name="p838035877165634"></a><a name="p838035877165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059036855165634"><a name="p2059036855165634"></a><a name="p2059036855165634"></a>void </p>
<p id="p1737534610165634"><a name="p1737534610165634"></a><a name="p1737534610165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row183851055165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303233321165634"><a name="p1303233321165634"></a><a name="p1303233321165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263149528165634"><a name="p263149528165634"></a><a name="p263149528165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1852105366165634"><a name="p1852105366165634"></a><a name="p1852105366165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row561533970165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1894016980165634"><a name="p1894016980165634"></a><a name="p1894016980165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p889798458165634"><a name="p889798458165634"></a><a name="p889798458165634"></a>virtual void </p>
<p id="p417013654165634"><a name="p417013654165634"></a><a name="p417013654165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row153551678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p418648599165634"><a name="p418648599165634"></a><a name="p418648599165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1341121781165634"><a name="p1341121781165634"></a><a name="p1341121781165634"></a>bool </p>
<p id="p2019329101165634"><a name="p2019329101165634"></a><a name="p2019329101165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1496926780165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203799142165634"><a name="p1203799142165634"></a><a name="p1203799142165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1081882322165634"><a name="p1081882322165634"></a><a name="p1081882322165634"></a>void </p>
<p id="p770944691165634"><a name="p770944691165634"></a><a name="p770944691165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row384448653165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661252197165634"><a name="p1661252197165634"></a><a name="p1661252197165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p129632686165634"><a name="p129632686165634"></a><a name="p129632686165634"></a>bool </p>
<p id="p1779088319165634"><a name="p1779088319165634"></a><a name="p1779088319165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row165813403165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708285231165634"><a name="p1708285231165634"></a><a name="p1708285231165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1373171295165634"><a name="p1373171295165634"></a><a name="p1373171295165634"></a>void </p>
<p id="p1337319669165634"><a name="p1337319669165634"></a><a name="p1337319669165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row722414731165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1990311117165634"><a name="p1990311117165634"></a><a name="p1990311117165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638287633165634"><a name="p1638287633165634"></a><a name="p1638287633165634"></a>bool </p>
<p id="p1043464464165634"><a name="p1043464464165634"></a><a name="p1043464464165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row617855551165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107080741165634"><a name="p107080741165634"></a><a name="p107080741165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p276610915165634"><a name="p276610915165634"></a><a name="p276610915165634"></a>void </p>
<p id="p19019023165634"><a name="p19019023165634"></a><a name="p19019023165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1727995147165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904956720165634"><a name="p1904956720165634"></a><a name="p1904956720165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403911345165634"><a name="p1403911345165634"></a><a name="p1403911345165634"></a>bool </p>
<p id="p1237451861165634"><a name="p1237451861165634"></a><a name="p1237451861165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1603642512165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1562822958165634"><a name="p1562822958165634"></a><a name="p1562822958165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p797001436165634"><a name="p797001436165634"></a><a name="p797001436165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1441170164165634"><a name="p1441170164165634"></a><a name="p1441170164165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row80546907165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p823246873165634"><a name="p823246873165634"></a><a name="p823246873165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p363892985165634"><a name="p363892985165634"></a><a name="p363892985165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1396371790165634"><a name="p1396371790165634"></a><a name="p1396371790165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1516073075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2028374583165634"><a name="p2028374583165634"></a><a name="p2028374583165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108001655165634"><a name="p108001655165634"></a><a name="p108001655165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1857791563165634"><a name="p1857791563165634"></a><a name="p1857791563165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row924392437165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p569133985165634"><a name="p569133985165634"></a><a name="p569133985165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1460743979165634"><a name="p1460743979165634"></a><a name="p1460743979165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1083788492165634"><a name="p1083788492165634"></a><a name="p1083788492165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1515171616165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879961588165634"><a name="p879961588165634"></a><a name="p879961588165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2097309521165634"><a name="p2097309521165634"></a><a name="p2097309521165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1611465076165634"><a name="p1611465076165634"></a><a name="p1611465076165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1421837162165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1529330779165634"><a name="p1529330779165634"></a><a name="p1529330779165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523951870165634"><a name="p1523951870165634"></a><a name="p1523951870165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p595524644165634"><a name="p595524644165634"></a><a name="p595524644165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row628947902165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2093049565165634"><a name="p2093049565165634"></a><a name="p2093049565165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1315280853165634"><a name="p1315280853165634"></a><a name="p1315280853165634"></a>void </p>
<p id="p667613501165634"><a name="p667613501165634"></a><a name="p667613501165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row715444714165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509066738165634"><a name="p1509066738165634"></a><a name="p1509066738165634"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p379668265165634"><a name="p379668265165634"></a><a name="p379668265165634"></a>virtual void </p>
<p id="p687612864165634"><a name="p687612864165634"></a><a name="p687612864165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row2053000544165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577935379165634"><a name="p577935379165634"></a><a name="p577935379165634"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2046199634165634"><a name="p2046199634165634"></a><a name="p2046199634165634"></a>virtual int16_t </p>
<p id="p1006535995165634"><a name="p1006535995165634"></a><a name="p1006535995165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row813248430165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p816937109165634"><a name="p816937109165634"></a><a name="p816937109165634"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1043865566165634"><a name="p1043865566165634"></a><a name="p1043865566165634"></a>virtual void </p>
<p id="p115408728165634"><a name="p115408728165634"></a><a name="p115408728165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1535216264165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887189460165634"><a name="p887189460165634"></a><a name="p887189460165634"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1245613258165634"><a name="p1245613258165634"></a><a name="p1245613258165634"></a>virtual int16_t </p>
<p id="p1156836341165634"><a name="p1156836341165634"></a><a name="p1156836341165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row396576930165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063866960165634"><a name="p2063866960165634"></a><a name="p2063866960165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949002024165634"><a name="p949002024165634"></a><a name="p949002024165634"></a>virtual void </p>
<p id="p409482519165634"><a name="p409482519165634"></a><a name="p409482519165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1239354835165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p690037099165634"><a name="p690037099165634"></a><a name="p690037099165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p509210102165634"><a name="p509210102165634"></a><a name="p509210102165634"></a>virtual void </p>
<p id="p1313098258165634"><a name="p1313098258165634"></a><a name="p1313098258165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row950441387165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468447957165634"><a name="p468447957165634"></a><a name="p468447957165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p240430793165634"><a name="p240430793165634"></a><a name="p240430793165634"></a>int16_t </p>
<p id="p839279771165634"><a name="p839279771165634"></a><a name="p839279771165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1331978374165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1902942310165634"><a name="p1902942310165634"></a><a name="p1902942310165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016171300165634"><a name="p1016171300165634"></a><a name="p1016171300165634"></a>virtual void </p>
<p id="p512373289165634"><a name="p512373289165634"></a><a name="p512373289165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1906358596165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p355485513165634"><a name="p355485513165634"></a><a name="p355485513165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1524678416165634"><a name="p1524678416165634"></a><a name="p1524678416165634"></a>int16_t </p>
<p id="p163220447165634"><a name="p163220447165634"></a><a name="p163220447165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row697171058165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p51543329165634"><a name="p51543329165634"></a><a name="p51543329165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1888663317165634"><a name="p1888663317165634"></a><a name="p1888663317165634"></a>virtual void </p>
<p id="p1976688040165634"><a name="p1976688040165634"></a><a name="p1976688040165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1540648458165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12692143165634"><a name="p12692143165634"></a><a name="p12692143165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115433036165634"><a name="p2115433036165634"></a><a name="p2115433036165634"></a>virtual void </p>
<p id="p1725282406165634"><a name="p1725282406165634"></a><a name="p1725282406165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1215631315165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411035899165634"><a name="p1411035899165634"></a><a name="p1411035899165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p330856971165634"><a name="p330856971165634"></a><a name="p330856971165634"></a>bool </p>
<p id="p1191155409165634"><a name="p1191155409165634"></a><a name="p1191155409165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1489899705165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p272268334165634"><a name="p272268334165634"></a><a name="p272268334165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1537587701165634"><a name="p1537587701165634"></a><a name="p1537587701165634"></a>void </p>
<p id="p1123243385165634"><a name="p1123243385165634"></a><a name="p1123243385165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1706160985165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1876366330165634"><a name="p1876366330165634"></a><a name="p1876366330165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p373215763165634"><a name="p373215763165634"></a><a name="p373215763165634"></a>void </p>
<p id="p1787085179165634"><a name="p1787085179165634"></a><a name="p1787085179165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row111312228165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1588425181165634"><a name="p1588425181165634"></a><a name="p1588425181165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540081463165634"><a name="p540081463165634"></a><a name="p540081463165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p452689655165634"><a name="p452689655165634"></a><a name="p452689655165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1230611953165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171343017165634"><a name="p1171343017165634"></a><a name="p1171343017165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570506419165634"><a name="p1570506419165634"></a><a name="p1570506419165634"></a>void </p>
<p id="p1481439174165634"><a name="p1481439174165634"></a><a name="p1481439174165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row527391286165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1693160614165634"><a name="p1693160614165634"></a><a name="p1693160614165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674292186165634"><a name="p674292186165634"></a><a name="p674292186165634"></a>const char * </p>
<p id="p878521014165634"><a name="p878521014165634"></a><a name="p878521014165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row828495236165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p104851185165634"><a name="p104851185165634"></a><a name="p104851185165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203007701165634"><a name="p203007701165634"></a><a name="p203007701165634"></a>void </p>
<p id="p1473045048165634"><a name="p1473045048165634"></a><a name="p1473045048165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row625801897165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p484923407165634"><a name="p484923407165634"></a><a name="p484923407165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478142088165634"><a name="p1478142088165634"></a><a name="p1478142088165634"></a>int16_t </p>
<p id="p426798310165634"><a name="p426798310165634"></a><a name="p426798310165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1272120798165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p562156102165634"><a name="p562156102165634"></a><a name="p562156102165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764744104165634"><a name="p1764744104165634"></a><a name="p1764744104165634"></a>virtual void </p>
<p id="p170773360165634"><a name="p170773360165634"></a><a name="p170773360165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1039140962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p675571291165634"><a name="p675571291165634"></a><a name="p675571291165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295381491165634"><a name="p1295381491165634"></a><a name="p1295381491165634"></a>void </p>
<p id="p1291952746165634"><a name="p1291952746165634"></a><a name="p1291952746165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row779439719165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p75415410165634"><a name="p75415410165634"></a><a name="p75415410165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356504669165634"><a name="p1356504669165634"></a><a name="p1356504669165634"></a>void </p>
<p id="p2141365220165634"><a name="p2141365220165634"></a><a name="p2141365220165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row813580975165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235010547165634"><a name="p235010547165634"></a><a name="p235010547165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690642662165634"><a name="p690642662165634"></a><a name="p690642662165634"></a>void </p>
<p id="p444880908165634"><a name="p444880908165634"></a><a name="p444880908165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row877255639165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1877280165165634"><a name="p1877280165165634"></a><a name="p1877280165165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p963075146165634"><a name="p963075146165634"></a><a name="p963075146165634"></a>void </p>
<p id="p1388302480165634"><a name="p1388302480165634"></a><a name="p1388302480165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1416232909165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1538045610165634"><a name="p1538045610165634"></a><a name="p1538045610165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801075776165634"><a name="p1801075776165634"></a><a name="p1801075776165634"></a>void </p>
<p id="p914654121165634"><a name="p914654121165634"></a><a name="p914654121165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1001438475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1879737505165634"><a name="p1879737505165634"></a><a name="p1879737505165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1689806348165634"><a name="p1689806348165634"></a><a name="p1689806348165634"></a>void </p>
<p id="p1153545380165634"><a name="p1153545380165634"></a><a name="p1153545380165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1134711293165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p923294067165634"><a name="p923294067165634"></a><a name="p923294067165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380218228165634"><a name="p1380218228165634"></a><a name="p1380218228165634"></a>void </p>
<p id="p357630179165634"><a name="p357630179165634"></a><a name="p357630179165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1267592374165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2118852541165634"><a name="p2118852541165634"></a><a name="p2118852541165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354745088165634"><a name="p1354745088165634"></a><a name="p1354745088165634"></a>void </p>
<p id="p1976232826165634"><a name="p1976232826165634"></a><a name="p1976232826165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1917504050165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1030488080165634"><a name="p1030488080165634"></a><a name="p1030488080165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048987078165634"><a name="p1048987078165634"></a><a name="p1048987078165634"></a>void </p>
<p id="p1536438911165634"><a name="p1536438911165634"></a><a name="p1536438911165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1723186399165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264360806165634"><a name="p1264360806165634"></a><a name="p1264360806165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875404745165634"><a name="p875404745165634"></a><a name="p875404745165634"></a>void </p>
<p id="p1626731743165634"><a name="p1626731743165634"></a><a name="p1626731743165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1233500667165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416841173165634"><a name="p1416841173165634"></a><a name="p1416841173165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1962088701165634"><a name="p1962088701165634"></a><a name="p1962088701165634"></a>void </p>
<p id="p672256062165634"><a name="p672256062165634"></a><a name="p672256062165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1399068702165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1307733268165634"><a name="p1307733268165634"></a><a name="p1307733268165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p657168507165634"><a name="p657168507165634"></a><a name="p657168507165634"></a>void </p>
<p id="p979524731165634"><a name="p979524731165634"></a><a name="p979524731165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row973281733165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280434576165634"><a name="p1280434576165634"></a><a name="p1280434576165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499306676165634"><a name="p499306676165634"></a><a name="p499306676165634"></a>void </p>
<p id="p1544124829165634"><a name="p1544124829165634"></a><a name="p1544124829165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row787821994165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1896317516165634"><a name="p1896317516165634"></a><a name="p1896317516165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p747838004165634"><a name="p747838004165634"></a><a name="p747838004165634"></a>void </p>
<p id="p681127278165634"><a name="p681127278165634"></a><a name="p681127278165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1588767962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p455398711165634"><a name="p455398711165634"></a><a name="p455398711165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p817685853165634"><a name="p817685853165634"></a><a name="p817685853165634"></a>void </p>
<p id="p312431500165634"><a name="p312431500165634"></a><a name="p312431500165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1060949627165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1615514216165634"><a name="p1615514216165634"></a><a name="p1615514216165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030183674165634"><a name="p1030183674165634"></a><a name="p1030183674165634"></a>void </p>
<p id="p471752008165634"><a name="p471752008165634"></a><a name="p471752008165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row470626177165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821544446165634"><a name="p1821544446165634"></a><a name="p1821544446165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965505811165634"><a name="p1965505811165634"></a><a name="p1965505811165634"></a>virtual void </p>
<p id="p1089757597165634"><a name="p1089757597165634"></a><a name="p1089757597165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row616302251165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835633801165634"><a name="p835633801165634"></a><a name="p835633801165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785661760165634"><a name="p785661760165634"></a><a name="p785661760165634"></a>virtual int64_t </p>
<p id="p1901818378165634"><a name="p1901818378165634"></a><a name="p1901818378165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1445727473165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p745803767165634"><a name="p745803767165634"></a><a name="p745803767165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2103482341165634"><a name="p2103482341165634"></a><a name="p2103482341165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p380740460165634"><a name="p380740460165634"></a><a name="p380740460165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row445852570165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265075937165634"><a name="p1265075937165634"></a><a name="p1265075937165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223478453165634"><a name="p223478453165634"></a><a name="p223478453165634"></a>void * </p>
<p id="p935075889165634"><a name="p935075889165634"></a><a name="p935075889165634"></a>Overrides the <strong id="b635301937165634"><a name="b635301937165634"></a><a name="b635301937165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1885239923165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114829914165634"><a name="p114829914165634"></a><a name="p114829914165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75544487165634"><a name="p75544487165634"></a><a name="p75544487165634"></a>void </p>
<p id="p1895651024165634"><a name="p1895651024165634"></a><a name="p1895651024165634"></a>Overrides the <strong id="b1433715035165634"><a name="b1433715035165634"></a><a name="b1433715035165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1170260178165634"></a>
<table><thead align="left"><tr id="row1141684451165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1255950643165634"><a name="p1255950643165634"></a><a name="p1255950643165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p911873267165634"><a name="p911873267165634"></a><a name="p911873267165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1823165111165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p776302679165634"><a name="p776302679165634"></a><a name="p776302679165634"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p800844556165634"><a name="p800844556165634"></a><a name="p800844556165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1781164336165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604561984165634"><a name="p604561984165634"></a><a name="p604561984165634"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p321097231165634"><a name="p321097231165634"></a><a name="p321097231165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row381109248165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781965280165634"><a name="p1781965280165634"></a><a name="p1781965280165634"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p195966892165634"><a name="p195966892165634"></a><a name="p195966892165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row2033207566165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313256378165634"><a name="p313256378165634"></a><a name="p313256378165634"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1986461967165634"><a name="p1986461967165634"></a><a name="p1986461967165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row397520268165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p80659029165634"><a name="p80659029165634"></a><a name="p80659029165634"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p188136947165634"><a name="p188136947165634"></a><a name="p188136947165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row696701155165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786921494165634"><a name="p786921494165634"></a><a name="p786921494165634"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p16664849165634"><a name="p16664849165634"></a><a name="p16664849165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1776185733165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1795552036165634"><a name="p1795552036165634"></a><a name="p1795552036165634"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p841739695165634"><a name="p841739695165634"></a><a name="p841739695165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1746839653165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858727226165634"><a name="p1858727226165634"></a><a name="p1858727226165634"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076366382165634"><a name="p2076366382165634"></a><a name="p2076366382165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

