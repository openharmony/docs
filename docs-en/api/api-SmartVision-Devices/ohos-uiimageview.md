# OHOS::UIImageView<a name="EN-US_TOPIC_0000001054718151"></a>

-   [Overview](#section1553377739165634)
-   [Summary](#section1768561066165634)
-   [Public Member Functions](#pub-methods)
-   [Protected Attributes](#pro-attribs)

## **Overview**<a name="section1553377739165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the functions related to an image view. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1768561066165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table784039174165634"></a>
<table><thead align="left"><tr id="row123966858165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p231205601165634"><a name="p231205601165634"></a><a name="p231205601165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p213735917165634"><a name="p213735917165634"></a><a name="p213735917165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row92902641165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613836132165634"><a name="p613836132165634"></a><a name="p613836132165634"></a><a href="graphic.md#ga3db47186dbc7a0cb996c23abcdaf2c38">UIImageView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010283329165634"><a name="p2010283329165634"></a><a name="p2010283329165634"></a> </p>
<p id="p511854919165634"><a name="p511854919165634"></a><a name="p511854919165634"></a>A default constructor used to create a <strong id="b1852224833165634"><a name="b1852224833165634"></a><a name="b1852224833165634"></a><a href="ohos-uiimageview.md">UIImageView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1271765041165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1646853479165634"><a name="p1646853479165634"></a><a name="p1646853479165634"></a><a href="graphic.md#ga8be6fe17af73ab21f97effa26dbacaca">~UIImageView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852545867165634"><a name="p1852545867165634"></a><a name="p1852545867165634"></a>virtual </p>
<p id="p548804517165634"><a name="p548804517165634"></a><a name="p548804517165634"></a>A destructor used to delete the <strong id="b1256927516165634"><a name="b1256927516165634"></a><a name="b1256927516165634"></a><a href="ohos-uiimageview.md">UIImageView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1422158068165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501211111165634"><a name="p501211111165634"></a><a name="p501211111165634"></a><a href="graphic.md#ga5dc99855271c582e960e0952cca8227c">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304836864165634"><a name="p1304836864165634"></a><a name="p1304836864165634"></a>UIViewType </p>
<p id="p552336294165634"><a name="p552336294165634"></a><a name="p552336294165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row62222075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1430265137165634"><a name="p1430265137165634"></a><a name="p1430265137165634"></a><a href="graphic.md#ga20ea7dd2d8ddb16cf9750ccdcc2a2803">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p133176582165634"><a name="p133176582165634"></a><a name="p133176582165634"></a>int16_t </p>
<p id="p1202502824165634"><a name="p1202502824165634"></a><a name="p1202502824165634"></a>Obtains the width of this image view. </p>
</td>
</tr>
<tr id="row1089280063165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p78063296165634"><a name="p78063296165634"></a><a name="p78063296165634"></a><a href="graphic.md#gaddc6e68c67782eaad40977c6c2256cdd">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p937223928165634"><a name="p937223928165634"></a><a name="p937223928165634"></a>int16_t </p>
<p id="p1438206139165634"><a name="p1438206139165634"></a><a name="p1438206139165634"></a>Obtains the height of this image view. </p>
</td>
</tr>
<tr id="row54931720165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697015503165634"><a name="p1697015503165634"></a><a name="p1697015503165634"></a><a href="graphic.md#ga5d79816831f61406c1c8bd300da9973e">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301253280165634"><a name="p1301253280165634"></a><a name="p1301253280165634"></a>bool </p>
<p id="p145722927165634"><a name="p145722927165634"></a><a name="p145722927165634"></a>Checks whether this image view needs to be covered to optimize the drawing process. </p>
</td>
</tr>
<tr id="row217000303165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697564616165634"><a name="p1697564616165634"></a><a name="p1697564616165634"></a><a href="graphic.md#ga565cecb8ac66f2009dc4783da9bdc699">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734188872165634"><a name="p1734188872165634"></a><a name="p1734188872165634"></a>void </p>
<p id="p100827511165634"><a name="p100827511165634"></a><a name="p100827511165634"></a>Draws this image view. </p>
</td>
</tr>
<tr id="row386354570165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223262951165634"><a name="p1223262951165634"></a><a name="p1223262951165634"></a><a href="graphic.md#ga4e2dac4fd52a54a828f13db5ab51d110">SetSrc</a> (const char *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043190345165634"><a name="p2043190345165634"></a><a name="p2043190345165634"></a>void </p>
<p id="p598167619165634"><a name="p598167619165634"></a><a name="p598167619165634"></a>Sets the image path. </p>
</td>
</tr>
<tr id="row518651985165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p292517571165634"><a name="p292517571165634"></a><a name="p292517571165634"></a><a href="graphic.md#ga18a9eed434132ac60c127ca1fc03e663">SetSrc</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *src)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676757862165634"><a name="p1676757862165634"></a><a name="p1676757862165634"></a>void </p>
<p id="p1304027849165634"><a name="p1304027849165634"></a><a name="p1304027849165634"></a>Sets the image information. </p>
</td>
</tr>
<tr id="row1609857418165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578470597165634"><a name="p1578470597165634"></a><a name="p1578470597165634"></a><a href="graphic.md#gab3f60d7eff9b467c64edc90293dbb21d">SetAutoEnable</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1306107077165634"><a name="p1306107077165634"></a><a name="p1306107077165634"></a>void </p>
<p id="p1489626493165634"><a name="p1489626493165634"></a><a name="p1489626493165634"></a>Sets whether the image view size needs to be adaptive to the image size. </p>
</td>
</tr>
<tr id="row1646668778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p338216090165634"><a name="p338216090165634"></a><a name="p338216090165634"></a><a href="graphic.md#ga339c80c2f8f05ff0d79638dc61c71d5a">SetBlurLevel</a> (BlurLevel level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1703618830165634"><a name="p1703618830165634"></a><a name="p1703618830165634"></a>void </p>
<p id="p1386697612165634"><a name="p1386697612165634"></a><a name="p1386697612165634"></a>Sets the blur level for this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row1152245246165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126607197165634"><a name="p2126607197165634"></a><a name="p2126607197165634"></a><a href="graphic.md#ga8c891ce7719b97f6d49b0554caa371cb">GetBlurLevel</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068942767165634"><a name="p1068942767165634"></a><a name="p1068942767165634"></a>BlurLevel </p>
<p id="p1269860766165634"><a name="p1269860766165634"></a><a name="p1269860766165634"></a>Obtains the blur level of this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row760030835165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1052821299165634"><a name="p1052821299165634"></a><a name="p1052821299165634"></a><a href="graphic.md#gacd3bafd7cd7dfb83d46d4fae36eae612">SetTransformAlgorithm</a> (TransformAlgorithm algorithm)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p816306956165634"><a name="p816306956165634"></a><a name="p816306956165634"></a>void </p>
<p id="p665729844165634"><a name="p665729844165634"></a><a name="p665729844165634"></a>Sets the algorithm used for image rotation and scaling. </p>
</td>
</tr>
<tr id="row1549207448165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p223586558165634"><a name="p223586558165634"></a><a name="p223586558165634"></a><a href="graphic.md#gac7b75c6fa653d3ac0c8bc9062939d293">GetTransformAlgorithm</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868551621165634"><a name="p1868551621165634"></a><a name="p1868551621165634"></a>TransformAlgorithm </p>
<p id="p934041472165634"><a name="p934041472165634"></a><a name="p934041472165634"></a>Obtains the algorithm used for image rotation and scaling. </p>
</td>
</tr>
<tr id="row1861861919165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49638718165634"><a name="p49638718165634"></a><a name="p49638718165634"></a><a href="graphic.md#ga3824befafd4f4dda003195ca2bbef399">GetPath</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1198464605165634"><a name="p1198464605165634"></a><a name="p1198464605165634"></a>const char * </p>
<p id="p649949078165634"><a name="p649949078165634"></a><a name="p649949078165634"></a>Obtains the image path.</p>
</td>
</tr>
<tr id="row1008344450165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354904707165634"><a name="p1354904707165634"></a><a name="p1354904707165634"></a><a href="graphic.md#gaa9fbde27be3e3ea2fc6b4dabbf588af8">GetImageInfo</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76776191165634"><a name="p76776191165634"></a><a name="p76776191165634"></a>const <a href="ohos-imageinfo.md">ImageInfo</a> * </p>
<p id="p1745361901165634"><a name="p1745361901165634"></a><a name="p1745361901165634"></a>Obtains image information.</p>
</td>
</tr>
<tr id="row378883251165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p317167179165634"><a name="p317167179165634"></a><a name="p317167179165634"></a><a href="graphic.md#ga07da08c8507a3dbee5c21ea0de170a16">GetSrcType</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p139533050165634"><a name="p139533050165634"></a><a name="p139533050165634"></a>uint8_t </p>
<p id="p235813517165634"><a name="p235813517165634"></a><a name="p235813517165634"></a>Obtains the image type.</p>
</td>
</tr>
<tr id="row1690459121165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p776736281165634"><a name="p776736281165634"></a><a name="p776736281165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333482311165634"><a name="p333482311165634"></a><a name="p333482311165634"></a> </p>
<p id="p347668666165634"><a name="p347668666165634"></a><a name="p347668666165634"></a>A default constructor used to create an <strong id="b696603410165634"><a name="b696603410165634"></a><a name="b696603410165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1228105822165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369450278165634"><a name="p369450278165634"></a><a name="p369450278165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724380571165634"><a name="p724380571165634"></a><a name="p724380571165634"></a> </p>
<p id="p348264535165634"><a name="p348264535165634"></a><a name="p348264535165634"></a>A constructor used to create an <strong id="b580213106165634"><a name="b580213106165634"></a><a name="b580213106165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1318599516165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873688076165634"><a name="p1873688076165634"></a><a name="p1873688076165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301257672165634"><a name="p1301257672165634"></a><a name="p1301257672165634"></a>virtual </p>
<p id="p1894708825165634"><a name="p1894708825165634"></a><a name="p1894708825165634"></a>A destructor used to delete the <strong id="b1260006966165634"><a name="b1260006966165634"></a><a name="b1260006966165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1707393268165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p965109004165634"><a name="p965109004165634"></a><a name="p965109004165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2078997413165634"><a name="p2078997413165634"></a><a name="p2078997413165634"></a>virtual void </p>
<p id="p1469564977165634"><a name="p1469564977165634"></a><a name="p1469564977165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1340721575165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p179085356165634"><a name="p179085356165634"></a><a name="p179085356165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p412341348165634"><a name="p412341348165634"></a><a name="p412341348165634"></a>void </p>
<p id="p586153528165634"><a name="p586153528165634"></a><a name="p586153528165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1028020343165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p923819249165634"><a name="p923819249165634"></a><a name="p923819249165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59535006165634"><a name="p59535006165634"></a><a name="p59535006165634"></a>void </p>
<p id="p730121217165634"><a name="p730121217165634"></a><a name="p730121217165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row469149848165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208829660165634"><a name="p1208829660165634"></a><a name="p1208829660165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p956646573165634"><a name="p956646573165634"></a><a name="p956646573165634"></a>virtual bool </p>
<p id="p1779739653165634"><a name="p1779739653165634"></a><a name="p1779739653165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1508111293165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337320857165634"><a name="p337320857165634"></a><a name="p337320857165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p120907399165634"><a name="p120907399165634"></a><a name="p120907399165634"></a>virtual bool </p>
<p id="p745787100165634"><a name="p745787100165634"></a><a name="p745787100165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1573730131165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735379452165634"><a name="p735379452165634"></a><a name="p735379452165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511818268165634"><a name="p1511818268165634"></a><a name="p1511818268165634"></a>virtual bool </p>
<p id="p948951604165634"><a name="p948951604165634"></a><a name="p948951604165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row734671263165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1442454366165634"><a name="p1442454366165634"></a><a name="p1442454366165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p981308183165634"><a name="p981308183165634"></a><a name="p981308183165634"></a>virtual bool </p>
<p id="p131302659165634"><a name="p131302659165634"></a><a name="p131302659165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row282235083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p730799835165634"><a name="p730799835165634"></a><a name="p730799835165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169522537165634"><a name="p169522537165634"></a><a name="p169522537165634"></a>virtual void </p>
<p id="p1664412416165634"><a name="p1664412416165634"></a><a name="p1664412416165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1278639949165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1430202294165634"><a name="p1430202294165634"></a><a name="p1430202294165634"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920631689165634"><a name="p920631689165634"></a><a name="p920631689165634"></a>virtual void </p>
<p id="p1916188422165634"><a name="p1916188422165634"></a><a name="p1916188422165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1155652975165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1181038558165634"><a name="p1181038558165634"></a><a name="p1181038558165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p548253077165634"><a name="p548253077165634"></a><a name="p548253077165634"></a>virtual void </p>
<p id="p408997105165634"><a name="p408997105165634"></a><a name="p408997105165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row2122909306165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641592514165634"><a name="p1641592514165634"></a><a name="p1641592514165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p241486273165634"><a name="p241486273165634"></a><a name="p241486273165634"></a>virtual void </p>
<p id="p1166302952165634"><a name="p1166302952165634"></a><a name="p1166302952165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row951359042165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1827929806165634"><a name="p1827929806165634"></a><a name="p1827929806165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413549465165634"><a name="p413549465165634"></a><a name="p413549465165634"></a>void </p>
<p id="p907651735165634"><a name="p907651735165634"></a><a name="p907651735165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row2091145945165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587385633165634"><a name="p587385633165634"></a><a name="p587385633165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1277953710165634"><a name="p1277953710165634"></a><a name="p1277953710165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p736975343165634"><a name="p736975343165634"></a><a name="p736975343165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row748217772165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657346245165634"><a name="p657346245165634"></a><a name="p657346245165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p463712172165634"><a name="p463712172165634"></a><a name="p463712172165634"></a>void </p>
<p id="p1744369171165634"><a name="p1744369171165634"></a><a name="p1744369171165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1838450475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584398164165634"><a name="p1584398164165634"></a><a name="p1584398164165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122397624165634"><a name="p122397624165634"></a><a name="p122397624165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1498593153165634"><a name="p1498593153165634"></a><a name="p1498593153165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1650412077165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p790828495165634"><a name="p790828495165634"></a><a name="p790828495165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231356174165634"><a name="p1231356174165634"></a><a name="p1231356174165634"></a>void </p>
<p id="p8902862165634"><a name="p8902862165634"></a><a name="p8902862165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1217678442165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916829390165634"><a name="p916829390165634"></a><a name="p916829390165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1349572629165634"><a name="p1349572629165634"></a><a name="p1349572629165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1171602632165634"><a name="p1171602632165634"></a><a name="p1171602632165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row629022351165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p10514131165634"><a name="p10514131165634"></a><a name="p10514131165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546014387165634"><a name="p1546014387165634"></a><a name="p1546014387165634"></a>void </p>
<p id="p1920901428165634"><a name="p1920901428165634"></a><a name="p1920901428165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1772577035165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1925904765165634"><a name="p1925904765165634"></a><a name="p1925904765165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1960863198165634"><a name="p1960863198165634"></a><a name="p1960863198165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p1436269603165634"><a name="p1436269603165634"></a><a name="p1436269603165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1753895337165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2050792428165634"><a name="p2050792428165634"></a><a name="p2050792428165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p218756165165634"><a name="p218756165165634"></a><a name="p218756165165634"></a>virtual void </p>
<p id="p504598691165634"><a name="p504598691165634"></a><a name="p504598691165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1947583768165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478692978165634"><a name="p1478692978165634"></a><a name="p1478692978165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368288391165634"><a name="p1368288391165634"></a><a name="p1368288391165634"></a>void </p>
<p id="p1091542724165634"><a name="p1091542724165634"></a><a name="p1091542724165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row60624577165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1946236755165634"><a name="p1946236755165634"></a><a name="p1946236755165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969955922165634"><a name="p969955922165634"></a><a name="p969955922165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p374223569165634"><a name="p374223569165634"></a><a name="p374223569165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row272482406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1696104446165634"><a name="p1696104446165634"></a><a name="p1696104446165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6844776165634"><a name="p6844776165634"></a><a name="p6844776165634"></a>void </p>
<p id="p881970216165634"><a name="p881970216165634"></a><a name="p881970216165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row190310159165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1531526391165634"><a name="p1531526391165634"></a><a name="p1531526391165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927819398165634"><a name="p927819398165634"></a><a name="p927819398165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p856909133165634"><a name="p856909133165634"></a><a name="p856909133165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row990528075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1321959237165634"><a name="p1321959237165634"></a><a name="p1321959237165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1531418019165634"><a name="p1531418019165634"></a><a name="p1531418019165634"></a>virtual void </p>
<p id="p1830666650165634"><a name="p1830666650165634"></a><a name="p1830666650165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row909623757165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p199483580165634"><a name="p199483580165634"></a><a name="p199483580165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1180877729165634"><a name="p1180877729165634"></a><a name="p1180877729165634"></a>bool </p>
<p id="p1072657602165634"><a name="p1072657602165634"></a><a name="p1072657602165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1138047797165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716199926165634"><a name="p1716199926165634"></a><a name="p1716199926165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978160017165634"><a name="p978160017165634"></a><a name="p978160017165634"></a>void </p>
<p id="p240127830165634"><a name="p240127830165634"></a><a name="p240127830165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row256748012165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p682134185165634"><a name="p682134185165634"></a><a name="p682134185165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p709635975165634"><a name="p709635975165634"></a><a name="p709635975165634"></a>bool </p>
<p id="p1517613072165634"><a name="p1517613072165634"></a><a name="p1517613072165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row650533293165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107613885165634"><a name="p1107613885165634"></a><a name="p1107613885165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064546163165634"><a name="p1064546163165634"></a><a name="p1064546163165634"></a>void </p>
<p id="p1703207415165634"><a name="p1703207415165634"></a><a name="p1703207415165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1706538434165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2068483761165634"><a name="p2068483761165634"></a><a name="p2068483761165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766351659165634"><a name="p766351659165634"></a><a name="p766351659165634"></a>bool </p>
<p id="p1098419995165634"><a name="p1098419995165634"></a><a name="p1098419995165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1042107407165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1813730093165634"><a name="p1813730093165634"></a><a name="p1813730093165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652205269165634"><a name="p652205269165634"></a><a name="p652205269165634"></a>void </p>
<p id="p1368358122165634"><a name="p1368358122165634"></a><a name="p1368358122165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row2051465258165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1769810352165634"><a name="p1769810352165634"></a><a name="p1769810352165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p760966876165634"><a name="p760966876165634"></a><a name="p760966876165634"></a>bool </p>
<p id="p1859855966165634"><a name="p1859855966165634"></a><a name="p1859855966165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1801472395165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718365428165634"><a name="p1718365428165634"></a><a name="p1718365428165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508669073165634"><a name="p1508669073165634"></a><a name="p1508669073165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p307860822165634"><a name="p307860822165634"></a><a name="p307860822165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1923301823165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1576387995165634"><a name="p1576387995165634"></a><a name="p1576387995165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1049366847165634"><a name="p1049366847165634"></a><a name="p1049366847165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p685404048165634"><a name="p685404048165634"></a><a name="p685404048165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row44300965165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65662003165634"><a name="p65662003165634"></a><a name="p65662003165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034220016165634"><a name="p1034220016165634"></a><a name="p1034220016165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p357995259165634"><a name="p357995259165634"></a><a name="p357995259165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row175555854165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445422179165634"><a name="p445422179165634"></a><a name="p445422179165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482010165165634"><a name="p482010165165634"></a><a name="p482010165165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p35453805165634"><a name="p35453805165634"></a><a name="p35453805165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1092430920165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p208819679165634"><a name="p208819679165634"></a><a name="p208819679165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1027320507165634"><a name="p1027320507165634"></a><a name="p1027320507165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p79126520165634"><a name="p79126520165634"></a><a name="p79126520165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row2034811185165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548246288165634"><a name="p1548246288165634"></a><a name="p1548246288165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435640345165634"><a name="p435640345165634"></a><a name="p435640345165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p595490763165634"><a name="p595490763165634"></a><a name="p595490763165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1815421616165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780156404165634"><a name="p1780156404165634"></a><a name="p1780156404165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672000402165634"><a name="p1672000402165634"></a><a name="p1672000402165634"></a>void </p>
<p id="p573285588165634"><a name="p573285588165634"></a><a name="p573285588165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row2043478526165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1618178444165634"><a name="p1618178444165634"></a><a name="p1618178444165634"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1241459013165634"><a name="p1241459013165634"></a><a name="p1241459013165634"></a>virtual void </p>
<p id="p520769777165634"><a name="p520769777165634"></a><a name="p520769777165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1570122503165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332256585165634"><a name="p1332256585165634"></a><a name="p1332256585165634"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259748570165634"><a name="p1259748570165634"></a><a name="p1259748570165634"></a>virtual void </p>
<p id="p1728780763165634"><a name="p1728780763165634"></a><a name="p1728780763165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1560122400165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p681361763165634"><a name="p681361763165634"></a><a name="p681361763165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1661685787165634"><a name="p1661685787165634"></a><a name="p1661685787165634"></a>virtual void </p>
<p id="p522260640165634"><a name="p522260640165634"></a><a name="p522260640165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row103635225165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p150089487165634"><a name="p150089487165634"></a><a name="p150089487165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024194099165634"><a name="p2024194099165634"></a><a name="p2024194099165634"></a>virtual void </p>
<p id="p1847210815165634"><a name="p1847210815165634"></a><a name="p1847210815165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1168876465165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p69922539165634"><a name="p69922539165634"></a><a name="p69922539165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p556718851165634"><a name="p556718851165634"></a><a name="p556718851165634"></a>int16_t </p>
<p id="p831073011165634"><a name="p831073011165634"></a><a name="p831073011165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1204215993165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1862242909165634"><a name="p1862242909165634"></a><a name="p1862242909165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382490768165634"><a name="p1382490768165634"></a><a name="p1382490768165634"></a>virtual void </p>
<p id="p948173065165634"><a name="p948173065165634"></a><a name="p948173065165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row356188103165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487608549165634"><a name="p487608549165634"></a><a name="p487608549165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p614164522165634"><a name="p614164522165634"></a><a name="p614164522165634"></a>int16_t </p>
<p id="p640638426165634"><a name="p640638426165634"></a><a name="p640638426165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row627662459165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114474618165634"><a name="p114474618165634"></a><a name="p114474618165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511262856165634"><a name="p511262856165634"></a><a name="p511262856165634"></a>virtual void </p>
<p id="p835455490165634"><a name="p835455490165634"></a><a name="p835455490165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1921238467165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295571766165634"><a name="p295571766165634"></a><a name="p295571766165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1228261277165634"><a name="p1228261277165634"></a><a name="p1228261277165634"></a>virtual void </p>
<p id="p554510548165634"><a name="p554510548165634"></a><a name="p554510548165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1728903657165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231216790165634"><a name="p1231216790165634"></a><a name="p1231216790165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847395570165634"><a name="p847395570165634"></a><a name="p847395570165634"></a>bool </p>
<p id="p159325834165634"><a name="p159325834165634"></a><a name="p159325834165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row784600572165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1788046250165634"><a name="p1788046250165634"></a><a name="p1788046250165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p811371442165634"><a name="p811371442165634"></a><a name="p811371442165634"></a>void </p>
<p id="p1606095329165634"><a name="p1606095329165634"></a><a name="p1606095329165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row659502857165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611721446165634"><a name="p611721446165634"></a><a name="p611721446165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993514613165634"><a name="p1993514613165634"></a><a name="p1993514613165634"></a>void </p>
<p id="p678277926165634"><a name="p678277926165634"></a><a name="p678277926165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1470949707165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1917602965165634"><a name="p1917602965165634"></a><a name="p1917602965165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523992172165634"><a name="p523992172165634"></a><a name="p523992172165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p712390893165634"><a name="p712390893165634"></a><a name="p712390893165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row142202411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496306245165634"><a name="p496306245165634"></a><a name="p496306245165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1449404274165634"><a name="p1449404274165634"></a><a name="p1449404274165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1464431467165634"><a name="p1464431467165634"></a><a name="p1464431467165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row1033434738165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p119367740165634"><a name="p119367740165634"></a><a name="p119367740165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918100940165634"><a name="p918100940165634"></a><a name="p918100940165634"></a>void </p>
<p id="p372283110165634"><a name="p372283110165634"></a><a name="p372283110165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1809013909165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p836052707165634"><a name="p836052707165634"></a><a name="p836052707165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762723631165634"><a name="p762723631165634"></a><a name="p762723631165634"></a>const char * </p>
<p id="p1718609921165634"><a name="p1718609921165634"></a><a name="p1718609921165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row697595698165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102332217165634"><a name="p1102332217165634"></a><a name="p1102332217165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250369666165634"><a name="p1250369666165634"></a><a name="p1250369666165634"></a>void </p>
<p id="p541495586165634"><a name="p541495586165634"></a><a name="p541495586165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row635312477165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893021778165634"><a name="p893021778165634"></a><a name="p893021778165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715041187165634"><a name="p715041187165634"></a><a name="p715041187165634"></a>int16_t </p>
<p id="p2050664710165634"><a name="p2050664710165634"></a><a name="p2050664710165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row460979704165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381653436165634"><a name="p1381653436165634"></a><a name="p1381653436165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977632886165634"><a name="p1977632886165634"></a><a name="p1977632886165634"></a>virtual void </p>
<p id="p1867129356165634"><a name="p1867129356165634"></a><a name="p1867129356165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row566338591165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567229093165634"><a name="p1567229093165634"></a><a name="p1567229093165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413346764165634"><a name="p1413346764165634"></a><a name="p1413346764165634"></a>void </p>
<p id="p161697049165634"><a name="p161697049165634"></a><a name="p161697049165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1921735887165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1960093577165634"><a name="p1960093577165634"></a><a name="p1960093577165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p924171735165634"><a name="p924171735165634"></a><a name="p924171735165634"></a>void </p>
<p id="p739716725165634"><a name="p739716725165634"></a><a name="p739716725165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1597799971165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497014121165634"><a name="p1497014121165634"></a><a name="p1497014121165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145657856165634"><a name="p1145657856165634"></a><a name="p1145657856165634"></a>void </p>
<p id="p926014227165634"><a name="p926014227165634"></a><a name="p926014227165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row83832465165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663000625165634"><a name="p1663000625165634"></a><a name="p1663000625165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883816965165634"><a name="p883816965165634"></a><a name="p883816965165634"></a>void </p>
<p id="p102194567165634"><a name="p102194567165634"></a><a name="p102194567165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1476347616165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111367969165634"><a name="p1111367969165634"></a><a name="p1111367969165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550347139165634"><a name="p550347139165634"></a><a name="p550347139165634"></a>void </p>
<p id="p1116161073165634"><a name="p1116161073165634"></a><a name="p1116161073165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1932443856165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890897440165634"><a name="p1890897440165634"></a><a name="p1890897440165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679236240165634"><a name="p679236240165634"></a><a name="p679236240165634"></a>void </p>
<p id="p1042461434165634"><a name="p1042461434165634"></a><a name="p1042461434165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1058846754165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1371253570165634"><a name="p1371253570165634"></a><a name="p1371253570165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288142686165634"><a name="p288142686165634"></a><a name="p288142686165634"></a>void </p>
<p id="p25834566165634"><a name="p25834566165634"></a><a name="p25834566165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row605018922165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357210922165634"><a name="p357210922165634"></a><a name="p357210922165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1000720837165634"><a name="p1000720837165634"></a><a name="p1000720837165634"></a>void </p>
<p id="p199407362165634"><a name="p199407362165634"></a><a name="p199407362165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row406290099165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p483389251165634"><a name="p483389251165634"></a><a name="p483389251165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1378513147165634"><a name="p1378513147165634"></a><a name="p1378513147165634"></a>void </p>
<p id="p692594060165634"><a name="p692594060165634"></a><a name="p692594060165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row976517894165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909452287165634"><a name="p1909452287165634"></a><a name="p1909452287165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587233246165634"><a name="p587233246165634"></a><a name="p587233246165634"></a>void </p>
<p id="p1089365437165634"><a name="p1089365437165634"></a><a name="p1089365437165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1988129810165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957236649165634"><a name="p1957236649165634"></a><a name="p1957236649165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026196280165634"><a name="p1026196280165634"></a><a name="p1026196280165634"></a>void </p>
<p id="p1320817032165634"><a name="p1320817032165634"></a><a name="p1320817032165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1577708907165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p698981598165634"><a name="p698981598165634"></a><a name="p698981598165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1040804187165634"><a name="p1040804187165634"></a><a name="p1040804187165634"></a>void </p>
<p id="p857489198165634"><a name="p857489198165634"></a><a name="p857489198165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row14616619165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p405058933165634"><a name="p405058933165634"></a><a name="p405058933165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p812026745165634"><a name="p812026745165634"></a><a name="p812026745165634"></a>void </p>
<p id="p2059287582165634"><a name="p2059287582165634"></a><a name="p2059287582165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1454573185165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1879342704165634"><a name="p1879342704165634"></a><a name="p1879342704165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723012312165634"><a name="p723012312165634"></a><a name="p723012312165634"></a>void </p>
<p id="p81022110165634"><a name="p81022110165634"></a><a name="p81022110165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row13617038165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097958927165634"><a name="p2097958927165634"></a><a name="p2097958927165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048821722165634"><a name="p1048821722165634"></a><a name="p1048821722165634"></a>void </p>
<p id="p2071653315165634"><a name="p2071653315165634"></a><a name="p2071653315165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row153939985165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p109064220165634"><a name="p109064220165634"></a><a name="p109064220165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1107227524165634"><a name="p1107227524165634"></a><a name="p1107227524165634"></a>void </p>
<p id="p822972860165634"><a name="p822972860165634"></a><a name="p822972860165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1646668972165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1035550973165634"><a name="p1035550973165634"></a><a name="p1035550973165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1625646462165634"><a name="p1625646462165634"></a><a name="p1625646462165634"></a>virtual void </p>
<p id="p1661467862165634"><a name="p1661467862165634"></a><a name="p1661467862165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row994757048165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p718005834165634"><a name="p718005834165634"></a><a name="p718005834165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203358032165634"><a name="p203358032165634"></a><a name="p203358032165634"></a>virtual int64_t </p>
<p id="p528564416165634"><a name="p528564416165634"></a><a name="p528564416165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row728152417165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861816483165634"><a name="p1861816483165634"></a><a name="p1861816483165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1106934142165634"><a name="p1106934142165634"></a><a name="p1106934142165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1667874809165634"><a name="p1667874809165634"></a><a name="p1667874809165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row2046722497165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491722108165634"><a name="p1491722108165634"></a><a name="p1491722108165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1673963959165634"><a name="p1673963959165634"></a><a name="p1673963959165634"></a>void * </p>
<p id="p1638478081165634"><a name="p1638478081165634"></a><a name="p1638478081165634"></a>Overrides the <strong id="b714172774165634"><a name="b714172774165634"></a><a name="b714172774165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row600600080165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362712589165634"><a name="p362712589165634"></a><a name="p362712589165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684034645165634"><a name="p1684034645165634"></a><a name="p1684034645165634"></a>void </p>
<p id="p1478371762165634"><a name="p1478371762165634"></a><a name="p1478371762165634"></a>Overrides the <strong id="b595415651165634"><a name="b595415651165634"></a><a name="b595415651165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Protected Attributes<a name="pro-attribs"></a>

<a name="table623142753165634"></a>
<table><thead align="left"><tr id="row1694867547165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p981490738165634"><a name="p981490738165634"></a><a name="p981490738165634"></a>Protected Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p971763857165634"><a name="p971763857165634"></a><a name="p971763857165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row842830714165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1195778762165634"><a name="p1195778762165634"></a><a name="p1195778762165634"></a><a href="graphic.md#ga3e530646bd55e49f0e5b0052e121f040">imageWidth_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894808283165634"><a name="p1894808283165634"></a><a name="p1894808283165634"></a>Represents the width of this image. </p>
</td>
</tr>
<tr id="row693193229165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1847810889165634"><a name="p1847810889165634"></a><a name="p1847810889165634"></a><a href="graphic.md#ga5a7112d86d7b11b904b57c853817621d">imageHeight_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1225181335165634"><a name="p1225181335165634"></a><a name="p1225181335165634"></a>Represents the height of this image. </p>
</td>
</tr>
<tr id="row2075794783165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1615021593165634"><a name="p1615021593165634"></a><a name="p1615021593165634"></a><a href="graphic.md#gac13c0b542f4d7f789754bacf572894b2">autoEnable_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p295467368165634"><a name="p295467368165634"></a><a name="p295467368165634"></a>Specifies whether automatic adaptation is enabled. </p>
</td>
</tr>
<tr id="row1737499363165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378577597165634"><a name="p1378577597165634"></a><a name="p1378577597165634"></a><a href="graphic.md#ga687a71ca22c04a7e761969f1fab1b06f">needRefresh_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559364042165634"><a name="p1559364042165634"></a><a name="p1559364042165634"></a>Specifies whether a refresh is needed. </p>
</td>
</tr>
<tr id="row938818916165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p8509755165634"><a name="p8509755165634"></a><a name="p8509755165634"></a><a href="graphic.md#gacbbee3e74893c43864b116779d97ad09">colorFormat_</a>: 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1415232121165634"><a name="p1415232121165634"></a><a name="p1415232121165634"></a>Represents the color format of this image. </p>
</td>
</tr>
<tr id="row1808008812165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2071907088165634"><a name="p2071907088165634"></a><a name="p2071907088165634"></a><a href="graphic.md#ga1c57bd4af56c49a11060e32b6e33066c">blurLevel_</a>: 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702108304165634"><a name="p702108304165634"></a><a name="p702108304165634"></a>Represents the blur level of this image when it is rotated or scaled. </p>
</td>
</tr>
<tr id="row1524165517165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p864455773165634"><a name="p864455773165634"></a><a name="p864455773165634"></a><a href="graphic.md#ga5a8f8683c377c59c6a3c193f18468e60">algorithm_</a>: 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070915419165634"><a name="p1070915419165634"></a><a name="p1070915419165634"></a>Represents the algorithm used for image rotation and scaling. </p>
</td>
</tr>
</tbody>
</table>

