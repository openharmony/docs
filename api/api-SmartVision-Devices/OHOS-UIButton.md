# OHOS::UIButton<a name="ZH-CN_TOPIC_0000001055358130"></a>

-   [Overview](#section1989894275165634)
-   [Summary](#section566843452165634)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1989894275165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a button. 

This component responds to the press and release events.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section566843452165634"></a>

## Public Types<a name="pub-types"></a>

<a name="table983126626165634"></a>
<table><thead align="left"><tr id="row328835550165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1681473969165634"><a name="p1681473969165634"></a><a name="p1681473969165634"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p572745364165634"><a name="p572745364165634"></a><a name="p572745364165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row472684329165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703336489165634"><a name="p1703336489165634"></a><a name="p1703336489165634"></a><a href="Graphic.md#gaf9f6c0c373f090e79b9e8d847e186e92">ButtonImageSrc</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528636653165634"><a name="p528636653165634"></a><a name="p528636653165634"></a>Enumerates the images for different button states. </p>
</td>
</tr>
<tr id="row2026315239165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1950374748165634"><a name="p1950374748165634"></a><a name="p1950374748165634"></a><a href="Graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416672759165634"><a name="p416672759165634"></a><a name="p416672759165634"></a>Enumerates the states of this button. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1250134445165634"></a>
<table><thead align="left"><tr id="row794146411165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1214403941165634"><a name="p1214403941165634"></a><a name="p1214403941165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1244631434165634"><a name="p1244631434165634"></a><a name="p1244631434165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row847214876165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1967215558165634"><a name="p1967215558165634"></a><a name="p1967215558165634"></a><a href="Graphic.md#ga3aee093d4c583223850a7ad80d5bed79">UIButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p53665969165634"><a name="p53665969165634"></a><a name="p53665969165634"></a> </p>
<p id="p1708216388165634"><a name="p1708216388165634"></a><a name="p1708216388165634"></a>A constructor used to create a <strong id="b1351048104165634"><a name="b1351048104165634"></a><a name="b1351048104165634"></a><a href="OHOS-UIButton.md">UIButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row518383940165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p271709914165634"><a name="p271709914165634"></a><a name="p271709914165634"></a><a href="Graphic.md#ga33e30931e9b3557634b2b2be93bc41f6">UIButton</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143754285165634"><a name="p143754285165634"></a><a name="p143754285165634"></a> </p>
<p id="p43063585165634"><a name="p43063585165634"></a><a name="p43063585165634"></a>A constructor used to create a <strong id="b792183907165634"><a name="b792183907165634"></a><a name="b792183907165634"></a><a href="OHOS-UIButton.md">UIButton</a></strong> instance based on the button ID. </p>
</td>
</tr>
<tr id="row1730044807165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136406496165634"><a name="p2136406496165634"></a><a name="p2136406496165634"></a><a href="Graphic.md#ga0c5fbcf319fc6df8170d407a337b9d8b">~UIButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645618198165634"><a name="p645618198165634"></a><a name="p645618198165634"></a>virtual </p>
<p id="p2096419120165634"><a name="p2096419120165634"></a><a name="p2096419120165634"></a>A destructor used to delete the <strong id="b642486757165634"><a name="b642486757165634"></a><a name="b642486757165634"></a><a href="OHOS-UIButton.md">UIButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1773905703165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p174715536165634"><a name="p174715536165634"></a><a name="p174715536165634"></a><a href="Graphic.md#gad19f55fb0de64f3f39485292d0629dc7">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73864523165634"><a name="p73864523165634"></a><a name="p73864523165634"></a>UIViewType </p>
<p id="p1350581197165634"><a name="p1350581197165634"></a><a name="p1350581197165634"></a>Obtains the component type. </p>
</td>
</tr>
<tr id="row56288621165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026988690165634"><a name="p2026988690165634"></a><a name="p2026988690165634"></a><a href="Graphic.md#gaf64d9ec1744ab9c7385dd64d30a786e4">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1667145763165634"><a name="p1667145763165634"></a><a name="p1667145763165634"></a>bool </p>
<p id="p359684795165634"><a name="p359684795165634"></a><a name="p359684795165634"></a>Do something before draw, this function will be invoked mainly to check if this view need to cover invalidate area so render manager can decide which layer to draw firstly. </p>
</td>
</tr>
<tr id="row463610212165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1157337769165634"><a name="p1157337769165634"></a><a name="p1157337769165634"></a><a href="Graphic.md#gae69843b87be9fcdab3e4ac776547f3bc">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1965444406165634"><a name="p1965444406165634"></a><a name="p1965444406165634"></a>void </p>
<p id="p573975768165634"><a name="p573975768165634"></a><a name="p573975768165634"></a>Executes the draw action. </p>
</td>
</tr>
<tr id="row1587497973165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p805498808165634"><a name="p805498808165634"></a><a name="p805498808165634"></a><a href="Graphic.md#ga1d887720c89170abd3c8a400a791765d">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115961332165634"><a name="p1115961332165634"></a><a name="p1115961332165634"></a>void </p>
<p id="p1593632246165634"><a name="p1593632246165634"></a><a name="p1593632246165634"></a>Executes the press event action. </p>
</td>
</tr>
<tr id="row507861230165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682320394165634"><a name="p1682320394165634"></a><a name="p1682320394165634"></a><a href="Graphic.md#gadb9492eb82ff23f91f9263fc748f24de">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223988849165634"><a name="p1223988849165634"></a><a name="p1223988849165634"></a>void </p>
<p id="p595229646165634"><a name="p595229646165634"></a><a name="p595229646165634"></a>Executes the press release event action. </p>
</td>
</tr>
<tr id="row184313463165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1390135516165634"><a name="p1390135516165634"></a><a name="p1390135516165634"></a><a href="Graphic.md#ga4f481e0ce91f87c6b70f6e0190e4f34f">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1561905367165634"><a name="p1561905367165634"></a><a name="p1561905367165634"></a>void </p>
<p id="p1573020002165634"><a name="p1573020002165634"></a><a name="p1573020002165634"></a>Executes the cancel event action. </p>
</td>
</tr>
<tr id="row37156949165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158396534165634"><a name="p158396534165634"></a><a name="p158396534165634"></a><a href="Graphic.md#ga60194db1c1bba6a0ef963bdbbe9f972f">SetImageSrc</a> (const char *defaultImgSrc, const char *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p304452678165634"><a name="p304452678165634"></a><a name="p304452678165634"></a>void </p>
<p id="p407305705165634"><a name="p407305705165634"></a><a name="p407305705165634"></a>Sets the image for this button. </p>
</td>
</tr>
<tr id="row758636356165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p186998127165634"><a name="p186998127165634"></a><a name="p186998127165634"></a><a href="Graphic.md#gab751bc5941edb403022d65d2c605a241">SetImageSrc</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *defaultImgSrc, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1244527381165634"><a name="p1244527381165634"></a><a name="p1244527381165634"></a>void </p>
<p id="p844072100165634"><a name="p844072100165634"></a><a name="p844072100165634"></a>Sets the image for this button. </p>
</td>
</tr>
<tr id="row1754590019165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846417756165634"><a name="p1846417756165634"></a><a name="p1846417756165634"></a><a href="Graphic.md#ga952fcbc88905cf35ec3e09bdf01375f2">SetImagePosition</a> (const int16_t x, const int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559324501165634"><a name="p559324501165634"></a><a name="p559324501165634"></a>void </p>
<p id="p1715693001165634"><a name="p1715693001165634"></a><a name="p1715693001165634"></a>Sets the position for this image. </p>
</td>
</tr>
<tr id="row979336648165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p382428783165634"><a name="p382428783165634"></a><a name="p382428783165634"></a><a href="Graphic.md#ga4d8abf189ddcbf325c60402084d7e3c3">GetImageX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145748998165634"><a name="p1145748998165634"></a><a name="p1145748998165634"></a>int16_t </p>
<p id="p1137581353165634"><a name="p1137581353165634"></a><a name="p1137581353165634"></a>Obtains the x-coordinate of this image. </p>
</td>
</tr>
<tr id="row103957301165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1155343397165634"><a name="p1155343397165634"></a><a name="p1155343397165634"></a><a href="Graphic.md#ga25a02afb52cc15212084fb6bc8f27afd">GetImageY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p335592976165634"><a name="p335592976165634"></a><a name="p335592976165634"></a>int16_t </p>
<p id="p589934880165634"><a name="p589934880165634"></a><a name="p589934880165634"></a>Obtains the y-coordinate of this image. </p>
</td>
</tr>
<tr id="row1166303367165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1810153014165634"><a name="p1810153014165634"></a><a name="p1810153014165634"></a><a href="Graphic.md#gaf6496e4858473ab2acb80a2be6264a01">GetCurImageSrc</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p859415982165634"><a name="p859415982165634"></a><a name="p859415982165634"></a>const <a href="OHOS-Image.md">Image</a> * </p>
<p id="p1219611524165634"><a name="p1219611524165634"></a><a name="p1219611524165634"></a>Obtains the image for the current button state. </p>
</td>
</tr>
<tr id="row516404974165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2122750576165634"><a name="p2122750576165634"></a><a name="p2122750576165634"></a><a href="Graphic.md#ga8cb74b23f740091e59ad350a8dea436b">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p278783772165634"><a name="p278783772165634"></a><a name="p278783772165634"></a>int16_t </p>
<p id="p1226641136165634"><a name="p1226641136165634"></a><a name="p1226641136165634"></a>Obtains the width of this image. </p>
</td>
</tr>
<tr id="row1628290490165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p640257600165634"><a name="p640257600165634"></a><a name="p640257600165634"></a><a href="Graphic.md#ga1f8015706cfc73728696bf2bbd3e833b">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704061520165634"><a name="p704061520165634"></a><a name="p704061520165634"></a>int16_t </p>
<p id="p1069294678165634"><a name="p1069294678165634"></a><a name="p1069294678165634"></a>Obtains the height of this image. </p>
</td>
</tr>
<tr id="row1848276286165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231715085165634"><a name="p1231715085165634"></a><a name="p1231715085165634"></a><a href="Graphic.md#ga420f927c473cec8c6f3265ff7c35336f">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p828959772165634"><a name="p828959772165634"></a><a name="p828959772165634"></a>void </p>
<p id="p1226102004165634"><a name="p1226102004165634"></a><a name="p1226102004165634"></a>Sets the width for this image. </p>
</td>
</tr>
<tr id="row1225096012165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1602105353165634"><a name="p1602105353165634"></a><a name="p1602105353165634"></a><a href="Graphic.md#ga8b6dbfcd0328753c2c3cef4d14b0ff30">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213320690165634"><a name="p1213320690165634"></a><a name="p1213320690165634"></a>void </p>
<p id="p642987862165634"><a name="p642987862165634"></a><a name="p642987862165634"></a>Sets the height for this image. </p>
</td>
</tr>
<tr id="row816255465165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p276382878165634"><a name="p276382878165634"></a><a name="p276382878165634"></a><a href="Graphic.md#ga93994f4d735e4f9a7d3e7d737e2c620c">GetContentRect</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2131360930165634"><a name="p2131360930165634"></a><a name="p2131360930165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1795592410165634"><a name="p1795592410165634"></a><a name="p1795592410165634"></a>Obtains a rectangular area that contains coordinate information. </p>
</td>
</tr>
<tr id="row1192759065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1135479864165634"><a name="p1135479864165634"></a><a name="p1135479864165634"></a><a href="Graphic.md#ga37736a82bec6a01bc5a880e1d01ccccd">GetStyle</a> (uint8_t key) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397987114165634"><a name="p397987114165634"></a><a name="p397987114165634"></a>int64_t </p>
<p id="p1419005009165634"><a name="p1419005009165634"></a><a name="p1419005009165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1356972747165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p584612739165634"><a name="p584612739165634"></a><a name="p584612739165634"></a><a href="Graphic.md#gaa5fdd9b28b8c919dbde0e34d8ae38caf">SetStyle</a> (uint8_t key, int64_t value) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446070956165634"><a name="p446070956165634"></a><a name="p446070956165634"></a>void </p>
<p id="p457828024165634"><a name="p457828024165634"></a><a name="p457828024165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row2011945116165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1048746718165634"><a name="p1048746718165634"></a><a name="p1048746718165634"></a><a href="Graphic.md#gaa3f74af93c91a24e58fdd06ad7d0bdf9">GetStyleForState</a> (uint8_t key, <a href="Graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794706896165634"><a name="p794706896165634"></a><a name="p794706896165634"></a>int64_t </p>
<p id="p944821461165634"><a name="p944821461165634"></a><a name="p944821461165634"></a>Obtains the style of a button in a specific state. </p>
</td>
</tr>
<tr id="row474272202165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374922186165634"><a name="p374922186165634"></a><a name="p374922186165634"></a><a href="Graphic.md#ga7ece04980fa99a277bfbb591771f47f1">SetStyleForState</a> (uint8_t key, int64_t value, <a href="Graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96224184165634"><a name="p96224184165634"></a><a name="p96224184165634"></a>void </p>
<p id="p405887677165634"><a name="p405887677165634"></a><a name="p405887677165634"></a>Sets the style for a button in a specific state. </p>
</td>
</tr>
<tr id="row469616566165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2094856327165634"><a name="p2094856327165634"></a><a name="p2094856327165634"></a><a href="Graphic.md#ga283131701e907e586964189818d04411">Disable</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886570640165634"><a name="p1886570640165634"></a><a name="p1886570640165634"></a>void </p>
<p id="p350969718165634"><a name="p350969718165634"></a><a name="p350969718165634"></a>Disables this button. </p>
</td>
</tr>
<tr id="row832616244165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52999325165634"><a name="p52999325165634"></a><a name="p52999325165634"></a><a href="Graphic.md#ga3185df8b60a609564f978ed9576fb813">Enable</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22806865165634"><a name="p22806865165634"></a><a name="p22806865165634"></a>void </p>
<p id="p490169191165634"><a name="p490169191165634"></a><a name="p490169191165634"></a>Enables this button. </p>
</td>
</tr>
<tr id="row1925864577165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p307857507165634"><a name="p307857507165634"></a><a name="p307857507165634"></a><a href="Graphic.md#ga737d850b2adf8a2977369e611764b1ae">SetStateForStyle</a> (<a href="Graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289889077165634"><a name="p289889077165634"></a><a name="p289889077165634"></a>void </p>
<p id="p750259641165634"><a name="p750259641165634"></a><a name="p750259641165634"></a>Sets the state for a button. After the setting, calling <a href="Graphic.md#gaa5fdd9b28b8c919dbde0e34d8ae38caf">SetStyle</a> will change the style of this button, but not its state. </p>
</td>
</tr>
<tr id="row748256354165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1007220247165634"><a name="p1007220247165634"></a><a name="p1007220247165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073501263165634"><a name="p2073501263165634"></a><a name="p2073501263165634"></a> </p>
<p id="p1606477167165634"><a name="p1606477167165634"></a><a name="p1606477167165634"></a>A default constructor used to create an <strong id="b1467517153165634"><a name="b1467517153165634"></a><a name="b1467517153165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1986843595165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p905341904165634"><a name="p905341904165634"></a><a name="p905341904165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523082482165634"><a name="p1523082482165634"></a><a name="p1523082482165634"></a> </p>
<p id="p1488148459165634"><a name="p1488148459165634"></a><a name="p1488148459165634"></a>A constructor used to create an <strong id="b1709510658165634"><a name="b1709510658165634"></a><a name="b1709510658165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1876702800165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572577593165634"><a name="p1572577593165634"></a><a name="p1572577593165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785034751165634"><a name="p785034751165634"></a><a name="p785034751165634"></a>virtual </p>
<p id="p118324649165634"><a name="p118324649165634"></a><a name="p118324649165634"></a>A destructor used to delete the <strong id="b751318882165634"><a name="b751318882165634"></a><a name="b751318882165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row60758827165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156659449165634"><a name="p156659449165634"></a><a name="p156659449165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p347752910165634"><a name="p347752910165634"></a><a name="p347752910165634"></a>virtual void </p>
<p id="p1786162734165634"><a name="p1786162734165634"></a><a name="p1786162734165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row243946353165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1618998155165634"><a name="p1618998155165634"></a><a name="p1618998155165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2123043714165634"><a name="p2123043714165634"></a><a name="p2123043714165634"></a>virtual void </p>
<p id="p284058631165634"><a name="p284058631165634"></a><a name="p284058631165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1074417756165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476130862165634"><a name="p1476130862165634"></a><a name="p1476130862165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2098923117165634"><a name="p2098923117165634"></a><a name="p2098923117165634"></a>void </p>
<p id="p1263118697165634"><a name="p1263118697165634"></a><a name="p1263118697165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row228483417165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p17593880165634"><a name="p17593880165634"></a><a name="p17593880165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1490452970165634"><a name="p1490452970165634"></a><a name="p1490452970165634"></a>void </p>
<p id="p2048434942165634"><a name="p2048434942165634"></a><a name="p2048434942165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1072418178165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358742619165634"><a name="p1358742619165634"></a><a name="p1358742619165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696261438165634"><a name="p696261438165634"></a><a name="p696261438165634"></a>virtual bool </p>
<p id="p2111174431165634"><a name="p2111174431165634"></a><a name="p2111174431165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1294911446165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p504683701165634"><a name="p504683701165634"></a><a name="p504683701165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p491644480165634"><a name="p491644480165634"></a><a name="p491644480165634"></a>virtual bool </p>
<p id="p1494951404165634"><a name="p1494951404165634"></a><a name="p1494951404165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1208268431165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p556234762165634"><a name="p556234762165634"></a><a name="p556234762165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858001297165634"><a name="p1858001297165634"></a><a name="p1858001297165634"></a>virtual bool </p>
<p id="p454391472165634"><a name="p454391472165634"></a><a name="p454391472165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1202672065165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1426162988165634"><a name="p1426162988165634"></a><a name="p1426162988165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p919239302165634"><a name="p919239302165634"></a><a name="p919239302165634"></a>virtual bool </p>
<p id="p1439491297165634"><a name="p1439491297165634"></a><a name="p1439491297165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1288170532165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1575236606165634"><a name="p1575236606165634"></a><a name="p1575236606165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1143232272165634"><a name="p1143232272165634"></a><a name="p1143232272165634"></a>virtual void </p>
<p id="p651699627165634"><a name="p651699627165634"></a><a name="p651699627165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1868338751165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p650349729165634"><a name="p650349729165634"></a><a name="p650349729165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90910456165634"><a name="p90910456165634"></a><a name="p90910456165634"></a>void </p>
<p id="p123800980165634"><a name="p123800980165634"></a><a name="p123800980165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1592943022165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1454927967165634"><a name="p1454927967165634"></a><a name="p1454927967165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1250683893165634"><a name="p1250683893165634"></a><a name="p1250683893165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p998705326165634"><a name="p998705326165634"></a><a name="p998705326165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row575115631165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405057085165634"><a name="p1405057085165634"></a><a name="p1405057085165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1314307253165634"><a name="p1314307253165634"></a><a name="p1314307253165634"></a>void </p>
<p id="p126281833165634"><a name="p126281833165634"></a><a name="p126281833165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row81763594165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128286413165634"><a name="p2128286413165634"></a><a name="p2128286413165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1704113630165634"><a name="p1704113630165634"></a><a name="p1704113630165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1369757313165634"><a name="p1369757313165634"></a><a name="p1369757313165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1108629491165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930881437165634"><a name="p930881437165634"></a><a name="p930881437165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p900429001165634"><a name="p900429001165634"></a><a name="p900429001165634"></a>void </p>
<p id="p766312322165634"><a name="p766312322165634"></a><a name="p766312322165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row14759033165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1164419343165634"><a name="p1164419343165634"></a><a name="p1164419343165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1514473787165634"><a name="p1514473787165634"></a><a name="p1514473787165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p378309139165634"><a name="p378309139165634"></a><a name="p378309139165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row304425047165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1325187919165634"><a name="p1325187919165634"></a><a name="p1325187919165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p878888492165634"><a name="p878888492165634"></a><a name="p878888492165634"></a>void </p>
<p id="p1053252543165634"><a name="p1053252543165634"></a><a name="p1053252543165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row758599180165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092350994165634"><a name="p2092350994165634"></a><a name="p2092350994165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771215072165634"><a name="p771215072165634"></a><a name="p771215072165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p328562622165634"><a name="p328562622165634"></a><a name="p328562622165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row444132671165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1152428925165634"><a name="p1152428925165634"></a><a name="p1152428925165634"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p633056885165634"><a name="p633056885165634"></a><a name="p633056885165634"></a>virtual void </p>
<p id="p271868797165634"><a name="p271868797165634"></a><a name="p271868797165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row694082700165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352834090165634"><a name="p1352834090165634"></a><a name="p1352834090165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007918816165634"><a name="p2007918816165634"></a><a name="p2007918816165634"></a>void </p>
<p id="p479032101165634"><a name="p479032101165634"></a><a name="p479032101165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row332912329165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097743439165634"><a name="p2097743439165634"></a><a name="p2097743439165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p520995385165634"><a name="p520995385165634"></a><a name="p520995385165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p82583355165634"><a name="p82583355165634"></a><a name="p82583355165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row129225024165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p511965035165634"><a name="p511965035165634"></a><a name="p511965035165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1691237993165634"><a name="p1691237993165634"></a><a name="p1691237993165634"></a>void </p>
<p id="p260947082165634"><a name="p260947082165634"></a><a name="p260947082165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1330449104165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625490969165634"><a name="p1625490969165634"></a><a name="p1625490969165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p242040071165634"><a name="p242040071165634"></a><a name="p242040071165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p219244011165634"><a name="p219244011165634"></a><a name="p219244011165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row12358627165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1942481130165634"><a name="p1942481130165634"></a><a name="p1942481130165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14766843165634"><a name="p14766843165634"></a><a name="p14766843165634"></a>virtual void </p>
<p id="p1129054530165634"><a name="p1129054530165634"></a><a name="p1129054530165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row2013937021165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2094877247165634"><a name="p2094877247165634"></a><a name="p2094877247165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216314836165634"><a name="p216314836165634"></a><a name="p216314836165634"></a>bool </p>
<p id="p234163355165634"><a name="p234163355165634"></a><a name="p234163355165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row513634592165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76051235165634"><a name="p76051235165634"></a><a name="p76051235165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072851037165634"><a name="p2072851037165634"></a><a name="p2072851037165634"></a>void </p>
<p id="p1237718910165634"><a name="p1237718910165634"></a><a name="p1237718910165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row693473299165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1825629353165634"><a name="p1825629353165634"></a><a name="p1825629353165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1745532109165634"><a name="p1745532109165634"></a><a name="p1745532109165634"></a>bool </p>
<p id="p1853606322165634"><a name="p1853606322165634"></a><a name="p1853606322165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1786250675165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p314600439165634"><a name="p314600439165634"></a><a name="p314600439165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455287125165634"><a name="p1455287125165634"></a><a name="p1455287125165634"></a>void </p>
<p id="p2009943777165634"><a name="p2009943777165634"></a><a name="p2009943777165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row694727900165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p626765454165634"><a name="p626765454165634"></a><a name="p626765454165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p291506725165634"><a name="p291506725165634"></a><a name="p291506725165634"></a>bool </p>
<p id="p849852253165634"><a name="p849852253165634"></a><a name="p849852253165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1696806412165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191531260165634"><a name="p191531260165634"></a><a name="p191531260165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p545014387165634"><a name="p545014387165634"></a><a name="p545014387165634"></a>void </p>
<p id="p760167018165634"><a name="p760167018165634"></a><a name="p760167018165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row174798632165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p917752556165634"><a name="p917752556165634"></a><a name="p917752556165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1749110014165634"><a name="p1749110014165634"></a><a name="p1749110014165634"></a>bool </p>
<p id="p2042427926165634"><a name="p2042427926165634"></a><a name="p2042427926165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row2096149827165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p551471753165634"><a name="p551471753165634"></a><a name="p551471753165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1788282993165634"><a name="p1788282993165634"></a><a name="p1788282993165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1805107868165634"><a name="p1805107868165634"></a><a name="p1805107868165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row245875345165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1851754428165634"><a name="p1851754428165634"></a><a name="p1851754428165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p267814964165634"><a name="p267814964165634"></a><a name="p267814964165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2087249268165634"><a name="p2087249268165634"></a><a name="p2087249268165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1559202354165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50569943165634"><a name="p50569943165634"></a><a name="p50569943165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1149568561165634"><a name="p1149568561165634"></a><a name="p1149568561165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p203683067165634"><a name="p203683067165634"></a><a name="p203683067165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1096032245165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821659945165634"><a name="p1821659945165634"></a><a name="p1821659945165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90435582165634"><a name="p90435582165634"></a><a name="p90435582165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2134450693165634"><a name="p2134450693165634"></a><a name="p2134450693165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1691676827165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317183611165634"><a name="p1317183611165634"></a><a name="p1317183611165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117646973165634"><a name="p2117646973165634"></a><a name="p2117646973165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p917131183165634"><a name="p917131183165634"></a><a name="p917131183165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row973083909165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p69870190165634"><a name="p69870190165634"></a><a name="p69870190165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864097177165634"><a name="p864097177165634"></a><a name="p864097177165634"></a>void </p>
<p id="p429271762165634"><a name="p429271762165634"></a><a name="p429271762165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1627714047165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p319436187165634"><a name="p319436187165634"></a><a name="p319436187165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225035396165634"><a name="p225035396165634"></a><a name="p225035396165634"></a>virtual void </p>
<p id="p1553488779165634"><a name="p1553488779165634"></a><a name="p1553488779165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row2095900914165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1789769293165634"><a name="p1789769293165634"></a><a name="p1789769293165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1505828028165634"><a name="p1505828028165634"></a><a name="p1505828028165634"></a>virtual void </p>
<p id="p670198396165634"><a name="p670198396165634"></a><a name="p670198396165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row503242809165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1787046725165634"><a name="p1787046725165634"></a><a name="p1787046725165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498790454165634"><a name="p1498790454165634"></a><a name="p1498790454165634"></a>int16_t </p>
<p id="p1772299670165634"><a name="p1772299670165634"></a><a name="p1772299670165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1572230123165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428520957165634"><a name="p428520957165634"></a><a name="p428520957165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192668120165634"><a name="p1192668120165634"></a><a name="p1192668120165634"></a>virtual void </p>
<p id="p967671068165634"><a name="p967671068165634"></a><a name="p967671068165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1244224851165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p202566180165634"><a name="p202566180165634"></a><a name="p202566180165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p110244681165634"><a name="p110244681165634"></a><a name="p110244681165634"></a>int16_t </p>
<p id="p1002836921165634"><a name="p1002836921165634"></a><a name="p1002836921165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row318786710165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998882481165634"><a name="p998882481165634"></a><a name="p998882481165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144604282165634"><a name="p144604282165634"></a><a name="p144604282165634"></a>virtual void </p>
<p id="p1113388544165634"><a name="p1113388544165634"></a><a name="p1113388544165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row974424590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289308089165634"><a name="p1289308089165634"></a><a name="p1289308089165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231266824165634"><a name="p1231266824165634"></a><a name="p1231266824165634"></a>virtual void </p>
<p id="p1668208102165634"><a name="p1668208102165634"></a><a name="p1668208102165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1726846403165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p546025907165634"><a name="p546025907165634"></a><a name="p546025907165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884127114165634"><a name="p884127114165634"></a><a name="p884127114165634"></a>bool </p>
<p id="p229567544165634"><a name="p229567544165634"></a><a name="p229567544165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1017980281165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971575569165634"><a name="p1971575569165634"></a><a name="p1971575569165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1046164703165634"><a name="p1046164703165634"></a><a name="p1046164703165634"></a>void </p>
<p id="p980510274165634"><a name="p980510274165634"></a><a name="p980510274165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1023025085165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1559855539165634"><a name="p1559855539165634"></a><a name="p1559855539165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p131938897165634"><a name="p131938897165634"></a><a name="p131938897165634"></a>void </p>
<p id="p1089782431165634"><a name="p1089782431165634"></a><a name="p1089782431165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row523141193165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744405636165634"><a name="p1744405636165634"></a><a name="p1744405636165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p750491887165634"><a name="p750491887165634"></a><a name="p750491887165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p63465824165634"><a name="p63465824165634"></a><a name="p63465824165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row388538056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1025273439165634"><a name="p1025273439165634"></a><a name="p1025273439165634"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108175847165634"><a name="p108175847165634"></a><a name="p108175847165634"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1619098494165634"><a name="p1619098494165634"></a><a name="p1619098494165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row960650397165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p622709992165634"><a name="p622709992165634"></a><a name="p622709992165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1390493838165634"><a name="p1390493838165634"></a><a name="p1390493838165634"></a>void </p>
<p id="p1513247684165634"><a name="p1513247684165634"></a><a name="p1513247684165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row828034440165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1904433277165634"><a name="p1904433277165634"></a><a name="p1904433277165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1672865613165634"><a name="p1672865613165634"></a><a name="p1672865613165634"></a>const char * </p>
<p id="p1220469724165634"><a name="p1220469724165634"></a><a name="p1220469724165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row995701778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1210626224165634"><a name="p1210626224165634"></a><a name="p1210626224165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2135751416165634"><a name="p2135751416165634"></a><a name="p2135751416165634"></a>void </p>
<p id="p394141417165634"><a name="p394141417165634"></a><a name="p394141417165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row564196048165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641440090165634"><a name="p1641440090165634"></a><a name="p1641440090165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187165405165634"><a name="p187165405165634"></a><a name="p187165405165634"></a>int16_t </p>
<p id="p468048500165634"><a name="p468048500165634"></a><a name="p468048500165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1150450176165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611222896165634"><a name="p611222896165634"></a><a name="p611222896165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p48677648165634"><a name="p48677648165634"></a><a name="p48677648165634"></a>virtual void </p>
<p id="p973940436165634"><a name="p973940436165634"></a><a name="p973940436165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row614550330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p127746180165634"><a name="p127746180165634"></a><a name="p127746180165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860876842165634"><a name="p1860876842165634"></a><a name="p1860876842165634"></a>void </p>
<p id="p916945703165634"><a name="p916945703165634"></a><a name="p916945703165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row478054444165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1852840473165634"><a name="p1852840473165634"></a><a name="p1852840473165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1656600270165634"><a name="p1656600270165634"></a><a name="p1656600270165634"></a>void </p>
<p id="p276504216165634"><a name="p276504216165634"></a><a name="p276504216165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row57095424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p637275244165634"><a name="p637275244165634"></a><a name="p637275244165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1264730619165634"><a name="p1264730619165634"></a><a name="p1264730619165634"></a>void </p>
<p id="p1017930310165634"><a name="p1017930310165634"></a><a name="p1017930310165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row541009135165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p324122132165634"><a name="p324122132165634"></a><a name="p324122132165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176481190165634"><a name="p176481190165634"></a><a name="p176481190165634"></a>void </p>
<p id="p1387017562165634"><a name="p1387017562165634"></a><a name="p1387017562165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row577665474165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117799531165634"><a name="p117799531165634"></a><a name="p117799531165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1446467654165634"><a name="p1446467654165634"></a><a name="p1446467654165634"></a>void </p>
<p id="p814566390165634"><a name="p814566390165634"></a><a name="p814566390165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1549448555165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p244368818165634"><a name="p244368818165634"></a><a name="p244368818165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393431705165634"><a name="p1393431705165634"></a><a name="p1393431705165634"></a>void </p>
<p id="p362934919165634"><a name="p362934919165634"></a><a name="p362934919165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row2020366690165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1897161067165634"><a name="p1897161067165634"></a><a name="p1897161067165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900583177165634"><a name="p1900583177165634"></a><a name="p1900583177165634"></a>void </p>
<p id="p1939062407165634"><a name="p1939062407165634"></a><a name="p1939062407165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row119720524165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267512789165634"><a name="p267512789165634"></a><a name="p267512789165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90591682165634"><a name="p90591682165634"></a><a name="p90591682165634"></a>void </p>
<p id="p1413803229165634"><a name="p1413803229165634"></a><a name="p1413803229165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1725190834165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306687085165634"><a name="p1306687085165634"></a><a name="p1306687085165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1190430314165634"><a name="p1190430314165634"></a><a name="p1190430314165634"></a>void </p>
<p id="p73450972165634"><a name="p73450972165634"></a><a name="p73450972165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1395288785165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557137734165634"><a name="p557137734165634"></a><a name="p557137734165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864677686165634"><a name="p864677686165634"></a><a name="p864677686165634"></a>void </p>
<p id="p1867822911165634"><a name="p1867822911165634"></a><a name="p1867822911165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row608717788165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p714991612165634"><a name="p714991612165634"></a><a name="p714991612165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337489552165634"><a name="p1337489552165634"></a><a name="p1337489552165634"></a>void </p>
<p id="p1524773861165634"><a name="p1524773861165634"></a><a name="p1524773861165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1399127036165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306535954165634"><a name="p306535954165634"></a><a name="p306535954165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039197117165634"><a name="p2039197117165634"></a><a name="p2039197117165634"></a>void </p>
<p id="p1399160537165634"><a name="p1399160537165634"></a><a name="p1399160537165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row475452854165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2077296531165634"><a name="p2077296531165634"></a><a name="p2077296531165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p801831456165634"><a name="p801831456165634"></a><a name="p801831456165634"></a>void </p>
<p id="p535503501165634"><a name="p535503501165634"></a><a name="p535503501165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row896770326165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257071983165634"><a name="p257071983165634"></a><a name="p257071983165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p280186385165634"><a name="p280186385165634"></a><a name="p280186385165634"></a>void </p>
<p id="p988981276165634"><a name="p988981276165634"></a><a name="p988981276165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1389331956165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p777556292165634"><a name="p777556292165634"></a><a name="p777556292165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806997769165634"><a name="p806997769165634"></a><a name="p806997769165634"></a>void </p>
<p id="p736375685165634"><a name="p736375685165634"></a><a name="p736375685165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row596024459165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1402637444165634"><a name="p1402637444165634"></a><a name="p1402637444165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568386696165634"><a name="p1568386696165634"></a><a name="p1568386696165634"></a>void </p>
<p id="p2063998052165634"><a name="p2063998052165634"></a><a name="p2063998052165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row286827645165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p641916202165634"><a name="p641916202165634"></a><a name="p641916202165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1445706734165634"><a name="p1445706734165634"></a><a name="p1445706734165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1088970345165634"><a name="p1088970345165634"></a><a name="p1088970345165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row318043460165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744812142165634"><a name="p1744812142165634"></a><a name="p1744812142165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p171933359165634"><a name="p171933359165634"></a><a name="p171933359165634"></a>void * </p>
<p id="p91826296165634"><a name="p91826296165634"></a><a name="p91826296165634"></a>Overrides the <strong id="b518453131165634"><a name="b518453131165634"></a><a name="b518453131165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row123212351165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2103425503165634"><a name="p2103425503165634"></a><a name="p2103425503165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1083299726165634"><a name="p1083299726165634"></a><a name="p1083299726165634"></a>void </p>
<p id="p514135762165634"><a name="p514135762165634"></a><a name="p514135762165634"></a>Overrides the <strong id="b351025009165634"><a name="b351025009165634"></a><a name="b351025009165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

