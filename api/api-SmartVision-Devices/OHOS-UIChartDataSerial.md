# OHOS::UIChartDataSerial<a name="ZH-CN_TOPIC_0000001055678116"></a>

-   [Overview](#section1012289381165634)
-   [Summary](#section2001841170165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1012289381165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a data set and provides functions such as adding and deleting data points. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2001841170165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1707717065165634"></a>
<table><thead align="left"><tr id="row1173602900165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1017995411165634"><a name="p1017995411165634"></a><a name="p1017995411165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1281926957165634"><a name="p1281926957165634"></a><a name="p1281926957165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row341005233165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p827261716165634"><a name="p827261716165634"></a><a name="p827261716165634"></a><a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494059305165634"><a name="p1494059305165634"></a><a name="p1494059305165634"></a>Defines the style for the top, bottom, and frontmost points in a line chart. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1484782672165634"></a>
<table><thead align="left"><tr id="row538889010165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2106660411165634"><a name="p2106660411165634"></a><a name="p2106660411165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1434298948165634"><a name="p1434298948165634"></a><a name="p1434298948165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2128702896165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p608975308165634"><a name="p608975308165634"></a><a name="p608975308165634"></a><a href="Graphic.md#ga8f1555cd3433927a650e7800a8746779">UIChartDataSerial</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765545991165634"><a name="p765545991165634"></a><a name="p765545991165634"></a> </p>
<p id="p21139770165634"><a name="p21139770165634"></a><a name="p21139770165634"></a>A constructor used to create a <strong id="b1074163484165634"><a name="b1074163484165634"></a><a name="b1074163484165634"></a><a href="OHOS-UIChartDataSerial.md">UIChartDataSerial</a></strong> instance. </p>
</td>
</tr>
<tr id="row1632958995165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6217985165634"><a name="p6217985165634"></a><a name="p6217985165634"></a><a href="Graphic.md#gaaf2cda0d138bb4b3a752f875f146a5bc">~UIChartDataSerial</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312729029165634"><a name="p1312729029165634"></a><a name="p1312729029165634"></a>virtual </p>
<p id="p443189750165634"><a name="p443189750165634"></a><a name="p443189750165634"></a>A destructor used to delete the <strong id="b424500105165634"><a name="b424500105165634"></a><a name="b424500105165634"></a><a href="OHOS-UIChartDataSerial.md">UIChartDataSerial</a></strong> instance. </p>
</td>
</tr>
<tr id="row200709516165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p500129761165634"><a name="p500129761165634"></a><a name="p500129761165634"></a><a href="Graphic.md#ga81133f20156b6dc269927a5be9caf653">SetMaxDataCount</a> (uint16_t maxCount)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1899712076165634"><a name="p1899712076165634"></a><a name="p1899712076165634"></a>bool </p>
<p id="p1920495037165634"><a name="p1920495037165634"></a><a name="p1920495037165634"></a>Sets the maximum number of data points that can be stored in a data set. </p>
</td>
</tr>
<tr id="row1215301653165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p902902960165634"><a name="p902902960165634"></a><a name="p902902960165634"></a><a href="Graphic.md#gaa4e5a9c7d456a3753020a3fb88159c83">ModifyPoint</a> (uint16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, const <a href="OHOS-Point.md">Point</a> &amp;point)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p310362700165634"><a name="p310362700165634"></a><a name="p310362700165634"></a>bool </p>
<p id="p1320238887165634"><a name="p1320238887165634"></a><a name="p1320238887165634"></a>Modifies the value of a data point in the data set. </p>
</td>
</tr>
<tr id="row1328517991165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145635082165634"><a name="p2145635082165634"></a><a name="p2145635082165634"></a><a href="Graphic.md#ga32f85e7d3d9c67d491caa4105c6fa379">GetPoint</a> (uint16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, <a href="OHOS-Point.md">Point</a> &amp;point)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1217841865165634"><a name="p1217841865165634"></a><a name="p1217841865165634"></a>bool </p>
<p id="p503722718165634"><a name="p503722718165634"></a><a name="p503722718165634"></a>Obtains the coordinates in the chart for a data point in the data set. </p>
</td>
</tr>
<tr id="row1794479100165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1669567785165634"><a name="p1669567785165634"></a><a name="p1669567785165634"></a><a href="Graphic.md#ga88d554725405cf9c501f145a25448238">AddPoints</a> (const <a href="OHOS-Point.md">Point</a> *data, uint16_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1284576816165634"><a name="p1284576816165634"></a><a name="p1284576816165634"></a>bool </p>
<p id="p426663577165634"><a name="p426663577165634"></a><a name="p426663577165634"></a>Adds data points. </p>
</td>
</tr>
<tr id="row1485166082165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p62004081165634"><a name="p62004081165634"></a><a name="p62004081165634"></a><a href="Graphic.md#ga148d9b3933a733433a96a48b95cff844">ClearData</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141390461165634"><a name="p2141390461165634"></a><a name="p2141390461165634"></a>void </p>
<p id="p243403484165634"><a name="p243403484165634"></a><a name="p243403484165634"></a>Clears all data points. </p>
</td>
</tr>
<tr id="row1269328002165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p403198018165634"><a name="p403198018165634"></a><a name="p403198018165634"></a><a href="Graphic.md#ga42b69b4725ed1d61bb8da019562c3fb2">GetDataCount</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035746975165634"><a name="p1035746975165634"></a><a name="p1035746975165634"></a>uint16_t </p>
<p id="p1033100217165634"><a name="p1033100217165634"></a><a name="p1033100217165634"></a>Obtains the number of data points available in the data set. </p>
</td>
</tr>
<tr id="row657700950165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948041842165634"><a name="p1948041842165634"></a><a name="p1948041842165634"></a><a href="Graphic.md#ga9a3d5d81adbef7f847b631d03a472fbd">EnableSmooth</a> (bool smooth)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1710893550165634"><a name="p1710893550165634"></a><a name="p1710893550165634"></a>void </p>
<p id="p559499975165634"><a name="p559499975165634"></a><a name="p559499975165634"></a>Sets whether to smooth a polyline. </p>
</td>
</tr>
<tr id="row1827631715165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200985189165634"><a name="p200985189165634"></a><a name="p200985189165634"></a><a href="Graphic.md#ga5d9211f3eaee4e1c9455709a228087fe">IsSmooth</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1777300875165634"><a name="p1777300875165634"></a><a name="p1777300875165634"></a>bool </p>
<p id="p1470830905165634"><a name="p1470830905165634"></a><a name="p1470830905165634"></a>Checks whether smoothing is performed on a polyline. </p>
</td>
</tr>
<tr id="row1514988399165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408077748165634"><a name="p408077748165634"></a><a name="p408077748165634"></a><a href="Graphic.md#gaa4635e5332809fc7a275c4077f9d140d">EnableGradient</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p913400552165634"><a name="p913400552165634"></a><a name="p913400552165634"></a>void </p>
<p id="p1869585444165634"><a name="p1869585444165634"></a><a name="p1869585444165634"></a>Enables the fill color of a line chart. </p>
</td>
</tr>
<tr id="row862820155165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114701534165634"><a name="p2114701534165634"></a><a name="p2114701534165634"></a><a href="Graphic.md#ga6188c14ea249a34db4819499f4e38133">IsGradient</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p27646423165634"><a name="p27646423165634"></a><a name="p27646423165634"></a>bool </p>
<p id="p1081812764165634"><a name="p1081812764165634"></a><a name="p1081812764165634"></a>Checks whether a polyline has a fill color. </p>
</td>
</tr>
<tr id="row77238224165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485887055165634"><a name="p1485887055165634"></a><a name="p1485887055165634"></a><a href="Graphic.md#ga60c2b77e89d616a416a05f18b5c5c055">GetPeakIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p311543747165634"><a name="p311543747165634"></a><a name="p311543747165634"></a>uint16_t </p>
<p id="p1616150716165634"><a name="p1616150716165634"></a><a name="p1616150716165634"></a>Obtains the index of the top point in the data set. </p>
</td>
</tr>
<tr id="row1259949110165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481687821165634"><a name="p481687821165634"></a><a name="p481687821165634"></a><a href="Graphic.md#ga390d7cfb4e3ced676ec6c7ac22c1ccc5">GetLatestIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p368083014165634"><a name="p368083014165634"></a><a name="p368083014165634"></a>uint16_t </p>
<p id="p1233007012165634"><a name="p1233007012165634"></a><a name="p1233007012165634"></a>Obtains the index of the frontmost point (the latest added or modified data point in a data set). </p>
</td>
</tr>
<tr id="row1849176872165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751290446165634"><a name="p1751290446165634"></a><a name="p1751290446165634"></a><a href="Graphic.md#ga630a7356e3dbcb212a2e88ef0c6b857d">GetValleyIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735397656165634"><a name="p735397656165634"></a><a name="p735397656165634"></a>uint16_t </p>
<p id="p524600434165634"><a name="p524600434165634"></a><a name="p524600434165634"></a>Obtains the index of the bottom point in a data set. </p>
</td>
</tr>
<tr id="row1074992428165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p865729166165634"><a name="p865729166165634"></a><a name="p865729166165634"></a><a href="Graphic.md#gaf6c796fbd08cab47cf4fc0d41185a591">GetPeakData</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p287851511165634"><a name="p287851511165634"></a><a name="p287851511165634"></a>int16_t </p>
<p id="p119176483165634"><a name="p119176483165634"></a><a name="p119176483165634"></a>Obtains the Y value of the top point in a data set. </p>
</td>
</tr>
<tr id="row1990388970165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p822316034165634"><a name="p822316034165634"></a><a name="p822316034165634"></a><a href="Graphic.md#gae75c525df3451cb5e863d15fd36db07e">GetValleyData</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p341145689165634"><a name="p341145689165634"></a><a name="p341145689165634"></a>int16_t </p>
<p id="p1696412426165634"><a name="p1696412426165634"></a><a name="p1696412426165634"></a>Obtains the Y value of the bottom point in a data set. </p>
</td>
</tr>
<tr id="row185059442165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1597419948165634"><a name="p1597419948165634"></a><a name="p1597419948165634"></a><a href="Graphic.md#gaa35d69c841a74505735d1acb60476f13">GetLineColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540783200165634"><a name="p540783200165634"></a><a name="p540783200165634"></a><a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1128691015165634"><a name="p1128691015165634"></a><a name="p1128691015165634"></a>Obtains the polyline color of the data set in a line chart. </p>
</td>
</tr>
<tr id="row1392376772165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p127225831165634"><a name="p127225831165634"></a><a name="p127225831165634"></a><a href="Graphic.md#ga3b20df3a339aa0f41d404eb3dc1d12ca">GetFillColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103444071165634"><a name="p103444071165634"></a><a name="p103444071165634"></a><a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p2002446266165634"><a name="p2002446266165634"></a><a name="p2002446266165634"></a>Obtains the fill color of the data set. </p>
</td>
</tr>
<tr id="row1268674677165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2130503401165634"><a name="p2130503401165634"></a><a name="p2130503401165634"></a><a href="Graphic.md#gac620b9878a5e28d066dffbcd6145539c">SetFillColor</a> (const <a href="OHOS-Color32.md">ColorType</a> &amp;color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085858238165634"><a name="p1085858238165634"></a><a name="p1085858238165634"></a>void </p>
<p id="p1403857227165634"><a name="p1403857227165634"></a><a name="p1403857227165634"></a>Sets the fill color of the data set. </p>
</td>
</tr>
<tr id="row937267004165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2059964958165634"><a name="p2059964958165634"></a><a name="p2059964958165634"></a><a href="Graphic.md#ga94beac0c71885b8546996271c876f999">SetLineColor</a> (const <a href="OHOS-Color32.md">ColorType</a> &amp;color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1359510919165634"><a name="p1359510919165634"></a><a name="p1359510919165634"></a>void </p>
<p id="p319996800165634"><a name="p319996800165634"></a><a name="p319996800165634"></a>Sets the polyline color of the data set in the line chart. </p>
</td>
</tr>
<tr id="row2088579991165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709931336165634"><a name="p1709931336165634"></a><a name="p1709931336165634"></a><a href="Graphic.md#ga02cb658da66c73863ac2a49849e23b24">HidePoint</a> (uint16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>, uint16_t count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769495287165634"><a name="p1769495287165634"></a><a name="p1769495287165634"></a>void </p>
<p id="p1140381414165634"><a name="p1140381414165634"></a><a name="p1140381414165634"></a>Hides some points in the data set. </p>
</td>
</tr>
<tr id="row1991880607165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393446837165634"><a name="p1393446837165634"></a><a name="p1393446837165634"></a><a href="Graphic.md#ga607716e734fba2eef917fdee372e43b1">GetHideIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777599430165634"><a name="p777599430165634"></a><a name="p777599430165634"></a>uint16_t </p>
<p id="p1787721692165634"><a name="p1787721692165634"></a><a name="p1787721692165634"></a>Obtains the index from which the data set starts to hide. </p>
</td>
</tr>
<tr id="row401224478165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806795541165634"><a name="p1806795541165634"></a><a name="p1806795541165634"></a><a href="Graphic.md#ga736907dd9f33b5335f0df5599f5cb006">GetHideCount</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p394719674165634"><a name="p394719674165634"></a><a name="p394719674165634"></a>uint16_t </p>
<p id="p2018247202165634"><a name="p2018247202165634"></a><a name="p2018247202165634"></a>Obtains the number of hidden points in the data set. </p>
</td>
</tr>
<tr id="row207248426165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p503502757165634"><a name="p503502757165634"></a><a name="p503502757165634"></a><a href="Graphic.md#ga8fcb9d0640963ff30ff010ca5d387ff2">SetHeadPointStyle</a> (const <a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p955906794165634"><a name="p955906794165634"></a><a name="p955906794165634"></a>void </p>
<p id="p312317263165634"><a name="p312317263165634"></a><a name="p312317263165634"></a>Sets the style of the frontmost point on a polyline. </p>
</td>
</tr>
<tr id="row712013083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1709530363165634"><a name="p1709530363165634"></a><a name="p1709530363165634"></a><a href="Graphic.md#ga91b0d5442e708e2d2bd39436b5d46baa">SetTopPointStyle</a> (const <a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p745706633165634"><a name="p745706633165634"></a><a name="p745706633165634"></a>void </p>
<p id="p1925086532165634"><a name="p1925086532165634"></a><a name="p1925086532165634"></a>Sets the style of the top point of a polyline. </p>
</td>
</tr>
<tr id="row345694833165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p799657621165634"><a name="p799657621165634"></a><a name="p799657621165634"></a><a href="Graphic.md#gab99eef3cd222625e8d3a30cca815ced2">SetBottomPointStyle</a> (const <a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1581046687165634"><a name="p1581046687165634"></a><a name="p1581046687165634"></a>void </p>
<p id="p560961201165634"><a name="p560961201165634"></a><a name="p560961201165634"></a>Sets the style of the bottom point of a polyline. </p>
</td>
</tr>
<tr id="row1776409997165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16092003165634"><a name="p16092003165634"></a><a name="p16092003165634"></a><a href="Graphic.md#ga37a267a68383b41ce1d5c9072c2f7e83">GetHeadPointStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770712269165634"><a name="p770712269165634"></a><a name="p770712269165634"></a>const <a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a> &amp; </p>
<p id="p143983869165634"><a name="p143983869165634"></a><a name="p143983869165634"></a>Obtains the style of the frontmost point on a polyline. </p>
</td>
</tr>
<tr id="row1081138755165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p883956090165634"><a name="p883956090165634"></a><a name="p883956090165634"></a><a href="Graphic.md#ga215f5c5f8de923f0aa399a6bbdf78e18">GetTopPointStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1980625986165634"><a name="p1980625986165634"></a><a name="p1980625986165634"></a>const <a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a> &amp; </p>
<p id="p1180309862165634"><a name="p1180309862165634"></a><a name="p1180309862165634"></a>Obtains the style of the top point of a polyline. </p>
</td>
</tr>
<tr id="row159416537165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1212678722165634"><a name="p1212678722165634"></a><a name="p1212678722165634"></a><a href="Graphic.md#gaca803ecb139a0dae90825748bdbbf12b">GetBottomPointStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1613345425165634"><a name="p1613345425165634"></a><a name="p1613345425165634"></a>const <a href="OHOS-UIChartDataSerial-PointStyle.md">PointStyle</a> &amp; </p>
<p id="p1679038947165634"><a name="p1679038947165634"></a><a name="p1679038947165634"></a>Obtains the style of the bottom point of a polyline. </p>
</td>
</tr>
<tr id="row1408183954165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032615675165634"><a name="p2032615675165634"></a><a name="p2032615675165634"></a><a href="Graphic.md#gaa90973e2315035570ffae0d4c3c2e976">EnableHeadPoint</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1258934935165634"><a name="p1258934935165634"></a><a name="p1258934935165634"></a>void </p>
<p id="p1404339702165634"><a name="p1404339702165634"></a><a name="p1404339702165634"></a>Enables the feature of drawing the frontmost point on a polyline. </p>
</td>
</tr>
<tr id="row218866279165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1947469010165634"><a name="p1947469010165634"></a><a name="p1947469010165634"></a><a href="Graphic.md#gab97d84ead6aa301d2ae23fc68aa98a9f">EnableTopPoint</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1340496467165634"><a name="p1340496467165634"></a><a name="p1340496467165634"></a>void </p>
<p id="p1721575536165634"><a name="p1721575536165634"></a><a name="p1721575536165634"></a>Enables the feature of drawing the top point of a polyline. If there are multiple top points, only the first one is drawn. </p>
</td>
</tr>
<tr id="row743686369165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807942740165634"><a name="p1807942740165634"></a><a name="p1807942740165634"></a><a href="Graphic.md#ga2c0d693d31efd256cc6529255699ddd3">EnableBottomPoint</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1828386042165634"><a name="p1828386042165634"></a><a name="p1828386042165634"></a>void </p>
<p id="p814408071165634"><a name="p814408071165634"></a><a name="p814408071165634"></a>Enables the feature of drawing the bottom point of a polyline. If there are multiple bottom points, only the first one is drawn. </p>
</td>
</tr>
<tr id="row19136716165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980236435165634"><a name="p980236435165634"></a><a name="p980236435165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771249473165634"><a name="p1771249473165634"></a><a name="p1771249473165634"></a>void * </p>
<p id="p1549689796165634"><a name="p1549689796165634"></a><a name="p1549689796165634"></a>Overrides the <strong id="b382084359165634"><a name="b382084359165634"></a><a name="b382084359165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1580389693165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1146537299165634"><a name="p1146537299165634"></a><a name="p1146537299165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200148715165634"><a name="p1200148715165634"></a><a name="p1200148715165634"></a>void </p>
<p id="p1188392287165634"><a name="p1188392287165634"></a><a name="p1188392287165634"></a>Overrides the <strong id="b1661441008165634"><a name="b1661441008165634"></a><a name="b1661441008165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

