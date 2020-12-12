# OHOS::UICircleProgress<a name="EN-US_TOPIC_0000001054879556"></a>

-   [Overview](#section1613404856165634)
-   [Summary](#section805614434165634)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1613404856165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a circular progress bar. 

This class is used to set the start and end angles, range, and current value to display the circular progress bar.

See also
:   [UIAbstractProgress](ohos-uiabstractprogress.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section805614434165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table357550046165634"></a>
<table><thead align="left"><tr id="row1436714347165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p378419273165634"><a name="p378419273165634"></a><a name="p378419273165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1247637677165634"><a name="p1247637677165634"></a><a name="p1247637677165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row787266416165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p273844872165634"><a name="p273844872165634"></a><a name="p273844872165634"></a><a href="graphic.md#gae6d547653f0448f9151fa257cbf9c3ac">UICircleProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779081157165634"><a name="p1779081157165634"></a><a name="p1779081157165634"></a> </p>
<p id="p1080975062165634"><a name="p1080975062165634"></a><a name="p1080975062165634"></a>A constructor used to create a <strong id="b1969053659165634"><a name="b1969053659165634"></a><a name="b1969053659165634"></a><a href="ohos-uicircleprogress.md">UICircleProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1837107897165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p206164183165634"><a name="p206164183165634"></a><a name="p206164183165634"></a><a href="graphic.md#ga10a9da813e933b3513e22a95bb81af98">~UICircleProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1317831747165634"><a name="p1317831747165634"></a><a name="p1317831747165634"></a>virtual </p>
<p id="p1711949225165634"><a name="p1711949225165634"></a><a name="p1711949225165634"></a>A destructor used to delete the <strong id="b1670335700165634"><a name="b1670335700165634"></a><a name="b1670335700165634"></a><a href="ohos-uicircleprogress.md">UICircleProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1398579958165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119894360165634"><a name="p2119894360165634"></a><a name="p2119894360165634"></a><a href="graphic.md#gab1d8fc06d4a73db344efd271d68a62e6">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1722370767165634"><a name="p1722370767165634"></a><a name="p1722370767165634"></a>UIViewType </p>
<p id="p1998117228165634"><a name="p1998117228165634"></a><a name="p1998117228165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1029895232165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1271391154165634"><a name="p1271391154165634"></a><a name="p1271391154165634"></a><a href="graphic.md#ga98bc4ea99629e4d5c7ca5ca4b43e8e96">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413585756165634"><a name="p413585756165634"></a><a name="p413585756165634"></a>bool </p>
<p id="p1395556366165634"><a name="p1395556366165634"></a><a name="p1395556366165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1863287022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1814567800165634"><a name="p1814567800165634"></a><a name="p1814567800165634"></a><a href="graphic.md#ga611f2f03c22499c428d1de3392ee4861">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151309042165634"><a name="p151309042165634"></a><a name="p151309042165634"></a>void </p>
<p id="p80294889165634"><a name="p80294889165634"></a><a name="p80294889165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1246708764165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1147247401165634"><a name="p1147247401165634"></a><a name="p1147247401165634"></a><a href="graphic.md#ga6cf6b8ab0934ce8c0ea1821da0791317">SetCenterPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258875533165634"><a name="p258875533165634"></a><a name="p258875533165634"></a>void </p>
<p id="p33359488165634"><a name="p33359488165634"></a><a name="p33359488165634"></a>Sets the coordinates of the center point for this circular progress bar. </p>
</td>
</tr>
<tr id="row1690309108165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1685571220165634"><a name="p1685571220165634"></a><a name="p1685571220165634"></a><a href="graphic.md#ga706ac374a1383cef01dfc59c5257e480">GetCenterPosition</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413048748165634"><a name="p1413048748165634"></a><a name="p1413048748165634"></a><a href="ohos-point.md">Point</a> </p>
<p id="p1668502103165634"><a name="p1668502103165634"></a><a name="p1668502103165634"></a>Obtains the coordinates of the center point for this circular progress bar. </p>
</td>
</tr>
<tr id="row82608761165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1079127465165634"><a name="p1079127465165634"></a><a name="p1079127465165634"></a><a href="graphic.md#ga80377fb579f6698cefd5fcf74d0cde46">SetRadius</a> (uint16_t radius)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p917125977165634"><a name="p917125977165634"></a><a name="p917125977165634"></a>void </p>
<p id="p41473507165634"><a name="p41473507165634"></a><a name="p41473507165634"></a>Sets the outer radius for this circular progress bar. </p>
</td>
</tr>
<tr id="row2052636167165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840455472165634"><a name="p840455472165634"></a><a name="p840455472165634"></a><a href="graphic.md#gabb2869e683ccd799891a8869613ec8c7">GetRadius</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024137538165634"><a name="p2024137538165634"></a><a name="p2024137538165634"></a>uint16_t </p>
<p id="p493329578165634"><a name="p493329578165634"></a><a name="p493329578165634"></a>Obtains the outer radius of this circular progress bar. </p>
</td>
</tr>
<tr id="row524227616165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005392014165634"><a name="p2005392014165634"></a><a name="p2005392014165634"></a><a href="graphic.md#gae27e30bd77b83bc55ecc9f2a5643943a">SetStartAngle</a> (int16_t startAngle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p671229176165634"><a name="p671229176165634"></a><a name="p671229176165634"></a>void </p>
<p id="p1675020250165634"><a name="p1675020250165634"></a><a name="p1675020250165634"></a>Sets the start angle. </p>
</td>
</tr>
<tr id="row1429034957165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p367435958165634"><a name="p367435958165634"></a><a name="p367435958165634"></a><a href="graphic.md#ga37a3e63da7a8658e48a25ae9ec73abea">GetStartAngle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1859695892165634"><a name="p1859695892165634"></a><a name="p1859695892165634"></a>int16_t </p>
<p id="p630878773165634"><a name="p630878773165634"></a><a name="p630878773165634"></a>Obtains the start angle. </p>
</td>
</tr>
<tr id="row1047949626165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p18610257165634"><a name="p18610257165634"></a><a name="p18610257165634"></a><a href="graphic.md#ga831186bf208f8236b006b13cc122c82c">SetEndAngle</a> (int16_t endAngle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834423798165634"><a name="p1834423798165634"></a><a name="p1834423798165634"></a>void </p>
<p id="p2020766611165634"><a name="p2020766611165634"></a><a name="p2020766611165634"></a>Sets the end angle. </p>
</td>
</tr>
<tr id="row1086494638165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977049175165634"><a name="p1977049175165634"></a><a name="p1977049175165634"></a><a href="graphic.md#gacab2327bfc24ee985818a95d468af181">GetEndAngle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462512024165634"><a name="p462512024165634"></a><a name="p462512024165634"></a>int16_t </p>
<p id="p1403184482165634"><a name="p1403184482165634"></a><a name="p1403184482165634"></a>Obtains the end angle. </p>
</td>
</tr>
<tr id="row107771403165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1932100856165634"><a name="p1932100856165634"></a><a name="p1932100856165634"></a><a href="graphic.md#ga62b71500ccc75673be297d2e114c0c1b">SetProgressImagePosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p551205086165634"><a name="p551205086165634"></a><a name="p551205086165634"></a>void </p>
<p id="p863760484165634"><a name="p863760484165634"></a><a name="p863760484165634"></a>Sets the coordinates of the foreground image for this progress bar relative to the view. </p>
</td>
</tr>
<tr id="row1079681290165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342346660165634"><a name="p342346660165634"></a><a name="p342346660165634"></a><a href="graphic.md#ga66b95a4793bc60596a56be00849b8296">SetBackgroundImagePosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1722159108165634"><a name="p1722159108165634"></a><a name="p1722159108165634"></a>void </p>
<p id="p633509965165634"><a name="p633509965165634"></a><a name="p633509965165634"></a>Sets the coordinates of the background image for this progress bar relative to the view. </p>
</td>
</tr>
<tr id="row880835876165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423836889165634"><a name="p423836889165634"></a><a name="p423836889165634"></a><a href="graphic.md#gad0453bc291f75f4864c112f9f2f474db">SetLineColor</a> (<a href="ohos-color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488698752165634"><a name="p488698752165634"></a><a name="p488698752165634"></a>void </p>
<p id="p1857267748165634"><a name="p1857267748165634"></a><a name="p1857267748165634"></a>Sets the foreground color for this progress bar. </p>
</td>
</tr>
<tr id="row1749675849165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p969759038165634"><a name="p969759038165634"></a><a name="p969759038165634"></a><a href="graphic.md#ga8f9bfb4f42ee0e094501ff776e3336da">UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p764515884165634"><a name="p764515884165634"></a><a name="p764515884165634"></a> </p>
<p id="p231736609165634"><a name="p231736609165634"></a><a name="p231736609165634"></a>A constructor used to create a <strong id="b633634844165634"><a name="b633634844165634"></a><a name="b633634844165634"></a><a href="ohos-uiabstractprogress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row951130294165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p307495504165634"><a name="p307495504165634"></a><a name="p307495504165634"></a><a href="graphic.md#ga5c1cf7239bf0c0f7d331e63df805b518">~UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672507790165634"><a name="p1672507790165634"></a><a name="p1672507790165634"></a>virtual </p>
<p id="p986391833165634"><a name="p986391833165634"></a><a name="p986391833165634"></a>A destructor used to delete the <strong id="b371696292165634"><a name="b371696292165634"></a><a name="b371696292165634"></a><a href="ohos-uiabstractprogress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1295155962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p772378940165634"><a name="p772378940165634"></a><a name="p772378940165634"></a><a href="graphic.md#gacb680c1ddc9135371676df504dc6c8f2">EnableBackground</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405859303165634"><a name="p1405859303165634"></a><a name="p1405859303165634"></a>void </p>
<p id="p2120573479165634"><a name="p2120573479165634"></a><a name="p2120573479165634"></a>Sets whether the background of the progress bar is visible. </p>
</td>
</tr>
<tr id="row1858508642165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1337776827165634"><a name="p1337776827165634"></a><a name="p1337776827165634"></a><a href="graphic.md#ga5f65014431a6489ffa1d4949f9c4449b">SetValue</a> (int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424543319165634"><a name="p424543319165634"></a><a name="p424543319165634"></a>void </p>
<p id="p1328070273165634"><a name="p1328070273165634"></a><a name="p1328070273165634"></a>Sets the current value for this progress bar. </p>
</td>
</tr>
<tr id="row1824005610165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p40294314165634"><a name="p40294314165634"></a><a name="p40294314165634"></a><a href="graphic.md#ga6face76aa7972efeb6cbb8f525f23135">GetValue</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2056917493165634"><a name="p2056917493165634"></a><a name="p2056917493165634"></a>int16_t </p>
<p id="p986046601165634"><a name="p986046601165634"></a><a name="p986046601165634"></a>Obtains the current value of this progress bar. </p>
</td>
</tr>
<tr id="row1813254464165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828055573165634"><a name="p1828055573165634"></a><a name="p1828055573165634"></a><a href="graphic.md#ga089e3875453011499ad33ed89a44a699">SetRange</a> (int16_t rangeMax, int16_t rangeMin)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p651320859165634"><a name="p651320859165634"></a><a name="p651320859165634"></a>void </p>
<p id="p1978049941165634"><a name="p1978049941165634"></a><a name="p1978049941165634"></a>Sets the range for this progress bar. </p>
</td>
</tr>
<tr id="row362608945165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682042742165634"><a name="p1682042742165634"></a><a name="p1682042742165634"></a><a href="graphic.md#ga68ab733afcf4224a799ccad2092d1d23">GetRangeMin</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085713568165634"><a name="p1085713568165634"></a><a name="p1085713568165634"></a>int16_t </p>
<p id="p347183238165634"><a name="p347183238165634"></a><a name="p347183238165634"></a>Obtains the minimum value of this progress bar. </p>
</td>
</tr>
<tr id="row757602693165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025199083165634"><a name="p2025199083165634"></a><a name="p2025199083165634"></a><a href="graphic.md#ga1840199f22d5d3e4ef58e41ac8f4febc">GetRangeMax</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1704774086165634"><a name="p1704774086165634"></a><a name="p1704774086165634"></a>int16_t </p>
<p id="p1091212505165634"><a name="p1091212505165634"></a><a name="p1091212505165634"></a>Obtains the maximum value of this progress bar. </p>
</td>
</tr>
<tr id="row718761544165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1394432370165634"><a name="p1394432370165634"></a><a name="p1394432370165634"></a><a href="graphic.md#ga5b3ec363e391f601e12bf937b9cf77db">SetImage</a> (const char *foregroundImage, const char *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513196163165634"><a name="p1513196163165634"></a><a name="p1513196163165634"></a>void </p>
<p id="p1234558918165634"><a name="p1234558918165634"></a><a name="p1234558918165634"></a>Sets the image for this progress bar. </p>
</td>
</tr>
<tr id="row568283698165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567281960165634"><a name="p1567281960165634"></a><a name="p1567281960165634"></a><a href="graphic.md#ga10723293ab9e384907dd9dacbc9ad448">SetImage</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *foregroundImage, const <a href="ohos-imageinfo.md">ImageInfo</a> *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p12952372165634"><a name="p12952372165634"></a><a name="p12952372165634"></a>void </p>
<p id="p443145729165634"><a name="p443145729165634"></a><a name="p443145729165634"></a>Sets the image as a pixel map for this progress bar. </p>
</td>
</tr>
<tr id="row1257370333165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1507853697165634"><a name="p1507853697165634"></a><a name="p1507853697165634"></a><a href="graphic.md#ga747a29652b441a06d09a97a297aae9bb">SetStep</a> (uint16_t step)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206572074165634"><a name="p206572074165634"></a><a name="p206572074165634"></a>void </p>
<p id="p1115191682165634"><a name="p1115191682165634"></a><a name="p1115191682165634"></a>Sets the step for this progress bar. </p>
</td>
</tr>
<tr id="row1769407165165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806972985165634"><a name="p806972985165634"></a><a name="p806972985165634"></a><a href="graphic.md#ga9c1678604605a54c2e338d283c46866d">GetStep</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32488178165634"><a name="p32488178165634"></a><a name="p32488178165634"></a>uint16_t </p>
<p id="p1769329382165634"><a name="p1769329382165634"></a><a name="p1769329382165634"></a>Obtains the current step of this progress bar. </p>
</td>
</tr>
<tr id="row762795778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177823123165634"><a name="p1177823123165634"></a><a name="p1177823123165634"></a><a href="graphic.md#ga6817b5178e93e5f16f2b420cf5a171c1">SetBackgroundStyle</a> (const <a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507133380165634"><a name="p1507133380165634"></a><a name="p1507133380165634"></a>void </p>
<p id="p744723784165634"><a name="p744723784165634"></a><a name="p744723784165634"></a>Sets the background style for this progress bar. </p>
</td>
</tr>
<tr id="row857510923165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1671951510165634"><a name="p1671951510165634"></a><a name="p1671951510165634"></a><a href="graphic.md#ga23acea0a42587746e35ec5f3a74af59f">SetBackgroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p204718938165634"><a name="p204718938165634"></a><a name="p204718938165634"></a>void </p>
<p id="p1703874249165634"><a name="p1703874249165634"></a><a name="p1703874249165634"></a>Sets a background style for this progress bar. </p>
</td>
</tr>
<tr id="row73871333165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1898486050165634"><a name="p1898486050165634"></a><a name="p1898486050165634"></a><a href="graphic.md#gac2ca1212c23c11405b12ae0a46c7eff1">GetBackgroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272858575165634"><a name="p1272858575165634"></a><a name="p1272858575165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p800459277165634"><a name="p800459277165634"></a><a name="p800459277165634"></a>Obtains the background style of this progress bar. </p>
</td>
</tr>
<tr id="row180324592165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p962817241165634"><a name="p962817241165634"></a><a name="p962817241165634"></a><a href="graphic.md#ga946d3f2c39a79d45149118536b2557a9">GetBackgroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p688546905165634"><a name="p688546905165634"></a><a name="p688546905165634"></a>int64_t </p>
<p id="p491360526165634"><a name="p491360526165634"></a><a name="p491360526165634"></a>Obtains the value of a background style of this progress bar. </p>
</td>
</tr>
<tr id="row636363860165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1348916956165634"><a name="p1348916956165634"></a><a name="p1348916956165634"></a><a href="graphic.md#gaccebcfa35f98f9bc6be4bb8cc53eb11c">SetForegroundStyle</a> (const <a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1562478368165634"><a name="p1562478368165634"></a><a name="p1562478368165634"></a>void </p>
<p id="p2021703105165634"><a name="p2021703105165634"></a><a name="p2021703105165634"></a>Sets the foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row1326544966165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1966763151165634"><a name="p1966763151165634"></a><a name="p1966763151165634"></a><a href="graphic.md#gae6386ca25603e42f06087f6b2ef65bae">SetForegroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1991268079165634"><a name="p1991268079165634"></a><a name="p1991268079165634"></a>void </p>
<p id="p1767484907165634"><a name="p1767484907165634"></a><a name="p1767484907165634"></a>Sets a foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row1671679979165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p500290731165634"><a name="p500290731165634"></a><a name="p500290731165634"></a><a href="graphic.md#gac77f945f375f333f80bd70254b5c1f96">GetForegroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1966744331165634"><a name="p1966744331165634"></a><a name="p1966744331165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p809044108165634"><a name="p809044108165634"></a><a name="p809044108165634"></a>Obtains the foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row701892962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1164323549165634"><a name="p1164323549165634"></a><a name="p1164323549165634"></a><a href="graphic.md#ga74cd121dd1794d7e8d905b233bd98217">GetForegroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p548653536165634"><a name="p548653536165634"></a><a name="p548653536165634"></a>int64_t </p>
<p id="p502882316165634"><a name="p502882316165634"></a><a name="p502882316165634"></a>Obtains the value of a foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row1224495777165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p398697103165634"><a name="p398697103165634"></a><a name="p398697103165634"></a><a href="graphic.md#gabdc0eb4d279212ea7c3ea7a1f9a85e13">SetCapType</a> (<a href="graphic.md#ga2db3928cdf793f4950245a6841dd43d6">CapType</a> cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078792755165634"><a name="p1078792755165634"></a><a name="p1078792755165634"></a>void </p>
<p id="p1664565048165634"><a name="p1664565048165634"></a><a name="p1664565048165634"></a>Sets the type of caps on the background and foreground of the progress bar. </p>
</td>
</tr>
<tr id="row1072291821165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2007822049165634"><a name="p2007822049165634"></a><a name="p2007822049165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847455672165634"><a name="p847455672165634"></a><a name="p847455672165634"></a> </p>
<p id="p1616768798165634"><a name="p1616768798165634"></a><a name="p1616768798165634"></a>A default constructor used to create an <strong id="b686339604165634"><a name="b686339604165634"></a><a name="b686339604165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1637837666165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1062513783165634"><a name="p1062513783165634"></a><a name="p1062513783165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14594455165634"><a name="p14594455165634"></a><a name="p14594455165634"></a> </p>
<p id="p1260606243165634"><a name="p1260606243165634"></a><a name="p1260606243165634"></a>A constructor used to create an <strong id="b786309318165634"><a name="b786309318165634"></a><a name="b786309318165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row380089170165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p415320321165634"><a name="p415320321165634"></a><a name="p415320321165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p594116779165634"><a name="p594116779165634"></a><a name="p594116779165634"></a>virtual </p>
<p id="p794765121165634"><a name="p794765121165634"></a><a name="p794765121165634"></a>A destructor used to delete the <strong id="b959852072165634"><a name="b959852072165634"></a><a name="b959852072165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row461523056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1460766843165634"><a name="p1460766843165634"></a><a name="p1460766843165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p866506498165634"><a name="p866506498165634"></a><a name="p866506498165634"></a>virtual void </p>
<p id="p767327948165634"><a name="p767327948165634"></a><a name="p767327948165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row583936778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p47065112165634"><a name="p47065112165634"></a><a name="p47065112165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1942518321165634"><a name="p1942518321165634"></a><a name="p1942518321165634"></a>virtual void </p>
<p id="p270806067165634"><a name="p270806067165634"></a><a name="p270806067165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row568061209165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p710503079165634"><a name="p710503079165634"></a><a name="p710503079165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9309366165634"><a name="p9309366165634"></a><a name="p9309366165634"></a>void </p>
<p id="p822974953165634"><a name="p822974953165634"></a><a name="p822974953165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row710435994165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p592774605165634"><a name="p592774605165634"></a><a name="p592774605165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p87204640165634"><a name="p87204640165634"></a><a name="p87204640165634"></a>void </p>
<p id="p1569548877165634"><a name="p1569548877165634"></a><a name="p1569548877165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1692862567165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p760437023165634"><a name="p760437023165634"></a><a name="p760437023165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175357759165634"><a name="p175357759165634"></a><a name="p175357759165634"></a>virtual bool </p>
<p id="p943722562165634"><a name="p943722562165634"></a><a name="p943722562165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1555592486165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1843966805165634"><a name="p1843966805165634"></a><a name="p1843966805165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508861200165634"><a name="p1508861200165634"></a><a name="p1508861200165634"></a>virtual bool </p>
<p id="p1897490766165634"><a name="p1897490766165634"></a><a name="p1897490766165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row389726139165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041948932165634"><a name="p1041948932165634"></a><a name="p1041948932165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1439891439165634"><a name="p1439891439165634"></a><a name="p1439891439165634"></a>virtual bool </p>
<p id="p528547308165634"><a name="p528547308165634"></a><a name="p528547308165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row2098519053165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337306451165634"><a name="p337306451165634"></a><a name="p337306451165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1829724924165634"><a name="p1829724924165634"></a><a name="p1829724924165634"></a>virtual bool </p>
<p id="p1788316735165634"><a name="p1788316735165634"></a><a name="p1788316735165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1923626635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p310139319165634"><a name="p310139319165634"></a><a name="p310139319165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661758671165634"><a name="p661758671165634"></a><a name="p661758671165634"></a>virtual void </p>
<p id="p1818198110165634"><a name="p1818198110165634"></a><a name="p1818198110165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row952997860165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1399307717165634"><a name="p1399307717165634"></a><a name="p1399307717165634"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1441069154165634"><a name="p1441069154165634"></a><a name="p1441069154165634"></a>virtual void </p>
<p id="p1555579087165634"><a name="p1555579087165634"></a><a name="p1555579087165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row900245738165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p192520117165634"><a name="p192520117165634"></a><a name="p192520117165634"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1588427922165634"><a name="p1588427922165634"></a><a name="p1588427922165634"></a>virtual void </p>
<p id="p172246403165634"><a name="p172246403165634"></a><a name="p172246403165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1345998303165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1148708403165634"><a name="p1148708403165634"></a><a name="p1148708403165634"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p353967222165634"><a name="p353967222165634"></a><a name="p353967222165634"></a>virtual void </p>
<p id="p1052059640165634"><a name="p1052059640165634"></a><a name="p1052059640165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1856835679165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1708366266165634"><a name="p1708366266165634"></a><a name="p1708366266165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965666695165634"><a name="p1965666695165634"></a><a name="p1965666695165634"></a>void </p>
<p id="p94437426165634"><a name="p94437426165634"></a><a name="p94437426165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row841069739165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p414670145165634"><a name="p414670145165634"></a><a name="p414670145165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182753168165634"><a name="p182753168165634"></a><a name="p182753168165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p380467887165634"><a name="p380467887165634"></a><a name="p380467887165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row178836881165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291400084165634"><a name="p1291400084165634"></a><a name="p1291400084165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178275324165634"><a name="p178275324165634"></a><a name="p178275324165634"></a>void </p>
<p id="p966807364165634"><a name="p966807364165634"></a><a name="p966807364165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1762331634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p466651923165634"><a name="p466651923165634"></a><a name="p466651923165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p171283360165634"><a name="p171283360165634"></a><a name="p171283360165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1196062356165634"><a name="p1196062356165634"></a><a name="p1196062356165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row275465417165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237822483165634"><a name="p237822483165634"></a><a name="p237822483165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2018841715165634"><a name="p2018841715165634"></a><a name="p2018841715165634"></a>void </p>
<p id="p1770787812165634"><a name="p1770787812165634"></a><a name="p1770787812165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1543667681165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p202396942165634"><a name="p202396942165634"></a><a name="p202396942165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999746496165634"><a name="p1999746496165634"></a><a name="p1999746496165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1611694069165634"><a name="p1611694069165634"></a><a name="p1611694069165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row866360083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113757922165634"><a name="p1113757922165634"></a><a name="p1113757922165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1392181992165634"><a name="p1392181992165634"></a><a name="p1392181992165634"></a>void </p>
<p id="p1627469895165634"><a name="p1627469895165634"></a><a name="p1627469895165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1503045892165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2042036374165634"><a name="p2042036374165634"></a><a name="p2042036374165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p171799108165634"><a name="p171799108165634"></a><a name="p171799108165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p304872231165634"><a name="p304872231165634"></a><a name="p304872231165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row79972430165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p467931767165634"><a name="p467931767165634"></a><a name="p467931767165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788785464165634"><a name="p1788785464165634"></a><a name="p1788785464165634"></a>virtual void </p>
<p id="p1956466442165634"><a name="p1956466442165634"></a><a name="p1956466442165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row2125863915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1366274717165634"><a name="p1366274717165634"></a><a name="p1366274717165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p706965449165634"><a name="p706965449165634"></a><a name="p706965449165634"></a>void </p>
<p id="p998881838165634"><a name="p998881838165634"></a><a name="p998881838165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row708477985165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1075868060165634"><a name="p1075868060165634"></a><a name="p1075868060165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1082653506165634"><a name="p1082653506165634"></a><a name="p1082653506165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p125125342165634"><a name="p125125342165634"></a><a name="p125125342165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row184161444165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627374175165634"><a name="p1627374175165634"></a><a name="p1627374175165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423735303165634"><a name="p423735303165634"></a><a name="p423735303165634"></a>void </p>
<p id="p347362275165634"><a name="p347362275165634"></a><a name="p347362275165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1137560384165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2078545536165634"><a name="p2078545536165634"></a><a name="p2078545536165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91126243165634"><a name="p91126243165634"></a><a name="p91126243165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p276772914165634"><a name="p276772914165634"></a><a name="p276772914165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1996175855165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1040612473165634"><a name="p1040612473165634"></a><a name="p1040612473165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508283008165634"><a name="p1508283008165634"></a><a name="p1508283008165634"></a>virtual void </p>
<p id="p1780910037165634"><a name="p1780910037165634"></a><a name="p1780910037165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row812467010165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2021528481165634"><a name="p2021528481165634"></a><a name="p2021528481165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775844254165634"><a name="p775844254165634"></a><a name="p775844254165634"></a>bool </p>
<p id="p307300411165634"><a name="p307300411165634"></a><a name="p307300411165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1015781549165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384533761165634"><a name="p384533761165634"></a><a name="p384533761165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273270967165634"><a name="p273270967165634"></a><a name="p273270967165634"></a>void </p>
<p id="p934079982165634"><a name="p934079982165634"></a><a name="p934079982165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row890529968165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1967504676165634"><a name="p1967504676165634"></a><a name="p1967504676165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1510151177165634"><a name="p1510151177165634"></a><a name="p1510151177165634"></a>bool </p>
<p id="p331011386165634"><a name="p331011386165634"></a><a name="p331011386165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1654360622165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2033928361165634"><a name="p2033928361165634"></a><a name="p2033928361165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2500077165634"><a name="p2500077165634"></a><a name="p2500077165634"></a>void </p>
<p id="p1259267968165634"><a name="p1259267968165634"></a><a name="p1259267968165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row666784746165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1664487597165634"><a name="p1664487597165634"></a><a name="p1664487597165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1280184358165634"><a name="p1280184358165634"></a><a name="p1280184358165634"></a>bool </p>
<p id="p1458097413165634"><a name="p1458097413165634"></a><a name="p1458097413165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1195188759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p499650871165634"><a name="p499650871165634"></a><a name="p499650871165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073784420165634"><a name="p2073784420165634"></a><a name="p2073784420165634"></a>void </p>
<p id="p1510898136165634"><a name="p1510898136165634"></a><a name="p1510898136165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row67917134165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p60020243165634"><a name="p60020243165634"></a><a name="p60020243165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1718413266165634"><a name="p1718413266165634"></a><a name="p1718413266165634"></a>bool </p>
<p id="p978234463165634"><a name="p978234463165634"></a><a name="p978234463165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row235910270165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707718196165634"><a name="p1707718196165634"></a><a name="p1707718196165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1548634503165634"><a name="p1548634503165634"></a><a name="p1548634503165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p541508513165634"><a name="p541508513165634"></a><a name="p541508513165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row360300162165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485415140165634"><a name="p1485415140165634"></a><a name="p1485415140165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1734162508165634"><a name="p1734162508165634"></a><a name="p1734162508165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p608770939165634"><a name="p608770939165634"></a><a name="p608770939165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1596642514165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596583992165634"><a name="p1596583992165634"></a><a name="p1596583992165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882835446165634"><a name="p1882835446165634"></a><a name="p1882835446165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p238213884165634"><a name="p238213884165634"></a><a name="p238213884165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row688547643165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1466988274165634"><a name="p1466988274165634"></a><a name="p1466988274165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1365203504165634"><a name="p1365203504165634"></a><a name="p1365203504165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1598582160165634"><a name="p1598582160165634"></a><a name="p1598582160165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row7272195165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26861615165634"><a name="p26861615165634"></a><a name="p26861615165634"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p799749030165634"><a name="p799749030165634"></a><a name="p799749030165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p139096591165634"><a name="p139096591165634"></a><a name="p139096591165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row700626945165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1922906683165634"><a name="p1922906683165634"></a><a name="p1922906683165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p951196416165634"><a name="p951196416165634"></a><a name="p951196416165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1949046854165634"><a name="p1949046854165634"></a><a name="p1949046854165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row2106015531165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177183901165634"><a name="p1177183901165634"></a><a name="p1177183901165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304934136165634"><a name="p1304934136165634"></a><a name="p1304934136165634"></a>void </p>
<p id="p232196795165634"><a name="p232196795165634"></a><a name="p232196795165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1462723143165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p478764867165634"><a name="p478764867165634"></a><a name="p478764867165634"></a><a href="graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2014005426165634"><a name="p2014005426165634"></a><a name="p2014005426165634"></a>virtual void </p>
<p id="p425091654165634"><a name="p425091654165634"></a><a name="p425091654165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row420830206165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122342864165634"><a name="p1122342864165634"></a><a name="p1122342864165634"></a><a href="graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p407401169165634"><a name="p407401169165634"></a><a name="p407401169165634"></a>virtual int16_t </p>
<p id="p1646584546165634"><a name="p1646584546165634"></a><a name="p1646584546165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row959829430165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638565788165634"><a name="p1638565788165634"></a><a name="p1638565788165634"></a><a href="graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797980504165634"><a name="p1797980504165634"></a><a name="p1797980504165634"></a>virtual void </p>
<p id="p2022892384165634"><a name="p2022892384165634"></a><a name="p2022892384165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row293335869165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p618780564165634"><a name="p618780564165634"></a><a name="p618780564165634"></a><a href="graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021395215165634"><a name="p2021395215165634"></a><a name="p2021395215165634"></a>virtual int16_t </p>
<p id="p453938127165634"><a name="p453938127165634"></a><a name="p453938127165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row2117045551165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1410131544165634"><a name="p1410131544165634"></a><a name="p1410131544165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215189368165634"><a name="p215189368165634"></a><a name="p215189368165634"></a>virtual void </p>
<p id="p1053251437165634"><a name="p1053251437165634"></a><a name="p1053251437165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1353417670165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117994104165634"><a name="p117994104165634"></a><a name="p117994104165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1673469676165634"><a name="p1673469676165634"></a><a name="p1673469676165634"></a>virtual void </p>
<p id="p638200153165634"><a name="p638200153165634"></a><a name="p638200153165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1988418906165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214086429165634"><a name="p214086429165634"></a><a name="p214086429165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1070483864165634"><a name="p1070483864165634"></a><a name="p1070483864165634"></a>int16_t </p>
<p id="p711791410165634"><a name="p711791410165634"></a><a name="p711791410165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row725809363165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1208652924165634"><a name="p1208652924165634"></a><a name="p1208652924165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034594133165634"><a name="p2034594133165634"></a><a name="p2034594133165634"></a>virtual void </p>
<p id="p1021908114165634"><a name="p1021908114165634"></a><a name="p1021908114165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row393982714165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1604203362165634"><a name="p1604203362165634"></a><a name="p1604203362165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45806555165634"><a name="p45806555165634"></a><a name="p45806555165634"></a>int16_t </p>
<p id="p1331320547165634"><a name="p1331320547165634"></a><a name="p1331320547165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row63262376165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1662462902165634"><a name="p1662462902165634"></a><a name="p1662462902165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1794749438165634"><a name="p1794749438165634"></a><a name="p1794749438165634"></a>virtual void </p>
<p id="p1945534970165634"><a name="p1945534970165634"></a><a name="p1945534970165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row972974777165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p213854411165634"><a name="p213854411165634"></a><a name="p213854411165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1773711272165634"><a name="p1773711272165634"></a><a name="p1773711272165634"></a>virtual void </p>
<p id="p1487235178165634"><a name="p1487235178165634"></a><a name="p1487235178165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1874743609165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1569940904165634"><a name="p1569940904165634"></a><a name="p1569940904165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1664019721165634"><a name="p1664019721165634"></a><a name="p1664019721165634"></a>bool </p>
<p id="p474695866165634"><a name="p474695866165634"></a><a name="p474695866165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row998234406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p297415345165634"><a name="p297415345165634"></a><a name="p297415345165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382750221165634"><a name="p382750221165634"></a><a name="p382750221165634"></a>void </p>
<p id="p1314945052165634"><a name="p1314945052165634"></a><a name="p1314945052165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1735340466165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1647489406165634"><a name="p1647489406165634"></a><a name="p1647489406165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1103582779165634"><a name="p1103582779165634"></a><a name="p1103582779165634"></a>void </p>
<p id="p1825251936165634"><a name="p1825251936165634"></a><a name="p1825251936165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row358480864165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2126496309165634"><a name="p2126496309165634"></a><a name="p2126496309165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135689245165634"><a name="p135689245165634"></a><a name="p135689245165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p140750610165634"><a name="p140750610165634"></a><a name="p140750610165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1511475992165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306767497165634"><a name="p306767497165634"></a><a name="p306767497165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457441963165634"><a name="p457441963165634"></a><a name="p457441963165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p822451525165634"><a name="p822451525165634"></a><a name="p822451525165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row565117545165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420790910165634"><a name="p420790910165634"></a><a name="p420790910165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861253257165634"><a name="p861253257165634"></a><a name="p861253257165634"></a>void </p>
<p id="p921648885165634"><a name="p921648885165634"></a><a name="p921648885165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1089437634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p95749447165634"><a name="p95749447165634"></a><a name="p95749447165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651181699165634"><a name="p1651181699165634"></a><a name="p1651181699165634"></a>const char * </p>
<p id="p1168060413165634"><a name="p1168060413165634"></a><a name="p1168060413165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row2093774677165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720234574165634"><a name="p1720234574165634"></a><a name="p1720234574165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391130600165634"><a name="p391130600165634"></a><a name="p391130600165634"></a>void </p>
<p id="p800788631165634"><a name="p800788631165634"></a><a name="p800788631165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row666508602165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1267411384165634"><a name="p1267411384165634"></a><a name="p1267411384165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p976704288165634"><a name="p976704288165634"></a><a name="p976704288165634"></a>int16_t </p>
<p id="p1303073227165634"><a name="p1303073227165634"></a><a name="p1303073227165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1145074850165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168845220165634"><a name="p168845220165634"></a><a name="p168845220165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1739298900165634"><a name="p1739298900165634"></a><a name="p1739298900165634"></a>virtual void </p>
<p id="p998590617165634"><a name="p998590617165634"></a><a name="p998590617165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row924493623165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772206755165634"><a name="p1772206755165634"></a><a name="p1772206755165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p344246197165634"><a name="p344246197165634"></a><a name="p344246197165634"></a>void </p>
<p id="p2140103198165634"><a name="p2140103198165634"></a><a name="p2140103198165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1752784529165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1829095799165634"><a name="p1829095799165634"></a><a name="p1829095799165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1995273193165634"><a name="p1995273193165634"></a><a name="p1995273193165634"></a>void </p>
<p id="p394801333165634"><a name="p394801333165634"></a><a name="p394801333165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row854344349165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1882871646165634"><a name="p1882871646165634"></a><a name="p1882871646165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2569927165634"><a name="p2569927165634"></a><a name="p2569927165634"></a>void </p>
<p id="p1264004212165634"><a name="p1264004212165634"></a><a name="p1264004212165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row98098885165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1964968265165634"><a name="p1964968265165634"></a><a name="p1964968265165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p685955875165634"><a name="p685955875165634"></a><a name="p685955875165634"></a>void </p>
<p id="p795193766165634"><a name="p795193766165634"></a><a name="p795193766165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row292633398165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1815031644165634"><a name="p1815031644165634"></a><a name="p1815031644165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381873449165634"><a name="p1381873449165634"></a><a name="p1381873449165634"></a>void </p>
<p id="p1879163151165634"><a name="p1879163151165634"></a><a name="p1879163151165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row469323956165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669904403165634"><a name="p669904403165634"></a><a name="p669904403165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p606198301165634"><a name="p606198301165634"></a><a name="p606198301165634"></a>void </p>
<p id="p1160135744165634"><a name="p1160135744165634"></a><a name="p1160135744165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1943622630165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1055805893165634"><a name="p1055805893165634"></a><a name="p1055805893165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644402977165634"><a name="p644402977165634"></a><a name="p644402977165634"></a>void </p>
<p id="p1504799419165634"><a name="p1504799419165634"></a><a name="p1504799419165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row727824796165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p696886470165634"><a name="p696886470165634"></a><a name="p696886470165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1262500661165634"><a name="p1262500661165634"></a><a name="p1262500661165634"></a>void </p>
<p id="p2090529754165634"><a name="p2090529754165634"></a><a name="p2090529754165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row704553348165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1267459742165634"><a name="p1267459742165634"></a><a name="p1267459742165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p493313780165634"><a name="p493313780165634"></a><a name="p493313780165634"></a>void </p>
<p id="p388764096165634"><a name="p388764096165634"></a><a name="p388764096165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row168038953165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160246282165634"><a name="p160246282165634"></a><a name="p160246282165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424264232165634"><a name="p1424264232165634"></a><a name="p1424264232165634"></a>void </p>
<p id="p2113831502165634"><a name="p2113831502165634"></a><a name="p2113831502165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1718226893165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p724401355165634"><a name="p724401355165634"></a><a name="p724401355165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494367981165634"><a name="p1494367981165634"></a><a name="p1494367981165634"></a>void </p>
<p id="p2074400407165634"><a name="p2074400407165634"></a><a name="p2074400407165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row583243358165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p570448050165634"><a name="p570448050165634"></a><a name="p570448050165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p217873683165634"><a name="p217873683165634"></a><a name="p217873683165634"></a>void </p>
<p id="p721823233165634"><a name="p721823233165634"></a><a name="p721823233165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row275336363165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1368472024165634"><a name="p1368472024165634"></a><a name="p1368472024165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1134730090165634"><a name="p1134730090165634"></a><a name="p1134730090165634"></a>void </p>
<p id="p1072242432165634"><a name="p1072242432165634"></a><a name="p1072242432165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1133163711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1694370948165634"><a name="p1694370948165634"></a><a name="p1694370948165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p131849801165634"><a name="p131849801165634"></a><a name="p131849801165634"></a>void </p>
<p id="p848942496165634"><a name="p848942496165634"></a><a name="p848942496165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1688553134165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343241665165634"><a name="p343241665165634"></a><a name="p343241665165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389006531165634"><a name="p1389006531165634"></a><a name="p1389006531165634"></a>void </p>
<p id="p1960692304165634"><a name="p1960692304165634"></a><a name="p1960692304165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1440837812165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775677131165634"><a name="p1775677131165634"></a><a name="p1775677131165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657028814165634"><a name="p1657028814165634"></a><a name="p1657028814165634"></a>void </p>
<p id="p618052548165634"><a name="p618052548165634"></a><a name="p618052548165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1847018878165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1121359999165634"><a name="p1121359999165634"></a><a name="p1121359999165634"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p404694168165634"><a name="p404694168165634"></a><a name="p404694168165634"></a>virtual void </p>
<p id="p1197179154165634"><a name="p1197179154165634"></a><a name="p1197179154165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1417828752165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313704931165634"><a name="p313704931165634"></a><a name="p313704931165634"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377876705165634"><a name="p1377876705165634"></a><a name="p1377876705165634"></a>virtual int64_t </p>
<p id="p131117249165634"><a name="p131117249165634"></a><a name="p131117249165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1724246918165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217431844165634"><a name="p1217431844165634"></a><a name="p1217431844165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p514819969165634"><a name="p514819969165634"></a><a name="p514819969165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1103820692165634"><a name="p1103820692165634"></a><a name="p1103820692165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row183216633165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p508482027165634"><a name="p508482027165634"></a><a name="p508482027165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1165946755165634"><a name="p1165946755165634"></a><a name="p1165946755165634"></a>void * </p>
<p id="p2067056144165634"><a name="p2067056144165634"></a><a name="p2067056144165634"></a>Overrides the <strong id="b334795195165634"><a name="b334795195165634"></a><a name="b334795195165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row942541949165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584847855165634"><a name="p1584847855165634"></a><a name="p1584847855165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1882097103165634"><a name="p1882097103165634"></a><a name="p1882097103165634"></a>void </p>
<p id="p1751896542165634"><a name="p1751896542165634"></a><a name="p1751896542165634"></a>Overrides the <strong id="b934346485165634"><a name="b934346485165634"></a><a name="b934346485165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

