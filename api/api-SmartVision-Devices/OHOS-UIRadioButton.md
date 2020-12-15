# OHOS::UIRadioButton<a name="ZH-CN_TOPIC_0000001054879558"></a>

-   [Overview](#section669252138165634)
-   [Summary](#section343087513165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section669252138165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a radio button. 

Only one option can be selected with the radio button.

See also
:   [UICheckBox](OHOS-UICheckBox.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section343087513165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table649985958165634"></a>
<table><thead align="left"><tr id="row1952928415165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1639094636165634"><a name="p1639094636165634"></a><a name="p1639094636165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1639284917165634"><a name="p1639284917165634"></a><a name="p1639284917165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row812951475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p562873131165634"><a name="p562873131165634"></a><a name="p562873131165634"></a><a href="Graphic.md#gaae79b6ffd2b156a8d42263a322985284">UIRadioButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504538796165634"><a name="p1504538796165634"></a><a name="p1504538796165634"></a> </p>
<p id="p1325369100165634"><a name="p1325369100165634"></a><a name="p1325369100165634"></a>A constructor used to create a <strong id="b426279293165634"><a name="b426279293165634"></a><a name="b426279293165634"></a><a href="OHOS-UIRadioButton.md">UIRadioButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1295788902165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447689205165634"><a name="p1447689205165634"></a><a name="p1447689205165634"></a><a href="Graphic.md#ga9b48f8664f04f08b94dca2e0b3821595">UIRadioButton</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1397591352165634"><a name="p1397591352165634"></a><a name="p1397591352165634"></a>  </p>
<p id="p1166596203165634"><a name="p1166596203165634"></a><a name="p1166596203165634"></a>Default constructor. </p>
</td>
</tr>
<tr id="row627023947165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1337333225165634"><a name="p1337333225165634"></a><a name="p1337333225165634"></a><a href="Graphic.md#ga1b9fbd5840829e912aa4013a343e7b36">~UIRadioButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913327904165634"><a name="p1913327904165634"></a><a name="p1913327904165634"></a>virtual </p>
<p id="p264819253165634"><a name="p264819253165634"></a><a name="p264819253165634"></a>A destructor used to delete the <strong id="b2082461717165634"><a name="b2082461717165634"></a><a name="b2082461717165634"></a><a href="OHOS-UIRadioButton.md">UIRadioButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row5156760165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219206680165634"><a name="p1219206680165634"></a><a name="p1219206680165634"></a><a href="Graphic.md#ga2efe6a87345903726c721fc7a9ed4365">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p437348214165634"><a name="p437348214165634"></a><a name="p437348214165634"></a>UIViewType </p>
<p id="p183147137165634"><a name="p183147137165634"></a><a name="p183147137165634"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row1106577174165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p656730229165634"><a name="p656730229165634"></a><a name="p656730229165634"></a><a href="Graphic.md#gade9069f6e553c6c43f7684e835b584e5">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285454696165634"><a name="p285454696165634"></a><a name="p285454696165634"></a>bool </p>
<p id="p193724341165634"><a name="p193724341165634"></a><a name="p193724341165634"></a>Do something before draw, this function will be invoked mainly to check if this view need to cover invalidate area so render manager can decide which layer to draw firstly. </p>
</td>
</tr>
<tr id="row928592382165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862547987165634"><a name="p862547987165634"></a><a name="p862547987165634"></a><a href="Graphic.md#ga7b6849c94b9d8b90cbbe890790fedf1e">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2074157480165634"><a name="p2074157480165634"></a><a name="p2074157480165634"></a>void </p>
<p id="p660444417165634"><a name="p660444417165634"></a><a name="p660444417165634"></a>Executes the click event action OnClickEvent will reverse the selected state of checkbox. Example: If the check box is selected, the checkbox status is changed to Unselected after the click action is taken. </p>
</td>
</tr>
<tr id="row1059205366165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995679070165634"><a name="p1995679070165634"></a><a name="p1995679070165634"></a><a href="Graphic.md#gad56eb918dbfec65f8f596572a9911286">SetName</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446670612165634"><a name="p446670612165634"></a><a name="p446670612165634"></a>void </p>
<p id="p561817874165634"><a name="p561817874165634"></a><a name="p561817874165634"></a>Sets the name for this radio button. </p>
</td>
</tr>
<tr id="row624067474165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p774638851165634"><a name="p774638851165634"></a><a name="p774638851165634"></a><a href="Graphic.md#ga7d2125ee509f1555888549277f31a7a7">GetName</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786014884165634"><a name="p1786014884165634"></a><a name="p1786014884165634"></a>const char * </p>
<p id="p166845633165634"><a name="p166845633165634"></a><a name="p166845633165634"></a>Obtains the name of this radio button. </p>
</td>
</tr>
<tr id="row364727626165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1011098427165634"><a name="p1011098427165634"></a><a name="p1011098427165634"></a><a href="Graphic.md#ga811085fbe237690f21a95e7df2a7c45f">UICheckBox</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p497708698165634"><a name="p497708698165634"></a><a name="p497708698165634"></a> </p>
<p id="p346714812165634"><a name="p346714812165634"></a><a name="p346714812165634"></a>A constructor used to create a <strong id="b1497904991165634"><a name="b1497904991165634"></a><a name="b1497904991165634"></a><a href="OHOS-UICheckBox.md">UICheckBox</a></strong> instance. </p>
</td>
</tr>
<tr id="row860080312165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p837377487165634"><a name="p837377487165634"></a><a name="p837377487165634"></a><a href="Graphic.md#ga061c90b24caa6595b70a9da9f96c5c4e">~UICheckBox</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p286162937165634"><a name="p286162937165634"></a><a name="p286162937165634"></a>virtual </p>
<p id="p297337847165634"><a name="p297337847165634"></a><a name="p297337847165634"></a>A destructor used to delete the <strong id="b2057262798165634"><a name="b2057262798165634"></a><a name="b2057262798165634"></a><a href="OHOS-UICheckBox.md">UICheckBox</a></strong> instance. </p>
</td>
</tr>
<tr id="row1383175493165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1932970414165634"><a name="p1932970414165634"></a><a name="p1932970414165634"></a><a href="Graphic.md#gad72c8f6a67fc3fb86da8eabffcf5315d">SetOnChangeListener</a> (<a href="OHOS-UICheckBox-OnChangeListener.md">OnChangeListener</a> *onStateChangeListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p192039095165634"><a name="p192039095165634"></a><a name="p192039095165634"></a>void </p>
<p id="p1842747127165634"><a name="p1842747127165634"></a><a name="p1842747127165634"></a>Sets the listener for this check box. </p>
</td>
</tr>
<tr id="row1355337856165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884938125165634"><a name="p884938125165634"></a><a name="p884938125165634"></a><a href="Graphic.md#ga8e75f8411fb25e564c82573a12773189">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p365670467165634"><a name="p365670467165634"></a><a name="p365670467165634"></a>void </p>
<p id="p989259364165634"><a name="p989259364165634"></a><a name="p989259364165634"></a>Executes the draw action Ondraw invokes the rendering function provided by the underlying layer to draw pictures based on the selected status of the checkbox. </p>
</td>
</tr>
<tr id="row507343525165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775405605165634"><a name="p1775405605165634"></a><a name="p1775405605165634"></a><a href="Graphic.md#ga2e1ac9e3084d018febf5ac0912a27c72">SetImages</a> (const char *selectedImageSrc, const char *unselectedImageSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028246483165634"><a name="p1028246483165634"></a><a name="p1028246483165634"></a>virtual void </p>
<p id="p427556967165634"><a name="p427556967165634"></a><a name="p427556967165634"></a>Sets the images for this check box. </p>
</td>
</tr>
<tr id="row113118224165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1426704682165634"><a name="p1426704682165634"></a><a name="p1426704682165634"></a><a href="Graphic.md#ga89eb87d02e7b31fc6517b8744751f021">SetImages</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *selectedImageSrc, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *unselectedImageSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p405849870165634"><a name="p405849870165634"></a><a name="p405849870165634"></a>virtual void </p>
<p id="p350856581165634"><a name="p350856581165634"></a><a name="p350856581165634"></a>Sets the images for this check box. </p>
</td>
</tr>
<tr id="row166231512165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p918581170165634"><a name="p918581170165634"></a><a name="p918581170165634"></a><a href="Graphic.md#gab3cddc176a6834fabc7c53912c97237c">GetState</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743746336165634"><a name="p743746336165634"></a><a name="p743746336165634"></a><a href="Graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> </p>
<p id="p2005590197165634"><a name="p2005590197165634"></a><a name="p2005590197165634"></a>Obtains the state of this check box. </p>
</td>
</tr>
<tr id="row1434931640165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2045077250165634"><a name="p2045077250165634"></a><a name="p2045077250165634"></a><a href="Graphic.md#ga32217050815d4d9129ace5ab410fb82d">SetState</a> (<a href="Graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p296011399165634"><a name="p296011399165634"></a><a name="p296011399165634"></a>void </p>
<p id="p1852374364165634"><a name="p1852374364165634"></a><a name="p1852374364165634"></a>Sets the state for this check box. </p>
</td>
</tr>
<tr id="row2080570065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005310297165634"><a name="p2005310297165634"></a><a name="p2005310297165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268580068165634"><a name="p1268580068165634"></a><a name="p1268580068165634"></a> </p>
<p id="p1413263544165634"><a name="p1413263544165634"></a><a name="p1413263544165634"></a>A default constructor used to create an <strong id="b255170579165634"><a name="b255170579165634"></a><a name="b255170579165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row778163821165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1507766877165634"><a name="p1507766877165634"></a><a name="p1507766877165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1616868767165634"><a name="p1616868767165634"></a><a name="p1616868767165634"></a> </p>
<p id="p486368665165634"><a name="p486368665165634"></a><a name="p486368665165634"></a>A constructor used to create an <strong id="b1381257584165634"><a name="b1381257584165634"></a><a name="b1381257584165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1231156298165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p218386299165634"><a name="p218386299165634"></a><a name="p218386299165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1588238761165634"><a name="p1588238761165634"></a><a name="p1588238761165634"></a>virtual </p>
<p id="p670046042165634"><a name="p670046042165634"></a><a name="p670046042165634"></a>A destructor used to delete the <strong id="b116167777165634"><a name="b116167777165634"></a><a name="b116167777165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row611858656165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1867913380165634"><a name="p1867913380165634"></a><a name="p1867913380165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1254701717165634"><a name="p1254701717165634"></a><a name="p1254701717165634"></a>virtual void </p>
<p id="p1601812723165634"><a name="p1601812723165634"></a><a name="p1601812723165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1512347282165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269113550165634"><a name="p1269113550165634"></a><a name="p1269113550165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343240738165634"><a name="p343240738165634"></a><a name="p343240738165634"></a>virtual void </p>
<p id="p669354267165634"><a name="p669354267165634"></a><a name="p669354267165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row316216654165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p149429453165634"><a name="p149429453165634"></a><a name="p149429453165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419862447165634"><a name="p1419862447165634"></a><a name="p1419862447165634"></a>void </p>
<p id="p1311118049165634"><a name="p1311118049165634"></a><a name="p1311118049165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1636506634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560027991165634"><a name="p560027991165634"></a><a name="p560027991165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629053491165634"><a name="p1629053491165634"></a><a name="p1629053491165634"></a>void </p>
<p id="p1876730742165634"><a name="p1876730742165634"></a><a name="p1876730742165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row747896590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14829171165634"><a name="p14829171165634"></a><a name="p14829171165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091968275165634"><a name="p1091968275165634"></a><a name="p1091968275165634"></a>virtual bool </p>
<p id="p120603149165634"><a name="p120603149165634"></a><a name="p120603149165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1335698663165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p968901117165634"><a name="p968901117165634"></a><a name="p968901117165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282851742165634"><a name="p1282851742165634"></a><a name="p1282851742165634"></a>virtual bool </p>
<p id="p196360628165634"><a name="p196360628165634"></a><a name="p196360628165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row900324479165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1534046089165634"><a name="p1534046089165634"></a><a name="p1534046089165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911136428165634"><a name="p1911136428165634"></a><a name="p1911136428165634"></a>virtual bool </p>
<p id="p90581253165634"><a name="p90581253165634"></a><a name="p90581253165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row613518868165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62964693165634"><a name="p62964693165634"></a><a name="p62964693165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1371530429165634"><a name="p1371530429165634"></a><a name="p1371530429165634"></a>virtual bool </p>
<p id="p62128805165634"><a name="p62128805165634"></a><a name="p62128805165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row213217082165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p165509238165634"><a name="p165509238165634"></a><a name="p165509238165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1280586738165634"><a name="p1280586738165634"></a><a name="p1280586738165634"></a>virtual void </p>
<p id="p644341072165634"><a name="p644341072165634"></a><a name="p644341072165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1224325674165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551054198165634"><a name="p1551054198165634"></a><a name="p1551054198165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p604011566165634"><a name="p604011566165634"></a><a name="p604011566165634"></a>virtual void </p>
<p id="p1564668344165634"><a name="p1564668344165634"></a><a name="p1564668344165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row241229667165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284394174165634"><a name="p284394174165634"></a><a name="p284394174165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125200973165634"><a name="p125200973165634"></a><a name="p125200973165634"></a>virtual void </p>
<p id="p891981510165634"><a name="p891981510165634"></a><a name="p891981510165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row340601828165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540813041165634"><a name="p1540813041165634"></a><a name="p1540813041165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1622520512165634"><a name="p1622520512165634"></a><a name="p1622520512165634"></a>void </p>
<p id="p1291442977165634"><a name="p1291442977165634"></a><a name="p1291442977165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1150548295165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1340918455165634"><a name="p1340918455165634"></a><a name="p1340918455165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p342870058165634"><a name="p342870058165634"></a><a name="p342870058165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p206859299165634"><a name="p206859299165634"></a><a name="p206859299165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1139375008165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p395122669165634"><a name="p395122669165634"></a><a name="p395122669165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828248650165634"><a name="p1828248650165634"></a><a name="p1828248650165634"></a>void </p>
<p id="p1681548766165634"><a name="p1681548766165634"></a><a name="p1681548766165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row349464842165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1952188951165634"><a name="p1952188951165634"></a><a name="p1952188951165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p307160224165634"><a name="p307160224165634"></a><a name="p307160224165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p20730078165634"><a name="p20730078165634"></a><a name="p20730078165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row269715192165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p409473455165634"><a name="p409473455165634"></a><a name="p409473455165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1516465895165634"><a name="p1516465895165634"></a><a name="p1516465895165634"></a>void </p>
<p id="p1211767657165634"><a name="p1211767657165634"></a><a name="p1211767657165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row768081848165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276921796165634"><a name="p1276921796165634"></a><a name="p1276921796165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583931453165634"><a name="p1583931453165634"></a><a name="p1583931453165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1729785721165634"><a name="p1729785721165634"></a><a name="p1729785721165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2106938260165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p238158938165634"><a name="p238158938165634"></a><a name="p238158938165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648233794165634"><a name="p1648233794165634"></a><a name="p1648233794165634"></a>void </p>
<p id="p1066312831165634"><a name="p1066312831165634"></a><a name="p1066312831165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row2116264966165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111561397165634"><a name="p1111561397165634"></a><a name="p1111561397165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457471715165634"><a name="p457471715165634"></a><a name="p457471715165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1759239018165634"><a name="p1759239018165634"></a><a name="p1759239018165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row206627332165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468083045165634"><a name="p1468083045165634"></a><a name="p1468083045165634"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766213406165634"><a name="p766213406165634"></a><a name="p766213406165634"></a>virtual void </p>
<p id="p679336917165634"><a name="p679336917165634"></a><a name="p679336917165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row220068140165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p896021915165634"><a name="p896021915165634"></a><a name="p896021915165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p537577529165634"><a name="p537577529165634"></a><a name="p537577529165634"></a>void </p>
<p id="p1847158730165634"><a name="p1847158730165634"></a><a name="p1847158730165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row2091466127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1808150427165634"><a name="p1808150427165634"></a><a name="p1808150427165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647779826165634"><a name="p647779826165634"></a><a name="p647779826165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1802993262165634"><a name="p1802993262165634"></a><a name="p1802993262165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row2129717416165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98717532165634"><a name="p98717532165634"></a><a name="p98717532165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1270604101165634"><a name="p1270604101165634"></a><a name="p1270604101165634"></a>void </p>
<p id="p2022075818165634"><a name="p2022075818165634"></a><a name="p2022075818165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row566920844165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1000548917165634"><a name="p1000548917165634"></a><a name="p1000548917165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552897153165634"><a name="p552897153165634"></a><a name="p552897153165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1104037829165634"><a name="p1104037829165634"></a><a name="p1104037829165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1473978915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1913621397165634"><a name="p1913621397165634"></a><a name="p1913621397165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182335697165634"><a name="p182335697165634"></a><a name="p182335697165634"></a>virtual void </p>
<p id="p1196016454165634"><a name="p1196016454165634"></a><a name="p1196016454165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1253919787165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p281762907165634"><a name="p281762907165634"></a><a name="p281762907165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2079936065165634"><a name="p2079936065165634"></a><a name="p2079936065165634"></a>bool </p>
<p id="p581803893165634"><a name="p581803893165634"></a><a name="p581803893165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row176932912165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943141878165634"><a name="p1943141878165634"></a><a name="p1943141878165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394649540165634"><a name="p1394649540165634"></a><a name="p1394649540165634"></a>void </p>
<p id="p565545791165634"><a name="p565545791165634"></a><a name="p565545791165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row16603901165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p817767555165634"><a name="p817767555165634"></a><a name="p817767555165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p849949848165634"><a name="p849949848165634"></a><a name="p849949848165634"></a>bool </p>
<p id="p391313865165634"><a name="p391313865165634"></a><a name="p391313865165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row698223365165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p974976780165634"><a name="p974976780165634"></a><a name="p974976780165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016461169165634"><a name="p1016461169165634"></a><a name="p1016461169165634"></a>void </p>
<p id="p746884514165634"><a name="p746884514165634"></a><a name="p746884514165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row908742190165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1792804509165634"><a name="p1792804509165634"></a><a name="p1792804509165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904257192165634"><a name="p904257192165634"></a><a name="p904257192165634"></a>bool </p>
<p id="p549572122165634"><a name="p549572122165634"></a><a name="p549572122165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row238130142165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1928349335165634"><a name="p1928349335165634"></a><a name="p1928349335165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2057442300165634"><a name="p2057442300165634"></a><a name="p2057442300165634"></a>void </p>
<p id="p1046990600165634"><a name="p1046990600165634"></a><a name="p1046990600165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row827624081165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632905223165634"><a name="p632905223165634"></a><a name="p632905223165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1230563579165634"><a name="p1230563579165634"></a><a name="p1230563579165634"></a>bool </p>
<p id="p2115305294165634"><a name="p2115305294165634"></a><a name="p2115305294165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1627100052165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1464628564165634"><a name="p1464628564165634"></a><a name="p1464628564165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462720352165634"><a name="p1462720352165634"></a><a name="p1462720352165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1556043792165634"><a name="p1556043792165634"></a><a name="p1556043792165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1552672925165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1069106242165634"><a name="p1069106242165634"></a><a name="p1069106242165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p699495928165634"><a name="p699495928165634"></a><a name="p699495928165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1270935932165634"><a name="p1270935932165634"></a><a name="p1270935932165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1082650694165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122673403165634"><a name="p122673403165634"></a><a name="p122673403165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p158192298165634"><a name="p158192298165634"></a><a name="p158192298165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1604361588165634"><a name="p1604361588165634"></a><a name="p1604361588165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row2916794165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p474376831165634"><a name="p474376831165634"></a><a name="p474376831165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p930229851165634"><a name="p930229851165634"></a><a name="p930229851165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2053091623165634"><a name="p2053091623165634"></a><a name="p2053091623165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row2109872522165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1822206340165634"><a name="p1822206340165634"></a><a name="p1822206340165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p693133382165634"><a name="p693133382165634"></a><a name="p693133382165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1182448653165634"><a name="p1182448653165634"></a><a name="p1182448653165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1009849778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439478970165634"><a name="p1439478970165634"></a><a name="p1439478970165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1061973183165634"><a name="p1061973183165634"></a><a name="p1061973183165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p594562444165634"><a name="p594562444165634"></a><a name="p594562444165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1027157257165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286319661165634"><a name="p1286319661165634"></a><a name="p1286319661165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1411984411165634"><a name="p1411984411165634"></a><a name="p1411984411165634"></a>void </p>
<p id="p2119856248165634"><a name="p2119856248165634"></a><a name="p2119856248165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1817845549165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p105133374165634"><a name="p105133374165634"></a><a name="p105133374165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2106374770165634"><a name="p2106374770165634"></a><a name="p2106374770165634"></a>virtual void </p>
<p id="p2101982300165634"><a name="p2101982300165634"></a><a name="p2101982300165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row478134792165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2077652217165634"><a name="p2077652217165634"></a><a name="p2077652217165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2826609165634"><a name="p2826609165634"></a><a name="p2826609165634"></a>virtual int16_t </p>
<p id="p1204965492165634"><a name="p1204965492165634"></a><a name="p1204965492165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1738442795165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904034017165634"><a name="p1904034017165634"></a><a name="p1904034017165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138160646165634"><a name="p138160646165634"></a><a name="p138160646165634"></a>virtual void </p>
<p id="p218044244165634"><a name="p218044244165634"></a><a name="p218044244165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row484880592165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1602310339165634"><a name="p1602310339165634"></a><a name="p1602310339165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p54956882165634"><a name="p54956882165634"></a><a name="p54956882165634"></a>virtual int16_t </p>
<p id="p220152432165634"><a name="p220152432165634"></a><a name="p220152432165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1977463018165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1643674940165634"><a name="p1643674940165634"></a><a name="p1643674940165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p920640005165634"><a name="p920640005165634"></a><a name="p920640005165634"></a>virtual void </p>
<p id="p722236967165634"><a name="p722236967165634"></a><a name="p722236967165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1523584100165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560803753165634"><a name="p1560803753165634"></a><a name="p1560803753165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p555257926165634"><a name="p555257926165634"></a><a name="p555257926165634"></a>virtual void </p>
<p id="p48884218165634"><a name="p48884218165634"></a><a name="p48884218165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row530750278165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p273640450165634"><a name="p273640450165634"></a><a name="p273640450165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p195852706165634"><a name="p195852706165634"></a><a name="p195852706165634"></a>int16_t </p>
<p id="p479420264165634"><a name="p479420264165634"></a><a name="p479420264165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row693090038165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p318690497165634"><a name="p318690497165634"></a><a name="p318690497165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1148179548165634"><a name="p1148179548165634"></a><a name="p1148179548165634"></a>virtual void </p>
<p id="p297914325165634"><a name="p297914325165634"></a><a name="p297914325165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1310884198165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994409218165634"><a name="p1994409218165634"></a><a name="p1994409218165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p886590109165634"><a name="p886590109165634"></a><a name="p886590109165634"></a>int16_t </p>
<p id="p285561797165634"><a name="p285561797165634"></a><a name="p285561797165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1254117154165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1237750056165634"><a name="p1237750056165634"></a><a name="p1237750056165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292144537165634"><a name="p1292144537165634"></a><a name="p1292144537165634"></a>virtual void </p>
<p id="p1099188839165634"><a name="p1099188839165634"></a><a name="p1099188839165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row353150411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313552407165634"><a name="p313552407165634"></a><a name="p313552407165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035467608165634"><a name="p1035467608165634"></a><a name="p1035467608165634"></a>virtual void </p>
<p id="p972859163165634"><a name="p972859163165634"></a><a name="p972859163165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1225995980165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078669926165634"><a name="p2078669926165634"></a><a name="p2078669926165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p878953042165634"><a name="p878953042165634"></a><a name="p878953042165634"></a>bool </p>
<p id="p129125294165634"><a name="p129125294165634"></a><a name="p129125294165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row224588803165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1760906911165634"><a name="p1760906911165634"></a><a name="p1760906911165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156878725165634"><a name="p156878725165634"></a><a name="p156878725165634"></a>void </p>
<p id="p327170550165634"><a name="p327170550165634"></a><a name="p327170550165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row527332744165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866908262165634"><a name="p866908262165634"></a><a name="p866908262165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p574047788165634"><a name="p574047788165634"></a><a name="p574047788165634"></a>void </p>
<p id="p1963212426165634"><a name="p1963212426165634"></a><a name="p1963212426165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row117854281165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058813787165634"><a name="p1058813787165634"></a><a name="p1058813787165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862731822165634"><a name="p1862731822165634"></a><a name="p1862731822165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1866568330165634"><a name="p1866568330165634"></a><a name="p1866568330165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row830412887165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1556411003165634"><a name="p1556411003165634"></a><a name="p1556411003165634"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216816490165634"><a name="p1216816490165634"></a><a name="p1216816490165634"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1024097497165634"><a name="p1024097497165634"></a><a name="p1024097497165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row1203171443165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p121265884165634"><a name="p121265884165634"></a><a name="p121265884165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1020973969165634"><a name="p1020973969165634"></a><a name="p1020973969165634"></a>void </p>
<p id="p2077740458165634"><a name="p2077740458165634"></a><a name="p2077740458165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row681670286165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726913928165634"><a name="p1726913928165634"></a><a name="p1726913928165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223251829165634"><a name="p223251829165634"></a><a name="p223251829165634"></a>const char * </p>
<p id="p1845538230165634"><a name="p1845538230165634"></a><a name="p1845538230165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row782973672165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1554701649165634"><a name="p1554701649165634"></a><a name="p1554701649165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750824421165634"><a name="p1750824421165634"></a><a name="p1750824421165634"></a>void </p>
<p id="p1566979693165634"><a name="p1566979693165634"></a><a name="p1566979693165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row2048776187165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538495030165634"><a name="p538495030165634"></a><a name="p538495030165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p676057586165634"><a name="p676057586165634"></a><a name="p676057586165634"></a>int16_t </p>
<p id="p1932757115165634"><a name="p1932757115165634"></a><a name="p1932757115165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1181436634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535219917165634"><a name="p1535219917165634"></a><a name="p1535219917165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687321360165634"><a name="p1687321360165634"></a><a name="p1687321360165634"></a>virtual void </p>
<p id="p1115555375165634"><a name="p1115555375165634"></a><a name="p1115555375165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row467730863165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763311159165634"><a name="p1763311159165634"></a><a name="p1763311159165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490819963165634"><a name="p1490819963165634"></a><a name="p1490819963165634"></a>void </p>
<p id="p1797369997165634"><a name="p1797369997165634"></a><a name="p1797369997165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row749432219165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724527333165634"><a name="p724527333165634"></a><a name="p724527333165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p842484996165634"><a name="p842484996165634"></a><a name="p842484996165634"></a>void </p>
<p id="p270434780165634"><a name="p270434780165634"></a><a name="p270434780165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row2110397144165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997469084165634"><a name="p1997469084165634"></a><a name="p1997469084165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361675561165634"><a name="p361675561165634"></a><a name="p361675561165634"></a>void </p>
<p id="p730623826165634"><a name="p730623826165634"></a><a name="p730623826165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1473737379165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1820281178165634"><a name="p1820281178165634"></a><a name="p1820281178165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42990224165634"><a name="p42990224165634"></a><a name="p42990224165634"></a>void </p>
<p id="p1322035194165634"><a name="p1322035194165634"></a><a name="p1322035194165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1647605586165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1182688360165634"><a name="p1182688360165634"></a><a name="p1182688360165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948985176165634"><a name="p1948985176165634"></a><a name="p1948985176165634"></a>void </p>
<p id="p454392656165634"><a name="p454392656165634"></a><a name="p454392656165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row70363960165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576351960165634"><a name="p576351960165634"></a><a name="p576351960165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1322870103165634"><a name="p1322870103165634"></a><a name="p1322870103165634"></a>void </p>
<p id="p311950297165634"><a name="p311950297165634"></a><a name="p311950297165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row954197390165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707308506165634"><a name="p1707308506165634"></a><a name="p1707308506165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783828363165634"><a name="p783828363165634"></a><a name="p783828363165634"></a>void </p>
<p id="p1800049276165634"><a name="p1800049276165634"></a><a name="p1800049276165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row925028025165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848725824165634"><a name="p1848725824165634"></a><a name="p1848725824165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733020743165634"><a name="p733020743165634"></a><a name="p733020743165634"></a>void </p>
<p id="p357735780165634"><a name="p357735780165634"></a><a name="p357735780165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1730188170165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495755730165634"><a name="p1495755730165634"></a><a name="p1495755730165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p613352005165634"><a name="p613352005165634"></a><a name="p613352005165634"></a>void </p>
<p id="p1677152688165634"><a name="p1677152688165634"></a><a name="p1677152688165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1157680491165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2094297846165634"><a name="p2094297846165634"></a><a name="p2094297846165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959401284165634"><a name="p1959401284165634"></a><a name="p1959401284165634"></a>void </p>
<p id="p1133047658165634"><a name="p1133047658165634"></a><a name="p1133047658165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1921401618165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1283143509165634"><a name="p1283143509165634"></a><a name="p1283143509165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672936102165634"><a name="p672936102165634"></a><a name="p672936102165634"></a>void </p>
<p id="p407286944165634"><a name="p407286944165634"></a><a name="p407286944165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row948955773165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155957212165634"><a name="p155957212165634"></a><a name="p155957212165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398559044165634"><a name="p398559044165634"></a><a name="p398559044165634"></a>void </p>
<p id="p2019423628165634"><a name="p2019423628165634"></a><a name="p2019423628165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1087809700165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2017949714165634"><a name="p2017949714165634"></a><a name="p2017949714165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940082619165634"><a name="p1940082619165634"></a><a name="p1940082619165634"></a>void </p>
<p id="p1578811022165634"><a name="p1578811022165634"></a><a name="p1578811022165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row151736869165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145840341165634"><a name="p145840341165634"></a><a name="p145840341165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559976520165634"><a name="p1559976520165634"></a><a name="p1559976520165634"></a>void </p>
<p id="p1689265779165634"><a name="p1689265779165634"></a><a name="p1689265779165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1305690308165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1614226275165634"><a name="p1614226275165634"></a><a name="p1614226275165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637787470165634"><a name="p637787470165634"></a><a name="p637787470165634"></a>void </p>
<p id="p1336179223165634"><a name="p1336179223165634"></a><a name="p1336179223165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1085740572165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1930551235165634"><a name="p1930551235165634"></a><a name="p1930551235165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621867974165634"><a name="p1621867974165634"></a><a name="p1621867974165634"></a>void </p>
<p id="p1091242759165634"><a name="p1091242759165634"></a><a name="p1091242759165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1382033299165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657058861165634"><a name="p657058861165634"></a><a name="p657058861165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1537423493165634"><a name="p1537423493165634"></a><a name="p1537423493165634"></a>virtual void </p>
<p id="p21865843165634"><a name="p21865843165634"></a><a name="p21865843165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row377333747165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p788845930165634"><a name="p788845930165634"></a><a name="p788845930165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p168562766165634"><a name="p168562766165634"></a><a name="p168562766165634"></a>virtual int64_t </p>
<p id="p1706635336165634"><a name="p1706635336165634"></a><a name="p1706635336165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row445341378165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1086744732165634"><a name="p1086744732165634"></a><a name="p1086744732165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1277982919165634"><a name="p1277982919165634"></a><a name="p1277982919165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1733869617165634"><a name="p1733869617165634"></a><a name="p1733869617165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row665397689165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1954962874165634"><a name="p1954962874165634"></a><a name="p1954962874165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411469944165634"><a name="p411469944165634"></a><a name="p411469944165634"></a>void * </p>
<p id="p1828428503165634"><a name="p1828428503165634"></a><a name="p1828428503165634"></a>Overrides the <strong id="b1734671855165634"><a name="b1734671855165634"></a><a name="b1734671855165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row106090638165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752784330165634"><a name="p752784330165634"></a><a name="p752784330165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767833934165634"><a name="p1767833934165634"></a><a name="p1767833934165634"></a>void </p>
<p id="p1670381220165634"><a name="p1670381220165634"></a><a name="p1670381220165634"></a>Overrides the <strong id="b1881090012165634"><a name="b1881090012165634"></a><a name="b1881090012165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1215054498165634"></a>
<table><thead align="left"><tr id="row2003883771165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1109044540165634"><a name="p1109044540165634"></a><a name="p1109044540165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1954909455165634"><a name="p1954909455165634"></a><a name="p1954909455165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row612584987165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p316055252165634"><a name="p316055252165634"></a><a name="p316055252165634"></a><a href="Graphic.md#ga15a3f0302aded0e4d1584ddc6002335d">UICheckBoxState</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166596527165634"><a name="p1166596527165634"></a><a name="p1166596527165634"></a>Enumerates the states of a check box. </p>
</td>
</tr>
</tbody>
</table>

