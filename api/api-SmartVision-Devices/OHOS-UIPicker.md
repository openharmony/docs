# OHOS::UIPicker<a name="ZH-CN_TOPIC_0000001054479589"></a>

-   [Overview](#section916326350165634)
-   [Summary](#section320523960165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section916326350165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a picker. Multiple texts or numbers can be put into a sliding list for selection. The selected text or numbers are highlighted. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section320523960165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table419180852165634"></a>
<table><thead align="left"><tr id="row1351571147165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p870481371165634"><a name="p870481371165634"></a><a name="p870481371165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1898497424165634"><a name="p1898497424165634"></a><a name="p1898497424165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1657430628165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664374694165634"><a name="p664374694165634"></a><a name="p664374694165634"></a><a href="OHOS-UIPicker-SelectedListener.md">SelectedListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p437088840165634"><a name="p437088840165634"></a><a name="p437088840165634"></a>Defines the listener used by a picker. This listener is triggered when an item is selected after sliding stops. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table2000245350165634"></a>
<table><thead align="left"><tr id="row608644995165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1215600814165634"><a name="p1215600814165634"></a><a name="p1215600814165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p720336134165634"><a name="p720336134165634"></a><a name="p720336134165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1804235692165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1831944209165634"><a name="p1831944209165634"></a><a name="p1831944209165634"></a><a href="Graphic.md#ga527215b87f48c8e4a76c1d1d7979b739">UIPicker</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192357817165634"><a name="p1192357817165634"></a><a name="p1192357817165634"></a> </p>
<p id="p291727533165634"><a name="p291727533165634"></a><a name="p291727533165634"></a>A constructor used to create a <strong id="b1131925875165634"><a name="b1131925875165634"></a><a name="b1131925875165634"></a><a href="OHOS-UIPicker.md">UIPicker</a></strong> instance. </p>
</td>
</tr>
<tr id="row1099242863165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p710331144165634"><a name="p710331144165634"></a><a name="p710331144165634"></a><a href="Graphic.md#ga7aa364d1c552eaf8b8be587e03049f59">~UIPicker</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p849434783165634"><a name="p849434783165634"></a><a name="p849434783165634"></a>virtual </p>
<p id="p1335654345165634"><a name="p1335654345165634"></a><a name="p1335654345165634"></a>A destructor used to delete the <strong id="b1307843005165634"><a name="b1307843005165634"></a><a name="b1307843005165634"></a><a href="OHOS-UIPicker.md">UIPicker</a></strong> instance. </p>
</td>
</tr>
<tr id="row873345214165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1753085195165634"><a name="p1753085195165634"></a><a name="p1753085195165634"></a><a href="Graphic.md#ga926337be55785de0b32ad57d7ee85c5c">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p355225122165634"><a name="p355225122165634"></a><a name="p355225122165634"></a>UIViewType </p>
<p id="p1886596132165634"><a name="p1886596132165634"></a><a name="p1886596132165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row459258568165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047692631165634"><a name="p2047692631165634"></a><a name="p2047692631165634"></a><a href="Graphic.md#ga3e2a703a10017c789366029b297969ab">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672463616165634"><a name="p672463616165634"></a><a name="p672463616165634"></a>bool </p>
<p id="p487391146165634"><a name="p487391146165634"></a><a name="p487391146165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1479281896165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1366861885165634"><a name="p1366861885165634"></a><a name="p1366861885165634"></a><a href="Graphic.md#ga419bb15f72b02f009a76a84e1242b37a">SetValues</a> (const char *value[], uint16_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p685049404165634"><a name="p685049404165634"></a><a name="p685049404165634"></a>bool </p>
<p id="p1908543477165634"><a name="p1908543477165634"></a><a name="p1908543477165634"></a>Sets dynamic text data in the picker by using a string array. </p>
</td>
</tr>
<tr id="row950693820165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p969081596165634"><a name="p969081596165634"></a><a name="p969081596165634"></a><a href="Graphic.md#gadc27ad0369bad90526a59d0cefdb9697">SetValues</a> (int16_t start, int16_t end)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1189091056165634"><a name="p1189091056165634"></a><a name="p1189091056165634"></a>bool </p>
<p id="p1965203202165634"><a name="p1965203202165634"></a><a name="p1965203202165634"></a>Sets the numeric data in the picker by using a given numeric range. </p>
</td>
</tr>
<tr id="row1595778642165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1776449346165634"><a name="p1776449346165634"></a><a name="p1776449346165634"></a><a href="Graphic.md#ga81e69c460191bbe3606ac540433178a1">ClearValues</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702493235165634"><a name="p702493235165634"></a><a name="p702493235165634"></a>virtual void </p>
<p id="p1512959528165634"><a name="p1512959528165634"></a><a name="p1512959528165634"></a>Clears all values in the picker. </p>
</td>
</tr>
<tr id="row2078064689165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p455533579165634"><a name="p455533579165634"></a><a name="p455533579165634"></a><a href="Graphic.md#ga11a0d71430e826f1971744e5ce1c9048">SetFontId</a> (uint8_t backgroundFontId, uint8_t highlightFontId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1729903598165634"><a name="p1729903598165634"></a><a name="p1729903598165634"></a>void </p>
<p id="p786263372165634"><a name="p786263372165634"></a><a name="p786263372165634"></a>Sets the font IDs of dynamic text, which is the string array set through <a href="Graphic.md#ga419bb15f72b02f009a76a84e1242b37a">SetValues</a>. </p>
</td>
</tr>
<tr id="row2028341957165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1385505028165634"><a name="p1385505028165634"></a><a name="p1385505028165634"></a><a href="Graphic.md#ga77e6edef3e2a70e68c4a79ca6e2b99f6">SetBackgroundFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p233593474165634"><a name="p233593474165634"></a><a name="p233593474165634"></a>void </p>
<p id="p161305642165634"><a name="p161305642165634"></a><a name="p161305642165634"></a>Sets the font name and size for the background text. </p>
</td>
</tr>
<tr id="row66088724165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p359201417165634"><a name="p359201417165634"></a><a name="p359201417165634"></a><a href="Graphic.md#ga56b1f4b7f18e9684cdbac447aa106503">SetHighlightFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1444599668165634"><a name="p1444599668165634"></a><a name="p1444599668165634"></a>void </p>
<p id="p2053812922165634"><a name="p2053812922165634"></a><a name="p2053812922165634"></a>Sets the font name and size for the highlighted text. </p>
</td>
</tr>
<tr id="row994261196165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1007497890165634"><a name="p1007497890165634"></a><a name="p1007497890165634"></a><a href="Graphic.md#gaaf111e4de815c455ddc35d200c1de7af">GetBackgroundFontId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115579950165634"><a name="p2115579950165634"></a><a name="p2115579950165634"></a>uint16_t </p>
<p id="p1481071039165634"><a name="p1481071039165634"></a><a name="p1481071039165634"></a>Obtains the font ID of the background text. </p>
</td>
</tr>
<tr id="row170587065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686222695165634"><a name="p686222695165634"></a><a name="p686222695165634"></a><a href="Graphic.md#ga3a03222a252380aa738186e9c004dc1a">GetHighlightFontId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1593549842165634"><a name="p1593549842165634"></a><a name="p1593549842165634"></a>uint16_t </p>
<p id="p972254594165634"><a name="p972254594165634"></a><a name="p972254594165634"></a>Obtains the font ID of the highlighted text. </p>
</td>
</tr>
<tr id="row1162058971165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286418278165634"><a name="p1286418278165634"></a><a name="p1286418278165634"></a><a href="Graphic.md#ga281508b16585cdf4531e29872486e6c8">SetTextColor</a> (<a href="OHOS-Color32.md">ColorType</a> backgroundColor, <a href="OHOS-Color32.md">ColorType</a> highlightColor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p582612703165634"><a name="p582612703165634"></a><a name="p582612703165634"></a>void </p>
<p id="p19807916165634"><a name="p19807916165634"></a><a name="p19807916165634"></a>Sets the text color. </p>
</td>
</tr>
<tr id="row1138273466165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p536881643165634"><a name="p536881643165634"></a><a name="p536881643165634"></a><a href="Graphic.md#ga2acbf79147239f60aafa2c78ccc2ff6d">GetBackgroundTextColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174594702165634"><a name="p174594702165634"></a><a name="p174594702165634"></a><a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p865953128165634"><a name="p865953128165634"></a><a name="p865953128165634"></a>Obtains the color of the background text. </p>
</td>
</tr>
<tr id="row377088127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790788914165634"><a name="p1790788914165634"></a><a name="p1790788914165634"></a><a href="Graphic.md#gaf51c8e0d1defb52191bc5f0b2c960695">GetHighlightTextColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973524602165634"><a name="p1973524602165634"></a><a name="p1973524602165634"></a><a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p205423970165634"><a name="p205423970165634"></a><a name="p205423970165634"></a>Obtains the color of the highlighted text. </p>
</td>
</tr>
<tr id="row1425556824165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1961321796165634"><a name="p1961321796165634"></a><a name="p1961321796165634"></a><a href="Graphic.md#ga07eb2080a6052c19dba2873fcfae2c34">SetSelected</a> (uint16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p630054117165634"><a name="p630054117165634"></a><a name="p630054117165634"></a>bool </p>
<p id="p1395368644165634"><a name="p1395368644165634"></a><a name="p1395368644165634"></a>Sets the index of the item currently selected in the picker. </p>
</td>
</tr>
<tr id="row793962348165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1888587913165634"><a name="p1888587913165634"></a><a name="p1888587913165634"></a><a href="Graphic.md#ga7c9d757790dfaae67fad110577b57ee9">GetSelected</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1050117081165634"><a name="p1050117081165634"></a><a name="p1050117081165634"></a>uint16_t </p>
<p id="p1069227851165634"><a name="p1069227851165634"></a><a name="p1069227851165634"></a>Obtains the index of the item currently selected in the picker. </p>
</td>
</tr>
<tr id="row599460105165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p413409006165634"><a name="p413409006165634"></a><a name="p413409006165634"></a><a href="Graphic.md#ga6a6d9ca48f543f4f6cf6073d6cca359a">SetItemHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606798294165634"><a name="p1606798294165634"></a><a name="p1606798294165634"></a>void </p>
<p id="p494593474165634"><a name="p494593474165634"></a><a name="p494593474165634"></a>Sets the height of each item in the picker. </p>
</td>
</tr>
<tr id="row1027876164165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149199044165634"><a name="p1149199044165634"></a><a name="p1149199044165634"></a><a href="Graphic.md#ga792a345948af532f9c06cd40c05d1a2d">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664222949165634"><a name="p1664222949165634"></a><a name="p1664222949165634"></a>void </p>
<p id="p1643267215165634"><a name="p1643267215165634"></a><a name="p1643267215165634"></a>Sets the width for this component. </p>
</td>
</tr>
<tr id="row798325342165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p597103733165634"><a name="p597103733165634"></a><a name="p597103733165634"></a><a href="Graphic.md#ga167979fe09694b0f0c09e9c676189bea">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1296279701165634"><a name="p1296279701165634"></a><a name="p1296279701165634"></a>void </p>
<p id="p363391664165634"><a name="p363391664165634"></a><a name="p363391664165634"></a>Sets the height for this component. </p>
</td>
</tr>
<tr id="row284173679165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p464881038165634"><a name="p464881038165634"></a><a name="p464881038165634"></a><a href="Graphic.md#ga742f27b59ae3c19dfb5d99e84ca19554">SetLoopState</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1591322269165634"><a name="p1591322269165634"></a><a name="p1591322269165634"></a>void </p>
<p id="p3813195165634"><a name="p3813195165634"></a><a name="p3813195165634"></a>Sets whether a picker can slide cyclically. </p>
</td>
</tr>
<tr id="row1329700214165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660216647165634"><a name="p1660216647165634"></a><a name="p1660216647165634"></a><a href="Graphic.md#ga70a514c87a883999a93b6c9d3713be61">RegisterSelectedListener</a> (<a href="OHOS-UIPicker-SelectedListener.md">SelectedListener</a> *pickerListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316309805165634"><a name="p1316309805165634"></a><a name="p1316309805165634"></a>void </p>
<p id="p823059166165634"><a name="p823059166165634"></a><a name="p823059166165634"></a>Registers a listener for a selected event. </p>
</td>
</tr>
<tr id="row1214707045165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591571988165634"><a name="p591571988165634"></a><a name="p591571988165634"></a><a href="Graphic.md#gad0c36e1430f8db5571fd92b82d6d6bc1">SetDirect</a> (<a href="Graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> direct)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240833533165634"><a name="p1240833533165634"></a><a name="p1240833533165634"></a>void </p>
<p id="p538989874165634"><a name="p538989874165634"></a><a name="p538989874165634"></a>Sets the text direction. </p>
</td>
</tr>
<tr id="row1268863512165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1919570529165634"><a name="p1919570529165634"></a><a name="p1919570529165634"></a><a href="Graphic.md#ga564153af81a4a41ceab63622506d25eb">SetTextFormatter</a> (<a href="OHOS-TextFormatter.md">TextFormatter</a> *formatter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1025623976165634"><a name="p1025623976165634"></a><a name="p1025623976165634"></a>void </p>
<p id="p1546323684165634"><a name="p1546323684165634"></a><a name="p1546323684165634"></a>Sets the text formatter. </p>
</td>
</tr>
<tr id="row1561867012165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585581863165634"><a name="p585581863165634"></a><a name="p585581863165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964848537165634"><a name="p964848537165634"></a><a name="p964848537165634"></a> </p>
<p id="p947761188165634"><a name="p947761188165634"></a><a name="p947761188165634"></a>A default constructor used to create a <strong id="b1471506656165634"><a name="b1471506656165634"></a><a name="b1471506656165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1493399577165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196736042165634"><a name="p1196736042165634"></a><a name="p1196736042165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179258943165634"><a name="p179258943165634"></a><a name="p179258943165634"></a>virtual </p>
<p id="p194437432165634"><a name="p194437432165634"></a><a name="p194437432165634"></a>A destructor used to delete the <strong id="b1903579669165634"><a name="b1903579669165634"></a><a name="b1903579669165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1260834813165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780644809165634"><a name="p1780644809165634"></a><a name="p1780644809165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1451638118165634"><a name="p1451638118165634"></a><a name="p1451638118165634"></a>UIViewType </p>
<p id="p2048892459165634"><a name="p2048892459165634"></a><a name="p2048892459165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2045212096165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1080889644165634"><a name="p1080889644165634"></a><a name="p1080889644165634"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687312997165634"><a name="p1687312997165634"></a><a name="p1687312997165634"></a>virtual void </p>
<p id="p1197620134165634"><a name="p1197620134165634"></a><a name="p1197620134165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row330304666165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p22915127165634"><a name="p22915127165634"></a><a name="p22915127165634"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1904935427165634"><a name="p1904935427165634"></a><a name="p1904935427165634"></a>virtual void </p>
<p id="p20734733165634"><a name="p20734733165634"></a><a name="p20734733165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1396365004165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943170828165634"><a name="p1943170828165634"></a><a name="p1943170828165634"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680125183165634"><a name="p1680125183165634"></a><a name="p1680125183165634"></a>virtual void </p>
<p id="p658761102165634"><a name="p658761102165634"></a><a name="p658761102165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row906861457165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p640331182165634"><a name="p640331182165634"></a><a name="p640331182165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p447260674165634"><a name="p447260674165634"></a><a name="p447260674165634"></a>virtual void </p>
<p id="p939835336165634"><a name="p939835336165634"></a><a name="p939835336165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row2090832027165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280368271165634"><a name="p1280368271165634"></a><a name="p1280368271165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p320130329165634"><a name="p320130329165634"></a><a name="p320130329165634"></a>virtual void </p>
<p id="p1708059114165634"><a name="p1708059114165634"></a><a name="p1708059114165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1576251893165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p725565233165634"><a name="p725565233165634"></a><a name="p725565233165634"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1874767026165634"><a name="p1874767026165634"></a><a name="p1874767026165634"></a>virtual void </p>
<p id="p172647278165634"><a name="p172647278165634"></a><a name="p172647278165634"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row382399005165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1116893863165634"><a name="p1116893863165634"></a><a name="p1116893863165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p819408380165634"><a name="p819408380165634"></a><a name="p819408380165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1024327212165634"><a name="p1024327212165634"></a><a name="p1024327212165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1419012022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446646355165634"><a name="p1446646355165634"></a><a name="p1446646355165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1102288113165634"><a name="p1102288113165634"></a><a name="p1102288113165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1060991032165634"><a name="p1060991032165634"></a><a name="p1060991032165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1900406356165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1681690313165634"><a name="p1681690313165634"></a><a name="p1681690313165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916091040165634"><a name="p916091040165634"></a><a name="p916091040165634"></a>void </p>
<p id="p866371614165634"><a name="p866371614165634"></a><a name="p866371614165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row952547841165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078892310165634"><a name="p2078892310165634"></a><a name="p2078892310165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945048958165634"><a name="p945048958165634"></a><a name="p945048958165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1700763696165634"><a name="p1700763696165634"></a><a name="p1700763696165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row116438429165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805994787165634"><a name="p805994787165634"></a><a name="p805994787165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p171774755165634"><a name="p171774755165634"></a><a name="p171774755165634"></a>void </p>
<p id="p624689656165634"><a name="p624689656165634"></a><a name="p624689656165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1690567848165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p815935728165634"><a name="p815935728165634"></a><a name="p815935728165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2080667266165634"><a name="p2080667266165634"></a><a name="p2080667266165634"></a> </p>
<p id="p149582686165634"><a name="p149582686165634"></a><a name="p149582686165634"></a>A default constructor used to create an <strong id="b639431612165634"><a name="b639431612165634"></a><a name="b639431612165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1081030396165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155851784165634"><a name="p1155851784165634"></a><a name="p1155851784165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1039149884165634"><a name="p1039149884165634"></a><a name="p1039149884165634"></a> </p>
<p id="p187974525165634"><a name="p187974525165634"></a><a name="p187974525165634"></a>A constructor used to create an <strong id="b2012959014165634"><a name="b2012959014165634"></a><a name="b2012959014165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1997411367165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786384367165634"><a name="p1786384367165634"></a><a name="p1786384367165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877364906165634"><a name="p1877364906165634"></a><a name="p1877364906165634"></a>virtual </p>
<p id="p431292785165634"><a name="p431292785165634"></a><a name="p431292785165634"></a>A destructor used to delete the <strong id="b1338389384165634"><a name="b1338389384165634"></a><a name="b1338389384165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1179960764165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242589548165634"><a name="p242589548165634"></a><a name="p242589548165634"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1857264270165634"><a name="p1857264270165634"></a><a name="p1857264270165634"></a>virtual void </p>
<p id="p1586035267165634"><a name="p1586035267165634"></a><a name="p1586035267165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row601979171165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p718346634165634"><a name="p718346634165634"></a><a name="p718346634165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053680892165634"><a name="p1053680892165634"></a><a name="p1053680892165634"></a>virtual void </p>
<p id="p800829139165634"><a name="p800829139165634"></a><a name="p800829139165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1070486339165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481608773165634"><a name="p481608773165634"></a><a name="p481608773165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1224832341165634"><a name="p1224832341165634"></a><a name="p1224832341165634"></a>virtual void </p>
<p id="p56632521165634"><a name="p56632521165634"></a><a name="p56632521165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row30159987165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498030559165634"><a name="p498030559165634"></a><a name="p498030559165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2077491502165634"><a name="p2077491502165634"></a><a name="p2077491502165634"></a>void </p>
<p id="p1707864388165634"><a name="p1707864388165634"></a><a name="p1707864388165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row552593390165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1162227005165634"><a name="p1162227005165634"></a><a name="p1162227005165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p807303968165634"><a name="p807303968165634"></a><a name="p807303968165634"></a>void </p>
<p id="p1604437516165634"><a name="p1604437516165634"></a><a name="p1604437516165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row668076436165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720978230165634"><a name="p1720978230165634"></a><a name="p1720978230165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677021762165634"><a name="p1677021762165634"></a><a name="p1677021762165634"></a>virtual bool </p>
<p id="p897157083165634"><a name="p897157083165634"></a><a name="p897157083165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1863834748165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173895044165634"><a name="p1173895044165634"></a><a name="p1173895044165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141681205165634"><a name="p1141681205165634"></a><a name="p1141681205165634"></a>virtual bool </p>
<p id="p875331458165634"><a name="p875331458165634"></a><a name="p875331458165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1929429411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p903162126165634"><a name="p903162126165634"></a><a name="p903162126165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769477694165634"><a name="p769477694165634"></a><a name="p769477694165634"></a>virtual bool </p>
<p id="p1580619045165634"><a name="p1580619045165634"></a><a name="p1580619045165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1309042297165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p550125067165634"><a name="p550125067165634"></a><a name="p550125067165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p353162989165634"><a name="p353162989165634"></a><a name="p353162989165634"></a>virtual bool </p>
<p id="p527234383165634"><a name="p527234383165634"></a><a name="p527234383165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row137719254165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633061386165634"><a name="p633061386165634"></a><a name="p633061386165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1041293934165634"><a name="p1041293934165634"></a><a name="p1041293934165634"></a>virtual void </p>
<p id="p1699487926165634"><a name="p1699487926165634"></a><a name="p1699487926165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1357703802165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172894930165634"><a name="p172894930165634"></a><a name="p172894930165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1877561206165634"><a name="p1877561206165634"></a><a name="p1877561206165634"></a>virtual void </p>
<p id="p318693109165634"><a name="p318693109165634"></a><a name="p318693109165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1595701891165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1609972310165634"><a name="p1609972310165634"></a><a name="p1609972310165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338864919165634"><a name="p338864919165634"></a><a name="p338864919165634"></a>virtual void </p>
<p id="p1683574537165634"><a name="p1683574537165634"></a><a name="p1683574537165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1175864726165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221460812165634"><a name="p1221460812165634"></a><a name="p1221460812165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1574714190165634"><a name="p1574714190165634"></a><a name="p1574714190165634"></a>virtual void </p>
<p id="p1778621814165634"><a name="p1778621814165634"></a><a name="p1778621814165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row664745414165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449227132165634"><a name="p1449227132165634"></a><a name="p1449227132165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2041696055165634"><a name="p2041696055165634"></a><a name="p2041696055165634"></a>void </p>
<p id="p161476270165634"><a name="p161476270165634"></a><a name="p161476270165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1176223787165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p966114023165634"><a name="p966114023165634"></a><a name="p966114023165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133553047165634"><a name="p1133553047165634"></a><a name="p1133553047165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1359272202165634"><a name="p1359272202165634"></a><a name="p1359272202165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1122580424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772509088165634"><a name="p1772509088165634"></a><a name="p1772509088165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929849137165634"><a name="p929849137165634"></a><a name="p929849137165634"></a>void </p>
<p id="p314364902165634"><a name="p314364902165634"></a><a name="p314364902165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row359072052165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p886768571165634"><a name="p886768571165634"></a><a name="p886768571165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665329707165634"><a name="p665329707165634"></a><a name="p665329707165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1780611631165634"><a name="p1780611631165634"></a><a name="p1780611631165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1926919168165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p157998331165634"><a name="p157998331165634"></a><a name="p157998331165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1590842056165634"><a name="p1590842056165634"></a><a name="p1590842056165634"></a>void </p>
<p id="p870569076165634"><a name="p870569076165634"></a><a name="p870569076165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1028669722165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128572436165634"><a name="p2128572436165634"></a><a name="p2128572436165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p913330229165634"><a name="p913330229165634"></a><a name="p913330229165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1486732110165634"><a name="p1486732110165634"></a><a name="p1486732110165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1156468958165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p80574594165634"><a name="p80574594165634"></a><a name="p80574594165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822107336165634"><a name="p1822107336165634"></a><a name="p1822107336165634"></a>void </p>
<p id="p941235125165634"><a name="p941235125165634"></a><a name="p941235125165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1970565632165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p633718105165634"><a name="p633718105165634"></a><a name="p633718105165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1302390807165634"><a name="p1302390807165634"></a><a name="p1302390807165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1588222315165634"><a name="p1588222315165634"></a><a name="p1588222315165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1102509952165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1329084926165634"><a name="p1329084926165634"></a><a name="p1329084926165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1292327899165634"><a name="p1292327899165634"></a><a name="p1292327899165634"></a>void </p>
<p id="p1717026524165634"><a name="p1717026524165634"></a><a name="p1717026524165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row892593371165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992436254165634"><a name="p992436254165634"></a><a name="p992436254165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p965632668165634"><a name="p965632668165634"></a><a name="p965632668165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p369489755165634"><a name="p369489755165634"></a><a name="p369489755165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1506298128165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p332310615165634"><a name="p332310615165634"></a><a name="p332310615165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675560837165634"><a name="p675560837165634"></a><a name="p675560837165634"></a>void </p>
<p id="p367926095165634"><a name="p367926095165634"></a><a name="p367926095165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row368398060165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887255712165634"><a name="p887255712165634"></a><a name="p887255712165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p118192511165634"><a name="p118192511165634"></a><a name="p118192511165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1994058504165634"><a name="p1994058504165634"></a><a name="p1994058504165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1325161978165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895502812165634"><a name="p1895502812165634"></a><a name="p1895502812165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053405562165634"><a name="p1053405562165634"></a><a name="p1053405562165634"></a>virtual void </p>
<p id="p2091308211165634"><a name="p2091308211165634"></a><a name="p2091308211165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1846807272165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p513028144165634"><a name="p513028144165634"></a><a name="p513028144165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1892567785165634"><a name="p1892567785165634"></a><a name="p1892567785165634"></a>bool </p>
<p id="p235407962165634"><a name="p235407962165634"></a><a name="p235407962165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row718834221165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27856906165634"><a name="p27856906165634"></a><a name="p27856906165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1686887760165634"><a name="p1686887760165634"></a><a name="p1686887760165634"></a>void </p>
<p id="p1865813972165634"><a name="p1865813972165634"></a><a name="p1865813972165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row280295925165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p820265087165634"><a name="p820265087165634"></a><a name="p820265087165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24917216165634"><a name="p24917216165634"></a><a name="p24917216165634"></a>bool </p>
<p id="p1162680650165634"><a name="p1162680650165634"></a><a name="p1162680650165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1027023239165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122801713165634"><a name="p122801713165634"></a><a name="p122801713165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p838993427165634"><a name="p838993427165634"></a><a name="p838993427165634"></a>void </p>
<p id="p1360476997165634"><a name="p1360476997165634"></a><a name="p1360476997165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1578476986165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p851487675165634"><a name="p851487675165634"></a><a name="p851487675165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p274478783165634"><a name="p274478783165634"></a><a name="p274478783165634"></a>bool </p>
<p id="p1852066083165634"><a name="p1852066083165634"></a><a name="p1852066083165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1804468842165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p748673559165634"><a name="p748673559165634"></a><a name="p748673559165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544396131165634"><a name="p1544396131165634"></a><a name="p1544396131165634"></a>void </p>
<p id="p197281000165634"><a name="p197281000165634"></a><a name="p197281000165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row2104779667165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p604134762165634"><a name="p604134762165634"></a><a name="p604134762165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036250172165634"><a name="p1036250172165634"></a><a name="p1036250172165634"></a>bool </p>
<p id="p262112079165634"><a name="p262112079165634"></a><a name="p262112079165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1490135459165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1106091987165634"><a name="p1106091987165634"></a><a name="p1106091987165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1464759507165634"><a name="p1464759507165634"></a><a name="p1464759507165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1136427328165634"><a name="p1136427328165634"></a><a name="p1136427328165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row456174274165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1602108664165634"><a name="p1602108664165634"></a><a name="p1602108664165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2125901074165634"><a name="p2125901074165634"></a><a name="p2125901074165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p912950755165634"><a name="p912950755165634"></a><a name="p912950755165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row102222387165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1644316553165634"><a name="p1644316553165634"></a><a name="p1644316553165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1224532057165634"><a name="p1224532057165634"></a><a name="p1224532057165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1893741666165634"><a name="p1893741666165634"></a><a name="p1893741666165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1466105382165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987984465165634"><a name="p1987984465165634"></a><a name="p1987984465165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380801300165634"><a name="p380801300165634"></a><a name="p380801300165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1992408595165634"><a name="p1992408595165634"></a><a name="p1992408595165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1554884848165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519765820165634"><a name="p519765820165634"></a><a name="p519765820165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250415387165634"><a name="p250415387165634"></a><a name="p250415387165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1800199094165634"><a name="p1800199094165634"></a><a name="p1800199094165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1596675896165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p765322163165634"><a name="p765322163165634"></a><a name="p765322163165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258329807165634"><a name="p1258329807165634"></a><a name="p1258329807165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p821667134165634"><a name="p821667134165634"></a><a name="p821667134165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1406733220165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1444617383165634"><a name="p1444617383165634"></a><a name="p1444617383165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1064395249165634"><a name="p1064395249165634"></a><a name="p1064395249165634"></a>void </p>
<p id="p1152550746165634"><a name="p1152550746165634"></a><a name="p1152550746165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1084377362165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1819116804165634"><a name="p1819116804165634"></a><a name="p1819116804165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1486307619165634"><a name="p1486307619165634"></a><a name="p1486307619165634"></a>virtual int16_t </p>
<p id="p895277074165634"><a name="p895277074165634"></a><a name="p895277074165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row1155739467165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313531313165634"><a name="p1313531313165634"></a><a name="p1313531313165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731289998165634"><a name="p731289998165634"></a><a name="p731289998165634"></a>virtual int16_t </p>
<p id="p79256425165634"><a name="p79256425165634"></a><a name="p79256425165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1808838592165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766697049165634"><a name="p1766697049165634"></a><a name="p1766697049165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1806662422165634"><a name="p1806662422165634"></a><a name="p1806662422165634"></a>virtual void </p>
<p id="p2006580959165634"><a name="p2006580959165634"></a><a name="p2006580959165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1473298086165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p834887900165634"><a name="p834887900165634"></a><a name="p834887900165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778678111165634"><a name="p778678111165634"></a><a name="p778678111165634"></a>virtual void </p>
<p id="p1617922784165634"><a name="p1617922784165634"></a><a name="p1617922784165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1139080699165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172119562165634"><a name="p172119562165634"></a><a name="p172119562165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969986257165634"><a name="p969986257165634"></a><a name="p969986257165634"></a>int16_t </p>
<p id="p248981019165634"><a name="p248981019165634"></a><a name="p248981019165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1063666901165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1153614731165634"><a name="p1153614731165634"></a><a name="p1153614731165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396804797165634"><a name="p396804797165634"></a><a name="p396804797165634"></a>virtual void </p>
<p id="p1320084988165634"><a name="p1320084988165634"></a><a name="p1320084988165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1976668213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p639269742165634"><a name="p639269742165634"></a><a name="p639269742165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1743718458165634"><a name="p1743718458165634"></a><a name="p1743718458165634"></a>int16_t </p>
<p id="p584861334165634"><a name="p584861334165634"></a><a name="p584861334165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row284682177165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140148290165634"><a name="p1140148290165634"></a><a name="p1140148290165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1509262228165634"><a name="p1509262228165634"></a><a name="p1509262228165634"></a>virtual void </p>
<p id="p57991563165634"><a name="p57991563165634"></a><a name="p57991563165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row580619461165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139666780165634"><a name="p1139666780165634"></a><a name="p1139666780165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570479663165634"><a name="p570479663165634"></a><a name="p570479663165634"></a>virtual void </p>
<p id="p311464742165634"><a name="p311464742165634"></a><a name="p311464742165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row580971335165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381635325165634"><a name="p1381635325165634"></a><a name="p1381635325165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2099081306165634"><a name="p2099081306165634"></a><a name="p2099081306165634"></a>bool </p>
<p id="p1254737410165634"><a name="p1254737410165634"></a><a name="p1254737410165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row89834228165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608790019165634"><a name="p608790019165634"></a><a name="p608790019165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1379530979165634"><a name="p1379530979165634"></a><a name="p1379530979165634"></a>void </p>
<p id="p346061716165634"><a name="p346061716165634"></a><a name="p346061716165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1992133767165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2099301816165634"><a name="p2099301816165634"></a><a name="p2099301816165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1152420372165634"><a name="p1152420372165634"></a><a name="p1152420372165634"></a>void </p>
<p id="p1200845390165634"><a name="p1200845390165634"></a><a name="p1200845390165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1357844587165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383454507165634"><a name="p383454507165634"></a><a name="p383454507165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494226696165634"><a name="p1494226696165634"></a><a name="p1494226696165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1229390171165634"><a name="p1229390171165634"></a><a name="p1229390171165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row534694949165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p780505423165634"><a name="p780505423165634"></a><a name="p780505423165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p274086087165634"><a name="p274086087165634"></a><a name="p274086087165634"></a>void </p>
<p id="p2143111434165634"><a name="p2143111434165634"></a><a name="p2143111434165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1849752884165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p646674729165634"><a name="p646674729165634"></a><a name="p646674729165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175217402165634"><a name="p175217402165634"></a><a name="p175217402165634"></a>const char * </p>
<p id="p329950370165634"><a name="p329950370165634"></a><a name="p329950370165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row2004157765165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155850928165634"><a name="p1155850928165634"></a><a name="p1155850928165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632262648165634"><a name="p1632262648165634"></a><a name="p1632262648165634"></a>void </p>
<p id="p43167719165634"><a name="p43167719165634"></a><a name="p43167719165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1096567469165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1670355662165634"><a name="p1670355662165634"></a><a name="p1670355662165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757169632165634"><a name="p1757169632165634"></a><a name="p1757169632165634"></a>int16_t </p>
<p id="p1290864476165634"><a name="p1290864476165634"></a><a name="p1290864476165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1983030907165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1262503692165634"><a name="p1262503692165634"></a><a name="p1262503692165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1865909466165634"><a name="p1865909466165634"></a><a name="p1865909466165634"></a>virtual void </p>
<p id="p1397993397165634"><a name="p1397993397165634"></a><a name="p1397993397165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1387842883165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168394927165634"><a name="p168394927165634"></a><a name="p168394927165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1376966821165634"><a name="p1376966821165634"></a><a name="p1376966821165634"></a>void </p>
<p id="p972796359165634"><a name="p972796359165634"></a><a name="p972796359165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1965616798165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919118493165634"><a name="p919118493165634"></a><a name="p919118493165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192953364165634"><a name="p1192953364165634"></a><a name="p1192953364165634"></a>void </p>
<p id="p1894440066165634"><a name="p1894440066165634"></a><a name="p1894440066165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1349867699165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p291379959165634"><a name="p291379959165634"></a><a name="p291379959165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408191185165634"><a name="p1408191185165634"></a><a name="p1408191185165634"></a>void </p>
<p id="p2046553401165634"><a name="p2046553401165634"></a><a name="p2046553401165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1787250423165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572884629165634"><a name="p1572884629165634"></a><a name="p1572884629165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1477560505165634"><a name="p1477560505165634"></a><a name="p1477560505165634"></a>void </p>
<p id="p2142757643165634"><a name="p2142757643165634"></a><a name="p2142757643165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1914935979165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315040370165634"><a name="p315040370165634"></a><a name="p315040370165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398410889165634"><a name="p398410889165634"></a><a name="p398410889165634"></a>void </p>
<p id="p2115717574165634"><a name="p2115717574165634"></a><a name="p2115717574165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row2082895806165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2072057338165634"><a name="p2072057338165634"></a><a name="p2072057338165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541743614165634"><a name="p1541743614165634"></a><a name="p1541743614165634"></a>void </p>
<p id="p1501840538165634"><a name="p1501840538165634"></a><a name="p1501840538165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row247359692165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32057247165634"><a name="p32057247165634"></a><a name="p32057247165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339868104165634"><a name="p1339868104165634"></a><a name="p1339868104165634"></a>void </p>
<p id="p1447740361165634"><a name="p1447740361165634"></a><a name="p1447740361165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1267098907165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514003173165634"><a name="p1514003173165634"></a><a name="p1514003173165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p57628368165634"><a name="p57628368165634"></a><a name="p57628368165634"></a>void </p>
<p id="p2000372580165634"><a name="p2000372580165634"></a><a name="p2000372580165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row2056036039165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2127325470165634"><a name="p2127325470165634"></a><a name="p2127325470165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245176102165634"><a name="p245176102165634"></a><a name="p245176102165634"></a>void </p>
<p id="p390696450165634"><a name="p390696450165634"></a><a name="p390696450165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1266053230165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612573139165634"><a name="p612573139165634"></a><a name="p612573139165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267263160165634"><a name="p1267263160165634"></a><a name="p1267263160165634"></a>void </p>
<p id="p1248695138165634"><a name="p1248695138165634"></a><a name="p1248695138165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row877076441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724193268165634"><a name="p724193268165634"></a><a name="p724193268165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2130618514165634"><a name="p2130618514165634"></a><a name="p2130618514165634"></a>void </p>
<p id="p2026782055165634"><a name="p2026782055165634"></a><a name="p2026782055165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1053506856165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1953331201165634"><a name="p1953331201165634"></a><a name="p1953331201165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067587322165634"><a name="p2067587322165634"></a><a name="p2067587322165634"></a>void </p>
<p id="p1274391236165634"><a name="p1274391236165634"></a><a name="p1274391236165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1129638818165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1331682147165634"><a name="p1331682147165634"></a><a name="p1331682147165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708621525165634"><a name="p708621525165634"></a><a name="p708621525165634"></a>void </p>
<p id="p901546913165634"><a name="p901546913165634"></a><a name="p901546913165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row2065439030165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078624746165634"><a name="p2078624746165634"></a><a name="p2078624746165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806566139165634"><a name="p806566139165634"></a><a name="p806566139165634"></a>void </p>
<p id="p924295098165634"><a name="p924295098165634"></a><a name="p924295098165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row96950551165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1895576107165634"><a name="p1895576107165634"></a><a name="p1895576107165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1458815273165634"><a name="p1458815273165634"></a><a name="p1458815273165634"></a>void </p>
<p id="p950332908165634"><a name="p950332908165634"></a><a name="p950332908165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row925647728165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1419032931165634"><a name="p1419032931165634"></a><a name="p1419032931165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1678453831165634"><a name="p1678453831165634"></a><a name="p1678453831165634"></a>void </p>
<p id="p1829499013165634"><a name="p1829499013165634"></a><a name="p1829499013165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1131407032165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2073196075165634"><a name="p2073196075165634"></a><a name="p2073196075165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885075170165634"><a name="p885075170165634"></a><a name="p885075170165634"></a>virtual void </p>
<p id="p1850240608165634"><a name="p1850240608165634"></a><a name="p1850240608165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1062443895165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1377047616165634"><a name="p1377047616165634"></a><a name="p1377047616165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916980861165634"><a name="p916980861165634"></a><a name="p916980861165634"></a>virtual int64_t </p>
<p id="p158764647165634"><a name="p158764647165634"></a><a name="p158764647165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1943609785165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198642770165634"><a name="p1198642770165634"></a><a name="p1198642770165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1901965696165634"><a name="p1901965696165634"></a><a name="p1901965696165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1950024062165634"><a name="p1950024062165634"></a><a name="p1950024062165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1063613345165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p223303205165634"><a name="p223303205165634"></a><a name="p223303205165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890274607165634"><a name="p1890274607165634"></a><a name="p1890274607165634"></a>void * </p>
<p id="p1528554328165634"><a name="p1528554328165634"></a><a name="p1528554328165634"></a>Overrides the <strong id="b643903780165634"><a name="b643903780165634"></a><a name="b643903780165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row450368399165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812026300165634"><a name="p812026300165634"></a><a name="p812026300165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1461953749165634"><a name="p1461953749165634"></a><a name="p1461953749165634"></a>void </p>
<p id="p1281925972165634"><a name="p1281925972165634"></a><a name="p1281925972165634"></a>Overrides the <strong id="b318871329165634"><a name="b318871329165634"></a><a name="b318871329165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1985454025165634"></a>
<table><thead align="left"><tr id="row989178506165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1446222094165634"><a name="p1446222094165634"></a><a name="p1446222094165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1820796335165634"><a name="p1820796335165634"></a><a name="p1820796335165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row54675320165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1095376919165634"><a name="p1095376919165634"></a><a name="p1095376919165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018923963165634"><a name="p2018923963165634"></a><a name="p2018923963165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1333776713165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1006742426165634"><a name="p1006742426165634"></a><a name="p1006742426165634"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76658808165634"><a name="p76658808165634"></a><a name="p76658808165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row703323613165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1104978081165634"><a name="p1104978081165634"></a><a name="p1104978081165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145959621165634"><a name="p1145959621165634"></a><a name="p1145959621165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row574469727165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835514454165634"><a name="p1835514454165634"></a><a name="p1835514454165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762380169165634"><a name="p1762380169165634"></a><a name="p1762380169165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row545653625165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1566383357165634"><a name="p1566383357165634"></a><a name="p1566383357165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265606926165634"><a name="p265606926165634"></a><a name="p265606926165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1975043381165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984794615165634"><a name="p984794615165634"></a><a name="p984794615165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451249405165634"><a name="p451249405165634"></a><a name="p451249405165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1043273048165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495968980165634"><a name="p495968980165634"></a><a name="p495968980165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235721499165634"><a name="p1235721499165634"></a><a name="p1235721499165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row362822218165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p697342240165634"><a name="p697342240165634"></a><a name="p697342240165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528616441165634"><a name="p528616441165634"></a><a name="p528616441165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

