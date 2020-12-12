# OHOS::UISlider<a name="ZH-CN_TOPIC_0000001054918181"></a>

-   [Overview](#section1422396766165634)
-   [Summary](#section229199819165634)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1422396766165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a slider. 

Users can drag or click the knob to adjust the progress of an event.

See also
:   [UIBoxProgress](OHOS-UIBoxProgress.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section229199819165634"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table948772166165634"></a>
<table><thead align="left"><tr id="row1091703481165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p950535292165634"><a name="p950535292165634"></a><a name="p950535292165634"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1709966183165634"><a name="p1709966183165634"></a><a name="p1709966183165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2125654709165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p498846565165634"><a name="p498846565165634"></a><a name="p498846565165634"></a><a href="OHOS-UISlider-UISliderEventListener.md">UISliderEventListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1015694718165634"><a name="p1015694718165634"></a><a name="p1015694718165634"></a>Represents the listener for a slider change. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1871262863165634"></a>
<table><thead align="left"><tr id="row1355483873165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p584323290165634"><a name="p584323290165634"></a><a name="p584323290165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2001120734165634"><a name="p2001120734165634"></a><a name="p2001120734165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1498157348165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1610424983165634"><a name="p1610424983165634"></a><a name="p1610424983165634"></a><a href="Graphic.md#ga67f8d874edcd65b1610117052ceed0a6">UISlider</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297232888165634"><a name="p297232888165634"></a><a name="p297232888165634"></a> </p>
<p id="p722898360165634"><a name="p722898360165634"></a><a name="p722898360165634"></a>A constructor used to create a <strong id="b1657572920165634"><a name="b1657572920165634"></a><a name="b1657572920165634"></a><a href="OHOS-UISlider.md">UISlider</a></strong> instance. </p>
</td>
</tr>
<tr id="row151746196165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927486498165634"><a name="p927486498165634"></a><a name="p927486498165634"></a><a href="Graphic.md#ga024c4f15347a0b70920ab745efe8d250">~UISlider</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1754668273165634"><a name="p1754668273165634"></a><a name="p1754668273165634"></a>virtual </p>
<p id="p122715556165634"><a name="p122715556165634"></a><a name="p122715556165634"></a>A destructor used to delete the <strong id="b1060251295165634"><a name="b1060251295165634"></a><a name="b1060251295165634"></a><a href="OHOS-UISlider.md">UISlider</a></strong> instance. </p>
</td>
</tr>
<tr id="row1680870837165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800231391165634"><a name="p800231391165634"></a><a name="p800231391165634"></a><a href="Graphic.md#gac2070526833718284148689678c542a9">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p686116094165634"><a name="p686116094165634"></a><a name="p686116094165634"></a>UIViewType </p>
<p id="p1064918503165634"><a name="p1064918503165634"></a><a name="p1064918503165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1014437338165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816287669165634"><a name="p1816287669165634"></a><a name="p1816287669165634"></a><a href="Graphic.md#gaf0de71e2d767ccfc3cb41679185a5529">SetKnobWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758704345165634"><a name="p1758704345165634"></a><a name="p1758704345165634"></a>void </p>
<p id="p310294650165634"><a name="p310294650165634"></a><a name="p310294650165634"></a>Sets the width for this knob. </p>
</td>
</tr>
<tr id="row1762058459165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065794077165634"><a name="p1065794077165634"></a><a name="p1065794077165634"></a><a href="Graphic.md#ga9bac904abdf8b097778fea5febc1ec00">GetKnobWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p29301444165634"><a name="p29301444165634"></a><a name="p29301444165634"></a>int16_t </p>
<p id="p125296501165634"><a name="p125296501165634"></a><a name="p125296501165634"></a>Obtains the knob width. </p>
</td>
</tr>
<tr id="row1181702783165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1913382061165634"><a name="p1913382061165634"></a><a name="p1913382061165634"></a><a href="Graphic.md#ga0685ff139a48f556a2323d06470ad301">SetImage</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *backgroundImage, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *foregroundImage, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *knobImage)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p148685646165634"><a name="p148685646165634"></a><a name="p148685646165634"></a>void </p>
<p id="p462577817165634"><a name="p462577817165634"></a><a name="p462577817165634"></a>Sets the images as pixel maps for this slider, including the background, foreground, and knob images. </p>
</td>
</tr>
<tr id="row387024090165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136645305165634"><a name="p1136645305165634"></a><a name="p1136645305165634"></a><a href="Graphic.md#gaea596b36fd10c26361666aeda1aca01e">SetImage</a> (const char *backgroundImage, const char *foregroundImage, const char *knobImage)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708803454165634"><a name="p1708803454165634"></a><a name="p1708803454165634"></a>void </p>
<p id="p1890881462165634"><a name="p1890881462165634"></a><a name="p1890881462165634"></a>Sets the images for this slider, including the background, foreground, and knob images. </p>
</td>
</tr>
<tr id="row1568107203165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58163703165634"><a name="p58163703165634"></a><a name="p58163703165634"></a><a href="Graphic.md#ga8369feb4c08ec7a01e7200a881acb94b">SetSliderColor</a> (const <a href="OHOS-Color32.md">ColorType</a> backgroundColor, const <a href="OHOS-Color32.md">ColorType</a> foregroundColor, const <a href="OHOS-Color32.md">ColorType</a> knobColor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1931155895165634"><a name="p1931155895165634"></a><a name="p1931155895165634"></a>void </p>
<p id="p2029380052165634"><a name="p2029380052165634"></a><a name="p2029380052165634"></a>Sets the colors for this slider, including the background, foreground, and knob colors. </p>
</td>
</tr>
<tr id="row1596530137165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p671374573165634"><a name="p671374573165634"></a><a name="p671374573165634"></a><a href="Graphic.md#ga977ead9a79667465b107ca0776868712">SetSliderRadius</a> (int16_t backgroundRadius, int16_t foregroundRadius, int16_t knobRadius)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246294829165634"><a name="p246294829165634"></a><a name="p246294829165634"></a>void </p>
<p id="p1441355183165634"><a name="p1441355183165634"></a><a name="p1441355183165634"></a>Sets the corner radiuses for this slider, including the background, foreground, and knob corner radiuses. </p>
</td>
</tr>
<tr id="row1991486930165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704449494165634"><a name="p1704449494165634"></a><a name="p1704449494165634"></a><a href="Graphic.md#gac78f9aa2fe12353627a74f87fe49ef4b">SetKnobStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2084759166165634"><a name="p2084759166165634"></a><a name="p2084759166165634"></a>void </p>
<p id="p409627752165634"><a name="p409627752165634"></a><a name="p409627752165634"></a>Sets the knob style. </p>
</td>
</tr>
<tr id="row636578369165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703039427165634"><a name="p1703039427165634"></a><a name="p1703039427165634"></a><a href="Graphic.md#ga80c30c69e9f565269b09fc9d7ded432e">SetKnobStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898540012165634"><a name="p898540012165634"></a><a name="p898540012165634"></a>void </p>
<p id="p649704438165634"><a name="p649704438165634"></a><a name="p649704438165634"></a>Sets a knob style. </p>
</td>
</tr>
<tr id="row708172536165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1921882192165634"><a name="p1921882192165634"></a><a name="p1921882192165634"></a><a href="Graphic.md#gaecf92fe00a7565d034937e89fe2cf1e6">GetKnobStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1525773214165634"><a name="p1525773214165634"></a><a name="p1525773214165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1622740090165634"><a name="p1622740090165634"></a><a name="p1622740090165634"></a>Obtains the knob style. </p>
</td>
</tr>
<tr id="row623712678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1367309731165634"><a name="p1367309731165634"></a><a name="p1367309731165634"></a><a href="Graphic.md#ga1fef57bd5d9a11a9c1946e8efec71b61">GetKnobStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485354778165634"><a name="p1485354778165634"></a><a name="p1485354778165634"></a>int64_t </p>
<p id="p962546010165634"><a name="p962546010165634"></a><a name="p962546010165634"></a>Obtains the value of a knob style. </p>
</td>
</tr>
<tr id="row544598128165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727879494165634"><a name="p1727879494165634"></a><a name="p1727879494165634"></a><a href="Graphic.md#ga05029e55d4ccb50cd45f1cd2a53917e4">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1901485280165634"><a name="p1901485280165634"></a><a name="p1901485280165634"></a>void </p>
<p id="p480381530165634"><a name="p480381530165634"></a><a name="p480381530165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1537848855165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1704350793165634"><a name="p1704350793165634"></a><a name="p1704350793165634"></a><a href="Graphic.md#ga4481d4453dbf06cc808e4848a814ed7e">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546677570165634"><a name="p1546677570165634"></a><a name="p1546677570165634"></a>bool </p>
<p id="p882113830165634"><a name="p882113830165634"></a><a name="p882113830165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row612373809165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p430523079165634"><a name="p430523079165634"></a><a name="p430523079165634"></a><a href="Graphic.md#gae9136559779057065708312fb62304bb">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454911881165634"><a name="p1454911881165634"></a><a name="p1454911881165634"></a>bool </p>
<p id="p1902051167165634"><a name="p1902051167165634"></a><a name="p1902051167165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1508677296165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1078332129165634"><a name="p1078332129165634"></a><a name="p1078332129165634"></a><a href="Graphic.md#gaf0483e605613ee1789332e67f00f5e2d">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1824378243165634"><a name="p1824378243165634"></a><a name="p1824378243165634"></a>bool </p>
<p id="p341190379165634"><a name="p341190379165634"></a><a name="p341190379165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1260647109165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1046000551165634"><a name="p1046000551165634"></a><a name="p1046000551165634"></a><a href="Graphic.md#gad6bd59e05d77868e595d087fd2de5d00">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833636566165634"><a name="p833636566165634"></a><a name="p833636566165634"></a>void </p>
<p id="p1501906844165634"><a name="p1501906844165634"></a><a name="p1501906844165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1638590945165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1421920505165634"><a name="p1421920505165634"></a><a name="p1421920505165634"></a><a href="Graphic.md#ga1319a5ea74ad822cb12b0f48c19ccb5d">SetSliderEventListener</a> (<a href="OHOS-UISlider-UISliderEventListener.md">UISliderEventListener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1015864286165634"><a name="p1015864286165634"></a><a name="p1015864286165634"></a>void </p>
<p id="p260124205165634"><a name="p260124205165634"></a><a name="p260124205165634"></a>Sets the listener for a slider change. </p>
</td>
</tr>
<tr id="row1528761590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565820367165634"><a name="p1565820367165634"></a><a name="p1565820367165634"></a><a href="Graphic.md#ga315a532a3e0aa658a64d2f7739483f35">UIBoxProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p385507678165634"><a name="p385507678165634"></a><a name="p385507678165634"></a> </p>
<p id="p776726460165634"><a name="p776726460165634"></a><a name="p776726460165634"></a>A constructor used to create a <strong id="b706836409165634"><a name="b706836409165634"></a><a name="b706836409165634"></a><a href="OHOS-UIBoxProgress.md">UIBoxProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row319935866165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1507679904165634"><a name="p1507679904165634"></a><a name="p1507679904165634"></a><a href="Graphic.md#ga7a5eefc7d4ad253a286444e76146af7f">~UIBoxProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1815933120165634"><a name="p1815933120165634"></a><a name="p1815933120165634"></a>virtual </p>
<p id="p842650711165634"><a name="p842650711165634"></a><a name="p842650711165634"></a>A destructor used to delete the <strong id="b222774227165634"><a name="b222774227165634"></a><a name="b222774227165634"></a><a href="OHOS-UIBoxProgress.md">UIBoxProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1640696678165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p583673220165634"><a name="p583673220165634"></a><a name="p583673220165634"></a><a href="Graphic.md#ga4b3eeb9de2443182480a71cadb23178c">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1453280641165634"><a name="p1453280641165634"></a><a name="p1453280641165634"></a>void </p>
<p id="p1266977611165634"><a name="p1266977611165634"></a><a name="p1266977611165634"></a>Sets the width for the view holding this progress bar. </p>
</td>
</tr>
<tr id="row1286781301165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58516601165634"><a name="p58516601165634"></a><a name="p58516601165634"></a><a href="Graphic.md#ga54299cb7561cee9a03d0fc9d0ddda784">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501261553165634"><a name="p501261553165634"></a><a name="p501261553165634"></a>void </p>
<p id="p1885618989165634"><a name="p1885618989165634"></a><a name="p1885618989165634"></a>Sets the height for this view. </p>
</td>
</tr>
<tr id="row1213204667165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909141262165634"><a name="p1909141262165634"></a><a name="p1909141262165634"></a><a href="Graphic.md#ga3e2e7d0c37b4945a3f4f456c20cb0177">SetDirection</a> (const <a href="Graphic.md#ga4a7a2c192206c8b18379f42a5fd176eb">Direction</a> &amp;direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1057896755165634"><a name="p1057896755165634"></a><a name="p1057896755165634"></a>void </p>
<p id="p314445759165634"><a name="p314445759165634"></a><a name="p314445759165634"></a>Sets the direction for this progress bar. </p>
</td>
</tr>
<tr id="row1343705467165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p953792453165634"><a name="p953792453165634"></a><a name="p953792453165634"></a><a href="Graphic.md#ga493699e8d0e934d7fb3d5502529a1c5e">GetDirection</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308887397165634"><a name="p1308887397165634"></a><a name="p1308887397165634"></a><a href="Graphic.md#ga4a7a2c192206c8b18379f42a5fd176eb">Direction</a> </p>
<p id="p11127999165634"><a name="p11127999165634"></a><a name="p11127999165634"></a>Obtains the direction of this progress bar. </p>
</td>
</tr>
<tr id="row288479635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1961470630165634"><a name="p1961470630165634"></a><a name="p1961470630165634"></a><a href="Graphic.md#gada3cf1819e826ee0aed4a40ef00b91a6">SetValidWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371710456165634"><a name="p371710456165634"></a><a name="p371710456165634"></a>void </p>
<p id="p1922670202165634"><a name="p1922670202165634"></a><a name="p1922670202165634"></a>Sets the actual width for this progress bar. </p>
</td>
</tr>
<tr id="row1007194572165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1541742923165634"><a name="p1541742923165634"></a><a name="p1541742923165634"></a><a href="Graphic.md#ga6577d38d85234e08f709dd0ae131b255">GetValidWidth</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p514720614165634"><a name="p514720614165634"></a><a name="p514720614165634"></a>int16_t </p>
<p id="p1715497666165634"><a name="p1715497666165634"></a><a name="p1715497666165634"></a>Obtains the actual width of this progress bar. </p>
</td>
</tr>
<tr id="row271482070165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1740471734165634"><a name="p1740471734165634"></a><a name="p1740471734165634"></a><a href="Graphic.md#ga6958b8273ad7a5563dfa19267cc3a13c">SetValidHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p74893914165634"><a name="p74893914165634"></a><a name="p74893914165634"></a>void </p>
<p id="p1169935128165634"><a name="p1169935128165634"></a><a name="p1169935128165634"></a>Sets the actual height for this progress bar. </p>
</td>
</tr>
<tr id="row1243240287165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703736964165634"><a name="p1703736964165634"></a><a name="p1703736964165634"></a><a href="Graphic.md#ga1e6c92b20c4931a058c0b7775bf180c9">GetValidHeight</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p512202698165634"><a name="p512202698165634"></a><a name="p512202698165634"></a>int16_t </p>
<p id="p1168301486165634"><a name="p1168301486165634"></a><a name="p1168301486165634"></a>Obtains the actual height of this progress bar. </p>
</td>
</tr>
<tr id="row366396034165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1690068954165634"><a name="p1690068954165634"></a><a name="p1690068954165634"></a><a href="Graphic.md#ga8f9bfb4f42ee0e094501ff776e3336da">UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1884224016165634"><a name="p1884224016165634"></a><a name="p1884224016165634"></a> </p>
<p id="p355371225165634"><a name="p355371225165634"></a><a name="p355371225165634"></a>A constructor used to create a <strong id="b802364370165634"><a name="b802364370165634"></a><a name="b802364370165634"></a><a href="OHOS-UIAbstractProgress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row29543974165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688867913165634"><a name="p688867913165634"></a><a name="p688867913165634"></a><a href="Graphic.md#ga5c1cf7239bf0c0f7d331e63df805b518">~UIAbstractProgress</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p947276746165634"><a name="p947276746165634"></a><a name="p947276746165634"></a>virtual </p>
<p id="p1527873233165634"><a name="p1527873233165634"></a><a name="p1527873233165634"></a>A destructor used to delete the <strong id="b1272634091165634"><a name="b1272634091165634"></a><a name="b1272634091165634"></a><a href="OHOS-UIAbstractProgress.md">UIAbstractProgress</a></strong> instance. </p>
</td>
</tr>
<tr id="row1007135163165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1420201827165634"><a name="p1420201827165634"></a><a name="p1420201827165634"></a><a href="Graphic.md#gacb680c1ddc9135371676df504dc6c8f2">EnableBackground</a> (bool enable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133661237165634"><a name="p2133661237165634"></a><a name="p2133661237165634"></a>void </p>
<p id="p1250948351165634"><a name="p1250948351165634"></a><a name="p1250948351165634"></a>Sets whether the background of the progress bar is visible. </p>
</td>
</tr>
<tr id="row131805704165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p946685997165634"><a name="p946685997165634"></a><a name="p946685997165634"></a><a href="Graphic.md#ga5f65014431a6489ffa1d4949f9c4449b">SetValue</a> (int16_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1284761790165634"><a name="p1284761790165634"></a><a name="p1284761790165634"></a>void </p>
<p id="p1776391524165634"><a name="p1776391524165634"></a><a name="p1776391524165634"></a>Sets the current value for this progress bar. </p>
</td>
</tr>
<tr id="row738675252165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p625437575165634"><a name="p625437575165634"></a><a name="p625437575165634"></a><a href="Graphic.md#ga6face76aa7972efeb6cbb8f525f23135">GetValue</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p625382544165634"><a name="p625382544165634"></a><a name="p625382544165634"></a>int16_t </p>
<p id="p1402123668165634"><a name="p1402123668165634"></a><a name="p1402123668165634"></a>Obtains the current value of this progress bar. </p>
</td>
</tr>
<tr id="row1948082477165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302660589165634"><a name="p1302660589165634"></a><a name="p1302660589165634"></a><a href="Graphic.md#ga089e3875453011499ad33ed89a44a699">SetRange</a> (int16_t rangeMax, int16_t rangeMin)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216300233165634"><a name="p216300233165634"></a><a name="p216300233165634"></a>void </p>
<p id="p1395641725165634"><a name="p1395641725165634"></a><a name="p1395641725165634"></a>Sets the range for this progress bar. </p>
</td>
</tr>
<tr id="row917315521165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1512376810165634"><a name="p1512376810165634"></a><a name="p1512376810165634"></a><a href="Graphic.md#ga68ab733afcf4224a799ccad2092d1d23">GetRangeMin</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1571507420165634"><a name="p1571507420165634"></a><a name="p1571507420165634"></a>int16_t </p>
<p id="p530395474165634"><a name="p530395474165634"></a><a name="p530395474165634"></a>Obtains the minimum value of this progress bar. </p>
</td>
</tr>
<tr id="row2067443986165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964354040165634"><a name="p964354040165634"></a><a name="p964354040165634"></a><a href="Graphic.md#ga1840199f22d5d3e4ef58e41ac8f4febc">GetRangeMax</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p705054458165634"><a name="p705054458165634"></a><a name="p705054458165634"></a>int16_t </p>
<p id="p2077502126165634"><a name="p2077502126165634"></a><a name="p2077502126165634"></a>Obtains the maximum value of this progress bar. </p>
</td>
</tr>
<tr id="row2133541815165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p299166605165634"><a name="p299166605165634"></a><a name="p299166605165634"></a><a href="Graphic.md#ga5b3ec363e391f601e12bf937b9cf77db">SetImage</a> (const char *foregroundImage, const char *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424982588165634"><a name="p424982588165634"></a><a name="p424982588165634"></a>void </p>
<p id="p101267524165634"><a name="p101267524165634"></a><a name="p101267524165634"></a>Sets the image for this progress bar. </p>
</td>
</tr>
<tr id="row23271973165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1412866928165634"><a name="p1412866928165634"></a><a name="p1412866928165634"></a><a href="Graphic.md#ga10723293ab9e384907dd9dacbc9ad448">SetImage</a> (const <a href="OHOS-ImageInfo.md">ImageInfo</a> *foregroundImage, const <a href="OHOS-ImageInfo.md">ImageInfo</a> *backgroundImage=nullptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p317619944165634"><a name="p317619944165634"></a><a name="p317619944165634"></a>void </p>
<p id="p548586402165634"><a name="p548586402165634"></a><a name="p548586402165634"></a>Sets the image as a pixel map for this progress bar. </p>
</td>
</tr>
<tr id="row1772312169165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927478133165634"><a name="p927478133165634"></a><a name="p927478133165634"></a><a href="Graphic.md#ga747a29652b441a06d09a97a297aae9bb">SetStep</a> (uint16_t step)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669196251165634"><a name="p669196251165634"></a><a name="p669196251165634"></a>void </p>
<p id="p880291016165634"><a name="p880291016165634"></a><a name="p880291016165634"></a>Sets the step for this progress bar. </p>
</td>
</tr>
<tr id="row1656742499165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1770020804165634"><a name="p1770020804165634"></a><a name="p1770020804165634"></a><a href="Graphic.md#ga9c1678604605a54c2e338d283c46866d">GetStep</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p252406535165634"><a name="p252406535165634"></a><a name="p252406535165634"></a>uint16_t </p>
<p id="p80263159165634"><a name="p80263159165634"></a><a name="p80263159165634"></a>Obtains the current step of this progress bar. </p>
</td>
</tr>
<tr id="row1859975658165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111042957165634"><a name="p2111042957165634"></a><a name="p2111042957165634"></a><a href="Graphic.md#ga6817b5178e93e5f16f2b420cf5a171c1">SetBackgroundStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413423135165634"><a name="p1413423135165634"></a><a name="p1413423135165634"></a>void </p>
<p id="p1044107025165634"><a name="p1044107025165634"></a><a name="p1044107025165634"></a>Sets the background style for this progress bar. </p>
</td>
</tr>
<tr id="row1213352915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235709430165634"><a name="p235709430165634"></a><a name="p235709430165634"></a><a href="Graphic.md#ga23acea0a42587746e35ec5f3a74af59f">SetBackgroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1876491480165634"><a name="p1876491480165634"></a><a name="p1876491480165634"></a>void </p>
<p id="p127460731165634"><a name="p127460731165634"></a><a name="p127460731165634"></a>Sets a background style for this progress bar. </p>
</td>
</tr>
<tr id="row589387002165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722733660165634"><a name="p1722733660165634"></a><a name="p1722733660165634"></a><a href="Graphic.md#gac2ca1212c23c11405b12ae0a46c7eff1">GetBackgroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1870821460165634"><a name="p1870821460165634"></a><a name="p1870821460165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1379475966165634"><a name="p1379475966165634"></a><a name="p1379475966165634"></a>Obtains the background style of this progress bar. </p>
</td>
</tr>
<tr id="row746719038165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p68968429165634"><a name="p68968429165634"></a><a name="p68968429165634"></a><a href="Graphic.md#ga946d3f2c39a79d45149118536b2557a9">GetBackgroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p686370237165634"><a name="p686370237165634"></a><a name="p686370237165634"></a>int64_t </p>
<p id="p1774945944165634"><a name="p1774945944165634"></a><a name="p1774945944165634"></a>Obtains the value of a background style of this progress bar. </p>
</td>
</tr>
<tr id="row1600366759165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200189418165634"><a name="p1200189418165634"></a><a name="p1200189418165634"></a><a href="Graphic.md#gaccebcfa35f98f9bc6be4bb8cc53eb11c">SetForegroundStyle</a> (const <a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p771252142165634"><a name="p771252142165634"></a><a name="p771252142165634"></a>void </p>
<p id="p769062285165634"><a name="p769062285165634"></a><a name="p769062285165634"></a>Sets the foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row1065034701165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1204846828165634"><a name="p1204846828165634"></a><a name="p1204846828165634"></a><a href="Graphic.md#gae6386ca25603e42f06087f6b2ef65bae">SetForegroundStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612365302165634"><a name="p1612365302165634"></a><a name="p1612365302165634"></a>void </p>
<p id="p1571156355165634"><a name="p1571156355165634"></a><a name="p1571156355165634"></a>Sets a foreground style for this progress bar. </p>
</td>
</tr>
<tr id="row1285965241165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1581699163165634"><a name="p1581699163165634"></a><a name="p1581699163165634"></a><a href="Graphic.md#gac77f945f375f333f80bd70254b5c1f96">GetForegroundStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690069263165634"><a name="p690069263165634"></a><a name="p690069263165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p813260701165634"><a name="p813260701165634"></a><a name="p813260701165634"></a>Obtains the foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row1055359028165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1951418553165634"><a name="p1951418553165634"></a><a name="p1951418553165634"></a><a href="Graphic.md#ga74cd121dd1794d7e8d905b233bd98217">GetForegroundStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1954714617165634"><a name="p1954714617165634"></a><a name="p1954714617165634"></a>int64_t </p>
<p id="p4075384165634"><a name="p4075384165634"></a><a name="p4075384165634"></a>Obtains the value of a foreground style of this progress bar. </p>
</td>
</tr>
<tr id="row286471056165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136354619165634"><a name="p1136354619165634"></a><a name="p1136354619165634"></a><a href="Graphic.md#gabdc0eb4d279212ea7c3ea7a1f9a85e13">SetCapType</a> (<a href="Graphic.md#ga2db3928cdf793f4950245a6841dd43d6">CapType</a> cap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696745304165634"><a name="p1696745304165634"></a><a name="p1696745304165634"></a>void </p>
<p id="p1801401053165634"><a name="p1801401053165634"></a><a name="p1801401053165634"></a>Sets the type of caps on the background and foreground of the progress bar. </p>
</td>
</tr>
<tr id="row1987768101165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707833345165634"><a name="p1707833345165634"></a><a name="p1707833345165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034178567165634"><a name="p2034178567165634"></a><a name="p2034178567165634"></a> </p>
<p id="p1382303774165634"><a name="p1382303774165634"></a><a name="p1382303774165634"></a>A default constructor used to create an <strong id="b123515017165634"><a name="b123515017165634"></a><a name="b123515017165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row216639869165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1476918358165634"><a name="p1476918358165634"></a><a name="p1476918358165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1075649263165634"><a name="p1075649263165634"></a><a name="p1075649263165634"></a> </p>
<p id="p359465346165634"><a name="p359465346165634"></a><a name="p359465346165634"></a>A constructor used to create an <strong id="b1876949424165634"><a name="b1876949424165634"></a><a name="b1876949424165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1442173352165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273401681165634"><a name="p1273401681165634"></a><a name="p1273401681165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954212481165634"><a name="p954212481165634"></a><a name="p954212481165634"></a>virtual </p>
<p id="p1703078330165634"><a name="p1703078330165634"></a><a name="p1703078330165634"></a>A destructor used to delete the <strong id="b1264324803165634"><a name="b1264324803165634"></a><a name="b1264324803165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1888821696165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1842656778165634"><a name="p1842656778165634"></a><a name="p1842656778165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1101086663165634"><a name="p1101086663165634"></a><a name="p1101086663165634"></a>virtual void </p>
<p id="p804810092165634"><a name="p804810092165634"></a><a name="p804810092165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row32024812165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p240064214165634"><a name="p240064214165634"></a><a name="p240064214165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p651168844165634"><a name="p651168844165634"></a><a name="p651168844165634"></a>virtual void </p>
<p id="p1290278998165634"><a name="p1290278998165634"></a><a name="p1290278998165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1507374816165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1447339812165634"><a name="p1447339812165634"></a><a name="p1447339812165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1337877669165634"><a name="p1337877669165634"></a><a name="p1337877669165634"></a>void </p>
<p id="p1758601604165634"><a name="p1758601604165634"></a><a name="p1758601604165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1419353821165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p643036450165634"><a name="p643036450165634"></a><a name="p643036450165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p94580761165634"><a name="p94580761165634"></a><a name="p94580761165634"></a>void </p>
<p id="p922774176165634"><a name="p922774176165634"></a><a name="p922774176165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1199015672165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1531974157165634"><a name="p1531974157165634"></a><a name="p1531974157165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346165970165634"><a name="p346165970165634"></a><a name="p346165970165634"></a>virtual bool </p>
<p id="p346060419165634"><a name="p346060419165634"></a><a name="p346060419165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1509855479165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1404939488165634"><a name="p1404939488165634"></a><a name="p1404939488165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p303423148165634"><a name="p303423148165634"></a><a name="p303423148165634"></a>virtual bool </p>
<p id="p742331502165634"><a name="p742331502165634"></a><a name="p742331502165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row768376421165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911541957165634"><a name="p1911541957165634"></a><a name="p1911541957165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1396882586165634"><a name="p1396882586165634"></a><a name="p1396882586165634"></a>virtual void </p>
<p id="p1255918822165634"><a name="p1255918822165634"></a><a name="p1255918822165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1360215646165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866560140165634"><a name="p866560140165634"></a><a name="p866560140165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733574036165634"><a name="p733574036165634"></a><a name="p733574036165634"></a>virtual void </p>
<p id="p1576197495165634"><a name="p1576197495165634"></a><a name="p1576197495165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1419795531165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051334951165634"><a name="p2051334951165634"></a><a name="p2051334951165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1366009165634"><a name="p1366009165634"></a><a name="p1366009165634"></a>virtual void </p>
<p id="p2022034993165634"><a name="p2022034993165634"></a><a name="p2022034993165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1131559138165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1839192221165634"><a name="p1839192221165634"></a><a name="p1839192221165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534224289165634"><a name="p1534224289165634"></a><a name="p1534224289165634"></a>void </p>
<p id="p317867761165634"><a name="p317867761165634"></a><a name="p317867761165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row116578017165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2021238756165634"><a name="p2021238756165634"></a><a name="p2021238756165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p716799578165634"><a name="p716799578165634"></a><a name="p716799578165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1052966290165634"><a name="p1052966290165634"></a><a name="p1052966290165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row138899081165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1968719078165634"><a name="p1968719078165634"></a><a name="p1968719078165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523876173165634"><a name="p523876173165634"></a><a name="p523876173165634"></a>void </p>
<p id="p223070113165634"><a name="p223070113165634"></a><a name="p223070113165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row2074297399165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p762734078165634"><a name="p762734078165634"></a><a name="p762734078165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p315399750165634"><a name="p315399750165634"></a><a name="p315399750165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p920390392165634"><a name="p920390392165634"></a><a name="p920390392165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row82862699165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285148246165634"><a name="p1285148246165634"></a><a name="p1285148246165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900037145165634"><a name="p1900037145165634"></a><a name="p1900037145165634"></a>void </p>
<p id="p655886561165634"><a name="p655886561165634"></a><a name="p655886561165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1919356770165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p615665923165634"><a name="p615665923165634"></a><a name="p615665923165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p530759181165634"><a name="p530759181165634"></a><a name="p530759181165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p387547160165634"><a name="p387547160165634"></a><a name="p387547160165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1508623428165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p652763732165634"><a name="p652763732165634"></a><a name="p652763732165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637384550165634"><a name="p1637384550165634"></a><a name="p1637384550165634"></a>void </p>
<p id="p1649618151165634"><a name="p1649618151165634"></a><a name="p1649618151165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1135174290165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p793004815165634"><a name="p793004815165634"></a><a name="p793004815165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273575597165634"><a name="p273575597165634"></a><a name="p273575597165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p141741976165634"><a name="p141741976165634"></a><a name="p141741976165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row712640357165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1173589900165634"><a name="p1173589900165634"></a><a name="p1173589900165634"></a><a href="Graphic.md#gaea9f334f2481e1c03a2cd8f3078d7c72">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836748147165634"><a name="p1836748147165634"></a><a name="p1836748147165634"></a>virtual void </p>
<p id="p997029812165634"><a name="p997029812165634"></a><a name="p997029812165634"></a>Obtains the top-level view based on specified coordinates. </p>
</td>
</tr>
<tr id="row1803093085165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p291079456165634"><a name="p291079456165634"></a><a name="p291079456165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1827431276165634"><a name="p1827431276165634"></a><a name="p1827431276165634"></a>void </p>
<p id="p1132925156165634"><a name="p1132925156165634"></a><a name="p1132925156165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1027206418165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1012680718165634"><a name="p1012680718165634"></a><a name="p1012680718165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575659283165634"><a name="p575659283165634"></a><a name="p575659283165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p773292375165634"><a name="p773292375165634"></a><a name="p773292375165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row910005267165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p891664798165634"><a name="p891664798165634"></a><a name="p891664798165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544201871165634"><a name="p1544201871165634"></a><a name="p1544201871165634"></a>void </p>
<p id="p1238876001165634"><a name="p1238876001165634"></a><a name="p1238876001165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row330542268165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p375578365165634"><a name="p375578365165634"></a><a name="p375578365165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p640359165165634"><a name="p640359165165634"></a><a name="p640359165165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p166738672165634"><a name="p166738672165634"></a><a name="p166738672165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row2109802205165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p329914348165634"><a name="p329914348165634"></a><a name="p329914348165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p599255837165634"><a name="p599255837165634"></a><a name="p599255837165634"></a>virtual void </p>
<p id="p1942283280165634"><a name="p1942283280165634"></a><a name="p1942283280165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row891365168165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1081474353165634"><a name="p1081474353165634"></a><a name="p1081474353165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p757329650165634"><a name="p757329650165634"></a><a name="p757329650165634"></a>bool </p>
<p id="p865920905165634"><a name="p865920905165634"></a><a name="p865920905165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1222042274165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1046084360165634"><a name="p1046084360165634"></a><a name="p1046084360165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090570480165634"><a name="p2090570480165634"></a><a name="p2090570480165634"></a>void </p>
<p id="p1742796662165634"><a name="p1742796662165634"></a><a name="p1742796662165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row120230688165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1850331374165634"><a name="p1850331374165634"></a><a name="p1850331374165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1199679011165634"><a name="p1199679011165634"></a><a name="p1199679011165634"></a>bool </p>
<p id="p1297967689165634"><a name="p1297967689165634"></a><a name="p1297967689165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1565555763165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p577483483165634"><a name="p577483483165634"></a><a name="p577483483165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137243170165634"><a name="p137243170165634"></a><a name="p137243170165634"></a>void </p>
<p id="p1205183110165634"><a name="p1205183110165634"></a><a name="p1205183110165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1639501380165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848461662165634"><a name="p1848461662165634"></a><a name="p1848461662165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2017660356165634"><a name="p2017660356165634"></a><a name="p2017660356165634"></a>bool </p>
<p id="p1749206738165634"><a name="p1749206738165634"></a><a name="p1749206738165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row553732786165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481764073165634"><a name="p481764073165634"></a><a name="p481764073165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504182406165634"><a name="p1504182406165634"></a><a name="p1504182406165634"></a>void </p>
<p id="p1733542353165634"><a name="p1733542353165634"></a><a name="p1733542353165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row2129801186165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1973596956165634"><a name="p1973596956165634"></a><a name="p1973596956165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608739943165634"><a name="p608739943165634"></a><a name="p608739943165634"></a>bool </p>
<p id="p1623420314165634"><a name="p1623420314165634"></a><a name="p1623420314165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row825521885165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249869935165634"><a name="p249869935165634"></a><a name="p249869935165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2051968054165634"><a name="p2051968054165634"></a><a name="p2051968054165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p822145322165634"><a name="p822145322165634"></a><a name="p822145322165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1682545714165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1649014831165634"><a name="p1649014831165634"></a><a name="p1649014831165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p818719559165634"><a name="p818719559165634"></a><a name="p818719559165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1905920319165634"><a name="p1905920319165634"></a><a name="p1905920319165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row61961299165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1320540667165634"><a name="p1320540667165634"></a><a name="p1320540667165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132850981165634"><a name="p2132850981165634"></a><a name="p2132850981165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1056214162165634"><a name="p1056214162165634"></a><a name="p1056214162165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1121718711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p590330944165634"><a name="p590330944165634"></a><a name="p590330944165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p671204506165634"><a name="p671204506165634"></a><a name="p671204506165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p315896213165634"><a name="p315896213165634"></a><a name="p315896213165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1498532651165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1725298213165634"><a name="p1725298213165634"></a><a name="p1725298213165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236802941165634"><a name="p236802941165634"></a><a name="p236802941165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p814108172165634"><a name="p814108172165634"></a><a name="p814108172165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row649849379165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1689444094165634"><a name="p1689444094165634"></a><a name="p1689444094165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p378485374165634"><a name="p378485374165634"></a><a name="p378485374165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p400917314165634"><a name="p400917314165634"></a><a name="p400917314165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row233505962165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120649316165634"><a name="p2120649316165634"></a><a name="p2120649316165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1720891498165634"><a name="p1720891498165634"></a><a name="p1720891498165634"></a>void </p>
<p id="p895595222165634"><a name="p895595222165634"></a><a name="p895595222165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1401336227165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1235398756165634"><a name="p1235398756165634"></a><a name="p1235398756165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462401490165634"><a name="p462401490165634"></a><a name="p462401490165634"></a>virtual int16_t </p>
<p id="p1356091375165634"><a name="p1356091375165634"></a><a name="p1356091375165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row880955777165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p845003724165634"><a name="p845003724165634"></a><a name="p845003724165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677504126165634"><a name="p1677504126165634"></a><a name="p1677504126165634"></a>virtual int16_t </p>
<p id="p1763269971165634"><a name="p1763269971165634"></a><a name="p1763269971165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row191615513165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1513749804165634"><a name="p1513749804165634"></a><a name="p1513749804165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1653944782165634"><a name="p1653944782165634"></a><a name="p1653944782165634"></a>virtual void </p>
<p id="p9719803165634"><a name="p9719803165634"></a><a name="p9719803165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1726145057165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1369613141165634"><a name="p1369613141165634"></a><a name="p1369613141165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413875377165634"><a name="p413875377165634"></a><a name="p413875377165634"></a>virtual void </p>
<p id="p1362563940165634"><a name="p1362563940165634"></a><a name="p1362563940165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1892381406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1037764722165634"><a name="p1037764722165634"></a><a name="p1037764722165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55333942165634"><a name="p55333942165634"></a><a name="p55333942165634"></a>int16_t </p>
<p id="p1037230536165634"><a name="p1037230536165634"></a><a name="p1037230536165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row927239799165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p540428690165634"><a name="p540428690165634"></a><a name="p540428690165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p918340870165634"><a name="p918340870165634"></a><a name="p918340870165634"></a>virtual void </p>
<p id="p197525903165634"><a name="p197525903165634"></a><a name="p197525903165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row206137398165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p797278554165634"><a name="p797278554165634"></a><a name="p797278554165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2344758165634"><a name="p2344758165634"></a><a name="p2344758165634"></a>int16_t </p>
<p id="p933251066165634"><a name="p933251066165634"></a><a name="p933251066165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row682883880165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1939939887165634"><a name="p1939939887165634"></a><a name="p1939939887165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p420596475165634"><a name="p420596475165634"></a><a name="p420596475165634"></a>virtual void </p>
<p id="p65573075165634"><a name="p65573075165634"></a><a name="p65573075165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1221264720165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20333696165634"><a name="p20333696165634"></a><a name="p20333696165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75757359165634"><a name="p75757359165634"></a><a name="p75757359165634"></a>virtual void </p>
<p id="p452637453165634"><a name="p452637453165634"></a><a name="p452637453165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row691794159165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452100508165634"><a name="p1452100508165634"></a><a name="p1452100508165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794330395165634"><a name="p794330395165634"></a><a name="p794330395165634"></a>bool </p>
<p id="p482951361165634"><a name="p482951361165634"></a><a name="p482951361165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row2041293375165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1198718305165634"><a name="p1198718305165634"></a><a name="p1198718305165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1380427911165634"><a name="p1380427911165634"></a><a name="p1380427911165634"></a>void </p>
<p id="p659300551165634"><a name="p659300551165634"></a><a name="p659300551165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1257590643165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p876711978165634"><a name="p876711978165634"></a><a name="p876711978165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453603322165634"><a name="p453603322165634"></a><a name="p453603322165634"></a>void </p>
<p id="p759849919165634"><a name="p759849919165634"></a><a name="p759849919165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row581153157165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1664017417165634"><a name="p1664017417165634"></a><a name="p1664017417165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973497337165634"><a name="p973497337165634"></a><a name="p973497337165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p136307165634"><a name="p136307165634"></a><a name="p136307165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row214048456165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4103241165634"><a name="p4103241165634"></a><a name="p4103241165634"></a><a href="Graphic.md#ga0573aa25307c22319db4629781b5cad2">GetChildById</a> (const char *id) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1482964355165634"><a name="p1482964355165634"></a><a name="p1482964355165634"></a>virtual <a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1181176472165634"><a name="p1181176472165634"></a><a name="p1181176472165634"></a>Obtains the child view of a specified ID. </p>
</td>
</tr>
<tr id="row995467337165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1304991401165634"><a name="p1304991401165634"></a><a name="p1304991401165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p626947783165634"><a name="p626947783165634"></a><a name="p626947783165634"></a>void </p>
<p id="p9361036165634"><a name="p9361036165634"></a><a name="p9361036165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1205091183165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1025691155165634"><a name="p1025691155165634"></a><a name="p1025691155165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1747738678165634"><a name="p1747738678165634"></a><a name="p1747738678165634"></a>const char * </p>
<p id="p1066777589165634"><a name="p1066777589165634"></a><a name="p1066777589165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1217075267165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1795245766165634"><a name="p1795245766165634"></a><a name="p1795245766165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250165875165634"><a name="p250165875165634"></a><a name="p250165875165634"></a>void </p>
<p id="p83727846165634"><a name="p83727846165634"></a><a name="p83727846165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1504873662165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1459144916165634"><a name="p1459144916165634"></a><a name="p1459144916165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p376939024165634"><a name="p376939024165634"></a><a name="p376939024165634"></a>int16_t </p>
<p id="p1139814011165634"><a name="p1139814011165634"></a><a name="p1139814011165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row393805443165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1395674636165634"><a name="p1395674636165634"></a><a name="p1395674636165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2112743261165634"><a name="p2112743261165634"></a><a name="p2112743261165634"></a>virtual void </p>
<p id="p1107795944165634"><a name="p1107795944165634"></a><a name="p1107795944165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row673104420165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p715705221165634"><a name="p715705221165634"></a><a name="p715705221165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1429555673165634"><a name="p1429555673165634"></a><a name="p1429555673165634"></a>void </p>
<p id="p349258869165634"><a name="p349258869165634"></a><a name="p349258869165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1536536555165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p371918718165634"><a name="p371918718165634"></a><a name="p371918718165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1644576334165634"><a name="p1644576334165634"></a><a name="p1644576334165634"></a>void </p>
<p id="p1439391126165634"><a name="p1439391126165634"></a><a name="p1439391126165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1278726334165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1249671838165634"><a name="p1249671838165634"></a><a name="p1249671838165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1857316861165634"><a name="p1857316861165634"></a><a name="p1857316861165634"></a>void </p>
<p id="p1015041302165634"><a name="p1015041302165634"></a><a name="p1015041302165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1993003725165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p455546693165634"><a name="p455546693165634"></a><a name="p455546693165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1804805428165634"><a name="p1804805428165634"></a><a name="p1804805428165634"></a>void </p>
<p id="p611247256165634"><a name="p611247256165634"></a><a name="p611247256165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row199285287165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p872157556165634"><a name="p872157556165634"></a><a name="p872157556165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1830522764165634"><a name="p1830522764165634"></a><a name="p1830522764165634"></a>void </p>
<p id="p656538706165634"><a name="p656538706165634"></a><a name="p656538706165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row933876315165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1988911479165634"><a name="p1988911479165634"></a><a name="p1988911479165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234807200165634"><a name="p1234807200165634"></a><a name="p1234807200165634"></a>void </p>
<p id="p1959765545165634"><a name="p1959765545165634"></a><a name="p1959765545165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1839878621165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1143204224165634"><a name="p1143204224165634"></a><a name="p1143204224165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2037738160165634"><a name="p2037738160165634"></a><a name="p2037738160165634"></a>void </p>
<p id="p1576066348165634"><a name="p1576066348165634"></a><a name="p1576066348165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1010076603165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300768347165634"><a name="p1300768347165634"></a><a name="p1300768347165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1310753642165634"><a name="p1310753642165634"></a><a name="p1310753642165634"></a>void </p>
<p id="p1253121741165634"><a name="p1253121741165634"></a><a name="p1253121741165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row571295625165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1655722234165634"><a name="p1655722234165634"></a><a name="p1655722234165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p612932816165634"><a name="p612932816165634"></a><a name="p612932816165634"></a>void </p>
<p id="p226887713165634"><a name="p226887713165634"></a><a name="p226887713165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1880777468165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223433432165634"><a name="p1223433432165634"></a><a name="p1223433432165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p80777207165634"><a name="p80777207165634"></a><a name="p80777207165634"></a>void </p>
<p id="p1044435797165634"><a name="p1044435797165634"></a><a name="p1044435797165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1498087881165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p99257734165634"><a name="p99257734165634"></a><a name="p99257734165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p977590689165634"><a name="p977590689165634"></a><a name="p977590689165634"></a>void </p>
<p id="p655611615165634"><a name="p655611615165634"></a><a name="p655611615165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row30589375165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790613168165634"><a name="p1790613168165634"></a><a name="p1790613168165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p928693288165634"><a name="p928693288165634"></a><a name="p928693288165634"></a>void </p>
<p id="p838348631165634"><a name="p838348631165634"></a><a name="p838348631165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row96539422165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223165672165634"><a name="p1223165672165634"></a><a name="p1223165672165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261274786165634"><a name="p1261274786165634"></a><a name="p1261274786165634"></a>void </p>
<p id="p953292219165634"><a name="p953292219165634"></a><a name="p953292219165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1000067027165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p707193719165634"><a name="p707193719165634"></a><a name="p707193719165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p136834705165634"><a name="p136834705165634"></a><a name="p136834705165634"></a>void </p>
<p id="p480654993165634"><a name="p480654993165634"></a><a name="p480654993165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row797730694165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1742069755165634"><a name="p1742069755165634"></a><a name="p1742069755165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095793220165634"><a name="p2095793220165634"></a><a name="p2095793220165634"></a>void </p>
<p id="p1509504858165634"><a name="p1509504858165634"></a><a name="p1509504858165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row2094763915165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1732206895165634"><a name="p1732206895165634"></a><a name="p1732206895165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p954361669165634"><a name="p954361669165634"></a><a name="p954361669165634"></a>void </p>
<p id="p2079195532165634"><a name="p2079195532165634"></a><a name="p2079195532165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row2068230040165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1079810414165634"><a name="p1079810414165634"></a><a name="p1079810414165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679554268165634"><a name="p679554268165634"></a><a name="p679554268165634"></a>virtual void </p>
<p id="p127835491165634"><a name="p127835491165634"></a><a name="p127835491165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1118735306165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1301675355165634"><a name="p1301675355165634"></a><a name="p1301675355165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88825172165634"><a name="p88825172165634"></a><a name="p88825172165634"></a>virtual int64_t </p>
<p id="p318233784165634"><a name="p318233784165634"></a><a name="p318233784165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1236402218165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1976979944165634"><a name="p1976979944165634"></a><a name="p1976979944165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1648295727165634"><a name="p1648295727165634"></a><a name="p1648295727165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p491330711165634"><a name="p491330711165634"></a><a name="p491330711165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row336788099165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2040882287165634"><a name="p2040882287165634"></a><a name="p2040882287165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474896849165634"><a name="p474896849165634"></a><a name="p474896849165634"></a>void * </p>
<p id="p961701668165634"><a name="p961701668165634"></a><a name="p961701668165634"></a>Overrides the <strong id="b443247004165634"><a name="b443247004165634"></a><a name="b443247004165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row410433549165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1305265354165634"><a name="p1305265354165634"></a><a name="p1305265354165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787152992165634"><a name="p787152992165634"></a><a name="p787152992165634"></a>void </p>
<p id="p2078649185165634"><a name="p2078649185165634"></a><a name="p2078649185165634"></a>Overrides the <strong id="b99079335165634"><a name="b99079335165634"></a><a name="b99079335165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1100695776165634"></a>
<table><thead align="left"><tr id="row753845920165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1368517694165634"><a name="p1368517694165634"></a><a name="p1368517694165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1326578899165634"><a name="p1326578899165634"></a><a name="p1326578899165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1129320235165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1794732552165634"><a name="p1794732552165634"></a><a name="p1794732552165634"></a><a href="Graphic.md#ga4a7a2c192206c8b18379f42a5fd176eb">Direction</a> : uint8_t { <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba43cb7d46f0e18f315d43b82024093b51">Direction::DIR_LEFT_TO_RIGHT</a>, <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba49e31df5a7fc02ee8c2f85b5e15f0145">Direction::DIR_RIGHT_TO_LEFT</a>, <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba68baeaa89ae4576fc3d9ac732f87a116">Direction::DIR_TOP_TO_BOTTOM</a>, <a href="Graphic.md#gga4a7a2c192206c8b18379f42a5fd176eba78b28982b481790c740bc9b2c1292baa">Direction::DIR_BOTTOM_TO_TOP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1007821506165634"><a name="p1007821506165634"></a><a name="p1007821506165634"></a>Enumerates the directions of the progress bar. </p>
</td>
</tr>
</tbody>
</table>

