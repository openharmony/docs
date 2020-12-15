# OHOS::UITimePicker<a name="ZH-CN_TOPIC_0000001054879560"></a>

-   [Overview](#section1455977287165635)
-   [Summary](#section816318413165635)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1455977287165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines the time picker. The time is in the format of "hour:minute" or "hour:minute:second". The selected time is highlighted. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section816318413165635"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table709189306165635"></a>
<table><thead align="left"><tr id="row1510605971165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p464153995165635"><a name="p464153995165635"></a><a name="p464153995165635"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p58951049165635"><a name="p58951049165635"></a><a name="p58951049165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1690697410165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1542090361165635"><a name="p1542090361165635"></a><a name="p1542090361165635"></a><a href="OHOS-UITimePicker-SelectedListener.md">SelectedListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108284566165635"><a name="p108284566165635"></a><a name="p108284566165635"></a>Defines the listener used by the time picker. This listener is triggered when an item is selected after sliding stops. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table259737586165635"></a>
<table><thead align="left"><tr id="row696585634165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p568707202165635"><a name="p568707202165635"></a><a name="p568707202165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1348238793165635"><a name="p1348238793165635"></a><a name="p1348238793165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row299093136165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838880090165635"><a name="p1838880090165635"></a><a name="p1838880090165635"></a><a href="Graphic.md#ga125b46b02ee28c0ba6403ef024196b03">UITimePicker</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p481289851165635"><a name="p481289851165635"></a><a name="p481289851165635"></a> </p>
<p id="p1805307649165635"><a name="p1805307649165635"></a><a name="p1805307649165635"></a>A constructor used to create a <strong id="b1535829574165635"><a name="b1535829574165635"></a><a name="b1535829574165635"></a><a href="OHOS-UITimePicker.md">UITimePicker</a></strong> instance. </p>
</td>
</tr>
<tr id="row1433644745165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p288381890165635"><a name="p288381890165635"></a><a name="p288381890165635"></a><a href="Graphic.md#gaf5906b1a1389a599c0086f25cfc02fa0">~UITimePicker</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p724565653165635"><a name="p724565653165635"></a><a name="p724565653165635"></a>virtual </p>
<p id="p953577577165635"><a name="p953577577165635"></a><a name="p953577577165635"></a>A destructor used to delete the <strong id="b206270979165635"><a name="b206270979165635"></a><a name="b206270979165635"></a><a href="OHOS-UITimePicker.md">UITimePicker</a></strong> instance. </p>
</td>
</tr>
<tr id="row1128814981165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p996470774165635"><a name="p996470774165635"></a><a name="p996470774165635"></a><a href="Graphic.md#gaf4770cfad2f6368b22e9ea581b12aefa">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p26423425165635"><a name="p26423425165635"></a><a name="p26423425165635"></a>UIViewType </p>
<p id="p375624175165635"><a name="p375624175165635"></a><a name="p375624175165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row408951684165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274513276165635"><a name="p1274513276165635"></a><a name="p1274513276165635"></a><a href="Graphic.md#gaecddab27ffd11267d3f613a1cf7f1549">SetSelected</a> (const char *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629177361165635"><a name="p629177361165635"></a><a name="p629177361165635"></a>bool </p>
<p id="p416639259165635"><a name="p416639259165635"></a><a name="p416639259165635"></a>Sets the time currently selected in the time picker. </p>
</td>
</tr>
<tr id="row548293606165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p151863682165635"><a name="p151863682165635"></a><a name="p151863682165635"></a><a href="Graphic.md#gac8c1732e78fa64af294694b2bbb35366">GetSelectValue</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1330131817165635"><a name="p1330131817165635"></a><a name="p1330131817165635"></a>const char * </p>
<p id="p1702592607165635"><a name="p1702592607165635"></a><a name="p1702592607165635"></a>Obtains the time currently selected in the time picker. </p>
</td>
</tr>
<tr id="row1749637335165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p472254784165635"><a name="p472254784165635"></a><a name="p472254784165635"></a><a href="Graphic.md#gac6475a538bb4e0e839dd8f9b0e3ae200">GetSelectHour</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p40411326165635"><a name="p40411326165635"></a><a name="p40411326165635"></a>const char * </p>
<p id="p1033463013165635"><a name="p1033463013165635"></a><a name="p1033463013165635"></a>Obtains the hour currently selected in the time picker. </p>
</td>
</tr>
<tr id="row1731102595165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1201315090165635"><a name="p1201315090165635"></a><a name="p1201315090165635"></a><a href="Graphic.md#ga0ccecc8d45fdda042ea0667ab9cc1181">GetSelectMinute</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1668911899165635"><a name="p1668911899165635"></a><a name="p1668911899165635"></a>const char * </p>
<p id="p573181780165635"><a name="p573181780165635"></a><a name="p573181780165635"></a>Obtains the minute currently selected in the time picker. </p>
</td>
</tr>
<tr id="row1211932081165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1106854403165635"><a name="p1106854403165635"></a><a name="p1106854403165635"></a><a href="Graphic.md#ga2e02f298f9b9bcf0520ebd2d0ef40677">GetSelectSecond</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618476429165635"><a name="p1618476429165635"></a><a name="p1618476429165635"></a>const char * </p>
<p id="p1199790648165635"><a name="p1199790648165635"></a><a name="p1199790648165635"></a>Obtains the second currently selected in the time picker. </p>
</td>
</tr>
<tr id="row2108229842165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790494900165635"><a name="p1790494900165635"></a><a name="p1790494900165635"></a><a href="Graphic.md#ga54e8588b0be58272d1fef244c5e9ba27">SetItemHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1246636711165635"><a name="p1246636711165635"></a><a name="p1246636711165635"></a>void </p>
<p id="p957378627165635"><a name="p957378627165635"></a><a name="p957378627165635"></a>Sets the height of each item in the time picker. </p>
</td>
</tr>
<tr id="row1271714432165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766370475165635"><a name="p1766370475165635"></a><a name="p1766370475165635"></a><a href="Graphic.md#gaa2402a0538f08fb4d6857c356be7699c">EnableSecond</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261035770165635"><a name="p261035770165635"></a><a name="p261035770165635"></a>void </p>
<p id="p1874166147165635"><a name="p1874166147165635"></a><a name="p1874166147165635"></a>Sets whether to enable seconds in the time picker. </p>
</td>
</tr>
<tr id="row2076572455165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p278599677165635"><a name="p278599677165635"></a><a name="p278599677165635"></a><a href="Graphic.md#gab1847d20b4ae671aaa512f978e043ee1">SetTextStyle</a> (uint8_t backgroundFontId, uint8_t highlightFontId, <a href="OHOS-Color32.md">ColorType</a> backgroundColor, <a href="OHOS-Color32.md">ColorType</a> highlightColor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p429279837165635"><a name="p429279837165635"></a><a name="p429279837165635"></a>void </p>
<p id="p1543169652165635"><a name="p1543169652165635"></a><a name="p1543169652165635"></a>Sets the text format in the time picker, including the font ID and color. </p>
</td>
</tr>
<tr id="row1165516935165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809764195165635"><a name="p1809764195165635"></a><a name="p1809764195165635"></a><a href="Graphic.md#ga4d7878f9ad47c81c81e22dfbf6efb3cd">SetTextColor</a> (<a href="OHOS-Color32.md">ColorType</a> backgroundColor, <a href="OHOS-Color32.md">ColorType</a> highlightColor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p143396723165635"><a name="p143396723165635"></a><a name="p143396723165635"></a>void </p>
<p id="p1498665409165635"><a name="p1498665409165635"></a><a name="p1498665409165635"></a>Sets the text color in the time picker. </p>
</td>
</tr>
<tr id="row912254527165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p15885094165635"><a name="p15885094165635"></a><a name="p15885094165635"></a><a href="Graphic.md#ga42de341630d7c681674df31a22e77856">SetBackgroundFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1482699525165635"><a name="p1482699525165635"></a><a name="p1482699525165635"></a>void </p>
<p id="p1275025778165635"><a name="p1275025778165635"></a><a name="p1275025778165635"></a>Sets the font name and size for the background text. </p>
</td>
</tr>
<tr id="row2040043156165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628311465165635"><a name="p628311465165635"></a><a name="p628311465165635"></a><a href="Graphic.md#ga2a340bb688a9ecc28d621daa6d570e07">SetHighlightFont</a> (const char *name, uint8_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1220476155165635"><a name="p1220476155165635"></a><a name="p1220476155165635"></a>void </p>
<p id="p1983029935165635"><a name="p1983029935165635"></a><a name="p1983029935165635"></a>Sets the font name and size for the highlighted text. </p>
</td>
</tr>
<tr id="row1385983582165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1724418763165635"><a name="p1724418763165635"></a><a name="p1724418763165635"></a><a href="Graphic.md#gad8dc3b2df7fe8aed16776a063efc8b4b">SetWidth</a> (int16_t width) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34038102165635"><a name="p34038102165635"></a><a name="p34038102165635"></a>void </p>
<p id="p1897171780165635"><a name="p1897171780165635"></a><a name="p1897171780165635"></a>Sets the width for the time picker. </p>
</td>
</tr>
<tr id="row488868062165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p324559481165635"><a name="p324559481165635"></a><a name="p324559481165635"></a><a href="Graphic.md#ga06667e791f24098f22ef096ee6af77ad">SetHeight</a> (int16_t height) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p811640202165635"><a name="p811640202165635"></a><a name="p811640202165635"></a>void </p>
<p id="p1895469731165635"><a name="p1895469731165635"></a><a name="p1895469731165635"></a>Sets the height for the time picker. </p>
</td>
</tr>
<tr id="row492528101165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1872157005165635"><a name="p1872157005165635"></a><a name="p1872157005165635"></a><a href="Graphic.md#gaa49ecf72e74e9b835c6fc19c701bf454">RegisterSelectedListener</a> (<a href="OHOS-UITimePicker-SelectedListener.md">SelectedListener</a> *timePickerListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282876848165635"><a name="p1282876848165635"></a><a name="p1282876848165635"></a>void </p>
<p id="p1326980553165635"><a name="p1326980553165635"></a><a name="p1326980553165635"></a>Registers a listener for a selected event. </p>
</td>
</tr>
<tr id="row544235390165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196338778165635"><a name="p1196338778165635"></a><a name="p1196338778165635"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p477882616165635"><a name="p477882616165635"></a><a name="p477882616165635"></a> </p>
<p id="p1677793779165635"><a name="p1677793779165635"></a><a name="p1677793779165635"></a>A default constructor used to create a <strong id="b1740613903165635"><a name="b1740613903165635"></a><a name="b1740613903165635"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1123773804165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1011448271165635"><a name="p1011448271165635"></a><a name="p1011448271165635"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1776097468165635"><a name="p1776097468165635"></a><a name="p1776097468165635"></a>virtual </p>
<p id="p1021525257165635"><a name="p1021525257165635"></a><a name="p1021525257165635"></a>A destructor used to delete the <strong id="b425157414165635"><a name="b425157414165635"></a><a name="b425157414165635"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row195989221165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1564829755165635"><a name="p1564829755165635"></a><a name="p1564829755165635"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614912734165635"><a name="p1614912734165635"></a><a name="p1614912734165635"></a>UIViewType </p>
<p id="p908335326165635"><a name="p908335326165635"></a><a name="p908335326165635"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row960576497165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p113416116165635"><a name="p113416116165635"></a><a name="p113416116165635"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005645874165635"><a name="p1005645874165635"></a><a name="p1005645874165635"></a>virtual void </p>
<p id="p615156132165635"><a name="p615156132165635"></a><a name="p615156132165635"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row438235312165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p562829046165635"><a name="p562829046165635"></a><a name="p562829046165635"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1681363404165635"><a name="p1681363404165635"></a><a name="p1681363404165635"></a>virtual void </p>
<p id="p53126676165635"><a name="p53126676165635"></a><a name="p53126676165635"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1542752280165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p433363298165635"><a name="p433363298165635"></a><a name="p433363298165635"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1949413006165635"><a name="p1949413006165635"></a><a name="p1949413006165635"></a>virtual void </p>
<p id="p1334897093165635"><a name="p1334897093165635"></a><a name="p1334897093165635"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1807337360165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1683625529165635"><a name="p1683625529165635"></a><a name="p1683625529165635"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1081392194165635"><a name="p1081392194165635"></a><a name="p1081392194165635"></a>virtual void </p>
<p id="p614792768165635"><a name="p614792768165635"></a><a name="p614792768165635"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row171699980165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p699984823165635"><a name="p699984823165635"></a><a name="p699984823165635"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p923179214165635"><a name="p923179214165635"></a><a name="p923179214165635"></a>virtual void </p>
<p id="p962005226165635"><a name="p962005226165635"></a><a name="p962005226165635"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row2096852444165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p138962164165635"><a name="p138962164165635"></a><a name="p138962164165635"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170386676165635"><a name="p1170386676165635"></a><a name="p1170386676165635"></a>virtual void </p>
<p id="p306738173165635"><a name="p306738173165635"></a><a name="p306738173165635"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row279959332165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p922712376165635"><a name="p922712376165635"></a><a name="p922712376165635"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p256238605165635"><a name="p256238605165635"></a><a name="p256238605165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p810939257165635"><a name="p810939257165635"></a><a name="p810939257165635"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1796233476165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1678156156165635"><a name="p1678156156165635"></a><a name="p1678156156165635"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p524316509165635"><a name="p524316509165635"></a><a name="p524316509165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1251169209165635"><a name="p1251169209165635"></a><a name="p1251169209165635"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1031983663165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p339051609165635"><a name="p339051609165635"></a><a name="p339051609165635"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1577079451165635"><a name="p1577079451165635"></a><a name="p1577079451165635"></a>void </p>
<p id="p49166101165635"><a name="p49166101165635"></a><a name="p49166101165635"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row880084684165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313890424165635"><a name="p1313890424165635"></a><a name="p1313890424165635"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1551681295165635"><a name="p1551681295165635"></a><a name="p1551681295165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1791664826165635"><a name="p1791664826165635"></a><a name="p1791664826165635"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1808480686165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653596050165635"><a name="p653596050165635"></a><a name="p653596050165635"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695729251165635"><a name="p1695729251165635"></a><a name="p1695729251165635"></a>void </p>
<p id="p81235567165635"><a name="p81235567165635"></a><a name="p81235567165635"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row528236869165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587487900165635"><a name="p587487900165635"></a><a name="p587487900165635"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1656482860165635"><a name="p1656482860165635"></a><a name="p1656482860165635"></a> </p>
<p id="p2059060858165635"><a name="p2059060858165635"></a><a name="p2059060858165635"></a>A default constructor used to create an <strong id="b259425053165635"><a name="b259425053165635"></a><a name="b259425053165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row620853613165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p626071021165635"><a name="p626071021165635"></a><a name="p626071021165635"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p211447175165635"><a name="p211447175165635"></a><a name="p211447175165635"></a> </p>
<p id="p361959336165635"><a name="p361959336165635"></a><a name="p361959336165635"></a>A constructor used to create an <strong id="b1080488777165635"><a name="b1080488777165635"></a><a name="b1080488777165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row661393494165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p933787751165635"><a name="p933787751165635"></a><a name="p933787751165635"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73513952165635"><a name="p73513952165635"></a><a name="p73513952165635"></a>virtual </p>
<p id="p1459923326165635"><a name="p1459923326165635"></a><a name="p1459923326165635"></a>A destructor used to delete the <strong id="b325458402165635"><a name="b325458402165635"></a><a name="b325458402165635"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1705208013165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2140392453165635"><a name="p2140392453165635"></a><a name="p2140392453165635"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513590906165635"><a name="p1513590906165635"></a><a name="p1513590906165635"></a>virtual bool </p>
<p id="p1006968721165635"><a name="p1006968721165635"></a><a name="p1006968721165635"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row1045806270165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p596230420165635"><a name="p596230420165635"></a><a name="p596230420165635"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1792028706165635"><a name="p1792028706165635"></a><a name="p1792028706165635"></a>virtual void </p>
<p id="p1274823950165635"><a name="p1274823950165635"></a><a name="p1274823950165635"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row876258276165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p776615340165635"><a name="p776615340165635"></a><a name="p776615340165635"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p602538557165635"><a name="p602538557165635"></a><a name="p602538557165635"></a>virtual void </p>
<p id="p1589408617165635"><a name="p1589408617165635"></a><a name="p1589408617165635"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row940636892165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p517493763165635"><a name="p517493763165635"></a><a name="p517493763165635"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p701951025165635"><a name="p701951025165635"></a><a name="p701951025165635"></a>virtual void </p>
<p id="p225478485165635"><a name="p225478485165635"></a><a name="p225478485165635"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1386392509165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p247615948165635"><a name="p247615948165635"></a><a name="p247615948165635"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2050868853165635"><a name="p2050868853165635"></a><a name="p2050868853165635"></a>void </p>
<p id="p420990387165635"><a name="p420990387165635"></a><a name="p420990387165635"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1161728665165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p248250876165635"><a name="p248250876165635"></a><a name="p248250876165635"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1485056791165635"><a name="p1485056791165635"></a><a name="p1485056791165635"></a>void </p>
<p id="p1739496912165635"><a name="p1739496912165635"></a><a name="p1739496912165635"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row569032624165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p390930544165635"><a name="p390930544165635"></a><a name="p390930544165635"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p318252620165635"><a name="p318252620165635"></a><a name="p318252620165635"></a>virtual bool </p>
<p id="p993405456165635"><a name="p993405456165635"></a><a name="p993405456165635"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row2065080220165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1029819521165635"><a name="p1029819521165635"></a><a name="p1029819521165635"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1535631362165635"><a name="p1535631362165635"></a><a name="p1535631362165635"></a>virtual bool </p>
<p id="p1186757593165635"><a name="p1186757593165635"></a><a name="p1186757593165635"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row909538875165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p131562273165635"><a name="p131562273165635"></a><a name="p131562273165635"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p781666673165635"><a name="p781666673165635"></a><a name="p781666673165635"></a>virtual bool </p>
<p id="p385228403165635"><a name="p385228403165635"></a><a name="p385228403165635"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row1793746375165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653716239165635"><a name="p653716239165635"></a><a name="p653716239165635"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788019580165635"><a name="p788019580165635"></a><a name="p788019580165635"></a>virtual bool </p>
<p id="p930352431165635"><a name="p930352431165635"></a><a name="p930352431165635"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1774206726165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737617267165635"><a name="p1737617267165635"></a><a name="p1737617267165635"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p832989056165635"><a name="p832989056165635"></a><a name="p832989056165635"></a>virtual void </p>
<p id="p589186027165635"><a name="p589186027165635"></a><a name="p589186027165635"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row233660958165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2060793403165635"><a name="p2060793403165635"></a><a name="p2060793403165635"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2066118604165635"><a name="p2066118604165635"></a><a name="p2066118604165635"></a>virtual void </p>
<p id="p2077021460165635"><a name="p2077021460165635"></a><a name="p2077021460165635"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1616503160165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1069839877165635"><a name="p1069839877165635"></a><a name="p1069839877165635"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628599784165635"><a name="p1628599784165635"></a><a name="p1628599784165635"></a>virtual void </p>
<p id="p383537103165635"><a name="p383537103165635"></a><a name="p383537103165635"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row162759484165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245958714165635"><a name="p245958714165635"></a><a name="p245958714165635"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2028549978165635"><a name="p2028549978165635"></a><a name="p2028549978165635"></a>virtual void </p>
<p id="p1086471384165635"><a name="p1086471384165635"></a><a name="p1086471384165635"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1228936738165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65244389165635"><a name="p65244389165635"></a><a name="p65244389165635"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p270023149165635"><a name="p270023149165635"></a><a name="p270023149165635"></a>void </p>
<p id="p1570464589165635"><a name="p1570464589165635"></a><a name="p1570464589165635"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1349150941165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1539308433165635"><a name="p1539308433165635"></a><a name="p1539308433165635"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p35572616165635"><a name="p35572616165635"></a><a name="p35572616165635"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p70171764165635"><a name="p70171764165635"></a><a name="p70171764165635"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1190450633165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1707061046165635"><a name="p1707061046165635"></a><a name="p1707061046165635"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p63373666165635"><a name="p63373666165635"></a><a name="p63373666165635"></a>void </p>
<p id="p1912024018165635"><a name="p1912024018165635"></a><a name="p1912024018165635"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1142864534165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1657191656165635"><a name="p1657191656165635"></a><a name="p1657191656165635"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p744766526165635"><a name="p744766526165635"></a><a name="p744766526165635"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p205390954165635"><a name="p205390954165635"></a><a name="p205390954165635"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1134547553165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948116024165635"><a name="p1948116024165635"></a><a name="p1948116024165635"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14560981165635"><a name="p14560981165635"></a><a name="p14560981165635"></a>void </p>
<p id="p782936921165635"><a name="p782936921165635"></a><a name="p782936921165635"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row134721587165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1571962484165635"><a name="p1571962484165635"></a><a name="p1571962484165635"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332695942165635"><a name="p1332695942165635"></a><a name="p1332695942165635"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p22266309165635"><a name="p22266309165635"></a><a name="p22266309165635"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row5985863165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p792777345165635"><a name="p792777345165635"></a><a name="p792777345165635"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036224004165635"><a name="p1036224004165635"></a><a name="p1036224004165635"></a>void </p>
<p id="p712649886165635"><a name="p712649886165635"></a><a name="p712649886165635"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row1185820254165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894735542165635"><a name="p894735542165635"></a><a name="p894735542165635"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130109719165635"><a name="p1130109719165635"></a><a name="p1130109719165635"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p723156165165635"><a name="p723156165165635"></a><a name="p723156165165635"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row825354578165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306872276165635"><a name="p306872276165635"></a><a name="p306872276165635"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86184087165635"><a name="p86184087165635"></a><a name="p86184087165635"></a>void </p>
<p id="p690711608165635"><a name="p690711608165635"></a><a name="p690711608165635"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row1873084566165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p508956498165635"><a name="p508956498165635"></a><a name="p508956498165635"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346583781165635"><a name="p346583781165635"></a><a name="p346583781165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p2113178217165635"><a name="p2113178217165635"></a><a name="p2113178217165635"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row943104925165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p751654209165635"><a name="p751654209165635"></a><a name="p751654209165635"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1704844814165635"><a name="p1704844814165635"></a><a name="p1704844814165635"></a>void </p>
<p id="p509183593165635"><a name="p509183593165635"></a><a name="p509183593165635"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row867150303165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1691216609165635"><a name="p1691216609165635"></a><a name="p1691216609165635"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026209723165635"><a name="p1026209723165635"></a><a name="p1026209723165635"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p367723745165635"><a name="p367723745165635"></a><a name="p367723745165635"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1007080242165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735431497165635"><a name="p735431497165635"></a><a name="p735431497165635"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p578022237165635"><a name="p578022237165635"></a><a name="p578022237165635"></a>virtual void </p>
<p id="p739717597165635"><a name="p739717597165635"></a><a name="p739717597165635"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row208204564165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2053047319165635"><a name="p2053047319165635"></a><a name="p2053047319165635"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202181543165635"><a name="p1202181543165635"></a><a name="p1202181543165635"></a>bool </p>
<p id="p2063489259165635"><a name="p2063489259165635"></a><a name="p2063489259165635"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row316066417165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1231094065165635"><a name="p1231094065165635"></a><a name="p1231094065165635"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p109786461165635"><a name="p109786461165635"></a><a name="p109786461165635"></a>void </p>
<p id="p2113041902165635"><a name="p2113041902165635"></a><a name="p2113041902165635"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1436144280165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673322169165635"><a name="p673322169165635"></a><a name="p673322169165635"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196088445165635"><a name="p196088445165635"></a><a name="p196088445165635"></a>bool </p>
<p id="p138688245165635"><a name="p138688245165635"></a><a name="p138688245165635"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row382006480165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354775359165635"><a name="p1354775359165635"></a><a name="p1354775359165635"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1976990225165635"><a name="p1976990225165635"></a><a name="p1976990225165635"></a>void </p>
<p id="p256637364165635"><a name="p256637364165635"></a><a name="p256637364165635"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row534452483165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p718679913165635"><a name="p718679913165635"></a><a name="p718679913165635"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1257125650165635"><a name="p1257125650165635"></a><a name="p1257125650165635"></a>bool </p>
<p id="p787091247165635"><a name="p787091247165635"></a><a name="p787091247165635"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row2082669730165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1946288460165635"><a name="p1946288460165635"></a><a name="p1946288460165635"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1760750628165635"><a name="p1760750628165635"></a><a name="p1760750628165635"></a>void </p>
<p id="p1582815168165635"><a name="p1582815168165635"></a><a name="p1582815168165635"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1039784539165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229396266165635"><a name="p229396266165635"></a><a name="p229396266165635"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p524873252165635"><a name="p524873252165635"></a><a name="p524873252165635"></a>bool </p>
<p id="p1720400352165635"><a name="p1720400352165635"></a><a name="p1720400352165635"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1794890446165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p788307055165635"><a name="p788307055165635"></a><a name="p788307055165635"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572301192165635"><a name="p572301192165635"></a><a name="p572301192165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1185799491165635"><a name="p1185799491165635"></a><a name="p1185799491165635"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row396744489165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1611566856165635"><a name="p1611566856165635"></a><a name="p1611566856165635"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1618350605165635"><a name="p1618350605165635"></a><a name="p1618350605165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1162655148165635"><a name="p1162655148165635"></a><a name="p1162655148165635"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1787380445165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p237880519165635"><a name="p237880519165635"></a><a name="p237880519165635"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p605564348165635"><a name="p605564348165635"></a><a name="p605564348165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p100029501165635"><a name="p100029501165635"></a><a name="p100029501165635"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row624063791165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1172410616165635"><a name="p1172410616165635"></a><a name="p1172410616165635"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872692868165635"><a name="p1872692868165635"></a><a name="p1872692868165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p267505067165635"><a name="p267505067165635"></a><a name="p267505067165635"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1466818986165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p618098691165635"><a name="p618098691165635"></a><a name="p618098691165635"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p622385472165635"><a name="p622385472165635"></a><a name="p622385472165635"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p750093000165635"><a name="p750093000165635"></a><a name="p750093000165635"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1848928171165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482855704165635"><a name="p1482855704165635"></a><a name="p1482855704165635"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p498308479165635"><a name="p498308479165635"></a><a name="p498308479165635"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p214855182165635"><a name="p214855182165635"></a><a name="p214855182165635"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row1026866617165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2009244419165635"><a name="p2009244419165635"></a><a name="p2009244419165635"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1301475785165635"><a name="p1301475785165635"></a><a name="p1301475785165635"></a>void </p>
<p id="p1163707233165635"><a name="p1163707233165635"></a><a name="p1163707233165635"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row360064762165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p891312761165635"><a name="p891312761165635"></a><a name="p891312761165635"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1642582537165635"><a name="p1642582537165635"></a><a name="p1642582537165635"></a>virtual int16_t </p>
<p id="p1983785302165635"><a name="p1983785302165635"></a><a name="p1983785302165635"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row533355020165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1890924618165635"><a name="p1890924618165635"></a><a name="p1890924618165635"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p562807434165635"><a name="p562807434165635"></a><a name="p562807434165635"></a>virtual int16_t </p>
<p id="p32079744165635"><a name="p32079744165635"></a><a name="p32079744165635"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1382779776165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092122441165635"><a name="p2092122441165635"></a><a name="p2092122441165635"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1057124902165635"><a name="p1057124902165635"></a><a name="p1057124902165635"></a>virtual void </p>
<p id="p1796327137165635"><a name="p1796327137165635"></a><a name="p1796327137165635"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1180452385165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1518850751165635"><a name="p1518850751165635"></a><a name="p1518850751165635"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332900592165635"><a name="p1332900592165635"></a><a name="p1332900592165635"></a>virtual void </p>
<p id="p1531945602165635"><a name="p1531945602165635"></a><a name="p1531945602165635"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row379033718165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1465150626165635"><a name="p1465150626165635"></a><a name="p1465150626165635"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208683276165635"><a name="p1208683276165635"></a><a name="p1208683276165635"></a>int16_t </p>
<p id="p1070225770165635"><a name="p1070225770165635"></a><a name="p1070225770165635"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row493065247165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131900556165635"><a name="p2131900556165635"></a><a name="p2131900556165635"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p696482310165635"><a name="p696482310165635"></a><a name="p696482310165635"></a>virtual void </p>
<p id="p202408926165635"><a name="p202408926165635"></a><a name="p202408926165635"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2003599670165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1937854760165635"><a name="p1937854760165635"></a><a name="p1937854760165635"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p880660164165635"><a name="p880660164165635"></a><a name="p880660164165635"></a>int16_t </p>
<p id="p652697823165635"><a name="p652697823165635"></a><a name="p652697823165635"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row2017461902165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p783726074165635"><a name="p783726074165635"></a><a name="p783726074165635"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p747767065165635"><a name="p747767065165635"></a><a name="p747767065165635"></a>virtual void </p>
<p id="p101417291165635"><a name="p101417291165635"></a><a name="p101417291165635"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row699689920165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075364456165635"><a name="p2075364456165635"></a><a name="p2075364456165635"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p16724544165635"><a name="p16724544165635"></a><a name="p16724544165635"></a>virtual void </p>
<p id="p188219716165635"><a name="p188219716165635"></a><a name="p188219716165635"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1480085363165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1526034845165635"><a name="p1526034845165635"></a><a name="p1526034845165635"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474748528165635"><a name="p1474748528165635"></a><a name="p1474748528165635"></a>bool </p>
<p id="p1622917279165635"><a name="p1622917279165635"></a><a name="p1622917279165635"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row48846887165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1673562503165635"><a name="p1673562503165635"></a><a name="p1673562503165635"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1641530142165635"><a name="p1641530142165635"></a><a name="p1641530142165635"></a>void </p>
<p id="p1897039335165635"><a name="p1897039335165635"></a><a name="p1897039335165635"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row910776648165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2043738504165635"><a name="p2043738504165635"></a><a name="p2043738504165635"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2036873814165635"><a name="p2036873814165635"></a><a name="p2036873814165635"></a>void </p>
<p id="p1017275242165635"><a name="p1017275242165635"></a><a name="p1017275242165635"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1072441433165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1855974511165635"><a name="p1855974511165635"></a><a name="p1855974511165635"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1778062724165635"><a name="p1778062724165635"></a><a name="p1778062724165635"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p2038945665165635"><a name="p2038945665165635"></a><a name="p2038945665165635"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row2072826605165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p75306662165635"><a name="p75306662165635"></a><a name="p75306662165635"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1450750188165635"><a name="p1450750188165635"></a><a name="p1450750188165635"></a>void </p>
<p id="p1367425558165635"><a name="p1367425558165635"></a><a name="p1367425558165635"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1314162051165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p243902070165635"><a name="p243902070165635"></a><a name="p243902070165635"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1831963232165635"><a name="p1831963232165635"></a><a name="p1831963232165635"></a>const char * </p>
<p id="p802358394165635"><a name="p802358394165635"></a><a name="p802358394165635"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row1716171333165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p208780726165635"><a name="p208780726165635"></a><a name="p208780726165635"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2026778612165635"><a name="p2026778612165635"></a><a name="p2026778612165635"></a>void </p>
<p id="p1180050122165635"><a name="p1180050122165635"></a><a name="p1180050122165635"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row450823390165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790924475165635"><a name="p1790924475165635"></a><a name="p1790924475165635"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p148675512165635"><a name="p148675512165635"></a><a name="p148675512165635"></a>int16_t </p>
<p id="p210176303165635"><a name="p210176303165635"></a><a name="p210176303165635"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row2126048928165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674936397165635"><a name="p674936397165635"></a><a name="p674936397165635"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1507489476165635"><a name="p1507489476165635"></a><a name="p1507489476165635"></a>virtual void </p>
<p id="p118782990165635"><a name="p118782990165635"></a><a name="p118782990165635"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row172639109165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1065839997165635"><a name="p1065839997165635"></a><a name="p1065839997165635"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2017860070165635"><a name="p2017860070165635"></a><a name="p2017860070165635"></a>void </p>
<p id="p1508545307165635"><a name="p1508545307165635"></a><a name="p1508545307165635"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row19978137165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p315411923165635"><a name="p315411923165635"></a><a name="p315411923165635"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p276357058165635"><a name="p276357058165635"></a><a name="p276357058165635"></a>void </p>
<p id="p1448914306165635"><a name="p1448914306165635"></a><a name="p1448914306165635"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1844119983165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254644374165635"><a name="p254644374165635"></a><a name="p254644374165635"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368758982165635"><a name="p1368758982165635"></a><a name="p1368758982165635"></a>void </p>
<p id="p25373638165635"><a name="p25373638165635"></a><a name="p25373638165635"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row366132555165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p181461724165635"><a name="p181461724165635"></a><a name="p181461724165635"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1282158404165635"><a name="p1282158404165635"></a><a name="p1282158404165635"></a>void </p>
<p id="p325344797165635"><a name="p325344797165635"></a><a name="p325344797165635"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row238910438165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1439586135165635"><a name="p1439586135165635"></a><a name="p1439586135165635"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p249852996165635"><a name="p249852996165635"></a><a name="p249852996165635"></a>void </p>
<p id="p1268183974165635"><a name="p1268183974165635"></a><a name="p1268183974165635"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1983058534165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2147440100165635"><a name="p2147440100165635"></a><a name="p2147440100165635"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p154489802165635"><a name="p154489802165635"></a><a name="p154489802165635"></a>void </p>
<p id="p1225297456165635"><a name="p1225297456165635"></a><a name="p1225297456165635"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1567437417165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781183985165635"><a name="p1781183985165635"></a><a name="p1781183985165635"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p777763584165635"><a name="p777763584165635"></a><a name="p777763584165635"></a>void </p>
<p id="p1300260527165635"><a name="p1300260527165635"></a><a name="p1300260527165635"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1538381206165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p118468807165635"><a name="p118468807165635"></a><a name="p118468807165635"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22116905165635"><a name="p22116905165635"></a><a name="p22116905165635"></a>void </p>
<p id="p295641131165635"><a name="p295641131165635"></a><a name="p295641131165635"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row405274810165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p788384740165635"><a name="p788384740165635"></a><a name="p788384740165635"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2019586903165635"><a name="p2019586903165635"></a><a name="p2019586903165635"></a>void </p>
<p id="p442964384165635"><a name="p442964384165635"></a><a name="p442964384165635"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1881205132165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909438872165635"><a name="p909438872165635"></a><a name="p909438872165635"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1271380160165635"><a name="p1271380160165635"></a><a name="p1271380160165635"></a>void </p>
<p id="p1083039270165635"><a name="p1083039270165635"></a><a name="p1083039270165635"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row662013077165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1948198263165635"><a name="p1948198263165635"></a><a name="p1948198263165635"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722727581165635"><a name="p722727581165635"></a><a name="p722727581165635"></a>void </p>
<p id="p1910255747165635"><a name="p1910255747165635"></a><a name="p1910255747165635"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row701186714165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1473463995165635"><a name="p1473463995165635"></a><a name="p1473463995165635"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p138176717165635"><a name="p138176717165635"></a><a name="p138176717165635"></a>void </p>
<p id="p74413210165635"><a name="p74413210165635"></a><a name="p74413210165635"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1085622045165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263312700165635"><a name="p1263312700165635"></a><a name="p1263312700165635"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163783402165635"><a name="p163783402165635"></a><a name="p163783402165635"></a>void </p>
<p id="p80362678165635"><a name="p80362678165635"></a><a name="p80362678165635"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row1302887761165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p401871866165635"><a name="p401871866165635"></a><a name="p401871866165635"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p179675664165635"><a name="p179675664165635"></a><a name="p179675664165635"></a>void </p>
<p id="p1449344539165635"><a name="p1449344539165635"></a><a name="p1449344539165635"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1017376646165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719907276165635"><a name="p1719907276165635"></a><a name="p1719907276165635"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1858346079165635"><a name="p1858346079165635"></a><a name="p1858346079165635"></a>void </p>
<p id="p1064334703165635"><a name="p1064334703165635"></a><a name="p1064334703165635"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row966553374165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1468846050165635"><a name="p1468846050165635"></a><a name="p1468846050165635"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p406070565165635"><a name="p406070565165635"></a><a name="p406070565165635"></a>void </p>
<p id="p903272721165635"><a name="p903272721165635"></a><a name="p903272721165635"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1454213247165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1855079875165635"><a name="p1855079875165635"></a><a name="p1855079875165635"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040270639165635"><a name="p2040270639165635"></a><a name="p2040270639165635"></a>virtual void </p>
<p id="p1976147612165635"><a name="p1976147612165635"></a><a name="p1976147612165635"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1652315697165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1941294065165635"><a name="p1941294065165635"></a><a name="p1941294065165635"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460962664165635"><a name="p460962664165635"></a><a name="p460962664165635"></a>virtual int64_t </p>
<p id="p825718975165635"><a name="p825718975165635"></a><a name="p825718975165635"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1258645922165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612245830165635"><a name="p612245830165635"></a><a name="p612245830165635"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297142369165635"><a name="p297142369165635"></a><a name="p297142369165635"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p685405131165635"><a name="p685405131165635"></a><a name="p685405131165635"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row279624963165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1119887420165635"><a name="p1119887420165635"></a><a name="p1119887420165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1030663046165635"><a name="p1030663046165635"></a><a name="p1030663046165635"></a>void * </p>
<p id="p564123343165635"><a name="p564123343165635"></a><a name="p564123343165635"></a>Overrides the <strong id="b921951820165635"><a name="b921951820165635"></a><a name="b921951820165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1830226240165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191374088165635"><a name="p191374088165635"></a><a name="p191374088165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1355744376165635"><a name="p1355744376165635"></a><a name="p1355744376165635"></a>void </p>
<p id="p1384731263165635"><a name="p1384731263165635"></a><a name="p1384731263165635"></a>Overrides the <strong id="b618406016165635"><a name="b618406016165635"></a><a name="b618406016165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1124461660165635"></a>
<table><thead align="left"><tr id="row926889699165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1495192930165635"><a name="p1495192930165635"></a><a name="p1495192930165635"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1126555655165635"><a name="p1126555655165635"></a><a name="p1126555655165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row390606704165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1802018394165635"><a name="p1802018394165635"></a><a name="p1802018394165635"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1411239906165635"><a name="p1411239906165635"></a><a name="p1411239906165635"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row309197905165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184574763165635"><a name="p1184574763165635"></a><a name="p1184574763165635"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466743072165635"><a name="p466743072165635"></a><a name="p466743072165635"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row28205922165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264004607165635"><a name="p1264004607165635"></a><a name="p1264004607165635"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354897914165635"><a name="p1354897914165635"></a><a name="p1354897914165635"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row472765015165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p956952240165635"><a name="p956952240165635"></a><a name="p956952240165635"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121505232165635"><a name="p1121505232165635"></a><a name="p1121505232165635"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1589554914165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016421575165635"><a name="p2016421575165635"></a><a name="p2016421575165635"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p669627805165635"><a name="p669627805165635"></a><a name="p669627805165635"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row521594756165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p510678573165635"><a name="p510678573165635"></a><a name="p510678573165635"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p571960760165635"><a name="p571960760165635"></a><a name="p571960760165635"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row492366413165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848694014165635"><a name="p1848694014165635"></a><a name="p1848694014165635"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p790924171165635"><a name="p790924171165635"></a><a name="p790924171165635"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1906235630165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1689116340165635"><a name="p1689116340165635"></a><a name="p1689116340165635"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p328297929165635"><a name="p328297929165635"></a><a name="p328297929165635"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

