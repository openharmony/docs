# OHOS::TextAdapter<a name="EN-US_TOPIC_0000001054799619"></a>

-   [Overview](#section1319751186165633)
-   [Summary](#section927771271165633)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1319751186165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines a text adapter, which implements  [UILabel](ohos-uilabel.md)  instance construction and supports text data and continuous integer data. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section927771271165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table560772516165633"></a>
<table><thead align="left"><tr id="row495973780165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1586687731165633"><a name="p1586687731165633"></a><a name="p1586687731165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p718001073165633"><a name="p718001073165633"></a><a name="p718001073165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row181478131165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p669434077165633"><a name="p669434077165633"></a><a name="p669434077165633"></a><a href="graphic.md#ga38bde4aa4a0952341ad74284ff686832">TextAdapter</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1570045557165633"><a name="p1570045557165633"></a><a name="p1570045557165633"></a> </p>
<p id="p199267118165633"><a name="p199267118165633"></a><a name="p199267118165633"></a>A constructor used to create a <strong id="b1150858777165633"><a name="b1150858777165633"></a><a name="b1150858777165633"></a><a href="ohos-uilabel.md">UILabel</a></strong> instance. </p>
</td>
</tr>
<tr id="row1512158957165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635533846165633"><a name="p1635533846165633"></a><a name="p1635533846165633"></a><a href="graphic.md#ga1e868c845df224beff2f3c6f49593d3b">~TextAdapter</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1599324193165633"><a name="p1599324193165633"></a><a name="p1599324193165633"></a>virtual </p>
<p id="p451152421165633"><a name="p451152421165633"></a><a name="p451152421165633"></a>A destructor used to delete the <strong id="b2098108636165633"><a name="b2098108636165633"></a><a name="b2098108636165633"></a><a href="ohos-uilabel.md">UILabel</a></strong> instance. </p>
</td>
</tr>
<tr id="row1643322103165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654624172165633"><a name="p654624172165633"></a><a name="p654624172165633"></a><a href="graphic.md#ga733211ca13eccff628bb2712c27b885e">GetView</a> (<a href="ohos-uiview.md">UIView</a> *inView, int16_t <a href="utils.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p494970265165633"><a name="p494970265165633"></a><a name="p494970265165633"></a><a href="ohos-uiview.md">UIView</a> * </p>
<p id="p299779797165633"><a name="p299779797165633"></a><a name="p299779797165633"></a>Obtains a <strong id="b1161162834165633"><a name="b1161162834165633"></a><a name="b1161162834165633"></a><a href="ohos-uilabel.md">UILabel</a></strong> instance to convert adapter data into another <strong id="b1402109844165633"><a name="b1402109844165633"></a><a name="b1402109844165633"></a><a href="ohos-uilabel.md">UILabel</a></strong> instance. </p>
</td>
</tr>
<tr id="row1825733642165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994084364165633"><a name="p1994084364165633"></a><a name="p1994084364165633"></a><a href="graphic.md#gabe6f62c7e3284e04b37451963e803a96">SetData</a> (<a href="ohos-list-t.md">List</a>&lt; const char * &gt; *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265232812165633"><a name="p265232812165633"></a><a name="p265232812165633"></a>void </p>
<p id="p1148646759165633"><a name="p1148646759165633"></a><a name="p1148646759165633"></a>Sets the <a href="ohos-uilabel.md">UILabel</a> adapter data, which is a string linked list. </p>
</td>
</tr>
<tr id="row717301342165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1995728617165633"><a name="p1995728617165633"></a><a name="p1995728617165633"></a><a href="graphic.md#ga9521d17dfaf251b42deafc182aea8a1e">SetData</a> (int16_t start, int16_t end)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366592231165633"><a name="p366592231165633"></a><a name="p366592231165633"></a>void </p>
<p id="p256694142165633"><a name="p256694142165633"></a><a name="p256694142165633"></a>Sets continuously increasing data. For example, if you need to set data <strong id="b1467215544165633"><a name="b1467215544165633"></a><a name="b1467215544165633"></a>0</strong>, <strong id="b1166899706165633"><a name="b1166899706165633"></a><a name="b1166899706165633"></a>1</strong>, <strong id="b316038528165633"><a name="b316038528165633"></a><a name="b316038528165633"></a>2</strong>, <strong id="b907495800165633"><a name="b907495800165633"></a><a name="b907495800165633"></a>3</strong>, <strong id="b1418335185165633"><a name="b1418335185165633"></a><a name="b1418335185165633"></a>4</strong>, use this function to set <strong id="b243196211165633"><a name="b243196211165633"></a><a name="b243196211165633"></a>start</strong> to 0 and <strong id="b2063941929165633"><a name="b2063941929165633"></a><a name="b2063941929165633"></a>end</strong> to 4. </p>
</td>
</tr>
<tr id="row57577900165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p174083580165633"><a name="p174083580165633"></a><a name="p174083580165633"></a><a href="graphic.md#gaf0ec9f4036ed071ab95081bb3237f89a">SetFontId</a> (uint8_t fontId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155885299165633"><a name="p155885299165633"></a><a name="p155885299165633"></a>void </p>
<p id="p323190504165633"><a name="p323190504165633"></a><a name="p323190504165633"></a>Sets font ID. </p>
</td>
</tr>
<tr id="row1937126654165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907692096165633"><a name="p1907692096165633"></a><a name="p1907692096165633"></a><a href="graphic.md#ga077ac9bece7019abc2a755031ddc5575">GetFontId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384929531165633"><a name="p1384929531165633"></a><a name="p1384929531165633"></a>uint8_t </p>
<p id="p1866532698165633"><a name="p1866532698165633"></a><a name="p1866532698165633"></a>Obtains font ID. </p>
</td>
</tr>
<tr id="row118720714165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p959493211165633"><a name="p959493211165633"></a><a name="p959493211165633"></a><a href="graphic.md#ga28d957b0aa0324e876a871eae1b80d3f">SetFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599580597165633"><a name="p599580597165633"></a><a name="p599580597165633"></a>void </p>
<p id="p1215746243165633"><a name="p1215746243165633"></a><a name="p1215746243165633"></a>Sets the font. </p>
</td>
</tr>
<tr id="row873590147165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p926664030165633"><a name="p926664030165633"></a><a name="p926664030165633"></a><a href="graphic.md#gacba8806f0f63a2b0436dbe4ec1b4d01c">GetStyle</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1634971213165633"><a name="p1634971213165633"></a><a name="p1634971213165633"></a><a href="ohos-style.md">Style</a> &amp; </p>
<p id="p1835846251165633"><a name="p1835846251165633"></a><a name="p1835846251165633"></a>Obtains the <a href="ohos-uilabel.md">UILabel</a> adapter style. </p>
</td>
</tr>
<tr id="row1288051262165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1399947482165633"><a name="p1399947482165633"></a><a name="p1399947482165633"></a><a href="graphic.md#gaa8d1098628c391a687b08f4ccdba0a4d">GetCount</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1913438406165633"><a name="p1913438406165633"></a><a name="p1913438406165633"></a>virtual uint16_t </p>
<p id="p464025582165633"><a name="p464025582165633"></a><a name="p464025582165633"></a>Obtains the <strong id="b760368989165633"><a name="b760368989165633"></a><a name="b760368989165633"></a>data</strong> size of the <a href="ohos-uilabel.md">UILabel</a> adapter. </p>
</td>
</tr>
<tr id="row2015823714165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2066478181165633"><a name="p2066478181165633"></a><a name="p2066478181165633"></a><a href="graphic.md#gaed7f27b1dbf4f50ae8eda00cc6cb6a27">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1166938259165633"><a name="p1166938259165633"></a><a name="p1166938259165633"></a>void </p>
<p id="p1601809169165633"><a name="p1601809169165633"></a><a name="p1601809169165633"></a>Sets the width of <a href="ohos-uilabel.md">UILabel</a> constructed by the adapter. </p>
</td>
</tr>
<tr id="row1149470489165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861006256165633"><a name="p1861006256165633"></a><a name="p1861006256165633"></a><a href="graphic.md#ga618021df16f2156ddeeb12d5a8fa14f9">SetDirect</a> (<a href="graphic.md#ga0c108f97781843f67c101b47b6c00cf0">UITextLanguageDirect</a> direct)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p157936949165633"><a name="p157936949165633"></a><a name="p157936949165633"></a>void </p>
<p id="p1216531290165633"><a name="p1216531290165633"></a><a name="p1216531290165633"></a>Sets the direction of the <a href="ohos-uilabel.md">UILabel</a> constructed by the adapter. </p>
</td>
</tr>
<tr id="row1338774368165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p841442999165633"><a name="p841442999165633"></a><a name="p841442999165633"></a><a href="graphic.md#ga2c83259c064091d74deac1e4a69f834c">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1651777469165633"><a name="p1651777469165633"></a><a name="p1651777469165633"></a>void </p>
<p id="p1798207984165633"><a name="p1798207984165633"></a><a name="p1798207984165633"></a>Sets the height of the <a href="ohos-uilabel.md">UILabel</a> constructed by the adapter. </p>
</td>
</tr>
<tr id="row1236532427165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1420971974165633"><a name="p1420971974165633"></a><a name="p1420971974165633"></a><a href="graphic.md#gafc5f3b2c909753f4a7ef53daa80b530b">SetLineBreakMode</a> (const uint8_t lineBreakMode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2138884519165633"><a name="p2138884519165633"></a><a name="p2138884519165633"></a>void </p>
<p id="p693789692165633"><a name="p693789692165633"></a><a name="p693789692165633"></a>Sets the <strong id="b742219316165633"><a name="b742219316165633"></a><a name="b742219316165633"></a>LineBreakMode</strong> attribute of <a href="ohos-uilabel.md">UILabel</a> constructed by the adapter. For details about the values of <strong id="b1746261237165633"><a name="b1746261237165633"></a><a name="b1746261237165633"></a>LineBreakMode</strong>, see <strong id="b778941449165633"><a name="b778941449165633"></a><a name="b778941449165633"></a>LINE_BREAK_ADAPT</strong>, <strong id="b1849644826165633"><a name="b1849644826165633"></a><a name="b1849644826165633"></a>LINE_BREAK_WRAP</strong>, <strong id="b92928536165633"><a name="b92928536165633"></a><a name="b92928536165633"></a>LINE_BREAK_ELLIPSIS</strong>, and <strong id="b829792256165633"><a name="b829792256165633"></a><a name="b829792256165633"></a>LINE_BREAK_MARQUEE</strong>. </p>
</td>
</tr>
<tr id="row804641580165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116023992165633"><a name="p2116023992165633"></a><a name="p2116023992165633"></a><a href="graphic.md#ga9aa8cecae666906c7fa3d292d6c1c842">SetOnClickListener</a> (<a href="ohos-uiview-onclicklistener.md">UIView::OnClickListener</a> *clickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2128728533165633"><a name="p2128728533165633"></a><a name="p2128728533165633"></a>void </p>
<p id="p1615923664165633"><a name="p1615923664165633"></a><a name="p1615923664165633"></a>Sets the callback function to be invoked upon a click event. </p>
</td>
</tr>
<tr id="row1789706012165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477781086165633"><a name="p477781086165633"></a><a name="p477781086165633"></a><a href="graphic.md#gadad75361a42fd390b5f9c5edad2f2f0b">SetTextFormatter</a> (<a href="ohos-textformatter.md">TextFormatter</a> *formatter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760190826165633"><a name="p1760190826165633"></a><a name="p1760190826165633"></a>void </p>
<p id="p863436030165633"><a name="p863436030165633"></a><a name="p863436030165633"></a>Sets the text formatter. </p>
</td>
</tr>
<tr id="row1414671484165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p545782134165633"><a name="p545782134165633"></a><a name="p545782134165633"></a><a href="graphic.md#gab60e1c77fb98352bd62e56b550d75d88">AbstractAdapter</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p613734207165633"><a name="p613734207165633"></a><a name="p613734207165633"></a> </p>
<p id="p1039339144165633"><a name="p1039339144165633"></a><a name="p1039339144165633"></a>A constructor used to create an <strong id="b49304891165633"><a name="b49304891165633"></a><a name="b49304891165633"></a><a href="ohos-abstractadapter.md">AbstractAdapter</a></strong> instance. </p>
</td>
</tr>
<tr id="row475944171165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p792896266165633"><a name="p792896266165633"></a><a name="p792896266165633"></a><a href="graphic.md#ga86fbbc62904d459ec4fa39bab7703af7">~AbstractAdapter</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393232740165633"><a name="p393232740165633"></a><a name="p393232740165633"></a>virtual </p>
<p id="p154078938165633"><a name="p154078938165633"></a><a name="p154078938165633"></a>A destructor used to delete the <strong id="b1024999623165633"><a name="b1024999623165633"></a><a name="b1024999623165633"></a><a href="ohos-abstractadapter.md">AbstractAdapter</a></strong> instance. </p>
</td>
</tr>
<tr id="row1775571472165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1544412925165633"><a name="p1544412925165633"></a><a name="p1544412925165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1086483145165633"><a name="p1086483145165633"></a><a name="p1086483145165633"></a>void * </p>
<p id="p1675555604165633"><a name="p1675555604165633"></a><a name="p1675555604165633"></a>Overrides the <strong id="b381749637165633"><a name="b381749637165633"></a><a name="b381749637165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row49009911165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005392278165633"><a name="p2005392278165633"></a><a name="p2005392278165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1606015410165633"><a name="p1606015410165633"></a><a name="p1606015410165633"></a>void </p>
<p id="p1031276767165633"><a name="p1031276767165633"></a><a name="p1031276767165633"></a>Overrides the <strong id="b1189474440165633"><a name="b1189474440165633"></a><a name="b1189474440165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

