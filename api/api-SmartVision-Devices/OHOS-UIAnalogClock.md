# OHOS::UIAnalogClock<a name="ZH-CN_TOPIC_0000001054718147"></a>

-   [Overview](#section750660902165633)
-   [Summary](#section305876497165633)
-   [Data Structures](#nested-classes)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section750660902165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Provides the functions related to an analog clock. 

See also
:   [UIAbstractClock](OHOS-UIAbstractClock.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section305876497165633"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table153959660165633"></a>
<table><thead align="left"><tr id="row1944330668165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p225401929165633"><a name="p225401929165633"></a><a name="p225401929165633"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2039887666165633"><a name="p2039887666165633"></a><a name="p2039887666165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row25589259165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585943190165633"><a name="p585943190165633"></a><a name="p585943190165633"></a><a href="OHOS-UIAnalogClock-Hand.md">Hand</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1676282793165633"><a name="p1676282793165633"></a><a name="p1676282793165633"></a>Defines the basic attributes of the analog clock hands. This is an inner class of <strong id="b1903095207165633"><a name="b1903095207165633"></a><a name="b1903095207165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong>. </p>
</td>
</tr>
</tbody>
</table>

## Public Types<a name="pub-types"></a>

<a name="table1744828637165633"></a>
<table><thead align="left"><tr id="row1483425905165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1845805609165633"><a name="p1845805609165633"></a><a name="p1845805609165633"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1012761104165633"><a name="p1012761104165633"></a><a name="p1012761104165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row565953965165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p84089678165633"><a name="p84089678165633"></a><a name="p84089678165633"></a><a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> { <a href="Graphic.md#gga13cf64ea5bd39550976aaf65b1381edfa2b8ab55559dff5a849bf7445f6865958">HandType::HOUR_HAND</a>, <a href="Graphic.md#gga13cf64ea5bd39550976aaf65b1381edfa50ddc7aea61ec54878c173e1423af447">HandType::MINUTE_HAND</a>, <a href="Graphic.md#gga13cf64ea5bd39550976aaf65b1381edfa620c615d18fdb1b23ed04df57842909d">HandType::SECOND_HAND</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1536063408165633"><a name="p1536063408165633"></a><a name="p1536063408165633"></a>Enumerates the clock hand types. </p>
</td>
</tr>
<tr id="row1865399246165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870386180165633"><a name="p870386180165633"></a><a name="p870386180165633"></a><a href="Graphic.md#ga0a595eeb50ce4e7dfff9ede16098d2db">DrawType</a> { <a href="Graphic.md#gga0a595eeb50ce4e7dfff9ede16098d2dba6ddf16010fbdac5db23575583cb8a388">DrawType::DRAW_LINE</a>, <a href="Graphic.md#gga0a595eeb50ce4e7dfff9ede16098d2dba5cb6a362b1dec2b19422e9e9a6bbda3c">DrawType::DRAW_IMAGE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043442330165633"><a name="p2043442330165633"></a><a name="p2043442330165633"></a>Enumerates the drawing types of a clock hand. </p>
</td>
</tr>
<tr id="row1838898486165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918995463165633"><a name="p1918995463165633"></a><a name="p1918995463165633"></a><a href="Graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> { <a href="Graphic.md#gga19db90932bc71e6bbced6ccf2935ac98a2025ac1a1f63409f0b37f444547ec859">ALWAYS_ON</a>, <a href="Graphic.md#gga19db90932bc71e6bbced6ccf2935ac98a8d32f103a422c6675618f5e9773b2eaa">NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544026067165633"><a name="p1544026067165633"></a><a name="p1544026067165633"></a>Enumerates the working modes of this clock. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table408295367165633"></a>
<table><thead align="left"><tr id="row307449850165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p679696718165633"><a name="p679696718165633"></a><a name="p679696718165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p337927669165633"><a name="p337927669165633"></a><a name="p337927669165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row197839174165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657755904165633"><a name="p1657755904165633"></a><a name="p1657755904165633"></a><a href="Graphic.md#ga2e986cb53c62dd015edced59450b9fff">UIAnalogClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38647407165633"><a name="p38647407165633"></a><a name="p38647407165633"></a> </p>
<p id="p612144171165633"><a name="p612144171165633"></a><a name="p612144171165633"></a>A default constructor used to create a <strong id="b1934180653165633"><a name="b1934180653165633"></a><a name="b1934180653165633"></a><a href="OHOS-UIAnalogClock.md">UIAnalogClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row339303002165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009881467165633"><a name="p1009881467165633"></a><a name="p1009881467165633"></a><a href="Graphic.md#ga4b06e05f003e25206d5fa772b303dcc5">~UIAnalogClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p458657900165633"><a name="p458657900165633"></a><a name="p458657900165633"></a>virtual </p>
<p id="p674731256165633"><a name="p674731256165633"></a><a name="p674731256165633"></a>A destructor used to delete the <strong id="b1643876134165633"><a name="b1643876134165633"></a><a name="b1643876134165633"></a><a href="OHOS-UIAnalogClock.md">UIAnalogClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row1840262812165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1604644592165633"><a name="p1604644592165633"></a><a name="p1604644592165633"></a><a href="Graphic.md#ga2f5123df8cbcc4f55c5192acbe30ba0d">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018236284165633"><a name="p1018236284165633"></a><a name="p1018236284165633"></a>UIViewType </p>
<p id="p1261369501165633"><a name="p1261369501165633"></a><a name="p1261369501165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row776890408165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630889089165633"><a name="p1630889089165633"></a><a name="p1630889089165633"></a><a href="Graphic.md#ga18816e5dae6a7b79cbc408b1bc70c584">SetHandImage</a> (<a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> type, const <a href="OHOS-UIImageView.md">UIImageView</a> &amp;img, <a href="OHOS-Point.md">Point</a> position, <a href="OHOS-Point.md">Point</a> center)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2108470161165633"><a name="p2108470161165633"></a><a name="p2108470161165633"></a>void </p>
<p id="p925167652165633"><a name="p925167652165633"></a><a name="p925167652165633"></a>Sets the image used to draw a clock hand. </p>
</td>
</tr>
<tr id="row1759575390165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025567033165633"><a name="p2025567033165633"></a><a name="p2025567033165633"></a><a href="Graphic.md#ga271358e8076b55ed48de19350b3e55de">SetHandLine</a> (<a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> type, <a href="OHOS-Point.md">Point</a> position, <a href="OHOS-Point.md">Point</a> center, <a href="OHOS-Color32.md">ColorType</a> color, uint16_t width, uint16_t height, OpacityType opacity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1786722438165633"><a name="p1786722438165633"></a><a name="p1786722438165633"></a>void </p>
<p id="p388429560165633"><a name="p388429560165633"></a><a name="p388429560165633"></a>Sets the line used to draw a clock hand. </p>
</td>
</tr>
<tr id="row1066870210165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1712632812165633"><a name="p1712632812165633"></a><a name="p1712632812165633"></a><a href="Graphic.md#ga4943396addd8f88fb131aa03319e3d8a">GetHandRotateCenter</a> (<a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> type) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719458312165633"><a name="p1719458312165633"></a><a name="p1719458312165633"></a><a href="OHOS-Point.md">Point</a> </p>
<p id="p1179938616165633"><a name="p1179938616165633"></a><a name="p1179938616165633"></a>Obtains the rotation center of a specified clock hand. </p>
</td>
</tr>
<tr id="row2145518667165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p517807182165633"><a name="p517807182165633"></a><a name="p517807182165633"></a><a href="Graphic.md#ga56b260401694fce13dc5f744cb8bf471">GetHandPosition</a> (<a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> type) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1488427541165633"><a name="p1488427541165633"></a><a name="p1488427541165633"></a><a href="OHOS-Point.md">Point</a> </p>
<p id="p2046198390165633"><a name="p2046198390165633"></a><a name="p2046198390165633"></a>Obtains the position of a specified clock hand. </p>
</td>
</tr>
<tr id="row973521961165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1154480978165633"><a name="p1154480978165633"></a><a name="p1154480978165633"></a><a href="Graphic.md#ga3fdfc7872768c5f5cea6627958f53ff8">GetHandInitAngle</a> (<a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> type) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360370183165633"><a name="p360370183165633"></a><a name="p360370183165633"></a>uint16_t </p>
<p id="p269812341165633"><a name="p269812341165633"></a><a name="p269812341165633"></a>Obtains the initial rotation angle of the specified clock hand. </p>
</td>
</tr>
<tr id="row448244235165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p728479507165633"><a name="p728479507165633"></a><a name="p728479507165633"></a><a href="Graphic.md#ga4092ecd3068a58937b750d308e8eca5f">GetHandCurrentAngle</a> (<a href="Graphic.md#ga13cf64ea5bd39550976aaf65b1381edf">HandType</a> type) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332981043165633"><a name="p332981043165633"></a><a name="p332981043165633"></a>uint16_t </p>
<p id="p1410838711165633"><a name="p1410838711165633"></a><a name="p1410838711165633"></a>Obtains the current rotation angle of the specified clock hand. </p>
</td>
</tr>
<tr id="row836945144165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61189129165633"><a name="p61189129165633"></a><a name="p61189129165633"></a><a href="Graphic.md#ga3099f37f0ff8cd1229c0734098649173">SetInitTime24Hour</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961094367165633"><a name="p1961094367165633"></a><a name="p1961094367165633"></a>void </p>
<p id="p1029692854165633"><a name="p1029692854165633"></a><a name="p1029692854165633"></a>Sets the initial time in the 24-hour format. </p>
</td>
</tr>
<tr id="row1645367012165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p743487617165633"><a name="p743487617165633"></a><a name="p743487617165633"></a><a href="Graphic.md#gaa118c65942244bb0948b626944c0eaf9">SetInitTime12Hour</a> (uint8_t hour, uint8_t minute, uint8_t second, bool am)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639282045165633"><a name="p639282045165633"></a><a name="p639282045165633"></a>void </p>
<p id="p1101988173165633"><a name="p1101988173165633"></a><a name="p1101988173165633"></a>Sets the initial time in the 12-hour format. </p>
</td>
</tr>
<tr id="row367007736165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1150033441165633"><a name="p1150033441165633"></a><a name="p1150033441165633"></a><a href="Graphic.md#ga6c943119bd89a863ec5f05722a1fd146">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1062883050165633"><a name="p1062883050165633"></a><a name="p1062883050165633"></a>void </p>
<p id="p770440325165633"><a name="p770440325165633"></a><a name="p770440325165633"></a>Draws an analog clock. </p>
</td>
</tr>
<tr id="row155876805165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p474977678165633"><a name="p474977678165633"></a><a name="p474977678165633"></a><a href="Graphic.md#ga1366a4ca45babb67f3103279a2bbc0bf">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679213289165633"><a name="p679213289165633"></a><a name="p679213289165633"></a>virtual void </p>
<p id="p831282528165633"><a name="p831282528165633"></a><a name="p831282528165633"></a>Performs the operations needed after the drawing. </p>
</td>
</tr>
<tr id="row1789188739165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984029999165633"><a name="p984029999165633"></a><a name="p984029999165633"></a><a href="Graphic.md#ga01d3098090d17bdd720df6e861784e13">SetPosition</a> (int16_t x, int16_t y) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001508852165633"><a name="p1001508852165633"></a><a name="p1001508852165633"></a>void </p>
<p id="p1504977518165633"><a name="p1504977518165633"></a><a name="p1504977518165633"></a>Sets the position for this analog clock. </p>
</td>
</tr>
<tr id="row427163715165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1275060423165633"><a name="p1275060423165633"></a><a name="p1275060423165633"></a><a href="Graphic.md#gaa7fad079e41c8efd137781350b60687b">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667428032165633"><a name="p667428032165633"></a><a name="p667428032165633"></a>void </p>
<p id="p1855063120165633"><a name="p1855063120165633"></a><a name="p1855063120165633"></a>Sets the position and size for this analog clock. </p>
</td>
</tr>
<tr id="row1576641857165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140488773165633"><a name="p140488773165633"></a><a name="p140488773165633"></a><a href="Graphic.md#ga1714e171ff1e9248932a9f2c14c82d12">SetWorkMode</a> (<a href="Graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> newMode) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460217812165633"><a name="p460217812165633"></a><a name="p460217812165633"></a>void </p>
<p id="p1882989610165633"><a name="p1882989610165633"></a><a name="p1882989610165633"></a>Sets the working mode for this analog clock. </p>
</td>
</tr>
<tr id="row2090154614165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1388955374165633"><a name="p1388955374165633"></a><a name="p1388955374165633"></a><a href="Graphic.md#ga5274a3e5b66e5f80aab899ef4e61edb2">UpdateClock</a> (bool clockInit) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1300215919165633"><a name="p1300215919165633"></a><a name="p1300215919165633"></a>void </p>
<p id="p255699536165633"><a name="p255699536165633"></a><a name="p255699536165633"></a>Updates the time of this analog clock. </p>
</td>
</tr>
<tr id="row1999598193165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1190804834165633"><a name="p1190804834165633"></a><a name="p1190804834165633"></a><a href="Graphic.md#ga160a40d9f81c72b606b3c5b05168bacf">UIAbstractClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1066537873165633"><a name="p1066537873165633"></a><a name="p1066537873165633"></a> </p>
<p id="p1116502135165633"><a name="p1116502135165633"></a><a name="p1116502135165633"></a>A default constructor used to create a <strong id="b452450954165633"><a name="b452450954165633"></a><a name="b452450954165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row2021315217165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p759566335165633"><a name="p759566335165633"></a><a name="p759566335165633"></a><a href="Graphic.md#ga93d3d68e48a79ee7fc4b42a9c0c0ccc1">UIAbstractClock</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1182484082165633"><a name="p1182484082165633"></a><a name="p1182484082165633"></a> </p>
<p id="p306461012165633"><a name="p306461012165633"></a><a name="p306461012165633"></a>A constructor used to create a <strong id="b863907827165633"><a name="b863907827165633"></a><a name="b863907827165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong> instance with time elements (hour, minute and second). </p>
</td>
</tr>
<tr id="row377348525165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1295541902165633"><a name="p1295541902165633"></a><a name="p1295541902165633"></a><a href="Graphic.md#ga0fb0c108b319f02b9d42b34c1d2c8708">~UIAbstractClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771630653165633"><a name="p1771630653165633"></a><a name="p1771630653165633"></a>virtual </p>
<p id="p1994609454165633"><a name="p1994609454165633"></a><a name="p1994609454165633"></a>A destructor used to delete the <strong id="b1550674771165633"><a name="b1550674771165633"></a><a name="b1550674771165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row2043928197165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659568014165633"><a name="p659568014165633"></a><a name="p659568014165633"></a><a href="Graphic.md#ga44a7312163a4192670c00bb8f9916e51">SetTime24Hour</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834554767165633"><a name="p834554767165633"></a><a name="p834554767165633"></a>void </p>
<p id="p54050692165633"><a name="p54050692165633"></a><a name="p54050692165633"></a>Sets the time in 24-hour format. </p>
</td>
</tr>
<tr id="row1171075577165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1056154385165633"><a name="p1056154385165633"></a><a name="p1056154385165633"></a><a href="Graphic.md#ga37750dfa0b5a47c8dcb61547dd991a6a">SetTime12Hour</a> (uint8_t hour, uint8_t minute, uint8_t second, bool am)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p804766025165633"><a name="p804766025165633"></a><a name="p804766025165633"></a>void </p>
<p id="p751822916165633"><a name="p751822916165633"></a><a name="p751822916165633"></a>Sets the time in 12-hour format. </p>
</td>
</tr>
<tr id="row169223368165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p915439400165633"><a name="p915439400165633"></a><a name="p915439400165633"></a><a href="Graphic.md#ga8cf863dfcd63410f2f20572a51f2516b">GetCurrentHour</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570419937165633"><a name="p1570419937165633"></a><a name="p1570419937165633"></a>uint8_t </p>
<p id="p485721985165633"><a name="p485721985165633"></a><a name="p485721985165633"></a>Obtains the current number of hours. </p>
</td>
</tr>
<tr id="row1533739313165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2004113915165633"><a name="p2004113915165633"></a><a name="p2004113915165633"></a><a href="Graphic.md#ga5f0eea09577104d9126a07bfbc0b780a">GetCurrentMinute</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306536429165633"><a name="p306536429165633"></a><a name="p306536429165633"></a>uint8_t </p>
<p id="p1574242426165633"><a name="p1574242426165633"></a><a name="p1574242426165633"></a>Obtains the current number of minutes. </p>
</td>
</tr>
<tr id="row964265413165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p474595802165633"><a name="p474595802165633"></a><a name="p474595802165633"></a><a href="Graphic.md#ga7bd4d2d4631d9ea373d008ec7a5d18ff">GetCurrentSecond</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1302563674165633"><a name="p1302563674165633"></a><a name="p1302563674165633"></a>uint8_t </p>
<p id="p1519698309165633"><a name="p1519698309165633"></a><a name="p1519698309165633"></a>Obtains the current number of seconds. </p>
</td>
</tr>
<tr id="row347120334165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607982136165633"><a name="p607982136165633"></a><a name="p607982136165633"></a><a href="Graphic.md#gaf4c05e6acf6700d7edb69dc49cd6fef8">IncOneSecond</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1406016638165633"><a name="p1406016638165633"></a><a name="p1406016638165633"></a>void </p>
<p id="p16506307165633"><a name="p16506307165633"></a><a name="p16506307165633"></a>Increases the time by one second. </p>
</td>
</tr>
<tr id="row701852944165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904193571165633"><a name="p904193571165633"></a><a name="p904193571165633"></a><a href="Graphic.md#gad2d78422d212ef1e93bb4a23e1ee3859">GetWorkMode</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p936229996165633"><a name="p936229996165633"></a><a name="p936229996165633"></a>virtual <a href="Graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> </p>
<p id="p705427679165633"><a name="p705427679165633"></a><a name="p705427679165633"></a>Obtains the working mode of this clock. </p>
</td>
</tr>
<tr id="row1363887099165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919056201165633"><a name="p919056201165633"></a><a name="p919056201165633"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777486486165633"><a name="p777486486165633"></a><a name="p777486486165633"></a> </p>
<p id="p305083186165633"><a name="p305083186165633"></a><a name="p305083186165633"></a>A default constructor used to create a <strong id="b1801614760165633"><a name="b1801614760165633"></a><a name="b1801614760165633"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1667642912165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1610992719165633"><a name="p1610992719165633"></a><a name="p1610992719165633"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700150053165633"><a name="p1700150053165633"></a><a name="p1700150053165633"></a>virtual </p>
<p id="p1622513979165633"><a name="p1622513979165633"></a><a name="p1622513979165633"></a>A destructor used to delete the <strong id="b1164519241165633"><a name="b1164519241165633"></a><a name="b1164519241165633"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row635054948165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1747828125165633"><a name="p1747828125165633"></a><a name="p1747828125165633"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1029082295165633"><a name="p1029082295165633"></a><a name="p1029082295165633"></a>UIViewType </p>
<p id="p1120331200165633"><a name="p1120331200165633"></a><a name="p1120331200165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1897751495165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1517182907165633"><a name="p1517182907165633"></a><a name="p1517182907165633"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1044857987165633"><a name="p1044857987165633"></a><a name="p1044857987165633"></a>virtual void </p>
<p id="p523486215165633"><a name="p523486215165633"></a><a name="p523486215165633"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row53580659165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1769517203165633"><a name="p1769517203165633"></a><a name="p1769517203165633"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p421274387165633"><a name="p421274387165633"></a><a name="p421274387165633"></a>virtual void </p>
<p id="p1548574834165633"><a name="p1548574834165633"></a><a name="p1548574834165633"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row86811166165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246359652165633"><a name="p1246359652165633"></a><a name="p1246359652165633"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400361976165633"><a name="p1400361976165633"></a><a name="p1400361976165633"></a>virtual void </p>
<p id="p1763104094165633"><a name="p1763104094165633"></a><a name="p1763104094165633"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1971728394165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p352465831165633"><a name="p352465831165633"></a><a name="p352465831165633"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39644667165633"><a name="p39644667165633"></a><a name="p39644667165633"></a>virtual void </p>
<p id="p324346205165633"><a name="p324346205165633"></a><a name="p324346205165633"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row2125920442165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p856252959165633"><a name="p856252959165633"></a><a name="p856252959165633"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372431620165633"><a name="p1372431620165633"></a><a name="p1372431620165633"></a>virtual void </p>
<p id="p474304816165633"><a name="p474304816165633"></a><a name="p474304816165633"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row74690911165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654881026165633"><a name="p1654881026165633"></a><a name="p1654881026165633"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894538186165633"><a name="p1894538186165633"></a><a name="p1894538186165633"></a>virtual void </p>
<p id="p1129962077165633"><a name="p1129962077165633"></a><a name="p1129962077165633"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row346292864165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1098644956165633"><a name="p1098644956165633"></a><a name="p1098644956165633"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p739081237165633"><a name="p739081237165633"></a><a name="p739081237165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p2123362474165633"><a name="p2123362474165633"></a><a name="p2123362474165633"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row2137484363165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764500944165633"><a name="p1764500944165633"></a><a name="p1764500944165633"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484960700165633"><a name="p1484960700165633"></a><a name="p1484960700165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1991213228165633"><a name="p1991213228165633"></a><a name="p1991213228165633"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row533024043165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1075090014165633"><a name="p1075090014165633"></a><a name="p1075090014165633"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273190137165633"><a name="p273190137165633"></a><a name="p273190137165633"></a>void </p>
<p id="p1781134511165633"><a name="p1781134511165633"></a><a name="p1781134511165633"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1736843146165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p252230437165633"><a name="p252230437165633"></a><a name="p252230437165633"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1104670638165633"><a name="p1104670638165633"></a><a name="p1104670638165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1031446003165633"><a name="p1031446003165633"></a><a name="p1031446003165633"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1358540906165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p253269344165633"><a name="p253269344165633"></a><a name="p253269344165633"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048007798165633"><a name="p1048007798165633"></a><a name="p1048007798165633"></a>void </p>
<p id="p999924391165633"><a name="p999924391165633"></a><a name="p999924391165633"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row431903005165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1247021594165633"><a name="p1247021594165633"></a><a name="p1247021594165633"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1643157749165633"><a name="p1643157749165633"></a><a name="p1643157749165633"></a> </p>
<p id="p1450576377165633"><a name="p1450576377165633"></a><a name="p1450576377165633"></a>A default constructor used to create an <strong id="b396308307165633"><a name="b396308307165633"></a><a name="b396308307165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row947461694165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p567662204165633"><a name="p567662204165633"></a><a name="p567662204165633"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1573390466165633"><a name="p1573390466165633"></a><a name="p1573390466165633"></a> </p>
<p id="p1474045442165633"><a name="p1474045442165633"></a><a name="p1474045442165633"></a>A constructor used to create an <strong id="b1222629928165633"><a name="b1222629928165633"></a><a name="b1222629928165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row444460694165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049696863165633"><a name="p2049696863165633"></a><a name="p2049696863165633"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p361024717165633"><a name="p361024717165633"></a><a name="p361024717165633"></a>virtual </p>
<p id="p599443852165633"><a name="p599443852165633"></a><a name="p599443852165633"></a>A destructor used to delete the <strong id="b805288890165633"><a name="b805288890165633"></a><a name="b805288890165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row171295791165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1701211737165633"><a name="p1701211737165633"></a><a name="p1701211737165633"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1158855783165633"><a name="p1158855783165633"></a><a name="p1158855783165633"></a>virtual bool </p>
<p id="p1930225005165633"><a name="p1930225005165633"></a><a name="p1930225005165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row512707567165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p180941721165633"><a name="p180941721165633"></a><a name="p180941721165633"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428518186165633"><a name="p1428518186165633"></a><a name="p1428518186165633"></a>virtual void </p>
<p id="p1135217641165633"><a name="p1135217641165633"></a><a name="p1135217641165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1677309364165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245094078165633"><a name="p245094078165633"></a><a name="p245094078165633"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1735342402165633"><a name="p1735342402165633"></a><a name="p1735342402165633"></a>void </p>
<p id="p654577405165633"><a name="p654577405165633"></a><a name="p654577405165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row30245360165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1148497308165633"><a name="p1148497308165633"></a><a name="p1148497308165633"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817699410165633"><a name="p1817699410165633"></a><a name="p1817699410165633"></a>void </p>
<p id="p711128509165633"><a name="p711128509165633"></a><a name="p711128509165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1320221772165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2102895646165633"><a name="p2102895646165633"></a><a name="p2102895646165633"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1630889706165633"><a name="p1630889706165633"></a><a name="p1630889706165633"></a>virtual bool </p>
<p id="p842181554165633"><a name="p842181554165633"></a><a name="p842181554165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1749015416165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975217524165633"><a name="p1975217524165633"></a><a name="p1975217524165633"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1898975409165633"><a name="p1898975409165633"></a><a name="p1898975409165633"></a>virtual bool </p>
<p id="p775672146165633"><a name="p775672146165633"></a><a name="p775672146165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1743510481165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p849117423165633"><a name="p849117423165633"></a><a name="p849117423165633"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152378278165633"><a name="p152378278165633"></a><a name="p152378278165633"></a>virtual bool </p>
<p id="p1690198078165633"><a name="p1690198078165633"></a><a name="p1690198078165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row2131129750165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423124624165633"><a name="p423124624165633"></a><a name="p423124624165633"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760937626165633"><a name="p1760937626165633"></a><a name="p1760937626165633"></a>virtual bool </p>
<p id="p510761187165633"><a name="p510761187165633"></a><a name="p510761187165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row673937246165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1297940948165633"><a name="p1297940948165633"></a><a name="p1297940948165633"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26644441165633"><a name="p26644441165633"></a><a name="p26644441165633"></a>virtual void </p>
<p id="p2060622463165633"><a name="p2060622463165633"></a><a name="p2060622463165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1024739858165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p467698008165633"><a name="p467698008165633"></a><a name="p467698008165633"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p450450307165633"><a name="p450450307165633"></a><a name="p450450307165633"></a>virtual void </p>
<p id="p1726032530165633"><a name="p1726032530165633"></a><a name="p1726032530165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row107007084165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2132886048165633"><a name="p2132886048165633"></a><a name="p2132886048165633"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1453749982165633"><a name="p1453749982165633"></a><a name="p1453749982165633"></a>virtual void </p>
<p id="p1238383718165633"><a name="p1238383718165633"></a><a name="p1238383718165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1376479677165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295654755165633"><a name="p295654755165633"></a><a name="p295654755165633"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1252956616165633"><a name="p1252956616165633"></a><a name="p1252956616165633"></a>virtual void </p>
<p id="p563059981165633"><a name="p563059981165633"></a><a name="p563059981165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row2003588023165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p416415762165633"><a name="p416415762165633"></a><a name="p416415762165633"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899978642165633"><a name="p899978642165633"></a><a name="p899978642165633"></a>void </p>
<p id="p1996823940165633"><a name="p1996823940165633"></a><a name="p1996823940165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row352440090165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p880471191165633"><a name="p880471191165633"></a><a name="p880471191165633"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1887591935165633"><a name="p1887591935165633"></a><a name="p1887591935165633"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p268255726165633"><a name="p268255726165633"></a><a name="p268255726165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row321500148165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p100568688165633"><a name="p100568688165633"></a><a name="p100568688165633"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100971048165633"><a name="p1100971048165633"></a><a name="p1100971048165633"></a>void </p>
<p id="p1271205418165633"><a name="p1271205418165633"></a><a name="p1271205418165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1048788709165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1233879222165633"><a name="p1233879222165633"></a><a name="p1233879222165633"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140788683165633"><a name="p2140788683165633"></a><a name="p2140788683165633"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p884378382165633"><a name="p884378382165633"></a><a name="p884378382165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row807349892165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1267416142165633"><a name="p1267416142165633"></a><a name="p1267416142165633"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746135433165633"><a name="p1746135433165633"></a><a name="p1746135433165633"></a>void </p>
<p id="p414431670165633"><a name="p414431670165633"></a><a name="p414431670165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row208904738165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1676179176165633"><a name="p1676179176165633"></a><a name="p1676179176165633"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76089814165633"><a name="p76089814165633"></a><a name="p76089814165633"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1174069049165633"><a name="p1174069049165633"></a><a name="p1174069049165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1389107510165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p809314242165633"><a name="p809314242165633"></a><a name="p809314242165633"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957874787165633"><a name="p957874787165633"></a><a name="p957874787165633"></a>void </p>
<p id="p512324870165633"><a name="p512324870165633"></a><a name="p512324870165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row809501671165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526259323165633"><a name="p1526259323165633"></a><a name="p1526259323165633"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834315741165633"><a name="p834315741165633"></a><a name="p834315741165633"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p946465052165633"><a name="p946465052165633"></a><a name="p946465052165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1511858350165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607910767165633"><a name="p607910767165633"></a><a name="p607910767165633"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1737728551165633"><a name="p1737728551165633"></a><a name="p1737728551165633"></a>void </p>
<p id="p853960522165633"><a name="p853960522165633"></a><a name="p853960522165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row2004292644165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1817769101165633"><a name="p1817769101165633"></a><a name="p1817769101165633"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135481232165633"><a name="p2135481232165633"></a><a name="p2135481232165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p289282524165633"><a name="p289282524165633"></a><a name="p289282524165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row563474336165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1991868476165633"><a name="p1991868476165633"></a><a name="p1991868476165633"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391158886165633"><a name="p391158886165633"></a><a name="p391158886165633"></a>void </p>
<p id="p1794043476165633"><a name="p1794043476165633"></a><a name="p1794043476165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row255787452165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1004112449165633"><a name="p1004112449165633"></a><a name="p1004112449165633"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p244835549165633"><a name="p244835549165633"></a><a name="p244835549165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1142691764165633"><a name="p1142691764165633"></a><a name="p1142691764165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row319900101165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658432769165633"><a name="p658432769165633"></a><a name="p658432769165633"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769171865165633"><a name="p1769171865165633"></a><a name="p1769171865165633"></a>virtual void </p>
<p id="p1401517901165633"><a name="p1401517901165633"></a><a name="p1401517901165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1361010154165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p188450147165633"><a name="p188450147165633"></a><a name="p188450147165633"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1635830348165633"><a name="p1635830348165633"></a><a name="p1635830348165633"></a>bool </p>
<p id="p343086947165633"><a name="p343086947165633"></a><a name="p343086947165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row749346277165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047669683165633"><a name="p2047669683165633"></a><a name="p2047669683165633"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426355118165633"><a name="p1426355118165633"></a><a name="p1426355118165633"></a>void </p>
<p id="p532904866165633"><a name="p532904866165633"></a><a name="p532904866165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row651667796165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1216179040165633"><a name="p1216179040165633"></a><a name="p1216179040165633"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p306976448165633"><a name="p306976448165633"></a><a name="p306976448165633"></a>bool </p>
<p id="p831472189165633"><a name="p831472189165633"></a><a name="p831472189165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1094381695165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p925415967165633"><a name="p925415967165633"></a><a name="p925415967165633"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p226220674165633"><a name="p226220674165633"></a><a name="p226220674165633"></a>void </p>
<p id="p927445065165633"><a name="p927445065165633"></a><a name="p927445065165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row2137390661165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600882422165633"><a name="p1600882422165633"></a><a name="p1600882422165633"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p389807788165633"><a name="p389807788165633"></a><a name="p389807788165633"></a>bool </p>
<p id="p993345373165633"><a name="p993345373165633"></a><a name="p993345373165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1179859648165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2108812439165633"><a name="p2108812439165633"></a><a name="p2108812439165633"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1735215195165633"><a name="p1735215195165633"></a><a name="p1735215195165633"></a>void </p>
<p id="p902262882165633"><a name="p902262882165633"></a><a name="p902262882165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row880004789165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83395242165633"><a name="p83395242165633"></a><a name="p83395242165633"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p944845005165633"><a name="p944845005165633"></a><a name="p944845005165633"></a>bool </p>
<p id="p822344754165633"><a name="p822344754165633"></a><a name="p822344754165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row318100688165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303557258165633"><a name="p1303557258165633"></a><a name="p1303557258165633"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139245179165633"><a name="p2139245179165633"></a><a name="p2139245179165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p74350859165633"><a name="p74350859165633"></a><a name="p74350859165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row635962118165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p715981033165633"><a name="p715981033165633"></a><a name="p715981033165633"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176424372165633"><a name="p176424372165633"></a><a name="p176424372165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p835267497165633"><a name="p835267497165633"></a><a name="p835267497165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1780924707165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491926992165633"><a name="p1491926992165633"></a><a name="p1491926992165633"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764929978165633"><a name="p1764929978165633"></a><a name="p1764929978165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2045199675165633"><a name="p2045199675165633"></a><a name="p2045199675165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1297969620165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p789537590165633"><a name="p789537590165633"></a><a name="p789537590165633"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389518472165633"><a name="p1389518472165633"></a><a name="p1389518472165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p934443758165633"><a name="p934443758165633"></a><a name="p934443758165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row2024719939165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160096197165633"><a name="p160096197165633"></a><a name="p160096197165633"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637724415165633"><a name="p1637724415165633"></a><a name="p1637724415165633"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2088639559165633"><a name="p2088639559165633"></a><a name="p2088639559165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row439961770165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p762425550165633"><a name="p762425550165633"></a><a name="p762425550165633"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795334520165633"><a name="p795334520165633"></a><a name="p795334520165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1372713167165633"><a name="p1372713167165633"></a><a name="p1372713167165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row9279152165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2133129179165633"><a name="p2133129179165633"></a><a name="p2133129179165633"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499210481165633"><a name="p499210481165633"></a><a name="p499210481165633"></a>void </p>
<p id="p1355891168165633"><a name="p1355891168165633"></a><a name="p1355891168165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row951282699165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755616657165633"><a name="p755616657165633"></a><a name="p755616657165633"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587528739165633"><a name="p587528739165633"></a><a name="p587528739165633"></a>virtual void </p>
<p id="p169297422165633"><a name="p169297422165633"></a><a name="p169297422165633"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row960384206165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265288748165633"><a name="p1265288748165633"></a><a name="p1265288748165633"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1980676872165633"><a name="p1980676872165633"></a><a name="p1980676872165633"></a>virtual int16_t </p>
<p id="p1054402300165633"><a name="p1054402300165633"></a><a name="p1054402300165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row934780848165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1597351866165633"><a name="p1597351866165633"></a><a name="p1597351866165633"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143580263165633"><a name="p1143580263165633"></a><a name="p1143580263165633"></a>virtual void </p>
<p id="p538712859165633"><a name="p538712859165633"></a><a name="p538712859165633"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row315386641165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1937619165165633"><a name="p1937619165165633"></a><a name="p1937619165165633"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113646293165633"><a name="p113646293165633"></a><a name="p113646293165633"></a>virtual int16_t </p>
<p id="p447539406165633"><a name="p447539406165633"></a><a name="p447539406165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1531966806165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p925506847165633"><a name="p925506847165633"></a><a name="p925506847165633"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1656664689165633"><a name="p1656664689165633"></a><a name="p1656664689165633"></a>virtual void </p>
<p id="p658233453165633"><a name="p658233453165633"></a><a name="p658233453165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row41678737165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585097206165633"><a name="p585097206165633"></a><a name="p585097206165633"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p296744196165633"><a name="p296744196165633"></a><a name="p296744196165633"></a>virtual void </p>
<p id="p661209305165633"><a name="p661209305165633"></a><a name="p661209305165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1309841810165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1104723138165633"><a name="p1104723138165633"></a><a name="p1104723138165633"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949833086165633"><a name="p949833086165633"></a><a name="p949833086165633"></a>int16_t </p>
<p id="p1742175121165633"><a name="p1742175121165633"></a><a name="p1742175121165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1702114894165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1822629370165633"><a name="p1822629370165633"></a><a name="p1822629370165633"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1094296165165633"><a name="p1094296165165633"></a><a name="p1094296165165633"></a>virtual void </p>
<p id="p795511542165633"><a name="p795511542165633"></a><a name="p795511542165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row335492184165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1559293280165633"><a name="p1559293280165633"></a><a name="p1559293280165633"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p574441889165633"><a name="p574441889165633"></a><a name="p574441889165633"></a>int16_t </p>
<p id="p292028962165633"><a name="p292028962165633"></a><a name="p292028962165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1772134906165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1224266993165633"><a name="p1224266993165633"></a><a name="p1224266993165633"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1601251867165633"><a name="p1601251867165633"></a><a name="p1601251867165633"></a>bool </p>
<p id="p432378923165633"><a name="p432378923165633"></a><a name="p432378923165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1905615277165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1308157431165633"><a name="p1308157431165633"></a><a name="p1308157431165633"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208504719165633"><a name="p208504719165633"></a><a name="p208504719165633"></a>void </p>
<p id="p1689537231165633"><a name="p1689537231165633"></a><a name="p1689537231165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1438589433165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026051503165633"><a name="p2026051503165633"></a><a name="p2026051503165633"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037623483165633"><a name="p2037623483165633"></a><a name="p2037623483165633"></a>void </p>
<p id="p539406092165633"><a name="p539406092165633"></a><a name="p539406092165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1491007416165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1192891951165633"><a name="p1192891951165633"></a><a name="p1192891951165633"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p574927770165633"><a name="p574927770165633"></a><a name="p574927770165633"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p525329103165633"><a name="p525329103165633"></a><a name="p525329103165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1701942341165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1711094504165633"><a name="p1711094504165633"></a><a name="p1711094504165633"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615578845165633"><a name="p1615578845165633"></a><a name="p1615578845165633"></a>void </p>
<p id="p878995014165633"><a name="p878995014165633"></a><a name="p878995014165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row801965001165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1253657481165633"><a name="p1253657481165633"></a><a name="p1253657481165633"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2057987358165633"><a name="p2057987358165633"></a><a name="p2057987358165633"></a>const char * </p>
<p id="p1439125242165633"><a name="p1439125242165633"></a><a name="p1439125242165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row342696491165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p624112312165633"><a name="p624112312165633"></a><a name="p624112312165633"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507829941165633"><a name="p1507829941165633"></a><a name="p1507829941165633"></a>void </p>
<p id="p1754738651165633"><a name="p1754738651165633"></a><a name="p1754738651165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1504168687165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1432254165633"><a name="p1432254165633"></a><a name="p1432254165633"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473680668165633"><a name="p1473680668165633"></a><a name="p1473680668165633"></a>int16_t </p>
<p id="p1427481031165633"><a name="p1427481031165633"></a><a name="p1427481031165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row648337577165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1833122705165633"><a name="p1833122705165633"></a><a name="p1833122705165633"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p896475341165633"><a name="p896475341165633"></a><a name="p896475341165633"></a>virtual void </p>
<p id="p2112550420165633"><a name="p2112550420165633"></a><a name="p2112550420165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1816018069165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p479579022165633"><a name="p479579022165633"></a><a name="p479579022165633"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1133054824165633"><a name="p1133054824165633"></a><a name="p1133054824165633"></a>void </p>
<p id="p1985356836165633"><a name="p1985356836165633"></a><a name="p1985356836165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row372799750165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p945184378165633"><a name="p945184378165633"></a><a name="p945184378165633"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504656353165633"><a name="p1504656353165633"></a><a name="p1504656353165633"></a>void </p>
<p id="p2017538467165633"><a name="p2017538467165633"></a><a name="p2017538467165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row273775420165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p942514270165633"><a name="p942514270165633"></a><a name="p942514270165633"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p356232121165633"><a name="p356232121165633"></a><a name="p356232121165633"></a>void </p>
<p id="p1047428997165633"><a name="p1047428997165633"></a><a name="p1047428997165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1228946373165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514258953165633"><a name="p1514258953165633"></a><a name="p1514258953165633"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202909618165633"><a name="p202909618165633"></a><a name="p202909618165633"></a>void </p>
<p id="p1826192469165633"><a name="p1826192469165633"></a><a name="p1826192469165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row437087208165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p167940688165633"><a name="p167940688165633"></a><a name="p167940688165633"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p223329067165633"><a name="p223329067165633"></a><a name="p223329067165633"></a>void </p>
<p id="p1243895314165633"><a name="p1243895314165633"></a><a name="p1243895314165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row865152711165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323463288165633"><a name="p323463288165633"></a><a name="p323463288165633"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609572964165633"><a name="p609572964165633"></a><a name="p609572964165633"></a>void </p>
<p id="p165605868165633"><a name="p165605868165633"></a><a name="p165605868165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row2082678644165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286019305165633"><a name="p1286019305165633"></a><a name="p1286019305165633"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674047744165633"><a name="p674047744165633"></a><a name="p674047744165633"></a>void </p>
<p id="p205983208165633"><a name="p205983208165633"></a><a name="p205983208165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row417376972165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722477532165633"><a name="p722477532165633"></a><a name="p722477532165633"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972579778165633"><a name="p1972579778165633"></a><a name="p1972579778165633"></a>void </p>
<p id="p1706638581165633"><a name="p1706638581165633"></a><a name="p1706638581165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row975783051165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1059588875165633"><a name="p1059588875165633"></a><a name="p1059588875165633"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893510004165633"><a name="p1893510004165633"></a><a name="p1893510004165633"></a>void </p>
<p id="p229995574165633"><a name="p229995574165633"></a><a name="p229995574165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1818168295165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p108595530165633"><a name="p108595530165633"></a><a name="p108595530165633"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9436239165633"><a name="p9436239165633"></a><a name="p9436239165633"></a>void </p>
<p id="p963775288165633"><a name="p963775288165633"></a><a name="p963775288165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1478140858165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1030336285165633"><a name="p1030336285165633"></a><a name="p1030336285165633"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p867056482165633"><a name="p867056482165633"></a><a name="p867056482165633"></a>void </p>
<p id="p195041830165633"><a name="p195041830165633"></a><a name="p195041830165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row234515057165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300800704165633"><a name="p1300800704165633"></a><a name="p1300800704165633"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1855229771165633"><a name="p1855229771165633"></a><a name="p1855229771165633"></a>void </p>
<p id="p1650047412165633"><a name="p1650047412165633"></a><a name="p1650047412165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row2054075207165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1125212311165633"><a name="p1125212311165633"></a><a name="p1125212311165633"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916377040165633"><a name="p916377040165633"></a><a name="p916377040165633"></a>void </p>
<p id="p671479145165633"><a name="p671479145165633"></a><a name="p671479145165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1764699567165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p149650360165633"><a name="p149650360165633"></a><a name="p149650360165633"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p288818650165633"><a name="p288818650165633"></a><a name="p288818650165633"></a>void </p>
<p id="p526126263165633"><a name="p526126263165633"></a><a name="p526126263165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1410283583165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1244552353165633"><a name="p1244552353165633"></a><a name="p1244552353165633"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489229037165633"><a name="p489229037165633"></a><a name="p489229037165633"></a>void </p>
<p id="p1979608676165633"><a name="p1979608676165633"></a><a name="p1979608676165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1786794210165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478499216165633"><a name="p1478499216165633"></a><a name="p1478499216165633"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885143805165633"><a name="p1885143805165633"></a><a name="p1885143805165633"></a>void </p>
<p id="p1963839164165633"><a name="p1963839164165633"></a><a name="p1963839164165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row427814427165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p202118792165633"><a name="p202118792165633"></a><a name="p202118792165633"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964473556165633"><a name="p964473556165633"></a><a name="p964473556165633"></a>virtual void </p>
<p id="p2084145817165633"><a name="p2084145817165633"></a><a name="p2084145817165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row944267051165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2130486630165633"><a name="p2130486630165633"></a><a name="p2130486630165633"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727162105165633"><a name="p1727162105165633"></a><a name="p1727162105165633"></a>virtual int64_t </p>
<p id="p1737712806165633"><a name="p1737712806165633"></a><a name="p1737712806165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1732311946165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567929997165633"><a name="p1567929997165633"></a><a name="p1567929997165633"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043628961165633"><a name="p2043628961165633"></a><a name="p2043628961165633"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p465690748165633"><a name="p465690748165633"></a><a name="p465690748165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1053560732165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786298733165633"><a name="p786298733165633"></a><a name="p786298733165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911507623165633"><a name="p1911507623165633"></a><a name="p1911507623165633"></a>void * </p>
<p id="p1130263820165633"><a name="p1130263820165633"></a><a name="p1130263820165633"></a>Overrides the <strong id="b1509000042165633"><a name="b1509000042165633"></a><a name="b1509000042165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row780796532165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p733574152165633"><a name="p733574152165633"></a><a name="p733574152165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582459213165633"><a name="p1582459213165633"></a><a name="p1582459213165633"></a>void </p>
<p id="p813165747165633"><a name="p813165747165633"></a><a name="p813165747165633"></a>Overrides the <strong id="b328593189165633"><a name="b328593189165633"></a><a name="b328593189165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table511954981165633"></a>
<table><thead align="left"><tr id="row1636373275165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p143589513165633"><a name="p143589513165633"></a><a name="p143589513165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p567576747165633"><a name="p567576747165633"></a><a name="p567576747165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1041408315165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p276359805165633"><a name="p276359805165633"></a><a name="p276359805165633"></a><a href="Graphic.md#ga7f433b8551722451f880e7fa05731a2f">ONE_MINUTE_IN_SECOND</a> = 60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734457349165633"><a name="p734457349165633"></a><a name="p734457349165633"></a>Represents 60 seconds per minute. </p>
</td>
</tr>
<tr id="row353201544165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1900478816165633"><a name="p1900478816165633"></a><a name="p1900478816165633"></a><a href="Graphic.md#ga5434b911b6f7e0637ac0626c9dd0f513">ONE_HOUR_IN_MINUTE</a> = 60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163610367165633"><a name="p1163610367165633"></a><a name="p1163610367165633"></a>Represents 60 minutes per hour. </p>
</td>
</tr>
<tr id="row529697638165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p660075808165633"><a name="p660075808165633"></a><a name="p660075808165633"></a><a href="Graphic.md#gae7742f1e715885ecc4f5b67d57530319">ONE_DAY_IN_HOUR</a> = 24</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794142178165633"><a name="p794142178165633"></a><a name="p794142178165633"></a>Represents 24 hours per day. </p>
</td>
</tr>
<tr id="row1595549041165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p974658989165633"><a name="p974658989165633"></a><a name="p974658989165633"></a><a href="Graphic.md#gae40a5ae3834b626e2976fab83f166171">HALF_DAY_IN_HOUR</a> = 12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1167405079165633"><a name="p1167405079165633"></a><a name="p1167405079165633"></a>Represents 12 hours every half day. </p>
</td>
</tr>
<tr id="row1914942951165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016272378165633"><a name="p2016272378165633"></a><a name="p2016272378165633"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382776710165633"><a name="p1382776710165633"></a><a name="p1382776710165633"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row1330035733165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1632823822165633"><a name="p1632823822165633"></a><a name="p1632823822165633"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2003996194165633"><a name="p2003996194165633"></a><a name="p2003996194165633"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row566540564165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1724871530165633"><a name="p1724871530165633"></a><a name="p1724871530165633"></a><a href="Graphic.md#gaabfbbb277dabf5477c628336a429f8ad">currentHour_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213788517165633"><a name="p1213788517165633"></a><a name="p1213788517165633"></a>Represents the current number of hours. </p>
</td>
</tr>
<tr id="row211263489165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1516714234165633"><a name="p1516714234165633"></a><a name="p1516714234165633"></a><a href="Graphic.md#ga34c3518c0dc9f35fc77b240b6f8d0dcb">currentMinute_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1948804775165633"><a name="p1948804775165633"></a><a name="p1948804775165633"></a>Represents the current number of minutes. </p>
</td>
</tr>
<tr id="row1960428933165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p221538944165633"><a name="p221538944165633"></a><a name="p221538944165633"></a><a href="Graphic.md#ga5b2749cdc5e52551731923d8268b8d5d">currentSecond_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p233949341165633"><a name="p233949341165633"></a><a name="p233949341165633"></a>Represents the current number of seconds. </p>
</td>
</tr>
<tr id="row1340934833165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294243680165633"><a name="p294243680165633"></a><a name="p294243680165633"></a><a href="Graphic.md#gab08c7c490a5b42fcdee04d45b5521d1c">mode_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1227354323165633"><a name="p1227354323165633"></a><a name="p1227354323165633"></a>Represents the current working mode of this clock. </p>
</td>
</tr>
<tr id="row401523670165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563007587165633"><a name="p563007587165633"></a><a name="p563007587165633"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351257950165633"><a name="p1351257950165633"></a><a name="p1351257950165633"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1024612184165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1013185268165633"><a name="p1013185268165633"></a><a name="p1013185268165633"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p757388479165633"><a name="p757388479165633"></a><a name="p757388479165633"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1005154011165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p655966051165633"><a name="p655966051165633"></a><a name="p655966051165633"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1041239020165633"><a name="p1041239020165633"></a><a name="p1041239020165633"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row934092159165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1070795278165633"><a name="p1070795278165633"></a><a name="p1070795278165633"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645476955165633"><a name="p645476955165633"></a><a name="p645476955165633"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row874547667165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p885980000165633"><a name="p885980000165633"></a><a name="p885980000165633"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134578335165633"><a name="p1134578335165633"></a><a name="p1134578335165633"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row8346218165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948854293165633"><a name="p1948854293165633"></a><a name="p1948854293165633"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126026067165633"><a name="p1126026067165633"></a><a name="p1126026067165633"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

