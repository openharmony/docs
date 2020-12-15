# OHOS::EasingEquation<a name="ZH-CN_TOPIC_0000001055039534"></a>

-   [Overview](#section1631699377165633)
-   [Summary](#section847426664165633)
-   [Static Public Member Functions](#pub-static-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1631699377165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines functions for specifying the velocity of an animation. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section847426664165633"></a>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table1633744403165633"></a>
<table><thead align="left"><tr id="row553366448165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p910583458165633"><a name="p910583458165633"></a><a name="p910583458165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p352816605165633"><a name="p352816605165633"></a><a name="p352816605165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row936950437165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44094814165633"><a name="p44094814165633"></a><a name="p44094814165633"></a><a href="Graphic.md#gab7cf0e64a0d363d8b448262d719ac97a">SetBackOvershoot</a> (double overshoot)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137100427165633"><a name="p137100427165633"></a><a name="p137100427165633"></a>static void </p>
<p id="p2010894313165633"><a name="p2010894313165633"></a><a name="p2010894313165633"></a>Sets the parameter <strong id="b1130939316165633"><a name="b1130939316165633"></a><a name="b1130939316165633"></a>s</strong> in the equation <strong id="b1179983762165633"><a name="b1179983762165633"></a><a name="b1179983762165633"></a>(s+1)*t^3 - s*t^2</strong> for a back easing. </p>
</td>
</tr>
<tr id="row59624392165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p101196011165633"><a name="p101196011165633"></a><a name="p101196011165633"></a><a href="Graphic.md#ga4598524b16a33de497fa9321d887d3b1">BackEaseIn</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p409009729165633"><a name="p409009729165633"></a><a name="p409009729165633"></a>static int16_t </p>
<p id="p1306708997165633"><a name="p1306708997165633"></a><a name="p1306708997165633"></a>Eases in with an overshoot. </p>
</td>
</tr>
<tr id="row1624505022165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p801955641165633"><a name="p801955641165633"></a><a name="p801955641165633"></a><a href="Graphic.md#ga7399f01f7abc33413bf25aa17a99c2f2">BackEaseOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1605544805165633"><a name="p1605544805165633"></a><a name="p1605544805165633"></a>static int16_t </p>
<p id="p875664541165633"><a name="p875664541165633"></a><a name="p875664541165633"></a>Eases out with an overshoot. </p>
</td>
</tr>
<tr id="row512634339165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158017494165633"><a name="p158017494165633"></a><a name="p158017494165633"></a><a href="Graphic.md#gac7c2a9a1dfce384438a3bd9d6c0c2525">BackEaseInOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424493763165633"><a name="p424493763165633"></a><a name="p424493763165633"></a>static int16_t </p>
<p id="p330299096165633"><a name="p330299096165633"></a><a name="p330299096165633"></a>Eases in and then out with an overshoot. </p>
</td>
</tr>
<tr id="row453406401165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p648198390165633"><a name="p648198390165633"></a><a name="p648198390165633"></a><a href="Graphic.md#ga446c958f14b3d6de24e2c1bab171bba2">CircEaseIn</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100687830165633"><a name="p1100687830165633"></a><a name="p1100687830165633"></a>static int16_t </p>
<p id="p787000095165633"><a name="p787000095165633"></a><a name="p787000095165633"></a>Eases in shaping like a circular curve. </p>
</td>
</tr>
<tr id="row553067155165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982971448165633"><a name="p1982971448165633"></a><a name="p1982971448165633"></a><a href="Graphic.md#gaab8fad8664d648df7e5e224b68ee54ad">CircEaseOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515475773165633"><a name="p1515475773165633"></a><a name="p1515475773165633"></a>static int16_t </p>
<p id="p151450859165633"><a name="p151450859165633"></a><a name="p151450859165633"></a>Eases out shaping like a circular curve. </p>
</td>
</tr>
<tr id="row633892291165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p752974953165633"><a name="p752974953165633"></a><a name="p752974953165633"></a><a href="Graphic.md#ga68c392dad14e1bef192b085aeec6ca9b">CircEaseInOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1444196198165633"><a name="p1444196198165633"></a><a name="p1444196198165633"></a>static int16_t </p>
<p id="p333318215165633"><a name="p333318215165633"></a><a name="p333318215165633"></a>Eases in and then out shaping like a circular curve. </p>
</td>
</tr>
<tr id="row619735420165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1204876389165633"><a name="p1204876389165633"></a><a name="p1204876389165633"></a><a href="Graphic.md#ga5c91a83cc424fb7e4e1f40cae6b3be66">CubicEaseIn</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p455953186165633"><a name="p455953186165633"></a><a name="p455953186165633"></a>static int16_t </p>
<p id="p1818706306165633"><a name="p1818706306165633"></a><a name="p1818706306165633"></a>Eases in shaping like a cubic curve. </p>
</td>
</tr>
<tr id="row655104714165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114016965165633"><a name="p1114016965165633"></a><a name="p1114016965165633"></a><a href="Graphic.md#ga529a948d9f6711a5f2726af5f10d7a48">CubicEaseOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p571766004165633"><a name="p571766004165633"></a><a name="p571766004165633"></a>static int16_t </p>
<p id="p1591405530165633"><a name="p1591405530165633"></a><a name="p1591405530165633"></a>Eases out shaping like a cubic curve. </p>
</td>
</tr>
<tr id="row1288630201165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p132217830165633"><a name="p132217830165633"></a><a name="p132217830165633"></a><a href="Graphic.md#gad99ea4ed828f274f111f492eea123cb4">CubicEaseInOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p909057356165633"><a name="p909057356165633"></a><a name="p909057356165633"></a>static int16_t </p>
<p id="p135565863165633"><a name="p135565863165633"></a><a name="p135565863165633"></a>Eases in and then out shaping like a cubic curve. </p>
</td>
</tr>
<tr id="row1604751387165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2076522134165633"><a name="p2076522134165633"></a><a name="p2076522134165633"></a><a href="Graphic.md#ga8af9a1f527ffaa5006cf0ee867f7d7d0">LinearEaseNone</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236468021165633"><a name="p236468021165633"></a><a name="p236468021165633"></a>static int16_t </p>
<p id="p522712165165633"><a name="p522712165165633"></a><a name="p522712165165633"></a>Displays no linear easing effects. </p>
</td>
</tr>
<tr id="row263264100165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p350414742165633"><a name="p350414742165633"></a><a name="p350414742165633"></a><a href="Graphic.md#ga72a9b93086c8466767942863a7d5cb78">QuadEaseIn</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1355578035165633"><a name="p1355578035165633"></a><a name="p1355578035165633"></a>static int16_t </p>
<p id="p23869117165633"><a name="p23869117165633"></a><a name="p23869117165633"></a>Eases in shaping like a quadratic curve. </p>
</td>
</tr>
<tr id="row436844817165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p528267347165633"><a name="p528267347165633"></a><a name="p528267347165633"></a><a href="Graphic.md#ga0c9cd2781e17f7077b4c9d5847eb90c8">QuadEaseOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1097910013165633"><a name="p1097910013165633"></a><a name="p1097910013165633"></a>static int16_t </p>
<p id="p442274646165633"><a name="p442274646165633"></a><a name="p442274646165633"></a>Eases out shaping like a quadratic curve. </p>
</td>
</tr>
<tr id="row705668741165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535142839165633"><a name="p535142839165633"></a><a name="p535142839165633"></a><a href="Graphic.md#ga8f62ddc3f1b2b33904845601108d6f64">QuadEaseInOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p417271306165633"><a name="p417271306165633"></a><a name="p417271306165633"></a>static int16_t </p>
<p id="p457557847165633"><a name="p457557847165633"></a><a name="p457557847165633"></a>Eases in and then out shaping like a quadratic curve. </p>
</td>
</tr>
<tr id="row1428041490165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p775985592165633"><a name="p775985592165633"></a><a name="p775985592165633"></a><a href="Graphic.md#ga9ddf5221cdde5f6a37096300847a50ac">QuintEaseIn</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p681479153165633"><a name="p681479153165633"></a><a name="p681479153165633"></a>static int16_t </p>
<p id="p1964749707165633"><a name="p1964749707165633"></a><a name="p1964749707165633"></a>Eases in shaping like a quintic curve. </p>
</td>
</tr>
<tr id="row784727694165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971575617165633"><a name="p1971575617165633"></a><a name="p1971575617165633"></a><a href="Graphic.md#gaa61e26b2bff3f69edced36d0c0d17a45">QuintEaseOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p441341740165633"><a name="p441341740165633"></a><a name="p441341740165633"></a>static int16_t </p>
<p id="p619119952165633"><a name="p619119952165633"></a><a name="p619119952165633"></a>Eases out shaping like a quintic curve. </p>
</td>
</tr>
<tr id="row125327356165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49487629165633"><a name="p49487629165633"></a><a name="p49487629165633"></a><a href="Graphic.md#ga8bea02f98d26a97072f32369370a421b">QuintEaseInOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1755817553165633"><a name="p1755817553165633"></a><a name="p1755817553165633"></a>static int16_t </p>
<p id="p360053274165633"><a name="p360053274165633"></a><a name="p360053274165633"></a>Eases in and then out shaping like a quintic curve. </p>
</td>
</tr>
<tr id="row272024462165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397684342165633"><a name="p397684342165633"></a><a name="p397684342165633"></a><a href="Graphic.md#ga89ee91a569b73c6ebb29ae4dfd2777f9">SineEaseIn</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456799357165633"><a name="p1456799357165633"></a><a name="p1456799357165633"></a>static int16_t </p>
<p id="p1207745821165633"><a name="p1207745821165633"></a><a name="p1207745821165633"></a>Eases in shaping like a sinusoidal curve. </p>
</td>
</tr>
<tr id="row246593923165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704103814165633"><a name="p1704103814165633"></a><a name="p1704103814165633"></a><a href="Graphic.md#ga34018757e69d7920557030f33393048d">SineEaseOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p618659112165633"><a name="p618659112165633"></a><a name="p618659112165633"></a>static int16_t </p>
<p id="p1632777895165633"><a name="p1632777895165633"></a><a name="p1632777895165633"></a>Eases out shaping like a sinusoidal curve. </p>
</td>
</tr>
<tr id="row1345901472165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1089862184165633"><a name="p1089862184165633"></a><a name="p1089862184165633"></a><a href="Graphic.md#ga2c3b14232a67095b0b941bae3a7b2e54">SineEaseInOut</a> (int16_t startPos, int16_t endPos, uint16_t curTime, uint16_t durationTime)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p130788642165633"><a name="p130788642165633"></a><a name="p130788642165633"></a>static int16_t </p>
<p id="p1453123751165633"><a name="p1453123751165633"></a><a name="p1453123751165633"></a>Eases in and then out shaping like a sinusoidal curve. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table909736790165633"></a>
<table><thead align="left"><tr id="row1474093777165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p82960245165633"><a name="p82960245165633"></a><a name="p82960245165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2133554257165633"><a name="p2133554257165633"></a><a name="p2133554257165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row273373321165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p433422769165633"><a name="p433422769165633"></a><a name="p433422769165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p789497572165633"><a name="p789497572165633"></a><a name="p789497572165633"></a>Overrides the <strong id="b2021054083165633"><a name="b2021054083165633"></a><a name="b2021054083165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1586391717165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994583322165633"><a name="p1994583322165633"></a><a name="p1994583322165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987404853165633"><a name="p987404853165633"></a><a name="p987404853165633"></a>Overrides the <strong id="b2070256357165633"><a name="b2070256357165633"></a><a name="b2070256357165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

