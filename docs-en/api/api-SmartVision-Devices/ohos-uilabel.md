# OHOS::UILabel<a name="EN-US_TOPIC_0000001055198150"></a>

-   [Overview](#section1992058238165633)
-   [Summary](#section1355340320165633)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1992058238165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the functions for presenting a label in a specified area, setting the style and background color of a label, and setting the display mode of a long label text. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1355340320165633"></a>

## Public Types<a name="pub-types"></a>

<a name="table1572472317165633"></a>
<table><thead align="left"><tr id="row1789425101165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1918824744165633"><a name="p1918824744165633"></a><a name="p1918824744165633"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2142503776165633"><a name="p2142503776165633"></a><a name="p2142503776165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row726334421165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1036347461165633"><a name="p1036347461165633"></a><a name="p1036347461165633"></a><a href="graphic.md#gaf2ba9acac6cafffc549781ace0475cd5">LineBreakMode</a> : uint8_t {   <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5a03a7da624ae08162b5e74ad67e50467f">LINE_BREAK_ADAPT</a> = 0, <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5abc49de1d3936e957882efbb3259dc5be">LINE_BREAK_STRETCH</a>, <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5a2d55ab62d9cead746eb1eaaad1e4e621">LINE_BREAK_WRAP</a>, <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5ac15f8bb00b735e743b621f24a864b0ed">LINE_BREAK_ELLIPSIS</a>,   <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5a6d3e13d5e53904899020e2c44f6ca82d">LINE_BREAK_MARQUEE</a>, <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5a4111b08e919f919c314556753aa3ff46">LINE_BREAK_CLIP</a>, <a href="graphic.md#ggaf2ba9acac6cafffc549781ace0475cd5afb101ae817692c5bada96ba35f9a636d">LINE_BREAK_MAX</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000153832165633"><a name="p2000153832165633"></a><a name="p2000153832165633"></a>Enumerates the display modes of a long text. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table923692419165633"></a>
<table><thead align="left"><tr id="row1404476504165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p987473941165633"><a name="p987473941165633"></a><a name="p987473941165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p82797262165633"><a name="p82797262165633"></a><a name="p82797262165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row473851328165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p530420067165633"><a name="p530420067165633"></a><a name="p530420067165633"></a><a href="graphic.md#ga7e145ba3fb7b78ecefa1018a9540be32">UILabel</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1453187763165633"><a name="p1453187763165633"></a><a name="p1453187763165633"></a> </p>
<p id="p1768351224165633"><a name="p1768351224165633"></a><a name="p1768351224165633"></a>A constructor used to create a <strong id="b526302435165633"><a name="b526302435165633"></a><a name="b526302435165633"></a><a href="ohos-uilabel.md">UILabel</a></strong> instance. </p>
</td>
</tr>
<tr id="row672394502165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1304951593165633"><a name="p1304951593165633"></a><a name="p1304951593165633"></a><a href="graphic.md#ga8509fa2391e0ddd37faed27e35845fc5">~UILabel</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273189443165633"><a name="p273189443165633"></a><a name="p273189443165633"></a>virtual </p>
<p id="p1832697790165633"><a name="p1832697790165633"></a><a name="p1832697790165633"></a>A destructor used to delete the <strong id="b524301722165633"><a name="b524301722165633"></a><a name="b524301722165633"></a><a href="ohos-uilabel.md">UILabel</a></strong> instance. </p>
</td>
</tr>
<tr id="row1129907054165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122172207165633"><a name="p122172207165633"></a><a name="p122172207165633"></a><a href="graphic.md#gaebb514dc68a761c444af0e0e89dfcb6f">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p978631609165633"><a name="p978631609165633"></a><a name="p978631609165633"></a>UIViewType </p>
<p id="p240965033165633"><a name="p240965033165633"></a><a name="p240965033165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1179173599165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p810803717165633"><a name="p810803717165633"></a><a name="p810803717165633"></a><a href="graphic.md#ga95bc777cda044ada4401d9c5900226c6">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151690065165633"><a name="p1151690065165633"></a><a name="p1151690065165633"></a>int16_t </p>
<p id="p823134599165633"><a name="p823134599165633"></a><a name="p823134599165633"></a>Obtains the width of this label. </p>
</td>
</tr>
<tr id="row1827541126165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p212280054165633"><a name="p212280054165633"></a><a name="p212280054165633"></a><a href="graphic.md#ga148f6d32ed06364dbee0190f6ff77b59">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p513608584165633"><a name="p513608584165633"></a><a name="p513608584165633"></a>int16_t </p>
<p id="p1695519297165633"><a name="p1695519297165633"></a><a name="p1695519297165633"></a>Obtains the height of this label. </p>
</td>
</tr>
<tr id="row2115621729165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735870025165633"><a name="p735870025165633"></a><a name="p735870025165633"></a><a href="graphic.md#gaac293fb7f318e1855fba21b740147061">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1565612543165633"><a name="p1565612543165633"></a><a name="p1565612543165633"></a>bool </p>
<p id="p1570761474165633"><a name="p1570761474165633"></a><a name="p1570761474165633"></a>Checks whether this label needs to be covered before drawing it. </p>
</td>
</tr>
<tr id="row1389307255165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1589516184165633"><a name="p1589516184165633"></a><a name="p1589516184165633"></a><a href="graphic.md#ga911199741bf792b5de00789b4c8d780d">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p148311963165633"><a name="p148311963165633"></a><a name="p148311963165633"></a>void </p>
<p id="p188931559165633"><a name="p188931559165633"></a><a name="p188931559165633"></a>Draws this label. </p>
</td>
</tr>
<tr id="row1583017783165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868032155165633"><a name="p868032155165633"></a><a name="p868032155165633"></a><a href="graphic.md#gab1f3eafda465d09aaa886f09db7e47c1">SetText</a> (const char *text)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337266243165633"><a name="p1337266243165633"></a><a name="p1337266243165633"></a>void </p>
<p id="p398504001165633"><a name="p398504001165633"></a><a name="p398504001165633"></a>Sets the text content for this label. </p>
</td>
</tr>
<tr id="row904510634165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720643999165633"><a name="p720643999165633"></a><a name="p720643999165633"></a><a href="graphic.md#gafa76232f16f5aad2a84fedbb31c4f0f7">GetText</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451399751165633"><a name="p451399751165633"></a><a name="p451399751165633"></a>const char * </p>
<p id="p1232869225165633"><a name="p1232869225165633"></a><a name="p1232869225165633"></a>Obtains the text of this label. </p>
</td>
</tr>
<tr id="row832832699165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2002440722165633"><a name="p2002440722165633"></a><a name="p2002440722165633"></a><a href="graphic.md#ga406c7972fbf4950aaa8c4cef8c86acc5">SetLineBreakMode</a> (const uint8_t lineBreakMode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366168676165633"><a name="p366168676165633"></a><a name="p366168676165633"></a>void </p>
<p id="p1448978077165633"><a name="p1448978077165633"></a><a name="p1448978077165633"></a>Sets the line break mode for this text. </p>
</td>
</tr>
<tr id="row1664742637165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167761854165633"><a name="p1167761854165633"></a><a name="p1167761854165633"></a><a href="graphic.md#gab8924e40668b2c882d5dac624b49c6e8">GetLineBreakMode</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597007522165633"><a name="p1597007522165633"></a><a name="p1597007522165633"></a>uint8_t </p>
<p id="p412977412165633"><a name="p412977412165633"></a><a name="p412977412165633"></a>Obtains the line break mode of this text. </p>
</td>
</tr>
<tr id="row1370330948165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720531809165633"><a name="p720531809165633"></a><a name="p720531809165633"></a><a href="graphic.md#ga07e45127ac9569064beb2a63753d2673">SetTextColor</a> (<a href="ohos-color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328050925165633"><a name="p328050925165633"></a><a name="p328050925165633"></a>void </p>
<p id="p958910056165633"><a name="p958910056165633"></a><a name="p958910056165633"></a>Sets the color for this text. </p>
</td>
</tr>
<tr id="row462180113165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1873700689165633"><a name="p1873700689165633"></a><a name="p1873700689165633"></a><a href="graphic.md#ga963236ec609ea50610f7ef2bf85ea6df">GetTextColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144816383165633"><a name="p144816383165633"></a><a name="p144816383165633"></a><a href="ohos-color32.md">ColorType</a> </p>
<p id="p1653812811165633"><a name="p1653812811165633"></a><a name="p1653812811165633"></a>Obtains the color of this text. </p>
</td>
</tr>
<tr id="row2083008294165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1619370163165633"><a name="p1619370163165633"></a><a name="p1619370163165633"></a><a href="graphic.md#ga889e1adc1a74db59dc161cb7031b1f23">SetAlign</a> (<a href="graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> horizontalAlign, <a href="graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> verticalAlign=TEXT_ALIGNMENT_TOP)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p488591328165633"><a name="p488591328165633"></a><a name="p488591328165633"></a>void </p>
<p id="p1643017386165633"><a name="p1643017386165633"></a><a name="p1643017386165633"></a>Sets the alignment mode for this text. </p>
</td>
</tr>
<tr id="row515643345165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p316459299165633"><a name="p316459299165633"></a><a name="p316459299165633"></a><a href="graphic.md#ga97a9af1537884de541336633edc54c72">GetHorAlign</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1316296137165633"><a name="p1316296137165633"></a><a name="p1316296137165633"></a><a href="graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> </p>
<p id="p396874450165633"><a name="p396874450165633"></a><a name="p396874450165633"></a>Obtains the horizontal alignment mode. </p>
</td>
</tr>
<tr id="row118422637165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p226238471165633"><a name="p226238471165633"></a><a name="p226238471165633"></a><a href="graphic.md#gaf4acdd488481fe6ce0e79eb6a9d35d78">GetVerAlign</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p322302717165633"><a name="p322302717165633"></a><a name="p322302717165633"></a><a href="graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> </p>
<p id="p252224375165633"><a name="p252224375165633"></a><a name="p252224375165633"></a>Obtains the vertical alignment mode. </p>
</td>
</tr>
<tr id="row1898819503165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p948880211165633"><a name="p948880211165633"></a><a name="p948880211165633"></a><a href="graphic.md#ga51d43cfa57f438939627066d66a3f6cb">SetDirect</a> (<a href="graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> direct)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p759241758165633"><a name="p759241758165633"></a><a name="p759241758165633"></a>void </p>
<p id="p268474920165633"><a name="p268474920165633"></a><a name="p268474920165633"></a>Sets the direction for this text. </p>
</td>
</tr>
<tr id="row1220637569165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654978453165633"><a name="p1654978453165633"></a><a name="p1654978453165633"></a><a href="graphic.md#gab7bbf711b9cd21935a29c4183c249d80">GetDirect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p627656634165633"><a name="p627656634165633"></a><a name="p627656634165633"></a><a href="graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> </p>
<p id="p723756586165633"><a name="p723756586165633"></a><a name="p723756586165633"></a>Obtains the direction of this text. </p>
</td>
</tr>
<tr id="row38533013165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p865876606165633"><a name="p865876606165633"></a><a name="p865876606165633"></a><a href="graphic.md#gaf8b585ae9aa99d4876e1d81c8b193300">SetFontId</a> (uint8_t fontId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p727883365165633"><a name="p727883365165633"></a><a name="p727883365165633"></a>void </p>
<p id="p890298953165633"><a name="p890298953165633"></a><a name="p890298953165633"></a>Sets the font ID for this label. </p>
</td>
</tr>
<tr id="row208302949165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1519099768165633"><a name="p1519099768165633"></a><a name="p1519099768165633"></a><a href="graphic.md#ga8484c4167b7638b2bbaa10ba447c9a2f">GetFontId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p791473576165633"><a name="p791473576165633"></a><a name="p791473576165633"></a>uint8_t </p>
<p id="p1863118538165633"><a name="p1863118538165633"></a><a name="p1863118538165633"></a>Obtains the font ID composed of font name and size. </p>
</td>
</tr>
<tr id="row1984201508165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891934003165633"><a name="p1891934003165633"></a><a name="p1891934003165633"></a><a href="graphic.md#gad4b6741054c0041c6df365b1d41d49ec">SetFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366690313165633"><a name="p366690313165633"></a><a name="p366690313165633"></a>void </p>
<p id="p764287465165633"><a name="p764287465165633"></a><a name="p764287465165633"></a>Sets the font for this label. </p>
</td>
</tr>
<tr id="row375176215165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p169829265165633"><a name="p169829265165633"></a><a name="p169829265165633"></a><a href="graphic.md#gaf95611590551b86e5e49efce1cab5069">SetRollSpeed</a> (uint16_t speed)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p720893785165633"><a name="p720893785165633"></a><a name="p720893785165633"></a>void </p>
<p id="p1764879635165633"><a name="p1764879635165633"></a><a name="p1764879635165633"></a>Sets the scroll speed for this text. </p>
</td>
</tr>
<tr id="row593562529165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p513352593165633"><a name="p513352593165633"></a><a name="p513352593165633"></a><a href="graphic.md#gaff1afb0c1079bbab70c0f012ba62ea88">GetTextWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470982541165633"><a name="p470982541165633"></a><a name="p470982541165633"></a>uint16_t </p>
<p id="p502867480165633"><a name="p502867480165633"></a><a name="p502867480165633"></a>Obtains the width of this text. </p>
</td>
</tr>
<tr id="row194098959165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p256552000165633"><a name="p256552000165633"></a><a name="p256552000165633"></a><a href="graphic.md#gaecbce6ea5599f99b1a2b150608cfc9e3">GetTextHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p560099767165633"><a name="p560099767165633"></a><a name="p560099767165633"></a>uint16_t </p>
<p id="p2000611050165633"><a name="p2000611050165633"></a><a name="p2000611050165633"></a>Obtains the height of this text. </p>
</td>
</tr>
<tr id="row253706802165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p891497901165633"><a name="p891497901165633"></a><a name="p891497901165633"></a><a href="graphic.md#gaeb4eb6f2b82574eb005fdbf17b0b926b">SetRollStartPos</a> (int16_t pos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969403662165633"><a name="p969403662165633"></a><a name="p969403662165633"></a>void </p>
<p id="p361698843165633"><a name="p361698843165633"></a><a name="p361698843165633"></a>Sets the position where this text starts to roll. </p>
</td>
</tr>
<tr id="row850122209165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894003488165633"><a name="p894003488165633"></a><a name="p894003488165633"></a><a href="graphic.md#gaa2bb611ed34bcb9fc5eb2d208409ab7a">GetRollStartPos</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p706752177165633"><a name="p706752177165633"></a><a name="p706752177165633"></a>int16_t </p>
<p id="p803600052165633"><a name="p803600052165633"></a><a name="p803600052165633"></a>Obtains the position where this text starts to roll. </p>
</td>
</tr>
<tr id="row206955642165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1096330355165633"><a name="p1096330355165633"></a><a name="p1096330355165633"></a><a href="graphic.md#ga4000481fca247d526961d9da6809a806">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p558627390165633"><a name="p558627390165633"></a><a name="p558627390165633"></a>void </p>
<p id="p1752856643165633"><a name="p1752856643165633"></a><a name="p1752856643165633"></a>Sets the width for this label. </p>
</td>
</tr>
<tr id="row374819930165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p574597031165633"><a name="p574597031165633"></a><a name="p574597031165633"></a><a href="graphic.md#ga9998ddd0dfc0863d31f931a76f1da033">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p99581571165633"><a name="p99581571165633"></a><a name="p99581571165633"></a>void </p>
<p id="p1715321480165633"><a name="p1715321480165633"></a><a name="p1715321480165633"></a>Sets the height for this label. </p>
</td>
</tr>
<tr id="row1905535336165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1710436025165633"><a name="p1710436025165633"></a><a name="p1710436025165633"></a><a href="graphic.md#ga3c8eb22a51f4ec16640f5003c32d0341">SetTextRotation</a> (LabelRotateDegree angle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774858588165633"><a name="p774858588165633"></a><a name="p774858588165633"></a>void </p>
<p id="p2054600816165633"><a name="p2054600816165633"></a><a name="p2054600816165633"></a>Sets the clockwise rotation angle for this text. </p>
</td>
</tr>
<tr id="row2090711633165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596742164165633"><a name="p1596742164165633"></a><a name="p1596742164165633"></a><a href="graphic.md#ga610cb09fe19aafbb65899b060ee3cac7">GetTextRotation</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813755073165633"><a name="p1813755073165633"></a><a name="p1813755073165633"></a>LabelRotateDegree </p>
<p id="p510668363165633"><a name="p510668363165633"></a><a name="p510668363165633"></a>Obtains the clockwise rotation degree of this text. </p>
</td>
</tr>
<tr id="row1932938029165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374562928165633"><a name="p374562928165633"></a><a name="p374562928165633"></a><a href="graphic.md#gaef9e2e7f3a8849875e2a29e961a7e590">GetTextRotateDegree</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016831179165633"><a name="p2016831179165633"></a><a name="p2016831179165633"></a>uint16_t </p>
<p id="p1735697659165633"><a name="p1735697659165633"></a><a name="p1735697659165633"></a>Obtains the number of text rotation degrees. </p>
</td>
</tr>
<tr id="row724640312165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p26305794165633"><a name="p26305794165633"></a><a name="p26305794165633"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p24506413165633"><a name="p24506413165633"></a><a name="p24506413165633"></a> </p>
<p id="p2007895997165633"><a name="p2007895997165633"></a><a name="p2007895997165633"></a>A default constructor used to create an <strong id="b1449624279165633"><a name="b1449624279165633"></a><a name="b1449624279165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row480289238165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p982913921165633"><a name="p982913921165633"></a><a name="p982913921165633"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899753138165633"><a name="p899753138165633"></a><a name="p899753138165633"></a> </p>
<p id="p1805626032165633"><a name="p1805626032165633"></a><a name="p1805626032165633"></a>A constructor used to create an <strong id="b748450036165633"><a name="b748450036165633"></a><a name="b748450036165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1802790878165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p442329626165633"><a name="p442329626165633"></a><a name="p442329626165633"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608003629165633"><a name="p608003629165633"></a><a name="p608003629165633"></a>virtual </p>
<p id="p1850600066165633"><a name="p1850600066165633"></a><a name="p1850600066165633"></a>A destructor used to delete the <strong id="b1618685049165633"><a name="b1618685049165633"></a><a name="b1618685049165633"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1124943469165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90002657165633"><a name="p90002657165633"></a><a name="p90002657165633"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667951881165633"><a name="p667951881165633"></a><a name="p667951881165633"></a>virtual void </p>
<p id="p1457297062165633"><a name="p1457297062165633"></a><a name="p1457297062165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row536159372165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45376547165633"><a name="p45376547165633"></a><a name="p45376547165633"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1041359647165633"><a name="p1041359647165633"></a><a name="p1041359647165633"></a>void </p>
<p id="p700928644165633"><a name="p700928644165633"></a><a name="p700928644165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row11312125165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p550392127165633"><a name="p550392127165633"></a><a name="p550392127165633"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p32931237165633"><a name="p32931237165633"></a><a name="p32931237165633"></a>void </p>
<p id="p472182540165633"><a name="p472182540165633"></a><a name="p472182540165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1314804709165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p179571402165633"><a name="p179571402165633"></a><a name="p179571402165633"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813000651165633"><a name="p1813000651165633"></a><a name="p1813000651165633"></a>virtual bool </p>
<p id="p655107345165633"><a name="p655107345165633"></a><a name="p655107345165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row581244264165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031657802165633"><a name="p1031657802165633"></a><a name="p1031657802165633"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p586367303165633"><a name="p586367303165633"></a><a name="p586367303165633"></a>virtual bool </p>
<p id="p687802832165633"><a name="p687802832165633"></a><a name="p687802832165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row751093149165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907077253165633"><a name="p1907077253165633"></a><a name="p1907077253165633"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1489951714165633"><a name="p1489951714165633"></a><a name="p1489951714165633"></a>virtual bool </p>
<p id="p2006890130165633"><a name="p2006890130165633"></a><a name="p2006890130165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row467210371165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168840619165633"><a name="p168840619165633"></a><a name="p168840619165633"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1176173475165633"><a name="p1176173475165633"></a><a name="p1176173475165633"></a>virtual bool </p>
<p id="p1678761961165633"><a name="p1678761961165633"></a><a name="p1678761961165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row249331122165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1818048554165633"><a name="p1818048554165633"></a><a name="p1818048554165633"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p268675507165633"><a name="p268675507165633"></a><a name="p268675507165633"></a>virtual void </p>
<p id="p537816478165633"><a name="p537816478165633"></a><a name="p537816478165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row411903207165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718622558165633"><a name="p1718622558165633"></a><a name="p1718622558165633"></a><a href="graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2147406897165633"><a name="p2147406897165633"></a><a name="p2147406897165633"></a>virtual void </p>
<p id="p516942914165633"><a name="p516942914165633"></a><a name="p516942914165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1533487460165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2007756428165633"><a name="p2007756428165633"></a><a name="p2007756428165633"></a><a href="graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2124783519165633"><a name="p2124783519165633"></a><a name="p2124783519165633"></a>virtual void </p>
<p id="p546604450165633"><a name="p546604450165633"></a><a name="p546604450165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row411550619165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1564221754165633"><a name="p1564221754165633"></a><a name="p1564221754165633"></a><a href="graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1769357993165633"><a name="p1769357993165633"></a><a name="p1769357993165633"></a>virtual void </p>
<p id="p147638476165633"><a name="p147638476165633"></a><a name="p147638476165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row2032225228165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119452756165633"><a name="p2119452756165633"></a><a name="p2119452756165633"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p870140595165633"><a name="p870140595165633"></a><a name="p870140595165633"></a>void </p>
<p id="p1391226109165633"><a name="p1391226109165633"></a><a name="p1391226109165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1528776976165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448159766165633"><a name="p1448159766165633"></a><a name="p1448159766165633"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628564791165633"><a name="p1628564791165633"></a><a name="p1628564791165633"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p99543568165633"><a name="p99543568165633"></a><a name="p99543568165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1519818306165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026944772165633"><a name="p2026944772165633"></a><a name="p2026944772165633"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1779764954165633"><a name="p1779764954165633"></a><a name="p1779764954165633"></a>void </p>
<p id="p2103000718165633"><a name="p2103000718165633"></a><a name="p2103000718165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1634759506165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355684702165633"><a name="p1355684702165633"></a><a name="p1355684702165633"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3075104165633"><a name="p3075104165633"></a><a name="p3075104165633"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p1868277568165633"><a name="p1868277568165633"></a><a name="p1868277568165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1569611905165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p291184965165633"><a name="p291184965165633"></a><a name="p291184965165633"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1210479996165633"><a name="p1210479996165633"></a><a name="p1210479996165633"></a>void </p>
<p id="p1299430837165633"><a name="p1299430837165633"></a><a name="p1299430837165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row859295108165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502695193165633"><a name="p1502695193165633"></a><a name="p1502695193165633"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97141055165633"><a name="p97141055165633"></a><a name="p97141055165633"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p983869619165633"><a name="p983869619165633"></a><a name="p983869619165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1319028761165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p243413400165633"><a name="p243413400165633"></a><a name="p243413400165633"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925216513165633"><a name="p925216513165633"></a><a name="p925216513165633"></a>void </p>
<p id="p1910294200165633"><a name="p1910294200165633"></a><a name="p1910294200165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row845091102165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1082439143165633"><a name="p1082439143165633"></a><a name="p1082439143165633"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428240655165633"><a name="p428240655165633"></a><a name="p428240655165633"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p786821505165633"><a name="p786821505165633"></a><a name="p786821505165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row599946783165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267081205165633"><a name="p267081205165633"></a><a name="p267081205165633"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474253159165633"><a name="p1474253159165633"></a><a name="p1474253159165633"></a>virtual void </p>
<p id="p838058410165633"><a name="p838058410165633"></a><a name="p838058410165633"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1139671623165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497520835165633"><a name="p1497520835165633"></a><a name="p1497520835165633"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1636850830165633"><a name="p1636850830165633"></a><a name="p1636850830165633"></a>void </p>
<p id="p538583797165633"><a name="p538583797165633"></a><a name="p538583797165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1370856671165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770560103165633"><a name="p1770560103165633"></a><a name="p1770560103165633"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p354660043165633"><a name="p354660043165633"></a><a name="p354660043165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1004450714165633"><a name="p1004450714165633"></a><a name="p1004450714165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row749803869165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235429038165633"><a name="p1235429038165633"></a><a name="p1235429038165633"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351707385165633"><a name="p351707385165633"></a><a name="p351707385165633"></a>void </p>
<p id="p1695329875165633"><a name="p1695329875165633"></a><a name="p1695329875165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row474299694165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1417122988165633"><a name="p1417122988165633"></a><a name="p1417122988165633"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p358082729165633"><a name="p358082729165633"></a><a name="p358082729165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1780910492165633"><a name="p1780910492165633"></a><a name="p1780910492165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1098085571165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787800213165633"><a name="p787800213165633"></a><a name="p787800213165633"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1284204968165633"><a name="p1284204968165633"></a><a name="p1284204968165633"></a>virtual void </p>
<p id="p1541972465165633"><a name="p1541972465165633"></a><a name="p1541972465165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row274070918165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541374439165633"><a name="p1541374439165633"></a><a name="p1541374439165633"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p916973092165633"><a name="p916973092165633"></a><a name="p916973092165633"></a>bool </p>
<p id="p758784040165633"><a name="p758784040165633"></a><a name="p758784040165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row178875649165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957128194165633"><a name="p1957128194165633"></a><a name="p1957128194165633"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2116353286165633"><a name="p2116353286165633"></a><a name="p2116353286165633"></a>void </p>
<p id="p680301760165633"><a name="p680301760165633"></a><a name="p680301760165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1476328406165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948775868165633"><a name="p1948775868165633"></a><a name="p1948775868165633"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145173197165633"><a name="p1145173197165633"></a><a name="p1145173197165633"></a>bool </p>
<p id="p1427144034165633"><a name="p1427144034165633"></a><a name="p1427144034165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1395422161165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980575841165633"><a name="p980575841165633"></a><a name="p980575841165633"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p997143358165633"><a name="p997143358165633"></a><a name="p997143358165633"></a>void </p>
<p id="p872409780165633"><a name="p872409780165633"></a><a name="p872409780165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row553192775165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101763658165633"><a name="p1101763658165633"></a><a name="p1101763658165633"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1168445963165633"><a name="p1168445963165633"></a><a name="p1168445963165633"></a>bool </p>
<p id="p951691959165633"><a name="p951691959165633"></a><a name="p951691959165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row986643490165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720878024165633"><a name="p720878024165633"></a><a name="p720878024165633"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6921389165633"><a name="p6921389165633"></a><a name="p6921389165633"></a>void </p>
<p id="p392923998165633"><a name="p392923998165633"></a><a name="p392923998165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1223478073165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1033139430165633"><a name="p1033139430165633"></a><a name="p1033139430165633"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p90976843165633"><a name="p90976843165633"></a><a name="p90976843165633"></a>bool </p>
<p id="p1339015416165633"><a name="p1339015416165633"></a><a name="p1339015416165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row160880367165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1195538963165633"><a name="p1195538963165633"></a><a name="p1195538963165633"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p287430545165633"><a name="p287430545165633"></a><a name="p287430545165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p999041139165633"><a name="p999041139165633"></a><a name="p999041139165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1926718518165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079252530165633"><a name="p2079252530165633"></a><a name="p2079252530165633"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1566425686165633"><a name="p1566425686165633"></a><a name="p1566425686165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1390519609165633"><a name="p1390519609165633"></a><a name="p1390519609165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1425170865165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p106204425165633"><a name="p106204425165633"></a><a name="p106204425165633"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258415707165633"><a name="p258415707165633"></a><a name="p258415707165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p440830988165633"><a name="p440830988165633"></a><a name="p440830988165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1353858064165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971647130165633"><a name="p1971647130165633"></a><a name="p1971647130165633"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p111233265165633"><a name="p111233265165633"></a><a name="p111233265165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p894953681165633"><a name="p894953681165633"></a><a name="p894953681165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1888352653165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p766677230165633"><a name="p766677230165633"></a><a name="p766677230165633"></a><a href="graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p269213528165633"><a name="p269213528165633"></a><a name="p269213528165633"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p994727649165633"><a name="p994727649165633"></a><a name="p994727649165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row216411558165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160950115165633"><a name="p160950115165633"></a><a name="p160950115165633"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028043314165633"><a name="p2028043314165633"></a><a name="p2028043314165633"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p814662252165633"><a name="p814662252165633"></a><a name="p814662252165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1137781436165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p795575741165633"><a name="p795575741165633"></a><a name="p795575741165633"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p950748943165633"><a name="p950748943165633"></a><a name="p950748943165633"></a>void </p>
<p id="p1611619654165633"><a name="p1611619654165633"></a><a name="p1611619654165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row722728607165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119845967165633"><a name="p2119845967165633"></a><a name="p2119845967165633"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770118084165633"><a name="p770118084165633"></a><a name="p770118084165633"></a>virtual void </p>
<p id="p587593517165633"><a name="p587593517165633"></a><a name="p587593517165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1188955724165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172959947165633"><a name="p172959947165633"></a><a name="p172959947165633"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1810656033165633"><a name="p1810656033165633"></a><a name="p1810656033165633"></a>virtual void </p>
<p id="p1905997599165633"><a name="p1905997599165633"></a><a name="p1905997599165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row989668406165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p658400828165633"><a name="p658400828165633"></a><a name="p658400828165633"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1952922284165633"><a name="p1952922284165633"></a><a name="p1952922284165633"></a>int16_t </p>
<p id="p571235435165633"><a name="p571235435165633"></a><a name="p571235435165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1518497963165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p228569263165633"><a name="p228569263165633"></a><a name="p228569263165633"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p373771895165633"><a name="p373771895165633"></a><a name="p373771895165633"></a>virtual void </p>
<p id="p1068856882165633"><a name="p1068856882165633"></a><a name="p1068856882165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row844061639165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1588015496165633"><a name="p1588015496165633"></a><a name="p1588015496165633"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1775569708165633"><a name="p1775569708165633"></a><a name="p1775569708165633"></a>int16_t </p>
<p id="p116784824165633"><a name="p116784824165633"></a><a name="p116784824165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1680117206165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1446992419165633"><a name="p1446992419165633"></a><a name="p1446992419165633"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1846052449165633"><a name="p1846052449165633"></a><a name="p1846052449165633"></a>virtual void </p>
<p id="p642018991165633"><a name="p642018991165633"></a><a name="p642018991165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row404897291165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1761680205165633"><a name="p1761680205165633"></a><a name="p1761680205165633"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603800025165633"><a name="p603800025165633"></a><a name="p603800025165633"></a>virtual void </p>
<p id="p984333254165633"><a name="p984333254165633"></a><a name="p984333254165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1132386006165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477163386165633"><a name="p477163386165633"></a><a name="p477163386165633"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1767295766165633"><a name="p1767295766165633"></a><a name="p1767295766165633"></a>bool </p>
<p id="p1487583254165633"><a name="p1487583254165633"></a><a name="p1487583254165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1796505556165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1228879617165633"><a name="p1228879617165633"></a><a name="p1228879617165633"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111368792165633"><a name="p1111368792165633"></a><a name="p1111368792165633"></a>void </p>
<p id="p1447747748165633"><a name="p1447747748165633"></a><a name="p1447747748165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1281962136165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p216988246165633"><a name="p216988246165633"></a><a name="p216988246165633"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100175133165633"><a name="p1100175133165633"></a><a name="p1100175133165633"></a>void </p>
<p id="p1704373565165633"><a name="p1704373565165633"></a><a name="p1704373565165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1315034692165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973870312165633"><a name="p1973870312165633"></a><a name="p1973870312165633"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1019734798165633"><a name="p1019734798165633"></a><a name="p1019734798165633"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p356277780165633"><a name="p356277780165633"></a><a name="p356277780165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1986847074165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34154681165633"><a name="p34154681165633"></a><a name="p34154681165633"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393173556165633"><a name="p1393173556165633"></a><a name="p1393173556165633"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1600099027165633"><a name="p1600099027165633"></a><a name="p1600099027165633"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row1381901400165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567905275165633"><a name="p1567905275165633"></a><a name="p1567905275165633"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p767863012165633"><a name="p767863012165633"></a><a name="p767863012165633"></a>void </p>
<p id="p2033898159165633"><a name="p2033898159165633"></a><a name="p2033898159165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row156391878165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50263061165633"><a name="p50263061165633"></a><a name="p50263061165633"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2009023979165633"><a name="p2009023979165633"></a><a name="p2009023979165633"></a>const char * </p>
<p id="p595952639165633"><a name="p595952639165633"></a><a name="p595952639165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row2039697738165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p967035951165633"><a name="p967035951165633"></a><a name="p967035951165633"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199168252165633"><a name="p1199168252165633"></a><a name="p1199168252165633"></a>void </p>
<p id="p701983550165633"><a name="p701983550165633"></a><a name="p701983550165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row659739941165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1786352986165633"><a name="p1786352986165633"></a><a name="p1786352986165633"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p215220756165633"><a name="p215220756165633"></a><a name="p215220756165633"></a>int16_t </p>
<p id="p747283013165633"><a name="p747283013165633"></a><a name="p747283013165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1787290726165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p52726074165633"><a name="p52726074165633"></a><a name="p52726074165633"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782192139165633"><a name="p782192139165633"></a><a name="p782192139165633"></a>virtual void </p>
<p id="p1288020525165633"><a name="p1288020525165633"></a><a name="p1288020525165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1629580113165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p997923714165633"><a name="p997923714165633"></a><a name="p997923714165633"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432752750165633"><a name="p432752750165633"></a><a name="p432752750165633"></a>void </p>
<p id="p493130773165633"><a name="p493130773165633"></a><a name="p493130773165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row448319982165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1083673587165633"><a name="p1083673587165633"></a><a name="p1083673587165633"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429419393165633"><a name="p429419393165633"></a><a name="p429419393165633"></a>void </p>
<p id="p221814538165633"><a name="p221814538165633"></a><a name="p221814538165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row143320833165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1150775784165633"><a name="p1150775784165633"></a><a name="p1150775784165633"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1765881733165633"><a name="p1765881733165633"></a><a name="p1765881733165633"></a>void </p>
<p id="p1950588419165633"><a name="p1950588419165633"></a><a name="p1950588419165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row2035592298165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1422291678165633"><a name="p1422291678165633"></a><a name="p1422291678165633"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069148659165633"><a name="p2069148659165633"></a><a name="p2069148659165633"></a>void </p>
<p id="p1093034288165633"><a name="p1093034288165633"></a><a name="p1093034288165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1869988669165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080765504165633"><a name="p2080765504165633"></a><a name="p2080765504165633"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122779424165633"><a name="p122779424165633"></a><a name="p122779424165633"></a>void </p>
<p id="p603741106165633"><a name="p603741106165633"></a><a name="p603741106165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1201874254165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465759981165633"><a name="p1465759981165633"></a><a name="p1465759981165633"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p637883398165633"><a name="p637883398165633"></a><a name="p637883398165633"></a>void </p>
<p id="p1164103567165633"><a name="p1164103567165633"></a><a name="p1164103567165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1842783422165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292528516165633"><a name="p1292528516165633"></a><a name="p1292528516165633"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1673793127165633"><a name="p1673793127165633"></a><a name="p1673793127165633"></a>void </p>
<p id="p579732330165633"><a name="p579732330165633"></a><a name="p579732330165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row692726169165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p48943186165633"><a name="p48943186165633"></a><a name="p48943186165633"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p678399367165633"><a name="p678399367165633"></a><a name="p678399367165633"></a>void </p>
<p id="p568404301165633"><a name="p568404301165633"></a><a name="p568404301165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1732747368165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1779483008165633"><a name="p1779483008165633"></a><a name="p1779483008165633"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2107420356165633"><a name="p2107420356165633"></a><a name="p2107420356165633"></a>void </p>
<p id="p341057017165633"><a name="p341057017165633"></a><a name="p341057017165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1763479580165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1921110452165633"><a name="p1921110452165633"></a><a name="p1921110452165633"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p281351051165633"><a name="p281351051165633"></a><a name="p281351051165633"></a>void </p>
<p id="p493578311165633"><a name="p493578311165633"></a><a name="p493578311165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1930597435165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141043158165633"><a name="p1141043158165633"></a><a name="p1141043158165633"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p150106356165633"><a name="p150106356165633"></a><a name="p150106356165633"></a>void </p>
<p id="p1528373717165633"><a name="p1528373717165633"></a><a name="p1528373717165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row940034169165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1944223475165633"><a name="p1944223475165633"></a><a name="p1944223475165633"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768590420165633"><a name="p1768590420165633"></a><a name="p1768590420165633"></a>void </p>
<p id="p1545620578165633"><a name="p1545620578165633"></a><a name="p1545620578165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1174068877165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1562837675165633"><a name="p1562837675165633"></a><a name="p1562837675165633"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p578158896165633"><a name="p578158896165633"></a><a name="p578158896165633"></a>void </p>
<p id="p1201372277165633"><a name="p1201372277165633"></a><a name="p1201372277165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1296932613165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994816754165633"><a name="p1994816754165633"></a><a name="p1994816754165633"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610347690165633"><a name="p1610347690165633"></a><a name="p1610347690165633"></a>void </p>
<p id="p307320906165633"><a name="p307320906165633"></a><a name="p307320906165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1363389824165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1546943731165633"><a name="p1546943731165633"></a><a name="p1546943731165633"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1975238240165633"><a name="p1975238240165633"></a><a name="p1975238240165633"></a>void </p>
<p id="p586245744165633"><a name="p586245744165633"></a><a name="p586245744165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row158500105165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526932029165633"><a name="p1526932029165633"></a><a name="p1526932029165633"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p51691754165633"><a name="p51691754165633"></a><a name="p51691754165633"></a>void </p>
<p id="p527562697165633"><a name="p527562697165633"></a><a name="p527562697165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row137019610165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622069841165633"><a name="p1622069841165633"></a><a name="p1622069841165633"></a><a href="graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1477690995165633"><a name="p1477690995165633"></a><a name="p1477690995165633"></a>virtual void </p>
<p id="p1312543632165633"><a name="p1312543632165633"></a><a name="p1312543632165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1455000624165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2003258410165633"><a name="p2003258410165633"></a><a name="p2003258410165633"></a><a href="graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190166793165633"><a name="p190166793165633"></a><a name="p190166793165633"></a>virtual int64_t </p>
<p id="p2069161741165633"><a name="p2069161741165633"></a><a name="p2069161741165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row304024542165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p824754019165633"><a name="p824754019165633"></a><a name="p824754019165633"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424130804165633"><a name="p424130804165633"></a><a name="p424130804165633"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1877572354165633"><a name="p1877572354165633"></a><a name="p1877572354165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row411132494165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315668479165633"><a name="p1315668479165633"></a><a name="p1315668479165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1662195306165633"><a name="p1662195306165633"></a><a name="p1662195306165633"></a>void * </p>
<p id="p1561860684165633"><a name="p1561860684165633"></a><a name="p1561860684165633"></a>Overrides the <strong id="b396160094165633"><a name="b396160094165633"></a><a name="b396160094165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row930634898165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p588278458165633"><a name="p588278458165633"></a><a name="p588278458165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405118163165633"><a name="p1405118163165633"></a><a name="p1405118163165633"></a>void </p>
<p id="p250675835165633"><a name="p250675835165633"></a><a name="p250675835165633"></a>Overrides the <strong id="b542131699165633"><a name="b542131699165633"></a><a name="b542131699165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

