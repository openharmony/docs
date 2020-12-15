# OHOS::UIChartPillar<a name="ZH-CN_TOPIC_0000001055518112"></a>

-   [Overview](#section1990708616165634)
-   [Summary](#section356697000165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1990708616165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Provides special functions for implementing a bar chart. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section356697000165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1277417981165634"></a>
<table><thead align="left"><tr id="row1079501717165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1347168122165634"><a name="p1347168122165634"></a><a name="p1347168122165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p945679568165634"><a name="p945679568165634"></a><a name="p945679568165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1455770296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396350324165634"><a name="p1396350324165634"></a><a name="p1396350324165634"></a><a href="Graphic.md#ga5c26ce24f640f795404c8375b4043186">UIChartPillar</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1110614673165634"><a name="p1110614673165634"></a><a name="p1110614673165634"></a> </p>
<p id="p2092722254165634"><a name="p2092722254165634"></a><a name="p2092722254165634"></a>A constructor used to create a <strong id="b1522214586165634"><a name="b1522214586165634"></a><a name="b1522214586165634"></a><a href="OHOS-UIChartPillar.md">UIChartPillar</a></strong> instance. </p>
</td>
</tr>
<tr id="row1732541674165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1998634376165634"><a name="p1998634376165634"></a><a name="p1998634376165634"></a><a href="Graphic.md#ga0f1e413e8eb026f2b5746b05b48d7ca7">~UIChartPillar</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2103807178165634"><a name="p2103807178165634"></a><a name="p2103807178165634"></a>virtual </p>
<p id="p1407659626165634"><a name="p1407659626165634"></a><a name="p1407659626165634"></a>A destructor used to delete the <strong id="b787285699165634"><a name="b787285699165634"></a><a name="b787285699165634"></a><a href="OHOS-UIChartPillar.md">UIChartPillar</a></strong> instance. </p>
</td>
</tr>
<tr id="row114148165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p488575248165634"><a name="p488575248165634"></a><a name="p488575248165634"></a><a href="Graphic.md#ga0c6028474577ce99caa6d3eafaef1573">RefreshChart</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137989296165634"><a name="p137989296165634"></a><a name="p137989296165634"></a>void </p>
<p id="p1469330974165634"><a name="p1469330974165634"></a><a name="p1469330974165634"></a>Refreshes a bar chart and redraws the dirty region. </p>
</td>
</tr>
<tr id="row516392363165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1165888062165634"><a name="p1165888062165634"></a><a name="p1165888062165634"></a><a href="Graphic.md#ga3ab02ed367123e4f84e5ab145f5ed949">UIChart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2131504692165634"><a name="p2131504692165634"></a><a name="p2131504692165634"></a> </p>
<p id="p1308701658165634"><a name="p1308701658165634"></a><a name="p1308701658165634"></a>A constructor used to create a <strong id="b1023097707165634"><a name="b1023097707165634"></a><a name="b1023097707165634"></a><a href="OHOS-UIChart.md">UIChart</a></strong> instance. </p>
</td>
</tr>
<tr id="row2053793088165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2129376075165634"><a name="p2129376075165634"></a><a name="p2129376075165634"></a><a href="Graphic.md#gab5d79c4736d822116dcdd7ed6e45294e">~UIChart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p860100125165634"><a name="p860100125165634"></a><a name="p860100125165634"></a>virtual </p>
<p id="p1842137694165634"><a name="p1842137694165634"></a><a name="p1842137694165634"></a>A destructor used to delete the <strong id="b279940344165634"><a name="b279940344165634"></a><a name="b279940344165634"></a><a href="OHOS-UIChart.md">UIChart</a></strong> instance. </p>
</td>
</tr>
<tr id="row2024442193165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1583498433165634"><a name="p1583498433165634"></a><a name="p1583498433165634"></a><a href="Graphic.md#gaea65298b6e4a71a2de65c13e1b14ed7b">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1565523075165634"><a name="p1565523075165634"></a><a name="p1565523075165634"></a>UIViewType </p>
<p id="p1197707608165634"><a name="p1197707608165634"></a><a name="p1197707608165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row444404448165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1257107377165634"><a name="p1257107377165634"></a><a name="p1257107377165634"></a><a href="Graphic.md#ga54b3c4122ebaeefe74587ca69aa98600">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p49866595165634"><a name="p49866595165634"></a><a name="p49866595165634"></a>void </p>
<p id="p740210178165634"><a name="p740210178165634"></a><a name="p740210178165634"></a>Sets the height for this component. </p>
</td>
</tr>
<tr id="row378971849165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345407040165634"><a name="p1345407040165634"></a><a name="p1345407040165634"></a><a href="Graphic.md#ga2ae317808111cd58e6ba93e030f23111">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2042623700165634"><a name="p2042623700165634"></a><a name="p2042623700165634"></a>void </p>
<p id="p1560517625165634"><a name="p1560517625165634"></a><a name="p1560517625165634"></a>Sets the width for this component. </p>
</td>
</tr>
<tr id="row1771062299165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1151443542165634"><a name="p1151443542165634"></a><a name="p1151443542165634"></a><a href="Graphic.md#ga9a8287a522f00bb3dbe60af8f242054a">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p506037514165634"><a name="p506037514165634"></a><a name="p506037514165634"></a>bool </p>
<p id="p1678983271165634"><a name="p1678983271165634"></a><a name="p1678983271165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row813406327165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856754951165634"><a name="p856754951165634"></a><a name="p856754951165634"></a><a href="Graphic.md#ga5c101948cb2cfb8394af0bcb56f65efb">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380504727165634"><a name="p380504727165634"></a><a name="p380504727165634"></a>void </p>
<p id="p1910168729165634"><a name="p1910168729165634"></a><a name="p1910168729165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row774667198165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299625658165634"><a name="p299625658165634"></a><a name="p299625658165634"></a><a href="Graphic.md#gafc510047aac4e7eebd5b229e726ef762">AddDataSerial</a> (<a href="OHOS-UIChartDataSerial.md">UIChartDataSerial</a> *dataSerial)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p534742836165634"><a name="p534742836165634"></a><a name="p534742836165634"></a>virtual bool </p>
<p id="p1944118576165634"><a name="p1944118576165634"></a><a name="p1944118576165634"></a>Adds a data set. </p>
</td>
</tr>
<tr id="row137087326165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p462807189165634"><a name="p462807189165634"></a><a name="p462807189165634"></a><a href="Graphic.md#ga2af81fbcd6a17ef250bf07e2d7606b8d">DeleteDataSerial</a> (<a href="OHOS-UIChartDataSerial.md">UIChartDataSerial</a> *dataSerial)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p956693278165634"><a name="p956693278165634"></a><a name="p956693278165634"></a>virtual bool </p>
<p id="p1068943736165634"><a name="p1068943736165634"></a><a name="p1068943736165634"></a>Deletes a data set. </p>
</td>
</tr>
<tr id="row552564563165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596280887165634"><a name="p1596280887165634"></a><a name="p1596280887165634"></a><a href="Graphic.md#gae2752857fbcb9f1541cd811321bfc2c6">ClearDataSerial</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45688238165634"><a name="p45688238165634"></a><a name="p45688238165634"></a>virtual void </p>
<p id="p774262128165634"><a name="p774262128165634"></a><a name="p774262128165634"></a>Clears all data sets. </p>
</td>
</tr>
<tr id="row602785255165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472461177165634"><a name="p472461177165634"></a><a name="p472461177165634"></a><a href="Graphic.md#ga010c178e2c1dec79e4af10cbf4545257">GetXAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p93246046165634"><a name="p93246046165634"></a><a name="p93246046165634"></a><a href="OHOS-UIXAxis.md">UIXAxis</a> &amp; </p>
<p id="p1096584608165634"><a name="p1096584608165634"></a><a name="p1096584608165634"></a>Obtains the x-axis instance. </p>
</td>
</tr>
<tr id="row1269811752165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p937892237165634"><a name="p937892237165634"></a><a name="p937892237165634"></a><a href="Graphic.md#ga696227300be45585be102f6a7f66b7b1">GetYAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p228512950165634"><a name="p228512950165634"></a><a name="p228512950165634"></a><a href="OHOS-UIYAxis.md">UIYAxis</a> &amp; </p>
<p id="p40218839165634"><a name="p40218839165634"></a><a name="p40218839165634"></a>Obtains the y-axis instance. </p>
</td>
</tr>
<tr id="row2076121921165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139525932165634"><a name="p139525932165634"></a><a name="p139525932165634"></a><a href="Graphic.md#ga7c99edd3adfb60796be92e98fd71a705">EnableReverse</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715135419165634"><a name="p715135419165634"></a><a name="p715135419165634"></a>void </p>
<p id="p822719864165634"><a name="p822719864165634"></a><a name="p822719864165634"></a>Enables chart reverse. </p>
</td>
</tr>
<tr id="row1706927289165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559666976165634"><a name="p559666976165634"></a><a name="p559666976165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951023708165634"><a name="p951023708165634"></a><a name="p951023708165634"></a> </p>
<p id="p745725165165634"><a name="p745725165165634"></a><a name="p745725165165634"></a>A default constructor used to create a <strong id="b1717100187165634"><a name="b1717100187165634"></a><a name="b1717100187165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1439338457165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376929342165634"><a name="p376929342165634"></a><a name="p376929342165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428628159165634"><a name="p428628159165634"></a><a name="p428628159165634"></a>virtual </p>
<p id="p1195518751165634"><a name="p1195518751165634"></a><a name="p1195518751165634"></a>A destructor used to delete the <strong id="b1049369548165634"><a name="b1049369548165634"></a><a name="b1049369548165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row107631823165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p912565981165634"><a name="p912565981165634"></a><a name="p912565981165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256500850165634"><a name="p1256500850165634"></a><a name="p1256500850165634"></a>UIViewType </p>
<p id="p1381484075165634"><a name="p1381484075165634"></a><a name="p1381484075165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row560566390165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1236250129165634"><a name="p1236250129165634"></a><a name="p1236250129165634"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619332712165634"><a name="p1619332712165634"></a><a name="p1619332712165634"></a>virtual void </p>
<p id="p1936029862165634"><a name="p1936029862165634"></a><a name="p1936029862165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row647344617165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1258483105165634"><a name="p1258483105165634"></a><a name="p1258483105165634"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555041412165634"><a name="p1555041412165634"></a><a name="p1555041412165634"></a>virtual void </p>
<p id="p1694676608165634"><a name="p1694676608165634"></a><a name="p1694676608165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row2041864443165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162458467165634"><a name="p162458467165634"></a><a name="p162458467165634"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1728022772165634"><a name="p1728022772165634"></a><a name="p1728022772165634"></a>virtual void </p>
<p id="p1468647473165634"><a name="p1468647473165634"></a><a name="p1468647473165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row445158219165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p464118365165634"><a name="p464118365165634"></a><a name="p464118365165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p836571806165634"><a name="p836571806165634"></a><a name="p836571806165634"></a>virtual void </p>
<p id="p587035481165634"><a name="p587035481165634"></a><a name="p587035481165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1216168384165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p280550615165634"><a name="p280550615165634"></a><a name="p280550615165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p210539087165634"><a name="p210539087165634"></a><a name="p210539087165634"></a>virtual void </p>
<p id="p1819322101165634"><a name="p1819322101165634"></a><a name="p1819322101165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row318081154165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139963540165634"><a name="p139963540165634"></a><a name="p139963540165634"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1459295924165634"><a name="p1459295924165634"></a><a name="p1459295924165634"></a>virtual void </p>
<p id="p304130804165634"><a name="p304130804165634"></a><a name="p304130804165634"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row18147957165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p132966295165634"><a name="p132966295165634"></a><a name="p132966295165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1748785825165634"><a name="p1748785825165634"></a><a name="p1748785825165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1520174960165634"><a name="p1520174960165634"></a><a name="p1520174960165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row331288355165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p79964066165634"><a name="p79964066165634"></a><a name="p79964066165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1791296177165634"><a name="p1791296177165634"></a><a name="p1791296177165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1918220639165634"><a name="p1918220639165634"></a><a name="p1918220639165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1664883155165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866070472165634"><a name="p866070472165634"></a><a name="p866070472165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1266367670165634"><a name="p1266367670165634"></a><a name="p1266367670165634"></a>void </p>
<p id="p699087885165634"><a name="p699087885165634"></a><a name="p699087885165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row65131060165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1894307477165634"><a name="p1894307477165634"></a><a name="p1894307477165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050184982165634"><a name="p2050184982165634"></a><a name="p2050184982165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1217887940165634"><a name="p1217887940165634"></a><a name="p1217887940165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1066379888165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76549638165634"><a name="p76549638165634"></a><a name="p76549638165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1331151592165634"><a name="p1331151592165634"></a><a name="p1331151592165634"></a>void </p>
<p id="p1342709707165634"><a name="p1342709707165634"></a><a name="p1342709707165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1785928743165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686718087165634"><a name="p686718087165634"></a><a name="p686718087165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p373886209165634"><a name="p373886209165634"></a><a name="p373886209165634"></a> </p>
<p id="p1592035942165634"><a name="p1592035942165634"></a><a name="p1592035942165634"></a>A default constructor used to create an <strong id="b184413671165634"><a name="b184413671165634"></a><a name="b184413671165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row977347849165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p672607265165634"><a name="p672607265165634"></a><a name="p672607265165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p588772002165634"><a name="p588772002165634"></a><a name="p588772002165634"></a> </p>
<p id="p108514875165634"><a name="p108514875165634"></a><a name="p108514875165634"></a>A constructor used to create an <strong id="b700055160165634"><a name="b700055160165634"></a><a name="b700055160165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1586027195165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p376894523165634"><a name="p376894523165634"></a><a name="p376894523165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76897865165634"><a name="p76897865165634"></a><a name="p76897865165634"></a>virtual </p>
<p id="p1367869857165634"><a name="p1367869857165634"></a><a name="p1367869857165634"></a>A destructor used to delete the <strong id="b36157481165634"><a name="b36157481165634"></a><a name="b36157481165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row805776423165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117808354165634"><a name="p117808354165634"></a><a name="p117808354165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p767407519165634"><a name="p767407519165634"></a><a name="p767407519165634"></a>virtual void </p>
<p id="p560905886165634"><a name="p560905886165634"></a><a name="p560905886165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row57471604165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1646862537165634"><a name="p1646862537165634"></a><a name="p1646862537165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570722170165634"><a name="p570722170165634"></a><a name="p570722170165634"></a>virtual void </p>
<p id="p1782893324165634"><a name="p1782893324165634"></a><a name="p1782893324165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1011099803165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605535664165634"><a name="p605535664165634"></a><a name="p605535664165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141725917165634"><a name="p2141725917165634"></a><a name="p2141725917165634"></a>void </p>
<p id="p1405215159165634"><a name="p1405215159165634"></a><a name="p1405215159165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1805493971165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p91280047165634"><a name="p91280047165634"></a><a name="p91280047165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p394515833165634"><a name="p394515833165634"></a><a name="p394515833165634"></a>void </p>
<p id="p1451506061165634"><a name="p1451506061165634"></a><a name="p1451506061165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1840165055165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p759609120165634"><a name="p759609120165634"></a><a name="p759609120165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114322867165634"><a name="p114322867165634"></a><a name="p114322867165634"></a>virtual bool </p>
<p id="p17858235165634"><a name="p17858235165634"></a><a name="p17858235165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1767030109165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1480966874165634"><a name="p1480966874165634"></a><a name="p1480966874165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260516385165634"><a name="p1260516385165634"></a><a name="p1260516385165634"></a>virtual bool </p>
<p id="p278956000165634"><a name="p278956000165634"></a><a name="p278956000165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1448397382165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1799733573165634"><a name="p1799733573165634"></a><a name="p1799733573165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p740090758165634"><a name="p740090758165634"></a><a name="p740090758165634"></a>virtual bool </p>
<p id="p426054070165634"><a name="p426054070165634"></a><a name="p426054070165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row599006021165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777887889165634"><a name="p1777887889165634"></a><a name="p1777887889165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019472134165634"><a name="p1019472134165634"></a><a name="p1019472134165634"></a>virtual bool </p>
<p id="p164111057165634"><a name="p164111057165634"></a><a name="p164111057165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row2104811436165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061487231165634"><a name="p2061487231165634"></a><a name="p2061487231165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761504197165634"><a name="p761504197165634"></a><a name="p761504197165634"></a>virtual void </p>
<p id="p1590783270165634"><a name="p1590783270165634"></a><a name="p1590783270165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row66550287165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45820684165634"><a name="p45820684165634"></a><a name="p45820684165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669381974165634"><a name="p1669381974165634"></a><a name="p1669381974165634"></a>virtual void </p>
<p id="p471309841165634"><a name="p471309841165634"></a><a name="p471309841165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1133945327165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830613816165634"><a name="p830613816165634"></a><a name="p830613816165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p754758146165634"><a name="p754758146165634"></a><a name="p754758146165634"></a>virtual void </p>
<p id="p1537041519165634"><a name="p1537041519165634"></a><a name="p1537041519165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row281895890165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984692929165634"><a name="p984692929165634"></a><a name="p984692929165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028134495165634"><a name="p1028134495165634"></a><a name="p1028134495165634"></a>virtual void </p>
<p id="p1193786317165634"><a name="p1193786317165634"></a><a name="p1193786317165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row922936214165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p22961726165634"><a name="p22961726165634"></a><a name="p22961726165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1724509679165634"><a name="p1724509679165634"></a><a name="p1724509679165634"></a>void </p>
<p id="p819621966165634"><a name="p819621966165634"></a><a name="p819621966165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row679226431165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918804765165634"><a name="p1918804765165634"></a><a name="p1918804765165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260239027165634"><a name="p260239027165634"></a><a name="p260239027165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p698249536165634"><a name="p698249536165634"></a><a name="p698249536165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1306535797165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p703835751165634"><a name="p703835751165634"></a><a name="p703835751165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828592718165634"><a name="p828592718165634"></a><a name="p828592718165634"></a>void </p>
<p id="p958072998165634"><a name="p958072998165634"></a><a name="p958072998165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row699866506165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p796190353165634"><a name="p796190353165634"></a><a name="p796190353165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p205482266165634"><a name="p205482266165634"></a><a name="p205482266165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1352291699165634"><a name="p1352291699165634"></a><a name="p1352291699165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row568226781165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1745321284165634"><a name="p1745321284165634"></a><a name="p1745321284165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153641642165634"><a name="p1153641642165634"></a><a name="p1153641642165634"></a>void </p>
<p id="p336091233165634"><a name="p336091233165634"></a><a name="p336091233165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1406792113165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779983718165634"><a name="p779983718165634"></a><a name="p779983718165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p134773319165634"><a name="p134773319165634"></a><a name="p134773319165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1827391543165634"><a name="p1827391543165634"></a><a name="p1827391543165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row735421947165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737319534165634"><a name="p1737319534165634"></a><a name="p1737319534165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382050597165634"><a name="p1382050597165634"></a><a name="p1382050597165634"></a>void </p>
<p id="p351331505165634"><a name="p351331505165634"></a><a name="p351331505165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row2051027330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1210994776165634"><a name="p1210994776165634"></a><a name="p1210994776165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p128014086165634"><a name="p128014086165634"></a><a name="p128014086165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p814834050165634"><a name="p814834050165634"></a><a name="p814834050165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row510328990165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751870116165634"><a name="p1751870116165634"></a><a name="p1751870116165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p326018287165634"><a name="p326018287165634"></a><a name="p326018287165634"></a>void </p>
<p id="p195770251165634"><a name="p195770251165634"></a><a name="p195770251165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row3751447165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247994216165634"><a name="p247994216165634"></a><a name="p247994216165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623749744165634"><a name="p623749744165634"></a><a name="p623749744165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1238449308165634"><a name="p1238449308165634"></a><a name="p1238449308165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row946993823165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117687006165634"><a name="p1117687006165634"></a><a name="p1117687006165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413924429165634"><a name="p413924429165634"></a><a name="p413924429165634"></a>void </p>
<p id="p2073520177165634"><a name="p2073520177165634"></a><a name="p2073520177165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1876309067165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722514802165634"><a name="p722514802165634"></a><a name="p722514802165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918332658165634"><a name="p918332658165634"></a><a name="p918332658165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p890984047165634"><a name="p890984047165634"></a><a name="p890984047165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row121122454165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p301900537165634"><a name="p301900537165634"></a><a name="p301900537165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435578772165634"><a name="p435578772165634"></a><a name="p435578772165634"></a>virtual void </p>
<p id="p59014557165634"><a name="p59014557165634"></a><a name="p59014557165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1432442331165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1608215907165634"><a name="p1608215907165634"></a><a name="p1608215907165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511428377165634"><a name="p511428377165634"></a><a name="p511428377165634"></a>bool </p>
<p id="p474362903165634"><a name="p474362903165634"></a><a name="p474362903165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row761404882165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50007065165634"><a name="p50007065165634"></a><a name="p50007065165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1006084425165634"><a name="p1006084425165634"></a><a name="p1006084425165634"></a>void </p>
<p id="p687758358165634"><a name="p687758358165634"></a><a name="p687758358165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1298292211165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p407860446165634"><a name="p407860446165634"></a><a name="p407860446165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p401337139165634"><a name="p401337139165634"></a><a name="p401337139165634"></a>bool </p>
<p id="p1058143062165634"><a name="p1058143062165634"></a><a name="p1058143062165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row241028730165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856087202165634"><a name="p856087202165634"></a><a name="p856087202165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151839310165634"><a name="p151839310165634"></a><a name="p151839310165634"></a>void </p>
<p id="p1939179097165634"><a name="p1939179097165634"></a><a name="p1939179097165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row196574113165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1553415356165634"><a name="p1553415356165634"></a><a name="p1553415356165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196965397165634"><a name="p196965397165634"></a><a name="p196965397165634"></a>bool </p>
<p id="p328136168165634"><a name="p328136168165634"></a><a name="p328136168165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1994214929165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1640885390165634"><a name="p1640885390165634"></a><a name="p1640885390165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862067816165634"><a name="p1862067816165634"></a><a name="p1862067816165634"></a>void </p>
<p id="p1160599959165634"><a name="p1160599959165634"></a><a name="p1160599959165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row248528858165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p774179889165634"><a name="p774179889165634"></a><a name="p774179889165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523625596165634"><a name="p1523625596165634"></a><a name="p1523625596165634"></a>bool </p>
<p id="p166145714165634"><a name="p166145714165634"></a><a name="p166145714165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row89603485165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891692803165634"><a name="p1891692803165634"></a><a name="p1891692803165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p425177803165634"><a name="p425177803165634"></a><a name="p425177803165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1079220340165634"><a name="p1079220340165634"></a><a name="p1079220340165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1329342485165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122596238165634"><a name="p1122596238165634"></a><a name="p1122596238165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775876016165634"><a name="p775876016165634"></a><a name="p775876016165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1234475403165634"><a name="p1234475403165634"></a><a name="p1234475403165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row19750202165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164225298165634"><a name="p164225298165634"></a><a name="p164225298165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1469733976165634"><a name="p1469733976165634"></a><a name="p1469733976165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p101128316165634"><a name="p101128316165634"></a><a name="p101128316165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row893430804165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609716234165634"><a name="p1609716234165634"></a><a name="p1609716234165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p569490168165634"><a name="p569490168165634"></a><a name="p569490168165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p710898715165634"><a name="p710898715165634"></a><a name="p710898715165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row2084809187165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p47532224165634"><a name="p47532224165634"></a><a name="p47532224165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095179220165634"><a name="p2095179220165634"></a><a name="p2095179220165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1672473241165634"><a name="p1672473241165634"></a><a name="p1672473241165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1315991198165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705274528165634"><a name="p705274528165634"></a><a name="p705274528165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717395909165634"><a name="p1717395909165634"></a><a name="p1717395909165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1848240604165634"><a name="p1848240604165634"></a><a name="p1848240604165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1522219528165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p665833190165634"><a name="p665833190165634"></a><a name="p665833190165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065677599165634"><a name="p1065677599165634"></a><a name="p1065677599165634"></a>void </p>
<p id="p1575442903165634"><a name="p1575442903165634"></a><a name="p1575442903165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1212442897165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1889597105165634"><a name="p1889597105165634"></a><a name="p1889597105165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718642333165634"><a name="p1718642333165634"></a><a name="p1718642333165634"></a>virtual int16_t </p>
<p id="p1533470915165634"><a name="p1533470915165634"></a><a name="p1533470915165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row206958539165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2088116659165634"><a name="p2088116659165634"></a><a name="p2088116659165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168737776165634"><a name="p1168737776165634"></a><a name="p1168737776165634"></a>virtual int16_t </p>
<p id="p226067883165634"><a name="p226067883165634"></a><a name="p226067883165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row141073857165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1674162523165634"><a name="p1674162523165634"></a><a name="p1674162523165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p513373724165634"><a name="p513373724165634"></a><a name="p513373724165634"></a>virtual void </p>
<p id="p1020187980165634"><a name="p1020187980165634"></a><a name="p1020187980165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1970801185165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p164832748165634"><a name="p164832748165634"></a><a name="p164832748165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2005953302165634"><a name="p2005953302165634"></a><a name="p2005953302165634"></a>virtual void </p>
<p id="p1320170479165634"><a name="p1320170479165634"></a><a name="p1320170479165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1358790385165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1218741129165634"><a name="p1218741129165634"></a><a name="p1218741129165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1302190204165634"><a name="p1302190204165634"></a><a name="p1302190204165634"></a>int16_t </p>
<p id="p952250650165634"><a name="p952250650165634"></a><a name="p952250650165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1211782695165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357662578165634"><a name="p357662578165634"></a><a name="p357662578165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1270481139165634"><a name="p1270481139165634"></a><a name="p1270481139165634"></a>virtual void </p>
<p id="p1639994505165634"><a name="p1639994505165634"></a><a name="p1639994505165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1528112172165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207503262165634"><a name="p1207503262165634"></a><a name="p1207503262165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1835809024165634"><a name="p1835809024165634"></a><a name="p1835809024165634"></a>int16_t </p>
<p id="p373678802165634"><a name="p373678802165634"></a><a name="p373678802165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row623668620165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p995567506165634"><a name="p995567506165634"></a><a name="p995567506165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546955687165634"><a name="p546955687165634"></a><a name="p546955687165634"></a>virtual void </p>
<p id="p1866985469165634"><a name="p1866985469165634"></a><a name="p1866985469165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1291303712165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2140112793165634"><a name="p2140112793165634"></a><a name="p2140112793165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1418193213165634"><a name="p1418193213165634"></a><a name="p1418193213165634"></a>virtual void </p>
<p id="p150652773165634"><a name="p150652773165634"></a><a name="p150652773165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row969603549165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448675848165634"><a name="p448675848165634"></a><a name="p448675848165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p897983022165634"><a name="p897983022165634"></a><a name="p897983022165634"></a>bool </p>
<p id="p142621530165634"><a name="p142621530165634"></a><a name="p142621530165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row533646544165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1741978273165634"><a name="p1741978273165634"></a><a name="p1741978273165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460247110165634"><a name="p460247110165634"></a><a name="p460247110165634"></a>void </p>
<p id="p1074910811165634"><a name="p1074910811165634"></a><a name="p1074910811165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row222723934165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060715930165634"><a name="p1060715930165634"></a><a name="p1060715930165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722134894165634"><a name="p722134894165634"></a><a name="p722134894165634"></a>void </p>
<p id="p723119577165634"><a name="p723119577165634"></a><a name="p723119577165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1260830142165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1241171760165634"><a name="p1241171760165634"></a><a name="p1241171760165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p410489989165634"><a name="p410489989165634"></a><a name="p410489989165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p755137980165634"><a name="p755137980165634"></a><a name="p755137980165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row849115419165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1853323457165634"><a name="p1853323457165634"></a><a name="p1853323457165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p384916239165634"><a name="p384916239165634"></a><a name="p384916239165634"></a>void </p>
<p id="p2059710664165634"><a name="p2059710664165634"></a><a name="p2059710664165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row912669197165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835741561165634"><a name="p1835741561165634"></a><a name="p1835741561165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875049592165634"><a name="p875049592165634"></a><a name="p875049592165634"></a>const char * </p>
<p id="p2012289662165634"><a name="p2012289662165634"></a><a name="p2012289662165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row46487015165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510893046165634"><a name="p1510893046165634"></a><a name="p1510893046165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p440403681165634"><a name="p440403681165634"></a><a name="p440403681165634"></a>void </p>
<p id="p398222933165634"><a name="p398222933165634"></a><a name="p398222933165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row101855341165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p773460053165634"><a name="p773460053165634"></a><a name="p773460053165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p697392621165634"><a name="p697392621165634"></a><a name="p697392621165634"></a>int16_t </p>
<p id="p1449894550165634"><a name="p1449894550165634"></a><a name="p1449894550165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row881194914165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1792819595165634"><a name="p1792819595165634"></a><a name="p1792819595165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628089868165634"><a name="p628089868165634"></a><a name="p628089868165634"></a>virtual void </p>
<p id="p1331792080165634"><a name="p1331792080165634"></a><a name="p1331792080165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row452473652165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987198670165634"><a name="p1987198670165634"></a><a name="p1987198670165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p344054983165634"><a name="p344054983165634"></a><a name="p344054983165634"></a>void </p>
<p id="p1706820382165634"><a name="p1706820382165634"></a><a name="p1706820382165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row252468389165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p638132332165634"><a name="p638132332165634"></a><a name="p638132332165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p869425639165634"><a name="p869425639165634"></a><a name="p869425639165634"></a>void </p>
<p id="p1747650849165634"><a name="p1747650849165634"></a><a name="p1747650849165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1931389022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1193449540165634"><a name="p1193449540165634"></a><a name="p1193449540165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1505480633165634"><a name="p1505480633165634"></a><a name="p1505480633165634"></a>void </p>
<p id="p1245856102165634"><a name="p1245856102165634"></a><a name="p1245856102165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row819785261165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1288336932165634"><a name="p1288336932165634"></a><a name="p1288336932165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p309283038165634"><a name="p309283038165634"></a><a name="p309283038165634"></a>void </p>
<p id="p1493196385165634"><a name="p1493196385165634"></a><a name="p1493196385165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1155847915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960847919165634"><a name="p1960847919165634"></a><a name="p1960847919165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1689430798165634"><a name="p1689430798165634"></a><a name="p1689430798165634"></a>void </p>
<p id="p804440018165634"><a name="p804440018165634"></a><a name="p804440018165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1107012441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p727881883165634"><a name="p727881883165634"></a><a name="p727881883165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p422832613165634"><a name="p422832613165634"></a><a name="p422832613165634"></a>void </p>
<p id="p150199279165634"><a name="p150199279165634"></a><a name="p150199279165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row302841811165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1695560647165634"><a name="p1695560647165634"></a><a name="p1695560647165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p767265419165634"><a name="p767265419165634"></a><a name="p767265419165634"></a>void </p>
<p id="p1410470307165634"><a name="p1410470307165634"></a><a name="p1410470307165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row2096100564165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p675734781165634"><a name="p675734781165634"></a><a name="p675734781165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929010269165634"><a name="p929010269165634"></a><a name="p929010269165634"></a>void </p>
<p id="p290584972165634"><a name="p290584972165634"></a><a name="p290584972165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1143968562165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1619100256165634"><a name="p1619100256165634"></a><a name="p1619100256165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924308956165634"><a name="p924308956165634"></a><a name="p924308956165634"></a>void </p>
<p id="p1981618125165634"><a name="p1981618125165634"></a><a name="p1981618125165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1081735231165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1260198106165634"><a name="p1260198106165634"></a><a name="p1260198106165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p911762924165634"><a name="p911762924165634"></a><a name="p911762924165634"></a>void </p>
<p id="p1311023091165634"><a name="p1311023091165634"></a><a name="p1311023091165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row308950850165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p154237496165634"><a name="p154237496165634"></a><a name="p154237496165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p383653127165634"><a name="p383653127165634"></a><a name="p383653127165634"></a>void </p>
<p id="p1812446377165634"><a name="p1812446377165634"></a><a name="p1812446377165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row554915464165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082841626165634"><a name="p1082841626165634"></a><a name="p1082841626165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290425476165634"><a name="p290425476165634"></a><a name="p290425476165634"></a>void </p>
<p id="p1655443058165634"><a name="p1655443058165634"></a><a name="p1655443058165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row719159942165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1582522637165634"><a name="p1582522637165634"></a><a name="p1582522637165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208836361165634"><a name="p1208836361165634"></a><a name="p1208836361165634"></a>void </p>
<p id="p586120428165634"><a name="p586120428165634"></a><a name="p586120428165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1196056388165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p983157278165634"><a name="p983157278165634"></a><a name="p983157278165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p729504560165634"><a name="p729504560165634"></a><a name="p729504560165634"></a>void </p>
<p id="p1131501314165634"><a name="p1131501314165634"></a><a name="p1131501314165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row676809280165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p386797066165634"><a name="p386797066165634"></a><a name="p386797066165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858641446165634"><a name="p1858641446165634"></a><a name="p1858641446165634"></a>void </p>
<p id="p32075805165634"><a name="p32075805165634"></a><a name="p32075805165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row479840025165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139771503165634"><a name="p139771503165634"></a><a name="p139771503165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1388939360165634"><a name="p1388939360165634"></a><a name="p1388939360165634"></a>void </p>
<p id="p1234455884165634"><a name="p1234455884165634"></a><a name="p1234455884165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row245940638165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248380167165634"><a name="p1248380167165634"></a><a name="p1248380167165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1147191264165634"><a name="p1147191264165634"></a><a name="p1147191264165634"></a>virtual void </p>
<p id="p1021492651165634"><a name="p1021492651165634"></a><a name="p1021492651165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row903294581165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977882109165634"><a name="p1977882109165634"></a><a name="p1977882109165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806157709165634"><a name="p806157709165634"></a><a name="p806157709165634"></a>virtual int64_t </p>
<p id="p1024752493165634"><a name="p1024752493165634"></a><a name="p1024752493165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1640414556165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1696244092165634"><a name="p1696244092165634"></a><a name="p1696244092165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104694424165634"><a name="p2104694424165634"></a><a name="p2104694424165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1941886294165634"><a name="p1941886294165634"></a><a name="p1941886294165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1468061716165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511232270165634"><a name="p1511232270165634"></a><a name="p1511232270165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1642259563165634"><a name="p1642259563165634"></a><a name="p1642259563165634"></a>void * </p>
<p id="p257920100165634"><a name="p257920100165634"></a><a name="p257920100165634"></a>Overrides the <strong id="b885800420165634"><a name="b885800420165634"></a><a name="b885800420165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1501636608165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332562732165634"><a name="p1332562732165634"></a><a name="p1332562732165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1538304859165634"><a name="p1538304859165634"></a><a name="p1538304859165634"></a>void </p>
<p id="p91524944165634"><a name="p91524944165634"></a><a name="p91524944165634"></a>Overrides the <strong id="b1857883220165634"><a name="b1857883220165634"></a><a name="b1857883220165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1753502521165634"></a>
<table><thead align="left"><tr id="row1957614170165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p939208476165634"><a name="p939208476165634"></a><a name="p939208476165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2000049057165634"><a name="p2000049057165634"></a><a name="p2000049057165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1785420015165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846761117165634"><a name="p1846761117165634"></a><a name="p1846761117165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774363178165634"><a name="p774363178165634"></a><a name="p774363178165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1186756701165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1359166145165634"><a name="p1359166145165634"></a><a name="p1359166145165634"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p980421264165634"><a name="p980421264165634"></a><a name="p980421264165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row884264726165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839174321165634"><a name="p1839174321165634"></a><a name="p1839174321165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912098946165634"><a name="p1912098946165634"></a><a name="p1912098946165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row385221344165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606506412165634"><a name="p1606506412165634"></a><a name="p1606506412165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1244257944165634"><a name="p1244257944165634"></a><a name="p1244257944165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1406022334165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1278954288165634"><a name="p1278954288165634"></a><a name="p1278954288165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253377270165634"><a name="p1253377270165634"></a><a name="p1253377270165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row608956133165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396310792165634"><a name="p396310792165634"></a><a name="p396310792165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1294469804165634"><a name="p1294469804165634"></a><a name="p1294469804165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row162465874165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778159780165634"><a name="p778159780165634"></a><a name="p778159780165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1324738256165634"><a name="p1324738256165634"></a><a name="p1324738256165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1558692464165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1500178904165634"><a name="p1500178904165634"></a><a name="p1500178904165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614663223165634"><a name="p1614663223165634"></a><a name="p1614663223165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

