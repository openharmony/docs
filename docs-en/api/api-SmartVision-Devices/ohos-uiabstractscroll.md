# OHOS::UIAbstractScroll<a name="EN-US_TOPIC_0000001054598181"></a>

-   [Overview](#section219622185165633)
-   [Summary](#section1189512298165633)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section219622185165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the attributes of a scroll, including the scroll direction, blank size of a scroll view, velocity and effects of a scroll animation. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1189512298165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table915560397165633"></a>
<table><thead align="left"><tr id="row187305225165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p496005272165633"><a name="p496005272165633"></a><a name="p496005272165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2113395232165633"><a name="p2113395232165633"></a><a name="p2113395232165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1880818466165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990271187165633"><a name="p990271187165633"></a><a name="p990271187165633"></a><a href="graphic.md#ga93a169fba7c98f6534692cba9e8d539b">UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823990490165633"><a name="p1823990490165633"></a><a name="p1823990490165633"></a> </p>
<p id="p246285200165633"><a name="p246285200165633"></a><a name="p246285200165633"></a>A constructor used to create a <strong id="b605589385165633"><a name="b605589385165633"></a><a name="b605589385165633"></a><a href="ohos-uiabstractscroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row121827637165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405234080165633"><a name="p405234080165633"></a><a name="p405234080165633"></a><a href="graphic.md#ga414798ec7357edc85409128fba0a813c">~UIAbstractScroll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426426240165633"><a name="p426426240165633"></a><a name="p426426240165633"></a>virtual </p>
<p id="p663829140165633"><a name="p663829140165633"></a><a name="p663829140165633"></a>A destructor used to delete the <strong id="b957247206165633"><a name="b957247206165633"></a><a name="b957247206165633"></a><a href="ohos-uiabstractscroll.md">UIAbstractScroll</a></strong> instance. </p>
</td>
</tr>
<tr id="row1504259031165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p698408141165633"><a name="p698408141165633"></a><a name="p698408141165633"></a><a href="graphic.md#gaeb9e84901b38ef75fa650fc5a27ffc65">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590794484165633"><a name="p590794484165633"></a><a name="p590794484165633"></a>UIViewType </p>
<p id="p1926797701165633"><a name="p1926797701165633"></a><a name="p1926797701165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1569819842165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500830310165633"><a name="p1500830310165633"></a><a name="p1500830310165633"></a><a href="graphic.md#ga443783170697bea9a933843ad2a92283">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1158652395165633"><a name="p1158652395165633"></a><a name="p1158652395165633"></a>uint8_t </p>
<p id="p1649564384165633"><a name="p1649564384165633"></a><a name="p1649564384165633"></a>Obtains the scroll direction. </p>
</td>
</tr>
<tr id="row700812817165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1520437461165633"><a name="p1520437461165633"></a><a name="p1520437461165633"></a><a href="graphic.md#gab37cea97d63ee9ca609c9a1ed0f1e281">SetScrollBlankSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p764382046165633"><a name="p764382046165633"></a><a name="p764382046165633"></a>void </p>
<p id="p740124804165633"><a name="p740124804165633"></a><a name="p740124804165633"></a>Sets the blank size for this scroll view. </p>
</td>
</tr>
<tr id="row307791928165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061842556165633"><a name="p2061842556165633"></a><a name="p2061842556165633"></a><a href="graphic.md#gae2d6f5c97a316ecd3b41fecfa35a351f">SetMaxScrollDistance</a> (uint16_t distance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628877548165633"><a name="p628877548165633"></a><a name="p628877548165633"></a>void </p>
<p id="p1064228187165633"><a name="p1064228187165633"></a><a name="p1064228187165633"></a>Sets the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row333255679165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559343253165633"><a name="p559343253165633"></a><a name="p559343253165633"></a><a href="graphic.md#ga5d7fefcd2057e868a8f6c6a6000aa7ef">SetReboundSize</a> (uint16_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989156466165633"><a name="p989156466165633"></a><a name="p989156466165633"></a>void </p>
<p id="p1791903055165633"><a name="p1791903055165633"></a><a name="p1791903055165633"></a>Sets the rebound size, which is the distance a knob moves after being released when it reaches the end of a scrollbar. </p>
</td>
</tr>
<tr id="row1483989596165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1179498066165633"><a name="p1179498066165633"></a><a name="p1179498066165633"></a><a href="graphic.md#ga71a2b17d4145479ed2e2ca000eb7e86e">GetMaxScrollDistance</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p467515963165633"><a name="p467515963165633"></a><a name="p467515963165633"></a>uint16_t </p>
<p id="p1411825299165633"><a name="p1411825299165633"></a><a name="p1411825299165633"></a>Obtains the maximum scroll distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row324499348165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567244805165633"><a name="p1567244805165633"></a><a name="p1567244805165633"></a><a href="graphic.md#ga957ec65a7efad6818be6df5169158aad">SetDragFunc</a> (EasingFunc func)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511757866165633"><a name="p1511757866165633"></a><a name="p1511757866165633"></a>void </p>
<p id="p577769567165633"><a name="p577769567165633"></a><a name="p577769567165633"></a>Sets the easing function that specifies a scroll animation after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row380812078165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916991576165633"><a name="p916991576165633"></a><a name="p916991576165633"></a><a href="graphic.md#ga4dde5f89d70304e77a96d4f4679438c2">SetThrowDrag</a> (bool throwDrag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220196702165633"><a name="p1220196702165633"></a><a name="p1220196702165633"></a>void </p>
<p id="p1857831233165633"><a name="p1857831233165633"></a><a name="p1857831233165633"></a>Sets whether to continue scrolling after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row933410188165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1871200184165633"><a name="p1871200184165633"></a><a name="p1871200184165633"></a><a href="graphic.md#ga5013215d3075616ae081849ef52bb57a">MoveChildByOffset</a> (int16_t offsetX, int16_t offsetY) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p71754512165633"><a name="p71754512165633"></a><a name="p71754512165633"></a>void </p>
<p id="p2026178391165633"><a name="p2026178391165633"></a><a name="p2026178391165633"></a>Moves the position of all child views. </p>
</td>
</tr>
<tr id="row1174070725165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55412929165633"><a name="p55412929165633"></a><a name="p55412929165633"></a><a href="graphic.md#gad344babd5b251ed908cdf628fae55093">SetDragACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914569176165633"><a name="p914569176165633"></a><a name="p914569176165633"></a>void </p>
<p id="p1540856616165633"><a name="p1540856616165633"></a><a name="p1540856616165633"></a>Sets the drag acceleration. </p>
</td>
</tr>
<tr id="row891962391165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p213738577165633"><a name="p213738577165633"></a><a name="p213738577165633"></a><a href="graphic.md#ga29e68195b56783f265d85506f130c664">GetDragACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1218941251165633"><a name="p1218941251165633"></a><a name="p1218941251165633"></a>uint8_t </p>
<p id="p1681360483165633"><a name="p1681360483165633"></a><a name="p1681360483165633"></a>Obtains the drag acceleration. </p>
</td>
</tr>
<tr id="row1144687543165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141849795165633"><a name="p1141849795165633"></a><a name="p1141849795165633"></a><a href="graphic.md#gafab9d1a8f5987b50f9111c733ada6341">SetSwipeACCLevel</a> (uint16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1505526219165633"><a name="p1505526219165633"></a><a name="p1505526219165633"></a>void </p>
<p id="p597249678165633"><a name="p597249678165633"></a><a name="p597249678165633"></a>Sets the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1301634832165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2137555438165633"><a name="p2137555438165633"></a><a name="p2137555438165633"></a><a href="graphic.md#ga25dad3242949f0fbeff47d6df06053f6">GetSwipeACCLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p868138471165633"><a name="p868138471165633"></a><a name="p868138471165633"></a>uint8_t </p>
<p id="p638378778165633"><a name="p638378778165633"></a><a name="p638378778165633"></a>Obtains the compensation distance after a finger lifts the screen. </p>
</td>
</tr>
<tr id="row1565581582165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399717993165633"><a name="p399717993165633"></a><a name="p399717993165633"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p16722643165633"><a name="p16722643165633"></a><a name="p16722643165633"></a> </p>
<p id="p2123983165633"><a name="p2123983165633"></a><a name="p2123983165633"></a>A default constructor used to create a <strong id="b1280838031165633"><a name="b1280838031165633"></a><a name="b1280838031165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1970296458165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1568982677165633"><a name="p1568982677165633"></a><a name="p1568982677165633"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247048534165633"><a name="p247048534165633"></a><a name="p247048534165633"></a>virtual </p>
<p id="p2005746641165633"><a name="p2005746641165633"></a><a name="p2005746641165633"></a>A destructor used to delete the <strong id="b1365269127165633"><a name="b1365269127165633"></a><a name="b1365269127165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1580089707165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830997718165633"><a name="p830997718165633"></a><a name="p830997718165633"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33220691165633"><a name="p33220691165633"></a><a name="p33220691165633"></a>UIViewType </p>
<p id="p1521619991165633"><a name="p1521619991165633"></a><a name="p1521619991165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1158432124165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1608251600165633"><a name="p1608251600165633"></a><a name="p1608251600165633"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951511255165633"><a name="p951511255165633"></a><a name="p951511255165633"></a>virtual void </p>
<p id="p1933656849165633"><a name="p1933656849165633"></a><a name="p1933656849165633"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1607550770165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1361422552165633"><a name="p1361422552165633"></a><a name="p1361422552165633"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397294837165633"><a name="p397294837165633"></a><a name="p397294837165633"></a>virtual void </p>
<p id="p821573172165633"><a name="p821573172165633"></a><a name="p821573172165633"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row992730760165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1458872292165633"><a name="p1458872292165633"></a><a name="p1458872292165633"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1902210175165633"><a name="p1902210175165633"></a><a name="p1902210175165633"></a>virtual void </p>
<p id="p1849470841165633"><a name="p1849470841165633"></a><a name="p1849470841165633"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1569959147165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129844181165633"><a name="p129844181165633"></a><a name="p129844181165633"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381220176165633"><a name="p1381220176165633"></a><a name="p1381220176165633"></a>virtual void </p>
<p id="p1885342843165633"><a name="p1885342843165633"></a><a name="p1885342843165633"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1671694487165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1086475870165633"><a name="p1086475870165633"></a><a name="p1086475870165633"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606803461165633"><a name="p1606803461165633"></a><a name="p1606803461165633"></a>virtual void </p>
<p id="p1440705233165633"><a name="p1440705233165633"></a><a name="p1440705233165633"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1107344642165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696620932165633"><a name="p696620932165633"></a><a name="p696620932165633"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163880588165633"><a name="p163880588165633"></a><a name="p163880588165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p352426985165633"><a name="p352426985165633"></a><a name="p352426985165633"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1427302431165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369583221165633"><a name="p369583221165633"></a><a name="p369583221165633"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804258770165633"><a name="p804258770165633"></a><a name="p804258770165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p37227162165633"><a name="p37227162165633"></a><a name="p37227162165633"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row2052123915165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584561964165633"><a name="p1584561964165633"></a><a name="p1584561964165633"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p905344852165633"><a name="p905344852165633"></a><a name="p905344852165633"></a>void </p>
<p id="p1142877616165633"><a name="p1142877616165633"></a><a name="p1142877616165633"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row962007539165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p71083252165633"><a name="p71083252165633"></a><a name="p71083252165633"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145959740165633"><a name="p1145959740165633"></a><a name="p1145959740165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p885285141165633"><a name="p885285141165633"></a><a name="p885285141165633"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row168081214165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1586091182165633"><a name="p1586091182165633"></a><a name="p1586091182165633"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p291967087165633"><a name="p291967087165633"></a><a name="p291967087165633"></a>void </p>
<p id="p916337175165633"><a name="p916337175165633"></a><a name="p916337175165633"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row2042833803165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1338271843165633"><a name="p1338271843165633"></a><a name="p1338271843165633"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977046221165633"><a name="p1977046221165633"></a><a name="p1977046221165633"></a> </p>
<p id="p1034629971165633"><a name="p1034629971165633"></a><a name="p1034629971165633"></a>A default constructor used to create an <strong id="b1657544288165633"><a name="b1657544288165633"></a><a name="b1657544288165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1526063408165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314366931165633"><a name="p314366931165633"></a><a name="p314366931165633"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144071258165633"><a name="p144071258165633"></a><a name="p144071258165633"></a> </p>
<p id="p674429144165633"><a name="p674429144165633"></a><a name="p674429144165633"></a>A constructor used to create an <strong id="b1131161144165633"><a name="b1131161144165633"></a><a name="b1131161144165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1857416196165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p258331253165633"><a name="p258331253165633"></a><a name="p258331253165633"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22488872165633"><a name="p22488872165633"></a><a name="p22488872165633"></a>virtual </p>
<p id="p2046913730165633"><a name="p2046913730165633"></a><a name="p2046913730165633"></a>A destructor used to delete the <strong id="b1292816093165633"><a name="b1292816093165633"></a><a name="b1292816093165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row204618784165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296936001165633"><a name="p1296936001165633"></a><a name="p1296936001165633"></a><a href="graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938985322165633"><a name="p1938985322165633"></a><a name="p1938985322165633"></a>virtual bool </p>
<p id="p643270749165633"><a name="p643270749165633"></a><a name="p643270749165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1879179951165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1849430066165633"><a name="p1849430066165633"></a><a name="p1849430066165633"></a><a href="graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p183053984165633"><a name="p183053984165633"></a><a name="p183053984165633"></a>virtual void </p>
<p id="p2134796640165633"><a name="p2134796640165633"></a><a name="p2134796640165633"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row376261295165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p726463171165633"><a name="p726463171165633"></a><a name="p726463171165633"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1589164668165633"><a name="p1589164668165633"></a><a name="p1589164668165633"></a>virtual void </p>
<p id="p1086418193165633"><a name="p1086418193165633"></a><a name="p1086418193165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1489844098165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p110753439165633"><a name="p110753439165633"></a><a name="p110753439165633"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560821508165633"><a name="p560821508165633"></a><a name="p560821508165633"></a>virtual void </p>
<p id="p436815300165633"><a name="p436815300165633"></a><a name="p436815300165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1414553635165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766528733165633"><a name="p1766528733165633"></a><a name="p1766528733165633"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062241955165633"><a name="p2062241955165633"></a><a name="p2062241955165633"></a>void </p>
<p id="p1284883314165633"><a name="p1284883314165633"></a><a name="p1284883314165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row582206839165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051549194165633"><a name="p2051549194165633"></a><a name="p2051549194165633"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1344136213165633"><a name="p1344136213165633"></a><a name="p1344136213165633"></a>void </p>
<p id="p1657946237165633"><a name="p1657946237165633"></a><a name="p1657946237165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row942110968165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1659212952165633"><a name="p1659212952165633"></a><a name="p1659212952165633"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377500455165633"><a name="p1377500455165633"></a><a name="p1377500455165633"></a>virtual bool </p>
<p id="p136787676165633"><a name="p136787676165633"></a><a name="p136787676165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row517854565165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296329649165633"><a name="p296329649165633"></a><a name="p296329649165633"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396099267165633"><a name="p396099267165633"></a><a name="p396099267165633"></a>virtual bool </p>
<p id="p835450333165633"><a name="p835450333165633"></a><a name="p835450333165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1798439025165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p797548475165633"><a name="p797548475165633"></a><a name="p797548475165633"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675354635165633"><a name="p675354635165633"></a><a name="p675354635165633"></a>virtual bool </p>
<p id="p2062714601165633"><a name="p2062714601165633"></a><a name="p2062714601165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row399903069165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545894054165633"><a name="p545894054165633"></a><a name="p545894054165633"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p971781362165633"><a name="p971781362165633"></a><a name="p971781362165633"></a>virtual bool </p>
<p id="p1303448155165633"><a name="p1303448155165633"></a><a name="p1303448155165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row2087703227165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p53107147165633"><a name="p53107147165633"></a><a name="p53107147165633"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p112986140165633"><a name="p112986140165633"></a><a name="p112986140165633"></a>virtual void </p>
<p id="p514898326165633"><a name="p514898326165633"></a><a name="p514898326165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1003848854165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p701948489165633"><a name="p701948489165633"></a><a name="p701948489165633"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2111582998165633"><a name="p2111582998165633"></a><a name="p2111582998165633"></a>virtual void </p>
<p id="p1213452654165633"><a name="p1213452654165633"></a><a name="p1213452654165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1712656812165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196794029165633"><a name="p1196794029165633"></a><a name="p1196794029165633"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034956972165633"><a name="p2034956972165633"></a><a name="p2034956972165633"></a>virtual void </p>
<p id="p539389590165633"><a name="p539389590165633"></a><a name="p539389590165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row301545780165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p941180277165633"><a name="p941180277165633"></a><a name="p941180277165633"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610960133165633"><a name="p1610960133165633"></a><a name="p1610960133165633"></a>virtual void </p>
<p id="p1278421951165633"><a name="p1278421951165633"></a><a name="p1278421951165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row141016381165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p955034977165633"><a name="p955034977165633"></a><a name="p955034977165633"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623277500165633"><a name="p623277500165633"></a><a name="p623277500165633"></a>void </p>
<p id="p1465794978165633"><a name="p1465794978165633"></a><a name="p1465794978165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row2136141419165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998846205165633"><a name="p998846205165633"></a><a name="p998846205165633"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p538306400165633"><a name="p538306400165633"></a><a name="p538306400165633"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1196318624165633"><a name="p1196318624165633"></a><a name="p1196318624165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1178936929165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p349032201165633"><a name="p349032201165633"></a><a name="p349032201165633"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1655284360165633"><a name="p1655284360165633"></a><a name="p1655284360165633"></a>void </p>
<p id="p811975560165633"><a name="p811975560165633"></a><a name="p811975560165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row808314636165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376927135165633"><a name="p376927135165633"></a><a name="p376927135165633"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260020057165633"><a name="p1260020057165633"></a><a name="p1260020057165633"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p561743593165633"><a name="p561743593165633"></a><a name="p561743593165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row2097054647165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1425206546165633"><a name="p1425206546165633"></a><a name="p1425206546165633"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520328493165633"><a name="p520328493165633"></a><a name="p520328493165633"></a>void </p>
<p id="p1159607806165633"><a name="p1159607806165633"></a><a name="p1159607806165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1884685649165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282048398165633"><a name="p1282048398165633"></a><a name="p1282048398165633"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p101050381165633"><a name="p101050381165633"></a><a name="p101050381165633"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p989235850165633"><a name="p989235850165633"></a><a name="p989235850165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1973965248165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364071649165633"><a name="p364071649165633"></a><a name="p364071649165633"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905493633165633"><a name="p1905493633165633"></a><a name="p1905493633165633"></a>void </p>
<p id="p67732964165633"><a name="p67732964165633"></a><a name="p67732964165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1360682111165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425825711165633"><a name="p425825711165633"></a><a name="p425825711165633"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1888791757165633"><a name="p1888791757165633"></a><a name="p1888791757165633"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p903830946165633"><a name="p903830946165633"></a><a name="p903830946165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1496359487165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p334234754165633"><a name="p334234754165633"></a><a name="p334234754165633"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587939278165633"><a name="p587939278165633"></a><a name="p587939278165633"></a>void </p>
<p id="p562192573165633"><a name="p562192573165633"></a><a name="p562192573165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row880762057165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p327909162165633"><a name="p327909162165633"></a><a name="p327909162165633"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p569102773165633"><a name="p569102773165633"></a><a name="p569102773165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p426287267165633"><a name="p426287267165633"></a><a name="p426287267165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row261241877165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p950313972165633"><a name="p950313972165633"></a><a name="p950313972165633"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p101419950165633"><a name="p101419950165633"></a><a name="p101419950165633"></a>void </p>
<p id="p721032876165633"><a name="p721032876165633"></a><a name="p721032876165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1653200583165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884554236165633"><a name="p884554236165633"></a><a name="p884554236165633"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647979363165633"><a name="p647979363165633"></a><a name="p647979363165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p386882043165633"><a name="p386882043165633"></a><a name="p386882043165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1679571612165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1986374352165633"><a name="p1986374352165633"></a><a name="p1986374352165633"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1833603382165633"><a name="p1833603382165633"></a><a name="p1833603382165633"></a>virtual void </p>
<p id="p643770779165633"><a name="p643770779165633"></a><a name="p643770779165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row890747625165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2073724460165633"><a name="p2073724460165633"></a><a name="p2073724460165633"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1740041842165633"><a name="p1740041842165633"></a><a name="p1740041842165633"></a>bool </p>
<p id="p1313577171165633"><a name="p1313577171165633"></a><a name="p1313577171165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row967654234165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579455133165633"><a name="p579455133165633"></a><a name="p579455133165633"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p48901929165633"><a name="p48901929165633"></a><a name="p48901929165633"></a>void </p>
<p id="p1966572102165633"><a name="p1966572102165633"></a><a name="p1966572102165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1835817594165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p246240508165633"><a name="p246240508165633"></a><a name="p246240508165633"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p172728743165633"><a name="p172728743165633"></a><a name="p172728743165633"></a>bool </p>
<p id="p2040052124165633"><a name="p2040052124165633"></a><a name="p2040052124165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1071079729165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071562325165633"><a name="p1071562325165633"></a><a name="p1071562325165633"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p323946181165633"><a name="p323946181165633"></a><a name="p323946181165633"></a>void </p>
<p id="p1479159138165633"><a name="p1479159138165633"></a><a name="p1479159138165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1604383295165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1984658643165633"><a name="p1984658643165633"></a><a name="p1984658643165633"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24985229165633"><a name="p24985229165633"></a><a name="p24985229165633"></a>bool </p>
<p id="p516569834165633"><a name="p516569834165633"></a><a name="p516569834165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row330143842165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p488610414165633"><a name="p488610414165633"></a><a name="p488610414165633"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1162449458165633"><a name="p1162449458165633"></a><a name="p1162449458165633"></a>void </p>
<p id="p290726285165633"><a name="p290726285165633"></a><a name="p290726285165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1445559272165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281047796165633"><a name="p1281047796165633"></a><a name="p1281047796165633"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702879433165633"><a name="p702879433165633"></a><a name="p702879433165633"></a>bool </p>
<p id="p1429223459165633"><a name="p1429223459165633"></a><a name="p1429223459165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row628329207165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1142974965165633"><a name="p1142974965165633"></a><a name="p1142974965165633"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893735575165633"><a name="p1893735575165633"></a><a name="p1893735575165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p213753152165633"><a name="p213753152165633"></a><a name="p213753152165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1088984802165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p355755546165633"><a name="p355755546165633"></a><a name="p355755546165633"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503326581165633"><a name="p1503326581165633"></a><a name="p1503326581165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p201066030165633"><a name="p201066030165633"></a><a name="p201066030165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1224211599165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012427814165633"><a name="p1012427814165633"></a><a name="p1012427814165633"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707165886165633"><a name="p1707165886165633"></a><a name="p1707165886165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p2018203241165633"><a name="p2018203241165633"></a><a name="p2018203241165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1703195076165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1395556630165633"><a name="p1395556630165633"></a><a name="p1395556630165633"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945616679165633"><a name="p945616679165633"></a><a name="p945616679165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1984772226165633"><a name="p1984772226165633"></a><a name="p1984772226165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row655808466165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p693935648165633"><a name="p693935648165633"></a><a name="p693935648165633"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142670062165633"><a name="p1142670062165633"></a><a name="p1142670062165633"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1259966028165633"><a name="p1259966028165633"></a><a name="p1259966028165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1170679777165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360224597165633"><a name="p1360224597165633"></a><a name="p1360224597165633"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p70680284165633"><a name="p70680284165633"></a><a name="p70680284165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p789747715165633"><a name="p789747715165633"></a><a name="p789747715165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row542813482165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p759864214165633"><a name="p759864214165633"></a><a name="p759864214165633"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121772142165633"><a name="p1121772142165633"></a><a name="p1121772142165633"></a>void </p>
<p id="p1670465186165633"><a name="p1670465186165633"></a><a name="p1670465186165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row2115374381165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p867654094165633"><a name="p867654094165633"></a><a name="p867654094165633"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p854510871165633"><a name="p854510871165633"></a><a name="p854510871165633"></a>virtual void </p>
<p id="p250572603165633"><a name="p250572603165633"></a><a name="p250572603165633"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1262660718165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p24945383165633"><a name="p24945383165633"></a><a name="p24945383165633"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91208735165633"><a name="p91208735165633"></a><a name="p91208735165633"></a>virtual int16_t </p>
<p id="p1223003977165633"><a name="p1223003977165633"></a><a name="p1223003977165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row2088968909165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169997442165633"><a name="p169997442165633"></a><a name="p169997442165633"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684124777165633"><a name="p684124777165633"></a><a name="p684124777165633"></a>virtual void </p>
<p id="p1775126630165633"><a name="p1775126630165633"></a><a name="p1775126630165633"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row144170084165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p971055959165633"><a name="p971055959165633"></a><a name="p971055959165633"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771145954165633"><a name="p1771145954165633"></a><a name="p1771145954165633"></a>virtual int16_t </p>
<p id="p699833492165633"><a name="p699833492165633"></a><a name="p699833492165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row2008531637165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501313157165633"><a name="p1501313157165633"></a><a name="p1501313157165633"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2129867365165633"><a name="p2129867365165633"></a><a name="p2129867365165633"></a>virtual void </p>
<p id="p1649439939165633"><a name="p1649439939165633"></a><a name="p1649439939165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row219827126165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1571537220165633"><a name="p1571537220165633"></a><a name="p1571537220165633"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202577224165633"><a name="p202577224165633"></a><a name="p202577224165633"></a>virtual void </p>
<p id="p1574709714165633"><a name="p1574709714165633"></a><a name="p1574709714165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1133533022165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p503765057165633"><a name="p503765057165633"></a><a name="p503765057165633"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877172722165633"><a name="p1877172722165633"></a><a name="p1877172722165633"></a>int16_t </p>
<p id="p985853578165633"><a name="p985853578165633"></a><a name="p985853578165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row165171461165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p285255622165633"><a name="p285255622165633"></a><a name="p285255622165633"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p749422233165633"><a name="p749422233165633"></a><a name="p749422233165633"></a>virtual void </p>
<p id="p106679654165633"><a name="p106679654165633"></a><a name="p106679654165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1963619232165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487711373165633"><a name="p1487711373165633"></a><a name="p1487711373165633"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925367389165633"><a name="p925367389165633"></a><a name="p925367389165633"></a>int16_t </p>
<p id="p1780440083165633"><a name="p1780440083165633"></a><a name="p1780440083165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1277096723165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p675928463165633"><a name="p675928463165633"></a><a name="p675928463165633"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1496883639165633"><a name="p1496883639165633"></a><a name="p1496883639165633"></a>virtual void </p>
<p id="p1244451723165633"><a name="p1244451723165633"></a><a name="p1244451723165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row275705469165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p318759097165633"><a name="p318759097165633"></a><a name="p318759097165633"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p726251810165633"><a name="p726251810165633"></a><a name="p726251810165633"></a>virtual void </p>
<p id="p145584262165633"><a name="p145584262165633"></a><a name="p145584262165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row146412361165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136488129165633"><a name="p136488129165633"></a><a name="p136488129165633"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p630984719165633"><a name="p630984719165633"></a><a name="p630984719165633"></a>bool </p>
<p id="p1069571114165633"><a name="p1069571114165633"></a><a name="p1069571114165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1634988396165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1018099509165633"><a name="p1018099509165633"></a><a name="p1018099509165633"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1662847140165633"><a name="p1662847140165633"></a><a name="p1662847140165633"></a>void </p>
<p id="p1357024235165633"><a name="p1357024235165633"></a><a name="p1357024235165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row31369528165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p355423508165633"><a name="p355423508165633"></a><a name="p355423508165633"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p299074177165633"><a name="p299074177165633"></a><a name="p299074177165633"></a>void </p>
<p id="p1281306013165633"><a name="p1281306013165633"></a><a name="p1281306013165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row894084581165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186729956165633"><a name="p186729956165633"></a><a name="p186729956165633"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872176632165633"><a name="p1872176632165633"></a><a name="p1872176632165633"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p271327637165633"><a name="p271327637165633"></a><a name="p271327637165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row887969524165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862817276165633"><a name="p1862817276165633"></a><a name="p1862817276165633"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p21844489165633"><a name="p21844489165633"></a><a name="p21844489165633"></a>void </p>
<p id="p1546329772165633"><a name="p1546329772165633"></a><a name="p1546329772165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1740175272165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1938974886165633"><a name="p1938974886165633"></a><a name="p1938974886165633"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p823485352165633"><a name="p823485352165633"></a><a name="p823485352165633"></a>const char * </p>
<p id="p1790483111165633"><a name="p1790483111165633"></a><a name="p1790483111165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row874049315165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1668279189165633"><a name="p1668279189165633"></a><a name="p1668279189165633"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485834394165633"><a name="p1485834394165633"></a><a name="p1485834394165633"></a>void </p>
<p id="p1102988368165633"><a name="p1102988368165633"></a><a name="p1102988368165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1029403790165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1571157270165633"><a name="p1571157270165633"></a><a name="p1571157270165633"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1365015152165633"><a name="p1365015152165633"></a><a name="p1365015152165633"></a>int16_t </p>
<p id="p1932218704165633"><a name="p1932218704165633"></a><a name="p1932218704165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1063469779165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1047840980165633"><a name="p1047840980165633"></a><a name="p1047840980165633"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198076602165633"><a name="p1198076602165633"></a><a name="p1198076602165633"></a>virtual void </p>
<p id="p1869047471165633"><a name="p1869047471165633"></a><a name="p1869047471165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1767439506165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1187909798165633"><a name="p1187909798165633"></a><a name="p1187909798165633"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727468512165633"><a name="p1727468512165633"></a><a name="p1727468512165633"></a>void </p>
<p id="p1726133672165633"><a name="p1726133672165633"></a><a name="p1726133672165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row87642039165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685872351165633"><a name="p685872351165633"></a><a name="p685872351165633"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1989059826165633"><a name="p1989059826165633"></a><a name="p1989059826165633"></a>void </p>
<p id="p1153548349165633"><a name="p1153548349165633"></a><a name="p1153548349165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row2143970135165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406924722165633"><a name="p1406924722165633"></a><a name="p1406924722165633"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1907920214165633"><a name="p1907920214165633"></a><a name="p1907920214165633"></a>void </p>
<p id="p1184927488165633"><a name="p1184927488165633"></a><a name="p1184927488165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1022641549165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491704850165633"><a name="p1491704850165633"></a><a name="p1491704850165633"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204357159165633"><a name="p204357159165633"></a><a name="p204357159165633"></a>void </p>
<p id="p65989122165633"><a name="p65989122165633"></a><a name="p65989122165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1785275775165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1413980661165633"><a name="p1413980661165633"></a><a name="p1413980661165633"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p184848040165633"><a name="p184848040165633"></a><a name="p184848040165633"></a>void </p>
<p id="p348840774165633"><a name="p348840774165633"></a><a name="p348840774165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row2063066415165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p780951149165633"><a name="p780951149165633"></a><a name="p780951149165633"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1884458202165633"><a name="p1884458202165633"></a><a name="p1884458202165633"></a>void </p>
<p id="p860185522165633"><a name="p860185522165633"></a><a name="p860185522165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row44778545165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313049746165633"><a name="p313049746165633"></a><a name="p313049746165633"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070225548165633"><a name="p1070225548165633"></a><a name="p1070225548165633"></a>void </p>
<p id="p1595825456165633"><a name="p1595825456165633"></a><a name="p1595825456165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1558209858165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1106256574165633"><a name="p1106256574165633"></a><a name="p1106256574165633"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p272912804165633"><a name="p272912804165633"></a><a name="p272912804165633"></a>void </p>
<p id="p1832585677165633"><a name="p1832585677165633"></a><a name="p1832585677165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1620019042165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058551140165633"><a name="p1058551140165633"></a><a name="p1058551140165633"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p689627631165633"><a name="p689627631165633"></a><a name="p689627631165633"></a>void </p>
<p id="p1569205078165633"><a name="p1569205078165633"></a><a name="p1569205078165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1434022030165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1424148318165633"><a name="p1424148318165633"></a><a name="p1424148318165633"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1979670891165633"><a name="p1979670891165633"></a><a name="p1979670891165633"></a>void </p>
<p id="p952196812165633"><a name="p952196812165633"></a><a name="p952196812165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row41413280165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p842734903165633"><a name="p842734903165633"></a><a name="p842734903165633"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591526921165633"><a name="p591526921165633"></a><a name="p591526921165633"></a>void </p>
<p id="p328288077165633"><a name="p328288077165633"></a><a name="p328288077165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row920401590165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p721036699165633"><a name="p721036699165633"></a><a name="p721036699165633"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p136513984165633"><a name="p136513984165633"></a><a name="p136513984165633"></a>void </p>
<p id="p1756497851165633"><a name="p1756497851165633"></a><a name="p1756497851165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1106541539165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1429108993165633"><a name="p1429108993165633"></a><a name="p1429108993165633"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p349297004165633"><a name="p349297004165633"></a><a name="p349297004165633"></a>void </p>
<p id="p797413380165633"><a name="p797413380165633"></a><a name="p797413380165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row2084447233165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1189088301165633"><a name="p1189088301165633"></a><a name="p1189088301165633"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p472201545165633"><a name="p472201545165633"></a><a name="p472201545165633"></a>void </p>
<p id="p122674109165633"><a name="p122674109165633"></a><a name="p122674109165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row937962388165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1333553681165633"><a name="p1333553681165633"></a><a name="p1333553681165633"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1644205007165633"><a name="p1644205007165633"></a><a name="p1644205007165633"></a>void </p>
<p id="p1153049508165633"><a name="p1153049508165633"></a><a name="p1153049508165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row566706197165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124515539165633"><a name="p2124515539165633"></a><a name="p2124515539165633"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1244952224165633"><a name="p1244952224165633"></a><a name="p1244952224165633"></a>void </p>
<p id="p554769631165633"><a name="p554769631165633"></a><a name="p554769631165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row359064721165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569295046165633"><a name="p1569295046165633"></a><a name="p1569295046165633"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p362652417165633"><a name="p362652417165633"></a><a name="p362652417165633"></a>virtual void </p>
<p id="p2143190190165633"><a name="p2143190190165633"></a><a name="p2143190190165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row331575887165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55698584165633"><a name="p55698584165633"></a><a name="p55698584165633"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786622794165633"><a name="p1786622794165633"></a><a name="p1786622794165633"></a>virtual int64_t </p>
<p id="p129863612165633"><a name="p129863612165633"></a><a name="p129863612165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row668016437165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1903278805165633"><a name="p1903278805165633"></a><a name="p1903278805165633"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018652507165633"><a name="p1018652507165633"></a><a name="p1018652507165633"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p837631171165633"><a name="p837631171165633"></a><a name="p837631171165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1355939484165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381992351165633"><a name="p1381992351165633"></a><a name="p1381992351165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p617502499165633"><a name="p617502499165633"></a><a name="p617502499165633"></a>void * </p>
<p id="p439832924165633"><a name="p439832924165633"></a><a name="p439832924165633"></a>Overrides the <strong id="b337590355165633"><a name="b337590355165633"></a><a name="b337590355165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row912642571165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141319900165633"><a name="p1141319900165633"></a><a name="p1141319900165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236365726165633"><a name="p236365726165633"></a><a name="p236365726165633"></a>void </p>
<p id="p746333217165633"><a name="p746333217165633"></a><a name="p746333217165633"></a>Overrides the <strong id="b1367894471165633"><a name="b1367894471165633"></a><a name="b1367894471165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1744878951165633"></a>
<table><thead align="left"><tr id="row393483787165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p429089248165633"><a name="p429089248165633"></a><a name="p429089248165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p901618591165633"><a name="p901618591165633"></a><a name="p901618591165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row482639729165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777756219165633"><a name="p1777756219165633"></a><a name="p1777756219165633"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410537331165633"><a name="p1410537331165633"></a><a name="p1410537331165633"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row606581728165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50749053165633"><a name="p50749053165633"></a><a name="p50749053165633"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p405371322165633"><a name="p405371322165633"></a><a name="p405371322165633"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row737207986165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p546603714165633"><a name="p546603714165633"></a><a name="p546603714165633"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403825799165633"><a name="p1403825799165633"></a><a name="p1403825799165633"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row850189333165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p113982915165633"><a name="p113982915165633"></a><a name="p113982915165633"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059793826165633"><a name="p2059793826165633"></a><a name="p2059793826165633"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1868682057165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1614191705165633"><a name="p1614191705165633"></a><a name="p1614191705165633"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1362202276165633"><a name="p1362202276165633"></a><a name="p1362202276165633"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1670810445165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868468503165633"><a name="p868468503165633"></a><a name="p868468503165633"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674554141165633"><a name="p674554141165633"></a><a name="p674554141165633"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row649148258165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062756825165633"><a name="p1062756825165633"></a><a name="p1062756825165633"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p456055148165633"><a name="p456055148165633"></a><a name="p456055148165633"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row491100071165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p920148614165633"><a name="p920148614165633"></a><a name="p920148614165633"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181677681165633"><a name="p181677681165633"></a><a name="p181677681165633"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

