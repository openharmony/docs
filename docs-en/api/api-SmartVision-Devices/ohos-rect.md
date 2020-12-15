# OHOS::Rect<a name="EN-US_TOPIC_0000001055518102"></a>

-   [Overview](#section1699044475165633)
-   [Summary](#section1910666326165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1699044475165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines a rectangle, including the position data of the four boundaries of the rectangle, and provides functions for rectangle inclusion, intersection, and aggregation. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1910666326165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table99264593165633"></a>
<table><thead align="left"><tr id="row1051355386165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1610686742165633"><a name="p1610686742165633"></a><a name="p1610686742165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p438284809165633"><a name="p438284809165633"></a><a name="p438284809165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row476869884165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1908403566165633"><a name="p1908403566165633"></a><a name="p1908403566165633"></a><a href="graphic.md#ga7d3779a5cf121ba98026ddbf36705178">Rect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p789420976165633"><a name="p789420976165633"></a><a name="p789420976165633"></a> </p>
<p id="p674664956165633"><a name="p674664956165633"></a><a name="p674664956165633"></a>A constructor used to create a <strong id="b1952030964165633"><a name="b1952030964165633"></a><a name="b1952030964165633"></a><a href="ohos-rect.md">Rect</a></strong> instance. </p>
</td>
</tr>
<tr id="row23271216165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871396480165633"><a name="p871396480165633"></a><a name="p871396480165633"></a><a href="graphic.md#ga3729aa7a7f052d182bd20707097f9db9">~Rect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1713589539165633"><a name="p1713589539165633"></a><a name="p1713589539165633"></a> </p>
<p id="p222056807165633"><a name="p222056807165633"></a><a name="p222056807165633"></a>A destructor used to delete the <strong id="b1717247570165633"><a name="b1717247570165633"></a><a name="b1717247570165633"></a><a href="ohos-rect.md">Rect</a></strong> instance. </p>
</td>
</tr>
<tr id="row1929154201165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1538031177165633"><a name="p1538031177165633"></a><a name="p1538031177165633"></a><a href="graphic.md#gab37a12fb10478edcb5389fa0b347c46f">Rect</a> (int16_t left, int16_t top, int16_t right, int16_t bottom)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1440619520165633"><a name="p1440619520165633"></a><a name="p1440619520165633"></a> </p>
<p id="p1970332665165633"><a name="p1970332665165633"></a><a name="p1970332665165633"></a>A constructor used to create a <strong id="b1456791385165633"><a name="b1456791385165633"></a><a name="b1456791385165633"></a><a href="ohos-rect.md">Rect</a></strong> instance based on the coordinates of the four boundaries. </p>
</td>
</tr>
<tr id="row753159826165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879060610165633"><a name="p879060610165633"></a><a name="p879060610165633"></a><a href="graphic.md#ga766eee89dbd7d4969fb88485893ea662">Rect</a> (const <a href="ohos-rect.md">Rect</a> &amp;other)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2113060914165633"><a name="p2113060914165633"></a><a name="p2113060914165633"></a> </p>
<p id="p1001031052165633"><a name="p1001031052165633"></a><a name="p1001031052165633"></a>A constructor used to create a <strong id="b1167575977165633"><a name="b1167575977165633"></a><a name="b1167575977165633"></a><a href="ohos-rect.md">Rect</a></strong> instance by copying another rectangle. </p>
</td>
</tr>
<tr id="row1455906347165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1921430906165633"><a name="p1921430906165633"></a><a name="p1921430906165633"></a><a href="graphic.md#gabcc74bf916f06152b4a69e1a36116e3f">Rect</a> (const <a href="ohos-rect.md">Rect</a> &amp;&amp;other)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p472327793165633"><a name="p472327793165633"></a><a name="p472327793165633"></a> </p>
<p id="p1764818920165633"><a name="p1764818920165633"></a><a name="p1764818920165633"></a>A constructor used to create a <strong id="b676258946165633"><a name="b676258946165633"></a><a name="b676258946165633"></a><a href="ohos-rect.md">Rect</a></strong> instance by copying another rectangle. </p>
</td>
</tr>
<tr id="row630040240165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1084770396165633"><a name="p1084770396165633"></a><a name="p1084770396165633"></a><a href="graphic.md#ga4423fe83ed9271d1186711dff65796cb">SetRect</a> (int16_t left, int16_t top, int16_t right, int16_t bottom)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794954405165633"><a name="p794954405165633"></a><a name="p794954405165633"></a>void </p>
<p id="p1480413816165633"><a name="p1480413816165633"></a><a name="p1480413816165633"></a>Sets the coordinates of the four boundaries of a rectangle. </p>
</td>
</tr>
<tr id="row1552101657165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p133826173165633"><a name="p133826173165633"></a><a name="p133826173165633"></a><a href="graphic.md#ga2f8315ea6e574aec99210950feef1b55">GetWidth</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1926992260165633"><a name="p1926992260165633"></a><a name="p1926992260165633"></a>int16_t </p>
<p id="p1772469741165633"><a name="p1772469741165633"></a><a name="p1772469741165633"></a>Obtains the rectangle width. </p>
</td>
</tr>
<tr id="row285763737165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p93742278165633"><a name="p93742278165633"></a><a name="p93742278165633"></a><a href="graphic.md#ga9a1b7ee8eee0d5fa96739fd0a0bac638">GetHeight</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283757264165633"><a name="p283757264165633"></a><a name="p283757264165633"></a>int16_t </p>
<p id="p375519639165633"><a name="p375519639165633"></a><a name="p375519639165633"></a>Obtains the rectangle height. </p>
</td>
</tr>
<tr id="row785019352165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p390356427165633"><a name="p390356427165633"></a><a name="p390356427165633"></a><a href="graphic.md#gad0410528e93dcf552129e207dfe37aba">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330285308165633"><a name="p1330285308165633"></a><a name="p1330285308165633"></a>int16_t </p>
<p id="p711418967165633"><a name="p711418967165633"></a><a name="p711418967165633"></a>Obtains the left boundary coordinate of the rectangle. </p>
</td>
</tr>
<tr id="row431178466165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1257122637165633"><a name="p1257122637165633"></a><a name="p1257122637165633"></a><a href="graphic.md#gaa3b94d5228cabba6341039e8f28fda74">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2049210760165633"><a name="p2049210760165633"></a><a name="p2049210760165633"></a>int16_t </p>
<p id="p1053783769165633"><a name="p1053783769165633"></a><a name="p1053783769165633"></a>Obtains the top boundary coordinate of the rectangle. </p>
</td>
</tr>
<tr id="row1994983982165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684743138165633"><a name="p1684743138165633"></a><a name="p1684743138165633"></a><a href="graphic.md#ga2f4bd954929225e2f124db4c9d2c62ec">GetLeft</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1452707097165633"><a name="p1452707097165633"></a><a name="p1452707097165633"></a>int16_t </p>
<p id="p776009426165633"><a name="p776009426165633"></a><a name="p776009426165633"></a>Obtains the left boundary coordinate of the rectangle. </p>
</td>
</tr>
<tr id="row218807792165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732455869165633"><a name="p1732455869165633"></a><a name="p1732455869165633"></a><a href="graphic.md#ga9ab9c7eda50b517e55d608270360f0a0">GetTop</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p166959680165633"><a name="p166959680165633"></a><a name="p166959680165633"></a>int16_t </p>
<p id="p684904828165633"><a name="p684904828165633"></a><a name="p684904828165633"></a>Obtains the top boundary coordinate of the rectangle. </p>
</td>
</tr>
<tr id="row1867804930165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p410388053165633"><a name="p410388053165633"></a><a name="p410388053165633"></a><a href="graphic.md#gab7695173ebb2f4b8e9aa58947786a379">GetRight</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024199435165633"><a name="p2024199435165633"></a><a name="p2024199435165633"></a>int16_t </p>
<p id="p108123981165633"><a name="p108123981165633"></a><a name="p108123981165633"></a>Obtains the right boundary coordinate of the rectangle. </p>
</td>
</tr>
<tr id="row1698155947165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1044353104165633"><a name="p1044353104165633"></a><a name="p1044353104165633"></a><a href="graphic.md#ga6c2f9cf035a36c605e20ccc76de8fbea">GetBottom</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1463314279165633"><a name="p1463314279165633"></a><a name="p1463314279165633"></a>int16_t </p>
<p id="p1971046780165633"><a name="p1971046780165633"></a><a name="p1971046780165633"></a>Obtains the bottom boundary coordinate of the rectangle. </p>
</td>
</tr>
<tr id="row425328178165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216820378165633"><a name="p216820378165633"></a><a name="p216820378165633"></a><a href="graphic.md#ga6d14ede131d4a9445e0890632d2e4370">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489374060165633"><a name="p489374060165633"></a><a name="p489374060165633"></a>void </p>
<p id="p341630857165633"><a name="p341630857165633"></a><a name="p341630857165633"></a>Changes the left boundary coordinate of the rectangle without changing the rectangle width. </p>
</td>
</tr>
<tr id="row1634479650165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1205734795165633"><a name="p1205734795165633"></a><a name="p1205734795165633"></a><a href="graphic.md#ga260393d7b4c514eebc2a28187ec6f8b4">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541777449165633"><a name="p1541777449165633"></a><a name="p1541777449165633"></a>void </p>
<p id="p1089921902165633"><a name="p1089921902165633"></a><a name="p1089921902165633"></a>Changes the top boundary coordinate of the rectangle without changing the rectangle height. </p>
</td>
</tr>
<tr id="row1545563014165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141186265165633"><a name="p141186265165633"></a><a name="p141186265165633"></a><a href="graphic.md#ga723d2b5ace818a6b71e0570339689690">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565022235165633"><a name="p565022235165633"></a><a name="p565022235165633"></a>void </p>
<p id="p1581746276165633"><a name="p1581746276165633"></a><a name="p1581746276165633"></a>Changes the coordinates of the left and top boundaries of the rectangle without changing the rectangle width and height. </p>
</td>
</tr>
<tr id="row1794509599165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p121847957165633"><a name="p121847957165633"></a><a name="p121847957165633"></a><a href="graphic.md#ga8a31c03ecb4a452d79374b392537f183">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p385107662165633"><a name="p385107662165633"></a><a name="p385107662165633"></a>void </p>
<p id="p428787430165633"><a name="p428787430165633"></a><a name="p428787430165633"></a>Changes the width of the rectangle without changing the coordinate of the left boundary. </p>
</td>
</tr>
<tr id="row490312158165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118589061165633"><a name="p118589061165633"></a><a name="p118589061165633"></a><a href="graphic.md#ga8e3fab1e0d6cd4671c6628b94c493d0f">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858406957165633"><a name="p1858406957165633"></a><a name="p1858406957165633"></a>void </p>
<p id="p385185700165633"><a name="p385185700165633"></a><a name="p385185700165633"></a>Changes the height of the rectangle without changing the coordinate of the top boundary. </p>
</td>
</tr>
<tr id="row119025789165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129703069165633"><a name="p129703069165633"></a><a name="p129703069165633"></a><a href="graphic.md#ga043a1c4f0aaf4eed2ddf99083ed993bb">SetLeft</a> (int16_t left)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1717474660165633"><a name="p1717474660165633"></a><a name="p1717474660165633"></a>void </p>
<p id="p105984726165633"><a name="p105984726165633"></a><a name="p105984726165633"></a>Sets the coordinate of the left boundary of a rectangle. </p>
</td>
</tr>
<tr id="row669530538165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1453342845165633"><a name="p1453342845165633"></a><a name="p1453342845165633"></a><a href="graphic.md#gae7c63105b7e1871f231a1a8dfad48de7">SetTop</a> (int16_t top)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408446110165633"><a name="p1408446110165633"></a><a name="p1408446110165633"></a>void </p>
<p id="p1127072461165633"><a name="p1127072461165633"></a><a name="p1127072461165633"></a>Sets the coordinate of the top boundary of a rectangle. </p>
</td>
</tr>
<tr id="row1761898031165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1395949512165633"><a name="p1395949512165633"></a><a name="p1395949512165633"></a><a href="graphic.md#ga314f4443ef95351a80e6edaaeff11674">SetRight</a> (int16_t right)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708607907165633"><a name="p708607907165633"></a><a name="p708607907165633"></a>void </p>
<p id="p1130692226165633"><a name="p1130692226165633"></a><a name="p1130692226165633"></a>Sets the coordinate of the right boundary of a rectangle. </p>
</td>
</tr>
<tr id="row902075350165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720322229165633"><a name="p720322229165633"></a><a name="p720322229165633"></a><a href="graphic.md#ga764001fa9f51716fd3dacac691cbca6d">SetBottom</a> (int16_t bottom)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p78436828165633"><a name="p78436828165633"></a><a name="p78436828165633"></a>void </p>
<p id="p783523730165633"><a name="p783523730165633"></a><a name="p783523730165633"></a>Sets the coordinate of the bottom boundary of a rectangle. </p>
</td>
</tr>
<tr id="row1448333160165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092258714165633"><a name="p2092258714165633"></a><a name="p2092258714165633"></a><a href="graphic.md#ga6d51096b1d1b1929d8ee6a0d25c153d8">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706501428165633"><a name="p1706501428165633"></a><a name="p1706501428165633"></a>void </p>
<p id="p1830222060165633"><a name="p1830222060165633"></a><a name="p1830222060165633"></a>Sets the width and height of a rectangle. </p>
</td>
</tr>
<tr id="row2135053258165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284581227165633"><a name="p284581227165633"></a><a name="p284581227165633"></a><a href="graphic.md#ga37f61dc21e0acc2ae877687f06d11e50">GetSize</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424784496165633"><a name="p1424784496165633"></a><a name="p1424784496165633"></a>uint32_t </p>
<p id="p1583162171165633"><a name="p1583162171165633"></a><a name="p1583162171165633"></a>Obtains the area of a rectangle. </p>
</td>
</tr>
<tr id="row1391566017165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1467243335165633"><a name="p1467243335165633"></a><a name="p1467243335165633"></a><a href="graphic.md#ga1af82c2a558d4003d5d3b19302325a73">Intersect</a> (const <a href="ohos-rect.md">Rect</a> &amp;rect1, const <a href="ohos-rect.md">Rect</a> &amp;rect2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990243542165633"><a name="p990243542165633"></a><a name="p990243542165633"></a>bool </p>
<p id="p782958310165633"><a name="p782958310165633"></a><a name="p782958310165633"></a>Checks whether two rectangles intersect. </p>
</td>
</tr>
<tr id="row1794964961165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p731369230165633"><a name="p731369230165633"></a><a name="p731369230165633"></a><a href="graphic.md#ga6269289055eab8876cc3b3c946ddd4a4">Join</a> (const <a href="ohos-rect.md">Rect</a> &amp;rect1, const <a href="ohos-rect.md">Rect</a> &amp;rect2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p801092003165633"><a name="p801092003165633"></a><a name="p801092003165633"></a>void </p>
<p id="p1784826763165633"><a name="p1784826763165633"></a><a name="p1784826763165633"></a>Obtains the minimum rectangle that contains another two rectangles. </p>
</td>
</tr>
<tr id="row751698159165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607172019165633"><a name="p1607172019165633"></a><a name="p1607172019165633"></a><a href="graphic.md#ga1a810eb98134027556294620821c2548">IsContains</a> (const <a href="ohos-vector2-t.md">Vector2</a>&lt; int16_t &gt; &amp;point) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p551746022165633"><a name="p551746022165633"></a><a name="p551746022165633"></a>bool </p>
<p id="p775298160165633"><a name="p775298160165633"></a><a name="p775298160165633"></a>Checks whether the rectangle contains a coordinate point. </p>
</td>
</tr>
<tr id="row1450740038165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p807711211165633"><a name="p807711211165633"></a><a name="p807711211165633"></a><a href="graphic.md#ga5f3cb137429e00b2e7fe1e39f7e9faad">IsContains</a> (const <a href="ohos-point.md">Point</a> &amp;point) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657729777165633"><a name="p1657729777165633"></a><a name="p1657729777165633"></a>bool </p>
<p id="p141803716165633"><a name="p141803716165633"></a><a name="p141803716165633"></a>Checks whether the rectangle contains a coordinate point. </p>
</td>
</tr>
<tr id="row281291358165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p302193275165633"><a name="p302193275165633"></a><a name="p302193275165633"></a><a href="graphic.md#ga808a2b486872f5d1dc1f3e944352bcfb">IsExtends</a> (const <a href="ohos-rect.md">Rect</a> &amp;other) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199630291165633"><a name="p1199630291165633"></a><a name="p1199630291165633"></a>bool </p>
<p id="p955186743165633"><a name="p955186743165633"></a><a name="p955186743165633"></a>Checks whether the rectangle is adjacent to another rectangle horizontally or vertically. </p>
</td>
</tr>
<tr id="row676527611165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031819478165633"><a name="p1031819478165633"></a><a name="p1031819478165633"></a><a href="graphic.md#gacc346d49f3a8ee42662d34140afcbc9e">IsIntersect</a> (const <a href="ohos-rect.md">Rect</a> &amp;other) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p200816251165633"><a name="p200816251165633"></a><a name="p200816251165633"></a>bool </p>
<p id="p1056612332165633"><a name="p1056612332165633"></a><a name="p1056612332165633"></a>Checks whether the rectangle intersects with another rectangle. </p>
</td>
</tr>
<tr id="row1698092265165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276315119165633"><a name="p1276315119165633"></a><a name="p1276315119165633"></a><a href="graphic.md#ga3e17c74e6eaf3b01b5e009db582da498">IsContains</a> (const <a href="ohos-rect.md">Rect</a> &amp;other) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2014336976165633"><a name="p2014336976165633"></a><a name="p2014336976165633"></a>bool </p>
<p id="p772843716165633"><a name="p772843716165633"></a><a name="p772843716165633"></a>Checks whether the rectangle contains another rectangle. </p>
</td>
</tr>
<tr id="row763992827165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018280277165633"><a name="p2018280277165633"></a><a name="p2018280277165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707279537165633"><a name="p707279537165633"></a><a name="p707279537165633"></a>void * </p>
<p id="p1848677838165633"><a name="p1848677838165633"></a><a name="p1848677838165633"></a>Overrides the <strong id="b1506060333165633"><a name="b1506060333165633"></a><a name="b1506060333165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1322504818165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858899486165633"><a name="p1858899486165633"></a><a name="p1858899486165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1116502965165633"><a name="p1116502965165633"></a><a name="p1116502965165633"></a>void </p>
<p id="p1400879272165633"><a name="p1400879272165633"></a><a name="p1400879272165633"></a>Overrides the <strong id="b173640828165633"><a name="b173640828165633"></a><a name="b173640828165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

