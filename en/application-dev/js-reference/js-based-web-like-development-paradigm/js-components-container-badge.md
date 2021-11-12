# badge<a name="EN-US_TOPIC_0000001173324629"></a>

The  **<badge\>**  component is used to mark new events that require user attention in your application.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

This component supports only one child component.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>If multiple child components are used, only the first one takes effect by default.

## Attribute<a name="section1355418214459"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table3871294431"></a>
<table><thead align="left"><tr id="row12871029184318"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="p087529184319"><a name="p087529184319"></a><a name="p087529184319"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.61%" id="mcps1.1.6.1.2"><p id="p2087629204319"><a name="p2087629204319"></a><a name="p2087629204319"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="14.21%" id="mcps1.1.6.1.3"><p id="p1287112911432"><a name="p1287112911432"></a><a name="p1287112911432"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p1687929124312"><a name="p1687929124312"></a><a name="p1687929124312"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.54%" id="mcps1.1.6.1.5"><p id="p138732916431"><a name="p138732916431"></a><a name="p138732916431"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row887192994311"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p2087102919434"><a name="p2087102919434"></a><a name="p2087102919434"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="p188822916435"><a name="p188822916435"></a><a name="p188822916435"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="p10889298434"><a name="p10889298434"></a><a name="p10889298434"></a>rightTop</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1881929194314"><a name="p1881929194314"></a><a name="p1881929194314"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="p1788142954315"><a name="p1788142954315"></a><a name="p1788142954315"></a>Position of a number or dot badge. Available values are as follows:</p>
<a name="ul1388112944320"></a><a name="ul1388112944320"></a><ul id="ul1388112944320"><li><strong id="b3391219132117"><a name="b3391219132117"></a><a name="b3391219132117"></a>right</strong>: on the right border of the component.</li><li><strong id="b341442812510"><a name="b341442812510"></a><a name="b341442812510"></a>rightTop</strong>: in the upper right corner of the component border.</li><li><strong id="b101851310251"><a name="b101851310251"></a><a name="b101851310251"></a>left</strong>: on the left border of the component.</li></ul>
</td>
</tr>
<tr id="row6887294431"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p28822974315"><a name="p28822974315"></a><a name="p28822974315"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="p188129194313"><a name="p188129194313"></a><a name="p188129194313"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="p288102954310"><a name="p288102954310"></a><a name="p288102954310"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p158852915433"><a name="p158852915433"></a><a name="p158852915433"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="p19881229144313"><a name="p19881229144313"></a><a name="p19881229144313"></a>Number of notifications displayed via the badge. The default value is <strong id="b68878221295"><a name="b68878221295"></a><a name="b68878221295"></a>0</strong>. If the number of notifications is greater than 0, the badge changes from a dot to the number. If this attribute is not set or the value is less than or equal to 0, the badge is a dot.</p>
<div class="note" id="note388629144318"><a name="note388629144318"></a><a name="note388629144318"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p488929174319"><a name="p488929174319"></a><a name="p488929174319"></a>When the <strong id="b107952317541"><a name="b107952317541"></a><a name="b107952317541"></a>count</strong> value is greater than the <strong id="b57744085419"><a name="b57744085419"></a><a name="b57744085419"></a>maxcount</strong> value, <em id="i136441735511"><a name="i136441735511"></a><a name="i136441735511"></a>maxcount</em><strong id="b135651010553"><a name="b135651010553"></a><a name="b135651010553"></a>+</strong> is displayed.</p>
<p id="p16106238105113"><a name="p16106238105113"></a><a name="p16106238105113"></a>The largest integer value supported for <strong id="b12402155411712"><a name="b12402155411712"></a><a name="b12402155411712"></a>count</strong> is <strong id="b3868192910710"><a name="b3868192910710"></a><a name="b3868192910710"></a>2147483647</strong>.</p>
</div></div>
</td>
</tr>
<tr id="row1088152994313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1488329174315"><a name="p1488329174315"></a><a name="p1488329174315"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="p1888102934319"><a name="p1888102934319"></a><a name="p1888102934319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="p88820291436"><a name="p88820291436"></a><a name="p88820291436"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p10881329184320"><a name="p10881329184320"></a><a name="p10881329184320"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="p988112917435"><a name="p988112917435"></a><a name="p988112917435"></a>Whether to display the badge. The value <strong id="b15203113585411"><a name="b15203113585411"></a><a name="b15203113585411"></a>true</strong> means that the badge shows up when a new notification is received. To use a number badge, set the <strong id="b102697204598"><a name="b102697204598"></a><a name="b102697204598"></a>count</strong> attribute.</p>
</td>
</tr>
<tr id="row138862934313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p98872919436"><a name="p98872919436"></a><a name="p98872919436"></a>maxcount</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="p28822920432"><a name="p28822920432"></a><a name="p28822920432"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="p28842944318"><a name="p28842944318"></a><a name="p28842944318"></a>99</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p158810298438"><a name="p158810298438"></a><a name="p158810298438"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="p3881229164317"><a name="p3881229164317"></a><a name="p3881229164317"></a>Maximum number of notifications. When the number of new notifications exceeds the value of this attribute, <em id="i205207517"><a name="i205207517"></a><a name="i205207517"></a>maxcount</em><strong id="b12397175512"><a name="b12397175512"></a><a name="b12397175512"></a>+</strong> is displayed, for example, <strong id="b19503636557"><a name="b19503636557"></a><a name="b19503636557"></a>99+</strong>.</p>
<div class="note" id="note046285914515"><a name="note046285914515"></a><a name="note046285914515"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p114631559205118"><a name="p114631559205118"></a><a name="p114631559205118"></a>The largest integer value supported for <strong id="b138164151386"><a name="b138164151386"></a><a name="b138164151386"></a>maxcount</strong> is <strong id="b168231615682"><a name="b168231615682"></a><a name="b168231615682"></a>2147483647</strong>.</p>
</div></div>
</td>
</tr>
<tr id="row18881929154314"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p188122934312"><a name="p188122934312"></a><a name="p188122934312"></a>config</p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="p128910296432"><a name="p128910296432"></a><a name="p128910296432"></a><a href="../../nottoctopics/en-us_topic_0000001177114381.md#en-us_topic_0000001101866256_table525042221515">BadgeConfig</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="p389529124317"><a name="p389529124317"></a><a name="p389529124317"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p589142984319"><a name="p589142984319"></a><a name="p589142984319"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="p4890291437"><a name="p4890291437"></a><a name="p4890291437"></a>Configuration of the badge.</p>
</td>
</tr>
<tr id="row08922919437"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p12894299435"><a name="p12894299435"></a><a name="p12894299435"></a>label<sup id="sup14890292436"><a name="sup14890292436"></a><a name="sup14890292436"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="12.61%" headers="mcps1.1.6.1.2 "><p id="p18896292438"><a name="p18896292438"></a><a name="p18896292438"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="14.21%" headers="mcps1.1.6.1.3 "><p id="p1889429194315"><a name="p1889429194315"></a><a name="p1889429194315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6891729124318"><a name="p6891729124318"></a><a name="p6891729124318"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.54%" headers="mcps1.1.6.1.5 "><p id="p15894294432"><a name="p15894294432"></a><a name="p15894294432"></a>Text of the new notification displayed via the badge.</p>
<div class="note" id="note168915299438"><a name="note168915299438"></a><a name="note168915299438"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p118982994316"><a name="p118982994316"></a><a name="p118982994316"></a>When this attribute is set, attributes <strong id="b133005251811"><a name="b133005251811"></a><a name="b133005251811"></a>count</strong> and <strong id="b1089219451819"><a name="b1089219451819"></a><a name="b1089219451819"></a>maxcount</strong> do not take effect.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Table  1**  BadgeConfig

<a name="table525042221515"></a>
<table><thead align="left"><tr id="row10250162216151"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.2.6.1.1"><p id="p256733317156"><a name="p256733317156"></a><a name="p256733317156"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.62%" id="mcps1.2.6.1.2"><p id="p13567143391514"><a name="p13567143391514"></a><a name="p13567143391514"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.46%" id="mcps1.2.6.1.3"><p id="p165679339152"><a name="p165679339152"></a><a name="p165679339152"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.22%" id="mcps1.2.6.1.4"><p id="p1018465012153"><a name="p1018465012153"></a><a name="p1018465012153"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="51.33%" id="mcps1.2.6.1.5"><p id="p1250142241516"><a name="p1250142241516"></a><a name="p1250142241516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1425022251510"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="p6944185918156"><a name="p6944185918156"></a><a name="p6944185918156"></a>badgeColor</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="p3944185918156"><a name="p3944185918156"></a><a name="p3944185918156"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="p494412594152"><a name="p494412594152"></a><a name="p494412594152"></a>#fa2a2d</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="p2018411507152"><a name="p2018411507152"></a><a name="p2018411507152"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="p12623249168"><a name="p12623249168"></a><a name="p12623249168"></a>Background color of the badge</p>
</td>
</tr>
<tr id="row1325114221159"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="p189441459101515"><a name="p189441459101515"></a><a name="p189441459101515"></a>textColor</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="p18944175915154"><a name="p18944175915154"></a><a name="p18944175915154"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="p29441859141514"><a name="p29441859141514"></a><a name="p29441859141514"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="p31843506151"><a name="p31843506151"></a><a name="p31843506151"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="p196231461610"><a name="p196231461610"></a><a name="p196231461610"></a>Text color of the number badge</p>
</td>
</tr>
<tr id="row132511522131513"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="p7945175918154"><a name="p7945175918154"></a><a name="p7945175918154"></a>textSize</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="p1594515919158"><a name="p1594515919158"></a><a name="p1594515919158"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="p189451259121511"><a name="p189451259121511"></a><a name="p189451259121511"></a>10px</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="p14184125016151"><a name="p14184125016151"></a><a name="p14184125016151"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="p1962474101618"><a name="p1962474101618"></a><a name="p1962474101618"></a>Text size of the number badge</p>
</td>
</tr>
<tr id="row225122212159"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.2.6.1.1 "><p id="p1394585918156"><a name="p1394585918156"></a><a name="p1394585918156"></a>badgeSize</p>
</td>
<td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.2.6.1.2 "><p id="p159451459111519"><a name="p159451459111519"></a><a name="p159451459111519"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.46%" headers="mcps1.2.6.1.3 "><p id="p694545961517"><a name="p694545961517"></a><a name="p694545961517"></a>6px</p>
</td>
<td class="cellrowborder" valign="top" width="7.22%" headers="mcps1.2.6.1.4 "><p id="p10184135015153"><a name="p10184135015153"></a><a name="p10184135015153"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="51.33%" headers="mcps1.2.6.1.5 "><p id="p1962410411162"><a name="p1962410411162"></a><a name="p1962410411162"></a>Default size of the dot badge</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section5775351116"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The total size of child components must be smaller than or equal to that of the  **<badge\>**  component. Otherwise, the child components cannot be displayed.

## Event<a name="section43461940193518"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example Code<a name="section3510104413431"></a>

```
<!-- xxx.hml -->
<div class="container">
  <badge class="badge" config="{{badgeconfig}}" visible="true" count="100" maxcount="99">
    <text class="text1">huawei</text>
  </badge>
  <badge class="badge" visible="true" count="0">
    <text class="text2">huawei</text>
  </badge>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  width: 100%;
  align-items: center;
}
.badge {
  width: 50%;
  margin-top: 100px;
}
.text1 {
  background-color: #f9a01e;
  font-size: 50px;
}
.text2 {
  background-color: #46b1e3;
  font-size: 50px;
}
```

```
// xxx.js
export default {
  data:{
    badgeconfig:{
      badgeColor:"#0a59f7",
      textColor:"#ffffff",
    }
  }
}
```

![](figures/en-us_image_0000001150368628.png)

