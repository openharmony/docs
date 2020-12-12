# OHOS::Color<a name="ZH-CN_TOPIC_0000001055078157"></a>

-   [Overview](#section1931634200165633)
-   [Summary](#section1674582511165633)
-   [Static Public Member Functions](#pub-static-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1931634200165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Converts colors in different formats and defines common colors. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1674582511165633"></a>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table1815534175165633"></a>
<table><thead align="left"><tr id="row1854824078165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1016219504165633"><a name="p1016219504165633"></a><a name="p1016219504165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1484366357165633"><a name="p1484366357165633"></a><a name="p1484366357165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1487172291165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302032225165633"><a name="p1302032225165633"></a><a name="p1302032225165633"></a><a href="Graphic.md#gae12573eec4d4db025e96b5d9679e4b3f">GetMixColor</a> (<a href="OHOS-Color32.md">ColorType</a> c1, <a href="OHOS-Color32.md">ColorType</a> c2, uint8_t mix)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499275165633"><a name="p499275165633"></a><a name="p499275165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1552084834165633"><a name="p1552084834165633"></a><a name="p1552084834165633"></a>Mixes two colors (color 1 and color 2) based on a specified opacity. </p>
</td>
</tr>
<tr id="row1655171577165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621438216165633"><a name="p621438216165633"></a><a name="p621438216165633"></a><a href="Graphic.md#ga0c3bb99c625896eeab6eb0acbe14f437">GetColorFromRGB</a> (uint8_t r8, uint8_t g8, uint8_t b8)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p815105591165633"><a name="p815105591165633"></a><a name="p815105591165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p414818913165633"><a name="p414818913165633"></a><a name="p414818913165633"></a>Obtains the color based on the RGB color value. </p>
</td>
</tr>
<tr id="row364964697165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1449689403165633"><a name="p1449689403165633"></a><a name="p1449689403165633"></a><a href="Graphic.md#ga0a7e632d54e39d1d46e64c6cf20690cc">GetColorFromRGBA</a> (uint8_t r8, uint8_t g8, uint8_t b8, uint8_t alpha)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614415300165633"><a name="p1614415300165633"></a><a name="p1614415300165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1095466580165633"><a name="p1095466580165633"></a><a name="p1095466580165633"></a>Obtains the color based on the RGBA color value. </p>
</td>
</tr>
<tr id="row393081972165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982044188165633"><a name="p1982044188165633"></a><a name="p1982044188165633"></a><a href="Graphic.md#ga461b46dd76842ad4b0ffdc88202223a7">ColorTo32</a> (<a href="OHOS-Color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p785719945165633"><a name="p785719945165633"></a><a name="p785719945165633"></a>static uint32_t </p>
<p id="p84417370165633"><a name="p84417370165633"></a><a name="p84417370165633"></a>Converts color data into the RGBA8888 format. </p>
</td>
</tr>
<tr id="row46948918165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2100056855165633"><a name="p2100056855165633"></a><a name="p2100056855165633"></a><a href="Graphic.md#gaaca42d51bc5f28d5dbd5b1635be50224">ColorTo32</a> (<a href="OHOS-Color16.md">Color16</a> color, uint8_t alpha)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993124602165633"><a name="p1993124602165633"></a><a name="p1993124602165633"></a>static uint32_t </p>
<p id="p2034372972165633"><a name="p2034372972165633"></a><a name="p2034372972165633"></a>Converts color data with the 16-bit color depth into the RGBA8888 format. </p>
</td>
</tr>
<tr id="row146847367165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1823842295165633"><a name="p1823842295165633"></a><a name="p1823842295165633"></a><a href="Graphic.md#ga2a6a0bd067a05ee35793fefc8f9f4d1e">ColorTo16</a> (<a href="OHOS-Color32.md">Color32</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88785066165633"><a name="p88785066165633"></a><a name="p88785066165633"></a>static uint16_t </p>
<p id="p377765936165633"><a name="p377765936165633"></a><a name="p377765936165633"></a>Converts color data from the RGBA8888 format into the RGB565 format. </p>
</td>
</tr>
<tr id="row1580847647165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337784980165633"><a name="p337784980165633"></a><a name="p337784980165633"></a><a href="Graphic.md#gad98c45688cd59b11e9e766e62e24252f">White</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p419899498165633"><a name="p419899498165633"></a><a name="p419899498165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p731047569165633"><a name="p731047569165633"></a><a name="p731047569165633"></a>Obtains the color data of white. </p>
</td>
</tr>
<tr id="row1043078927165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1631922579165633"><a name="p1631922579165633"></a><a name="p1631922579165633"></a><a href="Graphic.md#ga6dcfcd450637398b7b7d28ce7464d153">Silver</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p585723671165633"><a name="p585723671165633"></a><a name="p585723671165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1820610227165633"><a name="p1820610227165633"></a><a name="p1820610227165633"></a>Obtains the color data of silver. </p>
</td>
</tr>
<tr id="row385481675165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p285950639165633"><a name="p285950639165633"></a><a name="p285950639165633"></a><a href="Graphic.md#ga920421d6dc1d9fbc21d5002948eb43c6">Gray</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706205048165633"><a name="p1706205048165633"></a><a name="p1706205048165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1772033284165633"><a name="p1772033284165633"></a><a name="p1772033284165633"></a>Obtains the color data of gray. </p>
</td>
</tr>
<tr id="row626556083165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888630538165633"><a name="p888630538165633"></a><a name="p888630538165633"></a><a href="Graphic.md#gac821c879969c94ec048117738e4bbef2">Black</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268230501165633"><a name="p1268230501165633"></a><a name="p1268230501165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1137277340165633"><a name="p1137277340165633"></a><a name="p1137277340165633"></a>Obtains the color data of black. </p>
</td>
</tr>
<tr id="row1747637261165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209994890165633"><a name="p209994890165633"></a><a name="p209994890165633"></a><a href="Graphic.md#gac7d29e91471253cbef9d709d74bc0d78">Red</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1512051778165633"><a name="p1512051778165633"></a><a name="p1512051778165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1578271302165633"><a name="p1578271302165633"></a><a name="p1578271302165633"></a>Obtains the color data of red. </p>
</td>
</tr>
<tr id="row1867323911165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1323072674165633"><a name="p1323072674165633"></a><a name="p1323072674165633"></a><a href="Graphic.md#gaf8342e9323109066e57434445de4423e">Maroon</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p81863662165633"><a name="p81863662165633"></a><a name="p81863662165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1992794437165633"><a name="p1992794437165633"></a><a name="p1992794437165633"></a>Obtains the color data of maroon. </p>
</td>
</tr>
<tr id="row213332023165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900903961165633"><a name="p900903961165633"></a><a name="p900903961165633"></a><a href="Graphic.md#gadd545c06bdd497b259179379e6910e15">Yellow</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2026801839165633"><a name="p2026801839165633"></a><a name="p2026801839165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1172797302165633"><a name="p1172797302165633"></a><a name="p1172797302165633"></a>Obtains the color data of yellow. </p>
</td>
</tr>
<tr id="row1004238991165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392482771165633"><a name="p392482771165633"></a><a name="p392482771165633"></a><a href="Graphic.md#ga8c8d03f5579dbb976119cee384856e3b">Olive</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268874943165633"><a name="p1268874943165633"></a><a name="p1268874943165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1857154613165633"><a name="p1857154613165633"></a><a name="p1857154613165633"></a>Obtains the color data of olive. </p>
</td>
</tr>
<tr id="row321640237165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489526164165633"><a name="p1489526164165633"></a><a name="p1489526164165633"></a><a href="Graphic.md#ga629dc5c95263df097a06b207a36b1dca">Lime</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059789138165633"><a name="p2059789138165633"></a><a name="p2059789138165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1245043255165633"><a name="p1245043255165633"></a><a name="p1245043255165633"></a>Obtains the color data of lime. </p>
</td>
</tr>
<tr id="row19703065165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956978643165633"><a name="p1956978643165633"></a><a name="p1956978643165633"></a><a href="Graphic.md#ga672e4e015f76e7cef0a4b819ee95f082">Green</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320296951165633"><a name="p1320296951165633"></a><a name="p1320296951165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1470473273165633"><a name="p1470473273165633"></a><a name="p1470473273165633"></a>Obtains the color data of green. </p>
</td>
</tr>
<tr id="row380739673165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835446454165633"><a name="p1835446454165633"></a><a name="p1835446454165633"></a><a href="Graphic.md#ga9d6b730a0799da3254543613acb0a3fa">Cyan</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p289257675165633"><a name="p289257675165633"></a><a name="p289257675165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1561706631165633"><a name="p1561706631165633"></a><a name="p1561706631165633"></a>Obtains the color data of cyan. </p>
</td>
</tr>
<tr id="row394372975165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433090958165633"><a name="p1433090958165633"></a><a name="p1433090958165633"></a><a href="Graphic.md#ga24da6b938c938b3defeb56ff79a4c4f5">Aqua</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550435268165633"><a name="p550435268165633"></a><a name="p550435268165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1119510415165633"><a name="p1119510415165633"></a><a name="p1119510415165633"></a>Obtains the color data of aqua. </p>
</td>
</tr>
<tr id="row644390885165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1431591366165633"><a name="p1431591366165633"></a><a name="p1431591366165633"></a><a href="Graphic.md#ga9f4afc8d27c8e90d5295b281a7198fe5">Teal</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132488798165633"><a name="p2132488798165633"></a><a name="p2132488798165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1247866036165633"><a name="p1247866036165633"></a><a name="p1247866036165633"></a>Obtains the color data of teal. </p>
</td>
</tr>
<tr id="row811605337165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1160761773165633"><a name="p1160761773165633"></a><a name="p1160761773165633"></a><a href="Graphic.md#ga3b02160a068039d3801580c8e35008b4">Blue</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1269237844165633"><a name="p1269237844165633"></a><a name="p1269237844165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1964645067165633"><a name="p1964645067165633"></a><a name="p1964645067165633"></a>Obtains the color data of blue. </p>
</td>
</tr>
<tr id="row212694313165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1552102845165633"><a name="p1552102845165633"></a><a name="p1552102845165633"></a><a href="Graphic.md#ga327d185847eab86cbe297a1e35f0d5d7">Navy</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1313140227165633"><a name="p1313140227165633"></a><a name="p1313140227165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1286059514165633"><a name="p1286059514165633"></a><a name="p1286059514165633"></a>Obtains the color data of navy. </p>
</td>
</tr>
<tr id="row1830448870165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p288774200165633"><a name="p288774200165633"></a><a name="p288774200165633"></a><a href="Graphic.md#ga4cbaf5650de24fc1ae45f93571b92f37">Magenta</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p63753023165633"><a name="p63753023165633"></a><a name="p63753023165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p1265305113165633"><a name="p1265305113165633"></a><a name="p1265305113165633"></a>Obtains the color data of magenta. </p>
</td>
</tr>
<tr id="row1800164195165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880405291165633"><a name="p1880405291165633"></a><a name="p1880405291165633"></a><a href="Graphic.md#ga7ec7f44a7a7d828641b739616b01dadb">Purple</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001633711165633"><a name="p2001633711165633"></a><a name="p2001633711165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p781486691165633"><a name="p781486691165633"></a><a name="p781486691165633"></a>Obtains the color data of purple. </p>
</td>
</tr>
<tr id="row1321800528165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812231637165633"><a name="p812231637165633"></a><a name="p812231637165633"></a><a href="Graphic.md#gae127df687f7b04f9debc853498678aeb">Orange</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p622945799165633"><a name="p622945799165633"></a><a name="p622945799165633"></a>static <a href="OHOS-Color32.md">ColorType</a> </p>
<p id="p377879490165633"><a name="p377879490165633"></a><a name="p377879490165633"></a>Obtains the color data of orange. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table231894243165633"></a>
<table><thead align="left"><tr id="row1388953169165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2026236588165633"><a name="p2026236588165633"></a><a name="p2026236588165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1862622930165633"><a name="p1862622930165633"></a><a name="p1862622930165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row129254776165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1747096367165633"><a name="p1747096367165633"></a><a name="p1747096367165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1063674833165633"><a name="p1063674833165633"></a><a name="p1063674833165633"></a>Overrides the <strong id="b1461623084165633"><a name="b1461623084165633"></a><a name="b1461623084165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1633374839165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392725649165633"><a name="p392725649165633"></a><a name="p392725649165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368255799165633"><a name="p1368255799165633"></a><a name="p1368255799165633"></a>Overrides the <strong id="b2088651730165633"><a name="b2088651730165633"></a><a name="b2088651730165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

