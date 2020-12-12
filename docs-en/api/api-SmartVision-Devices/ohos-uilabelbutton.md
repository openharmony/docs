# OHOS::UILabelButton<a name="EN-US_TOPIC_0000001055678118"></a>

-   [Overview](#section1326413647165634)
-   [Summary](#section665276057165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1326413647165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Provides the functions related to a label button. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section665276057165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1284503324165634"></a>
<table><thead align="left"><tr id="row1053638363165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p473367722165634"><a name="p473367722165634"></a><a name="p473367722165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1464070865165634"><a name="p1464070865165634"></a><a name="p1464070865165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1114493073165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1412264808165634"><a name="p1412264808165634"></a><a name="p1412264808165634"></a><a href="graphic.md#gadf3e53072501ed36700dea74a3ddbd8f">UILabelButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1345854117165634"><a name="p1345854117165634"></a><a name="p1345854117165634"></a> </p>
<p id="p1235729619165634"><a name="p1235729619165634"></a><a name="p1235729619165634"></a>A constructor used to create a <strong id="b895867700165634"><a name="b895867700165634"></a><a name="b895867700165634"></a><a href="ohos-uilabelbutton.md">UILabelButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1828704539165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870117466165634"><a name="p870117466165634"></a><a name="p870117466165634"></a><a href="graphic.md#ga9c585e4c556a62f44c71d538608544ee">~UILabelButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1538476702165634"><a name="p1538476702165634"></a><a name="p1538476702165634"></a>virtual </p>
<p id="p1794717987165634"><a name="p1794717987165634"></a><a name="p1794717987165634"></a>A destructor used to delete the <strong id="b350552955165634"><a name="b350552955165634"></a><a name="b350552955165634"></a><a href="ohos-uilabelbutton.md">UILabelButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row112734056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1036951993165634"><a name="p1036951993165634"></a><a name="p1036951993165634"></a><a href="graphic.md#ga159c536c3f826165c26fdabdc87f498a">OnDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1587711415165634"><a name="p1587711415165634"></a><a name="p1587711415165634"></a>void </p>
<p id="p1110912646165634"><a name="p1110912646165634"></a><a name="p1110912646165634"></a>Draws a label button. </p>
</td>
</tr>
<tr id="row36127533165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43479383165634"><a name="p43479383165634"></a><a name="p43479383165634"></a><a href="graphic.md#ga7064f161dbf0e539bd089db62339cad8">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758866859165634"><a name="p1758866859165634"></a><a name="p1758866859165634"></a>UIViewType </p>
<p id="p1855953514165634"><a name="p1855953514165634"></a><a name="p1855953514165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row270287267165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1620367675165634"><a name="p1620367675165634"></a><a name="p1620367675165634"></a><a href="graphic.md#ga6b5b491c9240a061fc21cf6b98bdaefc">SetText</a> (const char *text)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949412283165634"><a name="p949412283165634"></a><a name="p949412283165634"></a>void </p>
<p id="p1022462447165634"><a name="p1022462447165634"></a><a name="p1022462447165634"></a>Sets the text for this label button. </p>
</td>
</tr>
<tr id="row848669612165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1665042869165634"><a name="p1665042869165634"></a><a name="p1665042869165634"></a><a href="graphic.md#ga8d04dd052b36017d89e52be905b50d62">GetText</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p769898754165634"><a name="p769898754165634"></a><a name="p769898754165634"></a>const char * </p>
<p id="p1668345703165634"><a name="p1668345703165634"></a><a name="p1668345703165634"></a>Obtains the text of this label button. </p>
</td>
</tr>
<tr id="row699488085165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2119028630165634"><a name="p2119028630165634"></a><a name="p2119028630165634"></a><a href="graphic.md#gaf97dc0d36701691a001ef3fd9e6e8b4f">SetLablePosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1333121874165634"><a name="p1333121874165634"></a><a name="p1333121874165634"></a>void </p>
<p id="p479257239165634"><a name="p479257239165634"></a><a name="p479257239165634"></a>Sets the position for this label relative to the button holding it. </p>
</td>
</tr>
<tr id="row389955385165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1175446606165634"><a name="p1175446606165634"></a><a name="p1175446606165634"></a><a href="graphic.md#gaf98616000ecd2cbb458d59fa77b7fe60">GetLabelPosition</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p363238596165634"><a name="p363238596165634"></a><a name="p363238596165634"></a><a href="ohos-point.md">Point</a> </p>
<p id="p1699208357165634"><a name="p1699208357165634"></a><a name="p1699208357165634"></a>Obtains the position of this label relative to the button holding it. </p>
</td>
</tr>
<tr id="row714862000165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116521314165634"><a name="p116521314165634"></a><a name="p116521314165634"></a><a href="graphic.md#gab5625481e1a9cb77f30102c76ec76bdd">SetAlign</a> (<a href="graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> align)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p123836776165634"><a name="p123836776165634"></a><a name="p123836776165634"></a>void </p>
<p id="p509785056165634"><a name="p509785056165634"></a><a name="p509785056165634"></a>Sets the alignment mode for this text. </p>
</td>
</tr>
<tr id="row1119901262165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p993147410165634"><a name="p993147410165634"></a><a name="p993147410165634"></a><a href="graphic.md#ga94001af31d34b575be3678f06b77f432">GetAlign</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368945914165634"><a name="p1368945914165634"></a><a name="p1368945914165634"></a><a href="graphic.md#ga3f99b58f731a37cacde72d5e0c934593">UITextLanguageAlignment</a> </p>
<p id="p714234740165634"><a name="p714234740165634"></a><a name="p714234740165634"></a>Obtains the alignment mode of this text. </p>
</td>
</tr>
<tr id="row1789880466165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337537863165634"><a name="p337537863165634"></a><a name="p337537863165634"></a><a href="graphic.md#gabdea4ed71d6a22492ff423339cc08d5e">SetDirect</a> (<a href="graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> direct)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936671736165634"><a name="p1936671736165634"></a><a name="p1936671736165634"></a>void </p>
<p id="p138343767165634"><a name="p138343767165634"></a><a name="p138343767165634"></a>Sets the direction for this text. </p>
</td>
</tr>
<tr id="row1806222549165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273326916165634"><a name="p1273326916165634"></a><a name="p1273326916165634"></a><a href="graphic.md#gac39c029ba83cc256fded96108e299ff5">GetDirect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196630869165634"><a name="p196630869165634"></a><a name="p196630869165634"></a><a href="graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> </p>
<p id="p1235712953165634"><a name="p1235712953165634"></a><a name="p1235712953165634"></a>Obtains the direction of this text. </p>
</td>
</tr>
<tr id="row1087457700165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1432504543165634"><a name="p1432504543165634"></a><a name="p1432504543165634"></a><a href="graphic.md#ga66e316e344c0165a6fd3c5083ea523f4">SetLabelStyle</a> (<a href="ohos-style.md">Style</a> &amp;labelStyle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1072142054165634"><a name="p1072142054165634"></a><a name="p1072142054165634"></a>void </p>
<p id="p2047670976165634"><a name="p2047670976165634"></a><a name="p2047670976165634"></a>Sets the style for this label. </p>
</td>
</tr>
<tr id="row1494451210165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098855256165634"><a name="p2098855256165634"></a><a name="p2098855256165634"></a><a href="graphic.md#gad1d6be2a8aec65bef4c1f598bfde7666">SetLabelStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629979950165634"><a name="p629979950165634"></a><a name="p629979950165634"></a>void </p>
<p id="p700551380165634"><a name="p700551380165634"></a><a name="p700551380165634"></a>Sets a style for this label. </p>
</td>
</tr>
<tr id="row1271796424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332987100165634"><a name="p1332987100165634"></a><a name="p1332987100165634"></a><a href="graphic.md#gaefaa6ceaa04329594f1539d48fa121f2">GetLabelStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p601504051165634"><a name="p601504051165634"></a><a name="p601504051165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p2109738583165634"><a name="p2109738583165634"></a><a name="p2109738583165634"></a>Obtains the style of this label. </p>
</td>
</tr>
<tr id="row2016194614165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129157103165634"><a name="p129157103165634"></a><a name="p129157103165634"></a><a href="graphic.md#ga21c71c654974ddb388a1890576966524">GetLabelStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356303360165634"><a name="p1356303360165634"></a><a name="p1356303360165634"></a>int64_t </p>
<p id="p442473581165634"><a name="p442473581165634"></a><a name="p442473581165634"></a>Obtains the value of a style of this label. </p>
</td>
</tr>
<tr id="row339949423165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177090231165634"><a name="p1177090231165634"></a><a name="p1177090231165634"></a><a href="graphic.md#ga55592f14dc16b1e1ae3fc9ab7ee9a976">SetTextColor</a> (<a href="ohos-color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p64706075165634"><a name="p64706075165634"></a><a name="p64706075165634"></a>void </p>
<p id="p1079501328165634"><a name="p1079501328165634"></a><a name="p1079501328165634"></a>Sets the color for this text. </p>
</td>
</tr>
<tr id="row329256651165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1494355181165634"><a name="p1494355181165634"></a><a name="p1494355181165634"></a><a href="graphic.md#gad84d1829e94b7ec45ab6576bc14c62d0">SetFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1159486563165634"><a name="p1159486563165634"></a><a name="p1159486563165634"></a>void </p>
<p id="p253465686165634"><a name="p253465686165634"></a><a name="p253465686165634"></a>Sets the font for this text. </p>
</td>
</tr>
<tr id="row408440754165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p402543726165634"><a name="p402543726165634"></a><a name="p402543726165634"></a><a href="graphic.md#ga89cde9550d1bd443dad10d11c5c2fbfc">SetFontId</a> (uint8_t fontId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p827043102165634"><a name="p827043102165634"></a><a name="p827043102165634"></a>void </p>
<p id="p45751467165634"><a name="p45751467165634"></a><a name="p45751467165634"></a>Sets the font ID. </p>
</td>
</tr>
<tr id="row491396401165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p728291581165634"><a name="p728291581165634"></a><a name="p728291581165634"></a><a href="graphic.md#ga826c13b3721c17ea43a7ca386a03253c">GetFontId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p421350745165634"><a name="p421350745165634"></a><a name="p421350745165634"></a>uint8_t </p>
<p id="p1400404391165634"><a name="p1400404391165634"></a><a name="p1400404391165634"></a>Obtains the font ID. </p>
</td>
</tr>
<tr id="row815663360165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998870134165634"><a name="p998870134165634"></a><a name="p998870134165634"></a><a href="graphic.md#ga3aee093d4c583223850a7ad80d5bed79">UIButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734143117165634"><a name="p734143117165634"></a><a name="p734143117165634"></a> </p>
<p id="p998761842165634"><a name="p998761842165634"></a><a name="p998761842165634"></a>A constructor used to create a <strong id="b97534468165634"><a name="b97534468165634"></a><a name="b97534468165634"></a><a href="ohos-uibutton.md">UIButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row334989088165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1369205632165634"><a name="p1369205632165634"></a><a name="p1369205632165634"></a><a href="graphic.md#ga33e30931e9b3557634b2b2be93bc41f6">UIButton</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p928781358165634"><a name="p928781358165634"></a><a name="p928781358165634"></a> </p>
<p id="p994651065165634"><a name="p994651065165634"></a><a name="p994651065165634"></a>A constructor used to create a <strong id="b477171359165634"><a name="b477171359165634"></a><a name="b477171359165634"></a><a href="ohos-uibutton.md">UIButton</a></strong> instance based on the button ID. </p>
</td>
</tr>
<tr id="row1356435974165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p367120300165634"><a name="p367120300165634"></a><a name="p367120300165634"></a><a href="graphic.md#ga0c5fbcf319fc6df8170d407a337b9d8b">~UIButton</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1656744313165634"><a name="p1656744313165634"></a><a name="p1656744313165634"></a>virtual </p>
<p id="p2060320417165634"><a name="p2060320417165634"></a><a name="p2060320417165634"></a>A destructor used to delete the <strong id="b1950582902165634"><a name="b1950582902165634"></a><a name="b1950582902165634"></a><a href="ohos-uibutton.md">UIButton</a></strong> instance. </p>
</td>
</tr>
<tr id="row1604818590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p614122778165634"><a name="p614122778165634"></a><a name="p614122778165634"></a><a href="graphic.md#gaf64d9ec1744ab9c7385dd64d30a786e4">OnPreDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925493849165634"><a name="p925493849165634"></a><a name="p925493849165634"></a>bool </p>
<p id="p1622396417165634"><a name="p1622396417165634"></a><a name="p1622396417165634"></a>Do something before draw, this function will be invoked mainly to check if this view need to cover invalidate area so render manager can decide which layer to draw firstly. </p>
</td>
</tr>
<tr id="row208470417165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158517812165634"><a name="p158517812165634"></a><a name="p158517812165634"></a><a href="graphic.md#ga1d887720c89170abd3c8a400a791765d">OnPressEvent</a> (const <a href="ohos-pressevent.md">PressEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108716015165634"><a name="p108716015165634"></a><a name="p108716015165634"></a>void </p>
<p id="p1445695124165634"><a name="p1445695124165634"></a><a name="p1445695124165634"></a>Executes the press event action. </p>
</td>
</tr>
<tr id="row1059029315165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1694067600165634"><a name="p1694067600165634"></a><a name="p1694067600165634"></a><a href="graphic.md#gadb9492eb82ff23f91f9263fc748f24de">OnReleaseEvent</a> (const <a href="ohos-releaseevent.md">ReleaseEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190416839165634"><a name="p190416839165634"></a><a name="p190416839165634"></a>void </p>
<p id="p421740665165634"><a name="p421740665165634"></a><a name="p421740665165634"></a>Executes the press release event action. </p>
</td>
</tr>
<tr id="row336192905165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p727654917165634"><a name="p727654917165634"></a><a name="p727654917165634"></a><a href="graphic.md#ga4f481e0ce91f87c6b70f6e0190e4f34f">OnCancelEvent</a> (const <a href="ohos-cancelevent.md">CancelEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176419631165634"><a name="p176419631165634"></a><a name="p176419631165634"></a>void </p>
<p id="p54667148165634"><a name="p54667148165634"></a><a name="p54667148165634"></a>Executes the cancel event action. </p>
</td>
</tr>
<tr id="row999262711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1634776930165634"><a name="p1634776930165634"></a><a name="p1634776930165634"></a><a href="graphic.md#ga60194db1c1bba6a0ef963bdbbe9f972f">SetImageSrc</a> (const char *defaultImgSrc, const char *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652915566165634"><a name="p652915566165634"></a><a name="p652915566165634"></a>void </p>
<p id="p1539492321165634"><a name="p1539492321165634"></a><a name="p1539492321165634"></a>Sets the image for this button. </p>
</td>
</tr>
<tr id="row1868707922165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821944373165634"><a name="p1821944373165634"></a><a name="p1821944373165634"></a><a href="graphic.md#gab751bc5941edb403022d65d2c605a241">SetImageSrc</a> (const <a href="ohos-imageinfo.md">ImageInfo</a> *defaultImgSrc, const <a href="ohos-imageinfo.md">ImageInfo</a> *triggeredImgSrc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2126012407165634"><a name="p2126012407165634"></a><a name="p2126012407165634"></a>void </p>
<p id="p1274641732165634"><a name="p1274641732165634"></a><a name="p1274641732165634"></a>Sets the image for this button. </p>
</td>
</tr>
<tr id="row312957168165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2043284894165634"><a name="p2043284894165634"></a><a name="p2043284894165634"></a><a href="graphic.md#ga952fcbc88905cf35ec3e09bdf01375f2">SetImagePosition</a> (const int16_t x, const int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p115149993165634"><a name="p115149993165634"></a><a name="p115149993165634"></a>void </p>
<p id="p1224833507165634"><a name="p1224833507165634"></a><a name="p1224833507165634"></a>Sets the position for this image. </p>
</td>
</tr>
<tr id="row1389404386165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p804953979165634"><a name="p804953979165634"></a><a name="p804953979165634"></a><a href="graphic.md#ga4d8abf189ddcbf325c60402084d7e3c3">GetImageX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p66181776165634"><a name="p66181776165634"></a><a name="p66181776165634"></a>int16_t </p>
<p id="p1599179261165634"><a name="p1599179261165634"></a><a name="p1599179261165634"></a>Obtains the x-coordinate of this image. </p>
</td>
</tr>
<tr id="row557565306165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p788680263165634"><a name="p788680263165634"></a><a name="p788680263165634"></a><a href="graphic.md#ga25a02afb52cc15212084fb6bc8f27afd">GetImageY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264106024165634"><a name="p264106024165634"></a><a name="p264106024165634"></a>int16_t </p>
<p id="p1312486169165634"><a name="p1312486169165634"></a><a name="p1312486169165634"></a>Obtains the y-coordinate of this image. </p>
</td>
</tr>
<tr id="row1804596837165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1599999584165634"><a name="p1599999584165634"></a><a name="p1599999584165634"></a><a href="graphic.md#gaf6496e4858473ab2acb80a2be6264a01">GetCurImageSrc</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532155760165634"><a name="p1532155760165634"></a><a name="p1532155760165634"></a>const <a href="ohos-image.md">Image</a> * </p>
<p id="p942591408165634"><a name="p942591408165634"></a><a name="p942591408165634"></a>Obtains the image for the current button state. </p>
</td>
</tr>
<tr id="row2075526828165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451247194165634"><a name="p1451247194165634"></a><a name="p1451247194165634"></a><a href="graphic.md#ga8cb74b23f740091e59ad350a8dea436b">GetWidth</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182903976165634"><a name="p182903976165634"></a><a name="p182903976165634"></a>int16_t </p>
<p id="p1770695862165634"><a name="p1770695862165634"></a><a name="p1770695862165634"></a>Obtains the width of this image. </p>
</td>
</tr>
<tr id="row97024370165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1360426024165634"><a name="p1360426024165634"></a><a name="p1360426024165634"></a><a href="graphic.md#ga1f8015706cfc73728696bf2bbd3e833b">GetHeight</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2136463719165634"><a name="p2136463719165634"></a><a name="p2136463719165634"></a>int16_t </p>
<p id="p268766292165634"><a name="p268766292165634"></a><a name="p268766292165634"></a>Obtains the height of this image. </p>
</td>
</tr>
<tr id="row1518832349165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p143611410165634"><a name="p143611410165634"></a><a name="p143611410165634"></a><a href="graphic.md#ga420f927c473cec8c6f3265ff7c35336f">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1652887279165634"><a name="p1652887279165634"></a><a name="p1652887279165634"></a>void </p>
<p id="p181627708165634"><a name="p181627708165634"></a><a name="p181627708165634"></a>Sets the width for this image. </p>
</td>
</tr>
<tr id="row1753015744165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p639240198165634"><a name="p639240198165634"></a><a name="p639240198165634"></a><a href="graphic.md#ga8b6dbfcd0328753c2c3cef4d14b0ff30">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2059890870165634"><a name="p2059890870165634"></a><a name="p2059890870165634"></a>void </p>
<p id="p1658131504165634"><a name="p1658131504165634"></a><a name="p1658131504165634"></a>Sets the height for this image. </p>
</td>
</tr>
<tr id="row1474282002165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p117222379165634"><a name="p117222379165634"></a><a name="p117222379165634"></a><a href="graphic.md#ga93994f4d735e4f9a7d3e7d737e2c620c">GetContentRect</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p446002913165634"><a name="p446002913165634"></a><a name="p446002913165634"></a>virtual <a href="ohos-rect.md">Rect</a> </p>
<p id="p542936250165634"><a name="p542936250165634"></a><a name="p542936250165634"></a>Obtains a rectangular area that contains coordinate information. </p>
</td>
</tr>
<tr id="row230450721165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p730208700165634"><a name="p730208700165634"></a><a name="p730208700165634"></a><a href="graphic.md#ga37736a82bec6a01bc5a880e1d01ccccd">GetStyle</a> (uint8_t key) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1790012829165634"><a name="p1790012829165634"></a><a name="p1790012829165634"></a>int64_t </p>
<p id="p1329647766165634"><a name="p1329647766165634"></a><a name="p1329647766165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1275464132165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274402112165634"><a name="p1274402112165634"></a><a name="p1274402112165634"></a><a href="graphic.md#gaa5fdd9b28b8c919dbde0e34d8ae38caf">SetStyle</a> (uint8_t key, int64_t value) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121728280165634"><a name="p1121728280165634"></a><a name="p1121728280165634"></a>void </p>
<p id="p900153999165634"><a name="p900153999165634"></a><a name="p900153999165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row568991774165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1191070714165634"><a name="p1191070714165634"></a><a name="p1191070714165634"></a><a href="graphic.md#gaa3f74af93c91a24e58fdd06ad7d0bdf9">GetStyleForState</a> (uint8_t key, <a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250682664165634"><a name="p250682664165634"></a><a name="p250682664165634"></a>int64_t </p>
<p id="p322973976165634"><a name="p322973976165634"></a><a name="p322973976165634"></a>Obtains the style of a button in a specific state. </p>
</td>
</tr>
<tr id="row235275727165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787821386165634"><a name="p787821386165634"></a><a name="p787821386165634"></a><a href="graphic.md#ga7ece04980fa99a277bfbb591771f47f1">SetStyleForState</a> (uint8_t key, int64_t value, <a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381355910165634"><a name="p1381355910165634"></a><a name="p1381355910165634"></a>void </p>
<p id="p88638607165634"><a name="p88638607165634"></a><a name="p88638607165634"></a>Sets the style for a button in a specific state. </p>
</td>
</tr>
<tr id="row2112361611165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041320453165634"><a name="p1041320453165634"></a><a name="p1041320453165634"></a><a href="graphic.md#ga283131701e907e586964189818d04411">Disable</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p56106398165634"><a name="p56106398165634"></a><a name="p56106398165634"></a>void </p>
<p id="p1418140580165634"><a name="p1418140580165634"></a><a name="p1418140580165634"></a>Disables this button. </p>
</td>
</tr>
<tr id="row759021330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755269215165634"><a name="p1755269215165634"></a><a name="p1755269215165634"></a><a href="graphic.md#ga3185df8b60a609564f978ed9576fb813">Enable</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p275803214165634"><a name="p275803214165634"></a><a name="p275803214165634"></a>void </p>
<p id="p786671477165634"><a name="p786671477165634"></a><a name="p786671477165634"></a>Enables this button. </p>
</td>
</tr>
<tr id="row1537983979165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p887766648165634"><a name="p887766648165634"></a><a name="p887766648165634"></a><a href="graphic.md#ga737d850b2adf8a2977369e611764b1ae">SetStateForStyle</a> (<a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1299732134165634"><a name="p1299732134165634"></a><a name="p1299732134165634"></a>void </p>
<p id="p1205035284165634"><a name="p1205035284165634"></a><a name="p1205035284165634"></a>Sets the state for a button. After the setting, calling <a href="graphic.md#gaa5fdd9b28b8c919dbde0e34d8ae38caf">SetStyle</a> will change the style of this button, but not its state. </p>
</td>
</tr>
<tr id="row2027393026165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1025020179165634"><a name="p1025020179165634"></a><a name="p1025020179165634"></a><a href="graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295570425165634"><a name="p1295570425165634"></a><a name="p1295570425165634"></a> </p>
<p id="p1307520706165634"><a name="p1307520706165634"></a><a name="p1307520706165634"></a>A default constructor used to create an <strong id="b1935942911165634"><a name="b1935942911165634"></a><a name="b1935942911165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1968906445165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742324671165634"><a name="p742324671165634"></a><a name="p742324671165634"></a><a href="graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p387757163165634"><a name="p387757163165634"></a><a name="p387757163165634"></a> </p>
<p id="p142945063165634"><a name="p142945063165634"></a><a name="p142945063165634"></a>A constructor used to create an <strong id="b1948830379165634"><a name="b1948830379165634"></a><a name="b1948830379165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1476554392165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396903559165634"><a name="p396903559165634"></a><a name="p396903559165634"></a><a href="graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p666079574165634"><a name="p666079574165634"></a><a name="p666079574165634"></a>virtual </p>
<p id="p869989882165634"><a name="p869989882165634"></a><a name="p869989882165634"></a>A destructor used to delete the <strong id="b332265742165634"><a name="b332265742165634"></a><a name="b332265742165634"></a><a href="ohos-uiview.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row586022193165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1316700630165634"><a name="p1316700630165634"></a><a name="p1316700630165634"></a><a href="graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234748081165634"><a name="p234748081165634"></a><a name="p234748081165634"></a>virtual void </p>
<p id="p1754169372165634"><a name="p1754169372165634"></a><a name="p1754169372165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row544295472165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1663517605165634"><a name="p1663517605165634"></a><a name="p1663517605165634"></a><a href="graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034169951165634"><a name="p1034169951165634"></a><a name="p1034169951165634"></a>virtual void </p>
<p id="p1477967827165634"><a name="p1477967827165634"></a><a name="p1477967827165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row2053140734165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282188699165634"><a name="p282188699165634"></a><a name="p282188699165634"></a><a href="graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p900532778165634"><a name="p900532778165634"></a><a name="p900532778165634"></a>void </p>
<p id="p1539488827165634"><a name="p1539488827165634"></a><a name="p1539488827165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row514965295165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p402311662165634"><a name="p402311662165634"></a><a name="p402311662165634"></a><a href="graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="ohos-rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1422274801165634"><a name="p1422274801165634"></a><a name="p1422274801165634"></a>void </p>
<p id="p2108272215165634"><a name="p2108272215165634"></a><a name="p2108272215165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1860763689165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p777665738165634"><a name="p777665738165634"></a><a name="p777665738165634"></a><a href="graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="ohos-longpressevent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333664288165634"><a name="p333664288165634"></a><a name="p333664288165634"></a>virtual bool </p>
<p id="p574268418165634"><a name="p574268418165634"></a><a name="p574268418165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1727676943165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1288551872165634"><a name="p1288551872165634"></a><a name="p1288551872165634"></a><a href="graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1956747381165634"><a name="p1956747381165634"></a><a name="p1956747381165634"></a>virtual bool </p>
<p id="p438906115165634"><a name="p438906115165634"></a><a name="p438906115165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row8310015165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p759320912165634"><a name="p759320912165634"></a><a name="p759320912165634"></a><a href="graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p965416009165634"><a name="p965416009165634"></a><a name="p965416009165634"></a>virtual bool </p>
<p id="p995935566165634"><a name="p995935566165634"></a><a name="p995935566165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row605153326165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p170840860165634"><a name="p170840860165634"></a><a name="p170840860165634"></a><a href="graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="ohos-dragevent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1091707446165634"><a name="p1091707446165634"></a><a name="p1091707446165634"></a>virtual bool </p>
<p id="p781277034165634"><a name="p781277034165634"></a><a name="p781277034165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1893195544165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111098255165634"><a name="p1111098255165634"></a><a name="p1111098255165634"></a><a href="graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="ohos-clickevent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426352371165634"><a name="p1426352371165634"></a><a name="p1426352371165634"></a>virtual void </p>
<p id="p1611170605165634"><a name="p1611170605165634"></a><a name="p1611170605165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row415731106165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930720790165634"><a name="p930720790165634"></a><a name="p930720790165634"></a><a href="graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1350856076165634"><a name="p1350856076165634"></a><a name="p1350856076165634"></a>void </p>
<p id="p234408743165634"><a name="p234408743165634"></a><a name="p234408743165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1491693197165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131117535165634"><a name="p131117535165634"></a><a name="p131117535165634"></a><a href="graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073833175165634"><a name="p2073833175165634"></a><a name="p2073833175165634"></a><a href="ohos-uiview-ondraglistener.md">OnDragListener</a> *&amp; </p>
<p id="p5684089165634"><a name="p5684089165634"></a><a name="p5684089165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row434801877165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566635088165634"><a name="p566635088165634"></a><a name="p566635088165634"></a><a href="graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1022130879165634"><a name="p1022130879165634"></a><a name="p1022130879165634"></a>void </p>
<p id="p2017870135165634"><a name="p2017870135165634"></a><a name="p2017870135165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row2076551437165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323559633165634"><a name="p323559633165634"></a><a name="p323559633165634"></a><a href="graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762609893165634"><a name="p762609893165634"></a><a name="p762609893165634"></a><a href="ohos-uiview-onclicklistener.md">OnClickListener</a> *&amp; </p>
<p id="p359319861165634"><a name="p359319861165634"></a><a name="p359319861165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1249024372165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2064235139165634"><a name="p2064235139165634"></a><a name="p2064235139165634"></a><a href="graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p214832910165634"><a name="p214832910165634"></a><a name="p214832910165634"></a>void </p>
<p id="p1076875493165634"><a name="p1076875493165634"></a><a name="p1076875493165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1567434014165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110382338165634"><a name="p2110382338165634"></a><a name="p2110382338165634"></a><a href="graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p468862374165634"><a name="p468862374165634"></a><a name="p468862374165634"></a><a href="ohos-uiview-onlongpresslistener.md">OnLongPressListener</a> *&amp; </p>
<p id="p23015786165634"><a name="p23015786165634"></a><a name="p23015786165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1026378610165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p480505081165634"><a name="p480505081165634"></a><a name="p480505081165634"></a><a href="graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37347549165634"><a name="p37347549165634"></a><a name="p37347549165634"></a>void </p>
<p id="p722568691165634"><a name="p722568691165634"></a><a name="p722568691165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row453013767165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p144283236165634"><a name="p144283236165634"></a><a name="p144283236165634"></a><a href="graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p254318616165634"><a name="p254318616165634"></a><a name="p254318616165634"></a><a href="ohos-uiview-ontouchlistener.md">OnTouchListener</a> *&amp; </p>
<p id="p1425418046165634"><a name="p1425418046165634"></a><a name="p1425418046165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row34972927165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2079676641165634"><a name="p2079676641165634"></a><a name="p2079676641165634"></a><a href="graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="ohos-point.md">Point</a> &amp;point, <a href="ohos-uiview.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p184628550165634"><a name="p184628550165634"></a><a name="p184628550165634"></a>virtual void </p>
<p id="p1432803700165634"><a name="p1432803700165634"></a><a name="p1432803700165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1260763634165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047616056165634"><a name="p2047616056165634"></a><a name="p2047616056165634"></a><a href="graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="ohos-uiview.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220003772165634"><a name="p220003772165634"></a><a name="p220003772165634"></a>void </p>
<p id="p1121665594165634"><a name="p1121665594165634"></a><a name="p1121665594165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1910500550165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1368959702165634"><a name="p1368959702165634"></a><a name="p1368959702165634"></a><a href="graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085464576165634"><a name="p2085464576165634"></a><a name="p2085464576165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p143920261165634"><a name="p143920261165634"></a><a name="p143920261165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row446163356165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850418793165634"><a name="p1850418793165634"></a><a name="p1850418793165634"></a><a href="graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="ohos-uiview.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p661950533165634"><a name="p661950533165634"></a><a name="p661950533165634"></a>void </p>
<p id="p607757250165634"><a name="p607757250165634"></a><a name="p607757250165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1736709403165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p908109336165634"><a name="p908109336165634"></a><a name="p908109336165634"></a><a href="graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043859929165634"><a name="p2043859929165634"></a><a name="p2043859929165634"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1573888514165634"><a name="p1573888514165634"></a><a name="p1573888514165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1773273678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p485002828165634"><a name="p485002828165634"></a><a name="p485002828165634"></a><a href="graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p263279919165634"><a name="p263279919165634"></a><a name="p263279919165634"></a>virtual void </p>
<p id="p833621717165634"><a name="p833621717165634"></a><a name="p833621717165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row692970841165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482777525165634"><a name="p1482777525165634"></a><a name="p1482777525165634"></a><a href="graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1723331586165634"><a name="p1723331586165634"></a><a name="p1723331586165634"></a>bool </p>
<p id="p2103352652165634"><a name="p2103352652165634"></a><a name="p2103352652165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row97931594165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129289959165634"><a name="p129289959165634"></a><a name="p129289959165634"></a><a href="graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p914201236165634"><a name="p914201236165634"></a><a name="p914201236165634"></a>void </p>
<p id="p201890145165634"><a name="p201890145165634"></a><a name="p201890145165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1293561201165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1686837322165634"><a name="p1686837322165634"></a><a name="p1686837322165634"></a><a href="graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1128191080165634"><a name="p1128191080165634"></a><a name="p1128191080165634"></a>bool </p>
<p id="p1458302532165634"><a name="p1458302532165634"></a><a name="p1458302532165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1675383205165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p580575394165634"><a name="p580575394165634"></a><a name="p580575394165634"></a><a href="graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2039068084165634"><a name="p2039068084165634"></a><a name="p2039068084165634"></a>void </p>
<p id="p887139687165634"><a name="p887139687165634"></a><a name="p887139687165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1318918169165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838426400165634"><a name="p838426400165634"></a><a name="p838426400165634"></a><a href="graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192880400165634"><a name="p1192880400165634"></a><a name="p1192880400165634"></a>bool </p>
<p id="p1670152056165634"><a name="p1670152056165634"></a><a name="p1670152056165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row917259367165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2028927044165634"><a name="p2028927044165634"></a><a name="p2028927044165634"></a><a href="graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1811627376165634"><a name="p1811627376165634"></a><a name="p1811627376165634"></a>void </p>
<p id="p2018522151165634"><a name="p2018522151165634"></a><a name="p2018522151165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row778360339165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p374605406165634"><a name="p374605406165634"></a><a name="p374605406165634"></a><a href="graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215012004165634"><a name="p1215012004165634"></a><a name="p1215012004165634"></a>bool </p>
<p id="p1137026276165634"><a name="p1137026276165634"></a><a name="p1137026276165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1158434792165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p136941457165634"><a name="p136941457165634"></a><a name="p136941457165634"></a><a href="graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p821925288165634"><a name="p821925288165634"></a><a name="p821925288165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1459442064165634"><a name="p1459442064165634"></a><a name="p1459442064165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row2052488434165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1120099782165634"><a name="p1120099782165634"></a><a name="p1120099782165634"></a><a href="graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p781331980165634"><a name="p781331980165634"></a><a name="p781331980165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1133168317165634"><a name="p1133168317165634"></a><a name="p1133168317165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row566446107165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1934815447165634"><a name="p1934815447165634"></a><a name="p1934815447165634"></a><a href="graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p558720811165634"><a name="p558720811165634"></a><a name="p558720811165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1165579549165634"><a name="p1165579549165634"></a><a name="p1165579549165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1583861627165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1714850508165634"><a name="p1714850508165634"></a><a name="p1714850508165634"></a><a href="graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290564551165634"><a name="p290564551165634"></a><a name="p290564551165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p1054627146165634"><a name="p1054627146165634"></a><a name="p1054627146165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1165401586165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1160066818165634"><a name="p1160066818165634"></a><a name="p1160066818165634"></a><a href="graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669621410165634"><a name="p669621410165634"></a><a name="p669621410165634"></a><a href="ohos-rect.md">Rect</a> </p>
<p id="p2119936180165634"><a name="p2119936180165634"></a><a name="p2119936180165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row2064415386165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p749231578165634"><a name="p749231578165634"></a><a name="p749231578165634"></a><a href="graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p451259271165634"><a name="p451259271165634"></a><a name="p451259271165634"></a>void </p>
<p id="p511470821165634"><a name="p511470821165634"></a><a name="p511470821165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1776695395165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1832698633165634"><a name="p1832698633165634"></a><a name="p1832698633165634"></a><a href="graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p719446228165634"><a name="p719446228165634"></a><a name="p719446228165634"></a>virtual void </p>
<p id="p930417339165634"><a name="p930417339165634"></a><a name="p930417339165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row128067678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p419060981165634"><a name="p419060981165634"></a><a name="p419060981165634"></a><a href="graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1891855513165634"><a name="p1891855513165634"></a><a name="p1891855513165634"></a>virtual void </p>
<p id="p1073701370165634"><a name="p1073701370165634"></a><a name="p1073701370165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1901242821165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1828021984165634"><a name="p1828021984165634"></a><a name="p1828021984165634"></a><a href="graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208805325165634"><a name="p1208805325165634"></a><a name="p1208805325165634"></a>int16_t </p>
<p id="p1189385751165634"><a name="p1189385751165634"></a><a name="p1189385751165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1684071428165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p549089158165634"><a name="p549089158165634"></a><a name="p549089158165634"></a><a href="graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236134167165634"><a name="p236134167165634"></a><a name="p236134167165634"></a>virtual void </p>
<p id="p610934349165634"><a name="p610934349165634"></a><a name="p610934349165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row89284275165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654225265165634"><a name="p1654225265165634"></a><a name="p1654225265165634"></a><a href="graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006816964165634"><a name="p2006816964165634"></a><a name="p2006816964165634"></a>int16_t </p>
<p id="p1377833598165634"><a name="p1377833598165634"></a><a name="p1377833598165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1982326596165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1055547285165634"><a name="p1055547285165634"></a><a name="p1055547285165634"></a><a href="graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p856916077165634"><a name="p856916077165634"></a><a name="p856916077165634"></a>virtual void </p>
<p id="p488303463165634"><a name="p488303463165634"></a><a name="p488303463165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row33426262165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p839426504165634"><a name="p839426504165634"></a><a name="p839426504165634"></a><a href="graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540032440165634"><a name="p540032440165634"></a><a name="p540032440165634"></a>virtual void </p>
<p id="p1222509124165634"><a name="p1222509124165634"></a><a name="p1222509124165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1959978646165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203086066165634"><a name="p203086066165634"></a><a name="p203086066165634"></a><a href="graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1600572187165634"><a name="p1600572187165634"></a><a name="p1600572187165634"></a>bool </p>
<p id="p1110433992165634"><a name="p1110433992165634"></a><a name="p1110433992165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row313374943165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1259370099165634"><a name="p1259370099165634"></a><a name="p1259370099165634"></a><a href="graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1712527501165634"><a name="p1712527501165634"></a><a name="p1712527501165634"></a>void </p>
<p id="p1790996597165634"><a name="p1790996597165634"></a><a name="p1790996597165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row816854960165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p881202820165634"><a name="p881202820165634"></a><a name="p881202820165634"></a><a href="graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="ohos-transformmap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p226383375165634"><a name="p226383375165634"></a><a name="p226383375165634"></a>void </p>
<p id="p192893015165634"><a name="p192893015165634"></a><a name="p192893015165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row27390737165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p56926288165634"><a name="p56926288165634"></a><a name="p56926288165634"></a><a href="graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1899768022165634"><a name="p1899768022165634"></a><a name="p1899768022165634"></a><a href="ohos-transformmap.md">TransformMap</a> &amp; </p>
<p id="p482436347165634"><a name="p482436347165634"></a><a name="p482436347165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1527552646165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1634868511165634"><a name="p1634868511165634"></a><a name="p1634868511165634"></a><a href="graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1567185016165634"><a name="p1567185016165634"></a><a name="p1567185016165634"></a>virtual <a href="ohos-uiview.md">UIView</a> * </p>
<p id="p1257764746165634"><a name="p1257764746165634"></a><a name="p1257764746165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row89558096165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p834898266165634"><a name="p834898266165634"></a><a name="p834898266165634"></a><a href="graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308630538165634"><a name="p1308630538165634"></a><a name="p1308630538165634"></a>void </p>
<p id="p150268174165634"><a name="p150268174165634"></a><a name="p150268174165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row713228669165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p769992201165634"><a name="p769992201165634"></a><a name="p769992201165634"></a><a href="graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651850749165634"><a name="p1651850749165634"></a><a name="p1651850749165634"></a>const char * </p>
<p id="p50735646165634"><a name="p50735646165634"></a><a name="p50735646165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row58244058165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50799754165634"><a name="p50799754165634"></a><a name="p50799754165634"></a><a href="graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1685254598165634"><a name="p1685254598165634"></a><a name="p1685254598165634"></a>void </p>
<p id="p828031371165634"><a name="p828031371165634"></a><a name="p828031371165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row892353422165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p820924958165634"><a name="p820924958165634"></a><a name="p820924958165634"></a><a href="graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p913511954165634"><a name="p913511954165634"></a><a name="p913511954165634"></a>int16_t </p>
<p id="p1200215873165634"><a name="p1200215873165634"></a><a name="p1200215873165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row673845827165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1517081495165634"><a name="p1517081495165634"></a><a name="p1517081495165634"></a><a href="graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1590319394165634"><a name="p1590319394165634"></a><a name="p1590319394165634"></a>virtual void </p>
<p id="p1112874269165634"><a name="p1112874269165634"></a><a name="p1112874269165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row1775090250165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p372901341165634"><a name="p372901341165634"></a><a name="p372901341165634"></a><a href="graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p605947214165634"><a name="p605947214165634"></a><a name="p605947214165634"></a>void </p>
<p id="p1101268439165634"><a name="p1101268439165634"></a><a name="p1101268439165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1855778271165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1706954979165634"><a name="p1706954979165634"></a><a name="p1706954979165634"></a><a href="graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861882297165634"><a name="p861882297165634"></a><a name="p861882297165634"></a>void </p>
<p id="p412262586165634"><a name="p412262586165634"></a><a name="p412262586165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1612484489165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1179866107165634"><a name="p1179866107165634"></a><a name="p1179866107165634"></a><a href="graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220900162165634"><a name="p220900162165634"></a><a name="p220900162165634"></a>void </p>
<p id="p562229237165634"><a name="p562229237165634"></a><a name="p562229237165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row767277084165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p919529616165634"><a name="p919529616165634"></a><a name="p919529616165634"></a><a href="graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1375601390165634"><a name="p1375601390165634"></a><a name="p1375601390165634"></a>void </p>
<p id="p226997232165634"><a name="p226997232165634"></a><a name="p226997232165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1439681796165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p904926178165634"><a name="p904926178165634"></a><a name="p904926178165634"></a><a href="graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351084058165634"><a name="p351084058165634"></a><a name="p351084058165634"></a>void </p>
<p id="p398800102165634"><a name="p398800102165634"></a><a name="p398800102165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1915807325165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376559421165634"><a name="p1376559421165634"></a><a name="p1376559421165634"></a><a href="graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872718004165634"><a name="p1872718004165634"></a><a name="p1872718004165634"></a>void </p>
<p id="p1115385534165634"><a name="p1115385534165634"></a><a name="p1115385534165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row19429131165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806302108165634"><a name="p1806302108165634"></a><a name="p1806302108165634"></a><a href="graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1542378076165634"><a name="p1542378076165634"></a><a name="p1542378076165634"></a>void </p>
<p id="p1595389604165634"><a name="p1595389604165634"></a><a name="p1595389604165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row2132830195165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1310644096165634"><a name="p1310644096165634"></a><a name="p1310644096165634"></a><a href="graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272540049165634"><a name="p1272540049165634"></a><a name="p1272540049165634"></a>void </p>
<p id="p854655574165634"><a name="p854655574165634"></a><a name="p854655574165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row35540858165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171581999165634"><a name="p1171581999165634"></a><a name="p1171581999165634"></a><a href="graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1988175090165634"><a name="p1988175090165634"></a><a name="p1988175090165634"></a>void </p>
<p id="p393366394165634"><a name="p393366394165634"></a><a name="p393366394165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1706374084165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p679794088165634"><a name="p679794088165634"></a><a name="p679794088165634"></a><a href="graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p65591764165634"><a name="p65591764165634"></a><a name="p65591764165634"></a>void </p>
<p id="p1622033351165634"><a name="p1622033351165634"></a><a name="p1622033351165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row2096406808165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2107573085165634"><a name="p2107573085165634"></a><a name="p2107573085165634"></a><a href="graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240182638165634"><a name="p1240182638165634"></a><a name="p1240182638165634"></a>void </p>
<p id="p1870397846165634"><a name="p1870397846165634"></a><a name="p1870397846165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row1097270864165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2401438165634"><a name="p2401438165634"></a><a name="p2401438165634"></a><a href="graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533419053165634"><a name="p533419053165634"></a><a name="p533419053165634"></a>void </p>
<p id="p595667388165634"><a name="p595667388165634"></a><a name="p595667388165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row311810428165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1195638780165634"><a name="p1195638780165634"></a><a name="p1195638780165634"></a><a href="graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319514616165634"><a name="p319514616165634"></a><a name="p319514616165634"></a>void </p>
<p id="p629570358165634"><a name="p629570358165634"></a><a name="p629570358165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row2021518148165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276950364165634"><a name="p1276950364165634"></a><a name="p1276950364165634"></a><a href="graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2127913265165634"><a name="p2127913265165634"></a><a name="p2127913265165634"></a>void </p>
<p id="p112995437165634"><a name="p112995437165634"></a><a name="p112995437165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row695236424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1069316111165634"><a name="p1069316111165634"></a><a name="p1069316111165634"></a><a href="graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1475598109165634"><a name="p1475598109165634"></a><a name="p1475598109165634"></a>void </p>
<p id="p2016295754165634"><a name="p2016295754165634"></a><a name="p2016295754165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row999259709165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1762578644165634"><a name="p1762578644165634"></a><a name="p1762578644165634"></a><a href="graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="ohos-style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844923812165634"><a name="p844923812165634"></a><a name="p844923812165634"></a>void </p>
<p id="p1227116877165634"><a name="p1227116877165634"></a><a name="p1227116877165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row832845827165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55291415165634"><a name="p55291415165634"></a><a name="p55291415165634"></a><a href="graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611557258165634"><a name="p1611557258165634"></a><a name="p1611557258165634"></a>const <a href="ohos-style.md">Style</a> &amp; </p>
<p id="p16317371165634"><a name="p16317371165634"></a><a name="p16317371165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row740344221165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2095726782165634"><a name="p2095726782165634"></a><a name="p2095726782165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733091091165634"><a name="p1733091091165634"></a><a name="p1733091091165634"></a>void * </p>
<p id="p1165298347165634"><a name="p1165298347165634"></a><a name="p1165298347165634"></a>Overrides the <strong id="b1437934739165634"><a name="b1437934739165634"></a><a name="b1437934739165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1475068218165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p915346977165634"><a name="p915346977165634"></a><a name="p915346977165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1212735153165634"><a name="p1212735153165634"></a><a name="p1212735153165634"></a>void </p>
<p id="p1007639383165634"><a name="p1007639383165634"></a><a name="p1007639383165634"></a>Overrides the <strong id="b1631125431165634"><a name="b1631125431165634"></a><a name="b1631125431165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table416853673165634"></a>
<table><thead align="left"><tr id="row663493882165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2045132635165634"><a name="p2045132635165634"></a><a name="p2045132635165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1433686105165634"><a name="p1433686105165634"></a><a name="p1433686105165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1061990300165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358892047165634"><a name="p1358892047165634"></a><a name="p1358892047165634"></a><a href="graphic.md#gaf9f6c0c373f090e79b9e8d847e186e92">ButtonImageSrc</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p987385868165634"><a name="p987385868165634"></a><a name="p987385868165634"></a>Enumerates the images for different button states. </p>
</td>
</tr>
<tr id="row1755600350165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2088125650165634"><a name="p2088125650165634"></a><a name="p2088125650165634"></a><a href="graphic.md#ga188dd55c17ee44be27fa80543f13f729">ButtonState</a> : uint8_t </p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p79760409165634"><a name="p79760409165634"></a><a name="p79760409165634"></a>Enumerates the states of this button. </p>
</td>
</tr>
</tbody>
</table>

