# OHOS::UIDigitalClock<a name="EN-US_TOPIC_0000001055358132"></a>

-   [Overview](#section758940546165634)
-   [Summary](#section917645518165634)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section758940546165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Displays time digitally. 

See also
:   [UIDigitalClock](ohos-uidigitalclock.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section917645518165634"></a>

## Public Types<a name="pub-types"></a>

<a name="table493358758165634"></a>
<table><thead align="left"><tr id="row1471152930165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p488348487165634"><a name="p488348487165634"></a><a name="p488348487165634"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p126394425165634"><a name="p126394425165634"></a><a name="p126394425165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1681511797165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p644548595165634"><a name="p644548595165634"></a><a name="p644548595165634"></a><a href="graphic.md#gabe3b64b11e5bf5d7b54e1039e40f306b">DisplayMode</a> { <a href="graphic.md#ggabe3b64b11e5bf5d7b54e1039e40f306bafc93e631e582de9e4128be8e6d41dbfe">DISPLAY_12_HOUR_NO_SECONDS</a>, <a href="graphic.md#ggabe3b64b11e5bf5d7b54e1039e40f306ba0c5adc8c80a47a33eb7bfcbcad0b4163">DISPLAY_24_HOUR_NO_SECONDS</a>, <a href="graphic.md#ggabe3b64b11e5bf5d7b54e1039e40f306baa5cbeab2c7366db7f33b2e95da20615b">DISPLAY_12_HOUR</a>, <a href="graphic.md#ggabe3b64b11e5bf5d7b54e1039e40f306ba833c0664bba32e6fe4a53a1c471d0eb8">DISPLAY_24_HOUR</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p574251879165634"><a name="p574251879165634"></a><a name="p574251879165634"></a>Enumerates the display modes of this digital clock. </p>
</td>
</tr>
<tr id="row895458954165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545731567165634"><a name="p545731567165634"></a><a name="p545731567165634"></a><a href="graphic.md#gaa6aacc9ecbf5e20f22e50e542a69f472">TimeElement</a> { <a href="graphic.md#ggaa6aacc9ecbf5e20f22e50e542a69f472a8c15c8462a73ec9c9d9d3ad542ba4946">HOUR_ELEMENT</a>, <a href="graphic.md#ggaa6aacc9ecbf5e20f22e50e542a69f472ae60c24ee0bb6908798a770cb39034de2">MINUTE_ELEMENT</a>, <a href="graphic.md#ggaa6aacc9ecbf5e20f22e50e542a69f472a0299da12b65446f25e530d8d20881a1a">SECOND_ELEMENT</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959012617165634"><a name="p1959012617165634"></a><a name="p1959012617165634"></a>Enumerates the time elements of this digital clock. </p>
</td>
</tr>
<tr id="row1696886232165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28450119165634"><a name="p28450119165634"></a><a name="p28450119165634"></a><a href="graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> { <a href="graphic.md#gga19db90932bc71e6bbced6ccf2935ac98a2025ac1a1f63409f0b37f444547ec859">ALWAYS_ON</a>, <a href="graphic.md#gga19db90932bc71e6bbced6ccf2935ac98a8d32f103a422c6675618f5e9773b2eaa">NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734344749165634"><a name="p1734344749165634"></a><a name="p1734344749165634"></a>Enumerates the working modes of this clock. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table405055187165634"></a>
<table><thead align="left"><tr id="row288685275165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1026927034165634"><a name="p1026927034165634"></a><a name="p1026927034165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p110643174165634"><a name="p110643174165634"></a><a name="p110643174165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row132525574165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1473664795165634"><a name="p1473664795165634"></a><a name="p1473664795165634"></a><a href="graphic.md#gac89c3f554cea687e0b7d7338319c8d0b">UIDigitalClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447807575165634"><a name="p1447807575165634"></a><a name="p1447807575165634"></a> </p>
<p id="p1754317389165634"><a name="p1754317389165634"></a><a name="p1754317389165634"></a>A default constructor used to create a <strong id="b1895363701165634"><a name="b1895363701165634"></a><a name="b1895363701165634"></a><a href="ohos-uidigitalclock.md">UIDigitalClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row1393157038165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1544790097165634"><a name="p1544790097165634"></a><a name="p1544790097165634"></a><a href="graphic.md#gaf4daabe77c9ab8264618a4f970b0a15e">~UIDigitalClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455024169165634"><a name="p1455024169165634"></a><a name="p1455024169165634"></a>virtual </p>
<p id="p1415943304165634"><a name="p1415943304165634"></a><a name="p1415943304165634"></a>A destructor used to delete the <strong id="b761298194165634"><a name="b761298194165634"></a><a name="b761298194165634"></a><a href="ohos-uidigitalclock.md">UIDigitalClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row260585021165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062180632165634"><a name="p1062180632165634"></a><a name="p1062180632165634"></a><a href="graphic.md#ga567a8195e8520b74b682de697cfe1d90">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1370655524165634"><a name="p1370655524165634"></a><a name="p1370655524165634"></a>UIViewType </p>
<p id="p1766976923165634"><a name="p1766976923165634"></a><a name="p1766976923165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row74564458165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299466324165634"><a name="p299466324165634"></a><a name="p299466324165634"></a><a href="graphic.md#ga9013bc4fa8bfc77cf75b898db1a0fbf6">SetFontId</a> (uint8_t fontId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469887749165634"><a name="p469887749165634"></a><a name="p469887749165634"></a>void </p>
<p id="p1325651250165634"><a name="p1325651250165634"></a><a name="p1325651250165634"></a>Sets the dynamic font ID for this digital clock. </p>
</td>
</tr>
<tr id="row1398584820165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987740622165634"><a name="p1987740622165634"></a><a name="p1987740622165634"></a><a href="graphic.md#gaa41d0c6ab53a4451e9e90199dbaa3895">SetFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p476260352165634"><a name="p476260352165634"></a><a name="p476260352165634"></a>void </p>
<p id="p1341236160165634"><a name="p1341236160165634"></a><a name="p1341236160165634"></a>Sets the dynamic font for this digital clock. </p>
</td>
</tr>
<tr id="row896940820165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880568311165634"><a name="p1880568311165634"></a><a name="p1880568311165634"></a><a href="graphic.md#gaabdefd6f104682c755886594e259e810">SetColor</a> (<a href="ohos-color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031373652165634"><a name="p2031373652165634"></a><a name="p2031373652165634"></a>void </p>
<p id="p314169112165634"><a name="p314169112165634"></a><a name="p314169112165634"></a>Sets the font color for this digital clock. </p>
</td>
</tr>
<tr id="row248356518165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257733817165634"><a name="p257733817165634"></a><a name="p257733817165634"></a><a href="graphic.md#ga2ac4d800eb47c4238d160819e165a30a">SetDisplayMode</a> (<a href="graphic.md#gabe3b64b11e5bf5d7b54e1039e40f306b">DisplayMode</a> dm)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216490052165634"><a name="p216490052165634"></a><a name="p216490052165634"></a>void </p>
<p id="p97183503165634"><a name="p97183503165634"></a><a name="p97183503165634"></a>Sets the display mode for this digital clock. </p>
</td>
</tr>
<tr id="row1582154421165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p47756851165634"><a name="p47756851165634"></a><a name="p47756851165634"></a><a href="graphic.md#ga14a5b4ca3e2eda9ff0f6a7ad2bc11f48">GetDisplayMode</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1770095136165634"><a name="p1770095136165634"></a><a name="p1770095136165634"></a><a href="graphic.md#gabe3b64b11e5bf5d7b54e1039e40f306b">DisplayMode</a> </p>
<p id="p1348147904165634"><a name="p1348147904165634"></a><a name="p1348147904165634"></a>Obtains the display mode of this digital clock. </p>
</td>
</tr>
<tr id="row412621083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1434478723165634"><a name="p1434478723165634"></a><a name="p1434478723165634"></a><a href="graphic.md#gaf45e9196d307551e693807cae2f8b4d2">DisplayLeadingZero</a> (bool displayLeadingZero)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13528531165634"><a name="p13528531165634"></a><a name="p13528531165634"></a>void </p>
<p id="p1922985657165634"><a name="p1922985657165634"></a><a name="p1922985657165634"></a>Sets whether to add <strong id="b139482238165634"><a name="b139482238165634"></a><a name="b139482238165634"></a>0</strong> before the hour of this digital clock. </p>
</td>
</tr>
<tr id="row1874597042165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402732308165634"><a name="p1402732308165634"></a><a name="p1402732308165634"></a><a href="graphic.md#ga1565dcdb5ab0403fa477fd74c5920b99">SetOpacity</a> (uint8_t opacity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90185632165634"><a name="p90185632165634"></a><a name="p90185632165634"></a>void </p>
<p id="p983644665165634"><a name="p983644665165634"></a><a name="p983644665165634"></a>Sets the opacity for this digital clock. </p>
</td>
</tr>
<tr id="row838473091165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538138580165634"><a name="p538138580165634"></a><a name="p538138580165634"></a><a href="graphic.md#ga713ec508a94eb05eab0aa5ab1c7f41ca">GetOpacity</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1540683803165634"><a name="p1540683803165634"></a><a name="p1540683803165634"></a>uint8_t </p>
<p id="p1301745544165634"><a name="p1301745544165634"></a><a name="p1301745544165634"></a>Obtains the opacity of this digital clock. </p>
</td>
</tr>
<tr id="row429453335165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p522773173165634"><a name="p522773173165634"></a><a name="p522773173165634"></a><a href="graphic.md#ga386c03c483ef38cb5310563b6ba9bc02">UpdateClock</a> (bool clockInit) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p578351222165634"><a name="p578351222165634"></a><a name="p578351222165634"></a>void </p>
<p id="p1177525814165634"><a name="p1177525814165634"></a><a name="p1177525814165634"></a>Updates this digital clock. </p>
</td>
</tr>
<tr id="row1483884638165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391607678165634"><a name="p1391607678165634"></a><a name="p1391607678165634"></a><a href="graphic.md#ga160a40d9f81c72b606b3c5b05168bacf">UIAbstractClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1190104844165634"><a name="p1190104844165634"></a><a name="p1190104844165634"></a> </p>
<p id="p1204812263165634"><a name="p1204812263165634"></a><a name="p1204812263165634"></a>A default constructor used to create a <strong id="b1853453104165634"><a name="b1853453104165634"></a><a name="b1853453104165634"></a><a href="ohos-uiabstractclock.md">UIAbstractClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row1369903694165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p793807415165634"><a name="p793807415165634"></a><a name="p793807415165634"></a><a href="graphic.md#ga93d3d68e48a79ee7fc4b42a9c0c0ccc1">UIAbstractClock</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p458382158165634"><a name="p458382158165634"></a><a name="p458382158165634"></a> </p>
<p id="p1485169372165634"><a name="p1485169372165634"></a><a name="p1485169372165634"></a>A constructor used to create a <strong id="b1547074271165634"><a name="b1547074271165634"></a><a name="b1547074271165634"></a><a href="ohos-uiabstractclock.md">UIAbstractClock</a></strong> instance with time elements (hour, minute and second). </p>
</td>
</tr>
<tr id="row5355610165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1394320967165634"><a name="p1394320967165634"></a><a name="p1394320967165634"></a><a href="graphic.md#ga0fb0c108b319f02b9d42b34c1d2c8708">~UIAbstractClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890924326165634"><a name="p1890924326165634"></a><a name="p1890924326165634"></a>virtual </p>
<p id="p1308381588165634"><a name="p1308381588165634"></a><a name="p1308381588165634"></a>A destructor used to delete the <strong id="b838318178165634"><a name="b838318178165634"></a><a name="b838318178165634"></a><a href="ohos-uiabstractclock.md">UIAbstractClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row142101224165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1529463570165634"><a name="p1529463570165634"></a><a name="p1529463570165634"></a><a href="graphic.md#ga44a7312163a4192670c00bb8f9916e51">SetTime24Hour</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058811012165634"><a name="p1058811012165634"></a><a name="p1058811012165634"></a>void </p>
<p id="p1997086402165634"><a name="p1997086402165634"></a><a name="p1997086402165634"></a>Sets the time in 24-hour format. </p>
</td>
</tr>
<tr id="row417603488165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987760670165634"><a name="p1987760670165634"></a><a name="p1987760670165634"></a><a href="graphic.md#ga37750dfa0b5a47c8dcb61547dd991a6a">SetTime12Hour</a> (uint8_t hour, uint8_t minute, uint8_t second, bool am)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397988379165634"><a name="p397988379165634"></a><a name="p397988379165634"></a>void </p>
<p id="p614090504165634"><a name="p614090504165634"></a><a name="p614090504165634"></a>Sets the time in 12-hour format. </p>
</td>
</tr>
<tr id="row887932682165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249768782165634"><a name="p249768782165634"></a><a name="p249768782165634"></a><a href="graphic.md#ga8cf863dfcd63410f2f20572a51f2516b">GetCurrentHour</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260281552165634"><a name="p260281552165634"></a><a name="p260281552165634"></a>uint8_t </p>
<p id="p63430453165634"><a name="p63430453165634"></a><a name="p63430453165634"></a>Obtains the current number of hours. </p>
</td>
</tr>
<tr id="row1445227352165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964467458165634"><a name="p964467458165634"></a><a name="p964467458165634"></a><a href="graphic.md#ga5f0eea09577104d9126a07bfbc0b780a">GetCurrentMinute</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p329474484165634"><a name="p329474484165634"></a><a name="p329474484165634"></a>uint8_t </p>
<p id="p1934933756165634"><a name="p1934933756165634"></a><a name="p1934933756165634"></a>Obtains the current number of minutes. </p>
</td>
</tr>
<tr id="row201227647165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192797672165634"><a name="p192797672165634"></a><a name="p192797672165634"></a><a href="graphic.md#ga7bd4d2d4631d9ea373d008ec7a5d18ff">GetCurrentSecond</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761983577165634"><a name="p761983577165634"></a><a name="p761983577165634"></a>uint8_t </p>
<p id="p1836408615165634"><a name="p1836408615165634"></a><a name="p1836408615165634"></a>Obtains the current number of seconds. </p>
</td>
</tr>
<tr id="row2070682967165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1888504290165634"><a name="p1888504290165634"></a><a name="p1888504290165634"></a><a href="graphic.md#gaf4c05e6acf6700d7edb69dc49cd6fef8">IncOneSecond</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152673260165634"><a name="p152673260165634"></a><a name="p152673260165634"></a>void </p>
<p id="p2068410485165634"><a name="p2068410485165634"></a><a name="p2068410485165634"></a>Increases the time by one second. </p>
</td>
</tr>
<tr id="row769018676165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1186266590165634"><a name="p1186266590165634"></a><a name="p1186266590165634"></a><a href="graphic.md#gaafa5df66c896268de27bf335c1b72b92">SetWorkMode</a> (<a href="graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> newMode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570285466165634"><a name="p1570285466165634"></a><a name="p1570285466165634"></a>virtual void </p>
<p id="p1668209415165634"><a name="p1668209415165634"></a><a name="p1668209415165634"></a>Sets the working mode for this clock. </p>
</td>
</tr>
<tr id="row792586707165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1938786918165634"><a name="p1938786918165634"></a><a name="p1938786918165634"></a><a href="graphic.md#gad2d78422d212ef1e93bb4a23e1ee3859">GetWorkMode</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2052498985165634"><a name="p2052498985165634"></a><a name="p2052498985165634"></a>virtual <a href="graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> </p>
<p id="p1116871539165634"><a name="p1116871539165634"></a><a name="p1116871539165634"></a>Obtains the working mode of this clock. </p>
</td>
</tr>
<tr id="row764219657165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1176903799165634"><a name="p1176903799165634"></a><a name="p1176903799165634"></a><a href="graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1462257564165634"><a name="p1462257564165634"></a><a name="p1462257564165634"></a> </p>
<p id="p472080778165634"><a name="p472080778165634"></a><a name="p472080778165634"></a>A default constructor used to create a <strong id="b1441950454165634"><a name="b1441950454165634"></a><a name="b1441950454165634"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row478153822165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1536783377165634"><a name="p1536783377165634"></a><a name="p1536783377165634"></a><a href="graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1419035460165634"><a name="p1419035460165634"></a><a name="p1419035460165634"></a>virtual </p>
<p id="p1440306849165634"><a name="p1440306849165634"></a><a name="p1440306849165634"></a>A destructor used to delete the <strong id="b1490907740165634"><a name="b1490907740165634"></a><a name="b1490907740165634"></a><a href="ohos-uiviewgroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row711648892165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p749490149165634"><a name="p749490149165634"></a><a name="p749490149165634"></a><a href="graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255255868165634"><a name="p1255255868165634"></a><a name="p1255255868165634"></a>UIViewType </p>
<p id="p1551086520165634"><a name="p1551086520165634"></a><a name="p1551086520165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1156868292165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559434868165634"><a name="p559434868165634"></a><a name="p559434868165634"></a><a href="graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1226487025165634"><a name="p1226487025165634"></a><a name="p1226487025165634"></a>virtual void </p>
<p id="p972250134165634"><a name="p972250134165634"></a><a name="p972250134165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1362549840165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p750832690165634"><a name="p750832690165634"></a><a name="p750832690165634"></a><a href="graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="ohos-uiview.md">UIView</a> *prevView, <a href="ohos-uiview.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1431308189165634"><a name="p1431308189165634"></a><a name="p1431308189165634"></a>virtual void </p>
<p id="p2103601161165634"><a name="p2103601161165634"></a><a name="p2103601161165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row120922684165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50805183165634"><a name="p50805183165634"></a><a name="p50805183165634"></a><a href="graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="ohos-uiview.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1470087705165634"><a name="p1470087705165634"></a><a name="p1470087705165634"></a>virtual void </p>
<p id="p299138383165634"><a name="p299138383165634"></a><a name="p299138383165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1134261130165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909296742165634"><a name="p1909296742165634"></a><a name="p1909296742165634"></a><a href="graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339127719165634"><a name="p339127719165634"></a><a name="p339127719165634"></a>virtual void </p>
<p id="p1944767718165634"><a name="p1944767718165634"></a><a name="p1944767718165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row2057649932165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787212422165634"><a name="p1787212422165634"></a><a name="p1787212422165634"></a><a href="graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1548966928165634"><a name="p1548966928165634"></a><a name="p1548966928165634"></a>virtual void </p>
<p id="p1618313768165634"><a name="p1618313768165634"></a><a name="p1618313768165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row587489055165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p899447333165634"><a name="p899447333165634"></a><a name="p899447333165634"></a><a href="graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428586243165634"><a name="p428586243165634"></a><a name="p428586243165634"></a>virtual void </p>
<p id="p1666853180165634"><a name="p1666853180165634"></a><a name="p1666853180165634"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1894540662165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786130361165634"><a name="p1786130361165634"></a><a name="p1786130361165634"></a><a href="graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276124363165634"><a name="p1276124363165634"></a><a name="p1276124363165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p224936458165634"><a name="p224936458165634"></a><a name="p224936458165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row112698088165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p524404119165634"><a name="p524404119165634"></a><a name="p524404119165634"></a><a href="graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696937348165634"><a name="p696937348165634"></a><a name="p696937348165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p912667540165634"><a name="p912667540165634"></a><a name="p912667540165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row635866712165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p997599111165634"><a name="p997599111165634"></a><a name="p997599111165634"></a><a href="graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501988152165634"><a name="p501988152165634"></a><a name="p501988152165634"></a>void </p>
<p id="p1465503788165634"><a name="p1465503788165634"></a><a name="p1465503788165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1357371042165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p846056476165634"><a name="p846056476165634"></a><a name="p846056476165634"></a><a href="graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637449064165634"><a name="p637449064165634"></a><a name="p637449064165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p2099675677165634"><a name="p2099675677165634"></a><a name="p2099675677165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row458641244165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736846987165634"><a name="p1736846987165634"></a><a name="p1736846987165634"></a><a href="graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1557752372165634"><a name="p1557752372165634"></a><a name="p1557752372165634"></a>void </p>
<p id="p283761906165634"><a name="p283761906165634"></a><a name="p283761906165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1948367860165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1346890491165634"><a name="p1346890491165634"></a><a name="p1346890491165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p380076447165634"><a name="p380076447165634"></a><a name="p380076447165634"></a> </p>
<p id="p1674787767165634"><a name="p1674787767165634"></a><a name="p1674787767165634"></a>A default constructor used to create an <strong id="b453784727165634"><a name="b453784727165634"></a><a name="b453784727165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row69624175165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1514097280165634"><a name="p1514097280165634"></a><a name="p1514097280165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p709068916165634"><a name="p709068916165634"></a><a name="p709068916165634"></a> </p>
<p id="p624855224165634"><a name="p624855224165634"></a><a name="p624855224165634"></a>A constructor used to create an <strong id="b302986989165634"><a name="b302986989165634"></a><a name="b302986989165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1816887791165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824791302165634"><a name="p1824791302165634"></a><a name="p1824791302165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p817675598165634"><a name="p817675598165634"></a><a name="p817675598165634"></a>virtual </p>
<p id="p362322370165634"><a name="p362322370165634"></a><a name="p362322370165634"></a>A destructor used to delete the <strong id="b1015202666165634"><a name="b1015202666165634"></a><a name="b1015202666165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1161536363165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p712296375165634"><a name="p712296375165634"></a><a name="p712296375165634"></a><a href="graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1888403286165634"><a name="p1888403286165634"></a><a name="p1888403286165634"></a>virtual bool </p>
<p id="p954738531165634"><a name="p954738531165634"></a><a name="p954738531165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1460444814165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p598115044165634"><a name="p598115044165634"></a><a name="p598115044165634"></a><a href="graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645129477165634"><a name="p645129477165634"></a><a name="p645129477165634"></a>virtual void </p>
<p id="p512589219165634"><a name="p512589219165634"></a><a name="p512589219165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1511196493165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401754443165634"><a name="p1401754443165634"></a><a name="p1401754443165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117403686165634"><a name="p1117403686165634"></a><a name="p1117403686165634"></a>virtual void </p>
<p id="p1667312949165634"><a name="p1667312949165634"></a><a name="p1667312949165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row475827879165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519214090165634"><a name="p1519214090165634"></a><a name="p1519214090165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p467373144165634"><a name="p467373144165634"></a><a name="p467373144165634"></a>virtual void </p>
<p id="p805898458165634"><a name="p805898458165634"></a><a name="p805898458165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row500745641165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p194621744165634"><a name="p194621744165634"></a><a name="p194621744165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115269055165634"><a name="p1115269055165634"></a><a name="p1115269055165634"></a>void </p>
<p id="p859563351165634"><a name="p859563351165634"></a><a name="p859563351165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row794940681165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184554310165634"><a name="p1184554310165634"></a><a name="p1184554310165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p989881534165634"><a name="p989881534165634"></a><a name="p989881534165634"></a>void </p>
<p id="p960648877165634"><a name="p960648877165634"></a><a name="p960648877165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row2051388360165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1634098382165634"><a name="p1634098382165634"></a><a name="p1634098382165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788817501165634"><a name="p788817501165634"></a><a name="p788817501165634"></a>virtual bool </p>
<p id="p825580731165634"><a name="p825580731165634"></a><a name="p825580731165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1805548188165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1491539953165634"><a name="p1491539953165634"></a><a name="p1491539953165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1017118870165634"><a name="p1017118870165634"></a><a name="p1017118870165634"></a>virtual bool </p>
<p id="p1441032266165634"><a name="p1441032266165634"></a><a name="p1441032266165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row95682764165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852436051165634"><a name="p1852436051165634"></a><a name="p1852436051165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1294888781165634"><a name="p1294888781165634"></a><a name="p1294888781165634"></a>virtual bool </p>
<p id="p56903779165634"><a name="p56903779165634"></a><a name="p56903779165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1140314802165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p207753574165634"><a name="p207753574165634"></a><a name="p207753574165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1871091176165634"><a name="p1871091176165634"></a><a name="p1871091176165634"></a>virtual bool </p>
<p id="p851129651165634"><a name="p851129651165634"></a><a name="p851129651165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row2091462244165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p88170163165634"><a name="p88170163165634"></a><a name="p88170163165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556638580165634"><a name="p1556638580165634"></a><a name="p1556638580165634"></a>virtual void </p>
<p id="p577962603165634"><a name="p577962603165634"></a><a name="p577962603165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row587791772165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p754098621165634"><a name="p754098621165634"></a><a name="p754098621165634"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922627666165634"><a name="p922627666165634"></a><a name="p922627666165634"></a>virtual void </p>
<p id="p146107661165634"><a name="p146107661165634"></a><a name="p146107661165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1894855634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956839050165634"><a name="p1956839050165634"></a><a name="p1956839050165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035701092165634"><a name="p1035701092165634"></a><a name="p1035701092165634"></a>virtual void </p>
<p id="p927376160165634"><a name="p927376160165634"></a><a name="p927376160165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row550917416165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871356555165634"><a name="p871356555165634"></a><a name="p871356555165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157138556165634"><a name="p157138556165634"></a><a name="p157138556165634"></a>virtual void </p>
<p id="p1491639968165634"><a name="p1491639968165634"></a><a name="p1491639968165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1048973257165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677893709165634"><a name="p1677893709165634"></a><a name="p1677893709165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p54795636165634"><a name="p54795636165634"></a><a name="p54795636165634"></a>void </p>
<p id="p666098842165634"><a name="p666098842165634"></a><a name="p666098842165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row746351306165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087668575165634"><a name="p2087668575165634"></a><a name="p2087668575165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1738531989165634"><a name="p1738531989165634"></a><a name="p1738531989165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p142072114165634"><a name="p142072114165634"></a><a name="p142072114165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row258242265165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192296623165634"><a name="p192296623165634"></a><a name="p192296623165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1122242608165634"><a name="p1122242608165634"></a><a name="p1122242608165634"></a>void </p>
<p id="p441764169165634"><a name="p441764169165634"></a><a name="p441764169165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row339265476165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1974302162165634"><a name="p1974302162165634"></a><a name="p1974302162165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048338568165634"><a name="p1048338568165634"></a><a name="p1048338568165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1096319232165634"><a name="p1096319232165634"></a><a name="p1096319232165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row919305552165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1853579705165634"><a name="p1853579705165634"></a><a name="p1853579705165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717705333165634"><a name="p717705333165634"></a><a name="p717705333165634"></a>void </p>
<p id="p711743276165634"><a name="p711743276165634"></a><a name="p711743276165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2061478901165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097558670165634"><a name="p2097558670165634"></a><a name="p2097558670165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1429756556165634"><a name="p1429756556165634"></a><a name="p1429756556165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1887634954165634"><a name="p1887634954165634"></a><a name="p1887634954165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row971703279165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374561811165634"><a name="p1374561811165634"></a><a name="p1374561811165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p459830056165634"><a name="p459830056165634"></a><a name="p459830056165634"></a>void </p>
<p id="p1303488928165634"><a name="p1303488928165634"></a><a name="p1303488928165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1676509050165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987326289165634"><a name="p1987326289165634"></a><a name="p1987326289165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1556829785165634"><a name="p1556829785165634"></a><a name="p1556829785165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p403305336165634"><a name="p403305336165634"></a><a name="p403305336165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1637051483165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2013404718165634"><a name="p2013404718165634"></a><a name="p2013404718165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1278157870165634"><a name="p1278157870165634"></a><a name="p1278157870165634"></a>void </p>
<p id="p979600538165634"><a name="p979600538165634"></a><a name="p979600538165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1714302192165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p850930497165634"><a name="p850930497165634"></a><a name="p850930497165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777525210165634"><a name="p777525210165634"></a><a name="p777525210165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p9963741165634"><a name="p9963741165634"></a><a name="p9963741165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row2130122425165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362506057165634"><a name="p1362506057165634"></a><a name="p1362506057165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951961261165634"><a name="p951961261165634"></a><a name="p951961261165634"></a>void </p>
<p id="p268684051165634"><a name="p268684051165634"></a><a name="p268684051165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1953595441165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p549347852165634"><a name="p549347852165634"></a><a name="p549347852165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p805428047165634"><a name="p805428047165634"></a><a name="p805428047165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p452152880165634"><a name="p452152880165634"></a><a name="p452152880165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1715363227165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1932346715165634"><a name="p1932346715165634"></a><a name="p1932346715165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762740934165634"><a name="p1762740934165634"></a><a name="p1762740934165634"></a>virtual void </p>
<p id="p916399644165634"><a name="p916399644165634"></a><a name="p916399644165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1196024983165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871346079165634"><a name="p871346079165634"></a><a name="p871346079165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1787664741165634"><a name="p1787664741165634"></a><a name="p1787664741165634"></a>bool </p>
<p id="p1910603298165634"><a name="p1910603298165634"></a><a name="p1910603298165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row981841767165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p842101584165634"><a name="p842101584165634"></a><a name="p842101584165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1645859105165634"><a name="p1645859105165634"></a><a name="p1645859105165634"></a>void </p>
<p id="p682810820165634"><a name="p682810820165634"></a><a name="p682810820165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1202781953165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p631876705165634"><a name="p631876705165634"></a><a name="p631876705165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465465514165634"><a name="p1465465514165634"></a><a name="p1465465514165634"></a>bool </p>
<p id="p1503669831165634"><a name="p1503669831165634"></a><a name="p1503669831165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row543689405165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468867601165634"><a name="p1468867601165634"></a><a name="p1468867601165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975820480165634"><a name="p1975820480165634"></a><a name="p1975820480165634"></a>void </p>
<p id="p312310622165634"><a name="p312310622165634"></a><a name="p312310622165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row686091224165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175710142165634"><a name="p175710142165634"></a><a name="p175710142165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p926661673165634"><a name="p926661673165634"></a><a name="p926661673165634"></a>bool </p>
<p id="p1838958612165634"><a name="p1838958612165634"></a><a name="p1838958612165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row2120327109165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465950730165634"><a name="p1465950730165634"></a><a name="p1465950730165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1107907856165634"><a name="p1107907856165634"></a><a name="p1107907856165634"></a>void </p>
<p id="p1151600226165634"><a name="p1151600226165634"></a><a name="p1151600226165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row2134533296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1746950620165634"><a name="p1746950620165634"></a><a name="p1746950620165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p341032145165634"><a name="p341032145165634"></a><a name="p341032145165634"></a>bool </p>
<p id="p1077647564165634"><a name="p1077647564165634"></a><a name="p1077647564165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row565740409165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p248361495165634"><a name="p248361495165634"></a><a name="p248361495165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p436248007165634"><a name="p436248007165634"></a><a name="p436248007165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p718663686165634"><a name="p718663686165634"></a><a name="p718663686165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1241499650165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1434233267165634"><a name="p1434233267165634"></a><a name="p1434233267165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485621378165634"><a name="p1485621378165634"></a><a name="p1485621378165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1794457167165634"><a name="p1794457167165634"></a><a name="p1794457167165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row109317965165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137030896165634"><a name="p137030896165634"></a><a name="p137030896165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590118561165634"><a name="p590118561165634"></a><a name="p590118561165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1846570721165634"><a name="p1846570721165634"></a><a name="p1846570721165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row244119425165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55060500165634"><a name="p55060500165634"></a><a name="p55060500165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2076798298165634"><a name="p2076798298165634"></a><a name="p2076798298165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1367461900165634"><a name="p1367461900165634"></a><a name="p1367461900165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1404636033165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2064919040165634"><a name="p2064919040165634"></a><a name="p2064919040165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p92408846165634"><a name="p92408846165634"></a><a name="p92408846165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1028243771165634"><a name="p1028243771165634"></a><a name="p1028243771165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1253354311165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116129801165634"><a name="p116129801165634"></a><a name="p116129801165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1406619017165634"><a name="p1406619017165634"></a><a name="p1406619017165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1320114621165634"><a name="p1320114621165634"></a><a name="p1320114621165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row326228966165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1871471026165634"><a name="p1871471026165634"></a><a name="p1871471026165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1790223429165634"><a name="p1790223429165634"></a><a name="p1790223429165634"></a>void </p>
<p id="p807544888165634"><a name="p807544888165634"></a><a name="p807544888165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1438938890165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p287425057165634"><a name="p287425057165634"></a><a name="p287425057165634"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151407015165634"><a name="p151407015165634"></a><a name="p151407015165634"></a>virtual void </p>
<p id="p308539301165634"><a name="p308539301165634"></a><a name="p308539301165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1550426270165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031894568165634"><a name="p1031894568165634"></a><a name="p1031894568165634"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p910093301165634"><a name="p910093301165634"></a><a name="p910093301165634"></a>virtual int16_t </p>
<p id="p2122434355165634"><a name="p2122434355165634"></a><a name="p2122434355165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row591891453165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p490175323165634"><a name="p490175323165634"></a><a name="p490175323165634"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285394948165634"><a name="p285394948165634"></a><a name="p285394948165634"></a>virtual void </p>
<p id="p288309198165634"><a name="p288309198165634"></a><a name="p288309198165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row905773783165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p923498101165634"><a name="p923498101165634"></a><a name="p923498101165634"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121081054165634"><a name="p1121081054165634"></a><a name="p1121081054165634"></a>virtual int16_t </p>
<p id="p473704131165634"><a name="p473704131165634"></a><a name="p473704131165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1231704398165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1225594381165634"><a name="p1225594381165634"></a><a name="p1225594381165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708852738165634"><a name="p708852738165634"></a><a name="p708852738165634"></a>virtual void </p>
<p id="p728713877165634"><a name="p728713877165634"></a><a name="p728713877165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1390778683165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437149302165634"><a name="p437149302165634"></a><a name="p437149302165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p950754081165634"><a name="p950754081165634"></a><a name="p950754081165634"></a>virtual void </p>
<p id="p278563254165634"><a name="p278563254165634"></a><a name="p278563254165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row630979722165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655762510165634"><a name="p1655762510165634"></a><a name="p1655762510165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1943415063165634"><a name="p1943415063165634"></a><a name="p1943415063165634"></a>int16_t </p>
<p id="p608209102165634"><a name="p608209102165634"></a><a name="p608209102165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row333178825165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242596146165634"><a name="p242596146165634"></a><a name="p242596146165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653182473165634"><a name="p653182473165634"></a><a name="p653182473165634"></a>virtual void </p>
<p id="p489881892165634"><a name="p489881892165634"></a><a name="p489881892165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row850041450165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p767749308165634"><a name="p767749308165634"></a><a name="p767749308165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550406042165634"><a name="p550406042165634"></a><a name="p550406042165634"></a>int16_t </p>
<p id="p503541308165634"><a name="p503541308165634"></a><a name="p503541308165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1790130210165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1455748188165634"><a name="p1455748188165634"></a><a name="p1455748188165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1533953370165634"><a name="p1533953370165634"></a><a name="p1533953370165634"></a>virtual void </p>
<p id="p1941373500165634"><a name="p1941373500165634"></a><a name="p1941373500165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row400188315165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137124633165634"><a name="p137124633165634"></a><a name="p137124633165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1109840133165634"><a name="p1109840133165634"></a><a name="p1109840133165634"></a>virtual void </p>
<p id="p834115176165634"><a name="p834115176165634"></a><a name="p834115176165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1414336396165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p645247140165634"><a name="p645247140165634"></a><a name="p645247140165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603711935165634"><a name="p603711935165634"></a><a name="p603711935165634"></a>bool </p>
<p id="p386005262165634"><a name="p386005262165634"></a><a name="p386005262165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row962259877165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p625040005165634"><a name="p625040005165634"></a><a name="p625040005165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742115873165634"><a name="p1742115873165634"></a><a name="p1742115873165634"></a>void </p>
<p id="p1503725545165634"><a name="p1503725545165634"></a><a name="p1503725545165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row356571801165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1021250569165634"><a name="p1021250569165634"></a><a name="p1021250569165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882019977165634"><a name="p1882019977165634"></a><a name="p1882019977165634"></a>void </p>
<p id="p315837283165634"><a name="p315837283165634"></a><a name="p315837283165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row262935134165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p528024825165634"><a name="p528024825165634"></a><a name="p528024825165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502603339165634"><a name="p1502603339165634"></a><a name="p1502603339165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p1159884508165634"><a name="p1159884508165634"></a><a name="p1159884508165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row943048660165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p145452983165634"><a name="p145452983165634"></a><a name="p145452983165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2126149175165634"><a name="p2126149175165634"></a><a name="p2126149175165634"></a>void </p>
<p id="p844525803165634"><a name="p844525803165634"></a><a name="p844525803165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row874846120165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p7695376165634"><a name="p7695376165634"></a><a name="p7695376165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1336325155165634"><a name="p1336325155165634"></a><a name="p1336325155165634"></a>const char * </p>
<p id="p1529919386165634"><a name="p1529919386165634"></a><a name="p1529919386165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row29834153165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948183966165634"><a name="p1948183966165634"></a><a name="p1948183966165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p160259596165634"><a name="p160259596165634"></a><a name="p160259596165634"></a>void </p>
<p id="p437108519165634"><a name="p437108519165634"></a><a name="p437108519165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row501354357165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992569673165634"><a name="p992569673165634"></a><a name="p992569673165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1305256240165634"><a name="p1305256240165634"></a><a name="p1305256240165634"></a>int16_t </p>
<p id="p1068092915165634"><a name="p1068092915165634"></a><a name="p1068092915165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row682077871165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118140993165634"><a name="p118140993165634"></a><a name="p118140993165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1725093275165634"><a name="p1725093275165634"></a><a name="p1725093275165634"></a>virtual void </p>
<p id="p643142468165634"><a name="p643142468165634"></a><a name="p643142468165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1392667921165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p345709256165634"><a name="p345709256165634"></a><a name="p345709256165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2058575491165634"><a name="p2058575491165634"></a><a name="p2058575491165634"></a>void </p>
<p id="p1989279187165634"><a name="p1989279187165634"></a><a name="p1989279187165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row109446345165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248998159165634"><a name="p1248998159165634"></a><a name="p1248998159165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667619881165634"><a name="p1667619881165634"></a><a name="p1667619881165634"></a>void </p>
<p id="p835932277165634"><a name="p835932277165634"></a><a name="p835932277165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1094677978165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770070070165634"><a name="p1770070070165634"></a><a name="p1770070070165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p848167692165634"><a name="p848167692165634"></a><a name="p848167692165634"></a>void </p>
<p id="p2116801439165634"><a name="p2116801439165634"></a><a name="p2116801439165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1540962843165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284261142165634"><a name="p284261142165634"></a><a name="p284261142165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1174164996165634"><a name="p1174164996165634"></a><a name="p1174164996165634"></a>void </p>
<p id="p567340750165634"><a name="p567340750165634"></a><a name="p567340750165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row267618602165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p442610247165634"><a name="p442610247165634"></a><a name="p442610247165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p127515004165634"><a name="p127515004165634"></a><a name="p127515004165634"></a>void </p>
<p id="p1507334421165634"><a name="p1507334421165634"></a><a name="p1507334421165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1696428033165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p505547414165634"><a name="p505547414165634"></a><a name="p505547414165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2010212456165634"><a name="p2010212456165634"></a><a name="p2010212456165634"></a>void </p>
<p id="p1383952766165634"><a name="p1383952766165634"></a><a name="p1383952766165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1699945171165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p414562811165634"><a name="p414562811165634"></a><a name="p414562811165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927323965165634"><a name="p927323965165634"></a><a name="p927323965165634"></a>void </p>
<p id="p634857463165634"><a name="p634857463165634"></a><a name="p634857463165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row985973683165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p66314541165634"><a name="p66314541165634"></a><a name="p66314541165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504525530165634"><a name="p1504525530165634"></a><a name="p1504525530165634"></a>void </p>
<p id="p919043290165634"><a name="p919043290165634"></a><a name="p919043290165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row604490530165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1749040640165634"><a name="p1749040640165634"></a><a name="p1749040640165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260119101165634"><a name="p260119101165634"></a><a name="p260119101165634"></a>void </p>
<p id="p405591660165634"><a name="p405591660165634"></a><a name="p405591660165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1881497803165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p265196627165634"><a name="p265196627165634"></a><a name="p265196627165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2081010354165634"><a name="p2081010354165634"></a><a name="p2081010354165634"></a>void </p>
<p id="p66252060165634"><a name="p66252060165634"></a><a name="p66252060165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row687382501165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784944472165634"><a name="p784944472165634"></a><a name="p784944472165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059879347165634"><a name="p2059879347165634"></a><a name="p2059879347165634"></a>void </p>
<p id="p554910478165634"><a name="p554910478165634"></a><a name="p554910478165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1056926359165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1483856234165634"><a name="p1483856234165634"></a><a name="p1483856234165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2023295198165634"><a name="p2023295198165634"></a><a name="p2023295198165634"></a>void </p>
<p id="p900826765165634"><a name="p900826765165634"></a><a name="p900826765165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1127648892165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987272956165634"><a name="p1987272956165634"></a><a name="p1987272956165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089004222165634"><a name="p1089004222165634"></a><a name="p1089004222165634"></a>void </p>
<p id="p673582384165634"><a name="p673582384165634"></a><a name="p673582384165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row650320446165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1953319220165634"><a name="p1953319220165634"></a><a name="p1953319220165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p634750177165634"><a name="p634750177165634"></a><a name="p634750177165634"></a>void </p>
<p id="p235626103165634"><a name="p235626103165634"></a><a name="p235626103165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row448911503165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117290037165634"><a name="p1117290037165634"></a><a name="p1117290037165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667927279165634"><a name="p667927279165634"></a><a name="p667927279165634"></a>void </p>
<p id="p71493674165634"><a name="p71493674165634"></a><a name="p71493674165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row553236388165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2118684073165634"><a name="p2118684073165634"></a><a name="p2118684073165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197160026165634"><a name="p1197160026165634"></a><a name="p1197160026165634"></a>void </p>
<p id="p972391347165634"><a name="p972391347165634"></a><a name="p972391347165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row256028469165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p390125997165634"><a name="p390125997165634"></a><a name="p390125997165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24776960165634"><a name="p24776960165634"></a><a name="p24776960165634"></a>virtual void </p>
<p id="p1210710928165634"><a name="p1210710928165634"></a><a name="p1210710928165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row2036863588165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1229759660165634"><a name="p1229759660165634"></a><a name="p1229759660165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875644676165634"><a name="p875644676165634"></a><a name="p875644676165634"></a>virtual int64_t </p>
<p id="p1668664496165634"><a name="p1668664496165634"></a><a name="p1668664496165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row82853440165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929406981165634"><a name="p1929406981165634"></a><a name="p1929406981165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175391505165634"><a name="p1175391505165634"></a><a name="p1175391505165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p834266582165634"><a name="p834266582165634"></a><a name="p834266582165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row320567217165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1080144249165634"><a name="p1080144249165634"></a><a name="p1080144249165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p908469148165634"><a name="p908469148165634"></a><a name="p908469148165634"></a>void * </p>
<p id="p1801420262165634"><a name="p1801420262165634"></a><a name="p1801420262165634"></a>Overrides the <strong id="b620545382165634"><a name="b620545382165634"></a><a name="b620545382165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row424563485165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1090343816165634"><a name="p1090343816165634"></a><a name="p1090343816165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377061384165634"><a name="p1377061384165634"></a><a name="p1377061384165634"></a>void </p>
<p id="p581599124165634"><a name="p581599124165634"></a><a name="p581599124165634"></a>Overrides the <strong id="b205245922165634"><a name="b205245922165634"></a><a name="b205245922165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table969780066165634"></a>
<table><thead align="left"><tr id="row1853816923165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p116144311165634"><a name="p116144311165634"></a><a name="p116144311165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1544024906165634"><a name="p1544024906165634"></a><a name="p1544024906165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1881866243165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1650642385165634"><a name="p1650642385165634"></a><a name="p1650642385165634"></a><a href="graphic.md#ga7f433b8551722451f880e7fa05731a2f">ONE_MINUTE_IN_SECOND</a> = 60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1690203065165634"><a name="p1690203065165634"></a><a name="p1690203065165634"></a>Represents 60 seconds per minute. </p>
</td>
</tr>
<tr id="row449456169165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777199387165634"><a name="p1777199387165634"></a><a name="p1777199387165634"></a><a href="graphic.md#ga5434b911b6f7e0637ac0626c9dd0f513">ONE_HOUR_IN_MINUTE</a> = 60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1042345050165634"><a name="p1042345050165634"></a><a name="p1042345050165634"></a>Represents 60 minutes per hour. </p>
</td>
</tr>
<tr id="row1569681807165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52052427165634"><a name="p52052427165634"></a><a name="p52052427165634"></a><a href="graphic.md#gae7742f1e715885ecc4f5b67d57530319">ONE_DAY_IN_HOUR</a> = 24</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1941639241165634"><a name="p1941639241165634"></a><a name="p1941639241165634"></a>Represents 24 hours per day. </p>
</td>
</tr>
<tr id="row1746763856165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542752877165634"><a name="p542752877165634"></a><a name="p542752877165634"></a><a href="graphic.md#gae40a5ae3834b626e2976fab83f166171">HALF_DAY_IN_HOUR</a> = 12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55799936165634"><a name="p55799936165634"></a><a name="p55799936165634"></a>Represents 12 hours every half day. </p>
</td>
</tr>
<tr id="row1066985478165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135517968165634"><a name="p1135517968165634"></a><a name="p1135517968165634"></a><a href="graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p377646500165634"><a name="p377646500165634"></a><a name="p377646500165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row914514944165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1460343991165634"><a name="p1460343991165634"></a><a name="p1460343991165634"></a><a href="graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1750284233165634"><a name="p1750284233165634"></a><a name="p1750284233165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1182399070165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p243555279165634"><a name="p243555279165634"></a><a name="p243555279165634"></a><a href="graphic.md#gaabfbbb277dabf5477c628336a429f8ad">currentHour_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2054514702165634"><a name="p2054514702165634"></a><a name="p2054514702165634"></a>Represents the current number of hours. </p>
</td>
</tr>
<tr id="row1722221550165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2044196483165634"><a name="p2044196483165634"></a><a name="p2044196483165634"></a><a href="graphic.md#ga34c3518c0dc9f35fc77b240b6f8d0dcb">currentMinute_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587076592165634"><a name="p587076592165634"></a><a name="p587076592165634"></a>Represents the current number of minutes. </p>
</td>
</tr>
<tr id="row1252049497165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p551603840165634"><a name="p551603840165634"></a><a name="p551603840165634"></a><a href="graphic.md#ga5b2749cdc5e52551731923d8268b8d5d">currentSecond_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1235919664165634"><a name="p1235919664165634"></a><a name="p1235919664165634"></a>Represents the current number of seconds. </p>
</td>
</tr>
<tr id="row1885844585165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155305849165634"><a name="p1155305849165634"></a><a name="p1155305849165634"></a><a href="graphic.md#gab08c7c490a5b42fcdee04d45b5521d1c">mode_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641257302165634"><a name="p1641257302165634"></a><a name="p1641257302165634"></a>Represents the current working mode of this clock. </p>
</td>
</tr>
<tr id="row1700187442165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097782839165634"><a name="p2097782839165634"></a><a name="p2097782839165634"></a><a href="graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1721319467165634"><a name="p1721319467165634"></a><a name="p1721319467165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1455393533165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648064193165634"><a name="p648064193165634"></a><a name="p648064193165634"></a><a href="graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2113583701165634"><a name="p2113583701165634"></a><a name="p2113583701165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1133348535165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269687132165634"><a name="p1269687132165634"></a><a name="p1269687132165634"></a><a href="graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p713955109165634"><a name="p713955109165634"></a><a name="p713955109165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row957503345165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352149165634"><a name="p1352149165634"></a><a name="p1352149165634"></a><a href="graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1842709564165634"><a name="p1842709564165634"></a><a name="p1842709564165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1437516580165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p144325495165634"><a name="p144325495165634"></a><a name="p144325495165634"></a><a href="graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067735417165634"><a name="p2067735417165634"></a><a name="p2067735417165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row2059003914165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1695252702165634"><a name="p1695252702165634"></a><a name="p1695252702165634"></a><a href="graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1161612599165634"><a name="p1161612599165634"></a><a name="p1161612599165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

