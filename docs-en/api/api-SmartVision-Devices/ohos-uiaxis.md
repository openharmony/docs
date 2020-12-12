# OHOS::UIAxis<a name="EN-US_TOPIC_0000001054799621"></a>

-   [Overview](#section1917449989165633)
-   [Summary](#section1016908688165633)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1917449989165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents the coordinate axis base class, which defines the basic attributes of coordinate axis, sets whether a coordinate axis is visible, and sets the number of scales on a coordinate axis. This class is used in  [UIChart](ohos-uichart.md). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1016908688165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1557752267165633"></a>
<table><thead align="left"><tr id="row85711342165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p152680228165633"><a name="p152680228165633"></a><a name="p152680228165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1882064578165633"><a name="p1882064578165633"></a><a name="p1882064578165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row335939355165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909073703165633"><a name="p1909073703165633"></a><a name="p1909073703165633"></a><a href="graphic.md#gad79f1c694abce57af451b8f7b0b17c35">UIAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p634979896165633"><a name="p634979896165633"></a><a name="p634979896165633"></a> </p>
<p id="p1153201982165633"><a name="p1153201982165633"></a><a name="p1153201982165633"></a>A constructor used to create a <strong id="b2021563722165633"><a name="b2021563722165633"></a><a name="b2021563722165633"></a><a href="ohos-uiaxis.md">UIAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row1325864860165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2091860147165633"><a name="p2091860147165633"></a><a name="p2091860147165633"></a><a href="graphic.md#gaacc9ac178b3b235f1186297021eb98d8">~UIAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047248692165633"><a name="p1047248692165633"></a><a name="p1047248692165633"></a>virtual </p>
<p id="p412169853165633"><a name="p412169853165633"></a><a name="p412169853165633"></a>A destructor used to delete the <strong id="b1058258727165633"><a name="b1058258727165633"></a><a name="b1058258727165633"></a><a href="ohos-uiaxis.md">UIAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row1779285770165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1690377322165633"><a name="p1690377322165633"></a><a name="p1690377322165633"></a><a href="graphic.md#ga2f46b702f1543c5076a8957a94a780d3">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763534449165633"><a name="p1763534449165633"></a><a name="p1763534449165633"></a>UIViewType </p>
<p id="p514355619165633"><a name="p514355619165633"></a><a name="p514355619165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row461578501165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406137513165633"><a name="p1406137513165633"></a><a name="p1406137513165633"></a><a href="graphic.md#gabb486419e729add9ff85a24371253bf8">SetDataRange</a> (uint16_t min, uint16_t max)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64909970165633"><a name="p64909970165633"></a><a name="p64909970165633"></a>virtual bool </p>
<p id="p2063670453165633"><a name="p2063670453165633"></a><a name="p2063670453165633"></a>Sets the value range of a coordinate axis. </p>
</td>
</tr>
<tr id="row212194380165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544941480165633"><a name="p544941480165633"></a><a name="p544941480165633"></a><a href="graphic.md#gaebe68b636d2147f2e69bd658696dc4ee">SetMarkNum</a> (uint16_t count)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p448427119165633"><a name="p448427119165633"></a><a name="p448427119165633"></a>virtual void </p>
<p id="p945027501165633"><a name="p945027501165633"></a><a name="p945027501165633"></a>Sets the number of scales on a coordinate axis. </p>
</td>
</tr>
<tr id="row168877101165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1299518718165633"><a name="p1299518718165633"></a><a name="p1299518718165633"></a><a href="graphic.md#ga8ceec5e67fa2c4f161bd9af1f0788bbe">SetLineColor</a> (const <a href="ohos-color32.md">ColorType</a> &amp;color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702100128165633"><a name="p702100128165633"></a><a name="p702100128165633"></a>void </p>
<p id="p1680551580165633"><a name="p1680551580165633"></a><a name="p1680551580165633"></a>Sets the line color of the coordinate axis. </p>
</td>
</tr>
<tr id="row1197060331165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864610510165633"><a name="p1864610510165633"></a><a name="p1864610510165633"></a><a href="graphic.md#ga5360803f425055de52af5f7fa1081cfe">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1529920006165633"><a name="p1529920006165633"></a><a name="p1529920006165633"></a>void </p>
<p id="p853192022165633"><a name="p853192022165633"></a><a name="p853192022165633"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row313856900165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904895919165633"><a name="p1904895919165633"></a><a name="p1904895919165633"></a><a href="graphic.md#gad1bf4d83270c0a4ba04f3cffbc67bb97">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2011725790165633"><a name="p2011725790165633"></a><a name="p2011725790165633"></a>bool </p>
<p id="p139509301165633"><a name="p139509301165633"></a><a name="p139509301165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row2001749128165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1924637783165633"><a name="p1924637783165633"></a><a name="p1924637783165633"></a><a href="graphic.md#ga8ff3fd2953897245e4f6e3cb6bd71495">TranslateToPixel</a> (int16_t &amp;value)=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339523143165633"><a name="p339523143165633"></a><a name="p339523143165633"></a>virtual void </p>
<p id="p1512055091165633"><a name="p1512055091165633"></a><a name="p1512055091165633"></a>Translates data into pixel coordinates. </p>
</td>
</tr>
<tr id="row2055478398165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423102537165633"><a name="p423102537165633"></a><a name="p423102537165633"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667565241165633"><a name="p1667565241165633"></a><a name="p1667565241165633"></a> </p>
<p id="p890086703165633"><a name="p890086703165633"></a><a name="p890086703165633"></a>A default constructor used to create a <strong id="b1644899938165633"><a name="b1644899938165633"></a><a name="b1644899938165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1833480394165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1390848649165633"><a name="p1390848649165633"></a><a name="p1390848649165633"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1290154286165633"><a name="p1290154286165633"></a><a name="p1290154286165633"></a>virtual </p>
<p id="p1602424296165633"><a name="p1602424296165633"></a><a name="p1602424296165633"></a>A destructor used to delete the <strong id="b243124767165633"><a name="b243124767165633"></a><a name="b243124767165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1032001565165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p665446271165633"><a name="p665446271165633"></a><a name="p665446271165633"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724950883165633"><a name="p724950883165633"></a><a name="p724950883165633"></a>UIViewType </p>
<p id="p1440635572165633"><a name="p1440635572165633"></a><a name="p1440635572165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2025056276165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065842854165633"><a name="p2065842854165633"></a><a name="p2065842854165633"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058513672165633"><a name="p1058513672165633"></a><a name="p1058513672165633"></a>virtual void </p>
<p id="p410959671165633"><a name="p410959671165633"></a><a name="p410959671165633"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row425716725165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142545708165633"><a name="p142545708165633"></a><a name="p142545708165633"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489156431165633"><a name="p489156431165633"></a><a name="p489156431165633"></a>virtual void </p>
<p id="p1950010534165633"><a name="p1950010534165633"></a><a name="p1950010534165633"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row991368463165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p537828738165633"><a name="p537828738165633"></a><a name="p537828738165633"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825442011165633"><a name="p825442011165633"></a><a name="p825442011165633"></a>virtual void </p>
<p id="p1612424187165633"><a name="p1612424187165633"></a><a name="p1612424187165633"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1126352614165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114141976165633"><a name="p1114141976165633"></a><a name="p1114141976165633"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319952189165633"><a name="p319952189165633"></a><a name="p319952189165633"></a>virtual void </p>
<p id="p268108125165633"><a name="p268108125165633"></a><a name="p268108125165633"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row780962972165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834160702165633"><a name="p1834160702165633"></a><a name="p1834160702165633"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1254520137165633"><a name="p1254520137165633"></a><a name="p1254520137165633"></a>virtual void </p>
<p id="p1118078885165633"><a name="p1118078885165633"></a><a name="p1118078885165633"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1622876985165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876659253165633"><a name="p876659253165633"></a><a name="p876659253165633"></a><a href="graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1547348292165633"><a name="p1547348292165633"></a><a name="p1547348292165633"></a>virtual void </p>
<p id="p2047668166165633"><a name="p2047668166165633"></a><a name="p2047668166165633"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row970928578165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1333648599165633"><a name="p1333648599165633"></a><a name="p1333648599165633"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1210870495165633"><a name="p1210870495165633"></a><a name="p1210870495165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p2142627155165633"><a name="p2142627155165633"></a><a name="p2142627155165633"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row751797300165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137144090165633"><a name="p137144090165633"></a><a name="p137144090165633"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1289152536165633"><a name="p1289152536165633"></a><a name="p1289152536165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p719478340165633"><a name="p719478340165633"></a><a name="p719478340165633"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row877889774165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579370013165633"><a name="p579370013165633"></a><a name="p579370013165633"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114627840165633"><a name="p2114627840165633"></a><a name="p2114627840165633"></a>void </p>
<p id="p1836006593165633"><a name="p1836006593165633"></a><a name="p1836006593165633"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1698339072165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661939730165633"><a name="p1661939730165633"></a><a name="p1661939730165633"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1512314144165633"><a name="p1512314144165633"></a><a name="p1512314144165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p489072471165633"><a name="p489072471165633"></a><a name="p489072471165633"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row59475634165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167894101165633"><a name="p1167894101165633"></a><a name="p1167894101165633"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926036665165633"><a name="p1926036665165633"></a><a name="p1926036665165633"></a>void </p>
<p id="p1986347513165633"><a name="p1986347513165633"></a><a name="p1986347513165633"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1554694115165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p321094439165633"><a name="p321094439165633"></a><a name="p321094439165633"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123394903165633"><a name="p2123394903165633"></a><a name="p2123394903165633"></a> </p>
<p id="p2122416308165633"><a name="p2122416308165633"></a><a name="p2122416308165633"></a>A default constructor used to create an <strong id="b1023803774165633"><a name="b1023803774165633"></a><a name="b1023803774165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row608513912165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1665281954165633"><a name="p1665281954165633"></a><a name="p1665281954165633"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1777497680165633"><a name="p1777497680165633"></a><a name="p1777497680165633"></a> </p>
<p id="p1029519194165633"><a name="p1029519194165633"></a><a name="p1029519194165633"></a>A constructor used to create an <strong id="b1234169384165633"><a name="b1234169384165633"></a><a name="b1234169384165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1803373951165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p655869631165633"><a name="p655869631165633"></a><a name="p655869631165633"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1985719182165633"><a name="p1985719182165633"></a><a name="p1985719182165633"></a>virtual </p>
<p id="p197800176165633"><a name="p197800176165633"></a><a name="p197800176165633"></a>A destructor used to delete the <strong id="b1608198723165633"><a name="b1608198723165633"></a><a name="b1608198723165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row890033560165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345753924165633"><a name="p1345753924165633"></a><a name="p1345753924165633"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1888875072165633"><a name="p1888875072165633"></a><a name="p1888875072165633"></a>virtual void </p>
<p id="p392340069165633"><a name="p392340069165633"></a><a name="p392340069165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1558078016165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661466585165633"><a name="p1661466585165633"></a><a name="p1661466585165633"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619319242165633"><a name="p1619319242165633"></a><a name="p1619319242165633"></a>virtual void </p>
<p id="p209985781165633"><a name="p209985781165633"></a><a name="p209985781165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1658449883165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980851871165633"><a name="p1980851871165633"></a><a name="p1980851871165633"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1055358529165633"><a name="p1055358529165633"></a><a name="p1055358529165633"></a>void </p>
<p id="p1087285198165633"><a name="p1087285198165633"></a><a name="p1087285198165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1327609883165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907066201165633"><a name="p1907066201165633"></a><a name="p1907066201165633"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p746635636165633"><a name="p746635636165633"></a><a name="p746635636165633"></a>void </p>
<p id="p1167799715165633"><a name="p1167799715165633"></a><a name="p1167799715165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row860166572165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697260891165633"><a name="p1697260891165633"></a><a name="p1697260891165633"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1616725068165633"><a name="p1616725068165633"></a><a name="p1616725068165633"></a>virtual bool </p>
<p id="p1571308383165633"><a name="p1571308383165633"></a><a name="p1571308383165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row44820880165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2045871612165633"><a name="p2045871612165633"></a><a name="p2045871612165633"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1483111440165633"><a name="p1483111440165633"></a><a name="p1483111440165633"></a>virtual bool </p>
<p id="p1610014280165633"><a name="p1610014280165633"></a><a name="p1610014280165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row193093879165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p329285481165633"><a name="p329285481165633"></a><a name="p329285481165633"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771827843165633"><a name="p771827843165633"></a><a name="p771827843165633"></a>virtual bool </p>
<p id="p993602957165633"><a name="p993602957165633"></a><a name="p993602957165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row2106435454165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296740364165633"><a name="p296740364165633"></a><a name="p296740364165633"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726477552165633"><a name="p1726477552165633"></a><a name="p1726477552165633"></a>virtual bool </p>
<p id="p752191194165633"><a name="p752191194165633"></a><a name="p752191194165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1470385338165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298488755165633"><a name="p1298488755165633"></a><a name="p1298488755165633"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969663959165633"><a name="p1969663959165633"></a><a name="p1969663959165633"></a>virtual void </p>
<p id="p1144829766165633"><a name="p1144829766165633"></a><a name="p1144829766165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row712815607165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p271216962165633"><a name="p271216962165633"></a><a name="p271216962165633"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220772119165633"><a name="p1220772119165633"></a><a name="p1220772119165633"></a>virtual void </p>
<p id="p1644333883165633"><a name="p1644333883165633"></a><a name="p1644333883165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row194731761165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1123269728165633"><a name="p1123269728165633"></a><a name="p1123269728165633"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234456689165633"><a name="p1234456689165633"></a><a name="p1234456689165633"></a>virtual void </p>
<p id="p96412773165633"><a name="p96412773165633"></a><a name="p96412773165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row532214106165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604641516165633"><a name="p604641516165633"></a><a name="p604641516165633"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p541568380165633"><a name="p541568380165633"></a><a name="p541568380165633"></a>virtual void </p>
<p id="p1854411561165633"><a name="p1854411561165633"></a><a name="p1854411561165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row510870816165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368767188165633"><a name="p368767188165633"></a><a name="p368767188165633"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285121898165633"><a name="p285121898165633"></a><a name="p285121898165633"></a>void </p>
<p id="p1808801341165633"><a name="p1808801341165633"></a><a name="p1808801341165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row116828523165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p322849456165633"><a name="p322849456165633"></a><a name="p322849456165633"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801875697165633"><a name="p1801875697165633"></a><a name="p1801875697165633"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1939922847165633"><a name="p1939922847165633"></a><a name="p1939922847165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1676708949165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129244533165633"><a name="p129244533165633"></a><a name="p129244533165633"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174270517165633"><a name="p174270517165633"></a><a name="p174270517165633"></a>void </p>
<p id="p1658950284165633"><a name="p1658950284165633"></a><a name="p1658950284165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1411107985165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600753790165633"><a name="p1600753790165633"></a><a name="p1600753790165633"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861892652165633"><a name="p861892652165633"></a><a name="p861892652165633"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1836984262165633"><a name="p1836984262165633"></a><a name="p1836984262165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row334005006165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744521569165633"><a name="p1744521569165633"></a><a name="p1744521569165633"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p120065746165633"><a name="p120065746165633"></a><a name="p120065746165633"></a>void </p>
<p id="p2111007251165633"><a name="p2111007251165633"></a><a name="p2111007251165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1012378549165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062506436165633"><a name="p1062506436165633"></a><a name="p1062506436165633"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2092969762165633"><a name="p2092969762165633"></a><a name="p2092969762165633"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p2104224408165633"><a name="p2104224408165633"></a><a name="p2104224408165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row619922340165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p875485800165633"><a name="p875485800165633"></a><a name="p875485800165633"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465901035165633"><a name="p465901035165633"></a><a name="p465901035165633"></a>void </p>
<p id="p1091000221165633"><a name="p1091000221165633"></a><a name="p1091000221165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row883515295165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2048752456165633"><a name="p2048752456165633"></a><a name="p2048752456165633"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040667360165633"><a name="p2040667360165633"></a><a name="p2040667360165633"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p937762254165633"><a name="p937762254165633"></a><a name="p937762254165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1014052989165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296217195165633"><a name="p296217195165633"></a><a name="p296217195165633"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583682246165633"><a name="p1583682246165633"></a><a name="p1583682246165633"></a>void </p>
<p id="p1717171486165633"><a name="p1717171486165633"></a><a name="p1717171486165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1190206925165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p473368378165633"><a name="p473368378165633"></a><a name="p473368378165633"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113622808165633"><a name="p113622808165633"></a><a name="p113622808165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p909267276165633"><a name="p909267276165633"></a><a name="p909267276165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1944994621165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1785660692165633"><a name="p1785660692165633"></a><a name="p1785660692165633"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755773239165633"><a name="p1755773239165633"></a><a name="p1755773239165633"></a>void </p>
<p id="p282264304165633"><a name="p282264304165633"></a><a name="p282264304165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row850292001165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1623424323165633"><a name="p1623424323165633"></a><a name="p1623424323165633"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1698384165633"><a name="p1698384165633"></a><a name="p1698384165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p111152487165633"><a name="p111152487165633"></a><a name="p111152487165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1217506837165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p649838431165633"><a name="p649838431165633"></a><a name="p649838431165633"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p841744611165633"><a name="p841744611165633"></a><a name="p841744611165633"></a>virtual void </p>
<p id="p1086548466165633"><a name="p1086548466165633"></a><a name="p1086548466165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row965773861165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755629522165633"><a name="p755629522165633"></a><a name="p755629522165633"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170561579165633"><a name="p1170561579165633"></a><a name="p1170561579165633"></a>bool </p>
<p id="p549064458165633"><a name="p549064458165633"></a><a name="p549064458165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row697479304165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269782833165633"><a name="p1269782833165633"></a><a name="p1269782833165633"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674895727165633"><a name="p674895727165633"></a><a name="p674895727165633"></a>void </p>
<p id="p2125940323165633"><a name="p2125940323165633"></a><a name="p2125940323165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row118825766165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998914347165633"><a name="p998914347165633"></a><a name="p998914347165633"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647158163165633"><a name="p647158163165633"></a><a name="p647158163165633"></a>bool </p>
<p id="p668023055165633"><a name="p668023055165633"></a><a name="p668023055165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1676823117165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043661598165633"><a name="p1043661598165633"></a><a name="p1043661598165633"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1607810790165633"><a name="p1607810790165633"></a><a name="p1607810790165633"></a>void </p>
<p id="p154921307165633"><a name="p154921307165633"></a><a name="p154921307165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row702251500165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451666314165633"><a name="p1451666314165633"></a><a name="p1451666314165633"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2109742735165633"><a name="p2109742735165633"></a><a name="p2109742735165633"></a>bool </p>
<p id="p2073803636165633"><a name="p2073803636165633"></a><a name="p2073803636165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1177229660165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440920375165633"><a name="p1440920375165633"></a><a name="p1440920375165633"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936609734165633"><a name="p1936609734165633"></a><a name="p1936609734165633"></a>void </p>
<p id="p732797237165633"><a name="p732797237165633"></a><a name="p732797237165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row171719615165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237474669165633"><a name="p237474669165633"></a><a name="p237474669165633"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p201308155165633"><a name="p201308155165633"></a><a name="p201308155165633"></a>bool </p>
<p id="p1799563121165633"><a name="p1799563121165633"></a><a name="p1799563121165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1378945321165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p183742160165633"><a name="p183742160165633"></a><a name="p183742160165633"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1032161124165633"><a name="p1032161124165633"></a><a name="p1032161124165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p832172196165633"><a name="p832172196165633"></a><a name="p832172196165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row234350153165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1692368960165633"><a name="p1692368960165633"></a><a name="p1692368960165633"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339342021165633"><a name="p1339342021165633"></a><a name="p1339342021165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p173319672165633"><a name="p173319672165633"></a><a name="p173319672165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row56459338165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p754491454165633"><a name="p754491454165633"></a><a name="p754491454165633"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130877721165633"><a name="p1130877721165633"></a><a name="p1130877721165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p266593176165633"><a name="p266593176165633"></a><a name="p266593176165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row515504572165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1954757682165633"><a name="p1954757682165633"></a><a name="p1954757682165633"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p183899849165633"><a name="p183899849165633"></a><a name="p183899849165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p915536004165633"><a name="p915536004165633"></a><a name="p915536004165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1333885999165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p636074906165633"><a name="p636074906165633"></a><a name="p636074906165633"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643816229165633"><a name="p643816229165633"></a><a name="p643816229165633"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1015991732165633"><a name="p1015991732165633"></a><a name="p1015991732165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row230620539165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1910040849165633"><a name="p1910040849165633"></a><a name="p1910040849165633"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1177449538165633"><a name="p1177449538165633"></a><a name="p1177449538165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1333381097165633"><a name="p1333381097165633"></a><a name="p1333381097165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1191933192165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1039363974165633"><a name="p1039363974165633"></a><a name="p1039363974165633"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416689824165633"><a name="p416689824165633"></a><a name="p416689824165633"></a>void </p>
<p id="p874825228165633"><a name="p874825228165633"></a><a name="p874825228165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row286345505165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83606643165633"><a name="p83606643165633"></a><a name="p83606643165633"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687470300165633"><a name="p1687470300165633"></a><a name="p1687470300165633"></a>virtual void </p>
<p id="p56948443165633"><a name="p56948443165633"></a><a name="p56948443165633"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1329024640165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761279437165633"><a name="p761279437165633"></a><a name="p761279437165633"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1013868098165633"><a name="p1013868098165633"></a><a name="p1013868098165633"></a>virtual int16_t </p>
<p id="p1281965095165633"><a name="p1281965095165633"></a><a name="p1281965095165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1256574886165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1349136936165633"><a name="p1349136936165633"></a><a name="p1349136936165633"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p921029530165633"><a name="p921029530165633"></a><a name="p921029530165633"></a>virtual void </p>
<p id="p134412109165633"><a name="p134412109165633"></a><a name="p134412109165633"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row631385286165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282601186165633"><a name="p282601186165633"></a><a name="p282601186165633"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949131441165633"><a name="p949131441165633"></a><a name="p949131441165633"></a>virtual int16_t </p>
<p id="p1066923629165633"><a name="p1066923629165633"></a><a name="p1066923629165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row446567018165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137605812165633"><a name="p137605812165633"></a><a name="p137605812165633"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578532949165633"><a name="p1578532949165633"></a><a name="p1578532949165633"></a>virtual void </p>
<p id="p28940704165633"><a name="p28940704165633"></a><a name="p28940704165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1763692955165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605843247165633"><a name="p605843247165633"></a><a name="p605843247165633"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2074164352165633"><a name="p2074164352165633"></a><a name="p2074164352165633"></a>virtual void </p>
<p id="p1888599507165633"><a name="p1888599507165633"></a><a name="p1888599507165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row683905794165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p331194635165633"><a name="p331194635165633"></a><a name="p331194635165633"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37992826165633"><a name="p37992826165633"></a><a name="p37992826165633"></a>int16_t </p>
<p id="p1856943238165633"><a name="p1856943238165633"></a><a name="p1856943238165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1146830437165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495666243165633"><a name="p1495666243165633"></a><a name="p1495666243165633"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813025525165633"><a name="p813025525165633"></a><a name="p813025525165633"></a>virtual void </p>
<p id="p801816165633"><a name="p801816165633"></a><a name="p801816165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1139000962165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552104480165633"><a name="p1552104480165633"></a><a name="p1552104480165633"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1469698377165633"><a name="p1469698377165633"></a><a name="p1469698377165633"></a>int16_t </p>
<p id="p1435872191165633"><a name="p1435872191165633"></a><a name="p1435872191165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1109049044165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060150219165633"><a name="p1060150219165633"></a><a name="p1060150219165633"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611123576165633"><a name="p1611123576165633"></a><a name="p1611123576165633"></a>virtual void </p>
<p id="p747611061165633"><a name="p747611061165633"></a><a name="p747611061165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row175519013165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780206576165633"><a name="p1780206576165633"></a><a name="p1780206576165633"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68509933165633"><a name="p68509933165633"></a><a name="p68509933165633"></a>virtual void </p>
<p id="p1038407366165633"><a name="p1038407366165633"></a><a name="p1038407366165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1835800790165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967885451165633"><a name="p967885451165633"></a><a name="p967885451165633"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p530641579165633"><a name="p530641579165633"></a><a name="p530641579165633"></a>bool </p>
<p id="p1340617183165633"><a name="p1340617183165633"></a><a name="p1340617183165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1669777872165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128074195165633"><a name="p2128074195165633"></a><a name="p2128074195165633"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p407224544165633"><a name="p407224544165633"></a><a name="p407224544165633"></a>void </p>
<p id="p2682305165633"><a name="p2682305165633"></a><a name="p2682305165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1202766598165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880308806165633"><a name="p1880308806165633"></a><a name="p1880308806165633"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453223177165633"><a name="p453223177165633"></a><a name="p453223177165633"></a>void </p>
<p id="p1894218065165633"><a name="p1894218065165633"></a><a name="p1894218065165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row2085410457165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2046544759165633"><a name="p2046544759165633"></a><a name="p2046544759165633"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1691203623165633"><a name="p1691203623165633"></a><a name="p1691203623165633"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p207923457165633"><a name="p207923457165633"></a><a name="p207923457165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row702064470165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813867656165633"><a name="p1813867656165633"></a><a name="p1813867656165633"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1934895228165633"><a name="p1934895228165633"></a><a name="p1934895228165633"></a>void </p>
<p id="p1186007070165633"><a name="p1186007070165633"></a><a name="p1186007070165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row383225496165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654834118165633"><a name="p654834118165633"></a><a name="p654834118165633"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1819948371165633"><a name="p1819948371165633"></a><a name="p1819948371165633"></a>const char * </p>
<p id="p850345195165633"><a name="p850345195165633"></a><a name="p850345195165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row629306961165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1067814941165633"><a name="p1067814941165633"></a><a name="p1067814941165633"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441481930165633"><a name="p441481930165633"></a><a name="p441481930165633"></a>void </p>
<p id="p1148685639165633"><a name="p1148685639165633"></a><a name="p1148685639165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1372030579165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750271295165633"><a name="p750271295165633"></a><a name="p750271295165633"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343790973165633"><a name="p343790973165633"></a><a name="p343790973165633"></a>int16_t </p>
<p id="p1429006167165633"><a name="p1429006167165633"></a><a name="p1429006167165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1296917380165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1466122580165633"><a name="p1466122580165633"></a><a name="p1466122580165633"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928118717165633"><a name="p1928118717165633"></a><a name="p1928118717165633"></a>virtual void </p>
<p id="p1158308756165633"><a name="p1158308756165633"></a><a name="p1158308756165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row970961819165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112597373165633"><a name="p1112597373165633"></a><a name="p1112597373165633"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552440745165633"><a name="p1552440745165633"></a><a name="p1552440745165633"></a>void </p>
<p id="p151623183165633"><a name="p151623183165633"></a><a name="p151623183165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1022746998165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p643182295165633"><a name="p643182295165633"></a><a name="p643182295165633"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p581054686165633"><a name="p581054686165633"></a><a name="p581054686165633"></a>void </p>
<p id="p355418190165633"><a name="p355418190165633"></a><a name="p355418190165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row590971216165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707496711165633"><a name="p1707496711165633"></a><a name="p1707496711165633"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455020853165633"><a name="p455020853165633"></a><a name="p455020853165633"></a>void </p>
<p id="p427065764165633"><a name="p427065764165633"></a><a name="p427065764165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1686034175165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065836426165633"><a name="p2065836426165633"></a><a name="p2065836426165633"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1636431787165633"><a name="p1636431787165633"></a><a name="p1636431787165633"></a>void </p>
<p id="p2115493209165633"><a name="p2115493209165633"></a><a name="p2115493209165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row52427281165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p21680953165633"><a name="p21680953165633"></a><a name="p21680953165633"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p851388912165633"><a name="p851388912165633"></a><a name="p851388912165633"></a>void </p>
<p id="p1656009475165633"><a name="p1656009475165633"></a><a name="p1656009475165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row268226584165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2067481378165633"><a name="p2067481378165633"></a><a name="p2067481378165633"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p542625628165633"><a name="p542625628165633"></a><a name="p542625628165633"></a>void </p>
<p id="p239017259165633"><a name="p239017259165633"></a><a name="p239017259165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row386613813165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p37715926165633"><a name="p37715926165633"></a><a name="p37715926165633"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p53897735165633"><a name="p53897735165633"></a><a name="p53897735165633"></a>void </p>
<p id="p632416086165633"><a name="p632416086165633"></a><a name="p632416086165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row233777091165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p456144502165633"><a name="p456144502165633"></a><a name="p456144502165633"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964689155165633"><a name="p964689155165633"></a><a name="p964689155165633"></a>void </p>
<p id="p1858324767165633"><a name="p1858324767165633"></a><a name="p1858324767165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1910162949165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012012417165633"><a name="p1012012417165633"></a><a name="p1012012417165633"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386973227165633"><a name="p386973227165633"></a><a name="p386973227165633"></a>void </p>
<p id="p1506036778165633"><a name="p1506036778165633"></a><a name="p1506036778165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row983577378165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633041906165633"><a name="p1633041906165633"></a><a name="p1633041906165633"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1789866573165633"><a name="p1789866573165633"></a><a name="p1789866573165633"></a>void </p>
<p id="p1694340201165633"><a name="p1694340201165633"></a><a name="p1694340201165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1163652997165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p433347014165633"><a name="p433347014165633"></a><a name="p433347014165633"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744873747165633"><a name="p1744873747165633"></a><a name="p1744873747165633"></a>void </p>
<p id="p394608207165633"><a name="p394608207165633"></a><a name="p394608207165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1835317145165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2056727706165633"><a name="p2056727706165633"></a><a name="p2056727706165633"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1366643216165633"><a name="p1366643216165633"></a><a name="p1366643216165633"></a>void </p>
<p id="p1957976139165633"><a name="p1957976139165633"></a><a name="p1957976139165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1053270003165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p589958610165633"><a name="p589958610165633"></a><a name="p589958610165633"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779935563165633"><a name="p779935563165633"></a><a name="p779935563165633"></a>void </p>
<p id="p543849587165633"><a name="p543849587165633"></a><a name="p543849587165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row716954957165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p543776032165633"><a name="p543776032165633"></a><a name="p543776032165633"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619946841165633"><a name="p1619946841165633"></a><a name="p1619946841165633"></a>void </p>
<p id="p1352091769165633"><a name="p1352091769165633"></a><a name="p1352091769165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1278950493165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526484700165633"><a name="p1526484700165633"></a><a name="p1526484700165633"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2105856760165633"><a name="p2105856760165633"></a><a name="p2105856760165633"></a>void </p>
<p id="p1198551488165633"><a name="p1198551488165633"></a><a name="p1198551488165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1825824260165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p821490559165633"><a name="p821490559165633"></a><a name="p821490559165633"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999083045165633"><a name="p1999083045165633"></a><a name="p1999083045165633"></a>void </p>
<p id="p2117169813165633"><a name="p2117169813165633"></a><a name="p2117169813165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row223529305165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1068415687165633"><a name="p1068415687165633"></a><a name="p1068415687165633"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1833504531165633"><a name="p1833504531165633"></a><a name="p1833504531165633"></a>virtual void </p>
<p id="p1913287829165633"><a name="p1913287829165633"></a><a name="p1913287829165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row276922689165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p319701159165633"><a name="p319701159165633"></a><a name="p319701159165633"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p539159495165633"><a name="p539159495165633"></a><a name="p539159495165633"></a>virtual int64_t </p>
<p id="p1626163032165633"><a name="p1626163032165633"></a><a name="p1626163032165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1759636873165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p803327515165633"><a name="p803327515165633"></a><a name="p803327515165633"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1780711192165633"><a name="p1780711192165633"></a><a name="p1780711192165633"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p2084243780165633"><a name="p2084243780165633"></a><a name="p2084243780165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row657358413165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786845115165633"><a name="p786845115165633"></a><a name="p786845115165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p780685297165633"><a name="p780685297165633"></a><a name="p780685297165633"></a>void * </p>
<p id="p335698582165633"><a name="p335698582165633"></a><a name="p335698582165633"></a>Overrides the <strong id="b2034464800165633"><a name="b2034464800165633"></a><a name="b2034464800165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row839101073165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2056089940165633"><a name="p2056089940165633"></a><a name="p2056089940165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449003327165633"><a name="p1449003327165633"></a><a name="p1449003327165633"></a>void </p>
<p id="p1993839929165633"><a name="p1993839929165633"></a><a name="p1993839929165633"></a>Overrides the <strong id="b1311718833165633"><a name="b1311718833165633"></a><a name="b1311718833165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1518120382165633"></a>
<table><thead align="left"><tr id="row1176950481165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1854474907165633"><a name="p1854474907165633"></a><a name="p1854474907165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p973829715165633"><a name="p973829715165633"></a><a name="p973829715165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1792261651165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p345424232165633"><a name="p345424232165633"></a><a name="p345424232165633"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p687830387165633"><a name="p687830387165633"></a><a name="p687830387165633"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1001410695165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1239036525165633"><a name="p1239036525165633"></a><a name="p1239036525165633"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278506611165633"><a name="p1278506611165633"></a><a name="p1278506611165633"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1220513738165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542606231165633"><a name="p542606231165633"></a><a name="p542606231165633"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2045893102165633"><a name="p2045893102165633"></a><a name="p2045893102165633"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1695107208165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1108953527165633"><a name="p1108953527165633"></a><a name="p1108953527165633"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761187050165633"><a name="p761187050165633"></a><a name="p761187050165633"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row269760847165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2099936613165633"><a name="p2099936613165633"></a><a name="p2099936613165633"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p268291429165633"><a name="p268291429165633"></a><a name="p268291429165633"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1121380070165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p275455885165633"><a name="p275455885165633"></a><a name="p275455885165633"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005382931165633"><a name="p1005382931165633"></a><a name="p1005382931165633"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1862386561165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478327147165633"><a name="p1478327147165633"></a><a name="p1478327147165633"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p706347631165633"><a name="p706347631165633"></a><a name="p706347631165633"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row755185804165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836320370165633"><a name="p836320370165633"></a><a name="p836320370165633"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p974784557165633"><a name="p974784557165633"></a><a name="p974784557165633"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

