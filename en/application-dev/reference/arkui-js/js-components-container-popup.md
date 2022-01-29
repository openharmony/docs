# popup<a name="EN-US_TOPIC_0000001127284822"></a>

The  **<popup\>**  component is used to display a pop-up to offer instructions after a user clicks a bound control.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="s726c642d8f514b0cb5ef8854fe6ac02c"></a>

All child components are supported. Each  **<popup\>**  can have only one child component<sup>5+</sup>.

## Attributes<a name="s7ff9da9346504b11aca7015dc689dc67"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row679154543116"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p15904153153119"><a name="p15904153153119"></a><a name="p15904153153119"></a>target</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p6904205312310"><a name="p6904205312310"></a><a name="p6904205312310"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p79041853123118"><a name="p79041853123118"></a><a name="p79041853123118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p4904153173110"><a name="p4904153173110"></a><a name="p4904153173110"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p9904155363115"><a name="p9904155363115"></a><a name="p9904155363115"></a>ID of the target element. Dynamic switch is not supported.</p>
</td>
</tr>
<tr id="row17485184243110"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11904175316315"><a name="p11904175316315"></a><a name="p11904175316315"></a>placement</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1390413531314"><a name="p1390413531314"></a><a name="p1390413531314"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p390465317319"><a name="p390465317319"></a><a name="p390465317319"></a>bottom</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1990415317319"><a name="p1990415317319"></a><a name="p1990415317319"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1990410531316"><a name="p1990410531316"></a><a name="p1990410531316"></a>Position of the pop-up. Available values are as follows:</p>
<a name="ul1190565393119"></a><a name="ul1190565393119"></a><ul id="ul1190565393119"><li><strong id="b15820759192312"><a name="b15820759192312"></a><a name="b15820759192312"></a>left</strong>: The pop-up is displayed on the left of the target item.</li><li><strong id="b16901171419245"><a name="b16901171419245"></a><a name="b16901171419245"></a>right</strong>: The pop-up is displayed on the right of the target item.</li><li><strong id="b1499931915246"><a name="b1499931915246"></a><a name="b1499931915246"></a>top</strong>: The pop-up is displayed at the top of the target item.</li><li><strong id="b4343193516249"><a name="b4343193516249"></a><a name="b4343193516249"></a>bottom</strong>: The pop-up is displayed at the bottom of the target item.</li><li><strong id="b64261744192420"><a name="b64261744192420"></a><a name="b64261744192420"></a>topLeft</strong>: The pop-up is displayed on the upper left of the target item.</li><li><strong id="b612225418245"><a name="b612225418245"></a><a name="b612225418245"></a>topRight</strong>: The pop-up is displayed on the upper right of the target item.</li><li><strong id="b19405122515"><a name="b19405122515"></a><a name="b19405122515"></a>bottomLeft</strong>: The pop-up is displayed on the bottom left of the target item.</li><li><strong id="b1069401942019"><a name="b1069401942019"></a><a name="b1069401942019"></a>bottomRight</strong>: The pop-up is displayed on the bottom right of the target item.</li></ul>
</td>
</tr>
<tr id="row5684114975"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p156851846718"><a name="p156851846718"></a><a name="p156851846718"></a>keepalive<sup id="sup7289771114"><a name="sup7289771114"></a><a name="sup7289771114"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p13685642077"><a name="p13685642077"></a><a name="p13685642077"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p16685164777"><a name="p16685164777"></a><a name="p16685164777"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1068513410710"><a name="p1068513410710"></a><a name="p1068513410710"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p121401832662"><a name="p121401832662"></a><a name="p121401832662"></a>Whether to retain this pop-up.</p>
<p id="p0676162715614"><a name="p0676162715614"></a><a name="p0676162715614"></a><strong id="b1667616271964"><a name="b1667616271964"></a><a name="b1667616271964"></a>true</strong>: The pop-up does not disappear when users tap other areas or switch the page. To hide the pop-up, you need to call the <strong id="b166761527866"><a name="b166761527866"></a><a name="b166761527866"></a>hide</strong> method.</p>
<p id="p1661313358613"><a name="p1661313358613"></a><a name="p1661313358613"></a><strong id="b1343817329515"><a name="b1343817329515"></a><a name="b1343817329515"></a>false</strong>: The pop-up disappears when users tap other areas or switch the page.</p>
</td>
</tr>
<tr id="row99782190913"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p397971910920"><a name="p397971910920"></a><a name="p397971910920"></a>clickable<sup id="sup143370106114"><a name="sup143370106114"></a><a name="sup143370106114"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p149793191095"><a name="p149793191095"></a><a name="p149793191095"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p197981917920"><a name="p197981917920"></a><a name="p197981917920"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1197914193916"><a name="p1197914193916"></a><a name="p1197914193916"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p39792192095"><a name="p39792192095"></a><a name="p39792192095"></a>Whether to display the pop-up when users click the bound control. If this parameter is set to <strong id="b12988162164619"><a name="b12988162164619"></a><a name="b12988162164619"></a>false</strong>, the pop-up can be triggered only by a method call.</p>
</td>
</tr>
<tr id="row94796310119"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p174804313111"><a name="p174804313111"></a><a name="p174804313111"></a>arrowoffset<sup id="sup1520573571311"><a name="sup1520573571311"></a><a name="sup1520573571311"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1948053131110"><a name="p1948053131110"></a><a name="p1948053131110"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p6480831191117"><a name="p6480831191117"></a><a name="p6480831191117"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p8480153151112"><a name="p8480153151112"></a><a name="p8480153151112"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p548093131119"><a name="p548093131119"></a><a name="p548093131119"></a>Offset of the pop-up arrow. By default, the arrow is centered. A positive value means that the arrow moves along the language direction (LTR or RTL), and a negative value means that the arrow moves along the opposite direction of the language direction.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The  **focusable**  attribute is not supported.

## Styles<a name="s472a5052130e49bca059adfe7bb6b96d"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table9160202272017"></a>
<table><thead align="left"><tr id="row15160122212204"><th class="cellrowborder" valign="top" width="12.688731126887312%" id="mcps1.1.6.1.1"><p id="p5160182214208"><a name="p5160182214208"></a><a name="p5160182214208"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.47895210478952%" id="mcps1.1.6.1.2"><p id="p0160122232018"><a name="p0160122232018"></a><a name="p0160122232018"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.60913908609139%" id="mcps1.1.6.1.3"><p id="p13160152232015"><a name="p13160152232015"></a><a name="p13160152232015"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="6.28937106289371%" id="mcps1.1.6.1.4"><p id="p101617229209"><a name="p101617229209"></a><a name="p101617229209"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="61.933806619338064%" id="mcps1.1.6.1.5"><p id="p1616162216202"><a name="p1616162216202"></a><a name="p1616162216202"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row191611622172010"><td class="cellrowborder" valign="top" width="12.688731126887312%" headers="mcps1.1.6.1.1 "><p id="p1816142292013"><a name="p1816142292013"></a><a name="p1816142292013"></a>mask-color</p>
</td>
<td class="cellrowborder" valign="top" width="10.47895210478952%" headers="mcps1.1.6.1.2 "><p id="p516152217201"><a name="p516152217201"></a><a name="p516152217201"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.60913908609139%" headers="mcps1.1.6.1.3 "><p id="p11161102218207"><a name="p11161102218207"></a><a name="p11161102218207"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.28937106289371%" headers="mcps1.1.6.1.4 "><p id="p8161162282014"><a name="p8161162282014"></a><a name="p8161162282014"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="61.933806619338064%" headers="mcps1.1.6.1.5 "><p id="p1416162202014"><a name="p1416162202014"></a><a name="p1416162202014"></a>Color configuration of the mask layer. By default, the mask layer is completely transparent.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Position-related styles are not supported.

## Events<a name="section1295913853210"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameters</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row84115915325"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1458817720332"><a name="p1458817720332"></a><a name="p1458817720332"></a>visibilitychange</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p115888783316"><a name="p115888783316"></a><a name="p115888783316"></a>{ visibility: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p558817173314"><a name="p558817173314"></a><a name="p558817173314"></a>Triggered when a pop-up appears or disappears.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section1970516568131"></a>

Only the following methods are supported.

<a name="table20753173210251"></a>
<table><thead align="left"><tr id="row575363214257"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="p157531032112517"><a name="p157531032112517"></a><a name="p157531032112517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="p77531632132518"><a name="p77531632132518"></a><a name="p77531632132518"></a>Parameters</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="p147531232132512"><a name="p147531232132512"></a><a name="p147531232132512"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15753113210251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p2314135812511"><a name="p2314135812511"></a><a name="p2314135812511"></a>show<sup id="sup969153720142"><a name="sup969153720142"></a><a name="sup969153720142"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p7314115819256"><a name="p7314115819256"></a><a name="p7314115819256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p0314958162512"><a name="p0314958162512"></a><a name="p0314958162512"></a>Pops up a message.</p>
</td>
</tr>
<tr id="row393410526251"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="p7314358182512"><a name="p7314358182512"></a><a name="p7314358182512"></a>hide<sup id="sup16463154010141"><a name="sup16463154010141"></a><a name="sup16463154010141"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="p1231455814253"><a name="p1231455814253"></a><a name="p1231455814253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="p10314105842512"><a name="p10314105842512"></a><a name="p10314105842512"></a>Hides a pop-up.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>1.  Attributes and styles of a  **<popup\>**  component cannot be dynamically updated.
>2.  Margins of a pop-up take effect depending on its position relative to the target element. For example, if the pop-up is below the target element, only  **margin-top**  takes effect; if the pop-up displays on the upper left of the target element, only  **margin-bottom**  and  **margin-right**  take effect.
>3.  Styles set for the four borders of a pop-up must be the same. If they are different and the border radius is  **0**, the first configured border style \(in the sequence of left, top, right, and bottom\) takes effect. Otherwise, the  **border**  attribute does not take effect.
>4.  The click event bound to the target element of a pop-up does not take effect.

## Example Code<a name="section29231018162418"></a>

```
<!-- xxx.hml -->
<div class="container">
  <text id="text">Click to show the pop-up</text>
  <!-- popup supports single child of any type5+ -->
  <popup id="popup" class="popup" target="text" placement="top" keepalive="true" clickable="true" 
    arrowoffset="100px" onvisibilitychange="visibilitychange" onclick="hidepopup">
    <text class="text">Text content of the pop-up</text>
  </popup>
  <button class="button" onclick="showpopup">Click to show the pop-up</button>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: center;
  padding-top: 200px;
}
.popup {
  mask-color: gray;
}
.text {
  color: white;
}
.button {
  width: 220px;
  height: 70px;
  margin-top: 50px;
}
```

```
// xxx.js
import prompt from '@system.prompt'
export default {
  visibilitychange(e) {
    prompt.showToast({
      message: 'visibility change visibility: ' + e.visibility,
        duration: 3000,
    }); 
  },
  showpopup() {
    this.$element("popup").show();
  },
  hidepopup() {
    this.$element("popup").hide();
  },
}
```

![](figures/en-us_image_0000001178886129.png)

