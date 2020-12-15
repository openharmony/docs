# OHOS::UIXAxis<a name="EN-US_TOPIC_0000001054479585"></a>

-   [Overview](#section1164065848165633)
-   [Summary](#section1540662673165633)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1164065848165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the unique attributes and functions for the x-axis. This class is used in  [UIChart](ohos-uichart.md). 

See also
:   [UIAxis](ohos-uiaxis.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1540662673165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table849701946165633"></a>
<table><thead align="left"><tr id="row403495111165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1765626914165633"><a name="p1765626914165633"></a><a name="p1765626914165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1711437084165633"><a name="p1711437084165633"></a><a name="p1711437084165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row985407363165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207652218165633"><a name="p1207652218165633"></a><a name="p1207652218165633"></a><a href="graphic.md#ga8cc8e2c8249360ccfc89462fff33ca4a">UIXAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2093691979165633"><a name="p2093691979165633"></a><a name="p2093691979165633"></a> </p>
<p id="p1378745786165633"><a name="p1378745786165633"></a><a name="p1378745786165633"></a>A constructor used to create a <strong id="b1617752467165633"><a name="b1617752467165633"></a><a name="b1617752467165633"></a><a href="ohos-uixaxis.md">UIXAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row1008933564165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856256271165633"><a name="p1856256271165633"></a><a name="p1856256271165633"></a><a href="graphic.md#gaa4e8939fb25fc20dd93ed030044b019f">~UIXAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p838729272165633"><a name="p838729272165633"></a><a name="p838729272165633"></a>virtual </p>
<p id="p467791064165633"><a name="p467791064165633"></a><a name="p467791064165633"></a>A destructor used to delete the <strong id="b231336699165633"><a name="b231336699165633"></a><a name="b231336699165633"></a><a href="ohos-uixaxis.md">UIXAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row130989219165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249013331165633"><a name="p249013331165633"></a><a name="p249013331165633"></a><a href="graphic.md#ga9407ddab6d7e65fc075ca37b86163e6f">TranslateToPixel</a> (int16_t &amp;value) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p569202108165633"><a name="p569202108165633"></a><a name="p569202108165633"></a>void </p>
<p id="p1220039085165633"><a name="p1220039085165633"></a><a name="p1220039085165633"></a>Translates data into the x coordinate of a pixel. </p>
</td>
</tr>
<tr id="row279027104165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252767026165633"><a name="p1252767026165633"></a><a name="p1252767026165633"></a><a href="graphic.md#ga2181796eef584a71a5db9186399720aa">SetDataRange</a> (uint16_t min, uint16_t max) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377726892165633"><a name="p1377726892165633"></a><a name="p1377726892165633"></a>bool </p>
<p id="p1476194620165633"><a name="p1476194620165633"></a><a name="p1476194620165633"></a>Sets the value range of the X axis. </p>
</td>
</tr>
<tr id="row699792661165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1370606902165633"><a name="p1370606902165633"></a><a name="p1370606902165633"></a><a href="graphic.md#ga46f4151f1379809749ab2ba364d55170">SetMarkNum</a> (uint16_t count) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427556387165633"><a name="p427556387165633"></a><a name="p427556387165633"></a>void </p>
<p id="p394899751165633"><a name="p394899751165633"></a><a name="p394899751165633"></a>Sets the number of scales on the x-axis. </p>
</td>
</tr>
<tr id="row95668150165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111139245165633"><a name="p2111139245165633"></a><a name="p2111139245165633"></a><a href="graphic.md#gad79f1c694abce57af451b8f7b0b17c35">UIAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2008570818165633"><a name="p2008570818165633"></a><a name="p2008570818165633"></a> </p>
<p id="p749431326165633"><a name="p749431326165633"></a><a name="p749431326165633"></a>A constructor used to create a <strong id="b1962413654165633"><a name="b1962413654165633"></a><a name="b1962413654165633"></a><a href="ohos-uiaxis.md">UIAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row296889866165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p99369285165633"><a name="p99369285165633"></a><a name="p99369285165633"></a><a href="graphic.md#gaacc9ac178b3b235f1186297021eb98d8">~UIAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900333735165633"><a name="p1900333735165633"></a><a name="p1900333735165633"></a>virtual </p>
<p id="p1111405006165633"><a name="p1111405006165633"></a><a name="p1111405006165633"></a>A destructor used to delete the <strong id="b560568766165633"><a name="b560568766165633"></a><a name="b560568766165633"></a><a href="ohos-uiaxis.md">UIAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row1923177943165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2122816091165633"><a name="p2122816091165633"></a><a name="p2122816091165633"></a><a href="graphic.md#ga2f46b702f1543c5076a8957a94a780d3">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19674967165633"><a name="p19674967165633"></a><a name="p19674967165633"></a>UIViewType </p>
<p id="p779427703165633"><a name="p779427703165633"></a><a name="p779427703165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row657263329165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1001072755165633"><a name="p1001072755165633"></a><a name="p1001072755165633"></a><a href="graphic.md#ga8ceec5e67fa2c4f161bd9af1f0788bbe">SetLineColor</a> (const <a href="ohos-color32.md">ColorType</a> &amp;color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p846635439165633"><a name="p846635439165633"></a><a name="p846635439165633"></a>void </p>
<p id="p1234286814165633"><a name="p1234286814165633"></a><a name="p1234286814165633"></a>Sets the line color of the coordinate axis. </p>
</td>
</tr>
<tr id="row370846746165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934026132165633"><a name="p1934026132165633"></a><a name="p1934026132165633"></a><a href="graphic.md#ga5360803f425055de52af5f7fa1081cfe">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294557443165633"><a name="p294557443165633"></a><a name="p294557443165633"></a>void </p>
<p id="p1675717019165633"><a name="p1675717019165633"></a><a name="p1675717019165633"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1930818480165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1138907803165633"><a name="p1138907803165633"></a><a name="p1138907803165633"></a><a href="graphic.md#gad1bf4d83270c0a4ba04f3cffbc67bb97">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760998878165633"><a name="p1760998878165633"></a><a name="p1760998878165633"></a>bool </p>
<p id="p1460192750165633"><a name="p1460192750165633"></a><a name="p1460192750165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row174537548165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616264764165633"><a name="p616264764165633"></a><a name="p616264764165633"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712802691165633"><a name="p1712802691165633"></a><a name="p1712802691165633"></a> </p>
<p id="p840932579165633"><a name="p840932579165633"></a><a name="p840932579165633"></a>A default constructor used to create a <strong id="b1065559849165633"><a name="b1065559849165633"></a><a name="b1065559849165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1129732944165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041728833165633"><a name="p1041728833165633"></a><a name="p1041728833165633"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912517562165633"><a name="p1912517562165633"></a><a name="p1912517562165633"></a>virtual </p>
<p id="p465718512165633"><a name="p465718512165633"></a><a name="p465718512165633"></a>A destructor used to delete the <strong id="b1472123755165633"><a name="b1472123755165633"></a><a name="b1472123755165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row409108258165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1916862063165633"><a name="p1916862063165633"></a><a name="p1916862063165633"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1739098101165633"><a name="p1739098101165633"></a><a name="p1739098101165633"></a>UIViewType </p>
<p id="p1779960907165633"><a name="p1779960907165633"></a><a name="p1779960907165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row29455429165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971794132165633"><a name="p1971794132165633"></a><a name="p1971794132165633"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p995958390165633"><a name="p995958390165633"></a><a name="p995958390165633"></a>virtual void </p>
<p id="p1531900589165633"><a name="p1531900589165633"></a><a name="p1531900589165633"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1394881235165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p774468108165633"><a name="p774468108165633"></a><a name="p774468108165633"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652585815165633"><a name="p1652585815165633"></a><a name="p1652585815165633"></a>virtual void </p>
<p id="p2013363881165633"><a name="p2013363881165633"></a><a name="p2013363881165633"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1475612013165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120876039165633"><a name="p2120876039165633"></a><a name="p2120876039165633"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p830676697165633"><a name="p830676697165633"></a><a name="p830676697165633"></a>virtual void </p>
<p id="p2112988910165633"><a name="p2112988910165633"></a><a name="p2112988910165633"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row47565680165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p647854444165633"><a name="p647854444165633"></a><a name="p647854444165633"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204259298165633"><a name="p204259298165633"></a><a name="p204259298165633"></a>virtual void </p>
<p id="p1463821038165633"><a name="p1463821038165633"></a><a name="p1463821038165633"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1849852518165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1814939130165633"><a name="p1814939130165633"></a><a name="p1814939130165633"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858488479165633"><a name="p1858488479165633"></a><a name="p1858488479165633"></a>virtual void </p>
<p id="p411423232165633"><a name="p411423232165633"></a><a name="p411423232165633"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1861189623165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p906699460165633"><a name="p906699460165633"></a><a name="p906699460165633"></a><a href="graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255695796165633"><a name="p1255695796165633"></a><a name="p1255695796165633"></a>virtual void </p>
<p id="p915871792165633"><a name="p915871792165633"></a><a name="p915871792165633"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row2117347447165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1137852621165633"><a name="p1137852621165633"></a><a name="p1137852621165633"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173322461165633"><a name="p1173322461165633"></a><a name="p1173322461165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1002982004165633"><a name="p1002982004165633"></a><a name="p1002982004165633"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1628784597165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1649281903165633"><a name="p1649281903165633"></a><a name="p1649281903165633"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139355696165633"><a name="p139355696165633"></a><a name="p139355696165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1569656140165633"><a name="p1569656140165633"></a><a name="p1569656140165633"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row39465877165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567225193165633"><a name="p1567225193165633"></a><a name="p1567225193165633"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86354428165633"><a name="p86354428165633"></a><a name="p86354428165633"></a>void </p>
<p id="p1934750047165633"><a name="p1934750047165633"></a><a name="p1934750047165633"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1636436036165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1678267122165633"><a name="p1678267122165633"></a><a name="p1678267122165633"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10454708165633"><a name="p10454708165633"></a><a name="p10454708165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1903423457165633"><a name="p1903423457165633"></a><a name="p1903423457165633"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row610785058165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813041515165633"><a name="p1813041515165633"></a><a name="p1813041515165633"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2130793824165633"><a name="p2130793824165633"></a><a name="p2130793824165633"></a>void </p>
<p id="p1747584789165633"><a name="p1747584789165633"></a><a name="p1747584789165633"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1413829415165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1191790220165633"><a name="p1191790220165633"></a><a name="p1191790220165633"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643448439165633"><a name="p643448439165633"></a><a name="p643448439165633"></a> </p>
<p id="p1773423248165633"><a name="p1773423248165633"></a><a name="p1773423248165633"></a>A default constructor used to create an <strong id="b822277402165633"><a name="b822277402165633"></a><a name="b822277402165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1054427334165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750893981165633"><a name="p750893981165633"></a><a name="p750893981165633"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p935609464165633"><a name="p935609464165633"></a><a name="p935609464165633"></a> </p>
<p id="p2021580847165633"><a name="p2021580847165633"></a><a name="p2021580847165633"></a>A constructor used to create an <strong id="b2085496499165633"><a name="b2085496499165633"></a><a name="b2085496499165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1904049621165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034274332165633"><a name="p2034274332165633"></a><a name="p2034274332165633"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p303867518165633"><a name="p303867518165633"></a><a name="p303867518165633"></a>virtual </p>
<p id="p287761966165633"><a name="p287761966165633"></a><a name="p287761966165633"></a>A destructor used to delete the <strong id="b2137571672165633"><a name="b2137571672165633"></a><a name="b2137571672165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row733401540165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26818392165633"><a name="p26818392165633"></a><a name="p26818392165633"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1300508481165633"><a name="p1300508481165633"></a><a name="p1300508481165633"></a>virtual void </p>
<p id="p475047409165633"><a name="p475047409165633"></a><a name="p475047409165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row368203461165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p107953113165633"><a name="p107953113165633"></a><a name="p107953113165633"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p494056081165633"><a name="p494056081165633"></a><a name="p494056081165633"></a>virtual void </p>
<p id="p489010300165633"><a name="p489010300165633"></a><a name="p489010300165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1284911385165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608382201165633"><a name="p608382201165633"></a><a name="p608382201165633"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893242709165633"><a name="p1893242709165633"></a><a name="p1893242709165633"></a>void </p>
<p id="p795825840165633"><a name="p795825840165633"></a><a name="p795825840165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row2030275630165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1693120904165633"><a name="p1693120904165633"></a><a name="p1693120904165633"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325218939165633"><a name="p325218939165633"></a><a name="p325218939165633"></a>void </p>
<p id="p1497633476165633"><a name="p1497633476165633"></a><a name="p1497633476165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row969067282165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1130668180165633"><a name="p1130668180165633"></a><a name="p1130668180165633"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p613285606165633"><a name="p613285606165633"></a><a name="p613285606165633"></a>virtual bool </p>
<p id="p1102586439165633"><a name="p1102586439165633"></a><a name="p1102586439165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1770296717165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890284005165633"><a name="p1890284005165633"></a><a name="p1890284005165633"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978937373165633"><a name="p978937373165633"></a><a name="p978937373165633"></a>virtual bool </p>
<p id="p1068927619165633"><a name="p1068927619165633"></a><a name="p1068927619165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1157516064165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410435164165633"><a name="p1410435164165633"></a><a name="p1410435164165633"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1922858160165633"><a name="p1922858160165633"></a><a name="p1922858160165633"></a>virtual bool </p>
<p id="p1289226721165633"><a name="p1289226721165633"></a><a name="p1289226721165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row697179824165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p561263276165633"><a name="p561263276165633"></a><a name="p561263276165633"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479907953165633"><a name="p479907953165633"></a><a name="p479907953165633"></a>virtual bool </p>
<p id="p1640499224165633"><a name="p1640499224165633"></a><a name="p1640499224165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row688276511165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279583040165633"><a name="p1279583040165633"></a><a name="p1279583040165633"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910753374165633"><a name="p1910753374165633"></a><a name="p1910753374165633"></a>virtual void </p>
<p id="p2140227467165633"><a name="p2140227467165633"></a><a name="p2140227467165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1312505734165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p592027908165633"><a name="p592027908165633"></a><a name="p592027908165633"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p60513327165633"><a name="p60513327165633"></a><a name="p60513327165633"></a>virtual void </p>
<p id="p1498600191165633"><a name="p1498600191165633"></a><a name="p1498600191165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1991529033165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p452519511165633"><a name="p452519511165633"></a><a name="p452519511165633"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1164355505165633"><a name="p1164355505165633"></a><a name="p1164355505165633"></a>virtual void </p>
<p id="p1168409580165633"><a name="p1168409580165633"></a><a name="p1168409580165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row817291579165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542395204165633"><a name="p542395204165633"></a><a name="p542395204165633"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1014604675165633"><a name="p1014604675165633"></a><a name="p1014604675165633"></a>virtual void </p>
<p id="p1704771050165633"><a name="p1704771050165633"></a><a name="p1704771050165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row77172387165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624053184165633"><a name="p624053184165633"></a><a name="p624053184165633"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1799067738165633"><a name="p1799067738165633"></a><a name="p1799067738165633"></a>void </p>
<p id="p1966095074165633"><a name="p1966095074165633"></a><a name="p1966095074165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1242565894165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447648827165633"><a name="p1447648827165633"></a><a name="p1447648827165633"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p917472071165633"><a name="p917472071165633"></a><a name="p917472071165633"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1871925416165633"><a name="p1871925416165633"></a><a name="p1871925416165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1571957552165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p346103236165633"><a name="p346103236165633"></a><a name="p346103236165633"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1859583697165633"><a name="p1859583697165633"></a><a name="p1859583697165633"></a>void </p>
<p id="p791092486165633"><a name="p791092486165633"></a><a name="p791092486165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row261216238165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2056638660165633"><a name="p2056638660165633"></a><a name="p2056638660165633"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1328292369165633"><a name="p1328292369165633"></a><a name="p1328292369165633"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1049366435165633"><a name="p1049366435165633"></a><a name="p1049366435165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row79563057165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192051358165633"><a name="p192051358165633"></a><a name="p192051358165633"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p266260086165633"><a name="p266260086165633"></a><a name="p266260086165633"></a>void </p>
<p id="p293084908165633"><a name="p293084908165633"></a><a name="p293084908165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row989255374165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1750833469165633"><a name="p1750833469165633"></a><a name="p1750833469165633"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p347395007165633"><a name="p347395007165633"></a><a name="p347395007165633"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p239751418165633"><a name="p239751418165633"></a><a name="p239751418165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1683384152165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218455773165633"><a name="p218455773165633"></a><a name="p218455773165633"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2026664896165633"><a name="p2026664896165633"></a><a name="p2026664896165633"></a>void </p>
<p id="p1890654098165633"><a name="p1890654098165633"></a><a name="p1890654098165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1867567355165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1805919274165633"><a name="p1805919274165633"></a><a name="p1805919274165633"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047260923165633"><a name="p2047260923165633"></a><a name="p2047260923165633"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p2129794469165633"><a name="p2129794469165633"></a><a name="p2129794469165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1150110957165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p128928325165633"><a name="p128928325165633"></a><a name="p128928325165633"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047840806165633"><a name="p1047840806165633"></a><a name="p1047840806165633"></a>void </p>
<p id="p1783894373165633"><a name="p1783894373165633"></a><a name="p1783894373165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row706565540165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1305158954165633"><a name="p1305158954165633"></a><a name="p1305158954165633"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093962659165633"><a name="p1093962659165633"></a><a name="p1093962659165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1564481226165633"><a name="p1564481226165633"></a><a name="p1564481226165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1201532639165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1165636922165633"><a name="p1165636922165633"></a><a name="p1165636922165633"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139641446165633"><a name="p139641446165633"></a><a name="p139641446165633"></a>void </p>
<p id="p1260909651165633"><a name="p1260909651165633"></a><a name="p1260909651165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1717147159165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532235874165633"><a name="p1532235874165633"></a><a name="p1532235874165633"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p773825752165633"><a name="p773825752165633"></a><a name="p773825752165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p962875765165633"><a name="p962875765165633"></a><a name="p962875765165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row91132955165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p67256845165633"><a name="p67256845165633"></a><a name="p67256845165633"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176727251165633"><a name="p1176727251165633"></a><a name="p1176727251165633"></a>virtual void </p>
<p id="p1822260875165633"><a name="p1822260875165633"></a><a name="p1822260875165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row974923187165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32668547165633"><a name="p32668547165633"></a><a name="p32668547165633"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441410283165633"><a name="p441410283165633"></a><a name="p441410283165633"></a>bool </p>
<p id="p439841075165633"><a name="p439841075165633"></a><a name="p439841075165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1918842541165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1878475588165633"><a name="p1878475588165633"></a><a name="p1878475588165633"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449828839165633"><a name="p1449828839165633"></a><a name="p1449828839165633"></a>void </p>
<p id="p1014435860165633"><a name="p1014435860165633"></a><a name="p1014435860165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row179237681165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279210248165633"><a name="p1279210248165633"></a><a name="p1279210248165633"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p180648541165633"><a name="p180648541165633"></a><a name="p180648541165633"></a>bool </p>
<p id="p1986648125165633"><a name="p1986648125165633"></a><a name="p1986648125165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1138970780165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1599729876165633"><a name="p1599729876165633"></a><a name="p1599729876165633"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1792564676165633"><a name="p1792564676165633"></a><a name="p1792564676165633"></a>void </p>
<p id="p1652080224165633"><a name="p1652080224165633"></a><a name="p1652080224165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1575502631165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p525526714165633"><a name="p525526714165633"></a><a name="p525526714165633"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492049859165633"><a name="p1492049859165633"></a><a name="p1492049859165633"></a>bool </p>
<p id="p140990814165633"><a name="p140990814165633"></a><a name="p140990814165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row879450289165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p363605406165633"><a name="p363605406165633"></a><a name="p363605406165633"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664617295165633"><a name="p1664617295165633"></a><a name="p1664617295165633"></a>void </p>
<p id="p1433684908165633"><a name="p1433684908165633"></a><a name="p1433684908165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row494434947165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36155798165633"><a name="p36155798165633"></a><a name="p36155798165633"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466071886165633"><a name="p466071886165633"></a><a name="p466071886165633"></a>bool </p>
<p id="p1095978137165633"><a name="p1095978137165633"></a><a name="p1095978137165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1524158742165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559204847165633"><a name="p559204847165633"></a><a name="p559204847165633"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p680682095165633"><a name="p680682095165633"></a><a name="p680682095165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1097077544165633"><a name="p1097077544165633"></a><a name="p1097077544165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1727360392165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p151094031165633"><a name="p151094031165633"></a><a name="p151094031165633"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p695421459165633"><a name="p695421459165633"></a><a name="p695421459165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1404542513165633"><a name="p1404542513165633"></a><a name="p1404542513165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1760011450165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1546486870165633"><a name="p1546486870165633"></a><a name="p1546486870165633"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1790232555165633"><a name="p1790232555165633"></a><a name="p1790232555165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1375336651165633"><a name="p1375336651165633"></a><a name="p1375336651165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row619173937165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1349170088165633"><a name="p1349170088165633"></a><a name="p1349170088165633"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p835184505165633"><a name="p835184505165633"></a><a name="p835184505165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1106322475165633"><a name="p1106322475165633"></a><a name="p1106322475165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row791015058165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p932882778165633"><a name="p932882778165633"></a><a name="p932882778165633"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p207011255165633"><a name="p207011255165633"></a><a name="p207011255165633"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p166814210165633"><a name="p166814210165633"></a><a name="p166814210165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1989662813165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411051903165633"><a name="p1411051903165633"></a><a name="p1411051903165633"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1633175304165633"><a name="p1633175304165633"></a><a name="p1633175304165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1367250985165633"><a name="p1367250985165633"></a><a name="p1367250985165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row770686798165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358485146165633"><a name="p358485146165633"></a><a name="p358485146165633"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756017564165633"><a name="p1756017564165633"></a><a name="p1756017564165633"></a>void </p>
<p id="p496340774165633"><a name="p496340774165633"></a><a name="p496340774165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row258954584165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p348857887165633"><a name="p348857887165633"></a><a name="p348857887165633"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115633001165633"><a name="p2115633001165633"></a><a name="p2115633001165633"></a>virtual void </p>
<p id="p642364304165633"><a name="p642364304165633"></a><a name="p642364304165633"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row328239444165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1006560778165633"><a name="p1006560778165633"></a><a name="p1006560778165633"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844357471165633"><a name="p844357471165633"></a><a name="p844357471165633"></a>virtual int16_t </p>
<p id="p1254571710165633"><a name="p1254571710165633"></a><a name="p1254571710165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row129590470165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628521536165633"><a name="p628521536165633"></a><a name="p628521536165633"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1881817637165633"><a name="p1881817637165633"></a><a name="p1881817637165633"></a>virtual void </p>
<p id="p1240375469165633"><a name="p1240375469165633"></a><a name="p1240375469165633"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row688028804165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587848941165633"><a name="p587848941165633"></a><a name="p587848941165633"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361205991165633"><a name="p361205991165633"></a><a name="p361205991165633"></a>virtual int16_t </p>
<p id="p1393775118165633"><a name="p1393775118165633"></a><a name="p1393775118165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1336386802165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1301023411165633"><a name="p1301023411165633"></a><a name="p1301023411165633"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1429864093165633"><a name="p1429864093165633"></a><a name="p1429864093165633"></a>virtual void </p>
<p id="p471783424165633"><a name="p471783424165633"></a><a name="p471783424165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1203464526165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1331125337165633"><a name="p1331125337165633"></a><a name="p1331125337165633"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p317617471165633"><a name="p317617471165633"></a><a name="p317617471165633"></a>virtual void </p>
<p id="p1147034128165633"><a name="p1147034128165633"></a><a name="p1147034128165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1194015424165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040225316165633"><a name="p1040225316165633"></a><a name="p1040225316165633"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614900378165633"><a name="p1614900378165633"></a><a name="p1614900378165633"></a>int16_t </p>
<p id="p1663153112165633"><a name="p1663153112165633"></a><a name="p1663153112165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row343347523165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p950386136165633"><a name="p950386136165633"></a><a name="p950386136165633"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1367860752165633"><a name="p1367860752165633"></a><a name="p1367860752165633"></a>virtual void </p>
<p id="p1094308075165633"><a name="p1094308075165633"></a><a name="p1094308075165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1855975476165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569290983165633"><a name="p1569290983165633"></a><a name="p1569290983165633"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p905244032165633"><a name="p905244032165633"></a><a name="p905244032165633"></a>int16_t </p>
<p id="p1467077065165633"><a name="p1467077065165633"></a><a name="p1467077065165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1422538639165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p801136687165633"><a name="p801136687165633"></a><a name="p801136687165633"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078500513165633"><a name="p1078500513165633"></a><a name="p1078500513165633"></a>virtual void </p>
<p id="p792056725165633"><a name="p792056725165633"></a><a name="p792056725165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1589841622165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1633768908165633"><a name="p1633768908165633"></a><a name="p1633768908165633"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771560137165633"><a name="p771560137165633"></a><a name="p771560137165633"></a>virtual void </p>
<p id="p1664617656165633"><a name="p1664617656165633"></a><a name="p1664617656165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1015251305165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1018157479165633"><a name="p1018157479165633"></a><a name="p1018157479165633"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825145367165633"><a name="p825145367165633"></a><a name="p825145367165633"></a>bool </p>
<p id="p1276902328165633"><a name="p1276902328165633"></a><a name="p1276902328165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1062836302165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p7475937165633"><a name="p7475937165633"></a><a name="p7475937165633"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135638596165633"><a name="p135638596165633"></a><a name="p135638596165633"></a>void </p>
<p id="p1019434499165633"><a name="p1019434499165633"></a><a name="p1019434499165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row87774358165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p618628959165633"><a name="p618628959165633"></a><a name="p618628959165633"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354216765165633"><a name="p1354216765165633"></a><a name="p1354216765165633"></a>void </p>
<p id="p354251298165633"><a name="p354251298165633"></a><a name="p354251298165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1151032284165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612775023165633"><a name="p612775023165633"></a><a name="p612775023165633"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p712218728165633"><a name="p712218728165633"></a><a name="p712218728165633"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p1817085516165633"><a name="p1817085516165633"></a><a name="p1817085516165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1768236849165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1176018582165633"><a name="p1176018582165633"></a><a name="p1176018582165633"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1037469108165633"><a name="p1037469108165633"></a><a name="p1037469108165633"></a>void </p>
<p id="p1875253064165633"><a name="p1875253064165633"></a><a name="p1875253064165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1048835102165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638555479165633"><a name="p1638555479165633"></a><a name="p1638555479165633"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354803993165633"><a name="p1354803993165633"></a><a name="p1354803993165633"></a>const char * </p>
<p id="p618654408165633"><a name="p618654408165633"></a><a name="p618654408165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1935946697165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841818167165633"><a name="p841818167165633"></a><a name="p841818167165633"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p839492239165633"><a name="p839492239165633"></a><a name="p839492239165633"></a>void </p>
<p id="p1065988598165633"><a name="p1065988598165633"></a><a name="p1065988598165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row955396014165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p167319327165633"><a name="p167319327165633"></a><a name="p167319327165633"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p850662637165633"><a name="p850662637165633"></a><a name="p850662637165633"></a>int16_t </p>
<p id="p872609045165633"><a name="p872609045165633"></a><a name="p872609045165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row2069610861165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p651403952165633"><a name="p651403952165633"></a><a name="p651403952165633"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304313664165633"><a name="p304313664165633"></a><a name="p304313664165633"></a>virtual void </p>
<p id="p2084409046165633"><a name="p2084409046165633"></a><a name="p2084409046165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row80368170165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826511163165633"><a name="p826511163165633"></a><a name="p826511163165633"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2023153624165633"><a name="p2023153624165633"></a><a name="p2023153624165633"></a>void </p>
<p id="p1375904115165633"><a name="p1375904115165633"></a><a name="p1375904115165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row272359702165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1875787902165633"><a name="p1875787902165633"></a><a name="p1875787902165633"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815172808165633"><a name="p815172808165633"></a><a name="p815172808165633"></a>void </p>
<p id="p140340964165633"><a name="p140340964165633"></a><a name="p140340964165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row307590094165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1013565090165633"><a name="p1013565090165633"></a><a name="p1013565090165633"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1946421554165633"><a name="p1946421554165633"></a><a name="p1946421554165633"></a>void </p>
<p id="p124700726165633"><a name="p124700726165633"></a><a name="p124700726165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1288695405165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440876838165633"><a name="p1440876838165633"></a><a name="p1440876838165633"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783994975165633"><a name="p783994975165633"></a><a name="p783994975165633"></a>void </p>
<p id="p104471808165633"><a name="p104471808165633"></a><a name="p104471808165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1341606867165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377931384165633"><a name="p377931384165633"></a><a name="p377931384165633"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p933013751165633"><a name="p933013751165633"></a><a name="p933013751165633"></a>void </p>
<p id="p783310788165633"><a name="p783310788165633"></a><a name="p783310788165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1467212842165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1327137763165633"><a name="p1327137763165633"></a><a name="p1327137763165633"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208665835165633"><a name="p208665835165633"></a><a name="p208665835165633"></a>void </p>
<p id="p1378889545165633"><a name="p1378889545165633"></a><a name="p1378889545165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1841474389165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041466999165633"><a name="p1041466999165633"></a><a name="p1041466999165633"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367574943165633"><a name="p367574943165633"></a><a name="p367574943165633"></a>void </p>
<p id="p62124024165633"><a name="p62124024165633"></a><a name="p62124024165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row272232193165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719324022165633"><a name="p1719324022165633"></a><a name="p1719324022165633"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552194105165633"><a name="p552194105165633"></a><a name="p552194105165633"></a>void </p>
<p id="p2056184819165633"><a name="p2056184819165633"></a><a name="p2056184819165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1890984258165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891016484165633"><a name="p1891016484165633"></a><a name="p1891016484165633"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1363387851165633"><a name="p1363387851165633"></a><a name="p1363387851165633"></a>void </p>
<p id="p1509387084165633"><a name="p1509387084165633"></a><a name="p1509387084165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1036814279165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1629347282165633"><a name="p1629347282165633"></a><a name="p1629347282165633"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2119215722165633"><a name="p2119215722165633"></a><a name="p2119215722165633"></a>void </p>
<p id="p40311717165633"><a name="p40311717165633"></a><a name="p40311717165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row754803834165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p485300174165633"><a name="p485300174165633"></a><a name="p485300174165633"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637892793165633"><a name="p637892793165633"></a><a name="p637892793165633"></a>void </p>
<p id="p1893590791165633"><a name="p1893590791165633"></a><a name="p1893590791165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1386873114165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248479638165633"><a name="p1248479638165633"></a><a name="p1248479638165633"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063219920165633"><a name="p1063219920165633"></a><a name="p1063219920165633"></a>void </p>
<p id="p659623001165633"><a name="p659623001165633"></a><a name="p659623001165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1231339346165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1093997633165633"><a name="p1093997633165633"></a><a name="p1093997633165633"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1037793312165633"><a name="p1037793312165633"></a><a name="p1037793312165633"></a>void </p>
<p id="p1540408158165633"><a name="p1540408158165633"></a><a name="p1540408158165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row642758132165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425411949165633"><a name="p425411949165633"></a><a name="p425411949165633"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634060106165633"><a name="p1634060106165633"></a><a name="p1634060106165633"></a>void </p>
<p id="p217741721165633"><a name="p217741721165633"></a><a name="p217741721165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1819315919165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654647801165633"><a name="p654647801165633"></a><a name="p654647801165633"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1086990653165633"><a name="p1086990653165633"></a><a name="p1086990653165633"></a>void </p>
<p id="p580997838165633"><a name="p580997838165633"></a><a name="p580997838165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1512097979165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p885015831165633"><a name="p885015831165633"></a><a name="p885015831165633"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p621267947165633"><a name="p621267947165633"></a><a name="p621267947165633"></a>void </p>
<p id="p1093761039165633"><a name="p1093761039165633"></a><a name="p1093761039165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row5119400165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6350942165633"><a name="p6350942165633"></a><a name="p6350942165633"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305426418165633"><a name="p1305426418165633"></a><a name="p1305426418165633"></a>virtual void </p>
<p id="p327619184165633"><a name="p327619184165633"></a><a name="p327619184165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1699650138165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314321462165633"><a name="p314321462165633"></a><a name="p314321462165633"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941081955165633"><a name="p941081955165633"></a><a name="p941081955165633"></a>virtual int64_t </p>
<p id="p1580279863165633"><a name="p1580279863165633"></a><a name="p1580279863165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row755653080165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1936781376165633"><a name="p1936781376165633"></a><a name="p1936781376165633"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p593499156165633"><a name="p593499156165633"></a><a name="p593499156165633"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1835037743165633"><a name="p1835037743165633"></a><a name="p1835037743165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row783268744165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2040858619165633"><a name="p2040858619165633"></a><a name="p2040858619165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630674783165633"><a name="p1630674783165633"></a><a name="p1630674783165633"></a>void * </p>
<p id="p1920330775165633"><a name="p1920330775165633"></a><a name="p1920330775165633"></a>Overrides the <strong id="b981705452165633"><a name="b981705452165633"></a><a name="b981705452165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row330258571165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2040308456165633"><a name="p2040308456165633"></a><a name="p2040308456165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p616309562165633"><a name="p616309562165633"></a><a name="p616309562165633"></a>void </p>
<p id="p63306025165633"><a name="p63306025165633"></a><a name="p63306025165633"></a>Overrides the <strong id="b304742553165633"><a name="b304742553165633"></a><a name="b304742553165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table634348766165633"></a>
<table><thead align="left"><tr id="row428576868165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2099183478165633"><a name="p2099183478165633"></a><a name="p2099183478165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p403572295165633"><a name="p403572295165633"></a><a name="p403572295165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row981641443165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1305701048165633"><a name="p1305701048165633"></a><a name="p1305701048165633"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200001277165633"><a name="p1200001277165633"></a><a name="p1200001277165633"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1591504820165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1555011495165633"><a name="p1555011495165633"></a><a name="p1555011495165633"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1472552556165633"><a name="p1472552556165633"></a><a name="p1472552556165633"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row176478121165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778332621165633"><a name="p778332621165633"></a><a name="p778332621165633"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p40260042165633"><a name="p40260042165633"></a><a name="p40260042165633"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row55110893165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931795136165633"><a name="p931795136165633"></a><a name="p931795136165633"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p21575853165633"><a name="p21575853165633"></a><a name="p21575853165633"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row408067348165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p663144530165633"><a name="p663144530165633"></a><a name="p663144530165633"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1131966603165633"><a name="p1131966603165633"></a><a name="p1131966603165633"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row2079257936165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177877333165633"><a name="p1177877333165633"></a><a name="p1177877333165633"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1401621244165633"><a name="p1401621244165633"></a><a name="p1401621244165633"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row515787229165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41358707165633"><a name="p41358707165633"></a><a name="p41358707165633"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1968125624165633"><a name="p1968125624165633"></a><a name="p1968125624165633"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row2071837896165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943214664165633"><a name="p1943214664165633"></a><a name="p1943214664165633"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643371017165633"><a name="p1643371017165633"></a><a name="p1643371017165633"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

