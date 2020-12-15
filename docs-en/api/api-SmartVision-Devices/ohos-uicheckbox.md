# OHOS::UICheckBox<a name="EN-US_TOPIC_0000001054479587"></a>

-   [Overview](#section218109035165634)
-   [Summary](#section1855116257165634)
-   [Data Structures](#nested-classes)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section218109035165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a check box. 

A check box permits users to make a binary choice.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1855116257165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1239940462165634"></a>
<table><thead align="left"><tr id="row2105977935165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p154196180165634"><a name="p154196180165634"></a><a name="p154196180165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p217099266165634"><a name="p217099266165634"></a><a name="p217099266165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720472656165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764885598165634"><a name="p1764885598165634"></a><a name="p1764885598165634"></a><a href="ohos-uicheckbox-onchangelistener.md">OnChangeListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487700334165634"><a name="p1487700334165634"></a><a name="p1487700334165634"></a>Represents a listener for changes of a check box. </p>
</td>
</tr>
</tbody>
</table>

## Public Types<a name="pub-types"></a>

<a name="table1158321070165634"></a>
<table><thead align="left"><tr id="row1505928278165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p976671613165634"><a name="p976671613165634"></a><a name="p976671613165634"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1735478774165634"><a name="p1735478774165634"></a><a name="p1735478774165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1090368874165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082754726165634"><a name="p1082754726165634"></a><a name="p1082754726165634"></a><a href="graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875296923165634"><a name="p875296923165634"></a><a name="p875296923165634"></a>Enumerates the states of a check box. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table400434795165634"></a>
<table><thead align="left"><tr id="row598488143165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p974752227165634"><a name="p974752227165634"></a><a name="p974752227165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p4615327165634"><a name="p4615327165634"></a><a name="p4615327165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1443119174165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653216329165634"><a name="p653216329165634"></a><a name="p653216329165634"></a><a href="graphic.md#ga811085fbe237690f21a95e7df2a7c45f">UICheckBox</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p186525728165634"><a name="p186525728165634"></a><a name="p186525728165634"></a> </p>
<p id="p516369966165634"><a name="p516369966165634"></a><a name="p516369966165634"></a>A constructor used to create a <strong id="b89153705165634"><a name="b89153705165634"></a><a name="b89153705165634"></a><a href="ohos-uicheckbox.md">UICheckBox</a></strong> instance. </p>
</td>
</tr>
<tr id="row210710773165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604984639165634"><a name="p604984639165634"></a><a name="p604984639165634"></a><a href="graphic.md#ga061c90b24caa6595b70a9da9f96c5c4e">~UICheckBox</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1051611569165634"><a name="p1051611569165634"></a><a name="p1051611569165634"></a>virtual </p>
<p id="p2061852945165634"><a name="p2061852945165634"></a><a name="p2061852945165634"></a>A destructor used to delete the <strong id="b1806682766165634"><a name="b1806682766165634"></a><a name="b1806682766165634"></a><a href="ohos-uicheckbox.md">UICheckBox</a></strong> instance. </p>
</td>
</tr>
<tr id="row288647661165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552461795165634"><a name="p552461795165634"></a><a name="p552461795165634"></a><a href="graphic.md#ga6820cef1fb685db5796670ca56b6aace">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p381582814165634"><a name="p381582814165634"></a><a name="p381582814165634"></a>UIViewType </p>
<p id="p1925416700165634"><a name="p1925416700165634"></a><a name="p1925416700165634"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row1539298213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p303937461165634"><a name="p303937461165634"></a><a name="p303937461165634"></a><a href="graphic.md#gad72c8f6a67fc3fb86da8eabffcf5315d">SetOnChangeListener</a> (<a href="ohos-uicheckbox-onchangelistener.md">OnChangeListener</a> *onStateChangeListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2053730210165634"><a name="p2053730210165634"></a><a name="p2053730210165634"></a>void </p>
<p id="p1682895628165634"><a name="p1682895628165634"></a><a name="p1682895628165634"></a>Sets the listener for this check box. </p>
</td>
</tr>
<tr id="row1724368214165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146998129165634"><a name="p146998129165634"></a><a name="p146998129165634"></a><a href="graphic.md#ga53cc6c8f18b90c3abd96a791c8921010">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641853148165634"><a name="p1641853148165634"></a><a name="p1641853148165634"></a>bool </p>
<p id="p1894526722165634"><a name="p1894526722165634"></a><a name="p1894526722165634"></a>Do something before draw, this function will be invoked mainly to check if this view need to cover invalidate area so render manager can decide which layer to draw firstly. </p>
</td>
</tr>
<tr id="row599842101165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1649595616165634"><a name="p1649595616165634"></a><a name="p1649595616165634"></a><a href="graphic.md#ga8e75f8411fb25e564c82573a12773189">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p53501212165634"><a name="p53501212165634"></a><a name="p53501212165634"></a>void </p>
<p id="p1355593294165634"><a name="p1355593294165634"></a><a name="p1355593294165634"></a>Executes the draw action Ondraw invokes the rendering function provided by the underlying layer to draw pictures based on the selected status of the checkbox. </p>
</td>
</tr>
<tr id="row1821583739165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032823096165634"><a name="p1032823096165634"></a><a name="p1032823096165634"></a><a href="graphic.md#ga31d4f10f4c32b0fb284645450875ae0c">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1705750605165634"><a name="p1705750605165634"></a><a name="p1705750605165634"></a>void </p>
<p id="p1578903277165634"><a name="p1578903277165634"></a><a name="p1578903277165634"></a>Executes the click event action OnClickEvent will reverse the selected state of checkbox. Example: If the check box is selected, the checkbox status is changed to Unselected after the click action is taken. </p>
</td>
</tr>
<tr id="row197077424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034712629165634"><a name="p2034712629165634"></a><a name="p2034712629165634"></a><a href="graphic.md#ga2e1ac9e3084d018febf5ac0912a27c72">SetImages</a> (const char *selectedImageSrc, const char *unselectedImageSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p407186848165634"><a name="p407186848165634"></a><a name="p407186848165634"></a>virtual void </p>
<p id="p1889869578165634"><a name="p1889869578165634"></a><a name="p1889869578165634"></a>Sets the images for this check box. </p>
</td>
</tr>
<tr id="row2101115374165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291068227165634"><a name="p1291068227165634"></a><a name="p1291068227165634"></a><a href="graphic.md#ga89eb87d02e7b31fc6517b8744751f021">SetImages</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *selectedImageSrc, const <a href="ohos-imageinfo.md">ImageInfo</a> *unselectedImageSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787964599165634"><a name="p787964599165634"></a><a name="p787964599165634"></a>virtual void </p>
<p id="p225484929165634"><a name="p225484929165634"></a><a name="p225484929165634"></a>Sets the images for this check box. </p>
</td>
</tr>
<tr id="row683134967165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362333813165634"><a name="p362333813165634"></a><a name="p362333813165634"></a><a href="graphic.md#gab3cddc176a6834fabc7c53912c97237c">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663838995165634"><a name="p1663838995165634"></a><a name="p1663838995165634"></a><a href="graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> </p>
<p id="p596264785165634"><a name="p596264785165634"></a><a name="p596264785165634"></a>Obtains the state of this check box. </p>
</td>
</tr>
<tr id="row1441702070165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638951329165634"><a name="p1638951329165634"></a><a name="p1638951329165634"></a><a href="graphic.md#ga32217050815d4d9129ace5ab410fb82d">SetState</a> (<a href="graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163616029165634"><a name="p1163616029165634"></a><a name="p1163616029165634"></a>void </p>
<p id="p859976627165634"><a name="p859976627165634"></a><a name="p859976627165634"></a>Sets the state for this check box. </p>
</td>
</tr>
<tr id="row1693771741165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1571742696165634"><a name="p1571742696165634"></a><a name="p1571742696165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1547153741165634"><a name="p1547153741165634"></a><a name="p1547153741165634"></a> </p>
<p id="p1037747682165634"><a name="p1037747682165634"></a><a name="p1037747682165634"></a>A default constructor used to create an <strong id="b1970652717165634"><a name="b1970652717165634"></a><a name="b1970652717165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1642216194165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079274684165634"><a name="p2079274684165634"></a><a name="p2079274684165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826758947165634"><a name="p826758947165634"></a><a name="p826758947165634"></a> </p>
<p id="p981668822165634"><a name="p981668822165634"></a><a name="p981668822165634"></a>A constructor used to create an <strong id="b1969612988165634"><a name="b1969612988165634"></a><a name="b1969612988165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2009814737165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673955159165634"><a name="p673955159165634"></a><a name="p673955159165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308537819165634"><a name="p1308537819165634"></a><a name="p1308537819165634"></a>virtual </p>
<p id="p1503529775165634"><a name="p1503529775165634"></a><a name="p1503529775165634"></a>A destructor used to delete the <strong id="b359976132165634"><a name="b359976132165634"></a><a name="b359976132165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1874183578165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p865853664165634"><a name="p865853664165634"></a><a name="p865853664165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p458769133165634"><a name="p458769133165634"></a><a name="p458769133165634"></a>virtual void </p>
<p id="p1477066882165634"><a name="p1477066882165634"></a><a name="p1477066882165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row506468817165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1318516880165634"><a name="p1318516880165634"></a><a name="p1318516880165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p721315483165634"><a name="p721315483165634"></a><a name="p721315483165634"></a>virtual void </p>
<p id="p1438883248165634"><a name="p1438883248165634"></a><a name="p1438883248165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1746541874165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p890795913165634"><a name="p890795913165634"></a><a name="p890795913165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1586935204165634"><a name="p1586935204165634"></a><a name="p1586935204165634"></a>void </p>
<p id="p2045501333165634"><a name="p2045501333165634"></a><a name="p2045501333165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1844570170165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1170406375165634"><a name="p1170406375165634"></a><a name="p1170406375165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368409213165634"><a name="p368409213165634"></a><a name="p368409213165634"></a>void </p>
<p id="p1584995972165634"><a name="p1584995972165634"></a><a name="p1584995972165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row311898671165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459642234165634"><a name="p1459642234165634"></a><a name="p1459642234165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433404788165634"><a name="p433404788165634"></a><a name="p433404788165634"></a>virtual bool </p>
<p id="p1367400914165634"><a name="p1367400914165634"></a><a name="p1367400914165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1771326644165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1076332618165634"><a name="p1076332618165634"></a><a name="p1076332618165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396099579165634"><a name="p396099579165634"></a><a name="p396099579165634"></a>virtual bool </p>
<p id="p2058489757165634"><a name="p2058489757165634"></a><a name="p2058489757165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row128374746165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1653289568165634"><a name="p1653289568165634"></a><a name="p1653289568165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295788033165634"><a name="p1295788033165634"></a><a name="p1295788033165634"></a>virtual bool </p>
<p id="p255576980165634"><a name="p255576980165634"></a><a name="p255576980165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row436179799165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719071684165634"><a name="p1719071684165634"></a><a name="p1719071684165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1792976213165634"><a name="p1792976213165634"></a><a name="p1792976213165634"></a>virtual bool </p>
<p id="p1140524896165634"><a name="p1140524896165634"></a><a name="p1140524896165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1866559605165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1683921818165634"><a name="p1683921818165634"></a><a name="p1683921818165634"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380326242165634"><a name="p380326242165634"></a><a name="p380326242165634"></a>virtual void </p>
<p id="p379871030165634"><a name="p379871030165634"></a><a name="p379871030165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row909087275165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43619282165634"><a name="p43619282165634"></a><a name="p43619282165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p998449032165634"><a name="p998449032165634"></a><a name="p998449032165634"></a>virtual void </p>
<p id="p1652784004165634"><a name="p1652784004165634"></a><a name="p1652784004165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row443685669165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720408325165634"><a name="p1720408325165634"></a><a name="p1720408325165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1056719523165634"><a name="p1056719523165634"></a><a name="p1056719523165634"></a>virtual void </p>
<p id="p719219921165634"><a name="p719219921165634"></a><a name="p719219921165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row2047301008165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223857368165634"><a name="p1223857368165634"></a><a name="p1223857368165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1838180941165634"><a name="p1838180941165634"></a><a name="p1838180941165634"></a>void </p>
<p id="p706019339165634"><a name="p706019339165634"></a><a name="p706019339165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1057554835165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p252149013165634"><a name="p252149013165634"></a><a name="p252149013165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597406951165634"><a name="p1597406951165634"></a><a name="p1597406951165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p146497230165634"><a name="p146497230165634"></a><a name="p146497230165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row144356075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031424721165634"><a name="p1031424721165634"></a><a name="p1031424721165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717242805165634"><a name="p1717242805165634"></a><a name="p1717242805165634"></a>void </p>
<p id="p1099992083165634"><a name="p1099992083165634"></a><a name="p1099992083165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1805858109165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1545728335165634"><a name="p1545728335165634"></a><a name="p1545728335165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p596427677165634"><a name="p596427677165634"></a><a name="p596427677165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1932858412165634"><a name="p1932858412165634"></a><a name="p1932858412165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row457103747165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1615989823165634"><a name="p1615989823165634"></a><a name="p1615989823165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070928551165634"><a name="p1070928551165634"></a><a name="p1070928551165634"></a>void </p>
<p id="p1964708759165634"><a name="p1964708759165634"></a><a name="p1964708759165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1280130757165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1431439854165634"><a name="p1431439854165634"></a><a name="p1431439854165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p452062836165634"><a name="p452062836165634"></a><a name="p452062836165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1257367304165634"><a name="p1257367304165634"></a><a name="p1257367304165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1644132799165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1745706979165634"><a name="p1745706979165634"></a><a name="p1745706979165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436821153165634"><a name="p1436821153165634"></a><a name="p1436821153165634"></a>void </p>
<p id="p1422521727165634"><a name="p1422521727165634"></a><a name="p1422521727165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row935465078165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206309307165634"><a name="p1206309307165634"></a><a name="p1206309307165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1864703521165634"><a name="p1864703521165634"></a><a name="p1864703521165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p362105713165634"><a name="p362105713165634"></a><a name="p362105713165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1286762481165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471762139165634"><a name="p471762139165634"></a><a name="p471762139165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2108305316165634"><a name="p2108305316165634"></a><a name="p2108305316165634"></a>virtual void </p>
<p id="p435456872165634"><a name="p435456872165634"></a><a name="p435456872165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row301808225165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1017831270165634"><a name="p1017831270165634"></a><a name="p1017831270165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528179432165634"><a name="p528179432165634"></a><a name="p528179432165634"></a>void </p>
<p id="p2115527039165634"><a name="p2115527039165634"></a><a name="p2115527039165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1255648283165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p818779721165634"><a name="p818779721165634"></a><a name="p818779721165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632761996165634"><a name="p1632761996165634"></a><a name="p1632761996165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p570123778165634"><a name="p570123778165634"></a><a name="p570123778165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row350744165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p913255363165634"><a name="p913255363165634"></a><a name="p913255363165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823603142165634"><a name="p1823603142165634"></a><a name="p1823603142165634"></a>void </p>
<p id="p754199931165634"><a name="p754199931165634"></a><a name="p754199931165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row469405663165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114061741165634"><a name="p114061741165634"></a><a name="p114061741165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059629140165634"><a name="p2059629140165634"></a><a name="p2059629140165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p682191390165634"><a name="p682191390165634"></a><a name="p682191390165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row363068992165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1889741188165634"><a name="p1889741188165634"></a><a name="p1889741188165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145577546165634"><a name="p1145577546165634"></a><a name="p1145577546165634"></a>virtual void </p>
<p id="p97537821165634"><a name="p97537821165634"></a><a name="p97537821165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row371253217165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489605071165634"><a name="p1489605071165634"></a><a name="p1489605071165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464375152165634"><a name="p1464375152165634"></a><a name="p1464375152165634"></a>bool </p>
<p id="p881896370165634"><a name="p881896370165634"></a><a name="p881896370165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row689721852165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1829673615165634"><a name="p1829673615165634"></a><a name="p1829673615165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174956531165634"><a name="p1174956531165634"></a><a name="p1174956531165634"></a>void </p>
<p id="p108608229165634"><a name="p108608229165634"></a><a name="p108608229165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row547824855165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1379440206165634"><a name="p1379440206165634"></a><a name="p1379440206165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1736965708165634"><a name="p1736965708165634"></a><a name="p1736965708165634"></a>bool </p>
<p id="p440156130165634"><a name="p440156130165634"></a><a name="p440156130165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1952536624165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1692400477165634"><a name="p1692400477165634"></a><a name="p1692400477165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234066408165634"><a name="p234066408165634"></a><a name="p234066408165634"></a>void </p>
<p id="p872281660165634"><a name="p872281660165634"></a><a name="p872281660165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row413995703165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1016172543165634"><a name="p1016172543165634"></a><a name="p1016172543165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868343208165634"><a name="p1868343208165634"></a><a name="p1868343208165634"></a>bool </p>
<p id="p145710421165634"><a name="p145710421165634"></a><a name="p145710421165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1691353160165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p636071023165634"><a name="p636071023165634"></a><a name="p636071023165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1573476021165634"><a name="p1573476021165634"></a><a name="p1573476021165634"></a>void </p>
<p id="p945814696165634"><a name="p945814696165634"></a><a name="p945814696165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row26314212165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853257882165634"><a name="p853257882165634"></a><a name="p853257882165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1104292603165634"><a name="p1104292603165634"></a><a name="p1104292603165634"></a>bool </p>
<p id="p1040836648165634"><a name="p1040836648165634"></a><a name="p1040836648165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row2058018496165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1215111328165634"><a name="p1215111328165634"></a><a name="p1215111328165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p522836130165634"><a name="p522836130165634"></a><a name="p522836130165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p533452225165634"><a name="p533452225165634"></a><a name="p533452225165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1815970075165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1414873883165634"><a name="p1414873883165634"></a><a name="p1414873883165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2146089032165634"><a name="p2146089032165634"></a><a name="p2146089032165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1192255652165634"><a name="p1192255652165634"></a><a name="p1192255652165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row813463624165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212516887165634"><a name="p212516887165634"></a><a name="p212516887165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1915137336165634"><a name="p1915137336165634"></a><a name="p1915137336165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1088015372165634"><a name="p1088015372165634"></a><a name="p1088015372165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row26077237165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118898389165634"><a name="p118898389165634"></a><a name="p118898389165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1908310087165634"><a name="p1908310087165634"></a><a name="p1908310087165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1475303307165634"><a name="p1475303307165634"></a><a name="p1475303307165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row929974562165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2054111166165634"><a name="p2054111166165634"></a><a name="p2054111166165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544977899165634"><a name="p1544977899165634"></a><a name="p1544977899165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p522371586165634"><a name="p522371586165634"></a><a name="p522371586165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row2054222890165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1414477705165634"><a name="p1414477705165634"></a><a name="p1414477705165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019143633165634"><a name="p1019143633165634"></a><a name="p1019143633165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p935053252165634"><a name="p935053252165634"></a><a name="p935053252165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1507097008165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300942548165634"><a name="p1300942548165634"></a><a name="p1300942548165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1783710241165634"><a name="p1783710241165634"></a><a name="p1783710241165634"></a>void </p>
<p id="p1504836856165634"><a name="p1504836856165634"></a><a name="p1504836856165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1664726340165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624152091165634"><a name="p624152091165634"></a><a name="p624152091165634"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216309433165634"><a name="p216309433165634"></a><a name="p216309433165634"></a>virtual void </p>
<p id="p648354416165634"><a name="p648354416165634"></a><a name="p648354416165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row122613447165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1903351912165634"><a name="p1903351912165634"></a><a name="p1903351912165634"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861170409165634"><a name="p861170409165634"></a><a name="p861170409165634"></a>virtual int16_t </p>
<p id="p1719391043165634"><a name="p1719391043165634"></a><a name="p1719391043165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row723343021165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p459995330165634"><a name="p459995330165634"></a><a name="p459995330165634"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441472575165634"><a name="p1441472575165634"></a><a name="p1441472575165634"></a>virtual void </p>
<p id="p296126501165634"><a name="p296126501165634"></a><a name="p296126501165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row752868398165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674318545165634"><a name="p674318545165634"></a><a name="p674318545165634"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1814431888165634"><a name="p1814431888165634"></a><a name="p1814431888165634"></a>virtual int16_t </p>
<p id="p1944875577165634"><a name="p1944875577165634"></a><a name="p1944875577165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1196211743165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1168964909165634"><a name="p1168964909165634"></a><a name="p1168964909165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p961965227165634"><a name="p961965227165634"></a><a name="p961965227165634"></a>virtual void </p>
<p id="p194740462165634"><a name="p194740462165634"></a><a name="p194740462165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1395144645165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p704000646165634"><a name="p704000646165634"></a><a name="p704000646165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2062935977165634"><a name="p2062935977165634"></a><a name="p2062935977165634"></a>virtual void </p>
<p id="p1992693249165634"><a name="p1992693249165634"></a><a name="p1992693249165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1340282006165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139613746165634"><a name="p2139613746165634"></a><a name="p2139613746165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647404017165634"><a name="p647404017165634"></a><a name="p647404017165634"></a>int16_t </p>
<p id="p1971855543165634"><a name="p1971855543165634"></a><a name="p1971855543165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row860583124165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2085362614165634"><a name="p2085362614165634"></a><a name="p2085362614165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1929031280165634"><a name="p1929031280165634"></a><a name="p1929031280165634"></a>virtual void </p>
<p id="p1509491105165634"><a name="p1509491105165634"></a><a name="p1509491105165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1527763404165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p776335676165634"><a name="p776335676165634"></a><a name="p776335676165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1167015866165634"><a name="p1167015866165634"></a><a name="p1167015866165634"></a>int16_t </p>
<p id="p1571572593165634"><a name="p1571572593165634"></a><a name="p1571572593165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row357190063165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229301921165634"><a name="p229301921165634"></a><a name="p229301921165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1136385302165634"><a name="p1136385302165634"></a><a name="p1136385302165634"></a>virtual void </p>
<p id="p1249124356165634"><a name="p1249124356165634"></a><a name="p1249124356165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row534814323165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2062426198165634"><a name="p2062426198165634"></a><a name="p2062426198165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p567117407165634"><a name="p567117407165634"></a><a name="p567117407165634"></a>virtual void </p>
<p id="p1903192667165634"><a name="p1903192667165634"></a><a name="p1903192667165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row544791235165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009002341165634"><a name="p1009002341165634"></a><a name="p1009002341165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p235645208165634"><a name="p235645208165634"></a><a name="p235645208165634"></a>bool </p>
<p id="p147233077165634"><a name="p147233077165634"></a><a name="p147233077165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1759024920165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p869913531165634"><a name="p869913531165634"></a><a name="p869913531165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1991037656165634"><a name="p1991037656165634"></a><a name="p1991037656165634"></a>void </p>
<p id="p702788952165634"><a name="p702788952165634"></a><a name="p702788952165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row780932277165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982301518165634"><a name="p1982301518165634"></a><a name="p1982301518165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434389542165634"><a name="p434389542165634"></a><a name="p434389542165634"></a>void </p>
<p id="p137062684165634"><a name="p137062684165634"></a><a name="p137062684165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1444649364165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p443929292165634"><a name="p443929292165634"></a><a name="p443929292165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p753403982165634"><a name="p753403982165634"></a><a name="p753403982165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p1337840146165634"><a name="p1337840146165634"></a><a name="p1337840146165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row358263480165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p736704179165634"><a name="p736704179165634"></a><a name="p736704179165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289838876165634"><a name="p289838876165634"></a><a name="p289838876165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1836810998165634"><a name="p1836810998165634"></a><a name="p1836810998165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row1350874767165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p297212503165634"><a name="p297212503165634"></a><a name="p297212503165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p67885465165634"><a name="p67885465165634"></a><a name="p67885465165634"></a>void </p>
<p id="p346259329165634"><a name="p346259329165634"></a><a name="p346259329165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1160474993165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1471273524165634"><a name="p1471273524165634"></a><a name="p1471273524165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084187379165634"><a name="p2084187379165634"></a><a name="p2084187379165634"></a>const char * </p>
<p id="p1845569621165634"><a name="p1845569621165634"></a><a name="p1845569621165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1034937501165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348113467165634"><a name="p1348113467165634"></a><a name="p1348113467165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1280801864165634"><a name="p1280801864165634"></a><a name="p1280801864165634"></a>void </p>
<p id="p1403768076165634"><a name="p1403768076165634"></a><a name="p1403768076165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row623478012165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377602982165634"><a name="p377602982165634"></a><a name="p377602982165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653377930165634"><a name="p1653377930165634"></a><a name="p1653377930165634"></a>int16_t </p>
<p id="p1460135611165634"><a name="p1460135611165634"></a><a name="p1460135611165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1687867049165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p97532432165634"><a name="p97532432165634"></a><a name="p97532432165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p634314443165634"><a name="p634314443165634"></a><a name="p634314443165634"></a>virtual void </p>
<p id="p1670510535165634"><a name="p1670510535165634"></a><a name="p1670510535165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row549180571165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732421413165634"><a name="p1732421413165634"></a><a name="p1732421413165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p857790241165634"><a name="p857790241165634"></a><a name="p857790241165634"></a>void </p>
<p id="p570802346165634"><a name="p570802346165634"></a><a name="p570802346165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1683229764165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p161391382165634"><a name="p161391382165634"></a><a name="p161391382165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565659335165634"><a name="p565659335165634"></a><a name="p565659335165634"></a>void </p>
<p id="p1675349635165634"><a name="p1675349635165634"></a><a name="p1675349635165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1369847662165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1771539898165634"><a name="p1771539898165634"></a><a name="p1771539898165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p357516964165634"><a name="p357516964165634"></a><a name="p357516964165634"></a>void </p>
<p id="p32514992165634"><a name="p32514992165634"></a><a name="p32514992165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1187297475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2134668846165634"><a name="p2134668846165634"></a><a name="p2134668846165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267422445165634"><a name="p267422445165634"></a><a name="p267422445165634"></a>void </p>
<p id="p854240325165634"><a name="p854240325165634"></a><a name="p854240325165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row659880487165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169928976165634"><a name="p169928976165634"></a><a name="p169928976165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1032103103165634"><a name="p1032103103165634"></a><a name="p1032103103165634"></a>void </p>
<p id="p1522051622165634"><a name="p1522051622165634"></a><a name="p1522051622165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1810541521165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772445392165634"><a name="p1772445392165634"></a><a name="p1772445392165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2013556752165634"><a name="p2013556752165634"></a><a name="p2013556752165634"></a>void </p>
<p id="p496218314165634"><a name="p496218314165634"></a><a name="p496218314165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1678292592165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462269155165634"><a name="p1462269155165634"></a><a name="p1462269155165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580862323165634"><a name="p580862323165634"></a><a name="p580862323165634"></a>void </p>
<p id="p1628369862165634"><a name="p1628369862165634"></a><a name="p1628369862165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1041507465165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149849791165634"><a name="p1149849791165634"></a><a name="p1149849791165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672309631165634"><a name="p1672309631165634"></a><a name="p1672309631165634"></a>void </p>
<p id="p491672506165634"><a name="p491672506165634"></a><a name="p491672506165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row751008055165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2134316622165634"><a name="p2134316622165634"></a><a name="p2134316622165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519728813165634"><a name="p519728813165634"></a><a name="p519728813165634"></a>void </p>
<p id="p1185158417165634"><a name="p1185158417165634"></a><a name="p1185158417165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1301723037165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1970069691165634"><a name="p1970069691165634"></a><a name="p1970069691165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p170565053165634"><a name="p170565053165634"></a><a name="p170565053165634"></a>void </p>
<p id="p1212162270165634"><a name="p1212162270165634"></a><a name="p1212162270165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1670694012165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p764223148165634"><a name="p764223148165634"></a><a name="p764223148165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103766762165634"><a name="p103766762165634"></a><a name="p103766762165634"></a>void </p>
<p id="p1872116132165634"><a name="p1872116132165634"></a><a name="p1872116132165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row200026835165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136622467165634"><a name="p136622467165634"></a><a name="p136622467165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145185858165634"><a name="p1145185858165634"></a><a name="p1145185858165634"></a>void </p>
<p id="p671036570165634"><a name="p671036570165634"></a><a name="p671036570165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row491741118165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1169811071165634"><a name="p1169811071165634"></a><a name="p1169811071165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2099388868165634"><a name="p2099388868165634"></a><a name="p2099388868165634"></a>void </p>
<p id="p887870593165634"><a name="p887870593165634"></a><a name="p887870593165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1678726322165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76818521165634"><a name="p76818521165634"></a><a name="p76818521165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p23631879165634"><a name="p23631879165634"></a><a name="p23631879165634"></a>void </p>
<p id="p1194118393165634"><a name="p1194118393165634"></a><a name="p1194118393165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1809368725165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1914458839165634"><a name="p1914458839165634"></a><a name="p1914458839165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759300635165634"><a name="p1759300635165634"></a><a name="p1759300635165634"></a>void </p>
<p id="p1953441661165634"><a name="p1953441661165634"></a><a name="p1953441661165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1079099608165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2060224571165634"><a name="p2060224571165634"></a><a name="p2060224571165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913325534165634"><a name="p1913325534165634"></a><a name="p1913325534165634"></a>void </p>
<p id="p453337631165634"><a name="p453337631165634"></a><a name="p453337631165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row931738144165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1580743060165634"><a name="p1580743060165634"></a><a name="p1580743060165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786674909165634"><a name="p786674909165634"></a><a name="p786674909165634"></a>virtual void </p>
<p id="p778989253165634"><a name="p778989253165634"></a><a name="p778989253165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row786524326165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1689902145165634"><a name="p1689902145165634"></a><a name="p1689902145165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p907302084165634"><a name="p907302084165634"></a><a name="p907302084165634"></a>virtual int64_t </p>
<p id="p438657538165634"><a name="p438657538165634"></a><a name="p438657538165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row140197182165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1680982287165634"><a name="p1680982287165634"></a><a name="p1680982287165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1056064510165634"><a name="p1056064510165634"></a><a name="p1056064510165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p68338966165634"><a name="p68338966165634"></a><a name="p68338966165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1532048647165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1773275860165634"><a name="p1773275860165634"></a><a name="p1773275860165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1561434742165634"><a name="p1561434742165634"></a><a name="p1561434742165634"></a>void * </p>
<p id="p1503577865165634"><a name="p1503577865165634"></a><a name="p1503577865165634"></a>Overrides the <strong id="b1090212549165634"><a name="b1090212549165634"></a><a name="b1090212549165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row581491353165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654760825165634"><a name="p654760825165634"></a><a name="p654760825165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454280589165634"><a name="p454280589165634"></a><a name="p454280589165634"></a>void </p>
<p id="p1258480806165634"><a name="p1258480806165634"></a><a name="p1258480806165634"></a>Overrides the <strong id="b943223838165634"><a name="b943223838165634"></a><a name="b943223838165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

