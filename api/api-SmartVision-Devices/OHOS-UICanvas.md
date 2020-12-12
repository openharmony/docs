# OHOS::UICanvas<a name="ZH-CN_TOPIC_0000001054918177"></a>

-   [Overview](#section1708912539165634)
-   [Summary](#section1861402016165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1708912539165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a canvas, which is used to draw multiple types of 2D graphs. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1861402016165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1067259975165634"></a>
<table><thead align="left"><tr id="row281233461165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p742917765165634"><a name="p742917765165634"></a><a name="p742917765165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p497637153165634"><a name="p497637153165634"></a><a name="p497637153165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row942391654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1457386033165634"><a name="p1457386033165634"></a><a name="p1457386033165634"></a><a href="OHOS-UICanvas-FontStyle.md">FontStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1891711784165634"><a name="p1891711784165634"></a><a name="p1891711784165634"></a>Defines the font style. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table636542222165634"></a>
<table><thead align="left"><tr id="row406801465165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p272385405165634"><a name="p272385405165634"></a><a name="p272385405165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p52579721165634"><a name="p52579721165634"></a><a name="p52579721165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1971137045165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705856144165634"><a name="p705856144165634"></a><a name="p705856144165634"></a><a href="Graphic.md#ga60d2ed5d49ef68ae8d6f2a8b58322ed3">UICanvas</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977212400165634"><a name="p977212400165634"></a><a name="p977212400165634"></a> </p>
<p id="p694354960165634"><a name="p694354960165634"></a><a name="p694354960165634"></a>A constructor used to create a <strong id="b548391978165634"><a name="b548391978165634"></a><a name="b548391978165634"></a><a href="OHOS-UICanvas.md">UICanvas</a></strong> instance. </p>
</td>
</tr>
<tr id="row1026624111165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445120300165634"><a name="p445120300165634"></a><a name="p445120300165634"></a><a href="Graphic.md#gaf099d1872cdb070f038c5135309b9b6b">~UICanvas</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096510019165634"><a name="p1096510019165634"></a><a name="p1096510019165634"></a>virtual </p>
<p id="p1260652112165634"><a name="p1260652112165634"></a><a name="p1260652112165634"></a>A destructor used to delete the <strong id="b233070296165634"><a name="b233070296165634"></a><a name="b233070296165634"></a><a href="OHOS-UICanvas.md">UICanvas</a></strong> instance. </p>
</td>
</tr>
<tr id="row2131345875165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019569439165634"><a name="p2019569439165634"></a><a name="p2019569439165634"></a><a href="Graphic.md#ga467faebb78b4c4a753eaa44b772f0905">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p475676708165634"><a name="p475676708165634"></a><a name="p475676708165634"></a>UIViewType </p>
<p id="p1331408451165634"><a name="p1331408451165634"></a><a name="p1331408451165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2066342124165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313124841165634"><a name="p1313124841165634"></a><a name="p1313124841165634"></a><a href="Graphic.md#ga7e20822a6c448bee724f20afad1c69d4">Clear</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686318644165634"><a name="p1686318644165634"></a><a name="p1686318644165634"></a>void </p>
<p id="p1992286129165634"><a name="p1992286129165634"></a><a name="p1992286129165634"></a>Clears the entire canvas. </p>
</td>
</tr>
<tr id="row289639774165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231837870165634"><a name="p1231837870165634"></a><a name="p1231837870165634"></a><a href="Graphic.md#gaca35fe1a1d344eab80ecb1425a74a91a">SetStartPosition</a> (const <a href="OHOS-Point.md">Point</a> &amp;startPoint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p517583007165634"><a name="p517583007165634"></a><a name="p517583007165634"></a>void </p>
<p id="p1508190872165634"><a name="p1508190872165634"></a><a name="p1508190872165634"></a>Sets the coordinates of the start point for drawing a line. For example, if <strong id="b768119945165634"><a name="b768119945165634"></a><a name="b768119945165634"></a>startPoint</strong> is set to {50, 50}, the line is drawn from this set of coordinates on the canvas. </p>
</td>
</tr>
<tr id="row2082222654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2022373932165634"><a name="p2022373932165634"></a><a name="p2022373932165634"></a><a href="Graphic.md#gad23f7db18bfa5f91e3cb814193e6932d">GetStartPosition</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371301492165634"><a name="p371301492165634"></a><a name="p371301492165634"></a>const <a href="OHOS-Point.md">Point</a> &amp; </p>
<p id="p1191562410165634"><a name="p1191562410165634"></a><a name="p1191562410165634"></a>Obtains the coordinates of the start point of a line. </p>
</td>
</tr>
<tr id="row2084082188165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p801159206165634"><a name="p801159206165634"></a><a name="p801159206165634"></a><a href="Graphic.md#gac97d9d39484e5a1e36273510ae47327e">DrawLine</a> (const <a href="OHOS-Point.md">Point</a> &amp;endPoint, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2170912165634"><a name="p2170912165634"></a><a name="p2170912165634"></a>void </p>
<p id="p1767403204165634"><a name="p1767403204165634"></a><a name="p1767403204165634"></a>Draws a straight line. </p>
</td>
</tr>
<tr id="row1207735811165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903655018165634"><a name="p903655018165634"></a><a name="p903655018165634"></a><a href="Graphic.md#ga0c5e94526dab6a62d6db0a67385104db">DrawLine</a> (const <a href="OHOS-Point.md">Point</a> &amp;startPoint, const <a href="OHOS-Point.md">Point</a> &amp;endPoint, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206334653165634"><a name="p206334653165634"></a><a name="p206334653165634"></a>void </p>
<p id="p1471479452165634"><a name="p1471479452165634"></a><a name="p1471479452165634"></a>Draws a straight line from the coordinates of the start point. </p>
</td>
</tr>
<tr id="row779828321165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1227013101165634"><a name="p1227013101165634"></a><a name="p1227013101165634"></a><a href="Graphic.md#gab6557ddb74b721e4eba6cdabab954a3b">DrawCurve</a> (const <a href="OHOS-Point.md">Point</a> &amp;control1, const <a href="OHOS-Point.md">Point</a> &amp;control2, const <a href="OHOS-Point.md">Point</a> &amp;endPoint, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378209920165634"><a name="p378209920165634"></a><a name="p378209920165634"></a>void </p>
<p id="p102458500165634"><a name="p102458500165634"></a><a name="p102458500165634"></a>Draws a cubic Bezier curve. </p>
</td>
</tr>
<tr id="row2012768672165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1188746915165634"><a name="p1188746915165634"></a><a name="p1188746915165634"></a><a href="Graphic.md#gad186e8eab51e97a4854d3a757a3becfb">DrawCurve</a> (const <a href="OHOS-Point.md">Point</a> &amp;startPoint, const <a href="OHOS-Point.md">Point</a> &amp;control1, const <a href="OHOS-Point.md">Point</a> &amp;control2, const <a href="OHOS-Point.md">Point</a> &amp;endPoint, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p153638984165634"><a name="p153638984165634"></a><a name="p153638984165634"></a>void </p>
<p id="p13326001165634"><a name="p13326001165634"></a><a name="p13326001165634"></a>Draws a cubic Bezier curve from the start point coordinates. </p>
</td>
</tr>
<tr id="row248709703165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p311989605165634"><a name="p311989605165634"></a><a name="p311989605165634"></a><a href="Graphic.md#ga1cc0bc88810cdd5554e2b1b14e68c279">DrawRect</a> (const <a href="OHOS-Point.md">Point</a> &amp;startPoint, int16_t height, int16_t width, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1554158725165634"><a name="p1554158725165634"></a><a name="p1554158725165634"></a>void </p>
<p id="p52594280165634"><a name="p52594280165634"></a><a name="p52594280165634"></a>Draws a rectangle. </p>
</td>
</tr>
<tr id="row153078658165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136864924165634"><a name="p1136864924165634"></a><a name="p1136864924165634"></a><a href="Graphic.md#ga974544e34560d0f9d6e162c528fcd7af">DrawCircle</a> (const <a href="OHOS-Point.md">Point</a> &amp;center, uint16_t radius, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067645666165634"><a name="p2067645666165634"></a><a name="p2067645666165634"></a>void </p>
<p id="p1735227897165634"><a name="p1735227897165634"></a><a name="p1735227897165634"></a>Draws a circle. </p>
</td>
</tr>
<tr id="row1961244795165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1963208964165634"><a name="p1963208964165634"></a><a name="p1963208964165634"></a><a href="Graphic.md#gaf14bc2633c51a16097c3ad35e8bcb314">DrawSector</a> (const <a href="OHOS-Point.md">Point</a> &amp;center, uint16_t radius, int16_t startAngle, int16_t endAngle, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552763282165634"><a name="p1552763282165634"></a><a name="p1552763282165634"></a>void </p>
<p id="p210290182165634"><a name="p210290182165634"></a><a name="p210290182165634"></a>Draws a sector. </p>
</td>
</tr>
<tr id="row332838444165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568931506165634"><a name="p568931506165634"></a><a name="p568931506165634"></a><a href="Graphic.md#ga620028da5c71f96416becc877331ba6c">DrawArc</a> (const <a href="OHOS-Point.md">Point</a> &amp;center, uint16_t radius, int16_t startAngle, int16_t endAngle, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p229556468165634"><a name="p229556468165634"></a><a name="p229556468165634"></a>void </p>
<p id="p1980149705165634"><a name="p1980149705165634"></a><a name="p1980149705165634"></a>Draws an arc. </p>
</td>
</tr>
<tr id="row1360387276165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p807960748165634"><a name="p807960748165634"></a><a name="p807960748165634"></a><a href="Graphic.md#gad5810166b3e02f41319dd4f4229c516c">DrawImage</a> (const <a href="OHOS-Point.md">Point</a> &amp;startPoint, const char *image, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635056238165634"><a name="p1635056238165634"></a><a name="p1635056238165634"></a>void </p>
<p id="p1479314600165634"><a name="p1479314600165634"></a><a name="p1479314600165634"></a>Draws an image. </p>
</td>
</tr>
<tr id="row1093417679165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1287512854165634"><a name="p1287512854165634"></a><a name="p1287512854165634"></a><a href="Graphic.md#ga32d815e5a459b4a866217a7c5c4bb425">DrawLabel</a> (const <a href="OHOS-Point.md">Point</a> &amp;startPoint, const char *text, uint16_t maxWidth, const <a href="OHOS-UICanvas-FontStyle.md">FontStyle</a> &amp;fontStyle, const <a href="OHOS-Paint.md">Paint</a> &amp;paint)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428313164165634"><a name="p1428313164165634"></a><a name="p1428313164165634"></a>void </p>
<p id="p1695218448165634"><a name="p1695218448165634"></a><a name="p1695218448165634"></a>Draws text. </p>
</td>
</tr>
<tr id="row476800839165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393579065165634"><a name="p1393579065165634"></a><a name="p1393579065165634"></a><a href="Graphic.md#gac6122967d3e1f0d312eebed2f93a1369">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712916765165634"><a name="p1712916765165634"></a><a name="p1712916765165634"></a>virtual void </p>
<p id="p93849459165634"><a name="p93849459165634"></a><a name="p93849459165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row604823593165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420281600165634"><a name="p420281600165634"></a><a name="p420281600165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p725057253165634"><a name="p725057253165634"></a><a name="p725057253165634"></a> </p>
<p id="p1049009340165634"><a name="p1049009340165634"></a><a name="p1049009340165634"></a>A default constructor used to create an <strong id="b909253370165634"><a name="b909253370165634"></a><a name="b909253370165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1799642023165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702858495165634"><a name="p702858495165634"></a><a name="p702858495165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287816990165634"><a name="p1287816990165634"></a><a name="p1287816990165634"></a> </p>
<p id="p407503094165634"><a name="p407503094165634"></a><a name="p407503094165634"></a>A constructor used to create an <strong id="b180554739165634"><a name="b180554739165634"></a><a name="b180554739165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row828644804165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448684704165634"><a name="p1448684704165634"></a><a name="p1448684704165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110318073165634"><a name="p2110318073165634"></a><a name="p2110318073165634"></a>virtual </p>
<p id="p5663134165634"><a name="p5663134165634"></a><a name="p5663134165634"></a>A destructor used to delete the <strong id="b474692751165634"><a name="b474692751165634"></a><a name="b474692751165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2046088814165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111437409165634"><a name="p111437409165634"></a><a name="p111437409165634"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423801039165634"><a name="p423801039165634"></a><a name="p423801039165634"></a>virtual bool </p>
<p id="p95970801165634"><a name="p95970801165634"></a><a name="p95970801165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row239824977165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397177907165634"><a name="p397177907165634"></a><a name="p397177907165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1563618692165634"><a name="p1563618692165634"></a><a name="p1563618692165634"></a>virtual void </p>
<p id="p707988273165634"><a name="p707988273165634"></a><a name="p707988273165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row398050747165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947702274165634"><a name="p1947702274165634"></a><a name="p1947702274165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p357843834165634"><a name="p357843834165634"></a><a name="p357843834165634"></a>virtual void </p>
<p id="p1722418652165634"><a name="p1722418652165634"></a><a name="p1722418652165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1551318220165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1652140514165634"><a name="p1652140514165634"></a><a name="p1652140514165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6394299165634"><a name="p6394299165634"></a><a name="p6394299165634"></a>void </p>
<p id="p317449754165634"><a name="p317449754165634"></a><a name="p317449754165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row442652026165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2105588596165634"><a name="p2105588596165634"></a><a name="p2105588596165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2102458904165634"><a name="p2102458904165634"></a><a name="p2102458904165634"></a>void </p>
<p id="p166625977165634"><a name="p166625977165634"></a><a name="p166625977165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row634893015165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677094386165634"><a name="p1677094386165634"></a><a name="p1677094386165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p302686990165634"><a name="p302686990165634"></a><a name="p302686990165634"></a>virtual bool </p>
<p id="p701915082165634"><a name="p701915082165634"></a><a name="p701915082165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row35378028165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243189861165634"><a name="p1243189861165634"></a><a name="p1243189861165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203151947165634"><a name="p203151947165634"></a><a name="p203151947165634"></a>virtual bool </p>
<p id="p116978232165634"><a name="p116978232165634"></a><a name="p116978232165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1391101879165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249802271165634"><a name="p249802271165634"></a><a name="p249802271165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455692428165634"><a name="p1455692428165634"></a><a name="p1455692428165634"></a>virtual bool </p>
<p id="p1978580115165634"><a name="p1978580115165634"></a><a name="p1978580115165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row144875644165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578989930165634"><a name="p1578989930165634"></a><a name="p1578989930165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p43375495165634"><a name="p43375495165634"></a><a name="p43375495165634"></a>virtual bool </p>
<p id="p1919666433165634"><a name="p1919666433165634"></a><a name="p1919666433165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row992235341165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1508797091165634"><a name="p1508797091165634"></a><a name="p1508797091165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p688476809165634"><a name="p688476809165634"></a><a name="p688476809165634"></a>virtual void </p>
<p id="p1834292512165634"><a name="p1834292512165634"></a><a name="p1834292512165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row162613245165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145524866165634"><a name="p145524866165634"></a><a name="p145524866165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204328778165634"><a name="p204328778165634"></a><a name="p204328778165634"></a>virtual void </p>
<p id="p1936063400165634"><a name="p1936063400165634"></a><a name="p1936063400165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1979669852165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62017836165634"><a name="p62017836165634"></a><a name="p62017836165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236202318165634"><a name="p1236202318165634"></a><a name="p1236202318165634"></a>virtual void </p>
<p id="p1752951295165634"><a name="p1752951295165634"></a><a name="p1752951295165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row2004258401165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704086990165634"><a name="p704086990165634"></a><a name="p704086990165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203944168165634"><a name="p203944168165634"></a><a name="p203944168165634"></a>virtual void </p>
<p id="p1310763767165634"><a name="p1310763767165634"></a><a name="p1310763767165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1013671274165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p943678222165634"><a name="p943678222165634"></a><a name="p943678222165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96072799165634"><a name="p96072799165634"></a><a name="p96072799165634"></a>void </p>
<p id="p2107255838165634"><a name="p2107255838165634"></a><a name="p2107255838165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1758974499165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1088733181165634"><a name="p1088733181165634"></a><a name="p1088733181165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p820390562165634"><a name="p820390562165634"></a><a name="p820390562165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1333762318165634"><a name="p1333762318165634"></a><a name="p1333762318165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1523488164165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405456022165634"><a name="p1405456022165634"></a><a name="p1405456022165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123159698165634"><a name="p2123159698165634"></a><a name="p2123159698165634"></a>void </p>
<p id="p278124046165634"><a name="p278124046165634"></a><a name="p278124046165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1300238702165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1163751563165634"><a name="p1163751563165634"></a><a name="p1163751563165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p732260144165634"><a name="p732260144165634"></a><a name="p732260144165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1551621367165634"><a name="p1551621367165634"></a><a name="p1551621367165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1057646749165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33684010165634"><a name="p33684010165634"></a><a name="p33684010165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1920282217165634"><a name="p1920282217165634"></a><a name="p1920282217165634"></a>void </p>
<p id="p1146196124165634"><a name="p1146196124165634"></a><a name="p1146196124165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row408335092165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p570800636165634"><a name="p570800636165634"></a><a name="p570800636165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p928000468165634"><a name="p928000468165634"></a><a name="p928000468165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p331141948165634"><a name="p331141948165634"></a><a name="p331141948165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1636033293165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p219231434165634"><a name="p219231434165634"></a><a name="p219231434165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1511843377165634"><a name="p1511843377165634"></a><a name="p1511843377165634"></a>void </p>
<p id="p448285593165634"><a name="p448285593165634"></a><a name="p448285593165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row173343416165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274037858165634"><a name="p1274037858165634"></a><a name="p1274037858165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p427161844165634"><a name="p427161844165634"></a><a name="p427161844165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p2001847114165634"><a name="p2001847114165634"></a><a name="p2001847114165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1718950859165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p941242748165634"><a name="p941242748165634"></a><a name="p941242748165634"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p387327911165634"><a name="p387327911165634"></a><a name="p387327911165634"></a>virtual void </p>
<p id="p1732866346165634"><a name="p1732866346165634"></a><a name="p1732866346165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1166737360165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p350175540165634"><a name="p350175540165634"></a><a name="p350175540165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p491460773165634"><a name="p491460773165634"></a><a name="p491460773165634"></a>void </p>
<p id="p748873123165634"><a name="p748873123165634"></a><a name="p748873123165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1980721145165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903861100165634"><a name="p903861100165634"></a><a name="p903861100165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p623441806165634"><a name="p623441806165634"></a><a name="p623441806165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p49303923165634"><a name="p49303923165634"></a><a name="p49303923165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row437002037165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221610671165634"><a name="p1221610671165634"></a><a name="p1221610671165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818920878165634"><a name="p1818920878165634"></a><a name="p1818920878165634"></a>void </p>
<p id="p721716438165634"><a name="p721716438165634"></a><a name="p721716438165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1611886307165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110919653165634"><a name="p2110919653165634"></a><a name="p2110919653165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975388439165634"><a name="p1975388439165634"></a><a name="p1975388439165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p937362106165634"><a name="p937362106165634"></a><a name="p937362106165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row434812624165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p101292534165634"><a name="p101292534165634"></a><a name="p101292534165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352415338165634"><a name="p352415338165634"></a><a name="p352415338165634"></a>virtual void </p>
<p id="p428954801165634"><a name="p428954801165634"></a><a name="p428954801165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row759551564165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274509697165634"><a name="p1274509697165634"></a><a name="p1274509697165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p959524175165634"><a name="p959524175165634"></a><a name="p959524175165634"></a>bool </p>
<p id="p943083617165634"><a name="p943083617165634"></a><a name="p943083617165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row545172913165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1396311210165634"><a name="p1396311210165634"></a><a name="p1396311210165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532335855165634"><a name="p1532335855165634"></a><a name="p1532335855165634"></a>void </p>
<p id="p438300305165634"><a name="p438300305165634"></a><a name="p438300305165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1008820711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674476374165634"><a name="p674476374165634"></a><a name="p674476374165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084517192165634"><a name="p2084517192165634"></a><a name="p2084517192165634"></a>bool </p>
<p id="p1894886718165634"><a name="p1894886718165634"></a><a name="p1894886718165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1261052928165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p832594590165634"><a name="p832594590165634"></a><a name="p832594590165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p543673885165634"><a name="p543673885165634"></a><a name="p543673885165634"></a>void </p>
<p id="p2027708452165634"><a name="p2027708452165634"></a><a name="p2027708452165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1720811667165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2077834090165634"><a name="p2077834090165634"></a><a name="p2077834090165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p149709075165634"><a name="p149709075165634"></a><a name="p149709075165634"></a>bool </p>
<p id="p91617013165634"><a name="p91617013165634"></a><a name="p91617013165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1335937291165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1247068045165634"><a name="p1247068045165634"></a><a name="p1247068045165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p813111528165634"><a name="p813111528165634"></a><a name="p813111528165634"></a>void </p>
<p id="p374919230165634"><a name="p374919230165634"></a><a name="p374919230165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row699800329165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943565539165634"><a name="p1943565539165634"></a><a name="p1943565539165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706159635165634"><a name="p1706159635165634"></a><a name="p1706159635165634"></a>bool </p>
<p id="p1533075132165634"><a name="p1533075132165634"></a><a name="p1533075132165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row554527104165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267607112165634"><a name="p267607112165634"></a><a name="p267607112165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1925479196165634"><a name="p1925479196165634"></a><a name="p1925479196165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1473187361165634"><a name="p1473187361165634"></a><a name="p1473187361165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1145656096165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2030246163165634"><a name="p2030246163165634"></a><a name="p2030246163165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746660245165634"><a name="p1746660245165634"></a><a name="p1746660245165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p239986584165634"><a name="p239986584165634"></a><a name="p239986584165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row2054434701165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303171502165634"><a name="p1303171502165634"></a><a name="p1303171502165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2075647476165634"><a name="p2075647476165634"></a><a name="p2075647476165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p947322656165634"><a name="p947322656165634"></a><a name="p947322656165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1265822678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737664772165634"><a name="p1737664772165634"></a><a name="p1737664772165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1412492109165634"><a name="p1412492109165634"></a><a name="p1412492109165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p276736559165634"><a name="p276736559165634"></a><a name="p276736559165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1282812441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348354130165634"><a name="p1348354130165634"></a><a name="p1348354130165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948072144165634"><a name="p1948072144165634"></a><a name="p1948072144165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1741407932165634"><a name="p1741407932165634"></a><a name="p1741407932165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1819743599165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1074082252165634"><a name="p1074082252165634"></a><a name="p1074082252165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441383740165634"><a name="p1441383740165634"></a><a name="p1441383740165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1247585549165634"><a name="p1247585549165634"></a><a name="p1247585549165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1193657802165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p54775219165634"><a name="p54775219165634"></a><a name="p54775219165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1379791747165634"><a name="p1379791747165634"></a><a name="p1379791747165634"></a>void </p>
<p id="p2057764106165634"><a name="p2057764106165634"></a><a name="p2057764106165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1326261434165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p166218707165634"><a name="p166218707165634"></a><a name="p166218707165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1437576254165634"><a name="p1437576254165634"></a><a name="p1437576254165634"></a>virtual void </p>
<p id="p1679663564165634"><a name="p1679663564165634"></a><a name="p1679663564165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1544732603165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1950279085165634"><a name="p1950279085165634"></a><a name="p1950279085165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p980693272165634"><a name="p980693272165634"></a><a name="p980693272165634"></a>virtual int16_t </p>
<p id="p559659689165634"><a name="p559659689165634"></a><a name="p559659689165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1443007237165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519109480165634"><a name="p1519109480165634"></a><a name="p1519109480165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p128137667165634"><a name="p128137667165634"></a><a name="p128137667165634"></a>virtual void </p>
<p id="p50020980165634"><a name="p50020980165634"></a><a name="p50020980165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row672145187165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p530187458165634"><a name="p530187458165634"></a><a name="p530187458165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p468591186165634"><a name="p468591186165634"></a><a name="p468591186165634"></a>virtual int16_t </p>
<p id="p1285776697165634"><a name="p1285776697165634"></a><a name="p1285776697165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1553876844165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997087527165634"><a name="p1997087527165634"></a><a name="p1997087527165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2036317274165634"><a name="p2036317274165634"></a><a name="p2036317274165634"></a>virtual void </p>
<p id="p1977784982165634"><a name="p1977784982165634"></a><a name="p1977784982165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row700207069165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p880486153165634"><a name="p880486153165634"></a><a name="p880486153165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070065060165634"><a name="p1070065060165634"></a><a name="p1070065060165634"></a>virtual void </p>
<p id="p254839794165634"><a name="p254839794165634"></a><a name="p254839794165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row997519834165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1018155408165634"><a name="p1018155408165634"></a><a name="p1018155408165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p614547174165634"><a name="p614547174165634"></a><a name="p614547174165634"></a>int16_t </p>
<p id="p567407399165634"><a name="p567407399165634"></a><a name="p567407399165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row187174834165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p458871429165634"><a name="p458871429165634"></a><a name="p458871429165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p131101534165634"><a name="p131101534165634"></a><a name="p131101534165634"></a>virtual void </p>
<p id="p972799086165634"><a name="p972799086165634"></a><a name="p972799086165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1533877417165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1271482825165634"><a name="p1271482825165634"></a><a name="p1271482825165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332787622165634"><a name="p1332787622165634"></a><a name="p1332787622165634"></a>int16_t </p>
<p id="p1554510034165634"><a name="p1554510034165634"></a><a name="p1554510034165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row694375555165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1094127489165634"><a name="p1094127489165634"></a><a name="p1094127489165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762208799165634"><a name="p1762208799165634"></a><a name="p1762208799165634"></a>virtual void </p>
<p id="p298523567165634"><a name="p298523567165634"></a><a name="p298523567165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row530553722165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p234504849165634"><a name="p234504849165634"></a><a name="p234504849165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p374406224165634"><a name="p374406224165634"></a><a name="p374406224165634"></a>virtual void </p>
<p id="p1321140444165634"><a name="p1321140444165634"></a><a name="p1321140444165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1315279072165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28194113165634"><a name="p28194113165634"></a><a name="p28194113165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330213758165634"><a name="p1330213758165634"></a><a name="p1330213758165634"></a>bool </p>
<p id="p969224878165634"><a name="p969224878165634"></a><a name="p969224878165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1988456038165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032933583165634"><a name="p1032933583165634"></a><a name="p1032933583165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882618755165634"><a name="p1882618755165634"></a><a name="p1882618755165634"></a>void </p>
<p id="p76774594165634"><a name="p76774594165634"></a><a name="p76774594165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1857426866165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058374131165634"><a name="p1058374131165634"></a><a name="p1058374131165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p279287861165634"><a name="p279287861165634"></a><a name="p279287861165634"></a>void </p>
<p id="p712270713165634"><a name="p712270713165634"></a><a name="p712270713165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row2046137651165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481191265165634"><a name="p481191265165634"></a><a name="p481191265165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1212378337165634"><a name="p1212378337165634"></a><a name="p1212378337165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1930154761165634"><a name="p1930154761165634"></a><a name="p1930154761165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row451622180165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1255834032165634"><a name="p1255834032165634"></a><a name="p1255834032165634"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408306637165634"><a name="p1408306637165634"></a><a name="p1408306637165634"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1695528386165634"><a name="p1695528386165634"></a><a name="p1695528386165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row370799148165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p459731304165634"><a name="p459731304165634"></a><a name="p459731304165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57876221165634"><a name="p57876221165634"></a><a name="p57876221165634"></a>void </p>
<p id="p981299395165634"><a name="p981299395165634"></a><a name="p981299395165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row181890338165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895280192165634"><a name="p1895280192165634"></a><a name="p1895280192165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14920149165634"><a name="p14920149165634"></a><a name="p14920149165634"></a>const char * </p>
<p id="p300861077165634"><a name="p300861077165634"></a><a name="p300861077165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1267874778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2017724752165634"><a name="p2017724752165634"></a><a name="p2017724752165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1772079001165634"><a name="p1772079001165634"></a><a name="p1772079001165634"></a>void </p>
<p id="p1873284471165634"><a name="p1873284471165634"></a><a name="p1873284471165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1203554959165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011804586165634"><a name="p2011804586165634"></a><a name="p2011804586165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117855107165634"><a name="p2117855107165634"></a><a name="p2117855107165634"></a>int16_t </p>
<p id="p189332049165634"><a name="p189332049165634"></a><a name="p189332049165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row229455008165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p857599010165634"><a name="p857599010165634"></a><a name="p857599010165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872753554165634"><a name="p1872753554165634"></a><a name="p1872753554165634"></a>virtual void </p>
<p id="p1447890186165634"><a name="p1447890186165634"></a><a name="p1447890186165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row326255492165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443719581165634"><a name="p443719581165634"></a><a name="p443719581165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822044650165634"><a name="p1822044650165634"></a><a name="p1822044650165634"></a>void </p>
<p id="p1191035609165634"><a name="p1191035609165634"></a><a name="p1191035609165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row965474207165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676531359165634"><a name="p1676531359165634"></a><a name="p1676531359165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108764896165634"><a name="p108764896165634"></a><a name="p108764896165634"></a>void </p>
<p id="p358247996165634"><a name="p358247996165634"></a><a name="p358247996165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row832394354165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1789367392165634"><a name="p1789367392165634"></a><a name="p1789367392165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1201351721165634"><a name="p1201351721165634"></a><a name="p1201351721165634"></a>void </p>
<p id="p385767242165634"><a name="p385767242165634"></a><a name="p385767242165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row62248159165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1636867032165634"><a name="p1636867032165634"></a><a name="p1636867032165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p937161551165634"><a name="p937161551165634"></a><a name="p937161551165634"></a>void </p>
<p id="p560945555165634"><a name="p560945555165634"></a><a name="p560945555165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row886588602165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p309305189165634"><a name="p309305189165634"></a><a name="p309305189165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690962197165634"><a name="p1690962197165634"></a><a name="p1690962197165634"></a>void </p>
<p id="p421066538165634"><a name="p421066538165634"></a><a name="p421066538165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row173218716165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838750126165634"><a name="p838750126165634"></a><a name="p838750126165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776240590165634"><a name="p776240590165634"></a><a name="p776240590165634"></a>void </p>
<p id="p1478243992165634"><a name="p1478243992165634"></a><a name="p1478243992165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row546904005165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p402856883165634"><a name="p402856883165634"></a><a name="p402856883165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p512458192165634"><a name="p512458192165634"></a><a name="p512458192165634"></a>void </p>
<p id="p1550442147165634"><a name="p1550442147165634"></a><a name="p1550442147165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1020386883165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573629070165634"><a name="p1573629070165634"></a><a name="p1573629070165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1291748561165634"><a name="p1291748561165634"></a><a name="p1291748561165634"></a>void </p>
<p id="p1180887656165634"><a name="p1180887656165634"></a><a name="p1180887656165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row43836368165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1617676085165634"><a name="p1617676085165634"></a><a name="p1617676085165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088210033165634"><a name="p1088210033165634"></a><a name="p1088210033165634"></a>void </p>
<p id="p441934680165634"><a name="p441934680165634"></a><a name="p441934680165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row684552473165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412645278165634"><a name="p412645278165634"></a><a name="p412645278165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1567495031165634"><a name="p1567495031165634"></a><a name="p1567495031165634"></a>void </p>
<p id="p516022929165634"><a name="p516022929165634"></a><a name="p516022929165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1250532529165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1783712320165634"><a name="p1783712320165634"></a><a name="p1783712320165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523728089165634"><a name="p1523728089165634"></a><a name="p1523728089165634"></a>void </p>
<p id="p832596368165634"><a name="p832596368165634"></a><a name="p832596368165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1427465652165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1379779134165634"><a name="p1379779134165634"></a><a name="p1379779134165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1222444579165634"><a name="p1222444579165634"></a><a name="p1222444579165634"></a>void </p>
<p id="p191429275165634"><a name="p191429275165634"></a><a name="p191429275165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1892380259165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1161205170165634"><a name="p1161205170165634"></a><a name="p1161205170165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435266786165634"><a name="p435266786165634"></a><a name="p435266786165634"></a>void </p>
<p id="p1354353839165634"><a name="p1354353839165634"></a><a name="p1354353839165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1308945184165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357786078165634"><a name="p357786078165634"></a><a name="p357786078165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p850135417165634"><a name="p850135417165634"></a><a name="p850135417165634"></a>void </p>
<p id="p175469067165634"><a name="p175469067165634"></a><a name="p175469067165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row300554509165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p511341457165634"><a name="p511341457165634"></a><a name="p511341457165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1224349605165634"><a name="p1224349605165634"></a><a name="p1224349605165634"></a>void </p>
<p id="p1974659061165634"><a name="p1974659061165634"></a><a name="p1974659061165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row887461720165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779772737165634"><a name="p1779772737165634"></a><a name="p1779772737165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035924584165634"><a name="p1035924584165634"></a><a name="p1035924584165634"></a>void </p>
<p id="p1178946267165634"><a name="p1178946267165634"></a><a name="p1178946267165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row474952827165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209630895165634"><a name="p1209630895165634"></a><a name="p1209630895165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834232248165634"><a name="p834232248165634"></a><a name="p834232248165634"></a>virtual void </p>
<p id="p1841708368165634"><a name="p1841708368165634"></a><a name="p1841708368165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row989288880165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896836920165634"><a name="p896836920165634"></a><a name="p896836920165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973097354165634"><a name="p973097354165634"></a><a name="p973097354165634"></a>virtual int64_t </p>
<p id="p1756501491165634"><a name="p1756501491165634"></a><a name="p1756501491165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row2116299665165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1232549640165634"><a name="p1232549640165634"></a><a name="p1232549640165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p754817365165634"><a name="p754817365165634"></a><a name="p754817365165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p957074112165634"><a name="p957074112165634"></a><a name="p957074112165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row277834276165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282420256165634"><a name="p1282420256165634"></a><a name="p1282420256165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1622523410165634"><a name="p1622523410165634"></a><a name="p1622523410165634"></a>void * </p>
<p id="p773129763165634"><a name="p773129763165634"></a><a name="p773129763165634"></a>Overrides the <strong id="b1312598137165634"><a name="b1312598137165634"></a><a name="b1312598137165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row263424991165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1176929733165634"><a name="p1176929733165634"></a><a name="p1176929733165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97605376165634"><a name="p97605376165634"></a><a name="p97605376165634"></a>void </p>
<p id="p794057222165634"><a name="p794057222165634"></a><a name="p794057222165634"></a>Overrides the <strong id="b84552117165634"><a name="b84552117165634"></a><a name="b84552117165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

