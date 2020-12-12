# OHOS::Layout<a name="EN-US_TOPIC_0000001054918187"></a>

-   [Overview](#section833083656165635)
-   [Summary](#section1992683037165635)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section833083656165635"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the base class of the layout, which indicates the basic data types and operations that may be used in the layout. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1992683037165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1936544552165635"></a>
<table><thead align="left"><tr id="row1678303942165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p59179334165635"><a name="p59179334165635"></a><a name="p59179334165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1438061082165635"><a name="p1438061082165635"></a><a name="p1438061082165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row602692591165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p769849385165635"><a name="p769849385165635"></a><a name="p769849385165635"></a><a href="graphic.md#gaba1ca0f86a85d3c5636ca543b0ed08d8">Layout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p150638859165635"><a name="p150638859165635"></a><a name="p150638859165635"></a> </p>
<p id="p185518980165635"><a name="p185518980165635"></a><a name="p185518980165635"></a>A default constructor used to create a <strong id="b938976105165635"><a name="b938976105165635"></a><a name="b938976105165635"></a><a href="ohos-layout.md">Layout</a></strong> instance. </p>
</td>
</tr>
<tr id="row503719164165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p514377780165635"><a name="p514377780165635"></a><a name="p514377780165635"></a><a href="graphic.md#ga6c7cc7a849197fe014ea57d0534728bf">~Layout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892629044165635"><a name="p1892629044165635"></a><a name="p1892629044165635"></a>virtual </p>
<p id="p1920137752165635"><a name="p1920137752165635"></a><a name="p1920137752165635"></a>A destructor used to delete the <strong id="b1854960903165635"><a name="b1854960903165635"></a><a name="b1854960903165635"></a><a href="ohos-layout.md">Layout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1435691695165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214451316165635"><a name="p214451316165635"></a><a name="p214451316165635"></a><a href="graphic.md#gada9223ec4d664c00a9640c8b9cbcacc3">SetLayoutDirection</a> (const <a href="codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> &amp;direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33702894165635"><a name="p33702894165635"></a><a name="p33702894165635"></a>void </p>
<p id="p20773593165635"><a name="p20773593165635"></a><a name="p20773593165635"></a>Sets the layout direction. </p>
</td>
</tr>
<tr id="row1665176768165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1002575762165635"><a name="p1002575762165635"></a><a name="p1002575762165635"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894881509165635"><a name="p1894881509165635"></a><a name="p1894881509165635"></a> </p>
<p id="p1176683202165635"><a name="p1176683202165635"></a><a name="p1176683202165635"></a>A default constructor used to create a <strong id="b1455807559165635"><a name="b1455807559165635"></a><a name="b1455807559165635"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row2090897430165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p185008219165635"><a name="p185008219165635"></a><a name="p185008219165635"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645458108165635"><a name="p645458108165635"></a><a name="p645458108165635"></a>virtual </p>
<p id="p1409528214165635"><a name="p1409528214165635"></a><a name="p1409528214165635"></a>A destructor used to delete the <strong id="b1950448120165635"><a name="b1950448120165635"></a><a name="b1950448120165635"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1680741651165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p432847068165635"><a name="p432847068165635"></a><a name="p432847068165635"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420958968165635"><a name="p1420958968165635"></a><a name="p1420958968165635"></a>UIViewType </p>
<p id="p1833048693165635"><a name="p1833048693165635"></a><a name="p1833048693165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1632363233165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500992136165635"><a name="p1500992136165635"></a><a name="p1500992136165635"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121516285165635"><a name="p1121516285165635"></a><a name="p1121516285165635"></a>virtual void </p>
<p id="p1174669098165635"><a name="p1174669098165635"></a><a name="p1174669098165635"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row21842520165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1933241692165635"><a name="p1933241692165635"></a><a name="p1933241692165635"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1103127979165635"><a name="p1103127979165635"></a><a name="p1103127979165635"></a>virtual void </p>
<p id="p400857799165635"><a name="p400857799165635"></a><a name="p400857799165635"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row280119730165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1096546591165635"><a name="p1096546591165635"></a><a name="p1096546591165635"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1538794611165635"><a name="p1538794611165635"></a><a name="p1538794611165635"></a>virtual void </p>
<p id="p680847218165635"><a name="p680847218165635"></a><a name="p680847218165635"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1189019072165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020683119165635"><a name="p1020683119165635"></a><a name="p1020683119165635"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38477022165635"><a name="p38477022165635"></a><a name="p38477022165635"></a>virtual void </p>
<p id="p1143103010165635"><a name="p1143103010165635"></a><a name="p1143103010165635"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1518596152165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1011502634165635"><a name="p1011502634165635"></a><a name="p1011502634165635"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p376067775165635"><a name="p376067775165635"></a><a name="p376067775165635"></a>virtual void </p>
<p id="p297437665165635"><a name="p297437665165635"></a><a name="p297437665165635"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1078111881165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p978646373165635"><a name="p978646373165635"></a><a name="p978646373165635"></a><a href="graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1810037284165635"><a name="p1810037284165635"></a><a name="p1810037284165635"></a>virtual void </p>
<p id="p1992021944165635"><a name="p1992021944165635"></a><a name="p1992021944165635"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1491549095165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896120404165635"><a name="p896120404165635"></a><a name="p896120404165635"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294057766165635"><a name="p294057766165635"></a><a name="p294057766165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p376543556165635"><a name="p376543556165635"></a><a name="p376543556165635"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1367459780165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p948353490165635"><a name="p948353490165635"></a><a name="p948353490165635"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400775146165635"><a name="p400775146165635"></a><a name="p400775146165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p810346361165635"><a name="p810346361165635"></a><a name="p810346361165635"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row510342397165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p434057613165635"><a name="p434057613165635"></a><a name="p434057613165635"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427190941165635"><a name="p1427190941165635"></a><a name="p1427190941165635"></a>void </p>
<p id="p905691713165635"><a name="p905691713165635"></a><a name="p905691713165635"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1351176557165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2103323979165635"><a name="p2103323979165635"></a><a name="p2103323979165635"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366744991165635"><a name="p366744991165635"></a><a name="p366744991165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1889263241165635"><a name="p1889263241165635"></a><a name="p1889263241165635"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1021351747165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1699936121165635"><a name="p1699936121165635"></a><a name="p1699936121165635"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706237755165635"><a name="p1706237755165635"></a><a name="p1706237755165635"></a>void </p>
<p id="p1994510293165635"><a name="p1994510293165635"></a><a name="p1994510293165635"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row113623447165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1249836319165635"><a name="p1249836319165635"></a><a name="p1249836319165635"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13889621165635"><a name="p13889621165635"></a><a name="p13889621165635"></a> </p>
<p id="p420853392165635"><a name="p420853392165635"></a><a name="p420853392165635"></a>A default constructor used to create an <strong id="b390472009165635"><a name="b390472009165635"></a><a name="b390472009165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2078810776165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1668843971165635"><a name="p1668843971165635"></a><a name="p1668843971165635"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864921514165635"><a name="p864921514165635"></a><a name="p864921514165635"></a> </p>
<p id="p906032913165635"><a name="p906032913165635"></a><a name="p906032913165635"></a>A constructor used to create an <strong id="b1584109995165635"><a name="b1584109995165635"></a><a name="b1584109995165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2006861905165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146391171165635"><a name="p146391171165635"></a><a name="p146391171165635"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1263061914165635"><a name="p1263061914165635"></a><a name="p1263061914165635"></a>virtual </p>
<p id="p1963489442165635"><a name="p1963489442165635"></a><a name="p1963489442165635"></a>A destructor used to delete the <strong id="b1733418069165635"><a name="b1733418069165635"></a><a name="b1733418069165635"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row601936207165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217290247165635"><a name="p1217290247165635"></a><a name="p1217290247165635"></a><a href="graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779424041165635"><a name="p1779424041165635"></a><a name="p1779424041165635"></a>virtual bool </p>
<p id="p1312458534165635"><a name="p1312458534165635"></a><a name="p1312458534165635"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row155236481165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45740423165635"><a name="p45740423165635"></a><a name="p45740423165635"></a><a href="graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1655024618165635"><a name="p1655024618165635"></a><a name="p1655024618165635"></a>virtual void </p>
<p id="p613820669165635"><a name="p613820669165635"></a><a name="p613820669165635"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1755953701165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p939623406165635"><a name="p939623406165635"></a><a name="p939623406165635"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1362580172165635"><a name="p1362580172165635"></a><a name="p1362580172165635"></a>virtual void </p>
<p id="p236626481165635"><a name="p236626481165635"></a><a name="p236626481165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row50736064165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1025259366165635"><a name="p1025259366165635"></a><a name="p1025259366165635"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255913190165635"><a name="p1255913190165635"></a><a name="p1255913190165635"></a>virtual void </p>
<p id="p891675136165635"><a name="p891675136165635"></a><a name="p891675136165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row802720872165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2043136546165635"><a name="p2043136546165635"></a><a name="p2043136546165635"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1947904351165635"><a name="p1947904351165635"></a><a name="p1947904351165635"></a>void </p>
<p id="p1662551859165635"><a name="p1662551859165635"></a><a name="p1662551859165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1364137552165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880827019165635"><a name="p1880827019165635"></a><a name="p1880827019165635"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p646358628165635"><a name="p646358628165635"></a><a name="p646358628165635"></a>void </p>
<p id="p443439404165635"><a name="p443439404165635"></a><a name="p443439404165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1459905567165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p723715580165635"><a name="p723715580165635"></a><a name="p723715580165635"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p210929138165635"><a name="p210929138165635"></a><a name="p210929138165635"></a>virtual bool </p>
<p id="p694425449165635"><a name="p694425449165635"></a><a name="p694425449165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row474461278165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p530606612165635"><a name="p530606612165635"></a><a name="p530606612165635"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337546619165635"><a name="p1337546619165635"></a><a name="p1337546619165635"></a>virtual bool </p>
<p id="p2140556620165635"><a name="p2140556620165635"></a><a name="p2140556620165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1294335394165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736117961165635"><a name="p1736117961165635"></a><a name="p1736117961165635"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952921796165635"><a name="p1952921796165635"></a><a name="p1952921796165635"></a>virtual bool </p>
<p id="p1420173505165635"><a name="p1420173505165635"></a><a name="p1420173505165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1205961427165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1601504107165635"><a name="p1601504107165635"></a><a name="p1601504107165635"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771876688165635"><a name="p1771876688165635"></a><a name="p1771876688165635"></a>virtual bool </p>
<p id="p2110791897165635"><a name="p2110791897165635"></a><a name="p2110791897165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row163833310165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p132637899165635"><a name="p132637899165635"></a><a name="p132637899165635"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307906412165635"><a name="p1307906412165635"></a><a name="p1307906412165635"></a>virtual void </p>
<p id="p962910345165635"><a name="p962910345165635"></a><a name="p962910345165635"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1356935224165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2138665100165635"><a name="p2138665100165635"></a><a name="p2138665100165635"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144911514165635"><a name="p2144911514165635"></a><a name="p2144911514165635"></a>virtual void </p>
<p id="p999728708165635"><a name="p999728708165635"></a><a name="p999728708165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1960799282165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071200312165635"><a name="p1071200312165635"></a><a name="p1071200312165635"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p551882440165635"><a name="p551882440165635"></a><a name="p551882440165635"></a>virtual void </p>
<p id="p1722737503165635"><a name="p1722737503165635"></a><a name="p1722737503165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1035104285165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p465581073165635"><a name="p465581073165635"></a><a name="p465581073165635"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1671918427165635"><a name="p1671918427165635"></a><a name="p1671918427165635"></a>virtual void </p>
<p id="p800947379165635"><a name="p800947379165635"></a><a name="p800947379165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row465303766165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1099241367165635"><a name="p1099241367165635"></a><a name="p1099241367165635"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948410082165635"><a name="p1948410082165635"></a><a name="p1948410082165635"></a>void </p>
<p id="p1806875134165635"><a name="p1806875134165635"></a><a name="p1806875134165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1578285900165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1758803787165635"><a name="p1758803787165635"></a><a name="p1758803787165635"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264642413165635"><a name="p264642413165635"></a><a name="p264642413165635"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1094777139165635"><a name="p1094777139165635"></a><a name="p1094777139165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1822928415165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1595418392165635"><a name="p1595418392165635"></a><a name="p1595418392165635"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p387590344165635"><a name="p387590344165635"></a><a name="p387590344165635"></a>void </p>
<p id="p462643741165635"><a name="p462643741165635"></a><a name="p462643741165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1632144100165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040863488165635"><a name="p1040863488165635"></a><a name="p1040863488165635"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1106914607165635"><a name="p1106914607165635"></a><a name="p1106914607165635"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1249283485165635"><a name="p1249283485165635"></a><a name="p1249283485165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1150538658165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p365063869165635"><a name="p365063869165635"></a><a name="p365063869165635"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1654026404165635"><a name="p1654026404165635"></a><a name="p1654026404165635"></a>void </p>
<p id="p779100315165635"><a name="p779100315165635"></a><a name="p779100315165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1464984011165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770204104165635"><a name="p1770204104165635"></a><a name="p1770204104165635"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1214118683165635"><a name="p1214118683165635"></a><a name="p1214118683165635"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p2056476165165635"><a name="p2056476165165635"></a><a name="p2056476165165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1209107434165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1795281787165635"><a name="p1795281787165635"></a><a name="p1795281787165635"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1730615108165635"><a name="p1730615108165635"></a><a name="p1730615108165635"></a>void </p>
<p id="p2119091621165635"><a name="p2119091621165635"></a><a name="p2119091621165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row515452280165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528460841165635"><a name="p1528460841165635"></a><a name="p1528460841165635"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762435003165635"><a name="p762435003165635"></a><a name="p762435003165635"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p1201321769165635"><a name="p1201321769165635"></a><a name="p1201321769165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row437915146165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1252699001165635"><a name="p1252699001165635"></a><a name="p1252699001165635"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353926376165635"><a name="p1353926376165635"></a><a name="p1353926376165635"></a>void </p>
<p id="p303594092165635"><a name="p303594092165635"></a><a name="p303594092165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1704199671165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p913664951165635"><a name="p913664951165635"></a><a name="p913664951165635"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1607168439165635"><a name="p1607168439165635"></a><a name="p1607168439165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p208962002165635"><a name="p208962002165635"></a><a name="p208962002165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1173220532165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439466524165635"><a name="p1439466524165635"></a><a name="p1439466524165635"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572338541165635"><a name="p572338541165635"></a><a name="p572338541165635"></a>void </p>
<p id="p610345904165635"><a name="p610345904165635"></a><a name="p610345904165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1933191449165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045779019165635"><a name="p1045779019165635"></a><a name="p1045779019165635"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1728318468165635"><a name="p1728318468165635"></a><a name="p1728318468165635"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1402573422165635"><a name="p1402573422165635"></a><a name="p1402573422165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1155343663165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p427194853165635"><a name="p427194853165635"></a><a name="p427194853165635"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1741862125165635"><a name="p1741862125165635"></a><a name="p1741862125165635"></a>virtual void </p>
<p id="p1529353211165635"><a name="p1529353211165635"></a><a name="p1529353211165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row420533500165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1589787047165635"><a name="p1589787047165635"></a><a name="p1589787047165635"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653677868165635"><a name="p1653677868165635"></a><a name="p1653677868165635"></a>bool </p>
<p id="p1439857075165635"><a name="p1439857075165635"></a><a name="p1439857075165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row400946897165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p972506605165635"><a name="p972506605165635"></a><a name="p972506605165635"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p730095589165635"><a name="p730095589165635"></a><a name="p730095589165635"></a>void </p>
<p id="p314119019165635"><a name="p314119019165635"></a><a name="p314119019165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row2115756561165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1089909217165635"><a name="p1089909217165635"></a><a name="p1089909217165635"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p517867047165635"><a name="p517867047165635"></a><a name="p517867047165635"></a>bool </p>
<p id="p48986262165635"><a name="p48986262165635"></a><a name="p48986262165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1337914278165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p431925660165635"><a name="p431925660165635"></a><a name="p431925660165635"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p946395786165635"><a name="p946395786165635"></a><a name="p946395786165635"></a>void </p>
<p id="p1494119390165635"><a name="p1494119390165635"></a><a name="p1494119390165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row399114616165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p502810257165635"><a name="p502810257165635"></a><a name="p502810257165635"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852171110165635"><a name="p1852171110165635"></a><a name="p1852171110165635"></a>bool </p>
<p id="p981412302165635"><a name="p981412302165635"></a><a name="p981412302165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row2031013149165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1089460965165635"><a name="p1089460965165635"></a><a name="p1089460965165635"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572317944165635"><a name="p1572317944165635"></a><a name="p1572317944165635"></a>void </p>
<p id="p711348873165635"><a name="p711348873165635"></a><a name="p711348873165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row22431346165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624442764165635"><a name="p624442764165635"></a><a name="p624442764165635"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55337399165635"><a name="p55337399165635"></a><a name="p55337399165635"></a>bool </p>
<p id="p1296368152165635"><a name="p1296368152165635"></a><a name="p1296368152165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row140508493165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p914264917165635"><a name="p914264917165635"></a><a name="p914264917165635"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1125635344165635"><a name="p1125635344165635"></a><a name="p1125635344165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1413084786165635"><a name="p1413084786165635"></a><a name="p1413084786165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row313036195165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2029753678165635"><a name="p2029753678165635"></a><a name="p2029753678165635"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11331752165635"><a name="p11331752165635"></a><a name="p11331752165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1197649595165635"><a name="p1197649595165635"></a><a name="p1197649595165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1333492926165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514733408165635"><a name="p1514733408165635"></a><a name="p1514733408165635"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714140540165635"><a name="p714140540165635"></a><a name="p714140540165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1066725924165635"><a name="p1066725924165635"></a><a name="p1066725924165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1158108131165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584086702165635"><a name="p1584086702165635"></a><a name="p1584086702165635"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559568781165635"><a name="p1559568781165635"></a><a name="p1559568781165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1304557126165635"><a name="p1304557126165635"></a><a name="p1304557126165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1349377702165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1078933878165635"><a name="p1078933878165635"></a><a name="p1078933878165635"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1461199009165635"><a name="p1461199009165635"></a><a name="p1461199009165635"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1565521350165635"><a name="p1565521350165635"></a><a name="p1565521350165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row888493862165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139169838165635"><a name="p2139169838165635"></a><a name="p2139169838165635"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p955458072165635"><a name="p955458072165635"></a><a name="p955458072165635"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1563847237165635"><a name="p1563847237165635"></a><a name="p1563847237165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row159628864165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p939735787165635"><a name="p939735787165635"></a><a name="p939735787165635"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p240996134165635"><a name="p240996134165635"></a><a name="p240996134165635"></a>void </p>
<p id="p649976028165635"><a name="p649976028165635"></a><a name="p649976028165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row904234925165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410628122165635"><a name="p1410628122165635"></a><a name="p1410628122165635"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182840953165635"><a name="p182840953165635"></a><a name="p182840953165635"></a>virtual void </p>
<p id="p660555345165635"><a name="p660555345165635"></a><a name="p660555345165635"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row957712499165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1328884155165635"><a name="p1328884155165635"></a><a name="p1328884155165635"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356740830165635"><a name="p1356740830165635"></a><a name="p1356740830165635"></a>virtual int16_t </p>
<p id="p693824454165635"><a name="p693824454165635"></a><a name="p693824454165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row325941139165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278479164165635"><a name="p278479164165635"></a><a name="p278479164165635"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992922547165635"><a name="p1992922547165635"></a><a name="p1992922547165635"></a>virtual void </p>
<p id="p1879185929165635"><a name="p1879185929165635"></a><a name="p1879185929165635"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1472959502165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2112409565165635"><a name="p2112409565165635"></a><a name="p2112409565165635"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p47423669165635"><a name="p47423669165635"></a><a name="p47423669165635"></a>virtual int16_t </p>
<p id="p1837369345165635"><a name="p1837369345165635"></a><a name="p1837369345165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row107975728165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1256133337165635"><a name="p1256133337165635"></a><a name="p1256133337165635"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p110016379165635"><a name="p110016379165635"></a><a name="p110016379165635"></a>virtual void </p>
<p id="p113787658165635"><a name="p113787658165635"></a><a name="p113787658165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1497334395165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p781251959165635"><a name="p781251959165635"></a><a name="p781251959165635"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653361920165635"><a name="p1653361920165635"></a><a name="p1653361920165635"></a>virtual void </p>
<p id="p423447660165635"><a name="p423447660165635"></a><a name="p423447660165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1504490460165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663370885165635"><a name="p1663370885165635"></a><a name="p1663370885165635"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828446594165635"><a name="p1828446594165635"></a><a name="p1828446594165635"></a>int16_t </p>
<p id="p1412170239165635"><a name="p1412170239165635"></a><a name="p1412170239165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row949743027165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607693635165635"><a name="p607693635165635"></a><a name="p607693635165635"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494388776165635"><a name="p1494388776165635"></a><a name="p1494388776165635"></a>virtual void </p>
<p id="p1154700572165635"><a name="p1154700572165635"></a><a name="p1154700572165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1691351227165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495135398165635"><a name="p495135398165635"></a><a name="p495135398165635"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083090789165635"><a name="p1083090789165635"></a><a name="p1083090789165635"></a>int16_t </p>
<p id="p1064101687165635"><a name="p1064101687165635"></a><a name="p1064101687165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1730814121165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909490365165635"><a name="p909490365165635"></a><a name="p909490365165635"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868974835165635"><a name="p1868974835165635"></a><a name="p1868974835165635"></a>virtual void </p>
<p id="p528633256165635"><a name="p528633256165635"></a><a name="p528633256165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1434775273165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1227672438165635"><a name="p1227672438165635"></a><a name="p1227672438165635"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p994035770165635"><a name="p994035770165635"></a><a name="p994035770165635"></a>virtual void </p>
<p id="p52980130165635"><a name="p52980130165635"></a><a name="p52980130165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1002079807165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839485540165635"><a name="p1839485540165635"></a><a name="p1839485540165635"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1385666703165635"><a name="p1385666703165635"></a><a name="p1385666703165635"></a>bool </p>
<p id="p111089710165635"><a name="p111089710165635"></a><a name="p111089710165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row812031712165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p174962918165635"><a name="p174962918165635"></a><a name="p174962918165635"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1705794820165635"><a name="p1705794820165635"></a><a name="p1705794820165635"></a>void </p>
<p id="p1500391863165635"><a name="p1500391863165635"></a><a name="p1500391863165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1405259436165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641966607165635"><a name="p641966607165635"></a><a name="p641966607165635"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175536064165635"><a name="p1175536064165635"></a><a name="p1175536064165635"></a>void </p>
<p id="p1169457011165635"><a name="p1169457011165635"></a><a name="p1169457011165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1490392713165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1968815708165635"><a name="p1968815708165635"></a><a name="p1968815708165635"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p278655111165635"><a name="p278655111165635"></a><a name="p278655111165635"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p685175816165635"><a name="p685175816165635"></a><a name="p685175816165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1627644821165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1185640547165635"><a name="p1185640547165635"></a><a name="p1185640547165635"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1187340019165635"><a name="p1187340019165635"></a><a name="p1187340019165635"></a>void </p>
<p id="p37167166165635"><a name="p37167166165635"></a><a name="p37167166165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1858412272165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1298598416165635"><a name="p1298598416165635"></a><a name="p1298598416165635"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p988233949165635"><a name="p988233949165635"></a><a name="p988233949165635"></a>const char * </p>
<p id="p1326718708165635"><a name="p1326718708165635"></a><a name="p1326718708165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row27590771165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714234982165635"><a name="p1714234982165635"></a><a name="p1714234982165635"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909697154165635"><a name="p909697154165635"></a><a name="p909697154165635"></a>void </p>
<p id="p730226992165635"><a name="p730226992165635"></a><a name="p730226992165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row656226247165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p171830040165635"><a name="p171830040165635"></a><a name="p171830040165635"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419683853165635"><a name="p1419683853165635"></a><a name="p1419683853165635"></a>int16_t </p>
<p id="p353732882165635"><a name="p353732882165635"></a><a name="p353732882165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1405343039165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916438366165635"><a name="p916438366165635"></a><a name="p916438366165635"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p79556911165635"><a name="p79556911165635"></a><a name="p79556911165635"></a>virtual void </p>
<p id="p548202250165635"><a name="p548202250165635"></a><a name="p548202250165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1384366202165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p739117948165635"><a name="p739117948165635"></a><a name="p739117948165635"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1820662845165635"><a name="p1820662845165635"></a><a name="p1820662845165635"></a>void </p>
<p id="p2062618821165635"><a name="p2062618821165635"></a><a name="p2062618821165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row428700946165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838268701165635"><a name="p1838268701165635"></a><a name="p1838268701165635"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111224461165635"><a name="p1111224461165635"></a><a name="p1111224461165635"></a>void </p>
<p id="p1121828206165635"><a name="p1121828206165635"></a><a name="p1121828206165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row304954740165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610404748165635"><a name="p610404748165635"></a><a name="p610404748165635"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702522838165635"><a name="p702522838165635"></a><a name="p702522838165635"></a>void </p>
<p id="p1437581448165635"><a name="p1437581448165635"></a><a name="p1437581448165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1810807878165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008710356165635"><a name="p1008710356165635"></a><a name="p1008710356165635"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630509985165635"><a name="p1630509985165635"></a><a name="p1630509985165635"></a>void </p>
<p id="p1743608537165635"><a name="p1743608537165635"></a><a name="p1743608537165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row2133509252165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203565468165635"><a name="p1203565468165635"></a><a name="p1203565468165635"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487595238165635"><a name="p1487595238165635"></a><a name="p1487595238165635"></a>void </p>
<p id="p860191051165635"><a name="p860191051165635"></a><a name="p860191051165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row564957658165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1632714527165635"><a name="p1632714527165635"></a><a name="p1632714527165635"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p302641527165635"><a name="p302641527165635"></a><a name="p302641527165635"></a>void </p>
<p id="p362695360165635"><a name="p362695360165635"></a><a name="p362695360165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row429364751165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p875610685165635"><a name="p875610685165635"></a><a name="p875610685165635"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p670736446165635"><a name="p670736446165635"></a><a name="p670736446165635"></a>void </p>
<p id="p263768185165635"><a name="p263768185165635"></a><a name="p263768185165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1740170600165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1693835762165635"><a name="p1693835762165635"></a><a name="p1693835762165635"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p218697727165635"><a name="p218697727165635"></a><a name="p218697727165635"></a>void </p>
<p id="p1174154891165635"><a name="p1174154891165635"></a><a name="p1174154891165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1040704094165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563323414165635"><a name="p563323414165635"></a><a name="p563323414165635"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914080210165635"><a name="p914080210165635"></a><a name="p914080210165635"></a>void </p>
<p id="p1581676502165635"><a name="p1581676502165635"></a><a name="p1581676502165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row848089096165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1268587354165635"><a name="p1268587354165635"></a><a name="p1268587354165635"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715471718165635"><a name="p715471718165635"></a><a name="p715471718165635"></a>void </p>
<p id="p307996306165635"><a name="p307996306165635"></a><a name="p307996306165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row437631829165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1493132332165635"><a name="p1493132332165635"></a><a name="p1493132332165635"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2057234744165635"><a name="p2057234744165635"></a><a name="p2057234744165635"></a>void </p>
<p id="p1145076425165635"><a name="p1145076425165635"></a><a name="p1145076425165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1281810321165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423396236165635"><a name="p423396236165635"></a><a name="p423396236165635"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1599110016165635"><a name="p1599110016165635"></a><a name="p1599110016165635"></a>void </p>
<p id="p390522045165635"><a name="p390522045165635"></a><a name="p390522045165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row987096221165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313247668165635"><a name="p1313247668165635"></a><a name="p1313247668165635"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p687008023165635"><a name="p687008023165635"></a><a name="p687008023165635"></a>void </p>
<p id="p1001002655165635"><a name="p1001002655165635"></a><a name="p1001002655165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1451511446165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p166466800165635"><a name="p166466800165635"></a><a name="p166466800165635"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1201068993165635"><a name="p1201068993165635"></a><a name="p1201068993165635"></a>void </p>
<p id="p2147006630165635"><a name="p2147006630165635"></a><a name="p2147006630165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row125771794165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p280761940165635"><a name="p280761940165635"></a><a name="p280761940165635"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093016213165635"><a name="p1093016213165635"></a><a name="p1093016213165635"></a>void </p>
<p id="p1548235632165635"><a name="p1548235632165635"></a><a name="p1548235632165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row774875861165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072336229165635"><a name="p1072336229165635"></a><a name="p1072336229165635"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1782258128165635"><a name="p1782258128165635"></a><a name="p1782258128165635"></a>void </p>
<p id="p176162812165635"><a name="p176162812165635"></a><a name="p176162812165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row420370545165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1475532351165635"><a name="p1475532351165635"></a><a name="p1475532351165635"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454622195165635"><a name="p1454622195165635"></a><a name="p1454622195165635"></a>virtual void </p>
<p id="p1671512452165635"><a name="p1671512452165635"></a><a name="p1671512452165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1066099412165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p874775036165635"><a name="p874775036165635"></a><a name="p874775036165635"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133823913165635"><a name="p1133823913165635"></a><a name="p1133823913165635"></a>virtual int64_t </p>
<p id="p1832181436165635"><a name="p1832181436165635"></a><a name="p1832181436165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row873227385165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734906059165635"><a name="p1734906059165635"></a><a name="p1734906059165635"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204509232165635"><a name="p204509232165635"></a><a name="p204509232165635"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p337201635165635"><a name="p337201635165635"></a><a name="p337201635165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1781261026165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167006580165635"><a name="p1167006580165635"></a><a name="p1167006580165635"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90659209165635"><a name="p90659209165635"></a><a name="p90659209165635"></a>void * </p>
<p id="p1814257081165635"><a name="p1814257081165635"></a><a name="p1814257081165635"></a>Overrides the <strong id="b1953070085165635"><a name="b1953070085165635"></a><a name="b1953070085165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row616492178165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676898597165635"><a name="p1676898597165635"></a><a name="p1676898597165635"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p616919483165635"><a name="p616919483165635"></a><a name="p616919483165635"></a>void </p>
<p id="p1063540588165635"><a name="p1063540588165635"></a><a name="p1063540588165635"></a>Overrides the <strong id="b642235296165635"><a name="b642235296165635"></a><a name="b642235296165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1624734123165635"></a>
<table><thead align="left"><tr id="row185515588165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p364088960165635"><a name="p364088960165635"></a><a name="p364088960165635"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1237870615165635"><a name="p1237870615165635"></a><a name="p1237870615165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row760682003165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449369740165635"><a name="p1449369740165635"></a><a name="p1449369740165635"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p596622532165635"><a name="p596622532165635"></a><a name="p596622532165635"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row924554581165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489428221165635"><a name="p489428221165635"></a><a name="p489428221165635"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501801117165635"><a name="p501801117165635"></a><a name="p501801117165635"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1301536761165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1283477924165635"><a name="p1283477924165635"></a><a name="p1283477924165635"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261035523165635"><a name="p1261035523165635"></a><a name="p1261035523165635"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1670650218165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912330645165635"><a name="p912330645165635"></a><a name="p912330645165635"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1506773775165635"><a name="p1506773775165635"></a><a name="p1506773775165635"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row2058451405165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502061084165635"><a name="p1502061084165635"></a><a name="p1502061084165635"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p142758284165635"><a name="p142758284165635"></a><a name="p142758284165635"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row179776355165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895357024165635"><a name="p1895357024165635"></a><a name="p1895357024165635"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p594645791165635"><a name="p594645791165635"></a><a name="p594645791165635"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1857176815165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929957088165635"><a name="p929957088165635"></a><a name="p929957088165635"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610888051165635"><a name="p1610888051165635"></a><a name="p1610888051165635"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1368719847165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1692805142165635"><a name="p1692805142165635"></a><a name="p1692805142165635"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1845624015165635"><a name="p1845624015165635"></a><a name="p1845624015165635"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

