# OHOS::FlexLayout<a name="ZH-CN_TOPIC_0000001055078171"></a>

-   [Overview](#section1219905753165635)
-   [Summary](#section738607815165635)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1219905753165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines a flexible layout container. You can perform simple adaptive layout on child views that the container holds, for example, to evenly arrange all child views in the same row or column. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section738607815165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1697305738165635"></a>
<table><thead align="left"><tr id="row1742078567165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1582305999165635"><a name="p1582305999165635"></a><a name="p1582305999165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p416726655165635"><a name="p416726655165635"></a><a name="p416726655165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row116094246165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487936639165635"><a name="p487936639165635"></a><a name="p487936639165635"></a><a href="Graphic.md#gac06da499194705b22e31a8a78022ceab">FlexLayout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p822551148165635"><a name="p822551148165635"></a><a name="p822551148165635"></a> </p>
<p id="p886758170165635"><a name="p886758170165635"></a><a name="p886758170165635"></a>A default constructor used to create a <strong id="b923749426165635"><a name="b923749426165635"></a><a name="b923749426165635"></a><a href="OHOS-FlexLayout.md">FlexLayout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1904106934165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p323873708165635"><a name="p323873708165635"></a><a name="p323873708165635"></a><a href="Graphic.md#gada390db4ca762cf1dac06abfcd74e543">~FlexLayout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2058388324165635"><a name="p2058388324165635"></a><a name="p2058388324165635"></a>virtual </p>
<p id="p1831468855165635"><a name="p1831468855165635"></a><a name="p1831468855165635"></a>A destructor used to delete the <strong id="b1954183060165635"><a name="b1954183060165635"></a><a name="b1954183060165635"></a><a href="OHOS-FlexLayout.md">FlexLayout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1945895954165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1166318777165635"><a name="p1166318777165635"></a><a name="p1166318777165635"></a><a href="Graphic.md#gaa683d4401ecb3c19a5b5c2cea1252636">SetMajorAxisAlign</a> (const AlignType &amp;align)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p203301394165635"><a name="p203301394165635"></a><a name="p203301394165635"></a>void </p>
<p id="p1425973038165635"><a name="p1425973038165635"></a><a name="p1425973038165635"></a>Sets the alignment mode of the primary axis (the axis where the layout direction is located). The child views in the layout are placed in this mode in the direction of the primary axis. </p>
</td>
</tr>
<tr id="row886818706165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1638097811165635"><a name="p1638097811165635"></a><a name="p1638097811165635"></a><a href="Graphic.md#gadb57c6de7bcd0c04cde8004019e32b32">SetSecondaryAxisAlign</a> (const AlignType &amp;align)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1285020873165635"><a name="p1285020873165635"></a><a name="p1285020873165635"></a>void </p>
<p id="p1183050274165635"><a name="p1183050274165635"></a><a name="p1183050274165635"></a>Sets the alignment mode of the secondary axis (the axis perpendicular to the set layout direction). </p>
</td>
</tr>
<tr id="row160462906165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782219315165635"><a name="p782219315165635"></a><a name="p782219315165635"></a><a href="Graphic.md#gade436564eb29d29e32220863a6fe94e1">SetFlexWrap</a> (uint8_t wrap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1448217368165635"><a name="p1448217368165635"></a><a name="p1448217368165635"></a>void </p>
<p id="p1021183961165635"><a name="p1021183961165635"></a><a name="p1021183961165635"></a>Sets whether to support word wrap. </p>
</td>
</tr>
<tr id="row1753788131165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p966424528165635"><a name="p966424528165635"></a><a name="p966424528165635"></a><a href="Graphic.md#ga976abe5b006bef9018dd0d8ee2380526">LayoutChildren</a> (bool needInvalidate=false) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p646255734165635"><a name="p646255734165635"></a><a name="p646255734165635"></a>virtual void </p>
<p id="p1930584931165635"><a name="p1930584931165635"></a><a name="p1930584931165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row427045331165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1009438334165635"><a name="p1009438334165635"></a><a name="p1009438334165635"></a><a href="Graphic.md#gaba1ca0f86a85d3c5636ca543b0ed08d8">Layout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283641782165635"><a name="p1283641782165635"></a><a name="p1283641782165635"></a> </p>
<p id="p1681683724165635"><a name="p1681683724165635"></a><a name="p1681683724165635"></a>A default constructor used to create a <strong id="b1558229330165635"><a name="b1558229330165635"></a><a name="b1558229330165635"></a><a href="OHOS-Layout.md">Layout</a></strong> instance. </p>
</td>
</tr>
<tr id="row174677631165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295032479165635"><a name="p295032479165635"></a><a name="p295032479165635"></a><a href="Graphic.md#ga6c7cc7a849197fe014ea57d0534728bf">~Layout</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p996534053165635"><a name="p996534053165635"></a><a name="p996534053165635"></a>virtual </p>
<p id="p832248156165635"><a name="p832248156165635"></a><a name="p832248156165635"></a>A destructor used to delete the <strong id="b1562293027165635"><a name="b1562293027165635"></a><a name="b1562293027165635"></a><a href="OHOS-Layout.md">Layout</a></strong> instance. </p>
</td>
</tr>
<tr id="row1981733111165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509984960165635"><a name="p1509984960165635"></a><a name="p1509984960165635"></a><a href="Graphic.md#gada9223ec4d664c00a9640c8b9cbcacc3">SetLayoutDirection</a> (const <a href="Codec.md#ga8ef30fa9c08e08c8706653571f9f5b81">DirectionType</a> &amp;direction)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1303994947165635"><a name="p1303994947165635"></a><a name="p1303994947165635"></a>void </p>
<p id="p1730591401165635"><a name="p1730591401165635"></a><a name="p1730591401165635"></a>Sets the layout direction. </p>
</td>
</tr>
<tr id="row369673731165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p949488835165635"><a name="p949488835165635"></a><a name="p949488835165635"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761622682165635"><a name="p1761622682165635"></a><a name="p1761622682165635"></a> </p>
<p id="p624750866165635"><a name="p624750866165635"></a><a name="p624750866165635"></a>A default constructor used to create a <strong id="b977751127165635"><a name="b977751127165635"></a><a name="b977751127165635"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1523806219165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p787173603165635"><a name="p787173603165635"></a><a name="p787173603165635"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2027635799165635"><a name="p2027635799165635"></a><a name="p2027635799165635"></a>virtual </p>
<p id="p1886294179165635"><a name="p1886294179165635"></a><a name="p1886294179165635"></a>A destructor used to delete the <strong id="b1469053259165635"><a name="b1469053259165635"></a><a name="b1469053259165635"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row948651625165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1195690059165635"><a name="p1195690059165635"></a><a name="p1195690059165635"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p838202094165635"><a name="p838202094165635"></a><a name="p838202094165635"></a>UIViewType </p>
<p id="p767044686165635"><a name="p767044686165635"></a><a name="p767044686165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1019020987165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137191117165635"><a name="p137191117165635"></a><a name="p137191117165635"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847244802165635"><a name="p847244802165635"></a><a name="p847244802165635"></a>virtual void </p>
<p id="p1060018275165635"><a name="p1060018275165635"></a><a name="p1060018275165635"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1652527811165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906651339165635"><a name="p1906651339165635"></a><a name="p1906651339165635"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p693607908165635"><a name="p693607908165635"></a><a name="p693607908165635"></a>virtual void </p>
<p id="p2138226076165635"><a name="p2138226076165635"></a><a name="p2138226076165635"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1477438765165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p786675828165635"><a name="p786675828165635"></a><a name="p786675828165635"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p501280864165635"><a name="p501280864165635"></a><a name="p501280864165635"></a>virtual void </p>
<p id="p992867323165635"><a name="p992867323165635"></a><a name="p992867323165635"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row361527175165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1868850667165635"><a name="p1868850667165635"></a><a name="p1868850667165635"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1727303081165635"><a name="p1727303081165635"></a><a name="p1727303081165635"></a>virtual void </p>
<p id="p1768779987165635"><a name="p1768779987165635"></a><a name="p1768779987165635"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row688990226165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2127125046165635"><a name="p2127125046165635"></a><a name="p2127125046165635"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1833626665165635"><a name="p1833626665165635"></a><a name="p1833626665165635"></a>virtual void </p>
<p id="p301049383165635"><a name="p301049383165635"></a><a name="p301049383165635"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row554269643165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1920980407165635"><a name="p1920980407165635"></a><a name="p1920980407165635"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18070087165635"><a name="p18070087165635"></a><a name="p18070087165635"></a>virtual void </p>
<p id="p1306526091165635"><a name="p1306526091165635"></a><a name="p1306526091165635"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1518720703165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p296951432165635"><a name="p296951432165635"></a><a name="p296951432165635"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p352443570165635"><a name="p352443570165635"></a><a name="p352443570165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p286019075165635"><a name="p286019075165635"></a><a name="p286019075165635"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row386166893165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909520863165635"><a name="p1909520863165635"></a><a name="p1909520863165635"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1847897950165635"><a name="p1847897950165635"></a><a name="p1847897950165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1582419130165635"><a name="p1582419130165635"></a><a name="p1582419130165635"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row685660119165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1270190788165635"><a name="p1270190788165635"></a><a name="p1270190788165635"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p588547586165635"><a name="p588547586165635"></a><a name="p588547586165635"></a>void </p>
<p id="p1251218442165635"><a name="p1251218442165635"></a><a name="p1251218442165635"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1525596933165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429126581165635"><a name="p429126581165635"></a><a name="p429126581165635"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2075771947165635"><a name="p2075771947165635"></a><a name="p2075771947165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p392280444165635"><a name="p392280444165635"></a><a name="p392280444165635"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row780151472165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1945598038165635"><a name="p1945598038165635"></a><a name="p1945598038165635"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632376545165635"><a name="p1632376545165635"></a><a name="p1632376545165635"></a>void </p>
<p id="p833768335165635"><a name="p833768335165635"></a><a name="p833768335165635"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row291879648165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1374875891165635"><a name="p1374875891165635"></a><a name="p1374875891165635"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p206881469165635"><a name="p206881469165635"></a><a name="p206881469165635"></a> </p>
<p id="p1697723284165635"><a name="p1697723284165635"></a><a name="p1697723284165635"></a>A default constructor used to create an <strong id="b1923292277165635"><a name="b1923292277165635"></a><a name="b1923292277165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1156482308165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p568576744165635"><a name="p568576744165635"></a><a name="p568576744165635"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p449814312165635"><a name="p449814312165635"></a><a name="p449814312165635"></a> </p>
<p id="p278438289165635"><a name="p278438289165635"></a><a name="p278438289165635"></a>A constructor used to create an <strong id="b1692171655165635"><a name="b1692171655165635"></a><a name="b1692171655165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1684034698165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1019514929165635"><a name="p1019514929165635"></a><a name="p1019514929165635"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1731160012165635"><a name="p1731160012165635"></a><a name="p1731160012165635"></a>virtual </p>
<p id="p1086265026165635"><a name="p1086265026165635"></a><a name="p1086265026165635"></a>A destructor used to delete the <strong id="b522861031165635"><a name="b522861031165635"></a><a name="b522861031165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1712190594165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448664758165635"><a name="p1448664758165635"></a><a name="p1448664758165635"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p736714154165635"><a name="p736714154165635"></a><a name="p736714154165635"></a>virtual bool </p>
<p id="p1154507811165635"><a name="p1154507811165635"></a><a name="p1154507811165635"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row930726796165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1951804389165635"><a name="p1951804389165635"></a><a name="p1951804389165635"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1475040281165635"><a name="p1475040281165635"></a><a name="p1475040281165635"></a>virtual void </p>
<p id="p454124756165635"><a name="p454124756165635"></a><a name="p454124756165635"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row224642948165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p235591378165635"><a name="p235591378165635"></a><a name="p235591378165635"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1391051628165635"><a name="p1391051628165635"></a><a name="p1391051628165635"></a>virtual void </p>
<p id="p627041981165635"><a name="p627041981165635"></a><a name="p627041981165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1923888275165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657224509165635"><a name="p657224509165635"></a><a name="p657224509165635"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1929741984165635"><a name="p1929741984165635"></a><a name="p1929741984165635"></a>virtual void </p>
<p id="p1811834090165635"><a name="p1811834090165635"></a><a name="p1811834090165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1277232110165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295427509165635"><a name="p295427509165635"></a><a name="p295427509165635"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p659580951165635"><a name="p659580951165635"></a><a name="p659580951165635"></a>void </p>
<p id="p1023361451165635"><a name="p1023361451165635"></a><a name="p1023361451165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row290260609165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982935888165635"><a name="p1982935888165635"></a><a name="p1982935888165635"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434495315165635"><a name="p434495315165635"></a><a name="p434495315165635"></a>void </p>
<p id="p363221682165635"><a name="p363221682165635"></a><a name="p363221682165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1819610855165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1454464552165635"><a name="p1454464552165635"></a><a name="p1454464552165635"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p321955817165635"><a name="p321955817165635"></a><a name="p321955817165635"></a>virtual bool </p>
<p id="p1149967027165635"><a name="p1149967027165635"></a><a name="p1149967027165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row1190493963165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1824925917165635"><a name="p1824925917165635"></a><a name="p1824925917165635"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p809439110165635"><a name="p809439110165635"></a><a name="p809439110165635"></a>virtual bool </p>
<p id="p511188916165635"><a name="p511188916165635"></a><a name="p511188916165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row808180561165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606877182165635"><a name="p1606877182165635"></a><a name="p1606877182165635"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p381809652165635"><a name="p381809652165635"></a><a name="p381809652165635"></a>virtual bool </p>
<p id="p326352802165635"><a name="p326352802165635"></a><a name="p326352802165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1643813058165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1585643443165635"><a name="p1585643443165635"></a><a name="p1585643443165635"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031101392165635"><a name="p2031101392165635"></a><a name="p2031101392165635"></a>virtual bool </p>
<p id="p2681022165635"><a name="p2681022165635"></a><a name="p2681022165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1336923596165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1527674595165635"><a name="p1527674595165635"></a><a name="p1527674595165635"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p970120672165635"><a name="p970120672165635"></a><a name="p970120672165635"></a>virtual void </p>
<p id="p1318982847165635"><a name="p1318982847165635"></a><a name="p1318982847165635"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row289491729165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921387662165635"><a name="p921387662165635"></a><a name="p921387662165635"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10708286165635"><a name="p10708286165635"></a><a name="p10708286165635"></a>virtual void </p>
<p id="p139745534165635"><a name="p139745534165635"></a><a name="p139745534165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row414535277165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p998780562165635"><a name="p998780562165635"></a><a name="p998780562165635"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1467675561165635"><a name="p1467675561165635"></a><a name="p1467675561165635"></a>virtual void </p>
<p id="p91000592165635"><a name="p91000592165635"></a><a name="p91000592165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row283313861165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1733688024165635"><a name="p1733688024165635"></a><a name="p1733688024165635"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p791842589165635"><a name="p791842589165635"></a><a name="p791842589165635"></a>virtual void </p>
<p id="p1367043175165635"><a name="p1367043175165635"></a><a name="p1367043175165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row795081610165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1066579682165635"><a name="p1066579682165635"></a><a name="p1066579682165635"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190256417165635"><a name="p190256417165635"></a><a name="p190256417165635"></a>void </p>
<p id="p314800005165635"><a name="p314800005165635"></a><a name="p314800005165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1471505731165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102678340165635"><a name="p1102678340165635"></a><a name="p1102678340165635"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1905508099165635"><a name="p1905508099165635"></a><a name="p1905508099165635"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1932943474165635"><a name="p1932943474165635"></a><a name="p1932943474165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row557814939165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1180112941165635"><a name="p1180112941165635"></a><a name="p1180112941165635"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1836201286165635"><a name="p1836201286165635"></a><a name="p1836201286165635"></a>void </p>
<p id="p913515102165635"><a name="p913515102165635"></a><a name="p913515102165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row369525518165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p496209199165635"><a name="p496209199165635"></a><a name="p496209199165635"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972786584165635"><a name="p1972786584165635"></a><a name="p1972786584165635"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p1071771586165635"><a name="p1071771586165635"></a><a name="p1071771586165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row357550276165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1064862541165635"><a name="p1064862541165635"></a><a name="p1064862541165635"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1581930669165635"><a name="p1581930669165635"></a><a name="p1581930669165635"></a>void </p>
<p id="p1254606026165635"><a name="p1254606026165635"></a><a name="p1254606026165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1431295302165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1215818983165635"><a name="p1215818983165635"></a><a name="p1215818983165635"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36511633165635"><a name="p36511633165635"></a><a name="p36511633165635"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p898569793165635"><a name="p898569793165635"></a><a name="p898569793165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row94404515165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1238883779165635"><a name="p1238883779165635"></a><a name="p1238883779165635"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246284509165635"><a name="p246284509165635"></a><a name="p246284509165635"></a>void </p>
<p id="p1510646064165635"><a name="p1510646064165635"></a><a name="p1510646064165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row888271688165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p983315069165635"><a name="p983315069165635"></a><a name="p983315069165635"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943258621165635"><a name="p943258621165635"></a><a name="p943258621165635"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1727552187165635"><a name="p1727552187165635"></a><a name="p1727552187165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1579621342165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p435406646165635"><a name="p435406646165635"></a><a name="p435406646165635"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p735247592165635"><a name="p735247592165635"></a><a name="p735247592165635"></a>void </p>
<p id="p1676929902165635"><a name="p1676929902165635"></a><a name="p1676929902165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row233368143165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p683784143165635"><a name="p683784143165635"></a><a name="p683784143165635"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176478465165635"><a name="p176478465165635"></a><a name="p176478465165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p302274717165635"><a name="p302274717165635"></a><a name="p302274717165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1291418865165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1684125082165635"><a name="p1684125082165635"></a><a name="p1684125082165635"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p435194350165635"><a name="p435194350165635"></a><a name="p435194350165635"></a>void </p>
<p id="p1901939115165635"><a name="p1901939115165635"></a><a name="p1901939115165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row671085892165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1108923852165635"><a name="p1108923852165635"></a><a name="p1108923852165635"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p162595736165635"><a name="p162595736165635"></a><a name="p162595736165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p789610474165635"><a name="p789610474165635"></a><a name="p789610474165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1964601611165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p395023190165635"><a name="p395023190165635"></a><a name="p395023190165635"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p871262204165635"><a name="p871262204165635"></a><a name="p871262204165635"></a>virtual void </p>
<p id="p2100991527165635"><a name="p2100991527165635"></a><a name="p2100991527165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row2022484649165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1357676707165635"><a name="p1357676707165635"></a><a name="p1357676707165635"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1620683704165635"><a name="p1620683704165635"></a><a name="p1620683704165635"></a>bool </p>
<p id="p2104316424165635"><a name="p2104316424165635"></a><a name="p2104316424165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1822604722165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401748517165635"><a name="p1401748517165635"></a><a name="p1401748517165635"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478618214165635"><a name="p1478618214165635"></a><a name="p1478618214165635"></a>void </p>
<p id="p1427492738165635"><a name="p1427492738165635"></a><a name="p1427492738165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row397648911165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p551041342165635"><a name="p551041342165635"></a><a name="p551041342165635"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p833220435165635"><a name="p833220435165635"></a><a name="p833220435165635"></a>bool </p>
<p id="p390299169165635"><a name="p390299169165635"></a><a name="p390299169165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row1825122020165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306976864165635"><a name="p306976864165635"></a><a name="p306976864165635"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p260119330165635"><a name="p260119330165635"></a><a name="p260119330165635"></a>void </p>
<p id="p737339281165635"><a name="p737339281165635"></a><a name="p737339281165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row418751611165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087001217165635"><a name="p2087001217165635"></a><a name="p2087001217165635"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p181818356165635"><a name="p181818356165635"></a><a name="p181818356165635"></a>bool </p>
<p id="p2020163096165635"><a name="p2020163096165635"></a><a name="p2020163096165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row1089908157165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p611410601165635"><a name="p611410601165635"></a><a name="p611410601165635"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p469984040165635"><a name="p469984040165635"></a><a name="p469984040165635"></a>void </p>
<p id="p530844425165635"><a name="p530844425165635"></a><a name="p530844425165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row302551562165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1349527064165635"><a name="p1349527064165635"></a><a name="p1349527064165635"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1929135800165635"><a name="p1929135800165635"></a><a name="p1929135800165635"></a>bool </p>
<p id="p745401694165635"><a name="p745401694165635"></a><a name="p745401694165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1947250512165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087942662165635"><a name="p2087942662165635"></a><a name="p2087942662165635"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p651135219165635"><a name="p651135219165635"></a><a name="p651135219165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1960131380165635"><a name="p1960131380165635"></a><a name="p1960131380165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1673780834165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p766960304165635"><a name="p766960304165635"></a><a name="p766960304165635"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925539460165635"><a name="p925539460165635"></a><a name="p925539460165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p402761384165635"><a name="p402761384165635"></a><a name="p402761384165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1336527190165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1206294691165635"><a name="p1206294691165635"></a><a name="p1206294691165635"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p184228724165635"><a name="p184228724165635"></a><a name="p184228724165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p69766046165635"><a name="p69766046165635"></a><a name="p69766046165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row791647126165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1762904290165635"><a name="p1762904290165635"></a><a name="p1762904290165635"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667731364165635"><a name="p667731364165635"></a><a name="p667731364165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p657435522165635"><a name="p657435522165635"></a><a name="p657435522165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row147185801165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231064928165635"><a name="p1231064928165635"></a><a name="p1231064928165635"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p432402103165635"><a name="p432402103165635"></a><a name="p432402103165635"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2009637182165635"><a name="p2009637182165635"></a><a name="p2009637182165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1476866212165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1318236203165635"><a name="p1318236203165635"></a><a name="p1318236203165635"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1397702134165635"><a name="p1397702134165635"></a><a name="p1397702134165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1322094616165635"><a name="p1322094616165635"></a><a name="p1322094616165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row365312302165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1857588934165635"><a name="p1857588934165635"></a><a name="p1857588934165635"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413074043165635"><a name="p413074043165635"></a><a name="p413074043165635"></a>void </p>
<p id="p1374801697165635"><a name="p1374801697165635"></a><a name="p1374801697165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1954822355165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1273632987165635"><a name="p1273632987165635"></a><a name="p1273632987165635"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p605068897165635"><a name="p605068897165635"></a><a name="p605068897165635"></a>virtual void </p>
<p id="p781469821165635"><a name="p781469821165635"></a><a name="p781469821165635"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1107931973165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2055732911165635"><a name="p2055732911165635"></a><a name="p2055732911165635"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722838922165635"><a name="p722838922165635"></a><a name="p722838922165635"></a>virtual int16_t </p>
<p id="p618383535165635"><a name="p618383535165635"></a><a name="p618383535165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row93133286165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1830402728165635"><a name="p1830402728165635"></a><a name="p1830402728165635"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985479796165635"><a name="p985479796165635"></a><a name="p985479796165635"></a>virtual void </p>
<p id="p1703876694165635"><a name="p1703876694165635"></a><a name="p1703876694165635"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1245031205165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1162451586165635"><a name="p1162451586165635"></a><a name="p1162451586165635"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p315181079165635"><a name="p315181079165635"></a><a name="p315181079165635"></a>virtual int16_t </p>
<p id="p1215357857165635"><a name="p1215357857165635"></a><a name="p1215357857165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row707091778165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1710944788165635"><a name="p1710944788165635"></a><a name="p1710944788165635"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p246728424165635"><a name="p246728424165635"></a><a name="p246728424165635"></a>virtual void </p>
<p id="p794045235165635"><a name="p794045235165635"></a><a name="p794045235165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1252795945165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1504924749165635"><a name="p1504924749165635"></a><a name="p1504924749165635"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p16890438165635"><a name="p16890438165635"></a><a name="p16890438165635"></a>virtual void </p>
<p id="p1507663393165635"><a name="p1507663393165635"></a><a name="p1507663393165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row2028857898165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807173889165635"><a name="p1807173889165635"></a><a name="p1807173889165635"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p907503603165635"><a name="p907503603165635"></a><a name="p907503603165635"></a>int16_t </p>
<p id="p1001355250165635"><a name="p1001355250165635"></a><a name="p1001355250165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row603579765165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1840952122165635"><a name="p1840952122165635"></a><a name="p1840952122165635"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p150594062165635"><a name="p150594062165635"></a><a name="p150594062165635"></a>virtual void </p>
<p id="p1051067939165635"><a name="p1051067939165635"></a><a name="p1051067939165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row875647824165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p49087952165635"><a name="p49087952165635"></a><a name="p49087952165635"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p333912246165635"><a name="p333912246165635"></a><a name="p333912246165635"></a>int16_t </p>
<p id="p52797618165635"><a name="p52797618165635"></a><a name="p52797618165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1789273079165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962860262165635"><a name="p1962860262165635"></a><a name="p1962860262165635"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406508278165635"><a name="p406508278165635"></a><a name="p406508278165635"></a>virtual void </p>
<p id="p1857782007165635"><a name="p1857782007165635"></a><a name="p1857782007165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row348006527165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1077154173165635"><a name="p1077154173165635"></a><a name="p1077154173165635"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834111392165635"><a name="p1834111392165635"></a><a name="p1834111392165635"></a>virtual void </p>
<p id="p1427108831165635"><a name="p1427108831165635"></a><a name="p1427108831165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row402572515165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p51623768165635"><a name="p51623768165635"></a><a name="p51623768165635"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763456902165635"><a name="p1763456902165635"></a><a name="p1763456902165635"></a>bool </p>
<p id="p768292485165635"><a name="p768292485165635"></a><a name="p768292485165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row118653012165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1019186564165635"><a name="p1019186564165635"></a><a name="p1019186564165635"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768689540165635"><a name="p1768689540165635"></a><a name="p1768689540165635"></a>void </p>
<p id="p529887307165635"><a name="p529887307165635"></a><a name="p529887307165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row106934150165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1812761726165635"><a name="p1812761726165635"></a><a name="p1812761726165635"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p182694489165635"><a name="p182694489165635"></a><a name="p182694489165635"></a>void </p>
<p id="p965493313165635"><a name="p965493313165635"></a><a name="p965493313165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row128694464165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p662395955165635"><a name="p662395955165635"></a><a name="p662395955165635"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p150783478165635"><a name="p150783478165635"></a><a name="p150783478165635"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p721889548165635"><a name="p721889548165635"></a><a name="p721889548165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row677063372165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1200616425165635"><a name="p1200616425165635"></a><a name="p1200616425165635"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1427124262165635"><a name="p1427124262165635"></a><a name="p1427124262165635"></a>void </p>
<p id="p1356547276165635"><a name="p1356547276165635"></a><a name="p1356547276165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1216156804165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1223419172165635"><a name="p1223419172165635"></a><a name="p1223419172165635"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118596924165635"><a name="p1118596924165635"></a><a name="p1118596924165635"></a>const char * </p>
<p id="p1054427508165635"><a name="p1054427508165635"></a><a name="p1054427508165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1968471599165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523103541165635"><a name="p1523103541165635"></a><a name="p1523103541165635"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p967928262165635"><a name="p967928262165635"></a><a name="p967928262165635"></a>void </p>
<p id="p857184814165635"><a name="p857184814165635"></a><a name="p857184814165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1959166491165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376071032165635"><a name="p1376071032165635"></a><a name="p1376071032165635"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p405195281165635"><a name="p405195281165635"></a><a name="p405195281165635"></a>int16_t </p>
<p id="p743137418165635"><a name="p743137418165635"></a><a name="p743137418165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1177207995165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1796193525165635"><a name="p1796193525165635"></a><a name="p1796193525165635"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1266966098165635"><a name="p1266966098165635"></a><a name="p1266966098165635"></a>void </p>
<p id="p1952633904165635"><a name="p1952633904165635"></a><a name="p1952633904165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1344302185165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635540508165635"><a name="p1635540508165635"></a><a name="p1635540508165635"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813353630165635"><a name="p1813353630165635"></a><a name="p1813353630165635"></a>void </p>
<p id="p1133603161165635"><a name="p1133603161165635"></a><a name="p1133603161165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1898461225165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2140177974165635"><a name="p2140177974165635"></a><a name="p2140177974165635"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p639450897165635"><a name="p639450897165635"></a><a name="p639450897165635"></a>void </p>
<p id="p1559096529165635"><a name="p1559096529165635"></a><a name="p1559096529165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row2122399664165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688317282165635"><a name="p688317282165635"></a><a name="p688317282165635"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1890377543165635"><a name="p1890377543165635"></a><a name="p1890377543165635"></a>void </p>
<p id="p1550852052165635"><a name="p1550852052165635"></a><a name="p1550852052165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row2125412712165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1880346961165635"><a name="p1880346961165635"></a><a name="p1880346961165635"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2140654087165635"><a name="p2140654087165635"></a><a name="p2140654087165635"></a>void </p>
<p id="p615131254165635"><a name="p615131254165635"></a><a name="p615131254165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row546090988165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p180178025165635"><a name="p180178025165635"></a><a name="p180178025165635"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1323880214165635"><a name="p1323880214165635"></a><a name="p1323880214165635"></a>void </p>
<p id="p415397521165635"><a name="p415397521165635"></a><a name="p415397521165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row109855828165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p139471026165635"><a name="p139471026165635"></a><a name="p139471026165635"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1110865608165635"><a name="p1110865608165635"></a><a name="p1110865608165635"></a>void </p>
<p id="p506321820165635"><a name="p506321820165635"></a><a name="p506321820165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row199386467165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2072003690165635"><a name="p2072003690165635"></a><a name="p2072003690165635"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1790200329165635"><a name="p1790200329165635"></a><a name="p1790200329165635"></a>void </p>
<p id="p827155429165635"><a name="p827155429165635"></a><a name="p827155429165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row150688042165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1795168047165635"><a name="p1795168047165635"></a><a name="p1795168047165635"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1381672102165635"><a name="p1381672102165635"></a><a name="p1381672102165635"></a>void </p>
<p id="p1092096970165635"><a name="p1092096970165635"></a><a name="p1092096970165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1974688248165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1678159066165635"><a name="p1678159066165635"></a><a name="p1678159066165635"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640171726165635"><a name="p1640171726165635"></a><a name="p1640171726165635"></a>void </p>
<p id="p223823537165635"><a name="p223823537165635"></a><a name="p223823537165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1272709520165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p802211916165635"><a name="p802211916165635"></a><a name="p802211916165635"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p54688725165635"><a name="p54688725165635"></a><a name="p54688725165635"></a>void </p>
<p id="p1244368217165635"><a name="p1244368217165635"></a><a name="p1244368217165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row978555836165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087198252165635"><a name="p2087198252165635"></a><a name="p2087198252165635"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1855017684165635"><a name="p1855017684165635"></a><a name="p1855017684165635"></a>void </p>
<p id="p1307623243165635"><a name="p1307623243165635"></a><a name="p1307623243165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row885633147165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1818902439165635"><a name="p1818902439165635"></a><a name="p1818902439165635"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1696672653165635"><a name="p1696672653165635"></a><a name="p1696672653165635"></a>void </p>
<p id="p1988782750165635"><a name="p1988782750165635"></a><a name="p1988782750165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row760261203165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p897347716165635"><a name="p897347716165635"></a><a name="p897347716165635"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2029810293165635"><a name="p2029810293165635"></a><a name="p2029810293165635"></a>void </p>
<p id="p23238408165635"><a name="p23238408165635"></a><a name="p23238408165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1852148240165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p825150896165635"><a name="p825150896165635"></a><a name="p825150896165635"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002007669165635"><a name="p2002007669165635"></a><a name="p2002007669165635"></a>void </p>
<p id="p959202993165635"><a name="p959202993165635"></a><a name="p959202993165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row678282397165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2301953165635"><a name="p2301953165635"></a><a name="p2301953165635"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p149988349165635"><a name="p149988349165635"></a><a name="p149988349165635"></a>void </p>
<p id="p785841412165635"><a name="p785841412165635"></a><a name="p785841412165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row400948899165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376647143165635"><a name="p1376647143165635"></a><a name="p1376647143165635"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p402977414165635"><a name="p402977414165635"></a><a name="p402977414165635"></a>virtual void </p>
<p id="p1601859076165635"><a name="p1601859076165635"></a><a name="p1601859076165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1784010020165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p758403098165635"><a name="p758403098165635"></a><a name="p758403098165635"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1938199657165635"><a name="p1938199657165635"></a><a name="p1938199657165635"></a>virtual int64_t </p>
<p id="p1121310375165635"><a name="p1121310375165635"></a><a name="p1121310375165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1125038985165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p449081763165635"><a name="p449081763165635"></a><a name="p449081763165635"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1615756233165635"><a name="p1615756233165635"></a><a name="p1615756233165635"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p165479129165635"><a name="p165479129165635"></a><a name="p165479129165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row885087171165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384459614165635"><a name="p384459614165635"></a><a name="p384459614165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575583566165635"><a name="p575583566165635"></a><a name="p575583566165635"></a>void * </p>
<p id="p1576205258165635"><a name="p1576205258165635"></a><a name="p1576205258165635"></a>Overrides the <strong id="b634214638165635"><a name="b634214638165635"></a><a name="b634214638165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1181321651165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1335830625165635"><a name="p1335830625165635"></a><a name="p1335830625165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1158739213165635"><a name="p1158739213165635"></a><a name="p1158739213165635"></a>void </p>
<p id="p1126235630165635"><a name="p1126235630165635"></a><a name="p1126235630165635"></a>Overrides the <strong id="b2140592297165635"><a name="b2140592297165635"></a><a name="b2140592297165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1455067261165635"></a>
<table><thead align="left"><tr id="row88313724165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p116304392165635"><a name="p116304392165635"></a><a name="p116304392165635"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p776805302165635"><a name="p776805302165635"></a><a name="p776805302165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1309135672165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465554624165635"><a name="p1465554624165635"></a><a name="p1465554624165635"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1661586763165635"><a name="p1661586763165635"></a><a name="p1661586763165635"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row684042593165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843421706165635"><a name="p843421706165635"></a><a name="p843421706165635"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353060383165635"><a name="p1353060383165635"></a><a name="p1353060383165635"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row636198294165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p120121950165635"><a name="p120121950165635"></a><a name="p120121950165635"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2098585559165635"><a name="p2098585559165635"></a><a name="p2098585559165635"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1969502036165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727157711165635"><a name="p1727157711165635"></a><a name="p1727157711165635"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p578058024165635"><a name="p578058024165635"></a><a name="p578058024165635"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row618103343165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p319903332165635"><a name="p319903332165635"></a><a name="p319903332165635"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1585542590165635"><a name="p1585542590165635"></a><a name="p1585542590165635"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row938532556165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1886118929165635"><a name="p1886118929165635"></a><a name="p1886118929165635"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1791325908165635"><a name="p1791325908165635"></a><a name="p1791325908165635"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1719570137165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751841299165635"><a name="p1751841299165635"></a><a name="p1751841299165635"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1307033385165635"><a name="p1307033385165635"></a><a name="p1307033385165635"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row230845988165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p476571678165635"><a name="p476571678165635"></a><a name="p476571678165635"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p894275097165635"><a name="p894275097165635"></a><a name="p894275097165635"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

