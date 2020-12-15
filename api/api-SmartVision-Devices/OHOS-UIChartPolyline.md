# OHOS::UIChartPolyline<a name="ZH-CN_TOPIC_0000001054799623"></a>

-   [Overview](#section1273317788165634)
-   [Summary](#section570836943165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1273317788165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Provides special functions for implementing a polyline. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section570836943165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table555413537165634"></a>
<table><thead align="left"><tr id="row1674498000165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p586657770165634"><a name="p586657770165634"></a><a name="p586657770165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p163781171165634"><a name="p163781171165634"></a><a name="p163781171165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row752642437165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p148820886165634"><a name="p148820886165634"></a><a name="p148820886165634"></a><a href="Graphic.md#gaf32e6833f395ca6ac8620277531d5ea7">UIChartPolyline</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1945229013165634"><a name="p1945229013165634"></a><a name="p1945229013165634"></a> </p>
<p id="p1883284835165634"><a name="p1883284835165634"></a><a name="p1883284835165634"></a>A constructor used to create a <strong id="b1409308547165634"><a name="b1409308547165634"></a><a name="b1409308547165634"></a><a href="OHOS-UIChartPolyline.md">UIChartPolyline</a></strong> instance. </p>
</td>
</tr>
<tr id="row1085568963165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1124475092165634"><a name="p1124475092165634"></a><a name="p1124475092165634"></a><a href="Graphic.md#ga620a90ab246ec8c5c55aed8985329cb9">~UIChartPolyline</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p12267167165634"><a name="p12267167165634"></a><a name="p12267167165634"></a>virtual </p>
<p id="p1885680168165634"><a name="p1885680168165634"></a><a name="p1885680168165634"></a>A destructor used to delete the <strong id="b1429923801165634"><a name="b1429923801165634"></a><a name="b1429923801165634"></a><a href="OHOS-UIChartPolyline.md">UIChartPolyline</a></strong> instance. </p>
</td>
</tr>
<tr id="row1523566442165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1871652828165634"><a name="p1871652828165634"></a><a name="p1871652828165634"></a><a href="Graphic.md#ga53594e65076b8588bcc48d4c69fbe8fd">RefreshChart</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1444534209165634"><a name="p1444534209165634"></a><a name="p1444534209165634"></a>void </p>
<p id="p910838739165634"><a name="p910838739165634"></a><a name="p910838739165634"></a>Refreshes a line chart and redraws the dirty region. </p>
</td>
</tr>
<tr id="row1411516492165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811737008165634"><a name="p1811737008165634"></a><a name="p1811737008165634"></a><a href="Graphic.md#gacf4303bade3933dcac90459fa38d6e1f">SetGradientOpacity</a> (uint8_t minOpa, uint8_t maxOpa)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614338982165634"><a name="p1614338982165634"></a><a name="p1614338982165634"></a>void </p>
<p id="p1208714706165634"><a name="p1208714706165634"></a><a name="p1208714706165634"></a>Sets the opacity range of the fill color gradient. </p>
</td>
</tr>
<tr id="row1257830604165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1915922522165634"><a name="p1915922522165634"></a><a name="p1915922522165634"></a><a href="Graphic.md#gafdab5b0f7f8563d475c5aba2aeb1e828">SetGradientBottom</a> (uint16_t bottom)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73196053165634"><a name="p73196053165634"></a><a name="p73196053165634"></a>void </p>
<p id="p545687568165634"><a name="p545687568165634"></a><a name="p545687568165634"></a>Sets the distance between the bottom edge of the fill color range and the x-axis. </p>
</td>
</tr>
<tr id="row2111643906165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184887553165634"><a name="p1184887553165634"></a><a name="p1184887553165634"></a><a href="Graphic.md#ga3ab02ed367123e4f84e5ab145f5ed949">UIChart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583134456165634"><a name="p583134456165634"></a><a name="p583134456165634"></a> </p>
<p id="p2131628316165634"><a name="p2131628316165634"></a><a name="p2131628316165634"></a>A constructor used to create a <strong id="b658349866165634"><a name="b658349866165634"></a><a name="b658349866165634"></a><a href="OHOS-UIChart.md">UIChart</a></strong> instance. </p>
</td>
</tr>
<tr id="row655346518165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671699320165634"><a name="p1671699320165634"></a><a name="p1671699320165634"></a><a href="Graphic.md#gab5d79c4736d822116dcdd7ed6e45294e">~UIChart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096947674165634"><a name="p1096947674165634"></a><a name="p1096947674165634"></a>virtual </p>
<p id="p1244893290165634"><a name="p1244893290165634"></a><a name="p1244893290165634"></a>A destructor used to delete the <strong id="b1046878296165634"><a name="b1046878296165634"></a><a name="b1046878296165634"></a><a href="OHOS-UIChart.md">UIChart</a></strong> instance. </p>
</td>
</tr>
<tr id="row744788115165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235292490165634"><a name="p1235292490165634"></a><a name="p1235292490165634"></a><a href="Graphic.md#gaea65298b6e4a71a2de65c13e1b14ed7b">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p490095495165634"><a name="p490095495165634"></a><a name="p490095495165634"></a>UIViewType </p>
<p id="p1097904595165634"><a name="p1097904595165634"></a><a name="p1097904595165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row840971579165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p503813619165634"><a name="p503813619165634"></a><a name="p503813619165634"></a><a href="Graphic.md#ga54b3c4122ebaeefe74587ca69aa98600">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1578989558165634"><a name="p1578989558165634"></a><a name="p1578989558165634"></a>void </p>
<p id="p1413230452165634"><a name="p1413230452165634"></a><a name="p1413230452165634"></a>Sets the height for this component. </p>
</td>
</tr>
<tr id="row736252786165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385164142165634"><a name="p385164142165634"></a><a name="p385164142165634"></a><a href="Graphic.md#ga2ae317808111cd58e6ba93e030f23111">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202097225165634"><a name="p1202097225165634"></a><a name="p1202097225165634"></a>void </p>
<p id="p2115663244165634"><a name="p2115663244165634"></a><a name="p2115663244165634"></a>Sets the width for this component. </p>
</td>
</tr>
<tr id="row1189037836165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1550566795165634"><a name="p1550566795165634"></a><a name="p1550566795165634"></a><a href="Graphic.md#ga9a8287a522f00bb3dbe60af8f242054a">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1711418064165634"><a name="p1711418064165634"></a><a name="p1711418064165634"></a>bool </p>
<p id="p941177071165634"><a name="p941177071165634"></a><a name="p941177071165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1634936703165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p331990182165634"><a name="p331990182165634"></a><a name="p331990182165634"></a><a href="Graphic.md#ga5c101948cb2cfb8394af0bcb56f65efb">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507525437165634"><a name="p507525437165634"></a><a name="p507525437165634"></a>void </p>
<p id="p1804215120165634"><a name="p1804215120165634"></a><a name="p1804215120165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row883496920165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36354024165634"><a name="p36354024165634"></a><a name="p36354024165634"></a><a href="Graphic.md#gafc510047aac4e7eebd5b229e726ef762">AddDataSerial</a> (<a href="OHOS-UIChartDataSerial.md">UIChartDataSerial</a> *dataSerial)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p579102819165634"><a name="p579102819165634"></a><a name="p579102819165634"></a>virtual bool </p>
<p id="p848667637165634"><a name="p848667637165634"></a><a name="p848667637165634"></a>Adds a data set. </p>
</td>
</tr>
<tr id="row770608240165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725388969165634"><a name="p725388969165634"></a><a name="p725388969165634"></a><a href="Graphic.md#ga2af81fbcd6a17ef250bf07e2d7606b8d">DeleteDataSerial</a> (<a href="OHOS-UIChartDataSerial.md">UIChartDataSerial</a> *dataSerial)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p709262234165634"><a name="p709262234165634"></a><a name="p709262234165634"></a>virtual bool </p>
<p id="p967469418165634"><a name="p967469418165634"></a><a name="p967469418165634"></a>Deletes a data set. </p>
</td>
</tr>
<tr id="row2013264906165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1249630165634"><a name="p1249630165634"></a><a name="p1249630165634"></a><a href="Graphic.md#gae2752857fbcb9f1541cd811321bfc2c6">ClearDataSerial</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1020933419165634"><a name="p1020933419165634"></a><a name="p1020933419165634"></a>virtual void </p>
<p id="p606334272165634"><a name="p606334272165634"></a><a name="p606334272165634"></a>Clears all data sets. </p>
</td>
</tr>
<tr id="row2142420881165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2096951979165634"><a name="p2096951979165634"></a><a name="p2096951979165634"></a><a href="Graphic.md#ga010c178e2c1dec79e4af10cbf4545257">GetXAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465459402165634"><a name="p465459402165634"></a><a name="p465459402165634"></a><a href="OHOS-UIXAxis.md">UIXAxis</a> &amp; </p>
<p id="p683314342165634"><a name="p683314342165634"></a><a name="p683314342165634"></a>Obtains the x-axis instance. </p>
</td>
</tr>
<tr id="row1254379975165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16486721165634"><a name="p16486721165634"></a><a name="p16486721165634"></a><a href="Graphic.md#ga696227300be45585be102f6a7f66b7b1">GetYAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1851988146165634"><a name="p1851988146165634"></a><a name="p1851988146165634"></a><a href="OHOS-UIYAxis.md">UIYAxis</a> &amp; </p>
<p id="p1771765239165634"><a name="p1771765239165634"></a><a name="p1771765239165634"></a>Obtains the y-axis instance. </p>
</td>
</tr>
<tr id="row516679308165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76898147165634"><a name="p76898147165634"></a><a name="p76898147165634"></a><a href="Graphic.md#ga7c99edd3adfb60796be92e98fd71a705">EnableReverse</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155236299165634"><a name="p155236299165634"></a><a name="p155236299165634"></a>void </p>
<p id="p1565549305165634"><a name="p1565549305165634"></a><a name="p1565549305165634"></a>Enables chart reverse. </p>
</td>
</tr>
<tr id="row1881190265165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628641709165634"><a name="p628641709165634"></a><a name="p628641709165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216130332165634"><a name="p216130332165634"></a><a name="p216130332165634"></a> </p>
<p id="p663296947165634"><a name="p663296947165634"></a><a name="p663296947165634"></a>A default constructor used to create a <strong id="b1506346501165634"><a name="b1506346501165634"></a><a name="b1506346501165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row721874066165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p447064204165634"><a name="p447064204165634"></a><a name="p447064204165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1510162908165634"><a name="p1510162908165634"></a><a name="p1510162908165634"></a>virtual </p>
<p id="p631905223165634"><a name="p631905223165634"></a><a name="p631905223165634"></a>A destructor used to delete the <strong id="b471542415165634"><a name="b471542415165634"></a><a name="b471542415165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1942862386165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212294442165634"><a name="p212294442165634"></a><a name="p212294442165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653127661165634"><a name="p653127661165634"></a><a name="p653127661165634"></a>UIViewType </p>
<p id="p2112710597165634"><a name="p2112710597165634"></a><a name="p2112710597165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row33749033165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2015096512165634"><a name="p2015096512165634"></a><a name="p2015096512165634"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p100707359165634"><a name="p100707359165634"></a><a name="p100707359165634"></a>virtual void </p>
<p id="p616453732165634"><a name="p616453732165634"></a><a name="p616453732165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1096076949165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369319944165634"><a name="p369319944165634"></a><a name="p369319944165634"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2019717468165634"><a name="p2019717468165634"></a><a name="p2019717468165634"></a>virtual void </p>
<p id="p329292213165634"><a name="p329292213165634"></a><a name="p329292213165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row48109603165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735542931165634"><a name="p735542931165634"></a><a name="p735542931165634"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182162854165634"><a name="p182162854165634"></a><a name="p182162854165634"></a>virtual void </p>
<p id="p2004934011165634"><a name="p2004934011165634"></a><a name="p2004934011165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1153033241165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1517836256165634"><a name="p1517836256165634"></a><a name="p1517836256165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769901183165634"><a name="p769901183165634"></a><a name="p769901183165634"></a>virtual void </p>
<p id="p1860167373165634"><a name="p1860167373165634"></a><a name="p1860167373165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1628145953165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2009216626165634"><a name="p2009216626165634"></a><a name="p2009216626165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413972703165634"><a name="p1413972703165634"></a><a name="p1413972703165634"></a>virtual void </p>
<p id="p722518251165634"><a name="p722518251165634"></a><a name="p722518251165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1434447331165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865681356165634"><a name="p1865681356165634"></a><a name="p1865681356165634"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618003030165634"><a name="p1618003030165634"></a><a name="p1618003030165634"></a>virtual void </p>
<p id="p771996160165634"><a name="p771996160165634"></a><a name="p771996160165634"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1270749645165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1481726396165634"><a name="p1481726396165634"></a><a name="p1481726396165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565324308165634"><a name="p565324308165634"></a><a name="p565324308165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1604556840165634"><a name="p1604556840165634"></a><a name="p1604556840165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row671721197165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p198387431165634"><a name="p198387431165634"></a><a name="p198387431165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1127495121165634"><a name="p1127495121165634"></a><a name="p1127495121165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p840136869165634"><a name="p840136869165634"></a><a name="p840136869165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1974621230165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443029795165634"><a name="p1443029795165634"></a><a name="p1443029795165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p598768777165634"><a name="p598768777165634"></a><a name="p598768777165634"></a>void </p>
<p id="p1939299139165634"><a name="p1939299139165634"></a><a name="p1939299139165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row515078820165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827553560165634"><a name="p1827553560165634"></a><a name="p1827553560165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732039466165634"><a name="p1732039466165634"></a><a name="p1732039466165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1179492427165634"><a name="p1179492427165634"></a><a name="p1179492427165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row716503405165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172138693165634"><a name="p172138693165634"></a><a name="p172138693165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1633880386165634"><a name="p1633880386165634"></a><a name="p1633880386165634"></a>void </p>
<p id="p494807548165634"><a name="p494807548165634"></a><a name="p494807548165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row506703579165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p332263292165634"><a name="p332263292165634"></a><a name="p332263292165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864384627165634"><a name="p864384627165634"></a><a name="p864384627165634"></a> </p>
<p id="p406902020165634"><a name="p406902020165634"></a><a name="p406902020165634"></a>A default constructor used to create an <strong id="b1802738883165634"><a name="b1802738883165634"></a><a name="b1802738883165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1327746746165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638653892165634"><a name="p1638653892165634"></a><a name="p1638653892165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p699494845165634"><a name="p699494845165634"></a><a name="p699494845165634"></a> </p>
<p id="p2137765866165634"><a name="p2137765866165634"></a><a name="p2137765866165634"></a>A constructor used to create an <strong id="b69647329165634"><a name="b69647329165634"></a><a name="b69647329165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row886059422165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669820166165634"><a name="p669820166165634"></a><a name="p669820166165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1173652366165634"><a name="p1173652366165634"></a><a name="p1173652366165634"></a>virtual </p>
<p id="p1886064944165634"><a name="p1886064944165634"></a><a name="p1886064944165634"></a>A destructor used to delete the <strong id="b125470903165634"><a name="b125470903165634"></a><a name="b125470903165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row909727043165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302472811165634"><a name="p1302472811165634"></a><a name="p1302472811165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169333004165634"><a name="p169333004165634"></a><a name="p169333004165634"></a>virtual void </p>
<p id="p227402677165634"><a name="p227402677165634"></a><a name="p227402677165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1625005514165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p81503471165634"><a name="p81503471165634"></a><a name="p81503471165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1662727708165634"><a name="p1662727708165634"></a><a name="p1662727708165634"></a>void </p>
<p id="p423004667165634"><a name="p423004667165634"></a><a name="p423004667165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row611135627165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p39634751165634"><a name="p39634751165634"></a><a name="p39634751165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1349227105165634"><a name="p1349227105165634"></a><a name="p1349227105165634"></a>void </p>
<p id="p1861280438165634"><a name="p1861280438165634"></a><a name="p1861280438165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1101207788165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191713220165634"><a name="p191713220165634"></a><a name="p191713220165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734170290165634"><a name="p1734170290165634"></a><a name="p1734170290165634"></a>virtual bool </p>
<p id="p896121538165634"><a name="p896121538165634"></a><a name="p896121538165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1895945166165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p404698902165634"><a name="p404698902165634"></a><a name="p404698902165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465930825165634"><a name="p465930825165634"></a><a name="p465930825165634"></a>virtual bool </p>
<p id="p1657820440165634"><a name="p1657820440165634"></a><a name="p1657820440165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1604420946165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719827310165634"><a name="p1719827310165634"></a><a name="p1719827310165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p817039679165634"><a name="p817039679165634"></a><a name="p817039679165634"></a>virtual bool </p>
<p id="p1461667262165634"><a name="p1461667262165634"></a><a name="p1461667262165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row42956534165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p646563995165634"><a name="p646563995165634"></a><a name="p646563995165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695117742165634"><a name="p1695117742165634"></a><a name="p1695117742165634"></a>virtual bool </p>
<p id="p1001406133165634"><a name="p1001406133165634"></a><a name="p1001406133165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row931211087165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780212283165634"><a name="p1780212283165634"></a><a name="p1780212283165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826444201165634"><a name="p1826444201165634"></a><a name="p1826444201165634"></a>virtual void </p>
<p id="p86678165165634"><a name="p86678165165634"></a><a name="p86678165165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row655128989165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071515041165634"><a name="p1071515041165634"></a><a name="p1071515041165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p960206075165634"><a name="p960206075165634"></a><a name="p960206075165634"></a>virtual void </p>
<p id="p682734599165634"><a name="p682734599165634"></a><a name="p682734599165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row641358914165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p977430143165634"><a name="p977430143165634"></a><a name="p977430143165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421556039165634"><a name="p1421556039165634"></a><a name="p1421556039165634"></a>virtual void </p>
<p id="p1217456489165634"><a name="p1217456489165634"></a><a name="p1217456489165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1155218212165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p290375451165634"><a name="p290375451165634"></a><a name="p290375451165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644399531165634"><a name="p644399531165634"></a><a name="p644399531165634"></a>virtual void </p>
<p id="p165570603165634"><a name="p165570603165634"></a><a name="p165570603165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1804693622165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1823662432165634"><a name="p1823662432165634"></a><a name="p1823662432165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1811686921165634"><a name="p1811686921165634"></a><a name="p1811686921165634"></a>void </p>
<p id="p1142546114165634"><a name="p1142546114165634"></a><a name="p1142546114165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1426819674165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186155085165634"><a name="p186155085165634"></a><a name="p186155085165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145532611165634"><a name="p1145532611165634"></a><a name="p1145532611165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p2118743427165634"><a name="p2118743427165634"></a><a name="p2118743427165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1951297364165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971634457165634"><a name="p1971634457165634"></a><a name="p1971634457165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p658425127165634"><a name="p658425127165634"></a><a name="p658425127165634"></a>void </p>
<p id="p1940376587165634"><a name="p1940376587165634"></a><a name="p1940376587165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1132754423165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p524591054165634"><a name="p524591054165634"></a><a name="p524591054165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p600972380165634"><a name="p600972380165634"></a><a name="p600972380165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1542251768165634"><a name="p1542251768165634"></a><a name="p1542251768165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1984939335165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1917320292165634"><a name="p1917320292165634"></a><a name="p1917320292165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225455467165634"><a name="p1225455467165634"></a><a name="p1225455467165634"></a>void </p>
<p id="p1906863496165634"><a name="p1906863496165634"></a><a name="p1906863496165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1351115820165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657368734165634"><a name="p1657368734165634"></a><a name="p1657368734165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6191907165634"><a name="p6191907165634"></a><a name="p6191907165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p573924114165634"><a name="p573924114165634"></a><a name="p573924114165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1996455474165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243937430165634"><a name="p1243937430165634"></a><a name="p1243937430165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2012026177165634"><a name="p2012026177165634"></a><a name="p2012026177165634"></a>void </p>
<p id="p1822444424165634"><a name="p1822444424165634"></a><a name="p1822444424165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1917520413165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1527758937165634"><a name="p1527758937165634"></a><a name="p1527758937165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959584463165634"><a name="p1959584463165634"></a><a name="p1959584463165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p345654372165634"><a name="p345654372165634"></a><a name="p345654372165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1295474134165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p217029069165634"><a name="p217029069165634"></a><a name="p217029069165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1647343385165634"><a name="p1647343385165634"></a><a name="p1647343385165634"></a>void </p>
<p id="p1219306829165634"><a name="p1219306829165634"></a><a name="p1219306829165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1496875086165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p970746367165634"><a name="p970746367165634"></a><a name="p970746367165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1928251093165634"><a name="p1928251093165634"></a><a name="p1928251093165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p863273714165634"><a name="p863273714165634"></a><a name="p863273714165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row446383654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066011873165634"><a name="p2066011873165634"></a><a name="p2066011873165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p935137528165634"><a name="p935137528165634"></a><a name="p935137528165634"></a>void </p>
<p id="p118912880165634"><a name="p118912880165634"></a><a name="p118912880165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1435564834165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1767628624165634"><a name="p1767628624165634"></a><a name="p1767628624165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491228947165634"><a name="p1491228947165634"></a><a name="p1491228947165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p576984938165634"><a name="p576984938165634"></a><a name="p576984938165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row681362665165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1694985509165634"><a name="p1694985509165634"></a><a name="p1694985509165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p324067214165634"><a name="p324067214165634"></a><a name="p324067214165634"></a>virtual void </p>
<p id="p214454092165634"><a name="p214454092165634"></a><a name="p214454092165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1161603316165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1023145538165634"><a name="p1023145538165634"></a><a name="p1023145538165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629915329165634"><a name="p1629915329165634"></a><a name="p1629915329165634"></a>bool </p>
<p id="p114160546165634"><a name="p114160546165634"></a><a name="p114160546165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1394298776165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p824739981165634"><a name="p824739981165634"></a><a name="p824739981165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1092638389165634"><a name="p1092638389165634"></a><a name="p1092638389165634"></a>void </p>
<p id="p653436696165634"><a name="p653436696165634"></a><a name="p653436696165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1797378147165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p971907358165634"><a name="p971907358165634"></a><a name="p971907358165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1981084313165634"><a name="p1981084313165634"></a><a name="p1981084313165634"></a>bool </p>
<p id="p62505879165634"><a name="p62505879165634"></a><a name="p62505879165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row29032626165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114864605165634"><a name="p1114864605165634"></a><a name="p1114864605165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p873673529165634"><a name="p873673529165634"></a><a name="p873673529165634"></a>void </p>
<p id="p445105146165634"><a name="p445105146165634"></a><a name="p445105146165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row549771685165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2015116435165634"><a name="p2015116435165634"></a><a name="p2015116435165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231955091165634"><a name="p1231955091165634"></a><a name="p1231955091165634"></a>bool </p>
<p id="p1626218518165634"><a name="p1626218518165634"></a><a name="p1626218518165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row2086377307165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388763477165634"><a name="p1388763477165634"></a><a name="p1388763477165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p811886514165634"><a name="p811886514165634"></a><a name="p811886514165634"></a>void </p>
<p id="p1825732749165634"><a name="p1825732749165634"></a><a name="p1825732749165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row236070149165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p599566168165634"><a name="p599566168165634"></a><a name="p599566168165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2136908490165634"><a name="p2136908490165634"></a><a name="p2136908490165634"></a>bool </p>
<p id="p950199289165634"><a name="p950199289165634"></a><a name="p950199289165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row803624744165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604857399165634"><a name="p604857399165634"></a><a name="p604857399165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p272648781165634"><a name="p272648781165634"></a><a name="p272648781165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1306606329165634"><a name="p1306606329165634"></a><a name="p1306606329165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1282531832165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1597904047165634"><a name="p1597904047165634"></a><a name="p1597904047165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267369505165634"><a name="p267369505165634"></a><a name="p267369505165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1990145004165634"><a name="p1990145004165634"></a><a name="p1990145004165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1587157908165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226950377165634"><a name="p1226950377165634"></a><a name="p1226950377165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p878299929165634"><a name="p878299929165634"></a><a name="p878299929165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p488034163165634"><a name="p488034163165634"></a><a name="p488034163165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row724267689165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p151341525165634"><a name="p151341525165634"></a><a name="p151341525165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1784348857165634"><a name="p1784348857165634"></a><a name="p1784348857165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1703280302165634"><a name="p1703280302165634"></a><a name="p1703280302165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1563390962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200344606165634"><a name="p200344606165634"></a><a name="p200344606165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868182716165634"><a name="p1868182716165634"></a><a name="p1868182716165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1981841322165634"><a name="p1981841322165634"></a><a name="p1981841322165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row75936372165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323844545165634"><a name="p323844545165634"></a><a name="p323844545165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202014660165634"><a name="p202014660165634"></a><a name="p202014660165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1462393284165634"><a name="p1462393284165634"></a><a name="p1462393284165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row2028540951165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2056559005165634"><a name="p2056559005165634"></a><a name="p2056559005165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1135273036165634"><a name="p1135273036165634"></a><a name="p1135273036165634"></a>void </p>
<p id="p1988865688165634"><a name="p1988865688165634"></a><a name="p1988865688165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1681573161165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p627381061165634"><a name="p627381061165634"></a><a name="p627381061165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1782867351165634"><a name="p1782867351165634"></a><a name="p1782867351165634"></a>virtual int16_t </p>
<p id="p754315352165634"><a name="p754315352165634"></a><a name="p754315352165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row854598317165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p360754340165634"><a name="p360754340165634"></a><a name="p360754340165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p67237459165634"><a name="p67237459165634"></a><a name="p67237459165634"></a>virtual int16_t </p>
<p id="p1605216505165634"><a name="p1605216505165634"></a><a name="p1605216505165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1180597375165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228174728165634"><a name="p228174728165634"></a><a name="p228174728165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1101148549165634"><a name="p1101148549165634"></a><a name="p1101148549165634"></a>virtual void </p>
<p id="p2010121606165634"><a name="p2010121606165634"></a><a name="p2010121606165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row2078036914165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p347828968165634"><a name="p347828968165634"></a><a name="p347828968165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1869322199165634"><a name="p1869322199165634"></a><a name="p1869322199165634"></a>virtual void </p>
<p id="p1931365246165634"><a name="p1931365246165634"></a><a name="p1931365246165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row632459432165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1325156300165634"><a name="p1325156300165634"></a><a name="p1325156300165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1557929582165634"><a name="p1557929582165634"></a><a name="p1557929582165634"></a>int16_t </p>
<p id="p2113622166165634"><a name="p2113622166165634"></a><a name="p2113622166165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row218999862165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1701850496165634"><a name="p1701850496165634"></a><a name="p1701850496165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34281852165634"><a name="p34281852165634"></a><a name="p34281852165634"></a>virtual void </p>
<p id="p1461680910165634"><a name="p1461680910165634"></a><a name="p1461680910165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1549633433165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1297961672165634"><a name="p1297961672165634"></a><a name="p1297961672165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2032476406165634"><a name="p2032476406165634"></a><a name="p2032476406165634"></a>int16_t </p>
<p id="p196886246165634"><a name="p196886246165634"></a><a name="p196886246165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row485791211165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1212001641165634"><a name="p1212001641165634"></a><a name="p1212001641165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1821055754165634"><a name="p1821055754165634"></a><a name="p1821055754165634"></a>virtual void </p>
<p id="p1437674243165634"><a name="p1437674243165634"></a><a name="p1437674243165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1168264901165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44234719165634"><a name="p44234719165634"></a><a name="p44234719165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1864674550165634"><a name="p1864674550165634"></a><a name="p1864674550165634"></a>virtual void </p>
<p id="p130328161165634"><a name="p130328161165634"></a><a name="p130328161165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row555551128165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p224047255165634"><a name="p224047255165634"></a><a name="p224047255165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018058478165634"><a name="p1018058478165634"></a><a name="p1018058478165634"></a>bool </p>
<p id="p1047491636165634"><a name="p1047491636165634"></a><a name="p1047491636165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row683571872165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578732044165634"><a name="p578732044165634"></a><a name="p578732044165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1990496120165634"><a name="p1990496120165634"></a><a name="p1990496120165634"></a>void </p>
<p id="p1531591000165634"><a name="p1531591000165634"></a><a name="p1531591000165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1137180656165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p77231935165634"><a name="p77231935165634"></a><a name="p77231935165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134387229165634"><a name="p1134387229165634"></a><a name="p1134387229165634"></a>void </p>
<p id="p1730292590165634"><a name="p1730292590165634"></a><a name="p1730292590165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1902522159165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1648111433165634"><a name="p1648111433165634"></a><a name="p1648111433165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368379429165634"><a name="p1368379429165634"></a><a name="p1368379429165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1342816932165634"><a name="p1342816932165634"></a><a name="p1342816932165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1891849074165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2127781952165634"><a name="p2127781952165634"></a><a name="p2127781952165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2113839129165634"><a name="p2113839129165634"></a><a name="p2113839129165634"></a>void </p>
<p id="p2023728839165634"><a name="p2023728839165634"></a><a name="p2023728839165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1832167113165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1164163115165634"><a name="p1164163115165634"></a><a name="p1164163115165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18160552165634"><a name="p18160552165634"></a><a name="p18160552165634"></a>const char * </p>
<p id="p2013301556165634"><a name="p2013301556165634"></a><a name="p2013301556165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row554358748165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489561478165634"><a name="p489561478165634"></a><a name="p489561478165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p381949534165634"><a name="p381949534165634"></a><a name="p381949534165634"></a>void </p>
<p id="p1542105106165634"><a name="p1542105106165634"></a><a name="p1542105106165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1463015952165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1397968371165634"><a name="p1397968371165634"></a><a name="p1397968371165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411859138165634"><a name="p411859138165634"></a><a name="p411859138165634"></a>int16_t </p>
<p id="p1178880934165634"><a name="p1178880934165634"></a><a name="p1178880934165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1245376687165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1674816510165634"><a name="p1674816510165634"></a><a name="p1674816510165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632589582165634"><a name="p632589582165634"></a><a name="p632589582165634"></a>virtual void </p>
<p id="p1552191931165634"><a name="p1552191931165634"></a><a name="p1552191931165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row2077641351165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1972446668165634"><a name="p1972446668165634"></a><a name="p1972446668165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1831658062165634"><a name="p1831658062165634"></a><a name="p1831658062165634"></a>void </p>
<p id="p916682590165634"><a name="p916682590165634"></a><a name="p916682590165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row277165187165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1910149876165634"><a name="p1910149876165634"></a><a name="p1910149876165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p502634590165634"><a name="p502634590165634"></a><a name="p502634590165634"></a>void </p>
<p id="p1327972759165634"><a name="p1327972759165634"></a><a name="p1327972759165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row2042983652165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681917303165634"><a name="p681917303165634"></a><a name="p681917303165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494797976165634"><a name="p1494797976165634"></a><a name="p1494797976165634"></a>void </p>
<p id="p1046210513165634"><a name="p1046210513165634"></a><a name="p1046210513165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row437877058165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827861447165634"><a name="p1827861447165634"></a><a name="p1827861447165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p611680630165634"><a name="p611680630165634"></a><a name="p611680630165634"></a>void </p>
<p id="p1232777116165634"><a name="p1232777116165634"></a><a name="p1232777116165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row594188614165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1769895248165634"><a name="p1769895248165634"></a><a name="p1769895248165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p417316048165634"><a name="p417316048165634"></a><a name="p417316048165634"></a>void </p>
<p id="p1158402528165634"><a name="p1158402528165634"></a><a name="p1158402528165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1544311129165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1797519727165634"><a name="p1797519727165634"></a><a name="p1797519727165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2071072434165634"><a name="p2071072434165634"></a><a name="p2071072434165634"></a>void </p>
<p id="p810112575165634"><a name="p810112575165634"></a><a name="p810112575165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row233834375165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496731024165634"><a name="p496731024165634"></a><a name="p496731024165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404916485165634"><a name="p1404916485165634"></a><a name="p1404916485165634"></a>void </p>
<p id="p108581635165634"><a name="p108581635165634"></a><a name="p108581635165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row882863957165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983522492165634"><a name="p1983522492165634"></a><a name="p1983522492165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1152862075165634"><a name="p1152862075165634"></a><a name="p1152862075165634"></a>void </p>
<p id="p771110993165634"><a name="p771110993165634"></a><a name="p771110993165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1836254590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192820203165634"><a name="p1192820203165634"></a><a name="p1192820203165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32274471165634"><a name="p32274471165634"></a><a name="p32274471165634"></a>void </p>
<p id="p3175609165634"><a name="p3175609165634"></a><a name="p3175609165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row828384962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1395679329165634"><a name="p1395679329165634"></a><a name="p1395679329165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1177556324165634"><a name="p1177556324165634"></a><a name="p1177556324165634"></a>void </p>
<p id="p1607030034165634"><a name="p1607030034165634"></a><a name="p1607030034165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row2004782758165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1214289937165634"><a name="p1214289937165634"></a><a name="p1214289937165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592639164165634"><a name="p1592639164165634"></a><a name="p1592639164165634"></a>void </p>
<p id="p1073686569165634"><a name="p1073686569165634"></a><a name="p1073686569165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row253618421165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p995874910165634"><a name="p995874910165634"></a><a name="p995874910165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p614424821165634"><a name="p614424821165634"></a><a name="p614424821165634"></a>void </p>
<p id="p512077234165634"><a name="p512077234165634"></a><a name="p512077234165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1024399836165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p676847789165634"><a name="p676847789165634"></a><a name="p676847789165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1010144864165634"><a name="p1010144864165634"></a><a name="p1010144864165634"></a>void </p>
<p id="p1717957199165634"><a name="p1717957199165634"></a><a name="p1717957199165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1840396909165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364315998165634"><a name="p364315998165634"></a><a name="p364315998165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1953004959165634"><a name="p1953004959165634"></a><a name="p1953004959165634"></a>void </p>
<p id="p1390985810165634"><a name="p1390985810165634"></a><a name="p1390985810165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row56606862165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658076420165634"><a name="p658076420165634"></a><a name="p658076420165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1639279107165634"><a name="p1639279107165634"></a><a name="p1639279107165634"></a>void </p>
<p id="p1686623489165634"><a name="p1686623489165634"></a><a name="p1686623489165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1792228970165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005034019165634"><a name="p1005034019165634"></a><a name="p1005034019165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1303046619165634"><a name="p1303046619165634"></a><a name="p1303046619165634"></a>void </p>
<p id="p731442998165634"><a name="p731442998165634"></a><a name="p731442998165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row443119828165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058014410165634"><a name="p1058014410165634"></a><a name="p1058014410165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305459268165634"><a name="p1305459268165634"></a><a name="p1305459268165634"></a>virtual void </p>
<p id="p1584729469165634"><a name="p1584729469165634"></a><a name="p1584729469165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row885947493165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p180868685165634"><a name="p180868685165634"></a><a name="p180868685165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1203777251165634"><a name="p1203777251165634"></a><a name="p1203777251165634"></a>virtual int64_t </p>
<p id="p34644191165634"><a name="p34644191165634"></a><a name="p34644191165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row257234679165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725928517165634"><a name="p1725928517165634"></a><a name="p1725928517165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501295795165634"><a name="p501295795165634"></a><a name="p501295795165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p477146480165634"><a name="p477146480165634"></a><a name="p477146480165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1863771988165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p640532826165634"><a name="p640532826165634"></a><a name="p640532826165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p23543281165634"><a name="p23543281165634"></a><a name="p23543281165634"></a>void * </p>
<p id="p127141614165634"><a name="p127141614165634"></a><a name="p127141614165634"></a>Overrides the <strong id="b664464176165634"><a name="b664464176165634"></a><a name="b664464176165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row991350056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962622286165634"><a name="p1962622286165634"></a><a name="p1962622286165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182919291165634"><a name="p182919291165634"></a><a name="p182919291165634"></a>void </p>
<p id="p1153726736165634"><a name="p1153726736165634"></a><a name="p1153726736165634"></a>Overrides the <strong id="b1813398346165634"><a name="b1813398346165634"></a><a name="b1813398346165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1318351258165634"></a>
<table><thead align="left"><tr id="row405431785165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p219755126165634"><a name="p219755126165634"></a><a name="p219755126165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p786560712165634"><a name="p786560712165634"></a><a name="p786560712165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1349919182165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684361093165634"><a name="p1684361093165634"></a><a name="p1684361093165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1251928333165634"><a name="p1251928333165634"></a><a name="p1251928333165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row714077200165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980484427165634"><a name="p1980484427165634"></a><a name="p1980484427165634"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p431342805165634"><a name="p431342805165634"></a><a name="p431342805165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1109283820165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152733176165634"><a name="p1152733176165634"></a><a name="p1152733176165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618501624165634"><a name="p1618501624165634"></a><a name="p1618501624165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1562513767165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p300919090165634"><a name="p300919090165634"></a><a name="p300919090165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731857604165634"><a name="p731857604165634"></a><a name="p731857604165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1115429926165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2058447850165634"><a name="p2058447850165634"></a><a name="p2058447850165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591040761165634"><a name="p591040761165634"></a><a name="p591040761165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row2084959376165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1940483958165634"><a name="p1940483958165634"></a><a name="p1940483958165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1998329005165634"><a name="p1998329005165634"></a><a name="p1998329005165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row809655653165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482864239165634"><a name="p1482864239165634"></a><a name="p1482864239165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282367947165634"><a name="p1282367947165634"></a><a name="p1282367947165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row821533487165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498765588165634"><a name="p498765588165634"></a><a name="p498765588165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1756782082165634"><a name="p1756782082165634"></a><a name="p1756782082165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

