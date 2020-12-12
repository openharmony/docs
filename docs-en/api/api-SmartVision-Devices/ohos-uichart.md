# OHOS::UIChart<a name="EN-US_TOPIC_0000001055039538"></a>

-   [Overview](#section1003665507165633)
-   [Summary](#section1369937248165633)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1003665507165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the chart class and provides functions such as adding and deleting data sets to display a chart. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1369937248165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table975988012165633"></a>
<table><thead align="left"><tr id="row77927522165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1550547454165633"><a name="p1550547454165633"></a><a name="p1550547454165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1706540204165633"><a name="p1706540204165633"></a><a name="p1706540204165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row512816556165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2320981165633"><a name="p2320981165633"></a><a name="p2320981165633"></a><a href="graphic.md#ga3ab02ed367123e4f84e5ab145f5ed949">UIChart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1188329715165633"><a name="p1188329715165633"></a><a name="p1188329715165633"></a> </p>
<p id="p758050153165633"><a name="p758050153165633"></a><a name="p758050153165633"></a>A constructor used to create a <strong id="b1464899847165633"><a name="b1464899847165633"></a><a name="b1464899847165633"></a><a href="ohos-uichart.md">UIChart</a></strong> instance. </p>
</td>
</tr>
<tr id="row143548725165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p758284142165633"><a name="p758284142165633"></a><a name="p758284142165633"></a><a href="graphic.md#gab5d79c4736d822116dcdd7ed6e45294e">~UIChart</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90995618165633"><a name="p90995618165633"></a><a name="p90995618165633"></a>virtual </p>
<p id="p2001275423165633"><a name="p2001275423165633"></a><a name="p2001275423165633"></a>A destructor used to delete the <strong id="b1800049544165633"><a name="b1800049544165633"></a><a name="b1800049544165633"></a><a href="ohos-uichart.md">UIChart</a></strong> instance. </p>
</td>
</tr>
<tr id="row403410081165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268822621165633"><a name="p268822621165633"></a><a name="p268822621165633"></a><a href="graphic.md#gaea65298b6e4a71a2de65c13e1b14ed7b">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750129777165633"><a name="p1750129777165633"></a><a name="p1750129777165633"></a>UIViewType </p>
<p id="p1499870259165633"><a name="p1499870259165633"></a><a name="p1499870259165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row695824255165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p367116295165633"><a name="p367116295165633"></a><a name="p367116295165633"></a><a href="graphic.md#ga54b3c4122ebaeefe74587ca69aa98600">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1829295122165633"><a name="p1829295122165633"></a><a name="p1829295122165633"></a>void </p>
<p id="p1532085119165633"><a name="p1532085119165633"></a><a name="p1532085119165633"></a>Sets the height for this component. </p>
</td>
</tr>
<tr id="row23075267165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031166288165633"><a name="p1031166288165633"></a><a name="p1031166288165633"></a><a href="graphic.md#ga2ae317808111cd58e6ba93e030f23111">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459027847165633"><a name="p459027847165633"></a><a name="p459027847165633"></a>void </p>
<p id="p1005758163165633"><a name="p1005758163165633"></a><a name="p1005758163165633"></a>Sets the width for this component. </p>
</td>
</tr>
<tr id="row903233508165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1029900466165633"><a name="p1029900466165633"></a><a name="p1029900466165633"></a><a href="graphic.md#ga9a8287a522f00bb3dbe60af8f242054a">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2068420108165633"><a name="p2068420108165633"></a><a name="p2068420108165633"></a>bool </p>
<p id="p603953752165633"><a name="p603953752165633"></a><a name="p603953752165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row469387111165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p171371634165633"><a name="p171371634165633"></a><a name="p171371634165633"></a><a href="graphic.md#ga5c101948cb2cfb8394af0bcb56f65efb">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125102275165633"><a name="p2125102275165633"></a><a name="p2125102275165633"></a>void </p>
<p id="p477922780165633"><a name="p477922780165633"></a><a name="p477922780165633"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row83918286165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566305146165633"><a name="p566305146165633"></a><a name="p566305146165633"></a><a href="graphic.md#gafc510047aac4e7eebd5b229e726ef762">AddDataSerial</a> (<a href="ohos-uichartdataserial.md">UIChartDataSerial</a> *dataSerial)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413069931165633"><a name="p1413069931165633"></a><a name="p1413069931165633"></a>virtual bool </p>
<p id="p906673241165633"><a name="p906673241165633"></a><a name="p906673241165633"></a>Adds a data set. </p>
</td>
</tr>
<tr id="row1749754959165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p951301694165633"><a name="p951301694165633"></a><a name="p951301694165633"></a><a href="graphic.md#ga2af81fbcd6a17ef250bf07e2d7606b8d">DeleteDataSerial</a> (<a href="ohos-uichartdataserial.md">UIChartDataSerial</a> *dataSerial)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758151689165633"><a name="p1758151689165633"></a><a name="p1758151689165633"></a>virtual bool </p>
<p id="p1110619687165633"><a name="p1110619687165633"></a><a name="p1110619687165633"></a>Deletes a data set. </p>
</td>
</tr>
<tr id="row1079236773165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674636708165633"><a name="p674636708165633"></a><a name="p674636708165633"></a><a href="graphic.md#gae2752857fbcb9f1541cd811321bfc2c6">ClearDataSerial</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690296095165633"><a name="p690296095165633"></a><a name="p690296095165633"></a>virtual void </p>
<p id="p1504031086165633"><a name="p1504031086165633"></a><a name="p1504031086165633"></a>Clears all data sets. </p>
</td>
</tr>
<tr id="row919423534165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1411094152165633"><a name="p1411094152165633"></a><a name="p1411094152165633"></a><a href="graphic.md#gaaab35011c82308c770cf5c15641fe21c">RefreshChart</a> ()=0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377989844165633"><a name="p1377989844165633"></a><a name="p1377989844165633"></a>virtual void </p>
<p id="p1624014941165633"><a name="p1624014941165633"></a><a name="p1624014941165633"></a>Refreshes a chart and redraws the dirty region. </p>
</td>
</tr>
<tr id="row1042588569165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1678267719165633"><a name="p1678267719165633"></a><a name="p1678267719165633"></a><a href="graphic.md#ga010c178e2c1dec79e4af10cbf4545257">GetXAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450015262165633"><a name="p450015262165633"></a><a name="p450015262165633"></a><a href="ohos-uixaxis.md">UIXAxis</a> &amp; </p>
<p id="p1471684646165633"><a name="p1471684646165633"></a><a name="p1471684646165633"></a>Obtains the x-axis instance. </p>
</td>
</tr>
<tr id="row810546464165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358029660165633"><a name="p1358029660165633"></a><a name="p1358029660165633"></a><a href="graphic.md#ga696227300be45585be102f6a7f66b7b1">GetYAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638867258165633"><a name="p1638867258165633"></a><a name="p1638867258165633"></a><a href="ohos-uiyaxis.md">UIYAxis</a> &amp; </p>
<p id="p1557663144165633"><a name="p1557663144165633"></a><a name="p1557663144165633"></a>Obtains the y-axis instance. </p>
</td>
</tr>
<tr id="row916477745165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1603319466165633"><a name="p1603319466165633"></a><a name="p1603319466165633"></a><a href="graphic.md#ga7c99edd3adfb60796be92e98fd71a705">EnableReverse</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p831731608165633"><a name="p831731608165633"></a><a name="p831731608165633"></a>void </p>
<p id="p880222075165633"><a name="p880222075165633"></a><a name="p880222075165633"></a>Enables chart reverse. </p>
</td>
</tr>
<tr id="row351429826165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1715164166165633"><a name="p1715164166165633"></a><a name="p1715164166165633"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p991018722165633"><a name="p991018722165633"></a><a name="p991018722165633"></a> </p>
<p id="p2140135351165633"><a name="p2140135351165633"></a><a name="p2140135351165633"></a>A default constructor used to create a <strong id="b1369048860165633"><a name="b1369048860165633"></a><a name="b1369048860165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1001032286165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576736394165633"><a name="p576736394165633"></a><a name="p576736394165633"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663318501165633"><a name="p1663318501165633"></a><a name="p1663318501165633"></a>virtual </p>
<p id="p448015335165633"><a name="p448015335165633"></a><a name="p448015335165633"></a>A destructor used to delete the <strong id="b1937888263165633"><a name="b1937888263165633"></a><a name="b1937888263165633"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row549709650165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p478052119165633"><a name="p478052119165633"></a><a name="p478052119165633"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531156418165633"><a name="p1531156418165633"></a><a name="p1531156418165633"></a>UIViewType </p>
<p id="p1119336738165633"><a name="p1119336738165633"></a><a name="p1119336738165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1712434888165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447459637165633"><a name="p1447459637165633"></a><a name="p1447459637165633"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p199360059165633"><a name="p199360059165633"></a><a name="p199360059165633"></a>virtual void </p>
<p id="p2046724408165633"><a name="p2046724408165633"></a><a name="p2046724408165633"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row948970338165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286956021165633"><a name="p1286956021165633"></a><a name="p1286956021165633"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p607914402165633"><a name="p607914402165633"></a><a name="p607914402165633"></a>virtual void </p>
<p id="p1498952160165633"><a name="p1498952160165633"></a><a name="p1498952160165633"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1120461194165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p333286695165633"><a name="p333286695165633"></a><a name="p333286695165633"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p852113916165633"><a name="p852113916165633"></a><a name="p852113916165633"></a>virtual void </p>
<p id="p933990615165633"><a name="p933990615165633"></a><a name="p933990615165633"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row998776732165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1981597009165633"><a name="p1981597009165633"></a><a name="p1981597009165633"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827863308165633"><a name="p1827863308165633"></a><a name="p1827863308165633"></a>virtual void </p>
<p id="p1788200357165633"><a name="p1788200357165633"></a><a name="p1788200357165633"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row659975670165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245334049165633"><a name="p245334049165633"></a><a name="p245334049165633"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885855224165633"><a name="p1885855224165633"></a><a name="p1885855224165633"></a>virtual void </p>
<p id="p1878805584165633"><a name="p1878805584165633"></a><a name="p1878805584165633"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1133877954165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1106101770165633"><a name="p1106101770165633"></a><a name="p1106101770165633"></a><a href="graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p77733116165633"><a name="p77733116165633"></a><a name="p77733116165633"></a>virtual void </p>
<p id="p1256675260165633"><a name="p1256675260165633"></a><a name="p1256675260165633"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row206915241165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2081518299165633"><a name="p2081518299165633"></a><a name="p2081518299165633"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018713353165633"><a name="p2018713353165633"></a><a name="p2018713353165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1100350619165633"><a name="p1100350619165633"></a><a name="p1100350619165633"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row97663589165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p988117774165633"><a name="p988117774165633"></a><a name="p988117774165633"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1181945626165633"><a name="p1181945626165633"></a><a name="p1181945626165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1409690826165633"><a name="p1409690826165633"></a><a name="p1409690826165633"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row166150472165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2037286747165633"><a name="p2037286747165633"></a><a name="p2037286747165633"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690995999165633"><a name="p690995999165633"></a><a name="p690995999165633"></a>void </p>
<p id="p687123789165633"><a name="p687123789165633"></a><a name="p687123789165633"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row786061685165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1185518237165633"><a name="p1185518237165633"></a><a name="p1185518237165633"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p855987635165633"><a name="p855987635165633"></a><a name="p855987635165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1015531103165633"><a name="p1015531103165633"></a><a name="p1015531103165633"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row229817025165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p530560683165633"><a name="p530560683165633"></a><a name="p530560683165633"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152528214165633"><a name="p152528214165633"></a><a name="p152528214165633"></a>void </p>
<p id="p1832297564165633"><a name="p1832297564165633"></a><a name="p1832297564165633"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row2107815101165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839383437165633"><a name="p1839383437165633"></a><a name="p1839383437165633"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892000231165633"><a name="p1892000231165633"></a><a name="p1892000231165633"></a> </p>
<p id="p92375313165633"><a name="p92375313165633"></a><a name="p92375313165633"></a>A default constructor used to create an <strong id="b109786988165633"><a name="b109786988165633"></a><a name="b109786988165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1974493258165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049241993165633"><a name="p2049241993165633"></a><a name="p2049241993165633"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206994806165633"><a name="p206994806165633"></a><a name="p206994806165633"></a> </p>
<p id="p132018847165633"><a name="p132018847165633"></a><a name="p132018847165633"></a>A constructor used to create an <strong id="b2140684783165633"><a name="b2140684783165633"></a><a name="b2140684783165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1517365235165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489983392165633"><a name="p1489983392165633"></a><a name="p1489983392165633"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p993321305165633"><a name="p993321305165633"></a><a name="p993321305165633"></a>virtual </p>
<p id="p2103837577165633"><a name="p2103837577165633"></a><a name="p2103837577165633"></a>A destructor used to delete the <strong id="b1375361656165633"><a name="b1375361656165633"></a><a name="b1375361656165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1530410318165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p795865198165633"><a name="p795865198165633"></a><a name="p795865198165633"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746530129165633"><a name="p1746530129165633"></a><a name="p1746530129165633"></a>virtual void </p>
<p id="p628627455165633"><a name="p628627455165633"></a><a name="p628627455165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row459592610165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p416141828165633"><a name="p416141828165633"></a><a name="p416141828165633"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1958662711165633"><a name="p1958662711165633"></a><a name="p1958662711165633"></a>virtual void </p>
<p id="p1897442800165633"><a name="p1897442800165633"></a><a name="p1897442800165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1587463291165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294156514165633"><a name="p294156514165633"></a><a name="p294156514165633"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1989752306165633"><a name="p1989752306165633"></a><a name="p1989752306165633"></a>void </p>
<p id="p298375557165633"><a name="p298375557165633"></a><a name="p298375557165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1459187984165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p789376315165633"><a name="p789376315165633"></a><a name="p789376315165633"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p851710163165633"><a name="p851710163165633"></a><a name="p851710163165633"></a>void </p>
<p id="p2100164413165633"><a name="p2100164413165633"></a><a name="p2100164413165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row112453336165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1930716129165633"><a name="p1930716129165633"></a><a name="p1930716129165633"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1431299697165633"><a name="p1431299697165633"></a><a name="p1431299697165633"></a>virtual bool </p>
<p id="p1523034289165633"><a name="p1523034289165633"></a><a name="p1523034289165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row53715115165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236976401165633"><a name="p236976401165633"></a><a name="p236976401165633"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053251495165633"><a name="p1053251495165633"></a><a name="p1053251495165633"></a>virtual bool </p>
<p id="p1770149604165633"><a name="p1770149604165633"></a><a name="p1770149604165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row320604793165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641335883165633"><a name="p641335883165633"></a><a name="p641335883165633"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574603099165633"><a name="p1574603099165633"></a><a name="p1574603099165633"></a>virtual bool </p>
<p id="p488089082165633"><a name="p488089082165633"></a><a name="p488089082165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row433958374165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p543125075165633"><a name="p543125075165633"></a><a name="p543125075165633"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p81652120165633"><a name="p81652120165633"></a><a name="p81652120165633"></a>virtual bool </p>
<p id="p1306577237165633"><a name="p1306577237165633"></a><a name="p1306577237165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row510269105165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p663408904165633"><a name="p663408904165633"></a><a name="p663408904165633"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1732563317165633"><a name="p1732563317165633"></a><a name="p1732563317165633"></a>virtual void </p>
<p id="p1097329514165633"><a name="p1097329514165633"></a><a name="p1097329514165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row65359510165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1261806628165633"><a name="p1261806628165633"></a><a name="p1261806628165633"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696321292165633"><a name="p696321292165633"></a><a name="p696321292165633"></a>virtual void </p>
<p id="p424455306165633"><a name="p424455306165633"></a><a name="p424455306165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row222503889165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708551353165633"><a name="p1708551353165633"></a><a name="p1708551353165633"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223721833165633"><a name="p1223721833165633"></a><a name="p1223721833165633"></a>virtual void </p>
<p id="p1585175964165633"><a name="p1585175964165633"></a><a name="p1585175964165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1305525184165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1577394439165633"><a name="p1577394439165633"></a><a name="p1577394439165633"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p911993100165633"><a name="p911993100165633"></a><a name="p911993100165633"></a>virtual void </p>
<p id="p2009958329165633"><a name="p2009958329165633"></a><a name="p2009958329165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1650897471165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p488513048165633"><a name="p488513048165633"></a><a name="p488513048165633"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078375812165633"><a name="p1078375812165633"></a><a name="p1078375812165633"></a>void </p>
<p id="p65511115165633"><a name="p65511115165633"></a><a name="p65511115165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row625718926165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065115121165633"><a name="p1065115121165633"></a><a name="p1065115121165633"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575262064165633"><a name="p575262064165633"></a><a name="p575262064165633"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p1958718887165633"><a name="p1958718887165633"></a><a name="p1958718887165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1795238346165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1879801135165633"><a name="p1879801135165633"></a><a name="p1879801135165633"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021269944165633"><a name="p2021269944165633"></a><a name="p2021269944165633"></a>void </p>
<p id="p1359705760165633"><a name="p1359705760165633"></a><a name="p1359705760165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row911739524165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355362574165633"><a name="p1355362574165633"></a><a name="p1355362574165633"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p863171347165633"><a name="p863171347165633"></a><a name="p863171347165633"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1425475299165633"><a name="p1425475299165633"></a><a name="p1425475299165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row71147240165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41196971165633"><a name="p41196971165633"></a><a name="p41196971165633"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p50556240165633"><a name="p50556240165633"></a><a name="p50556240165633"></a>void </p>
<p id="p1556425750165633"><a name="p1556425750165633"></a><a name="p1556425750165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1498782637165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425715777165633"><a name="p425715777165633"></a><a name="p425715777165633"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p521179600165633"><a name="p521179600165633"></a><a name="p521179600165633"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p88395358165633"><a name="p88395358165633"></a><a name="p88395358165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row844517306165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p599868036165633"><a name="p599868036165633"></a><a name="p599868036165633"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p317152826165633"><a name="p317152826165633"></a><a name="p317152826165633"></a>void </p>
<p id="p1398485535165633"><a name="p1398485535165633"></a><a name="p1398485535165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row940154568165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771177556165633"><a name="p1771177556165633"></a><a name="p1771177556165633"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4738557165633"><a name="p4738557165633"></a><a name="p4738557165633"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p583067509165633"><a name="p583067509165633"></a><a name="p583067509165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1282546879165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894345798165633"><a name="p894345798165633"></a><a name="p894345798165633"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316427051165633"><a name="p1316427051165633"></a><a name="p1316427051165633"></a>void </p>
<p id="p117660104165633"><a name="p117660104165633"></a><a name="p117660104165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row193278603165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1866261286165633"><a name="p1866261286165633"></a><a name="p1866261286165633"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590504179165633"><a name="p590504179165633"></a><a name="p590504179165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p683877044165633"><a name="p683877044165633"></a><a name="p683877044165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row726112892165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900480088165633"><a name="p900480088165633"></a><a name="p900480088165633"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910208053165633"><a name="p1910208053165633"></a><a name="p1910208053165633"></a>void </p>
<p id="p92086462165633"><a name="p92086462165633"></a><a name="p92086462165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row657761420165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1597681083165633"><a name="p1597681083165633"></a><a name="p1597681083165633"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663712969165633"><a name="p663712969165633"></a><a name="p663712969165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p317380538165633"><a name="p317380538165633"></a><a name="p317380538165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row407684813165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1814849609165633"><a name="p1814849609165633"></a><a name="p1814849609165633"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1152205124165633"><a name="p1152205124165633"></a><a name="p1152205124165633"></a>virtual void </p>
<p id="p519011430165633"><a name="p519011430165633"></a><a name="p519011430165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row450291073165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996478365165633"><a name="p996478365165633"></a><a name="p996478365165633"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000777188165633"><a name="p2000777188165633"></a><a name="p2000777188165633"></a>bool </p>
<p id="p1375151892165633"><a name="p1375151892165633"></a><a name="p1375151892165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1493693583165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757996684165633"><a name="p757996684165633"></a><a name="p757996684165633"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1164839562165633"><a name="p1164839562165633"></a><a name="p1164839562165633"></a>void </p>
<p id="p1348361313165633"><a name="p1348361313165633"></a><a name="p1348361313165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row176904659165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1042456458165633"><a name="p1042456458165633"></a><a name="p1042456458165633"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2008305683165633"><a name="p2008305683165633"></a><a name="p2008305683165633"></a>bool </p>
<p id="p423739464165633"><a name="p423739464165633"></a><a name="p423739464165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row246850358165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839137324165633"><a name="p1839137324165633"></a><a name="p1839137324165633"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660089217165633"><a name="p1660089217165633"></a><a name="p1660089217165633"></a>void </p>
<p id="p317677430165633"><a name="p317677430165633"></a><a name="p317677430165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row658825073165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p713775961165633"><a name="p713775961165633"></a><a name="p713775961165633"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2017458458165633"><a name="p2017458458165633"></a><a name="p2017458458165633"></a>bool </p>
<p id="p1614214012165633"><a name="p1614214012165633"></a><a name="p1614214012165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row65261042165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411376887165633"><a name="p411376887165633"></a><a name="p411376887165633"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p465088597165633"><a name="p465088597165633"></a><a name="p465088597165633"></a>void </p>
<p id="p403412587165633"><a name="p403412587165633"></a><a name="p403412587165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1883746199165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1222291896165633"><a name="p1222291896165633"></a><a name="p1222291896165633"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p858337746165633"><a name="p858337746165633"></a><a name="p858337746165633"></a>bool </p>
<p id="p1236045716165633"><a name="p1236045716165633"></a><a name="p1236045716165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1525363358165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1090447033165633"><a name="p1090447033165633"></a><a name="p1090447033165633"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885667810165633"><a name="p885667810165633"></a><a name="p885667810165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1125877950165633"><a name="p1125877950165633"></a><a name="p1125877950165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row971898075165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1579853097165633"><a name="p1579853097165633"></a><a name="p1579853097165633"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669931651165633"><a name="p1669931651165633"></a><a name="p1669931651165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1423590660165633"><a name="p1423590660165633"></a><a name="p1423590660165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row916681587165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557845949165633"><a name="p557845949165633"></a><a name="p557845949165633"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1094833467165633"><a name="p1094833467165633"></a><a name="p1094833467165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1911327082165633"><a name="p1911327082165633"></a><a name="p1911327082165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row717671711165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510370132165633"><a name="p1510370132165633"></a><a name="p1510370132165633"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282531518165633"><a name="p282531518165633"></a><a name="p282531518165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1803269525165633"><a name="p1803269525165633"></a><a name="p1803269525165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row308207948165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1854484440165633"><a name="p1854484440165633"></a><a name="p1854484440165633"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1146312646165633"><a name="p1146312646165633"></a><a name="p1146312646165633"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p2129059476165633"><a name="p2129059476165633"></a><a name="p2129059476165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row510305061165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p196529110165633"><a name="p196529110165633"></a><a name="p196529110165633"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114631472165633"><a name="p114631472165633"></a><a name="p114631472165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p960578458165633"><a name="p960578458165633"></a><a name="p960578458165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1002807874165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p259554986165633"><a name="p259554986165633"></a><a name="p259554986165633"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59576644165633"><a name="p59576644165633"></a><a name="p59576644165633"></a>void </p>
<p id="p973949891165633"><a name="p973949891165633"></a><a name="p973949891165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1776304909165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1783967749165633"><a name="p1783967749165633"></a><a name="p1783967749165633"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717937494165633"><a name="p717937494165633"></a><a name="p717937494165633"></a>virtual int16_t </p>
<p id="p954418580165633"><a name="p954418580165633"></a><a name="p954418580165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1410289851165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887032341165633"><a name="p887032341165633"></a><a name="p887032341165633"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707175533165633"><a name="p707175533165633"></a><a name="p707175533165633"></a>virtual int16_t </p>
<p id="p763516762165633"><a name="p763516762165633"></a><a name="p763516762165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row617457907165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904275003165633"><a name="p1904275003165633"></a><a name="p1904275003165633"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117475952165633"><a name="p2117475952165633"></a><a name="p2117475952165633"></a>virtual void </p>
<p id="p456100177165633"><a name="p456100177165633"></a><a name="p456100177165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1754318781165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732641276165633"><a name="p1732641276165633"></a><a name="p1732641276165633"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p71619327165633"><a name="p71619327165633"></a><a name="p71619327165633"></a>virtual void </p>
<p id="p1994917953165633"><a name="p1994917953165633"></a><a name="p1994917953165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1972453233165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440176997165633"><a name="p1440176997165633"></a><a name="p1440176997165633"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p162672753165633"><a name="p162672753165633"></a><a name="p162672753165633"></a>int16_t </p>
<p id="p1478497629165633"><a name="p1478497629165633"></a><a name="p1478497629165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row232314864165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1723366429165633"><a name="p1723366429165633"></a><a name="p1723366429165633"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p341181377165633"><a name="p341181377165633"></a><a name="p341181377165633"></a>virtual void </p>
<p id="p1191090928165633"><a name="p1191090928165633"></a><a name="p1191090928165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1008525448165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p769315324165633"><a name="p769315324165633"></a><a name="p769315324165633"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p530238649165633"><a name="p530238649165633"></a><a name="p530238649165633"></a>int16_t </p>
<p id="p2041729871165633"><a name="p2041729871165633"></a><a name="p2041729871165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row129971144165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984272079165633"><a name="p984272079165633"></a><a name="p984272079165633"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2015144122165633"><a name="p2015144122165633"></a><a name="p2015144122165633"></a>virtual void </p>
<p id="p852229243165633"><a name="p852229243165633"></a><a name="p852229243165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1097629063165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1626951837165633"><a name="p1626951837165633"></a><a name="p1626951837165633"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809285724165633"><a name="p1809285724165633"></a><a name="p1809285724165633"></a>virtual void </p>
<p id="p1091376106165633"><a name="p1091376106165633"></a><a name="p1091376106165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1857095919165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p961776214165633"><a name="p961776214165633"></a><a name="p961776214165633"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p244276239165633"><a name="p244276239165633"></a><a name="p244276239165633"></a>bool </p>
<p id="p1930233581165633"><a name="p1930233581165633"></a><a name="p1930233581165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row515922570165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p619997514165633"><a name="p619997514165633"></a><a name="p619997514165633"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502521753165633"><a name="p1502521753165633"></a><a name="p1502521753165633"></a>void </p>
<p id="p1579538901165633"><a name="p1579538901165633"></a><a name="p1579538901165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row550791097165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1782441723165633"><a name="p1782441723165633"></a><a name="p1782441723165633"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787895171165633"><a name="p1787895171165633"></a><a name="p1787895171165633"></a>void </p>
<p id="p1523212944165633"><a name="p1523212944165633"></a><a name="p1523212944165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row265216703165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957126452165633"><a name="p1957126452165633"></a><a name="p1957126452165633"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p284883759165633"><a name="p284883759165633"></a><a name="p284883759165633"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p240582516165633"><a name="p240582516165633"></a><a name="p240582516165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1814742429165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p733263459165633"><a name="p733263459165633"></a><a name="p733263459165633"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272671533165633"><a name="p1272671533165633"></a><a name="p1272671533165633"></a>void </p>
<p id="p1587966507165633"><a name="p1587966507165633"></a><a name="p1587966507165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1328425088165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812837161165633"><a name="p812837161165633"></a><a name="p812837161165633"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071420062165633"><a name="p1071420062165633"></a><a name="p1071420062165633"></a>const char * </p>
<p id="p1398265338165633"><a name="p1398265338165633"></a><a name="p1398265338165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row201343967165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1213468710165633"><a name="p1213468710165633"></a><a name="p1213468710165633"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142864879165633"><a name="p1142864879165633"></a><a name="p1142864879165633"></a>void </p>
<p id="p1417330997165633"><a name="p1417330997165633"></a><a name="p1417330997165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row7887465165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1338159062165633"><a name="p1338159062165633"></a><a name="p1338159062165633"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427684032165633"><a name="p427684032165633"></a><a name="p427684032165633"></a>int16_t </p>
<p id="p1504858768165633"><a name="p1504858768165633"></a><a name="p1504858768165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1650594358165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1646966307165633"><a name="p1646966307165633"></a><a name="p1646966307165633"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025246416165633"><a name="p2025246416165633"></a><a name="p2025246416165633"></a>virtual void </p>
<p id="p416737322165633"><a name="p416737322165633"></a><a name="p416737322165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row947546221165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560632231165633"><a name="p1560632231165633"></a><a name="p1560632231165633"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178559259165633"><a name="p178559259165633"></a><a name="p178559259165633"></a>void </p>
<p id="p724913849165633"><a name="p724913849165633"></a><a name="p724913849165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1464022581165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p57873001165633"><a name="p57873001165633"></a><a name="p57873001165633"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330673177165633"><a name="p1330673177165633"></a><a name="p1330673177165633"></a>void </p>
<p id="p1778257153165633"><a name="p1778257153165633"></a><a name="p1778257153165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row336497024165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p615551226165633"><a name="p615551226165633"></a><a name="p615551226165633"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836554347165633"><a name="p1836554347165633"></a><a name="p1836554347165633"></a>void </p>
<p id="p1789831253165633"><a name="p1789831253165633"></a><a name="p1789831253165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1395473488165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1739368867165633"><a name="p1739368867165633"></a><a name="p1739368867165633"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p901095075165633"><a name="p901095075165633"></a><a name="p901095075165633"></a>void </p>
<p id="p1722227005165633"><a name="p1722227005165633"></a><a name="p1722227005165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row228338841165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1369252607165633"><a name="p1369252607165633"></a><a name="p1369252607165633"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p626234994165633"><a name="p626234994165633"></a><a name="p626234994165633"></a>void </p>
<p id="p233710332165633"><a name="p233710332165633"></a><a name="p233710332165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row64515232165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p184274835165633"><a name="p184274835165633"></a><a name="p184274835165633"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290012963165633"><a name="p290012963165633"></a><a name="p290012963165633"></a>void </p>
<p id="p1917194545165633"><a name="p1917194545165633"></a><a name="p1917194545165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row365508210165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217429902165633"><a name="p1217429902165633"></a><a name="p1217429902165633"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320242137165633"><a name="p1320242137165633"></a><a name="p1320242137165633"></a>void </p>
<p id="p2090453057165633"><a name="p2090453057165633"></a><a name="p2090453057165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row499552799165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956241369165633"><a name="p1956241369165633"></a><a name="p1956241369165633"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p443147055165633"><a name="p443147055165633"></a><a name="p443147055165633"></a>void </p>
<p id="p2104931693165633"><a name="p2104931693165633"></a><a name="p2104931693165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1159063278165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1169208030165633"><a name="p1169208030165633"></a><a name="p1169208030165633"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523205471165633"><a name="p1523205471165633"></a><a name="p1523205471165633"></a>void </p>
<p id="p609584741165633"><a name="p609584741165633"></a><a name="p609584741165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row193463312165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111636931165633"><a name="p111636931165633"></a><a name="p111636931165633"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1724802805165633"><a name="p1724802805165633"></a><a name="p1724802805165633"></a>void </p>
<p id="p1083431818165633"><a name="p1083431818165633"></a><a name="p1083431818165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1787703855165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1225650156165633"><a name="p1225650156165633"></a><a name="p1225650156165633"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1931953690165633"><a name="p1931953690165633"></a><a name="p1931953690165633"></a>void </p>
<p id="p363872739165633"><a name="p363872739165633"></a><a name="p363872739165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row473857763165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943014546165633"><a name="p1943014546165633"></a><a name="p1943014546165633"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1522890111165633"><a name="p1522890111165633"></a><a name="p1522890111165633"></a>void </p>
<p id="p153970613165633"><a name="p153970613165633"></a><a name="p153970613165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row2145208831165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1232418748165633"><a name="p1232418748165633"></a><a name="p1232418748165633"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1956404602165633"><a name="p1956404602165633"></a><a name="p1956404602165633"></a>void </p>
<p id="p360699139165633"><a name="p360699139165633"></a><a name="p360699139165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row696378646165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535130654165633"><a name="p1535130654165633"></a><a name="p1535130654165633"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383716407165633"><a name="p1383716407165633"></a><a name="p1383716407165633"></a>void </p>
<p id="p1523458981165633"><a name="p1523458981165633"></a><a name="p1523458981165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row50678951165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p935203484165633"><a name="p935203484165633"></a><a name="p935203484165633"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050613550165633"><a name="p2050613550165633"></a><a name="p2050613550165633"></a>void </p>
<p id="p1478832949165633"><a name="p1478832949165633"></a><a name="p1478832949165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row515750312165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p854823880165633"><a name="p854823880165633"></a><a name="p854823880165633"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1683604030165633"><a name="p1683604030165633"></a><a name="p1683604030165633"></a>void </p>
<p id="p1537992247165633"><a name="p1537992247165633"></a><a name="p1537992247165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row303494496165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337530741165633"><a name="p337530741165633"></a><a name="p337530741165633"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2029269635165633"><a name="p2029269635165633"></a><a name="p2029269635165633"></a>virtual void </p>
<p id="p226484337165633"><a name="p226484337165633"></a><a name="p226484337165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row455906500165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569558042165633"><a name="p1569558042165633"></a><a name="p1569558042165633"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1360402248165633"><a name="p1360402248165633"></a><a name="p1360402248165633"></a>virtual int64_t </p>
<p id="p427832032165633"><a name="p427832032165633"></a><a name="p427832032165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row803211408165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949684942165633"><a name="p949684942165633"></a><a name="p949684942165633"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687808317165633"><a name="p1687808317165633"></a><a name="p1687808317165633"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p2016061208165633"><a name="p2016061208165633"></a><a name="p2016061208165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1546507379165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167540119165633"><a name="p1167540119165633"></a><a name="p1167540119165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p269109942165633"><a name="p269109942165633"></a><a name="p269109942165633"></a>void * </p>
<p id="p1465885377165633"><a name="p1465885377165633"></a><a name="p1465885377165633"></a>Overrides the <strong id="b1781545977165633"><a name="b1781545977165633"></a><a name="b1781545977165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1042414414165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847661056165633"><a name="p847661056165633"></a><a name="p847661056165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190431177165633"><a name="p190431177165633"></a><a name="p190431177165633"></a>void </p>
<p id="p729292259165633"><a name="p729292259165633"></a><a name="p729292259165633"></a>Overrides the <strong id="b996889299165633"><a name="b996889299165633"></a><a name="b996889299165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1363799064165633"></a>
<table><thead align="left"><tr id="row1129875748165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p138407139165633"><a name="p138407139165633"></a><a name="p138407139165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p149949044165633"><a name="p149949044165633"></a><a name="p149949044165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1306913001165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1193859840165633"><a name="p1193859840165633"></a><a name="p1193859840165633"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137127891165633"><a name="p2137127891165633"></a><a name="p2137127891165633"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row146419909165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816458848165633"><a name="p1816458848165633"></a><a name="p1816458848165633"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735191730165633"><a name="p735191730165633"></a><a name="p735191730165633"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1229930378165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393953349165633"><a name="p393953349165633"></a><a name="p393953349165633"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948480942165633"><a name="p1948480942165633"></a><a name="p1948480942165633"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1518104990165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p932514622165633"><a name="p932514622165633"></a><a name="p932514622165633"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2042851337165633"><a name="p2042851337165633"></a><a name="p2042851337165633"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row190029532165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p224266973165633"><a name="p224266973165633"></a><a name="p224266973165633"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133429657165633"><a name="p1133429657165633"></a><a name="p1133429657165633"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1121818686165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278262734165633"><a name="p278262734165633"></a><a name="p278262734165633"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611597595165633"><a name="p1611597595165633"></a><a name="p1611597595165633"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1575351909165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1188535423165633"><a name="p1188535423165633"></a><a name="p1188535423165633"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166390575165633"><a name="p166390575165633"></a><a name="p166390575165633"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1606533309165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1475662255165633"><a name="p1475662255165633"></a><a name="p1475662255165633"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763107937165633"><a name="p1763107937165633"></a><a name="p1763107937165633"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

