# OHOS::UIToggleButton<a name="ZH-CN_TOPIC_0000001055198158"></a>

-   [Overview](#section1816983910165635)
-   [Summary](#section323334055165635)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1816983910165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a toggle button. 

Each toggle button contains two images, one for pressing and the other for releasing.

See also
:   [UICheckBox](OHOS-UICheckBox.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section323334055165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1004358853165635"></a>
<table><thead align="left"><tr id="row326303311165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1151399680165635"><a name="p1151399680165635"></a><a name="p1151399680165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1819499467165635"><a name="p1819499467165635"></a><a name="p1819499467165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row191886105165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p398135169165635"><a name="p398135169165635"></a><a name="p398135169165635"></a><a href="Graphic.md#ga98d6bb49e21d7748020b75a9f5f1c61d">UIToggleButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166386686165635"><a name="p166386686165635"></a><a name="p166386686165635"></a> </p>
<p id="p625907801165635"><a name="p625907801165635"></a><a name="p625907801165635"></a>A constructor used to create a <strong id="b1114913623165635"><a name="b1114913623165635"></a><a name="b1114913623165635"></a><a href="OHOS-UIToggleButton.md">UIToggleButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1578380339165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628848696165635"><a name="p1628848696165635"></a><a name="p1628848696165635"></a><a href="Graphic.md#ga4946fb71fed32a4f328ecdd1da3141c5">~UIToggleButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p993286870165635"><a name="p993286870165635"></a><a name="p993286870165635"></a>virtual </p>
<p id="p1179795957165635"><a name="p1179795957165635"></a><a name="p1179795957165635"></a>A destructor used to delete the <strong id="b704861610165635"><a name="b704861610165635"></a><a name="b704861610165635"></a><a href="OHOS-UIToggleButton.md">UIToggleButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1022920646165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p627176088165635"><a name="p627176088165635"></a><a name="p627176088165635"></a><a href="Graphic.md#gaeb2bf2bfa7b5f229a151bec4fd046b40">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755273075165635"><a name="p1755273075165635"></a><a name="p1755273075165635"></a>UIViewType </p>
<p id="p594158110165635"><a name="p594158110165635"></a><a name="p594158110165635"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row385354635165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2084598786165635"><a name="p2084598786165635"></a><a name="p2084598786165635"></a><a href="Graphic.md#ga73354e99d22f2fe8b44f1c11c8d62fd0">SetState</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608894577165635"><a name="p608894577165635"></a><a name="p608894577165635"></a>void </p>
<p id="p777663362165635"><a name="p777663362165635"></a><a name="p777663362165635"></a>Sets the state for this toggle button. </p>
</td>
</tr>
<tr id="row1595620096165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2002503897165635"><a name="p2002503897165635"></a><a name="p2002503897165635"></a><a href="Graphic.md#gad46154853ea44173988a82fa366f16db">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p436534726165635"><a name="p436534726165635"></a><a name="p436534726165635"></a>bool </p>
<p id="p1140385267165635"><a name="p1140385267165635"></a><a name="p1140385267165635"></a>Obtains the state of this toggle button. </p>
</td>
</tr>
<tr id="row2138717666165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491454873165635"><a name="p491454873165635"></a><a name="p491454873165635"></a><a href="Graphic.md#ga811085fbe237690f21a95e7df2a7c45f">UICheckBox</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2105971964165635"><a name="p2105971964165635"></a><a name="p2105971964165635"></a> </p>
<p id="p199349877165635"><a name="p199349877165635"></a><a name="p199349877165635"></a>A constructor used to create a <strong id="b1808819442165635"><a name="b1808819442165635"></a><a name="b1808819442165635"></a><a href="OHOS-UICheckBox.md">UICheckBox</a></strong> instance. </p>
</td>
</tr>
<tr id="row1978660152165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1226770567165635"><a name="p1226770567165635"></a><a name="p1226770567165635"></a><a href="Graphic.md#ga061c90b24caa6595b70a9da9f96c5c4e">~UICheckBox</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817015410165635"><a name="p1817015410165635"></a><a name="p1817015410165635"></a>virtual </p>
<p id="p1833100070165635"><a name="p1833100070165635"></a><a name="p1833100070165635"></a>A destructor used to delete the <strong id="b2128452849165635"><a name="b2128452849165635"></a><a name="b2128452849165635"></a><a href="OHOS-UICheckBox.md">UICheckBox</a></strong> instance. </p>
</td>
</tr>
<tr id="row1142917373165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847157977165635"><a name="p847157977165635"></a><a name="p847157977165635"></a><a href="Graphic.md#gad72c8f6a67fc3fb86da8eabffcf5315d">SetOnChangeListener</a> (<a href="OHOS-UICheckBox-OnChangeListener.md">OnChangeListener</a> *onStateChangeListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p293053215165635"><a name="p293053215165635"></a><a name="p293053215165635"></a>void </p>
<p id="p1506958199165635"><a name="p1506958199165635"></a><a name="p1506958199165635"></a>Sets the listener for this check box. </p>
</td>
</tr>
<tr id="row2081229611165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443928091165635"><a name="p1443928091165635"></a><a name="p1443928091165635"></a><a href="Graphic.md#ga53cc6c8f18b90c3abd96a791c8921010">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1655533016165635"><a name="p1655533016165635"></a><a name="p1655533016165635"></a>bool </p>
<p id="p1214756270165635"><a name="p1214756270165635"></a><a name="p1214756270165635"></a>Do something before draw, this function will be invoked mainly to check if this view need to cover invalidate area so render manager can decide which layer to draw firstly. </p>
</td>
</tr>
<tr id="row388574962165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1803012358165635"><a name="p1803012358165635"></a><a name="p1803012358165635"></a><a href="Graphic.md#ga8e75f8411fb25e564c82573a12773189">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204249344165635"><a name="p204249344165635"></a><a name="p204249344165635"></a>void </p>
<p id="p476347710165635"><a name="p476347710165635"></a><a name="p476347710165635"></a>Executes the draw action Ondraw invokes the rendering function provided by the underlying layer to draw pictures based on the selected status of the checkbox. </p>
</td>
</tr>
<tr id="row2111735267165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p667915969165635"><a name="p667915969165635"></a><a name="p667915969165635"></a><a href="Graphic.md#ga31d4f10f4c32b0fb284645450875ae0c">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p485841347165635"><a name="p485841347165635"></a><a name="p485841347165635"></a>void </p>
<p id="p1350849154165635"><a name="p1350849154165635"></a><a name="p1350849154165635"></a>Executes the click event action OnClickEvent will reverse the selected state of checkbox. Example: If the check box is selected, the checkbox status is changed to Unselected after the click action is taken. </p>
</td>
</tr>
<tr id="row1249539626165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1903802656165635"><a name="p1903802656165635"></a><a name="p1903802656165635"></a><a href="Graphic.md#ga2e1ac9e3084d018febf5ac0912a27c72">SetImages</a> (const char *selectedImageSrc, const char *unselectedImageSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1715443700165635"><a name="p1715443700165635"></a><a name="p1715443700165635"></a>virtual void </p>
<p id="p1672127024165635"><a name="p1672127024165635"></a><a name="p1672127024165635"></a>Sets the images for this check box. </p>
</td>
</tr>
<tr id="row73478424165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1328644569165635"><a name="p1328644569165635"></a><a name="p1328644569165635"></a><a href="Graphic.md#ga89eb87d02e7b31fc6517b8744751f021">SetImages</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *selectedImageSrc, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *unselectedImageSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170470692165635"><a name="p1170470692165635"></a><a name="p1170470692165635"></a>virtual void </p>
<p id="p1418100035165635"><a name="p1418100035165635"></a><a name="p1418100035165635"></a>Sets the images for this check box. </p>
</td>
</tr>
<tr id="row1832641206165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625916046165635"><a name="p1625916046165635"></a><a name="p1625916046165635"></a><a href="Graphic.md#gab3cddc176a6834fabc7c53912c97237c">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p477388799165635"><a name="p477388799165635"></a><a name="p477388799165635"></a><a href="Graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> </p>
<p id="p1258587263165635"><a name="p1258587263165635"></a><a name="p1258587263165635"></a>Obtains the state of this check box. </p>
</td>
</tr>
<tr id="row1929709443165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1689282592165635"><a name="p1689282592165635"></a><a name="p1689282592165635"></a><a href="Graphic.md#ga32217050815d4d9129ace5ab410fb82d">SetState</a> (<a href="Graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1481922091165635"><a name="p1481922091165635"></a><a name="p1481922091165635"></a>void </p>
<p id="p1885329834165635"><a name="p1885329834165635"></a><a name="p1885329834165635"></a>Sets the state for this check box. </p>
</td>
</tr>
<tr id="row846123004165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1458788986165635"><a name="p1458788986165635"></a><a name="p1458788986165635"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1082661984165635"><a name="p1082661984165635"></a><a name="p1082661984165635"></a> </p>
<p id="p413515519165635"><a name="p413515519165635"></a><a name="p413515519165635"></a>A default constructor used to create an <strong id="b2044380939165635"><a name="b2044380939165635"></a><a name="b2044380939165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1377457338165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600745744165635"><a name="p1600745744165635"></a><a name="p1600745744165635"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944733145165635"><a name="p1944733145165635"></a><a name="p1944733145165635"></a> </p>
<p id="p1702380818165635"><a name="p1702380818165635"></a><a name="p1702380818165635"></a>A constructor used to create an <strong id="b2014515496165635"><a name="b2014515496165635"></a><a name="b2014515496165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row919404270165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764692035165635"><a name="p764692035165635"></a><a name="p764692035165635"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085849330165635"><a name="p1085849330165635"></a><a name="p1085849330165635"></a>virtual </p>
<p id="p1725379063165635"><a name="p1725379063165635"></a><a name="p1725379063165635"></a>A destructor used to delete the <strong id="b920678668165635"><a name="b920678668165635"></a><a name="b920678668165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row310826664165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1936769031165635"><a name="p1936769031165635"></a><a name="p1936769031165635"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p161251181165635"><a name="p161251181165635"></a><a name="p161251181165635"></a>virtual void </p>
<p id="p779702553165635"><a name="p779702553165635"></a><a name="p779702553165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row517489346165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1454893914165635"><a name="p1454893914165635"></a><a name="p1454893914165635"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1619964353165635"><a name="p1619964353165635"></a><a name="p1619964353165635"></a>virtual void </p>
<p id="p97220153165635"><a name="p97220153165635"></a><a name="p97220153165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row172600520165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798467319165635"><a name="p798467319165635"></a><a name="p798467319165635"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p252277871165635"><a name="p252277871165635"></a><a name="p252277871165635"></a>void </p>
<p id="p1039867270165635"><a name="p1039867270165635"></a><a name="p1039867270165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row756420737165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p468108090165635"><a name="p468108090165635"></a><a name="p468108090165635"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2035269538165635"><a name="p2035269538165635"></a><a name="p2035269538165635"></a>void </p>
<p id="p1897733263165635"><a name="p1897733263165635"></a><a name="p1897733263165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1087103391165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p531224879165635"><a name="p531224879165635"></a><a name="p531224879165635"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176908268165635"><a name="p1176908268165635"></a><a name="p1176908268165635"></a>virtual bool </p>
<p id="p212761177165635"><a name="p212761177165635"></a><a name="p212761177165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1959227927165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p505066686165635"><a name="p505066686165635"></a><a name="p505066686165635"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990855193165635"><a name="p990855193165635"></a><a name="p990855193165635"></a>virtual bool </p>
<p id="p1358952298165635"><a name="p1358952298165635"></a><a name="p1358952298165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1568945710165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847041883165635"><a name="p847041883165635"></a><a name="p847041883165635"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1825045986165635"><a name="p1825045986165635"></a><a name="p1825045986165635"></a>virtual bool </p>
<p id="p1995212057165635"><a name="p1995212057165635"></a><a name="p1995212057165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1427133658165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p501003212165635"><a name="p501003212165635"></a><a name="p501003212165635"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2046350736165635"><a name="p2046350736165635"></a><a name="p2046350736165635"></a>virtual bool </p>
<p id="p205925328165635"><a name="p205925328165635"></a><a name="p205925328165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row246567650165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2093495771165635"><a name="p2093495771165635"></a><a name="p2093495771165635"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403541318165635"><a name="p1403541318165635"></a><a name="p1403541318165635"></a>virtual void </p>
<p id="p141247041165635"><a name="p141247041165635"></a><a name="p141247041165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row691218205165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p439801121165635"><a name="p439801121165635"></a><a name="p439801121165635"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1915792655165635"><a name="p1915792655165635"></a><a name="p1915792655165635"></a>virtual void </p>
<p id="p1343983673165635"><a name="p1343983673165635"></a><a name="p1343983673165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row130718680165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p516216486165635"><a name="p516216486165635"></a><a name="p516216486165635"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1745921098165635"><a name="p1745921098165635"></a><a name="p1745921098165635"></a>virtual void </p>
<p id="p1636450675165635"><a name="p1636450675165635"></a><a name="p1636450675165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row809322605165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306279809165635"><a name="p1306279809165635"></a><a name="p1306279809165635"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272224268165635"><a name="p1272224268165635"></a><a name="p1272224268165635"></a>void </p>
<p id="p1783889587165635"><a name="p1783889587165635"></a><a name="p1783889587165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row359037242165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1884857626165635"><a name="p1884857626165635"></a><a name="p1884857626165635"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1971273756165635"><a name="p1971273756165635"></a><a name="p1971273756165635"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1119252788165635"><a name="p1119252788165635"></a><a name="p1119252788165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1265303246165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p763877927165635"><a name="p763877927165635"></a><a name="p763877927165635"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p370872806165635"><a name="p370872806165635"></a><a name="p370872806165635"></a>void </p>
<p id="p1307516788165635"><a name="p1307516788165635"></a><a name="p1307516788165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1288749523165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p46857708165635"><a name="p46857708165635"></a><a name="p46857708165635"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860587428165635"><a name="p1860587428165635"></a><a name="p1860587428165635"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1132587384165635"><a name="p1132587384165635"></a><a name="p1132587384165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row547159769165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1454598593165635"><a name="p1454598593165635"></a><a name="p1454598593165635"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p803444289165635"><a name="p803444289165635"></a><a name="p803444289165635"></a>void </p>
<p id="p345802781165635"><a name="p345802781165635"></a><a name="p345802781165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2093972200165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1868142892165635"><a name="p1868142892165635"></a><a name="p1868142892165635"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p353215688165635"><a name="p353215688165635"></a><a name="p353215688165635"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1922534671165635"><a name="p1922534671165635"></a><a name="p1922534671165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row348286979165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p525162620165635"><a name="p525162620165635"></a><a name="p525162620165635"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470682930165635"><a name="p470682930165635"></a><a name="p470682930165635"></a>void </p>
<p id="p1056230392165635"><a name="p1056230392165635"></a><a name="p1056230392165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1827178150165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835240754165635"><a name="p835240754165635"></a><a name="p835240754165635"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p760593073165635"><a name="p760593073165635"></a><a name="p760593073165635"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1374267832165635"><a name="p1374267832165635"></a><a name="p1374267832165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1421866988165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p232585377165635"><a name="p232585377165635"></a><a name="p232585377165635"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951825982165635"><a name="p951825982165635"></a><a name="p951825982165635"></a>virtual void </p>
<p id="p2091625005165635"><a name="p2091625005165635"></a><a name="p2091625005165635"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row670950530165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p661819263165635"><a name="p661819263165635"></a><a name="p661819263165635"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641276708165635"><a name="p1641276708165635"></a><a name="p1641276708165635"></a>void </p>
<p id="p564500505165635"><a name="p564500505165635"></a><a name="p564500505165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row243761930165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1312119959165635"><a name="p1312119959165635"></a><a name="p1312119959165635"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469527614165635"><a name="p469527614165635"></a><a name="p469527614165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p806580697165635"><a name="p806580697165635"></a><a name="p806580697165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row328805383165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1130986411165635"><a name="p1130986411165635"></a><a name="p1130986411165635"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p606977968165635"><a name="p606977968165635"></a><a name="p606977968165635"></a>void </p>
<p id="p99754274165635"><a name="p99754274165635"></a><a name="p99754274165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1047560689165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p709805491165635"><a name="p709805491165635"></a><a name="p709805491165635"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719987032165635"><a name="p719987032165635"></a><a name="p719987032165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p153617257165635"><a name="p153617257165635"></a><a name="p153617257165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1666870499165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1084056108165635"><a name="p1084056108165635"></a><a name="p1084056108165635"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p627776331165635"><a name="p627776331165635"></a><a name="p627776331165635"></a>virtual void </p>
<p id="p1833408186165635"><a name="p1833408186165635"></a><a name="p1833408186165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1747183473165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372186632165635"><a name="p1372186632165635"></a><a name="p1372186632165635"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319915512165635"><a name="p319915512165635"></a><a name="p319915512165635"></a>bool </p>
<p id="p1038104978165635"><a name="p1038104978165635"></a><a name="p1038104978165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row867227187165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p718119094165635"><a name="p718119094165635"></a><a name="p718119094165635"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680140601165635"><a name="p1680140601165635"></a><a name="p1680140601165635"></a>void </p>
<p id="p1547216115165635"><a name="p1547216115165635"></a><a name="p1547216115165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1800485051165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p201123204165635"><a name="p201123204165635"></a><a name="p201123204165635"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p576588180165635"><a name="p576588180165635"></a><a name="p576588180165635"></a>bool </p>
<p id="p330842897165635"><a name="p330842897165635"></a><a name="p330842897165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row493935714165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p717700439165635"><a name="p717700439165635"></a><a name="p717700439165635"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p936021195165635"><a name="p936021195165635"></a><a name="p936021195165635"></a>void </p>
<p id="p2039147591165635"><a name="p2039147591165635"></a><a name="p2039147591165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row2078786204165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p974368015165635"><a name="p974368015165635"></a><a name="p974368015165635"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p211029339165635"><a name="p211029339165635"></a><a name="p211029339165635"></a>bool </p>
<p id="p455175462165635"><a name="p455175462165635"></a><a name="p455175462165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row549062452165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720772509165635"><a name="p720772509165635"></a><a name="p720772509165635"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1891260309165635"><a name="p1891260309165635"></a><a name="p1891260309165635"></a>void </p>
<p id="p1888869808165635"><a name="p1888869808165635"></a><a name="p1888869808165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row295083746165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p740170369165635"><a name="p740170369165635"></a><a name="p740170369165635"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398702172165635"><a name="p1398702172165635"></a><a name="p1398702172165635"></a>bool </p>
<p id="p1922233036165635"><a name="p1922233036165635"></a><a name="p1922233036165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row163254417165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1070084530165635"><a name="p1070084530165635"></a><a name="p1070084530165635"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503529961165635"><a name="p1503529961165635"></a><a name="p1503529961165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p67431856165635"><a name="p67431856165635"></a><a name="p67431856165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1527630231165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p917516129165635"><a name="p917516129165635"></a><a name="p917516129165635"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p643546553165635"><a name="p643546553165635"></a><a name="p643546553165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p712459392165635"><a name="p712459392165635"></a><a name="p712459392165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1544646267165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1225157931165635"><a name="p1225157931165635"></a><a name="p1225157931165635"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929706877165635"><a name="p929706877165635"></a><a name="p929706877165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p752440073165635"><a name="p752440073165635"></a><a name="p752440073165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row974969330165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707838952165635"><a name="p1707838952165635"></a><a name="p1707838952165635"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p262860549165635"><a name="p262860549165635"></a><a name="p262860549165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p653896715165635"><a name="p653896715165635"></a><a name="p653896715165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row136376307165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p7525345165635"><a name="p7525345165635"></a><a name="p7525345165635"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p529496616165635"><a name="p529496616165635"></a><a name="p529496616165635"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1027907856165635"><a name="p1027907856165635"></a><a name="p1027907856165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row733722584165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p276932720165635"><a name="p276932720165635"></a><a name="p276932720165635"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694907999165635"><a name="p1694907999165635"></a><a name="p1694907999165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p283967098165635"><a name="p283967098165635"></a><a name="p283967098165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1908348826165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614128121165635"><a name="p614128121165635"></a><a name="p614128121165635"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p511628718165635"><a name="p511628718165635"></a><a name="p511628718165635"></a>void </p>
<p id="p1514678249165635"><a name="p1514678249165635"></a><a name="p1514678249165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1778427383165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p488827987165635"><a name="p488827987165635"></a><a name="p488827987165635"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1375995406165635"><a name="p1375995406165635"></a><a name="p1375995406165635"></a>virtual void </p>
<p id="p1550833988165635"><a name="p1550833988165635"></a><a name="p1550833988165635"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row312245576165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p601717393165635"><a name="p601717393165635"></a><a name="p601717393165635"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388042145165635"><a name="p388042145165635"></a><a name="p388042145165635"></a>virtual int16_t </p>
<p id="p274692267165635"><a name="p274692267165635"></a><a name="p274692267165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1751846822165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p130840375165635"><a name="p130840375165635"></a><a name="p130840375165635"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632253428165635"><a name="p1632253428165635"></a><a name="p1632253428165635"></a>virtual void </p>
<p id="p312520844165635"><a name="p312520844165635"></a><a name="p312520844165635"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1009532161165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041250613165635"><a name="p2041250613165635"></a><a name="p2041250613165635"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1224608213165635"><a name="p1224608213165635"></a><a name="p1224608213165635"></a>virtual int16_t </p>
<p id="p1187653120165635"><a name="p1187653120165635"></a><a name="p1187653120165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row2030388252165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p386252074165635"><a name="p386252074165635"></a><a name="p386252074165635"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687754078165635"><a name="p1687754078165635"></a><a name="p1687754078165635"></a>virtual void </p>
<p id="p1061518483165635"><a name="p1061518483165635"></a><a name="p1061518483165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1460345973165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721046906165635"><a name="p1721046906165635"></a><a name="p1721046906165635"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035676430165635"><a name="p1035676430165635"></a><a name="p1035676430165635"></a>virtual void </p>
<p id="p1609414439165635"><a name="p1609414439165635"></a><a name="p1609414439165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row317495319165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1144105625165635"><a name="p1144105625165635"></a><a name="p1144105625165635"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2033056805165635"><a name="p2033056805165635"></a><a name="p2033056805165635"></a>int16_t </p>
<p id="p483284527165635"><a name="p483284527165635"></a><a name="p483284527165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row5553847165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909062066165635"><a name="p1909062066165635"></a><a name="p1909062066165635"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1132341375165635"><a name="p1132341375165635"></a><a name="p1132341375165635"></a>virtual void </p>
<p id="p1522629469165635"><a name="p1522629469165635"></a><a name="p1522629469165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row202821056165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708520597165635"><a name="p1708520597165635"></a><a name="p1708520597165635"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p251895058165635"><a name="p251895058165635"></a><a name="p251895058165635"></a>int16_t </p>
<p id="p1942654955165635"><a name="p1942654955165635"></a><a name="p1942654955165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row49789189165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1442552725165635"><a name="p1442552725165635"></a><a name="p1442552725165635"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p953744134165635"><a name="p953744134165635"></a><a name="p953744134165635"></a>virtual void </p>
<p id="p1566500625165635"><a name="p1566500625165635"></a><a name="p1566500625165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row158476473165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p934449173165635"><a name="p934449173165635"></a><a name="p934449173165635"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p185603014165635"><a name="p185603014165635"></a><a name="p185603014165635"></a>virtual void </p>
<p id="p1855284559165635"><a name="p1855284559165635"></a><a name="p1855284559165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row978903071165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p763841588165635"><a name="p763841588165635"></a><a name="p763841588165635"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368552430165635"><a name="p368552430165635"></a><a name="p368552430165635"></a>bool </p>
<p id="p478025300165635"><a name="p478025300165635"></a><a name="p478025300165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row2076865883165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752816854165635"><a name="p752816854165635"></a><a name="p752816854165635"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001778400165635"><a name="p2001778400165635"></a><a name="p2001778400165635"></a>void </p>
<p id="p1723312216165635"><a name="p1723312216165635"></a><a name="p1723312216165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1339354682165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p363804079165635"><a name="p363804079165635"></a><a name="p363804079165635"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255320189165635"><a name="p1255320189165635"></a><a name="p1255320189165635"></a>void </p>
<p id="p1753034762165635"><a name="p1753034762165635"></a><a name="p1753034762165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row674436729165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p586133163165635"><a name="p586133163165635"></a><a name="p586133163165635"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696645745165635"><a name="p1696645745165635"></a><a name="p1696645745165635"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p2033760640165635"><a name="p2033760640165635"></a><a name="p2033760640165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row434743311165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1619056626165635"><a name="p1619056626165635"></a><a name="p1619056626165635"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1084885875165635"><a name="p1084885875165635"></a><a name="p1084885875165635"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p628969912165635"><a name="p628969912165635"></a><a name="p628969912165635"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row736212383165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466576054165635"><a name="p466576054165635"></a><a name="p466576054165635"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620193924165635"><a name="p1620193924165635"></a><a name="p1620193924165635"></a>void </p>
<p id="p1362989283165635"><a name="p1362989283165635"></a><a name="p1362989283165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row899458349165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998229335165635"><a name="p998229335165635"></a><a name="p998229335165635"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2008702521165635"><a name="p2008702521165635"></a><a name="p2008702521165635"></a>const char * </p>
<p id="p66716617165635"><a name="p66716617165635"></a><a name="p66716617165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1820612696165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402989314165635"><a name="p1402989314165635"></a><a name="p1402989314165635"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320872525165635"><a name="p320872525165635"></a><a name="p320872525165635"></a>void </p>
<p id="p862596268165635"><a name="p862596268165635"></a><a name="p862596268165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1869667128165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1309034520165635"><a name="p1309034520165635"></a><a name="p1309034520165635"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p845793508165635"><a name="p845793508165635"></a><a name="p845793508165635"></a>int16_t </p>
<p id="p666483140165635"><a name="p666483140165635"></a><a name="p666483140165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1841999666165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p95464058165635"><a name="p95464058165635"></a><a name="p95464058165635"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p772064370165635"><a name="p772064370165635"></a><a name="p772064370165635"></a>virtual void </p>
<p id="p510480069165635"><a name="p510480069165635"></a><a name="p510480069165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row445044939165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1090991981165635"><a name="p1090991981165635"></a><a name="p1090991981165635"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1119599129165635"><a name="p1119599129165635"></a><a name="p1119599129165635"></a>void </p>
<p id="p1461267064165635"><a name="p1461267064165635"></a><a name="p1461267064165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row929123355165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1325250744165635"><a name="p1325250744165635"></a><a name="p1325250744165635"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295969153165635"><a name="p1295969153165635"></a><a name="p1295969153165635"></a>void </p>
<p id="p1474758544165635"><a name="p1474758544165635"></a><a name="p1474758544165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1354655566165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1912252063165635"><a name="p1912252063165635"></a><a name="p1912252063165635"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p959336807165635"><a name="p959336807165635"></a><a name="p959336807165635"></a>void </p>
<p id="p1004785391165635"><a name="p1004785391165635"></a><a name="p1004785391165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1721779041165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008491738165635"><a name="p1008491738165635"></a><a name="p1008491738165635"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p588165257165635"><a name="p588165257165635"></a><a name="p588165257165635"></a>void </p>
<p id="p1169211168165635"><a name="p1169211168165635"></a><a name="p1169211168165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row493934293165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1319961407165635"><a name="p1319961407165635"></a><a name="p1319961407165635"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p467857147165635"><a name="p467857147165635"></a><a name="p467857147165635"></a>void </p>
<p id="p1156964805165635"><a name="p1156964805165635"></a><a name="p1156964805165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row977133470165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658326682165635"><a name="p658326682165635"></a><a name="p658326682165635"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2044185425165635"><a name="p2044185425165635"></a><a name="p2044185425165635"></a>void </p>
<p id="p1340219368165635"><a name="p1340219368165635"></a><a name="p1340219368165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1495056139165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1674627043165635"><a name="p1674627043165635"></a><a name="p1674627043165635"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p517095151165635"><a name="p517095151165635"></a><a name="p517095151165635"></a>void </p>
<p id="p1467098243165635"><a name="p1467098243165635"></a><a name="p1467098243165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row2021198384165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217772306165635"><a name="p1217772306165635"></a><a name="p1217772306165635"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090056117165635"><a name="p2090056117165635"></a><a name="p2090056117165635"></a>void </p>
<p id="p1841458932165635"><a name="p1841458932165635"></a><a name="p1841458932165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1668283985165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1697574351165635"><a name="p1697574351165635"></a><a name="p1697574351165635"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p440698854165635"><a name="p440698854165635"></a><a name="p440698854165635"></a>void </p>
<p id="p1570890977165635"><a name="p1570890977165635"></a><a name="p1570890977165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1921006205165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781087758165635"><a name="p1781087758165635"></a><a name="p1781087758165635"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282271007165635"><a name="p282271007165635"></a><a name="p282271007165635"></a>void </p>
<p id="p2017696136165635"><a name="p2017696136165635"></a><a name="p2017696136165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row65074647165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2052954932165635"><a name="p2052954932165635"></a><a name="p2052954932165635"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1318460540165635"><a name="p1318460540165635"></a><a name="p1318460540165635"></a>void </p>
<p id="p1045076393165635"><a name="p1045076393165635"></a><a name="p1045076393165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row2066811487165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p790335380165635"><a name="p790335380165635"></a><a name="p790335380165635"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753678621165635"><a name="p753678621165635"></a><a name="p753678621165635"></a>void </p>
<p id="p646714798165635"><a name="p646714798165635"></a><a name="p646714798165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1717821330165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097739126165635"><a name="p2097739126165635"></a><a name="p2097739126165635"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245188961165635"><a name="p245188961165635"></a><a name="p245188961165635"></a>void </p>
<p id="p859536160165635"><a name="p859536160165635"></a><a name="p859536160165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1410748232165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2073702397165635"><a name="p2073702397165635"></a><a name="p2073702397165635"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10264460165635"><a name="p10264460165635"></a><a name="p10264460165635"></a>void </p>
<p id="p322360600165635"><a name="p322360600165635"></a><a name="p322360600165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row895649146165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p547352183165635"><a name="p547352183165635"></a><a name="p547352183165635"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p357877875165635"><a name="p357877875165635"></a><a name="p357877875165635"></a>void </p>
<p id="p1462000815165635"><a name="p1462000815165635"></a><a name="p1462000815165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row159723046165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p970910896165635"><a name="p970910896165635"></a><a name="p970910896165635"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p531463816165635"><a name="p531463816165635"></a><a name="p531463816165635"></a>void </p>
<p id="p147717957165635"><a name="p147717957165635"></a><a name="p147717957165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1525314157165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145982884165635"><a name="p2145982884165635"></a><a name="p2145982884165635"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733843884165635"><a name="p733843884165635"></a><a name="p733843884165635"></a>virtual void </p>
<p id="p10215066165635"><a name="p10215066165635"></a><a name="p10215066165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1652346028165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423078502165635"><a name="p1423078502165635"></a><a name="p1423078502165635"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p613604627165635"><a name="p613604627165635"></a><a name="p613604627165635"></a>virtual int64_t </p>
<p id="p399385550165635"><a name="p399385550165635"></a><a name="p399385550165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1442500094165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16378622165635"><a name="p16378622165635"></a><a name="p16378622165635"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479470090165635"><a name="p479470090165635"></a><a name="p479470090165635"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p449624641165635"><a name="p449624641165635"></a><a name="p449624641165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row364973541165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779959834165635"><a name="p1779959834165635"></a><a name="p1779959834165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002987249165635"><a name="p2002987249165635"></a><a name="p2002987249165635"></a>void * </p>
<p id="p825434914165635"><a name="p825434914165635"></a><a name="p825434914165635"></a>Overrides the <strong id="b1284026241165635"><a name="b1284026241165635"></a><a name="b1284026241165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row841431334165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1438286107165635"><a name="p1438286107165635"></a><a name="p1438286107165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878526081165635"><a name="p1878526081165635"></a><a name="p1878526081165635"></a>void </p>
<p id="p82522128165635"><a name="p82522128165635"></a><a name="p82522128165635"></a>Overrides the <strong id="b1954052957165635"><a name="b1954052957165635"></a><a name="b1954052957165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1266974231165635"></a>
<table><thead align="left"><tr id="row1077844343165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1447544616165635"><a name="p1447544616165635"></a><a name="p1447544616165635"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p62147906165635"><a name="p62147906165635"></a><a name="p62147906165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1363515602165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247620885165635"><a name="p247620885165635"></a><a name="p247620885165635"></a><a href="Graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544053648165635"><a name="p1544053648165635"></a><a name="p1544053648165635"></a>Enumerates the states of a check box. </p>
</td>
</tr>
</tbody>
</table>

