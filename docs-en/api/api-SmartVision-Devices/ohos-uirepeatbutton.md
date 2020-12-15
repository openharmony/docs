# OHOS::UIRepeatButton<a name="EN-US_TOPIC_0000001055198156"></a>

-   [Overview](#section385405716165634)
-   [Summary](#section275248783165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section385405716165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents a repeat button. 

If a repeat button is clicked and hold, the click event is triggered continuously.

See also
:   [UIButton](ohos-uibutton.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section275248783165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table521706601165634"></a>
<table><thead align="left"><tr id="row956147613165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p291272698165634"><a name="p291272698165634"></a><a name="p291272698165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p742896341165634"><a name="p742896341165634"></a><a name="p742896341165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row804094033165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468691541165634"><a name="p1468691541165634"></a><a name="p1468691541165634"></a><a href="graphic.md#gac43cbe638a874231842ad80c23c00b0a">UIRepeatButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p158441255165634"><a name="p158441255165634"></a><a name="p158441255165634"></a> </p>
<p id="p231441934165634"><a name="p231441934165634"></a><a name="p231441934165634"></a>A constructor used to create a <strong id="b1735017105165634"><a name="b1735017105165634"></a><a name="b1735017105165634"></a><a href="ohos-uirepeatbutton.md">UIRepeatButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row879905576165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893349174165634"><a name="p893349174165634"></a><a name="p893349174165634"></a><a href="graphic.md#ga2e2a8bc2b9aa21899356dbad7a242900">~UIRepeatButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1765116518165634"><a name="p1765116518165634"></a><a name="p1765116518165634"></a>virtual </p>
<p id="p2082029224165634"><a name="p2082029224165634"></a><a name="p2082029224165634"></a>A destructor used to delete the <strong id="b97129136165634"><a name="b97129136165634"></a><a name="b97129136165634"></a><a href="ohos-uirepeatbutton.md">UIRepeatButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1533502141165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577002007165634"><a name="p577002007165634"></a><a name="p577002007165634"></a><a href="graphic.md#gac391336aedd68659b7f76bee59eba521">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1918109765165634"><a name="p1918109765165634"></a><a name="p1918109765165634"></a>UIViewType </p>
<p id="p1289547599165634"><a name="p1289547599165634"></a><a name="p1289547599165634"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row1934085770165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756954845165634"><a name="p1756954845165634"></a><a name="p1756954845165634"></a><a href="graphic.md#ga88637ae5acd7701ded0d0e88fb28227d">SetInterval</a> (uint16_t interval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p484259771165634"><a name="p484259771165634"></a><a name="p484259771165634"></a>virtual void </p>
<p id="p346102264165634"><a name="p346102264165634"></a><a name="p346102264165634"></a>Sets the interval between two consecutive click events. </p>
</td>
</tr>
<tr id="row1316407311165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12302770165634"><a name="p12302770165634"></a><a name="p12302770165634"></a><a href="graphic.md#gad772c84a309dbaa150b66f697e5b8ed8">GetInterval</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p879429292165634"><a name="p879429292165634"></a><a name="p879429292165634"></a>virtual uint16_t </p>
<p id="p1339698728165634"><a name="p1339698728165634"></a><a name="p1339698728165634"></a>Obtains the interval between two consecutive click events. </p>
</td>
</tr>
<tr id="row936468741165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118584891165634"><a name="p118584891165634"></a><a name="p118584891165634"></a><a href="graphic.md#gaca17d1cfa9daa35a88d387ebc1d9352c">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078555719165634"><a name="p1078555719165634"></a><a name="p1078555719165634"></a>virtual void </p>
<p id="p2067663281165634"><a name="p2067663281165634"></a><a name="p2067663281165634"></a>The action of click event. </p>
</td>
</tr>
<tr id="row2028555081165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p311534321165634"><a name="p311534321165634"></a><a name="p311534321165634"></a><a href="graphic.md#gadd5891c03d95d07d127558b5bc9a7bd7">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p82083497165634"><a name="p82083497165634"></a><a name="p82083497165634"></a>virtual void </p>
<p id="p1421891191165634"><a name="p1421891191165634"></a><a name="p1421891191165634"></a>The action of release event. </p>
</td>
</tr>
<tr id="row1785056701165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1666494669165634"><a name="p1666494669165634"></a><a name="p1666494669165634"></a><a href="graphic.md#ga33de0d99700bd1c289d967458477606f">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p614175664165634"><a name="p614175664165634"></a><a name="p614175664165634"></a>virtual bool </p>
<p id="p1362553485165634"><a name="p1362553485165634"></a><a name="p1362553485165634"></a>The action of long press event. </p>
</td>
</tr>
<tr id="row2053487917165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246654260165634"><a name="p1246654260165634"></a><a name="p1246654260165634"></a><a href="graphic.md#gaba3c785f0e636cd1ac1317b9d3fcf430">HandleTickEvent</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1906256522165634"><a name="p1906256522165634"></a><a name="p1906256522165634"></a> void </p>
<p id="p894660816165634"><a name="p894660816165634"></a><a name="p894660816165634"></a>handle the event of long pressing. </p>
</td>
</tr>
<tr id="row1208751199165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2096017154165634"><a name="p2096017154165634"></a><a name="p2096017154165634"></a><a href="graphic.md#ga3aee093d4c583223850a7ad80d5bed79">UIButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1472283106165634"><a name="p1472283106165634"></a><a name="p1472283106165634"></a> </p>
<p id="p1833534006165634"><a name="p1833534006165634"></a><a name="p1833534006165634"></a>A constructor used to create a <strong id="b703504039165634"><a name="b703504039165634"></a><a name="b703504039165634"></a><a href="ohos-uibutton.md">UIButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row220550578165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1728830497165634"><a name="p1728830497165634"></a><a name="p1728830497165634"></a><a href="graphic.md#ga33e30931e9b3557634b2b2be93bc41f6">UIButton</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1302186918165634"><a name="p1302186918165634"></a><a name="p1302186918165634"></a> </p>
<p id="p1436730114165634"><a name="p1436730114165634"></a><a name="p1436730114165634"></a>A constructor used to create a <strong id="b711903323165634"><a name="b711903323165634"></a><a name="b711903323165634"></a><a href="ohos-uibutton.md">UIButton</a></strong> instance based on the button ID. </p>
</td>
</tr>
<tr id="row1527466935165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1394007975165634"><a name="p1394007975165634"></a><a name="p1394007975165634"></a><a href="graphic.md#ga0c5fbcf319fc6df8170d407a337b9d8b">~UIButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455553186165634"><a name="p455553186165634"></a><a name="p455553186165634"></a>virtual </p>
<p id="p328870604165634"><a name="p328870604165634"></a><a name="p328870604165634"></a>A destructor used to delete the <strong id="b1420451736165634"><a name="b1420451736165634"></a><a name="b1420451736165634"></a><a href="ohos-uibutton.md">UIButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row442541144165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p747795637165634"><a name="p747795637165634"></a><a name="p747795637165634"></a><a href="graphic.md#gaf64d9ec1744ab9c7385dd64d30a786e4">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1341243739165634"><a name="p1341243739165634"></a><a name="p1341243739165634"></a>bool </p>
<p id="p474546956165634"><a name="p474546956165634"></a><a name="p474546956165634"></a>Do something before draw, this function will be invoked mainly to check if this view need to cover invalidate area so render manager can decide which layer to draw firstly. </p>
</td>
</tr>
<tr id="row1954855529165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p861977913165634"><a name="p861977913165634"></a><a name="p861977913165634"></a><a href="graphic.md#ga1d887720c89170abd3c8a400a791765d">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p974965847165634"><a name="p974965847165634"></a><a name="p974965847165634"></a>void </p>
<p id="p1130555386165634"><a name="p1130555386165634"></a><a name="p1130555386165634"></a>Executes the press event action. </p>
</td>
</tr>
<tr id="row1508878140165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p206255669165634"><a name="p206255669165634"></a><a name="p206255669165634"></a><a href="graphic.md#ga4f481e0ce91f87c6b70f6e0190e4f34f">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1014904683165634"><a name="p1014904683165634"></a><a name="p1014904683165634"></a>void </p>
<p id="p1097360381165634"><a name="p1097360381165634"></a><a name="p1097360381165634"></a>Executes the cancel event action. </p>
</td>
</tr>
<tr id="row314891891165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032392529165634"><a name="p1032392529165634"></a><a name="p1032392529165634"></a><a href="graphic.md#ga60194db1c1bba6a0ef963bdbbe9f972f">SetImageSrc</a> (const char *defaultImgSrc, const char *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806634768165634"><a name="p806634768165634"></a><a name="p806634768165634"></a>void </p>
<p id="p2074021298165634"><a name="p2074021298165634"></a><a name="p2074021298165634"></a>Sets the image for this button. </p>
</td>
</tr>
<tr id="row1661205080165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1733505795165634"><a name="p1733505795165634"></a><a name="p1733505795165634"></a><a href="graphic.md#gab751bc5941edb403022d65d2c605a241">SetImageSrc</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *defaultImgSrc, const <a href="ohos-imageinfo.md">ImageInfo</a> *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085002930165634"><a name="p1085002930165634"></a><a name="p1085002930165634"></a>void </p>
<p id="p1112412481165634"><a name="p1112412481165634"></a><a name="p1112412481165634"></a>Sets the image for this button. </p>
</td>
</tr>
<tr id="row115696867165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852971744165634"><a name="p1852971744165634"></a><a name="p1852971744165634"></a><a href="graphic.md#ga952fcbc88905cf35ec3e09bdf01375f2">SetImagePosition</a> (const int16_t x, const int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1585267288165634"><a name="p1585267288165634"></a><a name="p1585267288165634"></a>void </p>
<p id="p1599867470165634"><a name="p1599867470165634"></a><a name="p1599867470165634"></a>Sets the position for this image. </p>
</td>
</tr>
<tr id="row825577392165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578021980165634"><a name="p578021980165634"></a><a name="p578021980165634"></a><a href="graphic.md#ga4d8abf189ddcbf325c60402084d7e3c3">GetImageX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1996646489165634"><a name="p1996646489165634"></a><a name="p1996646489165634"></a>int16_t </p>
<p id="p1472230380165634"><a name="p1472230380165634"></a><a name="p1472230380165634"></a>Obtains the x-coordinate of this image. </p>
</td>
</tr>
<tr id="row1112690809165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p151982743165634"><a name="p151982743165634"></a><a name="p151982743165634"></a><a href="graphic.md#ga25a02afb52cc15212084fb6bc8f27afd">GetImageY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p452555471165634"><a name="p452555471165634"></a><a name="p452555471165634"></a>int16_t </p>
<p id="p1288607069165634"><a name="p1288607069165634"></a><a name="p1288607069165634"></a>Obtains the y-coordinate of this image. </p>
</td>
</tr>
<tr id="row1873863910165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228656263165634"><a name="p228656263165634"></a><a name="p228656263165634"></a><a href="graphic.md#gaf6496e4858473ab2acb80a2be6264a01">GetCurImageSrc</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629649767165634"><a name="p629649767165634"></a><a name="p629649767165634"></a>const <a href="ohos-image.md">Image</a> * </p>
<p id="p672144748165634"><a name="p672144748165634"></a><a name="p672144748165634"></a>Obtains the image for the current button state. </p>
</td>
</tr>
<tr id="row2022676544165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1165803123165634"><a name="p1165803123165634"></a><a name="p1165803123165634"></a><a href="graphic.md#ga8cb74b23f740091e59ad350a8dea436b">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p71275739165634"><a name="p71275739165634"></a><a name="p71275739165634"></a>int16_t </p>
<p id="p1007313584165634"><a name="p1007313584165634"></a><a name="p1007313584165634"></a>Obtains the width of this image. </p>
</td>
</tr>
<tr id="row560030056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051563606165634"><a name="p2051563606165634"></a><a name="p2051563606165634"></a><a href="graphic.md#ga1f8015706cfc73728696bf2bbd3e833b">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p275212275165634"><a name="p275212275165634"></a><a name="p275212275165634"></a>int16_t </p>
<p id="p1730001438165634"><a name="p1730001438165634"></a><a name="p1730001438165634"></a>Obtains the height of this image. </p>
</td>
</tr>
<tr id="row1114987009165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1280892379165634"><a name="p1280892379165634"></a><a name="p1280892379165634"></a><a href="graphic.md#ga420f927c473cec8c6f3265ff7c35336f">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1350762958165634"><a name="p1350762958165634"></a><a name="p1350762958165634"></a>void </p>
<p id="p1627831829165634"><a name="p1627831829165634"></a><a name="p1627831829165634"></a>Sets the width for this image. </p>
</td>
</tr>
<tr id="row1827476602165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1791963793165634"><a name="p1791963793165634"></a><a name="p1791963793165634"></a><a href="graphic.md#ga8b6dbfcd0328753c2c3cef4d14b0ff30">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936132782165634"><a name="p1936132782165634"></a><a name="p1936132782165634"></a>void </p>
<p id="p406915328165634"><a name="p406915328165634"></a><a name="p406915328165634"></a>Sets the height for this image. </p>
</td>
</tr>
<tr id="row25448005165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668080170165634"><a name="p668080170165634"></a><a name="p668080170165634"></a><a href="graphic.md#ga93994f4d735e4f9a7d3e7d737e2c620c">GetContentRect</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614725667165634"><a name="p1614725667165634"></a><a name="p1614725667165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p1952864971165634"><a name="p1952864971165634"></a><a name="p1952864971165634"></a>Obtains a rectangular area that contains coordinate information. </p>
</td>
</tr>
<tr id="row367886357165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p94513306165634"><a name="p94513306165634"></a><a name="p94513306165634"></a><a href="graphic.md#ga37736a82bec6a01bc5a880e1d01ccccd">GetStyle</a> (uint8_t key) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1714979022165634"><a name="p1714979022165634"></a><a name="p1714979022165634"></a>int64_t </p>
<p id="p353346076165634"><a name="p353346076165634"></a><a name="p353346076165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row391951830165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805759154165634"><a name="p805759154165634"></a><a name="p805759154165634"></a><a href="graphic.md#gaa5fdd9b28b8c919dbde0e34d8ae38caf">SetStyle</a> (uint8_t key, int64_t value) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972125868165634"><a name="p1972125868165634"></a><a name="p1972125868165634"></a>void </p>
<p id="p1025899508165634"><a name="p1025899508165634"></a><a name="p1025899508165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1648571419165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657025234165634"><a name="p657025234165634"></a><a name="p657025234165634"></a><a href="graphic.md#gaa3f74af93c91a24e58fdd06ad7d0bdf9">GetStyleForState</a> (uint8_t key, <a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497195208165634"><a name="p1497195208165634"></a><a name="p1497195208165634"></a>int64_t </p>
<p id="p1461738582165634"><a name="p1461738582165634"></a><a name="p1461738582165634"></a>Obtains the style of a button in a specific state. </p>
</td>
</tr>
<tr id="row2129516637165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786330398165634"><a name="p786330398165634"></a><a name="p786330398165634"></a><a href="graphic.md#ga7ece04980fa99a277bfbb591771f47f1">SetStyleForState</a> (uint8_t key, int64_t value, <a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399995333165634"><a name="p1399995333165634"></a><a name="p1399995333165634"></a>void </p>
<p id="p401230589165634"><a name="p401230589165634"></a><a name="p401230589165634"></a>Sets the style for a button in a specific state. </p>
</td>
</tr>
<tr id="row9160496165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p926370542165634"><a name="p926370542165634"></a><a name="p926370542165634"></a><a href="graphic.md#ga283131701e907e586964189818d04411">Disable</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p802381868165634"><a name="p802381868165634"></a><a name="p802381868165634"></a>void </p>
<p id="p1666737788165634"><a name="p1666737788165634"></a><a name="p1666737788165634"></a>Disables this button. </p>
</td>
</tr>
<tr id="row1865777861165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1299908617165634"><a name="p1299908617165634"></a><a name="p1299908617165634"></a><a href="graphic.md#ga3185df8b60a609564f978ed9576fb813">Enable</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p312189063165634"><a name="p312189063165634"></a><a name="p312189063165634"></a>void </p>
<p id="p972503064165634"><a name="p972503064165634"></a><a name="p972503064165634"></a>Enables this button. </p>
</td>
</tr>
<tr id="row1592021006165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p850089029165634"><a name="p850089029165634"></a><a name="p850089029165634"></a><a href="graphic.md#ga737d850b2adf8a2977369e611764b1ae">SetStateForStyle</a> (<a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p509587676165634"><a name="p509587676165634"></a><a name="p509587676165634"></a>void </p>
<p id="p1201185147165634"><a name="p1201185147165634"></a><a name="p1201185147165634"></a>Sets the state for a button. After the setting, calling <a href="graphic.md#gaa5fdd9b28b8c919dbde0e34d8ae38caf">SetStyle</a> will change the style of this button, but not its state. </p>
</td>
</tr>
<tr id="row199511863165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726560845165634"><a name="p1726560845165634"></a><a name="p1726560845165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p29961854165634"><a name="p29961854165634"></a><a name="p29961854165634"></a> </p>
<p id="p678842506165634"><a name="p678842506165634"></a><a name="p678842506165634"></a>A default constructor used to create an <strong id="b912662643165634"><a name="b912662643165634"></a><a name="b912662643165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row444730714165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1207437519165634"><a name="p1207437519165634"></a><a name="p1207437519165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938729536165634"><a name="p938729536165634"></a><a name="p938729536165634"></a> </p>
<p id="p1114558788165634"><a name="p1114558788165634"></a><a name="p1114558788165634"></a>A constructor used to create an <strong id="b1201474613165634"><a name="b1201474613165634"></a><a name="b1201474613165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1829507029165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501327673165634"><a name="p1501327673165634"></a><a name="p1501327673165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1171939859165634"><a name="p1171939859165634"></a><a name="p1171939859165634"></a>virtual </p>
<p id="p634082538165634"><a name="p634082538165634"></a><a name="p634082538165634"></a>A destructor used to delete the <strong id="b509794441165634"><a name="b509794441165634"></a><a name="b509794441165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2092442893165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p410786482165634"><a name="p410786482165634"></a><a name="p410786482165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p360116141165634"><a name="p360116141165634"></a><a name="p360116141165634"></a>virtual void </p>
<p id="p1326501673165634"><a name="p1326501673165634"></a><a name="p1326501673165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1565364995165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498321532165634"><a name="p498321532165634"></a><a name="p498321532165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194310875165634"><a name="p194310875165634"></a><a name="p194310875165634"></a>virtual void </p>
<p id="p538906047165634"><a name="p538906047165634"></a><a name="p538906047165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row525897361165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1234657910165634"><a name="p1234657910165634"></a><a name="p1234657910165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1776491690165634"><a name="p1776491690165634"></a><a name="p1776491690165634"></a>void </p>
<p id="p1325054186165634"><a name="p1325054186165634"></a><a name="p1325054186165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1267561951165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p922653578165634"><a name="p922653578165634"></a><a name="p922653578165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151355532165634"><a name="p151355532165634"></a><a name="p151355532165634"></a>void </p>
<p id="p1933267415165634"><a name="p1933267415165634"></a><a name="p1933267415165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row774004853165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1980525786165634"><a name="p1980525786165634"></a><a name="p1980525786165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p78883807165634"><a name="p78883807165634"></a><a name="p78883807165634"></a>virtual bool </p>
<p id="p1397848755165634"><a name="p1397848755165634"></a><a name="p1397848755165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1781081175165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p605826062165634"><a name="p605826062165634"></a><a name="p605826062165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141058536165634"><a name="p1141058536165634"></a><a name="p1141058536165634"></a>virtual bool </p>
<p id="p1266991697165634"><a name="p1266991697165634"></a><a name="p1266991697165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1368178031165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1469502694165634"><a name="p1469502694165634"></a><a name="p1469502694165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154022254165634"><a name="p1154022254165634"></a><a name="p1154022254165634"></a>virtual bool </p>
<p id="p1548683474165634"><a name="p1548683474165634"></a><a name="p1548683474165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1340400661165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1602348550165634"><a name="p1602348550165634"></a><a name="p1602348550165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1201649586165634"><a name="p1201649586165634"></a><a name="p1201649586165634"></a>void </p>
<p id="p1092721694165634"><a name="p1092721694165634"></a><a name="p1092721694165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row272057401165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139143211165634"><a name="p1139143211165634"></a><a name="p1139143211165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768974180165634"><a name="p1768974180165634"></a><a name="p1768974180165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p579327166165634"><a name="p579327166165634"></a><a name="p579327166165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1087386231165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782965149165634"><a name="p782965149165634"></a><a name="p782965149165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1437837350165634"><a name="p1437837350165634"></a><a name="p1437837350165634"></a>void </p>
<p id="p163521835165634"><a name="p163521835165634"></a><a name="p163521835165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row296668077165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1416380307165634"><a name="p1416380307165634"></a><a name="p1416380307165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p173915234165634"><a name="p173915234165634"></a><a name="p173915234165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p176538644165634"><a name="p176538644165634"></a><a name="p176538644165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row632617696165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p890433919165634"><a name="p890433919165634"></a><a name="p890433919165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p907029711165634"><a name="p907029711165634"></a><a name="p907029711165634"></a>void </p>
<p id="p458361357165634"><a name="p458361357165634"></a><a name="p458361357165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2136745630165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751942103165634"><a name="p1751942103165634"></a><a name="p1751942103165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p275391280165634"><a name="p275391280165634"></a><a name="p275391280165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p412646881165634"><a name="p412646881165634"></a><a name="p412646881165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1329202330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800407268165634"><a name="p800407268165634"></a><a name="p800407268165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1069803053165634"><a name="p1069803053165634"></a><a name="p1069803053165634"></a>void </p>
<p id="p717066571165634"><a name="p717066571165634"></a><a name="p717066571165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1173419964165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1547652989165634"><a name="p1547652989165634"></a><a name="p1547652989165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p131661244165634"><a name="p131661244165634"></a><a name="p131661244165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p990599176165634"><a name="p990599176165634"></a><a name="p990599176165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1383982462165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p102026224165634"><a name="p102026224165634"></a><a name="p102026224165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p152312191165634"><a name="p152312191165634"></a><a name="p152312191165634"></a>virtual void </p>
<p id="p859577398165634"><a name="p859577398165634"></a><a name="p859577398165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1499536255165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782473213165634"><a name="p782473213165634"></a><a name="p782473213165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1552566649165634"><a name="p1552566649165634"></a><a name="p1552566649165634"></a>void </p>
<p id="p865867363165634"><a name="p865867363165634"></a><a name="p865867363165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1566011967165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1801578257165634"><a name="p1801578257165634"></a><a name="p1801578257165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p632261097165634"><a name="p632261097165634"></a><a name="p632261097165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p500756339165634"><a name="p500756339165634"></a><a name="p500756339165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row329331278165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p63292960165634"><a name="p63292960165634"></a><a name="p63292960165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021868502165634"><a name="p2021868502165634"></a><a name="p2021868502165634"></a>void </p>
<p id="p1157120358165634"><a name="p1157120358165634"></a><a name="p1157120358165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1326548604165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1463775877165634"><a name="p1463775877165634"></a><a name="p1463775877165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223789532165634"><a name="p1223789532165634"></a><a name="p1223789532165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p2049416783165634"><a name="p2049416783165634"></a><a name="p2049416783165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row247682261165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p346659991165634"><a name="p346659991165634"></a><a name="p346659991165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1543421378165634"><a name="p1543421378165634"></a><a name="p1543421378165634"></a>virtual void </p>
<p id="p1869748931165634"><a name="p1869748931165634"></a><a name="p1869748931165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1357257069165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1378864445165634"><a name="p1378864445165634"></a><a name="p1378864445165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405443726165634"><a name="p1405443726165634"></a><a name="p1405443726165634"></a>bool </p>
<p id="p449332638165634"><a name="p449332638165634"></a><a name="p449332638165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row665912960165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1113321667165634"><a name="p1113321667165634"></a><a name="p1113321667165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p168849234165634"><a name="p168849234165634"></a><a name="p168849234165634"></a>void </p>
<p id="p45580752165634"><a name="p45580752165634"></a><a name="p45580752165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row802147314165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p99160803165634"><a name="p99160803165634"></a><a name="p99160803165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2111097540165634"><a name="p2111097540165634"></a><a name="p2111097540165634"></a>bool </p>
<p id="p1696468328165634"><a name="p1696468328165634"></a><a name="p1696468328165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1101713403165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1681287533165634"><a name="p1681287533165634"></a><a name="p1681287533165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833036830165634"><a name="p833036830165634"></a><a name="p833036830165634"></a>void </p>
<p id="p94143261165634"><a name="p94143261165634"></a><a name="p94143261165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1829911905165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1381530816165634"><a name="p1381530816165634"></a><a name="p1381530816165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628701638165634"><a name="p1628701638165634"></a><a name="p1628701638165634"></a>bool </p>
<p id="p1513402763165634"><a name="p1513402763165634"></a><a name="p1513402763165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row322186737165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1927461742165634"><a name="p1927461742165634"></a><a name="p1927461742165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491831106165634"><a name="p1491831106165634"></a><a name="p1491831106165634"></a>void </p>
<p id="p674748965165634"><a name="p674748965165634"></a><a name="p674748965165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1176529384165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p890423462165634"><a name="p890423462165634"></a><a name="p890423462165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967095432165634"><a name="p1967095432165634"></a><a name="p1967095432165634"></a>bool </p>
<p id="p2015889605165634"><a name="p2015889605165634"></a><a name="p2015889605165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row290162592165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821394242165634"><a name="p1821394242165634"></a><a name="p1821394242165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724284139165634"><a name="p724284139165634"></a><a name="p724284139165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1788827753165634"><a name="p1788827753165634"></a><a name="p1788827753165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1369133122165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977167189165634"><a name="p1977167189165634"></a><a name="p1977167189165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580465043165634"><a name="p1580465043165634"></a><a name="p1580465043165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p278531872165634"><a name="p278531872165634"></a><a name="p278531872165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row269771017165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p632934872165634"><a name="p632934872165634"></a><a name="p632934872165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590779606165634"><a name="p590779606165634"></a><a name="p590779606165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p827515590165634"><a name="p827515590165634"></a><a name="p827515590165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1151608237165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846035196165634"><a name="p1846035196165634"></a><a name="p1846035196165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p853457916165634"><a name="p853457916165634"></a><a name="p853457916165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1386572408165634"><a name="p1386572408165634"></a><a name="p1386572408165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row705999964165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600598872165634"><a name="p1600598872165634"></a><a name="p1600598872165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68371476165634"><a name="p68371476165634"></a><a name="p68371476165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p2134571051165634"><a name="p2134571051165634"></a><a name="p2134571051165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1563927023165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p758415996165634"><a name="p758415996165634"></a><a name="p758415996165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1114743663165634"><a name="p1114743663165634"></a><a name="p1114743663165634"></a>void </p>
<p id="p1211531306165634"><a name="p1211531306165634"></a><a name="p1211531306165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row474421806165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74543168165634"><a name="p74543168165634"></a><a name="p74543168165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399718532165634"><a name="p1399718532165634"></a><a name="p1399718532165634"></a>virtual void </p>
<p id="p1670498982165634"><a name="p1670498982165634"></a><a name="p1670498982165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1048291838165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379437145165634"><a name="p379437145165634"></a><a name="p379437145165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1358104271165634"><a name="p1358104271165634"></a><a name="p1358104271165634"></a>virtual void </p>
<p id="p312334781165634"><a name="p312334781165634"></a><a name="p312334781165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row263738488165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p149227655165634"><a name="p149227655165634"></a><a name="p149227655165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579190598165634"><a name="p1579190598165634"></a><a name="p1579190598165634"></a>int16_t </p>
<p id="p893354183165634"><a name="p893354183165634"></a><a name="p893354183165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1026447213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1577789094165634"><a name="p1577789094165634"></a><a name="p1577789094165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p697941277165634"><a name="p697941277165634"></a><a name="p697941277165634"></a>virtual void </p>
<p id="p557236917165634"><a name="p557236917165634"></a><a name="p557236917165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2131665873165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p830041168165634"><a name="p830041168165634"></a><a name="p830041168165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p730302596165634"><a name="p730302596165634"></a><a name="p730302596165634"></a>int16_t </p>
<p id="p650911898165634"><a name="p650911898165634"></a><a name="p650911898165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1884805753165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865849531165634"><a name="p1865849531165634"></a><a name="p1865849531165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1743854697165634"><a name="p1743854697165634"></a><a name="p1743854697165634"></a>virtual void </p>
<p id="p306143032165634"><a name="p306143032165634"></a><a name="p306143032165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row246312379165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1060337738165634"><a name="p1060337738165634"></a><a name="p1060337738165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229686266165634"><a name="p1229686266165634"></a><a name="p1229686266165634"></a>virtual void </p>
<p id="p723392434165634"><a name="p723392434165634"></a><a name="p723392434165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row831755383165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1345761877165634"><a name="p1345761877165634"></a><a name="p1345761877165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304576296165634"><a name="p1304576296165634"></a><a name="p1304576296165634"></a>bool </p>
<p id="p2071672276165634"><a name="p2071672276165634"></a><a name="p2071672276165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row614270066165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p448166901165634"><a name="p448166901165634"></a><a name="p448166901165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339785135165634"><a name="p1339785135165634"></a><a name="p1339785135165634"></a>void </p>
<p id="p1433719568165634"><a name="p1433719568165634"></a><a name="p1433719568165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row506367213165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1408477563165634"><a name="p1408477563165634"></a><a name="p1408477563165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722572282165634"><a name="p722572282165634"></a><a name="p722572282165634"></a>void </p>
<p id="p1252957457165634"><a name="p1252957457165634"></a><a name="p1252957457165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1331538028165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p357981265165634"><a name="p357981265165634"></a><a name="p357981265165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550475890165634"><a name="p550475890165634"></a><a name="p550475890165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p372966049165634"><a name="p372966049165634"></a><a name="p372966049165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1248624378165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p426155327165634"><a name="p426155327165634"></a><a name="p426155327165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053777207165634"><a name="p1053777207165634"></a><a name="p1053777207165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p569932449165634"><a name="p569932449165634"></a><a name="p569932449165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row202808822165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811009776165634"><a name="p1811009776165634"></a><a name="p1811009776165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036368577165634"><a name="p1036368577165634"></a><a name="p1036368577165634"></a>void </p>
<p id="p1539628938165634"><a name="p1539628938165634"></a><a name="p1539628938165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row323962835165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1128493771165634"><a name="p1128493771165634"></a><a name="p1128493771165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421077629165634"><a name="p1421077629165634"></a><a name="p1421077629165634"></a>const char * </p>
<p id="p700127428165634"><a name="p700127428165634"></a><a name="p700127428165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1319984759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559465786165634"><a name="p559465786165634"></a><a name="p559465786165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p40673718165634"><a name="p40673718165634"></a><a name="p40673718165634"></a>void </p>
<p id="p487566981165634"><a name="p487566981165634"></a><a name="p487566981165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row187695814165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p401540780165634"><a name="p401540780165634"></a><a name="p401540780165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025928067165634"><a name="p2025928067165634"></a><a name="p2025928067165634"></a>int16_t </p>
<p id="p1572139583165634"><a name="p1572139583165634"></a><a name="p1572139583165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row743452681165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p965002046165634"><a name="p965002046165634"></a><a name="p965002046165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555183268165634"><a name="p1555183268165634"></a><a name="p1555183268165634"></a>virtual void </p>
<p id="p1688528700165634"><a name="p1688528700165634"></a><a name="p1688528700165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row784880994165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1673377399165634"><a name="p1673377399165634"></a><a name="p1673377399165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p41146130165634"><a name="p41146130165634"></a><a name="p41146130165634"></a>void </p>
<p id="p2074588966165634"><a name="p2074588966165634"></a><a name="p2074588966165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1312333849165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2101690649165634"><a name="p2101690649165634"></a><a name="p2101690649165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3691255165634"><a name="p3691255165634"></a><a name="p3691255165634"></a>void </p>
<p id="p1712556360165634"><a name="p1712556360165634"></a><a name="p1712556360165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row218352254165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1946083552165634"><a name="p1946083552165634"></a><a name="p1946083552165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187605794165634"><a name="p187605794165634"></a><a name="p187605794165634"></a>void </p>
<p id="p1119519874165634"><a name="p1119519874165634"></a><a name="p1119519874165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row661405015165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705474844165634"><a name="p705474844165634"></a><a name="p705474844165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163746580165634"><a name="p1163746580165634"></a><a name="p1163746580165634"></a>void </p>
<p id="p277541344165634"><a name="p277541344165634"></a><a name="p277541344165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row915751645165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141160769165634"><a name="p141160769165634"></a><a name="p141160769165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p809828079165634"><a name="p809828079165634"></a><a name="p809828079165634"></a>void </p>
<p id="p1759518958165634"><a name="p1759518958165634"></a><a name="p1759518958165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row816173823165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879616009165634"><a name="p879616009165634"></a><a name="p879616009165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135354607165634"><a name="p2135354607165634"></a><a name="p2135354607165634"></a>void </p>
<p id="p417271368165634"><a name="p417271368165634"></a><a name="p417271368165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1171517200165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247834262165634"><a name="p247834262165634"></a><a name="p247834262165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572703210165634"><a name="p572703210165634"></a><a name="p572703210165634"></a>void </p>
<p id="p1048832456165634"><a name="p1048832456165634"></a><a name="p1048832456165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1342732395165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1090852080165634"><a name="p1090852080165634"></a><a name="p1090852080165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96641468165634"><a name="p96641468165634"></a><a name="p96641468165634"></a>void </p>
<p id="p441144352165634"><a name="p441144352165634"></a><a name="p441144352165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row251019530165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2008557618165634"><a name="p2008557618165634"></a><a name="p2008557618165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p672067902165634"><a name="p672067902165634"></a><a name="p672067902165634"></a>void </p>
<p id="p706446230165634"><a name="p706446230165634"></a><a name="p706446230165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row918591166165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p474660775165634"><a name="p474660775165634"></a><a name="p474660775165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2065772968165634"><a name="p2065772968165634"></a><a name="p2065772968165634"></a>void </p>
<p id="p887987372165634"><a name="p887987372165634"></a><a name="p887987372165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row945726759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p561314687165634"><a name="p561314687165634"></a><a name="p561314687165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p286977140165634"><a name="p286977140165634"></a><a name="p286977140165634"></a>void </p>
<p id="p597079109165634"><a name="p597079109165634"></a><a name="p597079109165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1828810597165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17486258165634"><a name="p17486258165634"></a><a name="p17486258165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1163751252165634"><a name="p1163751252165634"></a><a name="p1163751252165634"></a>void </p>
<p id="p384327337165634"><a name="p384327337165634"></a><a name="p384327337165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1158123094165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072769520165634"><a name="p1072769520165634"></a><a name="p1072769520165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p841657528165634"><a name="p841657528165634"></a><a name="p841657528165634"></a>void </p>
<p id="p1159383926165634"><a name="p1159383926165634"></a><a name="p1159383926165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1218848296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1946618325165634"><a name="p1946618325165634"></a><a name="p1946618325165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1218201595165634"><a name="p1218201595165634"></a><a name="p1218201595165634"></a>void </p>
<p id="p308981944165634"><a name="p308981944165634"></a><a name="p308981944165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row388891771165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110774644165634"><a name="p2110774644165634"></a><a name="p2110774644165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804598389165634"><a name="p1804598389165634"></a><a name="p1804598389165634"></a>void </p>
<p id="p737187255165634"><a name="p737187255165634"></a><a name="p737187255165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row17525402165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1521133568165634"><a name="p1521133568165634"></a><a name="p1521133568165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p253945041165634"><a name="p253945041165634"></a><a name="p253945041165634"></a>void </p>
<p id="p231331439165634"><a name="p231331439165634"></a><a name="p231331439165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1242298891165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p571802158165634"><a name="p571802158165634"></a><a name="p571802158165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197418035165634"><a name="p1197418035165634"></a><a name="p1197418035165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1953611583165634"><a name="p1953611583165634"></a><a name="p1953611583165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1291781863165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p869282948165634"><a name="p869282948165634"></a><a name="p869282948165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1078852634165634"><a name="p1078852634165634"></a><a name="p1078852634165634"></a>void * </p>
<p id="p230996500165634"><a name="p230996500165634"></a><a name="p230996500165634"></a>Overrides the <strong id="b257052574165634"><a name="b257052574165634"></a><a name="b257052574165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1020040007165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p163384449165634"><a name="p163384449165634"></a><a name="p163384449165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774384467165634"><a name="p774384467165634"></a><a name="p774384467165634"></a>void </p>
<p id="p988582173165634"><a name="p988582173165634"></a><a name="p988582173165634"></a>Overrides the <strong id="b1859635052165634"><a name="b1859635052165634"></a><a name="b1859635052165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table667728142165634"></a>
<table><thead align="left"><tr id="row628385549165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1231348930165634"><a name="p1231348930165634"></a><a name="p1231348930165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1408347561165634"><a name="p1408347561165634"></a><a name="p1408347561165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1762464652165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1648900848165634"><a name="p1648900848165634"></a><a name="p1648900848165634"></a><a href="graphic.md#gaf9f6c0c373f090e79b9e8d847e186e92">ButtonImageSrc</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343617929165634"><a name="p1343617929165634"></a><a name="p1343617929165634"></a>Enumerates the images for different button states. </p>
</td>
</tr>
<tr id="row2084266410165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374957635165634"><a name="p374957635165634"></a><a name="p374957635165634"></a><a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2101785773165634"><a name="p2101785773165634"></a><a name="p2101785773165634"></a>Enumerates the states of this button. </p>
</td>
</tr>
</tbody>
</table>

