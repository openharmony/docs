# OHOS::GridLayout<a name="ZH-CN_TOPIC_0000001054598193"></a>

-   [Overview](#section1257456601165635)
-   [Summary](#section106526950165635)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1257456601165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a grid layout container. You can perform simple grid layout on child views that the container holds. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section106526950165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1588822975165635"></a>
<table><thead align="left"><tr id="row2140191900165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1314869869165635"><a name="p1314869869165635"></a><a name="p1314869869165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1462408951165635"><a name="p1462408951165635"></a><a name="p1462408951165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1753040685165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p462665344165635"><a name="p462665344165635"></a><a name="p462665344165635"></a><a href="Graphic.md#ga9c612ad9265b7031ed95844277608b3e">GridLayout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p321199956165635"><a name="p321199956165635"></a><a name="p321199956165635"></a> </p>
<p id="p661191045165635"><a name="p661191045165635"></a><a name="p661191045165635"></a>A default constructor used to create a <strong id="b1027373808165635"><a name="b1027373808165635"></a><a name="b1027373808165635"></a><a href="OHOS-GridLayout.md">GridLayout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1083380696165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p59126407165635"><a name="p59126407165635"></a><a name="p59126407165635"></a><a href="Graphic.md#ga1c2e62760fdb7032341272197f376358">~GridLayout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709629790165635"><a name="p1709629790165635"></a><a name="p1709629790165635"></a>virtual </p>
<p id="p1968376142165635"><a name="p1968376142165635"></a><a name="p1968376142165635"></a>A destructor used to delete the <strong id="b1875616947165635"><a name="b1875616947165635"></a><a name="b1875616947165635"></a><a href="OHOS-GridLayout.md">GridLayout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1835539086165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603378262165635"><a name="p603378262165635"></a><a name="p603378262165635"></a><a href="Graphic.md#gac2df1f13d5ee6d2e6993c9a51eb9a716">SetRows</a> (const uint16_t &amp;rows)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1123671983165635"><a name="p1123671983165635"></a><a name="p1123671983165635"></a>void </p>
<p id="p1628240207165635"><a name="p1628240207165635"></a><a name="p1628240207165635"></a>Sets the number of rows in a grid. </p>
</td>
</tr>
<tr id="row1254417693165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1014737672165635"><a name="p1014737672165635"></a><a name="p1014737672165635"></a><a href="Graphic.md#gab5737dec2f5c0bc812dee9c4bc7a796b">SetCols</a> (const uint16_t &amp;cols)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898766401165635"><a name="p898766401165635"></a><a name="p898766401165635"></a>void </p>
<p id="p435158292165635"><a name="p435158292165635"></a><a name="p435158292165635"></a>Sets the number of columns in a grid. </p>
</td>
</tr>
<tr id="row334058864165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949477599165635"><a name="p949477599165635"></a><a name="p949477599165635"></a><a href="Graphic.md#ga449c17a9fa3898aac9ac68a2c48363a3">LayoutChildren</a> (bool needInvalidate=false) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p959780755165635"><a name="p959780755165635"></a><a name="p959780755165635"></a>virtual void </p>
<p id="p1856822830165635"><a name="p1856822830165635"></a><a name="p1856822830165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row2134493154165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p66449623165635"><a name="p66449623165635"></a><a name="p66449623165635"></a><a href="Graphic.md#gaba1ca0f86a85d3c5636ca543b0ed08d8">Layout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065126906165635"><a name="p1065126906165635"></a><a name="p1065126906165635"></a> </p>
<p id="p1628650291165635"><a name="p1628650291165635"></a><a name="p1628650291165635"></a>A default constructor used to create a <strong id="b1956787490165635"><a name="b1956787490165635"></a><a name="b1956787490165635"></a><a href="OHOS-Layout.md">Layout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1183879101165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757309110165635"><a name="p757309110165635"></a><a name="p757309110165635"></a><a href="Graphic.md#ga6c7cc7a849197fe014ea57d0534728bf">~Layout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p881832555165635"><a name="p881832555165635"></a><a name="p881832555165635"></a>virtual </p>
<p id="p2041704129165635"><a name="p2041704129165635"></a><a name="p2041704129165635"></a>A destructor used to delete the <strong id="b417191810165635"><a name="b417191810165635"></a><a name="b417191810165635"></a><a href="OHOS-Layout.md">Layout</a></strong> instance. </p>
</td>
</tr>
<tr id="row2098027156165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44561632165635"><a name="p44561632165635"></a><a name="p44561632165635"></a><a href="Graphic.md#gada9223ec4d664c00a9640c8b9cbcacc3">SetLayoutDirection</a> (const <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> &amp;direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786541351165635"><a name="p1786541351165635"></a><a name="p1786541351165635"></a>void </p>
<p id="p1106427524165635"><a name="p1106427524165635"></a><a name="p1106427524165635"></a>Sets the layout direction. </p>
</td>
</tr>
<tr id="row1562023222165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768972207165635"><a name="p768972207165635"></a><a name="p768972207165635"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65908121165635"><a name="p65908121165635"></a><a name="p65908121165635"></a> </p>
<p id="p1399211092165635"><a name="p1399211092165635"></a><a name="p1399211092165635"></a>A default constructor used to create a <strong id="b2117531752165635"><a name="b2117531752165635"></a><a name="b2117531752165635"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1689412226165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p675950617165635"><a name="p675950617165635"></a><a name="p675950617165635"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631899745165635"><a name="p1631899745165635"></a><a name="p1631899745165635"></a>virtual </p>
<p id="p552561247165635"><a name="p552561247165635"></a><a name="p552561247165635"></a>A destructor used to delete the <strong id="b903543386165635"><a name="b903543386165635"></a><a name="b903543386165635"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1578257170165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p883094090165635"><a name="p883094090165635"></a><a name="p883094090165635"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292683355165635"><a name="p1292683355165635"></a><a name="p1292683355165635"></a>UIViewType </p>
<p id="p511612062165635"><a name="p511612062165635"></a><a name="p511612062165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2042149959165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2045980411165635"><a name="p2045980411165635"></a><a name="p2045980411165635"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578269502165635"><a name="p1578269502165635"></a><a name="p1578269502165635"></a>virtual void </p>
<p id="p733091296165635"><a name="p733091296165635"></a><a name="p733091296165635"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1136512232165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p763604329165635"><a name="p763604329165635"></a><a name="p763604329165635"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p941814835165635"><a name="p941814835165635"></a><a name="p941814835165635"></a>virtual void </p>
<p id="p1285687012165635"><a name="p1285687012165635"></a><a name="p1285687012165635"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row494992618165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1479066132165635"><a name="p1479066132165635"></a><a name="p1479066132165635"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507414974165635"><a name="p1507414974165635"></a><a name="p1507414974165635"></a>virtual void </p>
<p id="p333040405165635"><a name="p333040405165635"></a><a name="p333040405165635"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row987243505165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1826380575165635"><a name="p1826380575165635"></a><a name="p1826380575165635"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p375629056165635"><a name="p375629056165635"></a><a name="p375629056165635"></a>virtual void </p>
<p id="p1388617200165635"><a name="p1388617200165635"></a><a name="p1388617200165635"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row852983750165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1494147571165635"><a name="p1494147571165635"></a><a name="p1494147571165635"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911188121165635"><a name="p1911188121165635"></a><a name="p1911188121165635"></a>virtual void </p>
<p id="p1849915565165635"><a name="p1849915565165635"></a><a name="p1849915565165635"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row374695382165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p588999764165635"><a name="p588999764165635"></a><a name="p588999764165635"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694445746165635"><a name="p1694445746165635"></a><a name="p1694445746165635"></a>virtual void </p>
<p id="p821948287165635"><a name="p821948287165635"></a><a name="p821948287165635"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1749329934165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1785641164165635"><a name="p1785641164165635"></a><a name="p1785641164165635"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1752384711165635"><a name="p1752384711165635"></a><a name="p1752384711165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p262292392165635"><a name="p262292392165635"></a><a name="p262292392165635"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1340302617165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p79627955165635"><a name="p79627955165635"></a><a name="p79627955165635"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p551288592165635"><a name="p551288592165635"></a><a name="p551288592165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1554304193165635"><a name="p1554304193165635"></a><a name="p1554304193165635"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1573639003165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1087015908165635"><a name="p1087015908165635"></a><a name="p1087015908165635"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64622700165635"><a name="p64622700165635"></a><a name="p64622700165635"></a>void </p>
<p id="p1660998212165635"><a name="p1660998212165635"></a><a name="p1660998212165635"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row2013613793165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1048807619165635"><a name="p1048807619165635"></a><a name="p1048807619165635"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1288251570165635"><a name="p1288251570165635"></a><a name="p1288251570165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p750457938165635"><a name="p750457938165635"></a><a name="p750457938165635"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row65980448165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1327632089165635"><a name="p1327632089165635"></a><a name="p1327632089165635"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731663772165635"><a name="p731663772165635"></a><a name="p731663772165635"></a>void </p>
<p id="p908113447165635"><a name="p908113447165635"></a><a name="p908113447165635"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1013076655165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468231494165635"><a name="p468231494165635"></a><a name="p468231494165635"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938010706165635"><a name="p938010706165635"></a><a name="p938010706165635"></a> </p>
<p id="p265800585165635"><a name="p265800585165635"></a><a name="p265800585165635"></a>A default constructor used to create an <strong id="b400086438165635"><a name="b400086438165635"></a><a name="b400086438165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row388820449165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983335422165635"><a name="p1983335422165635"></a><a name="p1983335422165635"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14621948165635"><a name="p14621948165635"></a><a name="p14621948165635"></a> </p>
<p id="p1615000011165635"><a name="p1615000011165635"></a><a name="p1615000011165635"></a>A constructor used to create an <strong id="b14057049165635"><a name="b14057049165635"></a><a name="b14057049165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row394004533165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004458535165635"><a name="p1004458535165635"></a><a name="p1004458535165635"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769744353165635"><a name="p769744353165635"></a><a name="p769744353165635"></a>virtual </p>
<p id="p1660492669165635"><a name="p1660492669165635"></a><a name="p1660492669165635"></a>A destructor used to delete the <strong id="b1299451590165635"><a name="b1299451590165635"></a><a name="b1299451590165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row381833706165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2054882382165635"><a name="p2054882382165635"></a><a name="p2054882382165635"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1501904457165635"><a name="p1501904457165635"></a><a name="p1501904457165635"></a>virtual bool </p>
<p id="p2095405088165635"><a name="p2095405088165635"></a><a name="p2095405088165635"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row932616265165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p378320987165635"><a name="p378320987165635"></a><a name="p378320987165635"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368775541165635"><a name="p368775541165635"></a><a name="p368775541165635"></a>virtual void </p>
<p id="p183713258165635"><a name="p183713258165635"></a><a name="p183713258165635"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row973590836165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1784140455165635"><a name="p1784140455165635"></a><a name="p1784140455165635"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1540985944165635"><a name="p1540985944165635"></a><a name="p1540985944165635"></a>virtual void </p>
<p id="p1327001361165635"><a name="p1327001361165635"></a><a name="p1327001361165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row654644915165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1505936927165635"><a name="p1505936927165635"></a><a name="p1505936927165635"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406585165165635"><a name="p406585165165635"></a><a name="p406585165165635"></a>virtual void </p>
<p id="p562105105165635"><a name="p562105105165635"></a><a name="p562105105165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1461044092165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032450422165635"><a name="p2032450422165635"></a><a name="p2032450422165635"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1736879576165635"><a name="p1736879576165635"></a><a name="p1736879576165635"></a>void </p>
<p id="p1952843626165635"><a name="p1952843626165635"></a><a name="p1952843626165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1980021937165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1739968206165635"><a name="p1739968206165635"></a><a name="p1739968206165635"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911455611165635"><a name="p1911455611165635"></a><a name="p1911455611165635"></a>void </p>
<p id="p1559613521165635"><a name="p1559613521165635"></a><a name="p1559613521165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row417184623165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p297986142165635"><a name="p297986142165635"></a><a name="p297986142165635"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p189188194165635"><a name="p189188194165635"></a><a name="p189188194165635"></a>virtual bool </p>
<p id="p1516018048165635"><a name="p1516018048165635"></a><a name="p1516018048165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row2122823120165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919182198165635"><a name="p919182198165635"></a><a name="p919182198165635"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1674340174165635"><a name="p1674340174165635"></a><a name="p1674340174165635"></a>virtual bool </p>
<p id="p157608615165635"><a name="p157608615165635"></a><a name="p157608615165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1004541671165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1525835098165635"><a name="p1525835098165635"></a><a name="p1525835098165635"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1396065883165635"><a name="p1396065883165635"></a><a name="p1396065883165635"></a>virtual bool </p>
<p id="p432016848165635"><a name="p432016848165635"></a><a name="p432016848165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1052757105165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1016154212165635"><a name="p1016154212165635"></a><a name="p1016154212165635"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144574351165635"><a name="p144574351165635"></a><a name="p144574351165635"></a>virtual bool </p>
<p id="p697353481165635"><a name="p697353481165635"></a><a name="p697353481165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row245607772165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453343118165635"><a name="p1453343118165635"></a><a name="p1453343118165635"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663625700165635"><a name="p1663625700165635"></a><a name="p1663625700165635"></a>virtual void </p>
<p id="p374033701165635"><a name="p374033701165635"></a><a name="p374033701165635"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row866883444165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p854029484165635"><a name="p854029484165635"></a><a name="p854029484165635"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1044609741165635"><a name="p1044609741165635"></a><a name="p1044609741165635"></a>virtual void </p>
<p id="p737937388165635"><a name="p737937388165635"></a><a name="p737937388165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1925438690165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p685776716165635"><a name="p685776716165635"></a><a name="p685776716165635"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404056848165635"><a name="p1404056848165635"></a><a name="p1404056848165635"></a>virtual void </p>
<p id="p1934491511165635"><a name="p1934491511165635"></a><a name="p1934491511165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row2108862130165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1326864765165635"><a name="p1326864765165635"></a><a name="p1326864765165635"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p561117809165635"><a name="p561117809165635"></a><a name="p561117809165635"></a>virtual void </p>
<p id="p1614007122165635"><a name="p1614007122165635"></a><a name="p1614007122165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row234828139165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763984038165635"><a name="p1763984038165635"></a><a name="p1763984038165635"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p193835228165635"><a name="p193835228165635"></a><a name="p193835228165635"></a>void </p>
<p id="p1264083306165635"><a name="p1264083306165635"></a><a name="p1264083306165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1282584712165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p575691173165635"><a name="p575691173165635"></a><a name="p575691173165635"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1293447921165635"><a name="p1293447921165635"></a><a name="p1293447921165635"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1746744685165635"><a name="p1746744685165635"></a><a name="p1746744685165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1839384142165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2109571057165635"><a name="p2109571057165635"></a><a name="p2109571057165635"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494519362165635"><a name="p1494519362165635"></a><a name="p1494519362165635"></a>void </p>
<p id="p1068379311165635"><a name="p1068379311165635"></a><a name="p1068379311165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row2025681181165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1886592026165635"><a name="p1886592026165635"></a><a name="p1886592026165635"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p256743972165635"><a name="p256743972165635"></a><a name="p256743972165635"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p937967539165635"><a name="p937967539165635"></a><a name="p937967539165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row756900703165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p859568603165635"><a name="p859568603165635"></a><a name="p859568603165635"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p701598744165635"><a name="p701598744165635"></a><a name="p701598744165635"></a>void </p>
<p id="p526313043165635"><a name="p526313043165635"></a><a name="p526313043165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1691182266165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1711254068165635"><a name="p1711254068165635"></a><a name="p1711254068165635"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832029957165635"><a name="p1832029957165635"></a><a name="p1832029957165635"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1146862052165635"><a name="p1146862052165635"></a><a name="p1146862052165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row575957184165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p458264461165635"><a name="p458264461165635"></a><a name="p458264461165635"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p431349077165635"><a name="p431349077165635"></a><a name="p431349077165635"></a>void </p>
<p id="p1341816922165635"><a name="p1341816922165635"></a><a name="p1341816922165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row583206687165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1776670842165635"><a name="p1776670842165635"></a><a name="p1776670842165635"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1328100237165635"><a name="p1328100237165635"></a><a name="p1328100237165635"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1640179218165635"><a name="p1640179218165635"></a><a name="p1640179218165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row2029706137165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1307640532165635"><a name="p1307640532165635"></a><a name="p1307640532165635"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609054624165635"><a name="p609054624165635"></a><a name="p609054624165635"></a>void </p>
<p id="p1549173966165635"><a name="p1549173966165635"></a><a name="p1549173966165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1853167708165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1279511366165635"><a name="p1279511366165635"></a><a name="p1279511366165635"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1458975476165635"><a name="p1458975476165635"></a><a name="p1458975476165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1942661417165635"><a name="p1942661417165635"></a><a name="p1942661417165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1353655077165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16133388165635"><a name="p16133388165635"></a><a name="p16133388165635"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466718431165635"><a name="p466718431165635"></a><a name="p466718431165635"></a>void </p>
<p id="p1139153120165635"><a name="p1139153120165635"></a><a name="p1139153120165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row2143145779165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p77585837165635"><a name="p77585837165635"></a><a name="p77585837165635"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118626902165635"><a name="p118626902165635"></a><a name="p118626902165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1634873475165635"><a name="p1634873475165635"></a><a name="p1634873475165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1181546211165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790357364165635"><a name="p1790357364165635"></a><a name="p1790357364165635"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p403885949165635"><a name="p403885949165635"></a><a name="p403885949165635"></a>virtual void </p>
<p id="p1843185583165635"><a name="p1843185583165635"></a><a name="p1843185583165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row112179554165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1015190619165635"><a name="p1015190619165635"></a><a name="p1015190619165635"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43842240165635"><a name="p43842240165635"></a><a name="p43842240165635"></a>bool </p>
<p id="p343148239165635"><a name="p343148239165635"></a><a name="p343148239165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1510822616165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2039337709165635"><a name="p2039337709165635"></a><a name="p2039337709165635"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1237931295165635"><a name="p1237931295165635"></a><a name="p1237931295165635"></a>void </p>
<p id="p1787127261165635"><a name="p1787127261165635"></a><a name="p1787127261165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1969431054165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p42650039165635"><a name="p42650039165635"></a><a name="p42650039165635"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916373684165635"><a name="p1916373684165635"></a><a name="p1916373684165635"></a>bool </p>
<p id="p1974218192165635"><a name="p1974218192165635"></a><a name="p1974218192165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1710472614165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283992346165635"><a name="p283992346165635"></a><a name="p283992346165635"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p226021785165635"><a name="p226021785165635"></a><a name="p226021785165635"></a>void </p>
<p id="p1394194554165635"><a name="p1394194554165635"></a><a name="p1394194554165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row367550865165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1979186634165635"><a name="p1979186634165635"></a><a name="p1979186634165635"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p199814618165635"><a name="p199814618165635"></a><a name="p199814618165635"></a>bool </p>
<p id="p1175677246165635"><a name="p1175677246165635"></a><a name="p1175677246165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row656373779165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450178059165635"><a name="p1450178059165635"></a><a name="p1450178059165635"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621496518165635"><a name="p1621496518165635"></a><a name="p1621496518165635"></a>void </p>
<p id="p160679151165635"><a name="p160679151165635"></a><a name="p160679151165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row601108631165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1496630523165635"><a name="p1496630523165635"></a><a name="p1496630523165635"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488070623165635"><a name="p488070623165635"></a><a name="p488070623165635"></a>bool </p>
<p id="p201880151165635"><a name="p201880151165635"></a><a name="p201880151165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row711377265165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405417916165635"><a name="p405417916165635"></a><a name="p405417916165635"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223902712165635"><a name="p223902712165635"></a><a name="p223902712165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1324358493165635"><a name="p1324358493165635"></a><a name="p1324358493165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row407439554165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535143987165635"><a name="p535143987165635"></a><a name="p535143987165635"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406194043165635"><a name="p406194043165635"></a><a name="p406194043165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2131639772165635"><a name="p2131639772165635"></a><a name="p2131639772165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row2077179457165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2108590273165635"><a name="p2108590273165635"></a><a name="p2108590273165635"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1238096620165635"><a name="p1238096620165635"></a><a name="p1238096620165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p134415234165635"><a name="p134415234165635"></a><a name="p134415234165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1374955589165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p454596659165635"><a name="p454596659165635"></a><a name="p454596659165635"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579862615165635"><a name="p1579862615165635"></a><a name="p1579862615165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2052515345165635"><a name="p2052515345165635"></a><a name="p2052515345165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1176502649165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1316738602165635"><a name="p1316738602165635"></a><a name="p1316738602165635"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1923380436165635"><a name="p1923380436165635"></a><a name="p1923380436165635"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1275900717165635"><a name="p1275900717165635"></a><a name="p1275900717165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row971640244165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1255564995165635"><a name="p1255564995165635"></a><a name="p1255564995165635"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506673297165635"><a name="p506673297165635"></a><a name="p506673297165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2005814943165635"><a name="p2005814943165635"></a><a name="p2005814943165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row506398595165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p462624540165635"><a name="p462624540165635"></a><a name="p462624540165635"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1748764700165635"><a name="p1748764700165635"></a><a name="p1748764700165635"></a>void </p>
<p id="p768955432165635"><a name="p768955432165635"></a><a name="p768955432165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row471846028165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576765877165635"><a name="p576765877165635"></a><a name="p576765877165635"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837252891165635"><a name="p1837252891165635"></a><a name="p1837252891165635"></a>virtual void </p>
<p id="p1543896454165635"><a name="p1543896454165635"></a><a name="p1543896454165635"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row855427638165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2020273878165635"><a name="p2020273878165635"></a><a name="p2020273878165635"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1914091309165635"><a name="p1914091309165635"></a><a name="p1914091309165635"></a>virtual int16_t </p>
<p id="p1759785656165635"><a name="p1759785656165635"></a><a name="p1759785656165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1710409912165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1810083206165635"><a name="p1810083206165635"></a><a name="p1810083206165635"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p257197583165635"><a name="p257197583165635"></a><a name="p257197583165635"></a>virtual void </p>
<p id="p1350366863165635"><a name="p1350366863165635"></a><a name="p1350366863165635"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row559420475165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p85255751165635"><a name="p85255751165635"></a><a name="p85255751165635"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648666794165635"><a name="p1648666794165635"></a><a name="p1648666794165635"></a>virtual int16_t </p>
<p id="p742865378165635"><a name="p742865378165635"></a><a name="p742865378165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row2113650632165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029584974165635"><a name="p2029584974165635"></a><a name="p2029584974165635"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p149294564165635"><a name="p149294564165635"></a><a name="p149294564165635"></a>virtual void </p>
<p id="p797633279165635"><a name="p797633279165635"></a><a name="p797633279165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row728070295165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025667395165635"><a name="p2025667395165635"></a><a name="p2025667395165635"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1031255843165635"><a name="p1031255843165635"></a><a name="p1031255843165635"></a>virtual void </p>
<p id="p735781048165635"><a name="p735781048165635"></a><a name="p735781048165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row870283925165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p987882233165635"><a name="p987882233165635"></a><a name="p987882233165635"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502696203165635"><a name="p1502696203165635"></a><a name="p1502696203165635"></a>int16_t </p>
<p id="p1277562827165635"><a name="p1277562827165635"></a><a name="p1277562827165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1946372788165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206697892165635"><a name="p1206697892165635"></a><a name="p1206697892165635"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1731829042165635"><a name="p1731829042165635"></a><a name="p1731829042165635"></a>virtual void </p>
<p id="p2072122722165635"><a name="p2072122722165635"></a><a name="p2072122722165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row651933443165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281826567165635"><a name="p1281826567165635"></a><a name="p1281826567165635"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788870128165635"><a name="p788870128165635"></a><a name="p788870128165635"></a>int16_t </p>
<p id="p502135541165635"><a name="p502135541165635"></a><a name="p502135541165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1364930638165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1151384640165635"><a name="p1151384640165635"></a><a name="p1151384640165635"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p124944103165635"><a name="p124944103165635"></a><a name="p124944103165635"></a>virtual void </p>
<p id="p951739513165635"><a name="p951739513165635"></a><a name="p951739513165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1544697908165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975034642165635"><a name="p1975034642165635"></a><a name="p1975034642165635"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1883306983165635"><a name="p1883306983165635"></a><a name="p1883306983165635"></a>virtual void </p>
<p id="p2058500762165635"><a name="p2058500762165635"></a><a name="p2058500762165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1777346111165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p747859843165635"><a name="p747859843165635"></a><a name="p747859843165635"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731747861165635"><a name="p731747861165635"></a><a name="p731747861165635"></a>bool </p>
<p id="p781734446165635"><a name="p781734446165635"></a><a name="p781734446165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row171426913165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p478860769165635"><a name="p478860769165635"></a><a name="p478860769165635"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818024666165635"><a name="p1818024666165635"></a><a name="p1818024666165635"></a>void </p>
<p id="p1606932740165635"><a name="p1606932740165635"></a><a name="p1606932740165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1130103305165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1174228478165635"><a name="p1174228478165635"></a><a name="p1174228478165635"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534145655165635"><a name="p1534145655165635"></a><a name="p1534145655165635"></a>void </p>
<p id="p772080053165635"><a name="p772080053165635"></a><a name="p772080053165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1965662563165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659934690165635"><a name="p659934690165635"></a><a name="p659934690165635"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p851123149165635"><a name="p851123149165635"></a><a name="p851123149165635"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p80853749165635"><a name="p80853749165635"></a><a name="p80853749165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row378011496165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1955349702165635"><a name="p1955349702165635"></a><a name="p1955349702165635"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669772224165635"><a name="p669772224165635"></a><a name="p669772224165635"></a>void </p>
<p id="p95360291165635"><a name="p95360291165635"></a><a name="p95360291165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1188569829165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1812528383165635"><a name="p1812528383165635"></a><a name="p1812528383165635"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663608730165635"><a name="p663608730165635"></a><a name="p663608730165635"></a>const char * </p>
<p id="p1001533270165635"><a name="p1001533270165635"></a><a name="p1001533270165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1595822880165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652858555165635"><a name="p1652858555165635"></a><a name="p1652858555165635"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1412316091165635"><a name="p1412316091165635"></a><a name="p1412316091165635"></a>void </p>
<p id="p1865669070165635"><a name="p1865669070165635"></a><a name="p1865669070165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1786572985165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412832069165635"><a name="p412832069165635"></a><a name="p412832069165635"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p367434464165635"><a name="p367434464165635"></a><a name="p367434464165635"></a>int16_t </p>
<p id="p1987246042165635"><a name="p1987246042165635"></a><a name="p1987246042165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1293170297165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p128689265165635"><a name="p128689265165635"></a><a name="p128689265165635"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2070133682165635"><a name="p2070133682165635"></a><a name="p2070133682165635"></a>void </p>
<p id="p1852197958165635"><a name="p1852197958165635"></a><a name="p1852197958165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row853283657165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p344789075165635"><a name="p344789075165635"></a><a name="p344789075165635"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371263239165635"><a name="p371263239165635"></a><a name="p371263239165635"></a>void </p>
<p id="p404279444165635"><a name="p404279444165635"></a><a name="p404279444165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row626268017165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2124575173165635"><a name="p2124575173165635"></a><a name="p2124575173165635"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568622313165635"><a name="p1568622313165635"></a><a name="p1568622313165635"></a>void </p>
<p id="p388233412165635"><a name="p388233412165635"></a><a name="p388233412165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row121270634165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1353959216165635"><a name="p1353959216165635"></a><a name="p1353959216165635"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702876377165635"><a name="p702876377165635"></a><a name="p702876377165635"></a>void </p>
<p id="p1107883083165635"><a name="p1107883083165635"></a><a name="p1107883083165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row2109421347165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p246454817165635"><a name="p246454817165635"></a><a name="p246454817165635"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259390160165635"><a name="p1259390160165635"></a><a name="p1259390160165635"></a>void </p>
<p id="p384583191165635"><a name="p384583191165635"></a><a name="p384583191165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1817859692165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563621746165635"><a name="p563621746165635"></a><a name="p563621746165635"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828237739165635"><a name="p828237739165635"></a><a name="p828237739165635"></a>void </p>
<p id="p62294221165635"><a name="p62294221165635"></a><a name="p62294221165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row645429532165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336859402165635"><a name="p1336859402165635"></a><a name="p1336859402165635"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19391724165635"><a name="p19391724165635"></a><a name="p19391724165635"></a>void </p>
<p id="p1159660674165635"><a name="p1159660674165635"></a><a name="p1159660674165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1549065713165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830456284165635"><a name="p830456284165635"></a><a name="p830456284165635"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p760467714165635"><a name="p760467714165635"></a><a name="p760467714165635"></a>void </p>
<p id="p1284369418165635"><a name="p1284369418165635"></a><a name="p1284369418165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row203709041165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786020670165635"><a name="p786020670165635"></a><a name="p786020670165635"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762547119165635"><a name="p1762547119165635"></a><a name="p1762547119165635"></a>void </p>
<p id="p1012007054165635"><a name="p1012007054165635"></a><a name="p1012007054165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row155378530165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1851004275165635"><a name="p1851004275165635"></a><a name="p1851004275165635"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001601346165635"><a name="p2001601346165635"></a><a name="p2001601346165635"></a>void </p>
<p id="p1548676608165635"><a name="p1548676608165635"></a><a name="p1548676608165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row755676836165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p799886374165635"><a name="p799886374165635"></a><a name="p799886374165635"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488241555165635"><a name="p1488241555165635"></a><a name="p1488241555165635"></a>void </p>
<p id="p1241259948165635"><a name="p1241259948165635"></a><a name="p1241259948165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row4377241165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1965353828165635"><a name="p1965353828165635"></a><a name="p1965353828165635"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p600216362165635"><a name="p600216362165635"></a><a name="p600216362165635"></a>void </p>
<p id="p892445192165635"><a name="p892445192165635"></a><a name="p892445192165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1758514748165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1277496661165635"><a name="p1277496661165635"></a><a name="p1277496661165635"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1412870366165635"><a name="p1412870366165635"></a><a name="p1412870366165635"></a>void </p>
<p id="p998285876165635"><a name="p998285876165635"></a><a name="p998285876165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row560793209165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1406815364165635"><a name="p1406815364165635"></a><a name="p1406815364165635"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1012051215165635"><a name="p1012051215165635"></a><a name="p1012051215165635"></a>void </p>
<p id="p1300306266165635"><a name="p1300306266165635"></a><a name="p1300306266165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1553021458165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268978742165635"><a name="p1268978742165635"></a><a name="p1268978742165635"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p716092482165635"><a name="p716092482165635"></a><a name="p716092482165635"></a>void </p>
<p id="p1819156152165635"><a name="p1819156152165635"></a><a name="p1819156152165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1070389475165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1201606722165635"><a name="p1201606722165635"></a><a name="p1201606722165635"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1076359095165635"><a name="p1076359095165635"></a><a name="p1076359095165635"></a>void </p>
<p id="p551106398165635"><a name="p551106398165635"></a><a name="p551106398165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row542213818165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1284263064165635"><a name="p1284263064165635"></a><a name="p1284263064165635"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p542642064165635"><a name="p542642064165635"></a><a name="p542642064165635"></a>virtual void </p>
<p id="p1050031756165635"><a name="p1050031756165635"></a><a name="p1050031756165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row936001567165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358570285165635"><a name="p358570285165635"></a><a name="p358570285165635"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1946297197165635"><a name="p1946297197165635"></a><a name="p1946297197165635"></a>virtual int64_t </p>
<p id="p406596029165635"><a name="p406596029165635"></a><a name="p406596029165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1836148761165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p324220623165635"><a name="p324220623165635"></a><a name="p324220623165635"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872188599165635"><a name="p1872188599165635"></a><a name="p1872188599165635"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p438031328165635"><a name="p438031328165635"></a><a name="p438031328165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row399859660165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p744943220165635"><a name="p744943220165635"></a><a name="p744943220165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499807556165635"><a name="p499807556165635"></a><a name="p499807556165635"></a>void * </p>
<p id="p161384384165635"><a name="p161384384165635"></a><a name="p161384384165635"></a>Overrides the <strong id="b912379156165635"><a name="b912379156165635"></a><a name="b912379156165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1776297460165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696783597165635"><a name="p696783597165635"></a><a name="p696783597165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1432777811165635"><a name="p1432777811165635"></a><a name="p1432777811165635"></a>void </p>
<p id="p1904442184165635"><a name="p1904442184165635"></a><a name="p1904442184165635"></a>Overrides the <strong id="b1899546187165635"><a name="b1899546187165635"></a><a name="b1899546187165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1813184000165635"></a>
<table><thead align="left"><tr id="row1868488031165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1661462865165635"><a name="p1661462865165635"></a><a name="p1661462865165635"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p567299682165635"><a name="p567299682165635"></a><a name="p567299682165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row136056598165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1570255364165635"><a name="p1570255364165635"></a><a name="p1570255364165635"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515370575165635"><a name="p1515370575165635"></a><a name="p1515370575165635"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1605291972165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763816445165635"><a name="p1763816445165635"></a><a name="p1763816445165635"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442506433165635"><a name="p442506433165635"></a><a name="p442506433165635"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1568223211165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362203503165635"><a name="p1362203503165635"></a><a name="p1362203503165635"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760818962165635"><a name="p1760818962165635"></a><a name="p1760818962165635"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1869134865165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p138483520165635"><a name="p138483520165635"></a><a name="p138483520165635"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1144726123165635"><a name="p1144726123165635"></a><a name="p1144726123165635"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row2076158525165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616424248165635"><a name="p616424248165635"></a><a name="p616424248165635"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1607533446165635"><a name="p1607533446165635"></a><a name="p1607533446165635"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row477573323165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p721619647165635"><a name="p721619647165635"></a><a name="p721619647165635"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801369668165635"><a name="p1801369668165635"></a><a name="p1801369668165635"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1778970395165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1955176254165635"><a name="p1955176254165635"></a><a name="p1955176254165635"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p128973143165635"><a name="p128973143165635"></a><a name="p128973143165635"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1084767485165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p954024365165635"><a name="p954024365165635"></a><a name="p954024365165635"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22460593165635"><a name="p22460593165635"></a><a name="p22460593165635"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

