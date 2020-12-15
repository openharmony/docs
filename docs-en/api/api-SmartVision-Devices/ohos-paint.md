# OHOS::Paint<a name="EN-US_TOPIC_0000001055078161"></a>

-   [Overview](#section1608281812165634)
-   [Summary](#section757770120165634)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section1608281812165634"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Defines the basic styles of graphs drawn on canvases. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section757770120165634"></a>

## Public Types<a name="pub-types"></a>

<a name="table1392231340165634"></a>
<table><thead align="left"><tr id="row215063919165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1653489585165634"><a name="p1653489585165634"></a><a name="p1653489585165634"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p895801104165634"><a name="p895801104165634"></a><a name="p895801104165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1893458424165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1698399417165634"><a name="p1698399417165634"></a><a name="p1698399417165634"></a><a href="graphic.md#ga548320a469b7862fa416af062cad5d7a">PaintStyle</a> { <a href="graphic.md#gga548320a469b7862fa416af062cad5d7aa16a9f85a0cca54cb2e20bb58a6a41a41">STROKE_STYLE</a> = 1, <a href="graphic.md#gga548320a469b7862fa416af062cad5d7aa706e9d250b4f9ef43008dcd61eb67bb6">FILL_STYLE</a>, <a href="graphic.md#gga548320a469b7862fa416af062cad5d7aa30415cae54bf38e3275e847b5ab3ef1c">STROKE_FILL_STYLE</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533466512165634"><a name="p533466512165634"></a><a name="p533466512165634"></a>Enumerates paint styles of a closed graph. The styles are invalid for non-closed graphs. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table339654757165634"></a>
<table><thead align="left"><tr id="row1759182154165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p239183635165634"><a name="p239183635165634"></a><a name="p239183635165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p56459936165634"><a name="p56459936165634"></a><a name="p56459936165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1131110127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p309523746165634"><a name="p309523746165634"></a><a name="p309523746165634"></a><a href="graphic.md#ga68ecc0cb6bc379284fd1fbaebb8dcfcd">Paint</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1236119737165634"><a name="p1236119737165634"></a><a name="p1236119737165634"></a> </p>
<p id="p146184701165634"><a name="p146184701165634"></a><a name="p146184701165634"></a>A constructor used to create a <strong id="b1005580353165634"><a name="b1005580353165634"></a><a name="b1005580353165634"></a><a href="ohos-paint.md">Paint</a></strong> instance. </p>
</td>
</tr>
<tr id="row106794390165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p305453845165634"><a name="p305453845165634"></a><a name="p305453845165634"></a><a href="graphic.md#ga53f5ef8053f9e468a2fcf6c81449d16d">~Paint</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492284052165634"><a name="p1492284052165634"></a><a name="p1492284052165634"></a>virtual </p>
<p id="p1055142511165634"><a name="p1055142511165634"></a><a name="p1055142511165634"></a>A destructor used to delete the <strong id="b739039538165634"><a name="b739039538165634"></a><a name="b739039538165634"></a><a href="ohos-paint.md">Paint</a></strong> instance. </p>
</td>
</tr>
<tr id="row455024755165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1172485942165634"><a name="p1172485942165634"></a><a name="p1172485942165634"></a><a href="graphic.md#gab93dc15f466a656150e62d7620d34333">SetStyle</a> (<a href="graphic.md#ga548320a469b7862fa416af062cad5d7a">PaintStyle</a> style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p444014318165634"><a name="p444014318165634"></a><a name="p444014318165634"></a>void </p>
<p id="p169833901165634"><a name="p169833901165634"></a><a name="p169833901165634"></a>Sets the paint style of a closed graph. </p>
</td>
</tr>
<tr id="row836922792165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1034015968165634"><a name="p1034015968165634"></a><a name="p1034015968165634"></a><a href="graphic.md#ga18429dcf1a0dfbe0bf3e5718efa65128">GetStyle</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783913196165634"><a name="p783913196165634"></a><a name="p783913196165634"></a><a href="graphic.md#ga548320a469b7862fa416af062cad5d7a">PaintStyle</a> </p>
<p id="p1411499676165634"><a name="p1411499676165634"></a><a name="p1411499676165634"></a>Obtains the paint style of a closed graph. </p>
</td>
</tr>
<tr id="row742250383165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673384006165634"><a name="p673384006165634"></a><a name="p673384006165634"></a><a href="graphic.md#gad56b6b014e1d061ba93ba8e6c135b90a">SetStrokeWidth</a> (uint16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p129865907165634"><a name="p129865907165634"></a><a name="p129865907165634"></a>void </p>
<p id="p7888841165634"><a name="p7888841165634"></a><a name="p7888841165634"></a>Sets the width of a line or border. </p>
</td>
</tr>
<tr id="row1510225373165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757381944165634"><a name="p757381944165634"></a><a name="p757381944165634"></a><a href="graphic.md#gaf8420a460f4a21c9208674e07893c3f0">GetStrokeWidth</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258287946165634"><a name="p258287946165634"></a><a name="p258287946165634"></a>uint16_t </p>
<p id="p1420446072165634"><a name="p1420446072165634"></a><a name="p1420446072165634"></a>Obtains the width of a line or border. </p>
</td>
</tr>
<tr id="row1226207493165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2057775513165634"><a name="p2057775513165634"></a><a name="p2057775513165634"></a><a href="graphic.md#gaff7464c7456b1e7caf9464ff61ab2527">SetStrokeColor</a> (<a href="ohos-color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1946395163165634"><a name="p1946395163165634"></a><a name="p1946395163165634"></a>void </p>
<p id="p232952289165634"><a name="p232952289165634"></a><a name="p232952289165634"></a>Sets the color of a line or border. </p>
</td>
</tr>
<tr id="row2124904165165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1921028960165634"><a name="p1921028960165634"></a><a name="p1921028960165634"></a><a href="graphic.md#gaf9dba05cf9c9f91853a523d961e76fb1">GetStrokeColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p895862045165634"><a name="p895862045165634"></a><a name="p895862045165634"></a><a href="ohos-color32.md">ColorType</a> </p>
<p id="p414854768165634"><a name="p414854768165634"></a><a name="p414854768165634"></a>Obtains the color of a line or border. </p>
</td>
</tr>
<tr id="row124707771165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p789722065165634"><a name="p789722065165634"></a><a name="p789722065165634"></a><a href="graphic.md#gab1b0e3a5e21ce2ec8454311ed31956ae">SetFillColor</a> (<a href="ohos-color32.md">ColorType</a> color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p495448979165634"><a name="p495448979165634"></a><a name="p495448979165634"></a>void </p>
<p id="p274743150165634"><a name="p274743150165634"></a><a name="p274743150165634"></a>Sets fill color. </p>
</td>
</tr>
<tr id="row1960935735165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1325062622165634"><a name="p1325062622165634"></a><a name="p1325062622165634"></a><a href="graphic.md#gadc1b88c39670f103e0c84a089e2178cf">GetFillColor</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744489354165634"><a name="p1744489354165634"></a><a name="p1744489354165634"></a><a href="ohos-color32.md">ColorType</a> </p>
<p id="p1462064907165634"><a name="p1462064907165634"></a><a name="p1462064907165634"></a>Obtains the fill color. </p>
</td>
</tr>
<tr id="row972701281165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p837529617165634"><a name="p837529617165634"></a><a name="p837529617165634"></a><a href="graphic.md#gacd329fb89bbf6f0e3fd4f9a61f4ce60f">SetOpacity</a> (uint8_t opacity)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064756805165634"><a name="p2064756805165634"></a><a name="p2064756805165634"></a>void </p>
<p id="p2080511134165634"><a name="p2080511134165634"></a><a name="p2080511134165634"></a>Sets the opacity. </p>
</td>
</tr>
<tr id="row183741147165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49471964165634"><a name="p49471964165634"></a><a name="p49471964165634"></a><a href="graphic.md#ga3a47fccd734ec0e79af89bedacdd4357">GetOpacity</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1708402357165634"><a name="p1708402357165634"></a><a name="p1708402357165634"></a>uint8_t </p>
<p id="p1227802135165634"><a name="p1227802135165634"></a><a name="p1227802135165634"></a>Obtains the opacity. </p>
</td>
</tr>
<tr id="row2099790498165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p454398146165634"><a name="p454398146165634"></a><a name="p454398146165634"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1713238582165634"><a name="p1713238582165634"></a><a name="p1713238582165634"></a>void * </p>
<p id="p1426152390165634"><a name="p1426152390165634"></a><a name="p1426152390165634"></a>Overrides the <strong id="b1919687634165634"><a name="b1919687634165634"></a><a name="b1919687634165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1208709897165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997522960165634"><a name="p1997522960165634"></a><a name="p1997522960165634"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p713686577165634"><a name="p713686577165634"></a><a name="p713686577165634"></a>void </p>
<p id="p561272006165634"><a name="p561272006165634"></a><a name="p561272006165634"></a>Overrides the <strong id="b1344123947165634"><a name="b1344123947165634"></a><a name="b1344123947165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

