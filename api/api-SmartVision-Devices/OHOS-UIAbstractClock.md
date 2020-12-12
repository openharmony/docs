# OHOS::UIAbstractClock<a name="ZH-CN_TOPIC_0000001055358128"></a>

-   [Overview](#section224969549165633)
-   [Summary](#section2086266185165633)
-   [Public Types](#pub-types)
-   [Public Member Functions](#pub-methods)
-   [Static Public Attributes](#pub-static-attribs)
-   [Protected Attributes](#pro-attribs)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section224969549165633"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

An abstract class that contains functions for converting units of time \(hour, minute, and second\), setting and obtaining the time. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section2086266185165633"></a>

## Public Types<a name="pub-types"></a>

<a name="table273825151165633"></a>
<table><thead align="left"><tr id="row1308236191165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p403378376165633"><a name="p403378376165633"></a><a name="p403378376165633"></a>Public Type Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1438728687165633"><a name="p1438728687165633"></a><a name="p1438728687165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1443714965165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019000208165633"><a name="p2019000208165633"></a><a name="p2019000208165633"></a><a href="Graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> { <a href="Graphic.md#gga19db90932bc71e6bbced6ccf2935ac98a2025ac1a1f63409f0b37f444547ec859">ALWAYS_ON</a>, <a href="Graphic.md#gga19db90932bc71e6bbced6ccf2935ac98a8d32f103a422c6675618f5e9773b2eaa">NORMAL</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1054604059165633"><a name="p1054604059165633"></a><a name="p1054604059165633"></a>Enumerates the working modes of this clock. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table164343439165633"></a>
<table><thead align="left"><tr id="row1652236817165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1830320686165633"><a name="p1830320686165633"></a><a name="p1830320686165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p651100818165633"><a name="p651100818165633"></a><a name="p651100818165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row899211784165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p634428938165633"><a name="p634428938165633"></a><a name="p634428938165633"></a><a href="Graphic.md#ga160a40d9f81c72b606b3c5b05168bacf">UIAbstractClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1689630029165633"><a name="p1689630029165633"></a><a name="p1689630029165633"></a> </p>
<p id="p1450465049165633"><a name="p1450465049165633"></a><a name="p1450465049165633"></a>A default constructor used to create a <strong id="b1223470595165633"><a name="b1223470595165633"></a><a name="b1223470595165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row531569764165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p699001948165633"><a name="p699001948165633"></a><a name="p699001948165633"></a><a href="Graphic.md#ga93d3d68e48a79ee7fc4b42a9c0c0ccc1">UIAbstractClock</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p273785470165633"><a name="p273785470165633"></a><a name="p273785470165633"></a> </p>
<p id="p777591829165633"><a name="p777591829165633"></a><a name="p777591829165633"></a>A constructor used to create a <strong id="b1433829051165633"><a name="b1433829051165633"></a><a name="b1433829051165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong> instance with time elements (hour, minute and second). </p>
</td>
</tr>
<tr id="row1888477334165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1859159861165633"><a name="p1859159861165633"></a><a name="p1859159861165633"></a><a href="Graphic.md#ga0fb0c108b319f02b9d42b34c1d2c8708">~UIAbstractClock</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1512112404165633"><a name="p1512112404165633"></a><a name="p1512112404165633"></a>virtual </p>
<p id="p2117505264165633"><a name="p2117505264165633"></a><a name="p2117505264165633"></a>A destructor used to delete the <strong id="b2128492352165633"><a name="b2128492352165633"></a><a name="b2128492352165633"></a><a href="OHOS-UIAbstractClock.md">UIAbstractClock</a></strong> instance. </p>
</td>
</tr>
<tr id="row802048732165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p944133597165633"><a name="p944133597165633"></a><a name="p944133597165633"></a><a href="Graphic.md#ga8f7edc9e099688b4fd2b3ed3171eac58">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p601543443165633"><a name="p601543443165633"></a><a name="p601543443165633"></a>UIViewType </p>
<p id="p1965338853165633"><a name="p1965338853165633"></a><a name="p1965338853165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1039740873165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931234347165633"><a name="p931234347165633"></a><a name="p931234347165633"></a><a href="Graphic.md#ga44a7312163a4192670c00bb8f9916e51">SetTime24Hour</a> (uint8_t hour, uint8_t minute, uint8_t second)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809858128165633"><a name="p1809858128165633"></a><a name="p1809858128165633"></a>void </p>
<p id="p1895435398165633"><a name="p1895435398165633"></a><a name="p1895435398165633"></a>Sets the time in 24-hour format. </p>
</td>
</tr>
<tr id="row1400989172165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242308323165633"><a name="p1242308323165633"></a><a name="p1242308323165633"></a><a href="Graphic.md#ga37750dfa0b5a47c8dcb61547dd991a6a">SetTime12Hour</a> (uint8_t hour, uint8_t minute, uint8_t second, bool am)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p302734247165633"><a name="p302734247165633"></a><a name="p302734247165633"></a>void </p>
<p id="p1189459762165633"><a name="p1189459762165633"></a><a name="p1189459762165633"></a>Sets the time in 12-hour format. </p>
</td>
</tr>
<tr id="row913771886165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107350528165633"><a name="p1107350528165633"></a><a name="p1107350528165633"></a><a href="Graphic.md#ga8cf863dfcd63410f2f20572a51f2516b">GetCurrentHour</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383133401165633"><a name="p1383133401165633"></a><a name="p1383133401165633"></a>uint8_t </p>
<p id="p1348465289165633"><a name="p1348465289165633"></a><a name="p1348465289165633"></a>Obtains the current number of hours. </p>
</td>
</tr>
<tr id="row8263464165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14456106165633"><a name="p14456106165633"></a><a name="p14456106165633"></a><a href="Graphic.md#ga5f0eea09577104d9126a07bfbc0b780a">GetCurrentMinute</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1883943419165633"><a name="p1883943419165633"></a><a name="p1883943419165633"></a>uint8_t </p>
<p id="p1711069787165633"><a name="p1711069787165633"></a><a name="p1711069787165633"></a>Obtains the current number of minutes. </p>
</td>
</tr>
<tr id="row1202177586165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p286377108165633"><a name="p286377108165633"></a><a name="p286377108165633"></a><a href="Graphic.md#ga7bd4d2d4631d9ea373d008ec7a5d18ff">GetCurrentSecond</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1473717308165633"><a name="p1473717308165633"></a><a name="p1473717308165633"></a>uint8_t </p>
<p id="p1290898624165633"><a name="p1290898624165633"></a><a name="p1290898624165633"></a>Obtains the current number of seconds. </p>
</td>
</tr>
<tr id="row2146955879165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116083735165633"><a name="p2116083735165633"></a><a name="p2116083735165633"></a><a href="Graphic.md#gaf4c05e6acf6700d7edb69dc49cd6fef8">IncOneSecond</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p317555395165633"><a name="p317555395165633"></a><a name="p317555395165633"></a>void </p>
<p id="p17278263165633"><a name="p17278263165633"></a><a name="p17278263165633"></a>Increases the time by one second. </p>
</td>
</tr>
<tr id="row8638846165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191178920165633"><a name="p191178920165633"></a><a name="p191178920165633"></a><a href="Graphic.md#gad7c0fba1eac5d10998954e9c1e097197">UpdateClock</a> (bool clockInit)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p222580219165633"><a name="p222580219165633"></a><a name="p222580219165633"></a>virtual void </p>
<p id="p428979236165633"><a name="p428979236165633"></a><a name="p428979236165633"></a>Updates this clock. </p>
</td>
</tr>
<tr id="row1136847084165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358721012165633"><a name="p358721012165633"></a><a name="p358721012165633"></a><a href="Graphic.md#gaafa5df66c896268de27bf335c1b72b92">SetWorkMode</a> (<a href="Graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> newMode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484378604165633"><a name="p1484378604165633"></a><a name="p1484378604165633"></a>virtual void </p>
<p id="p123143264165633"><a name="p123143264165633"></a><a name="p123143264165633"></a>Sets the working mode for this clock. </p>
</td>
</tr>
<tr id="row1284105004165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p327737125165633"><a name="p327737125165633"></a><a name="p327737125165633"></a><a href="Graphic.md#gad2d78422d212ef1e93bb4a23e1ee3859">GetWorkMode</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p461261498165633"><a name="p461261498165633"></a><a name="p461261498165633"></a>virtual <a href="Graphic.md#ga19db90932bc71e6bbced6ccf2935ac98">WorkMode</a> </p>
<p id="p1954782002165633"><a name="p1954782002165633"></a><a name="p1954782002165633"></a>Obtains the working mode of this clock. </p>
</td>
</tr>
<tr id="row51898069165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1520368005165633"><a name="p1520368005165633"></a><a name="p1520368005165633"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p943051184165633"><a name="p943051184165633"></a><a name="p943051184165633"></a> </p>
<p id="p249555555165633"><a name="p249555555165633"></a><a name="p249555555165633"></a>A default constructor used to create a <strong id="b1452708974165633"><a name="b1452708974165633"></a><a name="b1452708974165633"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1821684875165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1987778152165633"><a name="p1987778152165633"></a><a name="p1987778152165633"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1916337058165633"><a name="p1916337058165633"></a><a name="p1916337058165633"></a>virtual </p>
<p id="p954920436165633"><a name="p954920436165633"></a><a name="p954920436165633"></a>A destructor used to delete the <strong id="b1732694665165633"><a name="b1732694665165633"></a><a name="b1732694665165633"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row544087923165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p419597171165633"><a name="p419597171165633"></a><a name="p419597171165633"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p945732979165633"><a name="p945732979165633"></a><a name="p945732979165633"></a>UIViewType </p>
<p id="p1801379054165633"><a name="p1801379054165633"></a><a name="p1801379054165633"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1415374652165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p20177270165633"><a name="p20177270165633"></a><a name="p20177270165633"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p417530590165633"><a name="p417530590165633"></a><a name="p417530590165633"></a>virtual void </p>
<p id="p602426068165633"><a name="p602426068165633"></a><a name="p602426068165633"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row634219895165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302244073165633"><a name="p1302244073165633"></a><a name="p1302244073165633"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p513007764165633"><a name="p513007764165633"></a><a name="p513007764165633"></a>virtual void </p>
<p id="p170840785165633"><a name="p170840785165633"></a><a name="p170840785165633"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1988914833165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p956254191165633"><a name="p956254191165633"></a><a name="p956254191165633"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2082404325165633"><a name="p2082404325165633"></a><a name="p2082404325165633"></a>virtual void </p>
<p id="p787977247165633"><a name="p787977247165633"></a><a name="p787977247165633"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1979333396165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2022767510165633"><a name="p2022767510165633"></a><a name="p2022767510165633"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129929703165633"><a name="p1129929703165633"></a><a name="p1129929703165633"></a>virtual void </p>
<p id="p1666045813165633"><a name="p1666045813165633"></a><a name="p1666045813165633"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1685856580165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158187593165633"><a name="p158187593165633"></a><a name="p158187593165633"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p905080218165633"><a name="p905080218165633"></a><a name="p905080218165633"></a>virtual void </p>
<p id="p80382454165633"><a name="p80382454165633"></a><a name="p80382454165633"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row2000747808165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p782072353165633"><a name="p782072353165633"></a><a name="p782072353165633"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282831136165633"><a name="p282831136165633"></a><a name="p282831136165633"></a>virtual void </p>
<p id="p1675529541165633"><a name="p1675529541165633"></a><a name="p1675529541165633"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1335862708165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1724724584165633"><a name="p1724724584165633"></a><a name="p1724724584165633"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090112394165633"><a name="p2090112394165633"></a><a name="p2090112394165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1967447113165633"><a name="p1967447113165633"></a><a name="p1967447113165633"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1897016420165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p778742462165633"><a name="p778742462165633"></a><a name="p778742462165633"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p54352283165633"><a name="p54352283165633"></a><a name="p54352283165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1176357027165633"><a name="p1176357027165633"></a><a name="p1176357027165633"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1437275639165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2134247413165633"><a name="p2134247413165633"></a><a name="p2134247413165633"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p369370472165633"><a name="p369370472165633"></a><a name="p369370472165633"></a>void </p>
<p id="p28451603165633"><a name="p28451603165633"></a><a name="p28451603165633"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1246552370165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263092648165633"><a name="p1263092648165633"></a><a name="p1263092648165633"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1693250782165633"><a name="p1693250782165633"></a><a name="p1693250782165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p979757873165633"><a name="p979757873165633"></a><a name="p979757873165633"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row655997861165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1851131751165633"><a name="p1851131751165633"></a><a name="p1851131751165633"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p254967587165633"><a name="p254967587165633"></a><a name="p254967587165633"></a>void </p>
<p id="p677737608165633"><a name="p677737608165633"></a><a name="p677737608165633"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1031307181165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p367683233165633"><a name="p367683233165633"></a><a name="p367683233165633"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1223252122165633"><a name="p1223252122165633"></a><a name="p1223252122165633"></a> </p>
<p id="p962611362165633"><a name="p962611362165633"></a><a name="p962611362165633"></a>A default constructor used to create an <strong id="b190970041165633"><a name="b190970041165633"></a><a name="b190970041165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1864780763165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p657784195165633"><a name="p657784195165633"></a><a name="p657784195165633"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1862056387165633"><a name="p1862056387165633"></a><a name="p1862056387165633"></a> </p>
<p id="p1578321916165633"><a name="p1578321916165633"></a><a name="p1578321916165633"></a>A constructor used to create an <strong id="b1496355893165633"><a name="b1496355893165633"></a><a name="b1496355893165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row504301086165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p513850042165633"><a name="p513850042165633"></a><a name="p513850042165633"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1188454528165633"><a name="p1188454528165633"></a><a name="p1188454528165633"></a>virtual </p>
<p id="p2085033297165633"><a name="p2085033297165633"></a><a name="p2085033297165633"></a>A destructor used to delete the <strong id="b31009728165633"><a name="b31009728165633"></a><a name="b31009728165633"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1588328527165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1364792215165633"><a name="p1364792215165633"></a><a name="p1364792215165633"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p426110867165633"><a name="p426110867165633"></a><a name="p426110867165633"></a>virtual bool </p>
<p id="p1410988226165633"><a name="p1410988226165633"></a><a name="p1410988226165633"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row985799803165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1306474171165633"><a name="p1306474171165633"></a><a name="p1306474171165633"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2054643322165633"><a name="p2054643322165633"></a><a name="p2054643322165633"></a>virtual void </p>
<p id="p1740552821165633"><a name="p1740552821165633"></a><a name="p1740552821165633"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1645873053165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1269920210165633"><a name="p1269920210165633"></a><a name="p1269920210165633"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591169944165633"><a name="p591169944165633"></a><a name="p591169944165633"></a>virtual void </p>
<p id="p1196145455165633"><a name="p1196145455165633"></a><a name="p1196145455165633"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1709064496165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1281318894165633"><a name="p1281318894165633"></a><a name="p1281318894165633"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428608760165633"><a name="p428608760165633"></a><a name="p428608760165633"></a>virtual void </p>
<p id="p178170519165633"><a name="p178170519165633"></a><a name="p178170519165633"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row101905158165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p816861594165633"><a name="p816861594165633"></a><a name="p816861594165633"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048078289165633"><a name="p2048078289165633"></a><a name="p2048078289165633"></a>void </p>
<p id="p378669586165633"><a name="p378669586165633"></a><a name="p378669586165633"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1716538070165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p64786175165633"><a name="p64786175165633"></a><a name="p64786175165633"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1365109390165633"><a name="p1365109390165633"></a><a name="p1365109390165633"></a>void </p>
<p id="p1420542040165633"><a name="p1420542040165633"></a><a name="p1420542040165633"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1374614533165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p936006021165633"><a name="p936006021165633"></a><a name="p936006021165633"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1607026711165633"><a name="p1607026711165633"></a><a name="p1607026711165633"></a>virtual bool </p>
<p id="p1763490880165633"><a name="p1763490880165633"></a><a name="p1763490880165633"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row955777958165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155337332165633"><a name="p155337332165633"></a><a name="p155337332165633"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1281682552165633"><a name="p1281682552165633"></a><a name="p1281682552165633"></a>virtual bool </p>
<p id="p1945896151165633"><a name="p1945896151165633"></a><a name="p1945896151165633"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row850096766165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p356281329165633"><a name="p356281329165633"></a><a name="p356281329165633"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1087380315165633"><a name="p1087380315165633"></a><a name="p1087380315165633"></a>virtual bool </p>
<p id="p574399975165633"><a name="p574399975165633"></a><a name="p574399975165633"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row949378350165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p948593149165633"><a name="p948593149165633"></a><a name="p948593149165633"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p935123276165633"><a name="p935123276165633"></a><a name="p935123276165633"></a>virtual bool </p>
<p id="p2029526350165633"><a name="p2029526350165633"></a><a name="p2029526350165633"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1708396307165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p262966372165633"><a name="p262966372165633"></a><a name="p262966372165633"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1728150877165633"><a name="p1728150877165633"></a><a name="p1728150877165633"></a>virtual void </p>
<p id="p1948749580165633"><a name="p1948749580165633"></a><a name="p1948749580165633"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1485355899165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p533080531165633"><a name="p533080531165633"></a><a name="p533080531165633"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p218954987165633"><a name="p218954987165633"></a><a name="p218954987165633"></a>virtual void </p>
<p id="p526377198165633"><a name="p526377198165633"></a><a name="p526377198165633"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1033243748165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289861701165633"><a name="p1289861701165633"></a><a name="p1289861701165633"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765901205165633"><a name="p765901205165633"></a><a name="p765901205165633"></a>virtual void </p>
<p id="p1396032843165633"><a name="p1396032843165633"></a><a name="p1396032843165633"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1885508494165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344658755165633"><a name="p1344658755165633"></a><a name="p1344658755165633"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114002461165633"><a name="p2114002461165633"></a><a name="p2114002461165633"></a>virtual void </p>
<p id="p1171350898165633"><a name="p1171350898165633"></a><a name="p1171350898165633"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row856052681165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909913928165633"><a name="p1909913928165633"></a><a name="p1909913928165633"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p259645260165633"><a name="p259645260165633"></a><a name="p259645260165633"></a>void </p>
<p id="p897335077165633"><a name="p897335077165633"></a><a name="p897335077165633"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1904764976165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p518067631165633"><a name="p518067631165633"></a><a name="p518067631165633"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p283793043165633"><a name="p283793043165633"></a><a name="p283793043165633"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p238091332165633"><a name="p238091332165633"></a><a name="p238091332165633"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row682796998165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1565789301165633"><a name="p1565789301165633"></a><a name="p1565789301165633"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p479679078165633"><a name="p479679078165633"></a><a name="p479679078165633"></a>void </p>
<p id="p1934191108165633"><a name="p1934191108165633"></a><a name="p1934191108165633"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row2130029609165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1515544437165633"><a name="p1515544437165633"></a><a name="p1515544437165633"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p241211418165633"><a name="p241211418165633"></a><a name="p241211418165633"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p194029978165633"><a name="p194029978165633"></a><a name="p194029978165633"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1452437290165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047712880165633"><a name="p2047712880165633"></a><a name="p2047712880165633"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1190073493165633"><a name="p1190073493165633"></a><a name="p1190073493165633"></a>void </p>
<p id="p287784489165633"><a name="p287784489165633"></a><a name="p287784489165633"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1927563479165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1860512966165633"><a name="p1860512966165633"></a><a name="p1860512966165633"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1000446288165633"><a name="p1000446288165633"></a><a name="p1000446288165633"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p47712008165633"><a name="p47712008165633"></a><a name="p47712008165633"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row1455509854165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p21719054165633"><a name="p21719054165633"></a><a name="p21719054165633"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p335852288165633"><a name="p335852288165633"></a><a name="p335852288165633"></a>void </p>
<p id="p1142090159165633"><a name="p1142090159165633"></a><a name="p1142090159165633"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row191876663165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1543146921165633"><a name="p1543146921165633"></a><a name="p1543146921165633"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541848676165633"><a name="p1541848676165633"></a><a name="p1541848676165633"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1212392283165633"><a name="p1212392283165633"></a><a name="p1212392283165633"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row2046857055165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406569482165633"><a name="p406569482165633"></a><a name="p406569482165633"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1491913160165633"><a name="p1491913160165633"></a><a name="p1491913160165633"></a>void </p>
<p id="p168215319165633"><a name="p168215319165633"></a><a name="p168215319165633"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row161694040165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p361896192165633"><a name="p361896192165633"></a><a name="p361896192165633"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245647008165633"><a name="p245647008165633"></a><a name="p245647008165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1949417182165633"><a name="p1949417182165633"></a><a name="p1949417182165633"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row428914925165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1527284106165633"><a name="p1527284106165633"></a><a name="p1527284106165633"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p454565566165633"><a name="p454565566165633"></a><a name="p454565566165633"></a>void </p>
<p id="p249064457165633"><a name="p249064457165633"></a><a name="p249064457165633"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1863786887165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761926468165633"><a name="p761926468165633"></a><a name="p761926468165633"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p379662113165633"><a name="p379662113165633"></a><a name="p379662113165633"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p367237479165633"><a name="p367237479165633"></a><a name="p367237479165633"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row2027082351165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489439845165633"><a name="p1489439845165633"></a><a name="p1489439845165633"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1881842129165633"><a name="p1881842129165633"></a><a name="p1881842129165633"></a>virtual void </p>
<p id="p1785352719165633"><a name="p1785352719165633"></a><a name="p1785352719165633"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row1003444178165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1668532741165633"><a name="p1668532741165633"></a><a name="p1668532741165633"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p525273798165633"><a name="p525273798165633"></a><a name="p525273798165633"></a>bool </p>
<p id="p136970116165633"><a name="p136970116165633"></a><a name="p136970116165633"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1223336493165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p816508282165633"><a name="p816508282165633"></a><a name="p816508282165633"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1753870133165633"><a name="p1753870133165633"></a><a name="p1753870133165633"></a>void </p>
<p id="p1771362027165633"><a name="p1771362027165633"></a><a name="p1771362027165633"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row708442650165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1601625984165633"><a name="p1601625984165633"></a><a name="p1601625984165633"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1121870228165633"><a name="p1121870228165633"></a><a name="p1121870228165633"></a>bool </p>
<p id="p2006580021165633"><a name="p2006580021165633"></a><a name="p2006580021165633"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row777628062165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1321129708165633"><a name="p1321129708165633"></a><a name="p1321129708165633"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p613345001165633"><a name="p613345001165633"></a><a name="p613345001165633"></a>void </p>
<p id="p111877943165633"><a name="p111877943165633"></a><a name="p111877943165633"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row686457045165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909257758165633"><a name="p1909257758165633"></a><a name="p1909257758165633"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1689769141165633"><a name="p1689769141165633"></a><a name="p1689769141165633"></a>bool </p>
<p id="p763290918165633"><a name="p763290918165633"></a><a name="p763290918165633"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row788247723165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1284881242165633"><a name="p1284881242165633"></a><a name="p1284881242165633"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p528061749165633"><a name="p528061749165633"></a><a name="p528061749165633"></a>void </p>
<p id="p1838052918165633"><a name="p1838052918165633"></a><a name="p1838052918165633"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1046839745165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p92894870165633"><a name="p92894870165633"></a><a name="p92894870165633"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426111636165633"><a name="p1426111636165633"></a><a name="p1426111636165633"></a>bool </p>
<p id="p819672463165633"><a name="p819672463165633"></a><a name="p819672463165633"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row76596486165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026320420165633"><a name="p1026320420165633"></a><a name="p1026320420165633"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p847109202165633"><a name="p847109202165633"></a><a name="p847109202165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p430310361165633"><a name="p430310361165633"></a><a name="p430310361165633"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1469210761165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p365836425165633"><a name="p365836425165633"></a><a name="p365836425165633"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503980528165633"><a name="p1503980528165633"></a><a name="p1503980528165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p533586843165633"><a name="p533586843165633"></a><a name="p533586843165633"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1328898152165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495421588165633"><a name="p495421588165633"></a><a name="p495421588165633"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1898017888165633"><a name="p1898017888165633"></a><a name="p1898017888165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p892771599165633"><a name="p892771599165633"></a><a name="p892771599165633"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row102551081165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p992401887165633"><a name="p992401887165633"></a><a name="p992401887165633"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p674583397165633"><a name="p674583397165633"></a><a name="p674583397165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p160854359165633"><a name="p160854359165633"></a><a name="p160854359165633"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1725025486165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p37373154165633"><a name="p37373154165633"></a><a name="p37373154165633"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p892012329165633"><a name="p892012329165633"></a><a name="p892012329165633"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p2085236829165633"><a name="p2085236829165633"></a><a name="p2085236829165633"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row1131153494165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p393896335165633"><a name="p393896335165633"></a><a name="p393896335165633"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1086584201165633"><a name="p1086584201165633"></a><a name="p1086584201165633"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p408008856165633"><a name="p408008856165633"></a><a name="p408008856165633"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row236324855165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462366898165633"><a name="p1462366898165633"></a><a name="p1462366898165633"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2080524110165633"><a name="p2080524110165633"></a><a name="p2080524110165633"></a>void </p>
<p id="p796692740165633"><a name="p796692740165633"></a><a name="p796692740165633"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row52147534165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551700853165633"><a name="p1551700853165633"></a><a name="p1551700853165633"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236167704165633"><a name="p236167704165633"></a><a name="p236167704165633"></a>virtual void </p>
<p id="p1023150849165633"><a name="p1023150849165633"></a><a name="p1023150849165633"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row594026703165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139462716165633"><a name="p1139462716165633"></a><a name="p1139462716165633"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391392583165633"><a name="p391392583165633"></a><a name="p391392583165633"></a>virtual int16_t </p>
<p id="p1584723718165633"><a name="p1584723718165633"></a><a name="p1584723718165633"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row403382145165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1074017178165633"><a name="p1074017178165633"></a><a name="p1074017178165633"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1431233509165633"><a name="p1431233509165633"></a><a name="p1431233509165633"></a>virtual void </p>
<p id="p889884130165633"><a name="p889884130165633"></a><a name="p889884130165633"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row298572904165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355262919165633"><a name="p1355262919165633"></a><a name="p1355262919165633"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2005744343165633"><a name="p2005744343165633"></a><a name="p2005744343165633"></a>virtual int16_t </p>
<p id="p2046500880165633"><a name="p2046500880165633"></a><a name="p2046500880165633"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row153096601165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p713713461165633"><a name="p713713461165633"></a><a name="p713713461165633"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1268580033165633"><a name="p1268580033165633"></a><a name="p1268580033165633"></a>virtual void </p>
<p id="p730731560165633"><a name="p730731560165633"></a><a name="p730731560165633"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1152556284165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p229027056165633"><a name="p229027056165633"></a><a name="p229027056165633"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p217107802165633"><a name="p217107802165633"></a><a name="p217107802165633"></a>virtual void </p>
<p id="p238182718165633"><a name="p238182718165633"></a><a name="p238182718165633"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1763706792165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1244139733165633"><a name="p1244139733165633"></a><a name="p1244139733165633"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p490970090165633"><a name="p490970090165633"></a><a name="p490970090165633"></a>int16_t </p>
<p id="p2019425730165633"><a name="p2019425730165633"></a><a name="p2019425730165633"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row207620075165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p213467351165633"><a name="p213467351165633"></a><a name="p213467351165633"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2146910382165633"><a name="p2146910382165633"></a><a name="p2146910382165633"></a>virtual void </p>
<p id="p425078916165633"><a name="p425078916165633"></a><a name="p425078916165633"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row256262700165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755012650165633"><a name="p755012650165633"></a><a name="p755012650165633"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p98972301165633"><a name="p98972301165633"></a><a name="p98972301165633"></a>int16_t </p>
<p id="p1051993490165633"><a name="p1051993490165633"></a><a name="p1051993490165633"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row415895579165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1166519525165633"><a name="p1166519525165633"></a><a name="p1166519525165633"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p247911510165633"><a name="p247911510165633"></a><a name="p247911510165633"></a>virtual void </p>
<p id="p40916594165633"><a name="p40916594165633"></a><a name="p40916594165633"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row960391868165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734474077165633"><a name="p1734474077165633"></a><a name="p1734474077165633"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940368083165633"><a name="p1940368083165633"></a><a name="p1940368083165633"></a>virtual void </p>
<p id="p385871990165633"><a name="p385871990165633"></a><a name="p385871990165633"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1501094781165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p906680273165633"><a name="p906680273165633"></a><a name="p906680273165633"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513208014165633"><a name="p1513208014165633"></a><a name="p1513208014165633"></a>bool </p>
<p id="p2658700165633"><a name="p2658700165633"></a><a name="p2658700165633"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row595387523165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2057569601165633"><a name="p2057569601165633"></a><a name="p2057569601165633"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p336118738165633"><a name="p336118738165633"></a><a name="p336118738165633"></a>void </p>
<p id="p814168801165633"><a name="p814168801165633"></a><a name="p814168801165633"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row1742690407165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2016591221165633"><a name="p2016591221165633"></a><a name="p2016591221165633"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p482590854165633"><a name="p482590854165633"></a><a name="p482590854165633"></a>void </p>
<p id="p232057699165633"><a name="p232057699165633"></a><a name="p232057699165633"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row357788144165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p191493172165633"><a name="p191493172165633"></a><a name="p191493172165633"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1156643767165633"><a name="p1156643767165633"></a><a name="p1156643767165633"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1025942576165633"><a name="p1025942576165633"></a><a name="p1025942576165633"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row228003571165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2019050543165633"><a name="p2019050543165633"></a><a name="p2019050543165633"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2147168944165633"><a name="p2147168944165633"></a><a name="p2147168944165633"></a>void </p>
<p id="p534963915165633"><a name="p534963915165633"></a><a name="p534963915165633"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1069615734165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1909456295165633"><a name="p1909456295165633"></a><a name="p1909456295165633"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86959722165633"><a name="p86959722165633"></a><a name="p86959722165633"></a>const char * </p>
<p id="p1845635849165633"><a name="p1845635849165633"></a><a name="p1845635849165633"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row2134741264165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p606368806165633"><a name="p606368806165633"></a><a name="p606368806165633"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242458997165633"><a name="p1242458997165633"></a><a name="p1242458997165633"></a>void </p>
<p id="p1006362418165633"><a name="p1006362418165633"></a><a name="p1006362418165633"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row768921068165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2129502528165633"><a name="p2129502528165633"></a><a name="p2129502528165633"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005888010165633"><a name="p1005888010165633"></a><a name="p1005888010165633"></a>int16_t </p>
<p id="p339625265165633"><a name="p339625265165633"></a><a name="p339625265165633"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row1483970217165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1746882234165633"><a name="p1746882234165633"></a><a name="p1746882234165633"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817286868165633"><a name="p1817286868165633"></a><a name="p1817286868165633"></a>virtual void </p>
<p id="p1443856765165633"><a name="p1443856765165633"></a><a name="p1443856765165633"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row801775657165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1985445391165633"><a name="p1985445391165633"></a><a name="p1985445391165633"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1681368685165633"><a name="p1681368685165633"></a><a name="p1681368685165633"></a>void </p>
<p id="p1010874658165633"><a name="p1010874658165633"></a><a name="p1010874658165633"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1614797191165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1175541516165633"><a name="p1175541516165633"></a><a name="p1175541516165633"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1961567814165633"><a name="p1961567814165633"></a><a name="p1961567814165633"></a>void </p>
<p id="p878200990165633"><a name="p878200990165633"></a><a name="p878200990165633"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row1921390534165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p593952682165633"><a name="p593952682165633"></a><a name="p593952682165633"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1435511367165633"><a name="p1435511367165633"></a><a name="p1435511367165633"></a>void </p>
<p id="p2001497208165633"><a name="p2001497208165633"></a><a name="p2001497208165633"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row540526390165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217793680165633"><a name="p1217793680165633"></a><a name="p1217793680165633"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1886776889165633"><a name="p1886776889165633"></a><a name="p1886776889165633"></a>void </p>
<p id="p481699896165633"><a name="p481699896165633"></a><a name="p481699896165633"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row197533731165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1864292053165633"><a name="p1864292053165633"></a><a name="p1864292053165633"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343798662165633"><a name="p343798662165633"></a><a name="p343798662165633"></a>void </p>
<p id="p665997236165633"><a name="p665997236165633"></a><a name="p665997236165633"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row765145619165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612475206165633"><a name="p612475206165633"></a><a name="p612475206165633"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1175312510165633"><a name="p1175312510165633"></a><a name="p1175312510165633"></a>void </p>
<p id="p1947465895165633"><a name="p1947465895165633"></a><a name="p1947465895165633"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1913769954165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835921534165633"><a name="p835921534165633"></a><a name="p835921534165633"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2122351635165633"><a name="p2122351635165633"></a><a name="p2122351635165633"></a>void </p>
<p id="p673008320165633"><a name="p673008320165633"></a><a name="p673008320165633"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1467885370165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2063675082165633"><a name="p2063675082165633"></a><a name="p2063675082165633"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801146667165633"><a name="p1801146667165633"></a><a name="p1801146667165633"></a>void </p>
<p id="p201441009165633"><a name="p201441009165633"></a><a name="p201441009165633"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row518826142165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1729754202165633"><a name="p1729754202165633"></a><a name="p1729754202165633"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117063715165633"><a name="p1117063715165633"></a><a name="p1117063715165633"></a>void </p>
<p id="p227453329165633"><a name="p227453329165633"></a><a name="p227453329165633"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row1302657263165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1834688459165633"><a name="p1834688459165633"></a><a name="p1834688459165633"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1969428962165633"><a name="p1969428962165633"></a><a name="p1969428962165633"></a>void </p>
<p id="p90686246165633"><a name="p90686246165633"></a><a name="p90686246165633"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row609360968165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p355288932165633"><a name="p355288932165633"></a><a name="p355288932165633"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1349734803165633"><a name="p1349734803165633"></a><a name="p1349734803165633"></a>void </p>
<p id="p1638824728165633"><a name="p1638824728165633"></a><a name="p1638824728165633"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row263416695165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p445675367165633"><a name="p445675367165633"></a><a name="p445675367165633"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1272443487165633"><a name="p1272443487165633"></a><a name="p1272443487165633"></a>void </p>
<p id="p1479802307165633"><a name="p1479802307165633"></a><a name="p1479802307165633"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row1178692482165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1384705601165633"><a name="p1384705601165633"></a><a name="p1384705601165633"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p616675586165633"><a name="p616675586165633"></a><a name="p616675586165633"></a>void </p>
<p id="p497443004165633"><a name="p497443004165633"></a><a name="p497443004165633"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row821504460165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p330432089165633"><a name="p330432089165633"></a><a name="p330432089165633"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1119419092165633"><a name="p1119419092165633"></a><a name="p1119419092165633"></a>void </p>
<p id="p350527984165633"><a name="p350527984165633"></a><a name="p350527984165633"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row341820161165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1282138908165633"><a name="p1282138908165633"></a><a name="p1282138908165633"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p722700175165633"><a name="p722700175165633"></a><a name="p722700175165633"></a>void </p>
<p id="p1826009314165633"><a name="p1826009314165633"></a><a name="p1826009314165633"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row1455698407165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p956703869165633"><a name="p956703869165633"></a><a name="p956703869165633"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1129810537165633"><a name="p1129810537165633"></a><a name="p1129810537165633"></a>void </p>
<p id="p320489962165633"><a name="p320489962165633"></a><a name="p320489962165633"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row1205991607165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1184940910165633"><a name="p1184940910165633"></a><a name="p1184940910165633"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1900875116165633"><a name="p1900875116165633"></a><a name="p1900875116165633"></a>virtual void </p>
<p id="p843111654165633"><a name="p843111654165633"></a><a name="p843111654165633"></a>Sets a style. </p>
</td>
</tr>
<tr id="row787562983165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1303281006165633"><a name="p1303281006165633"></a><a name="p1303281006165633"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p864300277165633"><a name="p864300277165633"></a><a name="p864300277165633"></a>virtual int64_t </p>
<p id="p433062380165633"><a name="p433062380165633"></a><a name="p433062380165633"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row110012735165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p880257165633"><a name="p880257165633"></a><a name="p880257165633"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p708115912165633"><a name="p708115912165633"></a><a name="p708115912165633"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p681177240165633"><a name="p681177240165633"></a><a name="p681177240165633"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1804813552165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1485285013165633"><a name="p1485285013165633"></a><a name="p1485285013165633"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p749511612165633"><a name="p749511612165633"></a><a name="p749511612165633"></a>void * </p>
<p id="p999998902165633"><a name="p999998902165633"></a><a name="p999998902165633"></a>Overrides the <strong id="b639148261165633"><a name="b639148261165633"></a><a name="b639148261165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1322369761165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p742208910165633"><a name="p742208910165633"></a><a name="p742208910165633"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631931677165633"><a name="p1631931677165633"></a><a name="p1631931677165633"></a>void </p>
<p id="p1669627709165633"><a name="p1669627709165633"></a><a name="p1669627709165633"></a>Overrides the <strong id="b212453618165633"><a name="b212453618165633"></a><a name="b212453618165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Attributes<a name="pub-static-attribs"></a>

<a name="table1647339479165633"></a>
<table><thead align="left"><tr id="row1171394455165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p783619981165633"><a name="p783619981165633"></a><a name="p783619981165633"></a>Static Public Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1904439231165633"><a name="p1904439231165633"></a><a name="p1904439231165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2055975623165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p129998399165633"><a name="p129998399165633"></a><a name="p129998399165633"></a><a href="Graphic.md#ga7f433b8551722451f880e7fa05731a2f">ONE_MINUTE_IN_SECOND</a> = 60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640381762165633"><a name="p1640381762165633"></a><a name="p1640381762165633"></a>Represents 60 seconds per minute. </p>
</td>
</tr>
<tr id="row732440344165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625462039165633"><a name="p1625462039165633"></a><a name="p1625462039165633"></a><a href="Graphic.md#ga5434b911b6f7e0637ac0626c9dd0f513">ONE_HOUR_IN_MINUTE</a> = 60</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170291815165633"><a name="p1170291815165633"></a><a name="p1170291815165633"></a>Represents 60 minutes per hour. </p>
</td>
</tr>
<tr id="row1331265637165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p548567424165633"><a name="p548567424165633"></a><a name="p548567424165633"></a><a href="Graphic.md#gae7742f1e715885ecc4f5b67d57530319">ONE_DAY_IN_HOUR</a> = 24</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p940637535165633"><a name="p940637535165633"></a><a name="p940637535165633"></a>Represents 24 hours per day. </p>
</td>
</tr>
<tr id="row950091923165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p241691973165633"><a name="p241691973165633"></a><a name="p241691973165633"></a><a href="Graphic.md#gae40a5ae3834b626e2976fab83f166171">HALF_DAY_IN_HOUR</a> = 12</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p791668702165633"><a name="p791668702165633"></a><a name="p791668702165633"></a>Represents 12 hours every half day. </p>
</td>
</tr>
</tbody>
</table>

## Protected Attributes<a name="pro-attribs"></a>

<a name="table730694674165633"></a>
<table><thead align="left"><tr id="row1740341587165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1744904362165633"><a name="p1744904362165633"></a><a name="p1744904362165633"></a>Protected Attribute Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1242867579165633"><a name="p1242867579165633"></a><a name="p1242867579165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1157979418165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p264664263165633"><a name="p264664263165633"></a><a name="p264664263165633"></a><a href="Graphic.md#gaabfbbb277dabf5477c628336a429f8ad">currentHour_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2127780173165633"><a name="p2127780173165633"></a><a name="p2127780173165633"></a>Represents the current number of hours. </p>
</td>
</tr>
<tr id="row42356712165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1596049005165633"><a name="p1596049005165633"></a><a name="p1596049005165633"></a><a href="Graphic.md#ga34c3518c0dc9f35fc77b240b6f8d0dcb">currentMinute_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541204636165633"><a name="p1541204636165633"></a><a name="p1541204636165633"></a>Represents the current number of minutes. </p>
</td>
</tr>
<tr id="row616282537165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1759032590165633"><a name="p1759032590165633"></a><a name="p1759032590165633"></a><a href="Graphic.md#ga5b2749cdc5e52551731923d8268b8d5d">currentSecond_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1843073256165633"><a name="p1843073256165633"></a><a name="p1843073256165633"></a>Represents the current number of seconds. </p>
</td>
</tr>
<tr id="row1751633523165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p672405118165633"><a name="p672405118165633"></a><a name="p672405118165633"></a><a href="Graphic.md#gab08c7c490a5b42fcdee04d45b5521d1c">mode_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145981023165633"><a name="p1145981023165633"></a><a name="p1145981023165633"></a>Represents the current working mode of this clock. </p>
</td>
</tr>
<tr id="row11992799165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1915449639165633"><a name="p1915449639165633"></a><a name="p1915449639165633"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751670240165633"><a name="p1751670240165633"></a><a name="p1751670240165633"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1704512274165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p327099066165633"><a name="p327099066165633"></a><a name="p327099066165633"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1192142219165633"><a name="p1192142219165633"></a><a name="p1192142219165633"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row2024280042165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p380223188165633"><a name="p380223188165633"></a><a name="p380223188165633"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1927759262165633"><a name="p1927759262165633"></a><a name="p1927759262165633"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row913822251165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1328349970165633"><a name="p1328349970165633"></a><a name="p1328349970165633"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1868599574165633"><a name="p1868599574165633"></a><a name="p1868599574165633"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row346319485165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653805726165633"><a name="p653805726165633"></a><a name="p653805726165633"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76312329165633"><a name="p76312329165633"></a><a name="p76312329165633"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row814837082165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p338429179165633"><a name="p338429179165633"></a><a name="p338429179165633"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p5327961165633"><a name="p5327961165633"></a><a name="p5327961165633"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table2031420033165633"></a>
<table><thead align="left"><tr id="row2126493388165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1034833141165633"><a name="p1034833141165633"></a><a name="p1034833141165633"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1266133628165633"><a name="p1266133628165633"></a><a name="p1266133628165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1373387719165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p789011646165633"><a name="p789011646165633"></a><a name="p789011646165633"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p42099564165633"><a name="p42099564165633"></a><a name="p42099564165633"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row2084479721165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196908104165633"><a name="p1196908104165633"></a><a name="p1196908104165633"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p54549464165633"><a name="p54549464165633"></a><a name="p54549464165633"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
</tbody>
</table>

