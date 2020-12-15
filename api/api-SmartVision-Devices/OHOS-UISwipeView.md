# OHOS::UISwipeView<a name="ZH-CN_TOPIC_0000001055518116"></a>

-   [Overview](#section373833199165634)
-   [Summary](#section344567888165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Static Public Attributes](#pub-static-attribs)
-   [Protected Member Functions](#pro-methods)
-   [Static Protected Attributes](#pro-static-attribs)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section373833199165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a swipe view. 

Each swipe view consists of multiple child views, which can be navigated through swiping. The child views can be either horizontal or vertical.

See also
:   [UIAbstractScroll](OHOS-UIAbstractScroll.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section344567888165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table212294800165634"></a>
<table><thead align="left"><tr id="row37712115165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p43161949165634"><a name="p43161949165634"></a><a name="p43161949165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p54977954165634"><a name="p54977954165634"></a><a name="p54977954165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1719539426165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27106596165634"><a name="p27106596165634"></a><a name="p27106596165634"></a><a href="OHOS-UISwipeView-OnSwipeListener.md">OnSwipeListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354756909165634"><a name="p1354756909165634"></a><a name="p1354756909165634"></a>Represents a listener for changes of the swipe view. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table449693304165634"></a>
<table><thead align="left"><tr id="row1720860942165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p31193407165634"><a name="p31193407165634"></a><a name="p31193407165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1659346544165634"><a name="p1659346544165634"></a><a name="p1659346544165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1034373441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61799141165634"><a name="p61799141165634"></a><a name="p61799141165634"></a><a href="Graphic.md#ga3a460525251fde8e30c35be808151509">UISwipeView</a> (uint8_t direction=<a href="Graphic.md#ga34dfbde0fad8baade31c02d9e8dd5026">HORIZONTAL</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1090369667165634"><a name="p1090369667165634"></a><a name="p1090369667165634"></a> </p>
<p id="p1937127416165634"><a name="p1937127416165634"></a><a name="p1937127416165634"></a>A constructor used to create a <strong id="b1317987927165634"><a name="b1317987927165634"></a><a name="b1317987927165634"></a><a href="OHOS-UISwipeView.md">UISwipeView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1836144144165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1991739613165634"><a name="p1991739613165634"></a><a name="p1991739613165634"></a><a href="Graphic.md#gaf51c21b72dcbe790c3bb7b83b53b3cef">~UISwipeView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072683581165634"><a name="p2072683581165634"></a><a name="p2072683581165634"></a>virtual </p>
<p id="p413434086165634"><a name="p413434086165634"></a><a name="p413434086165634"></a>A destructor used to delete the <strong id="b588266018165634"><a name="b588266018165634"></a><a name="b588266018165634"></a><a href="OHOS-UISwipeView.md">UISwipeView</a></strong> instance. </p>
</td>
</tr>
<tr id="row463553762165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606828041165634"><a name="p1606828041165634"></a><a name="p1606828041165634"></a><a href="Graphic.md#ga71ae0dd892d8d9b8d277ba2b5572182d">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34796117165634"><a name="p34796117165634"></a><a name="p34796117165634"></a>UIViewType </p>
<p id="p411215610165634"><a name="p411215610165634"></a><a name="p411215610165634"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row252228300165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1543998836165634"><a name="p1543998836165634"></a><a name="p1543998836165634"></a><a href="Graphic.md#ga29be43640abe185baef5ead904a729cb">SetDirection</a> (uint8_t direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941229739165634"><a name="p941229739165634"></a><a name="p941229739165634"></a>void </p>
<p id="p114959971165634"><a name="p114959971165634"></a><a name="p114959971165634"></a>Sets the dragging direction. </p>
</td>
</tr>
<tr id="row782495030165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495740968165634"><a name="p1495740968165634"></a><a name="p1495740968165634"></a><a href="Graphic.md#gad84dab74af54c23e6e724bdebb8b7df9">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p485021583165634"><a name="p485021583165634"></a><a name="p485021583165634"></a>uint8_t </p>
<p id="p913472886165634"><a name="p913472886165634"></a><a name="p913472886165634"></a>Obtains the dragging direction. </p>
</td>
</tr>
<tr id="row1252017475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p354907968165634"><a name="p354907968165634"></a><a name="p354907968165634"></a><a href="Graphic.md#ga1cdc37a33412d6134ed7214300bc1c87">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p284491844165634"><a name="p284491844165634"></a><a name="p284491844165634"></a>void </p>
<p id="p1435714154165634"><a name="p1435714154165634"></a><a name="p1435714154165634"></a>Adds a view. </p>
</td>
</tr>
<tr id="row1709834240165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906420698165634"><a name="p1906420698165634"></a><a name="p1906420698165634"></a><a href="Graphic.md#ga154efaf952ba1db65e53efdd29f0027b">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978241803165634"><a name="p1978241803165634"></a><a name="p1978241803165634"></a>void </p>
<p id="p959450120165634"><a name="p959450120165634"></a><a name="p959450120165634"></a>Inserts a view. </p>
</td>
</tr>
<tr id="row1393139671165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245465660165634"><a name="p245465660165634"></a><a name="p245465660165634"></a><a href="Graphic.md#ga2a4f70938a7d2298a318dff6dff95e85">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317673867165634"><a name="p1317673867165634"></a><a name="p1317673867165634"></a>virtual void </p>
<p id="p628468614165634"><a name="p628468614165634"></a><a name="p628468614165634"></a>Deletes a view. </p>
</td>
</tr>
<tr id="row1228327513165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p504284897165634"><a name="p504284897165634"></a><a name="p504284897165634"></a><a href="Graphic.md#gaedb8649e42a712463158f42eb66efc33">SetCurrentPage</a> (uint16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, bool needAnimator=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114498741165634"><a name="p114498741165634"></a><a name="p114498741165634"></a>void </p>
<p id="p598722283165634"><a name="p598722283165634"></a><a name="p598722283165634"></a>Sets the index for the current tab. </p>
</td>
</tr>
<tr id="row499012924165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p941470634165634"><a name="p941470634165634"></a><a name="p941470634165634"></a><a href="Graphic.md#gaea0c52e94714dff049117227a1fd1849">GetCurrentPage</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990394903165634"><a name="p990394903165634"></a><a name="p990394903165634"></a>uint16_t </p>
<p id="p129153640165634"><a name="p129153640165634"></a><a name="p129153640165634"></a>Obtains the current tab index. </p>
</td>
</tr>
<tr id="row956319060165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p497340280165634"><a name="p497340280165634"></a><a name="p497340280165634"></a><a href="Graphic.md#ga9b91ece1e4492afd3e4705e49bc511f3">GetCurrentView</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993351121165634"><a name="p1993351121165634"></a><a name="p1993351121165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p631413968165634"><a name="p631413968165634"></a><a name="p631413968165634"></a>Obtains the current view. </p>
</td>
</tr>
<tr id="row924408370165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74182832165634"><a name="p74182832165634"></a><a name="p74182832165634"></a><a href="Graphic.md#ga834d61387b0243cd0505f6d03d32a8f8">SetBlankSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p741239813165634"><a name="p741239813165634"></a><a name="p741239813165634"></a>void </p>
<p id="p770028741165634"><a name="p770028741165634"></a><a name="p770028741165634"></a>Sets a blank size, as defined in <a href="Graphic.md#ga81883a607d2cb3356560fc0f8f84cf74">DEFAULT_BLANK_SIZE</a>. </p>
</td>
</tr>
<tr id="row824518213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p615576823165634"><a name="p615576823165634"></a><a name="p615576823165634"></a><a href="Graphic.md#ga888ec9a6ddaa4051e7c2e5d76832565c">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1059338861165634"><a name="p1059338861165634"></a><a name="p1059338861165634"></a>bool </p>
<p id="p1166080784165634"><a name="p1166080784165634"></a><a name="p1166080784165634"></a>revice drag event, Switch to specified view when drag </p>
</td>
</tr>
<tr id="row285933258165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p726135148165634"><a name="p726135148165634"></a><a name="p726135148165634"></a><a href="Graphic.md#gab57d973cea1186dd90eec91cd27da1fb">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2054914392165634"><a name="p2054914392165634"></a><a name="p2054914392165634"></a>bool </p>
<p id="p1915992005165634"><a name="p1915992005165634"></a><a name="p1915992005165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row602318703165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1544568126165634"><a name="p1544568126165634"></a><a name="p1544568126165634"></a><a href="Graphic.md#gadb01e8e5702625c3a99f383eb7ae1664">SetAnimatorTime</a> (uint16_t <a href="TIME.md#gae7841e681c8c9d59818568d39553642c">time</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p238702935165634"><a name="p238702935165634"></a><a name="p238702935165634"></a>void </p>
<p id="p539763021165634"><a name="p539763021165634"></a><a name="p539763021165634"></a>Sets the time for the page being animated. The page will go beyond the blank during this time. </p>
</td>
</tr>
<tr id="row1147632412165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p966037272165634"><a name="p966037272165634"></a><a name="p966037272165634"></a><a href="Graphic.md#ga7f7dce8193817e29c9b82af47934d788">SetLoopState</a> (bool loop)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p402985308165634"><a name="p402985308165634"></a><a name="p402985308165634"></a>void </p>
<p id="p483213858165634"><a name="p483213858165634"></a><a name="p483213858165634"></a>Sets whether the swipe view supports a cycle swipe. </p>
</td>
</tr>
<tr id="row600317717165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843966889165634"><a name="p843966889165634"></a><a name="p843966889165634"></a><a href="Graphic.md#ga3c58441c4b07cf575b96b85df5e3a3bf">GetViewByIndex</a> (uint16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p336086476165634"><a name="p336086476165634"></a><a name="p336086476165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1670791890165634"><a name="p1670791890165634"></a><a name="p1670791890165634"></a>Obtains a view based on its index. </p>
</td>
</tr>
<tr id="row834846326165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1733183861165634"><a name="p1733183861165634"></a><a name="p1733183861165634"></a><a href="Graphic.md#ga4c33414b3a828d1750deed3cceb86daf">GetOnSwipeListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666925069165634"><a name="p666925069165634"></a><a name="p666925069165634"></a><a href="OHOS-UISwipeView-OnSwipeListener.md">OnSwipeListener</a> *&amp; </p>
<p id="p1360016986165634"><a name="p1360016986165634"></a><a name="p1360016986165634"></a>Obtains the listener set for swipe events. </p>
</td>
</tr>
<tr id="row1436557305165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411356432165634"><a name="p1411356432165634"></a><a name="p1411356432165634"></a><a href="Graphic.md#ga7d4a3dc25f189ab19eaef4a62cd0428e">SetOnSwipeListener</a> (<a href="OHOS-UISwipeView-OnSwipeListener.md">OnSwipeListener</a> *onSwipeListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2102027816165634"><a name="p2102027816165634"></a><a name="p2102027816165634"></a>void </p>
<p id="p773818881165634"><a name="p773818881165634"></a><a name="p773818881165634"></a>Sets the listener that contains a callback to be invoked upon a swipe event. </p>
</td>
</tr>
<tr id="row1075086966165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1328220113165634"><a name="p1328220113165634"></a><a name="p1328220113165634"></a><a href="Graphic.md#ga93a169fba7c98f6534692cba9e8d539b">UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p564387031165634"><a name="p564387031165634"></a><a name="p564387031165634"></a> </p>
<p id="p511790446165634"><a name="p511790446165634"></a><a name="p511790446165634"></a>A constructor used to create a <strong id="b939469574165634"><a name="b939469574165634"></a><a name="b939469574165634"></a><a href="OHOS-UIAbstractScroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row1973842310165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p386905151165634"><a name="p386905151165634"></a><a name="p386905151165634"></a><a href="Graphic.md#ga414798ec7357edc85409128fba0a813c">~UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1537063196165634"><a name="p1537063196165634"></a><a name="p1537063196165634"></a>virtual </p>
<p id="p606234494165634"><a name="p606234494165634"></a><a name="p606234494165634"></a>A destructor used to delete the <strong id="b1155879111165634"><a name="b1155879111165634"></a><a name="b1155879111165634"></a><a href="OHOS-UIAbstractScroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row99620972165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1190566020165634"><a name="p1190566020165634"></a><a name="p1190566020165634"></a><a href="Graphic.md#ga443783170697bea9a933843ad2a92283">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p952700172165634"><a name="p952700172165634"></a><a name="p952700172165634"></a>uint8_t </p>
<p id="p308140973165634"><a name="p308140973165634"></a><a name="p308140973165634"></a>Obtains the scroll direction. </p>
</td>
</tr>
<tr id="row593525326165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276201143165634"><a name="p1276201143165634"></a><a name="p1276201143165634"></a><a href="Graphic.md#gab37cea97d63ee9ca609c9a1ed0f1e281">SetScrollBlankSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578807564165634"><a name="p1578807564165634"></a><a name="p1578807564165634"></a>void </p>
<p id="p1537024058165634"><a name="p1537024058165634"></a><a name="p1537024058165634"></a>Sets the blank size for this scroll view. </p>
</td>
</tr>
<tr id="row1118026247165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772594764165634"><a name="p1772594764165634"></a><a name="p1772594764165634"></a><a href="Graphic.md#gae2d6f5c97a316ecd3b41fecfa35a351f">SetMaxScrollDistance</a> (uint16_t distance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979189786165634"><a name="p979189786165634"></a><a name="p979189786165634"></a>void </p>
<p id="p806661194165634"><a name="p806661194165634"></a><a name="p806661194165634"></a>Sets the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1604733398165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889413781165634"><a name="p889413781165634"></a><a name="p889413781165634"></a><a href="Graphic.md#ga5d7fefcd2057e868a8f6c6a6000aa7ef">SetReboundSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436774795165634"><a name="p1436774795165634"></a><a name="p1436774795165634"></a>void </p>
<p id="p1186004238165634"><a name="p1186004238165634"></a><a name="p1186004238165634"></a>Sets the rebound size, which is the distance a knob moves after being released when it reaches the end of a scrollbar. </p>
</td>
</tr>
<tr id="row1771898607165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1920307928165634"><a name="p1920307928165634"></a><a name="p1920307928165634"></a><a href="Graphic.md#ga71a2b17d4145479ed2e2ca000eb7e86e">GetMaxScrollDistance</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1346673775165634"><a name="p1346673775165634"></a><a name="p1346673775165634"></a>uint16_t </p>
<p id="p622319191165634"><a name="p622319191165634"></a><a name="p622319191165634"></a>Obtains the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row597172596165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1027830656165634"><a name="p1027830656165634"></a><a name="p1027830656165634"></a><a href="Graphic.md#ga957ec65a7efad6818be6df5169158aad">SetDragFunc</a> (EasingFunc func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p712409066165634"><a name="p712409066165634"></a><a name="p712409066165634"></a>void </p>
<p id="p1300236628165634"><a name="p1300236628165634"></a><a name="p1300236628165634"></a>Sets the easing function that specifies a scroll animation after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row651779796165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p442787303165634"><a name="p442787303165634"></a><a name="p442787303165634"></a><a href="Graphic.md#ga4dde5f89d70304e77a96d4f4679438c2">SetThrowDrag</a> (bool throwDrag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p159176931165634"><a name="p159176931165634"></a><a name="p159176931165634"></a>void </p>
<p id="p459627011165634"><a name="p459627011165634"></a><a name="p459627011165634"></a>Sets whether to continue scrolling after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1157170174165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664413281165634"><a name="p664413281165634"></a><a name="p664413281165634"></a><a href="Graphic.md#gad344babd5b251ed908cdf628fae55093">SetDragACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1217202507165634"><a name="p1217202507165634"></a><a name="p1217202507165634"></a>void </p>
<p id="p641511005165634"><a name="p641511005165634"></a><a name="p641511005165634"></a>Sets the drag acceleration. </p>
</td>
</tr>
<tr id="row187977343165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1466710150165634"><a name="p1466710150165634"></a><a name="p1466710150165634"></a><a href="Graphic.md#ga29e68195b56783f265d85506f130c664">GetDragACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319391158165634"><a name="p319391158165634"></a><a name="p319391158165634"></a>uint8_t </p>
<p id="p1754037467165634"><a name="p1754037467165634"></a><a name="p1754037467165634"></a>Obtains the drag acceleration. </p>
</td>
</tr>
<tr id="row576062073165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p70977589165634"><a name="p70977589165634"></a><a name="p70977589165634"></a><a href="Graphic.md#gafab9d1a8f5987b50f9111c733ada6341">SetSwipeACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p449790333165634"><a name="p449790333165634"></a><a name="p449790333165634"></a>void </p>
<p id="p907919683165634"><a name="p907919683165634"></a><a name="p907919683165634"></a>Sets the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row584951110165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p177008921165634"><a name="p177008921165634"></a><a name="p177008921165634"></a><a href="Graphic.md#ga25dad3242949f0fbeff47d6df06053f6">GetSwipeACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p280061248165634"><a name="p280061248165634"></a><a name="p280061248165634"></a>uint8_t </p>
<p id="p1805937876165634"><a name="p1805937876165634"></a><a name="p1805937876165634"></a>Obtains the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1552575710165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294416345165634"><a name="p294416345165634"></a><a name="p294416345165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016653102165634"><a name="p1016653102165634"></a><a name="p1016653102165634"></a> </p>
<p id="p252004029165634"><a name="p252004029165634"></a><a name="p252004029165634"></a>A default constructor used to create a <strong id="b169633378165634"><a name="b169633378165634"></a><a name="b169633378165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1367808009165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1479869187165634"><a name="p1479869187165634"></a><a name="p1479869187165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p569697430165634"><a name="p569697430165634"></a><a name="p569697430165634"></a>virtual </p>
<p id="p441889354165634"><a name="p441889354165634"></a><a name="p441889354165634"></a>A destructor used to delete the <strong id="b2032741139165634"><a name="b2032741139165634"></a><a name="b2032741139165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row648928198165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1346288493165634"><a name="p1346288493165634"></a><a name="p1346288493165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1850965328165634"><a name="p1850965328165634"></a><a name="p1850965328165634"></a>UIViewType </p>
<p id="p1655739169165634"><a name="p1655739169165634"></a><a name="p1655739169165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1202242263165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591559090165634"><a name="p591559090165634"></a><a name="p591559090165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p323337388165634"><a name="p323337388165634"></a><a name="p323337388165634"></a>virtual void </p>
<p id="p1692723049165634"><a name="p1692723049165634"></a><a name="p1692723049165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row622675686165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1742525154165634"><a name="p1742525154165634"></a><a name="p1742525154165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1889398949165634"><a name="p1889398949165634"></a><a name="p1889398949165634"></a>virtual void </p>
<p id="p256723977165634"><a name="p256723977165634"></a><a name="p256723977165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row479036230165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1125834118165634"><a name="p1125834118165634"></a><a name="p1125834118165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169645345165634"><a name="p169645345165634"></a><a name="p169645345165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1813548365165634"><a name="p1813548365165634"></a><a name="p1813548365165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1872862454165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485441892165634"><a name="p1485441892165634"></a><a name="p1485441892165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736191571165634"><a name="p736191571165634"></a><a name="p736191571165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1090198047165634"><a name="p1090198047165634"></a><a name="p1090198047165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row360922074165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742687371165634"><a name="p742687371165634"></a><a name="p742687371165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775108285165634"><a name="p775108285165634"></a><a name="p775108285165634"></a>void </p>
<p id="p343890023165634"><a name="p343890023165634"></a><a name="p343890023165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row862970510165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541623383165634"><a name="p1541623383165634"></a><a name="p1541623383165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1309543465165634"><a name="p1309543465165634"></a><a name="p1309543465165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p290505546165634"><a name="p290505546165634"></a><a name="p290505546165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1975649084165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120986350165634"><a name="p1120986350165634"></a><a name="p1120986350165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652435482165634"><a name="p1652435482165634"></a><a name="p1652435482165634"></a>void </p>
<p id="p923456700165634"><a name="p923456700165634"></a><a name="p923456700165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row809050869165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1566585850165634"><a name="p1566585850165634"></a><a name="p1566585850165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1929735701165634"><a name="p1929735701165634"></a><a name="p1929735701165634"></a> </p>
<p id="p2013595613165634"><a name="p2013595613165634"></a><a name="p2013595613165634"></a>A default constructor used to create an <strong id="b1832248390165634"><a name="b1832248390165634"></a><a name="b1832248390165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1224776340165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206417604165634"><a name="p1206417604165634"></a><a name="p1206417604165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p682598489165634"><a name="p682598489165634"></a><a name="p682598489165634"></a> </p>
<p id="p687610977165634"><a name="p687610977165634"></a><a name="p687610977165634"></a>A constructor used to create an <strong id="b806501315165634"><a name="b806501315165634"></a><a name="b806501315165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1646645217165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p308288570165634"><a name="p308288570165634"></a><a name="p308288570165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1812519190165634"><a name="p1812519190165634"></a><a name="p1812519190165634"></a>virtual </p>
<p id="p1491056048165634"><a name="p1491056048165634"></a><a name="p1491056048165634"></a>A destructor used to delete the <strong id="b1769858265165634"><a name="b1769858265165634"></a><a name="b1769858265165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1840640915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1928767368165634"><a name="p1928767368165634"></a><a name="p1928767368165634"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1366778784165634"><a name="p1366778784165634"></a><a name="p1366778784165634"></a>virtual bool </p>
<p id="p1888337160165634"><a name="p1888337160165634"></a><a name="p1888337160165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1761365522165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578528730165634"><a name="p578528730165634"></a><a name="p578528730165634"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1622147971165634"><a name="p1622147971165634"></a><a name="p1622147971165634"></a>virtual void </p>
<p id="p121912869165634"><a name="p121912869165634"></a><a name="p121912869165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1834961559165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633930216165634"><a name="p1633930216165634"></a><a name="p1633930216165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742331494165634"><a name="p1742331494165634"></a><a name="p1742331494165634"></a>virtual void </p>
<p id="p182604394165634"><a name="p182604394165634"></a><a name="p182604394165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row684646757165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p717545176165634"><a name="p717545176165634"></a><a name="p717545176165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1901621853165634"><a name="p1901621853165634"></a><a name="p1901621853165634"></a>virtual void </p>
<p id="p1104403718165634"><a name="p1104403718165634"></a><a name="p1104403718165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row250333439165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p869473701165634"><a name="p869473701165634"></a><a name="p869473701165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141966742165634"><a name="p1141966742165634"></a><a name="p1141966742165634"></a>void </p>
<p id="p175193962165634"><a name="p175193962165634"></a><a name="p175193962165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1092624541165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p507210470165634"><a name="p507210470165634"></a><a name="p507210470165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541683254165634"><a name="p1541683254165634"></a><a name="p1541683254165634"></a>void </p>
<p id="p1072420430165634"><a name="p1072420430165634"></a><a name="p1072420430165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1858423835165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p318509394165634"><a name="p318509394165634"></a><a name="p318509394165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050566520165634"><a name="p2050566520165634"></a><a name="p2050566520165634"></a>virtual bool </p>
<p id="p1378096541165634"><a name="p1378096541165634"></a><a name="p1378096541165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1143072988165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994248605165634"><a name="p1994248605165634"></a><a name="p1994248605165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540166232165634"><a name="p540166232165634"></a><a name="p540166232165634"></a>virtual bool </p>
<p id="p2038675004165634"><a name="p2038675004165634"></a><a name="p2038675004165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row601433041165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254278535165634"><a name="p254278535165634"></a><a name="p254278535165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934654407165634"><a name="p1934654407165634"></a><a name="p1934654407165634"></a>virtual void </p>
<p id="p1164784998165634"><a name="p1164784998165634"></a><a name="p1164784998165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row535605819165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1581955807165634"><a name="p1581955807165634"></a><a name="p1581955807165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927283312165634"><a name="p927283312165634"></a><a name="p927283312165634"></a>virtual void </p>
<p id="p502937409165634"><a name="p502937409165634"></a><a name="p502937409165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1047413866165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p281199297165634"><a name="p281199297165634"></a><a name="p281199297165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532429996165634"><a name="p1532429996165634"></a><a name="p1532429996165634"></a>virtual void </p>
<p id="p1530192491165634"><a name="p1530192491165634"></a><a name="p1530192491165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row2012267886165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p301185310165634"><a name="p301185310165634"></a><a name="p301185310165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1736998667165634"><a name="p1736998667165634"></a><a name="p1736998667165634"></a>virtual void </p>
<p id="p605454970165634"><a name="p605454970165634"></a><a name="p605454970165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row624103744165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248717194165634"><a name="p1248717194165634"></a><a name="p1248717194165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1869812201165634"><a name="p1869812201165634"></a><a name="p1869812201165634"></a>void </p>
<p id="p2061064647165634"><a name="p2061064647165634"></a><a name="p2061064647165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1569884866165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120093605165634"><a name="p1120093605165634"></a><a name="p1120093605165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p62732266165634"><a name="p62732266165634"></a><a name="p62732266165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1772837722165634"><a name="p1772837722165634"></a><a name="p1772837722165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1080703649165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573037900165634"><a name="p1573037900165634"></a><a name="p1573037900165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282763395165634"><a name="p1282763395165634"></a><a name="p1282763395165634"></a>void </p>
<p id="p1552569126165634"><a name="p1552569126165634"></a><a name="p1552569126165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1894949914165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1048604502165634"><a name="p1048604502165634"></a><a name="p1048604502165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1675396281165634"><a name="p1675396281165634"></a><a name="p1675396281165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p135948006165634"><a name="p135948006165634"></a><a name="p135948006165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row2053881774165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079346575165634"><a name="p2079346575165634"></a><a name="p2079346575165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1649487820165634"><a name="p1649487820165634"></a><a name="p1649487820165634"></a>void </p>
<p id="p2035781510165634"><a name="p2035781510165634"></a><a name="p2035781510165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row189737878165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328164466165634"><a name="p328164466165634"></a><a name="p328164466165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1925329336165634"><a name="p1925329336165634"></a><a name="p1925329336165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p101066575165634"><a name="p101066575165634"></a><a name="p101066575165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row12429165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1368691676165634"><a name="p1368691676165634"></a><a name="p1368691676165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905015952165634"><a name="p1905015952165634"></a><a name="p1905015952165634"></a>void </p>
<p id="p1713793528165634"><a name="p1713793528165634"></a><a name="p1713793528165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row2067507621165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523066600165634"><a name="p1523066600165634"></a><a name="p1523066600165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905610181165634"><a name="p1905610181165634"></a><a name="p1905610181165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p865459118165634"><a name="p865459118165634"></a><a name="p865459118165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1816024670165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168354451165634"><a name="p168354451165634"></a><a name="p168354451165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1950458489165634"><a name="p1950458489165634"></a><a name="p1950458489165634"></a>void </p>
<p id="p1390523339165634"><a name="p1390523339165634"></a><a name="p1390523339165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1178185816165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376912753165634"><a name="p1376912753165634"></a><a name="p1376912753165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695939565165634"><a name="p1695939565165634"></a><a name="p1695939565165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1896114975165634"><a name="p1896114975165634"></a><a name="p1896114975165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1795711435165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p590363821165634"><a name="p590363821165634"></a><a name="p590363821165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1013588614165634"><a name="p1013588614165634"></a><a name="p1013588614165634"></a>void </p>
<p id="p633647496165634"><a name="p633647496165634"></a><a name="p633647496165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1168699594165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635993268165634"><a name="p1635993268165634"></a><a name="p1635993268165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1887002793165634"><a name="p1887002793165634"></a><a name="p1887002793165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p504435260165634"><a name="p504435260165634"></a><a name="p504435260165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row12037209165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32567312165634"><a name="p32567312165634"></a><a name="p32567312165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833437731165634"><a name="p833437731165634"></a><a name="p833437731165634"></a>virtual void </p>
<p id="p822854713165634"><a name="p822854713165634"></a><a name="p822854713165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1876749533165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p639523130165634"><a name="p639523130165634"></a><a name="p639523130165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p248316415165634"><a name="p248316415165634"></a><a name="p248316415165634"></a>bool </p>
<p id="p1505981973165634"><a name="p1505981973165634"></a><a name="p1505981973165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row834551088165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2055379860165634"><a name="p2055379860165634"></a><a name="p2055379860165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1105821218165634"><a name="p1105821218165634"></a><a name="p1105821218165634"></a>void </p>
<p id="p573471885165634"><a name="p573471885165634"></a><a name="p573471885165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1786365426165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142257052165634"><a name="p142257052165634"></a><a name="p142257052165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p657123053165634"><a name="p657123053165634"></a><a name="p657123053165634"></a>bool </p>
<p id="p1678666881165634"><a name="p1678666881165634"></a><a name="p1678666881165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1548295010165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119326580165634"><a name="p1119326580165634"></a><a name="p1119326580165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1425274989165634"><a name="p1425274989165634"></a><a name="p1425274989165634"></a>void </p>
<p id="p1080576091165634"><a name="p1080576091165634"></a><a name="p1080576091165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row605295152165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p344720009165634"><a name="p344720009165634"></a><a name="p344720009165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35768673165634"><a name="p35768673165634"></a><a name="p35768673165634"></a>bool </p>
<p id="p714917720165634"><a name="p714917720165634"></a><a name="p714917720165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1471106697165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1408751962165634"><a name="p1408751962165634"></a><a name="p1408751962165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948733475165634"><a name="p1948733475165634"></a><a name="p1948733475165634"></a>void </p>
<p id="p821465610165634"><a name="p821465610165634"></a><a name="p821465610165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1256613416165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423380680165634"><a name="p1423380680165634"></a><a name="p1423380680165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p379672230165634"><a name="p379672230165634"></a><a name="p379672230165634"></a>bool </p>
<p id="p690168139165634"><a name="p690168139165634"></a><a name="p690168139165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1515537858165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1752585159165634"><a name="p1752585159165634"></a><a name="p1752585159165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592908142165634"><a name="p1592908142165634"></a><a name="p1592908142165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2051455757165634"><a name="p2051455757165634"></a><a name="p2051455757165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row879912494165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p816330571165634"><a name="p816330571165634"></a><a name="p816330571165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p357150236165634"><a name="p357150236165634"></a><a name="p357150236165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p923096699165634"><a name="p923096699165634"></a><a name="p923096699165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row369457807165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1164103138165634"><a name="p1164103138165634"></a><a name="p1164103138165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p123127243165634"><a name="p123127243165634"></a><a name="p123127243165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p956420114165634"><a name="p956420114165634"></a><a name="p956420114165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1766021642165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399942765165634"><a name="p399942765165634"></a><a name="p399942765165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1193288664165634"><a name="p1193288664165634"></a><a name="p1193288664165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p529348397165634"><a name="p529348397165634"></a><a name="p529348397165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row223745485165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228507111165634"><a name="p228507111165634"></a><a name="p228507111165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354629898165634"><a name="p354629898165634"></a><a name="p354629898165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1359872579165634"><a name="p1359872579165634"></a><a name="p1359872579165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row520072892165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391890690165634"><a name="p391890690165634"></a><a name="p391890690165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2087224386165634"><a name="p2087224386165634"></a><a name="p2087224386165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p713131792165634"><a name="p713131792165634"></a><a name="p713131792165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1438540512165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2072410592165634"><a name="p2072410592165634"></a><a name="p2072410592165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1754784352165634"><a name="p1754784352165634"></a><a name="p1754784352165634"></a>void </p>
<p id="p1061323469165634"><a name="p1061323469165634"></a><a name="p1061323469165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1182630398165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1774504163165634"><a name="p1774504163165634"></a><a name="p1774504163165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1335876351165634"><a name="p1335876351165634"></a><a name="p1335876351165634"></a>virtual void </p>
<p id="p1728778643165634"><a name="p1728778643165634"></a><a name="p1728778643165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row100204480165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p263723986165634"><a name="p263723986165634"></a><a name="p263723986165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1392360228165634"><a name="p1392360228165634"></a><a name="p1392360228165634"></a>virtual int16_t </p>
<p id="p277662968165634"><a name="p277662968165634"></a><a name="p277662968165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1352465819165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102784740165634"><a name="p1102784740165634"></a><a name="p1102784740165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332747869165634"><a name="p332747869165634"></a><a name="p332747869165634"></a>virtual void </p>
<p id="p1457464201165634"><a name="p1457464201165634"></a><a name="p1457464201165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row826230512165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1467762908165634"><a name="p1467762908165634"></a><a name="p1467762908165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283072591165634"><a name="p1283072591165634"></a><a name="p1283072591165634"></a>virtual int16_t </p>
<p id="p67720515165634"><a name="p67720515165634"></a><a name="p67720515165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1405100175165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p564644126165634"><a name="p564644126165634"></a><a name="p564644126165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28877430165634"><a name="p28877430165634"></a><a name="p28877430165634"></a>virtual void </p>
<p id="p551021495165634"><a name="p551021495165634"></a><a name="p551021495165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row262599084165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p272350860165634"><a name="p272350860165634"></a><a name="p272350860165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090355831165634"><a name="p2090355831165634"></a><a name="p2090355831165634"></a>virtual void </p>
<p id="p817613444165634"><a name="p817613444165634"></a><a name="p817613444165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1589258432165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1923526333165634"><a name="p1923526333165634"></a><a name="p1923526333165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p996779238165634"><a name="p996779238165634"></a><a name="p996779238165634"></a>int16_t </p>
<p id="p1038194330165634"><a name="p1038194330165634"></a><a name="p1038194330165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row103979231165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p515512749165634"><a name="p515512749165634"></a><a name="p515512749165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030457380165634"><a name="p1030457380165634"></a><a name="p1030457380165634"></a>virtual void </p>
<p id="p157446639165634"><a name="p157446639165634"></a><a name="p157446639165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2118071262165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466451526165634"><a name="p466451526165634"></a><a name="p466451526165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p271038747165634"><a name="p271038747165634"></a><a name="p271038747165634"></a>int16_t </p>
<p id="p466917200165634"><a name="p466917200165634"></a><a name="p466917200165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row295312144165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563539929165634"><a name="p563539929165634"></a><a name="p563539929165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2089944519165634"><a name="p2089944519165634"></a><a name="p2089944519165634"></a>virtual void </p>
<p id="p543090602165634"><a name="p543090602165634"></a><a name="p543090602165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row2144451431165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156321675165634"><a name="p156321675165634"></a><a name="p156321675165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832839024165634"><a name="p1832839024165634"></a><a name="p1832839024165634"></a>virtual void </p>
<p id="p808138163165634"><a name="p808138163165634"></a><a name="p808138163165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1281008604165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1705735716165634"><a name="p1705735716165634"></a><a name="p1705735716165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025342656165634"><a name="p2025342656165634"></a><a name="p2025342656165634"></a>bool </p>
<p id="p688466064165634"><a name="p688466064165634"></a><a name="p688466064165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1139844081165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755996686165634"><a name="p1755996686165634"></a><a name="p1755996686165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2097549222165634"><a name="p2097549222165634"></a><a name="p2097549222165634"></a>void </p>
<p id="p1565544022165634"><a name="p1565544022165634"></a><a name="p1565544022165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row143156759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1785809616165634"><a name="p1785809616165634"></a><a name="p1785809616165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p793263639165634"><a name="p793263639165634"></a><a name="p793263639165634"></a>void </p>
<p id="p2007786121165634"><a name="p2007786121165634"></a><a name="p2007786121165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row2131243784165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425112416165634"><a name="p1425112416165634"></a><a name="p1425112416165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1414671719165634"><a name="p1414671719165634"></a><a name="p1414671719165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p454512559165634"><a name="p454512559165634"></a><a name="p454512559165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1072351878165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p387603291165634"><a name="p387603291165634"></a><a name="p387603291165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1386005783165634"><a name="p1386005783165634"></a><a name="p1386005783165634"></a>void </p>
<p id="p347413688165634"><a name="p347413688165634"></a><a name="p347413688165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1037132330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1270349292165634"><a name="p1270349292165634"></a><a name="p1270349292165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651637610165634"><a name="p1651637610165634"></a><a name="p1651637610165634"></a>const char * </p>
<p id="p686953529165634"><a name="p686953529165634"></a><a name="p686953529165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1601742657165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1037459081165634"><a name="p1037459081165634"></a><a name="p1037459081165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922263698165634"><a name="p922263698165634"></a><a name="p922263698165634"></a>void </p>
<p id="p198526185165634"><a name="p198526185165634"></a><a name="p198526185165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row2017489929165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139879754165634"><a name="p1139879754165634"></a><a name="p1139879754165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964798514165634"><a name="p1964798514165634"></a><a name="p1964798514165634"></a>int16_t </p>
<p id="p1326903204165634"><a name="p1326903204165634"></a><a name="p1326903204165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row101422405165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374607268165634"><a name="p1374607268165634"></a><a name="p1374607268165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432721589165634"><a name="p1432721589165634"></a><a name="p1432721589165634"></a>virtual void </p>
<p id="p1452422836165634"><a name="p1452422836165634"></a><a name="p1452422836165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row10552158165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p791592664165634"><a name="p791592664165634"></a><a name="p791592664165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717312004165634"><a name="p717312004165634"></a><a name="p717312004165634"></a>void </p>
<p id="p1016544259165634"><a name="p1016544259165634"></a><a name="p1016544259165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row630296769165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961705091165634"><a name="p961705091165634"></a><a name="p961705091165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837261024165634"><a name="p1837261024165634"></a><a name="p1837261024165634"></a>void </p>
<p id="p878670223165634"><a name="p878670223165634"></a><a name="p878670223165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1793547714165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1543985928165634"><a name="p1543985928165634"></a><a name="p1543985928165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p471912102165634"><a name="p471912102165634"></a><a name="p471912102165634"></a>void </p>
<p id="p142487155165634"><a name="p142487155165634"></a><a name="p142487155165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row2081547619165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587372793165634"><a name="p587372793165634"></a><a name="p587372793165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393786293165634"><a name="p1393786293165634"></a><a name="p1393786293165634"></a>void </p>
<p id="p1215841906165634"><a name="p1215841906165634"></a><a name="p1215841906165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1310730218165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1244134048165634"><a name="p1244134048165634"></a><a name="p1244134048165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664575601165634"><a name="p1664575601165634"></a><a name="p1664575601165634"></a>void </p>
<p id="p2113538006165634"><a name="p2113538006165634"></a><a name="p2113538006165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1813973404165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1679701380165634"><a name="p1679701380165634"></a><a name="p1679701380165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p984652905165634"><a name="p984652905165634"></a><a name="p984652905165634"></a>void </p>
<p id="p432223339165634"><a name="p432223339165634"></a><a name="p432223339165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row21488001165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p46634176165634"><a name="p46634176165634"></a><a name="p46634176165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185850467165634"><a name="p1185850467165634"></a><a name="p1185850467165634"></a>void </p>
<p id="p325986383165634"><a name="p325986383165634"></a><a name="p325986383165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row822543016165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237097665165634"><a name="p237097665165634"></a><a name="p237097665165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255869532165634"><a name="p1255869532165634"></a><a name="p1255869532165634"></a>void </p>
<p id="p2100758643165634"><a name="p2100758643165634"></a><a name="p2100758643165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row664433456165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704358377165634"><a name="p704358377165634"></a><a name="p704358377165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p41797530165634"><a name="p41797530165634"></a><a name="p41797530165634"></a>void </p>
<p id="p1005007999165634"><a name="p1005007999165634"></a><a name="p1005007999165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row2045781887165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1632473756165634"><a name="p1632473756165634"></a><a name="p1632473756165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1842032656165634"><a name="p1842032656165634"></a><a name="p1842032656165634"></a>void </p>
<p id="p1157292181165634"><a name="p1157292181165634"></a><a name="p1157292181165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row771280459165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281582402165634"><a name="p1281582402165634"></a><a name="p1281582402165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p83719128165634"><a name="p83719128165634"></a><a name="p83719128165634"></a>void </p>
<p id="p239008890165634"><a name="p239008890165634"></a><a name="p239008890165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1394243319165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p953258890165634"><a name="p953258890165634"></a><a name="p953258890165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816253249165634"><a name="p1816253249165634"></a><a name="p1816253249165634"></a>void </p>
<p id="p1146357004165634"><a name="p1146357004165634"></a><a name="p1146357004165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row505751452165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523000806165634"><a name="p1523000806165634"></a><a name="p1523000806165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p67558477165634"><a name="p67558477165634"></a><a name="p67558477165634"></a>void </p>
<p id="p1469143664165634"><a name="p1469143664165634"></a><a name="p1469143664165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row453427694165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p770371707165634"><a name="p770371707165634"></a><a name="p770371707165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1004336379165634"><a name="p1004336379165634"></a><a name="p1004336379165634"></a>void </p>
<p id="p639532221165634"><a name="p639532221165634"></a><a name="p639532221165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row945760438165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401401096165634"><a name="p1401401096165634"></a><a name="p1401401096165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508522717165634"><a name="p1508522717165634"></a><a name="p1508522717165634"></a>void </p>
<p id="p590570478165634"><a name="p590570478165634"></a><a name="p590570478165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1618035497165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p317686946165634"><a name="p317686946165634"></a><a name="p317686946165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776533954165634"><a name="p776533954165634"></a><a name="p776533954165634"></a>void </p>
<p id="p573530354165634"><a name="p573530354165634"></a><a name="p573530354165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row558790235165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p819529009165634"><a name="p819529009165634"></a><a name="p819529009165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1114481300165634"><a name="p1114481300165634"></a><a name="p1114481300165634"></a>virtual void </p>
<p id="p1461528895165634"><a name="p1461528895165634"></a><a name="p1461528895165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1123386005165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p842866964165634"><a name="p842866964165634"></a><a name="p842866964165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330561278165634"><a name="p1330561278165634"></a><a name="p1330561278165634"></a>virtual int64_t </p>
<p id="p272419490165634"><a name="p272419490165634"></a><a name="p272419490165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1131186594165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1549001508165634"><a name="p1549001508165634"></a><a name="p1549001508165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886022543165634"><a name="p1886022543165634"></a><a name="p1886022543165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p46757675165634"><a name="p46757675165634"></a><a name="p46757675165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row79949875165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p987455716165634"><a name="p987455716165634"></a><a name="p987455716165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446975028165634"><a name="p446975028165634"></a><a name="p446975028165634"></a>void * </p>
<p id="p496151500165634"><a name="p496151500165634"></a><a name="p496151500165634"></a>Overrides the <strong id="b598792185165634"><a name="b598792185165634"></a><a name="b598792185165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row539594581165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688673602165634"><a name="p688673602165634"></a><a name="p688673602165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1673822824165634"><a name="p1673822824165634"></a><a name="p1673822824165634"></a>void </p>
<p id="p1095500175165634"><a name="p1095500175165634"></a><a name="p1095500175165634"></a>Overrides the <strong id="b1720755424165634"><a name="b1720755424165634"></a><a name="b1720755424165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Attributes<a name="pub-static-attribs"></a>

<a name="table710848619165634"></a>
<table><thead align="left"><tr id="row172028872165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1247651792165634"><a name="p1247651792165634"></a><a name="p1247651792165634"></a>Static Public Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2012704439165634"><a name="p2012704439165634"></a><a name="p2012704439165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1184738298165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1133290616165634"><a name="p1133290616165634"></a><a name="p1133290616165634"></a><a href="Graphic.md#ga34dfbde0fad8baade31c02d9e8dd5026">HORIZONTAL</a> = 0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173239201165634"><a name="p1173239201165634"></a><a name="p1173239201165634"></a>Indicates the horizontal direction. </p>
</td>
</tr>
<tr id="row908699126165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p911487107165634"><a name="p911487107165634"></a><a name="p911487107165634"></a><a href="Graphic.md#gacb8ccc9545b6c306f9eff97eaf5276aa">VERTICAL</a> = 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777420390165634"><a name="p777420390165634"></a><a name="p777420390165634"></a>Indicates the vertical direction. </p>
</td>
</tr>
</tbody>
</table>

## Protected Member Functions<a name="pro-methods"></a>

<a name="table2003796074165634"></a>
<table><thead align="left"><tr id="row1194274108165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p470257394165634"><a name="p470257394165634"></a><a name="p470257394165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1122281781165634"><a name="p1122281781165634"></a><a name="p1122281781165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row408111083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991283268165634"><a name="p991283268165634"></a><a name="p991283268165634"></a><a href="Graphic.md#ga4db88368bb4908ee05aa1137982b6d0e">MoveChildByOffset</a> (int16_t xOffset, int16_t yOffset) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p437563993165634"><a name="p437563993165634"></a><a name="p437563993165634"></a>void </p>
<p id="p1391145764165634"><a name="p1391145764165634"></a><a name="p1391145764165634"></a>Moves the position of all child views. </p>
</td>
</tr>
<tr id="row1334897418165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p609231933165634"><a name="p609231933165634"></a><a name="p609231933165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225360916165634"><a name="p1225360916165634"></a><a name="p1225360916165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1516993716165634"><a name="p1516993716165634"></a><a name="p1516993716165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1965572994165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p274141456165634"><a name="p274141456165634"></a><a name="p274141456165634"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1290129405165634"><a name="p1290129405165634"></a><a name="p1290129405165634"></a>virtual void </p>
<p id="p386848570165634"><a name="p386848570165634"></a><a name="p386848570165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
</tbody>
</table>

## Static Protected Attributes<a name="pro-static-attribs"></a>

<a name="table40350728165634"></a>
<table><thead align="left"><tr id="row307168564165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1497121826165634"><a name="p1497121826165634"></a><a name="p1497121826165634"></a>Static Protected Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1649548425165634"><a name="p1649548425165634"></a><a name="p1649548425165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1440046121165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1557358840165634"><a name="p1557358840165634"></a><a name="p1557358840165634"></a><a href="Graphic.md#gadcba2d82501e76cfd140f05c77f96a01">ANIMATOR_TIME</a> = 12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p950962812165634"><a name="p950962812165634"></a><a name="p950962812165634"></a>Indicates that the animation duration is 12 ticks. </p>
</td>
</tr>
<tr id="row1574409991165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1619244177165634"><a name="p1619244177165634"></a><a name="p1619244177165634"></a><a href="Graphic.md#ga0fc4210d617931b5cb229b1ac0313249">STOP_DISTANCE</a> = 5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723220931165634"><a name="p723220931165634"></a><a name="p723220931165634"></a>Indicates the maximum distance of an invalid dragging. Dragging is not triggered if the distance is less than this value. </p>
</td>
</tr>
<tr id="row1870812944165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p227903212165634"><a name="p227903212165634"></a><a name="p227903212165634"></a><a href="Graphic.md#ga81883a607d2cb3356560fc0f8f84cf74">DEFAULT_BLANK_SIZE</a> = 30</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2011856544165634"><a name="p2011856544165634"></a><a name="p2011856544165634"></a>Indicates the maximum distance between the first and the last tab when the current view is not in a cycle swipe mode. The page can be rebound after the setting. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1798936530165634"></a>
<table><thead align="left"><tr id="row1262963378165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2048062262165634"><a name="p2048062262165634"></a><a name="p2048062262165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1012104112165634"><a name="p1012104112165634"></a><a name="p1012104112165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1049544805165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1699508808165634"><a name="p1699508808165634"></a><a name="p1699508808165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071655509165634"><a name="p1071655509165634"></a><a name="p1071655509165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1589473891165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536800452165634"><a name="p536800452165634"></a><a name="p536800452165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144037148165634"><a name="p144037148165634"></a><a name="p144037148165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1730404903165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p226042819165634"><a name="p226042819165634"></a><a name="p226042819165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1077220536165634"><a name="p1077220536165634"></a><a name="p1077220536165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1875984274165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p827286840165634"><a name="p827286840165634"></a><a name="p827286840165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653942467165634"><a name="p653942467165634"></a><a name="p653942467165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row477136213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805319733165634"><a name="p805319733165634"></a><a name="p805319733165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450825904165634"><a name="p450825904165634"></a><a name="p450825904165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row286898089165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p561992596165634"><a name="p561992596165634"></a><a name="p561992596165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p655943491165634"><a name="p655943491165634"></a><a name="p655943491165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

