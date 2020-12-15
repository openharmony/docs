# OHOS::UIDialog<a name="ZH-CN_TOPIC_0000001055198154"></a>

-   [Overview](#section1747146483165634)
-   [Summary](#section1479269648165634)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1747146483165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Represents a dialog box. 

A dialog box displays information for user input. After a button is clicked in the dialog box, the corresponding callback event is triggered.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1479269648165634"></a>

## Public Types<a name="pub-types"></a>

<a name="table543997912165634"></a>
<table><thead align="left"><tr id="row581068823165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p541356930165634"><a name="p541356930165634"></a><a name="p541356930165634"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1114080768165634"><a name="p1114080768165634"></a><a name="p1114080768165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1768625261165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930285278165634"><a name="p930285278165634"></a><a name="p930285278165634"></a><a href="Graphic.md#ga1bfefa0b46fd5a79a28d0c9a75114295">DialogButtonType</a> { <a href="Graphic.md#gga1bfefa0b46fd5a79a28d0c9a75114295a39ef626649e9e14c6561411867e50f00">DialogButtonType::BUTTON1</a>, <a href="Graphic.md#gga1bfefa0b46fd5a79a28d0c9a75114295a752441e0500e1807164a5f758ed93a8c">DialogButtonType::BUTTON2</a>, <a href="Graphic.md#gga1bfefa0b46fd5a79a28d0c9a75114295a86707c1d7552f48007cc25b77a2db21b">DialogButtonType::BUTTON3</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p786224791165634"><a name="p786224791165634"></a><a name="p786224791165634"></a>Enumerates buttons in a dialog box. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table403335387165634"></a>
<table><thead align="left"><tr id="row107917465165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p215453250165634"><a name="p215453250165634"></a><a name="p215453250165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1909389952165634"><a name="p1909389952165634"></a><a name="p1909389952165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2124497127165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1736599516165634"><a name="p1736599516165634"></a><a name="p1736599516165634"></a><a href="Graphic.md#gaeaaddc56316206d4465ce8c927a686b7">UIDialog</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p345287622165634"><a name="p345287622165634"></a><a name="p345287622165634"></a> </p>
<p id="p336869663165634"><a name="p336869663165634"></a><a name="p336869663165634"></a>A constructor used to create a <strong id="b1345397223165634"><a name="b1345397223165634"></a><a name="b1345397223165634"></a><a href="OHOS-UIDialog.md">UIDialog</a></strong> instance. </p>
</td>
</tr>
<tr id="row618522919165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1499315795165634"><a name="p1499315795165634"></a><a name="p1499315795165634"></a><a href="Graphic.md#gae5b58ec7225efdbfaf9947e46bfd2616">~UIDialog</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2139381681165634"><a name="p2139381681165634"></a><a name="p2139381681165634"></a>virtual </p>
<p id="p1959158890165634"><a name="p1959158890165634"></a><a name="p1959158890165634"></a>A destructor used to delete the <strong id="b873359996165634"><a name="b873359996165634"></a><a name="b873359996165634"></a><a href="OHOS-UIDialog.md">UIDialog</a></strong> instance. </p>
</td>
</tr>
<tr id="row983176347165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1801879253165634"><a name="p1801879253165634"></a><a name="p1801879253165634"></a><a href="Graphic.md#gac0b18fe28ee4ad44814d3897d3cd5c05">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1687236533165634"><a name="p1687236533165634"></a><a name="p1687236533165634"></a>UIViewType </p>
<p id="p941472932165634"><a name="p941472932165634"></a><a name="p941472932165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row321176514165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306366248165634"><a name="p306366248165634"></a><a name="p306366248165634"></a><a href="Graphic.md#ga5629d5a1e19bc38087e8b35d65292714">SetTitle</a> (const char *title)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629722488165634"><a name="p1629722488165634"></a><a name="p1629722488165634"></a>void </p>
<p id="p145356280165634"><a name="p145356280165634"></a><a name="p145356280165634"></a>Sets the title for this dialog box. </p>
</td>
</tr>
<tr id="row116479420165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p460942117165634"><a name="p460942117165634"></a><a name="p460942117165634"></a><a href="Graphic.md#ga597e95748fba71238a99c8c17ed848a5">SetText</a> (const char *text)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p675464529165634"><a name="p675464529165634"></a><a name="p675464529165634"></a>void </p>
<p id="p1518541655165634"><a name="p1518541655165634"></a><a name="p1518541655165634"></a>Sets the text for this dialog box. </p>
</td>
</tr>
<tr id="row1617895322165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p384444088165634"><a name="p384444088165634"></a><a name="p384444088165634"></a><a href="Graphic.md#ga6b3cf14760fc07e38f51d366a8e5fdb9">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471854038165634"><a name="p1471854038165634"></a><a name="p1471854038165634"></a>bool </p>
<p id="p453700424165634"><a name="p453700424165634"></a><a name="p453700424165634"></a>Checks whether this label needs to be covered before drawing it. </p>
</td>
</tr>
<tr id="row611327440165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727623143165634"><a name="p1727623143165634"></a><a name="p1727623143165634"></a><a href="Graphic.md#gaa8bcf4d2d60becd105d0b87ee2ec18af">SetButton</a> (<a href="Graphic.md#ga1bfefa0b46fd5a79a28d0c9a75114295">DialogButtonType</a> buttonType, const char *text, <a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *listener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p936670575165634"><a name="p936670575165634"></a><a name="p936670575165634"></a>void </p>
<p id="p97713385165634"><a name="p97713385165634"></a><a name="p97713385165634"></a>Sets a button for this dialog box. </p>
</td>
</tr>
<tr id="row982893348165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p96286280165634"><a name="p96286280165634"></a><a name="p96286280165634"></a><a href="Graphic.md#gaf836d530b3fa9d50f70053c2b0b528d6">SetVisible</a> (bool visible) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580384709165634"><a name="p1580384709165634"></a><a name="p1580384709165634"></a>void </p>
<p id="p628581198165634"><a name="p628581198165634"></a><a name="p628581198165634"></a>Sets whether a dialog box is visible. </p>
</td>
</tr>
<tr id="row217992105165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1584337987165634"><a name="p1584337987165634"></a><a name="p1584337987165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1399214215165634"><a name="p1399214215165634"></a><a name="p1399214215165634"></a> </p>
<p id="p202556820165634"><a name="p202556820165634"></a><a name="p202556820165634"></a>A default constructor used to create a <strong id="b1062250273165634"><a name="b1062250273165634"></a><a name="b1062250273165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row887448169165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p209010533165634"><a name="p209010533165634"></a><a name="p209010533165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1623898224165634"><a name="p1623898224165634"></a><a name="p1623898224165634"></a>virtual </p>
<p id="p291952935165634"><a name="p291952935165634"></a><a name="p291952935165634"></a>A destructor used to delete the <strong id="b1181864984165634"><a name="b1181864984165634"></a><a name="b1181864984165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1809358366165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249284565165634"><a name="p249284565165634"></a><a name="p249284565165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p883571105165634"><a name="p883571105165634"></a><a name="p883571105165634"></a>UIViewType </p>
<p id="p662699428165634"><a name="p662699428165634"></a><a name="p662699428165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1543603526165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p993851204165634"><a name="p993851204165634"></a><a name="p993851204165634"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153625291165634"><a name="p1153625291165634"></a><a name="p1153625291165634"></a>virtual void </p>
<p id="p279494247165634"><a name="p279494247165634"></a><a name="p279494247165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1602297559165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p140624365165634"><a name="p140624365165634"></a><a name="p140624365165634"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1936502391165634"><a name="p1936502391165634"></a><a name="p1936502391165634"></a>virtual void </p>
<p id="p2102112210165634"><a name="p2102112210165634"></a><a name="p2102112210165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row778596950165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2001543733165634"><a name="p2001543733165634"></a><a name="p2001543733165634"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104960574165634"><a name="p2104960574165634"></a><a name="p2104960574165634"></a>virtual void </p>
<p id="p1133434398165634"><a name="p1133434398165634"></a><a name="p1133434398165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row132787026165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p322979601165634"><a name="p322979601165634"></a><a name="p322979601165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1052160749165634"><a name="p1052160749165634"></a><a name="p1052160749165634"></a>virtual void </p>
<p id="p14295334165634"><a name="p14295334165634"></a><a name="p14295334165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row528738635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1785852507165634"><a name="p1785852507165634"></a><a name="p1785852507165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p827436398165634"><a name="p827436398165634"></a><a name="p827436398165634"></a>virtual void </p>
<p id="p1281720517165634"><a name="p1281720517165634"></a><a name="p1281720517165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row568181313165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1858629316165634"><a name="p1858629316165634"></a><a name="p1858629316165634"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p445396387165634"><a name="p445396387165634"></a><a name="p445396387165634"></a>virtual void </p>
<p id="p389873802165634"><a name="p389873802165634"></a><a name="p389873802165634"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row491629319165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362302664165634"><a name="p362302664165634"></a><a name="p362302664165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1333041272165634"><a name="p1333041272165634"></a><a name="p1333041272165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1574471897165634"><a name="p1574471897165634"></a><a name="p1574471897165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1244699279165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1177543205165634"><a name="p1177543205165634"></a><a name="p1177543205165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1770469081165634"><a name="p1770469081165634"></a><a name="p1770469081165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1078061246165634"><a name="p1078061246165634"></a><a name="p1078061246165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1586839210165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4415983165634"><a name="p4415983165634"></a><a name="p4415983165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276220809165634"><a name="p1276220809165634"></a><a name="p1276220809165634"></a>void </p>
<p id="p1286133611165634"><a name="p1286133611165634"></a><a name="p1286133611165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1829089923165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p573215838165634"><a name="p573215838165634"></a><a name="p573215838165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p280586099165634"><a name="p280586099165634"></a><a name="p280586099165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1555389841165634"><a name="p1555389841165634"></a><a name="p1555389841165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row2014736598165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756642051165634"><a name="p1756642051165634"></a><a name="p1756642051165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p762082236165634"><a name="p762082236165634"></a><a name="p762082236165634"></a>void </p>
<p id="p260700449165634"><a name="p260700449165634"></a><a name="p260700449165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1434311309165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p90634260165634"><a name="p90634260165634"></a><a name="p90634260165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1523538157165634"><a name="p1523538157165634"></a><a name="p1523538157165634"></a> </p>
<p id="p2116474691165634"><a name="p2116474691165634"></a><a name="p2116474691165634"></a>A default constructor used to create an <strong id="b1805628491165634"><a name="b1805628491165634"></a><a name="b1805628491165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row45963713165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748249734165634"><a name="p1748249734165634"></a><a name="p1748249734165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p63709741165634"><a name="p63709741165634"></a><a name="p63709741165634"></a> </p>
<p id="p2056393968165634"><a name="p2056393968165634"></a><a name="p2056393968165634"></a>A constructor used to create an <strong id="b834029499165634"><a name="b834029499165634"></a><a name="b834029499165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1816978571165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065165187165634"><a name="p2065165187165634"></a><a name="p2065165187165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1148482320165634"><a name="p1148482320165634"></a><a name="p1148482320165634"></a>virtual </p>
<p id="p66210974165634"><a name="p66210974165634"></a><a name="p66210974165634"></a>A destructor used to delete the <strong id="b878970355165634"><a name="b878970355165634"></a><a name="b878970355165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row2018864635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1358796203165634"><a name="p1358796203165634"></a><a name="p1358796203165634"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125922418165634"><a name="p125922418165634"></a><a name="p125922418165634"></a>virtual void </p>
<p id="p909181619165634"><a name="p909181619165634"></a><a name="p909181619165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1107340087165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1134818565165634"><a name="p1134818565165634"></a><a name="p1134818565165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1157984540165634"><a name="p1157984540165634"></a><a name="p1157984540165634"></a>virtual void </p>
<p id="p760098341165634"><a name="p760098341165634"></a><a name="p760098341165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1134098406165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p477262492165634"><a name="p477262492165634"></a><a name="p477262492165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p740290354165634"><a name="p740290354165634"></a><a name="p740290354165634"></a>virtual void </p>
<p id="p1400130138165634"><a name="p1400130138165634"></a><a name="p1400130138165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row600718859165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1399644839165634"><a name="p1399644839165634"></a><a name="p1399644839165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1001386006165634"><a name="p1001386006165634"></a><a name="p1001386006165634"></a>void </p>
<p id="p1459564003165634"><a name="p1459564003165634"></a><a name="p1459564003165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1234617154165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p559809637165634"><a name="p559809637165634"></a><a name="p559809637165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p386579975165634"><a name="p386579975165634"></a><a name="p386579975165634"></a>void </p>
<p id="p1075578702165634"><a name="p1075578702165634"></a><a name="p1075578702165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1974883851165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2112220585165634"><a name="p2112220585165634"></a><a name="p2112220585165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1585936155165634"><a name="p1585936155165634"></a><a name="p1585936155165634"></a>virtual bool </p>
<p id="p299890673165634"><a name="p299890673165634"></a><a name="p299890673165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row459784153165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1461304500165634"><a name="p1461304500165634"></a><a name="p1461304500165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p901222962165634"><a name="p901222962165634"></a><a name="p901222962165634"></a>virtual bool </p>
<p id="p2088143695165634"><a name="p2088143695165634"></a><a name="p2088143695165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row1958460779165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1744264899165634"><a name="p1744264899165634"></a><a name="p1744264899165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1492813365165634"><a name="p1492813365165634"></a><a name="p1492813365165634"></a>virtual bool </p>
<p id="p971331132165634"><a name="p971331132165634"></a><a name="p971331132165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row169652857165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1488426102165634"><a name="p1488426102165634"></a><a name="p1488426102165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259802466165634"><a name="p1259802466165634"></a><a name="p1259802466165634"></a>virtual bool </p>
<p id="p472219559165634"><a name="p472219559165634"></a><a name="p472219559165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1828162323165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1872269551165634"><a name="p1872269551165634"></a><a name="p1872269551165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779933732165634"><a name="p779933732165634"></a><a name="p779933732165634"></a>virtual void </p>
<p id="p1975980098165634"><a name="p1975980098165634"></a><a name="p1975980098165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row390874411165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2001740265165634"><a name="p2001740265165634"></a><a name="p2001740265165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p156492458165634"><a name="p156492458165634"></a><a name="p156492458165634"></a>virtual void </p>
<p id="p715936034165634"><a name="p715936034165634"></a><a name="p715936034165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row2038930048165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p847507415165634"><a name="p847507415165634"></a><a name="p847507415165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1945993879165634"><a name="p1945993879165634"></a><a name="p1945993879165634"></a>virtual void </p>
<p id="p348293705165634"><a name="p348293705165634"></a><a name="p348293705165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1205994601165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1444076649165634"><a name="p1444076649165634"></a><a name="p1444076649165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267168522165634"><a name="p1267168522165634"></a><a name="p1267168522165634"></a>virtual void </p>
<p id="p1994090360165634"><a name="p1994090360165634"></a><a name="p1994090360165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row468307102165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722422964165634"><a name="p722422964165634"></a><a name="p722422964165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043858006165634"><a name="p2043858006165634"></a><a name="p2043858006165634"></a>void </p>
<p id="p1003509471165634"><a name="p1003509471165634"></a><a name="p1003509471165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row734098276165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114008572165634"><a name="p2114008572165634"></a><a name="p2114008572165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694630252165634"><a name="p1694630252165634"></a><a name="p1694630252165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p1616239537165634"><a name="p1616239537165634"></a><a name="p1616239537165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1989902899165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726744543165634"><a name="p1726744543165634"></a><a name="p1726744543165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1274562604165634"><a name="p1274562604165634"></a><a name="p1274562604165634"></a>void </p>
<p id="p378223229165634"><a name="p378223229165634"></a><a name="p378223229165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row859080866165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1757421282165634"><a name="p1757421282165634"></a><a name="p1757421282165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783936880165634"><a name="p783936880165634"></a><a name="p783936880165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p562031691165634"><a name="p562031691165634"></a><a name="p562031691165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1575982159165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p652892584165634"><a name="p652892584165634"></a><a name="p652892584165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p474580241165634"><a name="p474580241165634"></a><a name="p474580241165634"></a>void </p>
<p id="p339312961165634"><a name="p339312961165634"></a><a name="p339312961165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row462687889165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p732435810165634"><a name="p732435810165634"></a><a name="p732435810165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679941668165634"><a name="p679941668165634"></a><a name="p679941668165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1125518519165634"><a name="p1125518519165634"></a><a name="p1125518519165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1672347653165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p620833904165634"><a name="p620833904165634"></a><a name="p620833904165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1385087203165634"><a name="p1385087203165634"></a><a name="p1385087203165634"></a>void </p>
<p id="p1390571250165634"><a name="p1390571250165634"></a><a name="p1390571250165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1814264508165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890880830165634"><a name="p1890880830165634"></a><a name="p1890880830165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704025185165634"><a name="p704025185165634"></a><a name="p704025185165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p360329961165634"><a name="p360329961165634"></a><a name="p360329961165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row1327410434165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1561917441165634"><a name="p1561917441165634"></a><a name="p1561917441165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2072357159165634"><a name="p2072357159165634"></a><a name="p2072357159165634"></a>void </p>
<p id="p1317050135165634"><a name="p1317050135165634"></a><a name="p1317050135165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row791622688165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p656824313165634"><a name="p656824313165634"></a><a name="p656824313165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p760875019165634"><a name="p760875019165634"></a><a name="p760875019165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1660936027165634"><a name="p1660936027165634"></a><a name="p1660936027165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row419466671165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1592604000165634"><a name="p1592604000165634"></a><a name="p1592604000165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858027688165634"><a name="p1858027688165634"></a><a name="p1858027688165634"></a>void </p>
<p id="p2013607301165634"><a name="p2013607301165634"></a><a name="p2013607301165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row337109057165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1529736225165634"><a name="p1529736225165634"></a><a name="p1529736225165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1992072197165634"><a name="p1992072197165634"></a><a name="p1992072197165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p292586688165634"><a name="p292586688165634"></a><a name="p292586688165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row71251816165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1641216483165634"><a name="p1641216483165634"></a><a name="p1641216483165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p779781647165634"><a name="p779781647165634"></a><a name="p779781647165634"></a>bool </p>
<p id="p2047383533165634"><a name="p2047383533165634"></a><a name="p2047383533165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row616414613165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254893699165634"><a name="p254893699165634"></a><a name="p254893699165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111091173165634"><a name="p1111091173165634"></a><a name="p1111091173165634"></a>void </p>
<p id="p1400413543165634"><a name="p1400413543165634"></a><a name="p1400413543165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row63965036165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p817230015165634"><a name="p817230015165634"></a><a name="p817230015165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p571269835165634"><a name="p571269835165634"></a><a name="p571269835165634"></a>bool </p>
<p id="p1851224105165634"><a name="p1851224105165634"></a><a name="p1851224105165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row826221125165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1181435800165634"><a name="p1181435800165634"></a><a name="p1181435800165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916298916165634"><a name="p1916298916165634"></a><a name="p1916298916165634"></a>void </p>
<p id="p689682907165634"><a name="p689682907165634"></a><a name="p689682907165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row650408381165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1211039414165634"><a name="p1211039414165634"></a><a name="p1211039414165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403848715165634"><a name="p1403848715165634"></a><a name="p1403848715165634"></a>bool </p>
<p id="p994709509165634"><a name="p994709509165634"></a><a name="p994709509165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row564348248165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p266254946165634"><a name="p266254946165634"></a><a name="p266254946165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2141349894165634"><a name="p2141349894165634"></a><a name="p2141349894165634"></a>void </p>
<p id="p1571461573165634"><a name="p1571461573165634"></a><a name="p1571461573165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1704775903165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1031690941165634"><a name="p1031690941165634"></a><a name="p1031690941165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065258764165634"><a name="p1065258764165634"></a><a name="p1065258764165634"></a>bool </p>
<p id="p525070523165634"><a name="p525070523165634"></a><a name="p525070523165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row759604256165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1110993882165634"><a name="p1110993882165634"></a><a name="p1110993882165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p381541373165634"><a name="p381541373165634"></a><a name="p381541373165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1886760240165634"><a name="p1886760240165634"></a><a name="p1886760240165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1023449798165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397852707165634"><a name="p397852707165634"></a><a name="p397852707165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p425453233165634"><a name="p425453233165634"></a><a name="p425453233165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p539491192165634"><a name="p539491192165634"></a><a name="p539491192165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row872903711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p843694920165634"><a name="p843694920165634"></a><a name="p843694920165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1194499169165634"><a name="p1194499169165634"></a><a name="p1194499169165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p25538469165634"><a name="p25538469165634"></a><a name="p25538469165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row481958172165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560546531165634"><a name="p1560546531165634"></a><a name="p1560546531165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822921117165634"><a name="p1822921117165634"></a><a name="p1822921117165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p744208579165634"><a name="p744208579165634"></a><a name="p744208579165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1455019597165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1545835662165634"><a name="p1545835662165634"></a><a name="p1545835662165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1342046938165634"><a name="p1342046938165634"></a><a name="p1342046938165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1954580875165634"><a name="p1954580875165634"></a><a name="p1954580875165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row550732945165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141808663165634"><a name="p1141808663165634"></a><a name="p1141808663165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p979834038165634"><a name="p979834038165634"></a><a name="p979834038165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p647687441165634"><a name="p647687441165634"></a><a name="p647687441165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row740065981165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p768205460165634"><a name="p768205460165634"></a><a name="p768205460165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377566067165634"><a name="p1377566067165634"></a><a name="p1377566067165634"></a>void </p>
<p id="p1762786443165634"><a name="p1762786443165634"></a><a name="p1762786443165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1144996080165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p686292218165634"><a name="p686292218165634"></a><a name="p686292218165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624348530165634"><a name="p624348530165634"></a><a name="p624348530165634"></a>virtual void </p>
<p id="p924151312165634"><a name="p924151312165634"></a><a name="p924151312165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row20490884165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2067370411165634"><a name="p2067370411165634"></a><a name="p2067370411165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768001581165634"><a name="p1768001581165634"></a><a name="p1768001581165634"></a>virtual int16_t </p>
<p id="p440844472165634"><a name="p440844472165634"></a><a name="p440844472165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row49260185165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811617450165634"><a name="p1811617450165634"></a><a name="p1811617450165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p526034451165634"><a name="p526034451165634"></a><a name="p526034451165634"></a>virtual void </p>
<p id="p264499986165634"><a name="p264499986165634"></a><a name="p264499986165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1006363691165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1291137310165634"><a name="p1291137310165634"></a><a name="p1291137310165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p930756954165634"><a name="p930756954165634"></a><a name="p930756954165634"></a>virtual int16_t </p>
<p id="p807508912165634"><a name="p807508912165634"></a><a name="p807508912165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row470662943165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p327995206165634"><a name="p327995206165634"></a><a name="p327995206165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p645363688165634"><a name="p645363688165634"></a><a name="p645363688165634"></a>virtual void </p>
<p id="p956913181165634"><a name="p956913181165634"></a><a name="p956913181165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1490768060165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606943070165634"><a name="p606943070165634"></a><a name="p606943070165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216568850165634"><a name="p1216568850165634"></a><a name="p1216568850165634"></a>virtual void </p>
<p id="p1849934853165634"><a name="p1849934853165634"></a><a name="p1849934853165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row498575637165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1102653841165634"><a name="p1102653841165634"></a><a name="p1102653841165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p71755886165634"><a name="p71755886165634"></a><a name="p71755886165634"></a>int16_t </p>
<p id="p51843255165634"><a name="p51843255165634"></a><a name="p51843255165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row2087444637165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664626498165634"><a name="p664626498165634"></a><a name="p664626498165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1446604879165634"><a name="p1446604879165634"></a><a name="p1446604879165634"></a>virtual void </p>
<p id="p169583777165634"><a name="p169583777165634"></a><a name="p169583777165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row493365569165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p526358192165634"><a name="p526358192165634"></a><a name="p526358192165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1826466319165634"><a name="p1826466319165634"></a><a name="p1826466319165634"></a>int16_t </p>
<p id="p148567083165634"><a name="p148567083165634"></a><a name="p148567083165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row759232370165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864911029165634"><a name="p1864911029165634"></a><a name="p1864911029165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961538101165634"><a name="p1961538101165634"></a><a name="p1961538101165634"></a>virtual void </p>
<p id="p780720931165634"><a name="p780720931165634"></a><a name="p780720931165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1542749285165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1246692199165634"><a name="p1246692199165634"></a><a name="p1246692199165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p44790190165634"><a name="p44790190165634"></a><a name="p44790190165634"></a>virtual void </p>
<p id="p1620516366165634"><a name="p1620516366165634"></a><a name="p1620516366165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1178908781165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1202929900165634"><a name="p1202929900165634"></a><a name="p1202929900165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382398337165634"><a name="p382398337165634"></a><a name="p382398337165634"></a>bool </p>
<p id="p2089784300165634"><a name="p2089784300165634"></a><a name="p2089784300165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row1454031299165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p450054420165634"><a name="p450054420165634"></a><a name="p450054420165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945056613165634"><a name="p945056613165634"></a><a name="p945056613165634"></a>void </p>
<p id="p1317944554165634"><a name="p1317944554165634"></a><a name="p1317944554165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row100483446165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p975902654165634"><a name="p975902654165634"></a><a name="p975902654165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1823413627165634"><a name="p1823413627165634"></a><a name="p1823413627165634"></a>void </p>
<p id="p1627245900165634"><a name="p1627245900165634"></a><a name="p1627245900165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1498316080165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1901234934165634"><a name="p1901234934165634"></a><a name="p1901234934165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107765515165634"><a name="p107765515165634"></a><a name="p107765515165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p971235348165634"><a name="p971235348165634"></a><a name="p971235348165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1508588778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175498052165634"><a name="p175498052165634"></a><a name="p175498052165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p537388659165634"><a name="p537388659165634"></a><a name="p537388659165634"></a>void </p>
<p id="p487697899165634"><a name="p487697899165634"></a><a name="p487697899165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1431433751165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p960476728165634"><a name="p960476728165634"></a><a name="p960476728165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1015166813165634"><a name="p1015166813165634"></a><a name="p1015166813165634"></a>const char * </p>
<p id="p380309236165634"><a name="p380309236165634"></a><a name="p380309236165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row545488635165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2111879799165634"><a name="p2111879799165634"></a><a name="p2111879799165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1179639330165634"><a name="p1179639330165634"></a><a name="p1179639330165634"></a>void </p>
<p id="p1063756816165634"><a name="p1063756816165634"></a><a name="p1063756816165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1031367053165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1747241478165634"><a name="p1747241478165634"></a><a name="p1747241478165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460326514165634"><a name="p460326514165634"></a><a name="p460326514165634"></a>int16_t </p>
<p id="p1355580420165634"><a name="p1355580420165634"></a><a name="p1355580420165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row606210237165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120338364165634"><a name="p2120338364165634"></a><a name="p2120338364165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2119498673165634"><a name="p2119498673165634"></a><a name="p2119498673165634"></a>virtual void </p>
<p id="p297397289165634"><a name="p297397289165634"></a><a name="p297397289165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row882282680165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p194022859165634"><a name="p194022859165634"></a><a name="p194022859165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1563698518165634"><a name="p1563698518165634"></a><a name="p1563698518165634"></a>void </p>
<p id="p1675957740165634"><a name="p1675957740165634"></a><a name="p1675957740165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1481002942165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1361451200165634"><a name="p1361451200165634"></a><a name="p1361451200165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366104947165634"><a name="p366104947165634"></a><a name="p366104947165634"></a>void </p>
<p id="p277877504165634"><a name="p277877504165634"></a><a name="p277877504165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1960484873165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1075621074165634"><a name="p1075621074165634"></a><a name="p1075621074165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p315597487165634"><a name="p315597487165634"></a><a name="p315597487165634"></a>void </p>
<p id="p429349299165634"><a name="p429349299165634"></a><a name="p429349299165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row734390222165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445830490165634"><a name="p445830490165634"></a><a name="p445830490165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p794155299165634"><a name="p794155299165634"></a><a name="p794155299165634"></a>void </p>
<p id="p1312428653165634"><a name="p1312428653165634"></a><a name="p1312428653165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1631072067165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997286118165634"><a name="p1997286118165634"></a><a name="p1997286118165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1024909261165634"><a name="p1024909261165634"></a><a name="p1024909261165634"></a>void </p>
<p id="p1367678003165634"><a name="p1367678003165634"></a><a name="p1367678003165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row2015541054165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p554125874165634"><a name="p554125874165634"></a><a name="p554125874165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p577065785165634"><a name="p577065785165634"></a><a name="p577065785165634"></a>void </p>
<p id="p1940102667165634"><a name="p1940102667165634"></a><a name="p1940102667165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row44855727165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439168104165634"><a name="p1439168104165634"></a><a name="p1439168104165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p323792380165634"><a name="p323792380165634"></a><a name="p323792380165634"></a>void </p>
<p id="p499615519165634"><a name="p499615519165634"></a><a name="p499615519165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row2141722920165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2032852791165634"><a name="p2032852791165634"></a><a name="p2032852791165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818245038165634"><a name="p1818245038165634"></a><a name="p1818245038165634"></a>void </p>
<p id="p1889982762165634"><a name="p1889982762165634"></a><a name="p1889982762165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row415031369165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355584223165634"><a name="p1355584223165634"></a><a name="p1355584223165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1156838007165634"><a name="p1156838007165634"></a><a name="p1156838007165634"></a>void </p>
<p id="p272998726165634"><a name="p272998726165634"></a><a name="p272998726165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1507987701165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1061424388165634"><a name="p1061424388165634"></a><a name="p1061424388165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2001360788165634"><a name="p2001360788165634"></a><a name="p2001360788165634"></a>void </p>
<p id="p900004891165634"><a name="p900004891165634"></a><a name="p900004891165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row460974429165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1162960651165634"><a name="p1162960651165634"></a><a name="p1162960651165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p405281212165634"><a name="p405281212165634"></a><a name="p405281212165634"></a>void </p>
<p id="p1336046281165634"><a name="p1336046281165634"></a><a name="p1336046281165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row374898136165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p100345214165634"><a name="p100345214165634"></a><a name="p100345214165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33684342165634"><a name="p33684342165634"></a><a name="p33684342165634"></a>void </p>
<p id="p1961085904165634"><a name="p1961085904165634"></a><a name="p1961085904165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1437232060165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1959105509165634"><a name="p1959105509165634"></a><a name="p1959105509165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215187824165634"><a name="p1215187824165634"></a><a name="p1215187824165634"></a>void </p>
<p id="p349449936165634"><a name="p349449936165634"></a><a name="p349449936165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1753491756165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716245956165634"><a name="p1716245956165634"></a><a name="p1716245956165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1457228948165634"><a name="p1457228948165634"></a><a name="p1457228948165634"></a>void </p>
<p id="p1599012793165634"><a name="p1599012793165634"></a><a name="p1599012793165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row428017243165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p313974732165634"><a name="p313974732165634"></a><a name="p313974732165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p711651142165634"><a name="p711651142165634"></a><a name="p711651142165634"></a>void </p>
<p id="p389390118165634"><a name="p389390118165634"></a><a name="p389390118165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row2092715275165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p241356563165634"><a name="p241356563165634"></a><a name="p241356563165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1012763266165634"><a name="p1012763266165634"></a><a name="p1012763266165634"></a>void </p>
<p id="p1118328698165634"><a name="p1118328698165634"></a><a name="p1118328698165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row824549905165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406346251165634"><a name="p406346251165634"></a><a name="p406346251165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1851978814165634"><a name="p1851978814165634"></a><a name="p1851978814165634"></a>virtual void </p>
<p id="p952064624165634"><a name="p952064624165634"></a><a name="p952064624165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row2030032653165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p852627261165634"><a name="p852627261165634"></a><a name="p852627261165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1087573434165634"><a name="p1087573434165634"></a><a name="p1087573434165634"></a>virtual int64_t </p>
<p id="p2015154850165634"><a name="p2015154850165634"></a><a name="p2015154850165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row333239453165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p30077960165634"><a name="p30077960165634"></a><a name="p30077960165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p38911712165634"><a name="p38911712165634"></a><a name="p38911712165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p1166078891165634"><a name="p1166078891165634"></a><a name="p1166078891165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1131384481165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1128993530165634"><a name="p1128993530165634"></a><a name="p1128993530165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1303039584165634"><a name="p1303039584165634"></a><a name="p1303039584165634"></a>void * </p>
<p id="p1535682608165634"><a name="p1535682608165634"></a><a name="p1535682608165634"></a>Overrides the <strong id="b128374398165634"><a name="b128374398165634"></a><a name="b128374398165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row722384107165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1032502394165634"><a name="p1032502394165634"></a><a name="p1032502394165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592932889165634"><a name="p592932889165634"></a><a name="p592932889165634"></a>void </p>
<p id="p2020445047165634"><a name="p2020445047165634"></a><a name="p2020445047165634"></a>Overrides the <strong id="b1601358434165634"><a name="b1601358434165634"></a><a name="b1601358434165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table2133587855165634"></a>
<table><thead align="left"><tr id="row201856739165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1493612165634"><a name="p1493612165634"></a><a name="p1493612165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2145866009165634"><a name="p2145866009165634"></a><a name="p2145866009165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row417668216165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p834557655165634"><a name="p834557655165634"></a><a name="p834557655165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p630346907165634"><a name="p630346907165634"></a><a name="p630346907165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row291886650165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1677790568165634"><a name="p1677790568165634"></a><a name="p1677790568165634"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761852784165634"><a name="p1761852784165634"></a><a name="p1761852784165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1308972852165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p59919026165634"><a name="p59919026165634"></a><a name="p59919026165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p51780099165634"><a name="p51780099165634"></a><a name="p51780099165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row625164083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p72158675165634"><a name="p72158675165634"></a><a name="p72158675165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1195005038165634"><a name="p1195005038165634"></a><a name="p1195005038165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1262134863165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526567821165634"><a name="p1526567821165634"></a><a name="p1526567821165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1197112778165634"><a name="p1197112778165634"></a><a name="p1197112778165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1870245131165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1703343915165634"><a name="p1703343915165634"></a><a name="p1703343915165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p113495663165634"><a name="p113495663165634"></a><a name="p113495663165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1004444870165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p98416528165634"><a name="p98416528165634"></a><a name="p98416528165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404020036165634"><a name="p1404020036165634"></a><a name="p1404020036165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row541881064165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p48840179165634"><a name="p48840179165634"></a><a name="p48840179165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1713240497165634"><a name="p1713240497165634"></a><a name="p1713240497165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

